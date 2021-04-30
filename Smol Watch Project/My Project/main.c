#include <atmel_start.h>
#include <hpl_sleep.h>
#include "watch-library/watch.h"
#include "mars_clock.h"

Watch watch;
bool local = true;

void calendar_callback(struct calendar_descriptor *const calendar) {
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);

	update_display(&watch, date_time, true);
/*
	if (date_time.time.min % 2 == 0) {
		watch_set_led_color(50, 0);
	} else {
		watch_set_led_color(0, 50);
	}
*/
}

static void mode_callback() {
//	local = !local;
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);
	update_display(&watch, date_time, local);
}

int main(void)
{
	atmel_start_init();
	
	watch_init(&watch);

//	watch_enable_led(&watch);

	watch_enable_display(&watch);
	watch_display_pixel(&watch, 1, 16);

	watch_enable_interrupts(&watch);
	watch_register_interrupt_callback(&watch, BTN_MODE, &mode_callback);

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
	update_display(&watch, date_time, local);
	calendar_set_alarm(&CALENDAR_0, &alarm, &calendar_callback);

	while (1) {
		//sleep(4);
	}
	
	return 0;
}
