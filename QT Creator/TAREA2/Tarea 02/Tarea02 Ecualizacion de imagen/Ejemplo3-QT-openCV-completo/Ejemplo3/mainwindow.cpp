#include "mainwindow.h"
#include "mat2qimage.h"
#include "ui_mainwindow.h"

#include <opencv/cv.h>
#include <qdebug.h>
#include <QTimer>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/videoio.hpp>

#include<opencv2/objdetect.hpp>

#define IP 0
#define IMG_ADD "/home/aldo/Imágenes/Wallpapers/40114691-factory-wallpapers.jpg"
#include <opencv2/objdetect.hpp>

using namespace cv;

cv::VideoCapture camara(IP);

QString face_cascade_name = "../haarcascade_frontalface_alt2.xml";
CascadeClassifier face_cascade;

void MainWindow::fTimer() {
  Mat IMAGEN;
  Mat IMAGEN2;
  Mat GRIS;
  Mat IMAGEN3;
  Mat bgr[3];

  IMAGEN = cv::imread(IMG_ADD);

  cv::resize(IMAGEN, IMAGEN2, Size(400, 300), 0, 0, 0);

  cv::Mat result[3];

  cv::split(IMAGEN2, bgr);

  // equalizamos cada capay la pasamos a otro lugar
  equalizeHist(bgr[0], result[0]);
  equalizeHist(bgr[1], result[1]);
  equalizeHist(bgr[2], result[2]);
  // retrocedemos cada canal
  std::vector<cv::Mat> matVector;
  matVector.push_back(result[0]);
  matVector.push_back(result[1]);
  matVector.push_back(result[2]);
  // unimos los tres canales equalizados a una nueva matríz
  cv::Mat IMAGEN4;
  cv::merge(matVector, IMAGEN4);

  // se muestrea
  QImage qImage = Mat2QImage(IMAGEN4);
  QPixmap pixmap = QPixmap::fromImage(qImage);
  ui->label_2->clear();
  ui->label_2->setPixmap(pixmap);

  QImage qImage1 = Mat2QImage(IMAGEN2);
  QPixmap pixmap1 = QPixmap::fromImage(qImage1);
  ui->label->clear();
  ui->label->setPixmap(pixmap1);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  if (!face_cascade.load(face_cascade_name.toUtf8().constData())) {
    qDebug() << "Error al cargar el detector de rostros";
  }

  QTimer *cronometro = new QTimer(this);
  connect(cronometro, SIGNAL(timeout()), this, SLOT(fTimer()));
  cronometro->start(30);

  if (!camara.isOpened())
    camara.open(IP);
}

MainWindow::~MainWindow() { delete ui; }
