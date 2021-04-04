#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* Librerias */
#include <QMainWindow>
#include <mat2qimage.h>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/videoio.hpp>

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    /* Funcion para llenar un arreglo con configuracion de colores */
    void fillColorArray(int *array);
    /* Funcion para detectar color*/
    void detectColor(int color[], QString led);

public slots:
    /* Funcion repetitiva */
    void loop();
private slots:
    /* Sliders para configurar os filtros */
    void on_verticalSlider_A1_sliderMoved(int position);

    void on_verticalSlider_C1_sliderMoved(int position);

    void on_verticalSlider_B1_sliderMoved(int position);

    void on_verticalSlider_A2_sliderMoved(int position);

    void on_verticalSlider_B2_sliderMoved(int position);

    void on_verticalSlider_C2_sliderMoved(int position);

    /* Boton Calibracion*/
    void on_pushButton_clicked();

    void on_buttonCalibrate_clicked();

private:
    Ui::MainWindow* ui;

    /* Objeto para comunicacion serial */
    QSerialPort* Arduino;
    QString ArduinoPort;

    /* Variables para control del objeto serial */
    bool Arduino_isAvailable;

    static const quint16 ARDUINO_UNO = 66;
    static const quint16 ARDUINO_MEGA = 67;
    static const quint16 ARDUINO_NANO = 29987;

    /* Funcion para conectar el objeto serial */
    void connectArduino();
};

#endif // MAINWINDOW_H
