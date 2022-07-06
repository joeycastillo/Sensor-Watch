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
    static int16_t loop = 0;

    if (watch_get_pin_level(BTN_ALARM)) {
        button = 1;
    }
    if (watch_get_pin_level(BTN_LIGHT)) {
        button = 2;
    }
    if (watch_get_pin_level(BTN_MODE)) {
        button = 3;
    }

    if (button != last_button) {
        last_button = button;
        watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
    }

    for(int com = 0; com < 3; com++) {
        for(int seg = 0; seg < 24; seg++) {
            if (loop > 0) {
                if (seg % 2 == 0) watch_set_pixel(com, seg);
                else watch_set_pixel(com, seg);
            } else {
                if (seg % 2 == 1) watch_set_pixel(com, seg);
                else watch_set_pixel(com, seg);
            }
        }
    }

    return true;
}
