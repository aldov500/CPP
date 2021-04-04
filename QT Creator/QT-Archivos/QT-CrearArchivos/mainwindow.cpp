#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  /* Guarda el Texto en el lineEdit */
  QString nombreArchivo = ui->TextoNombre->text();
  /* Guarda multiples lineas en una linea plana */
  QString contenidoArchivo = ui->TextoArchivo->toPlainText();

  /* Creación de objeto tipo QFile*/
  QFile archivo(nombreArchivo);

  /* Abrir el archivo como solo lectura */
  if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
    /* Buffer de datos */
    QTextStream datosArchivo(&archivo);
    /* Escribir los datos en el buffer */
    datosArchivo << contenidoArchivo << endl;
    /* Cerrar el archivo */
    archivo.close();
    ui->label_3->setText("Archivo " + nombreArchivo + " creado.");
  }
}

void MainWindow::on_TextoNombre_textChanged(const QString& arg1) {
  ui->label_3->clear();
}
