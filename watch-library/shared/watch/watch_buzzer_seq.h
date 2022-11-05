/*
 * MIT License
 *
 * Copyright (c) 2020 Joey Castillo / Andreas Nebinger
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
#ifndef _WATCH_BUZZER_SEQ_H_INCLUDED
#define _WATCH_BUZZER_SEQ_H_INCLUDED
////< @file watch_buzzer_seq.h

#include "watch.h"

/** @addtogroup buzzer Buzzer
  * @brief This section covers functions related to the piezo buzzer embedded in the F-91W's back plate.
  */
/// @{
/** @brief Plays the given sequence of notes in a non-blocking way.
  * @param note_sequence A pointer to the sequence of buzzer note & duration tuples, ending with a zero.
  * @param callback_on_end A pointer to a callback function to be invoked when the sequence has finished playing.
  * @note This function plays the sequence asynchronously, so the ui will not be blocked. Be aware that
  *       it internally relies on the 32 Hz tick callback, so you will not be able to use that otherwise!
  */
void watch_buzzer_play_sequence(int8_t *note_sequence, void (*callback_on_end)(void));

/** @brief Aborts a playing sequence.
  */
void watch_buzzer_abort_sequence(void);

/// @}
#endif
