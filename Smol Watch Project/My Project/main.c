#include <atmel_start.h>
#include <hpl_sleep.h>
#include "watch-library/watch.h"
#include "mars_clock.h"

Watch watch;
bool local = true;

void calendar_callback(struct calendar_descriptor *const calendar) {
}

static void mode_callback() {
	local = !local;
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);
	update_display(&watch, date_time, local);
}

static void light_callback() {
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);
	date_time.time.min = (date_time.time.min + 1) % 60;
	watch_set_date_time(date_time);
	update_display(&watch, date_time, local);
}

static void alarm_callback() {
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);
	date_time.time.sec = 0;
	watch_set_date_time(date_time);
	update_display(&watch, date_time, local);
}

static void tick_callback() {
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);
	update_display(&watch, date_time, local);
}

int main(void)
{
	atmel_start_init();

	gpio_set_pin_level(RED, false);
	gpio_set_pin_direction(RED, GPIO_DIRECTION_OUT);
	gpio_set_pin_function(RED, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_level(GREEN, false);
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
	date_time.date.month = 5;
	date_time.date.day = 6;
	date_time.time.hour = 23;
	date_time.time.min = 30;
	date_time.time.sec = 0;
	watch_set_date_time(date_time);
/*	struct calendar_alarm alarm;
	alarm.cal_alarm.mode = REPEAT;
	alarm.cal_alarm.datetime = date_time;
	alarm.cal_alarm.datetime.time.sec = 0;
	alarm.cal_alarm.option = CALENDAR_ALARM_MATCH_SEC;
	alarm.callback = calendar_callback;
	calendar_set_alarm(&CALENDAR_0, &alarm, &calendar_callback);
*/
	update_display(&watch, date_time, local);
	watch_enable_tick(tick_callback);

	while (1) {
		sleep(4);
	}
	
	return 0;
}
