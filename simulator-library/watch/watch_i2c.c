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

#include "watch_i2c.h"

void watch_enable_i2c(void) {}

void watch_disable_i2c(void) {}

void watch_i2c_send(int16_t addr, uint8_t *buf, uint16_t length) {}

void watch_i2c_receive(int16_t addr, uint8_t *buf, uint16_t length) {}

void watch_i2c_write8(int16_t addr, uint8_t reg, uint8_t data) {}

uint8_t watch_i2c_read8(int16_t addr, uint8_t reg) {
    return 0;
}

uint16_t watch_i2c_read16(int16_t addr, uint8_t reg) {
    return 0;
}

uint32_t watch_i2c_read24(int16_t addr, uint8_t reg) {
    return 0;
}

uint32_t watch_i2c_read32(int16_t addr, uint8_t reg) {
    return 0;
}
