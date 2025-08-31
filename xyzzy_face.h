/*
 * MIT License
 *
 * Copyright (c) 2025 Klingon Jane
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation thNe rights
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

#ifndef XYZZY_FACE_H_
#define XYZZY_FACE_H_

#include "movement.h"
#define XY_MAX_PATH_LENGTH  24
#define XY_MAX_BRANCH_LENGTH   8
#define XY_MAX_CODES  4
#define XY_NUM_LEVELS  3
#define XY_MAX_BRANCHES 3
#define XY_MAX_THREATS 5

/*

XYZZY Micro-adventure.

A lightning-quick tribute to the original game.

Full acknowledgements to Will Crowther 1976 and Don Woods 1977 for
"Colossal Cave Adventure", which started this genre of games.

Tiny cave hint: The keywords always appear at locations 3 and 6.

Thankfully; keywords only appear on the main path in all caves.

*/


typedef struct {
                                // An asterisk '*' means saved to EEPROM
    uint8_t  mode;              // * 0 game over show country, 1 level select, 2 playing
    uint8_t  levelSelected;     // * 0 = training, 1 = normal, 2 = select
    uint8_t  loc;               // * Current progress into the cave
    uint8_t  mainPath[XY_MAX_PATH_LENGTH]; // * Main path defined by 0s and 1s
    uint8_t  locMainPathEnd;    // * Final room - end of main path - end of game
    uint8_t  numCodes;          // * Actual codes in use, up to XY_MAX_CODES
    uint8_t  locCodes[XY_MAX_CODES];  // * Code numbers on main path 
    uint8_t  codeValues[XY_MAX_CODES]; // * Values from 0 thru N
    uint8_t  codesSeen[XY_MAX_CODES];  // Booleans
    uint8_t  totalCodesSeen;    // How many codes has player seen?
    uint8_t  userCodes[XY_MAX_CODES]; // Codes enter by player
    uint8_t  userCodeIndex;     // Code currently being entered
    uint8_t  locXyzzy;          // * Return point short-cut when deeper in cave
    uint8_t  xyzzyKnown;        // * Has user ever reached xyzzy location?
    uint8_t  xyzzyCounter;      // Usually jump back to xyzzy
    uint8_t  locThreat[XY_MAX_THREATS]; // * Where is the threat?
    uint8_t  brThreat[XY_MAX_THREATS];  // * Which branch is threat on?
    uint8_t  inventory[XY_MAX_THREATS]; // * Do we have this item?
    uint8_t  locItem[XY_MAX_THREATS]; // * How deep is this item
    uint8_t  brItem[XY_MAX_THREATS];  // * Which branch is this item?
    uint8_t  ri[XY_MAX_THREATS]; // * Randomized index from 0 to n-1 for threat concealment
    uint8_t  locBranchPoint[XY_MAX_BRANCHES]; // * Where does branch occur?
    uint8_t  locBranchEnd[XY_MAX_BRANCHES]; // * Last valid place in this branch 
    uint8_t  branch[XY_MAX_BRANCHES][XY_MAX_BRANCH_LENGTH]; // * Branch defined by 0s and 1s
    uint8_t  brIndex;           // * Which branch you are on
    bool     onMainPath;        // * You are on the main path ( not any branch )
    uint8_t  shortcutCounter;   // How many consec times we've jumped back to locXyzzy
    uint16_t tickCounter;       // For minimum delays and debounce
    bool     writePending;      // Need to update EEPROM when resigning
    uint8_t  secretDestination; // * Your fixed secret country/planet destination 
    uint8_t  secretItem;        // * Your fixed item reward
    uint32_t startTime;         // * Seconds in UNIX time of cave generation
    uint32_t lastSolveTime;     // * Time of last solution
    uint32_t bestTime[XY_NUM_LEVELS];  // * Best times ever
    uint16_t days;              // For display of solve times
    uint8_t hours;              // For display of solve times
    uint8_t minutes;            // For display of solve times
    uint8_t seconds;            // For display of solve times
    uint8_t tdLevel;            // For time display
    uint8_t tdSubLevel;         // For time display
    bool alarmWasPressed;       // Was the alarm button down previously?
    bool lightWasPressed;       // Was the light button down previously?
    bool ignoreNextRelease;     // Ignore release after long press
    uint16_t buttonTimer;       // How many ticks was button held down
    uint8_t bothPressedTimer;   // How many ticks both buttons held down
    uint8_t resetCounter;       // To clear all saved times
} xyzzy_state_t;

void xyzzy_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void xyzzy_face_activate(movement_settings_t *settings, void *context);
bool xyzzy_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void xyzzy_face_resign(movement_settings_t *settings, void *context);

#define xyzzy_face ((const watch_face_t){ \
    xyzzy_face_setup, \
    xyzzy_face_activate, \
    xyzzy_face_loop, \
    xyzzy_face_resign, \
    NULL, \
})

#endif // XYZZY_FACE_H_
