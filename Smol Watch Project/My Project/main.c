#include <atmel_start.h>
#include <hpl_sleep.h>
#include "watch-library/watch.h"
#include "mars_clock.h"

Watch watch;
int light = 1;

void calendar_callback(struct calendar_descriptor *const calendar) {
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);

	update_display(&watch, date_time);
/*
	if (date_time.time.min % 2 == 0) {
		watch_set_led_color(50, 0);
	} else {
		watch_set_led_color(0, 50);
	}
*/
}

static void mode_callback() {
}

static void light_callback() {
}

static void alarm_callback() {
}

int lightOn = 0;

static void tick_callback() {
	gpio_set_pin_level(GREEN, lightOn == 0);
	lightOn = (lightOn + 1) % 10;
}

int main(void)
{
	atmel_start_init();

	gpio_set_pin_level(GREEN, false);

	// Set pin direction to output
	gpio_set_pin_direction(GREEN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(GREEN, GPIO_PIN_FUNCTION_OFF);

	watch_init(&watch);

	watch_enable_display(&watch);
	watch_display_pixel(&watch, 1, 16);

	watch_enable_buttons(&watch);
	watch_register_button_callback(&watch, BTN_MODE, &mode_callback);
	watch_register_button_callback(&watch, BTN_ALARM, &alarm_callback);
	watch_register_button_callback(&watch, BTN_LIGHT, &light_callback);

	watch_enable_date_time(&watch);
	struct calendar_date_time date_time;
	date_time.date.year = 2021;
	date_time.date.month = 4;
	date_time.date.day = 30;
	date_time.time.hour = 9;
	date_time.time.min = 40;
	date_time.time.sec = 0;
	watch_set_date_time(date_time);
	struct calendar_alarm alarm;
	alarm.cal_alarm.mode = REPEAT;
	alarm.cal_alarm.datetime = date_time;
	alarm.cal_alarm.datetime.time.sec = 0;
	alarm.cal_alarm.option = CALENDAR_ALARM_MATCH_SEC;
	alarm.callback = calendar_callback;
	update_display(&watch, date_time);
	calendar_set_alarm(&CALENDAR_0, &alarm, &calendar_callback);
	watch_enable_tick(tick_callback);

	while (1) {
		sleep(2);
	}
	
	return 0;
}
