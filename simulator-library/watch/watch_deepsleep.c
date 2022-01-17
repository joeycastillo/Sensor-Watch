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

#include "watch_extint.h"

// this warning only appears when you `make BOARD=OSO-SWAT-A1-02`. it's annoying,
// but i'd rather have it warn us at build-time than fail silently at run-time.
// besides, no one but me really has any of these boards anyway.
#if BTN_ALARM != GPIO(GPIO_PORTA, 2)
#warning This board revision does not support external wake on BTN_ALARM, so watch_register_extwake_callback will not work with it. Use watch_register_interrupt_callback instead.
#endif

void watch_register_extwake_callback(uint8_t pin, ext_irq_cb_t callback, bool level) {
    if (pin == BTN_ALARM) {
        watch_register_interrupt_callback(pin, callback, level ? INTERRUPT_TRIGGER_RISING : INTERRUPT_TRIGGER_FALLING);
    }
}

void watch_disable_extwake_interrupt(uint8_t pin) {
    if (pin == BTN_ALARM) {
        watch_register_interrupt_callback(pin, NULL, INTERRUPT_TRIGGER_NONE);
    }
}

void watch_store_backup_data(uint32_t data, uint8_t reg) {
    if (reg < 8) {
        // TODO: (a2) hook to UI
    }
}

uint32_t watch_get_backup_data(uint8_t reg) {
    if (reg < 8) {
        // TODO: (a2) hook to UI
    }

    return 0;
}

void watch_enter_sleep_mode(void) {
    // TODO: (a2) hook to UI

    // enter standby (4); we basically hang out here until an interrupt wakes us.
    // sleep(4);

    // call app_setup so the app can re-enable everything we disabled.
    app_setup();

    // and call app_wake_from_standby (since main won't have a chance to do it)
    app_wake_from_standby();
}

void watch_enter_deep_sleep_mode(void) {
    // identical to sleep mode except we disable the LCD first.
    // TODO: (a2) hook to UI

    watch_enter_sleep_mode();
}

void watch_enter_backup_mode(void) {
    // TODO: (a2) hook to UI

    // go into backup sleep mode (5). when we exit, the reset controller will take over.
    // sleep(5);
}

// deprecated
void watch_enter_shallow_sleep(bool display_on) {
    if (display_on) watch_enter_sleep_mode();
    else watch_enter_deep_sleep_mode();
}

// deprecated
void watch_enter_deep_sleep(void) {
    watch_register_extwake_callback(BTN_ALARM, NULL, true);
    watch_enter_backup_mode();
}
