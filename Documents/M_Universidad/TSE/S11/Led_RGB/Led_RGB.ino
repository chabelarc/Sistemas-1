#define LED_R 14
#define LED_G 27
#define LED_B 12
#define PIN_BUTTON 33

int led_status = 0;

/*Forma automática
typedef enum {
  RED = 1,
  GREEN,
  BLUE,
  CYAN,
  YELLOW,
  MAGENTA,
  WHITE
  LAST
  } RGB_States;
  
RGB_States led_status = 0;

*/

// Deboucing (evitar el rebote del botón)

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

void IRAM_ATTR isr_button(){
  //la función millis nos devuelve la cantidad de milisegundos que han pasado desde que nuestro programa inició
 if( (millis() - lastDebounceTime) >debounceDelay){
  led_status++;
  if(led_status >=8){
    led_status = 0;
    }
    /*
     if(led_status >=LAST){
    led_status = 0;
    }
     */
    lastDebounceTime = millis();
    //Forma 2 //if(led_status >= 7) led_status=0;

    // Forma 3 // led_status = (led_status >= 7) ? 0 : led_status+1; //uso de operador ternario
  }
  
  }

void setup() {
  //Botón
 pinMode(PIN_BUTTON, INPUT);
 attachInterrupt(PIN_BUTTON, isr_button, RISING);
 //Led
 pinMode(LED_R, OUTPUT);
 pinMode(LED_G, OUTPUT);
 pinMode(LED_B, OUTPUT);

 Serial.begin(115200);

}

void loop() {
 switch(led_status){
  //Rojo
  case 1: 
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  break;
   //Verde
  case 2: 
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  break; 
  //Azul
  case 3: 
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  break; 
  //Cyan
  case 4: 
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  break; // Amarillo
  case 5: 
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  break; //Magenta
  case 6: 
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  break;
  //Blanco
  case 7: 
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  break;

  default:  //off
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  break;
  
  }

 /* 
 switch(led_status){
  //Rojo
  case RED: 
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  break;
   //Verde
  case GREEN: 
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  break; 
  //Azul
  case BLUE: 
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  break; 
  //Cyan
  case CYAN: 
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  break; // Amarillo
  case 5: 
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  break; //Magenta
  case 6: 
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  break;
  //Blanco
  case 7: 
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  break;

  default:  //off
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  break;
  
  } */ 
}
