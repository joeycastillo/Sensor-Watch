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

#ifndef PRIME_HUNTER_FACE_H_
#define PRIME_HUNTER_FACE_H_

#include "movement.h"
#define PNH_HIGH_SCORES  3

/*

Prime Number Hunter Safari

Press left button for prime numbers, right for composite.

Earn croutons to go on safari and hunt the big game prime numbers.

Big game numbers permanently improve your high score list.**

There is no time limit on a safari. 

As your three big game trophy numbers improve, the targets get larger and the
venues change.

You may override the auto-selected starting level at the beginning
of the game to increase/decrease difficulty.

Stats: Left/Light button
CR - credits
CO - total game count
S1 - Safaris attempted
S2 - Safaris successful
MA - number of times mauled

** Except Africa.  You might be EATEN. Stay alert.

*/


typedef struct {
    uint32_t theNumber;         // Current number player is evaluating
    uint32_t lastSafariNumber;  // Last number during safari gameplay
    bool     isPrime;           // Is theNumber prime?
    uint16_t factor;            // Factor if theNumber is composite
    uint8_t  numCorrect;        // Number of correct entries
    uint8_t  numStrikes;        // Number of strikes
    uint8_t  numCount;          // How many numbers presented this round
    uint8_t  roundNumber;       // Current round number 1 or 2 or 3 for safari
    int8_t   currentLevel;      // Current round difficulty level
    int8_t   defaultStartLevel; // Default start level next time game is played
    int8_t   actStartLevel;     // Actual start level for this game
    int32_t  croutonTotal;      // Total cash rese//rve - can start out negative!
    uint16_t tickCounter;       // For minimum delays
    uint8_t  attract_index;     // For displaying high scores, plus other stats
    uint8_t  attract_count;     // For displaying lists within attract mode
    uint16_t game_timer;        // Once reaches zero, this is the final number
    uint8_t  mode;              // 0 Pre-game waiting show scores, 1 show auxiliary data, 2 playing, 3 end game blank, 4 final display
    uint8_t  reset_counter;     // Can reset hero_counter by crashing using zero fuel several consecutive scenarios
    bool     write_pending;     // Need to update EEPROM when resigning
    uint16_t game_counter;      // Total games played since reset
    uint16_t safari_counter;    // Total safaris played since reset
    uint16_t safari_win_counter;// Total successful safaris since reset ( new high )
    uint16_t mauled_counter;	// Total number of times injured
    uint8_t  aux_display_mode;	// 0 - pilot rating, 1 - highest rating, 2 - game counter, 3 - start  year/month, 4 - version number
    uint8_t  country_code;      // 0 = Idaho, and so on...
    uint8_t  special_country;   // Your fixed bonus country/planet 
    bool     safari_mode;       // Are we on safari?
    uint32_t high_scores[PNH_HIGH_SCORES];   // Highest scores ever
} pnh_state_t;

void prime_hunter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void prime_hunter_face_activate(movement_settings_t *settings, void *context);
bool prime_hunter_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void prime_hunter_face_resign(movement_settings_t *settings, void *context);

#define prime_hunter_face ((const watch_face_t){ \
    prime_hunter_face_setup, \
    prime_hunter_face_activate, \
    prime_hunter_face_loop, \
    prime_hunter_face_resign, \
    NULL, \
})

#endif // PRIME_HUNTER_FACE_H_
