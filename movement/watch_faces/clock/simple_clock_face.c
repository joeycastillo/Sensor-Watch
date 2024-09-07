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
#include "simple_clock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"
#include "sunriset.h"

static void _load_default_chime_times(uint8_t hourly_chime_start, uint8_t hourly_chime_end, uint8_t *start_hour, uint8_t *end_hour) {
        *start_hour = Hourly_Chime_Start[hourly_chime_start];
        *end_hour = Hourly_Chime_End[hourly_chime_end];
}

static uint8_t _time_to_chime_hour(double time, double hours_from_utc, bool use_end_of_hour) {
    time += hours_from_utc;
    uint8_t hour_to_start = (uint8_t)time;
    double minutes = (time - hour_to_start) * 60;
    if (!use_end_of_hour) return hour_to_start;
    if (minutes >= 0.5)
        hour_to_start = (hour_to_start + 1) % 24;
    return hour_to_start;
}

static void _get_chime_times(watch_date_time date_time, movement_settings_t *settings, uint8_t *start_hour, uint8_t *end_hour) {
    uint8_t hourly_chime_start = settings->bit.hourly_chime_start;
    uint8_t hourly_chime_end = settings->bit.hourly_chime_end;
    if (hourly_chime_start != 3 && hourly_chime_end != 3) {
        _load_default_chime_times(hourly_chime_start, hourly_chime_end, start_hour, end_hour);
        return;
    }
    int16_t tz = movement_timezone_offsets[settings->bit.time_zone];
    watch_date_time utc_now = watch_utility_date_time_convert_zone(date_time, tz * 60, 0); // the current date / time in UTC
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    if (movement_location.reg == 0) {
        _load_default_chime_times(hourly_chime_start, hourly_chime_end, start_hour, end_hour);
        return;
    }
    double rise, set;
    uint8_t rise_hour, set_hour;
    double lat = (double)movement_location.bit.latitude / 100.0;
    double lon = (double)movement_location.bit.longitude / 100.0;
    double hours_from_utc = ((double)tz) / 60.0;
    uint8_t result = sun_rise_set(utc_now.unit.year + WATCH_RTC_REFERENCE_YEAR, utc_now.unit.month, utc_now.unit.day, lon, lat, &rise, &set);
    if (result != 0) {
        _load_default_chime_times(hourly_chime_start, hourly_chime_end, start_hour, end_hour);
        return;
    }
    rise_hour = _time_to_chime_hour(rise, hours_from_utc, true);
    set_hour = _time_to_chime_hour(set, hours_from_utc, false);
    *start_hour = (hourly_chime_start == 3) ? rise_hour : Hourly_Chime_Start[hourly_chime_start];
    *end_hour = (hourly_chime_end == 3) ? set_hour : Hourly_Chime_End[hourly_chime_end];
}

static void _update_alarm_indicator(bool settings_alarm_enabled, simple_clock_state_t *state) {
    state->alarm_enabled = settings_alarm_enabled;
    if (state->alarm_enabled) watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    else watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

void simple_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(simple_clock_state_t));
        simple_clock_state_t *state = (simple_clock_state_t *)*context_ptr;
        state->signal_enabled = false;
        state->watch_face_index = watch_face_index;
    }
}

void simple_clock_face_activate(movement_settings_t *settings, void *context) {
    simple_clock_state_t *state = (simple_clock_state_t *)context;

    if (watch_tick_animation_is_running()) watch_stop_tick_animation();

#ifdef CLOCK_FACE_24H_ONLY
    watch_set_indicator(WATCH_INDICATOR_24H);
#else
    if (settings->bit.clock_mode_24h) watch_set_indicator(WATCH_INDICATOR_24H);
#endif

    // handle chime indicator
    if (state->signal_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
    else watch_clear_indicator(WATCH_INDICATOR_BELL);

    // show alarm indicator if there is an active alarm
    _update_alarm_indicator(settings->bit.alarm_enabled, state);

    watch_set_colon();

    // this ensures that none of the timestamp fields will match, so we can re-render them all.
    state->previous_date_time = 0xFFFFFFFF;
}

bool simple_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    simple_clock_state_t *state = (simple_clock_state_t *)context;
    char buf[11];
    uint8_t pos;

    watch_date_time date_time;
    uint32_t previous_date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:
            date_time = watch_rtc_get_date_time();
            previous_date_time = state->previous_date_time;
            state->previous_date_time = date_time.reg;

            // check the battery voltage once a day...
            if (date_time.unit.day != state->last_battery_check) {
                state->last_battery_check = date_time.unit.day;
                watch_enable_adc();
                uint16_t voltage = watch_get_vcc_voltage();
                watch_disable_adc();
                // 2.2 volts will happen when the battery has maybe 5-10% remaining?
                // we can refine this later.
                state->battery_low = (voltage < 2200);
            }

            // ...and set the LAP indicator if low.
            if (state->battery_low) watch_set_indicator(WATCH_INDICATOR_LAP);

            if ((date_time.reg >> 6) == (previous_date_time >> 6) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                // everything before seconds is the same, don't waste cycles setting those segments.
                watch_display_character_lp_seconds('0' + date_time.unit.second / 10, 8);
                watch_display_character_lp_seconds('0' + date_time.unit.second % 10, 9);
                break;
            } else if ((date_time.reg >> 12) == (previous_date_time >> 12) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                // everything before minutes is the same.
                pos = 6;
                sprintf(buf, "%02d%02d", date_time.unit.minute, date_time.unit.second);
            } else {
                // other stuff changed; let's do it all.
#ifndef CLOCK_FACE_24H_ONLY
                if (!settings->bit.clock_mode_24h) {
                    // if we are in 12 hour mode, do some cleanup.
                    if (date_time.unit.hour < 12) {
                        watch_clear_indicator(WATCH_INDICATOR_PM);
                    } else {
                        watch_set_indicator(WATCH_INDICATOR_PM);
                    }
                    date_time.unit.hour %= 12;
                    if (date_time.unit.hour == 0) date_time.unit.hour = 12;
                }
#endif
                pos = 0;
                if (event.event_type == EVENT_LOW_ENERGY_UPDATE) {
                    if (!watch_tick_animation_is_running()) watch_start_tick_animation(500);
                    sprintf(buf, "%s%2d%2d%02d  ", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute);
                } else {
                    sprintf(buf, "%s%2d%2d%02d%02d", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
                }
            }
            watch_display_string(buf, pos);
            // handle alarm indicator
            if (state->alarm_enabled != settings->bit.alarm_enabled) _update_alarm_indicator(settings->bit.alarm_enabled, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            state->signal_enabled = !state->signal_enabled;
            if (state->signal_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
            else watch_clear_indicator(WATCH_INDICATOR_BELL);
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

void simple_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool simple_clock_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    simple_clock_state_t *state = (simple_clock_state_t *)context;
    if (!state->signal_enabled) return false;

    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.unit.minute != 0) return false;
    if (settings->bit.hourly_chime_always) return true;
    uint8_t chime_start, chime_end;
    _get_chime_times(date_time, settings, &chime_start, &chime_end);
    if (chime_end == 0) chime_end = 24;
    if (date_time.unit.hour < chime_start || date_time.unit.hour >= chime_end) return false;

    return true;
}
