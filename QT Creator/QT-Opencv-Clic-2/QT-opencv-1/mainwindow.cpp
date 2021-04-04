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
#include"mat2qimage.h"
#include<QMouseEvent>

using namespace cv;
VideoCapture camara1(1);
bool primeraVez = false;
Point origenMouse;
Size tamanioMouse;

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

void MainWindow::funcionActivacionTimer(){
    //Aqui se captura la imagen de camara IP cada 30ms
    if(camara1.isOpened()){   //Paso # 1
        Mat IMAGEN;
        Mat IMAGENpequena;
        camara1 >> IMAGEN;     //Paso # 2
        cv::resize(IMAGEN,IMAGENpequena,Size(640,360));  //Paso # 3

        Point Origen;
        Size tamanio;

        if(ui->checkBox->isChecked()){
            Origen.x = origenMouse.x;
            Origen.y = origenMouse.y;
            tamanio.width = tamanioMouse.width;
            tamanio.height = tamanioMouse.height;
        }
        else{
            Origen.x = ui->P0X->text().toInt();
            Origen.y = ui->P0Y->text().toInt();
            tamanio.width = ui->ANCHO->text().toInt();
            tamanio.height = ui->LARGO->text().toInt();
        }


        Rect roi1(Origen,tamanio);




        if(Origen.x > 0 && Origen.y > 0 && tamanio.width > 0 && tamanio.height > 0){

            //Extraer la ROI de la IMAGENpequena
            Mat imagenROI = IMAGENpequena(roi1);
            Mat imagenROIGRANDE;
            cv::resize(imagenROI,imagenROIGRANDE,Size(200,200));


            QImage qImage2 = Mat2QImage(imagenROIGRANDE);
            QPixmap pixmap2 = QPixmap::fromImage(qImage2);
            ui->label_6->clear();
            ui->label_6->setPixmap(pixmap2);
        }

        //Dibujar un rectangulo del tamanio de la ROI en IMAGENPequena
        rectangle(IMAGENpequena,roi1,Scalar(0,0,255),5,8,0);
        circle(IMAGENpequena, Origen, 10, Scalar(0,255,0),4,8,0);
        //Las siguientes 4 instrucciones representan al Paso # 4
        QImage qImage = Mat2QImage(IMAGENpequena);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->label->clear();
        ui->label->setPixmap(pixmap);





    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(30);


    if(!camara1.isOpened()) {
        camara1.open(0);

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
