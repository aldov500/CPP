#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:


    void on_buttonOpen_clicked();

    void on_verticalSlider_sliderMoved(int position);

private:
  Ui::MainWindow* ui;
  QMediaPlayer* reproductor;
};

#endif  // MAINWINDOW_H
