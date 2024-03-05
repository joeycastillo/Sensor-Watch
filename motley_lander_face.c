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

// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "motley_lander_face.h"

#define LANDER_TICK_FREQUENCY 8
#define ENGINE_THRUST 11
#define MODE_WAITING_TO_START 0
#define MODE_DISPLAY_SKILL_LEVEL 1
#define MODE_PLAYING 2
#define MODE_TOUCHDOWN_BLANK 3
#define MODE_DISPLAY_TOUCHDOWN_SPEED 4
#define MODE_DISPLAY_FUEL_SCORE 5
#define MODE_DISPLAY_FINAL_STATUS 6
#define CREWS_COMPLIMENT 8
// Granularity is how many divisions in a foot
#define GRANUL 80	
// Next lines for repeat heroes only.
#define DIFFICULTY_LEVELS	3
#define PROMOTION_INTERVAL	3
#define LEVEL_ACE 8
#define LEVEL_STARBUCK 11
#define EARTH_THRESHOLD 13

// The gory final result calculations:
#define SPEED_FATALITY_ALL 42
#define SPEED_FATALITY_NONE 22
#define SPEED_NO_DAMAGE 17
#define SPEED_LEVEL_INCREMENTS 4
#define SPEED_MAJOR_CRASH 65
#define MAJOR_CRASH_INCREMENTS 65
#define SPEED_INJURY_NONE 17
#define SPEED_INJURY_FULCRUM 22
#define INJURY_FULCRUM_PROB 60
#define FUEL_SCORE_GREAT 140
#define FUEL_SCORE_FANTASTIC 125

// Joey Castillo oversee storage allocation row
#define LANDER_STORAGE_ROW 17
// Random key number below selected using 'Probablity_face'.
#define STORAGE_KEY_NUMBER 110

char lander_difficulty_names[DIFFICULTY_LEVELS][7] = {
	"NOrMAL", "HArd  ", "HArdEr"
};

// --------------
// Custom methods
// --------------
 

static int gen_random_int (int16_t lower, int16_t upper) {
	int range;
	int retVal;
	range = upper - lower + 1;
	if ( range < 2 ) range = 2;
    // Emulator: use rand. Hardware: use arc4random.
    #if __EMSCRIPTEN__
    retVal = rand() % range;
    #else
    retVal = arc4random_uniform(range);
    #endif
	retVal += lower;
	return retVal;
}

static uint8_t assignProb ( uint8_t lowerProb, uint8_t upperProb, int16_t lowerSpeed, int16_t upperSpeed, int16_t actSpeed ) {
	float probRange, speedRange;
	float ratio, probFloat;
	int probInt;
	speedRange = upperSpeed - lowerSpeed;
	if (speedRange<1.0) speedRange = 1.0;
	probRange = upperProb - lowerProb;
	ratio = ( (float) actSpeed - (float) lowerSpeed ) / speedRange;
	probFloat = (float) lowerProb + ( ratio * probRange );
	probInt = (int) ( probFloat + 0.5 );
	probInt = min ( probInt, upperProb );
	probInt = max ( probInt, lowerProb );
	return (uint8_t) probInt;
}

static void write_to_motley_EEPROM(motley_lander_state_t *state) {
	uint8_t output_array [ 3 ];
	output_array [ 0 ] = STORAGE_KEY_NUMBER;
	output_array [ 1 ] = state->hero_counter;
	output_array [ 2 ] = state->difficulty_level;
	watch_storage_erase ( LANDER_STORAGE_ROW );
	watch_storage_sync ( );
	watch_storage_write ( LANDER_STORAGE_ROW, 0, output_array, 3 );
}
		
// ---------------------------
// Standard watch face methods
// ---------------------------
void motley_lander_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(motley_lander_state_t));
        memset(*context_ptr, 0, sizeof(motley_lander_state_t));
    }
    // Emulator only: Seed random number generator
    #if __EMSCRIPTEN__
    srand(time(NULL));
    #endif
}

void motley_lander_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    motley_lander_state_t *state = (motley_lander_state_t *)context;
	char buf [ 5 ];
	state->mode = MODE_WAITING_TO_START;
	state->led_active = false;
	state->verbose = false;
	state->reset_counter = 0;
	watch_clear_all_indicators ( );
	uint32_t offset = 0;
	uint32_t size = 3;
	uint8_t stored_data [ size ];		
	// See if the hero_counter was ever written to EEPROM storage
	watch_storage_read (LANDER_STORAGE_ROW, offset, stored_data, size);
	if (stored_data[0] == STORAGE_KEY_NUMBER ) {	// There's real data in there.
		state->hero_counter = stored_data [1];
		state->difficulty_level = stored_data [2];
	} else { // Nope. Nothing there.
		state->hero_counter = 0;	
		state->difficulty_level = 0;
	}
	// Fancy intro
	if ( state->hero_counter >= LEVEL_STARBUCK ) watch_display_string("StrbUC", 4);
	else if ( state->hero_counter >= LEVEL_ACE ) watch_display_string(" ACE  ", 4); // This human is good
	else if ( state->difficulty_level == 0 ) watch_display_string("      ", 4);
	else watch_display_string (lander_difficulty_names[state->difficulty_level], 4);
	if ( state->hero_counter == 0 ) sprintf ( buf, "ML  " );
	else if ( state->hero_counter <= 39 ) sprintf ( buf, "ML%2d", state->hero_counter );
	else if ( state->hero_counter <= 99 ) sprintf ( buf, "ML-%d", state->hero_counter / 10 );
	else sprintf ( buf, "ML%2d", state->hero_counter / 10 );
    watch_display_string(buf, 0);
}

bool motley_lander_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    motley_lander_state_t *state = (motley_lander_state_t *)context;
	char buf [ 20 ];	// [11] is more correct and works; compiler too helpful.

    switch (event.event_type) {
        case EVENT_TICK:
			state->tick_counter++;
			if ( state->mode == MODE_PLAYING ) {
				int16_t accel = state->gravity;
			    bool gas_pedal_on = watch_get_pin_level(BTN_ALARM);
				if ( gas_pedal_on && ( state->fuel_remaining > 0 ) ) {
					accel = ENGINE_THRUST + state->gravity;		// Gravity is negative
					state->fuel_remaining--;					// Used 1 fuel unit
					watch_set_indicator ( WATCH_INDICATOR_LAP );
					// Low fuel warning indicators
					if ( state->fuel_remaining == ( 3 * LANDER_TICK_FREQUENCY ) ) {	// 3 seconds of fuel left
						watch_set_indicator ( WATCH_INDICATOR_SIGNAL );
						watch_set_indicator ( WATCH_INDICATOR_BELL );
						watch_set_indicator ( WATCH_INDICATOR_PM );
						watch_set_indicator ( WATCH_INDICATOR_24H );
					}
					else if ( state->fuel_remaining == 0 ) {	// 0 seconds of fuel left, empty!
						watch_clear_all_indicators ( );
					}
				}
				else {
					watch_clear_indicator ( WATCH_INDICATOR_LAP );
				}
				state->speed += accel;
				state->height += state->speed;
				if ( state->height > 971 * GRANUL ) {	// They're outta here!
					watch_clear_all_indicators ();
					watch_display_string ( "ESCAPE", 4 );
					state->tick_counter = 0;
					state->mode = MODE_WAITING_TO_START;
				}
				else if ( state->height <= 0 ) {	// Touchdown
					state->tick_counter = 0;
					state->mode = MODE_TOUCHDOWN_BLANK;
				}
				else {
					// Update height display
					sprintf ( buf, "%4d", (int) ( state->height / GRANUL ) );
					watch_display_string ( buf, 4 );
				}
			}
			else if ( state->mode == MODE_TOUCHDOWN_BLANK ) {
				// Blank display on touchdown
				if ( state->tick_counter == 1 ) {
					watch_clear_all_indicators ();
					watch_display_string ( "      ", 4 );
					// Also calc fuel score now.
					float fuel_score_float;
					uint16_t fuel_used;
					fuel_used = state->fuel_start - state->fuel_remaining;
					fuel_score_float = (float) fuel_used / (float) state->fuel_tpl;
					state->fuel_score = (int) (fuel_score_float * 100.0 + 0.5);
					// Monitor reset_counter
					if ( fuel_used >= 1 ) state->reset_counter = 0;
					else state->reset_counter++;
					if ( state->reset_counter >= 3 ) {
						state->hero_counter = 0;
						state->difficulty_level = 0;
						watch_display_string ( "rESET ", 4 );
						write_to_motley_EEPROM(state);
					}
				}
				// Wait until time for next display
				if ( state->tick_counter >= ( 1 * LANDER_TICK_FREQUENCY ) ) {
					state->tick_counter = 0;
					if ( state->verbose ) state->mode = MODE_DISPLAY_TOUCHDOWN_SPEED;
					else state->mode = MODE_DISPLAY_FINAL_STATUS;
				}
			}
			else if ( state->mode == MODE_DISPLAY_TOUCHDOWN_SPEED ) {
				// Show touchdown speed.
				if ( state->tick_counter == 1 ) {
					sprintf ( buf, "%4dSP", -state->speed );
					watch_display_string ( buf, 4 );
				}
				// Wait until time for fuel score
				if ( state->tick_counter >= ( 2.0 * LANDER_TICK_FREQUENCY ) ) {
					state->tick_counter = 0;
					state->mode = MODE_DISPLAY_FUEL_SCORE;
				}
			}
			else if ( state->mode == MODE_DISPLAY_FUEL_SCORE ) {
				// Show fuel score
				if ( state->tick_counter == 1 ) {
					float fuel_score_float;
					uint16_t fuel_used;
					fuel_used = state->fuel_start - state->fuel_remaining;
					// Display fuel score
					fuel_score_float = (float) fuel_used / (float) state->fuel_tpl;
					state->fuel_score = (int) (fuel_score_float * 100.0 + 0.5);
					sprintf ( buf, "%4dFL", state->fuel_score );
					watch_display_string ( buf, 4 );
				}
				// Wait until time for final status
				if ( state->tick_counter >= ( 2.0 * LANDER_TICK_FREQUENCY ) ) {
					state->tick_counter = 0;
					state->mode = MODE_DISPLAY_FINAL_STATUS;
				}
			}
			else if ( state->mode == MODE_DISPLAY_FINAL_STATUS ) {
				bool last_pass = false;
				if ( state->tick_counter >= ( 2.0 * LANDER_TICK_FREQUENCY ) ) last_pass = true;

				// Show final status
				if ( state->tick_counter == 1 )
				{
					// Calculate many attributes
					// 1) Major crash: bug, crater, vaporized (gone).
					// 2) Rank ship's health 0 to 5
					// 3) Crew fatalities and injuries
					// 4) Bonus on fuel from health 5 to health 6
					// 5) Special conditions: hero
					// 6) Set fuel conservation indicator as appropriate
					// 7) Set coffee maker OK indicator as appropriate
					// 8) Green light for great landing
					// 9) Set standard display if not preempted.
					bool allDone;
					int16_t absSpeed, boostedSpeed, levelsDamage;
					int8_t shipsHealth, myRand;
					uint8_t fatalities, injuries, uninjured, probFatal, probInjury;
					uint8_t i;
					
					allDone = false;
					// Easiest implementation for difficulty_level is to increase touchdown speed above actual.
					absSpeed = abs ( state->speed ) + state->difficulty_level * 2;
					
					// 1) Major crash: bug, crater, vaporized (gone).
					if ( absSpeed >= SPEED_MAJOR_CRASH )
					{
						allDone = true;
						shipsHealth = -1;
						if ( absSpeed >= ( SPEED_MAJOR_CRASH + 2 * MAJOR_CRASH_INCREMENTS ) ) sprintf ( buf, "GOnE  " );
						else if ( absSpeed >= ( SPEED_MAJOR_CRASH + MAJOR_CRASH_INCREMENTS ) ) sprintf ( buf, " CrAtr" );
						else sprintf ( buf, "   bU6" );
					}

					// 2) Rank ship's health 0 to 5
					if (!allDone) {
						boostedSpeed = absSpeed + SPEED_LEVEL_INCREMENTS - 1;
						levelsDamage = (int) ( ( boostedSpeed - SPEED_NO_DAMAGE ) / SPEED_LEVEL_INCREMENTS );
						shipsHealth = 5 - levelsDamage;
						shipsHealth = min ( shipsHealth, 5 );	// Keep between 0 and 5
						shipsHealth = max ( shipsHealth, 0 );
					}
					// 3) Crew fatalities and injuries
					if (!allDone) {
						// Fatalies
						probFatal = assignProb ( 0, 96, SPEED_FATALITY_NONE, SPEED_FATALITY_ALL, absSpeed );
						// Injuries
						if ( absSpeed <= SPEED_INJURY_FULCRUM ) {
							probInjury = assignProb ( 0, INJURY_FULCRUM_PROB, SPEED_INJURY_NONE, SPEED_INJURY_FULCRUM, absSpeed );
						} else {
							probInjury = assignProb ( INJURY_FULCRUM_PROB, 98, SPEED_INJURY_FULCRUM, SPEED_FATALITY_ALL, absSpeed );
						}
						fatalities = 0;
						injuries = 0;
						for ( i = 0; i < CREWS_COMPLIMENT; i++ ) {
							myRand = gen_random_int ( 1, 100 );
							if ( myRand <= probFatal ) fatalities++;
							else if ( myRand <= probInjury ) injuries++;
						}
						uninjured = CREWS_COMPLIMENT - fatalities - injuries;
					}
					// 4) Bonus on fuel from health 5 to health 6
					if ( (!allDone) && (shipsHealth==5) && ( state->fuel_score <= FUEL_SCORE_GREAT ) ) shipsHealth = 6;
					// 5) Special conditions: hero
					if (!allDone) {
						if ( (shipsHealth==6) && ( state->fuel_score <= FUEL_SCORE_FANTASTIC ) ) {
							state->hero_counter++;
							if ( state->hero_counter==1 ) sprintf ( buf, "HErO  " );
							else if ( state->hero_counter == LEVEL_ACE ) sprintf ( buf, " ACE  " );
							else if ( state->hero_counter == LEVEL_STARBUCK ) sprintf ( buf, "STrbUC" );
							else if ( state->hero_counter>99 ) sprintf ( buf, "HEr%3d", state->hero_counter );
							else sprintf ( buf, "HErO%2d", state->hero_counter );	// Typical case
							allDone = true;
							// Extraordinary odds check
							int8_t my_odds = state->hero_counter - EARTH_THRESHOLD + 1;
							if ( my_odds >= gen_random_int ( 1, 200 ) ) {  // The final game-over.
								sprintf ( buf, "EArTH " );	// 17% within 8, 50% by 16, 79% by 24, 94% by 32
								state->hero_counter = 0;
							}
							// Force difficulty increase on user here. Can be manually reduced with light button. 
							state->difficulty_level = state->hero_counter / PROMOTION_INTERVAL;
							state->difficulty_level = min ( state->difficulty_level, DIFFICULTY_LEVELS - 1 );	// Upper limit
							// Write to EEPROM
							write_to_motley_EEPROM(state);
						}
					}
					state->ships_health = shipsHealth;	// Remember ships health
					// 6) Set fuel conservation indicator as appropriate
					if ( shipsHealth >= 1 && ( state->fuel_score <= FUEL_SCORE_GREAT ) ) watch_set_indicator ( WATCH_INDICATOR_LAP );
					// 7) Set coffee maker OK indicator as appropriate
					if ( shipsHealth >= 3 || ( shipsHealth >= 0 && ( gen_random_int ( 0, 3 ) != 1 ) ) ){
						watch_set_indicator ( WATCH_INDICATOR_BELL );
						watch_set_indicator ( WATCH_INDICATOR_SIGNAL );
					}
					// 8) Green light for great landing
					if ( shipsHealth >= 5 ) {
						watch_set_led_green ( );
						state->led_active = true;
					}
					// 9) Set standard display if not preempted.
					if (!allDone) {
						if ( ( injuries > 0 ) || ( uninjured == 0 ) ) {
							sprintf ( buf, "%d %2d%2d",  shipsHealth, uninjured, injuries );
						}
						else {	
							sprintf ( buf, "%d %2d  ",  shipsHealth, uninjured );
						}
					}	
					// Display final status.
					watch_display_string ( buf, 4 );
				}
				// Major crash?
				if ( state->ships_health < 0 ) { // Ship burning with red LED.
					if ( ( gen_random_int ( 0, 1 ) != 1 ) && !last_pass ) { 	// Always off on last pass
						// Turn on red LED.
						watch_set_led_red ( );
						state->led_active = true;
					} else {
						watch_set_led_off ( );
					}
				}								
				// Wait long enough, then allow waiting for next game.
				if ( last_pass ) {
					// No change to display text, allow new game to start.
					watch_set_led_off ( );
					state->mode = MODE_WAITING_TO_START;
				}
			}
			else if ( state->mode == MODE_DISPLAY_SKILL_LEVEL ) {
				// Display skill level
				if ( state->tick_counter == 1 ) {
					sprintf ( buf, " %d  %d   ", state->skill_level, state->skill_level );
					watch_display_string ( buf, 2 );
				}
				// Wait long enough, then start game.
				if ( state->tick_counter >= ( 2.0 * LANDER_TICK_FREQUENCY ) ) {
					state->tick_counter = 0;
					// Houston, WE ARE LAUNCHING NOW....
					state->mode = MODE_PLAYING;
				}
			}
            break;
        case EVENT_ALARM_BUTTON_DOWN:
			if ( state->mode == MODE_WAITING_TO_START ) {
				// That was the go signal - start a new game!!
				float numerator, denominator, timeSquared;
				int16_t gravity, thrust;
				float myTime, distToTop, fuel_mult;
				uint8_t skill_level;
				int32_t tplTop;			// Top lander height for TPL calculations
				movement_request_tick_frequency(LANDER_TICK_FREQUENCY);
				watch_set_led_off ( );	// Safety
				watch_clear_all_indicators ( );
				// Randomize starting parameters
				state->height = gen_random_int ( 131, 180 ) * GRANUL;
				// Per line below; see Mars Orbiter September 23, 1999
				if ( gen_random_int ( 0, 8 ) == 2 ) state->height = gen_random_int ( 340, 800 ) * GRANUL;
				state->speed = gen_random_int ( -120, 30 );		// Positive is up
				state->gravity = gen_random_int ( -3, -2 ) * 2;	// negative downwards value
				skill_level = gen_random_int ( 1, 4 );			// Precursor to fuel allocation
				// Theoretical Perfect Landing (TPL) calculations start here.
				myTime = (float) state->speed / (float) state->gravity;	// How long to reach this speed? Don't care which way sign is.
				distToTop = fabs ( 0.5 * state->gravity * myTime * myTime );
				tplTop = (int) ( state->height + distToTop + 0.5 );	// Theoretical highest point based on all of speed, height and gravity.
				// Time squared = ( 2 * grav * height ) / ( t*t + g*t ), where t is net acceleration with thrust on.
				gravity = abs ( state->gravity );
				thrust = ENGINE_THRUST + state->gravity;
				numerator = 2.0 * (float) gravity * (float) tplTop;
				denominator = thrust * thrust + thrust * gravity;
				timeSquared = numerator / denominator;
				state->fuel_tpl = (int) ( sqrt ( timeSquared ) + 0.5 );  // Fuel required for theoretical perfect landing (TPL).
				if ( skill_level == 1 ) fuel_mult = 4.0;		// TPL + 300%
				else if ( skill_level == 2 ) fuel_mult = 2.5;	// TPL + 150%
				else if ( skill_level == 3 ) fuel_mult = 1.6;	// TPL + 60%
				else fuel_mult = 1.3;							// TPL + 30%
				state->fuel_start = state->fuel_tpl * fuel_mult;
				state->fuel_remaining = state->fuel_start;
				state->skill_level = skill_level;
				state->tick_counter = 0;
				state->mode = MODE_DISPLAY_SKILL_LEVEL;
				// Houston, approaching launch....
			}
            break;
		case EVENT_LIGHT_LONG_UP:
			if ( state->mode == MODE_WAITING_TO_START ) {
				state->verbose = !state->verbose;
				if ( state->verbose ) sprintf ( buf, "     On " );
				else sprintf ( buf, "     OFF" );
				watch_display_string ( buf, 2 );
			}
            break;
		case EVENT_LIGHT_BUTTON_UP:
			if ( state->mode == MODE_WAITING_TO_START ) {
				uint8_t my_max_difficulty;
				my_max_difficulty = state->hero_counter / PROMOTION_INTERVAL;
				my_max_difficulty = min ( my_max_difficulty, DIFFICULTY_LEVELS - 1 );
				// User may adjust difficulty level
				state->difficulty_level++;
				if ( state->difficulty_level > my_max_difficulty ) state->difficulty_level = 0;
				// And display this level
				watch_display_string ( lander_difficulty_names [state->difficulty_level], 4 );
				write_to_motley_EEPROM(state);
			}
            break;
		case EVENT_LIGHT_BUTTON_DOWN:	// Disable LED
			break;
        case EVENT_LOW_ENERGY_UPDATE:
            watch_display_string("SLEEP ", 4);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }
	if ( !state->led_active ) return true;
    else return false;
}

void motley_lander_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off ( );
}
