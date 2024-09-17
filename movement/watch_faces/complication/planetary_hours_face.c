/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
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
#include <math.h>
#include "sunriset.h"
#include "watch.h"
#include "watch_utility.h"
#include "planetary_hours_face.h"

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

// STATIC FUNCTIONS AND CONSTANTS /////////////////////////////////////////////

/** @brief Planetary rulers in the Chaldean order from slowest to fastest
 *  @details Planetary rulers in the Chaldean order from slowest to fastest: 
 *  Jupiter, Mars, Sun, Venus, Mercury, Moon
 */
static const char planets[7][3] = {"Sa", "Ju", "Ma", "So", "Ve", "Me", "Lu"}; // Latin
static const char planetes[7][3] = {"Ch", "Ze", "Ar", "He", "Af", "Hr", "Se"}; // Greek

/** @brief Ruler of each weekday for easy lookup
 */
static const uint8_t plindex[7] = {3, 6, 2, 5, 1, 4, 0}; // day ruler index

/** @brief Astrological symbol for each planet
 */
static void _planetary_icon(uint8_t planet) {

    watch_clear_pixel(0, 13);
    watch_clear_pixel(0, 14);
    watch_clear_pixel(1, 13);
    watch_clear_pixel(1, 14);
    watch_clear_pixel(1, 15);
    watch_clear_pixel(2, 13);
    watch_clear_pixel(2, 14);
    watch_clear_pixel(2, 15);

    switch (planet) {
        case 0: // Saturn
            watch_set_pixel(0, 14);
            watch_set_pixel(2, 14);
            watch_set_pixel(1, 15);
            watch_set_pixel(2, 13);
            break;
        case 1: // Jupiter
            watch_set_pixel(0, 14);
            watch_set_pixel(1, 15);
            watch_set_pixel(1, 14);
            break;
        case 2: // Mars
            watch_set_pixel(2, 14);
            watch_set_pixel(2, 15);
            watch_set_pixel(1, 15);
            watch_set_pixel(2, 13);
            watch_set_pixel(1, 13);\
            break;
        case 3: // Sol
            watch_set_pixel(0, 14);
            watch_set_pixel(2, 14);
            watch_set_pixel(1, 13);
            watch_set_pixel(2, 13);
            watch_set_pixel(0, 13);
            watch_set_pixel(2, 15);
            break;
        case 4: // Venus
            watch_set_pixel(0, 14);
            watch_set_pixel(0, 13);
            watch_set_pixel(1, 13);
            watch_set_pixel(1, 15);
            watch_set_pixel(1, 14);
            break;
        case 5: // Mercury
            watch_set_pixel(0, 14);
            watch_set_pixel(1, 13);
            watch_set_pixel(1, 14);
            watch_set_pixel(1, 15);
            watch_set_pixel(2, 15);
            break;
        case 6: // Luna
            watch_set_pixel(2, 14);
            watch_set_pixel(2, 15);
            watch_set_pixel(2, 13);
            break;
    }
}

/** @details A solar phase can be a day phase between sunrise and sunset or an alternating night phase.
 *  This function calculates the start and end of the current phase based on a given geographic location.
 *  It also calculates the start of the next following phase.
 */
static void _planetary_solar_phases(movement_settings_t *settings, planetary_hours_state_t *state) {
    uint8_t phase, h;
    double sunrise, sunset;
    double hour_duration, next_hour_duration;
    uint32_t now_epoch;
    uint32_t sunrise_epoch_today, sunset_epoch_today, midnight_epoch_today;
    uint32_t sunset_epoch_yesterday, midnight_epoch_yesterday;
    uint32_t sunrise_epoch_tomorrow, sunset_epoch_tomorrow, midnight_epoch_tomorrow;
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);

    // check if we have a location. If not, display error
    if (movement_location.reg == 0) {
        watch_display_string("    no Loc", 0);
        state->no_location = true;
        return;
    }

    // location detected
    state->no_location = false;

    watch_date_time date_time = watch_rtc_get_date_time(); // the current local date / time
    watch_date_time utc_now = watch_utility_date_time_convert_zone(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60, 0); // the current date / time in UTC
    watch_date_time scratch_time; // scratchpad, contains different values at different times
    watch_date_time midnight;
    scratch_time.reg = midnight.reg = utc_now.reg;
    midnight.unit.hour = midnight.unit.minute = midnight.unit.second = 0; // start of the day at midnight

    // get location coordinate
    int16_t lat_centi = (int16_t)movement_location.bit.latitude;
    int16_t lon_centi = (int16_t)movement_location.bit.longitude;
    double lat = (double)lat_centi / 100.0;
    double lon = (double)lon_centi / 100.0;

    // save UTC offset
    state->utc_offset = ((double)movement_timezone_offsets[settings->bit.time_zone]) / 60.0;

    // calculate sunrise and sunset of current day in decimal hours after midnight
    sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &sunrise, &sunset);
    
    // calculate sunrise and sunset UNIX timestamps
    midnight_epoch_today = watch_utility_date_time_to_unix_time(midnight, 0);
    sunrise_epoch_today = midnight_epoch_today + sunrise * 3600;
    sunset_epoch_today = midnight_epoch_today + sunset * 3600;

    // go back to yesterday and calculate sunset
    midnight_epoch_yesterday = midnight_epoch_today - 86400;
    scratch_time = watch_utility_date_time_from_unix_time(midnight_epoch_yesterday, 0);
    sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &sunrise, &sunset);
    sunset_epoch_yesterday = midnight_epoch_yesterday + sunset * 3600;

    // go to tomorrow and calculate sunrise and sunset
    midnight_epoch_tomorrow = midnight_epoch_today + 86400;
    scratch_time = watch_utility_date_time_from_unix_time(midnight_epoch_tomorrow, 0);
    sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &sunrise, &sunset);
    sunrise_epoch_tomorrow = midnight_epoch_tomorrow + sunrise * 3600;
    sunset_epoch_tomorrow = midnight_epoch_tomorrow + sunset * 3600;

    // get UNIX epoch time
    now_epoch = watch_utility_date_time_to_unix_time(utc_now, 0);

    // by default we assume it is daytime (phase 1) between sunrise and sunset
    phase = 1;
    state->phase_start = sunrise_epoch_today;
    state->phase_end = sunset_epoch_today;
    state->phase_next = sunrise_epoch_tomorrow;
    state->start_at_night = false;

    // night time calculations
    if ( now_epoch < sunrise_epoch_today && now_epoch < sunset_epoch_today ) phase = 0; // morning before dawn
    if ( now_epoch > sunrise_epoch_today && now_epoch >= sunset_epoch_today ) phase = 2; // evening after dusk

    // phase 0: we are before sunrise
    if ( phase == 0) {
        state->phase_start = sunset_epoch_yesterday;
        state->phase_end = sunrise_epoch_today;
        state->phase_next = sunset_epoch_today;
        state->start_at_night = true;
    }

    // phase 2: we are after sunset
    if ( phase == 2) {
        state->phase_start = sunset_epoch_today;
        state->phase_end = sunrise_epoch_tomorrow;
        state->phase_next = sunset_epoch_tomorrow;
        state->start_at_night = true;
    }

    // calculate the duration of a planetary hour during this and the next solar phase
    hour_duration = ( state->phase_end - state->phase_start ) / 12.0;
    next_hour_duration = ( state->phase_next - state->phase_end ) / 12.0;

    // populate list of 24 planetary hour start points in UNIX timestamp format
    // starting from the beginning of the current phase
    for ( h = 0; h < 24; h++ ) {
        if ( h < 12 ) state->planetary_hours[h] = state->phase_start + h * hour_duration; // current phase
        else state->planetary_hours[h] = state->phase_end + ( h - 12 ) * next_hour_duration; // next phase
    }

    // initialize
    state->hour = 0;
    state->ruler = 0;
    state->skip_to_current = true;

}

/** @details A planetary hour is one of exactly twelve hours of a solar phase. Its length varies.
 *  This function calculates the current planetary hour and divides it up into relative minutes and seconds.
 *  It also calculates the current planetary ruler of the hour and of the day.
 */
static void _planetary_hours(movement_settings_t *settings, planetary_hours_state_t *state) {
    char buf[14];
    char ruler[3];
    uint8_t weekday, planet, planetary_hour;
    uint32_t current_hour_epoch;
    watch_date_time scratch_time;
    bool set_leading_zero = false;

    // check if we have a location. If not, display error
    if ( state->no_location ) {
        watch_display_string("    no Loc", 0);
        return;
    }

    // get current time
    watch_date_time date_time = watch_rtc_get_date_time(); // the current local date / time
    watch_date_time utc_now = watch_utility_date_time_convert_zone(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60, 0); // the current date / time in UTC
    current_hour_epoch = watch_utility_date_time_to_unix_time(utc_now, 0);
    
    // set the current planetary hour as default screen
    if ( state->skip_to_current ) {
        state->hour = ( current_hour_epoch - state->phase_start ) / (( state->phase_end - state->phase_start ) / 12.0);
        state->skip_to_current = false;
    }
    

    // when current phase ends calculate the next phase
    if ( watch_utility_date_time_to_unix_time(utc_now, 0) >= state->phase_end ) {
        _planetary_solar_phases(settings, state);
        return;
    }

    if (settings->bit.clock_mode_24h && !settings->bit.clock_24h_leading_zero) watch_set_indicator(WATCH_INDICATOR_24H);

    // roll over hour iterator
    if ( state->hour < 0 ) state->hour = 23;
    if ( state->hour > 23 ) state->hour = 0;
    if ( state->ruler < 0 ) state->hour = 2;
    if ( state->ruler > 2 ) state->hour = 0;

    // clear indicators
    watch_clear_indicator(WATCH_INDICATOR_BELL);
    watch_clear_indicator(WATCH_INDICATOR_LAP);

    // display bell indicator when displaying the current planetary hour
    if ( state->hour < 24 )
        if ( current_hour_epoch >= state->planetary_hours[state->hour] && current_hour_epoch < state->planetary_hours[state->hour + 1]) {
            watch_set_indicator(WATCH_INDICATOR_BELL);
        }

    // display LAP indicator when the hours of the next phase belong to the next day
    if ( state->start_at_night == true && state->hour > 11 )
        watch_set_indicator(WATCH_INDICATOR_LAP);

    // determine weekday from start of current phase
    scratch_time = watch_utility_date_time_from_unix_time(state->phase_start, 0);
    scratch_time = watch_utility_date_time_convert_zone(scratch_time, 0, state->utc_offset * 3600);
    weekday = watch_utility_get_iso8601_weekday_number(scratch_time.unit.year, scratch_time.unit.month, scratch_time.unit.day) - 1;
    
    // which planetary hour are we in?
    planetary_hour = state->hour % 12;

    // accomodate night hour count
    if ( state->hour < 12 ) {
        if ( state->start_at_night ) {
            planetary_hour += 12;
        }
    } else {
        if ( state->start_at_night ) {
            weekday = ( weekday + 1 ) % 7;
        } else {
            planetary_hour += 12;
        }
    }

    // make datetime object for selected planetary hour
    scratch_time = watch_utility_date_time_from_unix_time(state->planetary_hours[state->hour], 0);
    scratch_time = watch_utility_date_time_convert_zone(scratch_time, 0, state->utc_offset * 3600);
    
    // round minutes
    if (scratch_time.unit.second < 30 && scratch_time.unit.minute > 0 ) scratch_time.unit.minute--;
    else if ( scratch_time.unit.minute < 59 ) scratch_time.unit.minute++;

    // if we are in 12 hour mode, do some cleanup
    if (!settings->bit.clock_mode_24h) {
        if (scratch_time.unit.hour < 12) {
            watch_clear_indicator(WATCH_INDICATOR_PM);
        } else {
            watch_set_indicator(WATCH_INDICATOR_PM);
        }
        scratch_time.unit.hour %= 12;
        if (scratch_time.unit.hour == 0) scratch_time.unit.hour = 12;
    } else if (settings->bit.clock_24h_leading_zero && scratch_time.unit.hour < 10) {
        set_leading_zero = true;
    }
    
    // planetary ruler of the hour
    planet = ( plindex[weekday] + planetary_hour ) % 7;

    // latin or greek ruler names or astrological symbol
    if ( state->ruler == 0 ) strncpy(ruler, planets[planet], 3);
    if ( state->ruler == 1 ) strncpy(ruler, planetes[planet], 3);
    if ( state->ruler == 2 ) strncpy(ruler, "  ", 3);

    // display planetary time with ruler of the hour or ruler of the day
    sprintf(buf, "%s%2d%2d%02d  ", ruler, (planetary_hour % 24) + 1, scratch_time.unit.hour, scratch_time.unit.minute);

    watch_set_colon();
    watch_display_string(buf, 0);
    if (set_leading_zero)
        watch_display_string("0", 4);

    if ( state->ruler == 2 ) _planetary_icon(planet);
}

// PUBLIC WATCH FACE FUNCTIONS ////////////////////////////////////////////////

void planetary_hours_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) watch_face_index;
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(planetary_hours_state_t));
        memset(*context_ptr, 0, sizeof(planetary_hours_state_t));
    }
}

void planetary_hours_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    if (watch_tick_animation_is_running()) watch_stop_tick_animation();

#if __EMSCRIPTEN__
    int16_t browser_lat = EM_ASM_INT({ return lat; });
    int16_t browser_lon = EM_ASM_INT({ return lon; });
    if ((watch_get_backup_data(1) == 0) && (browser_lat || browser_lon)) {
        movement_location_t browser_loc;
        browser_loc.bit.latitude = browser_lat;
        browser_loc.bit.longitude = browser_lon;
        watch_store_backup_data(browser_loc.reg, 1);
    }
#endif

    planetary_hours_state_t *state = (planetary_hours_state_t *)context; 
    _planetary_solar_phases(settings, state);

}

bool planetary_hours_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    planetary_hours_state_t *state = (planetary_hours_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            watch_clear_indicator(WATCH_INDICATOR_PM);
            watch_clear_indicator(WATCH_INDICATOR_24H);
            _planetary_hours(settings, state);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            state->ruler = (state->ruler + 1) % 3;
            _planetary_hours(settings, state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            state->skip_to_current = true;
            _planetary_hours(settings, state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->hour++;
            _planetary_hours(settings, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            state->hour--;
            _planetary_hours(settings, state);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void planetary_hours_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

