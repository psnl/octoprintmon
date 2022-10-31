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
/*
#include <Arduino.h>
#include "lm-log.h"
#include "lm-wifi.h"
#include "lm-time.h"
#include "lm-config.h"
#include <OctoPrintAPI.h> //This is where the magic happens... shazam!


LmLog lmLog;
LmWifi lmWifi;
tm currentTime;

WiFiClient client; 

// You only need to set one of the of follwowing:
IPAddress ip(192, 168, 178, 101);                         // Your IP address of your OctoPrint server (inernal or external)
// char* octoprint_host = "octoprint.example.com";  // Or your hostname. Comment out one or the other.

const int octoprint_httpPort = 80;  //If you are connecting through a router this will work, but you need a random port forwarded to the OctoPrint server from your router. Enter that port here if you are external
String octoprint_apikey = "88EEDFCFB8024F05B78E0131708C5C51"; //See top of file or GIT Readme about getting API key

OctoprintApi api(client, ip, octoprint_httpPort, octoprint_apikey);               //If using IP address

unsigned long api_mtbs = 5000; //mean time between api requests (60 seconds)
unsigned long api_lasttime = 0;   //last time api request has been done


void ConfigModeCallback()
{
    Serial.println("Set Wifi");
}


void setup() {

    ConfigHelper::Init();

    lmLog.Init();

    lmWifi.Init("OctoPrintMon");

    LmTime::Init();

    //setCpuFrequencyMhz(80);
    //WiFi.disconnect(true);  // Disconnect from the network
    //WiFi.mode(WIFI_OFF);   
    WiFi.setTxPower(WIFI_POWER_8_5dBm);
    //Serial.println(WiFi.getTxPower());

    pinMode(11, OUTPUT);
    digitalWrite(11, HIGH); 

}


void loop() {
    char text[10];

  if (millis() - api_lasttime > api_mtbs || api_lasttime==0) {  //Check if time has expired to go check OctoPrint
    currentTime = LmTime::Get();
    snprintf(text, 10, "%02d:%02d:%02d", currentTime.tm_hour, currentTime.tm_min, currentTime.tm_sec);
    Serial.println(text);
    if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status     
      if(api.getPrinterStatistics())
      {
        
        Serial.print("Printer current state:\t\t\t");
        Serial.println(api.printerStats.printerState);
        Serial.print("Printer current heater bed:\t\t");
        Serial.println(api.printerStats.printerBedTempActual);
        Serial.print("Printer set heater bed:\t\t\t");
        Serial.println(api.printerStats.printerBedTempTarget);
        Serial.print("Printer current extruder:\t\t");
        Serial.println(api.printerStats.printerTool0TempActual);
        Serial.print("Printer set extruder:\t\t\t");
        Serial.println(api.printerStats.printerTool0TempTarget);
      }
      
      if(api.getPrintJob()){  //Get the print job API endpoint
        Serial.println("--------------getPrintJob()-------------");
        Serial.print("Printer current state string:\t\t");
        Serial.println(api.printJob.printerState);
        // Serial.println();
        // Serial.println("----------Job (File information)--------");
        // Serial.print("jobFileDate (Epoch) long:\t\t");
        // Serial.println(api.printJob.jobFileDate);
        // Serial.print("jobFileName String:\t\t\t");
        // Serial.println(api.printJob.jobFileName);
        // Serial.print("jobFileOrigin String:\t\t\t");
        // Serial.println(api.printJob.jobFileOrigin);
        // Serial.print("jobFileSize (bytes) long:\t\t");
        // Serial.println(api.printJob.jobFileSize);
        // Serial.print("jobFilamentTool0Length (mm) long:\t");
        // Serial.println(api.printJob.jobFilamentTool0Length);
        // Serial.print("jobFilamentTool0Volume (cm³) float:\t");
        // Serial.println(api.printJob.jobFilamentTool0Volume);
        // Serial.print("jobFilamentTool1Length (mm) long:\t");
        // Serial.println(api.printJob.jobFilamentTool1Length);
        // Serial.print("jobFilamentTool1Volume (cm³) float:\t");
        // Serial.println(api.printJob.jobFilamentTool1Volume);
        // Serial.print("estimatedPrintTime (sec) long:\t\t");
        // Serial.println(api.printJob.estimatedPrintTime);
        // Serial.println("----------------------------------------");  
        // Serial.println();
        // Serial.println("-------Job (Progress information)-------");
        // Serial.print("progressCompletion (%) float:\t\t");
        // Serial.println(api.printJob.progressCompletion);
        // Serial.print("progressFilepos (bytes) long:\t\t");
        // Serial.println(api.printJob.progressFilepos);
        // Serial.print("progressPrintTime (sec) long:\t\t");
        // Serial.println(api.printJob.progressPrintTime);
        Serial.print("progressPrintTimeLeft (sec) long:\t");
        Serial.println(api.printJob.progressPrintTimeLeft);
        // Serial.println("----------------------------------------");
        // Serial.println();  


        // // Example use case of data being returned, outputting to serial monitor. 
        // // Could easily by an OLED screen, LEDs, Neopixel bar, servo motor etc.
        // Serial.println("---------------Example Use--------------");
        // Serial.print("File:\t\t\t");
        // Serial.println(api.printJob.jobFileName);

        // //Human readable MB size:
        // const float bytes_in_megabytes = 1048576;
        // const float temp_size_mb = api.printJob.jobFileSize/bytes_in_megabytes;
        // Serial.print("File size:\t\t");
        // Serial.print(temp_size_mb);
        // Serial.println("MB");

        // //Filament info in readable text:
        // const float mm_in_m = 1000;
        // if(api.printJob.jobFilamentTool0Length!=0){
        //   const float filament_length_meter0 = api.printJob.jobFilamentTool0Length/mm_in_m;
        //   Serial.print("Filament (Tool 0):\t");
        //   Serial.print(filament_length_meter0);
        //   Serial.print("m / ");
        //   Serial.print(api.printJob.jobFilamentTool0Volume);
        //   Serial.println("cm³");
        // }
        // if(api.printJob.jobFilamentTool1Length!=0){
        //   const float filament_length_meter1 = api.printJob.jobFilamentTool1Length/mm_in_m;
        //   Serial.print("Filament (Tool 1):\t");
        //   Serial.print(filament_length_meter1);
        //   Serial.print("m / ");
        //   Serial.print(api.printJob.jobFilamentTool1Volume);
        //   Serial.println("cm³");
        // }

        // //File upload time in human readable date and time YYYY-MM-DD HH:MM:SS
        // // char bufDate[31];
        // // sprintf(bufDate,"Uploaded:\t\t%04d-%02d-%02d %02d:%02d:%02d",
        // // year(api.printJob.jobFileDate),
        // // month(api.printJob.jobFileDate),
        // // day(api.printJob.jobFileDate),
        // // hour(api.printJob.jobFileDate),
        // // minute(api.printJob.jobFileDate),
        // // second(api.printJob.jobFileDate)
        // // );
        // // Serial.println(bufDate);

        // //Estimated print time if availble in human readable time HH:MM:SS
        // int estrunHours= api.printJob.estimatedPrintTime/3600;
        // int estsecsRemaining=api.printJob.estimatedPrintTime%3600;
        // int estrunMinutes=estsecsRemaining/60;
        // int estrunSeconds=estsecsRemaining%60;
        // char estbuf[31];
        // sprintf(estbuf,"Print time estimate:\t%02d:%02d:%02d",estrunHours,estrunMinutes,estrunSeconds);
        // Serial.println(estbuf);

        // //Percentage of current print job complete
        // const float temp_percent = floor(api.printJob.progressCompletion*100)/100;
        // Serial.print("Percentage complete:\t");
        // Serial.print(temp_percent);
        // Serial.println("%");

        // //Print time left (if printing) in human readable time HH:MM:SS
        // int runHours= api.printJob.progressPrintTimeLeft/3600;
        // int secsRemaining=api.printJob.progressPrintTimeLeft%3600;
        // int runMinutes=secsRemaining/60;
        // int runSeconds=secsRemaining%60;
        // char buf[31];
        // sprintf(buf,"Print time left:\t%02d:%02d:%02d",runHours,runMinutes,runSeconds);
        // Serial.println(buf);
        // Serial.println("----------------------------------------"); 
        // Serial.println();
      }
    }
    api_lasttime = millis();  //Set api_lasttime to current milliseconds run
  }
}

*/