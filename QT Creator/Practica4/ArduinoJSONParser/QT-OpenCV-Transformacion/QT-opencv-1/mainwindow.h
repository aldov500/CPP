#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* Bibliotecas */
#include "mainwindow.h"
#include "mat2qimage.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMainWindow>
#include <QMouseEvent>
#include <QTextStream>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/videoio.hpp>
#include <QDebug>
#include <QFileDialog>
#include <QSerialPort>
#include <QSerialPortInfo>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    void funcionActivacionTimer();
    void mousePressEvent(QMouseEvent* evento);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_pushButtonAgregar_clicked();

private:
    Ui::MainWindow* ui;
    QSerialPort* arduino;
    bool arduino_esta_conectado = false;

    void conectarArduino();
    void recepcionSerialAsyncrona();
};

#endif // MAINWINDOW_H
