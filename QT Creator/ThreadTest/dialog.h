#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <mythread.h>

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
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    MyThread *mThread;
    MyThread *mThread2;
    MyThread *mThread3;

    QTimer* Counter;
    QTimer* Counter2;
    QTimer* Counter3;

public slots:
    void onNumberChange(int);
    void onNumberChange2(int);
    void onNumberChange3(int);

    void startCount();
    void startCount2();
    void startCount3();
signals:
//    void NumberChange(int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
