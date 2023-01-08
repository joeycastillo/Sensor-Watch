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
    movement_request_tick_frequency(4);
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
    if (!show_time){
        watch_set_pixel(0, 9);
        watch_set_pixel(0, 10);
    }
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
            // Editing should flash 'd'
            if (state->editing) {
                _tachymeter_face_distance_lcd(state);
                if (event.subsecond < 2) {
                    watch_display_string("  ", 2);
                }
            } else {
                _tachymeter_face_distance_lcd(state);
            }
            if (!state->running && state->total_seconds != 0) {
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
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (!state->running){
                // Clear results
                if (!state->editing){
                    state->total_seconds = 0;
                    state->total_speed = 0;
                    _tachymeter_face_distance_lcd(state);
                } else {
                    // Edit distance
                    state->distance = (state->distance + 1);
                }
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (settings->bit.button_should_sound) {
                watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
            }
            if (!state->running){
                if (!state->editing) {
                    // Start running
                    state->running = true;
                    state->start_time = watch_rtc_get_date_time();
                    state->total_seconds = 0;
                } else {
                    // Alarm button confirm distance
                    state->editing = false;
                }
            } else {
                // Stop running
                state->running = false;
                watch_date_time now = watch_rtc_get_date_time();
                uint32_t now_timestamp = watch_utility_date_time_to_unix_time(now, 0);
                uint32_t start_timestamp = watch_utility_date_time_to_unix_time(state->start_time, 0);
                state->total_seconds = now_timestamp - start_timestamp;
                state->total_speed = (uint32_t)(3600 * state->distance / state->total_seconds);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (!state->running){
                // Enter / exit distance editing mode
                if (settings->bit.button_should_sound) {
                    if (!state->editing) {
                        watch_buzzer_play_note(BUZZER_NOTE_C7, 80);
                        watch_buzzer_play_note(BUZZER_NOTE_C8, 80);
                        //movement_illuminate_led();
                    } else {
                        watch_buzzer_play_note(BUZZER_NOTE_C8, 80);
                        watch_buzzer_play_note(BUZZER_NOTE_C7, 80);
                    }
                }
                state->editing = !state->editing;
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
