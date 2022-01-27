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

#include "watch_slcd.h"
#include "watch_private_display.h"
#include "hpl_slcd_config.h"

#include <emscripten.h>
#include <emscripten/html5.h>

//////////////////////////////////////////////////////////////////////////////////////////
// Segmented Display

static char blink_character;
static bool blink_state;
static long blink_interval_id = - 1;
static bool tick_state;
static long tick_interval_id = -1;

void watch_enable_display(void) {
    watch_clear_display();
}

void watch_set_pixel(uint8_t com, uint8_t seg) {
    EM_ASM({
        document.querySelectorAll("[data-com='" + $0 + "'][data-seg='" + $1 + "']")
            .forEach((e) => e.style.opacity = 1);
    }, com, seg);
}

void watch_clear_pixel(uint8_t com, uint8_t seg) {
    EM_ASM({
        document.querySelectorAll("[data-com='" + $0 + "'][data-seg='" + $1 + "']")
            .forEach((e) => e.style.opacity = 0);
    }, com, seg);
}

void watch_clear_display(void) {
    EM_ASM({
        document.querySelectorAll("[data-com][data-seg]")
            .forEach((e) => e.style.opacity = 0);
    });
}

static void watch_invoke_blink_callback(void *userData) {
    blink_state = !blink_state;
    watch_display_character(blink_state ? blink_character : ' ', 7);
    watch_clear_pixel(2, 10); // clear segment B of position 7 since it can't blink
}

void watch_start_character_blink(char character, uint32_t duration) {
    if (blink_interval_id != -1) return;
    watch_display_character(character, 7);
    watch_clear_pixel(2, 10); // clear segment B of position 7 since it can't blink

    blink_state = true;
    blink_character = character;
    blink_interval_id = emscripten_set_interval(watch_invoke_blink_callback, (double)duration, NULL);
}

void watch_stop_blink(void) {
    emscripten_clear_timeout(blink_interval_id);
    blink_interval_id = -1;
    blink_state = false;
}

static void watch_invoke_tick_callback(void *userData) {
    tick_state = !tick_state;
    if (tick_state) {
        watch_clear_pixel(0, 2);
        watch_set_pixel(0, 3);
    } else {
        watch_clear_pixel(0, 3);
        watch_set_pixel(0, 2);
    }
}

void watch_start_tick_animation(uint32_t duration) {
    if (tick_interval_id != -1) return;
    watch_display_character(' ', 8);

    tick_state = true;
    tick_interval_id = emscripten_set_interval(watch_invoke_tick_callback, (double)duration, NULL);
}

bool watch_tick_animation_is_running(void) {
    return tick_interval_id != -1;
}

void watch_stop_tick_animation(void) {
    emscripten_clear_timeout(tick_interval_id);
    tick_interval_id = -1;
    tick_state = false;

    watch_display_character(' ', 8);
}
