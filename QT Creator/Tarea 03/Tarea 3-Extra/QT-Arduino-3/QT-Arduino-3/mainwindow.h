#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
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

private:
    Ui::MainWindow* ui;
    /* Creacion de objeto con comunicacion serial*/
    QSerialPort* Arduino;
    /* Bandera de Conexion */
    bool ArduinoIsConnected = false;

    /* Prototipos de Funciones */
    void connectArduino();
    void serialReceiver();
};

#endif // MAINWINDOW_H
