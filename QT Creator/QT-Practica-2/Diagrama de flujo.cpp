
Define Librerías a utilizar
Utilización de namespace cv y std
Declaración de la cámara

primeraVez = false;
Declaración de variables para mouse event
Declaración de Matrices Globales
Variable para el Area

Declaración de variables para Calibración
Declaración de banderas de control

MainWindow{
	Configura Ventana
    buscaYconectaArduino(); 
    Crea timer para la funcion ftimer
    Abre la Camara
}

mousePressEvent{
    Toma coordenadas 

    if (Click dentro de ventana) {
        Detectar el clic 1 y el clic 2
        if (!primeraVez) {
            Cambia bandera
            Toma coordenadas de clicks
            Toma tamaño de click
        } else {
            Cambia bandera
            Toma coordenadas de clicks
            Toma tamaño de click
        }
    }
}

detectarColor{
    Extraemos un color con inRange
    Creamos un vector de vectores para guardar el contorno
    Copiamos la imagen ya filtrada
    Aplicamos findCountours para encontrar los puntos que conformar los contornos
    
    for (contadorparacontornos) {
        Guarda el area de cada contorno detectado
        Muestra en consola el area
        if (area > area2) {
        	Guardamos en area 2 el area mas grande detectado
        }
    }
    if (area2 > 5) { 
        detectado = true;
    } else {
        detectado = false;
    }
}

void MainWindow::ftimer()
{
    Captura la imagen de camara IP cada 10ms
    if (CamaraAbierta) {
        Guarda imagen en matriz
        Se redimensiona la imagen

        Define Point
        

        if (checkbox está seleccionda) {
            Coordenadas de Click
            Tamaño de Click
        }

        Define un rectuangulo

        if (Click dentro de Ventana) {

            Extraer la ROI de la IMAGENpequena
	        Redimensiona 
            Muestra Imagen
        }
        Dibujar un rectangulo del tamanio de la ROI en IMAGENPequena
        Mostrar la imagen original
        Declara ImagenChica
        Guarda el mapa de pixeles
      	Muestra imagen en etiqueta
    }

    if (!imagenROIGRANDE está vacía && Puerta Cerrada) {
        detectarColor(r_canal0Max, r_canal0Min, r_canal1Max, r_canal1Min, r_canal2Max, r_canal2Min);
        Muestra Imagen
        if (detectado) {
            Muestra el mensaje("Rojo Detectado");
            if (ArduinoDisponible) {
                Envia valores al Arduino
                Abre puerta de Servo
            }
        } else {
            detectarColor(g_canal0Max, g_canal0Min, g_canal1Max, g_canal1Min, g_canal2Max, g_canal2Min);
            Muestra imagen
            if (detectado) {
                Muestra el mensaje("Verde Detectado");
                if (ArduinoDisponible) {
                    Escribe Valores
                    Abre puerta del Servo
                }
            } else {
                detectarColor(b_canal0Max, b_canal0Min, b_canal1Max, b_canal1Min, b_canal2Max, b_canal2Min);
                Muestra imagen
                if (detectado) {
                    Muestra el mensaje("Verde Detectado");
                        if (ArduinoDisponible) {
                    	Escribe Valores
                    	Abre puerta del Servo
                	}
                } else {
                    Muestra el mensaje("Nada Detectado");
                }
            }
        }
    } else {
        Muestra el mensaje("Puerta abierta");
    }
}

void MainWindow::buscaYconectaArduino()
{
    //Parte # 1, declaración inicial de las variables
    Inicializa el Arduino
    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::recepcionSerialAsyncrona);


    //Parte # 2,buscar puertos con los identificadores de Arduino
    Mensaje de Debug "Puertos disponibles: " << QSerialPortInfo::availablePorts().length();
    foreach (const QSerialPortInfo& serialPortInfo, QSerialPortInfo::availablePorts()) {
        Mensaje de Debug "Identificador del fabricante (VENDOR ID): " << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier()) {
            Mensaje de Debug "ID Vendedor " << serialPortInfo.vendorIdentifier();
            Mensaje de Debug "ID Producto: " << serialPortInfo.productIdentifier();

            if (serialPortInfo.productIdentifier() == arduino_UNO || serialPortInfo.productIdentifier() == arduino_MEGA) {
                ArduinoDisponible = true;
                serialName = serialPortInfo.portName();
                serialProductID = serialPortInfo.productIdentifier();
            }
        }
    }
    //Parte # 3, conexión del puerto encontrado con Arduino
    if (ArduinoDisponible) {
        Configura puerto Arduinio
        Establece lectura y escritura
        Establece velocidad de transmision
        Establece la paridad
        Mensaje de Debug "Producto: " << serialProductID;
        if (serialProductID == arduino_UNO)
            Mensaje de Debug("Arduino UNO R3 conectado");
        else if (serialProductID == arduino_MEGA)
            Mensaje de Debug("Arduino MEGA conectado");
        else
            Mensaje de Debug("Error 3");
    } else {
        ui->estado->clear();
        Mensaje de Debug("No hay arduino");
    }
}

void MainWindow::recepcionSerialAsyncrona()
{
    if (ArduinoDisponible && Arduino es leible) {
        //QByteArray datosLeidos = arduino->readAll();
        Lee arduino
        Guarda indice("\n");
        Guarda indice("@");
        Construye string
        Convierte string a entero
        Mensaje de Debug "Dato: " << datoEntero << endl;
        if (indice0 >= 0 && indice1 >= 0) {
            puerta = false;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Funciones de Cambio para Sliders
void MainWindow::on_c0_min_valueChanged(int value)
{
    ui->lcd_c0_min->display(value);
}

