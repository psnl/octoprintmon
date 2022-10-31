#pragma once

#include <ArduinoJson.h>
#include <SPIFFS.h>
#include <string>

class Config {

    public:
        Config()
        {
            octoPrintApi[0] = '\0';
            octoPrintIp[0] = '\0';
            octoPrintPort= 0;
            timeZone[0] = '\0';
        }

        char octoPrintApi[100];
        char octoPrintIp[100];
        int octoPrintPort;
        char timeZone[100];
};

class ConfigHelper
{
    public:

    static char const *filename;

    static char const * CFG_OPM_OCTOPRINT_API;
    static char const * CFG_OPM_OCTOPRINT_IP;
    static char const * CFG_OPM_OCTOPRINT_PORT;
    static char const * CFG_OPM_TIMEZONE;    
    static char const * CFG_OPM_VERSION;    

    static void Init();
    static void Read(Config& config);
    static void Write(Config& config);

    private:

    static void ReadJsonDoc(fs::FS &fs, const char * path, StaticJsonDocument<512>& doc);
    static void WriteJsonDoc(fs::FS &fs, const char * path, StaticJsonDocument<512>& doc);
};