/*
 * mars_clock.c
 *
 * Created: 4/29/2021 11:36:26 PM
 *  Author: joeycastillo
 */ 
#include <stdio.h>
#include <math.h>
#include "mars_clock.h"

// note: mars time not working, committing just the earth clock.

void update_display(Watch *watch, struct calendar_date_time date_time) {
	char buf[6];
	sprintf(&buf[0], "TE  %02d%02d%02d", date_time.time.hour, date_time.time.min, date_time.time.sec);
	watch_display_string(watch, buf, 0);
}
