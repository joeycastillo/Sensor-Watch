#include <stdlib.h>
#include <string.h>
#include "discgolf_face.h"
#include "watch.h"          // Remember to change number of courses in this file
#include "watch_utility.h"

/* 
 * Keep track of scores in discgolf or golf!
 * The watch face operates in three different modes:
 *
 *  - dg_setting: Select a course
 *      Enter this mode by holding down the light button. The screen will display
 *      the label for the hole and the lowest score since last boot. 
 *      Press alarm to loop through the holes. Press the light button to make a 
 *      selection. This will reset all scores and start a new game in dg_idle mode.
 *
 *  -dg_idle: We're playing a hole
 *      This either shows your current score relative to par, or the score for a
 *      particular hole. 
 *      At the start of a game, press alarm to loop through the holes and leave it
 *      your starting hole. For optimal experience, play the course linearly after that
 *      If you're viewing the hole you're supposed to be playing, the watch face will
 *      display your score relative to par.
 *      Use the alarm button to view other holes than the one you're playing, in which
 *      case the input score for that hole will be displayed, in case it needs changing.
 *      Long press the alarm button to snap back to currently playing hole.
 *      To input scores for a hole in this mode, press the light button.
 *
 *  -dg_scoring: Input score for a hole
 *      In this mode, if the score is 0 (hasn't been entered during this round),
 *      it will blink, indicating we're in scoring mode. Press the alarm button
 *      to increment the score up until 15, in which case it loops back to 0. 
 *      Press the light button to save the score for that hole, advance one hole
 *      if you're not editing an already input score, and returning to idle mode.
 *
 *  When all scores have been entered, the LAP indicator turns on. At that point, if we enter 
 *  dg_setting to select a course, the score for that round is evaluated against the current 
 *  lowest score for that course, and saved if it is better.
*/
///////////////////////////////////////////////////////////////////////////////////////////////
// Enter course data
/* Initialize lowest scores with a high number */
int8_t best[courses];

static const uint8_t pars[][18] = {
   { 3, 3, 4, 3, 3, 3, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },    // Grafarholt
   { 3, 4, 3, 3, 4, 3, 3, 3, 3, 4, 3, 3, 3, 3, 3, 3, 3, 3 },    // Gufunes
   { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0 },    // Vífilsstaðir
   { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0 },    // Dalvegur
   { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0 },    // Laugardalur
   { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0 },    // Guðmundarlundur
   { 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 },    // Víðistaðatún
   { 3, 3, 3, 4, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 },    // Fossvogur
   { 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 },    // Klambratún
   { 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 },    // Seljahverfi
   { 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 }     // Fella- og Hóla
};
static const uint8_t holes[] = {                                // Number of holes on each course
    18,
    18,
    10,
    10,
    10,
    10,
    9,
    9,
    9,
    9,
    9
};
/* Two-letter descriptive labels, second field can only be A, B, C, D, E, F, H, I, J, L, N, O, R, T, U and X. */
static const char labels[][2] = {
    { 'G', 'H' },
    { 'G', 'N' },
    { 'V', 'I' },
    { 'D', 'V' },
    { 'L', 'A' },
    { 'G', 'L' },
    { 'V', 'T' },
    { 'F', 'V' },
    { 'K', 'T' },
    { 'S', 'E' },
    { 'F', 'H' }
};

// End of course data
///////////////////////////////////////////////////////////////////////////////////////////////

/* Beep function */
static inline void beep(movement_settings_t *settings) {
    if (settings->bit.button_should_sound) watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
}

/* Prep for a new round */
static inline void reset(discgolf_state_t *state) {
    for (int i = 0; i < holes[state->course]; i++) {
        state->scores[i] = 0;
    }
    state->hole = 1;
    watch_clear_indicator(WATCH_INDICATOR_LAP);
    return;
}

/* Total number of throws so far */
static inline uint8_t score_sum(discgolf_state_t *state) {
    uint8_t sum = 0;
    for (int i = 0; i < holes[state->course]; i++) {
        sum = sum + state->scores[i];
    }
    return sum;
}

/* Count how many holes have been played */
static inline uint8_t count_played(discgolf_state_t *state) {
    uint8_t holes_played = 0;
    for (int i = 0; i < holes[state->course]; i++) {
        if (state->scores[i] > 0) holes_played++;
    }
    return holes_played;
}


/* Calculate the current score relative to par */
static inline int8_t calculate_score(discgolf_state_t *state) {
    uint8_t par_sum = 0;
    uint8_t score_sum = 0;
    
    for (int i = 0; i < holes[state->course]; i++) {
        if (state->scores[i] > 0) {
            par_sum = par_sum + pars[state->course][i];
            score_sum = score_sum + state->scores[i];
        }
    }
    return score_sum - par_sum;
}

/* Store score if it's the best so far */
static inline void store_best(discgolf_state_t *state) {
    uint8_t played = count_played(state);
    if ( played == holes[state->course] ) {
        int8_t high_score = calculate_score(state);
        if (high_score < best[state->course] ) {
            best[state->course] = high_score;
        }
    }
}

/* Configuration at boot, the high score array can be initialized with your high scores if they're known */
void discgolf_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
       *context_ptr = malloc(sizeof(discgolf_state_t));
       discgolf_state_t *state = (discgolf_state_t *)*context_ptr;
       memset(*context_ptr, 0, sizeof(discgolf_state_t));
       state->hole = 1;
       state->course = 0;
       state->playing = holes[state->course] + 1;
       for (int i = 0; i < courses; i++) best[i] = 99;
       state->mode = dg_setting;
    }
}

void discgolf_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    watch_clear_colon();
    discgolf_state_t *state = (discgolf_state_t *)context;

    /* If we were playing, go to current hole */
    if (state->playing <= holes[0]) {
        state->hole = state->playing;
    }
    /* Set LAP if round finished */
    if (count_played(state) == holes[state->course] ) {
        watch_set_indicator(WATCH_INDICATOR_LAP);
    }
    movement_request_tick_frequency(4);
}

bool discgolf_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    
    discgolf_state_t *state = (discgolf_state_t *)context;

    switch (event.event_type) {
        case EVENT_TIMEOUT:
            /* Snap to first screen if we're not playing*/
            if ( count_played(state) == holes[state->course] || state->mode == dg_setting) {
                movement_move_to_face(0);
            }
            /* Cancel scoring if timed out */
            if (state->mode == dg_scoring) {
                state->scores[state->hole] = 0;
                state->mode = dg_idle;
            }
            break;
        /* Advance if not scoring */
        case EVENT_MODE_BUTTON_UP:
            if ( state->mode != dg_scoring ) {
				movement_move_to_next_face();
            }
            break;
        /* Go to default face if not scoring */
        case EVENT_MODE_LONG_PRESS:
            if ( state->mode != dg_scoring ) {
                movement_move_to_face(0);
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            switch ( state->mode ) {
                case dg_idle:
                    /* Check if selected hole is the first one */
                    if ( score_sum(state) == 0 ) {
                        state->playing = state->hole;
                    }
                    /* Enter scoring mode */
                    state->mode = dg_scoring;
                    break;
                case dg_scoring:
                    /* Set the LAP indicator if all scores are entered */
                    if (count_played(state) == holes[state->course] ) {
                        watch_set_indicator(WATCH_INDICATOR_LAP);
                    }
                    /* Advance to next hole if not editing previously set score */
                    if ( state->hole == state->playing ) {
                        if (state->hole < holes[state->course]) state->hole++;
                        else state->hole = 1;
                        if (state->playing < holes[state->course]) state->playing++;
                        else state->playing = 1;
                    }
                    /* Return to idle */
                    state->mode = dg_idle;
                    break;
                case dg_setting:
                    /* Return to idle */
                    state->playing = holes[state->course] + 1;
                    state->mode = dg_idle;
                    break;
            }
            beep(settings);
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (state->mode) {
                /* Setting, loop through courses */
                case dg_setting:
                    state->course = (state->course + 1) % courses;
                    break;
                /* Scoring, increment score for current hole */
                case dg_scoring:
                    state->scores[state->hole - 1] = (state->scores[state->hole - 1] + 1) % 16;   // Loop around at 15
                    break;
                /* Idle, loop through holes */
                case dg_idle:
                    if (state->hole < holes[state->course]) {
                        state->hole++;
                    } else { state->hole = 1; }
                    break;
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            /* Enter setting mode, reset state */
            if ( state->mode == dg_idle ) {
                state->mode = dg_setting;
                store_best(state);
                reset(state);
                beep(settings);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            /* Snap back to currently playing hole if we've established one*/
            if ( (state->mode == dg_idle) && (state->hole != state->playing) && (state->playing <= holes[state->course]) ) {
                state->hole = state->playing;
                beep(settings);
            }
            break;
        default:
            break;
    }

    char buf[21];
    char prefix;
    int8_t diff;

    switch (state->mode) {
        /* Setting mode, display course label and high score */
        case dg_setting:
            if ( best[state->course] < 0 ) { 
                prefix = '-';
            } else { prefix = ' '; }
            sprintf(buf, "%c%c   %c%2d  ", labels[state->course][0], labels[state->course][1], prefix, abs(best[state->course]));
            break;
        /* Idle, show relative or input score */
        case dg_idle:
            if (state->hole == state->playing) {
                diff = calculate_score(state);
                if ( diff < 0 ) {
                    prefix = '-';
                } else { prefix = ' '; }
                sprintf(buf, "%c%c%2d %c%2d  ", labels[state->course][0], labels[state->course][1], state->hole, prefix, abs(diff));
            } else {
                sprintf(buf, "%c%c%2d  %2d  ", labels[state->course][0], labels[state->course][1], state->hole, state->scores[state->hole - 1]);
            }
            break;
        /* Scoring, show set score */
        case dg_scoring:
            sprintf(buf, "%c%c%2d  %2d  ", labels[state->course][0], labels[state->course][1], state->hole, state->scores[state->hole - 1]);
            break;
    }

    /* Blink during scoring */
    if (event.subsecond % 2 && state->mode == dg_scoring) {
        buf[6] = buf[7] = ' ';
    }

    /* Draw screen */
    watch_display_string(buf, 0);

    return true;
}

void discgolf_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_clear_indicator(WATCH_INDICATOR_LAP);
}
