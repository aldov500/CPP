#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <stdlib.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /* Configura la interfáz de usuario */
    ui->setupUi(this);
}

/* Destructor de objeto */
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_buttonEnviar_clicked()
{
    /* Creación de cadenas para almacenar datos de entrada */
    QString dest = ui->textDestinatario->text();
    QString subj = ui->textAsunto->text();
    QString body = ui->textEmail->toPlainText();

    /* Creación del archivo mediante clase QFile */
    QFile file("correo.txt");

    /* Comando de envío de archivo mediante SSMTP */
    QString command = "ssmtp " + dest + "< /home/aldo/Escritorio/Interfaces/'Tarea "
                                        "02'/build-QT-CrearArchivos-Desktop_Qt_5_9_1_GCC_64bit-Debug/"
                                        "correo.txt";

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        /* Llenado de datos al archivo creado */
        QTextStream fileData(&file);
        fileData << "To: " << dest << endl;
        fileData << "From: aldo.vargas@alumnos.udg.mx" << endl;
        fileData << "Subject: " << subj << endl
                 << endl;
        fileData << body << endl;
        file.close();
        /* Envío de archivo mediante comando */
        system(command.toUtf8().constData());
        ui->label_4->setText("Mensaje Enviado Correctamente.");

    }
    else{
        ui->label_4->setText("Error en archivo de correo.");
    }

}

void MainWindow::on_buttonLimpiar_clicked()
{
    /* Limpia todos los campos */
    ui->textAsunto->clear();
    ui->textDestinatario->clear();
    ui->textEmail->clear();
    ui->label_4->clear();
}
