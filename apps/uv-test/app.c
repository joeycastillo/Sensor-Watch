#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "watch.h"
#include "watch_extint.h"
#include "si1133.h"


void fatal_error(char *error_msg, si1133_fatal_error_codes error_no, uint8_t extra);

static bool needs_setup = true;

static si1133_adcmux current_mux = SI1133_ADCMUX_UV;
static void cb_light_pressed(void) {
    switch (current_mux) {
        case SI1133_ADCMUX_SMALL_IR:
            current_mux = SI1133_ADCMUX_MEDIUM_IR;
            break;
        case SI1133_ADCMUX_MEDIUM_IR:
            current_mux = SI1133_ADCMUX_LARGE_IR;
            break;
        case SI1133_ADCMUX_LARGE_IR:
            current_mux = SI1133_ADCMUX_WHITE;
            break;
        case SI1133_ADCMUX_WHITE:
            current_mux = SI1133_ADCMUX_LARGE_WHITE;
            break;
        case SI1133_ADCMUX_LARGE_WHITE:
            current_mux = SI1133_ADCMUX_UV;
            break;
        case SI1133_ADCMUX_UV:
            current_mux = SI1133_ADCMUX_UV_DEEP;
            break;
        case SI1133_ADCMUX_UV_DEEP:
            current_mux = SI1133_ADCMUX_SMALL_IR;
            break;
    }
    needs_setup = true;
}

static si1133_hw_gain current_hw_gain = SI1133_HW_GAIN_5;
static void cb_mode_pressed(void) {
    current_hw_gain = (current_hw_gain + 1) % 12;
    needs_setup = true;
}

static si1133_sw_gain current_sw_gain = SI1133_SW_GAIN_0;
static void cb_alarm_pressed(void) {
    current_sw_gain = (current_sw_gain + 1) % 8;
    needs_setup = true;
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

void fatal_error(char *error_msg, si1133_fatal_error_codes error_no, uint8_t extra) {
    watch_set_colon();
    sprintf(buf, "    %02x%0x   ", error_no, extra);
    watch_display_string(buf, 0);
    uint8_t loops = 60;
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

bool flipflop = true;
bool app_loop(void) {
    printf("--- tick\r\n");

    if(flipflop) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
    flipflop = !flipflop;

    if (needs_setup) {
        si1133_configure_channel(
                SI1133_CHAN_0,
                current_mux,
                SI1133_DECIM_0,
                SI1133_RANGING_OFF,
                current_hw_gain,
                current_sw_gain,
                SI1133_16_BIT,
                SI1133_POST_SHIFT_0,
                SI1133_THRESH_DISABLE,
                SI1133_COUNTER_DISABLE
                );
        needs_setup = false;

        sprintf(buf, "    %02x%02x%02x", current_mux, current_hw_gain, current_sw_gain);
        watch_display_string(buf,0);
        delay_ms(1500);
    }


    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    watch_display_string("          ", 0);

    si1133_start_measurement();
    si1133_response0_status status;
    status = si1133_check_errors();
    if (status) {
        if (status == SI1133_ERR_SATURATION) {
            watch_display_string("    overfl", 0);
            //TODO maybe reset if this happens
            goto out;
        } else {
            fatal_error("failed to start mesaurement", SI1133_FORCE_FAIL, status);
        }
    }


    uint32_t ticks = 0;
    uint32_t delay = 50;
    const uint32_t timeout_s = 10;
    uint8_t irq_status = watch_i2c_read8(SI1133_ADDR, SI1133_REG_IRQ_STATUS);
    while(irq_status != 0x01) {
        delay_ms(delay);
        ticks++;
        if (ticks & 0x80) {
            watch_set_colon();
        } else {
            watch_clear_colon();
        }
        if ((ticks * delay) > (timeout_s * 1000)) {
            fatal_error("timeout!", SI1133_TIMEOUT, 0);
            break;
        }
        irq_status = watch_i2c_read8(SI1133_ADDR, SI1133_REG_IRQ_STATUS);
    }
    printf("ticks %ud\r\n", ticks);

    uint8_t hostout0 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT0);
    uint8_t hostout1 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT1);
    uint16_t adccount = hostout0 << 8 | hostout1;
    sprintf(buf, "%02x%02x%04x  ",readings, current_mux, adccount);
    watch_display_string(buf, 0);
    printf("reading: %04x\r\n", adccount);
    printf("reading count: %02x\r\n", readings);
    printf("current mux: %02x\r\n", current_mux);
    readings++;

out:
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    delay_ms(2000);

    return false;
}
