#include <stdio.h>
#include <string.h>
#include "watch.h"

typedef struct ApplicationState {
    bool play;
} ApplicationState;

ApplicationState application_state;


void cb_alarm_pressed(void) {
    application_state.play = true;
}

void app_init(void) {
    memset(&application_state, 0, sizeof(application_state));
}

void app_wake_from_backup(void) {
}

void app_write_to_backup(void) {
}

void app_setup(void) {
    watch_register_extwake_callback(BTN_ALARM, cb_alarm_pressed, true);

    watch_enable_display();

    watch_enable_buzzer();
}

void app_prepare_for_standby(void) {
    watch_display_string("  rains ", 2);
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    if (application_state.play) {
        printf("Playing song...\n");
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
        for(size_t i = 0, count = sizeof(rains) / sizeof(rains[0]); i < count; i++) {
            char buf[9] = {0};
            if (rains[i] == BUZZER_NOTE_REST) {
                printf("rest for %d ms\n", durations[i]);
                sprintf(buf, "%2drESt  ", i);
            } else {
                printf("playing note %2d: %3.0f Hz for %d ms\n", i, 1000000.0 / (float)NotePeriods[rains[i]], durations[i]);
                sprintf(buf, "%2d%6d", i, NotePeriods[rains[i]]);
            }
            watch_display_string(buf, 2);
            watch_buzzer_play_note(rains[i], durations[i]);
        }
        printf("done!\n\n");
    }

    return true;
}
