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
    if (!hri_tcc_get_CTRLA_reg(TCC0, TCC_CTRLA_ENABLE)) {
        _watch_enable_tcc();
    }
}

void watch_disable_leds(void) {
    _watch_disable_tcc();
}

void watch_set_led_color(uint8_t red, uint8_t green) {
#ifdef WATCH_BLUE_TCC_CHANNEL
    watch_set_led_color_rgb(red, green, 0);
#else
    watch_set_led_color_rgb(red, green, green);
#endif
}

void watch_set_led_color_rgb(uint8_t red, uint8_t green, uint8_t blue) {
#ifndef WATCH_BLUE_TCC_CHANNEL
    (void) blue; // silence warning
#endif
    if (hri_tcc_get_CTRLA_reg(TCC0, TCC_CTRLA_ENABLE)) {
        uint32_t period = hri_tcc_get_PER_reg(TCC0, TCC_PER_MASK);
        hri_tcc_write_CCBUF_reg(TCC0, WATCH_RED_TCC_CHANNEL, ((period * red * 1000ull) / 255000ull));
        hri_tcc_write_CCBUF_reg(TCC0, WATCH_GREEN_TCC_CHANNEL, ((period * green * 1000ull) / 255000ull));
#ifdef WATCH_BLUE_TCC_CHANNEL
        hri_tcc_write_CCBUF_reg(TCC0, WATCH_BLUE_TCC_CHANNEL, ((period * blue * 1000ull) / 255000ull));
#endif
    }
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
