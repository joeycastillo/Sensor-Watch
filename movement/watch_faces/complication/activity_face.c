/*
 * MIT License
 *
 * Copyright (c) 2023 Gabor L Ugray
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

/* ** TODO
 * ===================
 * OK Save logged activity; restore real length limit
 * OK FULL behavior
 * OK Clear blinking confirmation
 * OK Actually clear
 * -- Actually chirp
 * -- Low energy mode > movement_le_inactivity_deadlines
 * -- Write in-comment documentation
 *
 */

#include <stdlib.h>
#include <string.h>
#include "activity_face.h"
#include "watch.h"
#include "watch_utility.h"

// ===========================================================================
// This part is semi-configurable: you can edit values here to customize you activity face
// In particular, with num_enabled_activities and enabled_activities you can choose a subset of the
//   activities that you want to see in your watch.
// You can also add new items to activity_names, but don't redefine or remove existing ones.

// If a logged activity is shorter than this, then it won't be added to log when it ends.
// This way scarce log slots are not taken up by aborted events that weren't real activities.
const uint16_t activity_min_length_sec = 300;

// Supported activities. ID of activity is index in this buffer
// W e should never change order or redefine items, only add new items when needed.
const char activity_names[][7] = {
    " bIKE ",
    "uuaLK ",
    "  rUn ",
    "  rOuu",
    "DAnCE ",
    "Suuinn",
    "ELLIP ",
    "SOCCEr",
    " FOOTb",
    "  SKI ",
    " bALL ",
};

// Number of currently enabled activities (size of enabled_activities).
const uint8_t num_enabled_activities = 3;

// Currently enabled activities. This makes picking on first subface easier: why show activities you personally never do.
const uint8_t enabled_activities[] = {0, 1, 2};

// End semi-configurable section
// ===========================================================================

// One logged activity
typedef struct __attribute__((__packed__)) {
    // Activity's start time
    watch_date_time start_time;

    // Total duration of activity, including time spend in paus
    uint16_t total_sec;

    // Number of seconds the activity was paused
    uint16_t pause_sec;

    // Type of activity (index in activity_names)
    uint8_t activity_type;

} activity_item_t;

// Size of (fixed) buffer to log activites. Takes up x9 bytes in SRAM if face is installed.
#define ACTIVITY_LOG_SZ 99

// Number of activities in buffer.
uint8_t activity_log_count = 0;

// Buffer with all logged activities.
activity_item_t activity_log_buffer[ACTIVITY_LOG_SZ];

// The face's different UI modes (views).
typedef enum {
    ACTM_CHOOSE = 0,
    ACTM_LOGGING,
    ACTM_PAUSED,
    ACTM_DONE,
    ACTM_CHIRP,
    ACTM_CHIRPING,
    ACTM_CLEAR,
    ACTM_CLEAR_CONFIRM,
    ACTM_CLEAR_DONE,
} activity_mode_t;

// The full state of the activity face
typedef struct {
    // Current mode (which secondary face, or ongoing operation like logging)
    activity_mode_t mode;

    // Index of currently selected activity in enabled_activities
    uint8_t type_ix;

    // Used for different things depending on mode
    // In ACTM_DONE: countdown for animation, before returning to start screen
    // In ACTM_LOGGING and ACTM_PAUSED: loops forever; value drives blinking colon and hour/minutes display at top
    // In ACTM_CHIRP and ACTM_CLEAR: loops; drives alternation between activity count and text
    uint8_t counter;

    // Start of currently logged activity, if any
    watch_date_time start_time;

    // Total paused seconds in current log
    uint16_t pause_sec;

    // Start of current pause, if we're in ACTM_PAUSED
    watch_date_time pause_start_time;

} activity_state_t;

#define ACTIVITY_BUF_SZ 14

// Temp buffer used for sprintf'ing content for the display.
char activity_buf[ACTIVITY_BUF_SZ];

static void _activity_clear_buffers() {
    // Clear activity buffer; 0xcd is good for diagnostics
    memset(activity_log_buffer, 0xcd, ACTIVITY_LOG_SZ * sizeof(activity_item_t));
    // Clear display buffer
    memset(activity_buf, 0, ACTIVITY_BUF_SZ);
}

void activity_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void)settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(activity_state_t));
        memset(*context_ptr, 0, sizeof(activity_state_t));
        // This happens only at boot
        _activity_clear_buffers();
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void activity_face_activate(movement_settings_t *settings, void *context) {
    (void)settings;
    activity_state_t *state = (activity_state_t *)context;

    state->mode = 0;
    movement_request_tick_frequency(2);
}

static void _activity_display_choice(activity_state_t *state) {
    watch_display_string("AC", 0);
    // If buffer is full: We say "FULL"
    if (activity_log_count >= ACTIVITY_LOG_SZ) {
        watch_display_string(" FULL ", 4);
    }
    // Otherwise, we show currently activity
    else {
        const char *name = activity_names[state->type_ix];
        watch_display_string((char *)name, 4);
    }
}

const uint8_t activity_anim_pixels[][2] = {
    {1, 4},  // TL
    {0, 5},  // BL
    {0, 6},  // BOT
    {1, 6},  // BR
    {2, 5},  // TR
    {2, 4},  // TOP
    // {2, 4}, // MID
};

static void _activity_display_duration(activity_state_t *state, uint32_t seconds_counted) {
    uint32_t seconds = seconds_counted - state->pause_sec;
    watch_duration_t duration = watch_utility_seconds_to_duration(seconds);

    // Under a minute: only seconds
    if (seconds < 60) {
        sprintf(activity_buf, "%02d", duration.seconds);
        watch_display_string(activity_buf, 8);
    }
    // Under 10 minutes: M:SS
    else if (seconds < 600) {
        sprintf(activity_buf, "%d%02d", duration.minutes, duration.seconds);
        watch_display_string(activity_buf, 7);
    }
    // Under an hour: MM:SS
    else if (seconds < 3600) {
        sprintf(activity_buf, "%02d%02d", duration.hours, duration.minutes, duration.seconds);
        watch_display_string(activity_buf, 6);
    }
    // Over an hour: H:MM:SS
    // (We never go to two-digit hours; stop at 8)
    else {
        sprintf(activity_buf, "%d%02d%02d", duration.hours, duration.minutes, duration.seconds);
        watch_display_string(activity_buf, 5);
    }

    // If we're over an hour: blink colon; LAP on
    if (duration.hours > 0) {
        watch_set_indicator(WATCH_INDICATOR_LAP);
        if ((state->counter % 2) == 0) {
            watch_set_colon();
        } else {
            watch_clear_colon();
        }
    }
    // Under an hour: blink LAP; colon off
    else {
        watch_clear_colon();
        if ((state->counter % 2) == 0) {
            watch_clear_indicator(WATCH_INDICATOR_LAP);
        } else {
            watch_set_indicator(WATCH_INDICATOR_LAP);
        }
    }
}

static void _activity_display_small_time(movement_settings_t *settings, activity_state_t *state, watch_date_time time) {
    uint8_t hour = time.unit.hour;
    if (!settings->bit.clock_mode_24h) {
        if (hour < 12)
            watch_clear_indicator(WATCH_INDICATOR_PM);
        else
            watch_set_indicator(WATCH_INDICATOR_PM);
        hour %= 12;
    }
    if ((state->counter % 16) < 6) {
        sprintf(activity_buf, "%02d", hour);
        watch_display_string(activity_buf, 0);
    } else {
        sprintf(activity_buf, "%02d", time.unit.minute);
        watch_display_string(activity_buf, 0);
    }
}

static void _activity_update_logging_screen(movement_settings_t *settings, activity_state_t *state) {
    watch_date_time now = watch_rtc_get_date_time();
    uint32_t now_timestamp = watch_utility_date_time_to_unix_time(now, 0);
    uint32_t start_timestamp = watch_utility_date_time_to_unix_time(state->start_time, 0);
    uint32_t seconds_counted = now_timestamp - start_timestamp;
    _activity_display_duration(state, seconds_counted);
    _activity_display_small_time(settings, state, now);
}

static void _activity_handle_tick(movement_settings_t *settings, activity_state_t *state) {
    // Display stopwatch-like duration while logging
    if (state->mode == ACTM_LOGGING) {
        ++state->counter;
        _activity_update_logging_screen(settings, state);
    }
    // While paused, just keep updating small time
    else if (state->mode == ACTM_PAUSED) {
        ++state->counter;
        watch_date_time now = watch_rtc_get_date_time();
        _activity_display_small_time(settings, state, now);
    }
    // Display countown animation, and exit face when down
    else if (state->mode == ACTM_DONE) {
        if (state->counter == 0)
            movement_move_to_face(0);
        else {
            uint8_t cd = state->counter % 6;
            watch_clear_pixel(activity_anim_pixels[cd][0], activity_anim_pixels[cd][1]);
            --state->counter;
            cd = state->counter % 6;
            watch_set_pixel(activity_anim_pixels[cd][0], activity_anim_pixels[cd][1]);
        }
    }
    // Chirp screen and clear screen: alternative between text and size of log
    else if (state->mode == ACTM_CHIRP || state->mode == ACTM_CLEAR) {
        ++state->counter;
        char *text = "CHIRP ";
        if (state->mode == ACTM_CLEAR) text = "CLEAR ";
        sprintf(activity_buf, "   %2d ", activity_log_count);
        if ((state->counter % 8) < 4)
            watch_display_string(text, 4);
        else
            watch_display_string(activity_buf, 4);
        // If clear screen and been hanging around for 15 seconds: return to choose
        // We are afraid of clear, it's very destructive
        if (state->mode == ACTM_CLEAR && state->counter > 30) {
            state->mode = ACTM_CHOOSE;
            _activity_display_choice(state);
        }
    }
    // Clear confirm: blink CLEAR
    else if (state->mode == ACTM_CLEAR_CONFIRM) {
        ++state->counter;
        if ((state->counter % 2) == 0)
            watch_display_string("CLEAR ", 4);
        else
            watch_display_string("      ", 4);
        if (state->counter > 30) {
            state->mode = ACTM_CHOOSE;
            _activity_display_choice(state);
        }
    }
    // Clear done: fill up zeroes, then return to choose screen
    else if (state->mode == ACTM_CLEAR_DONE) {
        ++state->counter;
        if (state->counter == 14) {
            state->mode = ACTM_CHOOSE;
            _activity_display_choice(state);
            return;
        }
        sprintf(activity_buf, "      ");
        uint8_t nZeros = state->counter / 2 + 1;
        if (nZeros > 6) nZeros = 6;
        for (uint8_t i = 0; i < nZeros; ++i) {
            activity_buf[i] = '0';
        }
        watch_display_string(activity_buf, 4);
    }
}

static void _activity_add_current_pause_sec(activity_state_t *state) {
    watch_date_time now = watch_rtc_get_date_time();
    uint32_t now_timestamp = watch_utility_date_time_to_unix_time(now, 0);
    uint32_t pause_start_timestamp = watch_utility_date_time_to_unix_time(state->pause_start_time, 0);
    uint32_t seconds_paused = now_timestamp - pause_start_timestamp;
    state->pause_sec += seconds_paused;
}

static void _activity_save_new(activity_state_t *state) {
    // Length of activity
    watch_date_time now = watch_rtc_get_date_time();
    uint32_t now_timestamp = watch_utility_date_time_to_unix_time(now, 0);
    uint32_t start_timestamp = watch_utility_date_time_to_unix_time(state->start_time, 0);
    uint32_t seconds_counted = now_timestamp - start_timestamp;

    // If shorter than minimum for log: don't save
    if (seconds_counted < activity_min_length_sec)
        return;

    // Sanity check about buffer length. This should never happen, but also we never want to overrun
    if (activity_log_count + 1 >= ACTIVITY_LOG_SZ)
        return;

    activity_item_t *itm = &activity_log_buffer[activity_log_count];
    itm->start_time = state->start_time;
    itm->total_sec = seconds_counted;
    itm->pause_sec = state->pause_sec;
    itm->activity_type = state->type_ix;
    ++activity_log_count;
}

static void _activity_alarm_long(activity_state_t *state) {
    // On choose face: start logging activity
    if (state->mode == ACTM_CHOOSE) {
        // If buffer is full: Ignore this long press
        if (activity_log_count >= ACTIVITY_LOG_SZ)
            return;
        // OK, we go ahead and start logging
        state->start_time = watch_rtc_get_date_time();
        state->pause_sec = 0;
        state->counter = -1;
        state->mode = ACTM_LOGGING;
        watch_clear_display();
    }
    // If logging or paused: end logging
    else if (state->mode == ACTM_LOGGING || state->mode == ACTM_PAUSED) {
        // If we're stopping from paused mode, add latest paused seconds
        _activity_add_current_pause_sec(state);
        _activity_save_new(state);
        // Go to DONE animation
        state->mode = ACTM_DONE;
        state->counter = 6 * 3;
        watch_clear_display();
        watch_display_string("AC   dONE ", 0);
    }
    // If clear: confirm (unless empty)
    else if (state->mode == ACTM_CLEAR) {
        if (activity_log_count == 0)
            return;
        state->mode = ACTM_CLEAR_CONFIRM;
        state->counter = -1;
    }
    // If clear confirm: do clear.
    else if (state->mode == ACTM_CLEAR_CONFIRM) {
        _activity_clear_buffers();
        activity_log_count = 0;
        state->mode = ACTM_CLEAR_DONE;
        state->counter = -1;
        watch_display_string("0     ", 4);
    }
}

static void _activity_alarm_short(movement_settings_t *settings, activity_state_t *state) {
    // If logging: pause
    if (state->mode == ACTM_LOGGING) {
        state->pause_start_time = watch_rtc_get_date_time();
        watch_display_string(" PAUSE", 4);
        watch_clear_indicator(WATCH_INDICATOR_LAP);
        state->mode = ACTM_PAUSED;
    }
    // If paused: Update paused seconds count and return to logging
    else if (state->mode == ACTM_PAUSED) {
        _activity_add_current_pause_sec(state);
        state->mode = ACTM_LOGGING;
        watch_display_string("      ", 4);
        _activity_update_logging_screen(settings, state);
    }
    // If choose face: move to chirp
    else if (state->mode == ACTM_CHOOSE) {
        state->mode = ACTM_CHIRP;
        state->counter = 0;
        watch_display_string("AC  CHIRP ", 0);
    }
    // If chirp face: move to clear
    else if (state->mode == ACTM_CHIRP) {
        state->mode = ACTM_CLEAR;
        state->counter = 0;
        watch_display_string("AC  CEAR ", 0);
    }
    // If clear face: return to choose face
    else if (state->mode == ACTM_CLEAR || state->mode == ACTM_CLEAR_CONFIRM) {
        state->mode = ACTM_CHOOSE;
        _activity_display_choice(state);
    }
}

bool activity_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    activity_state_t *state = (activity_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _activity_display_choice(state);
            break;
        case EVENT_TICK:
            _activity_handle_tick(settings, state);
            break;
        case EVENT_MODE_BUTTON_UP:
            if (state->mode != ACTM_LOGGING && state->mode != ACTM_PAUSED && state->mode != ACTM_CHIRPING) {
                movement_move_to_next_face();
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // In the choose face, LIGHT cycles through activities
            if (state->mode == ACTM_CHOOSE) {
                state->type_ix = (state->type_ix + 1) % num_enabled_activities;
                _activity_display_choice(state);
            }
            // While logging or paused, light is light
            else if (state->mode == ACTM_LOGGING || state->mode == ACTM_PAUSED) {
                movement_illuminate_led();
            }
            // Otherwise, we don't do light.
            break;
        case EVENT_ALARM_BUTTON_UP:
            _activity_alarm_short(settings, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            _activity_alarm_long(state);
            break;
        case EVENT_TIMEOUT:
            if (state->mode != ACTM_LOGGING && state->mode != ACTM_PAUSED) {
                movement_move_to_face(0);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            watch_start_tick_animation(500);
            break;
        default:
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void activity_face_resign(movement_settings_t *settings, void *context) {
    (void)settings;
    (void)context;

    // handle any cleanup before your watch face goes off-screen.
}
