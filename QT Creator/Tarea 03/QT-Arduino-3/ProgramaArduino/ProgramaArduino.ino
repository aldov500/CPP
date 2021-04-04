/* Contador Serial con conexion a QT */

/* Declaracion de variables */
int count, buttonRead;
unsigned long timeStampStart;
unsigned long timeStampStop;
bool firstDataSend;

/* Funcion de configuracion */
void setup()
{
  pinMode(7, INPUT_PULLUP);
  Serial.begin(115200);

  /* Inicializacion de variables */
  buttonRead = 0;
  timeStampStart = 0;
  timeStampStop = 0;
  firstDataSend = false;
}

void loop()
{

  buttonRead = digitalRead(7);

  /* Boton presionado */
  if (buttonRead == 0) {

    if (!firstDataSend) {
      /* Bandera de inicio de envio */
      firstDataSend = true;
      /* Guarda tiempo actual */
      timeStampStart = millis();
    }

    else {
      /* Guarda tiempo al soltar botton
       para calcular el Rebote */
      timeStampStop = millis();

      /* Calcula tiempo minimo para lectura correcta */
      if ((timeStampStop - timeStampStart) > 200) {
        /* Cambia bandera */
        firstDataSend = false;
        /* Incrementa el dato a enviar */
        count++;
        
        /* Evalua el limite de datos */
        if (count > 100)
          count = 0;
        
        /* Imprime al monitor serial */
        Serial.print("@");
        Serial.println(count);
      }
    }

  }

  else {

  }
}

