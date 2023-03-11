/*
 * MIT License
 *
 * Copyright (c) 2023 <#author_name#>
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
#include "next_plantetary_face.h"

static void _planetary_solar_phases(movement_settings_t *settings, next_plantetary_state_t *state) {
/* A solar phase can be a day phase between sunrise and sunset or an alternating night phase.
 * This function calculates the start and end of the current phase based on a given geographic location.
 * It also calculates the start of the next following phase.
 */
    uint8_t phase;
    double sunrise, sunset;
    uint32_t now_epoch;
    uint32_t sunrise_epoch_today, sunset_epoch_today, midnight_epoch_today;
    uint32_t sunrise_epoch_yesterday, sunset_epoch_yesterday, midnight_epoch_yesterday;
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

    // go back to yesterday and calculate sunrise and sunset
    midnight_epoch_yesterday = midnight_epoch_today - 86400;
    scratch_time = watch_utility_date_time_from_unix_time(midnight_epoch_yesterday, 0);
    sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &sunrise, &sunset);
    sunrise_epoch_yesterday = midnight_epoch_yesterday + sunrise * 3600;
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

    // night time calculations
    if ( now_epoch < sunrise_epoch_today && now_epoch < sunset_epoch_today ) phase = 0; // morning before dawn
    if ( now_epoch > sunrise_epoch_today && now_epoch >= sunset_epoch_today ) phase = 2; // evening after dusk

    // phase 0: we are before sunrise
    if ( phase == 0) {
        state->phase_start = sunset_epoch_yesterday;
        state->phase_end = sunrise_epoch_today;
        state->phase_next = sunset_epoch_today;
    }

    // phase 2: we are after sunset
    if ( phase == 2) {
        state->phase_start = sunset_epoch_today;
        state->phase_end = sunrise_epoch_tomorrow;
        state->phase_next = sunset_epoch_tomorrow;
    }

}

static void _planetary_time(movement_settings_t *settings, next_plantetary_state_t *state) {
/* A planetary hour is one of exactly twelve hours of a solar phase. Its length varies.
 * This function calculates the current planetary hour and divides it up into relative minutes and seconds.
 * It also calculates the current planetary ruler of the hour and of the day.
 */
    char buf[14];
    char ruler[3];
    uint8_t night_hour_count = 0;
    uint8_t weekday, planet, planetary_hour;
    double hour_duration, second_duration, next_hour_duration, next_second_duration, current_hour;
    watch_date_time scratch_time;

    // check if we have a location. If not, display error
    if ( state->no_location ) {
        watch_display_string("    no Loc", 0);
        return;
    }

    // get current time
    watch_date_time date_time = watch_rtc_get_date_time(); // the current local date / time
    watch_date_time utc_now = watch_utility_date_time_convert_zone(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60, 0); // the current date / time in UTC

    // Planetary rulers in the Chaldean order from slowest to fastest
    // Saturn, Jupiter, Mars, Sun, Venus, Mercury, Moon
    static const char planets[7][3] = {"Sa", "Ju", "Ma", "So", "Ve", "Me", "Lu"}; // Latin
    static const char planetes[7][3] = {"Ch", "Ze", "Ar", "He", "Ap", "Hr", "Se"}; // Greek

    // Ruler of each weekday for easy lookup
    static const uint8_t plindex[7] = {3, 0, 4, 1, 5, 2, 6}; // day ruler index

    watch_set_colon();

    if (settings->bit.clock_mode_24h) watch_set_indicator(WATCH_INDICATOR_24H);

    // PM for night hours, otherwise the night hours are counted from 13
    if ( state->night ) {
        if (settings->bit.clock_mode_24h) night_hour_count = 12;
        else watch_set_indicator(WATCH_INDICATOR_PM);
    }

    // calculate the duration of a planetary hour during this solar phase
    hour_duration = ( state->phase_end - state->phase_start ) / 12.0;
    next_hour_duration = ( state->phase_next - state->phase_end ) / 12.0;
    second_duration = hour_duration / 43200;
    next_second_duration = next_hour_duration / 43200;

    // which planetary hour are we in?
    current_hour = ( watch_utility_date_time_to_unix_time(utc_now, 0) - state->phase_start ) / hour_duration - 1;
    planetary_hour = current_hour + ( state->night ? 13 : 0 );
    current_hour += night_hour_count; //adjust for 24hr display

    state->hour = 0;

    

}

void next_plantetary_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(next_plantetary_state_t));
        memset(*context_ptr, 0, sizeof(next_plantetary_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void next_plantetary_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    next_plantetary_state_t *state = (next_plantetary_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
}

bool next_plantetary_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    next_plantetary_state_t *state = (next_plantetary_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // You can use the Light button for your own purposes. Note that by default, Movement will also
            // illuminate the LED in response to EVENT_LIGHT_BUTTON_DOWN; to suppress that behavior, add an
            // empty case for EVENT_LIGHT_BUTTON_DOWN.
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Just in case you have need for another button.
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
            // Movement's default loop handler will step in for any cases you don't handle above:
            // * EVENT_LIGHT_BUTTON_DOWN lights the LED
            // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
            // * EVENT_MODE_LONG_PRESS returns to the first watch face (or skips to the secondary watch face, if configured)
            // You can override any of these behaviors by adding a case for these events to this switch statement.
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void next_plantetary_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

