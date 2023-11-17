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
#include "character_set_face.h"
#include "watch.h"

void character_set_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(char));
}

void character_set_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    char *c = (char *)context;
    *c = '@';
    movement_request_tick_frequency(0);
}

bool character_set_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    char *c = (char *)context;
    char buf[11];
    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_UP:
            *c = (*c) + 1;
            if (*c & 0x80) *c = ' ';
            // fall through
        case EVENT_ACTIVATE:
            sprintf(buf, "%c%c%c%c%c%c%c%c%c%c", *c, *c, *c, *c, *c, *c, *c, *c, *c, *c);
            watch_display_string(buf, 0);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_page(0);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void character_set_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
