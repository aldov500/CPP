/* LIbrerías y archivos incluidos */

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

#include <opencv2/objdetect.hpp>

/* MACROS */
#define IP 0
#define IMG_ADD "/home/aldo/Imágenes/Wallpapers/1505520401699.jpg"
#define CASCADE "../haarcascade_frontalface_alt2.xml"

using namespace cv;

QString face_cascade_name = QString(CASCADE);
CascadeClassifier face_cascade;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  if (!face_cascade.load(face_cascade_name.toUtf8().constData())) {
    qDebug() << "Error al cargar el detector de rostros";
  }

  QTimer *cronometro = new QTimer(this);
  connect(cronometro, SIGNAL(timeout()), this, SLOT(fTimer()));
  cronometro->start(30);

  if (!camara.isOpened()) camara.open(IP);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::fTimer() {
  /* Matrices para Imagen */
  Mat IMAGEN;
  Mat IMAGEN2;
  Mat IMAGEN3;
  Mat IMAGEN4;

  Mat GRIS;
  Mat rgb[3];
  Mat result[3];

  /* Lectura de Imagen */
  IMAGEN = cv::imread(IMG_ADD);
  /* Ajuste de dimension */
  cv::resize(IMAGEN, IMAGEN2, Size(400, 300), 0, 0, 0);

  cv::split(IMAGEN2, rgb);

  /* Ecualizacion y guardado por capas */
  equalizeHist(rgb[0], result[0]);
  equalizeHist(rgb[1], result[1]);
  equalizeHist(rgb[2], result[2]);

  std::vector<cv::Mat> matVector;
  matVector.push_back(result[0]);
  matVector.push_back(result[1]);
  matVector.push_back(result[2]);

  /* Union de 3 canales en la matriz */
  cv::merge(matVector, IMAGEN4);

  /* Impresion en Etiquetas */
  QImage qImage = Mat2QImage(IMAGEN4);
  QPixmap pixmap = QPixmap::fromImage(qImage);
  ui->label_2->clear();
  ui->label_2->setPixmap(pixmap);

  QImage qImage1 = Mat2QImage(IMAGEN2);
  QPixmap pixmap1 = QPixmap::fromImage(qImage1);
  ui->label->clear();
  ui->label->setPixmap(pixmap1);
}
