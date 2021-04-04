#include "mainwindow.h"
#include "ui_mainwindow.h"

QVector<double> XX(101), YY(101);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);

    int j = 0;
    for(int i=0; i<(2 * M_PI * 100); i+=6.31){
        if(j<100){
            YY[j] = -sin(i);
            XX[j] = j;

            qDebug() << YY[j];
        }

        j++;
    }

    QCustomPlot* graph = ui->grafica;

    graph->addGraph();
    graph->graph(0)->setData(XX,YY);
    graph->xAxis->setLabel("Tiempo");
    graph->yAxis->setLabel("Voltaje");
    graph->xAxis->setRange(0,100);
    graph->yAxis->setRange(-1,1);
    ui->grafica->replot();



}

MainWindow::~MainWindow()
{
    delete ui;
}
