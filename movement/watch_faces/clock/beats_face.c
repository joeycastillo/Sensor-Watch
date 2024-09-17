/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Ellis <https://github.com/tahnok>
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
#include "beats_face.h"
#include "watch.h"

const uint8_t BEAT_REFRESH_FREQUENCY = 8;

void beats_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    (void) context_ptr;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(beats_face_state_t));
    }
}

void beats_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    beats_face_state_t *state = (beats_face_state_t *)context;
    state->next_subsecond_update = 0;
    state->last_centibeat_displayed = 0;
    movement_request_tick_frequency(BEAT_REFRESH_FREQUENCY);
}

bool beats_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    beats_face_state_t *state = (beats_face_state_t *)context;
    if (event.event_type == EVENT_TICK && event.subsecond != state->next_subsecond_update) {
         return true; // math is hard, don't do it if we don't have to.
    }

    char buf[16];
    uint32_t centibeats;

    watch_date_time date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            date_time = watch_rtc_get_date_time();
            centibeats = clock2beats(date_time.unit.hour, date_time.unit.minute, date_time.unit.second, event.subsecond, movement_timezone_offsets[settings->bit.time_zone]);
            if (centibeats == state->last_centibeat_displayed) {
                // we missed this update, try again next subsecond
                state->next_subsecond_update = (event.subsecond + 1) % BEAT_REFRESH_FREQUENCY;
            } else {
                state->next_subsecond_update = (event.subsecond + 1 + (BEAT_REFRESH_FREQUENCY * 2 / 3)) % BEAT_REFRESH_FREQUENCY;
                state->last_centibeat_displayed = centibeats;
            }
            sprintf(buf, "bt  %6lu", centibeats);

            watch_display_string(buf, 0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (!watch_tick_animation_is_running()) watch_start_tick_animation(432);
            date_time = watch_rtc_get_date_time();
            centibeats = clock2beats(date_time.unit.hour, date_time.unit.minute, date_time.unit.second, event.subsecond, movement_timezone_offsets[settings->bit.time_zone]);
            sprintf(buf, "bt  %4lu  ", centibeats / 100);

            watch_display_string(buf, 0);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void beats_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

uint32_t clock2beats(uint32_t hours, uint32_t minutes, uint32_t seconds, uint32_t subseconds, int16_t utc_offset) {
    uint32_t retval = seconds * 1000 + (subseconds * 1000) / (BEAT_REFRESH_FREQUENCY);
    retval += 60 * minutes * 1000;
    retval += hours * 60 * 60 * 1000;
    retval -= (utc_offset - 60) * 60 * 1000;

    retval /= 864; // convert to centibeats
    retval %= 100000;

    return retval;
}
