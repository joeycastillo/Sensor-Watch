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

#include "watch_gpio.h"

static bool pin_levels[UINT8_MAX];

void watch_enable_digital_input(const uint8_t pin) {}

void watch_disable_digital_input(const uint8_t pin) {}

void watch_enable_pull_up(const uint8_t pin) {}

void watch_enable_pull_down(const uint8_t pin) {}

bool watch_get_pin_level(const uint8_t pin) {
    return pin_levels[pin];
}

void watch_enable_digital_output(const uint8_t pin) {}

void watch_disable_digital_output(const uint8_t pin) {}

void watch_set_pin_level(const uint8_t pin, const bool level) {
    pin_levels[pin] = level;
}
