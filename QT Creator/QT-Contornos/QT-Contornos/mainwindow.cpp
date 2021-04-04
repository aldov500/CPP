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

using namespace cv;
using namespace std;
VideoCapture camara(0);

int contadorObjeto = 0;
bool primeraVez = true;

Mat IMAGEN;   //Para guardar la imagen que se abrirá
Mat IMAGENchica;    //Guardará la imagen pequeña
Mat ImagenHSV;   //Aquí se guarda la imagen HSV
Mat ImagenDesenfoque;  //Para la imagen con desenfoque
Mat ImagenFiltrada;  //Para la imagen binaria que resulta de inRange

RNG rng(12345); //Variable para generar numeros aleatorios

void MainWindow::ftimer(){
    Point2f centro;
    if(ui->checkBox->isChecked()){
    if(camara.isOpened()){
       camara >> IMAGEN;
       cv::resize(IMAGEN,IMAGENchica,Size(150,150));
       //Paso # 1 - Adaptar la imagen a la etiqueta

       cv::resize(IMAGEN,IMAGENchica,Size(150,150));

       //Paso # 2 - Procesar la imagen chica para obtener un desenfoque

       GaussianBlur(IMAGENchica, ImagenDesenfoque, Size(3,3),0,0,0);

       //Paso # 3 - Procesar la imagen anterior para obtener HSV

       //cvtColor(ImagenDesenfoque,ImagenHSV,CV_BGR2HSV);
       cvtColor(IMAGENchica,ImagenHSV,CV_BGR2HSV);

       //Paso # 4 - Mostrar las imagenes en sus respectivas etiquetas

       QImage qImage = Mat2QImage(IMAGENchica);
       QPixmap pixmap = QPixmap::fromImage(qImage);
       ui->img->clear();
       ui->img->setPixmap(pixmap);

       qImage = Mat2QImage(ImagenDesenfoque);
       pixmap = QPixmap::fromImage(qImage);
       ui->img_blur->clear();
       ui->img_blur->setPixmap(pixmap);

       qImage = Mat2QImage(ImagenHSV);
       pixmap = QPixmap::fromImage(qImage);
       ui->img_hsv->clear();
       ui->img_hsv->setPixmap(pixmap);
    }
    else{
        camara.open(0);
    }
}
    //Paso # 1 – Procesar imagen anterior para filtro doble

    if(!ImagenHSV.empty()){
    int canal0Min = ui->b1_min->value();
    int canal0Max = ui->b1_max->value();
    int canal1Min = ui->b2_min->value();
    int canal1Max = ui->b2_max->value();
    int canal2Min = ui->b3_min->value();
    int canal2Max = ui->b3_max->value();

    inRange(IMAGENchica,Scalar(canal0Min,canal1Min,canal2Min),Scalar(canal0Max,canal1Max,canal2Max),ImagenFiltrada);

    vector<vector<Point>>contornos;
    vector<Vec4i>jerarquia;
    Mat copiaImagenFiltrada;
    copiaImagenFiltrada = ImagenFiltrada;
    findContours(copiaImagenFiltrada, contornos, jerarquia, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0,0));
    Mat drawing = Mat::zeros(copiaImagenFiltrada.size(), CV_8UC3);
    int area = 0;
    int areaMaxima = 0;
    int indiceJ = -1;
    for(int i=0; i< (int)contornos.size();i++){
        Scalar color = Scalar(rng.uniform(0,255), rng.uniform(0,255), rng.uniform(0,255));
        drawContours(drawing,contornos,i,color,2,8,jerarquia,0,Point());
        area=contourArea(contornos[i]);
        qDebug()<<"Area"<<i<<":"<<area;
        if(area>areaMaxima){
            areaMaxima=area;
            indiceJ = i;
        }
    }
    //Si se encontro un contorno, encuentra el origen o el centro
    if(indiceJ >= 0){
        //Declarar clase moments
        Moments momento0;

        //Encontar el momento del indiceJ
        momento0 = moments(contornos[indiceJ]);

        //Calcular el centro del momento
        centro = Point2f(static_cast<float>(momento0.m10/momento0.m00), static_cast<float>(momento0.m01/momento0.m00));

        circle(drawing,centro,10,Scalar(255,255,255),2,8,0);

        if(ui->checkBox_2->isChecked()){
            if(centro.y > 70){
                if(primeraVez == true){
                    contadorObjeto++;
                    ui->lcdNumber->display(contadorObjeto);
                    primeraVez = false;
                }
            }
            else{
                primeraVez = true;
            }
        }
    }

    line(drawing,Point(0,70),Point(149,70),Scalar(255,255,255),2,8,0);

    QImage qImage = Mat2QImage(drawing);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->img_Contornos->clear();
    ui->img_Contornos->setPixmap(pixmap);
    qImage = Mat2QImage(ImagenFiltrada);
    pixmap = QPixmap::fromImage(qImage);
    ui->img_inRange->clear();
    ui->img_inRange->setPixmap(pixmap);
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *cronometro = new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(ftimer()));
    cronometro->start(100);
   // camara.open(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b1_min_sliderMoved(int position)
{
    ui->lcd_b1_min->display(position);
}

void MainWindow::on_b2_min_sliderMoved(int position)
{
    ui->lcd_b2_min->display(position);
}

void MainWindow::on_b3_min_sliderMoved(int position)
{
    ui->lcd_b3_min->display(position);
}

void MainWindow::on_b1_max_sliderMoved(int position)
{
    ui->lcd_b1_max->display(position);
}

void MainWindow::on_b2_max_sliderMoved(int position)
{
    ui->lcd_b2_max->display(position);
}

void MainWindow::on_b3_max_sliderMoved(int position)
{
    ui->lcd_b3_max->display(position);
}

void MainWindow::on_pushButton_clicked()
{
    if(!ui->checkBox->isChecked()){
    QString nombreImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), "/home/rex/Imágenes", tr("Imagenes (*.png *.jpg *.bmp)"));
    IMAGEN = imread(nombreImagen.toUtf8().constData());

    //Paso # 1 - Adaptar la imagen a la etiqueta

    cv::resize(IMAGEN,IMAGENchica,Size(150,150));

    //Paso # 2 - Procesar la imagen chica para obtener un desenfoque

    GaussianBlur(IMAGENchica, ImagenDesenfoque, Size(3,3),0,0,0);

    //Paso # 3 - Procesar la imagen anterior para obtener HSV

    //cvtColor(ImagenDesenfoque,ImagenHSV,CV_BGR2HSV);
    cvtColor(IMAGENchica,ImagenHSV,CV_BGR2HSV);

    //Paso # 4 - Mostrar las imagenes en sus respectivas etiquetas

    QImage qImage = Mat2QImage(IMAGENchica);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->img->clear();
    ui->img->setPixmap(pixmap);

    qImage = Mat2QImage(ImagenDesenfoque);
    pixmap = QPixmap::fromImage(qImage);
    ui->img_blur->clear();
    ui->img_blur->setPixmap(pixmap);

    qImage = Mat2QImage(ImagenHSV);
    pixmap = QPixmap::fromImage(qImage);
    ui->img_hsv->clear();
    ui->img_hsv->setPixmap(pixmap);
    }
}
