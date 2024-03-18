/*
 * MIT License
 *
 * Copyright (c) 2024 <#author_name#>
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
#include <inttypes.h>
#include "hpt_countdown_face.h"

#define LCD_UPDATE_RATE_WHILE_RUNNING 8

static void render(hpt_countdown_state_t *state, bool blink)
{
    // always draw auto-repeat indicator, but not count
    if (state->auto_repeat)
    {
        watch_set_indicator(WATCH_INDICATOR_LAP);
    }
    else
    {
        watch_clear_indicator(WATCH_INDICATOR_LAP);
    }

    char buf[9];
    if (state->setting_mode != 0)
    {
        // draw the set time and repeat mode
        sprintf(buf, "  %02d%02d%02d",
                state->set_hours,
                state->set_minutes,
                state->set_seconds);
        watch_display_string(buf, 2);
        if (blink)
        {
            // clear the setting being configured
            // should map to the digit being configured
            watch_display_string(" ", 10 - (state->setting_mode));
        }
    }
    else
    {
        // draw repeat count
        if (state->auto_repeat)
        {
            sprintf(buf, "%2d", state->repeat_count);
            watch_display_string(buf, 2);
        }
        else
        {
            watch_display_string("  ", 2);
        }

        int64_t timeLeft; // 1024hz ticks

        if (state->running)
        {
            // calculate time left until target time
            int64_t now = movement_hpt_get_fast();
            int64_t signed_target = state->target;
            timeLeft = signed_target - now;
        }
        else
        {
            timeLeft = state->paused_ms_left;
        }

        // TODO: need to do better with the division here
        // - it looks bad when you start the timer and it immediately shows the time-1
        // - it sits on the number zero for a full second before it triggers the beeps
        // - and in "normal" mode, it sits on the zero for a second before it starts showing negative numbers
        // Would rather it stay on the configured time for a full second when you start it and start beeping immediately when the timer hits zero

        bool negative = timeLeft < 0;
        if (negative)
            timeLeft = -timeLeft;
        // we do some clamping
        if (timeLeft >= 30 * 60 * 60 * 1024)
            timeLeft = (30 * 60 * 60 * 1024 - 1);

        // throw away ms part

        timeLeft /= 1024;

        uint8_t seconds = timeLeft % 60;
        timeLeft /= 60;
        uint8_t minutes = timeLeft % 60;
        uint8_t hours = timeLeft / 60;

        if (minutes == 0 && hours == 0)
        {
            sprintf(buf, "   %3d", negative ? -seconds : seconds);
            watch_display_string(buf, 4);
            watch_clear_colon();
        }
        else if (hours == 0)
        {
            sprintf(buf, " %3d%02d", negative ? -minutes : minutes, seconds);
            watch_display_string(buf, 4);
            watch_clear_colon();
        }
        else
        {
            watch_set_colon();
            if (state->auto_repeat)
            {
                // don't overwrite lap counter
                //  also, should never be negative
                sprintf(buf, "%2d%02d%02d", hours, minutes, seconds);
                watch_display_string(buf, 4);
            }
            else
            {
                // allow overwrite of lap counter with negative sign
                sprintf(buf, "%3d%02d%02d", negative ? -hours : hours, minutes, seconds);
                watch_display_string(buf, 3);
            }
        }
    }
}

static void reset_timer(hpt_countdown_state_t *state)
{
    // make sure time is always paused first!

    state->paused_ms_left = ((state->set_hours * 60 * 60) +
                             (state->set_minutes * 60) +
                             (state->set_seconds)) *
                            1024;
    state->repeat_count = 0;
}

// starts a paused timer
static void start_timer(hpt_countdown_state_t *state)
{
    movement_hpt_request_face(state->watch_face_index);
    uint64_t now = movement_hpt_get();
    state->running = true;

    movement_request_tick_frequency(LCD_UPDATE_RATE_WHILE_RUNNING);

    // reset the target based on the number of seconds left when the timer was paused
    state->target = now + state->paused_ms_left;

    // if the target was in the past, don't schedule a new reset, the time has already expired.
    if (state->target >= now)
    {
        movement_hpt_schedule_face(state->target, state->watch_face_index);
    }
}

// restarts a currently running timer for another lap
static void restart_timer(hpt_countdown_state_t *state)
{
    state->repeat_count = (state->repeat_count + 1) % 40;
    uint64_t duration = ((state->set_hours * 60 * 60) +
                         (state->set_minutes * 60) +
                         (state->set_seconds)) *
                        1024;
    state->target += duration;
    movement_hpt_schedule_face(state->target, state->watch_face_index);
}

static void trigger_timer(hpt_countdown_state_t *state)
{
    movement_play_alarm();

    // timer will start counting up, so we can cancel the alarm but leave the HPT running
    movement_hpt_cancel_face(state->watch_face_index);

    // if auto repeat is enabled, restart_timer will schedule another event for us.
    if (state->auto_repeat)
    {
        restart_timer(state);
    }
}

static void pause_timer(hpt_countdown_state_t *state)
{
    state->running = false;
    // record time left between now and the target
    state->paused_ms_left = state->target - movement_hpt_get();

    movement_request_tick_frequency(1);

    // can cancel the scheduled event and stop HPT
    movement_hpt_cancel_face(state->watch_face_index);
    movement_hpt_release_face(state->watch_face_index);
}

void hpt_countdown_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr)
{
    (void)settings;
    (void)watch_face_index;
    if (*context_ptr == NULL)
    {
        *context_ptr = malloc(sizeof(hpt_countdown_state_t));
        memset(*context_ptr, 0, sizeof(hpt_countdown_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.

        hpt_countdown_state_t *state = *context_ptr;
        state->auto_repeat = false;
        state->set_hours = 0;
        state->set_minutes = 0;
        state->set_seconds = 10;
        state->repeat_count = 0;
        state->watch_face_index = watch_face_index;
        state->setting_mode = 0;

        reset_timer(state);
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void hpt_countdown_face_activate(movement_settings_t *settings, void *context)
{
    (void)settings;
    hpt_countdown_state_t *state = (hpt_countdown_state_t *)context;

    // reset setting mode
    state->setting_mode = 0;
    watch_display_string("TR", 0);

    // if the timer is running, use a higher tick rate to update the display more responsively, even though the background timer is not tied to the tick rate anymore
    if (state->running)
    {
        movement_request_tick_frequency(LCD_UPDATE_RATE_WHILE_RUNNING);
    }
}

static void increment_setting(hpt_countdown_state_t *state)
{
    switch (state->setting_mode)
    {
    case 1: // seconds ones
        if (state->set_seconds % 10 == 9)
        {
            state->set_seconds -= 9;
        }
        else
        {
            state->set_seconds += 1;
        }
        break;
    case 2: // seconds tens
        state->set_seconds = (state->set_seconds + 10) % 60;
        break;
    case 3: // minutes ones
        if (state->set_minutes % 10 == 9)
        {
            state->set_minutes -= 9;
        }
        else
        {
            state->set_minutes += 1;
        }
        break;
    case 4: // minutes tens
        state->set_minutes = (state->set_minutes + 10) % 60;
        break;
    case 5: // hours ones
        if (state->set_hours % 10 == 9)
        {
            state->set_hours -= 9;
        }
        else
        {
            state->set_hours += 1;
        }
        break;
    case 6: // hours tens
        state->set_hours = (state->set_hours + 10) % 30;
        break;
    default:
        break;
    }
}

bool hpt_countdown_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    hpt_countdown_state_t *state = (hpt_countdown_state_t *)context;

    bool blink = !!(event.subsecond & 1);

    switch (event.event_type)
    {
    case EVENT_ACTIVATE:
        // Show your initial UI here.
        render(state, false);
        break;
    case EVENT_TICK:
        render(state, blink);
        break;
    case EVENT_LIGHT_BUTTON_DOWN:
        // swallow this because light behavior is different here.
        break;
    case EVENT_LIGHT_BUTTON_UP:
        // reset time and toggle repeat mode
        if (state->setting_mode != 0)
        {
            // exit setting mode
            reset_timer(state);
        }
        else if (!(state->running))
        {
            // if the timer is already reset, enter setting mode
            int64_t expected_ticks_left = ((state->set_hours * 60 * 60) +
                                           (state->set_minutes * 60) +
                                           (state->set_seconds)) *
                                          1024;

            if (state->paused_ms_left == expected_ticks_left)
            {
                // timer is already reset, enter settings mode
                state->setting_mode = 1;
            }
            else
            {
                // reset timer
                reset_timer(state);
            }
        }
        else
        {
            // nothing really to do if they press this while the timer is running I think
        }
        render(state, false);
        break;
    case EVENT_LIGHT_LONG_PRESS:
        // toggle auto-repeat mode
        state->auto_repeat = !(state->auto_repeat);
        // TODO: if timer is currently in overflow mode, restart a new lap immediately
        if (state->running && (state->target <= movement_hpt_get()))
        {
            restart_timer(state);
        }
        render(state, false);
        break;
    case EVENT_ALARM_BUTTON_DOWN:
        if (state->setting_mode == 0)
        {
            if (state->running)
            {
                pause_timer(state);
            }
            else
            {
                start_timer(state);
            }
        }
        else
        {
            // increment setting item
            increment_setting(state);
        }
        render(state, false);
        break;
    case EVENT_TIMEOUT:
        if (!(state->running))
        {
            movement_move_to_face(0);
        }
        break;
    case EVENT_MODE_BUTTON_UP:
        // if in setting mode, loop through settings, otherwise, regular mode behavior
        if (state->setting_mode != 0)
        {
            state->setting_mode = (state->setting_mode + 1);
            if (state->setting_mode > 6)
            {
                // loop back to 1
                state->setting_mode = 1;
            }
            render(state, true);
        }
        else
        {
            movement_move_to_next_face();
        }
        break;
    case EVENT_HPT:
        // timer went off
        trigger_timer(state);
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

void hpt_countdown_face_resign(movement_settings_t *settings, void *context)
{
    (void)settings;
    (void)context;

    // handle any cleanup before your watch face goes off-screen.
    movement_request_tick_frequency(1);
}
