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
    void ftimer();
private slots:
    void on_pushButton_clicked();


    void on_barraCanal0Min_sliderMoved(int position);

    void on_barraCanal0Max_sliderMoved(int position);

    void on_barraCanal1Min_sliderMoved(int position);

    void on_barraCanal1Max_sliderMoved(int position);

    void on_barraCanal2Min_sliderMoved(int position);

    void on_barraCanal2Max_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
