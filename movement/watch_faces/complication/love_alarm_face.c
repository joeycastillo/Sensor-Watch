/*
 * MIT License
 *
 * Copyright (c) 2026 Stebbs
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
#include <stdio.h>
#include "love_alarm_face.h"
#include "watch.h"

// "The Gambler" by fun. - opening piano riff (22 notes)
// Key: Bb major, Time: 6/8, Tempo: 140 BPM
// Eighth note = ~9 ticks at 64Hz (143ms)
static const int8_t _gambler_melody[] = {
    // Bb-D-F
    BUZZER_NOTE_A4SHARP_B4FLAT, 9,   // Bb4
    BUZZER_NOTE_D5, 9,               // D5
    BUZZER_NOTE_F5, 9,               // F5

    // A-D-F
    BUZZER_NOTE_A4, 9,               // A4
    BUZZER_NOTE_D5, 9,               // D5
    BUZZER_NOTE_F5, 9,               // F5

    // G-Bb-D
    BUZZER_NOTE_G4, 9,               // G4
    BUZZER_NOTE_A4SHARP_B4FLAT, 9,   // Bb4
    BUZZER_NOTE_D5, 9,               // D5

    // F-A-C
    BUZZER_NOTE_F4, 9,               // F4
    BUZZER_NOTE_A4, 9,               // A4
    BUZZER_NOTE_C5, 9,               // C5

    // Eb-G-Bb (Eb because key of Bb major)
    BUZZER_NOTE_D4SHARP_E4FLAT, 9,   // Eb4
    BUZZER_NOTE_G4, 9,               // G4
    BUZZER_NOTE_A4SHARP_B4FLAT, 9,   // Bb4

    // F-A-C
    BUZZER_NOTE_F4, 9,               // F4
    BUZZER_NOTE_A4, 9,               // A4
    BUZZER_NOTE_C5, 9,               // C5

    // Bb-D-A-Bb (ending phrase)
    BUZZER_NOTE_A4SHARP_B4FLAT, 9,   // Bb4
    BUZZER_NOTE_D5, 9,               // D5
    BUZZER_NOTE_A4, 9,               // A4
    BUZZER_NOTE_A4SHARP_B4FLAT, 14,  // Bb4 (longer, end of phrase)

    BUZZER_NOTE_REST, 16,

    // Repeat once more
   // -46, 1,

    // End
    0
};

// Love animation frames - sparkles and pulsing hearts
// Uses 6 characters for main display (positions 4-9)
// Using: * (sparkle), . (dot), o (circle/heart), @ (full bright)
static const char* love_anim_frames[] = {
    "  oo  ",  // two hearts center
    " o  o ",  // hearts apart
    "o    o",  // hearts far
    " o  o ",  // coming back
    "  oo  ",  // together
    " @@@@ ",  // glow!
    "@@@@@@",  // bright burst
    " @@@@ ",  // fade
    "  oo  ",  // hearts
    " *  * ",  // sparkle
    "*    *",  // twinkle out
    " *  * ",  // twinkle
    "  **  ",  // center sparkle
    " *  * ",  // expand
    "      ",  // pause
    "  oo  ",  // hearts return
};
#define NUM_LOVE_FRAMES 16
#define MELODY_LOOPS 2

static love_alarm_state_t *_active_state = NULL;

static void _love_alarm_display(movement_settings_t *settings, love_alarm_state_t *state, uint8_t subsecond) {
    char buf[11];

    if (state->alarm_playing) {
        // Show love animation with "LA" at top
        sprintf(buf, "LA  %s", love_anim_frames[state->anim_frame % NUM_LOVE_FRAMES]);
        watch_display_string(buf, 0);
        return;
    }

    // Normal display: "LO" "VE" then time (LOVE displays as LOUE on 7-segment)
    uint8_t h = state->hour;
    if (!settings->bit.clock_mode_24h) {
        if (h >= 12) {
            watch_set_indicator(WATCH_INDICATOR_PM);
            h %= 12;
        } else {
            watch_clear_indicator(WATCH_INDICATOR_PM);
        }
        if (h == 0) h = 12;
    } else {
        watch_set_indicator(WATCH_INDICATOR_24H);
    }

    sprintf(buf, "LA  %2d%02d  ", h, state->minute);

    // Blink current setting field
    if (state->is_setting && (subsecond % 2) && !state->quick_ticks) {
        if (state->setting_state == 1) {
            // Blink hour
            buf[4] = buf[5] = ' ';
        } else if (state->setting_state == 2) {
            // Blink minute
            buf[6] = buf[7] = ' ';
        }
    }

    watch_display_string(buf, 0);

    // Show signal indicator if alarm is enabled
    if (state->enabled) {
        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    }
}

static void _melody_finished_callback(void) {
    if (_active_state != NULL) {
        _active_state->melody_loops++;
        if (_active_state->melody_loops < MELODY_LOOPS) {
            // Play again
            watch_buzzer_play_sequence((int8_t *)_gambler_melody, _melody_finished_callback);
        } else {
            // Done playing
            _active_state->alarm_playing = false;
            _active_state->melody_loops = 0;
        }
    }
}

void love_alarm_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(love_alarm_state_t));
        love_alarm_state_t *state = (love_alarm_state_t *)*context_ptr;
        memset(state, 0, sizeof(love_alarm_state_t));
        state->hour = 12;  // Default to noon
        state->minute = 0;
        state->enabled = false;
        state->alarm_handled_minute = -1;
    }
}

void love_alarm_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    love_alarm_state_t *state = (love_alarm_state_t *)context;
    _active_state = state;
    watch_set_colon();
}

void love_alarm_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    love_alarm_state_t *state = (love_alarm_state_t *)context;
    state->is_setting = false;
    state->quick_ticks = false;
    _active_state = NULL;
    movement_request_tick_frequency(1);
}

bool love_alarm_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    love_alarm_state_t *state = (love_alarm_state_t *)context;

    if (!state->enabled) return false;

    watch_date_time now = watch_rtc_get_date_time();

    // Don't fire more than once per minute
    if (state->alarm_handled_minute == now.unit.minute) return false;

    if (state->hour == now.unit.hour && state->minute == now.unit.minute) {
        state->alarm_handled_minute = now.unit.minute;
        return true;
    }

    // Reset handled minute when we're past the alarm time
    // This ensures the alarm can fire again next time
    state->alarm_handled_minute = -1;
    return false;
}

bool love_alarm_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    love_alarm_state_t *state = (love_alarm_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _love_alarm_display(settings, state, event.subsecond);
            break;

        case EVENT_TICK:
            if (state->alarm_playing) {
                // Advance animation
                state->anim_frame = (state->anim_frame + 1) % NUM_LOVE_FRAMES;
            } else if (state->quick_ticks) {
                // Fast increment
                if (state->setting_state == 1) {
                    state->hour = (state->hour + 1) % 24;
                } else if (state->setting_state == 2) {
                    state->minute = (state->minute + 1) % 60;
                }
            }
            _love_alarm_display(settings, state, event.subsecond);
            break;

        case EVENT_LIGHT_BUTTON_UP:
            if (state->alarm_playing) {
                // Stop alarm
                watch_buzzer_abort_sequence();
                state->alarm_playing = false;
                state->melody_loops = 0;
                movement_request_tick_frequency(1);
            } else if (!state->is_setting) {
                // Enter setting mode
                state->is_setting = true;
                state->setting_state = 1;  // Start with hour
                movement_request_tick_frequency(4);
            } else {
                // Cycle to next setting
                state->setting_state++;
                if (state->setting_state > 2) {
                    // Done setting
                    state->is_setting = false;
                    state->setting_state = 0;
                    movement_request_tick_frequency(1);
                }
            }
            _love_alarm_display(settings, state, event.subsecond);
            break;

        case EVENT_LIGHT_LONG_PRESS:
            if (state->is_setting) {
                // Exit setting mode
                state->is_setting = false;
                state->setting_state = 0;
                state->quick_ticks = false;
                movement_request_tick_frequency(1);
            } else {
                // Enter setting mode
                state->is_setting = true;
                state->setting_state = 1;
                movement_request_tick_frequency(4);
            }
            _love_alarm_display(settings, state, event.subsecond);
            break;

        case EVENT_ALARM_BUTTON_UP:
            if (state->alarm_playing) {
                // Stop alarm
                watch_buzzer_abort_sequence();
                state->alarm_playing = false;
                state->melody_loops = 0;
                movement_request_tick_frequency(1);
            } else if (state->is_setting) {
                state->quick_ticks = false;
                // Increment current setting
                if (state->setting_state == 1) {
                    state->hour = (state->hour + 1) % 24;
                } else if (state->setting_state == 2) {
                    state->minute = (state->minute + 1) % 60;
                }
                // Auto-enable when setting
                state->enabled = true;
            }
            _love_alarm_display(settings, state, event.subsecond);
            break;

        case EVENT_ALARM_LONG_PRESS:
            if (!state->is_setting && !state->alarm_playing) {
                // Toggle enabled
                state->enabled = !state->enabled;
            } else if (state->is_setting) {
                // Start quick ticks
                state->quick_ticks = true;
                movement_request_tick_frequency(8);
            }
            _love_alarm_display(settings, state, event.subsecond);
            break;

        case EVENT_ALARM_LONG_UP:
            if (state->quick_ticks) {
                state->quick_ticks = false;
                movement_request_tick_frequency(4);
            }
            break;

        case EVENT_BACKGROUND_TASK:
            // Alarm triggered!
            _active_state = state;  // Set so callback works even if face not active
            state->alarm_playing = true;
            state->anim_frame = 0;
            state->melody_loops = 0;
            movement_request_tick_frequency(4);  // For animation

            // Play melody
            watch_buzzer_play_sequence((int8_t *)_gambler_melody, _melody_finished_callback);
            break;

        case EVENT_TIMEOUT:
            if (!state->alarm_playing) {
                movement_move_to_face(0);
            }
            break;

        case EVENT_LIGHT_BUTTON_DOWN:
            // Don't illuminate LED when in setting mode
            break;

        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}
