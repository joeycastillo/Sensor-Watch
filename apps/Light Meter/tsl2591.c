#include "tsl2591.h"
#include "watch_i2c.h"

bool tsl2591_init() {
    uint8_t device_id = watch_i2c_read8(TSL2591_ADDRESS, TSL2591_REGISTER_DEVICE_ID | TSL2591_COMMAND_BIT);
    if (device_id != 0x50) return false;

    tsl2591_set_gain(TSL2591_CONTROL_GAIN_LOW);
    tsl2591_set_integration_time(TSL2591_CONTROL_INTEGRATIONTIME_100MS);
    watch_i2c_write8(TSL2591_ADDRESS, TSL2591_REGISTER_ENABLE | TSL2591_COMMAND_BIT, TSL2591_ENABLE_POWERON | TSL2591_ENABLE_AEN);

    return true;
}

void tsl2591_set_gain(TSL2591Control gain) {
    uint8_t control = watch_i2c_read8(TSL2591_ADDRESS, TSL2591_REGISTER_CONTROL | TSL2591_COMMAND_BIT);
    control &= 0b11001111;
    control |= gain;
    watch_i2c_write8(TSL2591_ADDRESS, TSL2591_REGISTER_CONTROL | TSL2591_COMMAND_BIT, control);
}

void tsl2591_set_integration_time(TSL2591Control integration_time) {
    uint8_t control = watch_i2c_read8(TSL2591_ADDRESS, TSL2591_REGISTER_CONTROL | TSL2591_COMMAND_BIT);
    control &= 0b11111000;
    control |= integration_time;
    watch_i2c_write8(TSL2591_ADDRESS, TSL2591_REGISTER_CONTROL | TSL2591_COMMAND_BIT, control);
}

uint16_t tsl2591_get_visible_light_reading() {
    uint16_t full = make_le_16(watch_i2c_read16(TSL2591_ADDRESS, TSL2591_REGISTER_CHAN0_LOW | TSL2591_COMMAND_BIT));
    uint16_t infrared = make_le_16(watch_i2c_read16(TSL2591_ADDRESS, TSL2591_REGISTER_CHAN1_LOW | TSL2591_COMMAND_BIT));
    printf("Full Spectrum : %d\n", full);
    printf("Infrared      : %d\n", infrared);
    int32_t result = full - infrared;

    return (result > 0) ? (uint16_t)result : 0;
}