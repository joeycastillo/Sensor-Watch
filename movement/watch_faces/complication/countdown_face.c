/*
 * MIT License
 *
 * Copyright (c) 2024 Joseph Bryant
 * Copyright (c) 2023 Konrad Rieck
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

#include <stdlib.h>
#include <string.h>
#include "countdown_face.h"
#include "watch.h"
#include "watch_utility.h"

#define CD_SELECTIONS 3
#define DEFAULT_MINUTES 3

static bool quick_ticks_running;

static void abort_quick_ticks(countdown_state_t *state) {
    if (quick_ticks_running) {
        quick_ticks_running = false;
        if (state->mode == cd_setting)
            movement_request_tick_frequency(4);
        else
            movement_request_tick_frequency(1);
    }
}

static inline int32_t get_tz_offset(movement_settings_t *settings) {
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

static inline void store_countdown(countdown_state_t *state) {
    /* Store set countdown time */
    state->set_hours = state->hours;
    state->set_minutes = state->minutes;
    state->set_seconds = state->seconds;
}

static inline void load_countdown(countdown_state_t *state) {
    /* Load set countdown time */
    state->hours = state->set_hours;
    state->minutes = state->set_minutes;
    state->seconds = state->set_seconds;
}

static inline void button_beep(movement_settings_t *settings) {
    // play a beep as confirmation for a button press (if applicable)
    if (settings->bit.button_should_sound)
        watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
}

static void schedule_countdown(countdown_state_t *state, movement_settings_t *settings) {

    // Calculate the new state->now_ts but don't update it until we've updated the target - 
    // avoid possible race where the old target is compared to the new time and immediately triggers
    uint32_t new_now = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), get_tz_offset(settings));
    state->target_ts = watch_utility_offset_timestamp(new_now, state->hours, state->minutes, state->seconds);
    state->now_ts = new_now;
    watch_date_time target_dt = watch_utility_date_time_from_unix_time(state->target_ts, get_tz_offset(settings));
    movement_schedule_background_task_for_face(state->watch_face_index, target_dt);
}

static void auto_repeat(countdown_state_t *state, movement_settings_t *settings) {
    movement_play_alarm();
    load_countdown(state);
    schedule_countdown(state, settings);
}

static void start(countdown_state_t *state, movement_settings_t *settings) {
    state->mode = cd_running;
    schedule_countdown(state, settings);
}



static void draw(countdown_state_t *state, uint8_t subsecond) {
    char buf[16];

    uint32_t delta;
    div_t result;

    switch (state->mode) {
        case cd_running:
            if (state->target_ts <= state->now_ts)
                delta = 0;
            else
                delta = state->target_ts - state->now_ts;
            result = div(delta, 60);
            state->seconds = result.rem;
            result = div(result.quot, 60);
            state->hours = result.quot;
            state->minutes = result.rem;
            sprintf(buf, "CD  %2d%02d%02d", state->hours, state->minutes, state->seconds);
            break;
        case cd_reset:
        case cd_paused:
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            sprintf(buf, "CD  %2d%02d%02d", state->hours, state->minutes, state->seconds);
            break;
        case cd_setting:
            sprintf(buf, "CD  %2d%02d%02d", state->hours, state->minutes, state->seconds);
            if (!quick_ticks_running && subsecond % 2) {
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

static void pause(countdown_state_t *state) {
    state->mode = cd_paused;
    movement_cancel_background_task_for_face(state->watch_face_index);
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

static void reset(countdown_state_t *state) {
    state->mode = cd_reset;
    movement_cancel_background_task_for_face(state->watch_face_index);
    load_countdown(state);
}

static void ring(countdown_state_t *state) {
    movement_play_alarm();
    reset(state);
}

static void times_up(movement_settings_t *settings, countdown_state_t *state) {
    if(state->repeat) {
        auto_repeat(state, settings);
    }
    else {
        ring(state);
    }
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
        state->mode = cd_reset;
        state->watch_face_index = watch_face_index;
        store_countdown(state);
    }
}

void countdown_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    countdown_state_t *state = (countdown_state_t *)context;
    if(state->mode == cd_running) {
        watch_date_time now = watch_rtc_get_date_time();
        state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    }
    watch_set_colon();
    if(state->repeat)
        watch_set_indicator(WATCH_INDICATOR_BELL);

    movement_request_tick_frequency(1);
    quick_ticks_running = false;
}

bool countdown_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    countdown_state_t *state = (countdown_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            draw(state, event.subsecond);
            break;
        case EVENT_TICK:
            if (quick_ticks_running) {
                if (watch_get_pin_level(BTN_ALARM))
                    settings_increment(state);
                else
                    abort_quick_ticks(state);
            }

            if (state->mode == cd_running) {
                state->now_ts++;
            }
            draw(state, event.subsecond);
            break;
        case EVENT_MODE_BUTTON_UP:
            abort_quick_ticks(state);
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            switch(state->mode) {
                case cd_running:
                    movement_illuminate_led();
                    break;
                case cd_paused:
                    reset(state);
                    button_beep(settings);
                    break;
                case cd_reset:
                    state->mode = cd_setting;
                    movement_request_tick_frequency(4);
                    button_beep(settings);
                    break;
                case cd_setting:
                    state->selection++;
                    if(state->selection >= CD_SELECTIONS) {
                        state->selection = 0;
                        state->mode = cd_reset;
                        store_countdown(state);
                        movement_request_tick_frequency(1);
                        button_beep(settings);
                    }
                    break;
            }
            draw(state, event.subsecond);
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch(state->mode) {
                case cd_running:
                    pause(state);
                    button_beep(settings);
                    break;
                case cd_reset:
                case cd_paused:
                    if (!(state->hours == 0 && state->minutes == 0 && state->seconds == 0)) {
                        // Only start the timer if we have a valid time.
                        start(state, settings);
                        button_beep(settings);
                        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
                    }
                    break;
                case cd_setting:
                    settings_increment(state);
                    break;
            }
            draw(state, event.subsecond);
            break;
        case EVENT_ALARM_LONG_PRESS:
            switch(state->mode) {
                case cd_setting:
                    quick_ticks_running = true;
                    movement_request_tick_frequency(8);
                    break;
                default:
                    // Toggle auto-repeat
                    button_beep(settings);
                    state->repeat = !state->repeat;
                    if(state->repeat)
                        watch_set_indicator(WATCH_INDICATOR_BELL);
                    else
                        watch_clear_indicator(WATCH_INDICATOR_BELL);
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->mode == cd_setting) {
                switch (state->selection) {
                    case 0:
                        state->hours = 0;
                        // intentional fallthrough
                    case 1:
                        state->minutes = 0;
                        // intentional fallthrough
                    case 2:
                        state->seconds = 0;
                        break;
                }
            }
            break;
        case EVENT_ALARM_LONG_UP:
            abort_quick_ticks(state);
            break;
        case EVENT_BACKGROUND_TASK:
            times_up(settings, state);
            break;
        case EVENT_TIMEOUT:
            abort_quick_ticks(state);
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
        // intentionally squelch the light default event; we only show the light when cd is running
        case EVENT_LIGHT_BUTTON_DOWN:
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
        state->mode = cd_reset;
        store_countdown(state);
    }
}
