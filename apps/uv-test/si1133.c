#include <stdio.h>
#include "watch.h"
#include "si1133.h"

// TODO fix this? see uv-test/app.c
void fatal_error(char *error_msg, si1133_fatal_error_codes error_no, uint8_t extra);

void si1133_init(void) {
    watch_enable_i2c();

    uint8_t part_id = watch_i2c_read8(SI1133_ADDR, SI1133_REG_PART_ID);
    if (part_id != 0x33) {
        fatal_error("bad part id", SI1133_BAD_PART, 0);
    }
    watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, SI1133_CMD_RESET);
    si1133_response0_status status;
    status = si1133_check_errors();
    if (status) {
        fatal_error("failed to reset", SI1133_RESET_FAIL, status);
    }

    // from linux driver it looks like this is probably a mask for which channel should be enabled but it's not in datasheet
    watch_i2c_write8(SI1133_ADDR, SI1133_REG_IRQENABLE, 0xf);

    // --- set CHAN_LIST
    si1133_set_param(SI1133_PARAM_CHAN_LIST, 1);
    status = si1133_check_errors();
    if (status) {
        fatal_error("failed to enable channels", SI1133_NO_CHANNEL, status);
    }
}


uint8_t si1133_set_param(si1133_params param, uint8_t value) {
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

void si1133_start_measurement(void) {
    watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, SI1133_CMD_FORCE);
}

bool si1133_is_error_response(uint8_t response) {
    return response & SI1133_CMD_STATUS_ERROR;
}

uint8_t si1133_error_code_from_response(uint8_t response) {
    return response & SI1133_CMD_STATUS_ERROR_MASK;
}

si1133_response0_status si1133_check_errors(void) {
    uint8_t response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
    if (si1133_is_error_response(response)) {
        uint8_t raw_error_code = si1133_error_code_from_response(response);
        if (raw_error_code >= 0x10 && raw_error_code <= 0x13) {
            return (si1133_response0_status) raw_error_code;
        } else {
            return SI1133_ERR_UNKNOWN;
        }
    } else {
        return SI1133_NO_ERR;
    }
}
