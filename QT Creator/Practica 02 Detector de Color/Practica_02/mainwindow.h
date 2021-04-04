#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*  Librerias
 *     
 *     
 */

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QTimer>

#include<mat2qimage.h>
#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>

#include <QDateTime>
#include <QTime>
#include <QDate>
#include <QFile>
#include <QFileInfo>

#include <QMainWindow>

/*  Librería personalizada
 *     
 *     
 */
#include "practica_02.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void fillColorArray(int *array, bool *flag);

public slots:
    void TimerReadings();
    void TimerGeneral();


private slots:
    void on_Amin_sliderMoved(int position);
    void on_Amax_sliderMoved(int position);
    void on_Bmax_sliderMoved(int position);
    void on_Bmin_sliderMoved(int position);
    void on_Cmax_sliderMoved(int position);
    void on_Cmin_sliderMoved(int position);
    void on_dial_sliderMoved(int position);


    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    QString arduino_port_name;

    static const quint16 arduino_uno_vendor_id = 0x1a86;
    static const quint16 arduino_uno_product_id = 0x7523;
    bool arduino_is_available;
};

#endif // MAINWINDOW_H
