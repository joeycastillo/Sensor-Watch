/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
 * Copyright (c) 2022 Mikhail Svarichevsky https://3.14.by/
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
#include "set_time_hackwatch_face.h"
#include "watch.h"

char set_time_hackwatch_face_titles[][3] = {"HR", "M1", "SE", "YR", "MO", "DA", "ZO"};
#define set_time_hackwatch_face_NUM_SETTINGS (sizeof(set_time_hackwatch_face_titles) / sizeof(*set_time_hackwatch_face_titles))

watch_date_time date_time_settings;

void set_time_hackwatch_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(uint8_t));
}

void set_time_hackwatch_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    *((uint8_t *)context) = 3;
    movement_request_tick_frequency(32);
    date_time_settings = watch_rtc_get_date_time();
}

bool set_time_hackwatch_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    uint8_t current_page = *((uint8_t *)context);
    const uint8_t days_in_month[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};

    if (event.subsecond == 15) // Delay displayed time update by ~0.5 seconds, to align phase exactly to main clock at 1Hz
        date_time_settings = watch_rtc_get_date_time();

    static int8_t seconds_reset_sequence;

    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            if (current_page == 2)
                watch_rtc_enable(true);
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_LONG_PRESS:
            current_page = (current_page + set_time_hackwatch_face_NUM_SETTINGS - 1) % set_time_hackwatch_face_NUM_SETTINGS;
            if (current_page == 2)
                seconds_reset_sequence = 0;

            *((uint8_t *)context) = current_page;
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (current_page == 2)
                watch_rtc_enable(true);

            current_page = (current_page + 1) % set_time_hackwatch_face_NUM_SETTINGS;
            if (current_page == 2)
                seconds_reset_sequence = 0;

            *((uint8_t *)context) = current_page;
            break;
        case EVENT_TICK:
            // We use it to wait for "middle" subsecond position
            if (current_page == 2 && seconds_reset_sequence == 1 && event.subsecond == 15) { // wait ~0.5sec - until we reach half second point
                watch_rtc_enable(false);
                seconds_reset_sequence = 2;

                // Set new time while RTC is off, to get perfect start
                if (date_time_settings.unit.second > 30) {
                    date_time_settings.unit.minute = (date_time_settings.unit.minute + 1) % 60; // Roll to next minute if we are almost there
                    if (date_time_settings.unit.minute == 0) { // Overflow
                        date_time_settings.unit.hour = (date_time_settings.unit.hour + 1) % 24;
                        if (date_time_settings.unit.hour == 0) // Overflow
                            date_time_settings.unit.day++;
                    }
                }
                date_time_settings.unit.second = 0;
                watch_rtc_set_date_time(date_time_settings);
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            if (current_page == 2) {
                watch_rtc_enable(true); // If it is disabled accidentally - re-enable it
                seconds_reset_sequence = 1; // Waiting for whole second
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            switch (current_page) {
                case 0: // hour
                    date_time_settings.unit.hour = (date_time_settings.unit.hour + 24 -1) % 24;
                    break;
                case 1: // minute
                    date_time_settings.unit.minute = (date_time_settings.unit.minute + 60 - 1) % 60;
                    break;
                case 3: // year
                    // only allow 2021-2061. fix this sometime later
                    date_time_settings.unit.year = (date_time_settings.unit.year + 50 - 1) % 50;
                    break;
                case 4: // month
                    date_time_settings.unit.month = (date_time_settings.unit.month + 12 - 2) % 12 + 1;
                    break;
                case 5: // day
                    date_time_settings.unit.day = date_time_settings.unit.day - 2;
                    // can't set to the 29th on a leap year. if it's february 29, set to 11:59 on the 28th.
                    // and it should roll over.
                    if (date_time_settings.unit.day == 0) {
                        date_time_settings.unit.day = days_in_month[date_time_settings.unit.month - 1];
                    } else
                        date_time_settings.unit.day++;
                    break;
                case 6: // time zone
                    if (settings->bit.time_zone > 0) {
                        settings->bit.time_zone--;
                    } else {
                        settings->bit.time_zone = 40;
                    }
                    break;
            }
            if (current_page != 2) // Do not set time when we are at seconds, it was already set previously
                watch_rtc_set_date_time(date_time_settings);
            break;
        
        case EVENT_ALARM_LONG_UP://Setting seconds on long release
            switch (current_page) {
                case 2: // second
                    seconds_reset_sequence = 0;
                    watch_rtc_enable(true);
                    break;
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (current_page) {
                case 0: // hour
                    date_time_settings.unit.hour = (date_time_settings.unit.hour + 1) % 24;
                    break;
                case 1: // minute
                    date_time_settings.unit.minute = (date_time_settings.unit.minute + 1) % 60;
                    break;
                case 2: // second
                    seconds_reset_sequence = 0;
                    watch_rtc_enable(true);
                    break;
                case 3: // year
                    // only allow 2021-2061. fix this sometime later
                    date_time_settings.unit.year = ((date_time_settings.unit.year % 50) + 1);
                    break;
                case 4: // month
                    date_time_settings.unit.month = (date_time_settings.unit.month % 12) + 1;
                    break;
                case 5: // day
                    date_time_settings.unit.day = date_time_settings.unit.day + 1;
                    // can't set to the 29th on a leap year. if it's february 29, set to 11:59 on the 28th.
                    // and it should roll over.
                    if (date_time_settings.unit.day > days_in_month[date_time_settings.unit.month - 1]) {
                        date_time_settings.unit.day = 1;
                    }
                    break;
                case 6: // time zone
                    settings->bit.time_zone++;
                    if (settings->bit.time_zone > 40) settings->bit.time_zone = 0;
                    break;
            }
            if (current_page != 2) // Do not set time when we are at seconds, it was already set previously
                watch_rtc_set_date_time(date_time_settings);
            //TODO: Do not update whole RTC, just what we are changing
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    char buf[11];
    if (current_page < 3) {
        watch_set_colon();
        if (settings->bit.clock_mode_24h) {
            watch_set_indicator(WATCH_INDICATOR_24H);
            sprintf(buf,
                    "%s  %2d%02d%02d",
                    set_time_hackwatch_face_titles[current_page],
                    date_time_settings.unit.hour,
                    date_time_settings.unit.minute,
                    date_time_settings.unit.second);
        } else {
            sprintf(buf,
                    "%s  %2d%02d%02d",
                    set_time_hackwatch_face_titles[current_page],
                    (date_time_settings.unit.hour % 12) ? (date_time_settings.unit.hour % 12) : 12,
                    date_time_settings.unit.minute,
                    date_time_settings.unit.second);
            if (date_time_settings.unit.hour < 12) {
                watch_clear_indicator(WATCH_INDICATOR_PM);
            } else {
                watch_set_indicator(WATCH_INDICATOR_PM);
            }
        }
    } else if (current_page < 6) {
        watch_clear_colon();
        watch_clear_indicator(WATCH_INDICATOR_24H);
        watch_clear_indicator(WATCH_INDICATOR_PM);
        sprintf(buf,
                "%s  %2d%02d%02d",
                set_time_hackwatch_face_titles[current_page],
                date_time_settings.unit.year + 20,
                date_time_settings.unit.month,
                date_time_settings.unit.day);
    } else {
        if ((event.subsecond / 8 ) % 2) {
            watch_clear_colon();
            sprintf(buf, "%s        ", set_time_hackwatch_face_titles[current_page]);
        } else {
            watch_set_colon();
            sprintf(buf,
                    "%s %3d%02d  ",
                    set_time_hackwatch_face_titles[current_page],
                    (int8_t)(movement_timezone_offsets[settings->bit.time_zone] / 60),
                    (int8_t)(movement_timezone_offsets[settings->bit.time_zone] % 60) * (movement_timezone_offsets[settings->bit.time_zone] < 0 ? -1 : 1));
        }
    }

    // blink up the parameter we're setting
    if ( (event.subsecond / 8) % 2) {
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
                // Only blink first number when setting seconds, to make it easier to see subsecond error
                buf[8] = ' ';
                break;
            case 5:
                buf[8] = buf[9] = ' ';
                break;
        }
    }

    watch_display_string(buf, 0);

    return true;
}

void set_time_hackwatch_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off();
    watch_store_backup_data(settings->reg, 0);
}
