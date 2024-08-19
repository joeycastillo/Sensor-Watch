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


static const char _valid_letters[] = {'A', 'C', 'E', 'I', 'L', 'N', 'O', 'P', 'R', 'S'};

// From: https://gist.github.com/shmookey/b28e342e1b1756c4700f42f17102c2ff
// Number of words found: 284
static const char _legal_words[][WORDLE_LENGTH + 1] = {
    "ROPES", "RESIN", "PACES", "RIPEN", "ALIEN", "SPINE", "ROSIN", "PIERS", "CAPER", 
    "SNORE", "SANER", "RAILS", "SCORN", "PENIS", "NEARS", "ENROL", "PROSE", "CANES", 
    "POSER", "ACORN", "PAILS", "SLAIN", "REALS", "CLAPS", "PLIES", "PALES", "LIENS", 
    "PLAIN", "SLOPE", "REAPS", "CRAPE", "ASPEN", "COINS", "ARISE", "ALOES", "PANES", 
    "SCION", "SNARL", "COPRA", "PALER", "CLIPS", "PANIC", "PARSE", "PENAL", "SPARE", 
    "LIONS", "LINES", "SNARE", "PEONS", "CLEAN", "SPACE", "SCALE", "COILS", "SCRAP", 
    "OPINE", "NICER", "LOANS", "RACES", "RELIC", "NOISE", "PIANO", "CRANE", "SNAIL", 
    "SCORE", "CLEAR", "CROPS", "CORES", "COPSE", "PINES", "PANEL", "RINSE", "LOINS", 
    "PRONE", "ALONE", "RAISE", "OSIER", "LEARN", "SPICE", "SPOIL", "EARLS", "NAILS", 
    "PLANE", "CARES", "CRIES", "CORNS", "CORPS", "CLASP", "LACES", "ARSON", "LANES", 
    "OPENS", "SALON", "SINCE", "PLANS", "SCARE", "SPORE", "OCEAN", "AEONS", "PRICE", 
    "IRONS", "SCALP", "EPICS", "LIARS", "SPIRE", "LINER", "PILES", "SLICE", "LEANS", 
    "RAINS", "PLEAS", "SOLAR", "CAPES", "APRON", "RISEN", "POISE", "CONES", "PEARS", 
    "PERIL", "COALS", "OPALS", "ROLES", "CLOSE", "CAPON", "POLES", "EARNS", "CRISP", 
    "AROSE", "SCOPE", "AISLE", "CLANS", "CORAL", "SCRIP", "PAINS", "OPERA", "PAIRS", 
    "PEARL", "SIREN", "ACRES", "CAROL", "LAIRS", "PORES", "PRIES", "CRONE", "CANOE", 
    "LAPSE", "LEAPS", "SNIPE", "REINS", "PEALS", "SPEAR", "LOSER", "POLAR", "LANCE", 
    "CAIRN", "PLACE", "LASER", "SONIC", "EERIE", "PIECE", "ISLES", "NOOSE", "SNEER", 
    "SOLOS", "ELOPE", "INNER", "SLOOP", "SOARS", "SPREE", "SPANS", "PAPAL", "RIPER", 
    "COLON", "SCANS", "RARES", "PILLS", "CANON", "POLLS", "POPPA", "ERROR", "REARS", 
    "PESOS", "CRESS", "PENCE", "SPOOL", "COLOR", "NONCE", "CLASS", "SELLS", "NASAL", 
    "ERASE", "RILLS", "LAPEL", "COOLS", "EASEL", "COLIC", "SPELL", "SPOOR", "LASSO", 
    "APPAL", "PEACE", "SALSA", "SCENE", "NIECE", "CONIC", "APPLE", "SNAPS", "PEERS", 
    "ROARS", "SPARS", "SAILS", "SLOPS", "APACE", "POSES", "SENSE", "PEEPS", "CASES", 
    "CANAL", "CIRCA", "SLAPS", "SCOOP", "ROLLS", "PIPES", "SCARS", "LOOSE", "ROSES", 
    "LILAC", "OASES", "SOLES", "PAEAN", "PAPAS", "CRASS", "PROPS", "SEALS", "CACAO", 
    "LINEN", "SORES", "EASES", "POPES", "OASIS", "LOSES", "NOSES", "SIRES", "SPILL", 
    "CREPE", "ALIAS", "CROSS", "ARENA", "SPINS", "REPEL", "SPIES", "PRIOR", "POOLS", 
    "PRESS", "RISER", "AREAS", "SPOON", "SALES", "CREEP", "CEASE", "LOOPS", "ASSES", 
    "CALLS", "CRIER", "COCOA", "SEERS", "LOONS", "SLIPS", "PAPER", "REELS", "RISES", 
    "POSSE", "RARER", "SOILS", "PIPER", "INANE", "LOCAL", "PEASE", "ONION", "SLEEP", 
    "LEASE", "RACER", "LEPER", "SILLS", "CELLS",
#if (USE_EXPANDED_DICT != 1)
};
// These are words that'll never be used, but still need to be in the dictionary for guesses.
// Top 100K most common words from Wiktionary https://gist.github.com/h3xx/1976236
// Number of words found: 470
static const char _expanded_words[][WORDLE_LENGTH + 1] = {
#endif
#if (USE_EXPANDED_DICT != 0)
    "PARIS", "APRIL", "SPAIN", "EINEN", "ASCII", "EINER", "SEINE", "AINSI", "ALICE", 
    "ALLES", "ALORS", "EINES", "ALLER", "PEINE", "PARCE", "CELLE", "CLARA", "ELLES", 
    "ELLEN", "OLISI", "ALLEN", "ISAAC", "APRES", "CROIS", "SANOI", "PASSE", "ELSIE", 
    "REINE", "ELLER", "AARON", "CLARE", "IRENE", "ANNIE", "ELLOS", "PARLE", "ALLAN", 
    "PELLE", "CAIRO", "SENOR", "PENSE", "CECIL", "SEELE", "ORION", "SELON", "COSAS", 
    "PASSA", "ELLIS", "CARLO", "ENNEN", "SILAS", "EENEN", "OSCAR", "ONCLE", "CESSE", 
    "SONNE", "ASSIS", "PRISE", "SERAI", "CELIA", "NOIRE", "NORSE", "SINNE", "LIESS", 
    "ELIAS", "REPOS", "COLIN", "NOIRS", "CLAIR", "CIELO", "PARLA", "SOINS", "LASSE", 
    "NELLA", "PAOLO", "SOLON", "REPAS", "NANCE", "PAINE", "SAISI", "ELISE", "CESAR", 
    "CANNA", "SALLE", "SINON", "SINAI", "LOIRE", "PENSA", "LEILA", "REISE", "ELLAS", 
    "POORE", "EARLE", "CERCA", "LEISE", "POOLE", "AILES", "SANOA", "LEONE", "LILLE", 
    "PROIE", "CARNE", "SPIEL", "CERES", "ENSIN", "CINCO", "ROLLO", "ARRAS", "SEIEN", 
    "PRIER", "ANNAN", "CALLE", "LIISA", "SALIR", "LESSE", "LESEN", "LIIAN", "NEERE", 
    "ARIEL", "PIENI", "PIERO", "ERANO", "ELENA", "SILLE", "NEALE", "SEENE", "ROLLE", 
    "NELLE", "SOLLE", "ESSER", "PASAR", "PREIS", "ASIAN", "SENCE", "ANSON", "SERRA", 
    "CONAN", "SERAS", "SIENA", "SOPRA", "RENEE", "ALINE", "CORSE", "ASSAI", "INSEL", 
    "ROSIE", "SONIA", "APPEL", "CRISE", "CIRCE", "LINIE", "RENAN", "CAIRE", "COLLA", 
    "SANOO", "EENER", "ANCOR", "NEPAL", "REINO", "LAINE", "SOONE", "ALAIN", "LAPSI", 
    "INCAS", "INNES", "CARON", "ROSEN", "CASAS", "NOLAN", "SERRE", "PESAR", "SEARS", 
    "LEPIC", "LISLE", "LOSSE", "CINNA", "SERIE", "RIRES", "CORSO", "SOIRS", "CREER", 
    "POCOS", "SIENS", "ARLES", "CROCE", "IONIC", "PONER", "ESSEN", "SANON", "CESSA", 
    "SERIA", "ALPES", "NINON", "LILLA", "AINOA", "CORPO", "LESER", "ILLIS", "ROPER", 
    "ANNEE", "PAIRE", "PEPIN", "ORIEL", "CANNE", "AIRES", "ARCIS", "EASIE", "ANNOS", 
    "COLLE", "SELLE", "EILEN", "CAPRI", "ERICA", "ROCCO", "ARIAN", "CLEON", "ALLIE", 
    "PONCE", "COPIE", "INNAN", "NOCES", "NAPPE", "CORNE", "ESIIN", "ENCOR", "LORNA", 
    "SACRE", "PAPEL", "SAILE", "SAEPE", "CREON", "LLENO", "ELISA", "PASSO", "ASILE", 
    "LORCS", "ASIAA", "SANIN", "ONNEN", "SONNA", "AILIE", "ALIIS", "ECOLE", "CREES", 
    "PRESO", "CLARO", "EARES", "ROSSI", "COREA", "SANAN", "AESOP", "SAPOR", "EISEN", 
    "ACASO", "PARAS", "NANON", "LAPIS", "ARRAN", "CLLIA", "SACRA", "PRINS", "CENCI", 
    "CLAES", "SLAAP", "ROLLA", "COLES", "LORNE", "OLELO", "CASSE", "NILES", "PASOS", 
    "ESSAI", "ROSAS", "LLENA", "LEERE", "CLASE", "CALOR", "ROSSE", "ALLEE", "SOREL", 
    "SANAA", "SLONE", "OLSEN", "OOREN", "PARER", "PASSI", "POSSA", "PLAIE", "OPERE", 
    "SCAPE", "POLEN", "RIPON", "SCALA", "AILLE", "PALOS", "CLAPP", "ESCAP", "ELLEI", 
    "IONIA", "NICOL", "PAESE", "PERON", "ORSON", "INNEN", "AISNE", "RANCE", "SLAAN", 
    "PAOLI", "COLLO", "ANNAS", "ERROL", "CLERC", "SAINE", "RAINA", "PRESE", "PARIA", 
    "PERLE", "RECAL", "SINAE", "PESER", "OISIN", "PLENA", "CARLE", "PERES", "SACAR", 
    "ALPEN", "CORRE", "ACCES", "RILLA", "ANNAL", "PERSE", "SAALE", "PERRO", "AILSA", 
    "POCAS", "SOLEN", "PLASE", "SOLIS", "PAPPI", "COPIA", "ARIES", "ROCCA", "ALIOS", 
    "ROCAS", "PELOS", "NEPOS", "COLPA", "ISORA", "LECON", "SOANE", "SNELL", "ILLOS", 
    "PILAR", "ECLAC", "PRESA", "SILLA", "NIELS", "LIPPO", "CROLL", "PONEN", "POSEE", 
    "PIPPA", "ILLAN", "CENIS", "SANNA", "RASSI", "CERRO", "SCENA", "CASOS", "COLPO", 
    "POSSO", "POSEN", "EINAR", "ISLAS", "IPSIS", "SALEN", "ASIEN", "CREAN", "LENIN", 
    "LOCIS", "NENNE", "ILION", "NARES", "ONNEA", "PALAA", "PIPPO", "POLIS", "RICOS", 
    "ELSON", "SNOOP", "ANNIS", "PROPE", "ELLIE", "ERNIE", "PLIER", "SERES", "REINA", 
    "LIPPE", "OLINE", "PARIE", "ARLEE", "NIAIS", "LEONI", "RAINE", "LARES", "SEINS", 
    "CARRE", "POILS", "ALENE", "LINEA", "NEARE", "PENSO", "PRISA", "CAPEL", "PAREA", 
    "PEECE", "SALIO", "COELO", "SCIRE", "NELLO", "LIENE", "ORICE", "EPAIS", "PERCE", 
    "ALLIS", "PEPLE", "LARNE", "NEILL", "OLLEN", "CASCA", "LAPIN", "OLLIE", "SALIC", 
    "LIANE", "REESE", "ELSLI", "SPION", "RIENS", "LILAS", "PAPPA", "ERRER", "SPISE", 
    "CELIE", "OLSON", "IRREN", "ARIAS", "ARION", "PASEO", "CAERE", "PISAN", "CARRO", 
    "PAROI", "NOONE", "SEPPI", "OPPIA", "SEALE", "LIPPI", "PELAS", "COCOS", "PLACA", 
    "CONOR", "LANCA", "OSASI", "ALOIS", "NAIRN", "PIENO", "SPASS", "SAONE", "ALNAR", 
    "CARIA", "PIENA", 
#endif
};

#if (USE_EXPANDED_DICT == 1)
static const char _expanded_words[][WORDLE_LENGTH + 1] = {};
#endif


static const uint16_t _num_words = (sizeof(_legal_words) / sizeof(_legal_words[0]));
static const uint16_t _num_expanded_words = (sizeof(_expanded_words) / sizeof(_expanded_words[0]));
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
    for (size_t pos = curr_pos; pos < WORDLE_LENGTH;) {
        if (word_elements_result[++pos] != WORDLE_LETTER_CORRECT)
            return pos;
    }
    return WORDLE_LENGTH;
}

static uint8_t get_prev_pos(uint8_t curr_pos, WordleLetterResult *word_elements_result) {
    if (curr_pos == 0) return 0;
    for (int8_t pos = curr_pos; pos >= 0;) {
        if (word_elements_result[--pos] != WORDLE_LETTER_CORRECT)
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
    for (uint16_t i = 0; i < _num_expanded_words; i++) {
        is_exact_match = true;
        for (size_t j = 0; j < WORDLE_LENGTH; j++) {
            if (_valid_letters[word_elements[j]] != _expanded_words[i][j]) {
                is_exact_match = false;
                break;  
            }
        }
        if (is_exact_match) return _num_words + i;
    }
    return _num_words + _num_expanded_words;
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
    char buf[3];
    sprintf(buf, "%d", attempt+1);
    watch_display_string(buf, 3);
}

static void display_playing(wordle_state_t *state) {
    display_attempt(state->attempt);
    display_all_letters(state);
    state->curr_screen = SCREEN_PLAYING;
}

static void reset_all_elements(wordle_state_t *state) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        state->word_elements[i] = _num_valid_letters;
        state->word_elements_result[i] = WORDLE_LETTER_WRONG;
    }
    for (size_t i = 0; i < WORDLE_MAX_ATTEMPTS; i++) {
        state->guessed_words[i] = _num_words + _num_expanded_words;
    }
    state->using_random_guess = false;
    state->attempt = 0;
}

static void reset_incorrect_elements(wordle_state_t *state) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (state->word_elements_result[i] != WORDLE_LETTER_CORRECT)
            state->word_elements[i] = _num_valid_letters;
    }
}

static void reset_board(wordle_state_t *state) {
    reset_all_elements(state);
    state->curr_answer = get_random(_num_words);
    watch_clear_colon();
    state->position = get_first_pos(state->word_elements_result);
    display_playing(state);
    watch_display_string(" -", 4);
#if __EMSCRIPTEN__
    printf("ANSWER: %s\r\n", _legal_words[state->curr_answer]);
#endif
}

static void display_title(wordle_state_t *state) {
    state->curr_screen = SCREEN_TITLE;
    watch_display_string("WO  WordLE", 0);
}

#if !USE_DAILY_STREAK
static void display_continue_result(bool continuing) {
    watch_display_string(continuing ? "y" : "n", 9);
}

static void display_continue(wordle_state_t *state) {
    state->curr_screen = SCREEN_CONTINUE;
    watch_display_string("Cont ", 4);
    display_continue_result(state->continuing);
}
#endif

static void display_streak(wordle_state_t *state) {
    char buf[12];
    state->curr_screen = SCREEN_STREAK;
#if USE_DAILY_STREAK
    if (state->streak > 99)
        sprintf(buf, "WO  St--dy");
    else
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
    sprintf(buf," W   %s  ", subsecond % 2 ? "NICE" : "JOB ");
    watch_display_string(buf, 0);
}

static bool is_playing(const wordle_state_t *state) {
    if (state->attempt > 0) return true;
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (state->word_elements[i] != _num_valid_letters)
            return true;
    }
    return false;
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

static bool act_on_btn(wordle_state_t *state, const uint8_t pin) {
    switch (state->curr_screen)
    {
    case SCREEN_RESULT:
        reset_incorrect_elements(state);
        state->position = get_first_pos(state->word_elements_result);
        display_playing(state);
        return true;
    case SCREEN_TITLE:
#if USE_DAILY_STREAK
        if (state->prev_day == get_day_unix_time()) {
            display_wait(state);
        }
        else if (is_playing(state))
            display_playing(state);
        else
            display_streak(state);
#else
        if (is_playing(state)) {
            state->continuing = true;
            display_continue(state);
        }
        else
            display_streak(state);
#endif
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
        state->position = get_first_pos(state->word_elements_result);
        display_playing(state);
        return true;
#if USE_DAILY_STREAK
    case SCREEN_WAIT:
        (void) pin;
        display_title(state);
        return true;
#else
    case SCREEN_CONTINUE:
        switch (pin)
        {
        case BTN_ALARM:
            if (state->continuing)
                display_playing(state);
            else {
                reset_board(state);
                display_streak(state);
            }
            break;
        case BTN_LIGHT:
            state->continuing = !state->continuing;
            display_continue_result(state->continuing);
            break;
        }
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
    if (in_dict == _num_words + _num_expanded_words) {
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
        state->attempt = 0;
        state->curr_screen = SCREEN_WIN;
        if (state->streak < 0x7F)
            state->streak++;
#if USE_DAILY_STREAK
        state->prev_day = get_day_unix_time();
#endif
        return;
    }
    if (++state->attempt >= WORDLE_MAX_ATTEMPTS) {
        state->attempt = 0;
        state->curr_screen = SCREEN_LOSE;
        state->streak = 0;
        return;
    }
    state->curr_screen = SCREEN_RESULT;
    return;
}

#if (USE_RANDOM_GUESS != 0)
static const uint16_t _num_unique_words = 157;  // The _legal_words array begins with this many words where each letter is different.
static void insert_random_guess(wordle_state_t *state) {
    uint16_t random_guess;
    do {  // Don't allow the guess to be the same as the answer
        random_guess = get_random(USE_RANDOM_GUESS == 2 ? _num_unique_words : _num_words);
    } while (random_guess == state->curr_answer); 
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        for (size_t j = 0; j < _num_valid_letters; j++)
        {
            if (_legal_words[random_guess][i] == _valid_letters[j])
                state->word_elements[i] = j;     
        }
    } 
    state->position = WORDLE_LENGTH - 1;
    display_all_letters(state);
    state->using_random_guess = true;
}
#endif

void wordle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(wordle_state_t));
        memset(*context_ptr, 0, sizeof(wordle_state_t));
        wordle_state_t *state = (wordle_state_t *)*context_ptr;
        state->curr_screen = SCREEN_TITLE;
        reset_all_elements(state);
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void wordle_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    wordle_state_t *state = (wordle_state_t *)context;
#if USE_DAILY_STREAK
    uint32_t now = get_day_unix_time() ;
    if (state->prev_day <= (now + (60 *60 * 24))) state->streak = 0;
    if (state->curr_day != now) state->attempt = 0;
#endif
    state->using_random_guess = false;
    if (is_playing(state) && state->curr_screen >= SCREEN_RESULT) {
        reset_incorrect_elements(state);
        state->position = get_first_pos(state->word_elements_result); 
    }
    movement_request_tick_frequency(2);
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
            if (act_on_btn(state, BTN_LIGHT)) break;
            get_next_letter(state->position, state->word_elements);
            display_letter(state, true);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->curr_screen != SCREEN_PLAYING) break;
            get_prev_letter(state->position, state->word_elements);
            display_letter(state, true);
            break; 
        case EVENT_ALARM_BUTTON_UP:
            if (act_on_btn(state, BTN_ALARM)) break;
            display_letter(state, true);
            if (state->word_elements[state->position] == _num_valid_letters) break;
#if (USE_RANDOM_GUESS != 0)
            if (watch_get_pin_level(BTN_LIGHT) &&
            (state->using_random_guess || (state->attempt == 0 && state->position == 0))) {
                insert_random_guess(state);
                break;
            }
#endif
            state->position = get_next_pos(state->position, state->word_elements_result);
            if (state->position >= WORDLE_LENGTH) {
                get_result(state);
                state->using_random_guess = false;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->curr_screen != SCREEN_PLAYING) break;
            display_letter(state, true);
            state->position = get_prev_pos(state->position, state->word_elements_result);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
        case EVENT_ACTIVATE:
            break;
        case EVENT_TIMEOUT:
            if (state->curr_screen >= SCREEN_RESULT)
                display_title(state);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (state->curr_screen != SCREEN_TITLE)
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

