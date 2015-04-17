#include <pebble.h>

#define KEY_TEMPERATURE 0
#define KEY_CONDITIONS 1

static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_ampm_layer;
static TextLayer *s_date_layer;
static TextLayer *s_weather_layer;
static GFont s_time_font;
static GFont s_date_font;

static void update_time() {
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  
  int hour = tick_time->tm_hour;
  
  if(hour >= 21) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, "night");
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
	  text_layer_set_text(s_time_layer, "evening");
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
	  text_layer_set_text(s_ampm_layer, "late");
	  text_layer_set_text(s_time_layer, "afternoon");
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
	  text_layer_set_text(s_time_layer, "afternoon");
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
	  text_layer_set_text(s_ampm_layer, "late");
	  text_layer_set_text(s_time_layer, "morning");
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
	  text_layer_set_text(s_time_layer, "morning");
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
	  text_layer_set_text(s_ampm_layer, "early");
	  text_layer_set_text(s_time_layer, "morning");
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
	  text_layer_set_text(s_time_layer, "midnight");
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
  
  //static char time_buffer[] = "00";
  static char date_buffer[] = "WWWWWWWWW";
    
  /*if(clock_is_24h_style() == true) {
    strftime(time_buffer, sizeof("00"), "%H", tick_time);
  } else {
    strftime(time_buffer, sizeof("00"), "%l", tick_time);
  }*/

  strftime(date_buffer, sizeof("WWWWWWWWW"), "%A", tick_time);
    	
  //text_layer_set_text(s_time_layer, time_buffer);
  text_layer_set_text(s_date_layer, date_buffer); 
  
}

static void main_window_load(Window *window) {
	
	s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CYNTHE_28));
	s_date_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CYNTHE_18));
	
	s_weather_layer = text_layer_create(GRect(0, 0, 140, 168));
	text_layer_set_background_color(s_weather_layer, GColorClear);
	text_layer_set_text_color(s_weather_layer, GColorBlack);
	text_layer_set_font(s_weather_layer, s_date_font);
	text_layer_set_text(s_weather_layer, "Loading...");
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_weather_layer));
	
	s_time_layer = text_layer_create(GRect(0, 128, 140, 168));
	//text_layer_set_text_color(s_time_layer, GColorBlack);
	text_layer_set_background_color(s_time_layer, GColorClear);
	text_layer_set_font(s_time_layer, s_time_font);
	text_layer_set_text_alignment(s_time_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
	
	s_ampm_layer = text_layer_create(GRect(0, 92, 140, 168));
	text_layer_set_text_color(s_ampm_layer, GColorBlack);
	text_layer_set_background_color(s_ampm_layer, GColorClear);
	text_layer_set_font(s_ampm_layer, s_time_font);
	text_layer_set_text_alignment(s_ampm_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_ampm_layer));
	
	s_date_layer = text_layer_create(GRect(0, 119, 138, 168));
	text_layer_set_text_color(s_date_layer, GColorBlack);
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
	text_layer_destroy(s_weather_layer);
	fonts_unload_custom_font(s_time_font);
	fonts_unload_custom_font(s_date_font);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

// weather stuff

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {

}

static void inbox_dropped_callback(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

static void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}

static void outbox_sent_callback(DictionaryIterator *iterator, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}

// end weather stuff

static void init() {
  s_main_window = window_create();

  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  window_stack_push(s_main_window, true);
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  
  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_inbox_dropped(inbox_dropped_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
  app_message_register_outbox_sent(outbox_sent_callback);
  
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
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