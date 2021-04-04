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
    cronometro->start(30);
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
        cv::resize(IMAGEN, IMAGENpequena, Size(800, 450)); //Paso # 3

        Point origen;
        Size tamanio;

        origen.x = ui->lineEditP0X->text().toInt();
        origen.y = ui->lineEditP0Y->text().toInt();

        tamanio.width = ui->lineEditANCHO->text().toInt();
        tamanio.height = ui->lineEditALTO->text().toInt();

        Rect zona1(origen, tamanio);

        Mat IMAGENRoi = IMAGENpequena(zona1);

        //Las siguientes 4 instrucciones representan al Paso # 4
        QImage qImage = Mat2QImage(IMAGENpequena);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        ui->label->clear();
        ui->label->setPixmap(pixmap);

        //ROI
        QImage qImageR = Mat2QImage(IMAGENRoi);
        QPixmap pixmapR = QPixmap::fromImage(qImageR);
        ui->labelRoi->clear();
        ui->labelRoi->setPixmap(pixmap);
    }
}
