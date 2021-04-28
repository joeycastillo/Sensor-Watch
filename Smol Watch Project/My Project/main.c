#include <atmel_start.h>
#include "watch-library/watch.h"

int main(void)
{
	atmel_start_init();
	
	Watch watch;
	struct calendar_date_time date_time;
	date_time.date.year = 2021;
	date_time.date.month = 4;
	date_time.date.day = 25;
	date_time.time.hour = 4;
	date_time.time.min = 0;
	date_time.time.sec = 0;

	watch_init(&watch);

	watch_enable_led(&watch);

	watch_enable_date_time(&watch);
	watch_set_date_time(date_time);

	watch_enable_digital_output(A0);
	gpio_set_pin_level(A0, true);

	watch_enable_display(&watch);
/*	
	watch_enable_i2c(&watch);
	uint8_t chipID = 0;
	uint8_t ChipIdRegister = 0xD0;
	watch_i2c_send(0x77, &ChipIdRegister, 1);
	watch_i2c_receive(0x77, &chipID, 1);
	if (chipID == 0x60) {
		watch_set_led_green();
	}
*/
	uint8_t last = date_time.time.sec;
	
	while (1) {
		watch_get_date_time(&date_time);
		if (date_time.time.sec != last) {
			last = date_time.time.sec;
			if (last % 2 == 0) {
				watch_set_led_color(50, 0);
				watch_display_string(&watch, "0123456789", 0);
			} else {
				watch_set_led_color(0, 50);
				watch_display_string(&watch, "01", 0);
				watch_display_string(&watch, "23", 2);
				watch_display_string(&watch, "456789", 4);
			}
		}
	}
	
	return 0;
}
