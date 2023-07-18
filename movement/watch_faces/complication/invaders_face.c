/*
 * MIT License
 *
 * Copyright (c) 2023 Andreas Nebinger
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

// Emulator only: need time() to seed the random number generator
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include "watch_private_display.h"
#include "invaders_face.h"
#include "face_settings.h"

#define INVADERS_FACE_WAVES_PER_STAGE 9 // number of waves per stage (there are two stages)
#define INVADERS_FACE_WAVE_INVADERS 16  // number of invaders attacking per wave

static const uint8_t _defense_lines_segdata[3][2] = {{2, 12}, {2, 11}, {0, 11}};
static const uint8_t _bonus_points_segdata[4][2] = {{2, 7}, {2, 8}, {2, 9}, {0, 10}};
static const uint8_t _bonus_points_helper[] = {1, 5, 9, 11, 15, 19, 21, 25, 29};

static const int8_t _sound_seq_game_start[] = {BUZZER_NOTE_A6, 1, BUZZER_NOTE_A7, 3, -2, 1, BUZZER_NOTE_REST, 10, BUZZER_NOTE_A6, 1, BUZZER_NOTE_A7, 3, -2, 1, 0};
static const int8_t _sound_seq_shot_hit[] = {BUZZER_NOTE_A6, 1, BUZZER_NOTE_A7, 2, 0};
static const int8_t _sound_seq_shot_miss[] = {BUZZER_NOTE_A7, 1, 0};
static const int8_t _sound_seq_ufo_hit[] = {BUZZER_NOTE_A6, 1, BUZZER_NOTE_A7, 2, -2, 1, 0};
static const int8_t _sound_seq_def_gone[] = {BUZZER_NOTE_A6, 1, BUZZER_NOTE_A7, 3, -2, 3, BUZZER_NOTE_REST, 40, BUZZER_NOTE_A6, 1, BUZZER_NOTE_A7, 3, -2, 4, 0};
static const int8_t _sound_seq_next_wave[] = {BUZZER_NOTE_A6, 2, BUZZER_NOTE_A7, 2, BUZZER_NOTE_REST, 8, BUZZER_NOTE_A6, 2, BUZZER_NOTE_A7, 2, -2, 1,
                                              BUZZER_NOTE_REST, 32, 
                                              BUZZER_NOTE_A6, 2, BUZZER_NOTE_A7, 2, BUZZER_NOTE_REST, 8, BUZZER_NOTE_A6, 2, BUZZER_NOTE_A7, 2, -2, 1, 0};
static const int8_t _sound_seq_game_over[] = {BUZZER_NOTE_A6, 1, BUZZER_NOTE_A7, 3, -2, 11, 0};

typedef enum {
    invaders_state_activated,
    invaders_state_pre_game,
    invaders_state_playing,
    invaders_state_in_wave_break,
    invaders_state_pre_next_wave,
    invaders_state_next_wave,
    invaders_state_game_over
} invaders_current_state_t;

typedef struct {
    bool ufo_next : 1;                  // indicates whether next invader is a ufo
    bool inv_checking : 1;              // flag to indicate whether we are currently moving invaders (to prevent race conditions)
    bool suspend_buttons : 1;           // used while playing the game over sequence to prevent involuntary immediate restarts
} invaders_signals_t;

static int8_t _invaders[6];             // array of current invaders values (-1 = empty, 10 = ufo)
static uint8_t _wave_invaders[INVADERS_FACE_WAVE_INVADERS]; // all invaders for the current wave. (Predefined to save cpu cycles when playing.)
static invaders_current_state_t _current_state;
static uint8_t _defense_lines;          // number of defense lines which have been broken in the current wave
static uint8_t _aim;                    // current "aim" digit
static uint8_t _invader_idx;            // index of next invader attacking in current wave (0 to 15)
static uint8_t _wave_position;          // current position of first invader. When > 6 the defense is broken
static uint8_t _wave_tick_freq;         // number of ticks passing until the next invader is inserted
static uint8_t _ticks;                  // counts the ticks
static uint8_t _bonus_countdown;        // ticks countdown until the bonus point indicator is cleared
static uint8_t _waves;                  // counts the waves (_wave_tick_freq decreases slowly depending on _wave value)
static uint8_t _shots_in_wave;          // number of shots in current wave. If 30 is reached, the game is over
static uint8_t _invaders_shot;          // number of sucessfully shot invaders in current wave
static uint8_t _invaders_shot_sum;      // current sum of invader digits shot (needed to determine if a ufo is coming)
static invaders_signals_t _signals;     // holds severals flags
static uint16_t _score;                 // score of the current game

/// @brief return a random number. 0 <= return_value < num_values
static inline uint8_t _get_rand_num(uint8_t num_values) {
#if __EMSCRIPTEN__
    return rand() % num_values;
#else
    return arc4random_uniform(num_values);
#endif
}

/// @brief callback function to re-enable light and alarm buttons after playing a sound sequence
static inline void _resume_buttons() {
    _signals.suspend_buttons = false;
}

/// @brief play a sound sequence if the game is in beepy mode
static inline void _play_sequence(invaders_state_t *state, int8_t *sequence) {
    if (state->sound_on) watch_buzzer_play_sequence((int8_t *)sequence, NULL);
}

/// @brief draw the remaining defense lines
static void _display_defense_lines() {
    watch_display_character(' ', 1);
    for (uint8_t i = 0; i < 3 - _defense_lines; i++) watch_set_pixel(_defense_lines_segdata[i][0], _defense_lines_segdata[i][1]);
}

/** @brief draw label followed by the given score value 
 * @param label string displayed in the upper left corner
 * @param score score to display
 */
static void _display_score(char *label, uint16_t score) {
    watch_display_character(label[0], 0);
    watch_display_character(label[1], 1);
    char buf[10];
    sprintf(buf, "  %06d", (score * 10));
    watch_display_string(buf, 2);
}

/// @brief draw an invader at the given position
static inline void _display_invader(int8_t invader, uint8_t position) {
    switch (invader) {
    case 10:
        watch_display_character('n', position);
        break;
    case -1:
        watch_display_character(' ', position);
        break;
    default:
        watch_display_character(invader + 48, position);
        break;
    }
}

/// @brief game over: show score and set state
static void _game_over(invaders_state_t *state) {
    _display_score("GO", _score);
    _current_state = invaders_state_game_over;
    movement_request_tick_frequency(1);
    _signals.suspend_buttons = true;
    if (state->sound_on) watch_buzzer_play_sequence((int8_t *)_sound_seq_game_over, _resume_buttons);
    // save current score to highscore, if applicable
    if (_score > state->highscore) state->highscore = _score;
}

/// @brief initialize the current wave
static void _init_wave() {
    uint8_t i;
    if (_current_state == invaders_state_in_wave_break) {
        _invader_idx = _invaders_shot;
    } else {
        _invader_idx = _invaders_shot = _invaders_shot_sum = _defense_lines = _shots_in_wave = 0;
    }
    // pre-fill invaders
    for (i = _invader_idx; i < INVADERS_FACE_WAVE_INVADERS; i++) _wave_invaders[i] = _get_rand_num(10);
    // init invaders field
    for (i = 1; i < 6; i++) _invaders[i] = -1;
    _invaders[0] = _wave_invaders[_invader_idx];
    _wave_position = _aim = _bonus_countdown = 0;
    _signals.ufo_next = _signals.inv_checking = _signals.suspend_buttons = false;
    _current_state = invaders_state_playing;
    // determine wave speed
    _wave_tick_freq = 6 - ((_waves % INVADERS_FACE_WAVES_PER_STAGE) + 1) / 2;
    if (_waves >= INVADERS_FACE_WAVES_PER_STAGE) _wave_tick_freq--;
    // clear display
    watch_display_string("        ", 2);
    watch_display_character('0', 0);
    _display_defense_lines();
    // draw first invader
    watch_display_character(_wave_invaders[_invader_idx] + 48, 9);
}

/** @brief move invaders and add a new one, if necessary
 * @returns true, if invaders have reached position 6, false otherwise
 */
static bool _move_invaders() {
    if (_wave_position == 5) return true;
    _signals.inv_checking = true;
    if (_invaders[_wave_position] >= 0) _wave_position++;
    int8_t i;
    // move invaders
    for (i = _wave_position; i > 0; i--) _invaders[i] = _invaders[i - 1];
    if (_invader_idx < INVADERS_FACE_WAVE_INVADERS - 1) {
        // add invader
        _invader_idx++;
        if (_signals.ufo_next) {
            _invaders[0] = 10;
            _signals.ufo_next = false;
        } else {
            _invaders[0] = _wave_invaders[_invader_idx];
        }
    } else {
        // just add an empty invader slot
        _invaders[0] = -1;
    }
    // update display
    for (i = 0; i <= _wave_position; i++) {
        _display_invader(_invaders[i], 9 - i);
    }
    _signals.inv_checking = false;
    return false;
}

void invaders_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(invaders_state_t));
        memset(*context_ptr, 0, sizeof(invaders_state_t));
        invaders_state_t *state = (invaders_state_t *)*context_ptr;
        if (!face_data_init("invaders_face", 0, state, sizeof(invaders_state_t), NULL, NULL)) {
            // default: sound on
            state->sound_on = true;
        } 
    }
#if __EMSCRIPTEN__
    // simulator only: seed the randon number generator
    time_t t;
    srand((unsigned) time(&t));
#endif
}

void invaders_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    _current_state = invaders_state_activated;
    _signals.suspend_buttons = false;
}

bool invaders_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    invaders_state_t *state = (invaders_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // show highscore
            _display_score("GA", state->highscore);
            break;
        case EVENT_TICK:
            _ticks++;
            switch (_current_state) {
                case invaders_state_in_wave_break:
                case invaders_state_pre_game:
                case invaders_state_next_wave:
                    // wait 2 secs to start the first round
                    if (_ticks >= 2) {
                        _ticks = 0;
                        _init_wave();
                        _current_state = invaders_state_playing;
                        movement_request_tick_frequency(4);
                    }
                    break;
                case invaders_state_playing:
                    // game is playing
                    if (_ticks >= _wave_tick_freq) {
                        _ticks = 0;
                        if (_move_invaders()) {
                            // invaders broke through
                            if (_defense_lines < 2) {
                                // start current wave over
                                _defense_lines++;
                                _display_defense_lines();
                                _display_score("GA", _score);
                                _current_state = invaders_state_in_wave_break;
                                movement_request_tick_frequency(1);
                                _play_sequence(state, (int8_t *)_sound_seq_def_gone);
                            } else {
                                // game over
                                _game_over(state);
                            }
                        }
                    }
                    // handle bonus points indicators
                    if (_bonus_countdown) {
                        _bonus_countdown--;
                        if (!_bonus_countdown) {
                            watch_display_character(' ', 2);
                            watch_display_character(' ', 3);
                        }
                    }
                    break;
                case invaders_state_pre_next_wave:
                    if (_ticks >= 3) {
                        // switch to next wave
                        _ticks = 0;
                        movement_request_tick_frequency(1);
                        _display_score("GA", _score);
                        watch_set_pixel(1, 9);
                        watch_display_character((_waves % INVADERS_FACE_WAVES_PER_STAGE) + 49, 3);
                        _current_state = invaders_state_next_wave;
                        _waves++;
                        if (_waves == INVADERS_FACE_WAVES_PER_STAGE * 2) _waves = 0;
                        _play_sequence(state, (int8_t *)_sound_seq_next_wave);
                    }
                default:
                    break;
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if (!_signals.suspend_buttons) {
                if (_current_state == invaders_state_playing) {
                    // cycle the aim
                    _aim = (_aim + 1) % 11;
                    _display_invader(_aim, 0);
                } else if (_current_state == invaders_state_activated || _current_state == invaders_state_game_over) {
                    // just illuminate the LED
                    movement_illuminate_led();
                }
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if ((_current_state == invaders_state_activated || _current_state == invaders_state_game_over) && !_signals.suspend_buttons) {
                // switch between beepy and silent mode
                state->sound_on = !state->sound_on;
                watch_buzzer_play_note(BUZZER_NOTE_A7, state->sound_on ? 65 : 25);
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            if (!_signals.suspend_buttons) {
                switch (_current_state) {
                    case invaders_state_game_over:
                    case invaders_state_activated:
                        // initialize the game
                        _waves = 0;
                        _score = 0;
                        movement_request_tick_frequency(1);
                        _ticks = 0;
                        _current_state = invaders_state_pre_game;
                        _play_sequence(state, (int8_t *)_sound_seq_game_start);
                        break;
                    case invaders_state_playing: {
                        // "shoot"
                        _shots_in_wave++;
                        if (_shots_in_wave == 30) {
                            // max number of shots reached: game over
                            _game_over(state);
                        } else {
                            // wait if we are currently deleting an invader
                            while (_signals.inv_checking);
                            // proceed
                            _signals.inv_checking = true;
                            bool skip = false;
                            for (int8_t i = _wave_position; i >= 0 && !skip; i--) {
                                // if (_invaders[i] == -1) break;
                                if (_invaders[i] == _aim) {
                                    // invader is shot
                                    skip = true;
                                    _invaders_shot++;
                                    _play_sequence(state, _aim == 10 ? (int8_t *)_sound_seq_ufo_hit : (int8_t *)_sound_seq_shot_hit);
                                    if (_invaders_shot == INVADERS_FACE_WAVE_INVADERS) {
                                        // last invader shot: wave sucessfully completed
                                        watch_display_character(' ', 9 - _wave_position);
                                        _ticks = 0;
                                        _current_state = invaders_state_pre_next_wave;
                                        _signals.inv_checking = false;
                                    } else {
                                        // check for ufo appearance
                                        if (_aim && _aim < 10) {
                                            _invaders_shot_sum = (_invaders_shot_sum + _aim) % 10;
                                            if (_invaders_shot_sum == 0) _signals.ufo_next = true;
                                        }
                                        // remove invader
                                        if (_wave_position == 0 || i == 5) {
                                            _invaders[i] = -1;
                                        } else {
                                            for (uint8_t j = i; j < _wave_position; j++) {
                                                _invaders[j] = _invaders[j + 1];
                                                _display_invader(_invaders[j], 9 - j);
                                            }
                                        }
                                        watch_display_character(' ', 9 - _wave_position);
                                        if (_wave_position) _wave_position--;
                                        // update score
                                        if (_aim == 10) {
                                            // ufo shot. The original game uses a ridiculously complicated scoring system here...
                                            uint8_t bonus_points = 0;
                                            uint8_t j;
                                            for (j = 0; j < sizeof(_bonus_points_helper) && !bonus_points; j++) {
                                                if (_shots_in_wave == _bonus_points_helper[j]) {
                                                    bonus_points = 30;
                                                } else if (_shots_in_wave - 1 == _bonus_points_helper[j]) {
                                                    bonus_points = 20;
                                                }
                                            }
                                            if (!bonus_points) bonus_points = 10;
                                            bonus_points += (6 - i);
                                            if ((_waves >= INVADERS_FACE_WAVES_PER_STAGE) && i) bonus_points += (6 - i);
                                            _score += bonus_points;
                                            // represent bonus points by bars
                                            for (j = 0; j < (bonus_points / 10); j++) watch_set_pixel(_bonus_points_segdata[j][0], _bonus_points_segdata[j][1]);
                                            _bonus_countdown = 9;
                                        } else {
                                            // regular invader
                                            _score += (6 - _wave_position) * (_waves >= INVADERS_FACE_WAVES_PER_STAGE ? 2 : 1);
                                        }
                                    }
                                }
                            }
                            if (!skip) _play_sequence(state, (int8_t *)_sound_seq_shot_miss);
                            _signals.inv_checking = false;
                        }
                        break;
                    }    
                    default:
                        break;
                }
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
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

void invaders_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    invaders_state_t *state = (invaders_state_t *)context;
    _current_state = invaders_state_game_over;
    // save current score to highscore, if applicable
    if (_score > state->highscore) state->highscore = _score;
    // check if data needs to be saved
    face_data_save(state);
}

