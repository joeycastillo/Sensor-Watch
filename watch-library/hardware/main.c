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

//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "saml22.h"
#include "hal_init.h"
#include "watch.h"
#include "tusb.h"

int main(void) {
    // ASF code. Initialize the MCU with configuration options from Atmel Studio.
    init_mcu();

    // check if we are plugged into USB power.
    watch_enable_digital_input(VBUS_DET);
    watch_enable_pull_down(VBUS_DET);
    if (watch_get_pin_level(VBUS_DET)) {
        // if so, enable USB functionality.
        _watch_enable_usb();
    }
    watch_disable_digital_input(VBUS_DET);

    // initialize the delay driver before any user code is called.
    delay_driver_init();

    // User code. Give the app a chance to initialize its data structures and state.
    app_init();

    // If the RTC is already enabled, we're either waking from BACKUP mode or a reset.
    // Ideally we should check if the TAMPER or CMP0 (alarm) flags are set.
    if (_watch_rtc_is_enabled()) {
        // User code. Give the application a chance to restore state from backup registers.
        app_wake_from_backup();

        // disable the tamper interrupt and clear the tamper bit
        hri_rtcmode0_clear_INTEN_TAMPER_bit(RTC);
        hri_rtcmode0_clear_interrupt_TAMPER_bit(RTC);
    }

    // Watch library code. Set initial parameters for the device and enable the RTC.
    _watch_init();

    // if date/time register is 0 (power on reset state), default year to 2023.
    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.reg == 0) {
        date_time.unit.year = 3;
        watch_rtc_set_date_time(date_time);
    }

    // User code. Give the app a chance to enable and set up peripherals.
    app_setup();

    while (1) {
        bool usb_enabled = hri_usbdevice_get_CTRLA_ENABLE_bit(USB);
        bool can_sleep = app_loop();
        if (can_sleep && !usb_enabled) {
            app_prepare_for_standby();
            sleep(4);
            app_wake_from_standby();
        }
    }

    return 0;
}
