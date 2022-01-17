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

#include <emscripten.h>

static bool external_interrupt_enabled = false;
static ext_irq_cb_t external_interrupt_mode_callback = NULL;
static watch_interrupt_trigger external_interrupt_mode_trigger = INTERRUPT_TRIGGER_NONE;
static ext_irq_cb_t external_interrupt_light_callback = NULL;
static watch_interrupt_trigger external_interrupt_light_trigger = INTERRUPT_TRIGGER_NONE;
static ext_irq_cb_t external_interrupt_alarm_callback = NULL;
static watch_interrupt_trigger external_interrupt_alarm_trigger = INTERRUPT_TRIGGER_NONE;

void watch_enable_external_interrupts(void) {
    external_interrupt_enabled = true;

    EM_ASM({
        for (let i = 1; i <= 3; i++) {
            const element = document.querySelector('#btn' + i);
            element.addEventListener('mousedown', () => Module.ccall('watch_invoke_interrupt_callback', 'null', ['number, number'], [i, 1]));
            element.addEventListener('mouseup', () => Module.ccall('watch_invoke_interrupt_callback', 'null', ['number, number'], [i, 2]));
        }
    });
}

void watch_disable_external_interrupts(void) {
    external_interrupt_enabled = false;
}

EMSCRIPTEN_KEEPALIVE
void watch_invoke_interrupt_callback(uint32_t button, uint32_t trigger) {
    void resume_main_loop(void);

    if (button == 2) {
        if (external_interrupt_mode_callback && (external_interrupt_mode_trigger & trigger)) {
            external_interrupt_mode_callback();
            resume_main_loop();
        }
    } else if (button == 1) {
        if (external_interrupt_light_callback && (external_interrupt_light_trigger & trigger)) {
            external_interrupt_light_callback();
            resume_main_loop();
        }
    } else if (button == 3) {
        if (external_interrupt_alarm_callback && (external_interrupt_alarm_trigger & trigger)) {
            external_interrupt_alarm_callback();
            resume_main_loop();
        }
    }
}

void watch_register_interrupt_callback(const uint8_t pin, ext_irq_cb_t callback, watch_interrupt_trigger trigger) {
    if (pin == BTN_MODE) {
        external_interrupt_mode_callback = callback;
        external_interrupt_mode_trigger = trigger;
    } else if (pin == BTN_LIGHT) {
        external_interrupt_light_callback = callback;
        external_interrupt_light_trigger = trigger;
    } else if (pin == BTN_ALARM) {
        external_interrupt_alarm_callback = callback;
        external_interrupt_alarm_trigger = trigger;
    }
}

void watch_register_button_callback(const uint8_t pin, ext_irq_cb_t callback) {
    watch_register_interrupt_callback(pin, callback, INTERRUPT_TRIGGER_RISING);
}

void watch_enable_buttons(void) {
    watch_enable_external_interrupts();
}
