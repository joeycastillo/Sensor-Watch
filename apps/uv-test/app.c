#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "watch.h"

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
    tick = true;
}

#define SI1133_ADDR 0x55 //alt is 0x52

#define SI1133_REG_PART_ID 0x00
#define SI1133_REG_HW_ID 0x01
#define SI1133_REG_REV_ID 0x02

void app_init(void) {
    watch_enable_display();
    watch_display_string("UV  Strean", 0);

    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_ALARM, cb_alarm_pressed, INTERRUPT_TRIGGER_RISING);

    watch_enable_i2c();

    watch_rtc_register_periodic_callback(cb_tick, 1);
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
    if (tick) {
        tick = false;
        printf("TICK\r\n");

        printf("Init\r\n");
        uint8_t part_id = watch_i2c_read8(SI1133_ADDR, SI1133_REG_PART_ID);
        printf("part_id: %02x\r\n", part_id);
        uint8_t hw_id = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HW_ID);
        printf("hw_id: %02x\r\n", hw_id);
        uint8_t rev_id = watch_i2c_read8(SI1133_ADDR, SI1133_REG_REV_ID);
        printf("rev_id: %02x\r\n", rev_id);

        // do a reset by writing 0x0B 0x00 
        // this writes to register 0x0B the value 0x00 (which is a reset)
        //we should then be able to read RESPONSE0 (0x11) to check some of the bits

    }
    return true;
}
