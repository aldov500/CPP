#include "mainwindow.h"
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/videoio.hpp>
#include "mat2qimage.h"
#include "ui_mainwindow.h"
using namespace cv;
Mat imagen_OG = cv::imread("../pic0.png");  // Imagen original con su dirección
Mat imagen_OK;                              // Imagen redimensionada
Mat imagen_EQ;                              // Imagen ecualizada

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);  // Configuraciones iniciales del programa
  cv::resize(imagen_OG, imagen_OK, Size(508, 252), 0, 0,
             0);  // Redimensionado de la imagen original
  QImage qImage = Mat2QImage(imagen_OK);  // Conversión de matriz a QImage
  QPixmap pixmap =
      QPixmap::fromImage(qImage);  // Conversión de QImage a mapa de pixeles
  ui->label->clear();              // Limpiar el contenido de la etiqueta
  ui->label->setPixmap(pixmap);  // Despliegue de la imagen redimensionada en la
                                 // etiqueta correspondiente
  std::vector<Mat> rgb;  // Creación de un arreglo de matrices para los canales
                         // RGB de la imagen redimensionada
  split(imagen_OK, rgb);  // Separación de los canales RGB y almacenamiento en
                          // el arreglod de matrices
  cv::equalizeHist(
      rgb[0],
      rgb[0]);  // Ecualización del canal azul de la imagen redimensionada
  cv::equalizeHist(
      rgb[1],
      rgb[1]);  // Ecualización del canal verde de la imagen redimensionada
  cv::equalizeHist(
      rgb[2],
      rgb[2]);  // Ecualización del canal rojo de la imagen redimensionada
  cv::merge(rgb, imagen_EQ);  // Unión de los canales RGB en una matriz
  QImage qImage_EQ = Mat2QImage(imagen_EQ);  // Conversión de matriz a QImage
  QPixmap pixmap_EQ =
      QPixmap::fromImage(qImage_EQ);  // Conversión de QImage a mapa de pixeles
  ui->label_2->clear();               // Limpiar el contenido de la etiqueta
  ui->label_2->setPixmap(pixmap_EQ);  // Despliegue de la imagen ecualizada en
                                      // la etiqueta correspondiente
}
MainWindow::~MainWindow() { delete ui; }
