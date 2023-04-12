/*
 * MIT License
 *
 * Copyright (c) 2022 Joseph Komosa
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
#include "menstrual_cycle_face.h"
#include "watch.h"
#include "watch_utility.h"

#define MENSTRUAL_CYCLE_FACE_NUM_PAGES (6)
const char menstrual_cycle_face_titles[MENSTRUAL_CYCLE_FACE_NUM_PAGES][11] = {
    "PRin   day",   // Period In <num> Days: Days till your period
    "AV  cycle ",   // Average Cycle: Show the calculated daily average of your cycle
    "OV   prb  ",   // Ovulation Probability: The probability of you ovulating today (no, Lo, Hi)
    "PRishere  ",   // Period Is Here: Set to yes (y) on the day of your period to improve average cycle calculation
    "LAST per  ",   // Last Period: Enter the number of days since your last period to begin tracking
    "    Reset ",
};

void menstrual_cycle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(menstrual_cycle_state_t));
        memset(*context_ptr, 0, sizeof(menstrual_cycle_state_t));
        menstrual_cycle_state_t *state = ((menstrual_cycle_state_t *)*context_ptr);
        state->average.bit.total_cycles = 0;
        state->average.bit.first_day = 0;
        state->average.bit.first_month = 0;
        state->average.bit.first_year = 0;
        state->bits.backup_register = 0;
        state->days_since = 0;
    }
    menstrual_cycle_state_t *state = ((menstrual_cycle_state_t *)*context_ptr);
    if (!(state->bits.backup_register)) {
        state->bits.backup_register = movement_claim_backup_register();
        if (state->bits.backup_register) watch_store_backup_data(state->average.reg, state->bits.backup_register);
    }
    else {
        state->average.reg = watch_get_backup_data(state->bits.backup_register);
    }
}

void menstrual_cycle_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    menstrual_cycle_state_t *state = (menstrual_cycle_state_t *)context;
    state->bits.period_today = 0;
    state->bits.current_page = 0;
    state->bits.reset_tracking = 0;
    movement_request_tick_frequency(4); // we need to manually blink some pixels
}

bool menstrual_cycle_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    menstrual_cycle_state_t *state = (menstrual_cycle_state_t *)context;
    uint8_t current_page = state->bits.current_page;
    uint32_t now;
    watch_date_time date_last_period;
    switch (event.event_type) {
        case EVENT_TICK:
        case EVENT_ACTIVATE:
            // Do nothing; handled below.
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_BUTTON_DOWN:
            current_page = (current_page + 1) % MENSTRUAL_CYCLE_FACE_NUM_PAGES;
            state->bits.current_page = current_page;
            break;
        case EVENT_ALARM_LONG_PRESS:
            switch (current_page) {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    if (state->bits.period_today) {
                        state->average.bit.total_cycles += 1;
                        watch_store_backup_data(state->average.reg, state->bits.backup_register);
                        watch_buzzer_play_note(BUZZER_NOTE_E8, 100);
                    }
                    break;
                case 4:
                    if (!(get_total_days(settings, state))) {
                        now = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60);
                        date_last_period = watch_utility_date_time_from_unix_time(now - (state->days_since * 86400), movement_timezone_offsets[settings->bit.time_zone] * 60); 
                        state->average.bit.first_day = date_last_period.unit.day;
                        state->average.bit.first_month = date_last_period.unit.month;
                        state->average.bit.first_year = date_last_period.unit.year;
                        watch_store_backup_data(state->average.reg, state->bits.backup_register);
                        watch_buzzer_play_note(BUZZER_NOTE_E8, 100);
                    }
                    break;
                case 5:
                    if (state->bits.reset_tracking) {
                        state->average.bit.total_cycles = 0;
                        state->average.bit.first_day = 0;
                        state->average.bit.first_month = 0;
                        state->average.bit.first_year = 0;
                        watch_store_backup_data(state->average.reg, state->bits.backup_register);
                        watch_buzzer_play_note(BUZZER_NOTE_E8, 100);
                    }
                    break;
            }
        case EVENT_ALARM_BUTTON_UP:
            switch (current_page) {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    state->bits.period_today = !(state->bits.period_today);
                    break;
                case 4:
                    if (!(get_total_days(settings, state))) state->days_since = (state->days_since > 50) ? 0 : state->days_since + 1;
                    break;
                case 5:
                    state->bits.reset_tracking = !(state->bits.reset_tracking);
                    break;
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    watch_display_string((char *)menstrual_cycle_face_titles[current_page], 0);

    // blink active setting on even-numbered quarter-seconds
    if (event.subsecond % 2) {
        char buf[3];
        switch (current_page) {
            case 0:
                sprintf(buf, "%2d", get_days_till_period(settings, state));
                watch_display_string(buf, 4);
                break;
            case 1:
                if (state->average.bit.total_cycles > 0) sprintf(buf, "%2d", get_total_days(settings, state) / state->average.bit.total_cycles);
                else strcpy(buf, "28"); // Typical average for a menstral cycle is 28 days
                watch_display_string(buf, 2);
                break;
            case 2:
                watch_display_string("Hi", 8);
                break;
            case 3:
                if (state->bits.period_today) watch_display_string("y", 9);
                else watch_display_string("n", 9);
                break;
            case 4:
                if (!(get_total_days(settings, state))) sprintf(buf, "%2d", state->days_since);
                else strcpy(buf, "TR"); // Already Tracking
                watch_display_string(buf, 8);
                break;
            case 5:
                if (state->bits.reset_tracking) {
                    watch_display_string("y", 9);
                }
                else watch_display_string("n", 9);
                break;
        }
    }
    return true;
}

void menstrual_cycle_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    // menstrual_cycle_state_t *state = (menstrual_cycle_state_t *)context;
    // if (state->bits.backup_register) watch_store_backup_data(state->average.reg, state->bits.backup_register);
}

uint16_t get_total_days(movement_settings_t *settings, menstrual_cycle_state_t *state) {
    if (!(state->average.reg)) return 0; // Tracking has not yet been activated by logging the last period
    
    watch_date_time date_time_start;
    date_time_start.unit.day = state->average.bit.first_day;
    date_time_start.unit.month = state->average.bit.first_month;
    date_time_start.unit.year = state->average.bit.first_year;
    watch_date_time date_time_now = watch_rtc_get_date_time();
    uint32_t start_of_tracking = watch_utility_date_time_to_unix_time(date_time_start, movement_timezone_offsets[settings->bit.time_zone] * 60);
    uint32_t now = watch_utility_date_time_to_unix_time(date_time_now, movement_timezone_offsets[settings->bit.time_zone] * 60);
    return (now - start_of_tracking) / 86400; // 86400 seconds in a day
}

uint16_t get_days_till_period(movement_settings_t *settings, menstrual_cycle_state_t *state) {
    uint8_t average_cycle = 28;
    if (state->average.bit.total_cycles > 0) average_cycle = get_total_days(settings, state) / state->average.bit.total_cycles;
    return (average_cycle * (state->average.bit.total_cycles + 1)) - get_total_days(settings, state);
}