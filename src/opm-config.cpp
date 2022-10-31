#include "opm-config.h"

const char *ConfigHelper::filename = "/config.txt";  // <- SD library uses 8.3 filenames
const char *ConfigHelper::ConfigHelper::CFG_OPM_OCTOPRINT_IP = "opm_octoprint_ip";
const char *ConfigHelper::ConfigHelper::CFG_OPM_OCTOPRINT_PORT = "opm_octoprint_port";
const char *ConfigHelper::ConfigHelper::CFG_OPM_OCTOPRINT_API = "opm_octoprint_api";
const char *ConfigHelper::ConfigHelper::CFG_OPM_TIMEZONE = "opm_timezone";
const char *ConfigHelper::ConfigHelper::CFG_OPM_VERSION = "opm_version";

StaticJsonDocument<512> jsonDoc;

void ConfigHelper::Init()
{
    if (!SPIFFS.begin(true))
    {
        Serial.println("Failed to mount SPIFFS");
    }
}

void ConfigHelper::Read(Config& config)
{
    ReadJsonDoc(SPIFFS, filename, jsonDoc);

    // Copy values from the JsonDocument to the Config
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

}

void ConfigHelper::Write(Config& config)
{
    // Delete existing file, otherwise the configuration is appended to the file
    SPIFFS.remove(filename);

    jsonDoc[CFG_OPM_OCTOPRINT_IP] = (const char *)config.octoPrintIp;
    jsonDoc[CFG_OPM_OCTOPRINT_PORT] = (int)config.octoPrintPort;
    jsonDoc[CFG_OPM_OCTOPRINT_API] = (const char *)config.octoPrintApi;
    jsonDoc[CFG_OPM_TIMEZONE] = (const char *)config.timeZone;

    WriteJsonDoc(SPIFFS, filename, jsonDoc);
}


void ConfigHelper::ReadJsonDoc(fs::FS &fs, const char * path, StaticJsonDocument<512>& doc)
{
    Serial.printf("Reading file: %s\r\n", path);

    File file = fs.open(path);
    if(!file || file.isDirectory()){
        Serial.println("- failed to open file for reading");
        return;
    }

    //Serial.println("Read from file:");
    
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(doc, file);
    if (error)
    {
        Serial.println("Failed to read file, using default configuration");
    }
    file.close();
}

void ConfigHelper::WriteJsonDoc(fs::FS &fs, const char * path, StaticJsonDocument<512>& doc){
    //Serial.printf("Writing file: %s\r\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("- failed to open file for writing");
        return;
    }


    if(serializeJson(doc, file)){
        Serial.println("- file written");
    } else {
        Serial.println("- write failed");
    }
    file.close();
}
 