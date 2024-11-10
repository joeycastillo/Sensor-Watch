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

// Submitted github version:
// Granularity at 40, improved fuel feedback, no optional difficulty_level reduction.
// First-earth difficulty reductions. Signficant difficulty reduction on 1st six landings.
// Best ship's health at 8, minus 1 level for each 2 points of speed.

// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lander_face.h"

#define LANDER_TICK_FREQUENCY 8
#define MONSTER_DISPLAY_TICKS 9
#define ENGINE_THRUST 11
#define MODE_WAITING_TO_START 0
#define MODE_DISPLAY_SKILL_LEVEL 1
#define MODE_PLAYING 2
#define MODE_TOUCHDOWN_BLANK 3
#define MODE_DISPLAY_FINAL_STATUS 4
#define MODE_MONSTER 5
#define MODE_FIND_EARTH_MESSAGE 6
#define CREWS_COMPLIMENT 13
// Granularity is divisions per foot - height display
#define GRANUL 40
// Next lines for repeat heroes only.
#define PROMOTION_INTERVAL	3
#define LEVEL_ACE 8
#define LEVEL_SPENCER 11
#define HARD_EARTH_INCREMENTS 11
#define MAX_HARD_EARTH_CHANCE 6

// The gory final result calculations:
#define SPEED_FATALITY_ALL 41
#define SPEED_FATALITY_NONE 26
#define SPEED_NO_DAMAGE 21
#define SPEED_LEVEL_INCREMENTS 2
#define SPEED_MAJOR_CRASH 73
#define MAJOR_CRASH_INCREMENTS 65
#define SPEED_INJURY_NONE 20
#define SPEED_INJURY_FULCRUM 32
#define INJURY_FULCRUM_PROB 65
#define FUEL_SCORE_GOOD 145
#define FUEL_SCORE_GREAT 131
#define FUEL_SCORE_FANTASTIC 125

// Joey Castillo to oversee storage allocation row
#define LANDER_STORAGE_ROW 2
#define STORAGE_KEY_NUMBER 125

#define DIFFICULTY_LEVELS	3
char lander_difficulty_names[DIFFICULTY_LEVELS][7] = {
    "NOrMAL", "HArd  ", "HArdEr"
};
char lander_months[13][3]= {
    "Un", "JA", "FE", "Mr", "AP", "MY", "Jn", "JL", "AU", "SE", "OC", "NO", "dE"
};
#define MONSTER_TYPES 4
char lander_monster_names[MONSTER_TYPES][7] = {
    "mOnStr", "6Erbil", "HAmStr", "Rabbit"
};
#define MONSTER_ACTIONS 8
char lander_monster_actions[MONSTER_ACTIONS][7] = {
    "HUn6ry", "  EAtS", "6Reedy", "annoYd", "nASty ", "SAVOry", "HO66SH", " pI66Y"
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

static void write_to_lander_EEPROM(lander_state_t *state) {
    uint8_t size = 10;	// Length of data
    uint8_t output_array [ size ];
    uint8_t offset = 0;

    output_array [ 0 ] = STORAGE_KEY_NUMBER;
    output_array [ 1 ] = state->hero_counter;
    output_array [ 2 ] = state->legend_counter;
    output_array [ 3 ] = state->pilot_rating;
    output_array [ 4 ] = state->pilot_rating_highest;
    output_array [ 5 ] = state->rating_overflow_count;
    // Storage 6 and 7 are game counter, storage 6 is high byte, storage 7 is low byte
    output_array [ 6 ] = state->game_counter / 256;
    output_array [ 7 ] = state->game_counter % 256;
    output_array [ 8 ] = state->reset_year - 1999;
    output_array [ 9 ] = state->reset_month;
    watch_storage_erase ( LANDER_STORAGE_ROW );
    watch_storage_sync ( );
    watch_storage_write ( LANDER_STORAGE_ROW, offset, output_array, size );
}

// Reset all stats except hero variables
static void lander_reset(lander_state_t *state) {
    state->pilot_rating = 20;
    state->pilot_rating_highest = state->pilot_rating;
    state->rating_overflow_count = 0;
    state->game_counter = 0;
    state->reset_year = 1999; // Overwritten on 1st mission
    state->reset_month = 12;
}

// ---------------------------
// Standard watch face methods
// ---------------------------
void lander_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(lander_state_t));
        memset(*context_ptr, 0, sizeof(lander_state_t));
    }
    lander_state_t *state = (lander_state_t *)*context_ptr;
    // Emulator only: Seed random number generator
    #if __EMSCRIPTEN__
    srand(time(NULL));
    #endif
// Read in stored hero counter, pilot history etc. from EEPROM.
    uint32_t offset = 0;
    uint32_t size = 10; // How many bytes we want
    uint8_t stored_data [ size ];
    // See if the hero_counter was ever written to EEPROM storage
    watch_storage_read (LANDER_STORAGE_ROW, offset, stored_data, size);
    if (stored_data[0] == STORAGE_KEY_NUMBER )
    {
        state->hero_counter          = stored_data [1]; // There's real data in there.
        state->legend_counter        = stored_data [2];
        state->pilot_rating          = stored_data [3];
        state->pilot_rating_highest  = stored_data [4];
        state->rating_overflow_count = stored_data [5];
        state->game_counter          = stored_data [6] * 256;
        state->game_counter         += stored_data [7];
        state->reset_year            = stored_data [8] + 1999; // Ex. 2024
        state->reset_month           = stored_data [9];
        state->difficulty_level = state->hero_counter / PROMOTION_INTERVAL;
        state->difficulty_level = min ( state->difficulty_level, DIFFICULTY_LEVELS - 1 );	// Upper limit
        state->write_pending=false;
    }
    else
    {
        lander_reset(state);
        state->hero_counter = 0;
        state->legend_counter = 0;
        state->difficulty_level = 0;
        state->write_pending=false;
   }
}

void lander_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    lander_state_t *state = (lander_state_t *)context;
    char buf [ 7 ];
    state->mode = MODE_WAITING_TO_START;
    state->led_active = false;
    state->reset_counter = 0;
    state->aux_display_mode = 0;
    watch_clear_all_indicators ( );
    // Fancy intro
    if ( state->legend_counter == 0 ) watch_display_string("LA", 0);
    else watch_display_string("LE", 0);
    if ( ( state->hero_counter == 0 ) || ( state->hero_counter >= 40 ) ) watch_display_string ( "  ", 2);
    else
    {
        sprintf ( buf, "%2d", state->hero_counter );
        watch_display_string(buf, 2);
    }
    if ( state->hero_counter >= 100 ) sprintf ( buf, "Str%3d", state->hero_counter );
    else if ( state->hero_counter >= 40 ) sprintf ( buf, "Strb%2d", state->hero_counter );
    else if ( state->hero_counter >= LEVEL_SPENCER ) sprintf ( buf, "StrbUC" );
    else if ( state->hero_counter >= LEVEL_ACE ) sprintf ( buf, " ACE  " ); // This human is good
    else if ( state->difficulty_level == 0 ) sprintf ( buf, "     " );
    else sprintf ( buf, "%s", lander_difficulty_names[state->difficulty_level] );
    watch_display_string ( buf, 4);
}

bool lander_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    lander_state_t *state = (lander_state_t *)context;
    char buf [ 20 ];	// [11] is more correct and works; compiler too helpful.
    uint8_t i;

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
                if ( ( state->height > 971 * 80 ) && ( state->speed > 70 ) ) {  // Escape height
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
                    state->game_counter++;
                    if ( state->game_counter == 1 ) { // Grab year/month of very first mission
                        watch_date_time date_time;
                        date_time = watch_rtc_get_date_time();
                        state->reset_year = date_time.unit.year + 2020;  // 2020 is baseline movement uses.
                        state->reset_month = date_time.unit.month;
                    }
                    // Also calc fuel score now.
                    float fuel_score_float;
                    uint16_t fuel_used;
                    fuel_used = state->fuel_start - state->fuel_remaining;
                    fuel_score_float = (float) fuel_used / (float) state->fuel_tpl;
                    state->fuel_score = (int) (fuel_score_float * 100.0 + 0.5);
                    if ( state->legend_counter == 0 ) state->fuel_score -= 8;	// First Earth is easier
                    // Monitor reset_counter
                    if ( fuel_used >= 1 ) state->reset_counter = 0;
                    else state->reset_counter++;
                    if ( state->reset_counter == 3 ) {
                        lander_reset(state);
                        watch_display_string ( "  rESET ", 2 );
                        delay_ms(2000);
                        sprintf ( buf, "  %4d  ", state->pilot_rating);
                        watch_display_string ( buf, 2 );
                        state->tick_counter = 0;
                        state->mode = MODE_WAITING_TO_START;
                    }
                    else if ( state->reset_counter == 7 ) {
                        lander_reset(state);
                        state->hero_counter = 0;
                        state->legend_counter = 0;
                        state->difficulty_level = 0;
                        watch_display_string ( "  CLEAr ", 2 );
                        delay_ms(2000);
                        watch_display_string ( "      ", 4 );
                        state->tick_counter = 0;
                        state->mode = MODE_WAITING_TO_START;
                    }
                }
                // Wait until time for next display
                if ( state->tick_counter >= ( 1 * LANDER_TICK_FREQUENCY ) ) {
                    state->tick_counter = 0;
                    state->mode = MODE_DISPLAY_FINAL_STATUS;
                }
            }
            else if ( state->mode == MODE_DISPLAY_FINAL_STATUS ) {
                bool last_pass = false;
                if ( state->tick_counter >= LANDER_TICK_FREQUENCY ) last_pass = true;
                // Show final status
                if ( state->tick_counter == 1 ) {
                    // Calculate many attributes
                    // 1) Display touchdown speed - upper right, may get overwritten
                    // 2) Check for major crash: bug, crater, vaporized (gone).
                    // 3) Rank ship's health 0 to 8
                    // 4) Calculate pilot ranking
                    // 5) Special conditions: hero, stellar and Earth
                    // 6) Crew fatalities and injuries
                    // 7) Set fuel conservation indicators as appropriate
                    // 8) Set coffee maker OK indicator as appropriate
                    // 9) Green light if ship intact
                    // 10) Set standard display if not preempted.

                    bool shipDestroyed, stellarPilot, foundEarth, disableText;
                    int16_t actSpeed, adjSpeed, dispSpeed, tempSpeed, levelsDamage;
                    int8_t shipsHealth, myRand;
                    uint8_t fatalities, probFatal, probInjury, prevPilotRating;
                    char buf2[3];
                    uint8_t landing_points;
                    int16_t delta_fuel;

                    shipDestroyed = false;
                    stellarPilot = false;
                    foundEarth = false;
                    disableText = false;
                    // Landings more difficult with difficulty_level.
                    actSpeed = abs ( state->speed );
                    adjSpeed = actSpeed + state->difficulty_level * 4;
                    // First Earth is a bit easier than all the others
                    if ( state->legend_counter == 0 ) adjSpeed -= 3;
                    adjSpeed = max ( 1, adjSpeed );  // Unlikely, but technically possible

                    // 1) Display touchdown speed - upper right, may get overwritten
                    dispSpeed = actSpeed;
                    if ( dispSpeed < 0 ) dispSpeed = 0;
                    if ( dispSpeed > 999 ) dispSpeed = 999;
                    if ( dispSpeed > 399 ) dispSpeed = - ( dispSpeed / 100 );
                    else if ( dispSpeed > 39 ) dispSpeed = dispSpeed / 10;
                    sprintf ( buf2, "%2d", dispSpeed );
                    watch_display_string ( buf2, 2 );
                    // 2) Check for major crash: bug, crater, vaporized (gone).
                    if ( (!shipDestroyed) && adjSpeed >= SPEED_MAJOR_CRASH ) {
                        shipDestroyed = true;
                        disableText = true;
                        if ( adjSpeed >= ( SPEED_MAJOR_CRASH + 2 * MAJOR_CRASH_INCREMENTS ) ) sprintf ( buf, "GOnE  " );
                        else if ( adjSpeed >= ( SPEED_MAJOR_CRASH + MAJOR_CRASH_INCREMENTS ) ) sprintf ( buf, " CrAtr" );
                        else sprintf ( buf, "   bU6" );
                    }
                    // 3) Rank ship's health 0 to 8
                    shipsHealth = -1;
                    if ( !shipDestroyed ) {
                        tempSpeed = adjSpeed + SPEED_LEVEL_INCREMENTS - 1;
                        levelsDamage = (int) ( ( tempSpeed - SPEED_NO_DAMAGE ) / SPEED_LEVEL_INCREMENTS );
                        shipsHealth = 8 - levelsDamage;
                        shipsHealth = min ( shipsHealth, 8 );	// Keep between 0 and 8
                        shipsHealth = max ( shipsHealth, 0 );
                    }
                    state->ships_health = shipsHealth;    // Remember ships health
                    // 4) Calculate pilot ranking
                    landing_points = 0;
                    if ( state->ships_health > 0 ) landing_points = state->ships_health;
                    delta_fuel=floor((FUEL_SCORE_FANTASTIC - state->fuel_score)/6.0);
                    delta_fuel+=5;
                    delta_fuel = min ( 5, delta_fuel ); // Keep between 0 and 5
                    delta_fuel = max ( 0, delta_fuel );
                    if ( delta_fuel >  landing_points ) delta_fuel = landing_points;
                    landing_points+= delta_fuel;
                    prevPilotRating = state->pilot_rating;
                    state->pilot_rating+=landing_points;
                    // Emulate overflow bug above rating of 255
                    if ( state->pilot_rating < prevPilotRating ) // Overflow/wrap - very good pilot!
                    {
                        state->rating_overflow_count += 1;
                        state->pilot_rating = 127;
                        state->pilot_rating_highest = state->pilot_rating;
                        sprintf ( buf, "StELAr" );
                        stellarPilot = true;
                        disableText = true;
                    }
                    else if ( state->pilot_rating >= state->pilot_rating_highest ) {
                        watch_set_indicator ( WATCH_INDICATOR_BELL );
                        if ( state->pilot_rating > state->pilot_rating_highest ) {
                           state->pilot_rating_highest = state->pilot_rating;
                           watch_display_string("HI", 0);
                        }
                    }
                    // 5) Special conditions: hero, stellar and Earth
                    if (landing_points >= 13) {  // A hero's landing!!
                        state->hero_counter++;
                        disableText = true; // Suppress usual ship and crew count status message

                        // Did we happen to find Earth?
                        // Two rule sets for finding Earth.  Alternate between easy and hard.
                        int8_t my_odds, temp;
                        if ( state->legend_counter %2 == 0 ) my_odds = (int8_t) state->hero_counter - LEVEL_SPENCER; // Easy
                        else {
                            temp = ( state->hero_counter - LEVEL_SPENCER ) + HARD_EARTH_INCREMENTS - 1;
                            my_odds = temp / HARD_EARTH_INCREMENTS;
                            my_odds = min ( my_odds, MAX_HARD_EARTH_CHANCE );
                        }
                        // Display odds in weekday region if positive value
                        if ( my_odds > 0 ) {
                            char buff3 [ 3 ];
                            sprintf ( buff3, "%2d", my_odds );
                            watch_display_string ( buff3, 2 );
                        } else watch_display_string ( "  ", 2 );
                        // Check if we found Earth 
                        if ( my_odds >= gen_random_int ( 1, 200 ) ) {  // EARTH!!!!  The final objective.
                            // last chance to remind user which heroic landing this was prior
                            // to wiping it out forever
                            char buff4 [ 3 ];
                            sprintf ( buff4, "%2d", state->hero_counter % 40 );
                            watch_display_string ( buff4, 2 );
                            state->hero_counter = 0;
                            state->legend_counter++;
                            foundEarth = true;
                        }
                        // Message priorities are Earth, then Stellar, than Hero
                        if ( foundEarth ) sprintf ( buf, "EArTH " );	// 17% within 8, 50% by 16, 79% by 24, 94% by 32 <- easy mode
                        else if ( stellarPilot ) sprintf ( buf, "StELAr" );
                        else {
                            if ( state->hero_counter==1 ) sprintf ( buf, "HErO  " );
                            else if ( state->hero_counter == LEVEL_ACE ) sprintf ( buf, " ACE  " );
                            else if ( state->hero_counter == LEVEL_SPENCER ) sprintf ( buf, "STrbUC" );
                            else if ( state->hero_counter>99 ) sprintf ( buf, "HEr%3d", state->hero_counter );
                            else sprintf ( buf, "HErO%2d", state->hero_counter );	// Typical case
                        }
                        // Recalculate difficulty level base on new hero_counter.
                        state->difficulty_level = state->hero_counter / PROMOTION_INTERVAL;
                        state->difficulty_level = min ( state->difficulty_level, DIFFICULTY_LEVELS - 1 );	// Upper limit
                        // Write to EEPROM on resigning
                        state->write_pending=true;
                    }
                    // 6) Crew fatalities and injuries
                    if (!disableText) {
                        // Fatalies
                        probFatal = assignProb ( 0, 92, SPEED_FATALITY_NONE, SPEED_FATALITY_ALL, adjSpeed );
                        // Injuries
                        if ( adjSpeed <= SPEED_INJURY_FULCRUM ) {
                             probInjury = assignProb ( 0, INJURY_FULCRUM_PROB, SPEED_INJURY_NONE, SPEED_INJURY_FULCRUM, adjSpeed );
                        } else {
                            probInjury = assignProb ( INJURY_FULCRUM_PROB, 96, SPEED_INJURY_FULCRUM, SPEED_FATALITY_ALL, adjSpeed );
                        }
                        fatalities = 0;
                        state->injured = 0;
                        for ( i = 0; i < CREWS_COMPLIMENT; i++ ) {
                            myRand = gen_random_int ( 1, 100 );
                            if ( myRand <= probFatal ) fatalities++;
                            else if ( myRand <= probInjury ) state->injured++;
                        }
                        state->uninjured = CREWS_COMPLIMENT - fatalities - state->injured;
                    }
                    // 7) Set fuel conservation indicators as appropriate
                    if ( shipsHealth >= 1 && ( state->fuel_score <= FUEL_SCORE_FANTASTIC ) ) watch_set_indicator ( WATCH_INDICATOR_LAP );
                    if ( shipsHealth >= 1 && ( state->fuel_score <= FUEL_SCORE_GREAT     ) ) watch_set_indicator ( WATCH_INDICATOR_24H );
                    if ( shipsHealth >= 1 && ( state->fuel_score <= FUEL_SCORE_GOOD      ) ) watch_set_indicator ( WATCH_INDICATOR_PM );
                    // 8) Set coffee maker OK indicator as appropriate
                    if ( shipsHealth >= 5 || ( shipsHealth >= 0 && ( gen_random_int ( 0, 3 ) != 1 ) ) ){
                        watch_set_indicator ( WATCH_INDICATOR_SIGNAL );
                    }
                    // 9) Green light if ship intact
                    if ( shipsHealth >= 8 ) {
                        watch_set_led_green ( );
                        state->led_active = true;
                    }
                    // 10) Set standard display if not preempted.
                    if (!disableText) {
                        if ( ( state->injured > 0 ) || ( state->uninjured == 0 ) ) {
                            sprintf ( buf, "%d %2d%2d",  shipsHealth, state->uninjured, state->injured );
                        }
                        else {
                            sprintf ( buf, "%d %2d  ",  shipsHealth, state->uninjured );
                        }
                    }
                    // Display final status.
                    watch_display_string ( buf, 4 );
                } // End if tick_counter == 1

                // Major crash - ship burning with red LED.
                if ( state->ships_health < 0 ) {
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
                    watch_set_led_off ( );
                    // No change to display text, allow new game to start.
                    state->mode = MODE_WAITING_TO_START;
                    // Unless it's time for monsters
                    uint8_t survivors = state->injured + state->uninjured;
                    if ( ( state->ships_health >= 0 ) && ( survivors > 0 ) &&
                         ( gen_random_int ( -1, 3 ) >= state->ships_health ) ) {
                        state->mode = MODE_MONSTER;
                        state->tick_counter = 0;
                        state->monster_type = gen_random_int ( 0, MONSTER_TYPES - 1 );
                    }
                }
            } // End if MODE_DISPLAY_FINAL_STATUS
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
            else if ( state->mode == MODE_FIND_EARTH_MESSAGE ) {
                // Display "Find" then "Earth"
                if ( state->tick_counter == 1 ) {
                    sprintf ( buf, "   FInd " );
                    watch_display_string ( buf, 2 );
                }
                if ( state->tick_counter == (int) ( 1.5 * LANDER_TICK_FREQUENCY + 1 ) ) {
                    sprintf ( buf, "  EArTH " );
                    watch_display_string ( buf, 2 );
                }
                // Wait long enough, then display skill level.
                if ( state->tick_counter >= ( 3 * LANDER_TICK_FREQUENCY ) ) {
                    state->tick_counter = 0;
                    state->mode = MODE_DISPLAY_SKILL_LEVEL;
                }
            }
            else if ( state->mode == MODE_MONSTER ) {
                if ( state->tick_counter == 1 ) watch_display_string ( lander_monster_names[state->monster_type], 4 );
                else if ( state->tick_counter == MONSTER_DISPLAY_TICKS + 1 ) {
                    uint8_t my_rand;
                    my_rand = gen_random_int ( 0 , MONSTER_ACTIONS - 1 );
                    watch_display_string ( lander_monster_actions[my_rand], 4 );
                }
                else if ( state->tick_counter == MONSTER_DISPLAY_TICKS * 2 ) {  // Display 1st monster character
                    sprintf ( buf, "%s", lander_monster_names[state->monster_type] );
                    buf [1] = 0;
                    watch_display_string(buf,4);
                }
                else if ( state->tick_counter == MONSTER_DISPLAY_TICKS * 2 + 1 ) {  // Display current population, close mouth
                    sprintf ( buf, "c%2d%2d", state->uninjured, state->injured );
                    watch_display_string ( buf, 5 );
                }
                else if ( state->tick_counter == MONSTER_DISPLAY_TICKS * 2 + 3 ) watch_display_string ( "C", 5 );	// Open mouth
                else if ( state->tick_counter == MONSTER_DISPLAY_TICKS * 2 + 5 ) {
                    // Decision to: continue loop, end loop or eat astronaut
                    uint8_t survivors = state->injured + state->uninjured;
                    uint8_t myRand = gen_random_int ( 0, 16 );
                    if ( survivors == 0 ) state->mode = MODE_WAITING_TO_START;
                    else if ( myRand <= 1 ) { // Leave loop with survivors
                        sprintf ( buf, "%d %2d%2d", state->ships_health, state->uninjured, state->injured );
                        watch_display_string ( buf, 4 );
                        state->mode = MODE_WAITING_TO_START;
                    } else if ( myRand <= 11 ) state->tick_counter = MONSTER_DISPLAY_TICKS * 2;	// Do nothing, loop continues
                    else { // Eat an astronaut - welcome to the space program!
                        if ( state->injured > 0 && state->uninjured > 0 ) {
                            if ( gen_random_int ( 0,1 ) == 0 ) state->injured--;
                            else state->uninjured--;
                        }
                        else if ( state->injured > 0 ) state->injured--;
                        else state->uninjured--;
                        state->tick_counter = MONSTER_DISPLAY_TICKS * 2;	// Re-display
                    }
                }
                else if ( state->tick_counter >= MONSTER_DISPLAY_TICKS * 4 ) state->mode = MODE_WAITING_TO_START; // Safety
            } // End if MODE_MONSTER
            break;  // End case EVENT_TICK
        case EVENT_ALARM_BUTTON_UP:
            if ( state->mode == MODE_WAITING_TO_START ) {
                // That was the go signal - start a new game!!
                float numerator, denominator, timeSquared;
                int16_t absGravity, thrust;
                float myTime, distToTop, fuel_mult;
                uint8_t skill_level;
                int32_t tplTop;			// Top lander height for TPL calculations
                movement_request_tick_frequency(LANDER_TICK_FREQUENCY);
                watch_set_led_off ( );	// Safety
                watch_clear_all_indicators ( );
                // Randomize starting parameters
                state->height = gen_random_int ( 131, 181 ) * 80;
                // Per line below; see Mars Orbiter September 23, 1999
                if ( gen_random_int ( 0, 8 ) == 5 ) state->height = gen_random_int ( 240, 800 ) * 80;
                state->speed = gen_random_int ( -120, 35 );     // Positive is up
                state->gravity = gen_random_int ( -3, -2 ) * 2;	// negative downwards value
                skill_level = gen_random_int ( 1, 4 );          // Precursor to fuel allocation
                // Theoretical Perfect Landing (TPL) calculations start here.
                myTime = (float) state->speed / (float) state->gravity;	// How long to reach this speed? Don't care which way sign is.
                distToTop = fabs ( 0.5 * state->gravity * myTime * myTime );
                tplTop = (int) ( state->height + distToTop + 0.5 );	// Theoretical highest point based on all of speed, height and gravity.
                // Time squared = ( 2 * grav * height ) / ( t*t + g*t ), where t is net acceleration with thrust on.
                absGravity = abs ( state->gravity );
                thrust = ENGINE_THRUST + state->gravity;
                numerator = 2.0 * (float) absGravity * (float) tplTop;
                denominator = thrust * thrust + thrust * absGravity;
                timeSquared = numerator / denominator;
                state->fuel_tpl = (int) ( sqrt ( timeSquared ) + 0.5 );  // Fuel required for theoretical perfect landing (TPL).
                if ( skill_level == 1 ) fuel_mult = 4.0;        // TPL + 300%
                else if ( skill_level == 2 ) fuel_mult = 2.5;   // TPL + 150%
                else if ( skill_level == 3 ) fuel_mult = 1.6;   // TPL + 60%
                else fuel_mult = 1.3;                           // TPL + 30%
                state->fuel_start = state->fuel_tpl * fuel_mult;
                state->fuel_remaining = state->fuel_start;
                state->skill_level = skill_level;
                state->tick_counter = 0;
                // Early update to pilot ranking here to prevent cheating
                if ( state->pilot_rating > 0 ) state->pilot_rating--;
                state->pilot_rating = (int) ( state->pilot_rating * 0.9698 + 0.5 ); // Need 9 point avg to wrap
                state->write_pending = true;
                state->aux_display_mode = 0;
                if ( state->legend_counter == 0 ) watch_display_string("LA", 0);
                else watch_display_string("LE", 0);
                if ( gen_random_int ( 1, 109 ) != 37 ) {
                    // Houston, approaching launch....
                    state->mode = MODE_DISPLAY_SKILL_LEVEL;
                }
                else state->mode = MODE_FIND_EARTH_MESSAGE;
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if ( state->mode == MODE_WAITING_TO_START ) {
                 // Display difficulty level
                 watch_display_string ( lander_difficulty_names [state->difficulty_level], 4 );
            }
            break;
        case EVENT_LIGHT_LONG_UP:
            if ( ( state->mode == MODE_WAITING_TO_START ) && ( state->legend_counter > 0 ) ) {
                if ( state->legend_counter > 9 ) sprintf (buf,"EArt%2d", state->legend_counter );
                else sprintf (buf,"EArth%d", state->legend_counter );
                // Display legend counter
                watch_display_string ( buf, 4 );
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (state->write_pending) {
                write_to_lander_EEPROM(state);
                watch_storage_sync ( );
                state->write_pending=false;
            }
            watch_display_string("SLEEP ", 4);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if ( state->mode == MODE_WAITING_TO_START ) {
                watch_clear_all_indicators ( );
                if ( state->rating_overflow_count >= 1 ) watch_set_indicator ( WATCH_INDICATOR_SIGNAL );
                if ( state->rating_overflow_count >= 2 ) watch_set_indicator ( WATCH_INDICATOR_BELL );
                if ( state->rating_overflow_count >= 3 ) watch_set_indicator ( WATCH_INDICATOR_PM );
                if ( state->rating_overflow_count >= 4 ) watch_set_indicator ( WATCH_INDICATOR_24H );
                if ( state->rating_overflow_count >= 5 ) watch_set_indicator ( WATCH_INDICATOR_LAP );
                if ( state->aux_display_mode == 0 ) {
                    // Display pilot rating score here
                    sprintf ( buf, " %3d  ", state->pilot_rating );
                }
                else if ( state->aux_display_mode == 1 ) {
                    // Display pilot rating score here
                    sprintf ( buf, " %3dHI", state->pilot_rating_highest );
                }
                else if ( state->aux_display_mode == 2 ) {
                    // Display game counter
                    sprintf ( buf, " %5d", state->game_counter );
                }
                else {
                    // Display date
                    sprintf ( buf, "%4d%s", state->reset_year, lander_months [state->reset_month] );
                }
                watch_display_string ( buf, 4 );
                state->aux_display_mode++;
                state->aux_display_mode = state->aux_display_mode % 4;
            }
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }
	if ( !state->led_active ) return true;
    else return false;
}

void lander_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    lander_state_t *state = (lander_state_t *)context;
    watch_set_led_off ( );
    if (state->write_pending) {
        write_to_lander_EEPROM(state);
        state->write_pending=false;
    }
}
