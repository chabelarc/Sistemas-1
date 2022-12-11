#include "FS.h"
#include "SPIFFS.h"
#include <ArduinoJson.h>

void Jsonread(fs::FS &fs, const char * filename) {
   Serial.printf("Reading file: %s\r\n", filename);


  File file = fs.open(filename, "r");

  if(!file || file.isDirectory()){
        Serial.println("Error al abrir el documento");
        return;
    }


  StaticJsonDocument<64> doc;


  DeserializationError error = deserializeJson(doc, file);

   if (error) {
    Serial.print(F("deserialización fallida"));
    Serial.println(error.f_str());
    return;
   }

const char* Nombre_alumno = doc["nombre_alumno"]; 
Serial.print("Nombre del alumno: ");
Serial.println(Nombre_alumno);
}

void setup() {

  Serial.begin(9600);

  if(!SPIFFS.begin(true)){
        Serial.println("SPIFFS Mount Failed");
        return;
    }

}

void loop() {

  Jsonread(SPIFFS, "/json_test.txt");
  delay(5000);
  
}
