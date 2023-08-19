/*
 * MIT License
 *
 * Copyright (c) 2023 Alessandro Genova
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
#include "page_ordering_face.h"

typedef struct {
    uint8_t watch_face_index;
    uint8_t current_page_index;
    bool touched;
    bool tick_tock;
    bool reordering;
} page_ordering_face_state_t;

void page_ordering_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(page_ordering_face_state_t));
        memset(*context_ptr, 0, sizeof(page_ordering_face_state_t));
        page_ordering_face_state_t *state = (page_ordering_face_state_t *)*context_ptr;
        state->watch_face_index = watch_face_index;
    }
}

void page_ordering_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    page_ordering_face_state_t *state = (page_ordering_face_state_t *)context;
    state->current_page_index = 0;
    state->touched = false;
    state->tick_tock = true;
    state->reordering = false;
}

static void _page_ordering_face_update_lcd(page_ordering_face_state_t *state) {
    char buf[11];

    snprintf(buf + 0, 3, "FA");

    // Index of the face associated with the current page
    snprintf(buf + 2, 3, "%2.1d", movement_page_to_face(state->current_page_index));

    // Current page
    if (!state->reordering || state->tick_tock) {
        snprintf(buf + 4, 3, "%2.2d", state->current_page_index);
    } else {
        snprintf(buf + 4, 3, "  ");
    }

    // Whether the page is the first secondary page
    if (state->current_page_index == movement_get_secondary_page()) {
        watch_set_colon();
    } else {
        watch_clear_colon();
    }

    // Whether the page is enabled
    if (movement_is_page_enabled(state->current_page_index)) {
        snprintf(buf + 6, 5, " ON ");
    } else {
        snprintf(buf + 6, 5, " OFF");
    }

    watch_display_string(buf, 0);
}

static void _page_ordering_face_toggle_page(page_ordering_face_state_t *state) {
    // Prevent this page from ever disabling itself,
    // or else the watch could be in an unrecoverable state
    if (state->current_page_index == movement_face_to_page(state->watch_face_index)) {
        return;
    }

    movement_enable_page(state->current_page_index, !movement_is_page_enabled(state->current_page_index));
    state->touched = true;
}

static void _page_ordering_turn_page(page_ordering_face_state_t *state, int8_t change) {
    // Use uint16_t to avoid integer overflow if num_faces > 127;
    uint16_t num_faces = (uint16_t)movement_get_num_faces();
    uint16_t new_page_index = (uint16_t)state->current_page_index + (uint16_t)num_faces;

    new_page_index = (new_page_index + change) % num_faces;

    if (state->reordering) {
        movement_swap_page_order(state->current_page_index, new_page_index);

        state->touched = true;
    }

    state->current_page_index = new_page_index;
}

static void _page_ordering_set_secondary_page(page_ordering_face_state_t *state) {
    movement_set_secondary_page(state->current_page_index);
    state->touched = true;
}

bool page_ordering_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    page_ordering_face_state_t *state = (page_ordering_face_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            break;
        case EVENT_TICK:
            state->tick_tock = !state->tick_tock;
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (state->reordering) {
                state->reordering = false;
            } else {
                _page_ordering_face_toggle_page(state);
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->reordering) {
                _page_ordering_set_secondary_page(state);
                state->reordering = false;
            } else {
                state->reordering = true;
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            _page_ordering_turn_page(state, +1);
            break;
        case EVENT_ALARM_LONG_PRESS:
            _page_ordering_turn_page(state, -1);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_page(0);
            break;
        case EVENT_MODE_BUTTON_UP:
            if (state->touched) {
                movement_move_to_page(0);
            } else {
                movement_move_to_next_page();
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    _page_ordering_face_update_lcd(state);

    return true;
}

void page_ordering_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
