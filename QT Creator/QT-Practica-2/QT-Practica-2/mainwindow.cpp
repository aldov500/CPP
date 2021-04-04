#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QFileDialog>
#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>
#include "mat2qimage.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QMouseEvent>

using namespace cv;
using namespace std;

//Camara a utilizar
VideoCapture camara1(0);

bool primeraVez = false;
Point origenMouse;
Size tamanioMouse;


Mat IMAGEN;   //Para guardar la imagen que se abrirá
Mat IMAGENchica;    //Guardará la imagen pequeña
Mat imagenROIGRANDE;
Mat ImagenHSV;   //Aquí se guarda la imagen HSV
Mat ImagenDesenfoque;  //Para la imagen con desenfoque
Mat ImagenFiltrada;  //Para la imagen binaria que resulta de inRange
int area2;

int r_canal0Min=0;
int r_canal0Max=78;
int r_canal1Min=35;
int r_canal1Max=68;
int r_canal2Min=86;
int r_canal2Max=178;

int g_canal0Min=45;
int g_canal0Max=103;
int g_canal1Min=101;
int g_canal1Max=157;
int g_canal2Min=0;
int g_canal2Max=75;

int b_canal0Min=95;
int b_canal0Max=161;
int b_canal1Min=0;
int b_canal1Max=62;
int b_canal2Min=23;
int b_canal2Max=66;

bool detectado = false;
bool puerta = false;


void MainWindow::mousePressEvent(QMouseEvent *evento){
    //Coordenadas de toda la ventana
    int xGlobal = evento->x();
    int yGlobal = evento->y();

    if(xGlobal >= 0 && xGlobal <640 && yGlobal >= 0 && yGlobal <360){
        //Ocurrio dentro de la etiqueta

        //Detectar el clic 1 y el clic 2
        if(!primeraVez){
            primeraVez = true;
            origenMouse.x = xGlobal;
            origenMouse.y = yGlobal;
            tamanioMouse.width = 0;
            tamanioMouse.height = 0;
        }
        else{
            primeraVez = false;
            tamanioMouse.width = xGlobal - origenMouse.x;
            tamanioMouse.height = yGlobal - origenMouse.y;

        }
    }
}


void MainWindow::detectarColor(int c0_max, int c0_min, int c1_max, int c1_min, int c2_max, int c2_min){
    //Extraemos un color con inRange
    inRange(imagenROIGRANDE,Scalar(c0_min,c1_min,c2_min),Scalar(c0_max,c1_max,c2_max),ImagenFiltrada);
    //Creamos un vector de vectores para guardar el contorno
    vector<vector<Point>>contornos;
    vector<Vec4i>jerarquia;
    Mat copiaImagenFiltrada; //Copiamos la imagen ya filtrada
    copiaImagenFiltrada = ImagenFiltrada;
    //Aplicamos findCountours para encontrar los puntos que conformar los contornos
    findContours(copiaImagenFiltrada, contornos, jerarquia, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0,0));
    int area = 0;
    area2 = 0;
    for(int i=0; i< (int)contornos.size();i++){
        area=contourArea(contornos[i]); //Guarda el area de cada contorno detectado
        qDebug()<<"Area"<<i<<":"<<area; //Muestra en consola el area
        if(area>area2){
            area2=area; //Guardamos en area 2 el area mas grande detectado
        }
    }
    if(area2>5){ //Si obtenemos un area mayor a 5 el objeto es detectado
        detectado=true;
    }
    else {
        detectado=false;
    }
}

void MainWindow::ftimer(){
    //Aqui se captura la imagen de camara IP cada 10ms
    if(camara1.isOpened()){
        camara1 >> IMAGEN; //Se guarda imagen en matriz
        cv::resize(IMAGEN,IMAGENchica,Size(200,150)); //Se redimensiona la imagen

        Point Origen;
        Size tamanio;

        if(ui->checkBox->isChecked()){
            Origen.x = origenMouse.x;
            Origen.y = origenMouse.y;
            tamanio.width = tamanioMouse.width;
            tamanio.height = tamanioMouse.height;
        }

        Rect roi1(Origen,tamanio);

        if(Origen.x > 0 && Origen.y > 0 && tamanio.width > 0 && tamanio.height > 0){

            //Extraer la ROI de la IMAGENpequena
            Mat imagenROI = IMAGENchica(roi1);
            cv::resize(imagenROI,imagenROIGRANDE,Size(200,150));

            QImage qImage2 = Mat2QImage(imagenROIGRANDE);
            QPixmap pixmap2 = QPixmap::fromImage(qImage2);
            ui->img_2->clear();
            ui->img_2->setPixmap(pixmap2);
        }
        //Dibujar un rectangulo del tamanio de la ROI en IMAGENPequena
        rectangle(IMAGENchica,roi1,Scalar(0,0,255),5,8,0);
        circle(IMAGENchica, Origen, 10, Scalar(0,255,0),4,8,0);

        //Las siguientes 4 instrucciones se usan para mostrar la imagen original
        QImage qImage = Mat2QImage(IMAGENchica);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->img->clear();
        ui->img->setPixmap(pixmap);
    }

    if(!imagenROIGRANDE.empty() && !puerta){
        detectarColor(r_canal0Max,r_canal0Min,r_canal1Max,r_canal1Min,r_canal2Max,r_canal2Min);
        QImage qImage2 = Mat2QImage(ImagenFiltrada);
        QPixmap pixmap2 = QPixmap::fromImage(qImage2);
        ui->img_inRange->clear();
        ui->img_inRange->setPixmap(pixmap2);
        if(detectado){
            ui->mensaje->setText("Rojo Detectado");
            if(arduino_isAvailable){
                arduino->write("%0\n");
                arduino->write("$\n");
                puerta = true;
            }
        }
        else {
            detectarColor(g_canal0Max,g_canal0Min,g_canal1Max,g_canal1Min,g_canal2Max,g_canal2Min);
            qImage2 = Mat2QImage(ImagenFiltrada);
            pixmap2 = QPixmap::fromImage(qImage2);
            ui->img_inRange->clear();
            ui->img_inRange->setPixmap(pixmap2);
            if(detectado){
                ui->mensaje->setText("Verde Detectado");
                if(arduino_isAvailable){
                    arduino->write("%90\n");
                    arduino->write("$\n");
                    puerta = true;
                }
            }
            else {
                detectarColor(b_canal0Max,b_canal0Min,b_canal1Max,b_canal1Min,b_canal2Max,b_canal2Min);
                qImage2 = Mat2QImage(ImagenFiltrada);
                pixmap2 = QPixmap::fromImage(qImage2);
                ui->img_inRange->clear();
                ui->img_inRange->setPixmap(pixmap2);
                if(detectado){
                    ui->mensaje->setText("Azul Detectado");
                    if(arduino_isAvailable){
                        arduino->write("%180\n");
                        arduino->write("$\n");
                        puerta = true;
                    }
                }
                else {
                    ui->mensaje->setText("Nada Detectado");
                }
            }
        }
    }
    else {
        ui->mensaje->setText("Puerta abierta");
    }
}

void MainWindow::buscaYconectaArduino(){
    //Parte # 1, declaración inicial de las variables
    arduino_isAvailable = false;
    arduinoPort = "";
    arduino = new QSerialPort(this);
    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::recepcionSerialAsyncrona);
    QString serialName = "";
    int serialProductID = 0;

    //Parte # 2,buscar puertos con los identificadores de Arduino
    qDebug() << "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo& serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier()) {
            qDebug() << "ID Vendedor " << serialPortInfo.vendorIdentifier();
            qDebug() << "ID Producto: " << serialPortInfo.productIdentifier();

            if (serialPortInfo.productIdentifier() == arduino_UNO || serialPortInfo.productIdentifier() == arduino_MEGA) {
                arduino_isAvailable = true;
                serialName = serialPortInfo.portName();
                serialProductID = serialPortInfo.productIdentifier();
            }
        }
    }
    //Parte # 3, conexión del puerto encontrado con Arduino
    if (arduino_isAvailable) {
        arduinoPort = serialName;
        arduino->setPortName(arduinoPort);
        arduino->open(QIODevice::ReadWrite);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        ui->estado->clear();
        qDebug() << "Producto: " << serialProductID;
        if (serialProductID == arduino_UNO)
            ui->estado->setText("Arduino UNO R3 conectado");
        else if (serialProductID == arduino_MEGA)
            ui->estado->setText("Arduino MEGA conectado");
        else
            ui->estado->setText("Error 3");
    }
    else {
        ui->estado->clear();
        ui->estado->setText("No hay arduino");
    }
}

void MainWindow::recepcionSerialAsyncrona(){
    if(arduino_isAvailable && arduino->isReadable()){
        //QByteArray datosLeidos = arduino->readAll();
        QByteArray datosLeidos = arduino->readLine();
        int indice0 = datosLeidos.indexOf("\n");
        int indice1 = datosLeidos.indexOf("@");
        QString infoExtraida = datosLeidos.mid(indice1+1,(indice0-indice1));
        int datoEntero = infoExtraida.toInt();
        qDebug() << "Dato: " << datoEntero << endl;
        if(indice0>=0 && indice1>=0) {
                puerta=false;
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buscaYconectaArduino(); //Realiza una busqueda y conecta con arduino

    //Creando timer para la funcion ftimer
    QTimer *cronometro = new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(ftimer()));
    cronometro->start(10);

    //Abrir camara
    if(!camara1.isOpened()) {
        camara1.open(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Las siguientes 6 funciones muestran el valor de cada slider en su respectivo lcd
void MainWindow::on_c0_min_valueChanged(int value)
{
    ui->lcd_c0_min->display(value);
}

void MainWindow::on_c1_min_valueChanged(int value)
{
    ui->lcd_c1_min->display(value);
}

void MainWindow::on_c2_min_valueChanged(int value)
{
    ui->lcd_c2_min->display(value);
}

void MainWindow::on_c0_max_valueChanged(int value)
{
    ui->lcd_c0_max->display(value);
}

void MainWindow::on_c1_max_valueChanged(int value)
{
    ui->lcd_c1_max->display(value);
}

void MainWindow::on_c2_max_valueChanged(int value)
{
    ui->lcd_c2_max->display(value);
}
