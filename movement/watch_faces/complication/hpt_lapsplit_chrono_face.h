/*
 * MIT License
 *
 * Copyright (c) 2024 Zach Miller
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

#ifndef HPT_LAPSPLIT_CHRONO_FACE_H_
#define HPT_LAPSPLIT_CHRONO_FACE_H_

#include "movement.h"

/*
 * A lap/split chronograph accurate to thousandths of a second (though only hundreths are displayed).
 *
 * Display:
 * The chronograph face will display CH in the day-of-week digits to indicate the mode.
 * The chronograph time will be displayed in the primary digits in MM:SS HH format. If the time exceeds 1 hour,
 * the number of hours will be displayed in the top right corner (up to 24 hours). The colon in the time display will flash while
 * the chronograph is running. If the chronograph is in "lap" mode, the word "LAP" will be displayed, otherwise,
 * the chronograph is in "split" mode.
 *
 * In Lap mode, the number of recorded laps will be displayed in the top right corner of the display, up to 39 laps
 * before restarting from zero. In split mode, the upper right corner of the display will show hours elapsed, up to 39.
 * If more than 39 hours have elapsed in split mode, the letter E will show, indicating an Excessive amount of time has elapsed.
 *
 * Buttons:
 * - LIGHT: Lap+Split/Reset -  Pressing this while the chronograph is running will display a lap/split time while the chronograph
 *   continues to run in the background (This is indicated by the flashing colon). In lap mode, the
 *   chronograph will be restated from zero. Press this again while a lap/split time is being
 *   displayed to return to the running time. Press this while the chronograph is paused to reset to zero.
 *   Press this while the chronograph is stopped and reading zero will toggle between "lap" and "split" modes
 * - ALARM: Start/Stop - Press this to start or pause the chronograph.
 *
 * Two-finisher operation: While the chronograph is "split" mode and running, press [LIGHT] when the first
 * finisher crosses the line to display their split time. The chronograph will continue to run in the background.
 * Press [ALARM] when the second finisher crosses the line to stop the chronograph. The display will continue to
 * show the time of the first finisher. Press [LIGHT] to show the finish time of the second competitor. Press [LIGHT]
 * again to reset the chronograph, or [ALARM] to start the timer again.
 *
 * If the chronograph is stopped, the display will time out after the configured time and return to the main screen
 */

#define LCF_MODE_LAP 1
#define LCF_MODE_SPLIT 0

#define LCF_RUN_RUNNING 1
#define LCF_RUN_STOPPED 0

// show the time based on "splitTs"
#define LCF_DISPLAY_SPLIT 1
// show the time based on the time elapsed since "startTs"
#define LCF_DISPLAY_TIME 0

typedef struct
{
    /** LCF_MODE */
    uint8_t mode : 1;

    /** LCF_DISPLAY */
    uint8_t display : 1;

    /** LCF_RUN */
    uint8_t running : 1;

    uint8_t _padding1 :5;

    // up to 39 laps, then reset
    uint8_t laps : 6;

    uint8_t _padding2 :2;

    // when running, start timestamp is the zero index from which the timer is running from
    uint64_t startTs;

    // duration recorded time when chronograph is paused, in 1/1024ths of a second
    uint64_t pausedTs;

    // duration of lap/split time
    uint64_t splitTs;
} hpt_lapsplit_chrono_state_t;

void hpt_lapsplit_chrono_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void hpt_lapsplit_chrono_face_activate(movement_settings_t *settings, void *context);
bool hpt_lapsplit_chrono_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void hpt_lapsplit_chrono_face_resign(movement_settings_t *settings, void *context);

#define hpt_lapsplit_chrono_face ((const watch_face_t){ \
    hpt_lapsplit_chrono_face_setup,                     \
    hpt_lapsplit_chrono_face_activate,                  \
    hpt_lapsplit_chrono_face_loop,                      \
    hpt_lapsplit_chrono_face_resign,                    \
    NULL,                                           \
})

#endif // HPT_LAPSPLIT_CHRONO_FACE_H_
