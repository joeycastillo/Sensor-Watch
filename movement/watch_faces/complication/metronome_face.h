/*
 * MIT License
 *
 * Copyright (c) 2023 Austin Teets
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

#ifndef METRONOME_FACE_H_
#define METRONOME_FACE_H_

#include "movement.h"

/*
 * A Metronome watch complication
 * Allows the user to set the BPM, counts per measure, beep sound on/off
 * Screen flashes on on the beat and off on the half beat (1/8th note)
 * Beep will sound high for downbeat and low for subsequent beats in measure
 * USE:
 *      Press Alarm to start/stop metronome_face
 *      Hold Alarm to enter settings menu
 *          Short Light press will move through options
 *          Short Alarm press will increment/toggle options
 *          Long alarm press will exit options
 */
 
typedef enum {
    metWait,
    metRun,
    setMenu
} metronome_mode_t;

typedef enum {
    hundred,
    ten,
    one,
    count,
    alarm
} setting_cursor_t;

typedef struct {
    // Anything you need to keep track of, put it here!
    uint8_t bpm;
    double correction;
    double curCorrection;
    int count;
    int tick;
    int curTick;
    int curBeat;
    int halfBeat;
    metronome_mode_t mode : 3;
    setting_cursor_t setCur : 4;
    bool soundOn;
} metronome_state_t;

void metronome_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void metronome_face_activate(movement_settings_t *settings, void *context);
bool metronome_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void metronome_face_resign(movement_settings_t *settings, void *context);

#define metronome_face ((const watch_face_t){ \
    metronome_face_setup, \
    metronome_face_activate, \
    metronome_face_loop, \
    metronome_face_resign, \
    NULL, \
})

#endif // METRONOME_FACE_H_

