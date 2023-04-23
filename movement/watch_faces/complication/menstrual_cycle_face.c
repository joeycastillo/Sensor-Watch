/*
 * MIT License
 *
 * Copyright (c) 2023 Joseph Komosa | @jokomo24
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

#define TYPICAL_AVG_CY 28
#define SECONDS_PER_DAY 86400

#define MENSTRUAL_CYCLE_FACE_NUM_PAGES (6)
enum {
    period_in_num_days,
    average_cycle,
    peak_fertility_window,
    period_is_here,
    first_period,
    reset,
} page_titles_e;
const char menstrual_cycle_face_titles[MENSTRUAL_CYCLE_FACE_NUM_PAGES][11] = {
    "Prin   day",   // Period In <num> Days: Estimated days till the next period
    "Av  cycle ",   // Average Cycle: The average number of days estimated for the cycle
    "Peak Fert ",   // Peak Fertility Window: The first and last day of month (displayed top & bottom right, respectively, once tracking) for the estimated window of fertility
    "Prishere  ",   // Period Is Here: Set to yes (toggle y and hold via alarm) to save current date as the "previous" period, improving the 'days till next period', 'average cycle', and 'peak fertility window' estimations
    "Last Per  ",   // Last (first) Period: To begin tracking and for once only, enter the number of days (++days via alarm, and hold to enter) since the most recent period, thus becoming the date of "first" logged period
    "    Reset ",   // Reset: Set to yes (toggle y and hold via alarm) to reset period tracking
};

static inline uint16_t total_days_tracked(movement_settings_t *settings, menstrual_cycle_state_t *state) {
    if (!(state->dates.reg)) return 0; // Tracking has not yet been activated
    
    watch_date_time date_time_start;
    date_time_start.unit.day = state->dates.bit.first_day;
    date_time_start.unit.month = state->dates.bit.first_month;
    date_time_start.unit.year = state->dates.bit.first_year;
    watch_date_time date_time_now = watch_rtc_get_date_time();
    uint32_t unix_start = watch_utility_date_time_to_unix_time(date_time_start, movement_timezone_offsets[settings->bit.time_zone] * 60);
    uint32_t unix_now = watch_utility_date_time_to_unix_time(date_time_now, movement_timezone_offsets[settings->bit.time_zone] * 60);
    return (unix_now - unix_start) / SECONDS_PER_DAY;
}

static inline uint8_t days_till_period(movement_settings_t *settings, menstrual_cycle_state_t *state) {
    int16_t days_left = (state->cycles.bit.average_cycle * (state->cycles.bit.total_cycles + 1)) - total_days_tracked(settings, state);
    if (days_left < 0) return 0;
    return days_left;
}

static inline void reset_tracking(menstrual_cycle_state_t *state) {
    state->dates.bit.first_day = 0;
    state->dates.bit.first_month = 0;
    state->dates.bit.first_year = 0;
    state->dates.bit.prev_day = 0;
    state->dates.bit.prev_month = 0;
    state->dates.bit.prev_year = 0;
    state->cycles.bit.shortest_cycle = TYPICAL_AVG_CY;
    state->cycles.bit.longest_cycle = TYPICAL_AVG_CY;
    state->cycles.bit.average_cycle = TYPICAL_AVG_CY;
    state->cycles.bit.total_cycles = 0;
    watch_store_backup_data(state->dates.reg, state->backup_register_dt);
    watch_store_backup_data(state->dates.reg, state->backup_register_cy);
    strcpy(menstrual_cycle_face_titles[peak_fertility_window], "Peak Fert ");
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

/* Beep function */
static inline void beep(movement_settings_t *settings) {
    if (settings->bit.button_should_sound) watch_buzzer_play_note(BUZZER_NOTE_E8, 75);
}

typedef enum {first_day, last_day} fertile_window;
/*
Fertility Window based on "The Calendar Method"
Trusted Source: https://www.womenshealth.gov/pregnancy/you-get-pregnant/trying-conceive

The Calendar Method has several steps:

Step 1: Track the menstrual cycle for 8–12 months. One cycle is from the first day of one 
        period until the first day of the next period. The average cycle is 28 days, but 
        it may be as short as 24 days or as long as 38 days.
Step 2: Subtract 18 from the number of days in the shortest menstrual cycle.
Step 3: Subtract 11 from the number of days in the longest menstrual cycle.
Step 4: Using a calendar, mark down the start of the next period. Count ahead by the number
        of days calculated in step 2. This is when peak fertility begins. Peak fertility ends
        at the number of days calculated in step 3.
*/
static inline uint8_t get_day_pk_fert(movement_settings_t *settings, menstrual_cycle_state_t *state, fertile_window which_day) {
    watch_date_time date_prev_period;
    date_prev_period.unit.day = state->dates.bit.prev_day;
    date_prev_period.unit.month = state->dates.bit.prev_month;
    date_prev_period.unit.year = state->dates.bit.prev_year;
    uint32_t unix_prev_period = watch_utility_date_time_to_unix_time(date_prev_period, movement_timezone_offsets[settings->bit.time_zone] * 60);
    uint32_t unix_pk_date;
    switch(which_day) {
        case first_day:
            unix_pk_date = unix_prev_period + ((state->cycles.bit.shortest_cycle - 18) * SECONDS_PER_DAY);
            break;
        case last_day:
            unix_pk_date = unix_prev_period + ((state->cycles.bit.longest_cycle - 11) * SECONDS_PER_DAY);
            break;
    }
    return watch_utility_date_time_from_unix_time(unix_pk_date, movement_timezone_offsets[settings->bit.time_zone] * 60).unit.day;
}

static inline bool inside_fert_window(movement_settings_t *settings, menstrual_cycle_state_t *state) {
    watch_date_time date_time_now = watch_rtc_get_date_time();
    if (date_time_now.unit.day > get_day_pk_fert(settings, state, first_day) && 
       (date_time_now.unit.day < get_day_pk_fert(settings, state, last_day)))
       return true;
    return false;
}

static inline void calc_shortest_longest_cycle(movement_settings_t *settings, menstrual_cycle_state_t *state) {
    watch_date_time date_prev_period;
    date_prev_period.unit.day = state->dates.bit.prev_day;
    date_prev_period.unit.month = state->dates.bit.prev_month;
    date_prev_period.unit.year = state->dates.bit.prev_year;
    uint32_t unix_prev_period = watch_utility_date_time_to_unix_time(date_prev_period, movement_timezone_offsets[settings->bit.time_zone] * 60);
    uint8_t cycle_length = total_days_tracked(settings, state) - (unix_prev_period / SECONDS_PER_DAY);
    if (cycle_length < state->cycles.bit.shortest_cycle)
        state->cycles.bit.shortest_cycle = cycle_length;
    else if (cycle_length > state->cycles.bit.longest_cycle)
        state->cycles.bit.longest_cycle = cycle_length;
}

void menstrual_cycle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(menstrual_cycle_state_t));
        memset(*context_ptr, 0, sizeof(menstrual_cycle_state_t));
        menstrual_cycle_state_t *state = ((menstrual_cycle_state_t *)*context_ptr);
        state->dates.bit.first_day = 0;
        state->dates.bit.first_month = 0;
        state->dates.bit.first_year = 0;
        state->dates.bit.prev_day = 0;
        state->dates.bit.prev_month = 0;
        state->dates.bit.prev_year = 0;
        state->cycles.bit.shortest_cycle = TYPICAL_AVG_CY;
        state->cycles.bit.longest_cycle = TYPICAL_AVG_CY;
        state->cycles.bit.average_cycle = TYPICAL_AVG_CY;
        state->cycles.bit.total_cycles = 0;
        state->backup_register_dt = 0;
        state->backup_register_cy = 0;
    }
    menstrual_cycle_state_t *state = ((menstrual_cycle_state_t *)*context_ptr);
    if (!(state->backup_register_dt && state->backup_register_cy)) {
        state->backup_register_dt = movement_claim_backup_register();
        state->backup_register_cy = movement_claim_backup_register();
        if (state->backup_register_dt && state->backup_register_cy) {
            watch_store_backup_data(state->dates.reg, state->backup_register_dt);
            watch_store_backup_data(state->cycles.reg, state->backup_register_cy);
        }
    }
    else {
        state->dates.reg = watch_get_backup_data(state->backup_register_dt);
        state->cycles.reg = watch_get_backup_data(state->backup_register_cy);
    }
}

void menstrual_cycle_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    menstrual_cycle_state_t *state = (menstrual_cycle_state_t *)context;
    state->period_today = 0;
    state->current_page = 0;
    state->reset_tracking = 0;
    movement_request_tick_frequency(4); // we need to manually blink some pixels
}

bool menstrual_cycle_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    menstrual_cycle_state_t *state = (menstrual_cycle_state_t *)context;
    uint8_t current_page = state->current_page;
    uint32_t unix_now;
    watch_date_time date_period;
    uint8_t first_day_fert;
    uint8_t last_day_fert;
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
            state->current_page = current_page;
            state->days_since_period = 0;
            watch_clear_indicator(WATCH_INDICATOR_BELL);
            if (watch_tick_animation_is_running())
                watch_stop_tick_animation();
            break;
        case EVENT_ALARM_LONG_PRESS:
            switch (current_page) {
                case period_in_num_days:
                    break;
                case average_cycle:
                    break;
                case peak_fertility_window:
                    break;
                case period_is_here:
                    if (state->period_today && total_days_tracked(settings, state)) {
                        // Calculate before updating date of last period
                        calc_shortest_longest_cycle(settings, state);
                        // Update date of last period
                        date_period = watch_rtc_get_date_time();
                        state->dates.bit.prev_day = date_period.unit.day;
                        state->dates.bit.prev_month = date_period.unit.month;
                        state->dates.bit.prev_year = date_period.unit.year;
                        // Calculate new cycle average
                        state->cycles.bit.total_cycles += 1;
                        state->cycles.bit.average_cycle = total_days_tracked(settings, state) / state->cycles.bit.total_cycles;
                        // Store new data
                        watch_store_backup_data(state->dates.reg, state->backup_register_dt);
                        watch_store_backup_data(state->cycles.reg, state->backup_register_cy);
                        // beep(settings);
                    }
                    break;
                case first_period:
                    if (!(total_days_tracked(settings, state))) {
                        unix_now = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60);
                        date_period = watch_utility_date_time_from_unix_time(unix_now - (state->days_since_period * SECONDS_PER_DAY), movement_timezone_offsets[settings->bit.time_zone] * 60); 
                        state->dates.bit.first_day = date_period.unit.day;
                        state->dates.bit.first_month = date_period.unit.month;
                        state->dates.bit.first_year = date_period.unit.year;
                        state->dates.bit.prev_day = date_period.unit.day;
                        state->dates.bit.prev_month = date_period.unit.month;
                        state->dates.bit.prev_year = date_period.unit.year;
                        watch_store_backup_data(state->dates.reg, state->backup_register_dt);
                        // beep(settings);
                    }
                    break;
                case reset:
                    if (state->reset_tracking) {
                        reset_tracking(state);
                        beep(settings);
                    }
                    break;
            }
        case EVENT_ALARM_BUTTON_UP:
            switch (current_page) {
                case period_in_num_days:
                    break;
                case average_cycle:
                    break;
                case peak_fertility_window:
                    break;
                case period_is_here:
                    if (state->dates.reg && total_days_tracked(settings, state))
                        state->period_today = !(state->period_today);
                    break;
                case first_period:
                    if (!(state->dates.reg)) 
                        state->days_since_period = (state->days_since_period > 99) ? 0 : state->days_since_period + 1; // Cycle through pages to quickly reset to 0
                    break;
                case reset:
                    state->reset_tracking = !(state->reset_tracking);
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
        if (state->dates.reg)
             watch_set_indicator(WATCH_INDICATOR_SIGNAL); // signal that we are now in a tracking state
        switch (current_page) {
            case period_in_num_days:
                sprintf(buf, "%2d", days_till_period(settings, state));
                if (inside_fert_window(settings, state))
                    watch_set_indicator(WATCH_INDICATOR_BELL); // turn on alarm pixel 
                watch_display_string(buf, 4);
                break;
            case average_cycle:
                sprintf(buf, "%2d", state->cycles.bit.average_cycle);
                watch_display_string(buf, 2);
                break;
            case peak_fertility_window:
                if (state->dates.reg) {
                    if (strcmp(menstrual_cycle_face_titles[current_page], "Peak Fert ") == 0)
                        strcpy(menstrual_cycle_face_titles[current_page], "Fr   To   ");
                    first_day_fert = get_day_pk_fert(settings, state, first_day);
                    last_day_fert = get_day_pk_fert(settings, state, last_day);
                    sprintf(buf, "%2d", first_day_fert);
                    watch_display_string(buf, 2);
                    sprintf(buf, "%2d", last_day_fert);
                    watch_display_string(buf, 8);
                    if (inside_fert_window(settings, state))
                        watch_set_indicator(WATCH_INDICATOR_BELL); // turn on alarm pixel 
                }
                break;
            case period_is_here:
                if (!(state->dates.reg))
                    watch_display_string("NA", 8); // Not Applicable: Do not allow period entry until tracking is activated...
                else if (total_days_tracked(settings, state) % state->cycles.bit.average_cycle < 15) // ...and it's been >= 15 days since the last period
                    watch_start_tick_animation(500);
                else if (state->period_today)
                    watch_display_string("y", 9);
                else {
                    watch_stop_tick_animation();
                    watch_display_string("n", 9);
                }
                break;
            case first_period:
                if (state->dates.reg) 
                    watch_start_tick_animation(500); // Now tracking
                else {
                    sprintf(buf, "%2d", state->days_since_period);
                    watch_display_string(buf, 8);
                }
                break;
            case reset:
                if (state->reset_tracking) 
                    watch_display_string("y", 9);
                else 
                    watch_display_string("n", 9);
                break;
        }
    }
    return true;
}

void menstrual_cycle_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}