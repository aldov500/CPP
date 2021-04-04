#include "mainwindow.h"
#include "ui_mainwindow.h"

/* Biblioteca para usar system() */
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  QString dirName = ui->lineEdit->text();
  QString command = "mkdir " + dirName;

  system(command.toUtf8().constData());

  ui->label->clear();
  ui->label->setText("Carpeta "+ dirName + " creada.");
}
