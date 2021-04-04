#include "mainwindow.h"
#include "mat2qimage.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;
VideoCapture camara(0);

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer* cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(ftimer()));
    cronometro->start(5);

    camara.open(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ftimer()
{

    if (camara.isOpened()) {
        Mat COLOR, IMGchica, HSV, GRIS, HLS;
        Mat GREEN(200, 300, CV_8UC3, Scalar(0, 255, 0));

        camara >> COLOR;
        cv::resize(COLOR, IMGchica, Size(300, 200));
        cvtColor(IMGchica, HSV, CV_BGR2HSV);
        cvtColor(IMGchica, GRIS, CV_BGR2GRAY);
        cvtColor(IMGchica, HLS, CV_BGR2HLS_FULL);

        ui->LCOLOR->clear();

        if (ui->radioButton->isChecked()) {
            QImage img1 = Mat2QImage(IMGchica);
            QPixmap img2 = QPixmap::fromImage(img1);
            ui->LCOLOR->setPixmap(img2);

        } else if (ui->radioButton_2->isChecked()) {

            QImage img1 = Mat2QImage(GRIS);
            QPixmap img2 = QPixmap::fromImage(img1);
            ui->LCOLOR->setPixmap(img2);

        } else if (ui->radioButton_3->isChecked()) {
            QImage img1 = Mat2QImage(HSV);
            QPixmap img2 = QPixmap::fromImage(img1);
            ui->LCOLOR->setPixmap(img2);

        } else if (ui->radioButton_4->isChecked()) {
            QImage img1 = Mat2QImage(HLS);
            QPixmap img2 = QPixmap::fromImage(img1);
            ui->LCOLOR->setPixmap(img2);
        } else {

            QImage img1 = Mat2QImage(GREEN);
            QPixmap img2 = QPixmap::fromImage(img1);
            ui->LCOLOR->setPixmap(img2);
        }
    }
}
