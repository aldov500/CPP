#include "mainwindow.h"
#include "ui_mainwindow.h"

/* IP para conectar camara*/
#define IP  0   //"http://192.168.0.5:8080/video"
/* Constante para detector de pixeles */
#define LIM_DETECT 100

using namespace cv;

/* Variables globales */
VideoCapture camera(IP);
Mat matOriginal, matSmall, matHsv, matColor;

int arrRed[6], arrBlue[6], arrGreen[6];

int SIZEX = 300;
int SIZEY = 225;

/* Variables para pixeles */
int TotalNumberOfPixels = SIZEX * SIZEY;
int BlackPixels, WhitePixels;

/* Sliders */
int A1 = 0, A2 = 0;
int B1 = 0, B2 = 0;
int C1 = 0, C2 = 0;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*Inicializa los sliders*/
    fillColorArray(&arrRed[0]);
    fillColorArray(&arrGreen[0]);
    fillColorArray(&arrBlue[0]);

    /* Timer General */
    QTimer* newTimer = new QTimer(this);
    connect(newTimer, SIGNAL(timeout()), this, SLOT(loop()));
    newTimer->start(30);

    /* Abre camara IP */
    if (!camera.isOpened()) {
        camera.open(IP);
    }
}

void MainWindow::loop()
{
    if (camera.isOpened()) {
        /* Guarda imagen en matrices */
        camera >> matOriginal;

        /* Cambia de tamaña la matriz y la guarda en otra*/
        cv::resize(matOriginal, matSmall, Size(SIZEX, SIZEY), 0, 0, 0);
        /* Aplica filtro HSV*/
        cv::cvtColor(matSmall, matHsv, CV_BGR2HSV);
        /* Aplica funcion inRange con parametros de los sliders */
        cv::inRange(matHsv, Scalar(A1, B1, C1), Scalar(A2, B2, C2), matColor);
    }

    /* Si el botón de calibrar está presionado */
    if (ui->buttonCalibrate->isChecked()) {

        if (ui->radioButtonRed->isChecked()) {
            /* LLena el arreglo*/
            fillColorArray(&arrRed[0]);
        } else if (ui->radioButtonGreen->isChecked()) {
            fillColorArray(&arrGreen[0]);
        } else if (ui->radioButtonBlue->isChecked()) {
            fillColorArray(&arrBlue[0]);
        }

    } else {
        /* Si el boton no esta presionado detecta el color que esté en el radio */
        if (ui->radioButtonRed->isChecked()) {
            cv::inRange(matHsv, Scalar(arrRed[0], arrRed[2], arrRed[4]),
                Scalar(arrRed[1], arrRed[3], arrRed[5]), matColor);
            /* Detecta color */
            detectColor(&arrRed[0], "Rojo");
        } else if (ui->radioButtonGreen->isChecked()) {
            cv::inRange(matHsv, Scalar(arrGreen[0], arrGreen[2], arrGreen[4]),
                Scalar(arrGreen[1], arrGreen[3], arrGreen[5]), matColor);
            detectColor(&arrGreen[0], "Verde");
        } else if (ui->radioButtonBlue->isChecked()) {
            cv::inRange(matHsv, Scalar(arrBlue[0], arrBlue[2], arrBlue[4]),
                Scalar(arrBlue[1], arrBlue[3], arrBlue[5]), matColor);
            detectColor(&arrBlue[0], "Azul");
        }
    }

    /* Muestra imagenes en label*/
    QImage qImage = Mat2QImage(matSmall);
    QPixmap pixmap = QPixmap::fromImage(qImage);

    ui->labelIMG1->clear();
    ui->labelIMG1->setPixmap(pixmap);

    qImage = Mat2QImage(matColor);
    pixmap = QPixmap::fromImage(qImage);

    ui->labelIMG2->clear();
    ui->labelIMG2->setPixmap(pixmap);
}

void MainWindow::detectColor(int color[], QString led)
{
    /* Aplica filtro */
    cv::inRange(matHsv, Scalar(color[0], color[2], color[4]),
        Scalar(color[1], color[3], color[5]), matColor);
    /* Calculo de pixeles */
    BlackPixels = TotalNumberOfPixels - countNonZero(matColor);
    WhitePixels = TotalNumberOfPixels - BlackPixels;

    /* Deteccion */
    if (WhitePixels > LIM_DETECT) {
        if (Arduino_isAvailable) {
            if (Arduino->isWritable()) {
                if (led == "Rojo") {
                    Arduino->write("5"); // off Azul
                    Arduino->write("3"); // off Verde
                    Arduino->write("0"); // on rojo
                    ui->labelNotifications->setText("Detectado color Rojo");

                } else if (led == "Verde") {
                    Arduino->write("5"); // off Azul
                    Arduino->write("1"); // off Rojo
                    Arduino->write("2"); // on Verde
                    ui->labelNotifications->setText("Detectado color Verde");
                } else if (led == "Azul") {

                    Arduino->write("3"); // off Verde
                    Arduino->write("1"); // off Rojo
                    Arduino->write("4"); // on Azul
                    ui->labelNotifications->setText("Detectado color Azul");
                }
            }

        } else {
            ui->labelNotifications->setText("Arduino NO ESCRIBIBLE");
        }
    }

    else if (WhitePixels < 100) {
        Arduino->write("3"); // off Verde
        Arduino->write("1"); // off Rojo
        Arduino->write("5"); // off Azul
        ui->labelNotifications->setText("Deteccion en curso");
    }
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

        ui->labelNotifications->clear();
        qDebug() << "Producto: " << serialProductID;
        if (serialProductID == ARDUINO_UNO)
            ui->labelNotifications->setText("Arduino UNO R3 conectado");
        else if (serialProductID == ARDUINO_MEGA)
            ui->labelNotifications->setText("Arduino MEGA conectado");
        else if (serialProductID == ARDUINO_NANO)
            ui->labelNotifications->setText("Arduino NANO conectado");
        else
            ui->labelNotifications->setText("Error 3");

    } else {
        ui->labelNotifications->clear();
        ui->labelNotifications->setText("No hay Arduino");
    }
}

/* Llena el arreglo de matColores */
void MainWindow::fillColorArray(int* array)
{
    array[0] = A1;
    array[1] = A2;
    array[2] = B1;
    array[3] = B2;
    array[4] = C1;
    array[5] = C2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_verticalSlider_A1_sliderMoved(int position)
{
    A1 = position;
    ui->lcdNumber_A1->display(position);
}

void MainWindow::on_verticalSlider_B1_sliderMoved(int position)
{
    B1 = position;
    ui->lcdNumber_B1->display(position);
}

void MainWindow::on_verticalSlider_C1_sliderMoved(int position)
{
    C1 = position;
    ui->lcdNumber_C1->display(position);
}

void MainWindow::on_verticalSlider_A2_sliderMoved(int position)
{
    A2 = position;
    ui->lcdNumber_A2->display(position);
}

void MainWindow::on_verticalSlider_B2_sliderMoved(int position)
{
    B2 = position;
    ui->lcdNumber_B2->display(position);
}

void MainWindow::on_verticalSlider_C2_sliderMoved(int position)
{
    C2 = position;
    ui->lcdNumber_C2->display(position);
}
