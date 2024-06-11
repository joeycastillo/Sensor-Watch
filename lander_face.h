/*
 * MIT License
 *
 * Copyright (c) 2024 Klingon Jane
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

#ifndef LANDER_FACE_H_
#define LANDER_FACE_H_

#include "movement.h"

/*
 
My remake of a classic planet landing game.

Objective: Safely land the Cringeworthy.
Use your limited fuel supply to achieve a soft touch-down.

End scenarios and ship's health:

Hero    They name this planet after you.
8  		Life is very cozy.
7
6
5		Life is tolerable, plus some creature comforts
4
3		Marooned.
2
1
0		Ship destroyed. Life is harsh, no shelter. Giant hamsters are cute. **
Bug     As in squished.
Crater  They name this crater after you.
Gone    As in vapourized.

Landing display format is:
Ship's health, intact crewmen, injured crewmen.

Additional data:
Crew's compliment: 13.
Low fuel warning icons: activates when 3 seconds of full thrust remains.
** Yes, hamsters are very cute. However; some eating of astronauts may occur.

Starting velocity, height and gravity are randomized each scenario.
Fuel levels randomly assigned from 1 to 4 (hardest) to match starting parameters.

A safe landing is always possible.

End of game icons:
LAP - Fantastic budgeting of fuel supply ( Required for heroic landing status. )
24H - Great budgeting of fuel supply
PM -  Good budgeting of fuel supply
SIGNAL - The combination coffee and tea maker survived

Landings get progressively harder with the number of heroic landings made.
Number of heroic landings are remembered.

Heroic
Landings   Status
     0     Normal
     3     Hard   ( first difficulty increase )
     6     Harder ( final difficulty increase )
     8     Ace
    11     ??????

Save yourself.  Save the coffee maker. 

END of standard training manual

*/


/*
 
What is really going on here?
The fleet is lost. You are a newbie pilot making a name for yourself.

Objective: Find Earth.

After reaching ?????? status, future heroic sorties will have 'some' chance in 200
of finding Earth.

Your chances improve by 1 chance in 200 for each subsequent Heroic Landing (HL).

Completing HL 12 will give you 1 chance in 200, for that landing.
HL 13 will give you 2 chances in 200, for that landing.
HL 14 will give you 3 chances in 200, for that landing.
HL 20 will give you 9 chances in 200, for that landing, and so on.

At these higher levels, your chances in 200 are displayed in the upper right corner on a heroic landing.

For wannabe pilots only: The HL counter can be reset by crashing three consecutive
missions without touching the thrust button. ( 6 to reset Earth-found counter )

Find Earth. Save Humanity.

*/

typedef struct {
    int32_t height;
    int16_t speed;			// Positive is up
    uint16_t tick_counter;	// For minimum delays
    uint16_t fuel_start;
    uint16_t fuel_remaining;
    uint16_t fuel_tpl;		// Fuel required for theoretical perfect landing
    uint16_t fuel_score;	// 100 is perfect; higher is less perfect
    int8_t gravity;			// negative downwards value
    bool led_active;		// Did we use it this scenario?
    uint8_t mode;              // 0 Pre-launch waiting, 1 show level, 2 playing, 3 touchdown blank, 4 final display, 5 monster
    uint8_t skill_level;       // 1 thru 4. Dictates fuel alloted
    int8_t ships_health;       // 0 thru 8.  -1 = major crash
    uint8_t hero_counter;      // Total heroic landings ever
    uint8_t legend_counter;    // Historic events counter ( Earth )
    uint8_t difficulty_level;  // Based on hero_counter
    uint8_t reset_counter;     // Can reset hero_counter by crashing using zero fuel several consecutive scenarios
    uint8_t monster_type;      // Which monster is hungry?
    uint8_t uninjured;         // OK survivors
    uint8_t injured;           // Hurt survivors
} lander_state_t;

void lander_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void lander_face_activate(movement_settings_t *settings, void *context);
bool lander_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void lander_face_resign(movement_settings_t *settings, void *context);

#define lander_face ((const watch_face_t){ \
    lander_face_setup, \
    lander_face_activate, \
    lander_face_loop, \
    lander_face_resign, \
    NULL, \
})

#endif // LANDER_FACE_H_

