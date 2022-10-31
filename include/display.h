#pragma once

#include <Arduino.h>
// #include <LovyanGFX.hpp> // main library
// #include <lvgl.h>
// #include "lv_conf.h"
//#include "octoprint.h"
#include <queue.h>
#include "opm-time.h"

class Display
{

public:
    static void Task( void * pvParameters );
    static void Update(TQueueCommToDisplay& queue, bool force = false);

private:
    static void UpdateHeader(TQueueCommToDisplay& queue, bool force = false);
    static void UpdateTemperature(TQueueCommToDisplay& queue);
    static void UpdateTemperatureTool(TQueueCommToDisplay& queue);
    static void UpdateTemperatureBed(TQueueCommToDisplay& queue);
    static void UpdateWifiLogo(TQueueCommToDisplay& queue);
    static void UpdateJob(TQueueCommToDisplay& queue);
    static void UpdateFooter(TQueueCommToDisplay& queue);

};