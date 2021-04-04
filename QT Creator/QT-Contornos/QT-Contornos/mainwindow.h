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
    void on_b1_min_sliderMoved(int position);

    void on_b2_min_sliderMoved(int position);

    void on_b3_min_sliderMoved(int position);

    void on_b1_max_sliderMoved(int position);

    void on_b2_max_sliderMoved(int position);

    void on_b3_max_sliderMoved(int position);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
