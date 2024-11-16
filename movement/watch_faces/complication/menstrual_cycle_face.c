/*
 * MIT License
 *
 * Copyright (c) 2023 Joseph Borne Komosa | @jokomo24
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
 *
 * 
 * Menstrual Cycle Face
 * 
 * Background:
 * 
 * I discovered the Casio F-91W through my partner, appreciated the retro aesthetic of the watch,
 * and got one for myself. Soon afterward I discovered the Sensor Watch project and ordered two boards! 
 * I introduced the Sensor Watch to my partner who inquired whether she could track her menstrual cycle.
 * So I decided to implement a menstrual cycle watch face that also calculates the peak fertility window
 * using The Calendar Method. While this information may be useful when attempting to achieve or avoid 
 * pregnancy, it is important to understand that these are rough estimates at best.
 * 
 * How to use:
 * 
 * 1. To begin tracking, go to 'Last Period' page and toggle the alarm button to the number of days since 
 *    the last, most recent, period and hold the alarm button to enter. This will perform the following actions:
 *    - Store the corresponding date as the 'first' period in order to calculate the total_days_tracked.
 *    - Turn on the Signal Indicator to signify that tracking has been activated.
 *    - Deactivate this page and instead show the ticking animation.
 *    - Adjust the days left in the 'Period in <num> Days' page accordingly.
 *    - Activate the 'Period Is Here' page and no longer display 'NA'. To prevent accidental user entry,
 *      the page will display the ticking animation until ten days have passed since the date of the last 
 *      period entered.
 *    - Activate the 'Peak Fertility' page to begin showing the estimated window,
 *      as well as display the Alarm Indicator, on this page and on the main 'Period in <num> Days' page,
 *      whenever the current date falls within the Peak Fertility Window.
 * 
 * 2. Toggle and enter 'y' in the 'Period Is Here' page on the day of every sequential period afterward. 
 *    DO NOT FORGET TO DO SO!
 *    - If forgotten, the data will become inaccurate and tracking will need to be reset! -> (FIXME, allow one to enter a 'missed' period using the 'Last Period' page).
 *    This will perform the following actions:
 *    - Calculate this completed cycle's length and reevaluate the shortest and longest cycle variables.
 *    - Increment total_cycles by one.
 *    - Recalculate and save the average cycle for 'Average Cycle' page.
 */

#include <stdlib.h>
#include <string.h>
#include "menstrual_cycle_face.h"
#include "watch.h"
#include "watch_utility.h"

#define TYPICAL_AVG_CYC 28
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
    "Prin   day",   // Period In <num> Days: Estimated days till the next period occurs
    "Av  cycle ",   // Average Cycle: The average number of days estimated per cycle
    "Peak Fert ",   // Peak Fertility Window: The first and last day of month (displayed top & bottom right, respectively, once tracking) for the estimated window of fertility
    "Prishere  ",   // Period Is Here: Toggle and enter 'y' on the day the actual period occurs to improve Avg and Fert estimations
    "Last Per  ",   // Last Period: Enter the number of days since the last period to begin tracking from that corresponding date by storing it as the 'first'
    "    Reset ",   // Reset: Toggle and enter 'y' to reset tracking data
};

/* Beep function */
static inline void beep(movement_settings_t *settings) {
    if (settings->bit.button_should_sound) 
        watch_buzzer_play_note(BUZZER_NOTE_E8, 75);
}

// Calculate the total number of days for which menstrual cycle tracking has been active
static inline uint32_t total_days_tracked(menstrual_cycle_state_t *state) {

    // If tracking has not yet been activated, return 0
    if (!(state->dates.reg)) 
        return 0;

    // Otherwise, set the start date to the first day of the first tracked cycle
    watch_date_time date_time_start;
    date_time_start.unit.second = 0;
    date_time_start.unit.minute = 0;
    date_time_start.unit.hour = 0;
    date_time_start.unit.day = state->dates.bit.first_day;
    date_time_start.unit.month = state->dates.bit.first_month;
    date_time_start.unit.year = state->dates.bit.first_year;

    // Get the current date and time
    watch_date_time date_time_now = watch_rtc_get_date_time();

    // Convert the start date and current date to Unix time
    uint32_t unix_start = watch_utility_date_time_to_unix_time(date_time_start, state->utc_offset);
    uint32_t unix_now = watch_utility_date_time_to_unix_time(date_time_now, state->utc_offset);

    // Calculate the total number of days and return it
    return (unix_now - unix_start) / SECONDS_PER_DAY;
}

// Calculate the number of days until the next menstrual period
static inline int8_t days_till_period(menstrual_cycle_state_t *state) {

    // Calculate the number of days left until the next period based on the average cycle length and the number of cycles tracked
    int8_t days_left = (state->cycles.bit.average_cycle * (state->cycles.bit.total_cycles + 1)) - total_days_tracked(state);

    // If the result is negative, return 0 (i.e., the period is expected to start today or has already started)
    return (days_left < 0) ? 0 : days_left;
}

static inline void reset_tracking(menstrual_cycle_state_t *state) {

    state->dates.bit.first_day = 0;
    state->dates.bit.first_month = 0;
    state->dates.bit.first_year = 0;

    state->dates.bit.prev_day = 0;
    state->dates.bit.prev_month = 0;
    state->dates.bit.prev_year = 0;

    state->cycles.bit.shortest_cycle = TYPICAL_AVG_CYC;
    state->cycles.bit.longest_cycle = TYPICAL_AVG_CYC;
    state->cycles.bit.average_cycle = TYPICAL_AVG_CYC;
    state->cycles.bit.total_cycles = 0;

    state->dates.bit.reserved = 0;
    state->cycles.bit.reserved = 0;

    watch_store_backup_data(state->dates.reg, state->backup_register_dt);
    watch_store_backup_data(state->cycles.reg, state->backup_register_cy);

    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

/*
Fertility Window based on "The Calendar Method"
Source: https://www.womenshealth.gov/pregnancy/you-get-pregnant/trying-conceive

The Calendar Method has several steps:

Step 1: Track the menstrual cycle for 8–12 months. One cycle is from the first day of one 
        period until the first day of the next period. The average cycle is 28 days, but 
        it may be as short as 24 days or as long as 38 days.
Step 2: Subtract 18 from the number of days in the shortest menstrual cycle.
Step 3: Subtract 11 from the number of days in the longest menstrual cycle.
Step 4: Using a calendar, mark down the start of the next period (using previous instead). Count ahead by the number
        of days calculated in step 2. This is when peak fertility begins. Peak fertility ends
        at the number of days calculated in step 3.
NOTE: Right now, the fertility window face displays its estimated window as soon as tracking is activated, although
      it is important to keep in mind that The Calendar Method states that peak accuracy of the window will be 
      reached only after at least 8 months of tracking the menstrual cycle (can make it so that it only displays
      after total_days_tracked >= 8 months...but the info is interesting and should already be taken with the understanding that,
      in general, it is a rough estimation at best).
*/
typedef enum Fertile_Window {first_day, last_day} fertile_window;
// Calculate the predicted starting or ending day of peak fertility
static inline uint32_t get_day_pk_fert(menstrual_cycle_state_t *state, fertile_window which_day) {

    // Get the date of the previous period
    watch_date_time date_prev_period;
    date_prev_period.unit.second = 0;
    date_prev_period.unit.minute = 0;
    date_prev_period.unit.hour = 0;
    date_prev_period.unit.day = state->dates.bit.prev_day;
    date_prev_period.unit.month = state->dates.bit.prev_month;
    date_prev_period.unit.year = state->dates.bit.prev_year;

    // Convert the previous period date to Unix time
    uint32_t unix_prev_period = watch_utility_date_time_to_unix_time(date_prev_period, state->utc_offset);

    // Calculate the Unix time of the predicted peak fertility day based on the length of the shortest/longest cycle
    uint32_t unix_pk_date;
    switch(which_day) {
        case first_day:
            unix_pk_date = unix_prev_period + ((state->cycles.bit.shortest_cycle - 18) * SECONDS_PER_DAY);
            break;
        case last_day:
            unix_pk_date = unix_prev_period + ((state->cycles.bit.longest_cycle - 11) * SECONDS_PER_DAY);
            break;
    }

    // Convert the Unix time of the predicted peak fertility day to a date/time and return the day of the month
    return watch_utility_date_time_from_unix_time(unix_pk_date, state->utc_offset).unit.day;
}

// Determine if today falls within the predicted peak fertility window
static inline bool inside_fert_window(menstrual_cycle_state_t *state) {

    // If tracking has not yet been activated, return false
    if (!(state->dates.reg)) 
        return false;

    // Get the current date/time
    watch_date_time date_time_now = watch_rtc_get_date_time();

    // Check if the current day falls between the first and last predicted peak fertility days
    if (get_day_pk_fert(state, first_day) > get_day_pk_fert(state, last_day)) { // We are crossing over the end of the month
        if (date_time_now.unit.day >= get_day_pk_fert(state, first_day) ||
            date_time_now.unit.day <= get_day_pk_fert(state, last_day))
            return true;
    }
    else if (date_time_now.unit.day >= get_day_pk_fert(state, first_day) &&
             date_time_now.unit.day <= get_day_pk_fert(state, last_day))
             return true;
    // If the current day does not fall within the predicted peak fertility window, return false
    return false;
}

// Update the shortest and longest menstrual cycles based on the previous menstrual cycle
static inline void update_shortest_longest_cycle(menstrual_cycle_state_t *state) {

    // Get the date of the previous menstrual cycle
    watch_date_time date_prev_period;
    date_prev_period.unit.second = 0;
    date_prev_period.unit.minute = 0;
    date_prev_period.unit.hour = 0;
    date_prev_period.unit.day = state->dates.bit.prev_day;
    date_prev_period.unit.month = state->dates.bit.prev_month;
    date_prev_period.unit.year = state->dates.bit.prev_year;

    // Convert the date of the previous menstrual cycle to UNIX time
    uint32_t unix_prev_period = watch_utility_date_time_to_unix_time(date_prev_period, state->utc_offset);

    // Calculate the length of the current menstrual cycle
    uint8_t cycle_length = total_days_tracked(state) - (unix_prev_period / SECONDS_PER_DAY);

    // Update the shortest or longest cycle length if necessary
    if (cycle_length < state->cycles.bit.shortest_cycle)
        state->cycles.bit.shortest_cycle = cycle_length;
    else if (cycle_length > state->cycles.bit.longest_cycle)
        state->cycles.bit.longest_cycle = cycle_length;
}

void menstrual_cycle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) watch_face_index;
    (void) settings;
    
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

        state->cycles.bit.shortest_cycle = TYPICAL_AVG_CYC;
        state->cycles.bit.longest_cycle = TYPICAL_AVG_CYC;
        state->cycles.bit.average_cycle = TYPICAL_AVG_CYC;
        state->cycles.bit.total_cycles = 0;

        state->dates.bit.reserved = 0;
        state->cycles.bit.reserved = 0;

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
    state->utc_offset = movement_timezone_offsets[settings->bit.time_zone] * 60;
    movement_request_tick_frequency(4); // we need to manually blink some pixels
}

bool menstrual_cycle_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    menstrual_cycle_state_t *state = (menstrual_cycle_state_t *)context;
    watch_date_time date_period;
    uint8_t current_page = state->current_page;
    uint8_t first_day_fert;
    uint8_t last_day_fert;
    uint32_t unix_now;
    uint32_t unix_prev_period;
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
            state->days_prev_period = 0;
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
                    if (state->period_today && total_days_tracked(state)) {
                        // Calculate before updating date of last period
                        update_shortest_longest_cycle(state);
                        // Update the date of last period after calulating the, now previous, cycle length
                        date_period = watch_rtc_get_date_time();
                        state->dates.bit.prev_day = date_period.unit.day;
                        state->dates.bit.prev_month = date_period.unit.month;
                        state->dates.bit.prev_year = date_period.unit.year;
                        // Calculate new cycle average
                        state->cycles.bit.total_cycles += 1;
                        state->cycles.bit.average_cycle = total_days_tracked(state) / state->cycles.bit.total_cycles;
                        // Store the new data
                        watch_store_backup_data(state->dates.reg, state->backup_register_dt);
                        watch_store_backup_data(state->cycles.reg, state->backup_register_cy);
                        state->period_today = !(state->period_today);
                        beep(settings);
                    }
                    break;
                case first_period:
                    // If tracking has not yet been activated
                    if (!(state->dates.reg)) {
                        unix_now = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), state->utc_offset);
                        unix_prev_period = unix_now - (state->days_prev_period * SECONDS_PER_DAY);
                        date_period = watch_utility_date_time_from_unix_time(unix_prev_period, state->utc_offset);
                        state->dates.bit.first_day = date_period.unit.day;
                        state->dates.bit.first_month = date_period.unit.month;
                        state->dates.bit.first_year = date_period.unit.year;
                        state->dates.bit.prev_day = date_period.unit.day;
                        state->dates.bit.prev_month = date_period.unit.month;
                        state->dates.bit.prev_year = date_period.unit.year;
                        watch_store_backup_data(state->dates.reg, state->backup_register_dt);
                        beep(settings);
                    }
                    break;
                case reset:
                    if (state->reset_tracking) {
                        reset_tracking(state);
                        state->reset_tracking = !(state->reset_tracking);
                        beep(settings);
                    }
                    break;
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (current_page) {
                case period_in_num_days:
                    break;
                case average_cycle:
                    break;
                case peak_fertility_window:
                    break;
                case period_is_here:
                    if (total_days_tracked(state))
                        state->period_today = !(state->period_today);
                    break;
                case first_period:
                    if (!(state->dates.reg)) 
                        state->days_prev_period = (state->days_prev_period > 99) ? 0 : state->days_prev_period + 1; // Cycle through pages to quickly reset to 0
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
    if (state->dates.reg)
        watch_set_indicator(WATCH_INDICATOR_SIGNAL); // signal that we are now in a tracking state

    char buf[13];
    switch (current_page) {
        case period_in_num_days:
            sprintf(buf, "%2d", days_till_period(state));
            if (inside_fert_window(state))
                watch_set_indicator(WATCH_INDICATOR_BELL);
            watch_display_string(buf, 4);
            break;
        case average_cycle:
            sprintf(buf, "%2d", state->cycles.bit.average_cycle);
            watch_display_string(buf, 2);
            break;
        case peak_fertility_window:
            if (event.subsecond % 5 && state->dates.reg) { // blink active for 3 quarter-seconds
                first_day_fert = get_day_pk_fert(state, first_day);
                last_day_fert = get_day_pk_fert(state, last_day);
                sprintf(buf, "Fr%2d To %2d", first_day_fert, last_day_fert); // From: first day | To: last day
                if (inside_fert_window(state))
                    watch_set_indicator(WATCH_INDICATOR_BELL);
                watch_display_string(buf, 0);
            }
            break;
        case period_is_here:
            if (event.subsecond % 5) { // blink active for 3 quarter-seconds
                if (!(state->dates.reg))
                    watch_display_string("NA", 8); // Not Applicable: Do not allow period entry until tracking is activated...
                else if (state->period_today) 
                    watch_display_string("y", 9);
                else 
                    watch_display_string("n", 9);
            }
            break;
        case first_period:
            if (state->dates.reg) {
                if (!watch_tick_animation_is_running())
                    watch_start_tick_animation(500); // Tracking activated
            }
            else if (event.subsecond % 5) { // blink active for 3 quarter-seconds
                sprintf(buf, "%2d", state->days_prev_period);
                watch_display_string(buf, 8);
            }
            break;
        case reset:
            // blink active for 3 quarter-seconds
            if (event.subsecond % 5 && state->reset_tracking)
                watch_display_string("y", 9);
            else if (event.subsecond % 5)
                watch_display_string("n", 9);
            break;
    }
    return true;
}

void menstrual_cycle_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}