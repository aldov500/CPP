#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mat2qimage.h"
#include<qdebug.h>

#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/imgcodecs.hpp>

#include<QTimer>
#include<QDirIterator>
#include<QFileInfo>
#include<unistd.h>

using namespace cv;

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
    void loop2();
private slots:

    void on_radioButton_3_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
