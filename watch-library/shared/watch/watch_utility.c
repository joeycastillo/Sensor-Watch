/*
 * MIT License
 *
 * Copyright (c) 2021 Joey Castillo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <math.h>
#include "watch_utility.h"

const char * watch_utility_get_weekday(watch_date_time date_time) {
    static const char weekdays[7][3] = {"MO", "TU", "WE", "TH", "FR", "SA", "SU"};
    return weekdays[watch_utility_get_iso8601_weekday_number(date_time.unit.year + WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day) - 1];
}

// Per ISO8601 week starts on Monday with index 1
uint8_t watch_utility_get_iso8601_weekday_number(uint16_t year, uint8_t month, uint8_t day) {
    year -= WATCH_RTC_REFERENCE_YEAR;
    year += 20;
    if (month <= 2) {
        month += 12;
        year--;
    }
    return ((day + (13 * (month + 1) / 5) + year + (year / 4) + 5) % 7) + 1;
}

// this function is from the excellent musl c library
uint8_t watch_utility_get_weeknumber(uint16_t year, uint8_t month, uint8_t day) {
    uint8_t weekday;
    uint16_t days;

    if (use_iso_8601_weeknumber == 1) {
        weekday = ((watch_utility_get_iso8601_weekday_number(year, month, day) + 5) % 7) + 1;
    } else {
        weekday = watch_utility_get_iso8601_weekday_number(year, month, day) % 7;
    }
    days = watch_utility_days_since_new_year(year, month, day);

	int val = (days + 7U - (weekday+6U)%7) / 7;
	/* If 1 Jan is just 1-3 days past Monday,
	 * the previous week is also in this year. */
	if ((weekday + 371U - days - 2) % 7 <= 2)
		val++;
	if (!val) {
		val = 52;
		/* If 31 December of prev year a Thursday,
		 * or Friday of a leap year, then the
		 * prev year has 53 weeks. */
		int dec31 = (weekday + 7U - days - 1) % 7;
		if (dec31 == 4 || (dec31 == 5 && is_leap(year%400-1)))
			val++;
	} else if (val == 53) {
		/* If 1 January is not a Thursday, and not
		 * a Wednesday of a leap year, then this
		 * year has only 52 weeks. */
		int jan1 = (weekday + 371U - days) % 7;
		if (jan1 != 4 && (jan1 != 3 || !is_leap(year)))
			val = 1;
	}
	return val;
}

uint8_t is_leap(uint16_t y)
{
	y += 1900;
	return !(y%4) && ((y%100) || !(y%400));
}

uint16_t watch_utility_days_since_new_year(uint16_t year, uint8_t month, uint8_t day) {
    uint16_t DAYS_SO_FAR[] = {
        0,   // Jan
        31,  // Feb
        59,  // March
        90,  // April
        120, // May
        151, // June
        181, // July
        212, // August
        243, // September
        273, // October
        304, // November
        334  // December
    };

    return (is_leap(year) && (month > 2) ? 1 : 0) + DAYS_SO_FAR[month - 1] + day;
}

// Function taken from `src/time/__year_to_secs.c` of musl libc
// https://musl.libc.org
static uint32_t __year_to_secs(uint32_t year, int *is_leap)
{
	if (year-2ULL <= 136) {
		int y = year;
		int leaps = (y-68)>>2;
		if (!((y-68)&3)) {
			leaps--;
			if (is_leap) *is_leap = 1;
		} else if (is_leap) *is_leap = 0;
		return 31536000*(y-70) + 86400*leaps;
	}

	int cycles, centuries, leaps, rem;

	if (!is_leap) is_leap = &(int){0};
	cycles = (year-100) / 400;
	rem = (year-100) % 400;
	if (rem < 0) {
		cycles--;
		rem += 400;
	}
	if (!rem) {
		*is_leap = 1;
		centuries = 0;
		leaps = 0;
	} else {
		if (rem >= 200) {
			if (rem >= 300) centuries = 3, rem -= 300;
			else centuries = 2, rem -= 200;
		} else {
			if (rem >= 100) centuries = 1, rem -= 100;
			else centuries = 0;
		}
		if (!rem) {
			*is_leap = 0;
			leaps = 0;
		} else {
			leaps = rem / 4U;
			rem %= 4U;
			*is_leap = !rem;
		}
	}

	leaps += 97*cycles + 24*centuries - *is_leap;

	return (year-100) * 31536000LL + leaps * 86400LL + 946684800 + 86400;
}

// Function taken from `src/time/__month_to_secs.c` of musl libc
// https://musl.libc.org
static int __month_to_secs(int month, int is_leap)
{
	static const int secs_through_month[] = {
		0, 31*86400, 59*86400, 90*86400,
		120*86400, 151*86400, 181*86400, 212*86400,
		243*86400, 273*86400, 304*86400, 334*86400 };
	int t = secs_through_month[month];
	if (is_leap && month >= 2) t+=86400;
	return t;
}

// Function adapted from `src/time/__tm_to_secs.c` of musl libc
// https://musl.libc.org
uint32_t watch_utility_convert_to_unix_time(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, uint32_t utc_offset) {
    int is_leap;

    // POSIX tm struct starts year at 1900 and month at 0
    // https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/time.h.html 
    uint32_t timestamp = __year_to_secs(year - 1900, &is_leap);
    timestamp += __month_to_secs(month - 1, is_leap);

    // Regular conversion from musl libc
    timestamp += (day - 1) * 86400;
    timestamp += hour * 3600;
    timestamp += minute * 60;
    timestamp += second;
    timestamp -= utc_offset;

    return timestamp;
}

uint32_t watch_utility_date_time_to_unix_time(watch_date_time date_time, uint32_t utc_offset) {
    return watch_utility_convert_to_unix_time(date_time.unit.year + WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second, utc_offset);
}

#define LEAPOCH (946684800LL + 86400*(31+29))

#define DAYS_PER_400Y (365*400 + 97)
#define DAYS_PER_100Y (365*100 + 24)
#define DAYS_PER_4Y   (365*4   + 1)

watch_date_time watch_utility_date_time_from_unix_time(uint32_t timestamp, uint32_t utc_offset) {
    watch_date_time retval;
    retval.reg = 0;
    int32_t days, secs;
    int32_t remdays, remsecs, remyears;
    int32_t qc_cycles, c_cycles, q_cycles;
    int32_t years, months;
    int32_t wday, yday, leap;
    static const int8_t days_in_month[] = {31,30,31,30,31,31,30,31,30,31,31,29};
    timestamp += utc_offset;

    secs = timestamp - LEAPOCH;
    days = secs / 86400;
    remsecs = secs % 86400;
    if (remsecs < 0) {
        remsecs += 86400;
        days--;
    }

    wday = (3+days)%7;
    if (wday < 0) wday += 7;

    qc_cycles = (int)(days / DAYS_PER_400Y);
    remdays = days % DAYS_PER_400Y;
    if (remdays < 0) {
        remdays += DAYS_PER_400Y;
        qc_cycles--;
    }

    c_cycles = remdays / DAYS_PER_100Y;
    if (c_cycles == 4) c_cycles--;
    remdays -= c_cycles * DAYS_PER_100Y;

    q_cycles = remdays / DAYS_PER_4Y;
    if (q_cycles == 25) q_cycles--;
    remdays -= q_cycles * DAYS_PER_4Y;

    remyears = remdays / 365;
    if (remyears == 4) remyears--;
    remdays -= remyears * 365;

    leap = !remyears && (q_cycles || !c_cycles);
    yday = remdays + 31 + 28 + leap;
    if (yday >= 365+leap) yday -= 365+leap;

    years = remyears + 4*q_cycles + 100*c_cycles + 400*qc_cycles;

    for (months=0; days_in_month[months] <= remdays; months++)
        remdays -= days_in_month[months];

    years += 2000;

    months += 2;
    if (months >= 12) {
        months -=12;
        years++;
    }

    if (years < 2020 || years > 2083) return retval;
    retval.unit.year = years - WATCH_RTC_REFERENCE_YEAR;
    retval.unit.month = months + 1;
    retval.unit.day = remdays + 1;

    retval.unit.hour = remsecs / 3600;
    retval.unit.minute = remsecs / 60 % 60;
    retval.unit.second = remsecs % 60;

    return retval;
}

watch_date_time watch_utility_date_time_convert_zone(watch_date_time date_time, uint32_t origin_utc_offset, uint32_t destination_utc_offset) {
    uint32_t timestamp = watch_utility_date_time_to_unix_time(date_time, origin_utc_offset);
    return watch_utility_date_time_from_unix_time(timestamp, destination_utc_offset);
}

watch_duration_t watch_utility_seconds_to_duration(uint32_t seconds) {
    watch_duration_t retval;

    retval.seconds = (seconds % 60);
    retval.minutes = (seconds % 3600) / 60;
    retval.hours = (seconds % 86400) / 3600;
    retval.days = seconds / 86400;

    return retval;
}

bool watch_utility_convert_to_12_hour(watch_date_time *date_time) {
    bool is_pm = date_time->unit.hour > 11;
    date_time->unit.hour %= 12;
    if (date_time->unit.hour == 0) date_time->unit.hour = 12;
    return is_pm;
}

float watch_utility_thermistor_temperature(uint16_t value, bool highside, float b_coefficient, float nominal_temperature, float nominal_resistance, float series_resistance) {
    float reading = (float)value;

    if (highside) {
        reading = (1023.0 * series_resistance) / (reading / 64.0);
        reading -= series_resistance;
    } else {
        reading = series_resistance / (65535.0 / value - 1.0);
    }

    reading = reading / nominal_resistance;
    reading = log(reading);
    reading /= b_coefficient;
    reading += 1.0 / (nominal_temperature + 273.15);
    reading = 1.0 / reading;
    reading -= 273.15;

    return reading;
}

uint32_t watch_utility_offset_timestamp(uint32_t now, int8_t hours, int8_t minutes, int8_t seconds) {
    uint32_t new = now;
    new += hours * 60 * 60;
    new += minutes * 60;
    new += seconds;
    return new;
}
