/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Aptekar-Cassels
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
#include "page_face.h"

struct page_t {
    uint8_t face_index;
    uint8_t size;
    char name[11];
};

struct page_t pages[] = {
    {1, 3, "   1 test "},
    {5, 2, "   2 test "},
};

void page_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(page_state_t));
        page_state_t *state = (page_state_t *)*context_ptr;
        state->watch_face_index = watch_face_index;
    }
}

void page_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    page_state_t *state = (page_state_t *)context;

    for (uint8_t i = 0; i < sizeof(pages) / sizeof(struct page_t); i++) {
        if (pages[i].face_index == state->watch_face_index) {
            watch_display_string(pages[i].name, 0);
            state->size = pages[i].size;
            return;
        }
    }
    char buf[11];
    sprintf(buf, "P %2dError", state->watch_face_index);
    watch_display_string(buf, 0);
}

bool page_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    page_state_t *state = (page_state_t *)context;

    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_face(state->watch_face_index + state->size + 1);
            break;
        case EVENT_MODE_LONG_PRESS:
        case EVENT_ALARM_LONG_PRESS:
        case EVENT_ALARM_BUTTON_UP:
            movement_move_to_face(state->watch_face_index + 1);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void page_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

