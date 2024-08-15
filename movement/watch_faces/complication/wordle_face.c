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

#include <stdlib.h>
#include <string.h>
#include "wordle_face.h"
#if USE_DAILY_STREAK
#include "watch_utility.h"
#endif

#define FREQ 2

/*
TODO:
* Add a way to recount previous attempts
*/


// From: https://gist.github.com/shmookey/b28e342e1b1756c4700f42f17102c2ff

/*
Letter | Usage
_______|______
E      | 1519
S      | 1490
A      | 1213
R      | 1026
O      | 852
L      | 850
I      | 843
T      | 819  But looks bad across all positions
N      | 681
D      | 619  lowercase d looks like a in certain positions
C      | 525
U      | 514  P has more words with the other letters here (281 vs 198)
P      | 448
*/
static const char _valid_letters[] = {'A', 'C', 'E', 'I', 'L', 'N', 'O', 'P', 'R', 'S'};

// Number of words found: 281
static const char _legal_words[][WORDLE_LENGTH + 1] = {
    "SPIES", "SOLAR", "RAISE", "RARES", "PAEAN", "PLIES", "CRASS", "PEARS", "SNORE", 
    "POLES", "ROLLS", "ALOES", "LOSES", "SLICE", "PEACE", "POLLS", "POSES", "LANES", 
    "COPRA", "SPANS", "CANAL", "LOSER", "PAPER", "PILES", "CLASS", "RACER", "POOLS", 
    "PLAIN", "SPEAR", "SPARE", "INNER", "ALIEN", "NOSES", "EARLS", "SEALS", "LEARN", 
    "COLIC", "OPERA", "LOOSE", "SPOOR", "SCALE", "SOARS", "PAILS", "PRONE", "OPALS", 
    "PIPER", "RILLS", "CAIRN", "POISE", "LEAPS", "ELOPE", "NICER", "SLOOP", "PANES", 
    "SOLES", "CROSS", "NIECE", "LAIRS", "LEASE", "SALES", "SCENE", "SORES", "SNARL", 
    "SPIRE", "LASSO", "CLOSE", "OSIER", "SPOOL", "PRICE", "LOANS", "POSSE", "PENAL", 
    "SLAPS", "RELIC", "SINCE", "CIRCA", "LIARS", "RISES", "OPENS", "ROARS", "PACES", 
    "ARISE", "RISEN", "PENIS", "LAPEL", "CROPS", "CANON", "LAPSE", "SCION", "ARSON", 
    "AREAS", "SLAIN", "CANOE", "EERIE", "NOOSE", "PIANO", "PLANE", "CLASP", "SCARE", 
    "COCOA", "CRESS", "NASAL", "LOCAL", "RINSE", "SCARS", "PROPS", "OASES", "SLEEP", 
    "SNAPS", "SIRES", "CANES", "RAILS", "RESIN", "COLON", "PEASE", "POPES", "PENCE", 
    "AROSE", "REELS", "SALSA", "OCEAN", "PESOS", "OPINE", "RACES", "RAINS", "PRIES", 
    "CRIES", "CALLS", "PIERS", "CELLS", "SCRAP", "EARNS", "IRONS", "SPACE", "LOONS", 
    "SILLS", "COALS", "PIECE", "PALER", "REINS", "APACE", "SLOPE", "CREPE", "CONES", 
    "CAPER", "SEERS", "CAPES", "OASIS", "REAPS", "PALES", "CLAPS", "PLEAS", "INANE", 
    "COINS", "SNAIL", "CLEAR", "ROSIN", "LILAC", "SPARS", "SPINE", "NONCE", "CRISP", 
    "CRAPE", "AISLE", "CRONE", "SPOIL", "SPOON", "ARENA", "PARSE", "CASES", "SPICE", 
    "RIPER", "PILLS", "SOLOS", "SPINS", "PEERS", "RARER", "CONIC", "REARS", "CACAO", 
    "PAPAS", "ACRES", "ROPES", "CORAL", "CLEAN", "EASES", "SPILL", "SENSE", "PIPES", 
    "CLANS", "PRESS", "LOINS", "PAPAL", "APPLE", "PAIRS", "SCORN", "ALONE", "PEEPS", 
    "SPREE", "SNARE", "CLIPS", "EASEL", "CAROL", "ASPEN", "SALON", "LOOPS", "PEALS", 
    "SNEER", "PLACE", "SELLS", "LINEN", "CRIER", "ACORN", "SLIPS", "ERASE", "LIONS", 
    "NAILS", "REPEL", "CORES", "LEPER", "APPAL", "ROSES", "SCORE", "RISER", "CREEP", 
    "CAPON", "ERROR", "NOISE", "CARES", "APRON", "SOILS", "SLOPS", "PAINS", "EPICS", 
    "SANER", "SAILS", "PRIOR", "ASSES", "COILS", "SCOOP", "LACES", "SCALP", "CRANE", 
    "PLANS", "ISLES", "SPORE", "PANIC", "COOLS", "SPELL", "ALIAS", "PORES", "SCRIP", 
    "PEARL", "PANEL", "ENROL", "LANCE", "CORPS", "LINES", "COPSE", "ONION", "NEARS", 
    "RIPEN", "LINER", "SCOPE", "SCANS", "SNIPE", "CEASE", "LEANS", "AEONS", "PINES", 
    "POPPA", "ROLES", "REALS", "PERIL", "POSER", "PROSE", "POLAR", "CORNS", "LIENS", 
    "SIREN", "PEONS", 
};

static const uint16_t _num_words = (sizeof(_legal_words) / sizeof(_legal_words[0]));
static const uint8_t _num_valid_letters = (sizeof(_valid_letters) / sizeof(_valid_letters[0]));

static uint32_t get_random(uint32_t max) {
    #if __EMSCRIPTEN__
    return rand() % max;
    #else
    return arc4random_uniform(max);
    #endif
}

static uint8_t get_first_pos(WordleLetterResult *word_elements_result) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (word_elements_result[i] != WORDLE_LETTER_CORRECT)
            return i;
    }
    return 0;
}

static uint8_t get_next_pos(uint8_t curr_pos, WordleLetterResult *word_elements_result) {
    for (size_t pos = curr_pos+1; pos < WORDLE_LENGTH; pos++) {
        if (word_elements_result[pos] != WORDLE_LETTER_CORRECT)
            return pos;
    }
    return WORDLE_LENGTH;
}

static uint8_t get_prev_pos(uint8_t curr_pos, WordleLetterResult *word_elements_result) {
    if (curr_pos == 0) return 0;
    for (size_t pos = curr_pos-1; pos > 0; pos--) {
        if (word_elements_result[pos] != WORDLE_LETTER_CORRECT)
            return pos;
    }
    return curr_pos;
}

static void get_next_letter(uint8_t curr_pos, uint8_t *word_elements) {
    if (word_elements[curr_pos] >= _num_valid_letters) word_elements[curr_pos] = 0;
    else word_elements[curr_pos] = (word_elements[curr_pos] + 1) % _num_valid_letters;
}

static void get_prev_letter(uint8_t curr_pos, uint8_t *word_elements) {
    if (word_elements[curr_pos] >= _num_valid_letters) word_elements[curr_pos] = _num_valid_letters - 1;
    else word_elements[curr_pos] = (word_elements[curr_pos] + _num_valid_letters - 1) % _num_valid_letters;
}

static void display_letter(wordle_state_t *state, bool display_dash) {
    char buf[1 + 1];
    if (state->word_elements[state->position] >= _num_valid_letters) {
        if (display_dash)
            watch_display_string("-", state->position + 5);
        else
            watch_display_string(" ", state->position + 5);
        return;
    }
    sprintf(buf, "%c", _valid_letters[state->word_elements[state->position]]);
    watch_display_string(buf, state->position + 5);
}

static void display_all_letters(wordle_state_t *state) {
    uint8_t prev_pos = state->position;
    watch_display_string(" ", 4);
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        state->position = i;
        display_letter(state, false);
    }
    state->position = prev_pos;
}

static uint32_t check_word_in_dict(uint8_t *word_elements) {
    bool is_exact_match;
    for (uint16_t i = 0; i < _num_words; i++) {
        is_exact_match = true;
        for (size_t j = 0; j < WORDLE_LENGTH; j++) {
            if (_valid_letters[word_elements[j]] != _legal_words[i][j]) {
                is_exact_match = false;
                break;  
            }
        }
        if (is_exact_match) return i;
    }
    return _num_words;
}

static bool check_word(wordle_state_t *state) {
    // Exact
    bool is_exact_match = true;
    bool answer_already_accounted[WORDLE_LENGTH] = { false };
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (_valid_letters[state->word_elements[i]] == _legal_words[state->curr_answer][i]) {
            state->word_elements_result[i] = WORDLE_LETTER_CORRECT;
            answer_already_accounted[i] = true;
        }
        else {
            state->word_elements_result[i] = WORDLE_LETTER_WRONG;
            is_exact_match = false;
        }
    }
    if (is_exact_match) return true;
    // Wrong Location
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (state->word_elements_result[i] != WORDLE_LETTER_WRONG) continue;
        for (size_t j = 0; j < WORDLE_LENGTH; j++) {
            if (answer_already_accounted[j]) continue;
            if (_valid_letters[state->word_elements[i]] == _legal_words[state->curr_answer][j]) {
                state->word_elements_result[i] = WORDLE_LETTER_WRONG_LOC;
                answer_already_accounted[j] = true;
                break;
            }
        }
    }
    return false;
}

static void display_attempt(uint8_t attempt) {
    char buf[2];
    sprintf(buf, "%d", attempt+1);
    watch_display_string(buf, 3);
}

static void show_start_of_attempt(wordle_state_t *state) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (state->word_elements_result[i] != WORDLE_LETTER_CORRECT)
            state->word_elements[i] = _num_valid_letters;
    }
    display_attempt(state->attempt);
    display_all_letters(state);
    state->position = get_first_pos(state->word_elements_result);
    state->curr_screen = SCREEN_PLAYING;
}

static void reset_board(wordle_state_t *state) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        state->word_elements[i] = _num_valid_letters;
        state->word_elements_result[i] = WORDLE_LETTER_WRONG;
    }
    for (size_t i = 0; i < WORDLE_MAX_ATTEMPTS; i++) {
        state->guessed_words[i] = _num_words;
    }
    state->curr_answer = get_random(_num_words);
    state->attempt = 0;
    watch_clear_colon();
    watch_display_string(" ", 4);
    show_start_of_attempt(state);
    watch_display_string("-", 5);
#if __EMSCRIPTEN__
    printf("ANSWER: %s\r\n", _legal_words[state->curr_answer]);
#endif
}

static void display_title(wordle_state_t *state) {
    state->curr_screen = SCREEN_TITLE;
    watch_display_string("WO  WordLE", 0);
}

static void display_streak(wordle_state_t *state) {
    char buf[12];
    state->curr_screen = SCREEN_STREAK;
#if USE_DAILY_STREAK
    sprintf(buf, "WO  St%2ddy", state->streak);
#else
    sprintf(buf, "WO  St%4d", state->streak);
#endif
    watch_display_string(buf, 0);
    watch_set_colon();
}

#if USE_DAILY_STREAK
static void display_wait(wordle_state_t *state) {
    state->curr_screen = SCREEN_WAIT;
    if (state->streak < 40) {
        char buf[13];
        sprintf(buf,"WO%2d WaIt ", state->streak);
        watch_display_string(buf, 0);
    }
    else {  // Streak too long to display in top-right
        watch_display_string("WO   WaIt ", 0);
    }
}

static uint32_t get_day_unix_time(void) {
    watch_date_time now = watch_rtc_get_date_time();
    now.unit.hour = now.unit.minute = now.unit.second = 0;
    return watch_utility_date_time_to_unix_time(now, 0);
}
#endif

static void display_not_in_dict(wordle_state_t *state) {
    state->curr_screen = SCREEN_NO_DICT;
    watch_display_string("nodict", 4);
}

static void display_already_guessed(wordle_state_t *state) {
    state->curr_screen = SCREEN_ALREADY_GUESSED;
    watch_display_string("GUESSD", 4);
}

static void display_lose(wordle_state_t *state, uint8_t subsecond) {
    char buf[WORDLE_LENGTH + 6];
    sprintf(buf," L   %s", subsecond % 2 ? _legal_words[state->curr_answer] : "     ");
    watch_display_string(buf, 0);
}

static void display_win(wordle_state_t *state, uint8_t subsecond) {
    (void) state;
    char buf[13];
    sprintf(buf," W   %s  ", subsecond % 2 ? "NICE" : "JOb ");
    watch_display_string(buf, 0);
}

static void display_result(wordle_state_t *state, uint8_t subsecond) {
    char buf[WORDLE_LENGTH + 1];
    for (size_t i = 0; i < WORDLE_LENGTH; i++)
    {
        switch (state->word_elements_result[i])
        {
        case WORDLE_LETTER_WRONG:
            buf[i] = '-';
            break;
        case WORDLE_LETTER_CORRECT:
            buf[i] = _valid_letters[state->word_elements[i]];
            break;
        case WORDLE_LETTER_WRONG_LOC:
            if (subsecond % 2)
                buf[i] = ' ';
            else
               buf[i] = _valid_letters[state->word_elements[i]]; 
        default:
            break;
        }
    }
    watch_display_string(buf, 5);
}

static bool act_on_btn(wordle_state_t *state) {
    switch (state->curr_screen)
    {
    case SCREEN_RESULT:
        show_start_of_attempt(state);
        return true;
    case SCREEN_TITLE:
#if USE_DAILY_STREAK
        if (state->prev_day == get_day_unix_time()) {
            display_wait(state);
            return true;
        }
#endif
        if (state->playing)
            show_start_of_attempt(state);
        else
            display_streak(state);
        return true;
    case SCREEN_STREAK:
#if USE_DAILY_STREAK
        state->curr_day = get_day_unix_time();
#endif
        reset_board(state);
        return true;
    case SCREEN_WIN:
    case SCREEN_LOSE:
        display_title(state);
        return true;
    case SCREEN_NO_DICT:
    case SCREEN_ALREADY_GUESSED:
        show_start_of_attempt(state);
        return true;
#if USE_DAILY_STREAK
    case SCREEN_WAIT:
        display_title(state);
        return true;
#endif
    default:
        return false;
    }
    return false;
}

static void get_result(wordle_state_t *state) {
    // Check if it's in the dict
    uint16_t in_dict = check_word_in_dict(state->word_elements);
    if (in_dict == _num_words) {
        display_not_in_dict(state);
        return;
    }

    // Check if already guessed
    for (size_t i = 0; i < WORDLE_MAX_ATTEMPTS; i++) {
        if(in_dict == state->guessed_words[i]) {
            display_already_guessed(state);
            return;
        }
    }

    state->guessed_words[state->attempt] = in_dict;
    bool exact_match = check_word(state);
    if (exact_match) {
        state->playing = false;
        state->curr_screen = SCREEN_WIN;
        state->streak++;
#if USE_DAILY_STREAK
        state->prev_day = get_day_unix_time();
#endif
        return;
    }
    if (state->attempt++ > WORDLE_MAX_ATTEMPTS) {
        state->playing = false;
        state->curr_screen = SCREEN_LOSE;
        state->streak = 0;
        return;
    }
    state->curr_screen = SCREEN_RESULT;
    return;
}

void wordle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(wordle_state_t));
        memset(*context_ptr, 0, sizeof(wordle_state_t));
        wordle_state_t *state = (wordle_state_t *)*context_ptr;
        state->curr_screen = SCREEN_TITLE;
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void wordle_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    wordle_state_t *state = (wordle_state_t *)context;
#if USE_DAILY_STREAK
    uint32_t now = get_day_unix_time() ;
    if (state->prev_day <= (now + (60 *60 * 24))) state->streak = 0;
    if (state->curr_day != now) state->playing = false;
#endif
    movement_request_tick_frequency(FREQ);
    display_title(state);
}

bool wordle_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    wordle_state_t *state = (wordle_state_t *)context;

    switch (event.event_type) {
        case EVENT_TICK:
            switch (state->curr_screen)
            {
            case SCREEN_PLAYING:
                if (event.subsecond % 2) {
                    display_letter(state, true);
                } else {
                    watch_display_string(" ", state->position + 5);
                }
                break;
            case SCREEN_RESULT:
                display_result(state, event.subsecond);
                break;
            case SCREEN_LOSE:
                display_lose(state, event.subsecond);
                break;
            case SCREEN_WIN:
                display_win(state, event.subsecond);
                break;
            default:
                break;
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (act_on_btn(state)) break;
            get_next_letter(state->position, state->word_elements);
            display_letter(state, true);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->curr_screen != SCREEN_PLAYING) break;
            get_prev_letter(state->position, state->word_elements);
            display_letter(state, true);
            break; 
        case EVENT_ALARM_BUTTON_UP:
            if (act_on_btn(state)) break;
            display_letter(state, true);
            if (state->word_elements[state->position] == _num_valid_letters) break;
            state->playing = true;
            state->position = get_next_pos(state->position, state->word_elements_result);
            if (state->position >= WORDLE_LENGTH)
                get_result(state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->curr_screen != SCREEN_PLAYING) break;
            display_letter(state, true);
            state->position = get_prev_pos(state->position, state->word_elements_result);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
        case EVENT_ACTIVATE:
        case EVENT_TIMEOUT:
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (state->curr_screen == SCREEN_TITLE)
                display_title(state);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void wordle_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

