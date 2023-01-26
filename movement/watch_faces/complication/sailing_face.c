/*
 * MIT License
 *
 * Copyright (c) 2022 Wesley Ellis
 * Copyright (c) 2022 Niclas Hoyer
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
#include "sailing_face.h"
#include "watch.h"
#include "watch_utility.h"

#define sl_SELECTIONS 6
#define DEFAULT_MINUTES { 5,4,1,0,0,0 }

static inline int32_t get_tz_offset(movement_settings_t *settings) {
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

static void reset(sailing_state_t *state) {
    state->index = 0;
    state->mode = sl_waiting;
    movement_cancel_background_task();
    watch_clear_indicator(WATCH_INDICATOR_BELL);
}

static void start(sailing_state_t *state, movement_settings_t *settings) {
    uint8_t minutes = state->minutes[state->index];
    if (minutes == 0) {
        reset(state);
        return;
    }
    if (state->index < 5) {
        minutes -= state->minutes[state->index+1];
    }

    state->mode = sl_running;
    watch_date_time now = watch_rtc_get_date_time();
    state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
    state->target_ts = watch_utility_offset_timestamp(state->now_ts, 0, minutes, 0);
    watch_date_time target_dt = watch_utility_date_time_from_unix_time(state->target_ts, get_tz_offset(settings));
    movement_schedule_background_task_for_face(state->watch_face_index, target_dt);
    watch_set_indicator(WATCH_INDICATOR_BELL);
}

static void draw(sailing_state_t *state, uint8_t subsecond, movement_settings_t *settings) {
    (void) settings;

    char tmp[24];
    char buf[16];

    uint32_t delta;
    div_t result;
    uint8_t min, sec;
    uint8_t add = 0;

    switch (state->mode) {
        case sl_running:
            if (state->index < 5) {
                add = state->minutes[state->index+1];
            }
            if (state->now_ts >= state->target_ts) {
                delta = 0;
            } else {
                delta = state->target_ts - state->now_ts;
            }
            result = div(delta, 60);
            min = result.quot + add;
            sec = result.rem;

            if (min > 0) {
                sprintf(buf, "SL    %2d%02d", min, sec);
            } else {
                sprintf(buf, "SL    %2d  ", sec);
            }
            break;
        case sl_waiting:
            sprintf(buf, "SL    %2d%02d", state->minutes[0], 0);
            break;
        case sl_setting:
            // this sprintf to a larger tmp is to guarantee that no buffer overflows
            // occur here (and to squelch the corresponding compiler warning)
            sprintf(tmp, "SL  %1d%1d%1d%1d%1d%1d",
                state->minutes[0],
                state->minutes[1],
                state->minutes[2],
                state->minutes[3],
                state->minutes[4],
                state->minutes[5]
            );
            memcpy(buf, tmp, sizeof(buf));
            if (subsecond % 2) {
                buf[4 + state->selection] = ' ';
            }
            break;
    }
    watch_display_string(buf, 0);
}

static void ring(sailing_state_t *state, movement_settings_t *settings) {
    movement_play_signal();
    state->index += 1;
    if (state->index > 5) {
        reset(state);
        return;
    }
    uint8_t next_min = state->minutes[state->index];
    if (next_min == 0) {
        reset(state);
        return;
    }
    movement_cancel_background_task();
    start(state, settings);
}

static void settings_increment(sailing_state_t *state) {
    state->minutes[state->selection] += 1;
    uint8_t max = 10;
    if (state->selection > 0) {
        max = state->minutes[state->selection-1];
    }
    if (state->minutes[state->selection] >= max) {
        state->minutes[state->selection] = 0;
    }
    // ensure that minutes are decreasing
    if (state->selection < 5) {
        for (uint8_t i = 0; i < 5; i++) {
            if (state->minutes[i+1] >= state->minutes[i]) {
                if (state->minutes[i] > 0) {
                    state->minutes[i+1] = state->minutes[i] - 1;
                } else {
                    state->minutes[i+1] = 0;
                }
            }
        }
    }
    return;
}

void sailing_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(sailing_state_t));
        sailing_state_t *state = (sailing_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(sailing_state_t));
        static const uint8_t default_minutes[6] = DEFAULT_MINUTES;
        memcpy(&state->minutes, default_minutes, sizeof(default_minutes));
        state->watch_face_index = watch_face_index;
    }
}

void sailing_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    sailing_state_t *state = (sailing_state_t *)context;
    if(state->mode == sl_running) {
        watch_date_time now = watch_rtc_get_date_time();
        state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
    }
}


bool sailing_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    sailing_state_t *state = (sailing_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            draw(state, event.subsecond, settings);
            break;
        case EVENT_TICK:
            if (state->mode == sl_running) {
                state->now_ts++;
            }
            draw(state, event.subsecond, settings);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->mode == sl_running) {
                reset(state);
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            switch(state->mode) {
                case sl_running:
                    movement_illuminate_led();
                    break;
                case sl_waiting:
                    state->mode = sl_setting;
                    movement_request_tick_frequency(4);
                    break;
                case sl_setting:
                    state->selection++;
                    if(state->selection >= sl_SELECTIONS) {
                        state->selection = 0;
                        state->mode = sl_waiting;
                        movement_request_tick_frequency(1);
                    }
                    break;
            }
            draw(state, event.subsecond, settings);
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch(state->mode) {
                case sl_running:
                    ring(state, settings);
                    break;
                case sl_waiting:
                    movement_play_signal();
                    start(state, settings);
                    break;
                case sl_setting:
                    settings_increment(state);
                    break;
            }
            draw(state, event.subsecond, settings);
            break;
        case EVENT_BACKGROUND_TASK:
            ring(state, settings);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->mode == sl_setting) {
                    static const uint8_t default_minutes[6] = DEFAULT_MINUTES;
                    memcpy(&state->minutes, default_minutes, sizeof(default_minutes));
                    state->index = 0;
                    draw(state, event.subsecond, settings);
                    break;
            }
            break;
        case EVENT_TIMEOUT:
            if (state->mode != sl_running) {
                movement_move_to_face(0);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void sailing_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    sailing_state_t *state = (sailing_state_t *)context;
    if (state->mode == sl_setting) {
        state->selection = 0;
        state->mode = sl_waiting;
    }
}
