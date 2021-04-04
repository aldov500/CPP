//Definicion de pines a utilizar 

Declara Variable para el control de pulsaciones
Declara variable para cadena de entrada
Declara vector para guardar datos
Declara bandera de fin de cadena

void setup() {
  Configuracion de comunicacion serial
  Reserva memoria para cadena

  Configuracion de entradas y salidas
  pinMode(boton,INPUT_PULLUP);
  Activa interrupcion de boton
}

void loop() { 
  if(finCadena){                               //Se termino de recibir una cadena completa
    finCadena = false;                                  //Permitimos volver a recibir otra cadena
    Convertimos el string a un vectorChar
    Convertimos un vectorChar a un entero
    
    //Comparamos el valor recibido y aplicamos la instruccion correspondiente
    if(numeroEntero == 1){
      Escribe en Arduino(colorRojo,HIGH);
    }
    else if(numeroEntero == 2){
      Escribe en Arduino(colorRojo,LOW);
    }
    else if(numeroEntero == 3){
      Escribe en Arduino(colorAzul,HIGH);
    }
    else if(numeroEntero == 4){
      Escribe en Arduino(colorAzul,LOW);
    }
    else if(numeroEntero == 5){
      Escribe en Arduino(colorVerde,HIGH);
    }
    else if(numeroEntero == 6){
      Escribe en Arduino(colorVerde,LOW);
    }
    else if(numeroEntero == 7){
      Escribe en Arduino(l_blanco,HIGH);
    }
    else if(numeroEntero == 8){
      Escribe en Arduino(l_blanco,LOW);
    }
    else if(numeroEntero == 9){
      int valor_sensor = analogRead(A0);
      // Convierto la lectura analogica (la cual va desde 0 - 1023) hacia un voltaje (0 - 5V):
      float voltaje = valor_sensor * (5.0 / 1023.0);
      Envia serial("@");
      Envia serialln(voltaje);

    }
    cadenaCharEntrada = ""; 
  }
}

void evento Serial(){
  //Recepción de datos Seriales
  while (Serial.disponible()) {              //Si existen datos seriales, leer a todos
    char CaracterEntrada = Lee serialmente();   //Leer 1 byte serial recibido
    cadenaCharEntrada += CaracterEntrada;   //Agregar el nuevo char a una cadena String 
    if (CaracterEntrada == '\n') {          //Si el char o byte recibido es un fin de linea, activa la bandera
      finCadena = true;                        //Si la bandera finCadena = 1, entonces la transmision esta completa
    }
  }
}
