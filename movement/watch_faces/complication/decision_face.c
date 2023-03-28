/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
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
#include "divinate_face.h"
#include "decision_face.h"

void decision_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(decision_state_t));
        memset(*context_ptr, 0, sizeof(decision_state_t));
        decision_state_t *state = (decision_state_t *)*context_ptr;
        sprintf(state->binary[1], "4ES   ");
        sprintf(state->binary[0], "    NO");
    }
}

void decision_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool decision_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    decision_state_t *state = (decision_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_display_string("    Decide", 0);
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->decision = divine_bit();
            watch_display_string(state->binary[state->decision], 4);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void decision_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

