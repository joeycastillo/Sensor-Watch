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
bool tick = false;
char buf[13] = {0};

static void cb_tick(void) {
    if (!lis2dw_have_new_data()) return;

    tick = true;
}

void app_init(void) {
    watch_enable_display();
    watch_display_string("AC  Strean", 0);

    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_ALARM, cb_alarm_pressed, INTERRUPT_TRIGGER_RISING);

    watch_enable_i2c();
    lis2dw_begin();
    lis2dw_set_data_rate(LIS2DW_DATA_RATE_25_HZ);
    lis2dw_set_range(LIS2DW_RANGE_4_G);
    lis2dw_set_low_noise_mode(true);
    lis2dw_enable_fifo();

    lis2dw_enable_fifo();

    watch_rtc_register_periodic_callback(cb_tick, 1);
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
}

void app_write_to_backup(void) {
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    if (tick) {
        tick = false;
        lis2dw_fifo_t fifo;
        lis2dw_read_fifo(&fifo);
        for(int i = 0; i < fifo.count; i++) {
            printf("%d, %d, %d, %d, %d\n", fifo.readings[i].x, fifo.readings[i].y, fifo.readings[i].z, i, fifo.count);
        }
    }

    return true;
}
