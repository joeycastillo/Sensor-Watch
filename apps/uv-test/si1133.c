#include <stdio.h>
#include "watch.h"
#include "si1133.h"

// TODO fix this? see uv-test/app.c
void fatal_error(char *error_msg, uint8_t error_no, uint8_t extra);

void si1133_init(void) {
    watch_enable_i2c();

    uint8_t part_id = watch_i2c_read8(SI1133_ADDR, SI1133_REG_PART_ID);
    if (part_id != 0x33) {
        fatal_error("bad part id", 0, 0);
    }
    watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, SI1133_CMD_RESET);
    uint8_t response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
    if (response & SI1133_CMD_STATUS_ERROR) {
        fatal_error("failed to reset", 1, response);
    }

    // from linux driver it looks like this is probably a mask for which channel should be enabled but it's not in datasheet
    watch_i2c_write8(SI1133_ADDR, SI1133_REG_IRQENABLE, 0xf);

    // --- set CHAN_LIST
    si1133_set_param(SI1133_PARAM_CHAN_LIST, 1);

    si1133_configure_channel(
            SI1133_CHAN_0,
            SI1133_ADCMUX_UV,
            SI1133_DECIM_0,
            SI1133_RANGING_OFF,
            SI1133_HW_GAIN_11,
            SI1133_SW_GAIN_4,
            SI1133_16_BIT,
            SI1133_POST_SHIFT_0,
            SI1133_THRESH_DISABLE,
            SI1133_COUNTER_DISABLE
            );
}


int si1133_set_param(si1133_params param, uint8_t value) {
    // setting parameter is done via writing value to HOSTIN0 then writting param addres to COMMAND
    // the data written to command is 0b10xxxxxx where the 6 low bits are the param address
    watch_i2c_write8(SI1133_ADDR, SI1133_REG_HOSTIN0, value);
    uint8_t param_addr = SI1133_PARAM_SET_MASK | param;
    watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, param_addr);
    uint8_t response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
    return response;
}

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
        ) {
    uint8_t addr_base = (4 * channel);
    
    // --- set ADCCONFIG
    // see 7.2.1 in datasheet
    // decim_rate [6:5], adcmux [4:0]
    uint8_t adcconfig = (decim_rate << 5) | adcmux;
    si1133_params adcconfig_param = (si1133_params) SI1133_PARAM_ADCCONFIG0 + addr_base; 
    si1133_set_param(adcconfig_param, adcconfig);

    // --- set ADCSENS
    // [7] ranging bit?
    // [6:5] software gain
    // [4:0] hardware gain
    //uint8_t adcsens = 0x0b;
    uint8_t adcsens = (ranging << 6) | (sw_gain << 4) | hw_gain;
    si1133_params adcsense_param = (si1133_params) SI1133_PARAM_ADCSENS0 + addr_base; 
    si1133_set_param(adcsense_param, adcsens);

    // --- set ADCPOST
    uint8_t adcpost = (measurement_size << 5) | (post_shift << 2) | thresh_config;
    si1133_params adcpost_param = (si1133_params) SI1133_PARAM_ADCPOST0 + addr_base; 
    si1133_set_param(adcpost_param, adcpost);

    // --- set MEASCONFIG
    uint8_t measconfig = count_config << 5;
    si1133_params measconfig_param = (si1133_params) SI1133_PARAM_MEASCONFIG0 + addr_base; 
    si1133_set_param(measconfig_param, measconfig);

    // TODO return response if error?
    return 0;
}

bool si1133_start_measurement(void) {
    watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, SI1133_CMD_FORCE);
    uint8_t response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
    if (response & SI1133_CMD_STATUS_ERROR) {
        printf("error! bad respones from start measurement: %02x\r\n", (response & SI1133_CMD_STATUS_ERROR_MASK));
        return false;
    }
    return true;
}
