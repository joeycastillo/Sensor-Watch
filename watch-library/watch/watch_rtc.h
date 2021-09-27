/*
 * MIT License
 *
 * Copyright (c) 2020 Joey Castillo
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
////< @file watch_rtc.h

#include "hpl_calendar.h"

/** @addtogroup rtc Real-Time Clock
  * @brief This section covers functions related to the SAM L22's real-time clock peripheral, including
  *        date, time and alarm functions.
  * @details The real-time clock is the only peripheral that main.c enables for you. It is the cornerstone
  *          of low power operation on the watch, and it is required for several key functions that we
  *          assume will be available, namely the wake from BACKUP mode and the callback on the ALARM button.
  *          It is also required for the operation of the 1 Hz tick interrupt, which you will most likely use
  *          to wake from STANDBY mode.
  */
/// @{

#define WATCH_RTC_REFERENCE_YEAR (2020)

typedef struct watch_date_time {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} watch_date_time;

typedef enum watch_rtc_alarm_match {
    ALARM_MATCH_DISABLED = 0,
    ALARM_MATCH_SS,
    ALARM_MATCH_MMSS,
    ALARM_MATCH_HHMMSS,
} watch_rtc_alarm_match;

/** @brief Called by main.c to check if the RTC is enabled.
  * You may call this function, but outside of app_init, it should always return true.
  */
bool _watch_rtc_is_enabled();

/** @brief Sets the date and time.
  * @param date_time The time you wish to set.
  * @note Internally, the SAM L22 stores the year as six bits representing a value from 0 to 63. It treats this
  *       as a year offset from a reference year, which must be a leap year. For now, this library uses 2020 as
  *       the reference year, so the range of valid values is 2020 to 2083.
  */
void watch_rtc_set_date_time(watch_date_time date_time);

/** @brief Returns the system date and time in the provided struct.
  * @return A watch_date_time with the current date and time.
  */
watch_date_time watch_rtc_get_date_time();

/** @brief Registers an alarm callback that will be called when the RTC time matches the target time, as masked
  *        by the provided mask.
  * @param callback The function you wish to have called when the alarm fires. If this value is NULL, the alarm
  *                 interrupt will still be enabled, but no callback function will be called.
  * @param alarm_time The time that you wish to match. The date is currently ignored.
  * @param mask One of the values in watch_rtc_alarm_match indicating which values to check.
  * @details The alarm interrupt is a versatile tool for scheduling events in the future, especially since it can
  *          wake the device from both shallow and deep sleep modes. The key to its versatility is the mask
  *          parameter. Suppose we set an alarm for midnight, 00:00:00.
  *           * if mask is ALARM_MATCH_SS, the alarm will fire every minute when the clock ticks to seconds == 0.
  *           * with ALARM_MATCH_MMSS, the alarm will once an hour, at the top of each hour.
  *           * with ALARM_MATCH_HHMMSS, the alarm will fire at midnight every day.
  *          In theory the SAM L22's alarm function can match on days, months and even years, but I have not had
  *          success with this yet; as such, I am omitting these options for now.
  */
void watch_rtc_register_alarm_callback(ext_irq_cb_t callback, watch_date_time alarm_time, watch_rtc_alarm_match mask);

/** @brief Disables the alarm callback.
  */
void watch_rtc_disable_alarm_callback();

/** @brief Registers a "tick" callback that will be called once per second.
  * @param callback The function you wish to have called when the clock ticks. If you pass in NULL, the tick
  *                 interrupt will still be enabled, but no callback function will be called.
  */
void watch_register_tick_callback(ext_irq_cb_t callback);

/** @brief Disables the tick callback.
  */
void watch_disable_tick_callback();

/** @brief Sets the system date and time.
  * @param date_time A struct representing the date and time you wish to set.
  */
__attribute__((deprecated("Use watch_rtc_set_date_time function instead")))
void watch_set_date_time(struct calendar_date_time date_time);

/** @brief Returns the system date and time in the provided struct.
  * @param date_time A pointer to a calendar_date_time struct. It will have with the correct date and time on return.
  */
__attribute__((deprecated("Use the watch_rtc_get_date_time function instead")))
void watch_get_date_time(struct calendar_date_time *date_time);

/// @}
