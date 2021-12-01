/*
 * MIT License
 *
 * Copyright (c) 2021 Joey Castillo
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

#include "lis2dh.h"
#include "watch.h"

bool lis2dh_begin() {
    if (lis2dh_get_device_id() != LIS2DH_WHO_AM_I_VAL) {
        return false;
    }
    // Enable all axes, start at lowest possible data rate
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL1, LIS2DH_CTRL1_VAL_XEN |
                                                       LIS2DH_CTRL1_VAL_YEN |
                                                       LIS2DH_CTRL1_VAL_ZEN |
                                                       LIS2DH_CTRL1_VAL_ODR_1HZ);
    // Set range to ±2G and enable block data update (output registers not updated until MSB and LSB have been read)
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL4, LIS2DH_CTRL4_VAL_BDU | LIS2DH_RANGE_2_G);

    return true;
}

uint8_t lis2dh_get_device_id() {
    return watch_i2c_read8(LIS2DH_ADDRESS, LIS2DH_REG_WHO_AM_I);
}

bool lis2dh_have_new_data() {
    uint8_t retval = watch_i2c_read8(LIS2DH_ADDRESS, LIS2DH_REG_STATUS);
    return !!retval; // return true if any bit is set
}

lis2dh_reading lis2dh_get_raw_reading() {
    uint8_t buffer[6];
    uint8_t reg = LIS2DH_REG_OUT_X_L | 0x80; // set high bit for consecutive reads
    lis2dh_reading retval;

    watch_i2c_send(LIS2DH_ADDRESS, &reg, 1);
    watch_i2c_receive(LIS2DH_ADDRESS, (uint8_t *)&buffer, 6);

    retval.x = buffer[0];
    retval.x |= ((uint16_t)buffer[1]) << 8;
    retval.y = buffer[2];
    retval.y |= ((uint16_t)buffer[3]) << 8;
    retval.z = buffer[4];
    retval.z |= ((uint16_t)buffer[5]) << 8;

    return retval;
}

 lis2dh_acceleration_measurement lis2dh_get_acceleration_measurement(lis2dh_reading *out_reading) {
    lis2dh_reading reading = lis2dh_get_raw_reading();
    uint8_t range = lis2dh_get_range();
    if (out_reading != NULL) *out_reading = reading;

    // this bit is cribbed from Adafruit's LIS3DH driver; from their notes, the magic number below
    // converts from 16-bit lsb to 10-bit and divides by 1k to convert from milli-gs.
    // final value is raw_lsb => 10-bit lsb -> milli-gs -> gs
    uint8_t lsb_value = 1;
    if (range == LIS2DH_RANGE_2_G) lsb_value = 4;
    if (range == LIS2DH_RANGE_4_G) lsb_value = 8;
    if (range == LIS2DH_RANGE_8_G) lsb_value = 16;
    if (range == LIS2DH_RANGE_16_G) lsb_value = 48;

    lis2dh_acceleration_measurement retval;

    retval.x = lsb_value * ((float)reading.x / 64000.0);
    retval.y = lsb_value * ((float)reading.y / 64000.0);
    retval.z = lsb_value * ((float)reading.z / 64000.0);

    return retval;
}

void lis2dh_set_range(lis2dh_range_t range) {
    uint8_t val = watch_i2c_read8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL4) & 0xCF;
    uint8_t bits = range << 4;

    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL4, val | bits);
}

lis2dh_range_t lis2dh_get_range() {
    uint8_t retval = watch_i2c_read8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL4) & 0x30;
    retval >>= 4;
    return (lis2dh_range_t)retval;
}


void lis2dh_set_data_rate(lis2dh_data_rate_t dataRate) {
    uint8_t val = watch_i2c_read8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL1) & 0x0F;
    uint8_t bits = dataRate << 4;

    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL1, val | bits);
}

lis2dh_data_rate_t lis2dh_get_data_rate() {
    return watch_i2c_read8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL1) >> 4;
}

void lis2dh_configure_aoi_int1(lis2dh_interrupt_configuration configuration, uint8_t threshold, uint8_t duration) {
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL3, LIS2DH_CTRL3_VAL_I1_AOI1);
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_INT1_CFG, configuration);
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_INT1_THS, threshold);
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_INT1_DUR, duration);
}

lis2dh_interrupt_state lis2dh_get_int1_state() {
    return (lis2dh_interrupt_state) watch_i2c_read8(LIS2DH_ADDRESS, LIS2DH_REG_INT1_SRC);
}

void lis2dh_configure_aoi_int2(lis2dh_interrupt_configuration configuration, uint8_t threshold, uint8_t duration) {
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_CTRL6, LIS2DH_CTRL6_VAL_I2_INT2);
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_INT2_CFG, configuration);
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_INT2_THS, threshold);
    watch_i2c_write8(LIS2DH_ADDRESS, LIS2DH_REG_INT2_DUR, duration);
}

lis2dh_interrupt_state lis2dh_get_int2_state() {
    return (lis2dh_interrupt_state) watch_i2c_read8(LIS2DH_ADDRESS, LIS2DH_REG_INT2_SRC);
}

