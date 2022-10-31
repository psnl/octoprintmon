#pragma once

enum class ConnectionStatus
{
  WIFI_CONNECTING,
  WIFI_AP_ACTIVE,
  OCTOPRINT_DISCONNECTED,
  OCTOPRINT_PRINTER_DISCONNECTED,
  OCTOPRINT_PRINTER_CONNECTED,
  OCTOPRINT_PRINTTING
};

enum class Command
{
  NONE,
  SET_TOOL_TEMP,
  SET_BED_TEMP,
  PRINT_PLAY,
  PRINT_PAUSE,
  PRINT_STOP,
};


struct TQueueDisplayToComm
{
  Command command;
  uint16_t value;

  TQueueDisplayToComm()
  {
    command = Command::NONE;
    value = 0;
  };
};
struct TQueueCommToDisplay
{
  ConnectionStatus connectionState;
  bool apActive;
  float tempBedTarget;
  float tempBedActual;
  float tempHotendTarget;
  float tempHotendActual;
  char status[40];
  char name[40];
  float completion;
  long timeElapsed;
  long timeLeft;

  TQueueCommToDisplay()
  {
    connectionState = ConnectionStatus::WIFI_CONNECTING;
    tempBedActual = 0;
    tempHotendTarget = 0;
    tempHotendActual = 0;
    status[0] = '\0';
    name[0] = '\0';
    completion = 0;
    timeElapsed = 0;
    timeLeft = 0;  
  };
};