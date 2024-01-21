/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
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

#ifndef TOSS_UP_FACE_H_
#define TOSS_UP_FACE_H_

/*
 * TOSS UP face
 * ============
 *
 * Playful watch face for games of chance or divination using coins or dice.
 * 
 * LIGHT switches between Coins and Dice mode
 * 
 * COINS
 * =====
 * 
 * ALARM tosses a coin. If it lands on heads it gets sorted to the left side of the
 * display, if it lands on tails then sorted to the right side.
 * 
 * LONG PRESSING ALARM adds up to 5 more coins to the toss for more nuance in the decision
 * making (e.g. three heads vs two tails could be read as "yes, but with serious doubts").
 * 
 * LONG PRESSING LIGHT flips through additional style for the coins from the default Ө/O 
 * to H/T (heads/tails), Y/N (yes/no), E/Ǝ, C/Ↄ
 * 
 * LONG PRESSING ALARM on the "Coins" title page resets to one coin.
 * LONG PRESSING LIGHT on the "Coins" title page resets the style to Ө/O
 * 
 * DICE
 * ====
 * 
 * ALARM rolls a six sided dice.
 * 
 * LONG PRESSING ALARM adds up to 2 more dice to the roll.
 * 
 * LONG PRESSING LIGHT flips through other available polyhedral dice types with less or more
 * than the default 6 sides. The options are D2, D4, D6, D8, D10, D12, D20, D24, D30, D32, D36, 
 * D48, and a hypothetical D99. 
 * 
 * When more than one dice is used for a roll this changes only the last added dice. (see Note
 * below)
 *
 * LONG PRESSING ALARM on the "Dice" title page resets to one dice.
 * LONG PRESSING LIGHT on the "Dice" title page resets the dice to D6.
 * 
 * Please Note: If you need let's say a D8, D12, and D20 for your rolls then the procedure to
 * set this up would be as follows: from the default screen where you can roll the one D6 dice 
 * you would LONG PRESS LIGHT a few times to change the D6 to a D8, then LONG PRESS ALARM to add 
 * a second dice, LONG PRESS LIGHT again until the second dice changes to D12, then LONG PRESS
 * ALARM to add the third dice and LONG PRESS LIGHT again a few times until it becomes a D20.
 *
 */

#include "movement.h"

typedef struct {
    // Anything you need to keep track of, put it here!
    uint32_t entropy;
    uint8_t mode : 4; // 1 coin, 2 coins, 3 coins, 4 coins, dice, iching, geomnc
    bool setup;
    bool coins[6];
    uint8_t coin_num : 3;
    char coin_style[2];
    uint8_t coinface : 3;
    uint8_t dice[3];
    uint8_t dice_num : 2;
    uint8_t dd : 6;
    uint8_t dice_sides[3];
    uint8_t animation;
    bool animate;
} toss_up_state_t;

uint32_t get_true_entropy(void);
uint8_t divine_bit(void);
uint8_t roll_dice(uint8_t sides);
void toss_up_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void toss_up_face_activate(movement_settings_t *settings, void *context);
bool toss_up_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void toss_up_face_resign(movement_settings_t *settings, void *context);

#define toss_up_face ((const watch_face_t){ \
    toss_up_face_setup, \
    toss_up_face_activate, \
    toss_up_face_loop, \
    toss_up_face_resign, \
    NULL, \
})

#endif // TOSS_UP_FACE_H_

