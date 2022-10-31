#include <display.h>
#include <WiFi.h>

#define LGFX_AUTODETECT // Autodetect board
#define LGFX_USE_V1     // set to use new version of library
//#define LV_CONF_INCLUDE_SIMPLE

/* Uncomment below line to draw on screen with touch */
//#define DRAW_ON_SCREEN

#include <LovyanGFX.hpp> // main library
static LGFX lcd; // declare display variable

#include <lvgl.h>
#include "lv_conf.h"
#include "ui\ui.h"
//#include "octoprint.h"

static const uint16_t screenWidth = 320;
static const uint16_t screenHeight = 480;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

extern QueueHandle_t queueCommToDisplay;
extern QueueHandle_t queueDisplayToComm;
unsigned long timeUpdate = 0;
unsigned long popupTimeout = 0;

TQueueDisplayToComm queueDC;

// Variables for touch x,y
#ifdef DRAW_ON_SCREEN
static int32_t x, y;
#endif

  void display_flush(lv_disp_drv_t * disp, const lv_area_t *area, lv_color_t *color_p)
  {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    lcd.startWrite();
    lcd.setAddrWindow(area->x1, area->y1, w, h);
    lcd.pushColors((uint16_t *)&color_p->full, w * h, true);
    lcd.endWrite();

    lv_disp_flush_ready(disp);
  }

  /*** Touchpad callback to read the touchpad ***/
  void touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
  {
    uint16_t touchX, touchY;
    bool touched = lcd.getTouch(&touchX, &touchY);

    if (!touched)
    {
      data->state = LV_INDEV_STATE_REL;
    }
    else
    {
      data->state = LV_INDEV_STATE_PR;

      /*Set the coordinates*/
      data->point.x = touchX;
      data->point.y = touchY;

      // Serial.printf("Touch (x,y): (%03d,%03d)\n",touchX,touchY );
    }
  }

void Display::Update(TQueueCommToDisplay& queue, bool force)
{
  if (popupTimeout != 0)
  {
    if (millis() > (popupTimeout + 5000))
    {
      lv_obj_add_flag(ui_Popup_Control, LV_OBJ_FLAG_HIDDEN);
      popupTimeout = 0;
    }
  }


  UpdateHeader(queue, force);
  UpdateWifiLogo(queue);
  UpdateTemperature(queue);
  UpdateJob(queue);
  UpdateFooter(queue);
}

void Display::Task( void * pvParameters )
{
    String taskMessage = "Task running on core ";
    TQueueCommToDisplay queueCD;
    
    lcd.init(); // Initialize LovyanGFX
    lv_init();  // Initialize lvgl

    // Setting display to landscape
    //if (lcd.width() < lcd.height())
    //  lcd.setRotation(lcd.getRotation());
    //lcd.setRotation(lcd.getRotation() ^ 1);

    /* LVGL : Setting up buffer to use for display */
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);

    /*** LVGL : Setup & Initialize the display device driver ***/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = display_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /*** LVGL : Setup & Initialize the input device driver ***/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    lv_indev_drv_register(&indev_drv);

    ui_init();

    queueCD.connectionState = ConnectionStatus::WIFI_CONNECTING;
    Update(queueCD, true);

    while (true)
    {
        lv_timer_handler(); /* let the GUI do its work */
        delay(5);
        if (xQueueReceive(queueCommToDisplay, &queueCD, 0) == pdTRUE)
        {
          Update(queueCD);
        }
        UpdateHeader(queueCD);
    }
}

  /* Counter button event handler */
void Display::UpdateHeader(TQueueCommToDisplay& queue, bool force)
{
  if ((millis() > (timeUpdate + 2000)) || force)
  {
    timeUpdate = millis();
    auto currentTime = OpmTime::Get();
    switch (queue.connectionState)
    {
      case ConnectionStatus::WIFI_CONNECTING:
      case ConnectionStatus::WIFI_AP_ACTIVE:
        lv_label_set_text(ui_Header_Date, "OctoPrintMon");
        lv_label_set_text(ui_Header_Time, "");
        break;
      case ConnectionStatus::OCTOPRINT_PRINTER_CONNECTED:
      case ConnectionStatus::OCTOPRINT_PRINTTING:
      case ConnectionStatus::OCTOPRINT_DISCONNECTED:
      case ConnectionStatus::OCTOPRINT_PRINTER_DISCONNECTED:
        lv_label_set_text_fmt(ui_Header_Date, "%02d-%02d-%4d", currentTime.tm_mday, currentTime.tm_mon+1, currentTime.tm_year+1900);
        lv_label_set_text_fmt(ui_Header_Time, "%02d:%02d", currentTime.tm_hour, currentTime.tm_min);
        break;
    }
  }
}

void Display::UpdateTemperature(TQueueCommToDisplay& queue)
{
  switch (queue.connectionState)
  {
    case ConnectionStatus::WIFI_CONNECTING:
    case ConnectionStatus::WIFI_AP_ACTIVE:
    case ConnectionStatus::OCTOPRINT_DISCONNECTED:
    case ConnectionStatus::OCTOPRINT_PRINTER_DISCONNECTED:
      lv_obj_add_flag(ui_Knob_Bed, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_LabelBed, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_Knob_Tool, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_LabelTool, LV_OBJ_FLAG_HIDDEN);
      break;
    case ConnectionStatus::OCTOPRINT_PRINTER_CONNECTED:
    case ConnectionStatus::OCTOPRINT_PRINTTING:
      UpdateTemperatureBed(queue);
      UpdateTemperatureTool(queue);
      lv_obj_clear_flag(ui_Knob_Bed, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_LabelBed, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_Knob_Tool, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_LabelTool, LV_OBJ_FLAG_HIDDEN);
      break;
  }
}

void Display::UpdateTemperatureTool(TQueueCommToDisplay& queue)
{
  int tempHotendActual = (int)queue.tempHotendActual;
  int tempHotendTarget = (int)queue.tempHotendTarget;

  if (tempHotendActual < (tempHotendTarget-2))
  {
    lv_obj_set_style_arc_color(ui_ArcToolActual, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);
  }
  else if (tempHotendActual > (tempHotendTarget+2))
  {
    lv_obj_set_style_arc_color(ui_ArcToolActual, lv_palette_main(LV_PALETTE_BLUE), LV_PART_INDICATOR);
  }
  else
  {
    lv_obj_set_style_arc_color(ui_ArcToolActual, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);
  }

  switch (queue.connectionState)
  {
    case ConnectionStatus::WIFI_CONNECTING:
    case ConnectionStatus::WIFI_AP_ACTIVE:
    case ConnectionStatus::OCTOPRINT_DISCONNECTED:
    case ConnectionStatus::OCTOPRINT_PRINTER_DISCONNECTED:
      lv_arc_set_value(ui_ArcToolActual, 0);
      lv_arc_set_value(ui_ArcToolSet, 0);
      lv_label_set_text_fmt(ui_NumberToolActual, "--°");
      lv_label_set_text_fmt(ui_NumberToolSet, "T--");
      break;
    case ConnectionStatus::OCTOPRINT_PRINTER_CONNECTED:
    case ConnectionStatus::OCTOPRINT_PRINTTING:
      lv_arc_set_value(ui_ArcToolActual, tempHotendActual);
      lv_label_set_text_fmt(ui_NumberToolActual, "%d°", tempHotendActual);
      lv_arc_set_value(ui_ArcToolSet, tempHotendTarget);
      lv_label_set_text_fmt(ui_NumberToolSet, "T%d", tempHotendTarget);    
      break;
  }
}

void Display::UpdateTemperatureBed(TQueueCommToDisplay& queue)
{
  int tempBedActual = (int)queue.tempBedActual;
  int tempBedTarget = (int)queue.tempBedTarget;

  if (tempBedActual < (tempBedTarget-2))
  {
    lv_obj_set_style_arc_color(ui_ArcBedActual, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);
  }
  else if (tempBedActual > (tempBedTarget+2))
  {
    lv_obj_set_style_arc_color(ui_ArcBedActual, lv_palette_main(LV_PALETTE_BLUE), LV_PART_INDICATOR);
  }
  else
  {
    lv_obj_set_style_arc_color(ui_ArcBedActual, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);
  }

  switch (queue.connectionState)
  {
    case ConnectionStatus::WIFI_CONNECTING:
    case ConnectionStatus::WIFI_AP_ACTIVE:
    case ConnectionStatus::OCTOPRINT_DISCONNECTED:
    case ConnectionStatus::OCTOPRINT_PRINTER_DISCONNECTED:
      lv_arc_set_value(ui_ArcBedActual, 0);
      lv_arc_set_value(ui_ArcBedSet, 0);
      lv_label_set_text_fmt(ui_NumberBedActual, "--°");
      lv_label_set_text_fmt(ui_NumberBedSet, "T--");
      break;
    case ConnectionStatus::OCTOPRINT_PRINTER_CONNECTED:
    case ConnectionStatus::OCTOPRINT_PRINTTING:
      lv_arc_set_value(ui_ArcBedActual, tempBedActual);
      lv_label_set_text_fmt(ui_NumberBedActual, "%d°", tempBedActual);
      lv_arc_set_value(ui_ArcBedSet, tempBedTarget);
      lv_label_set_text_fmt(ui_NumberBedSet, "T%d", tempBedTarget); 
      break;
  }
}

void Display::UpdateJob(TQueueCommToDisplay& queue)
{
  switch (queue.connectionState)
  {
    case ConnectionStatus::WIFI_CONNECTING:
    case ConnectionStatus::WIFI_AP_ACTIVE:
    case ConnectionStatus::OCTOPRINT_DISCONNECTED:
    case ConnectionStatus::OCTOPRINT_PRINTER_DISCONNECTED:
    case ConnectionStatus::OCTOPRINT_PRINTER_CONNECTED:
      lv_obj_add_flag(ui_Footer_Completion, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_Status, LV_OBJ_FLAG_HIDDEN);
      break;
    case ConnectionStatus::OCTOPRINT_PRINTTING:
      lv_label_set_text_fmt(ui_LabelStatus, ": %s", queue.status);
      int hours = queue.timeLeft / 3600;
      int secondsLeft = queue.timeLeft % 3600;
      int min = secondsLeft / 60;
      int sec = secondsLeft % 60;
      lv_label_set_text_fmt(ui_LabelRemain, ": %dh %dm %ds", hours, min, sec);
      lv_label_set_text_fmt(ui_LabelName, ": %s", queue.name);
      lv_obj_clear_flag(ui_Footer_Completion, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_Status, LV_OBJ_FLAG_HIDDEN);
      break;
  }

}

void Display::UpdateWifiLogo(TQueueCommToDisplay& queue)
{
    switch (queue.connectionState)
    {
      case ConnectionStatus::WIFI_AP_ACTIVE:
        lv_obj_clear_flag(ui_Popup_WiFi, LV_OBJ_FLAG_HIDDEN);
        break;
      default:
        lv_obj_add_flag(ui_Popup_WiFi, LV_OBJ_FLAG_HIDDEN);
        break;
    }  
}

void Display::UpdateFooter(TQueueCommToDisplay& queue)
{
  switch (queue.connectionState)
  {
    case ConnectionStatus::WIFI_CONNECTING:
      lv_obj_add_flag(ui_Footer_Completion, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(ui_Footer_Status, "WiFi ...");
      lv_obj_clear_flag(ui_Footer_Status, LV_OBJ_FLAG_HIDDEN);
      break;
    case ConnectionStatus::WIFI_AP_ACTIVE:
      lv_obj_add_flag(ui_Footer_Completion, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(ui_Footer_Status, "Set WiFi credentials");
      lv_obj_clear_flag(ui_Footer_Status, LV_OBJ_FLAG_HIDDEN);
      break;
    case ConnectionStatus::OCTOPRINT_PRINTER_CONNECTED:
      lv_obj_add_flag(ui_Footer_Completion, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(ui_Footer_Status, "Ready");
      lv_obj_clear_flag(ui_Footer_Status, LV_OBJ_FLAG_HIDDEN);
      break;
    case ConnectionStatus::OCTOPRINT_PRINTTING:
      lv_obj_add_flag(ui_Footer_Status, LV_OBJ_FLAG_HIDDEN);
      lv_bar_set_value(ui_Footer_Completion, (int)ceil(queue.completion), LV_ANIM_ON);
      lv_obj_clear_flag(ui_Footer_Completion, LV_OBJ_FLAG_HIDDEN);
      break;
    case ConnectionStatus::OCTOPRINT_DISCONNECTED:
      lv_obj_add_flag(ui_Footer_Completion, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text_fmt(ui_Footer_Status, "OctoPrint ... (http://%s)", WiFi.localIP().toString().c_str());
      lv_obj_clear_flag(ui_Footer_Status, LV_OBJ_FLAG_HIDDEN);
      break;
    case ConnectionStatus::OCTOPRINT_PRINTER_DISCONNECTED:
      lv_obj_add_flag(ui_Footer_Completion, LV_OBJ_FLAG_HIDDEN);
      lv_label_set_text(ui_Footer_Status, "Printer disconnected");
      lv_obj_clear_flag(ui_Footer_Status, LV_OBJ_FLAG_HIDDEN);
      break;

  }
}

void eventToolPressed(lv_event_t * e)
{
  lv_label_set_text(ui_Label_Temperature_Setting, "Tool");
  lv_roller_set_selected(ui_Roller1, 2, LV_ANIM_ON);
  lv_roller_set_selected(ui_Roller2, 2, LV_ANIM_ON);
  lv_roller_set_selected(ui_Roller3, 5, LV_ANIM_ON);
	lv_obj_clear_flag(ui_Popup_Setting, LV_OBJ_FLAG_HIDDEN);
  queueDC.command = Command::SET_TOOL_TEMP;
}

void eventBedPressed(lv_event_t * e)
{
  lv_label_set_text(ui_Label_Temperature_Setting, "Bed");
  lv_roller_set_selected(ui_Roller1, 0, LV_ANIM_ON);
  lv_roller_set_selected(ui_Roller2, 6, LV_ANIM_ON);
  lv_roller_set_selected(ui_Roller3, 0, LV_ANIM_ON);
	lv_obj_clear_flag(ui_Popup_Setting, LV_OBJ_FLAG_HIDDEN);
  queueDC.command = Command::SET_BED_TEMP;
}


void SettingsOk(lv_event_t * e)
{

	uint16_t temp = lv_roller_get_selected(ui_Roller1) * 100 + lv_roller_get_selected(ui_Roller2) * 10 + lv_roller_get_selected(ui_Roller3);
  Serial.println(temp);
  lv_obj_add_flag(ui_Popup_Setting, LV_OBJ_FLAG_HIDDEN);
  queueDC.value = temp;
  xQueueOverwrite(queueDisplayToComm, &queueDC);
}

void SettingCancel(lv_event_t * e)
{
	lv_obj_add_flag(ui_Popup_Setting, LV_OBJ_FLAG_HIDDEN);
}

void PrintPlay(lv_event_t * e)
{
  lv_obj_add_flag(ui_Popup_Control, LV_OBJ_FLAG_HIDDEN);
  queueDC.command = Command::PRINT_PLAY;
  xQueueOverwrite(queueDisplayToComm, &queueDC);
}

void PrintPause(lv_event_t * e)
{
  lv_obj_add_flag(ui_Popup_Control, LV_OBJ_FLAG_HIDDEN);
  queueDC.command = Command::PRINT_PAUSE;
  xQueueOverwrite(queueDisplayToComm, &queueDC);
}

void PrintStop(lv_event_t * e)
{
  lv_obj_add_flag(ui_Popup_Control, LV_OBJ_FLAG_HIDDEN);
  queueDC.command = Command::PRINT_STOP;
  xQueueOverwrite(queueDisplayToComm, &queueDC);
}

void ControlPressed(lv_event_t * e)
{
    popupTimeout = millis();
		lv_obj_clear_flag(ui_Popup_Control, LV_OBJ_FLAG_HIDDEN);
}
