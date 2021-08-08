#include <stdio.h>
#include <string.h>
#include "watch.h"

typedef struct ApplicationState {
    bool play;
    bool debounce_wait;
} ApplicationState;

ApplicationState application_state;


void cb_alarm_pressed() {
    if (application_state.debounce_wait) return;
    application_state.debounce_wait = true;
    application_state.play = true;
}

void app_init() {
    memset(&application_state, 0, sizeof(application_state));
}

void app_wake_from_deep_sleep() {
}

void app_setup() {
    watch_register_button_callback(BTN_ALARM, cb_alarm_pressed);

    watch_enable_display();

    watch_enable_buzzer();
}

void app_prepare_for_sleep() {
    watch_display_string("  rains ", 2);
}

void app_wake_from_sleep() {
}

bool app_loop() {
    if (application_state.play) {
        const BuzzerNote rains[] = {
            BUZZER_NOTE_A4,
            BUZZER_NOTE_F5,
            BUZZER_NOTE_REST,
            BUZZER_NOTE_A4,
            BUZZER_NOTE_E5,
            BUZZER_NOTE_REST,
            BUZZER_NOTE_A4,
            BUZZER_NOTE_F5,
            BUZZER_NOTE_G5,
            BUZZER_NOTE_E5,
            BUZZER_NOTE_REST,
            BUZZER_NOTE_A4,
            BUZZER_NOTE_G5,
            BUZZER_NOTE_F5,
            BUZZER_NOTE_E5,
            BUZZER_NOTE_D5,
            BUZZER_NOTE_E5,
            BUZZER_NOTE_REST,

            BUZZER_NOTE_A5,
            BUZZER_NOTE_REST,
            BUZZER_NOTE_A5,
            BUZZER_NOTE_A5SHARP_B5FLAT,
            BUZZER_NOTE_G5,
            BUZZER_NOTE_REST,
            BUZZER_NOTE_C5,
            BUZZER_NOTE_A5,
            BUZZER_NOTE_A5SHARP_B5FLAT,
            BUZZER_NOTE_G5,
            BUZZER_NOTE_REST,
            BUZZER_NOTE_D5,
            BUZZER_NOTE_A5SHARP_B5FLAT,
            BUZZER_NOTE_A5,
            BUZZER_NOTE_G5,
            BUZZER_NOTE_F5,
            BUZZER_NOTE_E5,
        };
        const uint16_t durations[] = {
            200,
            600,
            100,
            200,
            600,
            100,
            200,
            400,
            400,
            600,
            100,
            200,
            400,
            400,
            400,
            400,
            800,
            600,

            200,
            50,
            400,
            200,
            400,
            100,
            200,
            400,
            400,
            400,
            200,
            200,
            400,
            400,
            400,
            400,
            900,
        };
        application_state.play = false;
        for(size_t i = 0; i < sizeof(rains); i++) {
            char buf[9] = {0};
            if (rains[i] == BUZZER_NOTE_REST) {
                sprintf(buf, "%2drESt  ", i);
            } else {
                sprintf(buf, "%2d%6d", i, NotePeriods[rains[i]]);
            }
            watch_display_string(buf, 2);
            watch_buzzer_play_note(rains[i], durations[i]);
        }
    }

    // Wait a moment to debounce button input
    delay_ms(250);
    application_state.debounce_wait = false;

    return true;
}
