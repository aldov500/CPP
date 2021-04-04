#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
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
VideoCapture camara(0);

void MainWindow::ftimer(){
    if(camara.isOpened()){
       Mat COLOR, IMGchica, HSV, GRIS,HLS;
       camara >> COLOR;
       cv::resize(COLOR,IMGchica,Size(320,180));
       cvtColor(IMGchica,HSV,CV_BGR2HSV);
       cvtColor(IMGchica,GRIS,CV_BGR2GRAY);
       cvtColor(IMGchica,HLS,CV_BGR2HLS_FULL);

       ui->LCOLOR->clear();
       ui->LGRIS->clear();
       ui->LHLS->clear();
       ui->LHSV->clear();

       QImage img1 = Mat2QImage(IMGchica);
       QPixmap img2 = QPixmap::fromImage(img1);
       ui->LCOLOR->setPixmap(img2);

       img1 = Mat2QImage(HSV);
       img2 = QPixmap::fromImage(img1);
       ui->LHSV->setPixmap(img2);

       img1 = Mat2QImage(HLS);
       img2 = QPixmap::fromImage(img1);
       ui->LHLS->setPixmap(img2);

       img1 = Mat2QImage(GRIS);
       img2 = QPixmap::fromImage(img1);
       ui->LGRIS->setPixmap(img2);


    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *cronometro = new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(ftimer()));
    cronometro->start(50);

    camara.open(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}
