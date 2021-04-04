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


    void registerEvent(QString head, QString stack, QString X, QString Y, QString R, QString H, QString skip, QString ref, QString comment);
public slots:
    void funcionActivacionTimer();
    void mousePressEvent(QMouseEvent *evento);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
