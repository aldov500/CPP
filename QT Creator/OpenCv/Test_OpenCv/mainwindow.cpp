#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){   
//    int fps = 30;

//    QTimer* LaptopCam = new QTimer(this);
//    connect(LaptopCam,SIGNAL(timeout()),this,SLOT(laptopRecorder()));
//    LaptopCam->start(fps);

//    QTimer* RemoteCam = new QTimer(this);
//    connect(RemoteCam,SIGNAL(timeout()),this,SLOT(remoteRecorder()));
//    RemoteCam->start(fps);

    MultiCam = new CameraThreads(this);
    connect(MultiCam,SIGNAL(NumberChange(int)),this,SLOT(onNumberChange(int)));
    MultiCam->run();
    ui->setupUi(this);

} MainWindow::~MainWindow(){delete ui;}

/****************************************/
/****************************************/
    /* THREADS CON GUI ACTIVADA */
/****************************************/
/****************************************/

void MainWindow::onNumberChange(int number){

    ui->STC_Thread->setNum(number);

}

/****************************************/
/****************************************/
/* FUNCION VIDEOCAPTURE CAMARA INTEGRADA*/
/****************************************/
/****************************************/

static cv::VideoCapture VC_LaptopCam(0);
static cv::Mat M_LaptopCam;
static cv::Mat M_LaptopCamRes;
static int counterLap;

void MainWindow::laptopRecorder(){
    counterLap += 1;

    VC_LaptopCam >> M_LaptopCam;

    cv::resize(M_LaptopCam, M_LaptopCamRes, cv::Size(360,240),0,0,0);

    QImage QI_LaptopCam     = Mat2QImage(M_LaptopCamRes);
    QPixmap QP_LaptopCam    = QPixmap::fromImage(QI_LaptopCam);

    ui->LBL_LaptopCam->clear();
    ui->LBL_LaptopCam->setPixmap(QP_LaptopCam);

    ui->STC_Count->setNum(counterLap);
}

/****************************************/
/****************************************/
/* FUNCION VIDEOCAPTURE POR MEDIO DE IP */
/****************************************/
/****************************************/

static cv::VideoCapture VC_RemoteCam("http://192.168.0.5:8080/video");
static cv::Mat M_RemoteCam;
static cv::Mat M_RemoteCamRes;
static int counterRem;

void MainWindow::remoteRecorder(){
    counterRem += 1;

    VC_RemoteCam >> M_RemoteCam;

    cv::resize(M_RemoteCam, M_RemoteCamRes, cv::Size(360,240),0,0,0);

    QImage QI_RemoteCam     = Mat2QImage(M_RemoteCamRes);
    QPixmap QP_RemoteCam    = QPixmap::fromImage(QI_RemoteCam);


    ui->LBL_RemoteCam->clear();
    ui->LBL_RemoteCam->setPixmap(QP_RemoteCam);

    ui->STC_Count_2->setNum(counterRem);
}


void MainWindow::on_BTN_Start_clicked()
{
    MultiCam->run();
}

void MainWindow::on_BTN_Stop_clicked()
{
    MultiCam->Stop = true;
}
