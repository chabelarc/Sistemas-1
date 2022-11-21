#define uS_TO_S_FACTOR 1000000 // Factor de conversión s a Us
#define TIME_TO_SLEEP 10 //Tiempo que el ESP va a dormir ne s
#define LED_PIN 32

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
 //Configuración Light Sleep
 esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*uS_TO_S_FACTOR);
 Serial.println("Configurando ESP32 para dormir por" +String(TIME_TO_SLEEP)+ "segundos");
 

}

void loop() {
  delay(500);
  digitalWrite(LED_PIN, LOW);
 esp_light_sleep_start();

 digitalWrite(LED_PIN, HIGH);
 delay(500);

  print_wakeup_reason(); //Indicar la razón por la cual se despertó

}

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason; //Es el tipo de dato _t

  wakeup_reason = esp_sleep_get_wakeup_cause();
  
  switch(wakeup_reason){
    case ESP_SLEEP_WAKEUP_EXT0:
    Serial.println("Inicio causado por señal en RTC_IO (Periféricos del RTC)");
    break;
    case ESP_SLEEP_WAKEUP_EXT1:
    Serial.println("Inicio causado por señal en RTC_CNTL ");
    break;
    case ESP_SLEEP_WAKEUP_TIMER:
    Serial.println("Inicio causado por señal  en el timer");
    break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD:
    Serial.println("Inicio causado por la señal lanzada por el UPL Croprocesador");
    break;
    case ESP_SLEEP_WAKEUP_ULP:
    Serial.println("Inicio causado por señal lanzada por el ULP(ultralow)Croprocesador");
    break;
    default:
    Serial.printf("El inicio no fue causado por ninguna razón conocida: %d\n", wakeup_reason); 
    }
  }
