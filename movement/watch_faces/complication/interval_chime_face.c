/*
 * MIT License
 *
 * Copyright (c) 2026 Stebbs
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interval_chime_face.h"
#include "watch.h"

static const uint8_t intervals[] = {1, 5, 10, 15, 30};
#define NUM_INTERVALS 5

static void play_power_up_sound(void) {
    watch_buzzer_play_note(BUZZER_NOTE_C5, 100);
    watch_buzzer_play_note(BUZZER_NOTE_E5, 100);
    watch_buzzer_play_note(BUZZER_NOTE_G5, 100);
    watch_buzzer_play_note(BUZZER_NOTE_C6, 200);
}

static void play_power_down_sound(void) {
    watch_buzzer_play_note(BUZZER_NOTE_C6, 100);
    watch_buzzer_play_note(BUZZER_NOTE_G5, 100);
    watch_buzzer_play_note(BUZZER_NOTE_E5, 100);
    watch_buzzer_play_note(BUZZER_NOTE_C5, 200);
}

static void update_display(interval_chime_state_t *state) {
    watch_clear_display();

    if (state->is_active) {
        char buf[11];
        uint8_t interval = intervals[state->interval_index];
        sprintf(buf, "rE P0n%02d", interval);
        watch_display_string(buf, 0);
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_display_string("rE P  0FF", 0);
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
}

void interval_chime_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(interval_chime_state_t));
        memset(*context_ptr, 0, sizeof(interval_chime_state_t));
    }
}

void interval_chime_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    interval_chime_state_t *state = (interval_chime_state_t *)context;

    watch_date_time date_time = watch_rtc_get_date_time();
    state->last_minute = date_time.unit.minute;

    update_display(state);
}

bool interval_chime_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    interval_chime_state_t *state = (interval_chime_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            update_display(state);
            break;

        case EVENT_TICK:
            if (state->is_active) {
                watch_date_time date_time = watch_rtc_get_date_time();
                if (date_time.unit.minute != state->last_minute) {
                    state->last_minute = date_time.unit.minute;
                    uint8_t interval = intervals[state->interval_index];
                    if (date_time.unit.minute % interval == 0) {
                        movement_play_signal();
                    }
                }
            }
            break;

        case EVENT_ALARM_BUTTON_UP:
            state->is_active = !state->is_active;

            if (state->is_active) {
                play_power_up_sound();
            } else {
                play_power_down_sound();
            }
            update_display(state);
            break;

        case EVENT_LIGHT_BUTTON_UP:
            state->interval_index = (state->interval_index + 1) % NUM_INTERVALS;
            update_display(state);
            movement_illuminate_led();
            break;

        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;

        case EVENT_LOW_ENERGY_UPDATE:
            break;

        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void interval_chime_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
