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

struct io_descriptor *I2C_0_io;

void watch_enable_i2c() {
    I2C_0_init();
    i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
    i2c_m_sync_enable(&I2C_0);
}

void watch_disable_i2c() {
    i2c_m_sync_disable(&I2C_0);
	hri_mclk_clear_APBCMASK_SERCOM1_bit(MCLK);
}

void watch_i2c_send(int16_t addr, uint8_t *buf, uint16_t length) {
    i2c_m_sync_set_periphaddr(&I2C_0, addr, I2C_M_SEVEN);
    io_write(I2C_0_io, buf, length);
}

void watch_i2c_receive(int16_t addr, uint8_t *buf, uint16_t length) {
    i2c_m_sync_set_periphaddr(&I2C_0, addr, I2C_M_SEVEN);
    io_read(I2C_0_io, buf, length);
}

void watch_i2c_write8(int16_t addr, uint8_t reg, uint8_t data) {
    uint8_t buf[2];
    buf[0] = reg;
    buf[1] = data;

    watch_i2c_send(addr, (uint8_t *)&buf, 2);
}

uint8_t watch_i2c_read8(int16_t addr, uint8_t reg) {
    uint8_t data;

    watch_i2c_send(addr, (uint8_t *)&reg, 1);
    watch_i2c_receive(addr, (uint8_t *)&data, 1);

    return data;
}

uint16_t watch_i2c_read16(int16_t addr, uint8_t reg) {
    uint16_t data;

    watch_i2c_send(addr, (uint8_t *)&reg, 1);
    watch_i2c_receive(addr, (uint8_t *)&data, 2);

    return data;
}

uint32_t watch_i2c_read24(int16_t addr, uint8_t reg) {
    uint32_t data;
    data = 0;

    watch_i2c_send(addr, (uint8_t *)&reg, 1);
    watch_i2c_receive(addr, (uint8_t *)&data, 3);

    return data << 8;
}

uint32_t watch_i2c_read32(int16_t addr, uint8_t reg) {
    uint32_t data;

    watch_i2c_send(addr, (uint8_t *)&reg, 1);
    watch_i2c_receive(addr, (uint8_t *)&data, 4);

    return data;
}
