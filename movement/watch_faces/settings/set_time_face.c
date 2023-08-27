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
#include "set_time_face.h"
#include "watch.h"

#define SET_TIME_FACE_NUM_SETTINGS (7)
const char set_time_face_titles[SET_TIME_FACE_NUM_SETTINGS][3] = {"HR", "M1", "SE", "YR", "MO", "DA", "ZO"};

static bool _quick_ticks_running;

static void _handle_alarm_button(movement_settings_t *settings, watch_date_time date_time, uint8_t current_page) {
    // handles short or long pressing of the alarm button
    const uint8_t days_in_month[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};

    switch (current_page) {
        case 0: // hour
            date_time.unit.hour = (date_time.unit.hour + 1) % 24;
            break;
        case 1: // minute
            date_time.unit.minute = (date_time.unit.minute + 1) % 60;
            break;
        case 2: // second
            date_time.unit.second = 0;
            break;
        case 3: // year
            date_time.unit.year = ((date_time.unit.year % 60) + 1);
            break;
        case 4: // month
            date_time.unit.month = (date_time.unit.month % 12) + 1;
            break;
        case 5: { // day
            uint32_t tmp_day = date_time.unit.day;   // use a temporary variable to avoid messing up the months
            tmp_day = tmp_day + 1;
            // handle February 29th on a leap year
            if (((tmp_day > days_in_month[date_time.unit.month - 1]) && (date_time.unit.month != 2 || (date_time.unit.year % 4) != 0))
                || (date_time.unit.month == 2 && (date_time.unit.year % 4) == 0 && tmp_day > 29)) {
                tmp_day = 1;
            }
            date_time.unit.day = tmp_day;
            break;
        }
        case 6: // time zone
            settings->bit.time_zone++;
            if (settings->bit.time_zone > 40) settings->bit.time_zone = 0;
            break;
    }
    watch_rtc_set_date_time(date_time);
}

static void _abort_quick_ticks() {
    if (_quick_ticks_running) {
        _quick_ticks_running = false;
        movement_request_tick_frequency(4);
    }
}

void set_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(uint8_t));
}

void set_time_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    *((uint8_t *)context) = 0;
    movement_request_tick_frequency(4);
    _quick_ticks_running = false;
}

bool set_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    uint8_t current_page = *((uint8_t *)context);
    watch_date_time date_time = watch_rtc_get_date_time();

    switch (event.event_type) {
        case EVENT_TICK:
            if (_quick_ticks_running) {
                if (watch_get_pin_level(BTN_ALARM)) _handle_alarm_button(settings, date_time, current_page);
                else _abort_quick_ticks();
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (current_page != 2) {
                _quick_ticks_running = true;
                movement_request_tick_frequency(8);
            }
            break;
        case EVENT_ALARM_LONG_UP:
            _abort_quick_ticks();
            break;
        case EVENT_MODE_BUTTON_UP:
            _abort_quick_ticks();
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_BUTTON_DOWN:
            current_page = (current_page + 1) % SET_TIME_FACE_NUM_SETTINGS;
            *((uint8_t *)context) = current_page;
            break;
        case EVENT_ALARM_BUTTON_UP:
            _abort_quick_ticks();
            _handle_alarm_button(settings, date_time, current_page);
            break;
        case EVENT_TIMEOUT:
            _abort_quick_ticks();
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    char buf[11];
    if (current_page < 3) {
        watch_set_colon();
        if (settings->bit.clock_mode_24h) {
            watch_set_indicator(WATCH_INDICATOR_24H);
            sprintf(buf, "%s  %2d%02d%02d", set_time_face_titles[current_page], date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
        } else {
            sprintf(buf, "%s  %2d%02d%02d", set_time_face_titles[current_page], (date_time.unit.hour % 12) ? (date_time.unit.hour % 12) : 12, date_time.unit.minute, date_time.unit.second);
            if (date_time.unit.hour < 12) watch_clear_indicator(WATCH_INDICATOR_PM);
            else watch_set_indicator(WATCH_INDICATOR_PM);
        }
    } else if (current_page < 6) {
        watch_clear_colon();
        watch_clear_indicator(WATCH_INDICATOR_24H);
        watch_clear_indicator(WATCH_INDICATOR_PM);
        sprintf(buf, "%s  %2d%02d%02d", set_time_face_titles[current_page], date_time.unit.year + 20, date_time.unit.month, date_time.unit.day);
    } else {
        if (event.subsecond % 2) {
            watch_clear_colon();
            sprintf(buf, "%s        ", set_time_face_titles[current_page]);
        } else {
            watch_set_colon();
            sprintf(buf, "%s %3d%02d  ", set_time_face_titles[current_page], (int8_t) (movement_timezone_offsets[settings->bit.time_zone] / 60), (int8_t) (movement_timezone_offsets[settings->bit.time_zone] % 60) * (movement_timezone_offsets[settings->bit.time_zone] < 0 ? -1 : 1));
        }
    }

    // blink up the parameter we're setting
    if (event.subsecond % 2 && !_quick_ticks_running) {
        switch (current_page) {
            case 0:
            case 3:
                buf[4] = buf[5] = ' ';
                break;
            case 1:
            case 4:
                buf[6] = buf[7] = ' ';
                break;
            case 2:
            case 5:
                buf[8] = buf[9] = ' ';
                break;
        }
    }

    watch_display_string(buf, 0);

    return true;
}

void set_time_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off();
    watch_store_backup_data(settings->reg, 0);
}
