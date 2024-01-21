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
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFtomato_ringEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include "tomato_face.h"
#include "watch_utility.h"

static uint8_t focus_min = 25;
static uint8_t break_min = 5;

static inline int32_t get_tz_offset(movement_settings_t *settings) {
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

static uint8_t get_length(tomato_state_t *state) {
    uint8_t length;
    if (state->kind == tomato_focus) {
        length = focus_min;
    } else {
        length = break_min;
    }

    return length;
}

static void tomato_start(tomato_state_t *state, movement_settings_t *settings) {
    watch_date_time now = watch_rtc_get_date_time();
    int8_t length = (int8_t) get_length(state);

    state->mode = tomato_run;
    state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
    state->target_ts = watch_utility_offset_timestamp(state->now_ts, 0, length, 0);
    watch_date_time target_dt = watch_utility_date_time_from_unix_time(state->target_ts, get_tz_offset(settings));
    movement_schedule_background_task(target_dt);
    watch_set_indicator(WATCH_INDICATOR_BELL);
}

static void tomato_draw(tomato_state_t *state) {
    char buf[16];

    uint32_t delta;
    div_t result;
    uint8_t min = 0;
    uint8_t sec = 0;
    char kind;

    if (state->kind == tomato_break) {
        kind = 'b';
    } else {
        kind = 'f';
    }

    switch (state->mode) {
        case tomato_run:
            delta = state->target_ts - state->now_ts;
            result = div(delta, 60);
            min = result.quot;
            sec = result.rem;
            break;
        case tomato_ready:
            min = get_length(state);
            sec = 0;
            break;
    }
    if (state->visible) {
        sprintf(buf, "TO %c%2d%02d%2d", kind, min, sec, state->done_count);
        watch_display_string(buf, 0);
    }
}

static void tomato_reset(tomato_state_t *state) {
    state->mode = tomato_ready;
    movement_cancel_background_task();
    watch_clear_indicator(WATCH_INDICATOR_BELL);
}

static void tomato_ring(tomato_state_t *state) {
    movement_play_signal();
    tomato_reset(state);
    if (state->kind == tomato_focus) {
        state->kind = tomato_break;
        state->done_count++;
    } else {
        state->kind = tomato_focus;
    }
}

void tomato_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(tomato_state_t));
        tomato_state_t *state = (tomato_state_t*)*context_ptr;
        memset(*context_ptr, 0, sizeof(tomato_state_t));
        state->mode=tomato_ready;
        state->kind= tomato_focus;
        state->done_count = 0;
        state->visible = true;
    }
}

void tomato_face_activate(movement_settings_t *settings, void *context) {
    tomato_state_t *state = (tomato_state_t *)context;
    if (state->mode == tomato_run) {
        watch_date_time now = watch_rtc_get_date_time();
        state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
        watch_set_indicator(WATCH_INDICATOR_BELL);
    }
    watch_set_colon();
    state->visible = true;
}

bool tomato_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    tomato_state_t *state = (tomato_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            tomato_draw(state);
            break;
        case EVENT_TICK:
            if (state->mode == tomato_run) {
                state->now_ts++;
            }
            tomato_draw(state);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            if (state->mode == tomato_ready) {
                if (state->kind == tomato_break) {
                    state->kind = tomato_focus;
                } else {
                    state->kind = tomato_break;
                }
            }
            tomato_draw(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch(state->mode) {
                case tomato_run:
                    tomato_reset(state);
                    break;
                case tomato_ready:
                    tomato_start(state, settings);
                    break;
            }
            tomato_draw(state);

            break;
        case EVENT_ALARM_LONG_PRESS:
            state->done_count = 0;
            break;
        case EVENT_BACKGROUND_TASK:
            tomato_ring(state);
            tomato_draw(state);
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

void tomato_face_resign(movement_settings_t *settings, void *context) {
    tomato_state_t *state = (tomato_state_t *)context;
    state->visible = false;
    (void) settings;
    (void) context;
}

