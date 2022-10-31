// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: Octoprint

#ifndef _OCTOPRINT_UI_H
#define _OCTOPRINT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

extern lv_obj_t * ui_Home;
extern lv_obj_t * ui_Header;
extern lv_obj_t * ui_Header_Date;
extern lv_obj_t * ui_Header_Time;
extern lv_obj_t * ui_Logo;
extern lv_obj_t * ui_Knob_Tool;
extern lv_obj_t * ui_ArcToolActual;
extern lv_obj_t * ui_Knob_Tool_BG;
extern lv_obj_t * ui_Number_Tool_BG;
extern lv_obj_t * ui_NumberToolActual;
extern lv_obj_t * ui_NumberToolSet;
extern lv_obj_t * ui_ArcToolSet;
extern lv_obj_t * ui_Knob_Bed;
extern lv_obj_t * ui_ArcBedActual;
extern lv_obj_t * ui_Knob_Bed_BG;
extern lv_obj_t * ui_Number_Bed_BG;
extern lv_obj_t * ui_NumberBedActual;
extern lv_obj_t * ui_NumberBedSet;
extern lv_obj_t * ui_ArcBedSet;
extern lv_obj_t * ui_LabelTool;
extern lv_obj_t * ui_LabelBed;
extern lv_obj_t * ui_Status;
extern lv_obj_t * ui_StatusStatus;
extern lv_obj_t * ui_StatusRemain;
extern lv_obj_t * ui_StatusName;
extern lv_obj_t * ui_LabelRemain;
extern lv_obj_t * ui_LabelName;
extern lv_obj_t * ui_LabelStatus;
extern lv_obj_t * ui_Popup_Setting;
extern lv_obj_t * ui_Temperature_Settings_Header;
extern lv_obj_t * ui_Label_Temperature_Setting;
extern lv_obj_t * ui_Roller1;
extern lv_obj_t * ui_Roller2;
extern lv_obj_t * ui_Roller3;
extern lv_obj_t * ui_ButtonOk;
extern lv_obj_t * ui_SettingsOk1;
extern lv_obj_t * ui_ButtonCancel;
extern lv_obj_t * ui_SettingsCancel;
extern lv_obj_t * ui_Popup_Control;
extern lv_obj_t * ui_Control_Settings_Header;
extern lv_obj_t * ui_Label_Control_Setting;
extern lv_obj_t * ui_ImgButtonPlay;
extern lv_obj_t * ui_ImgButtonPause;
extern lv_obj_t * ui_ImgButtonStop;
extern lv_obj_t * ui_Popup_WiFi;
extern lv_obj_t * ui_ImageWiFi;
extern lv_obj_t * ui_Footer;
extern lv_obj_t * ui_Footer_Status;
extern lv_obj_t * ui_Footer_Completion;

void eventToolPressed(lv_event_t * e);
void eventBedPressed(lv_event_t * e);
void ControlPressed(lv_event_t * e);
void SettingsOk(lv_event_t * e);
void SettingCancel(lv_event_t * e);
void PrintPlay(lv_event_t * e);
void PrintPause(lv_event_t * e);
void PrintStop(lv_event_t * e);

LV_IMG_DECLARE(ui_img_octoprint_png);    // assets\octoprint.png
LV_IMG_DECLARE(ui_img_play_png);    // assets\Play.png
LV_IMG_DECLARE(ui_img_pause_png);    // assets\Pause.png
LV_IMG_DECLARE(ui_img_stop_png);    // assets\Stop.png
LV_IMG_DECLARE(ui_img_qr_png);    // assets\qr.png




void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
