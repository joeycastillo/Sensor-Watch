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

#include "watch_rtc.h"

#include <emscripten.h>
#include <emscripten/html5.h>
#include <stdio.h>

static double time_offset = 0;
static long tick_callbacks[8];

ext_irq_cb_t alarm_callback;
ext_irq_cb_t btn_alarm_callback;
ext_irq_cb_t a2_callback;
ext_irq_cb_t a4_callback;

bool _watch_rtc_is_enabled(void) {
    return true;
}

void _watch_rtc_init(void) {
}

void watch_rtc_set_date_time(watch_date_time date_time) {
    time_offset = EM_ASM_DOUBLE({
        const year = 2020 + (($0 >> 26) & 0x3f);
        const month = ($0 >> 22) & 0xf;
        const day = ($0 >> 17) & 0x1f;
        const hour = ($0 >> 12) & 0x1f;
        const minute = ($0 >> 6) & 0x3f;
        const second = $0 & 0x3f;
        const date = new Date(year, month - 1, day, hour, minute, second);
        return date - Date.now();
    }, date_time.reg);
}

watch_date_time watch_rtc_get_date_time(void) {
    watch_date_time retval;
    retval.reg = EM_ASM_INT({
        const date = new Date(Date.now() + $0);
        return date.getSeconds() |
            (date.getMinutes() << 6) |
            (date.getHours() << 12) |
            (date.getDate() << 17) |
            ((date.getMonth() + 1) << 22) |
            ((date.getFullYear() - 2020) << 26);
    }, time_offset);

    return retval;
}

void watch_rtc_register_tick_callback(ext_irq_cb_t callback) {
    watch_rtc_register_periodic_callback(callback, 1);
}

void watch_rtc_disable_tick_callback(void) {
    watch_rtc_disable_periodic_callback(1);
}

static void call_callback(void *userData) {
    ext_irq_cb_t callback = userData;
    callback();

    void resume_main_loop(void);
    resume_main_loop();
}

void watch_rtc_register_periodic_callback(ext_irq_cb_t callback, uint8_t frequency) {
    // we told them, it has to be a power of 2.
    if (__builtin_popcount(frequency) != 1) return;

    // this left-justifies the period in a 32-bit integer.
    uint32_t tmp = frequency << 24;
    // now we can count the leading zeroes to get the value we need.
    // 0x01 (1 Hz) will have 7 leading zeros for PER7. 0xF0 (128 Hz) will have no leading zeroes for PER0.
    uint8_t per_n = __builtin_clz(tmp);

    // this also maps nicely to an index for our list of tick callbacks.
    double interval = 1000 / frequency; // in msec
    tick_callbacks[per_n] = emscripten_set_interval(call_callback, interval, (void *)callback);
}

void watch_rtc_disable_periodic_callback(uint8_t frequency) {
    if (__builtin_popcount(frequency) != 1) return;
    uint8_t per_n = __builtin_clz(frequency << 24);
    emscripten_clear_interval(tick_callbacks[per_n]);
    tick_callbacks[per_n] = 0;
}

void watch_rtc_disable_all_periodic_callbacks(void) {
    for (int i = 0; i < 8; i++) {
        if (tick_callbacks[i] != 0) {
            emscripten_clear_interval(tick_callbacks[i]);
            tick_callbacks[i] = 0;
        }
    }
}

void watch_rtc_register_alarm_callback(ext_irq_cb_t callback, watch_date_time alarm_time, watch_rtc_alarm_match mask) {
#if 0
    RTC->MODE2.Mode2Alarm[0].ALARM.reg = alarm_time.reg;
    RTC->MODE2.Mode2Alarm[0].MASK.reg = mask;
    RTC->MODE2.INTENSET.reg = RTC_MODE2_INTENSET_ALARM0;
    alarm_callback = callback;
    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);
    RTC->MODE2.INTENSET.reg = RTC_MODE2_INTENSET_ALARM0;
#endif
}

void watch_rtc_disable_alarm_callback(void) {
#if 0
    RTC->MODE2.INTENCLR.reg = RTC_MODE2_INTENCLR_ALARM0;
#endif
}

///////////////////////
// Deprecated functions

void watch_set_date_time(struct calendar_date_time date_time) {
#if 0
    RTC_MODE2_CLOCK_Type val;

    val.bit.SECOND = date_time.time.sec;
    val.bit.MINUTE = date_time.time.min;
    val.bit.HOUR = date_time.time.hour;
    val.bit.DAY = date_time.date.day;
    val.bit.MONTH = date_time.date.month;
    val.bit.YEAR = (uint8_t)(date_time.date.year - WATCH_RTC_REFERENCE_YEAR);

    RTC->MODE2.CLOCK.reg = val.reg;

    _sync_rtc();
#endif
}

void watch_get_date_time(struct calendar_date_time *date_time) {
#if 0
    _sync_rtc();
    RTC_MODE2_CLOCK_Type val = RTC->MODE2.CLOCK;

    date_time->time.sec = val.bit.SECOND;
    date_time->time.min = val.bit.MINUTE;
    date_time->time.hour = val.bit.HOUR;
    date_time->date.day = val.bit.DAY;
    date_time->date.month = val.bit.MONTH;
    date_time->date.year = val.bit.YEAR + WATCH_RTC_REFERENCE_YEAR;
#endif
}

void watch_register_tick_callback(ext_irq_cb_t callback) {
#if 0
    tick_callbacks[7] = callback;
    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);
    RTC->MODE2.INTENSET.reg = RTC_MODE2_INTENSET_PER7;
#endif
}
