#pragma once

class OpmTime
{
public:

static void Init(const char* defaultTimezone);
static tm Get();



static const char* ntpServer;
static const long  gmtOffset_sec;
static const int   daylightOffset_sec;

};


