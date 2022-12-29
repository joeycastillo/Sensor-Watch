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

void tachymeter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(tachymeter_state_t));
        memset(*context_ptr, 0, sizeof(tachymeter_state_t));
        tachymeter_state_t *state = (tachymeter_state_t *)*context_ptr;
        state->distance = 1;
    }
}

void tachymeter_face_activate(movement_settings_t *settings, void *context) {
    tachymeter_state_t *state = (tachymeter_state_t *)context;
    // TODO improve tick frequency for Speed/Time display
    movement_request_tick_frequency(2);
}

static void _tachymeter_face_distance_lcd(tachymeter_state_t *state){
    char buf[11];
    sprintf(buf, "TC %c%6d", 'd',  state->distance * 100);
    watch_display_string(buf, 0);
}

static void _tachymeter_face_totals_lcd(tachymeter_state_t *state, bool show_time){
    char buf[11];
    if (!show_time){
        sprintf(buf, "TC %c%6d", 'H',  state->total_speed);
    } else {
        sprintf(buf, "TC %c%6d", 't',  state->total_seconds);
    }
    watch_display_string(buf, 0);
}

bool tachymeter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    tachymeter_state_t *state = (tachymeter_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show last distance in UI
            if (!state->running){
                _tachymeter_face_distance_lcd(state);
            }
            break;
        case EVENT_TICK:
            if (!state->running && state->total_seconds != 0) {
                // Display results if finished and not cleared
                if (event.subsecond % 2 == 0) {
                    _tachymeter_face_totals_lcd(state, true);
                } else {
                    _tachymeter_face_totals_lcd(state, false);
                }
            } else if (state->running){
                // TODO Improve UI when tachymeter is running
                if (event.subsecond % 2 == 0) {
                    watch_display_string("1 ", 2);
                } else {
                    watch_display_string(" 1", 2);
                }
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // Clear results
            if (!state->running){
                state->total_seconds = 0;
                state->total_speed = 0;
                _tachymeter_face_distance_lcd(state);
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            if (settings->bit.button_should_sound) {
                watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
            }
            if (!state->running){
                state->running = true;
                state->start_time = watch_rtc_get_date_time();
                state->total_seconds = 0;
            } else {
                state->running = false;
                watch_date_time now = watch_rtc_get_date_time();
                uint32_t now_timestamp = watch_utility_date_time_to_unix_time(now, 0);
                uint32_t start_timestamp = watch_utility_date_time_to_unix_time(state->start_time, 0);
                state->total_seconds = now_timestamp - start_timestamp;
                state->total_speed = (uint32_t)(3600 * state->distance / state->total_seconds);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            // TODO Set and validate distance
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        default:
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void tachymeter_face_resign(movement_settings_t *settings, void *context) {
    // handle any cleanup before your watch face goes off-screen.
}

