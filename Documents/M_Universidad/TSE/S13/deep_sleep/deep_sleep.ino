RTC_DATA_ATTR int bootCount = 0; //Le agregamos un atributo para que se guarde dentro de la memoria del RTC para que se mantenga en deepsleep
#define uS_TO_S_FACTOR 1000000 // Factor de conversión s a Us
#define TIME_TO_SLEEP 5 //Tiempo que el ESP va a dormir ne s
#define LED_PIN 32
#define BUTTON_PIN 33

void setup() {
  Serial.begin(115200);
  delay(500);
  pinMode(LED_PIN, OUTPUT);
 //Configuración deep Sleep

 esp_sleep_enable_ext0_wakeup ((gpio_num_t)BUTTON_PIN, HIGH);
 
 //esp_sleep_enable_ext0_wakeup (GPIO_NUM_33, HIGH);
 
 esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*uS_TO_S_FACTOR);
 Serial.println("Configurando ESP32 para dormir por"+String(TIME_TO_SLEEP)+ "segundos");
 
bootCount++;
Serial.println("Boot number:" + String(bootCount));
print_wakeup_reason(); //Indicar la razón por la cual se despertó

if(bootCount %2 == 0) { 
  Serial.println("ESP32 se va a dormir ahora");
 esp_deep_sleep_start();
  }

Serial.println("Esta línea solo se imprime en impares"); 
}

void loop() {
  digitalWrite(LED_PIN, LOW);
  delay(500);
esp_light_sleep_start();

 digitalWrite(LED_PIN, HIGH);
 delay(500);

 print_wakeup_reason();
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
