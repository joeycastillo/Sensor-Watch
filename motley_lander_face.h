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

#ifndef MOTLEY_LANDER_FACE_H_
#define MOTLEY_LANDER_FACE_H_

#include "movement.h"

/*
 
Remake of a classic planet landing game.

Your ship, the Cringeworthy, is an economy based lander loaded with the finest automation and supplies for planetary settlement.

Use your limited fuel supply to achieve a soft touch-down.

Touchdown status is displayed at the end of a scenario.
The format is:  SH IC IN
IC  Intact crew.
IN  Injuries.  Don't sweat these.  Your crew is fragile but healthy.  They will recover.
SH  Ship's Health.  Your ship is also fragile.  That, and the lack of a fuel gauge makes it a popular econonical
    choice.  Ships's health is on a scale from 0 to 5.

0  Ship destroyed.  All equipment and most supplies lost.  Any survivors will find life harsh.
1
2  Marooned.
3  Most equipment survives.  Life is tolerable plus there are some creature comforts.  Six months to repair ship.
4
5  Ship 100% intact.  Life is very cozy.
6  Excess fuel reserves guarantees the colonies' prosperity.  Your retirement is luxurious.

Additional data:
Crew's compliment: 8.
Low fuel warning icons: activates when 3 seconds of full thrust remains.
 
Starting velocity, starting height, and planet gravity are randomized each scenario.
Randomly assigned skill levels from 1 to 4 (hardest) will dictate starting fuel.  A safe landing
is always possible.

Extraordinary outcomes supercede end of mission touchdown status. These are:

Hero    Stellar. All crew members become exceedingly wealthy. This luxury resort planet which you founded bears your name.
Bug     As in squished.
Crater  Future missions discover a ship fragment: DNA traces are sandwiched between the upper and lower hulls.  They
        name the crater after you.
Gone    As in vapourized.  There is a huge crater here.  No one knows why.

End of game icons:
LAP - Great budgeting of fuel supply
SIGNAL and BELL - The combination coffee and tea maker survived

Save yourself.  Save the coffee maker. 

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
	bool verbose;			// If true, display landing speed and fuel score
	uint8_t mode;			// 0 Pre-launch waiting, 1 show level, 2 playing, 3 touchdown, 4 touchdown speed, 5 fuel score, 6 final display
	uint8_t skill_level;	// 1 thru 4. Dictates fuel alloted
	int8_t ships_health;	// 0 thru 5 typically.  -1 = major crash
	uint8_t hero_counter;	// Total heroic landings ever
	uint8_t difficulty_level;	// Based on heroic_counter. Overrideable by user.
	uint8_t reset_counter;	// Can reset hero_counter by crashing using zero fuel several consecutive scenarios
} motley_lander_state_t;

void motley_lander_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void motley_lander_face_activate(movement_settings_t *settings, void *context);
bool motley_lander_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void motley_lander_face_resign(movement_settings_t *settings, void *context);

#define motley_lander_face ((const watch_face_t){ \
    motley_lander_face_setup, \
    motley_lander_face_activate, \
    motley_lander_face_loop, \
    motley_lander_face_resign, \
    NULL, \
})

#endif // MOTLEY_LANDER_FACE_H_

