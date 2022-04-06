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
    static const char weekdays[7][3] = {"SA", "SU", "MO", "TU", "WE", "TH", "FR"};
    date_time.unit.year += 20;
    if (date_time.unit.month <= 2) {
        date_time.unit.month += 12;
        date_time.unit.year--;
    }
    return weekdays[(date_time.unit.day + 13 * (date_time.unit.month + 1) / 5 + date_time.unit.year + date_time.unit.year / 4 + 525) % 7];
}

uint32_t watch_utility_convert_to_unix_time(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, uint32_t utc_offset) {
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

    uint32_t year_adj = year + 4800;
    uint32_t febs = year_adj - (month <= 2 ? 1 : 0);  /* Februaries since base. */
    uint32_t leap_days = 1 + (febs / 4) - (febs / 100) + (febs / 400);
    uint32_t days = 365 * year_adj + leap_days + DAYS_SO_FAR[month - 1] + day - 1;
    days -= 2472692;  /* Adjust to Unix epoch. */

    uint32_t timestamp = days * 86400;
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
