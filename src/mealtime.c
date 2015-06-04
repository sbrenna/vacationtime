#include <pebble.h>
#include <localize.h>
	
#define KEY_CONDITIONS 0
#define KEY_TEMPERATURE 1
#define KEY_TEMPERATUREC 2
#define KEY_SCALE 3

static Window *s_main_window;
static TextLayer *s_time_layer, *s_ampm_layer, *s_date_layer, *s_weather_layer, *s_temp_layer, *s_digit_h;
static GFont s_time_font, s_date_font, s_weather_font, s_temp_font;
static Layer *batt_layer;
static char hour_buffer[25];
static int digit_m_1 = 0;
static int digit_m_2 = 0;
static int digit_h_1 = 0;
static int digit_h_2 = 0;





void on_animation_stopped(Animation *anim, bool finished, void *context)
{
    //Free the memory used by the Animation
    property_animation_destroy((PropertyAnimation*) anim);
}
 
void animate_layer(Layer *layer, GRect *start, GRect *finish, int duration, int delay)
{
    //Declare animation
    PropertyAnimation *anim = property_animation_create_layer_frame(layer, start, finish);
 
    //Set characteristics
    animation_set_duration((Animation*) anim, duration);
    animation_set_delay((Animation*) anim, delay);
 
    //Set stopped handler to free memory
    AnimationHandlers handlers = {
        //The reference to the stopped handler is the only one in the array
        .stopped = (AnimationStoppedHandler) on_animation_stopped
    };
    animation_set_handlers((Animation*) anim, handlers, NULL);
 
    //Start animation!
    animation_schedule((Animation*) anim);
}

static void update_time() {
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  
  int hour = tick_time->tm_hour;
  /*digit_h_1 = tick_time->tm_hour/10;
  digit_h_2 = tick_time->tm_hour%10;
  digit_m_1 = tick_time->tm_min/10;
  digit_m_2 = tick_time->tm_min%10;
  //int min = tick_time->tm_min;
  snprintf(hour_buffer, sizeof(hour_buffer), "%d%d:%d%d", (int)digit_h_1, (int)digit_h_2, (int)digit_m_1, (int)digit_m_2);
  
  // Set text for hour and minutes
	text_layer_set_text(s_digit_h, hour_buffer);*/

  
  if(hour >= 21) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, "night");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#endif
  } else if(hour >= 18) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, "evening");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorOxfordBlue);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#endif
  } else if(hour >= 15) {
	  text_layer_set_text(s_ampm_layer, "late");
	  text_layer_set_text(s_time_layer, "afternoon");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorSunsetOrange);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
		text_layer_set_text_color(s_temp_layer, GColorBlack);
		text_layer_set_text_color(s_weather_layer, GColorBlack);
    text_layer_set_text_color(s_digit_h, GColorBlack);
#endif
  } else if(hour >= 12) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, "afternoon");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorVividCerulean);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
		text_layer_set_text_color(s_temp_layer, GColorBlack);
		text_layer_set_text_color(s_weather_layer, GColorBlack);
    text_layer_set_text_color(s_digit_h, GColorBlack);
#endif
  } else if(hour >= 9) {
	  text_layer_set_text(s_ampm_layer, "late");
	  text_layer_set_text(s_time_layer, "morning");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorVividCerulean);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
		text_layer_set_text_color(s_temp_layer, GColorBlack);
		text_layer_set_text_color(s_weather_layer, GColorBlack);
    text_layer_set_text_color(s_digit_h, GColorBlack);
#endif
  } else if(hour >= 6) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, "morning");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorVividCerulean);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
		text_layer_set_text_color(s_temp_layer, GColorBlack);
		text_layer_set_text_color(s_weather_layer, GColorBlack);
    text_layer_set_text_color(s_digit_h, GColorBlack);
#endif
  } else if(hour >= 3) {
	  text_layer_set_text(s_ampm_layer, "early");
	  text_layer_set_text(s_time_layer, "morning");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorVeryLightBlue);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#endif
  } else if(hour >= 0) {
	  text_layer_set_text(s_ampm_layer, " ");
	  text_layer_set_text(s_time_layer, "midnight");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorBlack);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#endif
  } else {
	  text_layer_set_text(s_ampm_layer, "error");
	  text_layer_set_text(s_time_layer, "error");
#ifdef PBL_COLOR
	  window_set_background_color(s_main_window, GColorRed);
	  text_layer_set_text_color(s_ampm_layer, GColorWhite);
	  text_layer_set_text_color(s_time_layer, GColorWhite);
	  text_layer_set_text_color(s_date_layer, GColorWhite);
		text_layer_set_text_color(s_temp_layer, GColorWhite);
		text_layer_set_text_color(s_weather_layer, GColorWhite);
    text_layer_set_text_color(s_digit_h, GColorWhite);
#else
	  window_set_background_color(s_main_window, GColorWhite);
	  text_layer_set_text_color(s_ampm_layer, GColorBlack);
	  text_layer_set_text_color(s_time_layer, GColorBlack);
	  text_layer_set_text_color(s_date_layer, GColorBlack);
		text_layer_set_text_color(s_temp_layer, GColorBlack);
		text_layer_set_text_color(s_weather_layer, GColorBlack);
    text_layer_set_text_color(s_digit_h, GColorBlack);
#endif
  }

  static char date_buffer[] = "WWWWWWWWW";

  strftime(date_buffer, sizeof("WWWWWWWWW"), "%A", tick_time);

if(strcmp(date_buffer, "Monday") == 0) {
	text_layer_set_text(s_date_layer, "Monday");
} else if(strcmp(date_buffer, "Tuesday") == 0) {
	text_layer_set_text(s_date_layer, "Tuesday");
} else if(strcmp(date_buffer, "Wednesday") == 0) {
	text_layer_set_text(s_date_layer, "Wednesday");
} else if(strcmp(date_buffer, "Thursday") == 0) {
	text_layer_set_text(s_date_layer, "Thursday");
} else if(strcmp(date_buffer, "Friday") == 0) {
	text_layer_set_text(s_date_layer, "Friday");
} else if(strcmp(date_buffer, "Saturday") == 0) {
	text_layer_set_text(s_date_layer, "Saturday");
} else if(strcmp(date_buffer, "Sunday") == 0) {
	text_layer_set_text(s_date_layer, "Sunday");
} else {
	text_layer_set_text(s_date_layer, date_buffer);
}
}

static void tap_handler(AccelAxisType axis, int32_t direction) {
	APP_LOG(APP_LOG_LEVEL_INFO, "Tap/flick registered!");
	
  
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  
  digit_h_1 = tick_time->tm_hour/10;
  digit_h_2 = tick_time->tm_hour%10;
  digit_m_1 = tick_time->tm_min/10;
  digit_m_2 = tick_time->tm_min%10;
  
  // Convert int to char
  snprintf(hour_buffer, sizeof(hour_buffer), "%d%d:%d%d", (int)digit_h_1, (int)digit_h_2, (int)digit_m_1, (int)digit_m_2);
  
  // Set text for hour and minutes
	text_layer_set_text(s_digit_h, hour_buffer);
  
	// Battery bar moves in from the left
	GRect startbatt = GRect(-5,0,144,168);
	GRect finishbatt = GRect(0,0,144,168);
	animate_layer(batt_layer, &startbatt, &finishbatt, 1000, 0);
	
	GRect startbatt2 = GRect(0,0,144,168);
	GRect finishbatt2 = GRect(-5,0,144,168);
	animate_layer(batt_layer, &startbatt2, &finishbatt2, 1000, 7000);
	
	// Current temp moves in from the right
	GRect start = GRect(288,0,141,168);
	GRect finish = GRect(0,0,141,168);
	animate_layer(text_layer_get_layer(s_temp_layer), &start, &finish, 1000, 0);
	
	GRect start3 = GRect(0,0,141,168);
	GRect finish3 = GRect(288,0,141,168);
	animate_layer(text_layer_get_layer(s_temp_layer), &start3, &finish3, 1000, 7000);
	
	// Current weather moves in from right
	GRect start2 = GRect(288,15,141,168);
	GRect finish2 = GRect(0,15,141,168);
	animate_layer(text_layer_get_layer(s_weather_layer), &start2, &finish2, 1000, 0);
	
	GRect start1 = GRect(0,15,141,168);
	GRect finish1 = GRect(288,15,141,168);
	animate_layer(text_layer_get_layer(s_weather_layer), &start1, &finish1, 1000, 7000);
  
  //Hour move in from right
  GRect start4 = GRect(288,30,141,168);
  GRect finish4 = GRect(0,30,141,168);
  animate_layer(text_layer_get_layer(s_digit_h), &start4, &finish4, 1000, 0);
  
  GRect start5 = GRect(0,30,141,168);
  GRect finish5 = GRect(288,30,141,168);
  animate_layer(text_layer_get_layer(s_digit_h), &start5, &finish5, 1000, 7000);
}

static void battery_handler(BatteryChargeState state) {
	layer_mark_dirty(batt_layer);
}

static void batt_layer_draw(Layer *layer, GContext *ctx) {
	time_t temp = time(NULL);
 	struct tm *tick_time = localtime(&temp);
  
 	int hour = tick_time->tm_hour;

 	BatteryChargeState state = battery_state_service_peek();
 	int pct = state.charge_percent;
	int w = 4; // width of battery bar

	#ifdef PBL_COLOR
	// basalt, aplite (should be a middle ground between fore/background colours)
 	if(hour >= 21) { // black, black
		graphics_context_set_fill_color(ctx, GColorLightGray); // foreground colour (remaining, lighter than bg)
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorBlack); // background colour (expended, darker than bg)
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 18) { // oxford blue, black
		graphics_context_set_fill_color(ctx, GColorCobaltBlue);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorOxfordBlue);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 15) { // sunset orange, white
		graphics_context_set_fill_color(ctx, GColorMelon);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorSunsetOrange);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 12) { // vivid cerulean, white
		graphics_context_set_fill_color(ctx, GColorBabyBlueEyes);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorVividCerulean);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 9) { // vivid cerulean, white
		graphics_context_set_fill_color(ctx, GColorBabyBlueEyes);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorVividCerulean);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 6) { // vivid cerulean, white
		graphics_context_set_fill_color(ctx, GColorBabyBlueEyes);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorVividCerulean);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 3) { // very light blue, black
		graphics_context_set_fill_color(ctx, GColorBabyBlueEyes);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorVeryLightBlue);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 0) { // black, black
		graphics_context_set_fill_color(ctx, GColorLightGray);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorBlack);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else {
	  
  }
	#else
	if(hour >= 21) { // black, black
		graphics_context_set_fill_color(ctx, GColorWhite); // foreground colour (remaining, lighter than bg)
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorBlack); // background colour (expended, darker than bg)
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 18) { // oxford blue, black
		graphics_context_set_fill_color(ctx, GColorWhite);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorBlack);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 15) { // sunset orange, white
		graphics_context_set_fill_color(ctx, GColorBlack);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorWhite);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 12) { // vivid cerulean, white
		graphics_context_set_fill_color(ctx, GColorBlack);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorWhite);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 9) { // vivid cerulean, white
		graphics_context_set_fill_color(ctx, GColorBlack);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorWhite);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 6) { // vivid cerulean, white
		graphics_context_set_fill_color(ctx, GColorBlack);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorWhite);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 3) { // very light blue, black
		graphics_context_set_fill_color(ctx, GColorWhite);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorBlack);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else if(hour >= 0) { // black, black
		graphics_context_set_fill_color(ctx, GColorWhite);
 		graphics_fill_rect(ctx, GRect(0,0,w,168), 0, GCornerNone);
 		graphics_context_set_fill_color(ctx, GColorBlack);
 		graphics_fill_rect(ctx, GRect(0,0,w,(16.8*(100-pct)/10)), 0, GCornerNone);
  } else {
	  
  }
  #endif
}

static void main_window_load(Window *window) {
	s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CYNTHE_25));
	s_date_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CYNTHE_22));
	s_temp_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CYNTHE_18));
	s_weather_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CYNTHE_14));

	batt_layer = layer_create(GRect(-5, 0, 144, 168));
	layer_add_child(window_get_root_layer(window), batt_layer);
	layer_set_update_proc(batt_layer, batt_layer_draw);
	
	s_ampm_layer = text_layer_create(GRect(0, 96, 142, 168));
	text_layer_set_background_color(s_ampm_layer, GColorClear);
	text_layer_set_font(s_ampm_layer, s_time_font);
	text_layer_set_text_alignment(s_ampm_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_ampm_layer));

	s_date_layer = text_layer_create(GRect(0, 115, 141, 168));
	text_layer_set_background_color(s_date_layer, GColorClear);
	text_layer_set_font(s_date_layer, s_date_font);
	text_layer_set_text_alignment(s_date_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_date_layer));

	s_time_layer = text_layer_create(GRect(0, 132, 142, 168));
	text_layer_set_background_color(s_time_layer, GColorClear);
	text_layer_set_font(s_time_layer, s_time_font);
	text_layer_set_text_alignment(s_time_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
	
	s_temp_layer = text_layer_create(GRect(288, 0, 141, 168));
	text_layer_set_background_color(s_temp_layer, GColorClear);
	text_layer_set_font(s_temp_layer, s_weather_font);
	text_layer_set_text_alignment(s_temp_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_temp_layer));
	text_layer_set_text(s_temp_layer, "Updating");
	
	s_weather_layer = text_layer_create(GRect(288, 15, 141, 168));
	text_layer_set_background_color(s_weather_layer, GColorClear);
	text_layer_set_font(s_weather_layer, s_weather_font);
	text_layer_set_text_alignment(s_weather_layer, GTextAlignmentRight);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_weather_layer));
	text_layer_set_text(s_weather_layer, "Weather");
  
  s_digit_h = text_layer_create(GRect(288,30,141,168));
  text_layer_set_background_color(s_digit_h, GColorClear);
  text_layer_set_text_alignment(s_digit_h, GTextAlignmentRight);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_digit_h));  

	update_time();
}

static void main_window_unload(Window *window) {
	text_layer_destroy(s_time_layer);
	text_layer_destroy(s_ampm_layer);
	text_layer_destroy(s_date_layer);
  text_layer_destroy(s_digit_h);
	fonts_unload_custom_font(s_time_font);
	fonts_unload_custom_font(s_date_font);
	layer_destroy(batt_layer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {
  // Store incoming information
	static char temperature_buffer[25];
	static char temperaturec_buffer[25];
	static char conditions_buffer[100];
	
	// Read first item
  Tuple *t = dict_read_first(iterator);

  // For all items
  while(t != NULL) {
		// Which key was received?
    switch(t->key) {
		case KEY_SCALE:
			if(strcmp(t->value->cstring, "degf") == 0) { // If fahrenheit is selected
				persist_write_bool(KEY_SCALE, false);
			} else if(strcmp(t->value->cstring, "degc") == 0) { // If celsius is selected
				persist_write_bool(KEY_SCALE, true);
			} 
  	break;
		case KEY_TEMPERATURE: // Temperature in fahrenheit
    
      if ((int)t->value->int32 > 20 && (int)t->value->int32 < 27) {
        snprintf(temperature_buffer, sizeof(temperature_buffer), "It's pretty warm");
      } else if ((int)t->value->int32 >= 27 && (int)t->value->int32 < 30) {
        snprintf(temperature_buffer, sizeof(temperature_buffer), "It's HOT!");
      } else if ((int)t->value->int32 >= 30) {
        snprintf(temperature_buffer, sizeof(temperature_buffer), "It's really HOT !");
      } else if ((int)t->value->int32 <= 20 && (int)t->value->int32 > 14) {
        snprintf(temperature_buffer, sizeof(temperature_buffer), "Feels mildly warm...");
      } else if ((int)t->value->int32 <= 14 && (int)t->value->int32 > 4) {
        snprintf(temperature_buffer, sizeof(temperature_buffer), "It's cold.");
      } else if ((int)t->value->int32 <= 4 && (int)t->value->int32 > 0) {
        snprintf(temperature_buffer, sizeof(temperature_buffer), "It's really cold !");
      } else if ((int)t->value->int32 <= 0) {  
        snprintf(temperature_buffer, sizeof(temperature_buffer), "It's freezing!");
      } else {
			snprintf(temperature_buffer, sizeof(temperature_buffer), "Feels like %d.", (int)t->value->int32);
      }  
      break;
		case KEY_TEMPERATUREC: // Temperature in celsius
			snprintf(temperaturec_buffer, sizeof(temperaturec_buffer), "Feels like %d.", (int)t->value->int32);
  	break;
		case KEY_CONDITIONS:
 		 	snprintf(conditions_buffer, sizeof(conditions_buffer), "%s", t->value->cstring);
 		break;
		default:
 		 APP_LOG(APP_LOG_LEVEL_ERROR, "Key %d not recognized!", (int)t->key);
 		 break;
    }

    // Look for next item
    t = dict_read_next(iterator);
  }
	// Set text for conditions
	text_layer_set_text(s_weather_layer, conditions_buffer);
	// Set text for temperature
	bool scale = persist_read_bool(KEY_SCALE);
	if(scale == false) {
		text_layer_set_text(s_temp_layer, temperature_buffer); // Set to fahrenheit
	} else if(scale == true) {
		text_layer_set_text(s_temp_layer, temperaturec_buffer); // Set to celsius
	} else {
		text_layer_set_text(s_temp_layer, temperature_buffer); // Default to fahrenheit
	}
}

static void inbox_dropped_callback(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
	text_layer_set_text(s_weather_layer, "Update Failed");
	text_layer_set_text(s_temp_layer, "Update Failed");
}

static void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
	text_layer_set_text(s_weather_layer, "Update Failed"); // No BT, Internet
	text_layer_set_text(s_temp_layer, "Update Failed");
}

static void outbox_sent_callback(DictionaryIterator *iterator, void *context) { // updates weather
  APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}

static void init() {
  s_main_window = window_create();

  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  window_stack_push(s_main_window, true);
  tick_timer_service_subscribe(HOUR_UNIT, tick_handler);
  battery_state_service_subscribe(battery_handler);
	accel_tap_service_subscribe(tap_handler);
	
	// Register callbacks
	app_message_register_inbox_received(inbox_received_callback);
	// Open AppMessage
	app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
	app_message_register_inbox_dropped(inbox_dropped_callback);
	app_message_register_outbox_failed(outbox_failed_callback);
	app_message_register_outbox_sent(outbox_sent_callback);
}

static void deinit() {
  window_destroy(s_main_window);
  tick_timer_service_unsubscribe();
  battery_state_service_unsubscribe();
}

int main(void) {
  init();
  //locale_init();
  app_event_loop();
  deinit();
}