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

static void extwake_callback(uint8_t reason);
ext_irq_cb_t btn_alarm_callback;
ext_irq_cb_t a2_callback;
ext_irq_cb_t a4_callback;

 static void extwake_callback(uint8_t reason) {
    if (reason & RTC_TAMPID_TAMPID2) {
        if (btn_alarm_callback != NULL) btn_alarm_callback();
    } else if (reason & RTC_TAMPID_TAMPID1) {
        if (a2_callback != NULL) a2_callback();
    } else if (reason & RTC_TAMPID_TAMPID0) {
        if (a4_callback != NULL) a4_callback();
    }
}

void watch_register_extwake_callback(uint8_t pin, ext_irq_cb_t callback, bool level) {
    uint32_t pinmux;
    hri_rtc_tampctrl_reg_t config = hri_rtc_get_TAMPCTRL_reg(RTC, 0xFFFFFFFF);

    switch (pin) {
        case A4:
            a4_callback = callback;
            pinmux = PINMUX_PB00G_RTC_IN0;
            config &= ~(3 << RTC_TAMPCTRL_IN0ACT_Pos);
            config &= ~(1 << RTC_TAMPCTRL_TAMLVL0_Pos);
            config |= 1 << RTC_TAMPCTRL_IN0ACT_Pos;
            config |= 1 << RTC_TAMPCTRL_DEBNC0_Pos;
            if (level) config |= 1 << RTC_TAMPCTRL_TAMLVL0_Pos;
            break;
        case A2:
            a2_callback = callback;
            pinmux = PINMUX_PB02G_RTC_IN1;
            config &= ~(3 << RTC_TAMPCTRL_IN1ACT_Pos);
            config &= ~(1 << RTC_TAMPCTRL_TAMLVL1_Pos);
            config |= 1 << RTC_TAMPCTRL_IN1ACT_Pos;
            config |= 1 << RTC_TAMPCTRL_DEBNC1_Pos;
            if (level) config |= 1 << RTC_TAMPCTRL_TAMLVL1_Pos;
            break;
        case BTN_ALARM:
            gpio_set_pin_pull_mode(pin, GPIO_PULL_DOWN);
            btn_alarm_callback = callback;
            pinmux = PINMUX_PA02G_RTC_IN2;
            config &= ~(3 << RTC_TAMPCTRL_IN2ACT_Pos);
            config &= ~(1 << RTC_TAMPCTRL_TAMLVL2_Pos);
            config |= 1 << RTC_TAMPCTRL_IN2ACT_Pos;
            config |= 1 << RTC_TAMPCTRL_DEBNC2_Pos;
            if (level) config |= 1 << RTC_TAMPCTRL_TAMLVL2_Pos;
            break;
        default:
            return;
    }
    gpio_set_pin_direction(pin, GPIO_DIRECTION_IN);
    gpio_set_pin_function(pin, pinmux);

    // disable the RTC
	if (hri_rtcmode0_get_CTRLA_ENABLE_bit(RTC)) {
		hri_rtcmode0_clear_CTRLA_ENABLE_bit(RTC);
		hri_rtcmode0_wait_for_sync(RTC, RTC_MODE0_SYNCBUSY_ENABLE);
	}
    // update the configuration
    hri_rtc_write_TAMPCTRL_reg(RTC, config);
    // re-enable the RTC
    hri_rtcmode0_set_CTRLA_ENABLE_bit(RTC);

    _extwake_register_callback(&CALENDAR_0.device, extwake_callback);
}

void watch_store_backup_data(uint32_t data, uint8_t reg) {
    if (reg < 8) {
        RTC->MODE0.BKUP[reg].reg = data;
    }
}

uint32_t watch_get_backup_data(uint8_t reg) {
    if (reg < 8) {
        return RTC->MODE0.BKUP[reg].reg;
    }

    return 0;
}

void watch_enter_deep_sleep() {
    // enable and configure the external wake interrupt, if not already set up.
    if (btn_alarm_callback == NULL && a2_callback == NULL && a4_callback == NULL) {
        gpio_set_pin_direction(BTN_ALARM, GPIO_DIRECTION_IN);
        gpio_set_pin_pull_mode(BTN_ALARM, GPIO_PULL_DOWN);
        gpio_set_pin_function(BTN_ALARM, PINMUX_PA02G_RTC_IN2);
        _extwake_register_callback(&CALENDAR_0.device, extwake_callback);
    }

    // disable SLCD
    slcd_sync_deinit(&SEGMENT_LCD_0);
    hri_mclk_clear_APBCMASK_SLCD_bit(SLCD);

    // TODO: disable other peripherals

    // go into backup sleep mode
    sleep(5);
}
