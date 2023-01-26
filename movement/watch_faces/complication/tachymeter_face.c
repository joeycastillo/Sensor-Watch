/*
 * MIT License
 *
 * Copyright (c) 2022 Raymundo Cassani
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
#include "tachymeter_face.h"
#include "watch_utility.h"

static uint32_t _distance_from_struct(distance_digits_t dist_digits) {
    // distance from digitwise distance
    uint32_t retval = (dist_digits.thousands * 100000 +
                       dist_digits.hundreds  *  10000 +
                       dist_digits.tens      *   1000 +
                       dist_digits.ones      *    100 +
                       dist_digits.tenths    *     10 +
                       dist_digits.hundredths);// * 1
    return retval;
}

void tachymeter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void)settings;
    (void)watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(tachymeter_state_t));
        memset(*context_ptr, 0, sizeof(tachymeter_state_t));
        tachymeter_state_t *state = (tachymeter_state_t *)*context_ptr;
        // Default distance
        state->dist_digits.ones = 1;
        state->distance = _distance_from_struct(state->dist_digits);
    }
}

void tachymeter_face_activate(movement_settings_t *settings, void *context) {
    (void)settings;
    (void)context;
    movement_request_tick_frequency(4); // 4Hz
}

static void _tachymeter_face_distance_lcd(movement_event_t event, tachymeter_state_t *state){
    char buf[11];
    // Distance from digits
    state->distance = _distance_from_struct(state->dist_digits);
    sprintf(buf, "TC %c%06lu", state->running ? ' ' : 'd',  state->distance);
    // Blinking display when editing
    if (state->editing) {
        // Blink 'd'
        if (event.subsecond < 2) {
            buf[3] = ' ';
        }
        // Blink active digit
        if (event.subsecond % 2) {
            buf[state->active_digit + 4] = ' ';
        }
    }
    watch_display_string(buf, 0);
}

static void _tachymeter_face_totals_lcd(tachymeter_state_t *state, bool show_time){
    char buf[15];
    if (!show_time){
        sprintf(buf, "TC %c%6lu", 'h',  state->total_speed);
    } else {
        sprintf(buf, "TC %c%6lu", 't',  state->total_time);
    }
    watch_display_string(buf, 0);
    if (!show_time){
        // Show '/' besides 'H'
        watch_set_pixel(0, 9);
        watch_set_pixel(0, 10);
    }
}

bool tachymeter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void)settings;
    tachymeter_state_t *state = (tachymeter_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show distance in UI
            if (state->total_time == 0) {
                _tachymeter_face_distance_lcd(event, state);
            }
            break;
        case EVENT_TICK:
            // Show editing distance (blinking)
            if (state->editing) {
                _tachymeter_face_distance_lcd(event, state);
            }
            if (!state->running && state->total_time != 0) {
            // Display results if finished and not cleared
                if (event.subsecond < 2) {
                     _tachymeter_face_totals_lcd(state, true);
                } else {
                     _tachymeter_face_totals_lcd(state, false);
                }
            } else if (state->running){
                watch_display_string("  ", 2);
                switch (state->animation_state) {
                    case 0:
                        watch_set_pixel(0, 7);
                        break;
                    case 1:
                        watch_set_pixel(1, 7);
                        break;
                    case 2:
                        watch_set_pixel(2, 7);
                        break;
                    case 3:
                        watch_set_pixel(2, 6);
                        break;
                    case 4:
                        watch_set_pixel(2, 8);
                        break;
                    case 5:
                        watch_set_pixel(0, 8);
                        break;
                }
                state->animation_state = (state->animation_state + 1) % 6;
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (state->editing){
                // Go to next digit
                state->active_digit = (state->active_digit + 1) % 6;
            } else {
                movement_illuminate_led();
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (!state->running && !state->editing){
                if (state->total_time != 0){
                    // Clear results
                    state->total_time = 0;
                    state->total_speed = 0;
                } else {
                    // Default distance
                    state->dist_digits.thousands  = 0;
                    state->dist_digits.hundreds   = 0;
                    state->dist_digits.tens       = 0;
                    state->dist_digits.ones       = 1;
                    state->dist_digits.tenths     = 0;
                    state->dist_digits.hundredths = 0;
                    state->distance = _distance_from_struct(state->dist_digits);
                }
            _tachymeter_face_distance_lcd(event, state);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (!state->running && state->total_time == 0){
                if (settings->bit.button_should_sound && !state->editing) {
                    watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
                }
                if (!state->editing) {
                    // Start running
                    state->running = true;
                    state->start_seconds = watch_rtc_get_date_time();
                    state->start_subsecond = event.subsecond;
                    state->total_time = 0;
                } else {
                    // Alarm button to increase active digit
                    switch (state->active_digit) {
                        case 0:
                            state->dist_digits.thousands = (state->dist_digits.thousands + 1) % 10;
                            break;
                        case 1:
                            state->dist_digits.hundreds = (state->dist_digits.hundreds + 1) % 10;
                            break;
                        case 2:
                            state->dist_digits.tens = (state->dist_digits.tens + 1) % 10;
                            break;
                        case 3:
                            state->dist_digits.ones = (state->dist_digits.ones + 1) % 10;
                            break;
                        case 4:
                            state->dist_digits.tenths = (state->dist_digits.tenths + 1) % 10;
                            break;
                        case 5:
                            state->dist_digits.hundredths = (state->dist_digits.hundredths + 1) % 10;
                            break;
                    }
                }
            } else if (state->running) {
                if (settings->bit.button_should_sound && !state->editing) {
                    watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
                }
                // Stop running
                state->running = false;
                watch_date_time now = watch_rtc_get_date_time();
                uint32_t now_timestamp = watch_utility_date_time_to_unix_time(now, 0);
                uint32_t start_timestamp = watch_utility_date_time_to_unix_time(state->start_seconds, 0);
                // Total time in centiseconds
                state->total_time = ((now_timestamp*100) + (event.subsecond*25)) - ((start_timestamp*100) + (state->start_subsecond*25));
                // Total speed in distance units per hour
                state->total_speed = (uint32_t)(3600 * 100 * state->distance / state->total_time);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (!state->running && state->total_time == 0){
                if (!state->editing) {
                    // Enter editing
                    state->editing = true;
                    state->active_digit = 0;
                    if (settings->bit.button_should_sound) {
                        watch_buzzer_play_note(BUZZER_NOTE_C7, 80);
                        watch_buzzer_play_note(BUZZER_NOTE_C8, 80);
                    }
                } else {
                    // Exit editing
                    state->editing = false;
                    // Validate distance
                    if(_distance_from_struct(state->dist_digits) == 0){
                        state->dist_digits.ones = 1;
                    }
                    _tachymeter_face_distance_lcd(event, state);
                    if (settings->bit.button_should_sound) {
                        watch_buzzer_play_note(BUZZER_NOTE_C8, 80);
                        watch_buzzer_play_note(BUZZER_NOTE_C7, 80);
                    }
                }
            }
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }
    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void tachymeter_face_resign(movement_settings_t *settings, void *context) {
    (void)settings;
    (void)context;
    // handle any cleanup before your watch face goes off-screen.
}
