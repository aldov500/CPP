#ifndef CUSTOMTHREADS_H
#define CUSTOMTHREADS_H

#include <QObject>
#include <QWidget>

class CustomThreads : public QThread
{
public:
    CustomThreads();
};

#endif // CUSTOMTHREADS_H