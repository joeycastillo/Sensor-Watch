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
#define SI1133_REG_COMMAND 0x0B
#define SI1133_REG_RESPONSE0 0x10
#define SI1133_REG_RESPONSE1 0x11
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

#define SI1133_CMD_RESET 0x01

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
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, SI1133_CMD_RESET);
        // this writes to register 0x0B the value 0x00 (which is a reset)
        //we should then be able to read RESPONSE0 (0x11) to check some of the bits
        uint8_t response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
        printf("response: %02x\r\n", response);

    }
    return true;
}
