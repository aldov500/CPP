#include "mainwindow.h"
#include "ui_mainwindow.h"

#define IPCam01   "http://192.168.0.4:8080/video"
#define IPCam02   0//  "http://192.168.43.1:8080/video"


cv::VideoCapture cam1(IPCam01);
cv::VideoCapture cam2(IPCam02);

QString path ="/home/ikhsan/Maildir/process/landing";
QString destinatario = "aldo.vargas.meza94@gmail.com";
QString command = "mpack -s subject picture.png "  + destinatario;
int count;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    QTimer* cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(loop()));
    cronometro->start(30);

    QTimer* cronometro2 = new QTimer(this);
    connect(cronometro2, SIGNAL(timeout()), this, SLOT(loop2()));
    cronometro2->start(100);

    if(!cam1.isOpened() || !cam2.isOpened()){
        cam1.open(IPCam01);
        cam2.open(IPCam02);
    }

    ui->label->clear();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::loop(){


    if(cam2.isOpened() && ui->radioButton_2->isChecked()){
        Mat img1, img2;
        cam2 >> img1;
        cv::resize(img1,img2,Size(200,150),0,0,0);
        QImage qImage = Mat2QImage(img2);
        QPixmap pixmap = QPixmap::fromImage(qImage);

        ui->label->clear();
        ui->label->setPixmap(pixmap);

    }
    else if(cam1.isOpened() && ui->radioButton->isChecked()){
        Mat img1, img2;
        cam1 >> img1;
        cv::resize(img1,img2,Size(200,150),0,0,0);
        QImage qImage = Mat2QImage(img2);
        QPixmap pixmap = QPixmap::fromImage(qImage);

        ui->label->clear();
        ui->label->setPixmap(pixmap);

    }
}

void MainWindow::loop2(){

    QDirIterator dir(path, QDir::NoFilter);
    count = 0;

    while(dir.hasNext()){

        QFileInfo infoArchivo(dir.next());
        if(infoArchivo.isFile() && infoArchivo.exists()){
            count++;

            int arr = destinatario.indexOf("@");
            int com = destinatario.indexOf(".com");

            if(arr>=0 && com>= 0){
                Mat IMAGEN;
                if(ui->radioButton->isChecked()){
                    cam1 >> IMAGEN;
                }else if(ui->radioButton_2->isChecked()){
                    cam2 >> IMAGEN;
                }
                else{
                    ui->label->clear();
                }

               cv::imwrite("picture.png",IMAGEN);
               system(command.toUtf8().constData());
            }

        }

    }


}

void MainWindow::on_radioButton_3_clicked(){
    cam1.release();
    cam2.release();
    ui->label->clear();
}

void MainWindow::on_pushButton_3_clicked(){
   QString camP1 = ui->lineEdit->text();
   ui->label_2->setText(camP1);
   QString camP2 = ui->lineEdit_2->text();

   if(ui->radioButton->isChecked() && !camP1.isEmpty()){
       cam1.open(camP1.toUtf8().constData());

   }
   else if(ui->radioButton_2->isChecked() && !camP2.isEmpty()){
       cam2.open(camP2.toUtf8().constData());

   }




}
