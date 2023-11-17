/*
 * MIT License
 *
 * Copyright (c) 2023 Konrad Rieck
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
#include "animated_clock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"
#include "animations.h"

/* Supported animation invervals */
#define NUM_ANIMATION_INVERVALS (7)
const uint8_t animation_intervals[] = {
    0, 1, 5, 10, 15, 30, 60
};

/* Preferences of clock */
#define NUM_PREFEFENCES (1)
const char preference_titles[][11] = {
    "IN        ",       // Interval in minutes
};

/* Auxiliary structure for indicator segments */
#define NUM_INDICATORS (4)
typedef struct {
    WatchIndicatorSegment segment;
    bool state;
} indicator_t;

static watch_date_time _convert_12h_mode(watch_date_time date_time)
{
    // if we are in 12 hour mode, do some cleanup.
    if (date_time.unit.hour < 12) {
        watch_clear_indicator(WATCH_INDICATOR_PM);
    } else {
        watch_set_indicator(WATCH_INDICATOR_PM);
    }
    date_time.unit.hour %= 12;
    if (date_time.unit.hour == 0)
        date_time.unit.hour = 12;

    return date_time;
}

/* Update all indicators on the face */
static void _update_indicators(movement_settings_t *settings, animated_clock_state_t *state)
{
    indicator_t indicators[NUM_INDICATORS] = {
        { WATCH_INDICATOR_24H, settings->bit.clock_mode_24h },
        { WATCH_INDICATOR_BELL, state->signal_enabled },
        { WATCH_INDICATOR_SIGNAL, state->alarm_enabled },
        { WATCH_INDICATOR_LAP, state->battery_low },
    };

    for (uint8_t i = 0; i < NUM_INDICATORS; i++)
        if (indicators[i].state)
            watch_set_indicator(indicators[i].segment);
        else
            watch_clear_indicator(indicators[i].segment);
}

/* Check for low battery and display warning */
static void _check_battery(watch_date_time date_time, movement_settings_t *settings,
                           animated_clock_state_t *state)
{
    bool prev_battery_low = state->battery_low;

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

    if (prev_battery_low != state->battery_low)
        _update_indicators(settings, state);
}

/* Check wether animation interval has been reached */
static void _check_animation_interval(animated_clock_state_t *state)
{
    watch_date_time date_time = watch_rtc_get_date_time();

    // Activate animations only in display mode
    if (state->mode != MODE_CLOCK)
        return;
    // Check for disabled animation
    if (animation_intervals[state->interval] == 0)
        return;
    // Check for last second
    if (date_time.unit.second != 0)
        return;
    // Check for last minute before start
    if (date_time.unit.minute % animation_intervals[state->interval] != 0)
        return;

    // Let's go...
    state->previous_date_time = REFRESH_FACE;
    state->mode = MODE_ANIMATION;
    state->animation = (state->animation + 1) % NUM_ANIMATIONS;
}


static void _init_display_clock(movement_settings_t *settings, animated_clock_state_t *state)
{
    watch_set_colon();
    _update_indicators(settings, state);
    movement_request_tick_frequency(1);
}

static void _display_clock(movement_event_t event, movement_settings_t *settings,
                           animated_clock_state_t *state)
{
    char buf[11];
    uint8_t pos;

    watch_date_time date_time = watch_rtc_get_date_time();
    uint32_t previous_date_time = state->previous_date_time;
    state->previous_date_time = date_time.reg;

    if (previous_date_time == REFRESH_FACE)
        _init_display_clock(settings, state);

    _check_battery(date_time, settings, state);

    if ((date_time.reg >> 6) == (previous_date_time >> 6)
        && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
        // everything before seconds is the same, don't waste cycles setting those segments.
        watch_display_character_lp_seconds('0' + date_time.unit.second / 10, 8);
        watch_display_character_lp_seconds('0' + date_time.unit.second % 10, 9);
        return;
    } else if ((date_time.reg >> 12) == (previous_date_time >> 12)
               && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
        // everything before minutes is the same.
        pos = 6;
        sprintf(buf, "%02d%02d", date_time.unit.minute, date_time.unit.second);
    } else {
        // other stuff changed; let's do it all.
        if (!settings->bit.clock_mode_24h)
            date_time = _convert_12h_mode(date_time);
        pos = 0;
        if (event.event_type == EVENT_LOW_ENERGY_UPDATE) {
            if (!watch_tick_animation_is_running())
                watch_start_tick_animation(500);
            sprintf(buf, "%s%2d%2d%02d  ", watch_utility_get_weekday(date_time), date_time.unit.day,
                    date_time.unit.hour, date_time.unit.minute);
        } else {
            sprintf(buf, "%s%2d%2d%02d%02d", watch_utility_get_weekday(date_time),
                    date_time.unit.day, date_time.unit.hour, date_time.unit.minute,
                    date_time.unit.second);
        }
    }
    watch_display_string(buf, pos);

    // handle change of alarm indicator
    if (state->alarm_enabled != settings->bit.alarm_enabled) {
        state->alarm_enabled = settings->bit.alarm_enabled;
        _update_indicators(settings, state);
    }
}

static void _init_display_preferences(animated_clock_state_t *state)
{
    watch_clear_colon();
    watch_clear_all_indicators();
    movement_request_tick_frequency(4);

    /* Clear refresh flag */
    state->previous_date_time = 0;
}

static void _display_preferences(uint8_t page, movement_event_t event,
                                 animated_clock_state_t *state)
{
    char buf[8];
    watch_display_string((char *) preference_titles[page], 0);

    if (state->previous_date_time == REFRESH_FACE)
        _init_display_preferences(state);

    switch (page) {
        case 0:
            if (state->interval == 0)
                sprintf(buf, "off   ");
            else
                sprintf(buf, "%2dn&in", animation_intervals[state->interval]);
            break;
    }

    // Blink first 3 characters
    if (event.subsecond % 2)
        memset(buf, ' ', 6);

    watch_display_string(buf, 4);
}

static bool _preferences_loop(movement_event_t event, movement_settings_t *settings,
                              animated_clock_state_t *state)
{
    uint8_t page = state->preference_page;

    switch (event.event_type) {
        case EVENT_TICK:
        case EVENT_ACTIVATE:
            // Do nothing; handled below.
            break;
        case EVENT_TIMEOUT:
        case EVENT_MODE_BUTTON_UP:
            // Return to display mode
            state->mode = MODE_CLOCK;
            state->previous_date_time = REFRESH_FACE;
            // Display clock now for smooth transition
            _display_clock(event, settings, state);
            return true;
        case EVENT_LIGHT_BUTTON_DOWN:
            page = (page + 1) % NUM_PREFEFENCES;
            state->preference_page = page;
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (page) {
                case 0:
                    state->interval = (state->interval + 1) % NUM_ANIMATION_INVERVALS;
                    break;
            }
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    _display_preferences(page, event, state);
    return true;
}

static bool _main_loop(movement_event_t event, movement_settings_t *settings,
                       animated_clock_state_t *state)
{
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            _check_animation_interval(state);
            if (state->mode != MODE_ANIMATION) {
                _display_clock(event, settings, state);
                break;
            }

            switch (state->animation % NUM_ANIMATIONS) {
                case 1:
                    ani_wyoscan_clock(event, settings, state);
                    break;
                case 0:
                    ani_scroll_clock(event, settings, state);
                    break;
            }

            break;
        case EVENT_LOW_ENERGY_UPDATE:
            _display_clock(event, settings, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            state->signal_enabled = !state->signal_enabled;
            _update_indicators(settings, state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            state->mode = MODE_PREFERENCES;
            state->previous_date_time = REFRESH_FACE;
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            /* Do nothing. */
            break;
        case EVENT_LIGHT_BUTTON_UP:
            movement_illuminate_led();
            break;
        case EVENT_BACKGROUND_TASK:
            if (watch_is_buzzer_or_led_enabled()) {
                // if we are in the foreground, we can just beep.
                movement_play_signal();
            } else {
                // if we were in the background, we need to enable the buzzer first
                watch_enable_buzzer();
                movement_play_signal();
                watch_disable_buzzer();
            }
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void animated_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index,
                               void **context_ptr)
{
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = calloc(sizeof(animated_clock_state_t), 1);
        animated_clock_state_t *state = (animated_clock_state_t *) *context_ptr;
        state->signal_enabled = false;
        state->watch_face_index = watch_face_index;
        state->interval = 1;    // Default every minute (see animation_intervals)
    }
}

void animated_clock_face_activate(movement_settings_t *settings, void *context)
{
    animated_clock_state_t *state = (animated_clock_state_t *) context;

    // this ensures that none of the timestamp fields will match, so we can re-render them all.
    state->previous_date_time = REFRESH_FACE;
    state->alarm_enabled = settings->bit.alarm_enabled;
    state->mode = MODE_CLOCK;
    if (watch_tick_animation_is_running())
        watch_stop_tick_animation();
}

bool animated_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    animated_clock_state_t *state = (animated_clock_state_t *) context;
    switch (state->mode) {
        case MODE_CLOCK:
        case MODE_ANIMATION:
            return _main_loop(event, settings, state);
        case MODE_PREFERENCES:
            return _preferences_loop(event, settings, state);
    }
    return true;
}

void animated_clock_face_resign(movement_settings_t *settings, void *context)
{
    (void) settings;
    (void) context;
}

bool animated_clock_face_wants_background_task(movement_settings_t *settings, void *context)
{
    (void) settings;
    animated_clock_state_t *state = (animated_clock_state_t *) context;
    if (!state->signal_enabled)
        return false;

    watch_date_time date_time = watch_rtc_get_date_time();
    return date_time.unit.minute == 0;
}
