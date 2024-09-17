/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Aptekar-Cassels
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
#include "solstice_face.h"

// Find solstice or equinox time in JDE for a given year, via method from Meeus Ch 27
static double calculate_solstice_equinox(uint16_t year, uint8_t k) {
    double Y = ((double)year - 2000) / 1000;
    double approx_terms[4][5] = {
        {2451623.80984, 365242.37404, 0.05169, -0.00411, -0.00057}, // March equinox
        {2451716.56767, 365241.62603, 0.00325, 0.00888, -0.00030}, // June solstice
        {2451810.21715, 365242.01767, -0.11575, 0.00337, 0.00078}, // September equinox
        {2451900.05952, 365242.74049, -0.06223, -0.00823, 0.00032}, // December solstice
    };
    double JDE0 = approx_terms[k][0] + Y * (approx_terms[k][1] + Y * (approx_terms[k][2] + Y * (approx_terms[k][3] + Y * approx_terms[k][4])));
    double T = (JDE0 - 2451545.0) / 36525;
    double W = 35999.373 * T - 2.47;
    double dlambda = 1 + (0.0334 * cos(W * M_PI / 180.0)) + (0.0007 * cos(2 * W * M_PI / 180.0));
    double correction_terms[25][3] = {
        {485,324.96,1934.136},
        {203,337.23,32964.467},
        {199,342.08,20.186},
        {182,27.85,445267.112},
        {156,73.14,45036.886},
        {136,171.52,22518.443},
        {77,222.54,65928.934},
        {74,296.72,3034.906},
        {70,243.58,9037.513},
        {58,119.81,33718.147},
        {52,297.17,150.678},
        {50,21.02,2281.226},
        {45,247.54,29929.562},
        {44,325.15,31555.956},
        {29,60.93,4443.417},
        {18,155.12,67555.328},
        {17,288.79,4562.452},
        {16,198.04,62894.029},
        {14,199.76,31436.921},
        {12,95.39,14577.848},
        {12,287.11,31931.756},
        {12,320.81,34777.259},
        {9,227.73,1222.114},
        {8,15.45,16859.074},
    };
    double S = 0;
    for (int i = 0; i < 25; i++) {
        S += correction_terms[i][0] * cos((correction_terms[i][1] + correction_terms[i][2] * T) * M_PI / 180.0);
    }
    double JDE = JDE0 + (0.00001 * S) / dlambda;

    return JDE;
}

// Convert JDE to Gergorian datetime as per Meeus Ch 7
static watch_date_time jde_to_date_time(double JDE) {
    double tmp = JDE + 0.5;
    double Z = floor(tmp);
    double F = fmod(tmp, 1);
    double A;
    if (Z < 2299161) {
        A = Z;
    } else {
        double alpha = floor((Z - 1867216.25) / 36524.25);
        A = Z + 1 + alpha - floor(alpha / 4);
    }
    double B = A + 1524;
    double C = floor((B - 122.1) / 365.25);
    double D = floor(365.25 * C);
    double E = floor((B - D) / 30.6001);
    double day = B - D - floor(30.6001 * E) + F;
    double month;
    if (E < 14) {
        month = E - 1;
    } else {
        month = E - 13;
    }
    double year;
    if (month > 2) {
        year = C - 4716;
    } else {
        year = C - 4715;
    }

    double hours = fmod(day, 1) * 24;
    double minutes = fmod(hours, 1) * 60;
    double seconds = fmod(minutes, 1) * 60;

    watch_date_time result = {.unit = {
        floor(seconds),
        floor(minutes),
        floor(hours),
        floor(day),
        floor(month),
        floor(year - 2020)
    }};

    return result;
}

static void calculate_datetimes(solstice_state_t *state, movement_settings_t *settings) {
    for (int i = 0; i < 4; i++) {
        // TODO: handle DST changes
        state->datetimes[i] = jde_to_date_time(calculate_solstice_equinox(2020 + state->year, i) + (movement_timezone_offsets[settings->bit.time_zone] / (60.0*24.0)));
    }
}

void solstice_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(solstice_state_t));
        solstice_state_t *state = (solstice_state_t *)*context_ptr;

        watch_date_time now = watch_rtc_get_date_time();
        state->year = now.unit.year;
        state->index = 0;
        calculate_datetimes(state, settings);

        uint32_t now_unix = watch_utility_date_time_to_unix_time(now, 0);
        for (int i = 0; i < 4; i++) {
            if (state->index == 0 && watch_utility_date_time_to_unix_time(state->datetimes[i], 0) > now_unix) {
                state->index = i;
            }
        }
    }
}

void solstice_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

static void show_main_screen(solstice_state_t *state) {
    char buf[11];
    watch_date_time date_time = state->datetimes[state->index];
    sprintf(buf, "  %2d  %2d%02d", date_time.unit.year + 20, date_time.unit.month, date_time.unit.day);
    watch_display_string(buf, 0);
}

static void show_date_time(movement_settings_t *settings, solstice_state_t *state) {
    char buf[11];
    watch_date_time date_time = state->datetimes[state->index];
    if (!settings->bit.clock_mode_24h) {
        if (date_time.unit.hour < 12) {
            watch_clear_indicator(WATCH_INDICATOR_PM);
        } else {
            watch_set_indicator(WATCH_INDICATOR_PM);
        }
        date_time.unit.hour %= 12;
        if (date_time.unit.hour == 0) date_time.unit.hour = 12;
    }
    sprintf(buf, "%s%2d%2d%02d%02d", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
    watch_set_colon();
    watch_display_string(buf, 0);
}

bool solstice_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    solstice_state_t *state = (solstice_state_t *)context;

    switch (event.event_type) {
        case EVENT_ALARM_LONG_PRESS:
            show_date_time(settings, state);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (state->index == 0) {
                if (state->year == 0) {
                    break;
                }
                state->year--;
                state->index = 3;
                calculate_datetimes(state, settings);
            } else {
                state->index--;
            }
            show_main_screen(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->index++;
            if (state->index > 3) {
                if (state->year == 83) {
                    break;
                }
                state->year++;
                state->index = 0;
                calculate_datetimes(state, settings);
            }
            show_main_screen(state);
            break;
        case EVENT_ALARM_LONG_UP:
            watch_clear_colon();
            watch_clear_indicator(WATCH_INDICATOR_PM);
            show_main_screen(state);
            break;
        case EVENT_ACTIVATE:
            show_main_screen(state);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void solstice_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

