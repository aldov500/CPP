#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent):QDialog(parent),ui(new Ui::Dialog){
    ui->setupUi(this);

    mThread = new MyThread(this);
    connect(mThread, SIGNAL(NumberChange(int)),this,SLOT(onNumberChange(int)));

//    mThread2 = new MyThread(this);
//    connect(mThread2, SIGNAL(NumberChange(int)),this,SLOT(onNumberChange2(int)));

//    mThread3 = new MyThread(this);
//    connect(mThread3, SIGNAL(NumberChange(int)),this,SLOT(onNumberChange3(int)));

    Counter = new QTimer(this);
    connect(Counter,SIGNAL(timeout()),this,SLOT(startCount()));

//    Counter2 = new QTimer(this);
//    connect(Counter2,SIGNAL(timeout()),this,SLOT(startCount2()));

//    Counter3 = new QTimer(this);
//    connect(Counter3,SIGNAL(timeout()),this,SLOT(startCount3()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::startCount(){
    mThread->run();
}

void Dialog::startCount2(){
    mThread2->run();
}

void Dialog::startCount3(){
    mThread3->run();
}

void Dialog::on_pushButton_clicked()
{
    Counter->start(25);
    Counter2->start(25);
    Counter3->start(25);
}

void Dialog::on_pushButton_2_clicked()
{
    Counter->stop();
    Counter2->stop();
    Counter3->stop();
}

static cv::VideoCapture VC_LaptopCam(0);

void Dialog::onNumberChange(int number){

    cv::Mat M_LaptopCam;
    cv::Mat M_LaptopCamRes;

    VC_LaptopCam >> M_LaptopCam;

    cv::resize(M_LaptopCam, M_LaptopCamRes, cv::Size(200,150),0,0,0);

    QImage QI_LaptopCam     = Mat2QImage(M_LaptopCamRes);
    QPixmap QP_LaptopCam    = QPixmap::fromImage(QI_LaptopCam);

    ui->label->clear();
    ui->label->setPixmap(QP_LaptopCam);

    ui->label_3->setNum(number);
}



void Dialog::onNumberChange2(int number){
    cv::VideoCapture VC_RemoteCam("http://192.168.0.5:8080/video");
    cv::Mat M_RemoteCam;
    cv::Mat M_RemoteCamRes;

    VC_RemoteCam >> M_RemoteCam;

    cv::resize(M_RemoteCam, M_RemoteCamRes, cv::Size(200,150),0,0,0);

    QImage QI_RemoteCam     = Mat2QImage(M_RemoteCamRes);
    QPixmap QP_RemoteCam    = QPixmap::fromImage(QI_RemoteCam);


    ui->label_2->clear();
    ui->label_2->setPixmap(QP_RemoteCam);

    ui->label_4->setNum(number);
}



void Dialog::onNumberChange3(int number){
    cv::VideoCapture VC_RemoteCam2("http://192.168.0.6:8080/video");
    cv::Mat M_RemoteCam2;
    cv::Mat M_RemoteCamRes2;

    VC_RemoteCam2 >> M_RemoteCam2;

     cv::resize(M_RemoteCam2, M_RemoteCamRes2, cv::Size(200,150),0,0,0);

     QImage QI_RemoteCam     = Mat2QImage(M_RemoteCamRes2);
     QPixmap QP_RemoteCam    = QPixmap::fromImage(QI_RemoteCam);


     ui->label_5->clear();
     ui->label_5->setPixmap(QP_RemoteCam);

     ui->label_6->setNum(number);
}
