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
#include "clock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"

// 2.2 volts will happen when the battery has maybe 5-10% remaining?
// we can refine this later.
#ifndef CLOCK_FACE_LOW_BATTERY_VOLTAGE_THRESHOLD
#define CLOCK_FACE_LOW_BATTERY_VOLTAGE_THRESHOLD 2200
#endif

typedef struct {
    uint32_t previous_date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    bool time_signal_enabled;
    bool battery_low;
} clock_state_t;

static void clock_indicate(WatchIndicatorSegment indicator, bool on) {
    if (on) {
        watch_set_indicator(indicator);
    } else {
        watch_clear_indicator(indicator);
    }
}

static void clock_indicate_alarm(movement_settings_t *settings) {
    clock_indicate(WATCH_INDICATOR_BELL, settings->bit.alarm_enabled);
}

static void clock_indicate_time_signal(clock_state_t *clock) {
    clock_indicate(WATCH_INDICATOR_SIGNAL, clock->time_signal_enabled);
}

static void clock_indicate_24h(movement_settings_t *settings) {
    clock_indicate(WATCH_INDICATOR_24H, settings->bit.clock_mode_24h);
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

static void clock_check_battery_periodically(clock_state_t *clock, watch_date_time date_time) {
    // check the battery voltage once a day
    if (date_time.unit.day == clock->last_battery_check) { return; }

    clock->last_battery_check = date_time.unit.day;

    watch_enable_adc();
    uint16_t voltage = watch_get_vcc_voltage();
    watch_disable_adc();

    clock->battery_low = voltage < CLOCK_FACE_LOW_BATTERY_VOLTAGE_THRESHOLD;
}

static void clock_indicate_low_available_power(clock_state_t *clock) {
    // Set the LAP indicator if battery power is low
    clock_indicate(WATCH_INDICATOR_LAP, clock->battery_low);
}

static void clock_display_low_energy(watch_date_time date_time) {
    char buf[11];

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

void clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(clock_state_t));
        clock_state_t *state = (clock_state_t *) *context_ptr;
        state->time_signal_enabled = false;
        state->watch_face_index = watch_face_index;
    }
}

void clock_face_activate(movement_settings_t *settings, void *context) {
    clock_state_t *clock = (clock_state_t *) context;

    if (watch_tick_animation_is_running()) watch_stop_tick_animation();

    clock_indicate_time_signal(clock);
    clock_indicate_alarm(settings);
    clock_indicate_24h(settings);

    watch_set_colon();

    // this ensures that none of the timestamp fields will match, so we can re-render them all.
    clock->previous_date_time = 0xFFFFFFFF;
}

bool clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    clock_state_t *state = (clock_state_t *) context;
    char buf[11];
    uint8_t pos;

    watch_date_time date_time;
    uint32_t previous_date_time;
    switch (event.event_type) {
        case EVENT_LOW_ENERGY_UPDATE:
            if (!watch_tick_animation_is_running()) watch_start_tick_animation(500);
            clock_display_low_energy(watch_rtc_get_date_time());
            break;
        case EVENT_TICK:
        case EVENT_ACTIVATE:
            date_time = watch_rtc_get_date_time();
            previous_date_time = state->previous_date_time;
            state->previous_date_time = date_time.reg;

            clock_check_battery_periodically(state, date_time);
            clock_indicate_low_available_power(state);

            if ((date_time.reg >> 6) == (previous_date_time >> 6)) {
                // everything before seconds is the same, don't waste cycles setting those segments.
                watch_display_character_lp_seconds('0' + date_time.unit.second / 10, 8);
                watch_display_character_lp_seconds('0' + date_time.unit.second % 10, 9);
                break;
            } else if ((date_time.reg >> 12) == (previous_date_time >> 12)) {
                // everything before minutes is the same.
                pos = 6;
                sprintf(buf, "%02d%02d", date_time.unit.minute, date_time.unit.second);
            } else {
                // other stuff changed; let's do it all.
                if (!settings->bit.clock_mode_24h) {
                    // if we are in 12 hour mode, do some cleanup.
                    clock_indicate_pm(settings, date_time);
                    date_time = clock_24h_to_12h(date_time);
                }
                sprintf(buf, "%s%2d%2d%02d%02d", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
            }

            watch_display_string(buf, 0);

            // handle alarm indicator
            clock_indicate_alarm(settings);

            break;
        case EVENT_ALARM_LONG_PRESS:
            state->time_signal_enabled = !state->time_signal_enabled;
            clock_indicate_time_signal(state);
            break;
        case EVENT_BACKGROUND_TASK:
            // uncomment this line to snap back to the clock face when the hour signal sounds:
            // movement_move_to_face(state->watch_face_index);
            movement_play_signal();
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool clock_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    clock_state_t *state = (clock_state_t *) context;
    if (!state->time_signal_enabled) return false;

    watch_date_time date_time = watch_rtc_get_date_time();

    return date_time.unit.minute == 0;
}
