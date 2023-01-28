/*
 * MIT License
 *
 * Copyright (c) 2023 tslil clingman
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

#ifndef AB_FACE_H_
#define AB_FACE_H_

/*
 * AB Face is an activity-break tracking face.
 *
 * The basic premise is that the user sets two time lengths, one for the active
 * phase and one for the break phase. If desired, the user may also set a
 * number of laps to be done (activity -> break is one lap). The watch then
 * either counts down the number of laps remaining, or counts up forever. Both
 * phases may be paused while running, and the overall progress may be reset
 *
*/
#include "movement.h"

void ab_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void ab_face_activate(movement_settings_t *settings, void *context);
bool ab_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void ab_face_resign(movement_settings_t *settings, void *context);

#define ab_face ((const watch_face_t){ \
    ab_face_setup, \
    ab_face_activate, \
    ab_face_loop, \
    ab_face_resign, \
    NULL, \
})

#endif // AB_FACE_H_
