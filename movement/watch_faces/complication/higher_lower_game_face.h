/*
 * MIT License
 *
 * Copyright (c) 2023 Chris Ellis
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

#ifndef HIGHER_LOWER_GAME_FACE_H_
#define HIGHER_LOWER_GAME_FACE_H_

#include "movement.h"

/*
 * Higher-Lower game face
 * ======================
 *
 * A game face based on the "higher-lower" card game where the objective is to correctly guess if the next card will
 * be higher or lower than the last revealed cards.
 *
 * Game Flow:
 * - When the face is selected, the "Hi-Lo" "Title" screen will be displayed, and the status indicator will display "GA" for game
 * - Pressing `ALARM` or `LIGHT` will start the game and proceed to the "Guessing" screen
 *   - The first card will be revealed and the player must now make a guess
 *   - A player can guess `Higher` by pressing the `LIGHT` button, and `Lower` by pressing the `ALARM` button
 *   - The status indicator will show the result of the guess: HI (Higher), LO (Lower), or == (Equal)
 *   - There are five guesses to make on each game screen, once the end of the screen is reached, a new screen
 *     will be started, with the last revealed card carried over
 *   - The number of completed screens is displayed in the top right (see Scoring)
 * - If the player has guessed correctly, the score is updated and play continues (see Scoring)
 * - If the player has guessed incorrectly, the status will change to GO (Game Over)
 *   - The current card will be revealed
 *   - Pressing `ALARM` or `LIGHT` will transition to the "Score" screen
 * - If the game is won, the status indicator will display "WI" and the "Win" screen will be displayed
 *   - Pressing `ALARM` or `LIGHT` will transition to the "Score" screen
 * - The status indicator will change to "SC" when the final score is displayed
 *   - The number of completed game screens will be displayed on using the first two digits
 *   - The number of correct guesses will be displayed using the final three digits
 *   - E.g. "13: 063" represents 13 completed screens, with 63 correct guesses
 * - Pressing `ALARM` or `LIGHT` while on the "Score" screen will transition to back to the "Title" screen
 *
 * Scoring:
 * - If the player guesses correctly (HI/LO) a point is gained
 * - If the player guesses incorrectly the game ends
 *   - Unless the revealed card is equal (==) to the last card, in which case play continues, but no point is gained
 * - If the player completes 40 screens full of cards, the game ends and a win screen is displayed
 *
 * Misc:
 * The face tries to remain true to the spirit of using "cards"; to cope with the display limitations I've arrived at
 * the following mapping of card values to screen display, but am open to better suggestions:
 *
 * Thanks to voloved for adding deck shuffling and drawing!
 *
 * | Cards   |                          |
 * |---------|--------------------------|
 * | Value   |2|3|4|5|6|7|8|9|10|J|Q|K|A|
 * | Display |0|1|2|3|4|5|6|7|8 |9|-|=|≡|
 *
 * A previous alternative can be found in the git history:
 * | Cards   |                          |
 * |---------|--------------------------|
 * | Value   |2|3|4|5|6|7|8|9|10|J|Q|K|A|
 * | Display |2|3|4|5|6|7|8|9| 0|-|=|≡|H|
 *
 *
 * Future Ideas:
 * - Add sounds
 * - Save/Display high score
 * - Add a "Win" animation
 * - Consider using lap indicator for larger score limit
 */

typedef struct {
    // Anything you need to keep track of, put it here!
} higher_lower_game_face_state_t;

void higher_lower_game_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void higher_lower_game_face_activate(movement_settings_t *settings, void *context);
bool higher_lower_game_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void higher_lower_game_face_resign(movement_settings_t *settings, void *context);

#define higher_lower_game_face ((const watch_face_t){ \
    higher_lower_game_face_setup, \
    higher_lower_game_face_activate, \
    higher_lower_game_face_loop, \
    higher_lower_game_face_resign, \
    NULL, \
})

#endif // HIGHER_LOWER_GAME_FACE_H_
