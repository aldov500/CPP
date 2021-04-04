#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* Librerías */
#include <QDebug>
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

#include <QDate>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QTime>

#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    /* Prototipos de funciones publicas */
    void RadialEventButtonAnalogSwitcher(bool FLAG);
    void registerEvent(QString event, QString value);
    void sendEmailNow();

public slots:
    /* Prototipo de funcion*/
    void loop_100ms();

private slots:
    /* Funciones para Leds */
    void on_radioButton13_clicked();

    void on_radioButton12_clicked();

    void on_radioButton11_clicked();

    void on_radioButton10_clicked();

    /* Funciones para los botones */
    void on_pushButtonConnect_clicked();

    void on_pushButtonReset_clicked();

    /* Funciones para radiales de boton y analogico */
    void on_radioButtonButon_clicked(bool checked);

    void on_radioButtonAnalogic_clicked(bool checked);

    void on_pushButtonEmail_clicked();

private:
    Ui::MainWindow* ui;

    /* Objeto para comunicacion serial */
    QSerialPort* Arduino;
    QString ArduinoPort;
    /* Objeto para proceso externo */
    QProcess* emailProcess;

    /* Variables para control del objeto serial */
    bool Arduino_isAvailable;

    static const quint16 ARDUINO_UNO = 66;
    static const quint16 ARDUINO_MEGA = 67;
    static const quint16 ARDUINO_NANO = 29987;

    /* Funcion para conectar el objeto serial */
    void connectArduino();
};

#endif // MAINWINDOW_H
