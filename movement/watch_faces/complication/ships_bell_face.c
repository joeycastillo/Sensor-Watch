/*
 * MIT License
 *
 * Copyright (c) 2023 buckket
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
#include <stdio.h>
#include <string.h>
#include "ships_bell_face.h"

static void ships_bell_ring() {
    watch_date_time date_time = watch_rtc_get_date_time();

    date_time.unit.hour %= 4;
    date_time.unit.hour = date_time.unit.hour == 0 && date_time.unit.minute < 30 ? 4 : date_time.unit.hour;

    for (uint8_t i = 0; i < date_time.unit.hour; i++) {
        watch_buzzer_play_note(BUZZER_NOTE_C8, 75);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 75);
        watch_buzzer_play_note(BUZZER_NOTE_C8, 100);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 250);
    }

    if (date_time.unit.minute >= 30 ? 1 : 0) {
        watch_buzzer_play_note(BUZZER_NOTE_C8, 100);
    }
}

static void ships_bell_draw(ships_bell_state_t *state) {
    char buf[8];

    if (state->on_watch) {
        sprintf(buf, "%d", state->on_watch);
    } else {
        sprintf(buf, " ");
    }

    watch_date_time date_time = watch_rtc_get_date_time();
    date_time.unit.hour %= 4;

    sprintf(buf + 1, " %d%02d%02d", date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
    watch_display_string(buf, 3);
}

void ships_bell_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(ships_bell_state_t));
        memset(*context_ptr, 0, sizeof(ships_bell_state_t));
    }
}

void ships_bell_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;

    ships_bell_state_t *state = (ships_bell_state_t *) context;
    if (state->bell_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
    else watch_clear_indicator(WATCH_INDICATOR_BELL);

    watch_display_string("SB", 0);
    watch_set_colon();
}

bool ships_bell_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;

    ships_bell_state_t *state = (ships_bell_state_t *) context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            ships_bell_draw(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->bell_enabled = !state->bell_enabled;
            if (state->bell_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
            else watch_clear_indicator(WATCH_INDICATOR_BELL);
            break;
        case EVENT_ALARM_LONG_PRESS:
            state->on_watch = (state->on_watch + 1) % 4;
            ships_bell_draw(state);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        case EVENT_BACKGROUND_TASK:
            if (watch_is_buzzer_or_led_enabled()) {
                ships_bell_ring();
            } else {
                watch_enable_buzzer();
                ships_bell_ring();
                watch_disable_buzzer();
            }
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void ships_bell_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool ships_bell_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;

    ships_bell_state_t *state = (ships_bell_state_t *) context;
    if (!state->bell_enabled) return false;

    watch_date_time date_time = watch_rtc_get_date_time();
    if (!(date_time.unit.minute == 0 || date_time.unit.minute == 30)) return false;

    date_time.unit.hour %= 12;
    switch (state->on_watch) {
        case 1:
            return (date_time.unit.hour >= 4 && date_time.unit.hour < 8) ||
                   (date_time.unit.hour == 8 && date_time.unit.minute == 0);
        case 2:
            return (date_time.unit.hour >= 8 && date_time.unit.hour < 12) ||
                   (date_time.unit.hour == 0 && date_time.unit.minute == 0);
        case 3:
            return (date_time.unit.hour >= 0 && date_time.unit.hour < 4) ||
                   (date_time.unit.hour == 4 && date_time.unit.minute == 0);
        default:
            return true;
    }
}
