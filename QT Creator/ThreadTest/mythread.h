#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QtCore>

class MyThread : public QThread
{
Q_OBJECT

public:
    MyThread(QObject *parent = nullptr);
    void run();
    int count;


signals:
    void NumberChange(int);
};

#endif // MYTHREAD_H
