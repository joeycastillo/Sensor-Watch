#include <atmel_start.h>
#include <hpl_sleep.h>
#include "watch-library/watch.h"
#include "mars_clock.h"

bool local = true;

void calendar_callback(struct calendar_descriptor *const calendar) {
}

static void mode_callback() {
	local = !local;
}

static void light_callback() {
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);
	date_time.time.min = (date_time.time.min + 1) % 60;
	watch_set_date_time(date_time);
}

static void alarm_callback() {
	struct calendar_date_time date_time;
	calendar_get_date_time(&CALENDAR_0, &date_time);
	date_time.time.sec = 0;
	watch_set_date_time(date_time);
}

static void tick_callback() {
}

int main(void)
{
	atmel_start_init();

	watch_init();

	watch_enable_date_time();
	struct calendar_date_time date_time;
	date_time.date.year = 2021;
	date_time.date.month = 5;
	date_time.date.day = 8;
	date_time.time.hour = 19;
	date_time.time.min = 40;
	date_time.time.sec = 0;
	watch_set_date_time(date_time);
	update_display(date_time, local);
	watch_enable_tick(tick_callback);

	watch_enable_led();

	watch_enable_buttons();
	watch_register_button_callback(BTN_MODE, &mode_callback);
	watch_register_button_callback(BTN_ALARM, &alarm_callback);
	watch_register_button_callback(BTN_LIGHT, &light_callback);

	watch_enable_display();
	watch_display_pixel(1, 16);

	while (1) {
		if (watch_can_enter_standby()) {
			sleep(4);
		} else {
			sleep(2);
		}
		struct calendar_date_time date_time;
		calendar_get_date_time(&CALENDAR_0, &date_time);
		update_display(date_time, local);
	}
	
	return 0;
}
