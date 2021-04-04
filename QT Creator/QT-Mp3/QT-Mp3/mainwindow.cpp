#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMediaPlayer>
#include <QFileInfo>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  reproductor = new QMediaPlayer(this);
  connect(ui->buttonPlay, &QPushButton::clicked, reproductor,
          &QMediaPlayer::play);
  connect(ui->buttonPause, &QPushButton::clicked, reproductor,
          &QMediaPlayer::pause);
  connect(ui->buttonStop, &QPushButton::clicked, reproductor,
          &QMediaPlayer::stop);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_buttonOpen_clicked() {
  QString nombreArchivo =
      QFileDialog::getOpenFileName(this, "Selecciona un archivo", ".mp3");
  reproductor->setMedia(QUrl::fromLocalFile(nombreArchivo));
}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    reproductor->setVolume(position);
}
