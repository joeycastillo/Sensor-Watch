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
#include "movement.h"

// FROM stock_stopwatch_face.c ////////////////////////////////////////////////
// Copyright (c) 2022 Andreas Nebinger

// max time displayed is 99 days, 23 hours, 59 minutes, 59 seconds, 99 centiseconds
const uint64_t MAX_TIME = (9900LL/1024LL) + 1024LL * (59LL + 59LL*60LL + 23LL*60LL*60LL + 99LL*24LL*60LL*60LL);

// STATIC FUNCTIONS ///////////////////////////////////////////////////////////

/** @brief converts tick counts to duration struct for time display 
 * 
 * ticks = 1/1024ths of a second
 */
static dual_timer_duration_t ticks_to_duration(uint64_t ticks) {
    dual_timer_duration_t duration;

    // limit timers to 99d23h59m59d99c
    if(ticks > MAX_TIME) ticks = MAX_TIME;

    uint16_t thousandths = ticks % 1024;
    ticks /= 1024; // ticks = seconds now
    duration.centiseconds = (thousandths * 100) / 1024;
    duration.seconds = ticks % 60;
    ticks /= 60; // ticks = minutes now
    duration.minutes = ticks % 60;
    ticks /= 60; // ticks = hours now
    duration.hours = ticks % 24;
    ticks /= 24; // ticks = days now
    duration.days = ticks % 100;

    return duration;
}

/** @brief starts one of the dual timers
 *  @details Starts a dual timer. If no previous timer is running it starts the global
 *  tick counter. If a previous timer is already running it registers the current tick. 
 */
static void start_timer(dual_timer_state_t *state, bool timer) {
    // if it is not running yet, run it
    movement_hpt_request();
    movement_request_tick_frequency(16);
    state->start_ticks[timer] = movement_hpt_get();
    state->running[timer] = true;
}

/** @brief stops one of the dual timers
 *  @details Stops a dual timer. If no other timer is running it stops the global
 *  tick counter. If another timer is already running it registers the current stop tick. 
 */
static void stop_timer(dual_timer_state_t *state, bool timer) {
    // stop timer and save duration
    state->stop_ticks[timer] = movement_hpt_get();
    state->duration[timer] = ticks_to_duration(state->stop_ticks[timer] - state->start_ticks[timer]);
    state->running[timer] = false;

    // if neither timer is running, release hpt
    if(!(state->running[0] || state->running[1])) {
        movement_request_tick_frequency(1);
        movement_hpt_release();
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
    uint64_t now = movement_hpt_get();

    dual_timer_duration_t timer = state->running[state->show] ? ticks_to_duration(now - state->start_ticks[state->show]) : state->duration[state->show];
    dual_timer_duration_t other = state->running[!state->show] ? ticks_to_duration(now - state->start_ticks[!state->show]) : state->duration[!state->show];
    
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
    watch_display_string(state->running[!state->show] && (now % 1024) < 512 ? "+" : " ", 1);
    
    // indicate for how long the other counter has been running
    sprintf(oi, "%2u", other.days > 0 ? other.days : (other.hours > 0 ? other.hours : (other.minutes > 0 ? other.minutes : (other.seconds > 0 ? other.seconds : other.centiseconds))));
    watch_display_string( state->running[!state->show] ? oi : "  ", 2);
    
    // blink colon when running
    if ( timer.centiseconds > 50 || !state->running[state->show] ) watch_set_colon();
    else watch_clear_colon();
}

// PUBLIC WATCH FACE FUNCTIONS ////////////////////////////////////////////////

void dual_timer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(dual_timer_state_t));
        memset(*context_ptr, 0, sizeof(dual_timer_state_t));
    }
}

void dual_timer_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool dual_timer_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    dual_timer_state_t *state = (dual_timer_state_t *)context;

    bool is_running = (state->running[0] || state->running[1]);

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_set_colon();
            if (is_running) {
                movement_request_tick_frequency(16);
                if ( state->running[0] )
                    state->show = 0;
                else state->show = 1;
            } else {
                if (state->stop_ticks[0] > 0 || state->stop_ticks[1] > 0)
                    dual_timer_display(state);
                else watch_display_string("A   000000", 0);
            }
            break;
        case EVENT_TICK:
            if ( is_running ) {
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
            // don't switch to next face...
            break;
        case EVENT_MODE_LONG_PRESS:
            // ...but do it on long press MODE!
            movement_move_to_next_face();
            break;
        case EVENT_TIMEOUT:
            // go back to 
            if (!is_running) movement_move_to_face(0);
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
    movement_request_tick_frequency(1);
}

