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

#define MENSTRUAL_CYCLE_FACE_NUM_PREFEFENCES (6)
const char menstrual_cycle_face_titles[MENSTRUAL_CYCLE_FACE_NUM_PREFEFENCES][11] = {
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
        ((menstrual_cycle_state_t *)*context_ptr)->average.total_days = 120;
        ((menstrual_cycle_state_t *)*context_ptr)->average.total_cycles = 4;
    }
    else {
        menstrual_cycle_state_t *state = (menstrual_cycle_state_t *)*context_ptr;
        if (state->bits.backup_register) {
            state->average.total_days = 0; //get_total_days(settings, state->bits.backup_register);
            state->average.total_cycles = 0; //get_total_cycles(state->bits.backup_register);
        }
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
    switch (event.event_type) {
        case EVENT_TICK:
        case EVENT_ACTIVATE:
            // Do nothing; handled below.
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_BUTTON_DOWN:
            current_page = (current_page + 1) % MENSTRUAL_CYCLE_FACE_NUM_PREFEFENCES;
            state->bits.current_page = current_page;
            break;
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
                    break;
                case 5:
                    state->bits.reset_tracking = !(state->bits.reset_tracking);
                    break;
            }
        case EVENT_ALARM_LONG_PRESS:
            switch (current_page) {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    if(state->bits.period_today) {
                        state->average.total_cycles += 1;
                        watch_buzzer_play_note(BUZZER_NOTE_C8, 100);
                        return false;
                    }
                    break;
                case 4:
                    break;
                case 5:
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
                sprintf(buf, "%2d", get_days_till_period(state));
                watch_display_string(buf, 4);
                break;
            case 1:
                if (state->average.total_cycles > 0) sprintf(buf, "%2d", state->average.total_days / state->average.total_cycles);
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
                watch_display_string("15", 8);
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
    watch_set_led_off();
    menstrual_cycle_state_t *state = (menstrual_cycle_state_t *)context;
    uint32_t average_data = (((((state->average.first_period.day << 4) | state->average.first_period.month) << 7) | \
                                 state->average.first_period.year) << 16) | state->average.total_cycles;
    if(!state->bits.backup_register) {
        uint8_t backup_register = movement_claim_backup_register();
        state->bits.backup_register = backup_register;
    }
    if (state->bits.backup_register) watch_store_backup_data(average_data, state->bits.backup_register);
}

uint16_t get_total_days(movement_settings_t *settings, uint8_t backup_reg) {
    uint16_t date_first_period = watch_get_backup_data(backup_reg) >> 16;
    watch_date_time date_time_start;
    date_time_start.unit.day = date_first_period >> 11; // grab 5 msb
    date_time_start.unit.month = (date_first_period & 0x0780) >> 4; // grab next 4 bits
    date_time_start.unit.year = (date_first_period & 0x007F); // grab last 7 bits
    watch_date_time date_time_now = watch_rtc_get_date_time();
    uint32_t start_of_tracking = watch_utility_date_time_to_unix_time(date_time_start, movement_timezone_offsets[settings->bit.time_zone] * 60);
    uint32_t now = watch_utility_date_time_to_unix_time(date_time_now, movement_timezone_offsets[settings->bit.time_zone] * 60);
    return (now - start_of_tracking) / 86400; // 86400 seconds in a day
}

uint16_t get_total_cycles(uint8_t backup_reg) {
    return watch_get_backup_data(backup_reg) & 0xFFFF;
}

uint16_t get_days_till_period(menstrual_cycle_state_t *state) {
    uint8_t average_cycle = (state->average.total_cycles > 0) ? state->average.total_days / state->average.total_cycles : 28;
    return (average_cycle * (state->average.total_cycles + 1)) - state->average.total_days;
}