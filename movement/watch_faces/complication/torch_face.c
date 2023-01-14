/*
 * MIT License
 *
 * Copyright (c) 2023 Chad McBuff
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
#include "torch_face.h"
#include "watch.h"

void torch_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(torch_face_state_t));
        memset(*context_ptr, 0, sizeof(torch_face_state_t));
    }
}

void torch_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    torch_face_state_t *state = (torch_face_state_t *)context;
    state->active = false;
}

static void _torch_face_update_lcd(torch_face_state_t *state) {
    char buf[11];
    const char colors[][7] = {" FlASH"};
    sprintf(buf, "BL %c%s", state->fast ? 'F' : 'S', colors[state->color]);
    watch_display_string(buf, 0);
}

bool torch_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    torch_face_state_t *state = (torch_face_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _torch_face_update_lcd(state);
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (!state->active) {
                _torch_face_update_lcd(state);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (!state->active) {
                state->active = true;
                watch_clear_display();
                movement_request_tick_frequency(state->fast ? 8 : 2);            
            } else {
                state->active = false;
                watch_set_led_off();
                _torch_face_update_lcd(state);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (!state->active) {
                state->fast = !state->fast;
                _torch_face_update_lcd(state);
            }
            break;
        case EVENT_TICK:
            if (state->active) {
                watch_set_led_green();
                
            }
            break;
        case EVENT_TIMEOUT:
            if (!state->active) movement_move_to_face(0);
        default:
            break;
    }

    return true;
}

void torch_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off();
}
