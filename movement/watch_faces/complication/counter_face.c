/*
 * MIT License
 *
 * Copyright (c) 2022 Shogo Okamoto
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
#include "counter_face.h"
#include "watch.h"

void counter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(counter_state_t));
        memset(*context_ptr, 0, sizeof(counter_state_t));
    }
}

void counter_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool counter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;

    counter_state_t *state = (counter_state_t *)context;

    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->counter_idx++; // increment counter index
            if (state->counter_idx>99) { //0-99
                state->counter_idx=0;//reset counter index
            }
            print_counter(state);
            beep_counter(state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            state->counter_idx=0; // reset counter index
            print_counter(state);
            break;
        case EVENT_ACTIVATE:
            print_counter(state);
            break;
        case EVENT_TIMEOUT:
            // ignore timeout
            break;
        default:
            break;
    }

    return true;
}

// beep counter index times
void beep_counter(counter_state_t *state) {
	
	int low_count = state->counter_idx/5;
	int high_count = state->counter_idx - low_count * 5; 
	
	for (int i=0; i<low_count; i++) {
		watch_buzzer_play_note(BUZZER_NOTE_A6, 50);
	    watch_buzzer_play_note(BUZZER_NOTE_REST, 100);
	}
	
	//sleep between high and low
    watch_buzzer_play_note(BUZZER_NOTE_REST, 200);
	
	for (int i=0; i<high_count; i++) {
		watch_buzzer_play_note(BUZZER_NOTE_B6, 50);
	    watch_buzzer_play_note(BUZZER_NOTE_REST, 100);
	}
}


// print counter index at the center of display.
void print_counter(counter_state_t *state) {
    char buf[14];
    sprintf(buf, "CO    %02d", state->counter_idx); // center of LCD display
    watch_display_string(buf, 0);
}

void counter_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
