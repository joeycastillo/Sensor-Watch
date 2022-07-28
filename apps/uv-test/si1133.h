#include <stdint.h>
#include <stdlib.h>

#define SI1133_ADDR 0x55 //alt is 0x52

#define SI1133_REG_PART_ID 0x00
#define SI1133_REG_HW_ID 0x01
#define SI1133_REG_REV_ID 0x02
#define SI1133_REG_REV_ID 0x02
#define SI1133_REG_HOSTIN3 0x07
#define SI1133_REG_HOSTIN2 0x08
#define SI1133_REG_HOSTIN1 0x09
#define SI1133_REG_HOSTIN0 0x0a
#define SI1133_REG_COMMAND 0x0b
#define SI1133_REG_IRQENABLE 0x0f
#define SI1133_REG_RESPONSE1 0x10
#define SI1133_REG_RESPONSE0 0x11
#define SI1133_REG_IRQ_STATUS 0x12
#define SI1133_REG_HOSTOUT0 0x13
#define SI1133_REG_HOSTOUT1 0x14
#define SI1133_REG_HOSTOUT2 0x15
#define SI1133_REG_HOSTOUT3 0x16
#define SI1133_REG_HOSTOUT4 0x17
#define SI1133_REG_HOSTOUT5 0x18
#define SI1133_REG_HOSTOUT6 0x19
#define SI1133_REG_HOSTOUT7 0x1a
#define SI1133_REG_HOSTOUT8 0x1b
#define SI1133_REG_HOSTOUT9 0x1c
#define SI1133_REG_HOSTOUT10 0x1d
#define SI1133_REG_HOSTOUT11 0x1e
#define SI1133_REG_HOSTOUT12 0x1f
#define SI1133_REG_HOSTOUT13 0x20
#define SI1133_REG_HOSTOUT14 0x21
#define SI1133_REG_HOSTOUT15 0x22
#define SI1133_REG_HOSTOUT16 0x23
#define SI1133_REG_HOSTOUT17 0x24
#define SI1133_REG_HOSTOUT18 0x25
#define SI1133_REG_HOSTOUT19 0x26
#define SI1133_REG_HOSTOUT20 0x27
#define SI1133_REG_HOSTOUT21 0x28
#define SI1133_REG_HOSTOUT22 0x29
#define SI1133_REG_HOSTOUT23 0x2a
#define SI1133_REG_HOSTOUT24 0x2b
#define SI1133_REG_HOSTOUT25 0x2c

#define SI1133_CMD_RESET_CMD_CTR 0x00
#define SI1133_CMD_RESET 0x01
#define SI1133_CMD_FORCE 0x11
#define SI1133_CMD_PAUSE 0x12
#define SI1133_CMD_START 0x13

#define SI1133_CMD_STATUS_ERROR 0x10
#define SI1133_CMD_STATUS_ERROR_MASK 0x0f

#define SI1133_PARAM_QUERY_MASK 0x40 // 0b01......
#define SI1133_PARAM_SET_MASK 0x80 // 0b10......

typedef enum {
    SI1133_CHAN_0 = 0,
    SI1133_CHAN_1 = 1,
    SI1133_CHAN_2 = 2,
    SI1133_CHAN_3 = 3,
    SI1133_CHAN_4 = 4,
    SI1133_CHAN_5 = 5,
} si1133_channels;

typedef enum {
  SI1133_PARAM_CHAN_LIST = 0x01, 
  SI1133_PARAM_ADCCONFIG0 = 0x02,
  SI1133_PARAM_ADCSENS0 = 0x03,
  SI1133_PARAM_ADCPOST0 = 0x04,
  SI1133_PARAM_MEASCONFIG0= 0x05,
  SI1133_PARAM_ADCCONFIG1 = 0x06,
  SI1133_PARAM_ADCSENS1 = 0x07,
  SI1133_PARAM_ADCPOST1 = 0x08,
  SI1133_PARAM_MEASCONFIG1 = 0x09,
  SI1133_PARAM_ADCCONFIG2 = 0x0a,
  SI1133_PARAM_ADCSENS2 = 0x0b,
  SI1133_PARAM_ADCPOST2 = 0x0c,
  SI1133_PARAM_MEASCONFIG2 = 0x0d,
  SI1133_PARAM_ADCCONFIG3 = 0x0e,
  SI1133_PARAM_ADCSENS3 = 0x0f,
  SI1133_PARAM_ADCPOST3 = 0x10,
  SI1133_PARAM_MEASCONFIG3 = 0x11,
  SI1133_PARAM_ADCCONFIG4 = 0x12,
  SI1133_PARAM_ADCSENS4 = 0x13,
  SI1133_PARAM_ADCPOST4 = 0x14,
  SI1133_PARAM_MEASCONFIG4 = 0x15,
  SI1133_PARAM_ADCCONFIG5 = 0x16,
  SI1133_PARAM_ADCSENS5 = 0x17,
  SI1133_PARAM_ADCPOST5 = 0x18,
  SI1133_PARAM_MEASCONFIG5 = 0x19,
} si1133_params;

typedef enum {
  SI1133_ADCMUX_SMALL_IR = 0x00,
  SI1133_ADCMUX_MEDIUM_IR = 0x01,
  SI1133_ADCMUX_LARGE_IR =  0x02,
  SI1133_ADCMUX_WHITE =  0x0b,
  SI1133_ADCMUX_LARGE_WHITE = 0x0d,
  SI1133_ADCMUX_UV = 0x18,
  SI1133_ADCMUX_UV_DEEP = 0x19,
} si1133_adcmux;

typedef enum {
    SI1133_DECIM_0 = 0,
    SI1133_DECIM_1 = 1,
    SI1133_DECIM_2 = 2,
    SI1133_DECIM_3 = 3,
} si1133_decim;

typedef enum {
    SI1133_HW_GAIN_0 = 0,
    SI1133_HW_GAIN_1 = 1,
    SI1133_HW_GAIN_2 = 2,
    SI1133_HW_GAIN_3 = 3,
    SI1133_HW_GAIN_4 = 4,
    SI1133_HW_GAIN_5 = 5,
    SI1133_HW_GAIN_6 = 6,
    SI1133_HW_GAIN_7 = 7,
    SI1133_HW_GAIN_8 = 8,
    SI1133_HW_GAIN_9 = 9,
    SI1133_HW_GAIN_10 = 10,
    SI1133_HW_GAIN_11 = 11,
} si1133_hw_gain;

typedef enum {
    SI1133_RANGING_OFF = 0,
    SI1133_RANGING_ON = 1
} si1133_ranging;

typedef enum {
    SI1133_SW_GAIN_0 = 0,
    SI1133_SW_GAIN_1 = 1,
    SI1133_SW_GAIN_2 = 2,
    SI1133_SW_GAIN_3 = 3,
    SI1133_SW_GAIN_4 = 4,
    SI1133_SW_GAIN_5 = 5,
    SI1133_SW_GAIN_6 = 6,
    SI1133_SW_GAIN_7 = 7,
} si1133_sw_gain;

typedef enum {
    SI1133_16_BIT = 0,
    SI1133_24_BIT = 1
} si1133_measurement_size;

typedef enum {
    SI1133_POST_SHIFT_0 = 0,
    SI1133_POST_SHIFT_1 = 1,
    SI1133_POST_SHIFT_2 = 2,
    SI1133_POST_SHIFT_3 = 3,
} si1133_post_shift;

typedef enum {
    SI1133_THRESH_DISABLE = 0,
    SI1133_THRESH_0 = 1,
    SI1133_THRESH_1 = 2,
    SI1133_THRESH_2 = 3,
} si1133_threshold_config;

typedef enum {
    SI1133_COUNTER_DISABLE = 0,
    SI1133_MEASCOUNT_1 = 1,
    SI1133_MEASCOUNT_2 = 2,
    SI1133_MEASCOUNT_3 = 3,
} si1133_count_config;

void si1133_init(void);
bool si1133_start_measurement(void);

/**
 * @brief configure channel
 */
int si1133_configure_channel(
        si1133_channels channel,
        si1133_adcmux adcmux,
        si1133_decim decim_rate,
        si1133_ranging ranging,
        si1133_hw_gain hw_gain,
        si1133_sw_gain sw_gain,
        si1133_measurement_size measurement_size,
        si1133_post_shift post_shift,
        si1133_threshold_config thresh_config,
        si1133_count_config count_config
        );

/**
 * @brief set value for given param in si1133 internal parameter table
 * @param param address of parameter you want to set (6 bits long)
 * @param value value you want set for given parameter
 * @details
 * See section 5.1 of the si1133 datasheet for more details
 */
int si1133_set_param(si1133_params param, uint8_t value);
