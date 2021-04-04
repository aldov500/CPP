#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

VideoCapture camara1(0);    //Abre la camara de la laptop

Mat IMAGENsmall;
Mat IMAGEN;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!camara1.isOpened()) {
        camara1.open("http://192.168.0.6:8080/video");
    }

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){

    camara1 >> IMAGEN;
    cv::resize(IMAGEN,IMAGENsmall,Size(500,400),0,0,0);

    QImage qImage = Mat2QImage(IMAGENsmall);
    QPixmap pixmap = QPixmap::fromImage(qImage);

    ui->label->clear();
    ui->label->setPixmap(pixmap);
}
