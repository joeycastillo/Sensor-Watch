/*
 * MIT License
 *
 * Copyright (c) 2023 <Maxwell Trussell>
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
#include "dice_face.h"

// TODO: It might be nice to get this dynamically from preferences.
static uint8_t MaxFaces = 20;

static void draw(dice_state_t *state) {
	char buf[16];
	sprintf(buf, "di  %2d%2d  ", state->faces, state->result);
	watch_display_string(buf, 0);
}

static void roll(dice_state_t *state) {
	// FIXME: This produces a slightly non-uniform distribution.
	state->result = (rand() % state->faces) + 1;
	draw(state);
}

void dice_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
	(void) watch_face_index;
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(dice_state_t));
        memset(*context_ptr, 0, sizeof(dice_state_t));
		dice_state_t *state = (dice_state_t*) *context_ptr;
		state->faces = 20;
		state->result = 0;
    }
}

void dice_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
	watch_clear_colon();
    dice_state_t *state = (dice_state_t*) context;
	draw(state);
}

bool dice_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    dice_state_t *state = (dice_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
			draw(state);
            break;
        case EVENT_MODE_BUTTON_UP:
            // You shouldn't need to change this case; Mode almost always moves to the next watch face.
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
			state->faces = (state->faces % MaxFaces) + 1;
			draw(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Just in case you have need for another button.
			roll(state);
            break;
        default:
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void dice_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
