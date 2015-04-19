#include <pebble.h>
#include "localize.h"

static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_ampm_layer;
static TextLayer *s_date_layer;
static GFont s_time_font;
static GFont s_date_font;

static void update_time() {
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  
  int hour = tick_time->tm_hour;
  
  if(hour >= 21) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, _("night"));
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#endif
  } else if(hour >= 18) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, _("evening"));
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorOxfordBlue);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#endif
  } else if(hour >= 15) {
	  text_layer_set_text(s_ampm_layer, _("late"));
	  text_layer_set_text(s_time_layer, _("afternoon"));
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorSunsetOrange);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
#endif
  } else if(hour >= 12) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, _("afternoon"));
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorVividCerulean);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
#endif
  } else if(hour >= 9) {
	  text_layer_set_text(s_ampm_layer, _("late"));
	  text_layer_set_text(s_time_layer, _("morning"));
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorVividCerulean);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
#endif
  } else if(hour >= 6) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, _("morning"));
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorVividCerulean);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
#endif
  } else if(hour >= 3) {
	  text_layer_set_text(s_ampm_layer, _("early"));
	  text_layer_set_text(s_time_layer, _("morning"));
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorBabyBlueEyes);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#endif
  } else if(hour >= 0) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, _("midnight"));
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#endif
  } else {
	  text_layer_set_text(s_ampm_layer, "error");
	  text_layer_set_text(s_time_layer, "error");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorRed);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
#endif
  }
  
  static char date_buffer[] = "WWWWWWWWW";

  strftime(date_buffer, sizeof("WWWWWWWWW"), "%A", tick_time);

  text_layer_set_text(s_date_layer, date_buffer); 
  
}

static void main_window_load(Window *window) {
	setlocale(LC_ALL, "");
	
	
	s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CYNTHE_28));
	s_date_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CYNTHE_18));
	
	s_time_layer = text_layer_create(GRect(0, 128, 140, 168));
	text_layer_set_background_color(s_time_layer, GColorClear);
	text_layer_set_font(s_time_layer, s_time_font);
	text_layer_set_text_alignment(s_time_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
	
	s_ampm_layer = text_layer_create(GRect(0, 92, 140, 168));
	text_layer_set_background_color(s_ampm_layer, GColorClear);
	text_layer_set_font(s_ampm_layer, s_time_font);
	text_layer_set_text_alignment(s_ampm_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_ampm_layer));
	
	s_date_layer = text_layer_create(GRect(0, 119, 138, 168));
	text_layer_set_background_color(s_date_layer, GColorClear);
	text_layer_set_font(s_date_layer, s_date_font);
	text_layer_set_text_alignment(s_date_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_date_layer));
	
	update_time();
}

static void main_window_unload(Window *window) {
	text_layer_destroy(s_time_layer);
	text_layer_destroy(s_ampm_layer);
	text_layer_destroy(s_date_layer);
	fonts_unload_custom_font(s_time_font);
	fonts_unload_custom_font(s_date_font);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void init() {
  s_main_window = window_create();
	
	locale_init();

  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  window_stack_push(s_main_window, true);
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void deinit() {
  window_destroy(s_main_window);
  tick_timer_service_unsubscribe();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}