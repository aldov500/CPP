#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

void MainWindow::buscaYconectaArduino(){
    //Parte # 1, declaración inicial de las variables
    arduino_esta_disponible = false;
    arduino_puerto = "";
    arduino = new QSerialPort;
    QString nombreDispositivoSerial = "";
    int nombreProductID = 0;

    //Parte # 2,buscar puertos con los identificadores de Arduino
    qDebug() << "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "ID Vendedor " << serialPortInfo.vendorIdentifier();
            qDebug() << "ID Producto: " << serialPortInfo.productIdentifier();

            if(serialPortInfo.productIdentifier() == arduino_UNO || serialPortInfo.productIdentifier() == arduino_MEGA){
                arduino_esta_disponible = true;
                nombreDispositivoSerial = serialPortInfo.portName();
                nombreProductID = serialPortInfo.productIdentifier();
            }
        }

    }

    //Parte # 3, conexión del puerto encontrado con Arduino

    if(arduino_esta_disponible){
        arduino_puerto = nombreDispositivoSerial;
        arduino ->setPortName(arduino_puerto);
        arduino->open(QIODevice::ReadWrite);
        arduino->setDataBits(QSerialPort::Data8);
        arduino ->setBaudRate(QSerialPort::Baud115200);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
         ui->label->clear();
        qDebug() << "Producto: " << nombreProductID;
        if(nombreProductID == 67) ui->label->setText("Arduino UNO R3 conectado");
        else if(nombreProductID == 68) ui->label->setText("Arduino Mega conectado");
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
    buscaYconectaArduino();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    buscaYconectaArduino();
}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
    if(arduino_esta_disponible && arduino->isWritable()){
        if(checked){
            arduino->write("1\n");
        }
        else{
            arduino->write("2\n");
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(arduino_esta_disponible && arduino->isWritable()){
        arduino->write("3\n");
        if(arduino->isReadable()){
           // QByteArray datoLeido = arduino->read(2);
            QByteArray datoLeido = arduino->readAll();
           // int DatoEntero = datoLeido.toHex().toInt(0,16);
            qDebug() << datoLeido;
            ui->lcdNumber->display(datoLeido.toInt());
        }

    }
}
