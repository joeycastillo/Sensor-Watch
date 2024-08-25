/*
 * MIT License
 *
 * Copyright (c) 2024 <David Volovskiy>
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
 * Wordle Face
 * A port of NY Times' Wordle game (https://www.nytimes.com/games/wordle/index.html)
 * A random 5 letter word is chosen and you have WORDLE_MAX_ATTEMPTS attempts to guess it.
 * Each guess must be a valid 5-letter word found in _legal_words in the C file.
 * The only letters used are _valid_letters, also found in the C file.
 * After a guess, the letters in the correct spot will remain, 
 * and the letters found in the word, but in the incorrect spot will blink.
 * The screen after the title screen if a new game is started shows the streak of games won in a row.
 * 
 * If USE_DAILY_STREAK is set to True, then the game can only be played once per day,
 *                  and the streak resets to 0 if a day goes by without playing the game.
 * 
 * Controls:
 *    Light Press
 *        If Playing: Next letter
 *        Else: Next screen
 *    Light Hold
 *        If Playing: Previous letter
 *        Else: None
 *
 *    Alarm Press
 *        If Playing: If USE_RANDOM_GUESS is set and Light btn held and 
 *                    (on first letter or already used a random guess) 
 *                    and first attempt: Use a random 5 letter word with all letters that are different.
 *                    Else: Next position
 * Next position
 *        Else: Next screen
 *    Alarm Hold
 *        If Playing: Previous position
 *        Else: None
 */

#define WORDLE_LENGTH 5
#define WORDLE_MAX_ATTEMPTS 6
#define USE_DAILY_STREAK false

/*  USE_RANDOM_GUESS
 *  0 = Don't allow quickly choosing a random quess
 *  1 = Allow using a random guess of any value that can be an answer
 *  2 = Allow using a random guess of any value that can be an answer where all of its letters are unique
*/
#define USE_RANDOM_GUESS 2
#include "wordle_face_dict.h"

static const uint16_t _num_words = (sizeof(_valid_words) / sizeof(_valid_words[0]));
static const uint16_t _num_possible_words = (sizeof(_possible_words) / sizeof(_possible_words[0]));
static const uint8_t _num_valid_letters = (sizeof(_valid_letters) / sizeof(_valid_letters[0]));

typedef enum {
    WORDLE_LETTER_WRONG = 0,
    WORDLE_LETTER_WRONG_LOC,
    WORDLE_LETTER_CORRECT,
    WORDLE_LETTER_COUNT
} WordleLetterResult;

typedef enum {
    SCREEN_PLAYING = 0,
    SCREEN_TITLE,
    SCREEN_STREAK,
    SCREEN_CONTINUE,
#if USE_DAILY_STREAK
    SCREEN_WAIT,
#endif
    SCREEN_RESULT,
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
    uint8_t attempt : 4;
    uint8_t position : 3;
    bool using_random_guess : 1;
    uint16_t curr_answer : 15;
    bool continuing : 1;
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

