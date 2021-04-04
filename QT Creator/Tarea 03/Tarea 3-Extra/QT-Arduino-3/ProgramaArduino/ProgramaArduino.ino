/* Contador Serial con conexion a QT */

/* Declaracion de variables */
int count;

/* Funcion de configuracion */
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(115200);

  /* Inicializacion de variables */
  count = 0;
}
 
void loop()
{
  count = analogRead(A0);
  count = map(count, 0, 1024, 0, 100);
  
  Serial.print("@");
  Serial.println(count);
  
  delay(25);
    
}

