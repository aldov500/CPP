#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QSerialPortInfo>
#include<QSerialPort>

void MainWindow::recepcionSerialAsyncrona(){
    if(arduino_esta_conectado && arduino->isReadable()){
        //QByteArray datosLeidos = arduino->readAll();
        QByteArray datosLeidos = arduino->readLine();
        int indice0 = datosLeidos.indexOf("\n");
        int indice1 = datosLeidos.indexOf("@");
        QString infoExtraida = datosLeidos.mid(indice1+1,(indice0-indice1));
        int datoEntero = infoExtraida.toInt();

        qDebug() << "Dato: " << datoEntero << endl;

       // ui->lcdNumber->display(datoEntero);
        if(indice0>=0 && indice1>=0) {
                qDebug() << "Datos extraidos: " << infoExtraida.toUtf8().constData();
                qDebug() << "Datos leidos: " << datosLeidos << endl;
                ui->progressBar->setValue(datoEntero);
                //graficar(datoEntero);

        }



    }
}

void MainWindow::conectarArduino(){

    //Parte # 1, declaración inicial de las variables
    arduino_esta_conectado = false;
    arduino = new QSerialPort(this);
    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::recepcionSerialAsyncrona);

    QString nombreDispositivoSerial = "";
    int nombreProductID = 0;




    //-2 buscar puertos con los identificadores de Arduino
    qDebug() << "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "ID Vendedor " << serialPortInfo.vendorIdentifier();
            qDebug() << "ID Producto: " << serialPortInfo.productIdentifier();

            if(serialPortInfo.productIdentifier() == 66 || serialPortInfo.productIdentifier() == 67){
                arduino_esta_conectado = true;
                nombreDispositivoSerial = serialPortInfo.portName();
                nombreProductID = serialPortInfo.productIdentifier();
            }
        }

    }

    //3-Conexion
    if(arduino_esta_conectado){

        arduino ->setPortName(nombreDispositivoSerial);
        arduino->open(QIODevice::ReadWrite);
        arduino->setDataBits(QSerialPort::Data8);
        arduino ->setBaudRate(QSerialPort::Baud115200);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
         ui->label->clear();
        qDebug() << "Producto: " << nombreProductID;
        if(nombreProductID == 67) ui->label->setText("Arduino UNO R3 conectado");
        else if(nombreProductID == 66) ui->label->setText("Arduino Mega conectado");
        else ui->label->setText("Error 3");

    }
    else{
        ui->label->clear();
        ui->label->setText("No hay arduino");
    }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->progressBar->setValue(0);
    conectarArduino();

}

MainWindow::~MainWindow()
{
    arduino->close();
    delete ui;
}
