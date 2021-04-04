#include "mainwindow.h"
#include "ui_mainwindow.h"

QString textob;
QString texto;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{
    textob = ui->lineEdit->text();

}

void MainWindow::on_lineEdit_2_editingFinished()
{
    texto = ui->lineEdit_2->text();
}

void MainWindow::on_pushButton_clicked()
{
    int indice = texto.indexOf(textob);

    QString indiceS = QString::number(indice);

    if(indice == -1){
        ui->label_3->setText("NO Encontrado");
        ui->label_4->setText("IND");
    }
    else{
        ui->label_3->setText("Encontrado");
        ui->label_4->setText(indiceS);
    }

}
