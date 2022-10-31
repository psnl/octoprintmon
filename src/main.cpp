#include <Arduino.h>
#include <communication.h>
#include <display.h>
#include <opm-config.h>

#include "FS.h"
#include "SPIFFS.h"


QueueHandle_t queueCommToDisplay;
QueueHandle_t queueDisplayToComm;


Config config;

void setup() {

  Serial.begin(115200);

  ConfigHelper::Init();
  ConfigHelper::Read(config);

  Serial.print("OctoPrint IP : ");
  Serial.println(config.octoPrintIp);
  Serial.print("OctoPrint Port : ");
  Serial.println(config.octoPrintPort);
  Serial.print("OctoPrint API : ");
  Serial.println(config.octoPrintApi);
  Serial.print("Timezone : ");
  Serial.println(config.timeZone);

  queueCommToDisplay = xQueueCreate( 1, sizeof(TQueueCommToDisplay));
  queueDisplayToComm = xQueueCreate( 1, sizeof(TQueueDisplayToComm));

  xTaskCreatePinnedToCore(Display::Task, "taskDisplay", 4096, NULL, 1, NULL, 1);

  xTaskCreatePinnedToCore(Communication::Task, "taskCommunication", 4096, NULL, 1, NULL, 1);

}

void loop() {
  delay(100);
}
