/* QT Diseño de INterfaces
   Archivo de Funciones
   */

#include <QMainWindow>
#include <QTimer>

#include<mat2qimage.h>
#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>



void MainWindow::take_Picture(VideoCapture cam, Mat IMAGEN, Mat IMAGENsmall){
    int sizex = 500;
    int sizey = 400;

    cam >> IMAGEN;
    cv::resize(IMAGEN,IMAGENsmall,Size(sizex,sizey),0,0,0);

    QImage qImage = Mat2QImage(IMAGENsmall);
    QPixmap pixmap = QPixmap::fromImage(qImage);

    ui->label->clear();
    ui->label->setPixmap(pixmap);
}

void MainWindow::InitTimer(unsigned int delay){
	QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(TimerHandler()));
    cronometro->start(delay);
}

void MainWindow::TimerHandler(){
    take_Picture(cam_01,img,imgSmall);
}


void MainWindow::ColorSelector(bool *flagCalibrated, bool *colorFlag, bool *offFlag1, bool *offFlag2, int arrayColor[]){

    if(flagCalibrated){
        colorFlag = true;
    }
    else if(!flagCalibrated){
        for(int i=0; i<=6; i++){
            switch(i){
            case 0:
                arrayColor[i] = A1;
            break;
            case 1:
                arrayColor[i] = A2;
            break;
            case 2:
                arrayColor[i] = B1;
            break;
            case 3:
                arrayColor[i] = B2;
            break;
            case 4:
                arrayColor[i] = C1;
            break;
            case 5:
                arrayColor[i] = C2;
            break;
            case 6:
                offFlag1 = false;
                offFlag2 = false;
                colorFlag = true;
                flagCalibrated = true;
            break;


            }

        }

    }
}



if(bblue == true){
            cv::inRange(HSV,Scalar(blue[0],blue[2],blue[4]),Scalar(blue[1],blue[3],blue[5]),COLOR);
        }
        else if(bgreen == true){
            cv::inRange(HSV,Scalar(green[0],green[2],green[4]),Scalar(green[1],green[3],green[5]),COLOR);
        }
        else if(bred == true){
            cv::inRange(HSV,Scalar(red[0],red[2],red[4]),Scalar(red[1],red[3],red[5]),COLOR);
        }
        else{
            cv::inRange(HSV,Scalar(A1,B1,C1),Scalar(A2,B2,C2),COLOR);
        }


ui->pushButton->setVisible(true);
            if(ui->pushButton->isChecked()){
                cv::inRange(HSV,Scalar(A1,B1,C1),Scalar(A2,B2,C2),COLOR);
                red[0] = A1;
                red[1] = A2;
                red[2] = B1;
                red[3] = B2;
                red[4] = C1;
                red[5] = C2;
            }
            else{
                cv::inRange(HSV,Scalar(red[0],red[2],red[4]),Scalar(red[1],red[3],red[5]),COLOR);
            }