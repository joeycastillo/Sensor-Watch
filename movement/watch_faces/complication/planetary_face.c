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
#include <math.h>
#include "sunrise_sunset_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "sunriset.h"
#include "planetary_face.h"

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

static sunrise_sunset_lat_lon_settings_t _sunrise_sunset_face_struct_from_latlon(int16_t val) {
    sunrise_sunset_lat_lon_settings_t retval;

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

static void _planetary_face_sun_calculations(movement_settings_t *settings, planetary_state_t *state) {

    double yesterday_rise, yesterday_set, today_rise, today_set, tomorrow_rise, tomorrow_set;
    uint32_t epoch;
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);

    if (movement_location.reg == 0) {
        watch_display_string("PL  no Loc", 0);
        return;
    }

    watch_date_time date_time = watch_rtc_get_date_time(); // the current local date / time
    watch_date_time utc_now = watch_utility_date_time_convert_zone(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60, 0); // the current date / time in UTC
    watch_date_time scratch_time; // scratchpad, contains different values at different times
    watch_date_time day0;
    scratch_time.reg = utc_now.reg;
    day0.reg = utc_now.reg;

    int16_t lat_centi = (int16_t)movement_location.bit.latitude;
    int16_t lon_centi = (int16_t)movement_location.bit.longitude;

    double lat = (double)lat_centi / 100.0;
    double lon = (double)lon_centi / 100.0;

    // sunriset returns the rise/set times as signed decimal hours in UTC.
    // this can mean hours below 0 or above 31, which won't fit into a watch_date_time struct.
    // to deal with this, we set aside the offset in hours, and add it back before converting it to a watch_date_time.
    double hours_from_utc = ((double)movement_timezone_offsets[settings->bit.time_zone]) / 60.0;

    // calculate next sunrise and set
    epoch = watch_utility_date_time_to_unix_time(day0, 0);
    sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &today_rise, &today_set);

    today_rise = epoch + ( today_rise + hours_from_utc ) * 3600;
    today_set = epoch + ( today_set + hours_from_utc ) * 3600;

    // calculate last sunrise and set
    epoch -= 86400;
    scratch_time = watch_utility_date_time_from_unix_time(epoch, 0);
    sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &yesterday_rise, &yesterday_set);
    
    yesterday_rise = epoch + ( yesterday_rise + hours_from_utc ) * 3600;
    yesterday_set = epoch + ( yesterday_set + hours_from_utc ) * 3600;

    // calculate next sunrise and set after tomorrow
    epoch = watch_utility_date_time_to_unix_time(day0, 0) + 86400;
    scratch_time = watch_utility_date_time_from_unix_time(epoch, 0);
    sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &tomorrow_rise, &tomorrow_set);
    
    tomorrow_rise = epoch + ( tomorrow_rise + hours_from_utc ) * 3600;
    tomorrow_set = epoch + ( tomorrow_set + hours_from_utc ) * 3600;

    if ( today_set < today_rise ) {
        yesterday_set = today_set;
        today_set = tomorrow_set;
    }

    state->yesterday_set = yesterday_set;
    state->today_rise = today_rise;
    state->today_set = today_set;
    state->tomorrow_rise = tomorrow_rise;

    state->yesterday_night_second_length = today_rise - yesterday_set;
    state->today_day_second_length = today_set - today_rise;
    state->today_night_second_length = tomorrow_rise - today_set;

    printf("Yesterday: [%f, %f]\nToday: [%f, %f]\nTomorrow: [%f, %f]\n", 
        yesterday_rise, yesterday_set, today_rise, today_set, tomorrow_rise, tomorrow_set);

    printf("Yesterday Night: [%u]\nToday Day: [%u]\nToday Night: [%u]\n", 
        state->yesterday_night_second_length, state->today_day_second_length, state->today_night_second_length);
}

void planetary_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(planetary_state_t));
        memset(*context_ptr, 0, sizeof(planetary_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void planetary_face_activate(movement_settings_t *settings, void *context) {
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

    planetary_state_t *state = (planetary_state_t *)context;
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    state->sunstate.working_latitude = _sunrise_sunset_face_struct_from_latlon(movement_location.bit.latitude);
    state->sunstate.working_longitude = _sunrise_sunset_face_struct_from_latlon(movement_location.bit.longitude);
    _planetary_face_sun_calculations(settings, state);
}

bool planetary_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    planetary_state_t *state = (planetary_state_t *)context;

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

void planetary_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

