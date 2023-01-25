/*
 * MIT License
 *
 * Copyright (c) 2022 Wesley Ellis
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

//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
#include "countdown_face.h"
#include "watch.h"
#include "watch_utility.h"


#define CD_SELECTIONS 3
#define DEFAULT_MINUTES 3


static inline int32_t get_tz_offset(movement_settings_t *settings) {
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

static void start(countdown_state_t *state, movement_settings_t *settings) {
    watch_date_time now = watch_rtc_get_date_time();

    state->mode = cd_running;
    state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
    state->target_ts = watch_utility_offset_timestamp(state->now_ts, state->hours, state->minutes, state->seconds);
    watch_date_time target_dt = watch_utility_date_time_from_unix_time(state->target_ts, get_tz_offset(settings));
    movement_schedule_background_task(target_dt);
    watch_set_indicator(WATCH_INDICATOR_BELL);
}

static void draw(countdown_state_t *state, uint8_t subsecond) {
    char buf[16];

    uint32_t delta;
    div_t result;
    uint8_t hour, min, sec;

    switch (state->mode) {
        case cd_running:
            delta = state->target_ts - state->now_ts;
            result = div(delta, 60);
            sec = result.rem;
            result = div(result.quot, 60);
            hour = result.quot;
            min = result.rem;

            sprintf(buf, "CD  %2d%02d%02d", hour, min, sec);
            break;
        case cd_waiting:
            sprintf(buf, "CD  %2d%02d%02d", state->hours, state->minutes, state->seconds);
            break;
        case cd_setting:
            sprintf(buf, "CD  %2d%02d%02d", state->hours, state->minutes, state->seconds);
            if (subsecond % 2) {
                switch(state->selection) {
                    case 0:
                        buf[4] = buf[5] = ' ';
                        break;
                    case 1:
                        buf[6] = buf[7] = ' ';
                        break;
                    case 2:
                        buf[8] = buf[9] = ' ';
                        break;
                    default:
                        break;
                }
            }
            break;
    }
    watch_display_string(buf, 0);
}

static void reset(countdown_state_t *state) {
    state->mode = cd_waiting;
    movement_cancel_background_task();
    watch_clear_indicator(WATCH_INDICATOR_BELL);
}

static void ring(countdown_state_t *state) {
    movement_play_alarm();
    reset(state);
}

static void settings_increment(countdown_state_t *state) {
    switch(state->selection) {
        case 0:
            state->hours = (state->hours + 1) % 24;
            break;
        case 1:
            state->minutes = (state->minutes + 1) % 60;
            break;
        case 2:
            state->seconds = (state->seconds + 1) % 60;
            break;
        default:
            // should never happen
            break;
    }
    return;
}

void countdown_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(countdown_state_t));
        countdown_state_t *state = (countdown_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(countdown_state_t));
        state->minutes = DEFAULT_MINUTES;
    }
}

void countdown_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    countdown_state_t *state = (countdown_state_t *)context;
    if(state->mode == cd_running) {
        watch_date_time now = watch_rtc_get_date_time();
        state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
        watch_set_indicator(WATCH_INDICATOR_BELL);
    }
    watch_set_colon();
}


bool countdown_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    countdown_state_t *state = (countdown_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            draw(state, event.subsecond);
            break;
        case EVENT_TICK:
            if (state->mode == cd_running) {
                state->now_ts++;
            }
            draw(state, event.subsecond);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            switch(state->mode) {
                case cd_running:
                    movement_illuminate_led();
                    break;
                case cd_waiting:
                    state->mode = cd_setting;
                    movement_request_tick_frequency(4);
                    break;
                case cd_setting:
                    state->selection++;
                    if(state->selection >= CD_SELECTIONS) {
                        state->selection = 0;
                        state->mode = cd_waiting;
                        movement_request_tick_frequency(1);
                    }
                    break;
            }
            draw(state, event.subsecond);
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch(state->mode) {
                case cd_running:
                    reset(state);
                    break;
                case cd_waiting:
                    if (!(state->hours == 0 && state->minutes == 0 && state->seconds == 0)) {
                        // Only start the timer if we have a valid time.
                        start(state, settings);
                    }
                    break;
                case cd_setting:
                    settings_increment(state);
                    break;
            }
            draw(state, event.subsecond);
            break;
        case EVENT_BACKGROUND_TASK:
            ring(state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->mode == cd_setting) {
                    state->hours = 0;
                    state->minutes = 0;
                    state->seconds = 0;
                    draw(state, event.subsecond);
                    break;
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void countdown_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    countdown_state_t *state = (countdown_state_t *)context;
    if (state->mode == cd_setting) {
        state->selection = 0;
        state->mode = cd_waiting;
    }
}
