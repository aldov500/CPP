#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
int CAM = 0;
Mat IMAGEN;

VideoCapture camara1(CAM);

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer* cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(25);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::funcionActivacionTimer()
{ //Aqui se captura la imagen de camara IP cada 30ms
    if (camara1.isOpened()) { //Paso # 1

        Mat IMAGENpequena;
        camara1 >> IMAGEN; //Paso # 2
        cv::resize(IMAGEN, IMAGENpequena, Size(320, 240)); //Paso # 3

        //Las siguientes 4 instrucciones representan al Paso # 4
        QImage qImage = Mat2QImage(IMAGENpequena);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->label->clear();
        ui->label->setPixmap(pixmap);

        // Crear la matriz gris
        Mat HSV;
        cvtColor(IMAGENpequena, HSV, CV_BGR2HSV);
        qImage = Mat2QImage(HSV);
        pixmap = QPixmap::fromImage(qImage);
        ui->label_2->clear();
        ui->label_2->setPixmap(pixmap);

        Mat GRAY;
        cvtColor(IMAGENpequena, GRAY, CV_BGR2GRAY);
        qImage = Mat2QImage(GRAY);
        pixmap = QPixmap::fromImage(qImage);
        ui->label_3->clear();
        ui->label_3->setPixmap(pixmap);

        Mat HLS;
        cvtColor(IMAGENpequena, HLS, CV_BGR2HLS);
        qImage = Mat2QImage(HLS);
        pixmap = QPixmap::fromImage(qImage);
        ui->label_4->clear();
        ui->label_4->setPixmap(pixmap);



    }
}

void MainWindow::on_pushButton_clicked()
{
    QString nombre = ui->lineEdit->text();
    QString comando = "mpack -s Subject imagen.jpg " + nombre;

    imwrite("imagen.jpg",IMAGEN);

    system(comando.toUtf8().constData());

}
