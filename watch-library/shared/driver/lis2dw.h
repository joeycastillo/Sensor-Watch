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

#ifndef LIS2DW_H
#define LIS2DW_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int16_t x;
    int16_t y;
    int16_t z;
} lis2dw_reading_t;

typedef struct {
    float x;
    float y;
    float z;
} lis2dw_acceleration_measurement_t;

typedef struct {
    int8_t count;
    lis2dw_reading_t readings[32];
} lis2dw_fifo_t;

typedef enum {
  LIS2DW_DATA_RATE_POWERDOWN = 0,
  LIS2DW_DATA_RATE_LOWEST = 0b0001, // 12.5 Hz in high performance mode, 1.6 Hz in low power
  LIS2DW_DATA_RATE_12_5_HZ = 0b0010,
  LIS2DW_DATA_RATE_25_HZ = 0b0011,
  LIS2DW_DATA_RATE_50_HZ = 0b0100,
  LIS2DW_DATA_RATE_100_HZ = 0b0101,
  LIS2DW_DATA_RATE_200_HZ = 0b0110,
  LIS2DW_DATA_RATE_HP_400_HZ = 0b0111,
  LIS2DW_DATA_RATE_HP_800_HZ = 0b1000,
  LIS2DW_DATA_RATE_HP_1600_HZ = 0b1001,

} lis2dw_data_rate_t;

typedef enum {
  LIS2DW_MODE_LOW_POWER = 0b00,
  LIS2DW_MODE_HIGH_PERFORMANCE = 0b01,
  LIS2DW_MODE_ON_DEMAND = 0b10,
} lis2dw_mode_t;

typedef enum {
  LIS2DW_FIFO_MODE_OFF = 0b000,
  LIS2DW_FIFO_MODE_COLLECT_AND_STOP = 0b001,
  LIS2DW_FIFO_MODE_CONTINUOUS_TO_FIFO = 0b011,
  LIS2DW_FIFO_MODE_BYPASS_TO_CONTINUOUS = 0b100,
  LIS2DW_FIFO_MODE_COLLECT_CONTINUOUS = 0b110,
} lis2dw_fifo_mode_t;

typedef enum {
  LIS2DW_LP_MODE_1 = 0b00, // 12-bit
  LIS2DW_LP_MODE_2 = 0b01, // 14-bit
  LIS2DW_LP_MODE_3 = 0b10, // 14-bit
  LIS2DW_LP_MODE_4 = 0b11, // 14-bit
} lis2dw_low_power_mode_t;

typedef enum {
  LIS2DW_BANDWIDTH_FILTER_DIV2 = 0b00,
  LIS2DW_BANDWIDTH_FILTER_DIV4 = 0b01,
  LIS2DW_BANDWIDTH_FILTER_DIV10 = 0b10,
  LIS2DW_BANDWIDTH_FILTER_DIV20 = 0b11,
} lis2dw_bandwidth_filtering_mode_t;

typedef enum {
  LIS2DW_FILTER_LOW_PASS = 0,
  LIS2DW_FILTER_HIGH_PASS = 1,
} lis2dw_filter_t;

typedef enum {
  LIS2DW_RANGE_16_G = 0b11, // +/- 16g
  LIS2DW_RANGE_8_G = 0b10,  // +/- 8g
  LIS2DW_RANGE_4_G = 0b01,  // +/- 4g
  LIS2DW_RANGE_2_G = 0b00   // +/- 2g (default value)
} lis2dw_range_t;

typedef enum {
  LIS2DW_INTERRUPT_SRC_SLEEP_CHANGE = 0b00100000,
  LIS2DW_INTERRUPT_SRC_6D           = 0b00010000,
  LIS2DW_INTERRUPT_SRC_DOUBLE_TAP   = 0b00001000,
  LIS2DW_INTERRUPT_SRC_SINGLE_TAP   = 0b00000100,
  LIS2DW_INTERRUPT_SRC_WU           = 0b00000010,
  LIS2DW_INTERRUPT_SRC_FF           = 0b00000001
} lis2dw_interrupt_source;

typedef enum {
  LIS2DW_WAKEUP_SRC_FREEFALL    = 0b00100000,
  LIS2DW_WAKEUP_SRC_SLEEP_STATE = 0b00010000,
  LIS2DW_WAKEUP_SRC_WAKEUP      = 0b00001000,
  LIS2DW_WAKEUP_SRC_WAKEUP_X    = 0b00000100,
  LIS2DW_WAKEUP_SRC_WAKEUP_Y    = 0b00000010,
  LIS2DW_WAKEUP_SRC_WAKEUP_Z    = 0b00000001
} lis2dw_wakeup_source;

// Assumes SA0 is high; if low, its 0x18
#define LIS2DW_ADDRESS (0x19)

#define LIS2DW_REG_OUT_TEMP_L 0x0D  ///< Temperature data low bit
#define LIS2DW_REG_OUT_TEMP_H 0x0E  ///< Temperature data high bit

#define LIS2DW_REG_WHO_AM_I 0x0F    ///< Device identification, will read 0x44
#define LIS2DW_WHO_AM_I_VAL 0x44    ///< Expected value of the WHO_AM_I register

#define LIS2DW_REG_CTRL1 0x20               ///< CTRL_REG1 in the data sheet.
#define LIS2DW_CTRL1_VAL_ODR_POWERDOWN          0
#define LIS2DW_CTRL1_VAL_ODR_LOWEST             (LIS2DW_DATA_RATE_LOWEST << 4)
#define LIS2DW_CTRL1_VAL_ODR_12_5HZ             (LIS2DW_DATA_RATE_12_5_HZ << 4)
#define LIS2DW_CTRL1_VAL_ODR_25HZ               (LIS2DW_DATA_RATE_25_HZ << 4)
#define LIS2DW_CTRL1_VAL_ODR_50HZ               (LIS2DW_DATA_RATE_50_HZ << 4)
#define LIS2DW_CTRL1_VAL_ODR_100HZ              (LIS2DW_DATA_RATE_100_HZ << 4)
#define LIS2DW_CTRL1_VAL_ODR_200HZ              (LIS2DW_DATA_RATE_200_HZ << 4)
#define LIS2DW_CTRL1_VAL_ODR_HP_400_HZ          (LIS2DW_DATA_RATE_HP_400_HZ << 4)
#define LIS2DW_CTRL1_VAL_ODR_HP_800_HZ          (LIS2DW_DATA_RATE_HP_800_HZ << 4)
#define LIS2DW_CTRL1_VAL_ODR_HP_1600_HZ         (LIS2DW_DATA_RATE_HP_1600_HZ << 4)
#define LIS2DW_CTRL1_VAL_MODE_LOW_POWER         (LIS2DW_MODE_LOW_POWER << 2)
#define LIS2DW_CTRL1_VAL_MODE_HIGH_PERFORMANCE  (LIS2DW_MODE_HIGH_PERFORMANCE << 2)
#define LIS2DW_CTRL1_VAL_MODE_ON_DEMAND         (LIS2DW_MODE_ON_DEMAND << 2)
#define LIS2DW_CTRL1_VAL_LPMODE_1               (LIS2DW_LP_MODE_1 << 0)
#define LIS2DW_CTRL1_VAL_LPMODE_2               (LIS2DW_LP_MODE_2 << 0)
#define LIS2DW_CTRL1_VAL_LPMODE_3               (LIS2DW_LP_MODE_3 << 0)
#define LIS2DW_CTRL1_VAL_LPMODE_4               (LIS2DW_LP_MODE_4 << 0)

#define LIS2DW_REG_CTRL2 0x21
#define LIS2DW_CTRL2_VAL_BOOT       0b10000000
#define LIS2DW_CTRL2_VAL_SOFT_RESET 0b01000000
#define LIS2DW_CTRL2_VAL_CS_PU_DISC 0b00010000
#define LIS2DW_CTRL2_VAL_BDU        0b00001000
#define LIS2DW_CTRL2_VAL_IF_ADD_INC 0b00000100

#define LIS2DW_REG_CTRL3 0x22
#define LIS2DW_CTRL3_VAL_SELF_TEST_POS  0b10000000
#define LIS2DW_CTRL3_VAL_SELF_TEST_NEG  0b01000000
#define LIS2DW_CTRL3_VAL_PP_OD          0b00100000
#define LIS2DW_CTRL3_VAL_LIR            0b00010000
#define LIS2DW_CTRL3_VAL_H_L_ACTIVE     0b00001000
#define LIS2DW_CTRL3_VAL_SLP_MODE_SEL   0b00000010
#define LIS2DW_CTRL3_VAL_SLP_MODE_1     0b00000001

#define LIS2DW_REG_CTRL4_INT1 0x23
#define LIS2DW_CTRL4_INT1_6D          0b10000000
#define LIS2DW_CTRL4_INT1_SINGLE_TAP  0b01000000
#define LIS2DW_CTRL4_INT1_WU          0b00100000
#define LIS2DW_CTRL4_INT1_FF          0b00010000
#define LIS2DW_CTRL4_INT1_TAP         0b00001000
#define LIS2DW_CTRL4_INT1_DIFF5       0b00000100
#define LIS2DW_CTRL4_INT1_FTH         0b00000010
#define LIS2DW_CTRL4_INT1_DRDY        0b00000001

#define LIS2DW_REG_CTRL5_INT2 0x24
#define LIS2DW_CTRL5_INT2_SLEEP_STATE 0b10000000
#define LIS2DW_CTRL5_INT2_SLEEP_CHG   0b01000000
#define LIS2DW_CTRL5_INT2_BOOT        0b00100000
#define LIS2DW_CTRL5_INT2_DRDY_T      0b00010000
#define LIS2DW_CTRL5_INT2_OVR         0b00001000
#define LIS2DW_CTRL5_INT2_DIFF5       0b00000100
#define LIS2DW_CTRL5_INT2_FTH         0b00000010
#define LIS2DW_CTRL5_INT2_DRDY        0b00000001

#define LIS2DW_REG_CTRL6 0x25
#define LIS2DW_CTRL6_VAL_BANDWIDTH_DIV2   (LIS2DW_BANDWIDTH_FILTER_DIV2 << 6)
#define LIS2DW_CTRL6_VAL_BANDWIDTH_DIV4   (LIS2DW_BANDWIDTH_FILTER_DIV4 << 6)
#define LIS2DW_CTRL6_VAL_BANDWIDTH_DIV10  (LIS2DW_BANDWIDTH_FILTER_DIV10 << 6)
#define LIS2DW_CTRL6_VAL_BANDWIDTH_DIV20  (LIS2DW_BANDWIDTH_FILTER_DIV20 << 6)
#define LIS2DW_CTRL6_VAL_RANGE_2G         (LIS2DW_RANGE_2_G << 4)
#define LIS2DW_CTRL6_VAL_RANGE_4G         (LIS2DW_RANGE_4_G << 4)
#define LIS2DW_CTRL6_VAL_RANGE_8G         (LIS2DW_RANGE_8_G << 4)
#define LIS2DW_CTRL6_VAL_RANGE_16G        (LIS2DW_RANGE_16_G << 4)
#define LIS2DW_CTRL6_VAL_FDS_LOW          (LIS2DW_FILTER_LOW_PASS << 3)
#define LIS2DW_CTRL6_VAL_FDS_HIGH         (LIS2DW_FILTER_HIGH_PASS << 3)
#define LIS2DW_CTRL6_VAL_LOW_NOISE        0b00000100

#define LIS2DW_REG_OUT_TEMP 0x26

#define LIS2DW_REG_STATUS 0x27
#define LIS2DW_STATUS_VAL_FIFO_THS    0b10000000
#define LIS2DW_STATUS_VAL_WU_IA       0b01000000
#define LIS2DW_STATUS_VAL_SLEEP_STATE 0b00100000
#define LIS2DW_STATUS_VAL_DOUBLE_TAP  0b00010000
#define LIS2DW_STATUS_VAL_SINGLE_TAP  0b00001000
#define LIS2DW_STATUS_VAL_6D_IA       0b00000100
#define LIS2DW_STATUS_VAL_FF_IA       0b00000010
#define LIS2DW_STATUS_VAL_DRDY        0b00000001

#define LIS2DW_REG_OUT_X_L 0x28
#define LIS2DW_REG_OUT_X_H 0x29
#define LIS2DW_REG_OUT_Y_L 0x2A
#define LIS2DW_REG_OUT_Y_H 0x2B
#define LIS2DW_REG_OUT_Z_L 0x2C
#define LIS2DW_REG_OUT_Z_H 0x2D

#define LIS2DW_REG_FIFO_CTRL 0x2E
#define LIS2DW_FIFO_CTRL_MODE_OFF                   (LIS2DW_FIFO_MODE_OFF << 5)
#define LIS2DW_FIFO_CTRL_MODE_COLLECT_AND_STOP      (LIS2DW_FIFO_MODE_COLLECT_AND_STOP << 5)
#define LIS2DW_FIFO_CTRL_MODE_CONTINUOUS_TO_FIFO    (LIS2DW_FIFO_MODE_CONTINUOUS_TO_FIFO << 5)
#define LIS2DW_FIFO_CTRL_MODE_BYPASS_TO_CONTINUOUS  (LIS2DW_FIFO_MODE_BYPASS_TO_CONTINUOUS << 5)
#define LIS2DW_FIFO_CTRL_MODE_COLLECT_CONTINUOUS    (LIS2DW_FIFO_MODE_COLLECT_CONTINUOUS << 5)
#define LIS2DW_FIFO_CTRL_FTH                        (0b00011111)

#define LIS2DW_REG_FIFO_SAMPLE 0x2F
#define LIS2DW_FIFO_SAMPLE_THRESHOLD (1 << 7)
#define LIS2DW_FIFO_SAMPLE_OVERRUN (1 << 6)
#define LIS2DW_FIFO_SAMPLE_COUNT (0b00111111)

#define LIS2DW_REG_TAP_THS_X 0x30
#define LIS2DW_REG_TAP_THS_Y 0x31
#define LIS2DW_REG_TAP_THS_Z 0x32
#define LIS2DW_REG_INT1_DUR 0x33

#define LIS2DW_REG_WAKE_UP_THS 0x34
#define LIS2DW_WAKE_UP_THS_VAL_TAP_EVENT_ENABLED 0b10000000
#define LIS2DW_WAKE_UP_THS_VAL_SLEEP_ON          0b01000000

#define LIS2DW_REG_WAKE_UP_DUR 0x35
#define LIS2DW_REG_FREE_FALL 0x36
#define LIS2DW_REG_STATUS_DUP 0x37

#define LIS2DW_REG_WAKE_UP_SRC 0x38
#define LIS2DW_WAKE_UP_SRC_VAL_FF_IA          0b00100000
#define LIS2DW_WAKE_UP_SRC_VAL_SLEEP_STATE_IA 0b00010000
#define LIS2DW_WAKE_UP_SRC_VAL_WU_IA          0b00001000
#define LIS2DW_WAKE_UP_SRC_VAL_X_WU           0b00000100
#define LIS2DW_WAKE_UP_SRC_VAL_Y_WU           0b00000010
#define LIS2DW_WAKE_UP_SRC_VAL_Z_WU           0b00000001

#define LIS2DW_REG_TAP_SRC 0x39
#define LIS2DW_TAP_SRC_VAL_TAP_IA     0b01000000
#define LIS2DW_TAP_SRC_VAL_SINGLE_TAP 0b00100000
#define LIS2DW_TAP_SRC_VAL_DOUBLE_TAP 0b00010000
#define LIS2DW_TAP_SRC_VAL_TAP_SIGN   0b00001000
#define LIS2DW_TAP_SRC_VAL_X_TAP      0b00000100
#define LIS2DW_TAP_SRC_VAL_Y_TAP      0b00000010
#define LIS2DW_TAP_SRC_VAL_Z_TAP      0b00000001

#define LIS2DW_REG_SIXD_SRC 0x3A
#define LIS2DW_WAKE_UP_SRC_VAL_6D_IA  0b01000000
#define LIS2DW_WAKE_UP_SRC_VAL_ZH     0b00100000
#define LIS2DW_WAKE_UP_SRC_VAL_ZL     0b00010000
#define LIS2DW_WAKE_UP_SRC_VAL_YH     0b00001000
#define LIS2DW_WAKE_UP_SRC_VAL_YL     0b00000100
#define LIS2DW_WAKE_UP_SRC_VAL_XH     0b00000010
#define LIS2DW_WAKE_UP_SRC_VAL_XL     0b00000001

#define LIS2DW_REG_ALL_INT_SRC 0x3B
#define LIS2DW_REG_ALL_INT_SRC_SLEEP_CHANGE_IA  0b00100000
#define LIS2DW_REG_ALL_INT_SRC_6D_IA            0b00010000
#define LIS2DW_REG_ALL_INT_SRC_DOUBLE_TAP       0b00001000
#define LIS2DW_REG_ALL_INT_SRC_SINGLE_TAP       0b00000100
#define LIS2DW_REG_ALL_INT_SRC_WU_IA            0b00000010
#define LIS2DW_REG_ALL_INT_SRC_FF_IA            0b00000001

#define LIS2DW_REG_X_OFS_USR 0x3C
#define LIS2DW_REG_Y_OFS_USR 0x3D
#define LIS2DW_REG_Z_OFS_USR 0x3E

#define LIS2DW_REG_CTRL7 0x3F
#define LIS2DW_CTRL7_VAL_DRDY_PULSED        0b10000000
#define LIS2DW_CTRL7_VAL_INT2_ON_INT1       0b01000000
#define LIS2DW_CTRL7_VAL_INTERRUPTS_ENABLE  0b00100000
#define LIS2DW_CTRL7_VAL_USR_OFF_ON_OUT     0b00010000
#define LIS2DW_CTRL7_VAL_USR_OFF_ON_WU      0b00001000
#define LIS2DW_CTRL7_VAL_USR_OFF_W          0b00000100
#define LIS2DW_CTRL7_VAL_HP_REF_MODE        0b00000010
#define LIS2DW_CTRL7_VAL_LPASS_ON6D         0b00000001

bool lis2dw_begin(void);

uint8_t lis2dw_get_device_id(void);

bool lis2dw_have_new_data(void);

lis2dw_reading_t lis2dw_get_raw_reading(void);

lis2dw_acceleration_measurement_t lis2dw_get_acceleration_measurement(lis2dw_reading_t *out_reading);

uint16_t lis2dw_get_temperature(void);

void lis2dw_set_range(lis2dw_range_t range);

lis2dw_range_t lis2dw_get_range(void);

void lis2dw_set_data_rate(lis2dw_data_rate_t dataRate);

lis2dw_data_rate_t lis2dw_get_data_rate(void);

void lis2dw_set_filter_type(lis2dw_filter_t filter);

lis2dw_filter_t lis2dw_get_filter_type(void);

void lis2dw_set_bandwidth_filtering(lis2dw_bandwidth_filtering_mode_t bwfilter);

lis2dw_bandwidth_filtering_mode_t lis2dw_get_bandwidth_filtering(void);

void lis2dw_set_mode(lis2dw_mode_t mode);

lis2dw_mode_t lis2dw_get_mode(void);

void lis2dw_set_low_power_mode(lis2dw_low_power_mode_t mode);

lis2dw_low_power_mode_t lis2dw_get_low_power_mode(void);

void lis2dw_set_low_noise_mode(bool on);

bool lis2dw_get_low_noise_mode(void);

void lis2dw_disable_fifo(void);

void lis2dw_enable_fifo(void);

bool lis2dw_read_fifo(lis2dw_fifo_t *fifo_data);

void lis2dw_clear_fifo(void);

void lis2dw_configure_wakeup_int1(uint8_t threshold, bool latch, bool active_state);

lis2dw_interrupt_source lis2dw_get_interrupt_source(void);

lis2dw_wakeup_source lis2dw_get_wakeup_source(void);

#endif // LIS2DW_H
