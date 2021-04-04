#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMultimedia/QMediaPlayer>

QMediaPlayer* player;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/home/aldo/Escritorio/Interfaces/Sonidos/QT-Sound/audio.wav"));
    player->setVolume(50);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonPLAY_clicked()
{
      player->play();
}

void MainWindow::on_pushButtonPAUSE_clicked()
{
      player->pause();
}

void MainWindow::on_pushButtonSTOP_clicked()
{
    player->stop();
}
