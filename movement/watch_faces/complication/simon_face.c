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
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "simon_face.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Emulator only: need time() to seed the random number generator
#if __EMSCRIPTEN__
#include <time.h>
#endif

static char _simon_display_buf[12];
static uint8_t _timer;
static uint16_t _delay_beep;
static uint16_t _timeout;
static uint8_t _secSub;

static inline uint8_t _simon_get_rand_num(uint8_t num_values) {
#if __EMSCRIPTEN__
    return rand() % num_values;
#else
    return arc4random_uniform(num_values);
#endif
}

static void _simon_clear_display(simon_state_t *state) {
    if (state->playing_state == SIMON_NOT_PLAYING) {
        watch_display_string("          ", 0);
    } else {
        sprintf(_simon_display_buf, "  %2d      ", state->sequence_length);
        watch_display_string(_simon_display_buf, 0);
    }
}

static void _simon_not_playing_display(simon_state_t *state) {
    _simon_clear_display(state);

    sprintf(_simon_display_buf, "SI  %d", state->best_score);
    if (!state->soundOff)
        watch_set_indicator(WATCH_INDICATOR_BELL);
    else
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    if (!state->lightOff)
        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    else
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    watch_display_string(_simon_display_buf, 0);
    switch (state->mode)
    {
    case SIMON_MODE_EASY:
        watch_display_string("E", 9);
        break;
    case SIMON_MODE_HARD:
        watch_display_string("H", 9);
        break;
    default:
        break;
    }
}

static void _simon_reset(simon_state_t *state) {
    state->playing_state = SIMON_NOT_PLAYING;
    state->listen_index = 0;
    state->sequence_length = 0;
    _simon_not_playing_display(state);
}


static void _simon_display_note(SimonNote note, simon_state_t *state) {
    char *ndtemplate = NULL;

    switch (note) {
        case SIMON_LED_NOTE:
            ndtemplate = "LI%2d      ";
            break;
        case SIMON_ALARM_NOTE:
            ndtemplate = "  %2d    AL";
            break;
        case SIMON_MODE_NOTE:
            ndtemplate = "  %2dDE    ";
            break;
        case SIMON_WRONG_NOTE:
            ndtemplate = "OH  NOOOOO";
    }

    sprintf(_simon_display_buf, ndtemplate, state->sequence_length);
    watch_display_string(_simon_display_buf, 0);
}

static void _simon_play_note(SimonNote note, simon_state_t *state, bool skip_rest) {
    _simon_display_note(note, state);
    switch (note) {
        case SIMON_LED_NOTE:
            if (!state->lightOff) watch_set_led_yellow();
            if (state->soundOff)
                delay_ms(_delay_beep);
            else
                watch_buzzer_play_note(BUZZER_NOTE_D3, _delay_beep);
            break;
        case SIMON_MODE_NOTE:
            if (!state->lightOff) watch_set_led_red();
            if (state->soundOff)
                delay_ms(_delay_beep);
            else
               watch_buzzer_play_note(BUZZER_NOTE_E4, _delay_beep);
            break;
        case SIMON_ALARM_NOTE:
            if (!state->lightOff) watch_set_led_green();
            if (state->soundOff)
                delay_ms(_delay_beep);
            else
               watch_buzzer_play_note(BUZZER_NOTE_C3, _delay_beep);
            break;
        case SIMON_WRONG_NOTE:
            if (state->soundOff)
                delay_ms(800);
            else
               watch_buzzer_play_note(BUZZER_NOTE_A1, 800);
            break;
    }
    watch_set_led_off();

    if (note != SIMON_WRONG_NOTE) {
        _simon_clear_display(state);
        if (!skip_rest) {
            watch_buzzer_play_note(BUZZER_NOTE_REST, (_delay_beep * 2)/3);
        }
    }
}


static void _simon_setup_next_note(simon_state_t *state) {
    if (state->sequence_length > state->best_score) {
        state->best_score = state->sequence_length;
    }

    _simon_clear_display(state);
    state->playing_state = SIMON_TEACHING;
    state->sequence[state->sequence_length] = _simon_get_rand_num(3) + 1;
    state->sequence_length = state->sequence_length + 1;
    state->teaching_index = 0;
    state->listen_index = 0;
}

static void _simon_listen(SimonNote note, simon_state_t *state) {
    if (state->sequence[state->listen_index] == note) {
        _simon_play_note(note, state, true);
        state->listen_index++;
        _timer = 0;

        if (state->listen_index == state->sequence_length) {
            state->playing_state = SIMON_READY_FOR_NEXT_NOTE;
        }
    } else {
        _simon_play_note(SIMON_WRONG_NOTE, state, true);
        _simon_reset(state);
    }
}

static void _simon_begin_listening(simon_state_t *state) {
    state->playing_state = SIMON_LISTENING_BACK;
    state->listen_index = 0;
}

static void _simon_change_speed(simon_state_t *state){
      switch (state->mode)
  {
  case SIMON_MODE_HARD:
        _delay_beep = DELAY_FOR_TONE_MS / 2;
        _secSub = SIMON_FACE_FREQUENCY / 2;
        _timeout = (TIMER_MAX * SIMON_FACE_FREQUENCY) / 2;
    break;
  default:
        _delay_beep = DELAY_FOR_TONE_MS;
        _secSub = SIMON_FACE_FREQUENCY;
        _timeout = TIMER_MAX * SIMON_FACE_FREQUENCY;
    break;
  }
}

void simon_face_setup(movement_settings_t *settings, uint8_t watch_face_index,
        void **context_ptr) {
    (void)settings;
    (void)watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(simon_state_t));
        memset(*context_ptr, 0, sizeof(simon_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens
        // only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch
    // wakes from deep sleep.
#if __EMSCRIPTEN__
    // simulator only: seed the randon number generator
    time_t t;
    srand((unsigned)time(&t));
#endif
}

void simon_face_activate(movement_settings_t *settings, void *context) {
  (void) settings;
  (void) context;
  simon_state_t *state = (simon_state_t *)context;
  _simon_change_speed(state);
  movement_request_tick_frequency(SIMON_FACE_FREQUENCY);
   _timer = 0;
}

bool simon_face_loop(movement_event_t event, movement_settings_t *settings,
        void *context) {
    simon_state_t *state = (simon_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            _simon_reset(state);
            break;
        case EVENT_TICK:
            if (state->playing_state == SIMON_LISTENING_BACK && state->mode != SIMON_MODE_EASY)
            {
                _timer++;
                if(_timer >= (_timeout)){
                    _timer = 0;
                    _simon_play_note(SIMON_WRONG_NOTE, state, true);
                    _simon_reset(state);
                }
            }
            else if (state->playing_state == SIMON_TEACHING && event.subsecond  == 0) {
                SimonNote note = state->sequence[state->teaching_index];
                // if this is the final note in the sequence, don't play the rest to let
                // the player jump in faster
                _simon_play_note(note, state, state->teaching_index == (state->sequence_length - 1));
                state->teaching_index++;

                if (state->teaching_index == state->sequence_length) {
                    _simon_begin_listening(state);
                }
            }
            else if (state->playing_state == SIMON_READY_FOR_NEXT_NOTE && (event.subsecond % _secSub)  == 0) {
                _timer = 0;
                _simon_setup_next_note(state);
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->playing_state == SIMON_NOT_PLAYING) {
                state->lightOff = !state->lightOff;
                _simon_not_playing_display(state);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->playing_state == SIMON_NOT_PLAYING) {
                state->soundOff = !state->soundOff;
                _simon_not_playing_display(state);
                if (!state->soundOff)
                    watch_buzzer_play_note(BUZZER_NOTE_D3, _delay_beep);
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (state->playing_state == SIMON_NOT_PLAYING) {
                state->sequence_length = 0;
                watch_clear_indicator(WATCH_INDICATOR_BELL);
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                _simon_setup_next_note(state);
            } else if (state->playing_state == SIMON_LISTENING_BACK) {
                _simon_listen(SIMON_LED_NOTE, state);
            }
            break;
        case EVENT_MODE_LONG_PRESS:
            if (state->playing_state == SIMON_NOT_PLAYING) {
                movement_move_to_face(0);
            } else {
                state->playing_state = SIMON_NOT_PLAYING;
                _simon_reset(state);
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            if (state->playing_state == SIMON_NOT_PLAYING) {
                movement_move_to_next_face();
            } else if (state->playing_state == SIMON_LISTENING_BACK) {
                _simon_listen(SIMON_MODE_NOTE, state);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (state->playing_state == SIMON_LISTENING_BACK) {
                _simon_listen(SIMON_ALARM_NOTE, state);
            }
            else if (state->playing_state == SIMON_NOT_PLAYING){
                state->mode = (state->mode + 1) % SIMON_MODE_TOTAL;
                _simon_change_speed(state);
                _simon_not_playing_display(state);
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void simon_face_resign(movement_settings_t *settings, void *context) {
    (void)settings;
    (void)context;
    watch_set_led_off();
    watch_set_buzzer_off();
}
