/*
 * MIT License
 *
 * Copyright (c) 2023 Jeremy O'Brien
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

#include "smallchesslib.h"

#include "smallchess_face.h"
#include "watch.h"

#define PIECE_LIST_END_MARKER 0xff

int8_t cpu_done_beep[] = {BUZZER_NOTE_C5, 5, BUZZER_NOTE_C6, 5, BUZZER_NOTE_C7, 5, 0};

static void smallchess_init_board(smallchess_face_state_t *state) {
    SCL_gameInit((SCL_Game *)state->game, 0);
    memset(state->moveable_pieces, 0xff, sizeof(state->moveable_pieces));
    memset(state->moveable_dests, 0xff, sizeof(state->moveable_dests));
}

void smallchess_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(smallchess_face_state_t));
        memset(*context_ptr, 0, sizeof(smallchess_face_state_t));

        /* now alloc/init the game board */
        smallchess_face_state_t *state = (smallchess_face_state_t *)*context_ptr;
        state->game = malloc(sizeof(SCL_Game));
        smallchess_init_board(*context_ptr);
    }
}

void smallchess_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

static void _smallchess_calc_moveable_pieces(smallchess_face_state_t *state) {
    int moveable_pieces_idx = 0;
    SCL_Game *game = (SCL_Game *)state->game;
    for (int i = 0; i < SCL_BOARD_SQUARES; ++i) {
        if (game->board[i] != '.' &&
                SCL_pieceIsWhite(game->board[i]) == SCL_boardWhitesTurn(game->board)) {
            SCL_SquareSet moveable_pieces = SCL_SQUARE_SET_EMPTY;
            SCL_boardGetMoves(game->board, i, moveable_pieces);
            if (SCL_squareSetSize(moveable_pieces) != 0) {
                state->moveable_pieces[moveable_pieces_idx] = i;
                moveable_pieces_idx++;
            }
        }
    }
    state->moveable_pieces[moveable_pieces_idx] = PIECE_LIST_END_MARKER;
    state->moveable_pieces_idx = 0;
}

static void _smallchess_make_ai_move(smallchess_face_state_t *state) {
    char ai_from_str[3] = {0};
    char ai_to_str[3] = {0};
    uint8_t rep_from, rep_to;
    char ai_prom;

    watch_clear_display();
    watch_start_character_blink('C', 100);
    SCL_gameGetRepetiotionMove(state->game, &rep_from, &rep_to);

#ifndef __EMSCRIPTEN__
    hri_oscctrl_write_OSC16MCTRL_FSEL_bf(OSCCTRL, OSCCTRL_OSC16MCTRL_FSEL_16_Val);
#endif
    SCL_getAIMove(state->game, 3, 0, 0, SCL_boardEvaluateStatic, NULL, 0, rep_from, rep_to, &state->ai_from_square, &state->ai_to_square, &ai_prom);
#ifndef __EMSCRIPTEN__
    hri_oscctrl_write_OSC16MCTRL_FSEL_bf(OSCCTRL, OSCCTRL_OSC16MCTRL_FSEL_4_Val);
#endif

    SCL_gameMakeMove(state->game, state->ai_from_square, state->ai_to_square, ai_prom);
    watch_stop_blink();

    watch_buzzer_play_sequence(cpu_done_beep, NULL);

    /* cache the move as a string for SHOW_CPU_MOVE state */
    SCL_squareToString(state->ai_from_square, ai_from_str);
    SCL_squareToString(state->ai_to_square, ai_to_str);
    snprintf(state->last_move_str, sizeof(state->last_move_str), " %s-%s", ai_from_str, ai_to_str);

    /* now cache the list of legal pieces we can move */
    _smallchess_calc_moveable_pieces(state);
}

static char _smallchess_make_lowercase(char c) {
    if (c < 0x61)
        return c + 0x20;

    return c;
}

static void _smallchess_get_endgame_string(smallchess_face_state_t *state, char *buf, uint8_t len) {
    uint8_t endgame_state = ((SCL_Game *)state->game)->state;
    uint16_t ply = ((SCL_Game *)state->game)->ply;

    switch (endgame_state) {
        case SCL_GAME_STATE_WHITE_WIN:
            snprintf(buf, len, "Wh%2dm&ate ", ply);
            break;
        case SCL_GAME_STATE_BLACK_WIN:
            snprintf(buf, len, "bL%2dm&ate ", ply);
            break;
        case SCL_GAME_STATE_DRAW:
        case SCL_GAME_STATE_DRAW_STALEMATE:
        case SCL_GAME_STATE_DRAW_REPETITION:
        case SCL_GAME_STATE_DRAW_50:
        case SCL_GAME_STATE_DRAW_DEAD:
            snprintf(buf, len, "  %2d Drauu", ply);
            break;
        default:
            snprintf(buf, len, "  %2d Error", ply);
            break;
    }
}

static void _smallchess_face_update_lcd(smallchess_face_state_t *state) {
    uint8_t start_square;
    uint8_t end_square;
    char start_coord[3] = {0};
    char end_coord[3] = {0};
    char buf[14] = {0};

    uint16_t ply = ((SCL_Game *)state->game)->ply;

    switch (state->state) {
        case SMALLCHESS_MENU_RESUME:
            snprintf(buf, sizeof(buf), "SC%2dResume", ply);
            break;
        case SMALLCHESS_MENU_UNDO:
            snprintf(buf, sizeof(buf), "SC%2d Undo ", ply);
            break;
        case SMALLCHESS_MENU_SHOW_LAST_MOVE:
            snprintf(buf, sizeof(buf), "SC%2dShLast", ply);
            break;
        case SMALLCHESS_MENU_NEW_WHITE:
            snprintf(buf, sizeof(buf), "Wh%2dStart ", ply);
            break;
        case SMALLCHESS_MENU_NEW_BLACK:
            snprintf(buf, sizeof(buf), "bL%2dStart ", ply);
            break;
        case SMALLCHESS_SHOW_CPU_MOVE:
        case SMALLCHESS_SHOW_LAST_MOVE:
            snprintf(buf,
                    sizeof(buf),
                    "%c %2d%s",
                    _smallchess_make_lowercase(((SCL_Game *)state->game)->board[state->ai_to_square]),
                    ply,
                    state->last_move_str);

            break;
        case SMALLCHESS_SELECT_PIECE:
            if (((SCL_Game *)state->game)->state != SCL_GAME_STATE_PLAYING) {
                _smallchess_get_endgame_string(state, buf, sizeof(buf));
                break;
            }
            start_square = state->moveable_pieces[state->moveable_pieces_idx];
            SCL_squareToString(start_square, start_coord);
            snprintf(buf,
                    sizeof(buf),
                    "%c %2d %s-  ",
                    _smallchess_make_lowercase(((SCL_Game *)state->game)->board[start_square]),
                    ply + 1,
                    start_coord);
            break;
        case SMALLCHESS_SELECT_DEST:
            start_square = state->moveable_pieces[state->moveable_pieces_idx];
            SCL_squareToString(start_square, start_coord);
            end_square = state->moveable_dests[state->moveable_dests_idx];
            SCL_squareToString(end_square, end_coord);
            snprintf(buf,
                    sizeof(buf),
                    "%c %2d %s-%s",
                    _smallchess_make_lowercase(((SCL_Game *)state->game)->board[start_square]),
                    ply + 1,
                    start_coord,
                    end_coord);
            break;
        default:
            break;
    }

    watch_display_string(buf, 0);
}

static void _smallchess_select_main_menu_subitem(smallchess_face_state_t *state) {
    char from_str[3] = {0};
    char to_str[3] = {0};
    char prom;

    switch (state->state) {
        case SMALLCHESS_MENU_RESUME:
            state->state = SMALLCHESS_SELECT_PIECE;
            break;
        case SMALLCHESS_MENU_UNDO:
            /* undo twice to undo the CPU's move and our move */
            SCL_gameUndoMove((SCL_Game *)state->game);
            SCL_gameUndoMove((SCL_Game *)state->game);
            /* and re-calculate the moveable pieces for this new state */
            _smallchess_calc_moveable_pieces(state);
            break;
        case SMALLCHESS_MENU_NEW_WHITE:
            SCL_gameInit((SCL_Game *)state->game, 0);
            _smallchess_calc_moveable_pieces(state);
            state->state = SMALLCHESS_SELECT_PIECE;
            break;
        case SMALLCHESS_MENU_NEW_BLACK:
            SCL_gameInit((SCL_Game *)state->game, 0);
            /* force a move since black is playing */
            _smallchess_make_ai_move(state);
            state->state = SMALLCHESS_SHOW_CPU_MOVE;
            break;
        case SMALLCHESS_MENU_SHOW_LAST_MOVE:
            /* fetch the move */
            SCL_recordGetMove(((SCL_Game *)state->game)->record, ((SCL_Game *)state->game)->ply - 1, &state->ai_from_square, &state->ai_to_square, &prom);
            SCL_squareToString(state->ai_from_square, from_str);
            SCL_squareToString(state->ai_to_square, to_str);
            snprintf(state->last_move_str, sizeof(state->last_move_str), " %s-%s", from_str, to_str);
            state->state = SMALLCHESS_SHOW_LAST_MOVE;
            break;
        default:
            break;
    }
}

static void _smallchess_handle_select_piece_button_event(smallchess_face_state_t *state, movement_event_t event) {
    SCL_SquareSet moveable_dests = SCL_SQUARE_SET_EMPTY;

    /* back to main menu on any event when game ends */
    if (((SCL_Game *)state->game)->state != SCL_GAME_STATE_PLAYING) {
        state->state = SMALLCHESS_MENU_RESUME;
        return;
    }

    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_UP:
            // check for no moves possible state (shouldn't happen but this will prevent weirdness)
            if (state->moveable_pieces[0] == PIECE_LIST_END_MARKER) {
                return;
            }

            state->moveable_pieces_idx += 1;
            if (state->moveable_pieces_idx >= NUM_ELEMENTS(state->moveable_pieces)) {
                state->moveable_pieces_idx = 0;
            }

            if (state->moveable_pieces[state->moveable_pieces_idx] == PIECE_LIST_END_MARKER) {
                state->moveable_pieces_idx = 0;
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // check for no moves possible state (shouldn't happen but this will prevent weirdness)
            if (state->moveable_pieces[0] == PIECE_LIST_END_MARKER) {
                return;
            }

            /* handle wrap around */
            if (state->moveable_pieces_idx == 0) {
                for (unsigned int i = 0; i < NUM_ELEMENTS(state->moveable_pieces); i++) {
                    if (state->moveable_pieces[i] == 0xff) {
                        state->moveable_pieces_idx = i - 1;
                        break;
                    }
                }
            } else {
                state->moveable_pieces_idx -= 1;
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (((SCL_Game *)state->game)->ply == 0) {
                state->state = SMALLCHESS_MENU_NEW_WHITE;
            } else {
                state->state = SMALLCHESS_MENU_RESUME;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            /* pre-calculate the possible moves this piece can make */
            SCL_boardGetMoves(((SCL_Game *)state->game)->board, state->moveable_pieces[state->moveable_pieces_idx], moveable_dests);
            state->moveable_dests_idx = 0;
            SCL_SQUARE_SET_ITERATE_BEGIN(moveable_dests)
                state->moveable_dests[state->moveable_dests_idx] = iteratedSquare;
                state->moveable_dests_idx++;
            SCL_SQUARE_SET_ITERATE_END
            state->moveable_dests[state->moveable_dests_idx] = PIECE_LIST_END_MARKER;
            state->moveable_dests_idx = 0;
            state->state = SMALLCHESS_SELECT_DEST;
        default:
            break;
    }
}

static void _smallchess_handle_select_dest_button_event(smallchess_face_state_t *state, movement_event_t event) {
    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_UP:
            // check for no moves possible state (shouldn't happen but this will prevent weirdness)
            if (state->moveable_dests[0] == PIECE_LIST_END_MARKER) {
                return;
            }
            state->moveable_dests_idx += 1;
            if (state->moveable_dests_idx >= (sizeof(state->moveable_dests) / sizeof(state->moveable_dests[0]))) {
                state->moveable_dests_idx = 0;
            }

            if (state->moveable_dests[state->moveable_dests_idx] == PIECE_LIST_END_MARKER) {
                state->moveable_dests_idx = 0;
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // check for no moves possible state (shouldn't happen but this will prevent weirdness)
            if (state->moveable_dests[0] == PIECE_LIST_END_MARKER) {
                return;
            }

            /* handle wrap around */
            if (state->moveable_dests_idx == 0) {
                for (unsigned int i = 0; i < NUM_ELEMENTS(state->moveable_dests); i++) {
                    if (state->moveable_dests[i] == 0xff) {
                        state->moveable_dests_idx = i - 1;
                        break;
                    }
                }
            } else {
                state->moveable_dests_idx -= 1;
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            state->state = SMALLCHESS_SELECT_PIECE;
            break;
        case EVENT_ALARM_LONG_PRESS:
            SCL_gameMakeMove((SCL_Game *)state->game, state->moveable_pieces[state->moveable_pieces_idx], state->moveable_dests[state->moveable_dests_idx], 'q');

            /* if the player didn't win or draw here, calculate a move */
            if (((SCL_Game *)state->game)->state == SCL_GAME_STATE_PLAYING) {
                _smallchess_make_ai_move(state);
                state->state = SMALLCHESS_SHOW_CPU_MOVE;
            } else {
                /* player ended the game through mate or draw; jump to select piece screen to show state */
                state->state = SMALLCHESS_SELECT_PIECE;
            }
            break;
        default:
            break;
    }
}

/* this just waits until any button is hit */
static void _smallchess_handle_show_cpu_move_button_event(smallchess_face_state_t *state, movement_event_t event) {
    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_LIGHT_BUTTON_UP:
        case EVENT_ALARM_LONG_PRESS:
        case EVENT_LIGHT_LONG_PRESS:
            state->state = SMALLCHESS_SELECT_PIECE;
            break;
        default:
            break;
    }
}

static void _smallchess_handle_show_last_move_button_event(smallchess_face_state_t *state, movement_event_t event) {
    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_LIGHT_BUTTON_UP:
        case EVENT_ALARM_LONG_PRESS:
        case EVENT_LIGHT_LONG_PRESS:
            state->state = SMALLCHESS_MENU_SHOW_LAST_MOVE;
            break;
        default:
            break;
    }
}

static void _smallchess_handle_playing_button_event(smallchess_face_state_t *state, movement_event_t event) {
    if (state->state == SMALLCHESS_SELECT_PIECE) {
        _smallchess_handle_select_piece_button_event(state, event);
    } else if (state->state == SMALLCHESS_SELECT_DEST) {
        _smallchess_handle_select_dest_button_event(state, event);
    } else if (state->state == SMALLCHESS_SHOW_CPU_MOVE) {
        _smallchess_handle_show_cpu_move_button_event(state, event);
    } else if (state->state == SMALLCHESS_SHOW_LAST_MOVE) {
        _smallchess_handle_show_last_move_button_event(state, event);
    }
}

static void _smallchess_handle_main_menu_button_event(smallchess_face_state_t *state, movement_event_t event) {
    uint16_t ply = ((SCL_Game *)state->game)->ply;

    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_UP:
            /* no game started; only offer start white/start black */
            if (ply == 0) {
                if (state->state == SMALLCHESS_MENU_NEW_WHITE) {
                    state->state = SMALLCHESS_MENU_NEW_BLACK;
                } else {
                    state->state = SMALLCHESS_MENU_NEW_WHITE;
                }
            } else {
                state->state++;
                if (state->state >= SMALLCHESS_PLAYING_SPLIT) {
                    state->state = SMALLCHESS_MENU_RESUME;
                }
            }

            break;
        case EVENT_LIGHT_BUTTON_UP:
            /* no game started; only offer start white/start black */
            if (ply == 0) {
                if (state->state == SMALLCHESS_MENU_NEW_BLACK) {
                    state->state = SMALLCHESS_MENU_NEW_WHITE;
                } else {
                    state->state = SMALLCHESS_MENU_NEW_BLACK;
                }
            } else {
                if (state->state == SMALLCHESS_MENU_RESUME) {
                    state->state = SMALLCHESS_PLAYING_SPLIT - 1;
                } else {
                    state->state--;
                }
            }

            break;
        case EVENT_ALARM_LONG_PRESS:
            _smallchess_select_main_menu_subitem(state);
            break;
        default:
            break;
    }
}

static void _smallchess_handle_button_event(smallchess_face_state_t *state, movement_event_t event) {
    if (state->state < SMALLCHESS_PLAYING_SPLIT) {
        /* in main menu */
        _smallchess_handle_main_menu_button_event(state, event);
    } else if (state->state > SMALLCHESS_PLAYING_SPLIT) {
        /* in piece selection */
        _smallchess_handle_playing_button_event(state, event);
    }
}

bool smallchess_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    smallchess_face_state_t *state = (smallchess_face_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            if (((SCL_Game *)state->game)->ply == 0) {
                state->state = SMALLCHESS_MENU_NEW_WHITE;
            } else {
                state->state = SMALLCHESS_MENU_RESUME;
            }
            _smallchess_face_update_lcd(state);
            break;
        case EVENT_LIGHT_BUTTON_UP:
        case EVENT_LIGHT_LONG_PRESS:
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_ALARM_LONG_PRESS:
            _smallchess_handle_button_event(state, event);
            _smallchess_face_update_lcd(state);
            break;
        case EVENT_TICK:
            break;
        case EVENT_TIMEOUT:
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void smallchess_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off();
}
