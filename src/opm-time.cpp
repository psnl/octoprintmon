
#include <Arduino.h>
#include "opm-time.h"


const char* OpmTime::ntpServer = "pool.ntp.org";
//const char * defaultTimezone = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";

void OpmTime::Init(const char* defaultTimezone)
{
    //configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    configTzTime( defaultTimezone, ntpServer); //sets TZ and starts NTP sync
}

tm OpmTime::Get()
{
     struct tm timeinfo;
     getLocalTime(&timeinfo);
     return timeinfo;
}