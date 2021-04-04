#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conexion Arduino
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;

    QTimer* cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(loop()));
    cronometro->start(500);

}

MainWindow::~MainWindow()
{
    arduino->close();
    delete ui;
}

void MainWindow::loop(){
    if(!arduino_is_available){
        ui->label_6->clear();
        ui->label_6->setText("Arduino NO conectado.");

        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            ui->label->clear();
            ui->label->setText("Puerto USB conectado.");

            if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
                if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                    if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                        arduino_port_name = serialPortInfo.portName();
                        arduino->setPortName(arduino_port_name);
                        arduino->open(QIODevice::ReadWrite);
                        arduino->setDataBits(QSerialPort::Data8);
                        arduino->setBaudRate(QSerialPort::Baud9600);
                        arduino->setParity(QSerialPort::NoParity);
                        arduino->setStopBits(QSerialPort::OneStop);
                        arduino->setFlowControl(QSerialPort::NoFlowControl);
                        arduino_is_available = true;

                        ui->label->clear();
                        ui->label->setText("Arduino conectado.");
                    }
                    else{
                        ui->label->clear();
                        ui->label->setText("El Arduino no corresponde");
                    }
                }
                else{
                    ui->label->clear();
                    ui->label->setText("Dispositivo no es Arduino");
                }
            }
            else{
                ui->label->clear();
                ui->label->setText("Dispositivo sin identificador");
            }
        }
    }

    else{
    ui->label->clear();
    }
}



void MainWindow::on_pushButton_clicked(bool checked){

    if(arduino_is_available){
        if(arduino->isWritable()){
            if(checked){
                arduino->write("0");
                ui->label->clear();
                ui->label->setText("Se escribió en Serial 0");
            }
            else{
                arduino->write("1");
                ui->label->clear();
                ui->label->setText("Se escribió en Serial 1");
            }
        }
        else{
            ui->label->clear();
            ui->label->setText("Arduino NO escribible.");
        }
    }

    else{
        arduino_is_available = false;
        ui->label->clear();
        ui->label->setText("Arduino NO conectado.");
    }
}


void MainWindow::on_pushButton_2_clicked(bool checked){
    if(arduino_is_available){
        if(arduino->isWritable()){
            if(checked){
                arduino->write("0");
                ui->label->clear();
                ui->label->setText("Se escribió en Serial 0");
            }
            else{
                arduino->write("1");
                ui->label->clear();
                ui->label->setText("Se escribió en Serial 1");
            }
        }
        else{
            ui->label->clear();
            ui->label->setText("Arduino NO escribible.");
        }
    }

    else{
        arduino_is_available = false;
        ui->label->clear();
        ui->label->setText("Arduino NO conectado.");
    }
}



void MainWindow::on_pushButton_3_clicked(bool checked){
    if(arduino_is_available){
        if(arduino->isWritable()){
            if(checked){
                arduino->write("0");
                ui->label->clear();
                ui->label->setText("Se escribió en Serial 0");
            }
            else{
                arduino->write("1");
                ui->label->clear();
                ui->label->setText("Se escribió en Serial 1");
            }
        }
        else{
            ui->label->clear();
            ui->label->setText("Arduino NO escribible.");
        }
    }

    else{
        arduino_is_available = false;
        ui->label->clear();
        ui->label->setText("Arduino NO conectado.");
    }

}
