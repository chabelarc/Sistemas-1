int PIN_RELEVADOR = 15;
int PIN_BUTTON = 33;

int RELEVADOR_STATUS = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 250;

void IRAM_ATTR isr_button(){
  if ((millis() - lastDebounceTime) > debounceDelay){
     RELEVADOR_STATUS++; 
     if (RELEVADOR_STATUS >= 2){RELEVADOR_STATUS = 0;}
     
     lastDebounceTime = millis();
  }
}

void setup() {
 Serial.begin(115200);
 pinMode(PIN_BUTTON, INPUT);
 pinMode(PIN_RELEVADOR, OUTPUT);
 attachInterrupt(PIN_BUTTON, isr_button, RISING);
}

void loop() {
 if (RELEVADOR_STATUS = 0){
  digitalWrite(PIN_RELEVADOR, HIGH);
 }
  else {
   digitalWrite(PIN_RELEVADOR, LOW); 
    }
  
 

}
