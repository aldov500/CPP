#include "mythread.h"

MyThread::MyThread(QObject *parent){
    count = 0;
}

void MyThread::run(){
    QMutex mutex;
    mutex.lock();
    emit NumberChange(count);
    mutex.unlock();
    count += 1;
}

