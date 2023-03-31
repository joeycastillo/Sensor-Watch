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
#include "dual_timer_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_rtc.h"

// FROM stock_stopwatch_face.c ////////////////////////////////////////////////
// Copyright (c) 2022 Andreas Nebinger

#if __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#else
#include "../../../watch-library/hardware/include/saml22j18a.h"
#include "../../../watch-library/hardware/include/component/tc.h"
#include "../../../watch-library/hardware/hri/hri_tc_l22.h"
#endif

static const watch_date_time distant_future = {.unit = {0, 0, 0, 1, 1, 63}};
static bool _is_running;
static uint32_t _ticks;

#if __EMSCRIPTEN__

static long _em_interval_id = 0;

void em_dual_timer_cb_handler(void *userData) {
    // interrupt handler for emscripten 128 Hz callbacks
    (void) userData;
    _ticks++;
}

static void _dual_timer_cb_initialize() { }

static inline void _dual_timer_cb_stop() {
    emscripten_clear_interval(_em_interval_id);
    _em_interval_id = 0;
    _is_running = false;
}

static inline void _dual_timer_cb_start() {
    // initiate 128 hz callback
    _em_interval_id = emscripten_set_interval(em_dual_timer_cb_handler, (double)(1000/128), (void *)NULL);
}

#else

static inline void _dual_timer_cb_start() {
    // start the TC2 timer
    hri_tc_set_CTRLA_ENABLE_bit(TC2);
    _is_running = true;
}

static inline void _dual_timer_cb_stop() {
    // stop the TC2 timer
    hri_tc_clear_CTRLA_ENABLE_bit(TC2);
    _is_running = false;
}

static void _dual_timer_cb_initialize() {
    // setup and initialize TC2 for a 64 Hz interrupt
    hri_mclk_set_APBCMASK_TC2_bit(MCLK);
    hri_gclk_write_PCHCTRL_reg(GCLK, TC2_GCLK_ID, GCLK_PCHCTRL_GEN_GCLK3 | GCLK_PCHCTRL_CHEN);
    _dual_timer_cb_stop();
    hri_tc_write_CTRLA_reg(TC2, TC_CTRLA_SWRST);
    hri_tc_wait_for_sync(TC2, TC_SYNCBUSY_SWRST);
    hri_tc_write_CTRLA_reg(TC2, TC_CTRLA_PRESCALER_DIV64 | // 32 Khz divided by 64 divided by 4 results in a 128 Hz interrupt
                           TC_CTRLA_MODE_COUNT8 | 
                           TC_CTRLA_RUNSTDBY);
    hri_tccount8_write_PER_reg(TC2, 3);
    hri_tc_set_INTEN_OVF_bit(TC2);
    NVIC_ClearPendingIRQ(TC2_IRQn);
    NVIC_EnableIRQ (TC2_IRQn);
}

/* void TC2_Handler(void) {
    // interrupt handler for TC2 (globally!)
    _ticks++;
    TC2->COUNT8.INTFLAG.reg |= TC_INTFLAG_OVF;
} */

#endif

///////////////////////////////////////////////////////////////////////////////

static dual_timer_duration_t ticks_to_duration(uint32_t ticks) {
    dual_timer_duration_t duration;
    uint8_t hours, days;

    while (ticks >= (128 * 60 * 60)) {
        ticks -= (128 * 60 * 60);
        hours++;
        if (hours >= 24) {
            hours -= 24;
            days++;
        }
    }

    duration.centiseconds = (ticks & 0x7F) * 100 / 128;
    duration.seconds = (ticks >> 7) % 60;
    duration.minutes = (ticks >> 7) / 60;
    duration.hours = hours;
    duration.days = days;

    return duration;
}

static void start_timer(dual_timer_state_t *state, bool timer) {
    // if it is not running yet, run it
    if ( !_is_running ) {
        movement_request_tick_frequency(16);
        state->ticks[timer] = 0;
        _dual_timer_cb_start();
        movement_schedule_background_task(distant_future);
    } else {
        // if another timer is already running save the current tick
        state->ticks[timer] = _ticks;
    }
    state->start_time[timer] = watch_rtc_get_date_time();
    state->running[timer] = true;
}

static void stop_timer(dual_timer_state_t *state, bool timer) {
    if ( _is_running ) {
        // stop timer and save duration
        state->running[timer] == false;
        state->duration[timer] = ticks_to_duration(_ticks - state->ticks[timer]);
        // if the other timer is not running, stop callback
        if ( state->running[!timer] == false ) {
            _dual_timer_cb_stop();
            movement_request_tick_frequency(1);
            movement_cancel_background_task();
        }
    }
}

void dual_timer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(dual_timer_state_t));
        memset(*context_ptr, 0, sizeof(dual_timer_state_t));
        _ticks = 0;
    }
    if (!_is_running) {
        // prepare the 128 Hz callback source
        _dual_timer_cb_initialize();
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void dual_timer_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    dual_timer_state_t *state = (dual_timer_state_t *)context;
    if (_is_running) {
        // The background task will keep the watch from entering low energy mode while the stopwatch is on screen.
        movement_schedule_background_task(distant_future);
    }
    // Handle any tasks related to your watch face coming on screen.
}

bool dual_timer_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    dual_timer_state_t *state = (dual_timer_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            if (_is_running) movement_request_tick_frequency(16);
            break;
        case EVENT_TICK:
            printf("%d\n", _is_running);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if ( !state->running[1] ) {
                start_timer(state, 1);
            } else {
                stop_timer(state, 1);
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // You can use the Light button for your own purposes. Note that by default, Movement will also
            // illuminate the LED in response to EVENT_LIGHT_BUTTON_DOWN; to suppress that behavior, add an
            // empty case for EVENT_LIGHT_BUTTON_DOWN.
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            if ( !state->running[0] ) {
                start_timer(state, 0);
            } else {
                stop_timer(state, 0);
            }
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

void dual_timer_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_cancel_background_task();
    // handle any cleanup before your watch face goes off-screen.
}

