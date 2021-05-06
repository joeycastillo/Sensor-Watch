/*
 * mars_clock.c
 *
 * Created: 4/29/2021 11:36:26 PM
 *  Author: joeycastillo
 */ 
#include <stdio.h>
#include <math.h>
#include "mars_clock.h"

static unsigned short days[4][12] =
{
	{   0,  31,  60,  91, 121, 152, 182, 213, 244, 274, 305, 335},
	{ 366, 397, 425, 456, 486, 517, 547, 578, 609, 639, 670, 700},
	{ 731, 762, 790, 821, 851, 882, 912, 943, 974,1004,1035,1065},
	{1096,1127,1155,1186,1216,1247,1277,1308,1339,1369,1400,1430},
};

unsigned int date_time_to_epoch(struct calendar_date_time date_time)
{
	unsigned int second = date_time.time.sec;
	unsigned int minute = date_time.time.min;
	unsigned int hour   = date_time.time.hour;
	unsigned int day    = date_time.date.day-1;       // 0-30
	unsigned int month  = date_time.date.month-1;     // 0-11
	unsigned int year   = date_time.date.year - 1970; // 0-99
	return (((year/4*(365*4+1)+days[year%4][month]+day)*24+hour)*60+minute)*60+second;
}

void epoch_to_date_time(struct calendar_date_time date_time, unsigned int epoch)
{
	date_time.time.sec = epoch % 60;
	epoch /= 60;
	date_time.time.min = epoch % 60;
	epoch /= 60;
	date_time.time.hour   = epoch % 24;
	epoch /= 24;

	unsigned int years = epoch/(365*4+1)*4;
	epoch %= 365*4+1;

	unsigned int year;
	for (year=3; year>0; year--)
	{
		if (epoch >= days[year][0])
		break;
	}

	unsigned int month;
	for (month=11; month>0; month--)
	{
		if (epoch >= days[year][month])
		break;
	}

	date_time.date.year  = years+year;
	date_time.date.month = month+1;
	date_time.date.day   = epoch-days[year][month]+1;
}

void h_to_hms(struct calendar_date_time *date_time, double h) {
	unsigned int seconds = (unsigned int)(h * 3600.0);
	date_time->time.hour = seconds / 3600;
	seconds = seconds % 3600;
	date_time->time.min = floor(seconds / 60);
	date_time->time.sec = round(seconds % 60);
}


void update_display(Watch *watch, struct calendar_date_time date_time, bool local) {
	char buf[6];
	if (local) {
		sprintf(&buf[0], "TE  %02d%02d%02d", date_time.time.hour, date_time.time.min, date_time.time.sec);
	} else {
		unsigned int now = date_time_to_epoch(date_time);
		double jdut = 2440587.5 + ((double)now / 86400.0);
		double jdtt = jdut + ((37.0 + 32.184) / 86400.0);
		double jd2k = jdtt - 2451545.0;
		double msd = ((jd2k - 4.5) / 1.0274912517) + 44796.0 - 0.0009626;
		double mtc = fmod(24 * msd, 24);
		struct calendar_date_time mars_time;
		h_to_hms(&mars_time, mtc);
		sprintf(&buf[0], "MA  %02d%02d%02d", mars_time.time.hour, mars_time.time.min, mars_time.time.sec);
	}
	watch_display_string(watch, buf, 0);
}
