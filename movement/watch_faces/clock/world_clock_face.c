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
#include "world_clock_face.h"
#include "watch.h"
#include "watch_utility.h"

void world_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(world_clock_state_t));
        memset(*context_ptr, 0, sizeof(world_clock_state_t));
        uint8_t backup_register = movement_claim_backup_register();
        if (backup_register) {
            world_clock_state_t *state = (world_clock_state_t *)*context_ptr;
            state->settings.reg = watch_get_backup_data(backup_register);
            state->backup_register = backup_register;
        }
    }
}

void world_clock_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    world_clock_state_t *state = (world_clock_state_t *)context;
    state->current_screen = 0;

    if (watch_tick_animation_is_running()) watch_stop_tick_animation();
}

static bool world_clock_face_do_display_mode(movement_event_t event, movement_settings_t *settings, world_clock_state_t *state) {
    char buf[11];
    uint8_t pos;

    uint32_t timestamp;
    uint32_t previous_date_time;
    watch_date_time date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            if (settings->bit.clock_mode_24h && !settings->bit.clock_24h_leading_zero) watch_set_indicator(WATCH_INDICATOR_24H);
            watch_set_colon();
            state->previous_date_time = 0xFFFFFFFF;
            // fall through
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:
            date_time = watch_rtc_get_date_time();
            timestamp = watch_utility_date_time_to_unix_time(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60);
            date_time = watch_utility_date_time_from_unix_time(timestamp, movement_timezone_offsets[state->settings.bit.timezone_index] * 60);
            previous_date_time = state->previous_date_time;
            state->previous_date_time = date_time.reg;

            bool set_leading_zero = false;
            if ((date_time.reg >> 6) == (previous_date_time >> 6) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                // everything before seconds is the same, don't waste cycles setting those segments.
                pos = 8;
                sprintf(buf, "%02d", date_time.unit.second);
            } else if ((date_time.reg >> 12) == (previous_date_time >> 12) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                // everything before minutes is the same.
                pos = 6;
                sprintf(buf, "%02d%02d", date_time.unit.minute, date_time.unit.second);
            } else {
                // other stuff changed; let's do it all.
                if (!settings->bit.clock_mode_24h) {
                    // if we are in 12 hour mode, do some cleanup.
                    if (date_time.unit.hour < 12) {
                        watch_clear_indicator(WATCH_INDICATOR_PM);
                    } else {
                        watch_set_indicator(WATCH_INDICATOR_PM);
                    }
                    date_time.unit.hour %= 12;
                    if (date_time.unit.hour == 0) date_time.unit.hour = 12;
                } else if (settings->bit.clock_24h_leading_zero && date_time.unit.hour < 10) {
                    set_leading_zero = true;
                }
                pos = 0;
                if (event.event_type == EVENT_LOW_ENERGY_UPDATE) {
                    if (!watch_tick_animation_is_running()) watch_start_tick_animation(500);
                    sprintf(buf, "%c%c%2d%2d%02d  ",
                        movement_valid_position_0_chars[state->settings.bit.char_0],
                        movement_valid_position_1_chars[state->settings.bit.char_1],
                        date_time.unit.day,
                        date_time.unit.hour,
                        date_time.unit.minute);
                } else {
                    sprintf(buf, "%c%c%2d%2d%02d%02d",
                        movement_valid_position_0_chars[state->settings.bit.char_0],
                        movement_valid_position_1_chars[state->settings.bit.char_1],
                        date_time.unit.day,
                        date_time.unit.hour,
                        date_time.unit.minute,
                        date_time.unit.second);
                }
            }
            watch_display_string(buf, pos);
            if (set_leading_zero)
                watch_display_string("0", 4);
            break;
        case EVENT_ALARM_LONG_PRESS:
            movement_request_tick_frequency(4);
            state->current_screen = 1;
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

static bool _world_clock_face_do_settings_mode(movement_event_t event, movement_settings_t *settings, world_clock_state_t *state) {
    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            if (state->backup_register) watch_store_backup_data(state->settings.reg, state->backup_register);
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_BUTTON_DOWN:
            state->current_screen++;
            if (state->current_screen > 3) {
                movement_request_tick_frequency(1);
                state->current_screen = 0;
                if (state->backup_register) watch_store_backup_data(state->settings.reg, state->backup_register);
                event.event_type = EVENT_ACTIVATE;
                return world_clock_face_do_display_mode(event, settings, state);
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            switch (state->current_screen) {
                case 1:
                    state->settings.bit.char_0++;
                    if (state->settings.bit.char_0 >= strlen(movement_valid_position_0_chars)) {
                        state->settings.bit.char_0 = 0;
                    }
                    break;
                case 2:
                    state->settings.bit.char_1++;
                    if (state->settings.bit.char_1 >= strlen(movement_valid_position_1_chars)) {
                        state->settings.bit.char_1 = 0;
                    }
                    break;
                case 3:
                    state->settings.bit.timezone_index++;
                    if (state->settings.bit.timezone_index > 40) state->settings.bit.timezone_index = 0;
                    break;
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            break;
    }

    char buf[13];
    sprintf(buf, "%c%c %3d%02d  ",
        movement_valid_position_0_chars[state->settings.bit.char_0],
        movement_valid_position_1_chars[state->settings.bit.char_1],
        (int8_t) (movement_timezone_offsets[state->settings.bit.timezone_index] / 60),
        (int8_t) (movement_timezone_offsets[state->settings.bit.timezone_index] % 60) * (movement_timezone_offsets[state->settings.bit.timezone_index] < 0 ? -1 : 1));
    watch_set_colon();
    watch_clear_indicator(WATCH_INDICATOR_PM);

    // blink up the parameter we're setting
    if (event.subsecond % 2) {
        switch (state->current_screen) {
            case 1:
            case 2:
                buf[state->current_screen - 1] = '_';
                break;
            case 3:
                watch_clear_colon();
                sprintf(buf + 3, "       ");
                break;
        }
    }

    watch_display_string(buf, 0);

    return true;
}

bool world_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    world_clock_state_t *state = (world_clock_state_t *)context;

    if (state->current_screen == 0) {
        return world_clock_face_do_display_mode(event, settings, state);
    } else {
        return _world_clock_face_do_settings_mode(event, settings, state);
    }
}

void world_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
