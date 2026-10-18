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

// SEE prime_hunter_face.h FOR GAME PLAY DOCUMENTATION

// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "prime_hunter_face.h"

#define PNH_TICK_FREQUENCY 8
#define MODE_WAITING_TO_START 0
#define MODE_LEVEL_SELECT 1
#define MODE_PLAYING 2
#define MODE_DISPLAY_AUXILIARY_DATA 3

#define ROUND_TOTAL_SECONDS 50
#define ROUND_GOAL_CORRECT  12
#define ROUND_STRIKE_PENALTY 3
#define NORMAL_ROUNDS 3
#define RATIO_ACE 0.35
#define RATIO_PROMOTE 0.65
#define SAFARI_COST 563
#define MIN_SAFARI_FLOOR 200
#define SAFARI_NEXT 1.3
#define SAFARI_RANGE 1.60
#define STAGGER_BASE 1.316

#define ATTRACT_LEVEL 0
#define ATTRACT_COUNTRY 1
#define ATTRACT_HIGH_TITLE 2
#define ATTRACT_HIGH_SCORES 3
#define ATTRACT_LAST_SAFARI 4
#define ATTRACT_NUMBERS 5
#define ATTRACT_CROUTONS 6
#define NUM_RANDOM_ATTRACT 5

// Ver 19 has minor cosmetic attract mode bug fix over ver 17
#define PNH_VERSION_NUMBER 19
// Joey Castillo to oversee storage allocation row
#define PNH_STORAGE_ROW 3
#define PNH_STORAGE_KEY_NUMBER 31

#define STANDARD_COUNTRIES 6
#define BONUS_COUNTRIES 3
char pnh_countries[STANDARD_COUNTRIES + BONUS_COUNTRIES][7] =
    { "IdaHO ", "CAnAdA", " PErU ", "SWEdEn", " FIJI ", "aFrICA", "VULCAN", " MarS ", " ArUbA" };


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

static void write_to_pnh_EEPROM(pnh_state_t *state) {
    uint8_t base = 15;
    uint8_t size = base + ( PNH_HIGH_SCORES * 3 );	// Length of data
    uint8_t output_array [ size ];
    uint8_t offset = 0;
    uint8_t i;
    uint32_t tempVal;

    output_array [ 0 ] = PNH_STORAGE_KEY_NUMBER;
    tempVal = state->croutonTotal;
    output_array [ 3 ] = tempVal % 256;
    tempVal = tempVal / 256;
    output_array [ 2 ] = tempVal % 256;
    output_array [ 1 ] = tempVal / 256;
    output_array [ 4 ] = state->game_counter / 256;
    output_array [ 5 ] = state->game_counter % 256;
    output_array [ 6 ] = state->safari_counter / 256;
    output_array [ 7 ] = state->safari_counter % 256;
    output_array [ 8 ] = state->safari_win_counter / 256;
    output_array [ 9 ] = state->safari_win_counter % 256;
    output_array [ 10 ] = state->mauled_counter / 256;
    output_array [ 11 ] = state->mauled_counter % 256;
    output_array [ 12 ] = state->defaultStartLevel;
    output_array [ 13 ] = state->country_code;
    output_array [ 14 ] = state->special_country;
    // 15 thru 26 used for 12 bytes of high score storage
    for ( i = 0; i < PNH_HIGH_SCORES; i++ )
    {
        tempVal = state->high_scores [ i ];
        output_array [ base + ( i * 3 ) + 2 ] = tempVal % 256;
        tempVal = tempVal / 256;
        output_array [ base + ( i * 3 ) + 1 ] = tempVal % 256;
        output_array [ base + ( i * 3 ) + 0 ] = tempVal / 256;
    }
    watch_storage_erase ( PNH_STORAGE_ROW );
    watch_storage_sync ( );
    watch_storage_write ( PNH_STORAGE_ROW, offset, output_array, size );
}

// Calculate minLimit for safari candidate numbers
// Based strictly on country you are in, except for highest level
static int16_t calc_safari_min (pnh_state_t *state) {
    int16_t minLimit;
    float myBase;
    uint8_t myCountryCode;
    myCountryCode = state->country_code;
    if ( myCountryCode > STANDARD_COUNTRIES - 1 ) myCountryCode = STANDARD_COUNTRIES - 1;
    myBase = pow ( STAGGER_BASE, myCountryCode );  // Starting value will be 1.00 for country 0.
    minLimit = myBase * MIN_SAFARI_FLOOR;
    // For highest country only, minLimit shouldn't be much less than lowest high score.
    if ( myCountryCode >= ( STANDARD_COUNTRIES - 1 ) ) {
        if ( minLimit < 0.96* state->high_scores[PNH_HIGH_SCORES-1] ) minLimit = 0.96 * state->high_scores[PNH_HIGH_SCORES-1];
    }
    return minLimit;
}

// Generate next candidate number
static void pnh_new_number(pnh_state_t *state, uint8_t probPercentPrime ) {
    uint16_t i, testLim;
    uint32_t minLimit, maxLimit;
    uint32_t candidate;
    bool done;
    bool weWantAPrime;

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
    8) Do not repeat last number
END LOOP
*/

// 1) Calc boolean weWantAPrime;
    if ( gen_random_int ( 0, 99 ) < probPercentPrime  ) weWantAPrime = true;
    else weWantAPrime = false;

// 2) Calc min and max
    if ( state->mode != MODE_WAITING_TO_START ) {
        minLimit = 2;
        maxLimit = 100 * state->currentLevel;
        if ( ( state->currentLevel > 2 ) && ( gen_random_int ( 1, 2 ) == 2 ) )
        {
            minLimit = maxLimit - 199;
        }
        if ( state->safari_mode ) {  // Safari mode
            minLimit = calc_safari_min ( state );
            maxLimit = minLimit * SAFARI_RANGE;   // Likely around 1.5 times min.
            if ( state->country_code >= ( STANDARD_COUNTRIES - 1 ) ) {  // On highest level, ensure top value is assailable.
                if ( maxLimit < (state->high_scores[0]+100) ) maxLimit = state->high_scores[0] + 100;
            }
        }
    } else { // Demo/attract mode
        minLimit = 2;
        maxLimit = 9999;
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

//    7) If safari mode, reject numbers already on high score list
        if ( done && state->safari_mode ) {
            for ( i = 0; i < PNH_HIGH_SCORES; i++ ) {
                if ( candidate == state->high_scores[i] ) done = false;
            }
        }
//    8) Do not repeat last number
        if ( state->theNumber == candidate ) done = false;

    } // END master while loop
    state->theNumber = candidate;
    state->numCount++;
    if ( state->safari_mode ) state->lastSafariNumber = state->theNumber;
}

// Reset all stats and high scores
static void pnh_reset(pnh_state_t *state) {
    state->game_counter = 0;
    state->safari_counter = 0;
    state->safari_win_counter = 0;
    state->mauled_counter = 0;
    state->croutonTotal = 0;
    state->high_scores [ 0 ] = 5;
    state->high_scores [ 1 ] = 3;
    state->high_scores [ 2 ] = 2;
    state->defaultStartLevel = 1;
    state->country_code = 0;
    // Permanently choose ultimate destination.  Unless you get eaten and start over.
    state->special_country = gen_random_int ( STANDARD_COUNTRIES, STANDARD_COUNTRIES + BONUS_COUNTRIES - 1 );
}

// Country code based on existing high scores
static int8_t calc_country_code(pnh_state_t *state) {
    uint32_t totalHigh;
    int16_t country_code;
    float avgScore;
    bool done;
    uint8_t i;
    float myBase;	// 1, 1.3, 2, 2.6, 4, 5.6, 8
    int32_t minLimit;
    int32_t minAvg;    // If avgScore exceeds this, bump to next level
//    char shortBuf [4];
    totalHigh = 0;
    for ( i = 0; i < PNH_HIGH_SCORES; i++ ) totalHigh += state->high_scores[i];
    avgScore = totalHigh / PNH_HIGH_SCORES;
    country_code = 0;
    done = false;
    while ( ! done ) {
        // Calc min avg score to beat this country
        myBase = pow (  STAGGER_BASE, country_code );
        minLimit = myBase * MIN_SAFARI_FLOOR;
        minAvg = minLimit * SAFARI_NEXT;
        if ( avgScore >= minAvg ) country_code++;  // Check against next country level
        else done = true;
    }
//    sprintf ( shortBuf, "%2d", country_code );
//    watch_display_string ( shortBuf, 2 );
    if ( country_code > STANDARD_COUNTRIES - 1 ) { // Getting into very high territory
        // Keep on the planet?
        if ( country_code <= STANDARD_COUNTRIES + 5 ) country_code = STANDARD_COUNTRIES - 1;
        else { // Player reached maximum limit - use fixed special country/planet.
            country_code = state->special_country;
        }
    }
    return (int8_t) country_code;
}


// Update high score list if applicable
static void pnh_update_high_scores(pnh_state_t *state) {
    int8_t i, rank;
    uint32_t temp;
    char buf[11];
    if ( state->theNumber >= state->high_scores[PNH_HIGH_SCORES-1] ) {
        state->high_scores[PNH_HIGH_SCORES-1] = state->theNumber;
        rank = PNH_HIGH_SCORES;
        for ( i = PNH_HIGH_SCORES-2; i >= 0; i-- ) {
            if ( state->high_scores[i] < state->high_scores[i+1] ) {	// Swap
                temp = state->high_scores[i];
                state->high_scores[i] = state->high_scores[i+1];
                state->high_scores[i+1] = temp;
                rank = i + 1;
            }
        }
        // Blink new score and ranking a few times
        sprintf ( buf, "%4ld%2d", state->theNumber,rank );
        for ( i = 0; i < 8; i++ ) {
            watch_display_string ( "    ", 4 );
            delay_ms ( 125 );
            watch_display_string ( buf, 4 );
            delay_ms ( 125 );
        }
    }
}

// Remove a random high score from list
static void pnh_forfeit_one_high(pnh_state_t *state) {
    int8_t i;
    int8_t numTargets;
    int8_t myTarget;	// Index to erase
    char buf[11];
    // First pick a score
    // How many are there?
    numTargets = 0;
    myTarget = -1;
    for ( i = 0; i < PNH_HIGH_SCORES; i++ )
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
        // Fade in a zero
        for ( i = 0; i < 5; i++ ) {
           watch_display_string ( "    ", 4 );
           delay_ms ( 200 - (i*25) );
           watch_display_string ( "   0", 4 );
           delay_ms ( 200 + (i*25) );
        }
        // And now bubble lower scores up to fill this slot.
        for ( i = myTarget; i < PNH_HIGH_SCORES-1; i++ ) state->high_scores[i] = state->high_scores[i+1];
        state->high_scores[PNH_HIGH_SCORES-1] = 0;
    }
}


// Remove all high scores from list
static void pnh_forfeit_all_high(pnh_state_t *state) {
    int8_t i, j;
    char buf[11];
    for ( i = PNH_HIGH_SCORES-1; i >= 0; i-- )
    {
        if ( state->high_scores [ i ] > 10 ) {
            sprintf ( buf, "%4ld%2d", state->high_scores[i], i+1 );
            watch_display_string ( buf, 4 );
            delay_ms ( 1000 );
            // Fade out existing score
            for ( j = 0; j < 5; j++ ) {
               watch_display_string ( buf, 4 );
               delay_ms ( 200 - (j*25) );
               watch_display_string ( "    ", 4 );
               delay_ms ( 200 + (j*25) );
            }
            watch_display_string ( "   0", 4 );
            delay_ms ( 600 );
        }
        state->high_scores[i] = 0;
    }
    watch_display_string ( "NYah  ", 4 );
    delay_ms ( 600 );
    watch_display_string ( "    ", 4 );
    delay_ms ( 400 );
    watch_display_string ( "NYah  ", 4 );
    delay_ms ( 1600 );
}


static void pnh_update_attract(pnh_state_t *state) { // Game attraction mode while no one is playing
    uint32_t myScore, myCroutons;
    char buf[11], smallBuf[3];

// Increase the state->attract_index, unless in multiple entry displays like
// high scores or randomly generated numbers.

    // Calculate next entry to display
    if ( state->attract_index == ATTRACT_HIGH_SCORES ) {  // High score list
        state->attract_count++;
        if ( state->attract_count >= PNH_HIGH_SCORES ) {
            state->attract_index++;
            state->attract_count = 0;
       }
    } else if ( state->attract_index == ATTRACT_NUMBERS ) {
        state->attract_count++;
        if ( state->attract_count >= NUM_RANDOM_ATTRACT ) {  // How many randomly gen numbers to show
            state->attract_index++;
            state->attract_count = 0;
        }
    } else if ( state->attract_index == ATTRACT_CROUTONS ) {
        state->attract_index = 0;
    }
    else state->attract_index++;

    // We now know what we want to show!
    switch (state->attract_index) {
        case ATTRACT_HIGH_TITLE:
            sprintf ( buf, "HIgH  " );
            break;
        case ATTRACT_HIGH_SCORES:
            myScore = state->high_scores[state->attract_count];
            if ( myScore <= 9999 ) sprintf ( buf, "%4ld%2d", myScore, state->attract_count+1 );
            else sprintf ( buf, "%6ld", myScore );
            break;
        case ATTRACT_LAST_SAFARI:
            myScore = state->lastSafariNumber;
            if ( myScore <= 9999 ) sprintf ( buf, "%4ld L", myScore );
            else sprintf ( buf, "%6ld", myScore );
            break;
        case ATTRACT_CROUTONS:
            myCroutons = state->croutonTotal;
            if ( ( myCroutons <= 9999 ) || ( gen_random_int(0,3)!= 2 ) ) {
                if ( myCroutons > 9999 ) myCroutons = 9999;
                sprintf ( buf, "%4ldCr", myCroutons );
            } else sprintf ( buf, "%6ld", myCroutons );
            break;
        case ATTRACT_LEVEL:
            sprintf ( buf, " L%2d  ", state->defaultStartLevel );
            break;
        case ATTRACT_COUNTRY:
            sprintf ( buf, "%s", pnh_countries[state->country_code] );
            break;
        case ATTRACT_NUMBERS:
            pnh_new_number ( state, 61 ); // Usually prime
            if ( state->isPrime ) sprintf ( smallBuf, "P" );
            else sprintf ( smallBuf, "C" );
            sprintf ( buf, "%4ld %s", state->theNumber, smallBuf );
            break;
        default:
            sprintf ( buf, "LOSEr " );
            break;
    }
    watch_display_string ( buf, 4 );
}


// Start next round
static void pnh_start_next_round(pnh_state_t *state) {
    char buf [11];
    uint8_t probPrime;    // Percent chance we'd like a prime number
    int8_t new_country_code;
    state->numCorrect = 0;
    state->numStrikes = 0;
    state->numCount = 0;
    state->roundNumber++;
    state->currentLevel++;
    state->game_timer = ROUND_TOTAL_SECONDS * PNH_TICK_FREQUENCY;
    state->tickCounter = 0;
    state->safari_mode = false;
    // Display level intro
    if ( state->roundNumber > 1 ) {
        if ( state->roundNumber <= NORMAL_ROUNDS ) {
            sprintf ( buf, " L%2d  ", state->currentLevel );
            watch_display_string ( buf, 4 );
            delay_ms ( 750 );
            watch_display_string ( "    ", 4 );
            delay_ms ( 200 );
        } else {  // Safari
            state->safari_mode = true;
            state->safari_counter++;
            watch_display_string ( "SFari ", 4 );
            delay_ms ( 750 );
        }
    }

    // Generate and print starting number
    probPrime = 50;  // Normal play
    if ( state->safari_mode ) { // Starting safari
        new_country_code = calc_country_code(state);
        // Show old country
        sprintf ( buf, "%s", pnh_countries[state->country_code] );
        watch_display_string ( buf, 4 );
        delay_ms ( 1800 );
        // If a change (improvement), show new country now
        if ( new_country_code != state->country_code ) {
            watch_display_string ( "      ", 4 );
            delay_ms ( 500 );
            sprintf ( buf, "%s", pnh_countries[new_country_code] );
            watch_display_string ( buf, 4 );
            delay_ms ( 1500 );
            state->country_code = new_country_code;
        }
    }
    watch_display_string ( "      ", 4 );
    delay_ms ( 300 );
    pnh_new_number(state,probPrime);
    sprintf ( buf, "%4ld  ", state->theNumber );
    watch_display_string ( buf, 4 );
}

// ---------------------------
// Standard watch face methods
// ---------------------------
void prime_hunter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(pnh_state_t));
        memset(*context_ptr, 0, sizeof(pnh_state_t));
    }
    pnh_state_t *state = (pnh_state_t *)*context_ptr;
    // Emulator only: Seed random number generator
    #if __EMSCRIPTEN__
    srand(time(NULL));
    #endif
    // Read in stored high scores, gameCounter etc. from EEPROM.
    uint32_t offset = 0;
    uint8_t base = 15;
    uint32_t size = base + ( 3 * PNH_HIGH_SCORES ); // How many bytes we want
    uint8_t stored_data [ size ];
    uint8_t i;
    // Do the actual read
    watch_storage_read (PNH_STORAGE_ROW, offset, stored_data, size);
    // See if data was ever written to EEPROM storage
    if  ( stored_data[0] == PNH_STORAGE_KEY_NUMBER )
    {
        state->croutonTotal           = stored_data [1] * 65536;
        state->croutonTotal          += stored_data [2] * 256;
        state->croutonTotal          += stored_data [3];
        state->game_counter           = stored_data [4] * 256;
        state->game_counter          += stored_data [5];
        state->safari_counter         = stored_data [6] * 256;
        state->safari_counter        += stored_data [7];
        state->safari_win_counter     = stored_data [8] * 256;
        state->safari_win_counter    += stored_data [9];
        state->mauled_counter         = stored_data [10] * 256;
        state->mauled_counter        += stored_data [11];
        state->defaultStartLevel      = stored_data [12];
        state->country_code           = stored_data [13];
        state->special_country        = stored_data [14];
	// High score data in bytes 15 thru 23
        for ( i = 0; i < PNH_HIGH_SCORES; i++ )
        {
            state->high_scores[i]    = stored_data [ base + ( i * 3 ) + 0 ] * 65536;
            state->high_scores[i]   += stored_data [ base + ( i * 3 ) + 1 ] * 256;
            state->high_scores[i]   += stored_data [ base + ( i * 3 ) + 2 ];
        }
        state->write_pending=false;
    }
    else
    {
        pnh_reset(state);
        state->write_pending=false;
/*
        state->high_scores[0]=2287;
        state->high_scores[1]=1741;
        state->high_scores[2]=1699;
*/
    }
}

void prime_hunter_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    char buf [11];
    pnh_state_t *state = (pnh_state_t *)context;
    movement_request_tick_frequency(PNH_TICK_FREQUENCY);
    state->mode = MODE_WAITING_TO_START;
    state->reset_counter = 0;
    state->aux_display_mode = 0;
    watch_clear_all_indicators ( );
    // No fancy intro
    watch_display_string("HU  ", 0);
    state->tickCounter = 0;
    state->attract_index = ATTRACT_LEVEL;	        // Show level code as first displayed value
    state->tickCounter = (1.6 * PNH_TICK_FREQUENCY);   // But show it briefly
    state->attract_count = 0;
    sprintf ( buf, " L%2d  ", state->defaultStartLevel );
    watch_display_string ( buf, 4 );
}

bool prime_hunter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    pnh_state_t *state = (pnh_state_t *)context;
    char buf [ 20 ];	// [11] is more correct and works; compiler too helpful.
    bool user_picked_composite = 0;		// During gameplay
    bool user_picked_prime = 0;			// During gameplay
    uint16_t i;

    switch (event.event_type) {
        case EVENT_TICK:
            state->tickCounter++;
            if ( state->mode == MODE_WAITING_TO_START ) {
                // While waiting, we display the high score list and other items until
                // the user starts the next game.
                if ( state->tickCounter == 1 ) {	// We should be printing something new now
                    pnh_update_attract ( state );
                }
                // Check if current display has timed out.
                if ( state->attract_index == ATTRACT_HIGH_SCORES ) {  // High score speed
                    if ( state->tickCounter >= ( 1.6 * PNH_TICK_FREQUENCY ) ) state->tickCounter = 0;
                } else if ( state->attract_index == ATTRACT_LAST_SAFARI ) {  // Last safari number speed
                    if ( state->tickCounter >= ( 1.6 * PNH_TICK_FREQUENCY ) ) state->tickCounter = 0;
                } else if ( state->attract_index == ATTRACT_LEVEL ) {  // Level speed
                    if ( state->tickCounter >= ( 2.1 * PNH_TICK_FREQUENCY ) ) state->tickCounter = 0;
                } else if ( state->attract_index == ATTRACT_COUNTRY ) {  // Country goes slowly
                    if ( state->tickCounter >= ( 3.2 * PNH_TICK_FREQUENCY ) ) state->tickCounter = 0;
                } else {  // All others for now
                    if ( state->tickCounter >= ( 1.4 * PNH_TICK_FREQUENCY ) ) state->tickCounter = 0;
                }
            }	// End if MODE_WAITING_TO_START
            else if ( state->mode == MODE_LEVEL_SELECT ) {
                // Waiting on timeout to start game
               if ( state->tickCounter == 1 ) {
                   if ( state->currentLevel > ( state->defaultStartLevel + 4 ) ) state->currentLevel = 1;
                   sprintf ( buf, " L%2d  ", state->currentLevel );
                   watch_display_string ( buf, 4 );
               }
               if ( state->tickCounter > PNH_TICK_FREQUENCY * 2.0 ) {
                   watch_display_string ( "      ", 4 );
                   delay_ms ( 250 );
                   state->actStartLevel = state->currentLevel;
                   state->currentLevel--;
                   state->roundNumber = 0;
                   state->reset_counter = 0;
                   pnh_start_next_round(state);
                   // Game begins: we are playing!
                   state->mode = MODE_PLAYING;
               }
            }   // End if MODE_PLAYING
            else if ( state->mode == MODE_PLAYING ) {
                // Only need to decrement the timer while waiting for some button to be pressed.
               if ( state->game_timer > 0 ) state->game_timer--;
            }   // End if MODE_PLAYING
            break;  // End case EVENT_TICK
        case EVENT_ALARM_BUTTON_DOWN:
            if ( ( state->mode == MODE_WAITING_TO_START ) ||
                 ( state->mode == MODE_DISPLAY_AUXILIARY_DATA ) )  {
                // That was the go signal - start a new game!!
                state->roundNumber = 0;
                if ( state->defaultStartLevel == 0 ) state->defaultStartLevel = 1;
                state->currentLevel = state->defaultStartLevel - 1;
                state->game_counter++;
                state->write_pending = true;
                pnh_start_next_round(state);
                // Advance to level select menu
                state->mode = MODE_LEVEL_SELECT;
                state->tickCounter = 0;
            } else if ( state->mode == MODE_LEVEL_SELECT ) {
                state->currentLevel++;
                state->tickCounter = 0;
            } else if ( state->mode == MODE_PLAYING ) {
               // User picked composite button during gameplay
                if ( state->tickCounter > 2 ) user_picked_composite = true;  // Debounce
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (state->write_pending) {
                write_to_pnh_EEPROM(state);
                watch_storage_sync ( );
                state->write_pending=false;
            }
            watch_display_string("SLEEP ", 4);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if ( ( state->mode == MODE_WAITING_TO_START ) ||
                 ( state->mode == MODE_DISPLAY_AUXILIARY_DATA ) )  {
                state->mode = MODE_DISPLAY_AUXILIARY_DATA;
                if ( state->aux_display_mode == 0 ) {
                    // Display player croutons total here
                    if ( state->croutonTotal < 10000 ) sprintf ( buf, "%4ldCr", state->croutonTotal );
                    else {
                        watch_display_string ( "CrOUtn", 4 );
                        delay_ms ( 750 );
                        sprintf ( buf, "%6ld", state->croutonTotal );
                    }
                }
                else if ( state->aux_display_mode == 1 ) {
                    // Display game counter
                    if ( state->game_counter < 10000 ) sprintf ( buf, "%4dCO", state->game_counter );
                    else {
                        watch_display_string ( "COUnt ", 4 );
                        delay_ms ( 750 );
                        sprintf ( buf, "%6d", state->game_counter );
                    }
                }
                else if ( state->aux_display_mode == 2 ) {
                    // Display safari counter
                    if ( state->safari_counter < 10000 ) sprintf ( buf, "%4dS1", state->safari_counter );
                    else {
                        watch_display_string ( "SFar 1", 4 );
                        delay_ms ( 750 );
                        sprintf ( buf, "%6d", state->safari_counter );
                    }
                }
                else if ( state->aux_display_mode == 3 ) {
                    // Display safari win counter
                    if ( state->safari_win_counter < 10000 ) sprintf ( buf, "%4dS2", state->safari_win_counter );
                    else {
                        watch_display_string ( "SFar 2", 4 );
                        delay_ms ( 750 );
                        sprintf ( buf, "%6d", state->safari_win_counter );
                    }
                }
                else if ( state->aux_display_mode == 4 ) {
                    // Display mauled counter
                    sprintf ( buf, "%4dMA", state->mauled_counter );
                }
                else {
                    // Display version number
                    sprintf ( buf, " vEr%2d", PNH_VERSION_NUMBER );
                }
                watch_display_string ( buf, 4 );
                state->aux_display_mode++;
                state->aux_display_mode = state->aux_display_mode % 7;
            } else if ( state->mode == MODE_LEVEL_SELECT ) {
                state->currentLevel++;
                state->tickCounter = 0;
            } else if ( state->mode == MODE_PLAYING ) {
                // User picked prime button during gameplay
                if ( state->tickCounter > 2 ) user_picked_prime = true; // Debounce
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if ( ( state->mode == MODE_WAITING_TO_START ) ||
                 ( state->mode == MODE_DISPLAY_AUXILIARY_DATA ) ) {
                state->reset_counter++;
                if ( state->reset_counter == 3 ) {
                    state->croutonTotal = 0;
                    state->game_counter = 0;
                    watch_display_string ( "CLEAr ", 4 );
                    state->tickCounter = 1;
                } else if (state->reset_counter <= 5 ) {
                    sprintf ( buf, "rESET%d", state->reset_counter );
                    watch_display_string ( buf, 4 );
                    state->tickCounter = 1; // Avoid quick front end overwrites
                } else {
                    for ( i = 0; i < 5; i++ ) {
                        watch_display_string ( "      ", 4 );
                        delay_ms ( 150 );
                        watch_display_string ( "rESET ", 4 );
                        delay_ms ( 150 );
                    }
                    delay_ms ( 300 );
                    pnh_reset(state);
                    state->write_pending = true;
                }
            }
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    } // END massive event switch statement


    if ( user_picked_prime || user_picked_composite ) {
/*
    User has picked prime or comp, many things happen here
    1) Determine if this entry is correct
    2) Determine if round is over
    IF not round over
        3) Generate a new number
    ELSE round is over
        IF not safari
            4) Show round wins and strikes
            5) Calculate and show payout
            6) Determine if game is over or advance to next level
        ELSE safari round ending
            7) Set game over status
            8) Update high scores or apply damage as appropriate
                ELSE - incorrect
                    10) "OUCH"
                    11) Check for EATEN or MAULED conditions
        END ELSE safari
    END ELSE round is over
*/
        bool entry_correct = false;
        bool roundCompleted = false;
        bool gameOver = false;
        bool noCash = false;  // Not enough money for safari
        bool playerMauled = false;
        bool playerEaten = false;
        int8_t currentScore, deltaScore;
        float unusedTicksRatio, bonusMult;
        uint16_t croutons;   // Money earned this round.
        uint16_t bonusCroutons;
        int16_t croutonsLost;
        uint8_t aceBonus;
        uint8_t probPrime;  // Likely we want a prime, as a percentage
        uint8_t new_country_code;

        // 1) Determine if this entry is correct
        if ( user_picked_prime && state->isPrime ) entry_correct = true;
        if ( user_picked_composite && !state->isPrime ) entry_correct = true;
        if ( entry_correct ) state->numCorrect++;
        else {
            state->numStrikes++;
            if ( user_picked_prime ) {
                if ( state->factor <= 99 ) sprintf ( buf, "COmP%2d", state->factor );
                else sprintf ( buf, "%4dCO", state->factor );
                watch_display_string ( buf, 4 );
                delay_ms ( 1300 );
            } else {
                watch_display_string ( " PrImE", 4 );
                delay_ms ( 600 );
            }
        }

        // 2) Determine if round is over
        deltaScore = (int8_t) state->numCorrect - (int8_t) ( state->numStrikes * 1.51 );
        if ( !state->safari_mode ) { // Normal mode - not safari
            if ( ( deltaScore >= ROUND_GOAL_CORRECT ) || ( state->numStrikes > 4 ) || ( state->game_timer == 0 ) ) {
                roundCompleted = true;
            }
        } else {    // Safari mode
            if ( ( !entry_correct ) ||      // Stop safari on any wrong answer
                 ( state->numCount >= 5 ) ) {  // At most 5 targets per safari
                roundCompleted = true;
            }
            // We'll also stop if this number is prime AND worthy of the high score list
            if ( ( state->isPrime ) && ( state->theNumber > state->high_scores[PNH_HIGH_SCORES-1] ) ) {
                roundCompleted = true;
                if ( entry_correct ) state->safari_win_counter++;
            }
        }

        // IF not round over
         if ( !roundCompleted ) {

            // 3) Generate a new number
            probPrime = 50; // Normal case
            if ( state->safari_mode ) probPrime = 50;   // Safari mode - redundant unless % changes
            pnh_new_number(state,probPrime);
            sprintf ( buf, "%4ld  ", state->theNumber );
            watch_display_string ( buf, 4 );
            state->tickCounter = 0;
        } else { // ELSE round is over

             //   IF not safari
            if ( !state->safari_mode ) { /// End of a normal round

                // 5) Calculate and show wins, strikes and payout
                watch_display_string ( "      ", 4 );
                delay_ms ( 300 );
                currentScore = (int16_t) state->numCorrect - (int16_t) ( state->numStrikes * ROUND_STRIKE_PENALTY );
                if ( currentScore < 0 ) currentScore = 0;
                unusedTicksRatio = (float) state->game_timer / (float) ( ROUND_TOTAL_SECONDS * PNH_TICK_FREQUENCY );
                if ( unusedTicksRatio >= RATIO_ACE ) {
                    watch_set_indicator ( WATCH_INDICATOR_SIGNAL );
                    watch_set_indicator ( WATCH_INDICATOR_PM );
                }
                if ( unusedTicksRatio >= RATIO_PROMOTE ) watch_set_indicator ( WATCH_INDICATOR_LAP );
                sprintf ( buf, "%2d%2d%2d", state->numCorrect, state->numStrikes, currentScore );
                watch_display_string ( buf, 4 );
                delay_ms ( 1000 );
                bonusMult = 1.0 + unusedTicksRatio;  // Some value between 1 and 2
                if ( ( state->numStrikes == 0 ) && ( state->numCorrect==ROUND_GOAL_CORRECT ) && ( unusedTicksRatio > RATIO_ACE ) ) {
                    watch_display_string ( " ACE  ", 4 );
                    delay_ms ( 800 );
                    watch_display_string ( "      ", 4 );
                    delay_ms ( 150 );
                    aceBonus = ROUND_GOAL_CORRECT * 0.5;
                    if ( unusedTicksRatio > RATIO_PROMOTE ) { // Promote starting level
                        if ( state->currentLevel > state->defaultStartLevel ) {
                            watch_display_string ( " PrmtE", 4 );
                            delay_ms ( 1500 );
                            watch_display_string ( " bonUS", 4 );
                            delay_ms ( 1500 );
                            bonusCroutons = SAFARI_COST;
                            state->croutonTotal += bonusCroutons;
                            sprintf ( buf, "%4dCr", bonusCroutons );
                            watch_display_string ( buf, 4 );
                            delay_ms ( 1500 );
                            watch_display_string ( "      ", 4 );
                            delay_ms ( 500 );
                            state->defaultStartLevel = state->currentLevel;  // You are good enough to start here next game.
                        }
                    }
                } else aceBonus = 0;
                croutons = (uint16_t) ( bonusMult * (float) ( currentScore + aceBonus ) * (float) ( state->currentLevel + 2 ) );
                state->croutonTotal += croutons;
                sprintf ( buf, "%4dCr", croutons );
                watch_display_string ( buf, 4 );
                delay_ms ( 1000 );
                watch_clear_all_indicators ( );
                // 6) Determine if game is over or advance to next level
                if ( currentScore < 6 ) {
                    watch_display_string ( " FaIL ", 4 );
                    delay_ms ( 500 );
                    gameOver = true;
                    if ( currentScore < 3 ) { // Demote - reduce defaultStartLevel by one usually
                        if ( ( state->actStartLevel <= state->defaultStartLevel ) && ( state->defaultStartLevel >= 2 ) ) {
                            state->defaultStartLevel--;
                            watch_display_string ( " demOt", 4 );
                            delay_ms ( 2000 );
                            croutonsLost = gen_random_int ( 1, 9 ) * ( SAFARI_COST / 2 );
                            if ( croutonsLost > state->croutonTotal ) croutonsLost = state->croutonTotal;
                            watch_display_string ( " LOSE ", 4 );
                            delay_ms ( 1500 );
                            sprintf ( buf, "%4dCr", croutonsLost );
                            watch_display_string ( buf, 4 );
                            delay_ms ( 1500 );
                            state->croutonTotal -= croutonsLost;
                        }
                    }  // END if demote
                } else { // Score okay, may proceed
                    if ( currentScore < 8 ) watch_display_string ( " mEH   ", 4 );
                    else watch_display_string ( " PaSS ", 4 ); 
                    delay_ms ( 600 );
                    if ( state->roundNumber < NORMAL_ROUNDS ) {
                        pnh_start_next_round(state);
                    } else {  // Advancing to safari if enough money
                        if ( state->croutonTotal >= SAFARI_COST ) {
                            state->croutonTotal -= SAFARI_COST;  // Pay entry fee
                            pnh_start_next_round(state);
                        } else {  // Not enough money
                            gameOver = true;
                            noCash = true;
                        } // END else not enough money
                    } // END else advancing to safari
                } // END else score okay may proceed
            } else { // ELSE safari round ending
                // 7) Set game over status
                gameOver = true;

                // 8) Update high scores or apply damage as appropriate
                if ( ( entry_correct ) && state->isPrime ) {  // Bagged a prime during safari, maybe good enough
                    watch_display_string ( " YES  ", 4 );
                    delay_ms ( 750 );
                    pnh_update_high_scores(state);
                } else if ( entry_correct ) {   // No trophy prime this safari - so sad.
                    watch_display_string ( "  nO  ", 4 );
                    delay_ms ( 750 );
                    watch_display_string ( " trPHY", 4 );
                    delay_ms ( 750 );
                } else {    // Made a mistake during safari - potential danger
//                  10) "OUCH"
//                  11) Check for EATEN or MAULED conditions
                    // High country codes are more dangerous.
                    if ( state->country_code >= STANDARD_COUNTRIES - 1 ) {	// Certain damage at highest levels
                        if ( state->isPrime ) {
                            playerMauled = true;
                        } else { // Player called a composite number a prime
                            if ( state->factor <= 11 )  playerEaten = true;  // Worst case scenario!
                            else playerMauled = true;
                        }
                    } else if ( state->country_code >= STANDARD_COUNTRIES - 3 ) {  // Maul on 2, 3, 5 or 7.
                        if ( !state->isPrime ) {
                            if ( state->factor <= 7 ) playerMauled = true;
                        }
                    } else {  // Early countries, maul on 2 or 5.
                        if ( !state->isPrime ) {
                            if ( state->factor == 2 ) playerMauled = true;
                            if ( state->factor == 5 ) playerMauled = true;
                        }
                    }
                    watch_display_string ( "OUCH  ", 4 );
                    delay_ms ( 1750 );
                    watch_display_string ( "      ", 4 );
                    delay_ms ( 200 );
                    watch_display_string ( " YOU  ", 4 );
                    delay_ms ( 700 );
                    watch_display_string ( "      ", 4 );
                    delay_ms ( 200 );
                    watch_display_string ( " ArE  ", 4 );
                    delay_ms ( 700 );
                    watch_display_string ( "      ", 4 );
                    delay_ms ( 600 );
                    strcpy ( buf, " FInE " );
                    if ( playerMauled ) strcpy ( buf, "MAuLEd" );
                    if ( playerEaten ) strcpy ( buf, " EatEn" );
                    watch_display_string ( buf, 4 );
                    delay_ms ( 1500 );
                    if ( playerMauled ) {
                        pnh_forfeit_one_high ( state );
                        state->mauled_counter++;
                        state->croutonTotal = state->croutonTotal * 0.4;
                        // Did country code change for the worse? Show here.
                        new_country_code = calc_country_code ( state );
                        if ( new_country_code != state->country_code ) {   // Change in country code
                            sprintf ( buf, "%6s", pnh_countries[state->country_code] );
                            watch_display_string ( buf, 4 );
                            delay_ms ( 750 );
                            watch_display_string ( "      ", 4 );
                            delay_ms ( 300 );
                            sprintf ( buf, "%6s", pnh_countries[new_country_code] );
                            watch_display_string ( buf, 4 );
                            delay_ms ( 1500 );
                            state->country_code = new_country_code;
                        }
                    } else if ( playerEaten ) {
                        pnh_forfeit_all_high ( state );
                        pnh_reset ( state );
                    }
                    state->mode = MODE_WAITING_TO_START;
                    state->attract_index = ATTRACT_NUMBERS;
                    state->attract_count = NUM_RANDOM_ATTRACT;
                    state->tickCounter = 0;
                } // END else made mistake during safari
            }  // END else safari round ending
        } // END ELSE round is over

        if ( gameOver ) {
            int16_t bonusCroutons;
            int8_t bonusSpin;
            watch_display_string ( "6AmE  ", 4 );
            delay_ms ( 800 );
            watch_display_string ( "OvEr", 4 );
            delay_ms ( 1000 );
            // End of game 'random' bonus
            if ( ! playerEaten ) {
                watch_display_string ( "rAnd", 4 );
                delay_ms ( 1000 );
                bonusCroutons = 0;
                bonusSpin = 0;
                if ( gen_random_int ( 0, 2 ) !=1 ) bonusSpin = 1;
                if ( state->croutonTotal < SAFARI_COST / 2 ) {
                    bonusSpin = 1;	// Automatic spin if poor
                    bonusCroutons = SAFARI_COST * 0.2;
                }
                if ( bonusSpin ) bonusCroutons += gen_random_int ( 1, SAFARI_COST * 0.6 );
                state->croutonTotal += bonusCroutons;
                sprintf ( buf, "%4dCr", bonusCroutons );
                watch_display_string ( buf, 4 );
                delay_ms ( 1500 );
                if ( ( bonusCroutons > 0 ) && ( bonusCroutons < 10 ) ) {
                    watch_display_string ( " LOSEr", 4 );
                    delay_ms ( 2000 );
                }
            }
            state->mode = MODE_WAITING_TO_START;
            state->safari_mode = false;
            if ( !noCash ) {  // Usually show high score list
                state->attract_index = ATTRACT_NUMBERS;
                state->attract_count = NUM_RANDOM_ATTRACT;
            } else {  // No cash - show current credits
                state->attract_index = ATTRACT_HIGH_SCORES;
                state->attract_count = PNH_HIGH_SCORES;
            }
            state->tickCounter = 0;
        } // END IF Game Over
   } // END If User picked prime or composite

    return true;
}

void prime_hunter_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    pnh_state_t *state = (pnh_state_t *)context;
    if (state->write_pending) {
        write_to_pnh_EEPROM(state);
        state->write_pending=false;
    }
}

