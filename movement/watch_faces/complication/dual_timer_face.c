/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
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

void TC2_Handler(void) {
    // interrupt handler for TC2 (globally!)
    _ticks++;
    TC2->COUNT8.INTFLAG.reg |= TC_INTFLAG_OVF;
}

#endif

// STATIC FUNCTIONS ///////////////////////////////////////////////////////////

/** @brief converts tick counts to duration struct for time display 
 */
static dual_timer_duration_t ticks_to_duration(uint32_t ticks) {
    dual_timer_duration_t duration;
    uint8_t hours = 0;
    uint8_t days = 0;

    // count hours and days
    while (ticks >= (128 * 60 * 60)) {
        ticks -= (128 * 60 * 60);
        hours++;
        if (hours >= 24) {
            hours -= 24;
            days++;
        }
    }

    // convert minutes, seconds, centiseconds
    duration.centiseconds = (ticks & 0x7F) * 100 / 128;
    duration.seconds = (ticks >> 7) % 60;
    duration.minutes = (ticks >> 7) / 60;
    duration.hours = hours;
    duration.days = days;

    return duration;
}

/** @brief starts one of the dual timers
 *  @details Starts a dual timer. If no previous timer is running it starts the global
 *  tick counter. If a previous timer is already running it registers the current tick. 
 */
static void start_timer(dual_timer_state_t *state, bool timer) {
    // if it is not running yet, run it
    if ( !_is_running ) {
        _is_running = true;
        movement_request_tick_frequency(16);
        state->start_ticks[timer] = 0;
        state->stop_ticks[timer] = 0;
        _ticks = 0;
        _dual_timer_cb_start();
        movement_schedule_background_task(distant_future);
    } else {
        // if another timer is already running save the current tick
        state->start_ticks[timer] = _ticks;
        state->stop_ticks[timer] = _ticks;
    }
    state->running[timer] = true;
}

/** @brief stops one of the dual timers
 *  @details Stops a dual timer. If no other timer is running it stops the global
 *  tick counter. If another timer is already running it registers the current stop tick. 
 */
static void stop_timer(dual_timer_state_t *state, bool timer) {
    // stop timer and save duration
    state->stop_ticks[timer] = _ticks;
    state->duration[timer] = ticks_to_duration(state->stop_ticks[timer] - state->start_ticks[timer]);
    state->running[timer] = false;
    // if the other timer is not running, stop callback
    if ( state->running[!timer] == false ) {
        _is_running = false;
        _dual_timer_cb_stop();
        movement_request_tick_frequency(1);
        movement_cancel_background_task();
    }
}

/** @brief displays the measured time for each of the dual timers
 *  @details displays the dual timer. Below 1 hour it displays the timed minutes, seconds,
 *  and centiseconds. Above that it shows the timed hours, minutes, and seconds. If it 
 *  has run for more than a day it shows the days, hours, and minutes.
 *  When the timer is running, the colon blinks every half second.
 *  It also indicates at the top if another counter is running and for how long.
 */
static void dual_timer_display(dual_timer_state_t *state) {
    char buf[11];
    char oi[3];
    // get the current time count of the selected counter
    dual_timer_duration_t timer = state->running[state->show] ? ticks_to_duration(state->stop_ticks[state->show] - state->start_ticks[state->show]) : state->duration[state->show];
    // get the current time count of the other counter
    dual_timer_duration_t other = ticks_to_duration(state->stop_ticks[!state->show] - state->start_ticks[!state->show]);
    
    if ( timer.days > 0 )
        sprintf(buf, "%02u%02u%02u", timer.days, timer.hours, timer.minutes);
    else if ( timer.hours > 0 )
        sprintf(buf, "%02u%02u%02u", timer.hours, timer.minutes, timer.seconds);
    else
        sprintf(buf, "%02u%02u%02u", timer.minutes, timer.seconds, timer.centiseconds);
    watch_display_string(buf, 4);
    
    // which counter is displayed
    watch_display_string(state->show ? "B" : "A", 0);
    
    // indicate whether other counter is running
    watch_display_string(state->running[!state->show] && (_ticks % 100) < 50 ? "+" : " ", 1);
    
    // indicate for how long the other counter has been running
    sprintf(oi, "%2u", other.days > 0 ? other.days : (other.hours > 0 ? other.hours : (other.minutes > 0 ? other.minutes : (other.seconds > 0 ? other.seconds : other.centiseconds))));
    watch_display_string( (state->stop_ticks[!state->show] - state->start_ticks[!state->show]) > 0 ? oi : "  ", 2);
    
    // blink colon when running
    if ( timer.centiseconds > 50 || !state->running[state->show] ) watch_set_colon();
    else watch_clear_colon();
}

// PUBLIC WATCH FACE FUNCTIONS ////////////////////////////////////////////////

void dual_timer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(dual_timer_state_t));
        memset(*context_ptr, 0, sizeof(dual_timer_state_t));
        _ticks = 0;
    }
    if (!_is_running) {
        _dual_timer_cb_initialize();
    }
}

void dual_timer_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    if (_is_running) {
        movement_schedule_background_task(distant_future);
    }
}

bool dual_timer_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    dual_timer_state_t *state = (dual_timer_state_t *)context;

    // timers stop at 99:23:59:59:99
    if ( (_ticks - state->start_ticks[0]) >= 1105919999 )
        stop_timer(state, 0);

    if ( (_ticks - state->start_ticks[1]) >= 1105919999 )
        stop_timer(state, 1);

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_set_colon();
            if (_is_running) movement_request_tick_frequency(16);
            else watch_display_string("A   000000", 0);
            break;
        case EVENT_TICK:
            if ( _is_running ) {
                // update stop ticks
                if ( state->running[0] )
                    state->stop_ticks[0] = _ticks;
                if ( state->running[1] )
                    state->stop_ticks[1] = _ticks;
                dual_timer_display(state);
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // start/stop timer B
            state->running[1] = !state->running[1];
            if ( state->running[1] ) {
                start_timer(state, 1);
            } else {
                stop_timer(state, 1);
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            // start/stop timer A
            state->running[0] = !state->running[0];
            if ( state->running[0] ) {
                start_timer(state, 0);
            } else {
                stop_timer(state, 0);
            }
            break;
        case EVENT_MODE_BUTTON_DOWN:
            // switch between the timers
            state->show = !state->show;
            dual_timer_display(state);
            break;
        case EVENT_MODE_BUTTON_UP:
            // prevent watch from going to the next face when a timer is running
            // if no timers are running fall back to default functionality
            if ( !_is_running ) movement_move_to_next_face();
            break;
        case EVENT_MODE_LONG_PRESS:
            // but do it on long press MODE!
            // if no timers are running fall back to default functionality
            if ( _is_running ) movement_move_to_next_face();
            else movement_move_to_face(0);
            break;
        case EVENT_TIMEOUT:
            // go back to 
            if (!_is_running) movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            dual_timer_display(state);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void dual_timer_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_cancel_background_task();
    // handle any cleanup before your watch face goes off-screen.
}

