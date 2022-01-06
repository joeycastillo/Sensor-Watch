#include <stdio.h>
#include <string.h>
#include "watch.h"

bool even = false;
bool beep = false;
uint32_t i = 0;

static void cb_tick(void) {
    beep = true;
    even = !even;
}

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    watch_enable_display();

    watch_enable_buzzer();

    watch_enable_digital_output(A0);
    watch_enable_digital_output(SCL);
    watch_enable_digital_output(SDA);
    watch_enable_digital_output(A1);
    watch_enable_digital_output(A2);
    watch_enable_digital_output(A3);
    watch_enable_digital_output(A4);

    watch_enable_digital_input(BTN_ALARM);
    watch_enable_digital_input(BTN_LIGHT);
    watch_enable_digital_input(BTN_MODE);
    watch_enable_pull_down(BTN_ALARM);
    watch_enable_pull_down(BTN_LIGHT);
    watch_enable_pull_down(BTN_MODE);

    watch_set_pin_level(A0, false);
    watch_set_pin_level(SCL, false);
    watch_set_pin_level(SDA, false);
    watch_set_pin_level(A1, false);
    watch_set_pin_level(A2, false);
    watch_set_pin_level(A3, false);
    watch_set_pin_level(A4, false);

    watch_rtc_register_periodic_callback(cb_tick, 2);
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    char buf[14];

    if (beep) watch_buzzer_play_note(BUZZER_NOTE_E5, 100);

    if (even) {
        printf("Flashing even lights\n");
        #ifdef WATCH_SWAP_LED_PINS
        sprintf(buf, "WT%2d'blu_E", (uint8_t)(i++ % 40));
        #else
        sprintf(buf, "WT%2d'Grn_E", (uint8_t)(i++ % 40));
        #endif
        watch_set_led_green();
        watch_set_pin_level(A0, true);
        watch_set_pin_level(SCL, false);
        watch_set_pin_level(SDA, true);
        watch_set_pin_level(A1, false);
        watch_set_pin_level(A2, true);
        watch_set_pin_level(A3, false);
        watch_set_pin_level(A4, true);
    } else {
        printf("Flashing odd lights\n");
        sprintf(buf, "WT%2d-red~O", (uint8_t)(i++ % 40));
        watch_display_string(buf, 0);
        watch_set_led_red();
        watch_set_pin_level(A0, false);
        watch_set_pin_level(SCL, true);
        watch_set_pin_level(SDA, false);
        watch_set_pin_level(A1, true);
        watch_set_pin_level(A2, false);
        watch_set_pin_level(A3, true);
        watch_set_pin_level(A4, false);
    }
    if (watch_get_pin_level(BTN_ALARM)) {
        buf[2] = 'a';
        buf[3] = 'L';
    }
    if (watch_get_pin_level(BTN_LIGHT)) {
        buf[2] = '1';
        buf[3] = 'i';
    }
    if (watch_get_pin_level(BTN_MODE)) {
        buf[2] = '-';
        buf[3] = 'O';
    }
    watch_display_string(buf, 0);

    return true;
}
