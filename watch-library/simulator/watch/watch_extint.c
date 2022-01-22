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
static bool button_callbacks_installed = false;
static ext_irq_cb_t external_interrupt_mode_callback = NULL;
static watch_interrupt_trigger external_interrupt_mode_trigger = INTERRUPT_TRIGGER_NONE;
static ext_irq_cb_t external_interrupt_light_callback = NULL;
static watch_interrupt_trigger external_interrupt_light_trigger = INTERRUPT_TRIGGER_NONE;
static ext_irq_cb_t external_interrupt_alarm_callback = NULL;
static watch_interrupt_trigger external_interrupt_alarm_trigger = INTERRUPT_TRIGGER_NONE;

static void install_button_callbacks(void) {
    EM_ASM({
        const invoke = Module.cwrap('watch_invoke_interrupt_callback', 'null', ['number', 'number']);
        const RISING = 1;
        const FALLING = 2;

        const keys = ({ a: 3, l: 1, m: 2 });
        document.addEventListener('keydown', function(event) {
            if (event.repeat) return;
            if (event.target && event.target.id === 'output') return;

            const btn = keys[event.key.toLowerCase()];
            if (btn) invoke(btn, RISING);
        });

        document.addEventListener('keyup', function(event) {
            if (event.repeat) return;
            if (event.target && event.target.id === 'output') return;

            const btn = keys[event.key.toLowerCase()];
            if (btn) invoke(btn, FALLING);
        });

        for (let i = 1; i <= 3; i++) {
            const element = document.querySelector('#btn' + i);

            let mouseDown = false;
            element.addEventListener('mousedown', (event) => {
                invoke(i, RISING);
                mouseDown = true;
                event.preventDefault();
            });
            element.addEventListener('mouseup', (event) => {
                invoke(i, FALLING);
                mouseDown = false;
                event.preventDefault();
            });
            element.addEventListener('mouseout', (event) => {
                if (mouseDown) invoke(i, FALLING);
                mouseDown = false;
                event.preventDefault();
            });
            element.addEventListener('touchstart', (event) => {
                invoke(i, RISING);
                event.preventDefault();
            });
            element.addEventListener('touchend', (event) => {
                invoke(i, FALLING);
                event.preventDefault();
            });
        }
    });
}

void watch_enable_external_interrupts(void) {
    external_interrupt_enabled = true;

    if (!button_callbacks_installed) {
        install_button_callbacks();
        button_callbacks_installed = true;
    }
}

void watch_disable_external_interrupts(void) {
    external_interrupt_enabled = false;
}

void watch_invoke_interrupt_callback(uint32_t button, uint32_t trigger);

EMSCRIPTEN_KEEPALIVE
void watch_invoke_interrupt_callback(uint32_t button, uint32_t trigger) {
    if (!external_interrupt_enabled) return;

    void resume_main_loop(void);

    if (button == 2) {
        watch_set_pin_level(BTN_MODE, (trigger & INTERRUPT_TRIGGER_RISING) != 0);

        if (external_interrupt_mode_callback && (external_interrupt_mode_trigger & trigger)) {
            external_interrupt_mode_callback();
            resume_main_loop();
        }
    } else if (button == 1) {
        watch_set_pin_level(BTN_LIGHT, (trigger & INTERRUPT_TRIGGER_RISING) != 0);

        if (external_interrupt_light_callback && (external_interrupt_light_trigger & trigger)) {
            external_interrupt_light_callback();
            resume_main_loop();
        }
    } else if (button == 3) {
        watch_set_pin_level(BTN_ALARM, (trigger & INTERRUPT_TRIGGER_RISING) != 0);

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
