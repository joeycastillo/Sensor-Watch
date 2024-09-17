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
#include <string.h>
#include <math.h>
#include "watch_utility.h"
#include "mars_time_face.h"

// note: lander coordinates come from Mars24's `marslandmarks.xml` file
static double site_longitudes[MARS_TIME_NUM_SITES] = {
    0,                      // Mars Coordinated Time, at the meridian
    360.0 - 109.9,          // Zhurong lander site
    360.0 - 77.45088572,    // Perseverance lander site
    360.0 - 135.623447,     // InSight lander site
    360.0 - 137.441635,     // Curiosity lander site
};

static char site_names[MARS_TIME_NUM_SITES][3] = {
    "MC",
    "ZH",
    "PE",
    "IN",
    "CU",
};

static uint16_t landing_sols[MARS_TIME_NUM_SITES] = {
    0,
    52387,
    52304,
    51511,
    49269,
};

typedef struct {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} mars_clock_hms_t;

static void _h_to_hms(mars_clock_hms_t *date_time, double h) {
	unsigned int seconds = (unsigned int)(h * 3600.0);
	date_time->hour = seconds / 3600;
	seconds = seconds % 3600;
	date_time->minute = floor(seconds / 60);
	date_time->second = round(seconds % 60);
}

static void _update(movement_settings_t *settings, mars_time_state_t *state) {
    char buf[11];
    watch_date_time date_time = watch_rtc_get_date_time();
    uint32_t now = watch_utility_date_time_to_unix_time(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60);
    // TODO: I'm skipping over some steps here.
    // https://www.giss.nasa.gov/tools/mars24/help/algorithm.html
    double jdut = 2440587.5 + ((double)now / 86400.0);
    double jdtt = jdut + ((37.0 + 32.184) / 86400.0);
    double jd2k = jdtt - 2451545.0;
    double msd = ((jd2k - 4.5) / 1.0274912517) + 44796.0 - 0.0009626;
    double mtc = fmod(24 * msd, 24);
    double lmt;

    if (state->current_site == 0) {
        lmt = mtc;
    } else {
        double longitude = site_longitudes[state->current_site];
        double lmst = mtc - ((longitude * 24.0) / 360.0);
        lmt = fmod(lmst + 24, 24);
    }

    if (state->displaying_sol) {
        // TODO: this is not right, mission sol should turn over at midnight local time?
        uint16_t sol = floor(msd) - landing_sols[state->current_site];
        if (sol < 1000) sprintf(&buf[0], "%s  Sol%3d", site_names[state->current_site], sol);
        else sprintf(&buf[0], "%s $%6d", site_names[state->current_site], sol);
        watch_clear_colon();
        watch_clear_indicator(WATCH_INDICATOR_24H);
    } else {
        mars_clock_hms_t mars_time;
        _h_to_hms(&mars_time, lmt);
        sprintf(&buf[0], "%s  %02d%02d%02d", site_names[state->current_site], mars_time.hour, mars_time.minute, mars_time.second);
        watch_set_colon();
        watch_set_indicator(WATCH_INDICATOR_24H);
    }

    watch_display_string(buf, 0);
}

void mars_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(mars_time_state_t));
        memset(*context_ptr, 0, sizeof(mars_time_state_t));
    }
}

void mars_time_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    mars_time_state_t *state = (mars_time_state_t *)context;
    (void) state;
}

bool mars_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    mars_time_state_t *state = (mars_time_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            _update(settings, state);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            state->displaying_sol = !state->displaying_sol;
            _update(settings, state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->current_site = (state->current_site + 1) % MARS_TIME_NUM_SITES;
            _update(settings, state);
            break;
        case EVENT_TIMEOUT:
            // TODO: make this lower power so we can avoid timeout
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // TODO: low energy update
            // watch_start_tick_animation(500);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void mars_time_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

