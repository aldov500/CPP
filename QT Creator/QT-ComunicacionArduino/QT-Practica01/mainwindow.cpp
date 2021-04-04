#include "mainwindow.h"
#include "stdlib.h"
#include "ui_mainwindow.h"
/* Limite definido para sensor analogico */
#define ABOUND 750
/* Variables para fecha y hora */
QDate date;
QTime hour;
QString dateTime;
/* Varibales para evento analogico */
bool RadioFlag, analogEvent;
int analogBound;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /* Variables de control */
    analogBound = 0;
    RadioFlag = false;
    analogEvent = false;

    ui->setupUi(this);
    ui->labelStatus->setText("Esperando configuración...");
    connectArduino();

    /* Variables de QTimer y QProcess */
    QTimer* QTimer100MS = new QTimer(this);
    connect(QTimer100MS, SIGNAL(timeout()), this, SLOT(loop_100ms()));
    QTimer100MS->start(100);

    emailProcess = new QProcess(this);


}

void MainWindow::loop_100ms()
{
    /*Obtiene la hora y fecha actual */
    date = QDate::currentDate();
    hour = QTime::currentTime();
    dateTime = hour.toString() + ",  " + date.toString();
    ui->labelStatus->setText(dateTime);
    /* Inicia las funciones radiales principales */
    RadialEventButtonAnalogSwitcher(RadioFlag);
}

/* Funcionamiento de los botones radiales principales */
void MainWindow::RadialEventButtonAnalogSwitcher(bool FLAG)
{
    if ((FLAG) && (ui->radioButtonButon->isChecked())) {
        if (Arduino_isAvailable && Arduino->isReadable()) {

            QByteArray datosLeidos = Arduino->readLine();
            int indice0 = datosLeidos.indexOf("\n");
            int indice1 = datosLeidos.indexOf("@");
            QString infoExtraida = datosLeidos.mid(indice1 + 1, (indice0 - indice1));
            int datoEntero = infoExtraida.toInt();

            qDebug() << "Dato: " << datoEntero << endl;

            if (indice0 >= 0 && indice1 >= 0) {
                qDebug() << "Datos extraidos: " << infoExtraida.toUtf8().constData();
                qDebug() << "Datos leidos: " << datosLeidos << endl;
                ui->progressBar->setValue(datoEntero);
                registerEvent("CONTADOR", QString::number(datoEntero));

                if (datoEntero == 20) {
                    sendEmailNow();
                }
            }
        }
    } else if ((!FLAG) && (ui->radioButtonAnalogic->isChecked())) {

        if (Arduino_isAvailable && Arduino->isWritable()) {
            Arduino->write("5\n");

            if (Arduino->isReadable()) {
                QByteArray datoLeido = Arduino->readAll();
                ui->lcdNumberAnalogicResult->display(datoLeido.toInt());
                ui->progressBarAnalogic->setValue(datoLeido.toInt());

                if (datoLeido.toInt() > ABOUND) {
                    if (datoLeido.toInt() > analogBound) {
                        analogBound = datoLeido.toInt();
                    }

                } else {
                    if (analogBound > ABOUND) {
                        analogEvent = true;
                    }
                }
            }
        }

        if (analogEvent) {
            registerEvent("ILUMINACION ELEVADA", QString::number(analogBound));
            analogBound = 0;
            analogEvent = false;
        }
    }
}


/* Funciones de Radial Buttons, donde envian un caracter correspondiente y registran evento  */

void MainWindow::on_radioButton13_clicked()
{
    /* Enciende el LED */
    if (Arduino_isAvailable && Arduino->isReadable()) {
        Arduino->write("1\n");
    } else {
        qDebug() << "Error con Arduino";
    }
    /* Registra el Evento */
    registerEvent("LED ROJO", "ENCENDIDO");
}

void MainWindow::on_radioButton12_clicked()
{
    if (Arduino_isAvailable && Arduino->isReadable()) {
        Arduino->write("2\n");
    } else {
        qDebug() << "Error con Arduino";
    }

    /* Registra el Evento */
    registerEvent("LED AMARILLO", "ENCENDIDO");
}

void MainWindow::on_radioButton11_clicked()
{
    if (Arduino_isAvailable && Arduino->isReadable()) {
        Arduino->write("3\n");
    } else {
        qDebug() << "Error con Arduino";
    }

    /* Registra el Evento */
    registerEvent("LED VERDE", "ENCENDIDO");
}

void MainWindow::on_radioButton10_clicked()
{
    if (Arduino_isAvailable && Arduino->isReadable()) {
        Arduino->write("4\n");
    } else {
        qDebug() << "Error con Arduino";
    }
    /* Registra el Evento */
    registerEvent("LED BLANCO", "ENCENDIDO");
}

/* Funcion para reconectar el objeto serial */

void MainWindow::on_pushButtonConnect_clicked()
{
    Arduino->close();
    connectArduino();
}

void MainWindow::on_pushButtonReset_clicked()
{
    /* Limpia los campos y salidas de la interfaz */
    ui->lineEditEmail->clear();
    ui->lineEditFile->clear();
    ui->progressBar->setValue(0);
    ui->progressBarAnalogic->setValue(0);
}

void MainWindow::on_pushButtonEmail_clicked()
{
    /* Envía archivo Email especificado */
    sendEmailNow();
}

/* Control de las banderas del funcionamiento */
void MainWindow::on_radioButtonButon_clicked(bool checked)
{
    RadioFlag = checked;
}

void MainWindow::on_radioButtonAnalogic_clicked(bool checked)
{
    RadioFlag = !checked;
}

/* Conexion del objeto serial */
void MainWindow::connectArduino()
{
    //Parte # 1, declaración inicial de las variables
    Arduino_isAvailable = false;
    ArduinoPort = "";
    Arduino = new QSerialPort;

    QString serialName = "";
    int serialProductID = 0;

    //Parte # 2,buscar puertos con los identificadores de Arduino
    qDebug() << "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo& serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier()) {
            qDebug() << "ID Vendedor " << serialPortInfo.vendorIdentifier();
            qDebug() << "ID Producto: " << serialPortInfo.productIdentifier();

            if (serialPortInfo.productIdentifier() == ARDUINO_UNO || serialPortInfo.productIdentifier() == ARDUINO_MEGA || serialPortInfo.productIdentifier() == ARDUINO_NANO) {
                Arduino_isAvailable = true;
                serialName = serialPortInfo.portName();
                serialProductID = serialPortInfo.productIdentifier();
            }
        }
    }

    //Parte # 3, conexión del puerto encontrado con Arduino

    if (Arduino_isAvailable) {
        ArduinoPort = serialName;
        Arduino->setPortName(ArduinoPort);
        Arduino->open(QIODevice::ReadWrite);
        Arduino->setDataBits(QSerialPort::Data8);
        Arduino->setBaudRate(QSerialPort::Baud115200);
        Arduino->setParity(QSerialPort::NoParity);
        Arduino->setStopBits(QSerialPort::OneStop);
        Arduino->setFlowControl(QSerialPort::NoFlowControl);

        ui->labelConection->clear();
        qDebug() << "Producto: " << serialProductID;
        if (serialProductID == ARDUINO_UNO)
            ui->labelConection->setText("Arduino UNO R3 conectado");
        else if (serialProductID == ARDUINO_MEGA)
            ui->labelConection->setText("Arduino MEGA conectado");
        else if (serialProductID == ARDUINO_NANO)
            ui->labelConection->setText("Arduino NANO conectado");
        else
            ui->labelConection->setText("Error 3");

    } else {
        ui->labelConection->clear();
        ui->labelConection->setText("No hay arduino");
    }
}


/* Funcion que registra el evento en archivo */
void MainWindow::registerEvent(QString event, QString value)
{
    QString fileName;
    if (ui->lineEditFile->text().isEmpty()) {
        fileName = "unNamed.csv";
    } else {
        fileName = ui->lineEditFile->text() + ".csv";
    }

    QFile csvFile(fileName);
    QFileInfo dataOfFile(fileName);

    /* Archivo creado por primera vez */
    if (!dataOfFile.exists()) {
        csvFile.open(QIODevice::WriteOnly);
        QTextStream out(&csvFile);
        out << "EVENTO"
            << ",";
        out << "VALOR"
            << ",";
        out << "EMAIL"
            << ",";
        out << "FECHA"
            << ",";
        out << "HORA \n";
        csvFile.close();
    }

    if (dataOfFile.isFile() && dataOfFile.exists()) {
        if (csvFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream out(&csvFile);
            out << event.toUtf8().constData() << ",";
            out << value.toUtf8().constData() << ",";

            if (ui->lineEditEmail->text().isEmpty()) {
                out << "N/A"
                    << ",";
            } else {
                out << ui->lineEditEmail->text().toUtf8().constData() << ",";
            }
            out << date.toString().toUtf8().constData() << ",";
            out << hour.toString().toUtf8().constData() << "\n";
            csvFile.close();
        }
    }
}

/* Funcion que envía el correo */
void MainWindow::sendEmailNow()
{
    QString email = ui->lineEditEmail->text();
    QString file = ui->lineEditFile->text() + ".csv";
    QString command = "mpack -s Log_File " + file + " " + email;

    emailProcess->start(command);
}

/* Funcion destructora */
MainWindow::~MainWindow()
{
    Arduino->close();
    delete ui;
}
