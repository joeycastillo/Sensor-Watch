/*
 * MIT License
 *
 * Copyright (c) 2023 Per Waagø
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
#include "tuning_tones_face.h"

/*

    This face plays a tone that can be used as a reference when tuning
    musical instrument.

    - The alarm button (short press) starts and stops the tone
    - The light button (short press) changes which note is played. The name
    of the note is shown in the display.

*/

typedef struct Note {
    BuzzerNote note;
    char * name;
} Note;

static Note notes[] = {
    { .note = BUZZER_NOTE_C5, .name = "C " },
    { .note = BUZZER_NOTE_C5SHARP_D5FLAT, .name = "Db" },
    { .note = BUZZER_NOTE_D5, .name = "D " },
    { .note = BUZZER_NOTE_D5SHARP_E5FLAT, .name = "Eb" },
    { .note = BUZZER_NOTE_E5, .name = "E " },
    { .note = BUZZER_NOTE_F5, .name = "F " },
    { .note = BUZZER_NOTE_F5SHARP_G5FLAT, .name = "Gb" },
    { .note = BUZZER_NOTE_G5, .name = "G " },
    { .note = BUZZER_NOTE_G5SHARP_A5FLAT, .name = "Ab" },
    { .note = BUZZER_NOTE_A5, .name = "A " },
    { .note = BUZZER_NOTE_A5SHARP_B5FLAT, .name = "Bb" },
    { .note = BUZZER_NOTE_B5, .name = "B " },
};

static size_t note_count = sizeof notes / sizeof *notes;

static void draw(tuning_tones_state_t *state)
{
    watch_display_string(notes[state->note_ind].name, 8);
}

void tuning_tones_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        tuning_tones_state_t *state = malloc(sizeof *state);
        memset(state, 0, sizeof *state);
        state->note_ind = 9;
        *context_ptr = state;
    }
}

void tuning_tones_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

static void update_buzzer(const tuning_tones_state_t *state)
{
    if (state->playing) {
        watch_set_buzzer_off();
        watch_set_buzzer_period(NotePeriods[notes[state->note_ind].note]);
        watch_set_buzzer_on();
    }
}

bool tuning_tones_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    tuning_tones_state_t *state = (tuning_tones_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            draw(state);
            break;
        case EVENT_TICK:
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            state->note_ind++;
            if (state->note_ind == note_count) {
                state->note_ind = 0;
            }
            update_buzzer(state);
            draw(state);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            state->playing = !state->playing;
            if (!state->playing) {
                watch_set_buzzer_off();
            } else {
                update_buzzer(state);
            }
        case EVENT_ALARM_BUTTON_UP:
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return !state->playing;
}

void tuning_tones_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    tuning_tones_state_t *state = (tuning_tones_state_t *)context;

    if (state->playing) {
        state->playing = false;
        watch_set_buzzer_off();
    }
}
