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

#ifndef LIS2DH_H
#define LIS2DH_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} lis2dh_reading;

typedef struct {
    float x;
    float y;
    float z;
} lis2dh_acceleration_measurement;

typedef enum {
  LIS2DH_RANGE_16_G = 0b11, // +/- 16g
  LIS2DH_RANGE_8_G = 0b10,  // +/- 8g
  LIS2DH_RANGE_4_G = 0b01,  // +/- 4g
  LIS2DH_RANGE_2_G = 0b00   // +/- 2g (default value)
} lis2dh_range_t;

typedef enum {
  LIS2DH_DATA_RATE_POWERDOWN = 0,
  LIS2DH_DATA_RATE_1_HZ = 0b0001,
  LIS2DH_DATA_RATE_10_HZ = 0b0010,
  LIS2DH_DATA_RATE_25_HZ = 0b0011,
  LIS2DH_DATA_RATE_50_HZ = 0b0100,
  LIS2DH_DATA_RATE_100_HZ = 0b0101,
  LIS2DH_DATA_RATE_200_HZ = 0b0110,
  LIS2DH_DATA_RATE_400_HZ = 0b0111,
  LIS2DH_DATA_RATE_LP1620HZ = 0b1000,
  LIS2DH_DATA_RATE_LP5376HZ = 0b1001,

} lis2dh_data_rate_t;

typedef enum {
  LIS2DH_INTERRUPT_CONFIGURATION_OR            = 0b00000000,
  LIS2DH_INTERRUPT_CONFIGURATION_AND           = 0b10000000,
  LIS2DH_INTERRUPT_CONFIGURATION_6D_MOVEMENT   = 0b01000000,
  LIS2DH_INTERRUPT_CONFIGURATION_6D_POSITION   = 0b11000000, // in 6D mode, these have an alternate meaning:
  LIS2DH_INTERRUPT_CONFIGURATION_Z_HIGH_ENABLE = 0b00100000, // Z up enable
  LIS2DH_INTERRUPT_CONFIGURATION_Z_LOW_ENABLE  = 0b00010000, // Z down enable
  LIS2DH_INTERRUPT_CONFIGURATION_Y_HIGH_ENABLE = 0b00001000, // Y up enable
  LIS2DH_INTERRUPT_CONFIGURATION_Y_LOW_ENABLE  = 0b00000100, // Y down enable
  LIS2DH_INTERRUPT_CONFIGURATION_X_HIGH_ENABLE = 0b00000010, // X up enable
  LIS2DH_INTERRUPT_CONFIGURATION_X_LOW_ENABLE  = 0b00000001, // X down enable
} lis2dh_interrupt_configuration;

typedef enum {
  LIS2DH_INTERRUPT_STATE_ACTIVE = 0b01000000,
  LIS2DH_INTERRUPT_STATE_Z_HIGH = 0b00100000, // Z up
  LIS2DH_INTERRUPT_STATE_Z_LOW  = 0b00010000, // Z down
  LIS2DH_INTERRUPT_STATE_Y_HIGH = 0b00001000, // Y up
  LIS2DH_INTERRUPT_STATE_Y_LOW  = 0b00000100, // Y down
  LIS2DH_INTERRUPT_STATE_X_HIGH = 0b00000010, // X up
  LIS2DH_INTERRUPT_STATE_X_LOW  = 0b00000001, // X down
} lis2dh_interrupt_state;

bool lis2dh_begin(void);

uint8_t lis2dh_get_device_id(void);

bool lis2dh_have_new_data(void);

lis2dh_reading lis2dh_get_raw_reading(void);

lis2dh_acceleration_measurement lis2dh_get_acceleration_measurement(lis2dh_reading *out_reading);

void lis2dh_set_range(lis2dh_range_t range);

lis2dh_range_t lis2dh_get_range(void);

void lis2dh_set_data_rate(lis2dh_data_rate_t dataRate);

lis2dh_data_rate_t lis2dh_get_data_rate(void);

void lis2dh_configure_aoi_int1(lis2dh_interrupt_configuration configuration, uint8_t threshold, uint8_t duration, bool latch);

lis2dh_interrupt_state lis2dh_get_int1_state(void);

void lis2dh_configure_aoi_int2(lis2dh_interrupt_configuration configuration, uint8_t threshold, uint8_t duration, bool latch);

lis2dh_interrupt_state lis2dh_get_int2_state(void);

// Assumes SA0 is high; if low, its 0x18
#define LIS2DH_ADDRESS (0x19)

#define LIS2DH_REG_STATUS_AUX 0x07          ///< Auxiliary status register
#define LIS2DH_REG_STATUS_AUX_TDA (1 << 2)  ///< Temperature data available
#define LIS2DH_REG_STATUS_AUX_TOR (1 << 6)  ///< Temperature data overrun

#define LIS2DH_REG_OUT_TEMP_L 0x0C  ///< Temperature data low bit
#define LIS2DH_REG_OUT_TEMP_H 0x0D  ///< Temperature data high bit

#define LIS2DH_REG_INT_COUNTER 0x0E

#define LIS2DH_REG_WHO_AM_I 0x0F    ///< Device identification, will read 0x33
#define LIS2DH_WHO_AM_I_VAL 0x33    ///< Expected value of the WHO_AM_I register

#define LIS2DH_REG_TEMP_CFG 0x1F          ///< Temperature configuration; 0 to disable, 0xC0 to enable.
#define LIS2DH_TEMP_CFG_VAL_ENABLE 0xC0   ///< Value for LIS2DH_REG_TEMP_CFG that enables temperature sensing.
#define LIS2DH_TEMP_CFG_VAL_DISABLE 0x00  ///< Value for LIS2DH_REG_TEMP_CFG that disables temperature sensing.

#define LIS2DH_REG_CTRL1 0x20               ///< CTRL_REG1 in the data sheet.
#define LIS2DH_CTRL1_VAL_XEN  0b00000001    ///< Enable X-axis
#define LIS2DH_CTRL1_VAL_YEN  0b00000010    ///< Enable Y-axis
#define LIS2DH_CTRL1_VAL_ZEN  0b00000100    ///< Enable Z-axis
#define LIS2DH_CTRL1_VAL_LPEN 0b00001000    ///< Enable low power mode
#define LIS2DH_CTRL1_VAL_ODR_POWERDOWN 0    ///< Power down
#define LIS2DH_CTRL1_VAL_ODR_1HZ        (LIS2DH_DATA_RATE_1_HZ << 4)
#define LIS2DH_CTRL1_VAL_ODR_10HZ       (LIS2DH_DATA_RATE_10_HZ << 4)
#define LIS2DH_CTRL1_VAL_ODR_25HZ       (LIS2DH_DATA_RATE_25_HZ << 4)
#define LIS2DH_CTRL1_VAL_ODR_50HZ       (LIS2DH_DATA_RATE_50_HZ << 4)
#define LIS2DH_CTRL1_VAL_ODR_100HZ      (LIS2DH_DATA_RATE_100_HZ << 4)
#define LIS2DH_CTRL1_VAL_ODR_200HZ      (LIS2DH_DATA_RATE_200_HZ << 4)
#define LIS2DH_CTRL1_VAL_ODR_400HZ      (LIS2DH_DATA_RATE_400_HZ << 4)
#define LIS2DH_CTRL1_VAL_ODR_LP1620HZ   (LIS2DH_DATA_RATE_LP1620HZ << 4)
#define LIS2DH_CTRL1_VAL_ODR_LP5376HZ   (LIS2DH_DATA_RATE_LP5376HZ << 4)

#define LIS2DH_REG_CTRL2 0x21

#define LIS2DH_REG_CTRL3 0x22
#define LIS2DH_CTRL3_VAL_I1_CLICK   0b10000000
#define LIS2DH_CTRL3_VAL_I1_AOI1    0b01000000
#define LIS2DH_CTRL3_VAL_I1_AOI2    0b00100000
#define LIS2DH_CTRL3_VAL_I1_DRDY1   0b00010000
#define LIS2DH_CTRL3_VAL_I1_DRDY2   0b00001000
#define LIS2DH_CTRL3_VAL_I1_WTM     0b00000100
#define LIS2DH_CTRL3_VAL_I1_OVERRUN 0b00000010

#define LIS2DH_REG_CTRL4 0x23
#define LIS2DH_CTRL4_VAL_BDU        0b10000000
#define LIS2DH_CTRL4_VAL_BLE        0b01000000
#define LIS2DH_CTRL4_VAL_RANGE_2G   (LIS2DH_RANGE_2_G << 4)
#define LIS2DH_CTRL4_VAL_RANGE_4G   (LIS2DH_RANGE_4_G << 4)
#define LIS2DH_CTRL4_VAL_RANGE_8G   (LIS2DH_RANGE_8_G << 4)
#define LIS2DH_CTRL4_VAL_RANGE_16G  (LIS2DH_RANGE_16_G << 4)
#define LIS2DH_CTRL4_VAL_HR         0b00001000
#define LIS2DH_CTRL4_VAL_ST0        0b00000000
#define LIS2DH_CTRL4_VAL_ST1        0b00000000

#define LIS2DH_REG_CTRL5 0x24
#define LIS2DH_CTRL5_VAL_BOOT       0b10000000
#define LIS2DH_CTRL5_VAL_FIFO_EN    0b01000000
#define LIS2DH_CTRL5_VAL_LIR_INT1   0b00001000
#define LIS2DH_CTRL5_VAL_D4D_INT1   0b00000100
#define LIS2DH_CTRL5_VAL_LIR_INT2   0b00000010
#define LIS2DH_CTRL5_VAL_D4D_INT2   0b00000001

#define LIS2DH_REG_CTRL6 0x25
#define LIS2DH_CTRL6_VAL_I2_CLICK   0b10000000
#define LIS2DH_CTRL6_VAL_I2_INT1    0b01000000
#define LIS2DH_CTRL6_VAL_I2_INT2    0b00100000
#define LIS2DH_CTRL6_VAL_BOOT_I2    0b00010000
#define LIS2DH_CTRL6_VAL_P2_ACT     0b00001000
#define LIS2DH_CTRL6_VAL_H_L_ACTIVE 0b00000000

#define LIS2DH_REG_REFERENCE 0x26

#define LIS2DH_REG_STATUS 0x27
#define LIS2DH_STATUS_VAL_ZYXOR 0b10000000
#define LIS2DH_STATUS_VAL_ZOR   0b01000000
#define LIS2DH_STATUS_VAL_YOR   0b00100000
#define LIS2DH_STATUS_VAL_XOR   0b00010000
#define LIS2DH_STATUS_VAL_ZYXDA 0b00001000
#define LIS2DH_STATUS_VAL_ZDA   0b00000100
#define LIS2DH_STATUS_VAL_YDA   0b00000010
#define LIS2DH_STATUS_VAL_XDA   0b00000001

#define LIS2DH_REG_OUT_X_L 0x28
#define LIS2DH_REG_OUT_X_H 0x29
#define LIS2DH_REG_OUT_Y_L 0x2A
#define LIS2DH_REG_OUT_Y_H 0x2B
#define LIS2DH_REG_OUT_Z_L 0x2C
#define LIS2DH_REG_OUT_Z_H 0x2D

#define LIS2DH_REG_FIFO_CTRL 0x2E
#define LIS2DH_REG_FIFO_SRC 0x2F
#define LIS2DH_REG_INT1_CFG 0x30
#define LIS2DH_REG_INT1_SRC 0x31
#define LIS2DH_REG_INT1_THS 0x32
#define LIS2DH_REG_INT1_DUR 0x33
#define LIS2DH_REG_INT2_CFG 0x34
#define LIS2DH_REG_INT2_SRC 0x35
#define LIS2DH_REG_INT2_THS 0x36
#define LIS2DH_REG_INT2_DUR 0x37
#define LIS2DH_REG_CLICK_CFG 0x38
#define LIS2DH_REG_CLICK_SRC 0x39
#define LIS2DH_REG_CLICK_THS 0x3A
#define LIS2DH_REG_TIME_LIMIT 0x3B
#define LIS2DH_REG_TIME_LATENCY 0x3C
#define LIS2DH_REG_TIME_WINDOW 0x3D

#endif // LIS2DH_H
