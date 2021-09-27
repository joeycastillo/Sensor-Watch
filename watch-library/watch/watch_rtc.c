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

ext_irq_cb_t tick_callback;
ext_irq_cb_t alarm_callback;
ext_irq_cb_t btn_alarm_callback;
ext_irq_cb_t a2_callback;
ext_irq_cb_t a4_callback;

bool _watch_rtc_is_enabled() {
    return RTC->MODE2.CTRLA.bit.ENABLE;
}

void _sync_rtc() {
    while (RTC->MODE2.SYNCBUSY.reg);
}

void _watch_rtc_init() {
    MCLK->APBAMASK.reg |= MCLK_APBAMASK_RTC;

    if (_watch_rtc_is_enabled()) return; // don't reset the RTC if it's already set up.

    RTC->MODE2.CTRLA.bit.ENABLE = 0;
    _sync_rtc();

    RTC->MODE2.CTRLA.bit.SWRST = 1;
    _sync_rtc();

    RTC->MODE2.CTRLA.bit.MODE = RTC_MODE2_CTRLA_MODE_CLOCK_Val;
    RTC->MODE2.CTRLA.bit.PRESCALER = RTC_MODE2_CTRLA_PRESCALER_DIV1024_Val;
    RTC->MODE2.CTRLA.bit.CLOCKSYNC = 1;
    RTC->MODE2.CTRLA.bit.ENABLE = 1;
    _sync_rtc();
}

void watch_rtc_set_date_time(watch_date_time date_time) {
    RTC_MODE2_CLOCK_Type val;

    val.bit.SECOND = date_time.second;
    val.bit.MINUTE = date_time.minute;
    val.bit.HOUR = date_time.hour;
    val.bit.DAY = date_time.day;
    val.bit.MONTH = date_time.month;
    val.bit.YEAR = (uint8_t)(date_time.year - WATCH_RTC_REFERENCE_YEAR);

    RTC->MODE2.CLOCK.reg = val.reg;
    _sync_rtc();
}

watch_date_time watch_rtc_get_date_time() {
    watch_date_time retval;

    _sync_rtc();
    RTC_MODE2_CLOCK_Type val = RTC->MODE2.CLOCK;

    retval.year = val.bit.YEAR + WATCH_RTC_REFERENCE_YEAR;
    retval.month = val.bit.MONTH;
    retval.day = val.bit.DAY;
    retval.hour = val.bit.HOUR;
    retval.minute = val.bit.MINUTE;
    retval.second = val.bit.SECOND;

    return retval;
}

void watch_register_tick_callback(ext_irq_cb_t callback) {
    tick_callback = callback;
    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);
    RTC->MODE2.INTENSET.reg = RTC_MODE2_INTENSET_PER7;
}

void watch_disable_tick_callback() {
    RTC->MODE2.INTENCLR.reg = RTC_MODE2_INTENCLR_PER7;
}

void watch_rtc_register_alarm_callback(ext_irq_cb_t callback, watch_date_time alarm_time, watch_rtc_alarm_match mask) {
    RTC->MODE2.Mode2Alarm[0].ALARM.bit.SECOND = alarm_time.second;
    RTC->MODE2.Mode2Alarm[0].ALARM.bit.MINUTE = alarm_time.minute;
    RTC->MODE2.Mode2Alarm[0].ALARM.bit.HOUR = alarm_time.hour;
    RTC->MODE2.Mode2Alarm[0].ALARM.bit.DAY = alarm_time.day;
    RTC->MODE2.Mode2Alarm[0].ALARM.bit.MONTH = alarm_time.month;
    RTC->MODE2.Mode2Alarm[0].ALARM.bit.YEAR = (uint8_t)(alarm_time.year - WATCH_RTC_REFERENCE_YEAR);
    RTC->MODE2.Mode2Alarm[0].MASK.reg = mask;

    RTC->MODE2.INTENSET.reg = RTC_MODE2_INTENSET_ALARM0;
    alarm_callback = callback;
    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);
    RTC->MODE2.INTENSET.reg = RTC_MODE2_INTENSET_ALARM0;
}

void watch_rtc_disable_alarm_callback() {
    RTC->MODE2.INTENCLR.reg = RTC_MODE2_INTENCLR_ALARM0;
}

void RTC_Handler(void) {
    uint16_t interrupt_status = RTC->MODE2.INTFLAG.reg;
    uint16_t interrupt_enabled = RTC->MODE2.INTENSET.reg;

    if ((interrupt_status & interrupt_enabled) & RTC_MODE2_INTFLAG_ALARM0) {
        if (alarm_callback != NULL) {
            alarm_callback();
        }
        RTC->MODE2.INTFLAG.reg = RTC_MODE2_INTFLAG_ALARM0;
    } else if ((interrupt_status & interrupt_enabled) & RTC_MODE2_INTFLAG_PER7) {
        if (tick_callback != NULL) {
            tick_callback();
        }
        RTC->MODE2.INTFLAG.reg = RTC_MODE2_INTFLAG_PER7;
    } else if ((interrupt_status & interrupt_enabled) & RTC_MODE2_INTFLAG_TAMPER) {
        uint8_t reason = RTC->MODE2.TAMPID.reg;
        if (reason & RTC_TAMPID_TAMPID2) {
            if (btn_alarm_callback != NULL) btn_alarm_callback();
        } else if (reason & RTC_TAMPID_TAMPID1) {
            if (a2_callback != NULL) a2_callback();
        } else if (reason & RTC_TAMPID_TAMPID0) {
            if (a4_callback != NULL) a4_callback();
        }
        RTC->MODE2.TAMPID.reg = reason;
        RTC->MODE2.INTFLAG.reg = RTC_MODE2_INTFLAG_TAMPER;
    }
}

///////////////////////
// Deprecated functions

void watch_set_date_time(struct calendar_date_time date_time) {
    RTC_MODE2_CLOCK_Type val;

    val.bit.SECOND = date_time.time.sec;
    val.bit.MINUTE = date_time.time.min;
    val.bit.HOUR = date_time.time.hour;
    val.bit.DAY = date_time.date.day;
    val.bit.MONTH = date_time.date.month;
    val.bit.YEAR = (uint8_t)(date_time.date.year - WATCH_RTC_REFERENCE_YEAR);

    RTC->MODE2.CLOCK.reg = val.reg;

    _sync_rtc();
}

void watch_get_date_time(struct calendar_date_time *date_time) {
    _sync_rtc();
    RTC_MODE2_CLOCK_Type val = RTC->MODE2.CLOCK;

    date_time->time.sec = val.bit.SECOND;
    date_time->time.min = val.bit.MINUTE;
    date_time->time.hour = val.bit.HOUR;
    date_time->date.day = val.bit.DAY;
    date_time->date.month = val.bit.MONTH;
    date_time->date.year = val.bit.YEAR + WATCH_RTC_REFERENCE_YEAR;
}
