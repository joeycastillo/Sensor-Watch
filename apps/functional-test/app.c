#include <stdio.h>
#include <string.h>
#include "watch.h"

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    watch_enable_display();

    watch_enable_buzzer();

    watch_enable_digital_output(RED);
    watch_enable_digital_output(GREEN);
    watch_enable_digital_input(BTN_ALARM);
    watch_enable_digital_input(BTN_LIGHT);
    watch_enable_digital_input(BTN_MODE);
    watch_enable_pull_down(BTN_ALARM);
    watch_enable_pull_down(BTN_LIGHT);
    watch_enable_pull_down(BTN_MODE);
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    static int last_button = 0;
    static int button = 0;
    static int8_t loop = 0;

    watch_set_pin_level(GREEN, false);
    watch_set_pin_level(RED, false);
    if (watch_get_pin_level(BTN_ALARM)) {
        watch_set_pin_level(GREEN, true);
        button = 1;
    } else if (watch_get_pin_level(BTN_LIGHT)) {
        watch_set_pin_level(RED, true);
        button = 2;
    } else if (watch_get_pin_level(BTN_MODE)) {
        watch_set_pin_level(GREEN, true);
        watch_set_pin_level(RED, true);
        button = 3;
    }

    if (button != last_button) {
        last_button = button;
        watch_buzzer_play_note(BUZZER_NOTE_C8, 100);
    }

    static const bool segmap[3][24] = {
       //0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1}
    };

    for(int com = 0; com < 3; com++) {
        for(int seg = 0; seg < 24; seg++) {
            if (segmap[com][seg]) (loop >= 0) ? watch_set_pixel(com, seg) : watch_clear_pixel(com, seg);
            else (loop < 0) ? watch_set_pixel(com, seg) : watch_clear_pixel(com, seg);
        }
    }

    loop++;

    return false;
}
