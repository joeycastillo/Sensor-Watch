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
#ifndef _WATCH_RTC_H_INCLUDED
#define _WATCH_RTC_H_INCLUDED
////< @file watch_rtc.h

#include "watch.h"
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

typedef union {
    struct {
        uint32_t second : 6;    // 0-59
        uint32_t minute : 6;    // 0-59
        uint32_t hour : 5;      // 0-23
        uint32_t day : 5;       // 1-31
        uint32_t month : 4;     // 1-12
        uint32_t year : 6;      // 0-63 (representing 2020-2083)
    } unit;
    uint32_t reg;               // the bit-packed value as expected by the RTC peripheral's CLOCK register.
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
bool _watch_rtc_is_enabled(void);

/** @brief Sets the date and time.
  * @param date_time The date and time you wish to set, with a year value from 0-63 representing 2020-2083.
  * @note The SAM L22 stores the year as six bits representing a value from 0 to 63. It treats this as a year
  *       offset from a reference year, which must be a leap year. Since 2020 was a leap year, and it allows
  *       useful dates through 2083, it is assumed that watch apps will use 2020 as the reference year; thus
  *       1 means 2021, 2 means 2022, etc. **You will be responsible for handling this offset in your code**,
  *       if the calendar year is needed for timestamp calculation logic or display purposes.
  */
void watch_rtc_set_date_time(watch_date_time date_time);

/** @brief Returns the date and time.
  * @return A watch_date_time with the current date and time, with a year value from 0-63 representing 2020-2083.
  * @see watch_rtc_set_date_time for notes about how the year is stored.
  */
watch_date_time watch_rtc_get_date_time(void);

/** @brief Registers an alarm callback that will be called when the RTC time matches the target time, as masked
  *        by the provided mask.
  * @param callback The function you wish to have called when the alarm fires. If this value is NULL, the alarm
  *                 interrupt will still be enabled, but no callback function will be called.
  * @param alarm_time The time that you wish to match. The date is currently ignored.
  * @param mask One of the values in watch_rtc_alarm_match indicating which values to check.
  * @details The alarm interrupt is a versatile tool for scheduling events in the future, especially since it can
  *          wake the device from all sleep modes. The key to its versatility is the mask parameter.
  *          Suppose we set an alarm for midnight, 00:00:00.
  *           * if mask is ALARM_MATCH_SS, the alarm will fire every minute when the clock ticks to seconds == 0.
  *           * with ALARM_MATCH_MMSS, the alarm will once an hour, at the top of each hour.
  *           * with ALARM_MATCH_HHMMSS, the alarm will fire at midnight every day.
  *          In theory the SAM L22's alarm function can match on days, months and even years, but I have not had
  *          success with this yet; as such, I am omitting these options for now.
  */
void watch_rtc_register_alarm_callback(ext_irq_cb_t callback, watch_date_time alarm_time, watch_rtc_alarm_match mask);

/** @brief Disables the alarm callback.
  */
void watch_rtc_disable_alarm_callback(void);

/** @brief Registers a "tick" callback that will be called once per second.
  * @param callback The function you wish to have called when the clock ticks. If you pass in NULL, the tick
  *                 interrupt will still be enabled, but no callback function will be called.
  * @note this is equivalent to calling watch_rtc_register_periodic_callback with a frequency of 1. It can be
  *       disabled with either watch_rtc_disable_tick_callback() or watch_rtc_disable_periodic_callback(1),
  *       and will also be disabled when watch_rtc_disable_all_periodic_callbacks is called.
  */
void watch_rtc_register_tick_callback(ext_irq_cb_t callback);

/** @brief Disables the tick callback for the given period.
  */
void watch_rtc_disable_tick_callback(void);

/** @brief Registers a callback that will be called at a configurable period.
  * @param callback The function you wish to have called at the specified period. If you pass in NULL, the periodic
  *                 interrupt will still be enabled, but no callback function will be called.
  * @param frequency The frequency of the tick in Hz. **Must be a power of 2**, from 1 to 128 inclusive.
  * @note A 1 Hz tick (@see watch_rtc_register_tick_callback) is suitable for most applications, in that it gives you a
  *       chance to update the display once a second — an ideal update rate for a watch! If however you are displaying
  *       a value (such as an accelerometer output) that updates more frequently than once per second, you may want to
  *       tick at 16 or 32 Hz to update the screen more quickly. Just remember that the more frequent the tick, the more
  *       power your app will consume. Ideally you should enable the fast tick only when the user requires it (i.e. in
  *       response to an input event), and move back to the slow tick after some time.
  *
  *       Also note that the RTC peripheral does not have sub-second resolution, so even if you set a 2 or 4 Hz interval,
  *       the system will not have any way of telling you where you are within a given second; watch_rtc_get_date_time
  *       will return the exact same timestamp until the second ticks over.
  */
void watch_rtc_register_periodic_callback(ext_irq_cb_t callback, uint8_t frequency);

/** @brief Disables the tick callback for the given period.
  * @param frequency The frequency of the tick you wish to disable, in Hz. **Must be a power of 2**, from 1 to 128.
  */
void watch_rtc_disable_periodic_callback(uint8_t frequency);

/** @brief Disables tick callbacks for the given periods (as a bitmask).
  * @param mask The frequencies of tick callbacks you wish to disable, in Hz.
  * The 128 Hz callback is 0b1, the 64 Hz callback is 0b10, the 32 Hz callback is 0b100, etc.
  */
void watch_rtc_disable_matching_periodic_callbacks(uint8_t mask);

/** @brief Disables all periodic callbacks, including the once-per-second tick callback.
  */
void watch_rtc_disable_all_periodic_callbacks(void);

/** @brief Enable/disable RTC while in-flight. This is quite dangerous operation, so we repeat writing register twice.
 * Used when temporarily pausing RTC when adjusting subsecond, which are not accessible otherwise.
  */
void watch_rtc_enable(bool en);

/** @brief Adjusts frequency correction in single register write. Not waiting for syncronisation to save power - if you won't write new
 * correction value in the same ~millisecond - will not cause issue.
  */
void watch_rtc_freqcorr_write(int16_t value, int16_t sign);

/// @}
#endif
