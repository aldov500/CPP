int contador = 0;
unsigned long tiempo0 = 0;
unsigned long tiempo1 = 0;
bool primeraVez = false;

void setup() {
   pinMode(7, INPUT_PULLUP);  //Declarar el pin 7 como entrada con pull-up
   Serial.begin(9600); // Iniciar el puerto serial a 9600 BAUDs

}

void loop() {

  //Leer el estado de la entrada digital 7
  int estadoBoton = digitalRead(7); 
  //Serial.println(estadoBoton);
  
  if(estadoBoton == 0){
    //El boton esta activado
    if(!primeraVez){ primeraVez = true; tiempo0 = millis(); }  //Se detecta la primera activacion y se guarda ese tiempo
    else{
      tiempo1 = millis();     //En los rebotes se verifica el tiempo, aqui se podria llamar a otra funcion para aprovechar el tiempo del procesador
      if((tiempo1-tiempo0)>200) {  //Si el tiempo supera los 200ms entonces activamos las instrucciones correspondientes
          //Se activo el boton y pasaron 200ms
          primeraVez = false;
          contador++;
          if(contador>30) contador=0;
          Serial.print("@");
          Serial.println(contador);
      }
    }
    
    
  }
  else{
    //contador=0;
    //El boton esta desactivado
   // Serial.println("Boton desactivado");
  }

}

