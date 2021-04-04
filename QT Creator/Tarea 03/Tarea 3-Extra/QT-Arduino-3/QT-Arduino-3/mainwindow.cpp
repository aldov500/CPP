#include "mainwindow.h"
#include "ui_mainwindow.h"

/* Constructor de Clase MainWindow */
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /* Configuracion de Contexto para la interfaz de usuario */
    ui->setupUi(this);
    /* Inicializar valor de la barra de progreso */
    ui->progressBar->setValue(0);
    /* Conexion para el objeto de comunicacion serial */
    connectArduino();
}

/* Destructor de clase MainWindow */
MainWindow::~MainWindow()
{
    Arduino->close();
    delete ui;
}

/* Funcion para leer los datos enviados del objeto de Comunicacion Serial */
void MainWindow::serialReceiver()
{
    /* Variables para desempaquetar el dato recibido */
    int index0, index1;
    /* Variable para casting del Caracter enviado por Objeto Serial */
    int intData;
    /* Arreglo de Bites */
    QByteArray serialRead;
    /* Variable para el Caracter enviado por Objeto Serial*/
    QString extractedData;

    /* Evalua el objeto serial conectado y disponible */
    if (ArduinoIsConnected && Arduino->isReadable()) {
        /* Obtiene una lectura del objeto serial */
        serialRead = Arduino->readLine();

        /* Guarda los indices fronterizos del dato recibido */
        index0 = serialRead.indexOf("\n");
        index1 = serialRead.indexOf("@");

        /* Extraccion de datos desempaquetado */
        extractedData = serialRead.mid(index1 + 1, (index0 - index1));
        /* Guarda el valor del dato en entero */
        intData = extractedData.toInt();

        qDebug() << "Dato: " << intData << endl;

        /* Evalua que los indices fronterizos esten en posiciones correctas */
        if (index0 >= 0 && index1 >= 0) {

            qDebug() << "Datos extraidos: " << extractedData.toUtf8().constData();
            qDebug() << "Datos leidos: " << serialRead << endl;

            /* Carga el valor numerico en la barra de progreso */
            ui->progressBar->setValue(intData);
        }
    }
}

/*Funcion para Conectar el objeto serial */
void MainWindow::connectArduino()
{
    /* Bandera de control */
    ArduinoIsConnected = false;
    /* Inicializacion del objeto serial con un contexto */
    Arduino = new QSerialPort(this);

    /* Funcion de conexion */
    connect(Arduino, &QSerialPort::readyRead, this, &MainWindow::serialReceiver);

    /* Valores del dispositivo conectado serialmente */
    QString deviceName = "";
    int productID = 0;

    /* Busqueda de Puertos Libres */
    qDebug() << "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    /* Funcion ejecutada para cada puerto disponible */
    foreach (const QSerialPortInfo& serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier()) {
            qDebug() << "ID Vendedor " << serialPortInfo.vendorIdentifier();
            qDebug() << "ID Producto: " << serialPortInfo.productIdentifier();

            /* Condicion para nombrar el dispositivo */
            if (serialPortInfo.productIdentifier() == 66 || serialPortInfo.productIdentifier() == 67 || serialPortInfo.productIdentifier() == 29987) {
                /* Bnadera de conexion exitosa */
                ArduinoIsConnected = true;
                /* Extraccion de datos del dispositivo */
                deviceName = serialPortInfo.portName();
                productID = serialPortInfo.productIdentifier();
            }
        }
    }

    /* Si la conexion es exitosa */
    if (ArduinoIsConnected) {
        /* Configuración de objeto serial */
        Arduino->setPortName(deviceName);
        Arduino->open(QIODevice::ReadWrite);
        Arduino->setDataBits(QSerialPort::Data8);
        Arduino->setBaudRate(QSerialPort::Baud115200);
        Arduino->setParity(QSerialPort::NoParity);
        Arduino->setStopBits(QSerialPort::OneStop);
        Arduino->setFlowControl(QSerialPort::NoFlowControl);

        ui->label->clear();

        /* Impresion de informacion del dispositivo */
        qDebug() << "Producto: " << productID;

        if (productID == 67)
            ui->label->setText("Arduino UNO R3 conectado");
        else if (productID == 66)
            ui->label->setText("Arduino Mega conectado");
        else if (productID == 29987)
            ui->label->setText("Arduino Nano Conectado");
        else
            ui->label->setText("Error 3");

    }
    /* Conexion no exitosa */
    else {

        ui->label->clear();
        ui->label->setText("No hay Arduino");
    }
}
