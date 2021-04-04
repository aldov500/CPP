#include "mainwindow.h"
#include "ui_mainwindow.h"

int count = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    count ++;
    ui->lcdNumber->display(count);
    ui->labelCoordX->setText(QString::number(event->x()));
    ui->labelCoordY->setText(QString::number(event->y()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
