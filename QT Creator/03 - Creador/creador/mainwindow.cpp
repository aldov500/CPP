#include "mainwindow.h"
#include "ui_mainwindow.h"

QString carpeta;

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
    carpeta = ui->lineEdit->text();
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("                    ");

    if(!carpeta.isEmpty()){
        QString comando = "mkdir " + carpeta;
        system(comando.toUtf8().constData());
        ui->label->setText("Creada!");
    }
    else{
    ui->label->setText("NO creada!");
    }

}
