/*
 * MIT License
 *
 * Copyright (c) 2022 Andreas Nebinger
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
#include "stock_stopwatch_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_rtc.h"

/*
    This watch face implements the original F-91W stopwatch functionality
    including counting hundredths of seconds and lap timing. There are two
    improvements compared to the functionality of the original: 
    1. When reaching 59:59 the counter does not simply jump back to zero,
       but keeps track of hours in the upper right hand corner. (Up to 24h)
    2. Long pressing the light button toggles the led behaviour: it either
       turns on on each button press or it doesn't.
*/

// distant future for background task: January 1, 2083
static const watch_date_time distant_future = {
    .unit = {0, 0, 0, 1, 1, 63}
};

static uint32_t _ticks;
static uint32_t _lap_ticks;
static uint32_t _last_ticks_stopped;
static uint8_t _blink_ticks;
static uint32_t _old_seconds;
static uint8_t _old_minutes;
static uint8_t _hours;
static watch_date_time _start_time;
static watch_date_time _resume_time;
static watch_date_time _compare_time;
static uint8_t *_measure_ticks;
static uint8_t _tick_offset_start;
static uint8_t _tick_offset_resume;
static bool _colon;
static bool _is_running;

static void _fast_tick_callback() {
    _ticks++;  // overflow is handled further down in the app loop, to save cycles here
    if (_measure_ticks != NULL) {
        // we need to keep track of the tick offset to the next full rtc second (to be able to adjust the timer
        // when we wake up from low energy mode)
        watch_date_time current_time = watch_rtc_get_date_time();
        if (current_time.unit.second != _compare_time.unit.second) {
            // we are done counting
            if (_measure_ticks == &_tick_offset_resume) {
                // we have just woken up from low energy mode, so adjusts the ticks here
                _ticks -= *_measure_ticks;
                _old_minutes -= 1;  // initiate a redraw (no need to bother about overflows)
            }
            _measure_ticks = NULL;
        } else
            *_measure_ticks++;
    }
}

static inline void _button_beep(movement_settings_t *settings) {
    // play a beep as confirmation for a button press (if applicable)
    if (settings->bit.button_should_sound) watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
}

/// @brief Display minutes, seconds and fractions derived from 128 Hz tick counter
///        on the lcd.
/// @param ticks
static void _display_ticks(uint32_t ticks) {
    char buf[14];
    uint8_t sec_100 = (ticks & 0x7F) * 100 / 128;
    uint32_t seconds = ticks >> 7;
    uint32_t minutes = seconds / 60;
    if (_hours)
        sprintf(buf, "%2u%02lu%02lu%02u", _hours, minutes, (seconds % 60), sec_100);
    else
        sprintf(buf, "  %02lu%02lu%02u", minutes, (seconds % 60), sec_100);
    watch_display_string(buf, 2);
}

/// @brief Displays the current stopwatch time on the LCD (more optimized than _display_ticks())
static void _draw() {
    if (_lap_ticks == 0) {
        char buf[14];
        uint8_t sec_100 = (_ticks & 0x7F) * 100 / 128;
        if (_is_running) {
            uint32_t seconds = _ticks >> 7;
            if (seconds != _old_seconds) {
                // seconds have changed
                _old_seconds = seconds;
                uint8_t minutes = seconds / 60;
                seconds %= 60;
                if (minutes != _old_minutes) {
                    // minutes have changed, draw everything
                    _old_minutes = minutes;
                    minutes %= 60;
                    if (_hours)
                        // with hour indicator
                        sprintf(buf, "%2u%02u%02lu%02u", _hours, minutes, seconds, sec_100);
                    else
                        // no hour indicator
                        sprintf(buf, "  %02u%02lu%02u", minutes, seconds, sec_100);
                    watch_display_string(buf, 2);
                } else {
                    // just draw seconds
                    sprintf(buf, "%02lu%02u", seconds, sec_100);
                    watch_display_string(buf, 6);
                }
            } else {
                // only draw 100ths of seconds
                sprintf(buf, "%02u", sec_100);
                watch_display_string(buf, 8);
            }
        } else {
            _display_ticks(_ticks);
        }
    }
    if (_is_running) {
        // blink the colon every half second
        uint8_t blink_ticks = ((_ticks >> 6) & 1);
        if (blink_ticks != _blink_ticks) {
            _blink_ticks = blink_ticks;
            _colon = !_colon;
            if (_colon) watch_set_colon();
            else watch_clear_colon();
        }
    }
}

static inline void _update_lap_indicator() {
    if (_lap_ticks) watch_set_indicator(WATCH_INDICATOR_LAP);
    else  watch_clear_indicator(WATCH_INDICATOR_LAP);
}

static inline void _set_colon() {
    watch_set_colon();
    _colon = true;
}

void stock_stopwatch_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(stock_stopwatch_state_t));
        memset(*context_ptr, 0, sizeof(stock_stopwatch_state_t));
        stock_stopwatch_state_t *state = (stock_stopwatch_state_t *)*context_ptr;
        _ticks = _last_ticks_stopped = _lap_ticks = _blink_ticks = _old_minutes = _old_seconds = _hours = 0;
    _is_running = _colon = false;
        _start_time.reg = _resume_time.reg = _compare_time.reg = 0;
        _measure_ticks = NULL;
        state->light_on_button = true;
        state->callback_slot = -1;
    } else if (_is_running) {
        // we are resuming from low energy mode and are still running, so we need to set up some timing adjustments
        stock_stopwatch_state_t *state = (stock_stopwatch_state_t *)*context_ptr;
        if (state->callback_slot >= 0) watch_rtc_disable_periodic_callback_slot(128, state->callback_slot);
        _ticks = _last_ticks_stopped;
        watch_date_time _resume_time = watch_rtc_get_date_time();
        _compare_time = _resume_time;
        _ticks += (watch_utility_date_time_to_unix_time(_resume_time, 0) - watch_utility_date_time_to_unix_time(_start_time, 0)) * 128 + _tick_offset_start;
        _tick_offset_resume = 0;
        _measure_ticks = &_tick_offset_resume;
        // register 128 hz callback for time measuring
        state->callback_slot = watch_rtc_register_periodic_callback_slot(_fast_tick_callback, 128);
    }
}

void stock_stopwatch_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    if (_is_running) {
        // The background task will keep the watch from entering low energy mode while the stopwatch is on screen.
        movement_schedule_background_task(distant_future);
    }
}

bool stock_stopwatch_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    stock_stopwatch_state_t *state = (stock_stopwatch_state_t *)context;

    // handle overflow of fast ticks
    while (_ticks >= (128 * 60 * 60)) {
        _ticks -= (128 * 60 * 60);
        _hours++;
        if (_hours >= 24) _hours -= 24;
        // initiate a re-draw
        _old_minutes = 59;
    }

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _set_colon();
            watch_display_string("ST  ", 0);
            _update_lap_indicator();
            if (_is_running) movement_request_tick_frequency(16);
            _display_ticks(_lap_ticks ? _lap_ticks : _ticks);
            break;
        case EVENT_TICK:
            _draw();
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_LONG_PRESS:
            // kind od hidden feature: long press toggles light on or off
            state->light_on_button = !state->light_on_button;
            if (state->light_on_button) movement_illuminate_led();
            else watch_set_led_off();
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            _is_running = !_is_running;
            if (_is_running) {
                // start or continue stopwatch
                if (state->callback_slot >= 0) watch_rtc_disable_periodic_callback_slot(128, state->callback_slot);
                _compare_time = watch_rtc_get_date_time();
                _start_time = _compare_time;
                _tick_offset_start = 0;
                _measure_ticks = &_tick_offset_start;
                // update the display at 16 hz
                movement_request_tick_frequency(16);
                // register 128 hz callback for time measuring
                state->callback_slot = watch_rtc_register_periodic_callback_slot(_fast_tick_callback, 128);
                // schedule the keepalive task when running
                movement_schedule_background_task(distant_future);
            } else {
                // stop the stopwatch
                if (state->callback_slot >= 0) watch_rtc_disable_periodic_callback_slot(128, state->callback_slot);
                movement_request_tick_frequency(1);
                _last_ticks_stopped = _ticks;
                _set_colon();
                // cancel the keepalive task
                movement_cancel_background_task();
            }
            _draw();
            _button_beep(settings);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if (state->light_on_button) movement_illuminate_led();
            if (_is_running) {
                if (_lap_ticks) {
                    // clear lap and continue running
                    _lap_ticks = 0;
                    movement_request_tick_frequency(16);
                } else {
                    // set lap ticks and stop updating the display
                    _lap_ticks = _ticks;
                    movement_request_tick_frequency(2);
                    _set_colon();
                }
            } else {
                if (_lap_ticks) {
                    // clear lap and show running stopwatch
                    _lap_ticks = 0;
                } else if (_ticks) {
                    // reset stopwatch
                    _ticks = _last_ticks_stopped = _lap_ticks = _blink_ticks = _old_minutes = _old_seconds = _hours = 0;
                    _button_beep(settings);
                }
            }
            _display_ticks(_ticks);
            _update_lap_indicator();
            break;
        case EVENT_TIMEOUT:
            if (!_is_running) movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            _draw();
            break;
        default:
            break;
    }
    return true;
}

void stock_stopwatch_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    // cancel the keepalive task
    movement_cancel_background_task();
}