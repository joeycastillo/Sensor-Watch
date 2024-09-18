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
 * If WORDLE_USE_DAILY_STREAK is set to True, then the game can only be played once per day,
 *                  and the streak resets to 0 if a day goes by without playing the game.
 * 
 * Controls:
 *    Light Press
 *        If Playing: Next letter
 *        Else: Next screen
 *    Light Hold
 *        If Playing: Previous letter
 *        Else: Toggle Hard-Mode. This is skipping over letters that have been confirmed
 *              to not be in the word (indicated via 'H' in the top-right)
 *
 *    Alarm Press
 *        If Playing: If WORDLE_USE_RANDOM_GUESS is set and Light btn held and 
 *                    (on first letter or already used a random guess) 
 *                    and first attempt: Use a random 5 letter word with all letters that are different.
 *                    Else: Next position
 *        Else: Next screen
 *    Alarm Hold
 *        If Playing: Previous position
 *        Else: None
 * 
 * Note: Actual Hard Mode in Wordle game is "Any revealed hints must be used in subsequent guesses"
 *       But that came off as clunky UX on the Casio. So instead it only removes unused letters from the keyboard
 *       as that also simplifies the keyboard.
 */

#define WORDLE_LENGTH 5
#define WORDLE_MAX_ATTEMPTS 6
/*  WORDLE_USE_DAILY_STREAK
 *  0 = Don't ever reset the streak or the puzzle.
 *  1 = Reset the streak and puzzle 24hrs after starting a puzzle and not finishing it.
 *      If the last puzzle was started at 8AM, it'll be considered failed at 8AM the next day.
 *  2 = Reset the streak and puzzle if a puzzle goes unsolved or not started a day after the previous one.
 *      If the last puzzle was started at 8AM, it'll be considered failed at midnight the next day.
 *      This will not be the case if the puzzle is started at 8AM, continued at 11:59PM and solved at 12:01AM, the game will let that slide.
 *      Starting a new game instead of continuing is not allowed in this state.
*/
#define WORDLE_USE_DAILY_STREAK 1
#define WORDLE_ALLOW_NON_WORD_AND_REPEAT_GUESSES false  // This allows non-words to be entered and repeat guesses to be made. It saves ~11.5KB of ROM.
/*  WORDLE_USE_RANDOM_GUESS
 *  0 = Don't allow quickly choosing a random quess
 *  1 = Allow using a random guess of any value that can be an answer
 *  2 = Allow using a random guess of any value that can be an answer where all of its letters are unique
 *  3 = Allow using a random guess of any value that can be an answer, and it's considered one of the best initial choices.
*/
#define WORDLE_USE_RANDOM_GUESS 2
#include "wordle_face_dict.h"

#define WORDLE_NUM_WORDS (sizeof(_valid_words) / sizeof(_valid_words[0]))
#define WORDLE_NUM_POSSIBLE_WORDS (sizeof(_possible_words) / sizeof(_possible_words[0]))
#define WORDLE_NUM_VALID_LETTERS (sizeof(_valid_letters) / sizeof(_valid_letters[0]))

typedef enum {
    WORDLE_LETTER_WRONG = 0,
    WORDLE_LETTER_WRONG_LOC,
    WORDLE_LETTER_CORRECT,
    WORDLE_LETTER_COUNT
} WordleLetterResult;

typedef enum {
    SCREEN_TITLE = 0,
    SCREEN_STREAK,
    SCREEN_CONTINUE,
#if WORDLE_USE_DAILY_STREAK
    SCREEN_WAIT,
#endif
    SCREEN_PLAYING,
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
#if !WORDLE_ALLOW_NON_WORD_AND_REPEAT_GUESSES
    uint16_t guessed_words[WORDLE_MAX_ATTEMPTS];
#endif
    uint8_t attempt : 4;
    uint8_t position : 3;
    bool using_random_guess : 1;
    uint16_t curr_answer : 14;
    bool continuing : 1;
    bool skip_wrong_letter : 1;
    uint8_t streak;
    WordleScreen curr_screen;
    bool known_wrong_letters[WORDLE_NUM_VALID_LETTERS];
    uint32_t day_last_game_started;
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

