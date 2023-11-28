/*
 * MIT License
 *
 * Copyright (c) 2023 Gabor L Ugray
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

#ifndef ACTIVITY_FACE_H_
#define ACTIVITY_FACE_H_

/*
 * ACTIVITY watch face
 *
 * The Activity face lets you record activities like you would do with a fitness watch.
 * It supports different activities like running, biking, rowing etc., and for each recorded activity
 * it stores when it started and how long it was.
 * 
 * You can save up to 99 activities this way. Every once in a while you can chirp them out
 * using the watch's piezo buzzer as a modem, then clear the log in the watch.
 * To record and decode a chirpy transmission on your computer, you can use the web app here:
 * https://jealousmarkup.xyz/off/chirpy/rx/
 * 
 * Using the face
 * 
 * When you activate the face, it starts with the first screen to select the activity you want to log.
 * ALARM cycles through the list of activities.
 * LONG ALARM starts logging.
 * While logging is in progress, the face alternates between the elapsed time and the current time.
 * You can press ALARM to pause (e.g., while you hop in to the baker's for a croissant during your jog).
 * Pressing ALARM again resumes the activity.
 * LONG ALARM stops logging and saves the activity.
 * 
 * When you're not loggin, you can press LIGHT to access the secondary faces.
 * LIGHT #1 => Shows the size of the log (how many activities have been recorded).
 * LIGHT #2 => The screen to chirp out the data. Press LONG ALARM to start chirping.
 * LIGHT #3 => The screen to clear the log in the watch. Press LONG ALARM twice to clear data.
 *
 * Quirky details
 * 
 * The face will discard short activities (less than a minute) when you press LONG ALARM to finish logging.
 * These were probably logged by mistake, and it's better to save slots and chirping battery power for
 * stuff that really matters.
 * 
 * The face will continue to record an activity past the normal one-hour mark, when the watch
 * enters low energy mode. However, it will always stop at 8 hours. If an activity takes that long,
 * you probably just forgot to stop logging.
 * 
 * The log is stored in regular memory. It will be lost when you remove the battery, so make
 * sure you chirp it out before taking the watch apart.
 * 
 * See the top of activity_face.c for some customization options. What you most likely want to do
 * is reduce the list of activities shown on the first screen to the ones you are regularly doing.
 */

#include "movement.h"

void activity_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void activity_face_activate(movement_settings_t *settings, void *context);
bool activity_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void activity_face_resign(movement_settings_t *settings, void *context);

#define activity_face ((const watch_face_t){ \
    activity_face_setup, \
    activity_face_activate, \
    activity_face_loop, \
    activity_face_resign, \
    NULL, \
})

#endif // ACTIVITY_FACE_H_

