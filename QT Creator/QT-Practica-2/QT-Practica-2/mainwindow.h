#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ftimer();

    void on_c0_min_valueChanged(int value);

    void on_c1_min_valueChanged(int value);

    void on_c2_min_valueChanged(int value);

    void on_c0_max_valueChanged(int value);

    void on_c1_max_valueChanged(int value);

    void on_c2_max_valueChanged(int value);

    void mousePressEvent(QMouseEvent *evento);

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    QString arduinoPort;
    static const quint16 arduino_UNO =67;
    static const quint16 arduino_MEGA =66;
    bool arduino_isAvailable; //Indica que hay conexion con arduino
    void buscaYconectaArduino(); //Funcion que realiza la conexion con arduino
    void recepcionSerialAsyncrona();
    void detectarColor(int c0_max, int c0_min, int c1_max, int c1_min, int c2_max, int c2_min);
};

#endif // MAINWINDOW_H
