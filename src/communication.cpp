#include <communication.h>
#include "index.h"
#include <AsyncElegantOTA.h>
#include "opm-config.h"

AsyncWebServer server(80);
DNSServer dns;
extern StaticJsonDocument<200> jsonDoc;
WiFiClient client; 

extern Config config;

const char* opm_version = "v1.01";

const std::string Communication::name = "OctoPrintMon";

extern QueueHandle_t queueCommToDisplay;
extern QueueHandle_t queueDisplayToComm;


void Communication::ConfigModeCallback(AsyncWiFiManager* wifiManager)
{
    TQueueCommToDisplay queue;
    queue.connectionState = ConnectionStatus::WIFI_AP_ACTIVE;
    xQueueOverwrite(queueCommToDisplay, &queue);
    xQueueOverwrite(queueCommToDisplay, &queue);
    Serial.println("Config");
}

void Communication::Task( void * pvParameters )
{
    TQueueCommToDisplay queue;
    TQueueDisplayToComm queueDC;
    String taskMessage = "Task running on core ";
    taskMessage = taskMessage + xPortGetCoreID();

    IPAddress ip(127,0,0,1);  
    ConfigHelper::Read(config);
    ip.fromString(config.octoPrintIp);
    const int octoprint_httpPort = config.octoPrintPort;  //If you are connecting through a router this will work, but you need a random port forwarded to the OctoPrint server from your router. Enter that port here if you are external
    String octoprint_apikey = config.octoPrintApi; //See top of file or GIT Readme about getting API key
    const char * defaultTimezone = config.timeZone;

    OctoprintApi api(client, ip, octoprint_httpPort, octoprint_apikey);  

    WiFi.setHostname("OctoPrintMon");
    AsyncWiFiManager wifiManager(&server,&dns);

    // reset settings - for testing
    //wifiManager.resetSettings();
    //WiFi.disconnect(true, true);

    // WiFi.mode(WIFI_AP_STA); // cannot erase if not in STA mode !
    // WiFi.persistent(true);
    // WiFi.disconnect(true,true);
    // WiFi.persistent(false);    
    // while(true)
    // {
    //     delay(1000);
    // };
    queue.connectionState = ConnectionStatus::WIFI_CONNECTING;
    xQueueOverwrite(queueCommToDisplay, &queue);


    wifiManager.setAPCallback(ConfigModeCallback);
    if(!wifiManager.autoConnect(name.c_str(), "00000000", 5)) {
        Serial.println("failed to connect and hit timeout");
        //reset and try again, or maybe put it to deep sleep
        ESP.restart();
        delay(1000);
    }


    Serial.print("Connected ");
    Serial.println(WiFi.localIP().toString().c_str());

    OpmTime::Init(defaultTimezone);

    queue.connectionState = ConnectionStatus::WIFI_CONNECTING;
    xQueueOverwrite(queueCommToDisplay, &queue);
  
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
       String s = index_html; //Read HTML contents
        request->send(200, "text/html", s); //Send web page
    });

    server.on("/values", HTTP_GET, [](AsyncWebServerRequest *request){
        ConfigHelper::Read(config);
        JsonObject object = jsonDoc.to<JsonObject>();
        object[ConfigHelper::CFG_OPM_OCTOPRINT_IP] = (const char *)config.octoPrintIp;
        object[ConfigHelper::CFG_OPM_OCTOPRINT_PORT] = (int)config.octoPrintPort;
        object[ConfigHelper::CFG_OPM_OCTOPRINT_API] = (const char *)config.octoPrintApi;
        object[ConfigHelper::CFG_OPM_TIMEZONE] = (const char *)config.timeZone;
        object[ConfigHelper::CFG_OPM_VERSION] = (const char *)opm_version;
        String jsonString;
        serializeJson(jsonDoc, jsonString);
        Serial.println(jsonString);
        request->send(200, "text/plane", jsonString); 
    });

  server.on("/", HTTP_POST, 
    [](AsyncWebServerRequest *request){},
    [](AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data, size_t len, bool final){},
    [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
    {
      ConfigHelper::Read(config);
      DeserializationError error = deserializeJson(jsonDoc, data, len);
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
      }
      
      if (jsonDoc.containsKey(ConfigHelper::CFG_OPM_OCTOPRINT_IP)) {
          snprintf(config.octoPrintIp, sizeof(config.octoPrintIp), (const char *)jsonDoc[ConfigHelper::CFG_OPM_OCTOPRINT_IP]);
      }
      else {
          snprintf(config.octoPrintIp, sizeof(config.octoPrintIp), "192.168.1.1");
      }

      if (jsonDoc.containsKey(ConfigHelper::CFG_OPM_OCTOPRINT_PORT)) {
            config.octoPrintPort = (int)jsonDoc[ConfigHelper::CFG_OPM_OCTOPRINT_PORT];
      }
      else {
          config.octoPrintPort = 80;
      }

      if (jsonDoc.containsKey(ConfigHelper::CFG_OPM_OCTOPRINT_API)) {
          snprintf(config.octoPrintApi, sizeof(config.octoPrintApi), (const char *)jsonDoc[ConfigHelper::CFG_OPM_OCTOPRINT_API]);
      }
      else {
          snprintf(config.octoPrintApi, sizeof(config.octoPrintApi), "-");
      }

      if (jsonDoc.containsKey(ConfigHelper::CFG_OPM_TIMEZONE)) {
          snprintf(config.timeZone, sizeof(config.timeZone), (const char *)jsonDoc[ConfigHelper::CFG_OPM_TIMEZONE]);
      }
      else {
          snprintf(config.timeZone, sizeof(config.timeZone), "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00");
      }

      ConfigHelper::Write(config);
      request->send(200, "text/plane", "OK");
    }
  );
    server.begin();
    AsyncElegantOTA.begin(&server);    // Start ElegantOTA

    while(true){
        delay(2000);
        if (WiFi.status() == WL_CONNECTED) 
        { //Check WiFi connection status     
            if(api.getPrinterStatistics() && api.getPrintJob())
            {   
                if (xQueueReceive(queueDisplayToComm, &queueDC, 0) == pdTRUE)
                {
                    switch (queueDC.command)
                    {
                        case Command::SET_TOOL_TEMP:
                            api.octoPrintSetTool0Temperature(queueDC.value);
                            Serial.println(queueDC.value);
                            break;
                        case Command::SET_BED_TEMP:
                            api.octoPrintSetBedTemperature(queueDC.value);
                            Serial.println(queueDC.value);
                            break;
                        case Command::PRINT_STOP:
                            api.octoPrintJobCancel();
                            Serial.println(queueDC.value);
                            break;
                        case Command::PRINT_PLAY:
                            api.octoPrintJobResume();
                            Serial.println(queueDC.value);
                            break;
                        case Command::PRINT_PAUSE:
                            api.octoPrintJobPause();
                            Serial.println(queueDC.value);
                            break;
                    }
                }

                if ((api.printerStats.printerBedTempActual > 0.0f) && (api.printJob.printerState != "Offline"))
                {
                    queue.connectionState = ConnectionStatus::OCTOPRINT_PRINTER_CONNECTED;
                    queue.tempBedActual = api.printerStats.printerBedTempActual;
                    queue.tempBedTarget = api.printerStats.printerBedTempTarget;
                    queue.tempHotendActual = api.printerStats.printerTool0TempActual;
                    queue.tempHotendTarget = api.printerStats.printerTool0TempTarget;

                    if ((api.printJob.printerState != "Operational") || (api.printJob.progressPrintTime > 0))
                    {
                        queue.connectionState = ConnectionStatus::OCTOPRINT_PRINTTING;
                        snprintf(queue.status, sizeof(queue.status), "%s", api.printJob.printerState.c_str());
                        snprintf(queue.name, sizeof(queue.name), "%s", api.printJob.jobFileName.c_str());
                        queue.completion = api.printJob.progressCompletion;
                        queue.timeElapsed = api.printJob.progressPrintTime;
                        queue.timeLeft = api.printJob.progressPrintTimeLeft;
                        xQueueOverwrite(queueCommToDisplay, &queue);
                    }
                    else
                    {
                        snprintf(queue.status, sizeof(queue.status), "-");
                        snprintf(queue.name, sizeof(queue.name), "-");
                        queue.timeElapsed = 0;
                        queue.timeLeft = 0;
                        queue.completion = 0.0f;
                        xQueueOverwrite(queueCommToDisplay, &queue);
                    }
                }
                else
                {
                    queue.connectionState = ConnectionStatus::OCTOPRINT_PRINTER_DISCONNECTED;
                    xQueueOverwrite(queueCommToDisplay, &queue);
                    Serial.println("Printer off/disconnected");
                }
            }
            else
            {
                    queue.connectionState = ConnectionStatus::OCTOPRINT_DISCONNECTED;
                    xQueueOverwrite(queueCommToDisplay, &queue);
                Serial.println("OctoPrint disconnected");
            }
        }
        else 
        {
            queue.connectionState = ConnectionStatus::WIFI_CONNECTING;
            xQueueOverwrite(queueCommToDisplay, &queue);
        }
    }
 
}
