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

    printf("input: %d/%d/%d %d:%02d:%02d offset by %ld\n", year, month, day, hour, minute, second, utc_offset);

    uint32_t year_adj = year + 4800;
    uint32_t febs = year_adj - (month <= 2 ? 1 : 0);  /* Februaries since base. */
    uint32_t leap_days = 1 + (febs / 4) - (febs / 100) + (febs / 400);
    uint32_t days = 365 * year_adj + leap_days + DAYS_SO_FAR[month - 1] + day - 1;
    days -= 2472692;  /* Adjust to Unix epoch. */

    uint32_t timestamp = days * 86400;
    timestamp += hour * 3600;
    timestamp += minute * 60;
    timestamp += second;
    printf("timestamp was %ld.\ntimezone is %ld.\n", timestamp, utc_offset);
    timestamp -= utc_offset;
    printf("timestamp now %ld.\n\n", timestamp);

    return timestamp;
}

uint32_t watch_utility_date_time_to_unix_time(watch_date_time date_time, uint32_t utc_offset) {
    return watch_utility_convert_to_unix_time(date_time.unit.year + WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second, utc_offset);
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
