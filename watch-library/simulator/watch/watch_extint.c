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

#include <string.h>

#include "watch_extint.h"
#include "watch_main_loop.h"

#include <emscripten.h>
#include <emscripten/html5.h>

static bool debug_console_focused = false;
static bool external_interrupt_enabled = false;
static bool button_callbacks_installed = false;
static ext_irq_cb_t external_interrupt_mode_callback = NULL;
static watch_interrupt_trigger external_interrupt_mode_trigger = INTERRUPT_TRIGGER_NONE;
static ext_irq_cb_t external_interrupt_light_callback = NULL;
static watch_interrupt_trigger external_interrupt_light_trigger = INTERRUPT_TRIGGER_NONE;
static ext_irq_cb_t external_interrupt_alarm_callback = NULL;
static watch_interrupt_trigger external_interrupt_alarm_trigger = INTERRUPT_TRIGGER_NONE;

#define BTN_ID_ALARM 3
#define BTN_ID_LIGHT 1
#define BTN_ID_MODE 2
static const uint8_t BTN_IDS[] = { BTN_ID_ALARM, BTN_ID_LIGHT, BTN_ID_MODE };
static EM_BOOL watch_invoke_interrupt_callback(const uint8_t button_id, watch_interrupt_trigger trigger);

static EM_BOOL watch_invoke_key_callback(int eventType, const EmscriptenKeyboardEvent *keyEvent, void *userData) {
    if (debug_console_focused || keyEvent->repeat) return EM_FALSE;

    uint8_t button_id;
    const char *key = keyEvent->key;
    if (key[1] == 0) {
        // event is from a plain letter key
        switch (key[0]) {
            case 'A':
            case 'a':
                button_id = BTN_ID_ALARM;
                break;
            case 'L':
            case 'l':
                button_id = BTN_ID_LIGHT;
                break;
            case 'M':
            case 'm':
                button_id = BTN_ID_MODE;
                break;
            default:
                return EM_FALSE;
        }
    } else if (strncmp(key, "Arrow", 5) == 0) {
        // event is from one of the arrow keys
        switch(key[5]) {
            case 'U': // ArrowUp
                button_id = BTN_ID_LIGHT;
                break;
            case 'D': // ArrowDown
            case 'L': // ArrowLeft
                button_id = BTN_ID_MODE;
                break;
            case 'R': // ArrowRight
                button_id = BTN_ID_ALARM;
                break;
            default:
                return EM_FALSE;
        }
    } else {
        // another kind of key
        return EM_FALSE;
    }

    watch_interrupt_trigger trigger = eventType == EMSCRIPTEN_EVENT_KEYDOWN ? INTERRUPT_TRIGGER_RISING : INTERRUPT_TRIGGER_FALLING;
    return watch_invoke_interrupt_callback(button_id, trigger);
}

static EM_BOOL watch_invoke_mouse_callback(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
    if (eventType == EMSCRIPTEN_EVENT_MOUSEOUT && mouseEvent->buttons == 0) return EM_FALSE;
    uint8_t button_id = *(const char *)userData;
    watch_interrupt_trigger trigger = eventType == EMSCRIPTEN_EVENT_MOUSEDOWN ? INTERRUPT_TRIGGER_RISING : INTERRUPT_TRIGGER_FALLING;
    return watch_invoke_interrupt_callback(button_id, trigger);
}

static EM_BOOL watch_invoke_touch_callback(int eventType, const EmscriptenTouchEvent *touchEvent, void *userData) {
    uint8_t button_id = *(const char *)userData;
    watch_interrupt_trigger trigger = eventType == EMSCRIPTEN_EVENT_TOUCHSTART ? INTERRUPT_TRIGGER_RISING : INTERRUPT_TRIGGER_FALLING;
    return watch_invoke_interrupt_callback(button_id, trigger);
}

static EM_BOOL watch_invoke_focus_callback(int eventType, const EmscriptenFocusEvent *focusEvent, void *userData) {
    debug_console_focused = eventType == EMSCRIPTEN_EVENT_FOCUS;
    return EM_TRUE;
}

static void watch_install_button_callbacks(void) {
    emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_DOCUMENT, NULL, EM_FALSE, watch_invoke_key_callback);
    emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_DOCUMENT, NULL, EM_FALSE, watch_invoke_key_callback);

    const char *target_output = "#output";
    emscripten_set_focus_callback(target_output, NULL, EM_FALSE, watch_invoke_focus_callback);
    emscripten_set_blur_callback(target_output, NULL, EM_FALSE, watch_invoke_focus_callback);

    const char *target_input = "#input";
    emscripten_set_focus_callback(target_input, NULL, EM_FALSE, watch_invoke_focus_callback);
    emscripten_set_blur_callback(target_input, NULL, EM_FALSE, watch_invoke_focus_callback);

    for (int i = 0, count = sizeof(BTN_IDS) / sizeof(BTN_IDS[0]); i < count; i++) {
        char target[] = "#btn_";
        target[4] = BTN_IDS[i] + '0';

        emscripten_set_mousedown_callback(target, (void *)&BTN_IDS[i], EM_FALSE, watch_invoke_mouse_callback);
        emscripten_set_mouseup_callback(target, (void *)&BTN_IDS[i], EM_FALSE, watch_invoke_mouse_callback);
        emscripten_set_mouseout_callback(target, (void *)&BTN_IDS[i], EM_FALSE, watch_invoke_mouse_callback);

        emscripten_set_touchstart_callback(target, (void *)&BTN_IDS[i], EM_FALSE, watch_invoke_touch_callback);
        emscripten_set_touchend_callback(target, (void *)&BTN_IDS[i], EM_FALSE, watch_invoke_touch_callback);
    }
}

void watch_enable_external_interrupts(void) {
    external_interrupt_enabled = true;

    if (!button_callbacks_installed) {
        watch_install_button_callbacks();
        button_callbacks_installed = true;
    }
}

void watch_disable_external_interrupts(void) {
    external_interrupt_enabled = false;
}

static EM_BOOL watch_invoke_interrupt_callback(const uint8_t button_id, watch_interrupt_trigger event) {
    ext_irq_cb_t callback;
    watch_interrupt_trigger trigger;
    uint8_t pin;
    switch (button_id) {
        case BTN_ID_MODE:
            pin = BTN_MODE;
            callback = external_interrupt_mode_callback;
            trigger = external_interrupt_mode_trigger;
            break;
        case BTN_ID_LIGHT:
            pin = BTN_LIGHT;
            callback = external_interrupt_light_callback;
            trigger = external_interrupt_light_trigger;
            break;
        case BTN_ID_ALARM:
            pin = BTN_ALARM;
            callback = external_interrupt_alarm_callback;
            trigger = external_interrupt_alarm_trigger;
            break;
        default:
            return EM_FALSE;
    }

    const bool level = (event & INTERRUPT_TRIGGER_RISING) != 0;
    EM_ASM({
        const classList = document.querySelector('#btn' + $0).classList;
        const highlight = 'highlight';
        $1 ? classList.add(highlight) : classList.remove(highlight);
    }, button_id, level);

    if (!external_interrupt_enabled || main_loop_is_sleeping()) {
        return EM_FALSE;
    }

    watch_set_pin_level(pin, level);

    if (callback && (event & trigger) != 0) {
        callback();
        resume_main_loop();
    }

    return EM_TRUE;
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
