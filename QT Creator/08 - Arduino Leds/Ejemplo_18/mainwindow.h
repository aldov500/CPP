#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>

#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loop();
private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    QSerialPort *arduino;
    QString arduino_port_name;

    static const quint16 arduino_uno_vendor_id = 0x1a86;
    static const quint16 arduino_uno_product_id = 0x7523;
    bool arduino_is_available;

};

#endif // MAINWINDOW_H
