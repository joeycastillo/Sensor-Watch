/*
 * MIT License
 *
 * Copyright (c) 2023 Hugo Chargois
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
#include "butterfly_game_face.h"

static char butterfly_shapes[][3] = {
    "[]", "][", "25", "52", "9e", "e9", "6a", "a6", "3E", "E3", "00", "HH", "88"
};

static int8_t single_beep[] = {BUZZER_NOTE_A7, 4, 0};
static int8_t round_win_melody[] = {
    BUZZER_NOTE_C6, 4,
    BUZZER_NOTE_E6, 4,
    BUZZER_NOTE_G6, 4,
    BUZZER_NOTE_C7, 12,
    0};
static int8_t round_lose_melody[] = {
    BUZZER_NOTE_E6, 4,
    BUZZER_NOTE_F6, 4,
    BUZZER_NOTE_D6SHARP_E6FLAT, 4,
    BUZZER_NOTE_C6, 12,
    0};
static int8_t game_win_melody[] = {
    BUZZER_NOTE_G6, 4,
    BUZZER_NOTE_A6, 4,
    BUZZER_NOTE_B6, 4,
    BUZZER_NOTE_C7, 12,
    BUZZER_NOTE_D7, 4,
    BUZZER_NOTE_E7, 4,
    BUZZER_NOTE_D7, 4,
    BUZZER_NOTE_C7, 12,
    BUZZER_NOTE_B6, 4,
    BUZZER_NOTE_C7, 4,
    BUZZER_NOTE_D7, 4,
    BUZZER_NOTE_G7, 24,
    0};

#define NUM_SHAPES (sizeof(butterfly_shapes) / sizeof(butterfly_shapes[0]))

#define POS_LEFT   4
#define POS_CENTER 6
#define POS_RIGHT  8

#define TICK_FREQ 8
#define TICKS_PER_SHAPE 8

#define PLAYER_1 0
#define PLAYER_2 1


// returns a random integer r with 0 <= r < max
static inline uint8_t _get_rand(uint8_t max) {
#if __EMSCRIPTEN__
    return rand() % max;
#else
    return arc4random_uniform(max);
#endif
}

/*
 * The game is built with a simple state machine where each state is called a
 * "screen". Each screen can draw on the display and handles events, including
 * the "activate" event, which is repurposed and sent whenever we move from one
 * screen to another via the _transition_to function. Basically it's a mini
 * movement inside movement.
 */
typedef bool (*screen_fn_t)(movement_event_t, butterfly_game_state_t*);

static screen_fn_t cur_screen_fn;

static bool _transition_to(screen_fn_t sf, butterfly_game_state_t *state) {
    movement_event_t ev = {EVENT_ACTIVATE, 0};
    cur_screen_fn = sf;
    return sf(ev, state);
}

static uint8_t _pick_wrong_shape(butterfly_game_state_t *state, bool skip_wrong_shape) {
    if (!skip_wrong_shape) {
        // easy case, we only need to skip over 1 shape: the correct shape
        uint8_t r = _get_rand(NUM_SHAPES-1);
        if (r >= state->correct_shape) {
            r++;
        }
        return r;
    } else {
        // a bit more complex, we need to skip over 2 shapes: the correct one
        // and the current wrong one
        uint8_t r = _get_rand(NUM_SHAPES-2);
        uint8_t i1, i2; // the 2 indices to skip over, with i1 < i2
        if (state->correct_shape < state->current_shape) {
            i1 = state->correct_shape;
            i2 = state->current_shape;
        } else {
            i1 = state->current_shape;
            i2 = state->correct_shape;
        }

        if (r >= i1) {
            r++;
        }
        if (r >= i2) {
            r++;
        }

        return r;
    }
}

static void _display_shape(uint8_t shape, uint8_t pos) {
    watch_display_string(butterfly_shapes[shape], pos);
}

static void _display_scores(butterfly_game_state_t *state) {
    char buf[] = " ";
    buf[0] = '0' + state->score_p1;
    watch_display_string(buf, 0);
    buf[0] = '0' + state->score_p2;
    watch_display_string(buf, 3);
}

static void _play_sound(butterfly_game_state_t *state, int8_t *seq) {
    if (state->sound) watch_buzzer_play_sequence(seq, NULL);
}

static bool _round_start_screen(movement_event_t event, butterfly_game_state_t *state);
static bool _reset_screen(movement_event_t event, butterfly_game_state_t *state);

static bool _game_win_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->ctr = 4 * TICK_FREQ;
            watch_clear_display();

            if (state->score_p1 >= state->goal_score) {
                watch_display_string("pl1  wins", 0);
            } else {
                watch_display_string("pl2  wins", 0);
            }
            _play_sound(state, game_win_melody);

            break;
        case EVENT_TICK:
            state->ctr--;
            if (state->ctr == 0) {
                return _transition_to(_reset_screen, state);
            }
            break;
    }
    return true;
}

static bool _round_win_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->ctr = TICK_FREQ;

            if (state->round_winner == PLAYER_1) {
                state->score_p1++;
            } else {
                state->score_p2++;
            }

            watch_clear_display();
            _display_scores(state);
            _display_shape(state->correct_shape, state->round_winner == PLAYER_1 ? POS_LEFT : POS_RIGHT);
            _play_sound(state, round_win_melody);
            break;
        case EVENT_TICK:
            state->ctr--;
            if (state->ctr == 0) {
                if (state->score_p1 >= state->goal_score || state->score_p2 >= state->goal_score) {
                    return _transition_to(_game_win_screen, state);
                }
                return _transition_to(_round_start_screen, state);
            }
            break;
    }
    return true;
}

static bool _round_lose_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->ctr = TICK_FREQ;

            if (state->round_winner == PLAYER_1) {
                if (state->score_p2 > 0) state->score_p2--;
            } else {
                if (state->score_p1 > 0) state->score_p1--;
            }

            _display_shape(state->correct_shape, POS_CENTER);
            _play_sound(state, round_lose_melody);
            break;
        case EVENT_TICK:
            if (--state->ctr == 0) {
                return _transition_to(_round_start_screen, state);
            }
            _display_shape(state->ctr%2 ? state->correct_shape : state->current_shape, POS_CENTER);
            break;

    }
    return true;
}

static bool _correct_shape_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _display_shape(state->correct_shape, POS_CENTER);
            _play_sound(state, single_beep);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            state->round_winner = PLAYER_1;
            return _transition_to(_round_win_screen, state);
        case EVENT_ALARM_BUTTON_DOWN:
            state->round_winner = PLAYER_2;
            return _transition_to(_round_win_screen, state);
    }
    return true;
}

static bool _wrong_shape_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->ctr = TICKS_PER_SHAPE;
            state->current_shape = _pick_wrong_shape(state, true);
            _display_shape(state->current_shape, POS_CENTER);
            _play_sound(state, single_beep);
            break;
        case EVENT_TICK:
            if (--state->ctr == 0) {
                if (--state->show_correct_shape_after == 0) {
                    return _transition_to(_correct_shape_screen, state);
                }
                return _transition_to(_wrong_shape_screen, state);
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            state->round_winner = PLAYER_2;
            return _transition_to(_round_lose_screen, state);
        case EVENT_ALARM_BUTTON_DOWN:
            state->round_winner = PLAYER_1;
            return _transition_to(_round_lose_screen, state);
    }
    return true;
}

static bool _first_wrong_shape_screen(movement_event_t event, butterfly_game_state_t *state) {
    // the first of the wrong shape screens is a bit different than the next
    // ones, for 2 reasons:
    // * we can pick any shape except one (the correct shape); whereas in the
    //   subsequent wrong shape screens, we also must not pick the same wrong
    //   shape as the last
    // * we don't act on the light/alarm button events; they would normally be
    //   a fail in a wrong shape screen, but in this case it may just be that
    //   the 2 players acknowledge the picked shape (in the previous screen) in
    //   quick succession, and we don't want the second player to immediately
    //   fail.
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->ctr = TICKS_PER_SHAPE;
            state->current_shape = _pick_wrong_shape(state, false);
            _display_shape(state->current_shape, POS_CENTER);
            _play_sound(state, single_beep);
            break;
        case EVENT_TICK:
            if (--state->ctr == 0) {
                return _transition_to(_wrong_shape_screen, state);
            }
            break;
    }
    return true;
}

static bool _round_start_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->correct_shape = _get_rand(NUM_SHAPES);
            state->show_correct_shape_after = _get_rand(10) + 1;
            watch_display_string("    -    -", 0);
            _display_scores(state);
            _display_shape(state->correct_shape, POS_CENTER);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
        case EVENT_ALARM_BUTTON_DOWN:
            watch_display_string("      ", 4);
            return _transition_to(_first_wrong_shape_screen, state);
    }
    return true;
}

static bool _goal_select_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_clear_display();
            state->goal_score = 6;
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            return _transition_to(_round_start_screen, state);
        case EVENT_ALARM_BUTTON_DOWN:
            state->goal_score += 3;
            if (state->goal_score > 9) state->goal_score = 3;
            break;
    }

    char buf[] = "GOaL  ";
    buf[5] = '0' + state->goal_score;
    watch_display_string(buf, 4);
    return true;
}

static bool _reset_screen(movement_event_t event, butterfly_game_state_t *state) {
    (void) event;

    state->score_p1 = 0;
    state->score_p2 = 0;

    return _transition_to(_goal_select_screen, state);
}

static bool _continue_select_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_clear_display();

            // no game in progress, start a new game
            if (state->score_p1 == 0 && state->score_p2 == 0) {
                return _transition_to(_goal_select_screen, state);
            }

            state->cont = false;
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if (state->cont) {
                return _transition_to(_round_start_screen, state);
            }
            return _transition_to(_reset_screen, state);
        case EVENT_ALARM_BUTTON_DOWN:
            state->cont = !state->cont;
            break;
    }

    if (state->cont) {
        watch_display_string("Cont y", 4);
    } else {
        watch_display_string("Cont n", 4);
    }
    return true;
}

static bool _sound_select_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_clear_display();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            return _transition_to(_continue_select_screen, state);
        case EVENT_ALARM_BUTTON_DOWN:
            state->sound = !state->sound;
            break;
    }

    if (state->sound) {
        watch_display_string("snd y", 5);
    } else {
        watch_display_string("snd n", 5);
    }
    return true;
}

static bool _splash_screen(movement_event_t event, butterfly_game_state_t *state) {
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->ctr = TICK_FREQ;

            watch_clear_display();
            watch_display_string("Btrfly", 4);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
        case EVENT_ALARM_BUTTON_DOWN:
            return _transition_to(_sound_select_screen, state);
        case EVENT_TICK:
            if (--state->ctr == 0) {
                return _transition_to(_sound_select_screen, state);
            }
            break;
    }
    return true;
}

void butterfly_game_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(butterfly_game_state_t));
        memset(*context_ptr, 0, sizeof(butterfly_game_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
#if __EMSCRIPTEN__
    // simulator only: seed the random number generator
    time_t t;
    srand((unsigned) time(&t));
#endif
}

void butterfly_game_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    movement_request_tick_frequency(TICK_FREQ);
}

bool butterfly_game_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    butterfly_game_state_t *state = (butterfly_game_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            return _transition_to(_splash_screen, state);
        case EVENT_TICK:
        case EVENT_LIGHT_BUTTON_DOWN:
        case EVENT_ALARM_BUTTON_DOWN:
            return (*cur_screen_fn)(event, state);
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            return true;
        default:
            return movement_default_loop_handler(event, settings);
    }
}

void butterfly_game_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

