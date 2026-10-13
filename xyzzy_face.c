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

// XYZZY Micro-Adventure
// SEE xyzzy_face.h FOR GAME PLAY DOCUMENTATION

// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "xyzzy_face.h"
#include "watch.h"
#include "watch_utility.h"

#define XY_TICK_FREQUENCY 32
#define XY_LONG_PRESS  19
#define XY_SHORT_PRESS  2

#define XY_MODE_WAITING_TO_START 0
#define XY_MODE_LEVEL_SELECT 1
#define XY_MODE_PLAYING 2
#define XY_MODE_CODE_ENTRY 3
#define XY_MODE_TIME_DISPLAY 4

#define XY_VERSION_NUMBER 17
// Joey Castillo to oversee storage allocation row
#define XY_STORAGE_ROW 5
#define XY_STORAGE_KEY_NUMBER 11

char xyzzy_select_names[XY_NUM_LEVELS+1][7] =
    { " tIny ", "Stndrd", "COLOSL", "SELECT" };
char xyzzy_threat_names[XY_MAX_THREATS][7] = 
    { " bEAr ", "CAnYON", " trOLL", " rivEr", " drA6n" };
char xyzzy_item_names[XY_MAX_THREATS][7] = 
    { "HOnEY ", " rOPE ", " 6EMS ", " bOArd", " PhASr" };
char xyzzy_action_names[XY_MAX_THREATS][7] = 
    { " fEEd ", "CLImb ", " bribE", "SUrF  ", "Stun  " };

#define XY_NUM_KEYWORDS 9
char xyzzy_keywords[XY_NUM_KEYWORDS][7] =
    { " ---  ", "SUn   ", " MOOn ", " tree ", "EArtH ", " HILL ", "CLOUd ", " POnd ", "Star  " };
#define XY_NUM_TELEPORT 9
char teleportStrings[XY_NUM_TELEPORT][7] =
    { "- - - ", " -   -", "   -  ", "    - ", "-  - -", " -- - ", "- -- -", " -- --", "---  -" };

// Final items/countries rewards not relavent to game play.
#define XY_NUM_COUNTRIES 6
char xyzzy_countries[XY_NUM_COUNTRIES][7] =
    { " EntEr", "IdaHO ", "VULCAN", " MarS ", " ArUbA", " FIJI " };
#define XY_NUM_REWARDS 7
char xyzzy_rewards[XY_NUM_REWARDS][7] =
    { "HUmAn ", "StICk ", " PEbbL", "rAnCH ", "CASTLE", " YaCHT", "CHatEU" };

// Some arbitrary branch value for main path
#define XY_MAIN_PATH 37

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

static void xyzzy_display_location (xyzzy_state_t *state ) {
    char buf[11];
    uint8_t i;
    if ( state->mode == XY_MODE_PLAYING ) {
        sprintf ( buf, " %2d   ", state->loc );
        watch_display_string ( buf, 4 );
        if ( state->loc == 0 )  watch_display_string ( "EN", 8 );
        if ( state->onMainPath ) {
            if ( state->loc == state->locXyzzy ) watch_display_string ( "2Y", 8 );
            for ( i = 0; i < XY_MAX_BRANCHES; i++ ) {
                if ( state->loc == state->locBranchPoint[i] )  watch_display_string ( "br", 8 );
            }
        }
    }
}


static void xyzzy_display_code_entry (xyzzy_state_t *state ) {
    char buf[11];
    sprintf ( buf, "%2d%s", state->userCodeIndex+1, xyzzy_keywords[state->userCodes[state->userCodeIndex]] );
    watch_display_string ( buf, 2 );
}

static void write_to_xyzzy_EEPROM(xyzzy_state_t *state) {
    uint8_t base = 13; // Array writes being here
    // Do not exceed 64 bytes per write
    uint8_t size;
    uint8_t output_array [ 64 ]; // More than large enough for any one page
    uint8_t offset = 0;
    uint8_t i, j;
    uint8_t index;
    uint32_t bigNum; // Working copy of big number we are parsing into pieces
    uint8_t piece;   // The current 8-bit piece

    // 1st page
    size = base + XY_MAX_PATH_LENGTH + ( XY_MAX_CODES * 3 ) + ( XY_MAX_BRANCHES * 2 ); // (55 bytes)
    offset = 0;
    output_array [  0 ] = XY_STORAGE_KEY_NUMBER;
    output_array [  1 ] = state->mode;
    output_array [  2 ] = state->levelSelected;
    output_array [  3 ] = state->loc;
    output_array [  4 ] = state->locMainPathEnd;
    output_array [  5 ] = state->numCodes;
    output_array [  6 ] = state->totalCodesSeen;
    output_array [  7 ] = state->locXyzzy;
    output_array [  8 ] = state->xyzzyKnown;
    output_array [  9 ] = state->brIndex;
    output_array [ 10 ] = state->onMainPath;
    output_array [ 11 ] = state->secretDestination;
    output_array [ 12 ] = state->secretItem;
    index = base;  // First array output start location
    for ( i = 0; i < XY_MAX_PATH_LENGTH; i++ ) output_array [ index + i ] = state->mainPath[i]; 
    index += XY_MAX_PATH_LENGTH; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_CODES; i++ ) output_array [ index + i ] = state->locCodes[i];
    index += XY_MAX_CODES; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_CODES; i++ ) output_array [ index + i ] = state->codeValues[i];
    index += XY_MAX_CODES; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_CODES; i++ ) output_array [ index + i ] = state->codesSeen[i];
    index += XY_MAX_CODES; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_BRANCHES; i++ ) output_array [ index + i ] = state->locBranchPoint[i];
    index += XY_MAX_BRANCHES; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_BRANCHES; i++ ) output_array [ index + i ] = state->locBranchEnd[i];
    index += XY_MAX_BRANCHES; // Advance to next array output start location

    // Erase full row before first write only
    watch_storage_erase ( XY_STORAGE_ROW );
    watch_storage_sync ( ); 
    watch_storage_write ( XY_STORAGE_ROW, offset, output_array, size );
    watch_storage_sync ( ); 


    // 2nd page
    size = ( XY_MAX_THREATS * 6 ) + ( XY_MAX_BRANCHES * XY_MAX_BRANCH_LENGTH ); // (54 bytes)
    offset = 64;
    index = 0;
    for ( i = 0; i < XY_MAX_THREATS; i++ ) output_array [ index + i ] = state->locThreat[i];
    index += XY_MAX_THREATS; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_THREATS; i++ ) output_array [ index + i ] = state->brThreat[i];
    index += XY_MAX_THREATS; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_THREATS; i++ ) output_array [ index + i ] = state->inventory[i];
    index += XY_MAX_THREATS; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_THREATS; i++ ) output_array [ index + i ] = state->locItem[i];
    index += XY_MAX_THREATS; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_THREATS; i++ ) output_array [ index + i ] = state->brItem[i];
    index += XY_MAX_THREATS; // Advance to next array output start location
    for ( i = 0; i < XY_MAX_THREATS; i++ ) output_array [ index + i ] = state->ri[i];
    index += XY_MAX_THREATS; // Advance to next array output start location
    for ( j = 0; j < XY_MAX_BRANCHES; j++ ) {
        for ( i = 0; i < XY_MAX_BRANCH_LENGTH; i++ ) output_array [ index + i ] = state->branch[j][i];
        index += XY_MAX_BRANCH_LENGTH; // Advance to next array output start location
    }
    watch_storage_write ( XY_STORAGE_ROW, offset, output_array, size );
    watch_storage_sync ( ); 

    // 3rd page
    size = ( 4 * 2 ) + ( 4 * XY_NUM_LEVELS ); // (20 bytes)
    offset = 128;
    index = 0;
    // Parse the start time into four 8-bit integers
    bigNum = state->startTime;
    for ( i = 0; i < 4; i++ ) {
        piece = bigNum % 256;
        output_array [ index + 3 - i ] = piece;
        bigNum = bigNum / 256;
    }
    index += 4;
    // Parse the lastSolveTime into four 8-bit integers
    bigNum = state->lastSolveTime;
    for ( i = 0; i < 4; i++ ) {
        piece = bigNum % 256;
        output_array [ index + 3 - i ] = piece;
        bigNum = bigNum / 256;
    }
    index += 4;
    // Also all the bestTime array
    for ( j = 0; j < XY_NUM_LEVELS; j++ ) {
        bigNum = state->bestTime[j];
        for ( i = 0; i < 4; i++ ) {
            piece = bigNum % 256;
            output_array [ index + 3 - i ] = piece;
            bigNum = bigNum / 256;
        }
        index += 4;
    }
    watch_storage_write ( XY_STORAGE_ROW, offset, output_array, size );
    watch_storage_sync ( ); 
}


static void read_from_xyzzy_EEPROM(xyzzy_state_t *state) {
    uint8_t base = 13; // Array reads being here
    uint8_t size;
    uint8_t stored_data [ 64 ]; // More than enough for largest read
    uint8_t offset = 0;
    uint8_t i, j;
    uint8_t index;
    uint32_t bigNum;

    // Read 1st page
    size = base + XY_MAX_PATH_LENGTH + ( XY_MAX_CODES * 3 ) + ( XY_MAX_BRANCHES * 2 ); // (55 bytes)
    offset = 0;
    watch_storage_read (XY_STORAGE_ROW, offset, stored_data, size);
    // See if data was ever written to EEPROM storage
    if  ( stored_data[0] == XY_STORAGE_KEY_NUMBER )
    {
        state->mode =            stored_data [  1 ];
        state->loc =             stored_data [  2 ];
        state->levelSelected =   stored_data [  3 ];
        state->locMainPathEnd =  stored_data [  4 ];
        state->numCodes =        stored_data [  5 ];
        state->totalCodesSeen =  stored_data [  6 ];
        state->locXyzzy =        stored_data [  7 ];
        state->xyzzyKnown =      stored_data [  8 ];
        state->brIndex =         stored_data [  9 ];
        state->onMainPath =      stored_data [ 10 ];
        state->secretDestination = stored_data [ 11 ];
        state->secretItem =      stored_data [ 12 ];
        index = base;  // First array output start location
        for ( i = 0; i < XY_MAX_PATH_LENGTH; i++ ) state->mainPath[i] = stored_data [ index + i ]; 
        index += XY_MAX_PATH_LENGTH; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_CODES; i++ ) state->locCodes[i] = stored_data [ index + i ];
        index += XY_MAX_CODES; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_CODES; i++ )  state->codeValues[i] = stored_data [ index + i ];
        index += XY_MAX_CODES; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_CODES; i++ )  state->codesSeen[i] = stored_data [ index + i ];
        index += XY_MAX_CODES; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_BRANCHES; i++ )  state->locBranchPoint[i] = stored_data [ index + i ];
        index += XY_MAX_BRANCHES; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_BRANCHES; i++  )  state->locBranchEnd[i] = stored_data [ index + i ];
        index += XY_MAX_BRANCHES; // Advance to next array output start location

        // Read 2nd page
        size = ( XY_MAX_THREATS * 6 ) + ( XY_MAX_BRANCHES * XY_MAX_BRANCH_LENGTH ); // (54 bytes)
        offset = 64;
        index = 0;
        watch_storage_read (XY_STORAGE_ROW, offset, stored_data, size);
        for ( i = 0; i < XY_MAX_THREATS; i++ )  state->locThreat[i] = stored_data [ index + i ];
        index += XY_MAX_THREATS; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_THREATS; i++ )  state->brThreat[i] = stored_data [ index + i ];
        index += XY_MAX_THREATS; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_THREATS; i++ )  state->inventory[i] = stored_data [ index + i ];
        index += XY_MAX_THREATS; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_THREATS; i++ )  state->locItem[i] = stored_data [ index + i ];
        index += XY_MAX_THREATS; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_THREATS; i++ )  state->brItem[i] = stored_data [ index + i ];
        index += XY_MAX_THREATS; // Advance to next array output start location
        for ( i = 0; i < XY_MAX_THREATS; i++ )  state->ri[i] = stored_data [ index + i ];
        index += XY_MAX_THREATS; // Advance to next array output start location
        for ( j = 0; j < XY_MAX_BRANCHES; j++ ) {
            for ( i = 0; i < XY_MAX_BRANCH_LENGTH; i++ )  state->branch[j][i] = stored_data [ index + i ];
            index += XY_MAX_BRANCH_LENGTH; // Advance to next array output start location
        }

        // Read 3rd page
        size = ( 4 * 2 ) + ( 4 * XY_NUM_LEVELS ); // (20 bytes)
        offset = 128;
        index = 0;
        watch_storage_read (XY_STORAGE_ROW, offset, stored_data, size);
        // Read 32-bit startTime
        bigNum = 0;
        for ( i = 0; i < 4; i++ ) {
            bigNum *= 256;
            bigNum += stored_data [ index + i ];
        }
        state->startTime = bigNum;
        index += 4; // Advance to next array output start location
        // Read 32-bit lastSolveTime
        bigNum = 0;
        for ( i = 0; i < 4; i++ ) {
            bigNum *= 256;
            bigNum += stored_data [ index + i ];
        }
        state->lastSolveTime = bigNum;
        index += 4; // Advance to next array output start location
        // Also the bestTime array
        for ( j = 0; j < XY_NUM_LEVELS; j++ ) {
            bigNum = 0;
            for ( i = 0; i < 4; i++ ) {
                bigNum *= 256;
                bigNum += stored_data [ index + i ];
            }
            state->bestTime[j] = bigNum;
            index += 4; // Advance to next array output start location
        }
    }
    else
    {
        state->mode = XY_MODE_WAITING_TO_START;
        state->secretDestination = 0;
        state->secretItem = 0;
        for ( i = 0; i < XY_NUM_LEVELS; i++ ) {
            state->bestTime[i] = 0;
        }
    }
    state->writePending = false;
}


// Generate a new cave
static void xyzzy_gen_new_cave(xyzzy_state_t *state) {
    uint8_t i;
    bool done;
    bool valOK;
    uint8_t newLoc;
    uint8_t newCode;
    uint8_t j;
    uint8_t temp;
    uint8_t numBranches;
    uint8_t numThreats;  // Based on user selected difficulty
    uint8_t maxBranchPoint;

    state->mode = XY_MODE_PLAYING;
    state->loc = 0; // Entrance
    state->totalCodesSeen = 0;
    state->xyzzyKnown = 0;
    state->onMainPath = true;
    state->brIndex = 0; // Not meaningful yet
    state->shortcutCounter = 0;
    state->tickCounter = 0;
    state->writePending = true;
    state->secretDestination = gen_random_int ( 1, XY_NUM_COUNTRIES - 1 );
    state->secretItem = gen_random_int ( 1, XY_NUM_REWARDS - 1 );
    state->resetCounter = 0;

// INITIALIZE CAVE

    // Remember when this cave was generated - I.E. right now.
    state->startTime = watch_utility_date_time_to_unix_time ( watch_rtc_get_date_time(), 0 );
    // Generate all paths at full length
    for ( i = 0; i < XY_MAX_PATH_LENGTH; i++ ) state->mainPath[i] = gen_random_int(0,1); // Main path
    for ( j = 0; j < XY_MAX_BRANCHES; j++ ) {
        for ( i = 0; i < XY_MAX_BRANCH_LENGTH; i++ ) state->branch[j][i] = gen_random_int(0,1); // Branches
    }
    // Initialize other arrays
    for ( i = 0; i < XY_MAX_CODES; i++ ) {
        state->locCodes[i] = 199; // Init as not applicable
        state->codeValues[i] = 199;
        state->codesSeen[i] = 0;
    }
    for ( i = 0; i < XY_MAX_CODES; i++ ) { // Unique code values for final room
        done = false;
        do {
            valOK = true;
            newCode = gen_random_int(1,XY_NUM_KEYWORDS-1);
            for ( j = 0; j < XY_MAX_CODES; j++ ) if ( newCode == state->codeValues[j] ) valOK = false;
            if ( valOK ) done = true;
        } while ( !done ); 
        state->codeValues[i] = newCode;
    }
    for ( i = 0; i < XY_MAX_THREATS; i++ ) { 
        state->inventory[i] = 0; // Start out with nothing
        state->locItem[i] = 199; // Init as not applicable
        state->brItem[i] = 0;    // Init only, will reassign later if used.
        state->locThreat[i] = 199; // Init as not applicable
        state->brThreat[i] = 0;    // Init only, will reassign later if used.
    }
    for ( i = 0; i < XY_MAX_BRANCHES; i++ ) { 
        state->locBranchPoint[i] = 199; // Init as not applicable
        state->locBranchEnd[i] = 201;   // Init as anot applicable
    }
    for ( i = 0; i < XY_MAX_THREATS; i++ ) state->ri[i] = 199;  // Randomized index 0 to n-1, but scrambled
    for ( i = 0; i < XY_MAX_THREATS; i++ ) {
        done = false;
        do {
            valOK = true;
            newCode = gen_random_int ( 0, XY_MAX_THREATS - 1 );
            for ( j = 0; j < XY_MAX_THREATS; j++ ) if ( newCode == state->ri[j] ) valOK = false;
            if ( valOK ) done = true;
        } while ( !done );
        state->ri[i] = newCode;
    }

    if ( state->levelSelected == 0 ) {  // Easy/demo level
        state->locMainPathEnd = 8;
        state->numCodes = 2;
        numBranches = 0;
        numThreats = 0; 
    } else if ( state->levelSelected == 1 ) { // Moderate game
        state->locMainPathEnd = 21;
        state->numCodes = 4;
        numBranches = 1;
        numThreats = 1;
    } else { // The real game 
        state->locMainPathEnd = gen_random_int ( XY_MAX_PATH_LENGTH-2, XY_MAX_PATH_LENGTH );
        state->numCodes = 4;
        numBranches = 3;
        numThreats = 3;
    }
    if ( numThreats > numBranches ) numThreats = numBranches; // A limitation, for now....
    // ... could allow numThreats = numBranches + 1  with a code change to place last item
   //  on main path

    // Assign locXyzzy
    // Place primary threat near final room
    // Randomly assign all branch point locations and branch ends
    // LOOP - assign all items and threats
    // Assign all locCodes to be at unique locations, and not at any branch path start.

    // Assign locXyzzy
    state->locXyzzy = 199;  // Not used if very short cave
    if ( state->locMainPathEnd > 15 ) state->locXyzzy = ( state->locMainPathEnd / 2 ) + 1;
    // Place primary threat near final room
    state->locThreat[0] = 199;    // No primary threat
    state->brThreat[0] = XY_MAIN_PATH;
    if ( numThreats > 0 ) state->locThreat[0] = gen_random_int ( state->locMainPathEnd-4, state->locMainPathEnd-1 );

    // Randomly assign all branch point locations and branch ends
    // Add in any branches next, all unique and not at xyzzy
    maxBranchPoint = min ( state->locThreat[0], state->locMainPathEnd ) - 1;
    for ( i = 0; i < numBranches; i++ ) {
        done = false;
        while ( ! done ) {
            valOK = true;
            newLoc = gen_random_int ( 2, maxBranchPoint );
            if ( newLoc == state->locXyzzy ) valOK = false;
            for ( j = 0; j < XY_MAX_BRANCHES; j++ ) {
                if ( newLoc == state->locBranchPoint[j] ) valOK = false;
            }
            if ( valOK ) done = true;
        }
        state->locBranchPoint[i] = newLoc;
        state->locBranchEnd[i] = state->locBranchPoint[i] + gen_random_int ( XY_MAX_BRANCH_LENGTH -3, XY_MAX_BRANCH_LENGTH );
    }

    // LOOP - assign all items and threats
    for ( i = 0; i < numThreats; i++ ) {
        state->brItem[i] = i; // Simply assign one item per branch 
        // Usually place item right at end of branch+1 ( discover item AND dead end )
        if ( gen_random_int ( 0, 2 ) != 1 ) {
            state->locItem[i] = state->locBranchEnd[i] + 1; // Friendly
        } else {
            state->locItem[i] = state->locBranchEnd[i] - gen_random_int ( 0, 2 ); // Half friendly
            state->locItem[i] = max ( state->locBranchPoint[i] + 2, state->locItem[i] ); // Safety
        }
        // Place a threat at the front of this branch, if applicable
       if ( ( i + 1 ) < numThreats ) {
           state->brThreat[i+1] = i;
           state->locThreat[i+1] = gen_random_int ( state->locBranchPoint[i]+1, state->locItem[i]-1 );
           state->locThreat[i+1] = max ( state->locBranchPoint[i]+1, state->locThreat[i+1] ); // Safety
       }
    }
    // Assign all locCodes to be at unique locations, and not at any branch path start.
    for ( i = 0; i < state->numCodes; i++ ) {
        done = false;
        while ( ! done ) {
           valOK = true;
           newLoc = gen_random_int ( 2, state->locMainPathEnd - 2 );
           for ( j = 0; j < XY_MAX_BRANCHES; j++ ) {
               if ( newLoc == state->locBranchPoint[j] ) valOK = false;
           }
           for ( j = 0; j < state->numCodes; j++ ) {
              if ( newLoc == state->locCodes[j] ) valOK = false;
           }
           if ( valOK ) done = true;
       }
       state->locCodes[i] = newLoc;
    }
    // And locCodes must be in ascending order when done
    for ( i = 0; i < state->numCodes - 1; i++ )
    {
        for ( j = 0; j < state->numCodes - i - 1; j++ ) {
            if ( state->locCodes[j] > state->locCodes[j+1] ) {
                temp = state->locCodes[j];
                state->locCodes[j] = state->locCodes[j+1];
                state->locCodes[j+1] = temp;
            }
        }
    }
    // Small easement for tiny cave
    if ( state->levelSelected == 0 ) {
        state->locCodes[0] = 3;
        state->locCodes[1] = 6;
    }
}


// ---------------------------
// Standard watch face methods
// ---------------------------
void xyzzy_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(xyzzy_state_t));
        memset(*context_ptr, 0, sizeof(xyzzy_state_t));
    }
    xyzzy_state_t *state = (xyzzy_state_t *)*context_ptr;
    // Emulator only: Seed random number generator
    #if __EMSCRIPTEN__
    srand(time(NULL));
    #endif
    // Read in cave layout, secretDestination etc. from EEPROM.
    read_from_xyzzy_EEPROM(state);
    state->shortcutCounter = 0;
}

void xyzzy_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    xyzzy_state_t *state = (xyzzy_state_t *)context;
    char buf[16];
    uint8_t i;
    movement_request_tick_frequency(XY_TICK_FREQUENCY);
    // No fancy intro
    watch_clear_all_indicators ( );
    watch_display_string("CA        ", 0); // Cave
    // What to display depends on what mode we re-enter the game in
    if ( state->mode == XY_MODE_WAITING_TO_START ) {
        sprintf ( buf, "%s", xyzzy_countries[state->secretDestination] );
        watch_display_string ( buf, 4 );
    } else if ( state->mode == XY_MODE_LEVEL_SELECT ) {
        state->levelSelected = XY_NUM_LEVELS; // Shows 'Select'
        sprintf ( buf, "%s", xyzzy_select_names[state->levelSelected] );
        watch_display_string ( buf, 4 );
    } else { 
        xyzzy_display_location ( state );
        for ( i = 0; i < XY_MAX_THREATS; i++ ) if (state->inventory[i]) watch_set_indicator (state->ri[i]);
    }
    state->tickCounter = 0;
    state->buttonTimer = 0;
    state->bothPressedTimer = 0;
    state->ignoreNextRelease = false;
}

bool xyzzy_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    xyzzy_state_t *state = (xyzzy_state_t *)context;
    char buf [ 20 ];	// [11] is more correct and works; compiler too helpful.
    bool userPickedLeft = false;  // During gameplay
    bool userPickedRight = false; // During gameplay
    bool displayLocation = false;
    bool correctPick;   // Did user make 'correct' choice - advance further into cave
    bool branchMatch = false; // There is a path branch at this location
    bool codeMatch = false;   // There is a keyword at this location
    bool valOK;
    uint8_t codeMatchIndex;   // Which keyword is at this location?
    uint16_t i;
    uint8_t j;
    uint8_t branchInd;   // Index when on a branch - starts at 0
    uint8_t oldVal;
    uint32_t bigNum;
    bool jumpToXyzzy;	// Jump to xyzzy instead of entrance
    int8_t itemIndex;   // Index if item was found, or -1
    int8_t threatIndex; // Index if threat encountered, or -1
    // Debouncing of buttons
    bool alarmPress = false;  // Pressed right now
    bool lightPress = false;  // Pressed right now
    bool alarmUpShort = false;  // Short release
    bool lightUpShort = false;  // Short release
    bool alarmDownLong = false; // Long press
    bool lightDownLong = false; // Long press
    uint32_t nowSeconds;  // Unix time is in seconds
    uint32_t deltaSeconds;  // Total play time
    uint8_t hours, minutes, seconds;
    uint16_t days;
    uint8_t codePending[XY_MAX_CODES]; // Check user code entries
    bool codeEntryCompleted = false;   // Did user just finish entering a code?

    switch (event.event_type) {
        case EVENT_TICK:
            // ticks are used for input debounce or the alternating the display updates
            // if the game is over, or the best times display
            state->tickCounter++;
            if ( state->mode == XY_MODE_WAITING_TO_START ) {
                // While waiting, we display the high score list and other items until
                // the user starts the next game.
                if ( state->tickCounter == 1 ) {
                    watch_display_string ( " tHE  ", 4 );
                } else if ( state->tickCounter == (int) (XY_TICK_FREQUENCY * 1.6) ) { // Blank space
                    watch_display_string ( "      ", 4 );
                } else if ( state->tickCounter == XY_TICK_FREQUENCY * 2 ) { 
                    watch_display_string ( "CAVE  ", 4 );
                } else if ( state->tickCounter == (int) (XY_TICK_FREQUENCY * 5.9) ) { // Blank space
                    watch_display_string ( "      ", 4 );
                } else if ( state->tickCounter == XY_TICK_FREQUENCY * 7 ) { // Show 'Enter ' or reward destination 
                    sprintf ( buf, "%s", xyzzy_countries[state->secretDestination] );
                    watch_display_string ( buf, 4 );
                } else if ( state->tickCounter == (int) (XY_TICK_FREQUENCY * 9.6) ) { // Blank space
                    watch_display_string ( "      ", 4 );
                } else if ( state->tickCounter == XY_TICK_FREQUENCY * 10 ) { // Show 'Human ' or reward item
                    sprintf ( buf, "%s", xyzzy_rewards[state->secretItem] );
                    watch_display_string ( buf, 4 );
                } else if ( state->tickCounter == (int) (XY_TICK_FREQUENCY * 12.6) ) { // Blank space
                    watch_display_string ( "      ", 4 );
                } else if ( state->tickCounter >= XY_TICK_FREQUENCY * 14 ) state->tickCounter = 0;
            } else if ( state->mode == XY_MODE_TIME_DISPLAY ) {
                if ( state->tickCounter == 1 ) { // Display the currently selected request
                    if ( state->tdSubLevel == 0 ) { // Beginning of a new level, ex: tiny level
                        // Will need to do the math
                        if ( state->tdLevel < XY_NUM_LEVELS ) {
                            bigNum = state->bestTime[state->tdLevel];
                            sprintf ( buf, "%6s", xyzzy_select_names[state->tdLevel] );
                        } else {
                            bigNum = state->lastSolveTime;
                            sprintf ( buf, " LaSt " );
                        }
                        if ( bigNum == 0 ) {  // Avoid normal handling if this cave never completed
                            watch_display_string ( buf, 4 );
                            delay_ms ( 1000 );
                            sprintf ( buf, "----  " );
                            state->tdSubLevel = 4;
                        }
                        state->seconds = bigNum % 60;
                        bigNum = bigNum / 60;
                        state->minutes = bigNum % 60;
                        bigNum = bigNum / 60;
                        state->hours = bigNum % 24;
                        bigNum = bigNum / 24;
                        state->days = bigNum;
                    } else if ( state->tdSubLevel == 1 ) {  // Days
                        sprintf ( buf, "%4ddY", state->days );
                    } else if ( state->tdSubLevel == 2 ) {  // Hours
                        sprintf ( buf, "%4dHr", state->hours );
                    } else if ( state->tdSubLevel == 3 ) {  // Minutes
                        sprintf ( buf, "%4dMI", state->minutes );
                    } else if ( state->tdSubLevel == 4 ) {  // Seconds
                        sprintf ( buf, "%4dSE", state->seconds );
                    } else  {  // Blank
                        sprintf ( buf, "      " );
                    }
                    watch_display_string ( buf, 4 );
                } else if ( ( state->tickCounter >= XY_TICK_FREQUENCY * 1.0 ) ||
                            ( ( state->tdSubLevel >= 5 ) && ( state->tickCounter >= XY_TICK_FREQUENCY * 0.3 ) ) ) {
                    // Time to advance to next item
                    state->tdSubLevel++;
                    // But skip days if they are zero
                    if ( ( state->tdSubLevel == 1 ) && ( state->days == 0 ) ) state->tdSubLevel = 2;
                    // Also skip hours if both days and hours are zero
                    if ( ( state->tdSubLevel == 2 ) && ( state->days == 0 ) && ( state->hours == 0 ) ) {
                         state->tdSubLevel = 3;
                    }
                    // Are we done displaying this level?
                    if ( state->tdSubLevel > 5 ) {
                        state->tdSubLevel = 0;   // Advance to next level display
                        state->tdLevel++;
                        if ( state->tdLevel > XY_NUM_LEVELS ) {
                            state->mode = XY_MODE_WAITING_TO_START; // All done time display
                            sprintf ( buf, " vEr%2d", XY_VERSION_NUMBER );
                            watch_display_string ( buf, 4 );
                            delay_ms (2500);
                        }
                    }
                    state->tickCounter = 0;  // Reset counter
                }
            }

            // We'll monitor both the light and alarm buttons
            alarmPress = watch_get_pin_level(BTN_ALARM);
            lightPress = watch_get_pin_level(BTN_LIGHT);
            // If neither button pressed, we check for a button just being release
            if ( !alarmPress && !lightPress ) {
                // Possibly a button was just released
                if ( state->buttonTimer > 0 ) {
                    if ( !state->ignoreNextRelease ) {
                        // Which button and for how long?
                        if ( state->alarmWasPressed ) {
                            if ( state->buttonTimer >= XY_SHORT_PRESS ) alarmUpShort = true;
                            // else nothing - it was noise
                        }
                        if ( state->lightWasPressed ) {
                            if ( state->buttonTimer >= XY_SHORT_PRESS ) lightUpShort = true;
                            // else nothing - it was noise
                        }
                    } else { // We just ignored a release after a long press
                        state->ignoreNextRelease = false;
                    }
                    state->buttonTimer = 0;
                }
                state->alarmWasPressed = false;
                state->lightWasPressed = false;
                state->bothPressedTimer = 0;
            }
            else if ( alarmPress && !lightPress ) {
                state->alarmWasPressed = true;
                state->buttonTimer++;
                state->bothPressedTimer = 0;
                if ( state->buttonTimer == XY_LONG_PRESS ) {
                    alarmDownLong = true;
                    state->ignoreNextRelease = true;
                }
            }
            else if ( lightPress && !alarmPress) {
                state->lightWasPressed = true;
                state->buttonTimer++;
                state->bothPressedTimer = 0;
                if ( state->buttonTimer == XY_LONG_PRESS ) {
                    lightDownLong = true;
                    state->ignoreNextRelease = true;
                }
            } else {  // Both pressed
                state->ignoreNextRelease = true;
                state->bothPressedTimer++;
                if ( state->bothPressedTimer == XY_LONG_PRESS ) {
                    state->tickCounter = 0;
                    watch_clear_all_indicators();
                    if ( state->mode != XY_MODE_WAITING_TO_START ) {
                        state->resetCounter = 0;
                        watch_display_string ( "  rESEt ", 2 );
                        delay_ms ( 700 );
                    } else {
                        state->resetCounter++;
                        state->bothPressedTimer = XY_LONG_PRESS / 2;
                        if ( state->resetCounter < 7 ) {
                            sprintf ( buf, "  rESET%d", state->resetCounter );
                            watch_display_string ( buf, 2 );
                            delay_ms ( 500 );
                            state->tickCounter=2; // Avoid flashing intro while full reset
                        } else {
                            for ( i = 0; i < 5; i++ ) {
                                watch_display_string ( "      ", 4 );
                                delay_ms ( 75 );
                                watch_display_string ( "rESET ", 4 );
                                delay_ms ( 150 );
                            }
                            watch_display_string ( "CLEAr ", 4 );
                            delay_ms ( 1000 );
                            state->resetCounter = 0;
                            for ( i = 0; i < XY_NUM_LEVELS; i++ ) state->bestTime[i] = 0;
                            state->lastSolveTime = 0;
                        }
                    }
                    state->mode = XY_MODE_WAITING_TO_START;
                    state->secretDestination = 0;
                    state->secretItem = 0;
                }
            }
            break;  // End case EVENT_TICK
        case EVENT_LIGHT_LONG_UP:
        case EVENT_LIGHT_BUTTON_UP:
        case EVENT_ALARM_LONG_UP:
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_LIGHT_BUTTON_DOWN:   // Disable the backlight
        case EVENT_ALARM_BUTTON_DOWN:
//            state->tickCounter = 0;  // Why?
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (state->writePending) {
                write_to_xyzzy_EEPROM(state);
                watch_storage_sync ( );
                state->writePending=false;
            }
            watch_display_string("SLEEP ", 4);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    } // END event switch statement

    if ( lightDownLong ) {
        if ( ( state->mode == XY_MODE_WAITING_TO_START ) ||
             ( state->mode == XY_MODE_TIME_DISPLAY ) ) {
            // Advance to level select menu
            state->mode = XY_MODE_LEVEL_SELECT;
            state->levelSelected = XY_NUM_LEVELS;  // Shows "SELECT"
            sprintf ( buf, "%s", xyzzy_select_names[state->levelSelected] );
            watch_display_string ( buf, 4 );
        } else if ( state->mode == XY_MODE_PLAYING ) {
            state->onMainPath = 1;
            state->xyzzyCounter = 0;
            displayLocation = true;
            if ( ( state->loc != state->locXyzzy ) && state->xyzzyKnown ) { // Jump to xyzzy location
                state->loc = state->locXyzzy;
            } else {  // Jump to entrance
                state->loc = 0;
            }
        } else if ( state->mode == XY_MODE_CODE_ENTRY ) { // User is done entering code.
            codeEntryCompleted = true;
        }
    }

    if ( lightUpShort ) {
        if ( state->mode == XY_MODE_LEVEL_SELECT ) {
            // User made a level selection
            if ( state->levelSelected != XY_NUM_LEVELS ) { // Ignore when menu says 'Select'
                // NEW CAVE - NEW GAME
                xyzzy_gen_new_cave ( state );
                watch_display_string ( " NEW  ", 4 );
                delay_ms ( 1000 );
                watch_display_string ( "CAvE  ", 4 );
                delay_ms ( 1000 );
                watch_display_string ( " ---  ", 4 );
                delay_ms (400);
                // The game is starting
                state->mode = XY_MODE_PLAYING;
                displayLocation = true;
            }
        } else if ( state->mode == XY_MODE_PLAYING ) {
            userPickedLeft = true;
        } else if ( state->mode == XY_MODE_CODE_ENTRY ) { // Switch to next code value
            state->userCodeIndex++;
            if ( state->userCodeIndex >= state->totalCodesSeen ) state->userCodeIndex = 0;
            xyzzy_display_code_entry ( state );
        }
    }

    if ( alarmDownLong ) {
        if ( state->mode == XY_MODE_PLAYING ) {
            state->onMainPath = 1;
            state->xyzzyCounter = 0;
            displayLocation = true;
            if ( state->loc != 0 ) {
                // Jump to main entrance
                state->loc = 0;
            } else if ( state->xyzzyKnown ) {
                // Already at entrance, jump to XYZZY
                state->loc = state->locXyzzy;
            }
        } else if ( state->mode == XY_MODE_WAITING_TO_START ) {
            // Start time display mode
            state->mode = XY_MODE_TIME_DISPLAY;
            state->tdLevel = 0;
            state->tdSubLevel = 0;
            state->tickCounter = 0;
       }
    }

    if ( alarmUpShort ) {
        if ( state->mode == XY_MODE_PLAYING ) {
            userPickedRight = true;
        } else if ( state->mode == XY_MODE_LEVEL_SELECT ) {
            state->levelSelected++;
            if ( state->levelSelected >= XY_NUM_LEVELS ) state->levelSelected = 0;
            sprintf ( buf, "%s", xyzzy_select_names[state->levelSelected] );
            watch_display_string ( buf, 4 );
        } else if ( state->mode == XY_MODE_CODE_ENTRY ) { // Increase current code value
            state->userCodes[state->userCodeIndex]++;
            if ( state->userCodes[state->userCodeIndex] >= XY_NUM_KEYWORDS ) state->userCodes[state->userCodeIndex] = 1;
            xyzzy_display_code_entry ( state );
        }
    }

    if ( userPickedLeft || userPickedRight ) {
        state->writePending = true;
        displayLocation = true;
        // Did user pick 'correctly'?
        correctPick = false;
        if ( state->onMainPath ) {
            if ( ( userPickedLeft  && ( state->mainPath[state->loc] == 0 ) ) ||
                 ( userPickedRight && ( state->mainPath[state->loc] == 1 ) ) ) {
                correctPick = true;
            }
        } else { // On branches use relative index
            branchInd = state->loc - state->locBranchPoint[state->brIndex] - 1;
            if ( branchInd >= XY_MAX_BRANCH_LENGTH ) branchInd = 0;  // Unnecessary safety ( I hope )
            if ( ( userPickedLeft  && ( state->branch[state->brIndex][branchInd] == 0 ) ) ||
                 ( userPickedRight && ( state->branch[state->brIndex][branchInd] == 1 ) ) ) {
                correctPick = true;
            }
        }

        // Advance if correct pick
        if ( correctPick ) {
            state->loc++;
            if ( ( state->loc >= state->locXyzzy ) && ( state->onMainPath ) ) state->xyzzyKnown = 1;

            // Check for:
            // final room
            // end of current branch ( dead end )
            // any threat
            // any item

            bool bFinalRoom = false;
            bool bDeadEnd = false;
            bool bThreat = false;
            bool bItem = false;

            if ( state->onMainPath ) {
                if ( state->loc >= state->locMainPathEnd ) bFinalRoom = true;
                // No need to check deadEnd
                threatIndex = -1;
                for ( i = 0; i < XY_MAX_THREATS; i++ ) {
                    if ( state->loc == state->locThreat[i] ) {
                        if ( state->brThreat[i] == XY_MAIN_PATH ) {
                            bThreat = true;
                            threatIndex = i;
                        }
                    }
                }
                // No need to check item on main branch ( yet )
            } else {
                // No need to check finalRoom
                // Check for dead end
                if ( state->loc > ( state->locBranchEnd[state->brIndex] ) ) bDeadEnd = true;
                threatIndex = -1;
                for ( i = 0; i < XY_MAX_THREATS; i++ ) {
                    if ( ( state->loc == state->locThreat[i] ) && ( state->brIndex == state->brThreat[i] ) ) {
                        bThreat = true;
                        threatIndex = i;
                    }
                }
                itemIndex = -1;
                for ( i = 0; i < XY_MAX_THREATS; i++ ) { // Item match?
                    if ( ( state->brIndex == state->brItem[i] ) && ( state->loc == state->locItem[i] ) ) {
                        // Found an item!!
                        itemIndex = i;
                        bItem = true;
                    }
                }
            }
            if ( bFinalRoom ) {  // Entering final room
                watch_display_string ( " FINAL", 4 );
                delay_ms ( 1500 );
                watch_display_string ( " rooM ", 4 );
                delay_ms ( 1500 );
                if ( state->totalCodesSeen > 0 )
                {
                    state->mode = XY_MODE_CODE_ENTRY;
                    for ( i = 0; i < XY_MAX_CODES; i++ ) state->userCodes[i] = 0;
                    state->userCodeIndex = 0;
                    displayLocation = false;
                    xyzzy_display_code_entry ( state );
                } else {
                    codeEntryCompleted = true;
                }
            }
            if ( bItem ) {
                // Player discovered item!
                state->inventory[itemIndex] = 1;
                state->locItem[itemIndex] = 199;  // Won't find a second time.
                sprintf ( buf, "%s", xyzzy_item_names[state->ri[itemIndex]] );
                watch_display_string ( buf, 4 );
                delay_ms ( 800 );
                for ( i = 0; i < 6; i++ ) {
                    watch_clear_indicator ( state->ri[itemIndex] );
                    delay_ms ( 100 );
                    watch_set_indicator ( state->ri[itemIndex] );
                    delay_ms ( 100 );
                }
                delay_ms ( 800 );
            }
            if ( bDeadEnd ) {
                watch_display_string ( " dEAd ", 4 );
                delay_ms ( 1000 );
                watch_display_string ( " End  ", 4 );
                delay_ms ( 1000 );
                state->onMainPath = 1;
                state->xyzzyCounter = 0;
                if ( ( state->xyzzyKnown ) && ( state->locBranchPoint[state->brIndex] > state->locXyzzy ) ) {
                    // Return to xyzzy
                    state->loc = state->locXyzzy;
                } else { // Return to entrance
                    state->loc = 0;
                }
            }
            if ( bThreat ) {
                sprintf ( buf, "%s", xyzzy_threat_names[state->ri[threatIndex]] );
                watch_display_string ( buf, 4 );
                delay_ms ( 2000 );
                watch_display_string ( "      ", 4 );
                delay_ms ( 500 );
                if ( state->inventory[threatIndex] ) { // OK - required item in inventory
                    sprintf ( buf, "%s", xyzzy_item_names[state->ri[threatIndex]] );
                    watch_display_string ( buf, 4 );
                    delay_ms ( 1000 );
                    sprintf ( buf, "%s", xyzzy_action_names[state->ri[threatIndex]] );
                    for ( i = 0; i < 4; i++ ) {
                        watch_display_string ( buf, 4 );
                        delay_ms ( 500 );
                        watch_display_string ( "      ", 4 );
                        delay_ms ( 200 );
                    }
                    watch_display_string ( " dONE ", 4);
                    delay_ms ( 800 );
                    state->inventory[threatIndex] = 0;
                    state->locThreat[threatIndex] = 199; // Removed from cave
                } else { // Kicked back to entrance
                    state->loc = 0;
                    state->onMainPath = 1;
                }
            }
        } else { // User picked 'incorrectly'
            branchMatch = false;
            codeMatch = false;
            if ( state->onMainPath ) {
                for ( i = 0; i < XY_MAX_BRANCHES; i++ ) {
                    if ( state->loc == state->locBranchPoint[i] ) {
                        branchMatch = true;
                        state->brIndex = i;
                    }
                }
                for ( i = 0; i < state->numCodes; i++ ) {
                    if ( ( state->loc == state->locCodes[i] ) && state->onMainPath ) {
                        codeMatch = true;
                        codeMatchIndex = i;
                    }
                }
            }
            if ( branchMatch ) {
                // Begin proceeding down other path
                state->loc++;
                state->onMainPath = false;
            } else if ( codeMatch ) {
                // Stay at this position, display code segment
                if ( state->codesSeen[codeMatchIndex] == 0 ) {
                    state->totalCodesSeen++;
                    state->codesSeen[codeMatchIndex] = 1;
                } 
                sprintf ( buf, "%s", xyzzy_keywords[state->codeValues[codeMatchIndex]] );
                watch_display_string ( buf, 4 );
                delay_ms ( 1000 );
            } else {  // Incorrect move
                // A quick blink if already at the entrance
                if ( state->loc == 0 ) {
                    watch_display_string ( "      ", 4 );
                    delay_ms ( 200 );
                }
                // Jump back to entrance, or xyzzy location if applicable
                jumpToXyzzy = false;
                if ( ( state->xyzzyKnown ) && ( state->xyzzyCounter < 6 ) ) {
                    if ( ( state->onMainPath ) &&
                         ( state->loc > state->locXyzzy ) ) {
                        jumpToXyzzy = true;
                    }
                    if ( !state->onMainPath ) {
                         if ( state->locBranchPoint[state->brIndex] > state->locXyzzy ) {
                            jumpToXyzzy = true;
                         }
                    }
                }
                state->onMainPath = 1;
                if ( jumpToXyzzy )  {
                     state->loc = state->locXyzzy;
                     state->xyzzyCounter++;
                } else {
                    state->loc = 0;
                    state->xyzzyCounter = 0;
                }
            }
        }
    } // END If User picked left or right

    if ( codeEntryCompleted )
    {
        // User is done entering code. Is it right?
        // Only need to enter codes seen, don't care about order
        for ( i = 0; i < XY_MAX_CODES; i++ ) codePending[i] = state->codesSeen[i];
        for ( i = 0; i < state->numCodes; i++ ) {
           for ( j = 0; j < state->numCodes; j++ ) {
               if ( state->userCodes[i] == state->codeValues[j] ) codePending[j] = 0;
           }
        }
        // There should be no codes left pending
        valOK = true;
        for ( i = 0; i < state->numCodes; i++ ) if ( codePending[i] ) valOK = false;
        if ( !valOK ) {  // Nope, back to entrance.
            state->mode = XY_MODE_PLAYING;
            state->loc = 0;
            watch_display_string ( "   NO   ", 2 );
            delay_ms ( 1000 );
            displayLocation = true;
        } else {  // They did it - winner!
            nowSeconds = watch_utility_date_time_to_unix_time ( watch_rtc_get_date_time(), 0 );
            if ( state->totalCodesSeen > 0 ) {
                watch_display_string ( "   YES  ", 2 );
                delay_ms ( 1100 );
                watch_display_string ( "      ", 4 );
                delay_ms ( 200 );
            }
            watch_display_string ( "  6AME  ", 2 );
            delay_ms ( 1000 );
            watch_display_string ( "      ", 4 );
            delay_ms ( 200 );
            watch_display_string ( "OvEr   ", 4 );
            delay_ms ( 1000 );
            watch_display_string ( "      ", 4 );
            delay_ms ( 200 );
            watch_clear_all_indicators ( );
            watch_display_string ( " TELE ", 4 );
            delay_ms ( 700 );
            watch_display_string ( " POrt ", 4 );
            delay_ms ( 700 );
            watch_display_string ( "      ", 4 );
            delay_ms ( 200 );
            oldVal = 100;
            for ( i = 0; i < 15; i++ ) {
                do {
                    j = gen_random_int ( 0, XY_NUM_TELEPORT - 1 );
                } while ( j == oldVal );
                oldVal = j;
                watch_display_string ( teleportStrings[j], 4 );
                delay_ms ( 100 );
            }
            watch_display_string ( "      ", 4 );
            delay_ms ( 350 );
            watch_display_string ( " dESt ", 4 );
            delay_ms ( 800 );
            watch_display_string ( "      ", 4 );
            delay_ms ( 1500 );
            sprintf ( buf, "%s", xyzzy_countries[state->secretDestination] );
            watch_display_string ( buf, 4 );
            delay_ms ( 4000 );
            watch_display_string ( "      ", 4 );
            delay_ms ( 300 );
            watch_display_string ( " YOU  ", 4 );
            delay_ms ( 800 );
            watch_display_string ( " 6Et  ", 4 );
            delay_ms ( 800 );
            watch_display_string ( "      ", 4 );
            delay_ms ( 600 );
            sprintf ( buf, "%s", xyzzy_rewards[state->secretItem] );
            watch_display_string ( buf, 4 );
            delay_ms ( 2500 );
            watch_display_string ( "      ", 4 );
            delay_ms ( 400 );
            deltaSeconds = nowSeconds - state->startTime;
            state->lastSolveTime = deltaSeconds;
            // Check for fastest run at this level
            if ( ( deltaSeconds < state->bestTime[state->levelSelected] ) || ( state->bestTime[state->levelSelected]==0 ) ) {
                // New fastest time for at this cave size
                state->bestTime[state->levelSelected] = deltaSeconds;
                watch_display_string ( " NEw  ", 4 );
                delay_ms ( 700 );
                for ( i = 0; i < 5; i++ ) {
                    watch_display_string ( "      ", 4 );
                    delay_ms ( 200 );
                    watch_display_string ( " bESt ", 4 );
                    delay_ms ( 200 );
                }
                watch_display_string ( " tIME ", 4 );
                delay_ms ( 700 );
            }
            // Break this down in to days, hours, minutes and seconds
            seconds = deltaSeconds % 60;
            deltaSeconds = deltaSeconds / 60;
            minutes = deltaSeconds % 60;
            deltaSeconds = deltaSeconds / 60;
            hours = deltaSeconds % 24;
            days = deltaSeconds / 24;
            if ( days > 0 ) {
                sprintf ( buf, "%4ddy", days );
                watch_display_string ( buf, 4 );
                delay_ms ( 2500 );
            }
            if ( ( hours > 0 ) || ( days > 0 ) ) {
                sprintf ( buf, "%4dHr", hours );
                watch_display_string ( buf, 4 );
                delay_ms ( 2500 );
            }
            sprintf ( buf, "%4dMI", minutes );
            watch_display_string ( buf, 4 );
            delay_ms ( 2500 );
            sprintf ( buf, "%4dSE", seconds );
            watch_display_string ( buf, 4 );
            delay_ms ( 2500 );
            state->mode = XY_MODE_WAITING_TO_START;
            state->tickCounter = 0;
            displayLocation = false;
        }
    } // ENDIF Code entry completed

    if ( ( displayLocation ) && ( state->mode == XY_MODE_PLAYING ) ) xyzzy_display_location ( state );

    return true;
}

void xyzzy_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    xyzzy_state_t *state = (xyzzy_state_t *)context;
    if (state->writePending) {
        write_to_xyzzy_EEPROM(state);
        state->writePending=false;
    }
}

