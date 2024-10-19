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
 *
 * Sunrise/sunset calculations are public domain code by Paul Schlyter, December 1992
 *
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sunrise_sunset_alt_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "sunriset.h"

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

static const uint8_t _location_count = sizeof(alt_longLatPresets) / sizeof(alt_long_lat_presets_t);

static int compare(const void *a, const void *b) {
    SolarEvent *eventA = (SolarEvent *)a;
    SolarEvent *eventB = (SolarEvent *)b;

    return (eventA->timestamp - eventB->timestamp);
}

static void set_sunriset(double time_value, watch_date_time *time_unit) {
    // Calculate minutes and seconds
    float minutes = 60.0 * fmod(time_value, 1);
    float seconds = 60.0 * fmod(minutes, 1);

    // Set hour and minute
    time_unit->unit.hour = floor(time_value);
    if (seconds < 30) {
        time_unit->unit.minute = floor(minutes);
    } else {
        time_unit->unit.minute = ceil(minutes);
    }

    // Handle edge case where minutes equal 60
    if (time_unit->unit.minute == 60) {
        time_unit->unit.minute = 0;
        time_unit->unit.hour = (time_unit->unit.hour + 1) % 24;
    }
}

static void check_and_update_sunriset(double event_type, watch_date_time *event_time, watch_date_time utc_now, watch_date_time date_time) {
    set_sunriset(event_type, event_time);
    if (date_time.reg > event_time->reg) {
        // It's after the specific solar event. We need to display the event time for tomorrow.
        uint32_t timestamp = watch_utility_date_time_to_unix_time(utc_now, 0);
        timestamp += 86400;  // Advance by 24 hours
        *event_time = watch_utility_date_time_from_unix_time(timestamp, 0);
        set_sunriset(event_type, event_time);  // Update for the next day
    }
}

static void display_time(watch_date_time *time, const char *prefix, movement_settings_t *settings, watch_date_time *date_time, sunrise_sunset_alt_state_t *state) {
    bool set_leading_zero = false;
    char buf[14];

    // Handle 12-hour mode and PM indicator
    if (!settings->bit.clock_mode_24h) {
        if (watch_utility_convert_to_12_hour(time)) {
            watch_set_indicator(WATCH_INDICATOR_PM);
        } else {
            watch_clear_indicator(WATCH_INDICATOR_PM);
        }
    }
    // Handle 24-hour mode with leading zero
    else if (settings->bit.clock_24h_leading_zero && time->unit.hour < 10) {
        set_leading_zero = true;
    }

    // Format and display time
    sprintf(buf, "%s%2d%2d%02d%s", prefix, time->unit.day, time->unit.hour, time->unit.minute, alt_longLatPresets[state->longLatToUse].name);
    watch_display_string(buf, 0);

    // Display leading zero if needed
    if (set_leading_zero) {
        watch_display_string("0", 4);
    }
}

static void sunrise_sunset_alt_face_update(movement_settings_t *settings, sunrise_sunset_alt_state_t *state) {
    double naut_start, civ_start, rise, set, civ_end, naut_end;
    movement_location_t movement_location;
    if (state->longLatToUse == 0 || _location_count <= 1)
        movement_location = (movement_location_t) watch_get_backup_data(1);
    else{
        movement_location.bit.latitude = alt_longLatPresets[state->longLatToUse].latitude;
        movement_location.bit.longitude = alt_longLatPresets[state->longLatToUse].longitude;
    }

    if (movement_location.reg == 0) {
        watch_clear_colon();
        watch_clear_indicator(WATCH_INDICATOR_PM);
        watch_display_string("RI  no Loc", 0);
        return;
    }

    watch_date_time date_time = watch_rtc_get_date_time(); // the current local date / time
    watch_date_time utc_now = watch_utility_date_time_convert_zone(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60, 0); // the current date / time in UTC

    watch_date_time scratch_time; // scratchpad, contains different values at different times
    watch_date_time naut_start_time;
    watch_date_time civ_start_time;
    watch_date_time rise_time;
    watch_date_time set_time;
    watch_date_time civ_end_time;
    watch_date_time naut_end_time;

    scratch_time.reg = utc_now.reg;
    naut_start_time.reg = utc_now.reg;
    civ_start_time.reg = utc_now.reg;
    rise_time.reg = utc_now.reg;
    set_time.reg = utc_now.reg;
    civ_end_time.reg = utc_now.reg;
    naut_end_time.reg = utc_now.reg;

    // Weird quirky unsigned things were happening when I tried to cast these directly to doubles below.
    // it looks redundant, but extracting them to local int16's seemed to fix it.
    int16_t lat_centi = (int16_t)movement_location.bit.latitude;
    int16_t lon_centi = (int16_t)movement_location.bit.longitude;

    double lat = (double)lat_centi / 100.0;
    double lon = (double)lon_centi / 100.0;

    // sunriset returns the rise/set times as signed decimal hours in UTC.
    // this can mean hours below 0 or above 31, which won't fit into a watch_date_time struct.
    // to deal with this, we set aside the offset in hours, and add it back before converting it to a watch_date_time.
    double hours_from_utc = ((double)movement_timezone_offsets[settings->bit.time_zone]) / 60.0;

    sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &rise, &set);
    civil_twilight(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &civ_start, &civ_end);
    nautical_twilight(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &naut_start, &naut_end);

    watch_set_colon();
    if (settings->bit.clock_mode_24h && !settings->bit.clock_24h_leading_zero) watch_set_indicator(WATCH_INDICATOR_24H);

    naut_start += hours_from_utc;
    civ_start += hours_from_utc;
    rise += hours_from_utc;
    set += hours_from_utc;
    civ_end += hours_from_utc;
    naut_end += hours_from_utc;

    check_and_update_sunriset(naut_start, &naut_start_time, utc_now, date_time);
    check_and_update_sunriset(civ_start, &civ_start_time, utc_now, date_time);
    check_and_update_sunriset(rise, &rise_time, utc_now, date_time);
    check_and_update_sunriset(set, &set_time, utc_now, date_time);
    check_and_update_sunriset(civ_end, &civ_end_time, utc_now, date_time);
    check_and_update_sunriset(naut_end, &naut_end_time, utc_now, date_time);

     SolarEvent events[] = {
        {naut_start_time.reg, &naut_start_time, "naut_start_time", "nt"},
        {civ_start_time.reg, &civ_start_time, "civ_start_time", "cI"},
        {rise_time.reg, &rise_time, "rise_time", "rI"},
        {set_time.reg, &set_time, "set_time", "SE"},
        {civ_end_time.reg, &civ_end_time, "civ_end_time", "cI"},
        {naut_end_time.reg, &naut_end_time, "naut_end_time", "nt"}
    };

    int n = sizeof(events) / sizeof(events[0]);

    // Sort the array of events
    qsort(events, n, sizeof(SolarEvent), compare);

    switch (state->rise_index) {
        case 0:
            display_time(events[0].event, events[0].abreviation, settings, &date_time, state);
            break;
        case 1:
            display_time(events[1].event, events[1].abreviation, settings, &date_time, state);
            break;
        case 2:
            display_time(events[2].event, events[2].abreviation, settings, &date_time, state);
            break;
        case 3:
            display_time(events[3].event, events[3].abreviation, settings, &date_time, state);
            break;
        case 4:
            display_time(events[4].event, events[4].abreviation, settings, &date_time, state);
            break;
        case 5:
            display_time(events[5].event, events[5].abreviation, settings, &date_time, state);
            break;
        default:
            break;
    }

}

static int16_t sunrise_sunset_alt_face_latlon_from_struct(sunrise_sunset_alt_lat_lon_settings_t val) {
    int16_t retval = (val.sign ? -1 : 1) *
                        (
                            val.hundreds * 10000 +
                            val.tens * 1000 +
                            val.ones * 100 +
                            val.tenths * 10 +
                            val.hundredths
                        );
    return retval;
}

static sunrise_sunset_alt_lat_lon_settings_t sunrise_sunset_alt_face_struct_from_latlon(int16_t val) {
    sunrise_sunset_alt_lat_lon_settings_t retval;

    retval.sign = val < 0;
    val = abs(val);
    retval.hundredths = val % 10;
    val /= 10;
    retval.tenths = val % 10;
    val /= 10;
    retval.ones = val % 10;
    val /= 10;
    retval.tens = val % 10;
    val /= 10;
    retval.hundreds = val % 10;

    return retval;
}

static void sunrise_sunset_alt_face_update_location_register(sunrise_sunset_alt_state_t *state) {
    if (state->location_changed) {
        movement_location_t movement_location;
        int16_t lat = sunrise_sunset_alt_face_latlon_from_struct(state->working_latitude);
        int16_t lon = sunrise_sunset_alt_face_latlon_from_struct(state->working_longitude);
        movement_location.bit.latitude = lat;
        movement_location.bit.longitude = lon;
        watch_store_backup_data(movement_location.reg, 1);
        state->location_changed = false;
    }
}

static void sunrise_sunset_alt_face_update_settings_display(movement_event_t event, sunrise_sunset_alt_state_t *state) {
    char buf[12];

    switch (state->page) {
        case 0:
            return;
        case 1:
            sprintf(buf, "LA  %c %04d", state->working_latitude.sign ? '-' : '+', abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_latitude)));
            break;
        case 2:
            sprintf(buf, "LO  %c%05d", state->working_longitude.sign ? '-' : '+', abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_longitude)));
            break;
    }
    if (event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
}

static void sunrise_sunset_alt_face_advance_digit(sunrise_sunset_alt_state_t *state) {
    state->location_changed = true;
    switch (state->page) {
        case 1: // latitude
            switch (state->active_digit) {
                case 0:
                    state->working_latitude.sign++;
                    break;
                case 1:
                    // we skip this digit
                    break;
                case 2:
                    state->working_latitude.tens = (state->working_latitude.tens + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_latitude)) > 9000) {
                        // prevent latitude from going over ±90.
                        // TODO: perform these checks when advancing the digit?
                        state->working_latitude.ones = 0;
                        state->working_latitude.tenths = 0;
                        state->working_latitude.hundredths = 0;
                    }
                    break;
                case 3:
                    state->working_latitude.ones = (state->working_latitude.ones + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_latitude)) > 9000) state->working_latitude.ones = 0;
                    break;
                case 4:
                    state->working_latitude.tenths = (state->working_latitude.tenths + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_latitude)) > 9000) state->working_latitude.tenths = 0;
                    break;
                case 5:
                    state->working_latitude.hundredths = (state->working_latitude.hundredths + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_latitude)) > 9000) state->working_latitude.hundredths = 0;
                    break;
            }
            break;
        case 2: // longitude
            switch (state->active_digit) {
                case 0:
                    state->working_longitude.sign++;
                    break;
                case 1:
                    state->working_longitude.hundreds = (state->working_longitude.hundreds + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_longitude)) > 18000) {
                        // prevent longitude from going over ±180
                        state->working_longitude.tens = 8;
                        state->working_longitude.ones = 0;
                        state->working_longitude.tenths = 0;
                        state->working_longitude.hundredths = 0;
                    }
                    break;
                case 2:
                    state->working_longitude.tens = (state->working_longitude.tens + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_longitude)) > 18000) state->working_longitude.tens = 0;
                    break;
                case 3:
                    state->working_longitude.ones = (state->working_longitude.ones + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_longitude)) > 18000) state->working_longitude.ones = 0;
                    break;
                case 4:
                    state->working_longitude.tenths = (state->working_longitude.tenths + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_longitude)) > 18000) state->working_longitude.tenths = 0;
                    break;
                case 5:
                    state->working_longitude.hundredths = (state->working_longitude.hundredths + 1) % 10;
                    if (abs(sunrise_sunset_alt_face_latlon_from_struct(state->working_longitude)) > 18000) state->working_longitude.hundredths = 0;
                    break;
            }
            break;
    }
}

void sunrise_sunset_alt_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(sunrise_sunset_alt_state_t));
        memset(*context_ptr, 0, sizeof(sunrise_sunset_alt_state_t));
    }
}

void sunrise_sunset_alt_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    if (watch_tick_animation_is_running()) watch_stop_tick_animation();

#if __EMSCRIPTEN__
    int16_t browser_lat = EM_ASM_INT({
        return lat;
    });
    int16_t browser_lon = EM_ASM_INT({
        return lon;
    });
    if ((watch_get_backup_data(1) == 0) && (browser_lat || browser_lon)) {
        movement_location_t browser_loc;
        browser_loc.bit.latitude = browser_lat;
        browser_loc.bit.longitude = browser_lon;
        watch_store_backup_data(browser_loc.reg, 1);
    }
#endif


    sunrise_sunset_alt_state_t *state = (sunrise_sunset_alt_state_t *)context;
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    state->working_latitude = sunrise_sunset_alt_face_struct_from_latlon(movement_location.bit.latitude);
    state->working_longitude = sunrise_sunset_alt_face_struct_from_latlon(movement_location.bit.longitude);
}

bool sunrise_sunset_alt_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    sunrise_sunset_alt_state_t *state = (sunrise_sunset_alt_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            sunrise_sunset_alt_face_update(settings, state);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
        case EVENT_TICK:
            if (state->page == 0) {
                // if entering low energy mode, start tick animation
                if (event.event_type == EVENT_LOW_ENERGY_UPDATE && !watch_tick_animation_is_running()) watch_start_tick_animation(1000);
                } else {
                sunrise_sunset_alt_face_update_settings_display(event, state);
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if (state->page) {
                state->active_digit++;
                if (state->page == 1 && state->active_digit == 1) state->active_digit++; // max latitude is +- 90, no hundreds place
                if (state->active_digit > 5) {
                    state->active_digit = 0;
                    state->page = (state->page + 1) % 3;
                    sunrise_sunset_alt_face_update_location_register(state);
                }
                sunrise_sunset_alt_face_update_settings_display(event, context);
            } else if (_location_count <= 1) {
                movement_illuminate_led();
            }
            if (state->page == 0) {
                movement_request_tick_frequency(1);
                sunrise_sunset_alt_face_update(settings, state);
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (_location_count <= 1) break;
            else if (!state->page) movement_illuminate_led();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (state->page == 0 && _location_count > 1) {
                state->longLatToUse = (state->longLatToUse + 1) % _location_count;
                sunrise_sunset_alt_face_update(settings, state);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (state->page) {
                sunrise_sunset_alt_face_advance_digit(state);
                sunrise_sunset_alt_face_update_settings_display(event, context);
            } else {
                state->rise_index = (state->rise_index + 1) % 6;
                printf("state->rise_index = %d\n", state->rise_index);
                sunrise_sunset_alt_face_update(settings, state);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->page == 0) {
            if (state->longLatToUse != 0) {
                state->longLatToUse = 0;
                sunrise_sunset_alt_face_update(settings, state);
                break;
            }
                state->page++;
                state->active_digit = 0;
                watch_clear_display();
                movement_request_tick_frequency(4);
                sunrise_sunset_alt_face_update_settings_display(event, context);
            }
            else {
                state->active_digit = 0;
                state->page = 0;
                sunrise_sunset_alt_face_update_location_register(state);
                sunrise_sunset_alt_face_update(settings, state);
            }
            break;
        case EVENT_TIMEOUT:
            if (watch_get_backup_data(1) == 0) {
                // if no location set, return home
                movement_move_to_face(0);
            } else if (state->page || state->rise_index) {
                // otherwise on timeout, exit settings mode and return to the next sunrise or sunset
                state->page = 0;
                state->rise_index = 0;
                movement_request_tick_frequency(1);
                sunrise_sunset_alt_face_update(settings, state);
            }
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void sunrise_sunset_alt_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    sunrise_sunset_alt_state_t *state = (sunrise_sunset_alt_state_t *)context;
    state->page = 0;
    state->active_digit = 0;
    state->rise_index = 0;
    sunrise_sunset_alt_face_update_location_register(state);
}
