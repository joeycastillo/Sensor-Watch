#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "watch.h"
#include "watch_extint.h"
#include "si1133.h"


void fatal_error(char *error_msg, uint8_t error_no, uint8_t extra);

static void cb_light_pressed(void) {
}

static void cb_mode_pressed(void) {
}

static void cb_alarm_pressed(void) {
}

/*
static bool si1133_ready = false;

static void cb_si1133_int(void) {
    si1133_ready = true;
}
*/


static char buf[13] = {0};


void app_init(void) {
}

void app_wake_from_backup(void) {
    printf("waking from backup sleep\r\n");
}

void app_setup(void) {
    watch_enable_leds();

    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_ALARM, cb_alarm_pressed, INTERRUPT_TRIGGER_RISING);


    watch_enable_display();

    si1133_init();

    /*
     * Interrupts are not working at the moment and I can't seem to figure out why
     * Symptoms:
     *  - callback fires immediately after registering it, but doesn't seem to fire again after that?
     *  - callback seems to wake device from sleep (but callback isn't triggered) and measurement isn't ready when this happens
     *  - pin does seem to go low before when I do poll the status register
     *
     *  ----
     *
     *  It's possible this was only firing once because it was in app_init, not setup, and I need to re-register the callback everytime?
    watch_register_extwake_callback(A2, cb_si1133_int, false); // trigger on falling edge
    watch_enable_pull_up(A2);
    */

}

void app_prepare_for_standby(void) {
    printf("going to standby sleep\r\n");
}

void app_wake_from_standby(void) {
    printf("waking from standby sleep\r\n");
}

void fatal_error(char *error_msg, uint8_t error_no, uint8_t extra) {
    watch_set_colon();
    sprintf(buf, "    %02x%0x   ", error_no, extra);
    watch_display_string(buf, 0);
    uint8_t loops = 255;
    while(loops--) {
        printf("%s\r\n", error_msg);

        watch_set_indicator(WATCH_INDICATOR_BELL);
        watch_set_led_yellow();

        delay_ms(500);
        watch_clear_all_indicators();
        watch_set_led_color(0,0);
        delay_ms(500);
    }
    watch_enter_sleep_mode();
}


uint8_t readings = 0;
uint8_t error_count = 0;

bool app_loop(void) {
    printf("--- tick\r\n");

    if(!si1133_start_measurement()) {
        error_count++;
        goto end;
    }

    uint32_t ticks = 0;
    uint8_t irq_status = watch_i2c_read8(SI1133_ADDR, SI1133_REG_IRQ_STATUS);
    while(irq_status != 0x01) {
        delay_ms(10);
        ticks++;
        if (ticks > 1000) {
            error_count++;
            printf("timeout waiting for reading!!\r\n");
            break;
        }
        irq_status = watch_i2c_read8(SI1133_ADDR, SI1133_REG_IRQ_STATUS);
    }
    printf("ticks %ud\r\n", ticks);

    uint8_t hostout0 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT0);
    uint8_t hostout1 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT1);
    uint16_t adccount = hostout0 << 8 | hostout1;
    sprintf(buf, "%02x%02x%04x",error_count, readings, adccount);
    watch_display_string(buf, 0);
    printf("reading: %04x\r\n", adccount);
    printf("reading count: %02x\r\n", readings);
    printf("error count: %02x\r\n", error_count);
    readings++;

end:
    delay_ms(1000);
    return true;
}
