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

#ifndef BUTTERFLY_GAME_FACE_H_
#define BUTTERFLY_GAME_FACE_H_

#include "movement.h"

/*
 * BUTTERFLY
 *
 * A GAME OF SHAPE RECOGNITION AND QUICK REFLEXES FOR 2 PLAYERS
 *
 * Setup
 * =====
 * 
 * The game is played by 2 players, each using a distinct button:
 * - player 1 plays with the LIGHT (upper left) button
 * - player 2 plays with the ALARM (lower right) button
 * 
 * To play, both players need a firm grip on the watch. A suggested method is to
 * face each other, remove the watch from the wrist, and position it sideways
 * between you. Hold one side of the strap in your preferred hand (right or
 * left) and use your thumb to play.
 * 
 * Start of the game
 * =================
 * 
 * After the splash screen (BtrFly) is shown, the game proceeds through a couple
 * configuration screens. Use ALARM to cycle through the possible values, and
 * LIGHT to validate and move to the next screen.
 * 
 * The configuration options are:
 * 
 * - snd  y/n     Toggle sound effects on or off
 * - goal 3/6/9   Choose to play a game of 3, 6 or 9 points
 * - cont y/n     Decide to continue an unfinished game or start a new one
 *                (this option appears only if a game is in progress)
 * 
 * Rules
 * =====
 * 
 * Prior to each round, a symmetrical shape composed of 2 characters is shown in
 * the center of the screen. This shape, representing a butterfly's wings, is
 * randomly chosen from a set of a dozen or so possible shapes. For example:
 * 
 *     ][
 * 
 * Memorize this shape! Your objective in the round will be to "catch" this 
 * "butterfly" by pressing your button before your opponent does.
 * 
 * Once you believe you've memorized the shape, press your button. The round
 * officially begins as soon as either player presses their button.
 * 
 * Various "butterflies" will then appear on the screen, one after the other.
 * The fastest player to press their button when the correct butterfly is shown
 * wins the round. However, if a player presses their button when an incorrect
 * butterfly is shown, they immediately lose the round.
 * 
 * Scoring
 * =======
 * 
 * The scores are displayed at the top of the screen at all times.
 * 
 * When a round is won by a player, their score increases by one. When a round
 * is lost by a player, their score decreases by one; unless they have a score
 * of 0, in which case it remains unchanged.
 * 
 * The game ends when a player reaches the set point goal (3, 6 or 9 points).
 *
 */

typedef struct {
    bool cont : 1; // continue
    bool sound : 1;
    uint8_t goal_score : 4;
    
    // a generic ctr used by multiple states to display themselves for multiple frames
    uint8_t ctr : 6;

    uint8_t correct_shape : 5;
    uint8_t current_shape : 5;
    uint8_t show_correct_shape_after : 5;
    uint8_t round_winner : 1;

    uint8_t score_p1 : 5;
    uint8_t score_p2 : 5;
} butterfly_game_state_t;

void butterfly_game_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void butterfly_game_face_activate(movement_settings_t *settings, void *context);
bool butterfly_game_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void butterfly_game_face_resign(movement_settings_t *settings, void *context);

#define butterfly_game_face ((const watch_face_t){ \
    butterfly_game_face_setup, \
    butterfly_game_face_activate, \
    butterfly_game_face_loop, \
    butterfly_game_face_resign, \
    NULL, \
})

#endif // BUTTERFLY_GAME_FACE_H_

