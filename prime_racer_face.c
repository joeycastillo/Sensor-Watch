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


// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "prime_racer_face.h"

#define PN_RACER_TICK_FREQUENCY 4
#define MODE_WAITING_TO_START 0
#define MODE_DISPLAY_AUXILIARY_DATA 1
#define MODE_PLAYING 2

#define PN_RACER_VERSION_NUMBER 7
// Joey Castillo to oversee storage allocation row
#define PN_RACER_STORAGE_ROW 4
#define PN_RACER_STORAGE_KEY_NUMBER 3


// --------------
// Custom methods
// --------------
 

static int gen_random_int (int32_t lower, int32_t upper) {
    int32_t range;
    int32_t retVal;
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

static void write_to_pn_racer_EEPROM(pn_racer_state_t *state) {
    uint8_t base = 10;
    uint8_t size = base + ( PN_RACER_HIGH_SCORES * 3 );	// Length of data
    uint8_t output_array [ size ];
    uint8_t offset = 0;
    uint8_t i;
    uint32_t tempScore;

    output_array [ 0 ] = PN_RACER_STORAGE_KEY_NUMBER;
    // Storage 1 and 2 are game counter, storage 1 is high byte, storage 2 is low byte
    output_array [ 1 ] = state->game_counter / 256;
    output_array [ 2 ] = state->game_counter % 256;
    output_array [ 3 ] = state->failed_counter / 256;
    output_array [ 4 ] = state->failed_counter % 256;
    output_array [ 5 ] = state->high_average / 256;
    output_array [ 6 ] = state->high_average % 256;
    output_array [ 7 ] = state->high_single / 256;
    output_array [ 8 ] = state->high_single % 256;
    output_array [ 9 ] = state->high_round_number;
   // 8 thru N used for high score storage
    for ( i = 0; i < PN_RACER_HIGH_SCORES; i++ )
    {
        tempScore = state->high_scores [ i ];
        output_array [ base + ( i * 3 ) + 2 ] = tempScore % 256;
        tempScore = tempScore / 256;
        output_array [ base + ( i * 3 ) + 1 ] = tempScore % 256;
        output_array [ base + ( i * 3 ) + 0 ] = tempScore / 256;
    }
    watch_storage_erase ( PN_RACER_STORAGE_ROW );
    watch_storage_sync ( );
    watch_storage_write ( PN_RACER_STORAGE_ROW, offset, output_array, size );
}

// Calculate average high score
static void pn_racer_calc_current_average (pn_racer_state_t *state) {
    uint8_t i;
    uint32_t total;
    total = 0;
    for ( i = 0; i < PN_RACER_HIGH_SCORES; i++ ) total += state->high_scores [ i ];
    state->current_average = total / PN_RACER_HIGH_SCORES;
}

// Reset all stats and high scores
static void pn_racer_reset(pn_racer_state_t *state) {
    uint8_t i;
    for ( i = 0; i < PN_RACER_HIGH_SCORES; i++ ) state->high_scores [ i ] = 2;
    state->high_scores [ 0 ] = 31;
    state->high_scores [ 1 ] = 29;
    state->high_scores [ 2 ] = 23;
    if ( PN_RACER_HIGH_SCORES >= 11 ) {  // Safety
        state->high_scores [ 3 ] = 19;
        state->high_scores [ 4 ] = 17;
        state->high_scores [ 5 ] = 13;
        state->high_scores [ 6 ] = 11;
        state->high_scores [ 7 ] = 7;
        state->high_scores [ 8 ] = 5;
        state->high_scores [ 9 ] = 3;
        state->high_scores [ 10 ] = 2;
    }
    pn_racer_calc_current_average ( state );
    state->high_average = state->current_average;
    state->high_single = state->high_scores [ 0 ];
    state->high_round_number = 0;
    state->game_counter = 0;
    state->failed_counter = 0;
    state->lastScore = 0;
}

// Remove a random high score from list
static void pn_racer_forfeit_one_high(pn_racer_state_t *state) {
    int8_t i;
    int8_t numTargets;
    int8_t myTarget;	// Index to erase
    char buf[11];
    // First pick a score
    // How many are there?
    numTargets = 0;
    myTarget = -1;
    for ( i = 0; i < PN_RACER_HIGH_SCORES; i++ )
    {
        if ( state->high_scores [ i ] > 10 ) numTargets++;
    }
    if ( numTargets > 1 )  myTarget = gen_random_int ( 0, numTargets-1 );
    if ( numTargets == 1 ) myTarget = 0;
    if ( myTarget != -1 ) {
        sprintf ( buf, "%4ld%2d", state->high_scores[myTarget], myTarget+1 );
        watch_display_string ( buf, 4 );
        delay_ms ( 1000 );
        // Fade out existing score
        for ( i = 0; i < 5; i++ ) {
           watch_display_string ( buf, 4 );
           delay_ms ( 200 - (i*25) );
           watch_display_string ( "    ", 4 );
           delay_ms ( 200 + (i*25) );
        }
        watch_display_string ( "    ", 4 );
        delay_ms ( 200 );
        watch_display_string ( "   0", 4 );
        delay_ms ( 1000 );
       // And now bubble lower scores up to fill this slot.
        for ( i = myTarget; i < PN_RACER_HIGH_SCORES-1; i++ ) state->high_scores[i] = state->high_scores[i+1];
        state->high_scores[PN_RACER_HIGH_SCORES-1] = 0;
    }
}

// Reset all stats and high scores
static void pn_racer_update_high_scores(pn_racer_state_t *state) {
    int8_t i;
    uint32_t temp;
    char buf[11];
    int8_t bestIndex;
    // Check for best-ever
    if ( state->theNumber > state->high_single )
    {
        state->high_single = state->theNumber;
        sprintf ( buf, "%4dHS", state->high_single );
        for ( i = 0; i < 6; i++ )
        {
            watch_display_string ( "      ", 4 );
            delay_ms ( 500 );
            watch_display_string ( buf, 4 );
            delay_ms ( 500 );
        }
        delay_ms ( 1000 );
    }
    // Update the list
    if ( state->theNumber >= state->high_scores[PN_RACER_HIGH_SCORES-1] ) {
        state->high_scores[PN_RACER_HIGH_SCORES-1] = state->theNumber;
        bestIndex = PN_RACER_HIGH_SCORES-1;
        for ( i = PN_RACER_HIGH_SCORES-2; i >= 0; i-- ) {
            if ( state->high_scores[i] < state->high_scores[i+1] ) {	// Swap
                temp = state->high_scores[i];
                state->high_scores[i] = state->high_scores[i+1];
                state->high_scores[i+1] = temp;
                bestIndex = i;
            }
        }
        // Blink new score a few times
        sprintf ( buf, "%4ld%2d", state->lastScore, bestIndex+1 );
        for ( i = 0; i < 6; i++ ) {
            watch_display_string ( "      ", 4 );
            delay_ms ( 150 );
            watch_display_string ( buf, 4 );
            delay_ms ( 150 );
        }
    }
}

// Generate next candidate number
static void pn_racer_new_number(pn_racer_state_t *state ) {
    uint16_t i, testLim;
    uint32_t minLimit, maxLimit;
    uint32_t candidate;
    bool done;
    bool weWantAPrime;
    uint8_t probPercentPrime;

/*
The rules:
Randomly decide if we are seeking a prime or composite number
Set range between 2, and 100* currentLevel
Different range for safari mode
For composite numbers, there are three different sets of rejection rules
A) Below 30, no rules
B) Below 400, light rules
C) Higher has heavier rules

Reject evens and 5s ( 0, 2, 4, 5, 6, 8 ) 14 times in 15
Reject multiples of 3 half the time
*/	

/*
Pseudocode:
1) Calc boolean weWantAPrime;
2) Calc min and max
LOOP while not done
    3) Calc random candidate
    4) Test for primeness
    5) Apply rejection rules
    6) Test for correct number type ( prime or composite )
    7) If safari mode, reject numbers already on high score list
END LOOP
*/

// 1) Calc boolean weWantAPrime;
    probPercentPrime = 50;
    if ( gen_random_int ( 0, 99 ) < probPercentPrime  ) weWantAPrime = true;
    else weWantAPrime = false;

// 2) Calc min and max
    state->round_number++;
    if ( state->round_number > 1 ) {
        minLimit = state->lastScore + 1;
        maxLimit = floor ( minLimit * 1.4 + 0.5 );
        maxLimit = min ( minLimit + 150, maxLimit );
        maxLimit = max ( minLimit + 15, maxLimit );
    } else {
        minLimit = 2;
        maxLimit = 10;
    }

// LOOP while not done
    done = 0;
    while ( !done ) {
//    3) Calc random candidate
        candidate = gen_random_int ( minLimit, maxLimit );
//    4) Test for primeness
        if ( candidate <= 10 ) {	// Weed out weird cases with sqrt around 3
            state->isPrime = false;
            state->factor = 2;
            if ( candidate == 9 ) state->factor = 3;
            if ( ( candidate == 2 ) || ( candidate == 3 ) ||
                 ( candidate == 5 ) || ( candidate == 7 ) ) {
                 state->isPrime = true;
                 state->factor = 0;
            }
        } else { // The real factoring algorithm is here.
            testLim = floor ( sqrt ( candidate ) );
            state->isPrime = true;
            state->factor = 0;
            i = 3;
            if ( candidate % 2 == 0 )
            {
                state->isPrime = false;
                state->factor = 2;
            }
            while ( state->isPrime && ( i <= testLim ) ) {
                if ( ( candidate % i ) == 0 ) {
                    state->isPrime = false;
                    state->factor = i;
                }
                i += 2;
            }
        }			
//    5) Apply rejection rules
        if ( candidate < 30 ) {
            done = true;
        } else if ( candidate < 400 ) {
            if ( ( state->factor == 2 ) || ( candidate % 5 == 0 ) ) {
                if ( gen_random_int ( 1, 23 ) == 8 ) done = true;	// Rarely accept these.
            } else if ( state->factor == 3 ) {
                if ( gen_random_int ( 1, 2 ) == 1 ) done = true;	// Sometimes accept divisible by 3
            } else {
                done = true;	// Accept all others, primes and composites.
            }
        } else {  // Larger numbers have tighter rule set
            if ( ( state->factor == 2 ) || ( candidate % 5 == 0 ) ) {
                if ( gen_random_int ( 1, 61 ) == 8 ) done = true;	// Rarely accept these.
            } else if ( state->factor == 3 ) {
                if ( gen_random_int ( 1, 4 ) == 1 ) done = true;	// Sometimes accept divisible by 3
            } else if ( state->factor == 7 ) {
                if ( gen_random_int ( 1, 2 ) == 1 ) done = true;	// Sometimes accept divisible by 7
            } else if ( state->factor == 11 ) {
                if ( gen_random_int ( 1, 2 ) == 1 ) done = true;	// Sometimes accept divisible by 11
            } else {
                done = true;	// Accept all others, primes and composites.
            }
        }
//    6) Test for correct number type ( prime or composite )
        if ( ( weWantAPrime && !state->isPrime ) || ( !weWantAPrime && state->isPrime ) ) done = false;


    } // END master while loop
    state->lastScore = state->theNumber;
    state->theNumber = candidate;
    if ( state->theNumber > state->high_scores[PN_RACER_HIGH_SCORES-1] ) {
        watch_set_indicator ( WATCH_INDICATOR_24H );
        watch_set_indicator ( WATCH_INDICATOR_PM );
    }
    if ( state->theNumber > state->high_scores[0] ) watch_set_indicator ( WATCH_INDICATOR_LAP );
}


// ---------------------------
// Standard watch face methods
// ---------------------------
void pn_racer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(pn_racer_state_t));
        memset(*context_ptr, 0, sizeof(pn_racer_state_t));
    }
    pn_racer_state_t *state = (pn_racer_state_t *)*context_ptr;
    // Emulator only: Seed random number generator
    #if __EMSCRIPTEN__
    srand(time(NULL));
    #endif
    // Read in stored high scores, player_rating etc. from EEPROM.
    uint32_t offset = 0;
    uint8_t base = 10;
    uint32_t size = base + ( PN_RACER_HIGH_SCORES * 3 ); // How many bytes we want
    uint8_t stored_data [ size ];
    uint8_t i;
    // Do the actual read
    watch_storage_read (PN_RACER_STORAGE_ROW, offset, stored_data, size);
    // See if data was ever written to EEPROM storage
    if ( stored_data[0] == PN_RACER_STORAGE_KEY_NUMBER )
    {
        state->game_counter          = stored_data [1] * 256;
        state->game_counter         += stored_data [2];
        state->failed_counter        = stored_data [3] * 256;
        state->failed_counter       += stored_data [4];
        state->high_average          = stored_data [5] * 256;
        state->high_average         += stored_data [6];
        state->high_single           = stored_data [7] * 256;
        state->high_single          += stored_data [8];
        state->high_round_number     = stored_data [9];
	// High score data in bytes 10 thru N
        for ( i = 0; i < PN_RACER_HIGH_SCORES; i++ )
        {
            state->high_scores[i]    = stored_data [ base + ( i * 3 ) + 0 ] * 65536;
            state->high_scores[i]   += stored_data [ base + ( i * 3 ) + 1 ] * 256;
            state->high_scores[i]   += stored_data [ base + ( i * 3 ) + 2 ];
        }
        state->write_pending=false;
    }
    else
    {
        pn_racer_reset(state);
        state->write_pending=false;
    }
    pn_racer_calc_current_average ( state );
    state->lastScore = 0;
}

void pn_racer_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    pn_racer_state_t *state = (pn_racer_state_t *)context;
    movement_request_tick_frequency(PN_RACER_TICK_FREQUENCY);
    state->mode = MODE_WAITING_TO_START;
    state->reset_counter = 0;
    state->aux_display_mode = 0;
    watch_clear_all_indicators ( );
    // No fancy intro
    watch_display_string("PH        ", 0);
    state->tick_counter = 0;
    state->score_disp_index = PN_RACER_HIGH_SCORES+1;	// Prepare to jump in and show overall score as first number
}

bool pn_racer_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    pn_racer_state_t *state = (pn_racer_state_t *)context;
    char buf [ 20 ];	// [11] is more correct and works; compiler too helpful.
    char smallBuf [ 3 ];	// Contains accompanying characters like "1", "2", "3", "4", or " ".
    uint32_t thisScore=0;	// Score we want to display in waiting to start mode.
    bool user_picked_composite = 0;		// During gameplay
    bool user_picked_prime = 0;			// During gameplay
    uint16_t tempVal;
    uint8_t myRound;    // Round number to display
    int16_t i;

    switch (event.event_type) {
        case EVENT_TICK:
            state->tick_counter++;
            if ( state->mode == MODE_WAITING_TO_START ) {
                // While waiting, we display the high score list and the last score until
                // the user starts the next game.
                if ( state->tick_counter == 1 ) {	// We should be printing some new score now
                    if ( state->score_disp_index < PN_RACER_HIGH_SCORES ) {
                        thisScore = state->high_scores[state->score_disp_index];	// Which high score
                        sprintf ( smallBuf, "%2d", state->score_disp_index + 1 );
                        if ( thisScore < 2 ) state->score_disp_index = PN_RACER_HIGH_SCORES; // Skip ahead
                    }
                    if ( state->score_disp_index == PN_RACER_HIGH_SCORES+0 ) {
                        thisScore = state->theNumber;	// Score of last game played
                        sprintf ( smallBuf, "LA" );
                    }
                    if ( state->score_disp_index == PN_RACER_HIGH_SCORES+1 ) {
                        thisScore = state->current_average;	// Current average
                        sprintf ( smallBuf, "SC" );
                    }
                    if ( state->score_disp_index == PN_RACER_HIGH_SCORES+2 ) {
                        thisScore = state->high_average;	// Highest average
                        sprintf ( smallBuf, "HA" );
                    }
                    if ( state->score_disp_index == PN_RACER_HIGH_SCORES+3 ) {
                        thisScore = state->high_single;	// Highest single
                        sprintf ( smallBuf, "HS" );
                    }
                    if ( thisScore <= 9999 ) {	// Normal case
                        sprintf ( buf, "%4ld%s", thisScore, smallBuf );
                    } else if ( thisScore <= 99999 ) { // Pretty big score
                        sprintf ( buf, "%5ld ", thisScore );
                    } else {		// Huge 6 digit score
                        sprintf ( buf, "%6ld", thisScore );
                    }
                    watch_display_string ( buf, 4 ); // display this score
                } // End if tick_counter == 1
                // Blink if current overall score is best score
                if ( ( state->score_disp_index == PN_RACER_HIGH_SCORES+1 ) && ( state->current_average >= state->high_average ) ) {
                    if ( state->tick_counter % 4 == 3 ) {
                        watch_display_string ( "    SC", 4 );
                    } else if ( state->tick_counter % 4 == 1 ) {
                        sprintf ( buf, "%4dSC", state->current_average );
                        watch_display_string ( buf, 4 );
                    }
                }
                // Check if current display has timed out.
                if ( ( state->score_disp_index < PN_RACER_HIGH_SCORES ) && ( state->tick_counter >= 3 ) ) {
                    // Advance to next score
                    state->score_disp_index++;
                    state->tick_counter = 0;
                } else if ( state->score_disp_index == PN_RACER_HIGH_SCORES+1 ) {
                    if ( state->tick_counter >= 16 ) {
                        state->score_disp_index++;
                        state->tick_counter = 0;
                    }
                } else if ( ( state->score_disp_index >= PN_RACER_HIGH_SCORES ) && ( state->tick_counter >= 8 ) ) {
                    // Advance to next score
                    state->score_disp_index++;
                    state->tick_counter = 0;
                    if ( state->score_disp_index > PN_RACER_HIGH_SCORES+3 ) state->score_disp_index = 0;
                }
            }	// End if MODE_WAITING_TO_START
            else if ( state->mode == MODE_PLAYING ) {
                // Only need to decrement the timer while waiting for some button to be pressed.
               if ( state->game_timer > 0 ) {
                    state->game_timer--;
                    tempVal = state->game_timer / PN_RACER_TICK_FREQUENCY;
                    if ( tempVal > 99 ) tempVal = 99;
                    sprintf ( buf, "%2d", tempVal );
                    watch_display_string ( buf, 8 );
                }  // ELSE do nothing if timer runs out - waiting on final button press
            }   // End if MODE_PLAYING
            break;  // End case EVENT_TICK
        case EVENT_ALARM_BUTTON_DOWN:
            if ( ( state->mode == MODE_WAITING_TO_START ) ||
                 ( state->mode == MODE_DISPLAY_AUXILIARY_DATA ) )  {
                // That was the go signal - start a new game!!
                state->lastScore = 0;
                state->round_number = 0;
                state->game_counter++;
                watch_clear_all_indicators ( );
                watch_display_string("PH        ", 0);
                delay_ms ( 250 );
                state->game_timer =  40;
                state->aux_display_mode = 0;
                state->write_pending = true;
                // Generate and print starting number
                pn_racer_new_number(state);
                myRound = state->round_number;
                if ( myRound > 39 ) myRound = 39;
                sprintf ( buf, "%2d%4ld%2d", myRound, state->theNumber, state->game_timer );
                watch_display_string ( buf, 2 );
                // We are playing!
                state->mode = MODE_PLAYING;
            } else if ( state->mode == MODE_PLAYING ) {
                // User picked composite button during gameplay
                if ( state->tick_counter >= 2 ) user_picked_composite = true; // Debounce
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (state->write_pending) {
                write_to_pn_racer_EEPROM(state);
                watch_storage_sync ( );
                state->write_pending=false;
            }
            watch_display_string("SLEEP ", 4);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if ( ( state->mode == MODE_WAITING_TO_START ) ||
                 ( state->mode == MODE_DISPLAY_AUXILIARY_DATA ) )  {
                state->mode = MODE_DISPLAY_AUXILIARY_DATA;
                watch_clear_all_indicators ( );
                if ( state->aux_display_mode == 0 ) {
                    // Display highest average
                    sprintf ( buf, "%4dHA", state->high_average );
                } else if ( state->aux_display_mode == 1 ) {
                    // Display current average
                    sprintf ( buf, "%4dSC", state->current_average );
                } else if ( state->aux_display_mode == 2 ) {
                    // Display highest single ever
                    sprintf ( buf, "%4dHS", state->high_single );
                } else if ( state->aux_display_mode == 3 ) {
                    // Display last number
                    sprintf ( buf, "%4ldLA", state->theNumber );
                } else if ( state->aux_display_mode == 4 ) {
                    // Display game counter
                    sprintf ( buf, "%4dCO", state->game_counter );
                } else if ( state->aux_display_mode == 5 ) {
                    // Display failed counter
                    sprintf ( buf, "%4dFA", state->failed_counter );
                } else {
                    // Display version number
                    sprintf ( buf, " vEr%2d", PN_RACER_VERSION_NUMBER );
                }
                watch_display_string ( buf, 4 );
                state->aux_display_mode++;
                state->aux_display_mode = state->aux_display_mode % 7;
            } else if ( state->mode == MODE_PLAYING ) {
               // User picked prime button during gameplay
                if ( state->tick_counter >= 2 ) user_picked_prime = true;  // Debounce
            }
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    if ( user_picked_prime || user_picked_composite ) {
        // End of current number - process this entry
        bool entry_correct = false;
        state->tick_counter = 0;
        if ( user_picked_prime && state->isPrime ) entry_correct = true; 
        if ( user_picked_composite && !state->isPrime ) entry_correct = true;
        if ( entry_correct ) {
            state->lastScore = state->theNumber;
            if ( state->game_timer > 0 ) {
                // Reward time counter
                 if ( state->theNumber < 100 ) {
                     state->game_timer += ( 3 * PN_RACER_TICK_FREQUENCY );	// 3 seconds
                 } else if ( state->theNumber < 500 ) {
                     state->game_timer += ( 6 * PN_RACER_TICK_FREQUENCY );	// 6 seconds
                 } else {
                     state->game_timer += ( 10 * PN_RACER_TICK_FREQUENCY );	// 10 seconds
                 }
                 // Advance candidate number
                 pn_racer_new_number(state);
                 myRound = state->round_number;
                 if ( myRound > 39 ) myRound = 39;
                 sprintf ( buf, "%2d%4ld", myRound, state->theNumber );
                 watch_display_string ( buf, 2 );
            } else {  // Correct, but out of time
                state->mode = MODE_WAITING_TO_START;
                watch_display_string ( "      ", 4 );
                delay_ms ( 500 );
            }
        } else {
            state->failed_counter++;
            if ( user_picked_prime ) {
                if ( state->factor <= 99 ) sprintf ( buf, "COmP%2ld", state->factor );
                else sprintf ( buf, "COmP  " );
           } else sprintf ( buf, " PrImE" );
            watch_display_string ( buf, 4 );
            delay_ms ( 1500 );
            state->mode = MODE_WAITING_TO_START;
        }
        if ( state->mode == MODE_WAITING_TO_START ) {	// The game has ended.
            if ( entry_correct ) {
                pn_racer_update_high_scores (state);
            } else {
                pn_racer_forfeit_one_high (state);
            }
            pn_racer_calc_current_average ( state );
            // Show new average
            sprintf ( buf, "%4dCA", state->current_average );
            watch_display_string ( buf, 4 );
            delay_ms ( 1000 );
            // Show highest average
            sprintf ( buf, "%4dHA", state->high_average );
            watch_display_string ( buf, 4 );
            delay_ms ( 1000 );
            // Check for new highest average
            if ( state->current_average > state->high_average )
            {
                state->high_average = state->current_average;
                sprintf ( buf, "%4d", state->high_average );
                watch_display_string ( buf, 4 );
                for ( i = 0; i < 10; i++ )
                {
                    watch_display_string ( "  ", 8 );
                    delay_ms (100);
                    watch_display_string ( "HA", 8 );
                    delay_ms (100);
                }
            }
            state->score_disp_index = PN_RACER_HIGH_SCORES;
            state->tick_counter = 0;
            if ( state->round_number > 1 ) state->reset_counter = 0;
            else {
                state->reset_counter++;
                if ( state->reset_counter <= 2 ) {
                    watch_display_string ( " LOSEr", 4 );
                    delay_ms ( 1000 );
                }
            }
            if ( state->reset_counter >= 6 ) {
                pn_racer_reset(state);
                watch_display_string ( "  rESET ", 2 );
                delay_ms(2000);
            }
        }
    }

    return true;
}

void pn_racer_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    pn_racer_state_t *state = (pn_racer_state_t *)context;
    watch_set_led_off ( );
    if (state->write_pending) {
        write_to_pn_racer_EEPROM(state);
        state->write_pending=false;
    }
}

