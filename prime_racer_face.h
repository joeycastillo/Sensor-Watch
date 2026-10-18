/*
 * MIT License
 *
 * Copyright (c) 2025 Klingon Jane
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

#ifndef PN_RACER_FACE_H_
#define PN_RACER_FACE_H_

#include "movement.h"
#define PN_RACER_HIGH_SCORES  11

/*

Prime Number Racer

For math warriors....

Press left button for prime numbers, right for composite.

Right button to start a game, left button scrolls through stats

A successful game ends when the timer runs out and you classify the
final number correctly.

Your score is the average of the numbers in your high score list.

Any wrong answer results in the random loss of a high score.

SC - Score. The average of your 11 best scores
HA - Highest average score ever
HS - Highest single game completed
CO - Total game counter
FA - Failed game counter

In-game indicators turn on when you exceed the lowest score on
the high score list, and more when you exceed the highest score
on the list.

*/


typedef struct {
    uint32_t theNumber;         // Current number player is evaluating
    uint16_t high_average;      // Highest average score ever
    uint16_t high_single;       // Highest single score ever
    uint8_t  high_round_number; // Highest round number ever
    uint16_t current_average;   // Average of all high scores
    uint8_t  round_number;      // Current round number
    bool     isPrime;           // Is theNumber prime?
    uint32_t factor;            // Factor if theNumber is composite
    uint32_t lastScore;         // Final score in game just played
    uint16_t tick_counter;      // For minimum delays
    uint8_t  score_disp_index;  // For displaying all high scores, plus last score
    uint16_t game_timer;        // Once reaches zero, this is the final number
    uint8_t  mode;              // 0 Pre-game waiting show scores, 1 show auxiliary data, 2 playing, 3 end game blank, 4 final display
    uint8_t  reset_counter;     // Can reset hero_counter by crashing using zero fuel several consecutive scenarios
    bool     write_pending;     // Need to update EEPROM when resigning
    uint16_t game_counter;      // Total games played since reset
    uint16_t failed_counter;    // Failed games played since reset
    uint8_t  aux_display_mode;	// 0 - game counter,  1 - version number
    uint32_t high_scores[PN_RACER_HIGH_SCORES];   // Highest scores ever
} pn_racer_state_t;

void pn_racer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void pn_racer_face_activate(movement_settings_t *settings, void *context);
bool pn_racer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void pn_racer_face_resign(movement_settings_t *settings, void *context);

#define prime_racer_face ((const watch_face_t){ \
    pn_racer_face_setup, \
    pn_racer_face_activate, \
    pn_racer_face_loop, \
    pn_racer_face_resign, \
    NULL, \
})

#endif // PN_RACER_FACE_H_
