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
/** @brief Called by main.c to check if the RTC is enabled.
  * You may call this function, but outside of app_init, it sbould always return true.
  */
bool _watch_rtc_is_enabled();

/** @brief Sets the system date and time.
  * @param date_time A struct representing the date and time you wish to set.
  */
void watch_set_date_time(struct calendar_date_time date_time);

/** @brief Returns the system date and time in the provided struct.
  * @param date_time A pointer to a calendar_date_time struct.
                     It will be populated with the correct date and time on return.
  */
void watch_get_date_time(struct calendar_date_time *date_time);

/** @brief Registers a "tick" callback that will be called once per second.
  * @param callback The function you wish to have called when the clock ticks.
  */
void watch_register_tick_callback(ext_irq_cb_t callback);
/// @}
