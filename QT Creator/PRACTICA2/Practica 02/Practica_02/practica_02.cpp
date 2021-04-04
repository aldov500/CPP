#include "practica_02.h"

/*  Constructor
 *     
 *     
 */
colorDetector::colorDetector() {
  arduino_is_available = false;
  arduino_port_name = "";
  arduino = new QSerialPort;

  nombreArchivo = "detectionReport.csv";
  arduino_uno_vendor_id = 0x1a86;
  arduino_uno_product_id = 0x7523;
  redDet = false;
  greenDet = false;
  blueDet = false;
}

/*  sendEmail
 *    - Envia correo a la direccion ingresada
 *      con el archivo del reporte
 */

void colorDetector::sendEmail(QString d) {
  // QString destinatario = "aldo.vargas.meza94@gmail.com";
  QString destinatario = d;
  QString command = "mpack -s subject reporte.csv " + destinatario;

  int arr = destinatario.indexOf("@");
  int com = destinatario.indexOf(".com");
  int udg = destinatario.indexOf(".udg");

  if ((arr >= 0 && com >= 0) || (arr >= 0 && udg >= 0)) {
    system(command.toUtf8().constData());
  } else {

    qDebug() << "Error con el email.";
  }
}

/*  logData
 *     - Gaurda registro de Eventos de deteccion
 *     
 */

void colorDetector::logData(QString event, QString col) {
  QFile reporte(nombreArchivo);
  QFileInfo existe(nombreArchivo);

  color = col;
  evento = event;

  fecha = QDate::currentDate();
  hora = QTime::currentTime();

  tiempoLocal = fecha.toString() + " " + hora.toString();

  if (!existe.exists()) {
    reporte.open(QIODevice::WriteOnly);
    QTextStream out(&reporte);
    out << "EVENTO"
        << ",";
    out << "COLOR"
        << ",";
    out << "NOMBRE IMAGEN"
        << ",";
    out << "FECHA Y HORA \n";
    reporte.close();
  }

  if (existe.isFile() && existe.exists()) {
      QString nombreImagen = "detection_0" + QString::number(contador) + ".jpg";
      cv::imwrite(nombreImagen.toUtf8().constData(), COLOR);
    if (reporte.open(QIODevice::WriteOnly | QIODevice::Append)) {
      QTextStream out(&reporte);
      out << evento.toUtf8().constData() << ",";
      out << color.toUtf8().constData() << ",";
      out << "detection_0" << contador << ".jpg"<< ",";
      out << tiempoLocal.toUtf8().constData() << "\n";
      reporte.close();


    }

  }

  contador++;
}

/*  detect
 *     Detecta el color
 *     param: Arreglo de valores, Color
 */
void colorDetector::detect(int color[], QString led) {
  cv::inRange(HSV, Scalar(color[0], color[2], color[4]),
              Scalar(color[1], color[3], color[5]), COLOR);

  BlackPixels = TotalNumberOfPixels - countNonZero(COLOR);
  WhitePixels = TotalNumberOfPixels - BlackPixels;

  if (WhitePixels > LIM_DETECT) {
    if (arduino_is_available) {
      if (arduino->isWritable()) {
        if (led == "Rojo") {
          arduino->write("5"); // off Azul
          arduino->write("3"); // off Verde

          arduino->write("0"); // on rojo

          if (logg == false && redDet == false) {
            logData("DETECCION", led);
            logg = true;
            redDet = true;
            qDebug() << "Deteccion " << led;
          }
          else{

          }

        } else if (led == "Verde") {
          arduino->write("5"); // off Azul
          arduino->write("1"); // off Rojo

          arduino->write("2"); // on Verde

          if (logg == false && greenDet == false) {
            logData("DETECCION", led);
            logg = true;
            greenDet = true;
            qDebug() << "Deteccion " << led;
          }
          else{

          }

        } else if (led == "Azul") {
          arduino->write("3"); // off Verde
          arduino->write("1"); // off Rojo

          arduino->write("4"); // on Azul

          if (logg == false && blueDet == false) {
            logData("DETECCION", led);
            logg = true;
            blueDet = true;
            qDebug() << "Deteccion " << led;
          }
          else{

          }
        }
      }

    } else {
      qDebug() << "Arduino NO ESCRIBIBLE";
    }
  }

  else if (WhitePixels < 100) {
    if (led == "Rojo") {
      redDet = false;
    } else if (led == "Verde") {
      greenDet = false;
    } else if (led == "Azul") {
      blueDet = false;
    }

    logg = false;
    arduino->write("3"); // off Verde
    arduino->write("1"); // off Rojo
    arduino->write("5"); // off Azul
    qDebug() << "Deteccion en curso";
  }
}

void colorDetector::arduinoAvailable() {
  if (!arduino_is_available) {
    qDebug() << "Arduino no Conectado";

    foreach (const QSerialPortInfo &serialPortInfo,
             QSerialPortInfo::availablePorts()) {
      qDebug() << "Puerto Usb Conectado";

      if (serialPortInfo.hasVendorIdentifier() &&
          serialPortInfo.hasProductIdentifier()) {
        if (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id) {
          if (serialPortInfo.productIdentifier() == arduino_uno_product_id) {
            arduino_port_name = serialPortInfo.portName();
            arduino->setPortName(arduino_port_name);
            arduino->open(QIODevice::ReadWrite);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            arduino_is_available = true;

            qDebug() << "Arduino Conectado";
          } else {
            qDebug() << "El Arduino no corresponde";
          }
        } else {
          qDebug() << "Dispositivo no es Arduino";
        }
      } else {

        qDebug() << "Dispositivo sin identificador";
      }
    }
  } else {
  }
}
