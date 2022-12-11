#define RELEVADOR 15
#define PIN_BUTTON 33

bool relay_status = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 300; 

void IRAM_ATTR isr_button(){
  if ((millis() - lastDebounceTime) > debounceDelay){
     relay_status = !relay_status; 
     lastDebounceTime = millis();
  }
}

void setup() {  

  pinMode(PIN_BUTTON, INPUT);
  attachInterrupt(PIN_BUTTON, isr_button, RISING);
  pinMode(RELEVADOR,OUTPUT);

  Serial.begin(115200);
}

void loop() {    
  if(relay_status){digitalWrite(RELEVADOR,HIGH);}
  else{digitalWrite(RELEVADOR,LOW);}
}
