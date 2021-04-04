#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include "camerathreads.h"

#include <mat2qimage.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv/cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/imgcodecs.hpp>
#include <videoio.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    CameraThreads *MultiCam;

private slots:

    void on_BTN_Start_clicked();
    void on_BTN_Stop_clicked();
    void onNumberChange(int);

public slots:
    void laptopRecorder();
    void remoteRecorder();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
