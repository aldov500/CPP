#ifndef CAMERATHREADS_H
#define CAMERATHREADS_H

#include <QThread>
#include <QMainWindow>
#include <QObject>
#include <QtCore>

class CameraThreads : public QThread
{
public:
    CameraThreads(QWidget *parent = nullptr);
    void run();
    bool Stop;

signals:
    void NumberChange(int);


};

#endif // CAMERATHREADS_H
