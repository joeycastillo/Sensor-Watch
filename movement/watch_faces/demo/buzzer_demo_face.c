/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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
#include "buzzer_demo_face.h"
#include "watch.h"
#include "watch_buzzer_seq.h"

// Demo sound sequences
static const int8_t _sound_seq_1[] = {BUZZER_NOTE_C7, 16, BUZZER_NOTE_E7, 16, BUZZER_NOTE_G7, 16, BUZZER_NOTE_C8, 24, 0};
static const int8_t _sound_seq_2[] = {BUZZER_NOTE_E6, 8, BUZZER_NOTE_REST, 4, BUZZER_NOTE_E6, 8, BUZZER_NOTE_REST, 4, BUZZER_NOTE_G6, 24, 0};
static const int8_t _sound_seq_3[] = {BUZZER_NOTE_D5, 30, BUZZER_NOTE_REST, 2, BUZZER_NOTE_D5, 30, BUZZER_NOTE_REST, 2, BUZZER_NOTE_D5, 32, 0};

static uint8_t _sequence;

static void _draw(void) {
    char buf[4];
    sprintf(buf, "%1d", _sequence + 1);
    watch_display_string(buf, 3);
}

void buzzer_demo_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    (void) *context_ptr;
}

void buzzer_demo_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    _sequence = 0;
    watch_display_string("Play", 4);
}

bool buzzer_demo_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            _sequence = (_sequence + 1) % 3;
            _draw();
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (_sequence) {
            case 0:
                watch_buzzer_play_sequence((int8_t *)_sound_seq_1, NULL);
                break;
            case 1:
                watch_buzzer_play_sequence((int8_t *)_sound_seq_2, NULL);
                break;
            case 2:
                watch_buzzer_play_sequence((int8_t *)_sound_seq_3, NULL);
                break;
            default:
                break;
            }
            break;
        case EVENT_ACTIVATE:
            _draw();
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            break;
    }

    return true;
}

void buzzer_demo_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
