#include "mainwindow.h"
#include "ui_mainwindow.h"


int millisec = 0;
int sec = 0;
int min = 0;

bool play = false;
bool stop = false;
bool reset = false;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* Configuracion de señal QTimer para cronometro */
    QTimer* cronometro = new QTimer(this);
    /* Conexion a la función que se ejecutará */
    connect(cronometro, SIGNAL(timeout()), this, SLOT(cronLoop()));
    /* Inicio de funcion repetitiva cada 1 ms */
    cronometro->start(1);
}

/* Destructor de Clase */
MainWindow::~MainWindow()
{
    delete ui;
}

/* Funcion repetitiva */
void MainWindow::cronLoop()
{
    /* Boton play clickeado */
    if (play) {

        if (!stop) {
            millisec++;
            /* Limite de aumento de milisegundos */
            if (millisec > 999) {
                millisec = 0;
                sec++;
            }

            /* Limite de aumento de segundos*/
            if (sec > 59) {
                sec = 0;
                min++;
            }
            /* Limite de aumento para minutos */
            if (min > 59) {
                min = 0;
            }
            /* Impresion de valores en display de 7seg */
            ui->lcdNumber->display(millisec);
            ui->lcdNumber_2->display(sec);
            ui->lcdNumber_3->display(min);
        }
    }
    /* Botón de reset clickeado */
    else if (reset) {
        millisec = 0;
        sec = 0;
        min = 0;
        ui->lcdNumber->display(millisec);
        ui->lcdNumber_2->display(sec);
        ui->lcdNumber_3->display(min);
    } else {
    }
}

/* Boton de Play */
void MainWindow::on_pushButton_clicked()
{
    play = true;
    stop = false;
    reset = false;
}

/* Boton de Pausa */
void MainWindow::on_pushButton_2_clicked()
{
    play = false;
    stop = true;
    reset = false;
}

/* Boton de Reset */
void MainWindow::on_pushButton_3_clicked()
{
    play = false;
    stop = false;
    reset = true;
}
