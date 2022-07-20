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
#define SI1133_REG_REV_ID 0x02
#define SI1133_REG_HOSTIN3 0x07
#define SI1133_REG_HOSTIN2 0x08
#define SI1133_REG_HOSTIN1 0x09
#define SI1133_REG_HOSTIN0 0x0a
#define SI1133_REG_COMMAND 0x0B
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

#define SI1133_PARAM_QUERY_MASK 0x40 // 0b01......
#define SI1133_PARAM_SET_MASK 0x80 // 0b10......

#define SI1133_PARAM_CHAN_LIST 0x01
#define SI1133_PARAM_ADCCONFIG0 0x02
#define SI1133_PARAM_ADCSENS0 0x03
#define SI1133_PARAM_ADCPOST0 0x04
#define SI1133_PARAM_MEASCONFIG0 0x05
#define SI1133_PARAM_ADCCONFIG1 0x06
#define SI1133_PARAM_ADCSENS1 0x07
#define SI1133_PARAM_ADCPOST1 0x08
#define SI1133_PARAM_MEASCONFIG1 0x09
#define SI1133_PARAM_ADCCONFIG2 0x0a
#define SI1133_PARAM_ADCSENS2 0x0b
#define SI1133_PARAM_ADCPOST2 0x0c
#define SI1133_PARAM_MEASCONFIG2 0x0d
#define SI1133_PARAM_ADCCONFIG3 0x0e
#define SI1133_PARAM_ADCSENS3 0x0f
#define SI1133_PARAM_ADCPOST3 0x10
#define SI1133_PARAM_MEASCONFIG3 0x11
#define SI1133_PARAM_ADCCONFIG4 0x12
#define SI1133_PARAM_ADCSENS4 0x13
#define SI1133_PARAM_ADCPOST4 0x14
#define SI1133_PARAM_MEASCONFIG4 0x15
#define SI1133_PARAM_ADCCONFIG5 0x16
#define SI1133_PARAM_ADCSENS5 0x17
#define SI1133_PARAM_ADCPOST5 0x18
#define SI1133_PARAM_MEASCONFIG5 0x19

#define SI1133_ADCMUX_SMALL_IR 0x00
#define SI1133_ADCMUX_MEDIUM_IR 0x01
#define SI1133_ADCMUX_LARGE_IR 0x02
#define SI1133_ADCMUX_WHITE 0x0b
#define SI1133_ADCMUX_LARGE_WHITE 0x0d
#define SI1133_ADCMUX_UV 0x18
#define SI1133_ADCMUX_UV_DEEP 0x19

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
        printf("part_id: 0x%02x\r\n", part_id);
        uint8_t hw_id = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HW_ID);
        printf("hw_id: 0x%02x\r\n", hw_id);
        uint8_t rev_id = watch_i2c_read8(SI1133_ADDR, SI1133_REG_REV_ID);
        printf("rev_id: 0x%02x\r\n", rev_id);

        // do a reset by writing 0x0B 0x00 
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, SI1133_CMD_RESET);
        // this writes to register 0x0B the value 0x00 (which is a reset)
        //we should then be able to read RESPONSE0 (0x11) to check some of the bits
        uint8_t response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
        printf("response: 0x%02x\r\n", response);

        /*
         * ok so plan is
         *
         * 1. enable channel 1
         *  a. measure rate needs to be set? no, only for autonomous mode
         *  b. chan_list bit 1 needs set
         * 2. set up channel 1 registers to take UV reading
         * 3. set force mode to take 1 reading?
         * 4. read values out of HOSTOUTx
         */

        // setting parameter is done via writing value to HOSTIN0 then writting param addres to COMMAND
        // the data written to command is 0b10xxxxxx where the 6 low bits are the param address
        
        // --- set CHAN_LIST
        printf("writing chan list stuff\r\n");
        uint8_t chan_list = 1; //enable channel 1
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_HOSTIN0, chan_list);
        uint8_t chan_list_addr = SI1133_PARAM_SET_MASK | SI1133_PARAM_CHAN_LIST;
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, chan_list_addr);
        response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
        printf("response: 0x%02x\r\n", response);

        // --- set ADCCONFIG
        // decim_rate [6:5], adcmux [4:0]
        uint8_t adcconfig = (0 << 5) | SI1133_ADCMUX_WHITE;
        printf("adcconfig: 0x%02x\r\n", adcconfig);
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_HOSTIN0, adcconfig);
        uint8_t adcconfig_addr = SI1133_PARAM_SET_MASK | SI1133_PARAM_ADCCONFIG0;
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, adcconfig_addr);
        response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
        printf("response: 0x%02x\r\n", response);


        // --- set ADCSENS
        uint8_t adcsens = 0;
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_HOSTIN0, adcsens);
        uint8_t adcsens_addr = SI1133_PARAM_SET_MASK | SI1133_PARAM_ADCSENS0;
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, adcsens_addr);
        response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
        printf("response: 0x%02x\r\n", response);

        // --- set ADCPOST
        uint8_t adcpost = 0;
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_HOSTIN0, adcpost);
        uint8_t adcpost_addr = SI1133_PARAM_SET_MASK | SI1133_PARAM_ADCPOST0;
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, adcpost_addr);
        response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
        printf("response: 0x%02x\r\n", response);

        // --- set MEASCONFIG
        uint8_t measconfig = 0;
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_HOSTIN0, measconfig);
        uint8_t measconfig_addr = SI1133_PARAM_SET_MASK | SI1133_PARAM_MEASCONFIG0;
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, measconfig_addr);
        response = watch_i2c_read8(SI1133_ADDR, SI1133_REG_RESPONSE0);
        printf("response: 0x%02x\r\n", response);

        // FORCE mode
        watch_i2c_write8(SI1133_ADDR, SI1133_REG_COMMAND, SI1133_CMD_FORCE);

        // read IRQ_STATUS until 0x01?
        printf("checking IRQ_STATUS\r\n");
        uint8_t irq_status;
        while(irq_status != 0x01) {
            irq_status = watch_i2c_read8(SI1133_ADDR, SI1133_REG_IRQ_STATUS);
            printf("IRQ_STATUS: 0x%02x\r\n", irq_status);
        }
        uint8_t hostout0 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT0);
        uint8_t hostout1 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT1);
        printf("hostout0: 0x%02x\r\n", hostout0);
        printf("hostout1: 0x%02x\r\n", hostout1);
    }
    return true;
}
