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

#ifndef _WATCH_UTILITY_H_INCLUDED
#define _WATCH_UTILITY_H_INCLUDED
////< @file watch_utility.h

/*
 * Define use_iso_8601_weeknumber as 1 to let weeknumbers start on Monday, 0 to start on Sunday.
 */
#define use_iso_8601_weeknumber 0

#include "watch.h"

/** @addtogroup utility Utility Functions
  * @brief This section covers various useful functions that don't fit anywhere else.
  **/
/// @{

typedef struct {
    uint8_t seconds;  // 0-59
    uint8_t minutes;  // 0-59
    uint8_t hours;    // 0-23
    uint32_t days;    // 0-4294967295
} watch_duration_t;

/** @brief Returns a two-letter weekday for the given timestamp, suitable for display
  *        in positions 0-1 of the watch face
  * @param date_time The watch_date_time whose weekday you want.
  */
const char * watch_utility_get_weekday(watch_date_time date_time);

/** @brief Returns a number between 1-7 representing the weekday according to ISO8601 : week starts on Monday and has index 1, Sunday has index 7
 * @param year The year of the date
 * @param month The month of the date (1-12)
 * @param day The day of the date (1-31)
 */
uint8_t watch_utility_get_iso8601_weekday_number(uint16_t year, uint8_t month, uint8_t day);


/** @brief Returns a number between 1-53 representing the weeknumber according to ISO8601 : First week of the year always contains Thursday. If it overlaps on previous year, current year has 53 weeks
 * @param year The year of the date
 * @param month The month of the date (1-12)
 * @param day The day of the date (1-31)
 */
uint8_t watch_utility_get_weeknumber(uint16_t year, uint8_t month, uint8_t day);

/** @brief Returns a number between 1-366 representing the elapsed days since January 1st the same year.
 * @param year The year of the date
 * @param month The month of the date (1-12)
 * @param day The day of the date (1-31)
 */
uint16_t watch_utility_days_since_new_year(uint16_t year, uint8_t month, uint8_t day);

/** @brief Returns 1 if year is leap and 0 otherwise
 * @param year The year (ex. 2022)
 */
uint8_t is_leap(uint16_t year);

/** @brief Returns the UNIX time (seconds since 1970) for a given date/time in UTC.
  * @param date_time The watch_date_time that you wish to convert.
  * @param year The year of the date you wish to convert.
  * @param month The month of the date you wish to convert.
  * @param day The day of the date you wish to convert.
  * @param hour The hour of the date you wish to convert.
  * @param minute The minute of the date you wish to convert.
  * @param second The second of the date you wish to convert.
  * @param utc_offset The number of seconds that date_time is offset from UTC, or 0 if the time is UTC.
  * @return A UNIX timestamp for the given date/time and UTC offset.
  * @note Implemented by Wesley Ellis (tahnok) and based on BSD-licensed code by Josh Haberman:
  *       https://blog.reverberate.org/2020/05/12/optimizing-date-algorithms.html
  */
uint32_t watch_utility_convert_to_unix_time(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, uint32_t utc_offset);

/** @brief Returns the UNIX time (seconds since 1970) for a given watch_date_time struct.
  * @param date_time The watch_date_time that you wish to convert.
  * @param utc_offset The number of seconds that date_time is offset from UTC, or 0 if the time is UTC.
  * @return A UNIX timestamp for the given watch_date_time and UTC offset.
  */
uint32_t watch_utility_date_time_to_unix_time(watch_date_time date_time, uint32_t utc_offset);

/** @brief Converts a duration in seconds to a watch_duration_t struct.
  * @param seconds A positive number of seconds that you wish to convert to a formatted duration.
  * @return A populated struct with the number of days, hours, minutes and seconds elapsed.
  */
watch_duration_t watch_utility_seconds_to_duration(uint32_t seconds);

/** @brief Returns a watch_date_time struct for a given UNIX time and UTC offset.
  * @param timestamp The UNIX timestamp that you wish to convert.
  * @param utc_offset The number of seconds that you wish date_time to be offset from UTC.
  * @return A watch_date_time for the given UNIX timestamp and UTC offset, or if outside the range that
  *         watch_date_time can represent, a watch_date_time with all fields set to 0.
  * @note Adapted from MIT-licensed code from musl, Copyright © 2005-2014 Rich Felker, et al.:
  *       https://github.com/esmil/musl/blob/1cc81f5cb0df2b66a795ff0c26d7bbc4d16e13c6/src/time/__secs_to_tm.c
  */
watch_date_time watch_utility_date_time_from_unix_time(uint32_t timestamp, uint32_t utc_offset);

/** @brief Converts a watch_date_time for 12-hour display.
  * @param date_time A pointer to the watch_date_time that you wish to convert for display. Note that this
  *                  function will OVERWRITE the original date/time, rendering it invalid for date/time
  *                  calculations. Midnight (hour 0) will become 12, and hours in the afternoon will wrap
  *                  back around to values from 1-11.
  * @return True if the value is in the afternoon. You can use this value to determine whether to set the
  *         PM indicator on the LCD.
  * @note This function sort of abuses the watch_date_time struct; the date/time that results from calling
  *       this function is clamped to the hours of 1:00:00 AM through 12:59:59 PM. It no longer reflects a
  *       valid watch_date_time for writing to an RTC register.
  */
bool watch_utility_convert_to_12_hour(watch_date_time *date_time);

/** @brief Converts a time from a given time zone to another time zone.
  * @param date_time The watch_date_time that you wish to convert
  * @param origin_utc_offset The number of seconds from UTC in the origin time zone
  * @param destination_utc_offset The number of seconds from UTC in the destination time zone
  * @return A watch_date_time for the given UNIX timestamp and UTC offset, or if outside the range that
  *         watch_date_time can represent, a watch_date_time with all fields set to 0.
  * @note Adapted from MIT-licensed code from musl, Copyright © 2005-2014 Rich Felker, et al.:
  *       https://github.com/esmil/musl/blob/1cc81f5cb0df2b66a795ff0c26d7bbc4d16e13c6/src/time/__secs_to_tm.c
  */
watch_date_time watch_utility_date_time_convert_zone(watch_date_time date_time, uint32_t origin_utc_offset, uint32_t destination_utc_offset);

/** @brief Returns a temperature in degrees Celsius for a given thermistor voltage divider circuit.
  * @param value The raw analog reading from the thermistor pin (0-65535)
  * @param highside True if the thermistor is connected to VCC and the series resistor is connected
  *                 to GND; false if the thermistor is connected to GND and the series resistor is
  *                 connected to VCC.
  * @param b_coefficient From your thermistor's data sheet, the B25/85 coefficient. A typical value
  *                      will be between 2000 and 5000.
  * @param nominal_temperature From your thermistor's data sheet, the temperature (in Celsius) at
  *                            which the thermistor's resistance is at its nominal value.
  * @param nominal_resistance The thermistor's resistance at the nominal temperature.
  * @param series_resistance The value of the other resistor in the voltage divider.
  * @note Ported from Adafruit's MIT-licensed CircuitPython thermistor code, (c) 2017 Scott Shawcroft:
  *       https://github.com/adafruit/Adafruit_CircuitPython_Thermistor/blob/main/adafruit_thermistor.py
  */
float watch_utility_thermistor_temperature(uint16_t value, bool highside, float b_coefficient, float nominal_temperature, float nominal_resistance, float series_resistance);

/** @brief Offset a timestamp by a given amount
 * @param now Timestamp to offset from
 * @param hours Number of hours to offset
 * @param minutes Nmber of minutes to offset
 * @param seconds Number of secodns to offset
 */
uint32_t watch_utility_offset_timestamp(uint32_t now, int8_t hours, int8_t minutes, int8_t seconds);

#endif
