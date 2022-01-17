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

#include "watch_led.h"

void watch_enable_leds(void) {
    // TODO: (a2) hook to UI
}

void watch_disable_leds(void) {
    // TODO: (a2) hook to UI
}

void watch_enable_led(bool unused) {
    (void)unused;
    watch_enable_leds();
}

void watch_disable_led(bool unused) {
    (void)unused;
    watch_disable_leds();
}

void watch_set_led_color(uint8_t red, uint8_t green) {
    // TODO: (a2) hook to UI
}

void watch_set_led_red(void) {
    watch_set_led_color(255, 0);
}

void watch_set_led_green(void) {
    watch_set_led_color(0, 255);
}

void watch_set_led_yellow(void) {
    watch_set_led_color(255, 255);
}

void watch_set_led_off(void) {
    watch_set_led_color(0, 0);
}
