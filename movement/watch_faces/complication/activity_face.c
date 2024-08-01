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
 * -- Additional power-saving optimizations
 */

#include <stdlib.h>
#include <string.h>
#include "activity_face.h"
#include "chirpy_tx.h"
#include "watch.h"
#include "watch_utility.h"

// ===========================================================================
// This part is configurable: you can edit values here to customize you activity face
// In particular, with num_enabled_activities and enabled_activities you can choose a subset of the
//   activities that you want to see in your watch.
// You can also add new items to activity_names, but don't redefine or remove existing ones.

// If a logged activity is shorter than this, then it won't be added to log when it ends.
// This way scarce log slots are not taken up by aborted events that weren't real activities.
static const uint16_t activity_min_length_sec = 60;

// Supported activities. ID of activity is index in this buffer
// W e should never change order or redefine items, only add new items when needed.
static const char activity_names[][7] = {
    " bIKE ",
    "uuaLK ",
    "  rUn ",
    "DAnCE ",
    " yOgA ",
    "CrOSS ",
    "Suuinn",
    "ELLIP ",
    "  gYnn",
    "  rOuu",
    "SOCCEr",
    " FOOTb",
    " bALL ",
    "  SKI ",
};

// Currently enabled activities. This makes picking on first subface easier: why show activities you personally never do.
static const uint8_t enabled_activities[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

// Number of currently enabled activities (size of enabled_activities).
static const uint8_t num_enabled_activities = sizeof(enabled_activities) / sizeof(uint8_t);

// End configurable section
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

#define MAX_ACTIVITY_SECONDS 28800 // 8 hours = 28800 sec

// Size of (fixed) buffer to log activites. Takes up x9 bytes in SRAM if face is installed.
#define ACTIVITY_LOG_SZ 99

// Number of activities in buffer.
static uint8_t activity_log_count = 0;

// Buffer with all logged activities.
static activity_item_t activity_log_buffer[ACTIVITY_LOG_SZ];

#define CHIRPY_PREFIX_LEN 2
// First two bytes chirped out, to identify transmission as from the activity face
static const uint8_t activity_chirpy_prefix[CHIRPY_PREFIX_LEN] = {0x27, 0x00};

// The face's different UI modes (views).
typedef enum {
    ACTM_CHOOSE = 0,
    ACTM_LOGGING,
    ACTM_PAUSED,
    ACTM_DONE,
    ACTM_LOGSIZE,
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
    // In ACTM_DONE: countdown for animation, before returning to start face
    // In ACTM_LOGGING and ACTM_PAUSED: drives blinking colon and alternating time display
    // In ACTM_LOGSIZE, ACTM_CLEAR: enables timeout return to choose screen
    uint16_t counter;

    // Start of currently logged activity, if any
    watch_date_time start_time;

    // Total seconds elapsed since logging started
    uint16_t curr_total_sec;

    // Total paused seconds in current log
    uint16_t curr_pause_sec;

    // Helps us handle 1/64 ticks during transmission; including countdown timer
    chirpy_tick_state_t chirpy_tick_state;

    // Used by chirpy encoder during transmission
    chirpy_encoder_state_t chirpy_encoder_state;

    // 0: Running normally
    // 1: In LE mode
    // 2: Just woke up from LE mode. Will go to 0 after ignoring ALARM_BUTTON_UP.
    uint8_t le_state;

} activity_state_t;

#define ACTIVITY_BUF_SZ 14

// Temp buffer used for sprintf'ing content for the display.
char activity_buf[ACTIVITY_BUF_SZ];

// Needed by _activity_get_next_byte to keep track of where we are in transmission
uint16_t *activity_seq_pos;

static void _activity_clear_buffers() {
    // Clear activity buffer; 0xcd is good for diagnostics
    memset(activity_log_buffer, 0xcd, ACTIVITY_LOG_SZ * sizeof(activity_item_t));
    // Clear display buffer
    memset(activity_buf, 0, ACTIVITY_BUF_SZ);
}

static void _activity_display_choice(activity_state_t *state);
static void _activity_update_logging_screen(movement_settings_t *settings, activity_state_t *state);
static uint8_t _activity_get_next_byte(uint8_t *next_byte);

void activity_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void)settings;
    (void)watch_face_index;
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
    (void)context;

    // Not using this function. Calling _activity_activate from the event handler.
    // That is what we get both when the face is shown upon navigation by MODE,
    // and when waking from low energy state.
}

// Called from the ACTIVATE event handler in the loop
static void _activity_activate(movement_settings_t *settings, activity_state_t *state) {
    // If waking from low-energy state and currently logging: update seconds values
    // Those are not up-to-date because ticks have not been coming
    if (state->le_state != 0 && state->mode == ACTM_LOGGING) {
        state->le_state = 2;
        watch_date_time now = watch_rtc_get_date_time();
        uint32_t now_timestamp = watch_utility_date_time_to_unix_time(now, 0);
        uint32_t start_timestamp = watch_utility_date_time_to_unix_time(state->start_time, 0);
        uint32_t total_seconds = now_timestamp - start_timestamp;
        state->curr_total_sec = total_seconds;
        _activity_update_logging_screen(settings, state);
    }
    // Regular activation: start from defaults
    else {
        state->le_state = 0;
        state->mode = 0;
        state->type_ix = 0;
        _activity_display_choice(state);
    }
}

static void _activity_display_choice(activity_state_t *state) {
    watch_display_string("AC", 0);
    // If buffer is full: We say "FULL"
    if (activity_log_count >= ACTIVITY_LOG_SZ) {
        watch_display_string(" FULL ", 4);
    }
    // Otherwise, we show currently activity
    else {
        uint8_t activity_ix = enabled_activities[state->type_ix];
        const char *name = activity_names[activity_ix];
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

static void _activity_update_logging_screen(movement_settings_t *settings, activity_state_t *state) {
    watch_duration_t duration;

    watch_display_string("AC  ", 0);

    // If we're in LE state: per-minute update is special
    if (state->le_state == 1) {
        watch_date_time now = watch_rtc_get_date_time();
        uint32_t now_timestamp = watch_utility_date_time_to_unix_time(now, 0);
        uint32_t start_timestamp = watch_utility_date_time_to_unix_time(state->start_time, 0);
        uint32_t total_seconds = now_timestamp - start_timestamp;
        duration = watch_utility_seconds_to_duration(total_seconds);
        sprintf(activity_buf, " %d%02d  ", duration.hours, duration.minutes);
        watch_display_string(activity_buf, 4);
        watch_set_colon();
        watch_set_indicator(WATCH_INDICATOR_LAP);
        watch_clear_indicator(WATCH_INDICATOR_PM);
        watch_clear_indicator(WATCH_INDICATOR_24H);
        return;
    }

    // Show elapsed time, or PAUSE
    if ((state->counter % 5) < 3) {
        watch_set_indicator(WATCH_INDICATOR_LAP);
        watch_clear_indicator(WATCH_INDICATOR_PM);
        watch_clear_indicator(WATCH_INDICATOR_24H);
        if (state->mode == ACTM_PAUSED) {
            watch_display_string(" PAUSE", 4);
            watch_clear_colon();
        } else {
            duration = watch_utility_seconds_to_duration(state->curr_total_sec);
            // Under 10 minutes: M:SS
            if (state->curr_total_sec < 600) {
                sprintf(activity_buf, "   %01d%02d", duration.minutes, duration.seconds);
                watch_display_string(activity_buf, 4);
                watch_clear_colon();
            }
            // Under an hour: MM:SS
            else if (state->curr_total_sec < 3600) {
                sprintf(activity_buf, "  %02d%02d", duration.minutes, duration.seconds);
                watch_display_string(activity_buf, 4);
                watch_clear_colon();
            }
            // Over an hour: H:MM:SS
            // (We never go to two-digit hours; stop at 8)
            else {
                sprintf(activity_buf, " %d%02d%02d", duration.hours, duration.minutes, duration.seconds);
                watch_display_string(activity_buf, 4);
                watch_set_colon();
            }
        }
    }
    // Briefly, show time without seconds
    else {
        bool set_leading_zero = false;
        watch_clear_indicator(WATCH_INDICATOR_LAP);
        watch_date_time now = watch_rtc_get_date_time();
        uint8_t hour = now.unit.hour;
        if (!settings->bit.clock_mode_24h) {
            watch_clear_indicator(WATCH_INDICATOR_24H);
            if (hour < 12)
                watch_clear_indicator(WATCH_INDICATOR_PM);
            else
                watch_set_indicator(WATCH_INDICATOR_PM);
            hour %= 12;
            if (hour == 0) hour = 12;
        } else {
            watch_clear_indicator(WATCH_INDICATOR_PM);
            if (!settings->bit.clock_24h_leading_zero)
                watch_set_indicator(WATCH_INDICATOR_24H);
            else if (hour < 10)
                set_leading_zero = true;
        }
        sprintf(activity_buf, "%2d%02d  ", hour, now.unit.minute);
        watch_set_colon();
        watch_display_string(activity_buf, 4);
        if (set_leading_zero)
            watch_display_string("0", 4);
    }
}

static void _activity_quit_chirping() {
    watch_clear_indicator(WATCH_INDICATOR_BELL);
    watch_set_buzzer_off();
    movement_request_tick_frequency(1);
}

static void _activity_chirp_tick_transmit(void *context) {
    activity_state_t *state = (activity_state_t *)context;

    uint8_t tone = chirpy_get_next_tone(&state->chirpy_encoder_state);
    // Transmission over?
    if (tone == 255) {
        _activity_quit_chirping();
        state->mode = ACTM_CHIRP;
        state->counter = 0;
        watch_display_string("AC  CHIRP ", 0);
        return;
    }
    uint16_t period = chirpy_get_tone_period(tone);
    watch_set_buzzer_period(period);
    watch_set_buzzer_on();
}

static void _activity_chirp_tick_countdown(void *context) {
    activity_state_t *state = (activity_state_t *)context;

    // Countdown over: start actual broadcast
    if (state->chirpy_tick_state.seq_pos == 8 * 3) {
        state->chirpy_tick_state.tick_compare = 3;
        state->chirpy_tick_state.tick_count = 2;  // tick_compare - 1, so it starts immediately
        state->chirpy_tick_state.seq_pos = 0;
        state->chirpy_tick_state.tick_fun = _activity_chirp_tick_transmit;
        return;
    }
    // Sound or turn off buzzer
    if ((state->chirpy_tick_state.seq_pos % 8) == 0) {
        watch_set_buzzer_period(NotePeriods[BUZZER_NOTE_A5]);
        watch_set_buzzer_on();
        if (state->chirpy_tick_state.seq_pos == 0) {
            watch_display_string(" ---  ", 4);
        } else if (state->chirpy_tick_state.seq_pos == 8) {
            watch_display_string(" --", 5);
        } else if (state->chirpy_tick_state.seq_pos == 16) {
            watch_display_string("  -", 5);
        }
    } else if ((state->chirpy_tick_state.seq_pos % 8) == 1) {
        watch_set_buzzer_off();
    }
    ++state->chirpy_tick_state.seq_pos;
}

static uint8_t _activity_get_next_byte(uint8_t *next_byte) {
    uint16_t num_bytes = 2 + activity_log_count * sizeof(activity_item_t);
    uint16_t pos = *activity_seq_pos;

    // Init counter
    if (pos == 0) {
        sprintf(activity_buf, "%3d", activity_log_count);
        watch_display_string(activity_buf, 5);
    }

    if (pos == num_bytes) {
        return 0;
    }
    // Two-byte prefix
    if (pos < 2) {
        (*next_byte) = activity_chirpy_prefix[pos];
    }
    // Data
    else {
        pos -= 2;
        uint16_t ix = pos / sizeof(activity_item_t);
        const activity_item_t *itm = &activity_log_buffer[ix];
        uint16_t ofs = pos % sizeof(activity_item_t);

        // Update counter when starting new item
        if (ofs == 0) {
            sprintf(activity_buf, "%3d", activity_log_count - ix);
            watch_display_string(activity_buf, 5);
        }

        // Do this the hard way, byte by byte, to avoid high/low endedness issues
        // Higher order bytes first, is our serialization format
        uint8_t val;
        // watch_date_time start_time;
        // uint16_t total_sec;
        // uint16_t pause_sec;
        // uint8_t activity_type;
        if (ofs == 0)
            val = (itm->start_time.reg & 0xff000000) >> 24;
        else if (ofs == 1)
            val = (itm->start_time.reg & 0x00ff0000) >> 16;
        else if (ofs == 2)
            val = (itm->start_time.reg & 0x0000ff00) >> 8;
        else if (ofs == 3)
            val = (itm->start_time.reg & 0x000000ff);
        else if (ofs == 4)
            val = (itm->total_sec & 0xff00) >> 8;
        else if (ofs == 5)
            val = (itm->total_sec & 0x00ff);
        else if (ofs == 6)
            val = (itm->pause_sec & 0xff00) >> 8;
        else if (ofs == 7)
            val = (itm->pause_sec & 0x00ff);
        else
            val = itm->activity_type;
        (*next_byte) = val;
    }
    ++(*activity_seq_pos);
    return 1;
}

static void _activity_finish_logging(activity_state_t *state) {
    // Save this activity
    // If shorter than minimum for log: don't save
    // Sanity check about buffer length. This should never happen, but also we never want to overrun by error
    if (state->curr_total_sec >= activity_min_length_sec && activity_log_count + 1 < ACTIVITY_LOG_SZ) {
        activity_item_t *itm = &activity_log_buffer[activity_log_count];
        itm->start_time = state->start_time;
        itm->total_sec = state->curr_total_sec;
        itm->pause_sec = state->curr_pause_sec;
        itm->activity_type = state->type_ix;
        ++activity_log_count;
    }

    // Go to DONE animation
    // TODO: Not in LE mode
    state->mode = ACTM_DONE;
    watch_clear_indicator(WATCH_INDICATOR_LAP);
    movement_request_tick_frequency(2);
    state->counter = 6 * 1;
    watch_clear_display();
    watch_display_string("AC   dONE ", 0);
}

static void _activity_handle_tick(movement_settings_t *settings, activity_state_t *state) {
    // Display stopwatch-like duration while logging, alternating with time
    if (state->mode == ACTM_LOGGING || state->mode == ACTM_PAUSED) {
        ++state->counter;
        ++state->curr_total_sec;
        if (state->mode == ACTM_PAUSED)
            ++state->curr_pause_sec;
        // If we've reached max activity length: finish logging
        if (state->curr_total_sec == MAX_ACTIVITY_SECONDS) {
            _activity_finish_logging(state);
        }
        // Still logging: refresh display
        else {
            _activity_update_logging_screen(settings, state);
        }
    }
    // Display countown animation, and exit face when down
    else if (state->mode == ACTM_DONE) {
        if (state->counter == 0) {
            movement_move_to_face(0);
            movement_request_tick_frequency(1);
        }
        else {
            uint8_t cd = state->counter % 6;
            watch_clear_pixel(activity_anim_pixels[cd][0], activity_anim_pixels[cd][1]);
            --state->counter;
            cd = state->counter % 6;
            watch_set_pixel(activity_anim_pixels[cd][0], activity_anim_pixels[cd][1]);
        }
    }
    // Log size, chirp, clear: return to choose after some time
    else if (state->mode == ACTM_LOGSIZE || state->mode == ACTM_CHIRP || state->mode == ACTM_CLEAR) {
        ++state->counter;
        // Leave Log Size after 20 seconds
        // Leave Clear after only 10: this is danger zone, we don't like hanging around here
        // Leave Chirp after 2 minutes: most likely need to the time to fiddle with mic & Chirpy RX on the computer
        uint16_t timeout = 20;
        if (state->mode == ACTM_CLEAR) timeout = 10;
        else if (state->mode == ACTM_CHIRP) timeout = 120;
        if (state->counter > timeout) {
            state->mode = ACTM_CHOOSE;
            _activity_display_choice(state);
        }
    }
    // Chirping
    else if (state->mode == ACTM_CHIRPING) {
        ++state->chirpy_tick_state.tick_count;
        if (state->chirpy_tick_state.tick_count == state->chirpy_tick_state.tick_compare) {
            state->chirpy_tick_state.tick_count = 0;
            state->chirpy_tick_state.tick_fun(state);
        }
    }
    // Clear confirm: blink CLEAR
    else if (state->mode == ACTM_CLEAR_CONFIRM) {
        ++state->counter;
        if ((state->counter % 2) == 0)
            watch_display_string("CLEAR ", 4);
        else
            watch_display_string("      ", 4);
        if (state->counter > 12) {
            state->mode = ACTM_CHOOSE;
            _activity_display_choice(state);
            movement_request_tick_frequency(1);
        }
    }
    // Clear done: fill up zeroes, then return to choose screen
    else if (state->mode == ACTM_CLEAR_DONE) {
        ++state->counter;
        // Animation done
        if (state->counter == 7) {
            state->mode = ACTM_CHOOSE;
            _activity_display_choice(state);
            movement_request_tick_frequency(1);
            return;
        }
        // Display current state of animation
        sprintf(activity_buf, "      ");
        uint8_t nZeros = state->counter + 1;
        if (nZeros > 6) nZeros = 6;
        for (uint8_t i = 0; i < nZeros; ++i) {
            activity_buf[i] = '0';
        }
        watch_display_string(activity_buf, 4);
    }
}

static void _activity_alarm_long(movement_settings_t *settings, activity_state_t *state) {
    // On choose face: start logging activity
    if (state->mode == ACTM_CHOOSE) {
        // If buffer is full: Ignore this long press
        if (activity_log_count >= ACTIVITY_LOG_SZ)
            return;
        // OK, we go ahead and start logging
        state->start_time = watch_rtc_get_date_time();
        state->curr_total_sec = 0;
        state->curr_pause_sec = 0;
        state->counter = -1;
        state->mode = ACTM_LOGGING;
        watch_set_indicator(WATCH_INDICATOR_LAP);
        _activity_update_logging_screen(settings, state);
    }
    // If logging or paused: end logging
    else if (state->mode == ACTM_LOGGING || state->mode == ACTM_PAUSED) {
        _activity_finish_logging(state);
    }
    // If chirp: kick off chirping
    else if (state->mode == ACTM_CHIRP) {
        // Set up our tick handling for countdown beeps
        activity_seq_pos = &state->chirpy_tick_state.seq_pos;
        state->chirpy_tick_state.tick_compare = 8;
        state->chirpy_tick_state.tick_count = 7;  // tick_compare - 1, so it starts immediately
        state->chirpy_tick_state.seq_pos = 0;
        state->chirpy_tick_state.tick_fun = _activity_chirp_tick_countdown;
        // Set up chirpy encoder
        chirpy_init_encoder(&state->chirpy_encoder_state, _activity_get_next_byte);
        // Show bell; switch to 64/sec ticks
        watch_set_indicator(WATCH_INDICATOR_BELL);
        movement_request_tick_frequency(64);
        state->mode = ACTM_CHIRPING;
    }
    // If clear: confirm (unless empty)
    else if (state->mode == ACTM_CLEAR) {
        if (activity_log_count == 0)
            return;
        state->mode = ACTM_CLEAR_CONFIRM;
        state->counter = -1;
        movement_request_tick_frequency(4);
    }
    // If clear confirm: do clear.
    else if (state->mode == ACTM_CLEAR_CONFIRM) {
        _activity_clear_buffers();
        activity_log_count = 0;
        state->mode = ACTM_CLEAR_DONE;
        state->counter = -1;
        watch_display_string("0     ", 4);
        movement_request_tick_frequency(2);
    }
}

static void _activity_alarm_short(movement_settings_t *settings, activity_state_t *state) {
    // In the choose face, short ALARM cycles through activities
    if (state->mode == ACTM_CHOOSE) {
        state->type_ix = (state->type_ix + 1) % num_enabled_activities;
        _activity_display_choice(state);
    }
    // If logging: pause
    else if (state->mode == ACTM_LOGGING) {
        state->mode = ACTM_PAUSED;
        state->counter = 0;
        _activity_update_logging_screen(settings, state);
    }
    // If paused: Update paused seconds count and return to logging
    else if (state->mode == ACTM_PAUSED) {
        state->mode = ACTM_LOGGING;
        state->counter = 0;
        _activity_update_logging_screen(settings, state);
    }
    // If chirping: stoppit
    else if (state->mode == ACTM_CHIRPING) {
        _activity_quit_chirping();
        state->mode = ACTM_CHIRP;
        state->counter = 0;
        watch_display_string("AC  CHIRP ", 0);
    }
}

static void _activity_light_short(activity_state_t *state) {
    // If choose face: move to log size
    if (state->mode == ACTM_CHOOSE) {
        state->mode = ACTM_LOGSIZE;
        state->counter = 0;
        sprintf(activity_buf, "AC  L#g%3d", activity_log_count);
        watch_display_string(activity_buf, 0);
    }
    // If log size face: move to chirp
    else if (state->mode == ACTM_LOGSIZE) {
        state->mode = ACTM_CHIRP;
        state->counter = 0;
        watch_display_string("AC  CHIRP ", 0);
    }
    // If chirp face: move to clear
    else if (state->mode == ACTM_CHIRP) {
        state->mode = ACTM_CLEAR;
        state->counter = 0;
        watch_display_string("AC  CLEAR ", 0);
    }
    // If clear face: return to choose face
    else if (state->mode == ACTM_CLEAR || state->mode == ACTM_CLEAR_CONFIRM) {
        state->mode = ACTM_CHOOSE;
        _activity_display_choice(state);
        movement_request_tick_frequency(1);
    }
    // While logging or paused, light is light
    else if (state->mode == ACTM_LOGGING || state->mode == ACTM_PAUSED) {
        movement_illuminate_led();
    }
    // Otherwise, we don't do light.
}

bool activity_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    activity_state_t *state = (activity_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _activity_activate(settings, state);
            break;
        case EVENT_TICK:
            _activity_handle_tick(settings, state);
            break;
        case EVENT_MODE_BUTTON_UP:
            if (state->mode != ACTM_LOGGING && state->mode != ACTM_PAUSED && state->mode != ACTM_CHIRPING) {
                movement_request_tick_frequency(1);
                movement_move_to_next_face();
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            _activity_light_short(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            // We also receive ALARM press that woke us up from LE state
            // Don't want to act on that as if it were a real button press for us
            if (state->le_state != 2)
                _activity_alarm_short(settings, state);
            else
                state->le_state = 0;
            break;
        case EVENT_ALARM_LONG_PRESS:
            _activity_alarm_long(settings, state);
            break;
        case EVENT_TIMEOUT:
            if (state->mode != ACTM_LOGGING && state->mode != ACTM_PAUSED &&
                state->mode != ACTM_CHIRP && state->mode != ACTM_CHIRPING) {
                movement_request_tick_frequency(1);
                movement_move_to_face(0);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            state->le_state = 1;
            // If we're in paused logging mode: let's lose this activity. Pause is not meant for over an hour.
            if (state->mode == ACTM_PAUSED) {
                // When waking, face will revert to default screen
                state->mode = ACTM_CHOOSE;
                watch_display_string("AC  SLEEP ", 0);
                watch_clear_colon();
                watch_clear_indicator(WATCH_INDICATOR_LAP);
                watch_clear_indicator(WATCH_INDICATOR_PM);
            }
            else {
                _activity_update_logging_screen(settings, state);
                watch_start_tick_animation(500);
            }
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    // Return true if the watch can enter standby mode. False needed when chirping.
    if (state->mode == ACTM_CHIRPING)
        return false;
    else
        return true;
}

void activity_face_resign(movement_settings_t *settings, void *context) {
    (void)settings;
    (void)context;

    // Face should only ever temporarily request a higher frequency, so by the time we're resigning,
    // this should not be needed. But we don't want an error to create a situation that drains the battery.
    // Rather do this defensively here.
    movement_request_tick_frequency(1);
}
