/*
 * MIT License
 *
 * Copyright (c) 2022 David Singleton
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
#include "ratemeter_face.h"
#include "watch.h"

#define RATEMETER_FACE_FREQUENCY_FACTOR (6ul) // refresh rate will be 2 to this power Hz (0 for 1 Hz, 2 for 4 Hz, etc.)
#define RATEMETER_FACE_FREQUENCY (1 << RATEMETER_FACE_FREQUENCY_FACTOR)

void ratemeter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(ratemeter_state_t));
}

void ratemeter_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    memset(context, 0, sizeof(ratemeter_state_t));
}

bool ratemeter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    ratemeter_state_t *ratemeter_state = (ratemeter_state_t *)context;
    char buf[14];
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_display_string("ra          ", 0);
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            if (ratemeter_state->ticks != 0) {
                ratemeter_state->rate = (int16_t)(60.0 / ((float)ratemeter_state->ticks / (float)RATEMETER_FACE_FREQUENCY));
                // ratemeter_state->rate = (int16_t)((1 / (float)ratemeter_state->ticks) * (float)(RATEMETER_FACE_FREQUENCY * 60);

                printf("freq: %d \n", RATEMETER_FACE_FREQUENCY); // 64
                printf("ticks: %d \n", ratemeter_state->ticks);  // 13
                printf("rate: %d \n", ratemeter_state->rate);
                // char str[1024];
                // sprintf(str, "%d\n", ratemeter_state->rate);
            }
            ratemeter_state->ticks = 0;
            movement_request_tick_frequency(RATEMETER_FACE_FREQUENCY);
            break;
        case EVENT_ALARM_BUTTON_UP:
            break;
        case EVENT_ALARM_LONG_PRESS:
            break;
        case EVENT_TICK:
            if (ratemeter_state->rate == 0) {
                watch_display_string("ra          ", 0);
            } else {
                if (ratemeter_state->rate > 500) {
                    watch_display_string("ra      Hi", 0);
                } else if (ratemeter_state->rate < 1) {
                    watch_display_string("ra      Lo", 0);
                } else {
                    sprintf(buf, "ra  %-3d pn", ratemeter_state->rate);
                    watch_display_string(buf, 0);
                }
            }
            ratemeter_state->ticks++;
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void ratemeter_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
