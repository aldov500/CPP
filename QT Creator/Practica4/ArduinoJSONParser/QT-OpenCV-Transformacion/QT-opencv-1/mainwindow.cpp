#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QtNetwork>

/* Configuraciones Globales */
#define IP 0
#define WINW 648
#define WINH 450
using namespace cv;

bool primeraVez = false;

int xEtiqueta = 0;
int yEtiqueta = 0;
int numeradorComponentesColocados = 0;

Point componentesColocados[500];
Point origenMouse;
Size tamanioMouse;

Point2f puntosOrigen[4];
Point2f puntosCalibrado[4];

VideoCapture camara1(IP);

QString cadenaJSON;
QString xG, yG;

/* Main */
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    puntosCalibrado[0].x = 0;
    puntosCalibrado[0].y = 0;

    puntosCalibrado[1].x = 396;
    puntosCalibrado[1].y = 0;

    puntosCalibrado[2].x = 396;
    puntosCalibrado[2].y = 450;

    puntosCalibrado[3].x = 0;
    puntosCalibrado[3].y = 450;

    QTimer* cronometro = new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(30);

    if (!camara1.isOpened()) {
        camara1.open(IP);
    }

    conectarArduino();
}

/* Evento: Click */
void MainWindow::mousePressEvent(QMouseEvent* evento)
{
    int xGlobal = evento->x();
    int yGlobal = evento->y();

    // Calibrado seleccionado
    if (ui->checkBoxCalibrado->isChecked()) {
        if (xGlobal >= 0 && xGlobal <= 396 && yGlobal >= 0 && yGlobal <= 450) {
            // Coordenadas con decimal
            double xGlobalDouble = (double)xGlobal * 0.055555556;
            double yGlobalDouble = abs((double)yGlobal * 0.055555556 - 25);
            // Coordenadas en Int
            xEtiqueta = xGlobal;
            yEtiqueta = yGlobal;
            // Muestra las coordenadas
            ui->lcdNumber->display(xGlobalDouble);
            ui->lcdNumber_2->display(yGlobalDouble);
            // Guarda el JSON
            xG = QString::number(xGlobalDouble);
            yG = QString::number(yGlobalDouble);
        }

    } else {

        xGlobal = evento->x();
        yGlobal = evento->y() - 45;

        if (xGlobal >= 0 && xGlobal < 640 && yGlobal >= 0 && yGlobal < 360) {

            xEtiqueta = xGlobal;
            yEtiqueta = yGlobal;
            //Ocurrio dentro de la etiqueta
            //La casilla de calibracion esta activa
            if (ui->checkBoxCalibrar->isChecked()) {
                if (ui->radioButtonPunto0->isChecked()) {
                    puntosOrigen[0].x = xGlobal;
                    puntosOrigen[0].y = yGlobal;
                } else if (ui->radioButtonPunto1->isChecked()) {
                    puntosOrigen[1].x = xGlobal;
                    puntosOrigen[1].y = yGlobal;
                } else if (ui->radioButtonPunto2->isChecked()) {
                    puntosOrigen[2].x = xGlobal;
                    puntosOrigen[2].y = yGlobal;
                } else if (ui->radioButtonPunto3->isChecked()) {
                    puntosOrigen[3].x = xGlobal;
                    puntosOrigen[3].y = yGlobal;
                }
            }
        }
    }
}

/* Click Boton */
void MainWindow::on_pushButton_clicked()
{
    if (arduino_esta_conectado && arduino->isWritable()) {
        arduino->write(cadenaJSON.toUtf8().constData());
        qDebug() << "Enviado a arduino";
    }
}

/* Funcion repetitiva */
void MainWindow::funcionActivacionTimer()
{
    //Aqui se captura la imagen de camara IP cada 30ms
    if (camara1.isOpened()) { //Paso # 1
        Mat IMAGEN;
        Mat IMAGENpequena;
        camara1 >> IMAGEN; //Paso # 2
        cv::resize(IMAGEN, IMAGENpequena, Size(640, 360)); //Paso # 3

        if (ui->checkBoxCalibrar->isChecked()) {
            circle(IMAGENpequena, puntosOrigen[0], 7, Scalar(0, 0, 255), 3, 8, 0);
            circle(IMAGENpequena, puntosOrigen[1], 7, Scalar(0, 255, 255), 3, 8, 0);
            circle(IMAGENpequena, puntosOrigen[2], 7, Scalar(255, 0, 255), 3, 8, 0);
            circle(IMAGENpequena, puntosOrigen[3], 7, Scalar(255, 0, 0), 3, 8, 0);
            line(IMAGENpequena, puntosOrigen[0], puntosOrigen[1], Scalar(255, 0, 0), 2, 8, 0);
            line(IMAGENpequena, puntosOrigen[1], puntosOrigen[2], Scalar(255, 0, 0), 2, 8, 0);
            line(IMAGENpequena, puntosOrigen[2], puntosOrigen[3], Scalar(255, 0, 0), 2, 8, 0);
            line(IMAGENpequena, puntosOrigen[3], puntosOrigen[0], Scalar(255, 0, 0), 2, 8, 0);
        }

        if (ui->checkBoxCalibrado->isChecked()) {
            Mat resultado;
            Mat lambda(2, 4, CV_32FC1);
            lambda = getPerspectiveTransform(puntosOrigen, puntosCalibrado);
            warpPerspective(IMAGENpequena, resultado, lambda, Size(396, 450));

            for (int jj = 0; jj <= numeradorComponentesColocados - 1; jj++) {
                circle(resultado, componentesColocados[jj], 5, Scalar(255, 255, 255), 1, 8, 0);
            }

            int anchoZoom = ui->verticalSlider->value();
            int largoZoom = anchoZoom;

            int xZoom = xEtiqueta - anchoZoom / 2;
            int yZoom = yEtiqueta - largoZoom / 2;

            Mat Zoom;
            Mat ZoomGrande;

            if (xZoom >= 0 && yZoom >= 0 && yZoom <= resultado.rows - anchoZoom && xZoom <= resultado.cols - largoZoom) {
                Rect region1(Point(xZoom, yZoom), Size(anchoZoom, largoZoom));

                Zoom = resultado(region1);

                cv::resize(Zoom, ZoomGrande, Size(200, 200), 0, 0, 0);
            }

            QImage qImage = Mat2QImage(resultado);
            QPixmap pixmap = QPixmap::fromImage(qImage);
            ui->labelIMG1->clear();
            ui->labelIMG1->setPixmap(pixmap);

            qImage = Mat2QImage(ZoomGrande);
            pixmap = QPixmap::fromImage(qImage);
            ui->labelIMG2->clear();
            ui->labelIMG2->setPixmap(pixmap);

        } else {

            int anchoZoom = ui->verticalSlider->value();
            int largoZoom = anchoZoom;

            int xZoom = xEtiqueta - anchoZoom / 2;
            int yZoom = yEtiqueta - largoZoom / 2;

            Mat Zoom;
            Mat ZoomGrande;

            if (xZoom >= 0 && yZoom >= 0 && yZoom <= IMAGENpequena.rows - anchoZoom && xZoom <= IMAGENpequena.cols - largoZoom) {
                Rect region1(Point(xZoom, yZoom), Size(anchoZoom, largoZoom));

                Zoom = IMAGENpequena(region1);

                cv::resize(Zoom, ZoomGrande, Size(200, 200), 0, 0, 0);
            }

            QImage qImage = Mat2QImage(IMAGENpequena);
            QPixmap pixmap = QPixmap::fromImage(qImage);
            ui->labelIMG1->clear();
            ui->labelIMG1->setPixmap(pixmap);

            qImage = Mat2QImage(ZoomGrande);
            pixmap = QPixmap::fromImage(qImage);
            ui->labelIMG2->clear();
            ui->labelIMG2->setPixmap(pixmap);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{

    QString t1x = xG;//QString::number(xEtiqueta); //ui->lineEdit->text();
    double t1xi = t1x.toDouble();
    QString t1x1 = QString::number(t1xi);

    QString t1y = yG;//QString::number(yEtiqueta); //ui->lineEdit_2->text();
    double t1yi = t1y.toDouble();
    QString t1y1 = QString::number(t1yi); //Validacion

    QString t2 = ui->comboBoxH->currentText();
    //int t2i = t2.toInt();

    QString t3 = ui->comboBoxS->currentText();
    //int t3i = t3.toInt();

    cadenaJSON = "{\"X\":\"" + t1x1 + "\",\"Y\":\"" + t1y1 + "\",\"Stack\":\"" + t3 + "\",\"Head\":\"" + t2 + "\"}";
    ui->labelJSON->setText(cadenaJSON);
}

void MainWindow::on_pushButtonAgregar_clicked()
{
    numeradorComponentesColocados++;

    if (numeradorComponentesColocados > 499) {
        numeradorComponentesColocados = 0;
    }

    componentesColocados[numeradorComponentesColocados - 1].x = xEtiqueta;
    componentesColocados[numeradorComponentesColocados - 1].y = yEtiqueta;
    ui->lcdNumber_3->display(numeradorComponentesColocados);

    QString cabeza = ui->comboBoxH->currentText() + ";";
    QString stack = ui->comboBoxS->currentText() + ";";
    QString angulo = ui->comboBoxR->currentText() + ";";
    QString altura = ui->comboBoxHI->currentText() + ";";
    QString skip = ui->comboBoxSK->currentText() + ";";
    QString referencia = ui->lineEdit->text() + ";";
    QString comentario = ui->lineEdit_2->text();
    QString xCoordenada = QString::number(xEtiqueta) + ";";
    QString yCoordenada = QString::number(yEtiqueta) + ";";

    QFile archivo("PICKANDPLACE.csv");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        //Paso # 5 - Crear un buffer para los datos
        QTextStream datosArchivo(&archivo);

        //Paso # 6 - Escrbir los datos al buffer(archivo)
        datosArchivo << cabeza << stack << xCoordenada << yCoordenada << angulo << altura << skip << referencia << comentario << endl;

        //PASO # 7 - Cerrar el archivo
        archivo.close();
    }
}

void MainWindow::recepcionSerialAsyncrona()
{
    if (arduino_esta_conectado && arduino->isReadable()) {

        QByteArray datosLeidos = arduino->readLine();
        int indice0 = datosLeidos.indexOf("}") - 1;
        int indice1 = datosLeidos.indexOf(":") + 2;

        QString infoExtraida = datosLeidos.mid(indice1, indice0 - indice1);


        // ui->lcdNumber->display(datoEntero);
        if (indice0 >= 0 && indice1 >= 0) {
            qDebug() << "Datos leidos: " << datosLeidos << endl;
            qDebug() << "Dato Extraido: " << infoExtraida << endl;
        }
    }
}

void MainWindow::conectarArduino()
{

    //Parte # 1, declaración inicial de las variables
    arduino_esta_conectado = false;
    arduino = new QSerialPort(this);
    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::recepcionSerialAsyncrona);

    QString nombreDispositivoSerial = "";
    int nombreProductID = 0;

    //-2 buscar puertos con los identificadores de Arduino
    qDebug() << "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo& serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier()) {
            qDebug() << "ID Vendedor " << serialPortInfo.vendorIdentifier();
            qDebug() << "ID Producto: " << serialPortInfo.productIdentifier();

            if (serialPortInfo.productIdentifier() == 66 || serialPortInfo.productIdentifier() == 67 || serialPortInfo.productIdentifier() == 29987) {
                arduino_esta_conectado = true;
                nombreDispositivoSerial = serialPortInfo.portName();
                nombreProductID = serialPortInfo.productIdentifier();
            }
        }
    }

    //3-Conexion
    if (arduino_esta_conectado) {

        arduino->setPortName(nombreDispositivoSerial);
        arduino->open(QIODevice::ReadWrite);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        ui->label->clear();
        qDebug() << "Producto: " << nombreProductID;
        if (nombreProductID == 67)
            ui->label->setText("Arduino UNO R3 conectado");
        else if (nombreProductID == 66)
            ui->label->setText("Arduino Mega conectado");
        else if (nombreProductID == 29987)
            ui->label->setText("Arduino Nano conectado");
        else
            ui->label->setText("Error 3");

    } else {
        ui->label->clear();
        ui->label->setText("No hay arduino");
    }
}
