
//Podemos definir una variable o una macro
//int pinLDR=34; (forma de variable)
//const int no permite cambiar el valor de la variable posteriormente desde la compilación
//#define PIN_LDR 34 (forma macros/no lleva punto y coma) 
//Cambia en donde se almacenan las cosas (macros y variable)

#define PIN_LDR 34
#define PIN_LM 35
#define PIN_LED 32


void setup() {
  Serial.begin (9600); // Velocidad de comunicación con la computadora por USB (bytes por segundo)
  pinMode(PIN_LED,OUTPUT);
}

void loop() {
  /* analogRead (PIN_LDR);
   * analogRead (34);
   *int m = analogRead (PIN_LDR);  se conecta al ADC y convierte la señal para acá 
 analogRead (34) y analogRead (PIN_LDR) son equivalentes, sin embargo, al cambiar el numero de pin en define, ya no será necesario mofificar todo   
 */

 //Vamos a leer el fotoresistor

 Serial.println(analogRead (PIN_LDR)); 
  //Si esta oscuro, enciende LED
  if (analogRead(PIN_LDR)>300){
    digitalWrite(PIN_LED,LOW);    
  }
  else{
    digitalWrite(PIN_LED,HIGH);
  }

  
 //Vamos a leer la temperatura
 Serial.print(analogRead (PIN_LM)*0.1221); // multiplicamos para que se muestre en grados C 
 
}

//Necesitamos saber la resolución de nuestro sensor
//5000/(10*4095)= 0.1221
