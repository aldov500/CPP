#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void funcionActivacionTimer();
    void mousePressEvent(QMouseEvent *evento);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
