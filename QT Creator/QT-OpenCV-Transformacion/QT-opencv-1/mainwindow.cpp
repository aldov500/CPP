// Librerías

#include "mainwindow.h"
#include "mat2qimage.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include "stdlib.h"
#include <QTimer>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/videoio.hpp>

#include <QDate>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QTime>

// Nombre de espacio
using namespace cv;

// Declaración de variables globales
VideoCapture camara1(0);
bool primeraVez = false;
Point origenMouse;
Size tamanioMouse;
Point2f puntosOrigen[4];
Point2f puntosDestino[4];

Mat IMAGEN;
Mat IMAGENpequena;
Mat resultado;
QTimer* cronometro;


int imgCoordx = 396;
int imgCoordy = 450;

// Principal
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Puntos estáticos

    puntosDestino[0].x = 0;
    puntosDestino[0].y = 0;

    puntosDestino[1].x = imgCoordx;
    puntosDestino[1].y = 0;

    puntosDestino[2].x = imgCoordx;
    puntosDestino[2].y = imgCoordy;

    puntosDestino[3].x = 0;
    puntosDestino[3].y = imgCoordy;

    // Función repetitiva
    cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(10);

    // Cámara
    if (!camara1.isOpened()) {
        camara1.open(0);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* evento)
{
    ui->label_16->clear();
    //Coordenadas de toda la ventana
    if (ui->checkBox_2->isChecked()) {
        int xGlobal = evento->x();
        int yGlobal = evento->y();
        double xmm = (double)xGlobal * 0.055555556;
        double ymm = abs((double)yGlobal * 0.055555556 - 25);
        // Mostrar las coordenadas
        ui->lcdNumber->display(xmm);
        ui->lcdNumber_2->display(ymm);
        ui->P0X->setText(QString::number(imgCoordx - xmm));
        ui->P0Y->setText(QString::number(imgCoordy - ymm));

    } else {

        // Cambio de coordenadas
        int xGlobal = evento->x();
        int yGlobal = evento->y() - 45;

        if (xGlobal >= 0 && xGlobal < 640 && yGlobal >= 0 && yGlobal < 360) {
            //Ocurrio dentro de la etiqueta
            //La casilla de calibracion esta activa
            if (ui->checkBox->isChecked()) {
                // Modificaciones del vector de puntos
                if (ui->radioButton->isChecked()) {
                    puntosOrigen[0].x = xGlobal;
                    puntosOrigen[0].y = yGlobal;
                } else if (ui->radioButton_2->isChecked()) {
                    puntosOrigen[1].x = xGlobal;
                    puntosOrigen[1].y = yGlobal;
                } else if (ui->radioButton_3->isChecked()) {
                    puntosOrigen[2].x = xGlobal;
                    puntosOrigen[2].y = yGlobal;
                } else if (ui->radioButton_4->isChecked()) {
                    puntosOrigen[3].x = xGlobal;
                    puntosOrigen[3].y = yGlobal;
                }
            }
        }
    }
}

void MainWindow::funcionActivacionTimer()
{
    //Aqui se captura la imagen de camara IP cada 30ms
    if (camara1.isOpened()) { //Paso # 1
        camara1 >> IMAGEN; //Paso # 2
        IMAGEN= cv::imread("DSC00336.JPG");
        cv::resize(IMAGEN, IMAGENpequena, Size(640, 360)); //Paso # 3

        // Dibujo de guias para seleccion
        if (ui->checkBox->isChecked()) {
            circle(IMAGENpequena, puntosOrigen[0], 7, Scalar(0, 0, 255), 3, 8, 0);
            circle(IMAGENpequena, puntosOrigen[1], 7, Scalar(0, 255, 255), 3, 8, 0);
            circle(IMAGENpequena, puntosOrigen[2], 7, Scalar(255, 0, 255), 3, 8, 0);
            circle(IMAGENpequena, puntosOrigen[3], 7, Scalar(255, 0, 0), 3, 8, 0);
            line(IMAGENpequena, puntosOrigen[0], puntosOrigen[1], Scalar(255, 0, 0), 2, 8, 0);
            line(IMAGENpequena, puntosOrigen[1], puntosOrigen[2], Scalar(255, 0, 0), 2, 8, 0);
            line(IMAGENpequena, puntosOrigen[2], puntosOrigen[3], Scalar(255, 0, 0), 2, 8, 0);
            line(IMAGENpequena, puntosOrigen[3], puntosOrigen[0], Scalar(255, 0, 0), 2, 8, 0);
        }

        // Obtención de imagen reacomodada
        if (ui->checkBox_2->isChecked()) {
            Mat lambda(2, 4, CV_32FC1);
            lambda = getPerspectiveTransform(puntosOrigen, puntosDestino);
            warpPerspective(IMAGENpequena, resultado, lambda, Size(396, 450));

            QImage qImage = Mat2QImage(resultado);
            QPixmap pixmap = QPixmap::fromImage(qImage);
            ui->label->clear();
            ui->label->setPixmap(pixmap);
        } else {
            QImage qImage = Mat2QImage(IMAGENpequena);
            QPixmap pixmap = QPixmap::fromImage(qImage);
            ui->label->clear();
            ui->label->setPixmap(pixmap);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Registro de evento
void MainWindow::on_pushButton_clicked()
{
    registerEvent(ui->lineHead->text(),
                  ui->lineStack->text(),
                  ui->P0X->text(),
                  ui->P0Y->text(),
                  ui->lineAngle->text(),
                  ui->lineHeight->text(),
                  ui->lineSkip->text(),
                  ui->lineRef->text(),
                  ui->lineComment->text());
    ui->label_16->setText("Registro ingresado.");
}

// Funcion que ingresa evento a archivo
void MainWindow::registerEvent(QString head, QString stack, QString X, QString Y, QString R, QString H, QString skip, QString ref, QString comment)
{
    QString fileName = "unNamed.csv";
    QFile csvFile(fileName);
    QFileInfo dataOfFile(fileName);

    /* Archivo creado por primera vez */
    if (!dataOfFile.exists()) {
        csvFile.open(QIODevice::WriteOnly);
        QTextStream out(&csvFile);

        for(int i=0; i<60; i++){
             out << "\n";
        }

        out << "%"
            << ",";
        out << "Head"
            << ",";
        out << "Stack"
            << ",";
        out << "X"
            << ",";
        out << "Y"
            << ",";
        out << "R"
            << ",";
        out << "H"
            << ",";
        out << "skip"
            << ",";
        out << "Ref"
            << ",";
        out << "Comment\n";
        csvFile.close();
    }


    if (dataOfFile.isFile() && dataOfFile.exists()) {
        if (csvFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream out(&csvFile);
            out << " " << ",";
            out << head.toUtf8().constData() << ",";
            out << stack.toUtf8().constData() << ",";
            out << X.toUtf8().constData() << ",";
            out << Y.toUtf8().constData() << ",";
            out << R.toUtf8().constData() << ",";
            out << H.toUtf8().constData() << ",";
            out << skip.toUtf8().constData() << ",";
            out << ref.toUtf8().constData() << ",";
            out << comment.toUtf8().constData() << ",\n";
            csvFile.close();
        }
    }
}

