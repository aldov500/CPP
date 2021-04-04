#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mat2qimage.h"
#include <QFileDialog>
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

public slots:
    void fTimer();
private slots:
    void on_horizontalScrollBar1MIn_sliderMoved(int position);

    void on_horizontalScrollBar1Max_sliderMoved(int position);

    void on_horizontalScrollBar2MIn_sliderMoved(int position);

    void on_horizontalScrollBar2Max_sliderMoved(int position);

    void on_horizontalScrollBar3Min_sliderMoved(int position);

    void on_horizontalScrollBar3Max_sliderMoved(int position);

    void on_pushButtonImage_clicked();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
