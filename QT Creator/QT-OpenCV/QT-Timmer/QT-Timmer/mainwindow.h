#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <stdlib.h>

#include "mat2qimage.h"
#include <QMainWindow>
#include <QTimer>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/videoio.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    int contador = 0;

public slots:
    void funcionActivacionTimer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
