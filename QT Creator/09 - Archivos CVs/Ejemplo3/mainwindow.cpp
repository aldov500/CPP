#include "mainwindow.h"
using namespace cv;
#define IP  0

cv::VideoCapture camara(IP);

QDate fecha;
QTime hora;
QString nombreArchivo = "reporte.csv";

QString tiempoLocal,evento, color;
int contador = 0;
Mat IMAGEN;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    ui->radioButton->setChecked(true);

    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(loop()));
    cronometro->start(100);

    if(!camara.isOpened()) camara.open(IP);

    else         qDebug() << "No se abre la camara 22";
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::loop(){

    fecha = QDate::currentDate();
    hora = QTime::currentTime();
    tiempoLocal = fecha.toString() + " " + hora.toString();
    ui->label_6->setText(tiempoLocal);

/*
    cv::resize(IMAGEN,IMAGEN,Size(138,177),0,0,0);
    QImage qImage = Mat2QImage(IMAGEN);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    ui->label->clear();
    ui->label->setPixmap(pixmap);
*/

}



void MainWindow::on_pushButton_clicked(){
    contador++;
    ui->lcdNumber->display(contador);

    nombre = ui->lineEdit->text();
    quien = ui->lineEdit_2->text();
    empresa = ui->lineEdit_3->text();

    if(ui->radioButton->isChecked()){
        tipoIdentificacion = "INE";
        numeroIdentificacion = ui->lineEdit_4->text();
    }
    else if(ui->radioButton_2->isChecked()){
        tipoIdentificacion = "Pasaporte";
        numeroIdentificacion = ui->lineEdit_4->text();
    }
    else if(ui->radioButton_3->isChecked()){
        tipoIdentificacion = "Lic de Manejo";
        numeroIdentificacion = ui->lineEdit_4->text();
    }
    else if(ui->radioButton_4->isChecked()){
        tipoIdentificacion =ui->lineEdit_5->text();
        numeroIdentificacion = ui->lineEdit_4->text();
    }

    QFile reporte(nombreArchivo);
    QFileInfo existe(nombreArchivo);

    if(!existe.exists()){
        reporte.open(QIODevice::WriteOnly);
        QTextStream out(&reporte);
        out<< "NOMBRE" << ",";
        out<< "A QUIEN VISITA" << ",";
        out<< "EMPRESA" << ",";
        out<< "TIPO DE ID" << ",";
        out<< "NUMERO ID" << ",";
        out<< "NOMBRE IMAGEN" << ",";
        out<< "FECHA Y HORA \n";
        reporte.close();
    }

    if(existe.isFile() && existe.exists()){
        if(reporte.open(QIODevice::WriteOnly | QIODevice::Append)){
            QTextStream out(&reporte);
            out<< nombre.toUtf8().constData()<<",";
            out<< quien.toUtf8().constData()<<",";
            out<< empresa.toUtf8().constData()<<",";
            out<< tipoIdentificacion.toUtf8().constData()<<",";
            out<< numeroIdentificacion.toUtf8().constData()<<",";
            out<< "imagen"<< contador <<".jpg"<<",";
            out<< tiempoLocal.toUtf8().constData()<<"\n";
            reporte.close();

            QString nombreImagen = "imagen"+ QString::number(contador)+".jpg";
            cv::imwrite(nombreImagen.toUtf8().constData(), IMAGEN);


        }
    }

}

