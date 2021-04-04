#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

int seg = 0;
int min = 0;
int horas = 0;

bool play = false;
bool stop = false;
bool reset = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(FTimer()));

    cronometro -> start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FTimer(){

    if(play){

        if(!stop){
            seg++;

            if(seg>59){
                seg = 0;
                min++;
                }

            if(min>59){
                min = 0;
                horas++;
                }

            if(horas>23){
                horas = 0;
                }

            ui->lcdNumber->display(seg);
            ui->lcdNumber_2 -> display(min);
            ui->lcdNumber_3->display(horas);

            }
    }
    else if(reset){
        seg = 0;
        min = 0;
        horas = 0;
        ui->lcdNumber->display(seg);
        ui->lcdNumber_2 -> display(min);
        ui->lcdNumber_3->display(horas);
    }

}

// play
void MainWindow::on_pushButton_clicked()
{
    play = true;
    stop = false;
    reset = false;

}


// pause
void MainWindow::on_pushButton_2_clicked()
{
    play = false;
    stop = true;
    reset = false;
}

// reset
void MainWindow::on_pushButton_3_clicked()
{
    play = false;
    stop = false;
    reset = true;

}
