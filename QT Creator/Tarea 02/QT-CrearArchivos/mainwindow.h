#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:
    /* Funciones de Interfáz */
    void on_buttonEnviar_clicked();

    void on_buttonLimpiar_clicked();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
