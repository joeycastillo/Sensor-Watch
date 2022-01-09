#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "watch.h"
#include "lis2dw.h"

static void cb_light_pressed(void) {
}

static void cb_mode_pressed(void) {
}

static void cb_alarm_pressed(void) {
}

uint8_t interrupts = 0;
uint8_t last_interrupts = 0;
uint8_t ticks = 0;
char buf[13] = {0};

static void cb_tick(void) {
    if (!lis2dw_have_new_data()) return;

    lis2dw_reading raw_reading;
    lis2dw_acceleration_measurement measurement = lis2dw_get_acceleration_measurement(&raw_reading);
    (void)measurement;
    printf("%d, %d, %d\n", raw_reading.x, raw_reading.y, raw_reading.z);
}

void app_init(void) {
    watch_enable_display();
    watch_display_string("IN 0  0  0", 0);

    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_ALARM, cb_alarm_pressed, INTERRUPT_TRIGGER_RISING);

    watch_enable_i2c();
    lis2dw_begin();

    watch_rtc_register_periodic_callback(cb_tick, 16);
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    // TODO: interrupt configuration for LIS2DW
    sprintf(buf, "IN%2d%3d%3d", ticks, interrupts, last_interrupts);
    watch_display_string(buf, 0);

    return true;
}
