/*
 * MIT License
 *
 * Copyright (c) 2024 metrast (github)
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
#include "streak_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"

static void store_check(streak_state_t *state) {
    watch_date_time now = watch_rtc_get_date_time();
    state->last_check = watch_utility_date_time_to_unix_time(now, 0);
    state->check = 1;
    state->streak += 1;
    if (state->best < state->streak) {
        state->best += 1;
    }
    
    if (state->last_check != 0) {
        watch_date_time pre_last_check_date = watch_utility_date_time_from_unix_time(state->pre_last_check, 0);
        watch_date_time last_check_date = watch_utility_date_time_from_unix_time(state->last_check, 0);        
        uint8_t days_diff = last_check_date.unit.day - pre_last_check_date.unit.day;
        if (days_diff > 1) {
            state->pre_last_check = state->last_check;
        }
    }
}

static void reset_check(streak_state_t *state) {
    watch_date_time now = watch_rtc_get_date_time();
    watch_date_time last_check_date = watch_utility_date_time_from_unix_time(state->last_check, 0);

    if (now.unit.year > last_check_date.unit.year || 
        (now.unit.year == last_check_date.unit.year && now.unit.month > last_check_date.unit.month) || 
        (now.unit.year == last_check_date.unit.year && now.unit.month == last_check_date.unit.month && now.unit.day > last_check_date.unit.day)) {
        state->check = 0;
        state->last_best = state->best;
    }
    uint8_t days_diff = now.unit.day - last_check_date.unit.day;

    if (days_diff < 1) {
        days_diff = 1;
    }

    if (days_diff > 1) {
        state->streak = 0;
    }
}

static void undo_check(streak_state_t *state) {
    if (state->streak != 0) {
        state->check = 0;
        if (state->best == state->last_best + 1) {
            state->best -= 1;
        }
        state->streak -= 1;
        state->last_check = state->pre_last_check;
    }
}

static void print_streak_count(streak_state_t *state) {
    char buf [14];
    sprintf(buf, "SF  %04d  ", state->streak); //streak-face
    watch_display_string(buf, 0);
    if (state->check == 1) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
}

static void print_best(streak_state_t *state) {
    char buf [14];
    sprintf(buf, "BF  %04d  ", state->best); //best-face
    watch_display_string(buf, 0);

}

static void print_setting_best(streak_state_t *state) {
    char buf [14];
    sprintf(buf, "SB  %04d ", state->setting_best); //setting-best
    watch_display_string(buf, 0);
}

static bool quick_ticks_running = false;
static void abort_quick_ticks(streak_state_t *state) {
    if (quick_ticks_running) {
        quick_ticks_running = false;
        if (state->mode == setting_best_screen)
            movement_request_tick_frequency(4);
        else
            movement_request_tick_frequency(1);
    }
}

void streak_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(streak_state_t));
        memset(*context_ptr, 0, sizeof(streak_state_t));
        streak_state_t *state = (streak_state_t *)*context_ptr;
        state->streak = 0;
        state->check = 0;
        state->best = 0; //adjust when reflashing/changing battery
    }
}

void streak_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    movement_request_tick_frequency(1);
    quick_ticks_running = false;
    watch_set_led_off();
    streak_state_t *state = (streak_state_t *)context;
    reset_check(state);
    print_streak_count(state);
}

bool streak_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    streak_state_t *state = (streak_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->mode = streak_screen;
            reset_check(state);
            print_streak_count(state);
            break;

        case EVENT_TICK:
            if (quick_ticks_running) {
                if (watch_get_pin_level(BTN_ALARM)) {
                    switch (state->mode) {
                        case setting_best_screen:
                            state->setting_best = (state->setting_best < 9999) ? state->setting_best + 1 : 0;
                            print_setting_best(state);
                            break;
                        default:
                            abort_quick_ticks(state);
                            break;
                    }
                } else {
                    abort_quick_ticks(state);
                }
            }
            break;

        case EVENT_LIGHT_BUTTON_UP:
            watch_set_led_off();
            switch (state->mode) {
                case streak_screen:
                    state->setting_best = state->best;
                    state->mode = best_screen;
                    print_best(state);
                    break;
                case best_screen:
                    state->mode = streak_screen;
                    reset_check(state);
                    print_streak_count(state);
                    break;
                default:
                    break;
            }
            quick_ticks_running = false;
            break;

        case EVENT_LIGHT_BUTTON_DOWN:
            break;

        case EVENT_LIGHT_LONG_PRESS:
            switch (state->mode) {
                case streak_screen:
                    if (state->check == 1) {
                        undo_check(state);
                        print_streak_count(state);
                    }
                    break;
                case setting_best_screen:
                    state->setting_best = 0;
                    print_setting_best(state);
                    break;
                default:
                    break;
            }
            break;

        case EVENT_ALARM_BUTTON_UP:
            if (!quick_ticks_running) {
                abort_quick_ticks(state);
                switch (state->mode) {
                    case streak_screen:
                        if (state->check == 0) {
                            state->check = 1;
                            store_check(state);
                            print_streak_count(state);
                        }
                        break;
                    case best_screen:
                        break;
                    case setting_best_screen:
                        state->setting_best = (state->setting_best < 9999) ? state->setting_best + 1 : 0;
                        print_setting_best(state);
                        break;
                    default:
                        break;
                }
            }
            break;

        case EVENT_ALARM_LONG_PRESS:
            switch (state->mode) {
                case streak_screen:
                    if (state->best == 1 && state->streak == 1) {
                        undo_check(state);
                    } else {
                        state->streak = 0;
                        state->check = 0;
                    }
                    print_streak_count(state);
                    break;

                case setting_best_screen:
                    quick_ticks_running = true;
                    movement_request_tick_frequency(8);
                    break;

                default:
                    quick_ticks_running = false;
                    break;
            }
            break;

        case EVENT_MODE_LONG_PRESS:
            switch (state->mode) {
                case best_screen:
                    state->mode = setting_best_screen;
                    print_setting_best(state);
                    break;
                case setting_best_screen:
                    state->mode = best_screen;
                    if (state->setting_best != state->best) {
                        state->best = state->setting_best;
                    }
                    print_best(state);
                    break;
                default:
                    break;
            }
            break;

        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;

        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void streak_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
