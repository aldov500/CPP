#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

Mat IMAGEN; //Para guardar la imagen que se abrirá
Mat IMAGENchica; //Guardará la imagen pequeña
Mat ImagenHSV; //Aquí se guarda la imagen HSV
Mat ImagenDesenfoque; //Para la imagen con desenfoque
Mat ImagenFiltrada; //Para la imagen binaria que resulta de inRange

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    QTimer* cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(ftimer()));
    cronometro->start(100);
}

void MainWindow::fTimer()
{
    //Paso # 1 - Procesar imagen anterior para filtro de ventana

    if (!ImagenHSV.empty()) {

        int canal0Min = ui->horizontalScrollBar1MIn->value();
        int canal0Max = ui->horizontalScrollBar1Max->value();
        int canal1Min = ui->horizontalScrollBar2MIn->value();
        int canal1Max = ui->horizontalScrollBar2Max->value();
        int canal2Min = ui->horizontalScrollBar3Min->value();
        int canal2Max = ui->horizontalScrollBar3Max->value();

        inRange(IMAGENchica, Scalar(canal0Min, canal1Min, canal2Min), Scalar(canal0Max, canal1Max, canal2Max), ImagenFiltrada);

        QImage qImage = Mat2QImage(ImagenFiltrada);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->labelInRange->clear();
        ui->labelInRange->setPixmap(pixmap);
    }
}

void MainWindow::on_horizontalScrollBar1MIn_sliderMoved(int position)
{
    ui->lcdNumber1Min->display(position);
}

void MainWindow::on_horizontalScrollBar1Max_sliderMoved(int position)
{
    ui->lcdNumber1Max->display(position);
}

void MainWindow::on_horizontalScrollBar2MIn_sliderMoved(int position)
{
    ui->lcdNumber2Min->display(position);
}

void MainWindow::on_horizontalScrollBar2Max_sliderMoved(int position)
{
    ui->lcdNumber2Max->display(position);
}

void MainWindow::on_horizontalScrollBar3Min_sliderMoved(int position)
{
    ui->lcdNumber3Min->display(position);
}

void MainWindow::on_horizontalScrollBar3Max_sliderMoved(int position)
{
    ui->lcdNumber3Max->display(position);
}

void MainWindow::on_pushButtonImage_clicked()
{
    QString nombreImagen;
    nombreImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), "/home/", tr("Imagenes (*.png *.jpg *.bmp)"));
    QImage img1;
    QPixmap img2;

    /* Abrir y Guardar la imagen */
    IMAGEN = imread(nombreImagen.toUtf8().constData());
    /* Cambiar el tamaño de Imagen */
    cv::resize(IMAGEN, IMAGENchica, Size(150, 150));
    /* Aplicar desenfoque */
    GaussianBlur(IMAGENchica, ImagenDesenfoque, Size(3, 3), 0, 0, 0);
    /* Cambiar de BGR a HSV */
    cvtColor(ImagenDesenfoque, ImagenHSV, CV_BGR2HSV);

    /* Mostrar Imagen chica */
    img1 = Mat2QImage(IMAGENchica);
    img2 = QPixmap::fromImage(img1);
    ui->labelColor->clear();
    ui->labelColor->setPixmap(img2);

    /* Mostrar Imagen desenfoque */
    img1 = Mat2QImage(ImagenDesenfoque);
    img2 = QPixmap::fromImage(img1);
    ui->labelBlur->clear();
    ui->labelBlur->setPixmap(img2);

    /* Mostrar Imagen HSV */
    img1 = Mat2QImage(ImagenHSV);
    img2 = QPixmap::fromImage(img1);
    ui->labelHSV->clear();
    ui->labelHSV->setPixmap(img2);
}
