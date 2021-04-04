#include "mainwindow.h"
#include "ui_mainwindow.h"

int count = 0;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_button_ClickUp_clicked() {
    count ++;
    ui->lcdNumber->display(count);
}

void MainWindow::on_button_ClickDown_clicked()
{
    if(count < 1)
        count = 0;
    else
        count --;

    ui->lcdNumber->display(count);
}
