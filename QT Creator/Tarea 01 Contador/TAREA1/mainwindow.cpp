#include "mainwindow.h"
#include "ui_mainwindow.h"

/* Librería QTimer*/
#include <QTimer>

/* Variables para tiempo */
int sec = 0;
int min = 0;
int hrs = 0;

/* Banderas estado de Temporizador */
bool play = false;
bool pause = false;
bool reset = false;


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);

    QTimer *cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(FTimer()));

    cronometro -> start(10);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::FTimer(){
    if(play){
        sec--;
        if(sec < 1 ){
            if(min){
                min--;
                sec = 59;
            }
            else{
                if(hrs){
                    hrs--;
                    min = 59;
                }
                else{
                    reset = true;
                    play = false;
                }
            }
        }
        else if(min < 1 ){
            if(hrs){
                hrs--;
                min = 59;
            }
        }

    }

    else if(pause){

    }
    else if(reset){
        sec = 0;
        min = 0;
        hrs = 0;
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        reset = false;
        pause = true;

    }

    ui->lcdNumber->display(hrs);
    ui->lcdNumber_2->display(min);
    ui->lcdNumber_3->display(sec);

}


// Boton Play
void MainWindow::on_pushButton_clicked(){
    play = true;
    pause = false;
    reset = false;
}
// Boton Pause
void MainWindow::on_pushButton_2_clicked(){
    play = false;
    pause = true;
    reset = false;
}
// Boton Reset
void MainWindow::on_pushButton_3_clicked(){
    play = false;
    pause = false;
    reset = true;
}

// LineEdit Hrs
void MainWindow::on_lineEdit_editingFinished(){
    hrs = ui->lineEdit->text().toInt();
    ui->lcdNumber->display(hrs);
}
// LineEdit Min
void MainWindow::on_lineEdit_2_editingFinished(){
    min = ui->lineEdit_2->text().toInt();
    ui->lcdNumber_2->display(min);
}
// LineEdit Sec
void MainWindow::on_lineEdit_3_editingFinished(){
    sec = ui->lineEdit_3->text().toInt();
    ui->lcdNumber_3->display(sec);
}
