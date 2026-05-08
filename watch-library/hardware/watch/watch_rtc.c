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

#include <limits.h>

#include "watch_utility.h"
#include "watch_deepsleep.h"
#include "watch_rtc.h"

ext_irq_cb_t tick_callbacks[8];
ext_irq_cb_t btn_alarm_callback;
ext_irq_cb_t a2_callback;
ext_irq_cb_t a4_callback;

static const int CLK_RTC_OSC_HZ = 1024;
static const int PRESCALER_SETTING = RTC_MODE2_CTRLA_PRESCALER_DIV4_Val;
static const int PRESCALER_DIV = 1 << (PRESCALER_SETTING - 1);
const int CLK_RTC_CNT_HZ = CLK_RTC_OSC_HZ / PRESCALER_DIV;

bool _watch_rtc_is_enabled(void) {
    return RTC->MODE0.CTRLA.bit.ENABLE;
}

static void _sync_rtc(void) {
    while (RTC->MODE0.SYNCBUSY.reg);
}

void _watch_rtc_init(void) {
    MCLK->APBAMASK.reg |= MCLK_APBAMASK_RTC;

    // TODO was this guarding some kind of reboot thing?
    //if (_watch_rtc_is_enabled()) return; // don't reset the RTC if it's already set up.

    RTC->MODE0.CTRLA.bit.ENABLE = 0;
    _sync_rtc();

    RTC->MODE0.CTRLA.bit.SWRST = 1;
    _sync_rtc();

    RTC->MODE0.CTRLA.bit.MODE = RTC_MODE0_CTRLA_MODE_COUNT32_Val;
    RTC->MODE0.CTRLA.bit.PRESCALER = PRESCALER_SETTING;
    RTC->MODE0.CTRLA.bit.COUNTSYNC = 1;
    RTC->MODE0.CTRLA.bit.ENABLE = 1;
    RTC->MODE0.INTENSET.reg = RTC_MODE0_INTENSET_OVF;
    _sync_rtc();
}

static const int TZ_OFFSET_DIVIDER = 15;  // i.e. the granularity of our TZ_OFFSET is in 15 minute intervals
// TODO Mark this as used in movement.h description
static const int TB_BKUP_REG = 7;

union time_backup {
    struct {
        int32_t tz_offset : 8;
        uint32_t offset : 24;
    } bit;

    uint32_t reg;
};

void watch_rtc_set_date_time(watch_date_time date_time) {
    union time_backup tb;
    tb.reg = watch_get_backup_data(TB_BKUP_REG);
    watch_rtc_set_unix_time(watch_utility_date_time_to_unix_time(date_time, tb.bit.tz_offset * TZ_OFFSET_DIVIDER));
}

void watch_rtc_set_unix_time_raw(uint64_t unix_time_raw) {
    union time_backup tb;
    tb.reg = watch_get_backup_data(TB_BKUP_REG);
    tb.bit.offset = (unix_time_raw >> 8) / CLK_RTC_CNT_HZ;
    watch_store_backup_data(tb.reg, TB_BKUP_REG);
    _sync_rtc();
    RTC->MODE0.COUNT.reg = unix_time_raw & ((1 << 8) * CLK_RTC_CNT_HZ - 1);
}

void watch_rtc_set_unix_time(uint32_t unix_time) {
    watch_rtc_set_unix_time_raw((uint64_t)unix_time * CLK_RTC_CNT_HZ);
}

void watch_rtc_set_tz_offset(uint32_t tz_offset) {
    union time_backup tb;
    tb.reg = watch_get_backup_data(TB_BKUP_REG);
    tb.bit.tz_offset = tz_offset / TZ_OFFSET_DIVIDER;
    watch_store_backup_data(tb.reg, TB_BKUP_REG);
}

uint32_t watch_rtc_get_unix_time(void) {
    union time_backup tb;
    tb.reg = watch_get_backup_data(TB_BKUP_REG);
    _sync_rtc();
    return (tb.bit.offset << 8) + RTC->MODE0.COUNT.reg / CLK_RTC_CNT_HZ;
}

uint64_t watch_rtc_get_unix_time_raw(void) {
    union time_backup tb;
    tb.reg = watch_get_backup_data(TB_BKUP_REG);
    _sync_rtc();
    return (uint64_t)(tb.bit.offset << 8) * CLK_RTC_CNT_HZ + RTC->MODE0.COUNT.reg;
}

watch_date_time watch_rtc_get_date_time(void) {
    union time_backup tb;
    tb.reg = watch_get_backup_data(TB_BKUP_REG);
    _sync_rtc();
    return watch_utility_date_time_from_unix_time((tb.bit.offset << 8) + RTC->MODE0.COUNT.reg / CLK_RTC_CNT_HZ, tb.bit.tz_offset * TZ_OFFSET_DIVIDER);
}

void watch_rtc_register_tick_callback(ext_irq_cb_t callback) {
    watch_rtc_register_periodic_callback(callback, 1);
}

void watch_rtc_disable_tick_callback(void) {
    watch_rtc_disable_periodic_callback(1);
}

void watch_rtc_register_periodic_callback(ext_irq_cb_t callback, uint8_t frequency) {
    // we told them, it has to be a power of 2.
    if (__builtin_popcount(frequency) != 1) return;

    // this left-justifies the period in a 32-bit integer.
    uint32_t tmp = (frequency & 0xFF) << 24;
    // now we can count the leading zeroes to get the value we need.
    // 0x01 (1 Hz) will have 7 leading zeros for PER7. 0xF0 (128 Hz) will have no leading zeroes for PER0.
    uint8_t per_n = __builtin_clz(tmp);

    // this also maps nicely to an index for our list of tick callbacks.
    tick_callbacks[per_n] = callback;

    NVIC_ClearPendingIRQ(RTC_IRQn);
    NVIC_EnableIRQ(RTC_IRQn);
    RTC->MODE0.INTENSET.reg = 1 << per_n;
}

void watch_rtc_disable_periodic_callback(uint8_t frequency) {
    if (__builtin_popcount(frequency) != 1) return;
    uint8_t per_n = __builtin_clz((frequency & 0xFF) << 24);
    RTC->MODE0.INTENCLR.reg = 1 << per_n;
}

void watch_rtc_disable_matching_periodic_callbacks(uint8_t mask) {
    RTC->MODE0.INTENCLR.reg = mask;
}

void watch_rtc_disable_all_periodic_callbacks(void) {
    watch_rtc_disable_matching_periodic_callbacks(0xFF);
}

void RTC_Handler(void) {
    uint16_t interrupt_status = RTC->MODE0.INTFLAG.reg;
    uint16_t interrupt_enabled = RTC->MODE0.INTENSET.reg;

    if ((interrupt_status & interrupt_enabled) & RTC_MODE0_INTFLAG_PER_Msk) {
        // handle the tick callback first, it's what we do the most.
        // start from PER7, the 1 Hz tick.
        for(int8_t i = 7; i >= 0; i--) {
            if ((interrupt_status & interrupt_enabled) & (1 << i)) {
                if (tick_callbacks[i] != NULL) {
                    tick_callbacks[i]();
                }
                RTC->MODE0.INTFLAG.reg = 1 << i;
//                break; Uncertain if this fix is requried. We were discussing in discord. Might slightly increase power consumption. 
            }
        }
    } else if ((interrupt_status & interrupt_enabled) & RTC_MODE0_INTFLAG_TAMPER) {
        // handle the extwake interrupts next.
        uint8_t reason = RTC->MODE0.TAMPID.reg;
        if (reason & RTC_TAMPID_TAMPID2) {
            if (btn_alarm_callback != NULL) btn_alarm_callback();
        } else if (reason & RTC_TAMPID_TAMPID1) {
            if (a2_callback != NULL) a2_callback();
        } else if (reason & RTC_TAMPID_TAMPID0) {
            if (a4_callback != NULL) a4_callback();
        }
        RTC->MODE0.TAMPID.reg = reason;
        RTC->MODE0.INTFLAG.reg = RTC_MODE0_INTFLAG_TAMPER;
    } else if ((interrupt_status & interrupt_enabled) & RTC_MODE0_INTFLAG_OVF) {
        // Why is this 'else if'? Is it impossible for two interrupts to trigger
        // at the same time?
        union time_backup tb;
        tb.reg = watch_get_backup_data(TB_BKUP_REG);
        tb.bit.offset += (UINT_MAX >> 8) / CLK_RTC_CNT_HZ + 1;
        watch_store_backup_data(tb.reg, TB_BKUP_REG);
        RTC->MODE0.INTFLAG.reg = RTC_MODE0_INTFLAG_OVF;
    }
}

void watch_rtc_enable(bool en)
{
    // Writing it twice - as it's quite dangerous operation.
    // If write fails - we might hang with RTC off, which means no recovery possible
    while (RTC->MODE0.SYNCBUSY.reg);
    RTC->MODE0.CTRLA.bit.ENABLE = en ? 1 : 0;
    while (RTC->MODE0.SYNCBUSY.reg);
    RTC->MODE0.CTRLA.bit.ENABLE = en ? 1 : 0;
    while (RTC->MODE0.SYNCBUSY.reg);
}

void watch_rtc_freqcorr_write(int16_t value, int16_t sign)
{
    RTC_FREQCORR_Type data;

    data.bit.VALUE = value;
    data.bit.SIGN = sign;

    RTC->MODE0.FREQCORR.reg = data.reg; // Setting correction in single write operation

    // We do not sycnronize. We are not in a hurry
}

