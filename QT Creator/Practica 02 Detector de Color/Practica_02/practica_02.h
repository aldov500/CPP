#ifndef PRACTICA_02_H
#define PRACTICA_02_H

#include "mainwindow.h"

#define LIM_DETECT 1500

using namespace cv;

class colorDetector{
public:
    QDate fecha;
    QTime hora;
    int sizex = 400;
    int sizey = 300;


    int SliderParameter[6];
    int contador;

    int TotalNumberOfPixels = sizex * sizey;
    int BlackPixels, WhitePixels;

    Mat IMAGEN, IMAGENSmall;
    Mat GAUSS, HSV, COLOR;

    QString tiempoLocal, evento, color;
    QString nombreArchivo;

    QSerialPort *arduino;
    QString arduino_port_name;

    quint16 arduino_uno_vendor_id;
    quint16 arduino_uno_product_id;
    bool arduino_is_available;

    bool logg;
    bool redDet;
    bool greenDet;
    bool blueDet;

public:

    colorDetector();
    void sendEmail(QString d);
    void logData(QString event, QString col);
    void detect(int color[], QString led);
    void arduinoAvailable();
};

#endif // PRACTICA_02_H
