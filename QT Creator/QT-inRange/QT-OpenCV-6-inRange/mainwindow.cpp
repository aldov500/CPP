#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>
#include "mat2qimage.h"   //Nota2
#include <QFileDialog>
#include <QTimer>
using namespace cv;

Mat IMAGEN;
Mat IMAGENchica;
Mat ImagenHSV;
Mat ImagenDesenfoque;
Mat ImagenFiltrada;

void MainWindow::ftimer(){
    //Paso # 1 - Procesar imagen anterior para filtro de ventana

    if(!ImagenHSV.empty()){
    int canal0Min = ui->barraCanal0Min->value();
    int canal0Max = ui->barraCanal0Max->value();
    int canal1Min = ui->barraCanal1Min->value();
    int canal1Max = ui->barraCanal1Max->value();
    int canal2Min = ui->barraCanal2Min->value();
    int canal2Max = ui->barraCanal2Max->value();





    inRange(IMAGENchica,Scalar(canal0Min,canal1Min,canal2Min),Scalar(canal0Max,canal1Max,canal2Max),ImagenFiltrada);

    QImage qImage = Mat2QImage(ImagenFiltrada);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->labelInrange->clear();
    ui->labelInrange->setPixmap(pixmap);
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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nombreImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), "/home/", tr("Imagenes (*.png *.jpg *.bmp)"));
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
    ui->labelColor->clear();
    ui->labelColor->setPixmap(pixmap);

    qImage = Mat2QImage(ImagenDesenfoque);
    pixmap = QPixmap::fromImage(qImage);
    ui->labelGauss->clear();
    ui->labelGauss->setPixmap(pixmap);

    qImage = Mat2QImage(ImagenHSV);
    pixmap = QPixmap::fromImage(qImage);
    ui->labelHSV->clear();
    ui->labelHSV->setPixmap(pixmap);





}



void MainWindow::on_barraCanal0Min_sliderMoved(int position)
{
    ui->lcdCanal0Min->display(position);
}

void MainWindow::on_barraCanal0Max_sliderMoved(int position)
{
    ui->lcdCanal0Max->display(position);
}

void MainWindow::on_barraCanal1Min_sliderMoved(int position)
{
    ui->lcdCanal1Min->display(position);
}

void MainWindow::on_barraCanal1Max_sliderMoved(int position)
{
    ui->lcdCanal1Max->display(position);
}

void MainWindow::on_barraCanal2Min_sliderMoved(int position)
{
    ui->lcdCanal2Min->display(position);
}

void MainWindow::on_barraCanal2Max_sliderMoved(int position)
{
    ui->lcdCanal2Max->display(position);
}
