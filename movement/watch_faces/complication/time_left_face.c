/*
 * MIT License
 *
 * Copyright (c) 2022 Andreas Nebinger, based on the work of Joey Castillo
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
#include "time_left_face.h"
#include "watch.h"
#include "watch_private_display.h"
#include "watch_utility.h"

const char _state_titles[][3] = {{'D', 'L', ' '}, {'D', 'L', ' '}, {'D', 'A', ' '}, {'D', 'A', ' '}, {'Y', 'R', 'b'}, {'M', 'O', 'b'}, {'D', 'A', 'b'},
                                 {'Y', 'R', 'd'}, {'M', 'O', 'd'}, {'D', 'A', 'd'}};
const uint8_t TIME_LEFT_FACE_STATES = sizeof(_state_titles) / 3;            // total number of state pages
#define TIME_LEFT_FACE_SETTINGS_STATE 4                                     // number of first settings state
const uint8_t _percentage_segdata[][2] = {{1, 2}, {2, 2}, {2, 3}, {1, 3}};  // segment data for drawing the percentage sign
const uint8_t _animation_segdata[][2] = {{2, 8}, {1, 8}, {2, 7}, {2, 6}};  // segment data for the ticking animation

static bool _quick_ticks_running;

static uint32_t _juliandaynum(uint16_t year, uint16_t month, uint16_t day) {
    // from here: https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation
    return (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100))/4 + day - 32075;
}

/// @brief displays an integer value with or without using positions 8 and 9
static void _display_integer(char *buf) {
    if (buf[1] == ' ') { 
        // display at position 4 if the value is short enough, don't use positions 8 and 9
        watch_display_character(' ', 8);
        watch_display_character(' ', 9);
        watch_display_string((char *)buf + 2, 4);
    } else  {
        // otherwise just display using position 8 and 9
        watch_display_string(buf, 4);
    }
    watch_clear_colon();
}

///@brief display a percentage value
static void _display_percentage(float percentage, char *buf) {
    // always stay positive
    if (percentage < 0) {
        percentage *= -1;
        // Switch display to days 'O'ver
        watch_display_character('O', 1);
    }
    int32_t integral = percentage;
    if (integral >= 100) {
        // percentage equals 100 or more: don't do fractional part
        sprintf(buf, " %3li o", integral);
        watch_clear_colon();
    } else {
        // display percentage with two decimal places
        uint8_t fraction = (int)(percentage * (float)100) % 100;
        sprintf(buf, "%2li%02u o", integral, fraction);
        watch_set_colon();
    }
    watch_display_string(buf, 4);
    // draw (parts of) percentage symbol
    for (uint8_t i = 0; i < sizeof(_percentage_segdata) / 2; i++) 
        watch_set_pixel(_percentage_segdata[i][0], _percentage_segdata[i][1]);
}

/// @brief draw the current state to the display
static void _draw(time_left_state_t *state, uint8_t subsecond) {
    char buf[17];
    watch_display_character(_state_titles[state->current_page][0], 0);
    watch_display_character(_state_titles[state->current_page][1], 1);
    watch_display_character(' ', 2);
    watch_display_character(_state_titles[state->current_page][2], 3);
    if (state->current_page < TIME_LEFT_FACE_SETTINGS_STATE) {
        // we are displaying days left or days from birth
        watch_date_time date_time = watch_rtc_get_date_time();
        uint32_t julian_current_day = _juliandaynum(date_time.unit.year + WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day);
        uint32_t julian_target_day = _juliandaynum(state->target_date.bit.year, state->target_date.bit.month, state->target_date.bit.day);
        int32_t days_left = julian_target_day - julian_current_day;
        if (state->current_page == 0) {
            // display number of days left
            sprintf(buf, "%6li", days_left);
            _display_integer(buf);
        } else {
            // calculate starting date
            uint32_t julian_start_day = _juliandaynum(state->birth_date.bit.year, state->birth_date.bit.month, state->birth_date.bit.day);
            if ((state->current_page & 1) == 1) {
                float percentage_left;
                if (julian_start_day == julian_target_day) {
                    // failsafe
                    percentage_left = 0;
                } else {
                    // display correct percentages
                    percentage_left = (float)days_left * (float)100 / (float)(julian_target_day - julian_start_day);
                }
                _display_percentage(state->current_page == 1 ? percentage_left : 100 - percentage_left, buf);
            } else {
                // display days from birth
                sprintf(buf, "%6li", (int32_t)julian_current_day - julian_start_day);
                _display_integer(buf);
            }
        }
    } else {
        // we are in settings mode
        switch (state->current_page) {
        case TIME_LEFT_FACE_SETTINGS_STATE:
            // birth year
            sprintf(buf, "%04u  ", state->birth_date.bit.year);
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 1:
            // birth month
            sprintf(buf, "  %02u", state->birth_date.bit.month);
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 2:
            // birth day of month
            sprintf(buf, "  %02u", state->birth_date.bit.day);
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 3:
            // target year
            sprintf(buf, "%04u", state->target_date.bit.year);
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 4:
            // target month
            sprintf(buf, "  %02u", state->target_date.bit.month);
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 5:
            // target day of month
            sprintf(buf, "  %02u", state->target_date.bit.day);
            break;
        default:
            break;
        }
        // blink current settings position or display value
        if ((subsecond & 1) == 1) 
            watch_display_string("    ", 4);
        else
            watch_display_string(buf, 4);
    }
}

/// @brief handle short or long pressing the alarm button
static void _handle_alarm_button(time_left_state_t *state) {
    
    switch (state->current_page) {
        case TIME_LEFT_FACE_SETTINGS_STATE: // birth year
            state->birth_date.bit.year++;
            if (state->birth_date.bit.year > state->current_year + 10) state->birth_date.bit.year = 1959;
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 1: // birth month
            state->birth_date.bit.month = (state->birth_date.bit.month % 12) + 1;
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 2: // birth day
            state->birth_date.bit.day++;
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 3: // target year
            state->target_date.bit.year++;
            if (state->target_date.bit.year  >2083) state->target_date.bit.year = state->current_year - 10;
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 4: // target month
            state->target_date.bit.month = (state->target_date.bit.month % 12) + 1;
            break;
        case TIME_LEFT_FACE_SETTINGS_STATE + 5: // target day
            state->target_date.bit.day++;
            break;
    }
    if (state->birth_date.bit.day > days_in_month(state->birth_date.bit.month, state->birth_date.bit.year))
        state->birth_date.bit.day = 1;
    if (state->target_date.bit.day > days_in_month(state->target_date.bit.month, state->birth_date.bit.year))
        state->target_date.bit.day = 1;
}

static void _initiate_setting(time_left_state_t *state) {
    state->current_page = TIME_LEFT_FACE_SETTINGS_STATE;
    watch_clear_colon();
    movement_request_tick_frequency(4);
}

static void _resume_setting(time_left_state_t *state) {
    state->current_page = 0;
    movement_request_tick_frequency(1);
}

static void _abort_quick_ticks() {
    if (_quick_ticks_running) {
        _quick_ticks_running = false;
        movement_request_tick_frequency(4);
    }
}

void time_left_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(time_left_state_t));
        memset(*context_ptr, 0, sizeof(time_left_state_t));
        time_left_state_t *state = (time_left_state_t *)*context_ptr;
        state->birth_date.reg = watch_get_backup_data(2);
        if (state->birth_date.reg == 0) {
            // if birth date is totally blank, set a reasonable starting date. this works well for anyone under 63, but
            // you can keep pressing to go back to 1900; just pass the current year. also picked this date because if you
            // set it to 1959-01-02, it counts up from the launch of Luna-1, the first spacecraft to leave the well.
            state->birth_date.bit.year = 1959;
            state->birth_date.bit.month = 1;
            state->birth_date.bit.day = 1;
            watch_store_backup_data(state->birth_date.reg, 2);
            // set target date to today + 10 years (just to have any value)
            watch_date_time date_time = watch_rtc_get_date_time();
            state->target_date.bit.year = date_time.unit.year + WATCH_RTC_REFERENCE_YEAR + 10;
            state->target_date.bit.month = date_time.unit.month;
            state->target_date.bit.day = date_time.unit.day;
        }
    }
}

void time_left_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    time_left_state_t *state = (time_left_state_t *)context;

    // stash the current year, useful in birthday setting mode
    watch_date_time date_time = watch_rtc_get_date_time();
    state->current_year = date_time.unit.year + WATCH_RTC_REFERENCE_YEAR;
    _quick_ticks_running = false;
    // fetch the user's birth date from the birthday register
    state->birth_date.reg = watch_get_backup_data(2);
    // store original value of the birthdate to be able to detect changes on resigning
    state->birth_date_when_activated.reg = state->birth_date.reg;
}

bool time_left_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    time_left_state_t *state = (time_left_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _draw(state, event.subsecond);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
        case EVENT_TICK: {
            uint8_t subsecond = event.subsecond;
            if (_quick_ticks_running) {
                if (watch_get_pin_level(BTN_ALARM)) {
                    _handle_alarm_button(state);
                    subsecond = 0;
                } else _abort_quick_ticks();
            }
            if (state->current_page >= TIME_LEFT_FACE_SETTINGS_STATE) {
                // we are in settings mode. Draw to blink
                _draw(state, subsecond);
            } else {
                // otherwise, check if we have to update. the display only needs to change at midnight
                watch_date_time date_time = watch_rtc_get_date_time();
                if (date_time.unit.hour == 0 &&  date_time.unit.minute == 0 && date_time.unit.second == 0) {
                    _draw(state, subsecond);
                }
                // handle the ticking animation
                uint8_t animation_step = date_time.unit.second % (sizeof(_animation_segdata) / 2);
                watch_set_pixel(_animation_segdata[animation_step][0], _animation_segdata[animation_step][1]);
                if (animation_step == 0) animation_step = (sizeof(_animation_segdata) / 2) - 1;
                else animation_step--;
                watch_clear_pixel(_animation_segdata[animation_step][0], _animation_segdata[animation_step][1]);
            }
            break;
        }
        case EVENT_LIGHT_BUTTON_DOWN:
            // do not illuminate here (this is done when releasing the button)
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (state->current_page < TIME_LEFT_FACE_SETTINGS_STATE) movement_illuminate_led();
            else {
                // cycle through the settings pages
                state->current_page++;
                if (state->current_page >= TIME_LEFT_FACE_STATES) {
                    // we have done a full settings cycle, so resume to normal
                    _resume_setting(state);
                    _draw(state, event.subsecond);
                }
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->current_page >= TIME_LEFT_FACE_SETTINGS_STATE) {
                _resume_setting(state);
            } else {
                _initiate_setting(state);
            }
            _draw(state, event.subsecond);
            break;
        case EVENT_ALARM_BUTTON_UP:
            _abort_quick_ticks();
            if (state->current_page < TIME_LEFT_FACE_SETTINGS_STATE) {
                // alternate between days left and percentage left
                state->current_page = (state->current_page + 1) % TIME_LEFT_FACE_SETTINGS_STATE;
            } else {
                // we are in settings mode, so increment the current settings value
                _handle_alarm_button(state);
            }
            _draw(state, 0);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->current_page >= TIME_LEFT_FACE_SETTINGS_STATE) {
                // initiate fast cycling for settings values
                movement_request_tick_frequency(8);
                _quick_ticks_running = true;
                _handle_alarm_button(state);
                _draw(state, 0);
            }
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

void time_left_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    time_left_state_t *state = (time_left_state_t *)context;

    if (state->current_page >= TIME_LEFT_FACE_SETTINGS_STATE) _resume_setting(state);

    // if the user changed their birth date, store it to the birth date register
    if (state->birth_date_when_activated.reg != state->birth_date.reg) {
        watch_store_backup_data(state->birth_date.reg, 2);
    }
}
