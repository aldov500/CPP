#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlitedatabase.h"
#include "qdir.h"
#include <QDebug>

static sqlitedatabase newBase;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){ ui->setupUi(this);
    QString dirPath = QDir::currentPath();
    newBase.setDataBasePath(dirPath);
    newBase.dataBaseConnect();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_BTN_QueryExe_clicked(){
    if(newBase.dataBaseConnection() == true){
        QString sQuery = ui->EDT_Query->toPlainText();
        qDebug() << sQuery;
    }else{
        qDebug() << "Base de datos no conectada";
    }
}
