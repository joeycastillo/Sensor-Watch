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

#ifndef SMALLCHESS_FACE_H_
#define SMALLCHESS_FACE_H_

#include "movement.h"

/*
 * Chess watchface
 *
 * Implements a (very) simple chess engine.
 * Uses smallchesslib for the engine: https://codeberg.org/drummyfish/smallchesslib
 *
 * When moving a piece, only valid pieces and moves are presented.
 *
 * Interaction is done through a simple menu/submenu system:
 * - Light button: navigate backwards through the current menu
 * - Alarm button: navigate forwards through the current menu
 * - Light button (long press): navigate up to the parent menu
 * - Alarm button (long press): select the current item or submenu
 */

enum smallchess_state {
    /* main menu */
    SMALLCHESS_MENU_RESUME,
    SMALLCHESS_MENU_SHOW_LAST_MOVE,
    SMALLCHESS_MENU_UNDO,
    SMALLCHESS_MENU_NEW_WHITE,
    SMALLCHESS_MENU_NEW_BLACK,

    SMALLCHESS_PLAYING_SPLIT,

    /* playing game submenu */
    SMALLCHESS_SHOW_LAST_MOVE,
    SMALLCHESS_SHOW_CPU_MOVE,
    SMALLCHESS_SELECT_PIECE,
    SMALLCHESS_SELECT_DEST,
};

#define NUM_ELEMENTS(a) (sizeof(a) / sizeof(a[0]))
#define SMALLCHESS_NUM_PIECES 16 // number of pieces each player has

typedef struct {
    void *game;
    enum smallchess_state state;
    uint8_t moveable_pieces[SMALLCHESS_NUM_PIECES + 1];
    uint8_t moveable_pieces_idx;
    uint8_t moveable_dests[29]; // this magic number represents the maximum number of moves a piece can make (queen in center of board)
                                // plus one for the end list marker
    uint8_t moveable_dests_idx;
    char last_move_str[7];
    uint8_t ai_from_square, ai_to_square;
} smallchess_face_state_t;

void smallchess_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void smallchess_face_activate(movement_settings_t *settings, void *context);
bool smallchess_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void smallchess_face_resign(movement_settings_t *settings, void *context);

#define smallchess_face ((const watch_face_t){ \
    smallchess_face_setup, \
    smallchess_face_activate, \
    smallchess_face_loop, \
    smallchess_face_resign, \
    NULL, \
})

#endif // SMALLCHESS_FACE_H_
