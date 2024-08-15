/*
 * MIT License
 *
 * Copyright (c) 2024 <#author_name#>
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

#ifndef WORDLE_FACE_H_
#define WORDLE_FACE_H_

#include "movement.h"

/*
 * A DESCRIPTION OF YOUR WATCH FACE
 *
 * and a description of how use it
 *
 */

#define WORDLE_LENGTH 5
#define WORDLE_MAX_ATTEMPTS 6
#define USE_DAILY_STREAK true

typedef enum {
    WORDLE_LETTER_WRONG = 0,
    WORDLE_LETTER_WRONG_LOC,
    WORDLE_LETTER_CORRECT,
    WORDLE_LETTER_COUNT
} WordleLetterResult;

typedef enum {
    SCREEN_PLAYING = 0,
    SCREEN_RESULT,
    SCREEN_TITLE,
    SCREEN_STREAK,
#if USE_DAILY_STREAK
    SCREEN_WAIT,
#endif
    SCREEN_WIN,
    SCREEN_LOSE,
    SCREEN_NO_DICT,
    SCREEN_ALREADY_GUESSED,
    SCREEN_COUNT
} WordleScreen;

typedef struct {
    // Anything you need to keep track of, put it here!
    uint8_t word_elements[WORDLE_LENGTH];
    WordleLetterResult word_elements_result[WORDLE_LENGTH];
    uint16_t guessed_words[WORDLE_MAX_ATTEMPTS];
    uint8_t attempt : 3;
    uint8_t position : 3;
    bool playing : 1;
    bool unused : 1;
    uint16_t curr_answer;
    uint8_t streak;
    WordleScreen curr_screen;
#if USE_DAILY_STREAK
    uint32_t prev_day;
    uint32_t curr_day;
#endif
} wordle_state_t;

void wordle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void wordle_face_activate(movement_settings_t *settings, void *context);
bool wordle_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void wordle_face_resign(movement_settings_t *settings, void *context);

#define wordle_face ((const watch_face_t){ \
    wordle_face_setup, \
    wordle_face_activate, \
    wordle_face_loop, \
    wordle_face_resign, \
    NULL, \
})

#endif // WORDLE_FACE_H_

