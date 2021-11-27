#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "watch.h"
#include "lis2dh.h"

// This application displays data from the old Sensor Watch Motion sensor board.
// Note that this board required A0 to be set high to power the sensor.
// Future accelerometer boards will be powered directly from VCC.
// Also note that this board has its INT1 pin wired to A1, which is not an external
// wake pin. Future accelerometer boards will wire interrupt pins to A2 and A4.

uint8_t axis = 0;

void cb_light_pressed() {
    axis = 1;
}

void cb_mode_pressed() {
    axis = 2;
}

void cb_alarm_pressed() {
    axis = 3;
}

void app_init() {
    gpio_set_pin_direction(A0, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(A0, GPIO_PIN_FUNCTION_OFF);
    gpio_set_pin_level(A0, true);

    watch_enable_display();

    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_ALARM, cb_alarm_pressed, INTERRUPT_TRIGGER_RISING);

    watch_enable_i2c();

    lis2dh_begin();

    lis2dh_set_range(LIS2DH_RANGE_2_G);
    lis2dh_set_data_rate(LIS2DH_DATA_RATE_10_HZ);
}

void app_wake_from_backup() {
}

void app_setup() {
}

void app_prepare_for_standby() {
}

void app_wake_from_standby() {
}

bool app_loop() {
    if (lis2dh_have_new_data()) {
        lis2dh_reading reading;
        lis2dh_acceleration_measurement measurement = lis2dh_get_acceleration_measurement(&reading);

        // printf("%d,%d,%d\n", reading.x, reading.y, reading.z);
        printf("%f,%f,%f\n", measurement.x, measurement.y, measurement.z);

        char buf[11] = {0};
        switch (axis) {
            case 1:
                sprintf(buf, "AC X%-6d", reading.x);
                break;
            case 2:
                sprintf(buf, "AC Y%-6d", reading.y);
                break;
            case 3:
                sprintf(buf, "AC Z%-6d", reading.z);
                break;
            default:
                sprintf(buf, "    %2d%2d%2d", abs(reading.x >> 9), abs(reading.y >> 9), abs(reading.z >> 9));
                if (reading.x < 0) buf[0] = '_';
                if (reading.y < 0) buf[1] = '_';
                if (reading.z < 0) buf[3] = '_';
                break;
        }

        watch_display_string(buf, 0);
    }

    return false;
}
