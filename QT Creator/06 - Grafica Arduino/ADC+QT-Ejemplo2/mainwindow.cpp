#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

void MainWindow::fTimer(){
  if(arduino_is_available){
      if(arduino->isWritable()){
          arduino->write("30");
          if(arduino->isReadable()){
              QByteArray datosLeidos = arduino->read(2);
              int ADC_Digital = datosLeidos.toHex().toInt(0,16);
              float ADC_Flotante = (5*(float)ADC_Digital/1023);
              ui->progressBar->setValue(ADC_Digital);
              ui->lcdNumber->display(ADC_Flotante);
          }
      }


  }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *cronometro=new QTimer(this);
     connect(cronometro, SIGNAL(timeout()), this, SLOT(fTimer()));
     cronometro->start(500);


    arduino_is_available = false;
    arduino_port_name = "";
    led_count1 = 0;
    led_count2 = 0;
    arduino = new QSerialPort;
    qDebug() << "No. of Available Ports: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }

    }
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                     arduino_port_name = serialPortInfo.portName();
                     arduino_is_available = true;
                }
            }
        }
    }

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
        {
        ui->comboBox->addItem(serialPortInfo.portName());
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_baud_returnPressed()
{
    QString bauds = ui->baud->text();
    int vbauds = bauds.toInt();
    if(vbauds == 9600){
        arduino ->setBaudRate(QSerialPort::Baud9600);
        ui->pushButton_3->setEnabled(true);
    }
    else{
        ui->baud->clear();
        ui->pushButton_3->setEnabled(false);
    }

}

void MainWindow::on_pushButton_3_clicked(bool checked)
{
    if(arduino_is_available){
        arduino ->setPortName(arduino_port_name);
        if (ui->pushButton_3->isChecked()){
            arduino->open(QIODevice::ReadWrite);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            ui->pushButton_3->setText("Desconectar");
        }
        else{
            arduino->close();
            QMessageBox::information(this,"Fin de Comunicación","Comunicación Serial Terminada!");
            ui->pushButton_3->setText("Conectar");
        }
    }
}





