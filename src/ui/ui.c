// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: Octoprint

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Home;
lv_obj_t * ui_Header;
lv_obj_t * ui_Header_Date;
lv_obj_t * ui_Header_Time;
lv_obj_t * ui_Logo;
lv_obj_t * ui_Knob_Tool;
lv_obj_t * ui_ArcToolActual;
lv_obj_t * ui_Knob_Tool_BG;
lv_obj_t * ui_Number_Tool_BG;
lv_obj_t * ui_NumberToolActual;
lv_obj_t * ui_NumberToolSet;
lv_obj_t * ui_ArcToolSet;
lv_obj_t * ui_Knob_Bed;
lv_obj_t * ui_ArcBedActual;
lv_obj_t * ui_Knob_Bed_BG;
lv_obj_t * ui_Number_Bed_BG;
lv_obj_t * ui_NumberBedActual;
lv_obj_t * ui_NumberBedSet;
lv_obj_t * ui_ArcBedSet;
lv_obj_t * ui_LabelTool;
lv_obj_t * ui_LabelBed;
lv_obj_t * ui_Status;
lv_obj_t * ui_StatusStatus;
lv_obj_t * ui_StatusRemain;
lv_obj_t * ui_StatusName;
lv_obj_t * ui_LabelRemain;
lv_obj_t * ui_LabelName;
lv_obj_t * ui_LabelStatus;
lv_obj_t * ui_Popup_Setting;
lv_obj_t * ui_Temperature_Settings_Header;
lv_obj_t * ui_Label_Temperature_Setting;
lv_obj_t * ui_Roller1;
lv_obj_t * ui_Roller2;
lv_obj_t * ui_Roller3;
lv_obj_t * ui_ButtonOk;
lv_obj_t * ui_SettingsOk1;
lv_obj_t * ui_ButtonCancel;
lv_obj_t * ui_SettingsCancel;
lv_obj_t * ui_Popup_Control;
lv_obj_t * ui_Control_Settings_Header;
lv_obj_t * ui_Label_Control_Setting;
lv_obj_t * ui_ImgButtonPlay;
lv_obj_t * ui_ImgButtonPause;
lv_obj_t * ui_ImgButtonStop;
lv_obj_t * ui_Popup_WiFi;
lv_obj_t * ui_ImageWiFi;
lv_obj_t * ui_Footer;
lv_obj_t * ui_Footer_Status;
lv_obj_t * ui_Footer_Completion;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void ui_event_Knob_Tool(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        eventToolPressed(e);
    }
}
static void ui_event_Knob_Bed(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        eventBedPressed(e);
    }
}
static void ui_event_Status(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        ControlPressed(e);
    }
}
static void ui_event_ButtonOk(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        SettingsOk(e);
    }
}
static void ui_event_SettingsOk1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_ButtonCancel(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        SettingCancel(e);
    }
}
static void ui_event_ImgButtonPlay(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        PrintPlay(e);
    }
}
static void ui_event_ImgButtonPause(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        PrintPause(e);
    }
}
static void ui_event_ImgButtonStop(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        PrintStop(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Home_screen_init(void)
{

    // ui_Home

    ui_Home = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_Home, lv_color_hex(0x23232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Header

    ui_Header = lv_obj_create(ui_Home);

    lv_obj_set_height(ui_Header, 32);
    lv_obj_set_width(ui_Header, lv_pct(100));

    lv_obj_set_x(ui_Header, 0);
    lv_obj_set_y(ui_Header, 0);

    lv_obj_set_align(ui_Header, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Header, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Header, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Header_Date

    ui_Header_Date = lv_label_create(ui_Header);

    lv_obj_set_width(ui_Header_Date, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Header_Date, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Header_Date, 10);
    lv_obj_set_y(ui_Header_Date, 0);

    lv_obj_set_align(ui_Header_Date, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Header_Date, "12-05-2022");

    lv_obj_set_style_text_color(ui_Header_Date, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Header_Date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Header_Time

    ui_Header_Time = lv_label_create(ui_Header);

    lv_obj_set_width(ui_Header_Time, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Header_Time, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Header_Time, -10);
    lv_obj_set_y(ui_Header_Time, 0);

    lv_obj_set_align(ui_Header_Time, LV_ALIGN_RIGHT_MID);

    lv_label_set_text(ui_Header_Time, "22:13");

    lv_obj_set_style_text_color(ui_Header_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Header_Time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Logo

    ui_Logo = lv_img_create(ui_Home);
    lv_img_set_src(ui_Logo, &ui_img_octoprint_png);

    lv_obj_set_width(ui_Logo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Logo, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Logo, 0);
    lv_obj_set_y(ui_Logo, -140);

    lv_obj_set_align(ui_Logo, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Logo, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_Knob_Tool

    ui_Knob_Tool = lv_obj_create(ui_Home);

    lv_obj_set_width(ui_Knob_Tool, 140);
    lv_obj_set_height(ui_Knob_Tool, 140);

    lv_obj_set_x(ui_Knob_Tool, -75);
    lv_obj_set_y(ui_Knob_Tool, -10);

    lv_obj_set_align(ui_Knob_Tool, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Knob_Tool, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_add_event_cb(ui_Knob_Tool, ui_event_Knob_Tool, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_Knob_Tool, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Knob_Tool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Knob_Tool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ArcToolActual

    ui_ArcToolActual = lv_arc_create(ui_Knob_Tool);

    lv_obj_set_width(ui_ArcToolActual, 140);
    lv_obj_set_height(ui_ArcToolActual, 140);

    lv_obj_set_x(ui_ArcToolActual, 0);
    lv_obj_set_y(ui_ArcToolActual, 0);

    lv_obj_set_align(ui_ArcToolActual, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_ArcToolActual, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_arc_set_range(ui_ArcToolActual, 0, 260);
    lv_arc_set_bg_angles(ui_ArcToolActual, 120, 60);

    lv_obj_set_style_radius(ui_ArcToolActual, 140, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ArcToolActual, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcToolActual, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcToolActual, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcToolActual, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcToolActual, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcToolActual, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_ArcToolActual, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcToolActual, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcToolActual, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcToolActual, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcToolActual, lv_color_hex(0x36B9F6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcToolActual, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcToolActual, 7, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcToolActual, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcToolActual, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcToolActual, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Knob_Tool_BG

    ui_Knob_Tool_BG = lv_obj_create(ui_Knob_Tool);

    lv_obj_set_width(ui_Knob_Tool_BG, 105);
    lv_obj_set_height(ui_Knob_Tool_BG, 105);

    lv_obj_set_x(ui_Knob_Tool_BG, 0);
    lv_obj_set_y(ui_Knob_Tool_BG, 0);

    lv_obj_set_align(ui_Knob_Tool_BG, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Knob_Tool_BG, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_Knob_Tool_BG, 140, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Knob_Tool_BG, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Knob_Tool_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Knob_Tool_BG, lv_color_hex(0x3C414B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Knob_Tool_BG, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Knob_Tool_BG, lv_color_hex(0x2D323C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Knob_Tool_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Knob_Tool_BG, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Knob_Tool_BG, lv_color_hex(0x050A0F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Knob_Tool_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Knob_Tool_BG, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Knob_Tool_BG, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Knob_Tool_BG, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Knob_Tool_BG, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Number_Tool_BG

    ui_Number_Tool_BG = lv_obj_create(ui_Knob_Tool_BG);

    lv_obj_set_width(ui_Number_Tool_BG, 80);
    lv_obj_set_height(ui_Number_Tool_BG, 80);

    lv_obj_set_x(ui_Number_Tool_BG, 0);
    lv_obj_set_y(ui_Number_Tool_BG, 0);

    lv_obj_set_align(ui_Number_Tool_BG, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Number_Tool_BG,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_Number_Tool_BG, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Number_Tool_BG, lv_color_hex(0x0C191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Number_Tool_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Number_Tool_BG, lv_color_hex(0x191C26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Number_Tool_BG, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Number_Tool_BG, lv_color_hex(0x5A646E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Number_Tool_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_NumberToolActual

    ui_NumberToolActual = lv_label_create(ui_Number_Tool_BG);

    lv_obj_set_width(ui_NumberToolActual, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NumberToolActual, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_NumberToolActual, 0);
    lv_obj_set_y(ui_NumberToolActual, -10);

    lv_obj_set_align(ui_NumberToolActual, LV_ALIGN_CENTER);

    lv_label_set_text(ui_NumberToolActual, "260°");

    lv_obj_clear_flag(ui_NumberToolActual,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_NumberToolActual, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NumberToolActual, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NumberToolActual, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_NumberToolSet

    ui_NumberToolSet = lv_label_create(ui_Number_Tool_BG);

    lv_obj_set_width(ui_NumberToolSet, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NumberToolSet, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_NumberToolSet, 0);
    lv_obj_set_y(ui_NumberToolSet, 20);

    lv_obj_set_align(ui_NumberToolSet, LV_ALIGN_CENTER);

    lv_label_set_text(ui_NumberToolSet, "T260");

    lv_obj_clear_flag(ui_NumberToolSet, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_NumberToolSet, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NumberToolSet, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NumberToolSet, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ArcToolSet

    ui_ArcToolSet = lv_arc_create(ui_Knob_Tool);

    lv_obj_set_width(ui_ArcToolSet, 135);
    lv_obj_set_height(ui_ArcToolSet, 135);

    lv_obj_set_x(ui_ArcToolSet, 0);
    lv_obj_set_y(ui_ArcToolSet, 0);

    lv_obj_set_align(ui_ArcToolSet, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_ArcToolSet, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_arc_set_range(ui_ArcToolSet, 0, 260);
    lv_arc_set_bg_angles(ui_ArcToolSet, 120, 60);

    lv_obj_set_style_radius(ui_ArcToolSet, 135, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ArcToolSet, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcToolSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcToolSet, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcToolSet, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcToolSet, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcToolSet, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_ArcToolSet, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcToolSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcToolSet, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcToolSet, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcToolSet, lv_color_hex(0x989B9B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcToolSet, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcToolSet, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ArcToolSet, 20, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ArcToolSet, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcToolSet, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ArcToolSet, lv_color_hex(0x282828), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_ArcToolSet, LV_GRAD_DIR_VER, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Knob_Bed

    ui_Knob_Bed = lv_obj_create(ui_Home);

    lv_obj_set_width(ui_Knob_Bed, 140);
    lv_obj_set_height(ui_Knob_Bed, 140);

    lv_obj_set_x(ui_Knob_Bed, 75);
    lv_obj_set_y(ui_Knob_Bed, -10);

    lv_obj_set_align(ui_Knob_Bed, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Knob_Bed, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_add_event_cb(ui_Knob_Bed, ui_event_Knob_Bed, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_Knob_Bed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Knob_Bed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Knob_Bed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ArcBedActual

    ui_ArcBedActual = lv_arc_create(ui_Knob_Bed);

    lv_obj_set_width(ui_ArcBedActual, 140);
    lv_obj_set_height(ui_ArcBedActual, 140);

    lv_obj_set_x(ui_ArcBedActual, 0);
    lv_obj_set_y(ui_ArcBedActual, 0);

    lv_obj_set_align(ui_ArcBedActual, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_ArcBedActual, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_arc_set_range(ui_ArcBedActual, 0, 100);
    lv_arc_set_bg_angles(ui_ArcBedActual, 120, 60);

    lv_obj_set_style_radius(ui_ArcBedActual, 140, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ArcBedActual, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcBedActual, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcBedActual, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcBedActual, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcBedActual, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcBedActual, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_ArcBedActual, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcBedActual, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcBedActual, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcBedActual, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcBedActual, lv_color_hex(0x36B9F6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcBedActual, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcBedActual, 7, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcBedActual, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcBedActual, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcBedActual, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Knob_Bed_BG

    ui_Knob_Bed_BG = lv_obj_create(ui_Knob_Bed);

    lv_obj_set_width(ui_Knob_Bed_BG, 105);
    lv_obj_set_height(ui_Knob_Bed_BG, 105);

    lv_obj_set_x(ui_Knob_Bed_BG, 0);
    lv_obj_set_y(ui_Knob_Bed_BG, 0);

    lv_obj_set_align(ui_Knob_Bed_BG, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Knob_Bed_BG, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_Knob_Bed_BG, 140, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Knob_Bed_BG, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Knob_Bed_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Knob_Bed_BG, lv_color_hex(0x3C414B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Knob_Bed_BG, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Knob_Bed_BG, lv_color_hex(0x2D323C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Knob_Bed_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Knob_Bed_BG, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Knob_Bed_BG, lv_color_hex(0x050A0F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Knob_Bed_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Knob_Bed_BG, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Knob_Bed_BG, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Knob_Bed_BG, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Knob_Bed_BG, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Number_Bed_BG

    ui_Number_Bed_BG = lv_obj_create(ui_Knob_Bed_BG);

    lv_obj_set_width(ui_Number_Bed_BG, 80);
    lv_obj_set_height(ui_Number_Bed_BG, 80);

    lv_obj_set_x(ui_Number_Bed_BG, 0);
    lv_obj_set_y(ui_Number_Bed_BG, 0);

    lv_obj_set_align(ui_Number_Bed_BG, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Number_Bed_BG, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_Number_Bed_BG, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Number_Bed_BG, lv_color_hex(0x0C191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Number_Bed_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Number_Bed_BG, lv_color_hex(0x191C26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Number_Bed_BG, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Number_Bed_BG, lv_color_hex(0x5A646E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Number_Bed_BG, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_NumberBedActual

    ui_NumberBedActual = lv_label_create(ui_Number_Bed_BG);

    lv_obj_set_width(ui_NumberBedActual, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NumberBedActual, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_NumberBedActual, 0);
    lv_obj_set_y(ui_NumberBedActual, -10);

    lv_obj_set_align(ui_NumberBedActual, LV_ALIGN_CENTER);

    lv_label_set_text(ui_NumberBedActual, "260°");

    lv_obj_clear_flag(ui_NumberBedActual,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                      LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_NumberBedActual, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NumberBedActual, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NumberBedActual, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_NumberBedSet

    ui_NumberBedSet = lv_label_create(ui_Number_Bed_BG);

    lv_obj_set_width(ui_NumberBedSet, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NumberBedSet, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_NumberBedSet, 0);
    lv_obj_set_y(ui_NumberBedSet, 20);

    lv_obj_set_align(ui_NumberBedSet, LV_ALIGN_CENTER);

    lv_label_set_text(ui_NumberBedSet, "T260");

    lv_obj_clear_flag(ui_NumberBedSet, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_NumberBedSet, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NumberBedSet, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NumberBedSet, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ArcBedSet

    ui_ArcBedSet = lv_arc_create(ui_Knob_Bed);

    lv_obj_set_width(ui_ArcBedSet, 135);
    lv_obj_set_height(ui_ArcBedSet, 135);

    lv_obj_set_x(ui_ArcBedSet, 0);
    lv_obj_set_y(ui_ArcBedSet, 0);

    lv_obj_set_align(ui_ArcBedSet, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_ArcBedSet, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_arc_set_range(ui_ArcBedSet, 0, 100);
    lv_arc_set_bg_angles(ui_ArcBedSet, 120, 60);

    lv_obj_set_style_radius(ui_ArcBedSet, 135, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ArcBedSet, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcBedSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ArcBedSet, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ArcBedSet, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ArcBedSet, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ArcBedSet, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_ArcBedSet, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcBedSet, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcBedSet, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcBedSet, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcBedSet, lv_color_hex(0x989B9B), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcBedSet, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcBedSet, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ArcBedSet, 20, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ArcBedSet, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcBedSet, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ArcBedSet, lv_color_hex(0x282828), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_ArcBedSet, LV_GRAD_DIR_VER, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_LabelTool

    ui_LabelTool = lv_label_create(ui_Home);

    lv_obj_set_width(ui_LabelTool, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTool, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTool, -75);
    lv_obj_set_y(ui_LabelTool, 75);

    lv_obj_set_align(ui_LabelTool, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTool, "Tool");

    lv_obj_clear_flag(ui_LabelTool, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_LabelTool, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTool, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelBed

    ui_LabelBed = lv_label_create(ui_Home);

    lv_obj_set_width(ui_LabelBed, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelBed, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelBed, 75);
    lv_obj_set_y(ui_LabelBed, 75);

    lv_obj_set_align(ui_LabelBed, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelBed, "Bed");

    lv_obj_clear_flag(ui_LabelBed, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_text_color(ui_LabelBed, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBed, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Status

    ui_Status = lv_obj_create(ui_Home);

    lv_obj_set_width(ui_Status, 280);
    lv_obj_set_height(ui_Status, 100);

    lv_obj_set_x(ui_Status, 0);
    lv_obj_set_y(ui_Status, -40);

    lv_obj_set_align(ui_Status, LV_ALIGN_BOTTOM_MID);

    lv_obj_clear_flag(ui_Status, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_add_event_cb(ui_Status, ui_event_Status, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Status, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Status, lv_color_hex(0x1E242D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Status, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Status, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StatusStatus

    ui_StatusStatus = lv_label_create(ui_Status);

    lv_obj_set_width(ui_StatusStatus, 65);
    lv_obj_set_height(ui_StatusStatus, 18);

    lv_obj_set_x(ui_StatusStatus, 8);
    lv_obj_set_y(ui_StatusStatus, -30);

    lv_obj_set_align(ui_StatusStatus, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_StatusStatus, "Status");

    lv_obj_clear_flag(ui_StatusStatus, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_StatusRemain

    ui_StatusRemain = lv_label_create(ui_Status);

    lv_obj_set_width(ui_StatusRemain, 65);
    lv_obj_set_height(ui_StatusRemain, 18);

    lv_obj_set_x(ui_StatusRemain, 8);
    lv_obj_set_y(ui_StatusRemain, 0);

    lv_obj_set_align(ui_StatusRemain, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_StatusRemain, "Remain");

    lv_obj_clear_flag(ui_StatusRemain, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_StatusName

    ui_StatusName = lv_label_create(ui_Status);

    lv_obj_set_width(ui_StatusName, 65);
    lv_obj_set_height(ui_StatusName, 18);

    lv_obj_set_x(ui_StatusName, 8);
    lv_obj_set_y(ui_StatusName, 30);

    lv_obj_set_align(ui_StatusName, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_StatusName, "Name");

    lv_obj_clear_flag(ui_StatusName, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_LabelRemain

    ui_LabelRemain = lv_label_create(ui_Status);

    lv_obj_set_width(ui_LabelRemain, 185);
    lv_obj_set_height(ui_LabelRemain, 18);

    lv_obj_set_x(ui_LabelRemain, 37);
    lv_obj_set_y(ui_LabelRemain, 0);

    lv_obj_set_align(ui_LabelRemain, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelRemain, "Text");

    lv_obj_clear_flag(ui_LabelRemain, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_LabelName

    ui_LabelName = lv_label_create(ui_Status);

    lv_obj_set_width(ui_LabelName, 185);
    lv_obj_set_height(ui_LabelName, 18);

    lv_obj_set_x(ui_LabelName, 37);
    lv_obj_set_y(ui_LabelName, 30);

    lv_obj_set_align(ui_LabelName, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelName, "Text");

    lv_obj_clear_flag(ui_LabelName, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_LabelStatus

    ui_LabelStatus = lv_label_create(ui_Status);

    lv_obj_set_width(ui_LabelStatus, 185);
    lv_obj_set_height(ui_LabelStatus, 18);

    lv_obj_set_x(ui_LabelStatus, 37);
    lv_obj_set_y(ui_LabelStatus, -30);

    lv_obj_set_align(ui_LabelStatus, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelStatus, "Text");

    lv_obj_clear_flag(ui_LabelStatus, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE |
                      LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                      LV_OBJ_FLAG_SCROLL_CHAIN);

    // ui_Popup_Setting

    ui_Popup_Setting = lv_obj_create(ui_Home);

    lv_obj_set_width(ui_Popup_Setting, 280);
    lv_obj_set_height(ui_Popup_Setting, 203);

    lv_obj_set_x(ui_Popup_Setting, 0);
    lv_obj_set_y(ui_Popup_Setting, 10);

    lv_obj_set_align(ui_Popup_Setting, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Popup_Setting, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Popup_Setting, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Popup_Setting, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Popup_Setting, lv_color_hex(0x373741), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Popup_Setting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Popup_Setting, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Popup_Setting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Popup_Setting, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Popup_Setting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Popup_Setting, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Popup_Setting, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Temperature_Settings_Header

    ui_Temperature_Settings_Header = lv_obj_create(ui_Popup_Setting);

    lv_obj_set_height(ui_Temperature_Settings_Header, 24);
    lv_obj_set_width(ui_Temperature_Settings_Header, lv_pct(100));

    lv_obj_set_x(ui_Temperature_Settings_Header, 0);
    lv_obj_set_y(ui_Temperature_Settings_Header, 0);

    lv_obj_set_align(ui_Temperature_Settings_Header, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Temperature_Settings_Header, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Temperature_Settings_Header, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Temperature_Settings_Header, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Temperature_Settings_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Temperature_Setting

    ui_Label_Temperature_Setting = lv_label_create(ui_Temperature_Settings_Header);

    lv_obj_set_width(ui_Label_Temperature_Setting, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_Temperature_Setting, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_Temperature_Setting, 0);
    lv_obj_set_y(ui_Label_Temperature_Setting, 0);

    lv_obj_set_align(ui_Label_Temperature_Setting, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label_Temperature_Setting, "Tool");

    lv_obj_set_style_text_color(ui_Label_Temperature_Setting, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Temperature_Setting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Roller1

    ui_Roller1 = lv_roller_create(ui_Popup_Setting);
    lv_roller_set_options(ui_Roller1, "0\n1\n2", LV_ROLLER_MODE_NORMAL);

    lv_obj_set_height(ui_Roller1, 90);
    lv_obj_set_width(ui_Roller1, lv_pct(25));

    lv_obj_set_x(ui_Roller1, -85);
    lv_obj_set_y(ui_Roller1, -20);

    lv_obj_set_align(ui_Roller1, LV_ALIGN_CENTER);

    lv_obj_set_style_text_align(ui_Roller1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Roller1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Roller2

    ui_Roller2 = lv_roller_create(ui_Popup_Setting);
    lv_roller_set_options(ui_Roller2, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_NORMAL);

    lv_obj_set_height(ui_Roller2, 90);
    lv_obj_set_width(ui_Roller2, lv_pct(25));

    lv_obj_set_x(ui_Roller2, 0);
    lv_obj_set_y(ui_Roller2, -20);

    lv_obj_set_align(ui_Roller2, LV_ALIGN_CENTER);

    lv_obj_set_style_text_align(ui_Roller2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Roller2, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Roller3

    ui_Roller3 = lv_roller_create(ui_Popup_Setting);
    lv_roller_set_options(ui_Roller3, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_NORMAL);

    lv_obj_set_height(ui_Roller3, 90);
    lv_obj_set_width(ui_Roller3, lv_pct(25));

    lv_obj_set_x(ui_Roller3, 85);
    lv_obj_set_y(ui_Roller3, -20);

    lv_obj_set_align(ui_Roller3, LV_ALIGN_CENTER);

    lv_obj_set_style_text_align(ui_Roller3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Roller3, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonOk

    ui_ButtonOk = lv_btn_create(ui_Popup_Setting);

    lv_obj_set_width(ui_ButtonOk, 100);
    lv_obj_set_height(ui_ButtonOk, 37);

    lv_obj_set_x(ui_ButtonOk, 22);
    lv_obj_set_y(ui_ButtonOk, -15);

    lv_obj_set_align(ui_ButtonOk, LV_ALIGN_BOTTOM_LEFT);

    lv_obj_add_flag(ui_ButtonOk, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonOk, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonOk, ui_event_ButtonOk, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_ButtonOk, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SettingsOk1

    ui_SettingsOk1 = lv_label_create(ui_ButtonOk);

    lv_obj_set_width(ui_SettingsOk1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SettingsOk1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SettingsOk1, 0);
    lv_obj_set_y(ui_SettingsOk1, 0);

    lv_obj_set_align(ui_SettingsOk1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SettingsOk1, "OK");

    lv_obj_add_event_cb(ui_SettingsOk1, ui_event_SettingsOk1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_text_color(ui_SettingsOk1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingsOk1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonCancel

    ui_ButtonCancel = lv_btn_create(ui_Popup_Setting);

    lv_obj_set_width(ui_ButtonCancel, 100);
    lv_obj_set_height(ui_ButtonCancel, 37);

    lv_obj_set_x(ui_ButtonCancel, -22);
    lv_obj_set_y(ui_ButtonCancel, -15);

    lv_obj_set_align(ui_ButtonCancel, LV_ALIGN_BOTTOM_RIGHT);

    lv_obj_add_flag(ui_ButtonCancel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonCancel, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonCancel, ui_event_ButtonCancel, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(ui_ButtonCancel, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SettingsCancel

    ui_SettingsCancel = lv_label_create(ui_ButtonCancel);

    lv_obj_set_width(ui_SettingsCancel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SettingsCancel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SettingsCancel, 0);
    lv_obj_set_y(ui_SettingsCancel, 0);

    lv_obj_set_align(ui_SettingsCancel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SettingsCancel, "Cancel");

    lv_obj_set_style_text_color(ui_SettingsCancel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SettingsCancel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Popup_Control

    ui_Popup_Control = lv_obj_create(ui_Home);

    lv_obj_set_width(ui_Popup_Control, 280);
    lv_obj_set_height(ui_Popup_Control, 100);

    lv_obj_set_x(ui_Popup_Control, 0);
    lv_obj_set_y(ui_Popup_Control, -40);

    lv_obj_set_align(ui_Popup_Control, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_Popup_Control, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Popup_Control, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_Popup_Control, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Popup_Control, lv_color_hex(0x373741), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Popup_Control, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Popup_Control, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Popup_Control, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Popup_Control, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Popup_Control, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Popup_Control, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Popup_Control, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Control_Settings_Header

    ui_Control_Settings_Header = lv_obj_create(ui_Popup_Control);

    lv_obj_set_height(ui_Control_Settings_Header, 24);
    lv_obj_set_width(ui_Control_Settings_Header, lv_pct(100));

    lv_obj_set_x(ui_Control_Settings_Header, 0);
    lv_obj_set_y(ui_Control_Settings_Header, 0);

    lv_obj_set_align(ui_Control_Settings_Header, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_Control_Settings_Header, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Control_Settings_Header, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Control_Settings_Header, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Control_Settings_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label_Control_Setting

    ui_Label_Control_Setting = lv_label_create(ui_Control_Settings_Header);

    lv_obj_set_width(ui_Label_Control_Setting, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label_Control_Setting, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label_Control_Setting, 0);
    lv_obj_set_y(ui_Label_Control_Setting, 0);

    lv_obj_set_align(ui_Label_Control_Setting, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label_Control_Setting, "Control");

    lv_obj_set_style_text_color(ui_Label_Control_Setting, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Control_Setting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImgButtonPlay

    ui_ImgButtonPlay = lv_imgbtn_create(ui_Popup_Control);
    lv_imgbtn_set_src(ui_ImgButtonPlay, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_play_png, NULL);

    lv_obj_set_height(ui_ImgButtonPlay, 64);
    lv_obj_set_width(ui_ImgButtonPlay, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImgButtonPlay, -85);
    lv_obj_set_y(ui_ImgButtonPlay, 13);

    lv_obj_set_align(ui_ImgButtonPlay, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_ImgButtonPlay, ui_event_ImgButtonPlay, LV_EVENT_ALL, NULL);

    // ui_ImgButtonPause

    ui_ImgButtonPause = lv_imgbtn_create(ui_Popup_Control);
    lv_imgbtn_set_src(ui_ImgButtonPause, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_pause_png, NULL);

    lv_obj_set_height(ui_ImgButtonPause, 64);
    lv_obj_set_width(ui_ImgButtonPause, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImgButtonPause, 0);
    lv_obj_set_y(ui_ImgButtonPause, 13);

    lv_obj_set_align(ui_ImgButtonPause, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_ImgButtonPause, ui_event_ImgButtonPause, LV_EVENT_ALL, NULL);

    // ui_ImgButtonStop

    ui_ImgButtonStop = lv_imgbtn_create(ui_Popup_Control);
    lv_imgbtn_set_src(ui_ImgButtonStop, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_stop_png, NULL);

    lv_obj_set_height(ui_ImgButtonStop, 64);
    lv_obj_set_width(ui_ImgButtonStop, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImgButtonStop, 85);
    lv_obj_set_y(ui_ImgButtonStop, 13);

    lv_obj_set_align(ui_ImgButtonStop, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_ImgButtonStop, ui_event_ImgButtonStop, LV_EVENT_ALL, NULL);

    // ui_Popup_WiFi

    ui_Popup_WiFi = lv_obj_create(ui_Home);

    lv_obj_set_width(ui_Popup_WiFi, 265);
    lv_obj_set_height(ui_Popup_WiFi, 275);

    lv_obj_set_x(ui_Popup_WiFi, 0);
    lv_obj_set_y(ui_Popup_WiFi, 65);

    lv_obj_set_align(ui_Popup_WiFi, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Popup_WiFi, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_Popup_WiFi, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE |
                      LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC |
                      LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_style_radius(ui_Popup_WiFi, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImageWiFi

    ui_ImageWiFi = lv_img_create(ui_Popup_WiFi);
    lv_img_set_src(ui_ImageWiFi, &ui_img_qr_png);

    lv_obj_set_width(ui_ImageWiFi, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageWiFi, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageWiFi, 0);
    lv_obj_set_y(ui_ImageWiFi, 0);

    lv_obj_set_align(ui_ImageWiFi, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageWiFi, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageWiFi, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Footer

    ui_Footer = lv_obj_create(ui_Home);

    lv_obj_set_height(ui_Footer, 32);
    lv_obj_set_width(ui_Footer, lv_pct(100));

    lv_obj_set_x(ui_Footer, 0);
    lv_obj_set_y(ui_Footer, 0);

    lv_obj_set_align(ui_Footer, LV_ALIGN_BOTTOM_MID);

    lv_obj_clear_flag(ui_Footer, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Footer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Footer, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Footer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Footer_Status

    ui_Footer_Status = lv_label_create(ui_Footer);

    lv_obj_set_width(ui_Footer_Status, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Footer_Status, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Footer_Status, 10);
    lv_obj_set_y(ui_Footer_Status, 0);

    lv_obj_set_align(ui_Footer_Status, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_Footer_Status, "12-05-2022");

    lv_obj_set_style_text_color(ui_Footer_Status, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Footer_Status, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Footer_Completion

    ui_Footer_Completion = lv_bar_create(ui_Footer);
    lv_bar_set_range(ui_Footer_Completion, 0, 100);
    lv_bar_set_value(ui_Footer_Completion, 70, LV_ANIM_OFF);

    lv_obj_set_width(ui_Footer_Completion, 280);
    lv_obj_set_height(ui_Footer_Completion, 10);

    lv_obj_set_x(ui_Footer_Completion, 0);
    lv_obj_set_y(ui_Footer_Completion, 0);

    lv_obj_set_align(ui_Footer_Completion, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Footer_Completion,
                      LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE);

    lv_obj_set_style_radius(ui_Footer_Completion, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Footer_Completion, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Footer_Completion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Footer_Completion, lv_color_hex(0x1E242D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Footer_Completion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Footer_Completion, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Footer_Completion, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Footer_Completion, lv_color_hex(0x37B9F5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Footer_Completion, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Footer_Completion, lv_color_hex(0x1464F0), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Footer_Completion, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_basic_init(dispp);
    lv_disp_set_theme(dispp, theme);
    ui_Home_screen_init();
    lv_disp_load_scr(ui_Home);
}

