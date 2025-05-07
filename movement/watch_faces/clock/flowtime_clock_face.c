/*
 * MIT License
 *
 * Copyright © 2023-2025 Lionel Ringenbach <ucodia@live.com>
 * Copyright © 2021-2023 Joey Castillo <joeycastillo@utexas.edu> <jose.castillo@gmail.com>
 * Copyright © 2022 David Keck <davidskeck@users.noreply.github.com>
 * Copyright © 2022 TheOnePerson <a.nebinger@web.de>
 * Copyright © 2023 Jeremy O'Brien <neutral@fastmail.com>
 * Copyright © 2023 Mikhail Svarichevsky <3@14.by>
 * Copyright © 2023 Wesley Aptekar-Cassels <me@wesleyac.com>
 * Copyright © 2024 Matheus Afonso Martins Moreira <matheus.a.m.moreira@gmail.com>
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
#include "flowtime_clock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"
#include "flowtime.h"

typedef struct {
    struct {
        watch_date_time previous;
    } date_time;
    uint8_t watch_face_index;
    bool reality_check_enabled;
} clock_state_t;

static bool clock_is_in_24h_mode(movement_settings_t *settings) {
#ifdef CLOCK_FACE_24H_ONLY
    return true;
#else
    return settings->bit.clock_mode_24h;
#endif
}

static bool clock_should_set_leading_zero(movement_settings_t *settings) {
    return clock_is_in_24h_mode(settings) && settings->bit.clock_24h_leading_zero;
}

static void clock_indicate(WatchIndicatorSegment indicator, bool on) {
    if (on) {
        watch_set_indicator(indicator);
    } else {
        watch_clear_indicator(indicator);
    }
}

static void clock_indicate_alarm(movement_settings_t *settings) {
    clock_indicate(WATCH_INDICATOR_SIGNAL, settings->bit.alarm_enabled);
}

static void clock_indicate_24h(movement_settings_t *settings) {
    clock_indicate(WATCH_INDICATOR_24H, clock_is_in_24h_mode(settings));
}

static bool clock_is_pm(watch_date_time date_time) {
    return date_time.unit.hour >= 12;
}

static void clock_indicate_pm(movement_settings_t *settings, watch_date_time date_time) {
    if (settings->bit.clock_mode_24h) { return; }
    clock_indicate(WATCH_INDICATOR_PM, clock_is_pm(date_time));
}

static watch_date_time clock_24h_to_12h(watch_date_time date_time) {
    date_time.unit.hour %= 12;

    if (date_time.unit.hour == 0) {
        date_time.unit.hour = 12;
    }

    return date_time;
}

static void clock_display_all(watch_date_time date_time, bool leading_zero) {
    char buf[10 + 1];

    snprintf(
        buf,
        sizeof(buf),
        leading_zero? "%s%02d%02d%02d%02d" : "%s%2d%2d%02d%02d",
        watch_utility_get_weekday(date_time),
        date_time.unit.day,
        date_time.unit.hour,
        date_time.unit.minute,
        date_time.unit.second
    );

    watch_display_string(buf, 0);
}

static bool clock_display_some(watch_date_time current, watch_date_time previous) {
    if ((current.reg >> 6) == (previous.reg >> 6)) {
        // everything before seconds is the same, don't waste cycles setting those segments.

        watch_display_character_lp_seconds('0' + current.unit.second / 10, 8);
        watch_display_character_lp_seconds('0' + current.unit.second % 10, 9);

        return true;

    } else if ((current.reg >> 12) == (previous.reg >> 12)) {
        // everything before minutes is the same.

        char buf[4 + 1];

        snprintf(
            buf,
            sizeof(buf),
            "%02d%02d",
            current.unit.minute,
            current.unit.second
        );

        watch_display_string(buf, 6);

        return true;

    } else {
        // other stuff changed; let's do it all.
        return false;
    }
}

static void clock_display_clock(movement_settings_t *settings, clock_state_t *clock, watch_date_time current) {
    if (!clock_display_some(current, clock->date_time.previous)) {
        if (!clock_is_in_24h_mode(settings)) {
            // if we are in 12 hour mode, do some cleanup.
            clock_indicate_pm(settings, current);
            current = clock_24h_to_12h(current);
        }
        clock_display_all(current, clock_should_set_leading_zero(settings));
    }
}

static void clock_display_low_energy(watch_date_time date_time) {
    char buf[10 + 1];

    snprintf(
        buf,
        sizeof(buf),
        "%s%2d%2d%02d  ",
        watch_utility_get_weekday(date_time),
        date_time.unit.day,
        date_time.unit.hour,
        date_time.unit.minute
    );

    watch_display_string(buf, 0);
}

static void clock_start_tick_tock_animation(void) {
    if (!watch_tick_animation_is_running()) {
        watch_start_tick_animation(500);
    }
}

static void clock_stop_tick_tock_animation(void) {
    if (watch_tick_animation_is_running()) {
        watch_stop_tick_animation();
    }
}

void flowtime_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(clock_state_t));
        clock_state_t *state = (clock_state_t *) *context_ptr;
        state->reality_check_enabled = false;
        state->watch_face_index = watch_face_index;
    }
}

void flowtime_clock_face_activate(movement_settings_t *settings, void *context) {
    clock_state_t *clock = (clock_state_t *) context;

    clock_stop_tick_tock_animation();

    clock_indicate_alarm(settings);
    clock_indicate_24h(settings);

    watch_set_colon();

    // this ensures that none of the timestamp fields will match, so we can re-render them all.
    clock->date_time.previous.reg = 0xFFFFFFFF;
}

bool flowtime_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    clock_state_t *state = (clock_state_t *) context;
    watch_date_time current;
    watch_date_time display;

    switch (event.event_type) {
        case EVENT_LOW_ENERGY_UPDATE:
            clock_start_tick_tock_animation();
            current = watch_rtc_get_date_time();
            display = date_to_flowtime(&current);
            clock_display_low_energy(display);
            break;
        case EVENT_TICK:
        case EVENT_ACTIVATE:
            current = watch_rtc_get_date_time();
            display = state->reality_check_enabled ? current : date_to_flowtime(&current);
            clock_display_clock(settings, state, display);
            state->date_time.previous = display;
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            state->reality_check_enabled = true;
            watch_set_led_red();
            current = watch_rtc_get_date_time();
            clock_display_clock(settings, state, current);
            state->date_time.previous = current;
            break;
        case EVENT_ALARM_LONG_UP:
        case EVENT_ALARM_BUTTON_UP:
            state->reality_check_enabled = false;
            watch_set_led_off();
            current = watch_rtc_get_date_time();
            display = date_to_flowtime(&current);
            clock_display_clock(settings, state, display);    
            state->date_time.previous = display;
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void flowtime_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
