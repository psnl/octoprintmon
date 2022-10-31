#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncWiFiManager.h>    
#include <OctoPrintAPI.h>
#include <queue.h>
#include <opm-time.h>

class Communication
{

public:
    static const std::string name;

    static void Task( void * pvParameters );

    static void ConfigModeCallback(AsyncWiFiManager* wifiManager);

};