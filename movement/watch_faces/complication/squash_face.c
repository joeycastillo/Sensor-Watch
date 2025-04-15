/*
 * MIT License
 *
 * Copyright (c) 2025 Johan Oskarsson
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
#include <stdio.h>
#include "squash_face.h"

// https://en.wikipedia.org/wiki/Squash_(sport)#Scoring_system
// Using "point-a-rally scoring (PARS)" to 11 below.
#define POINTS_TO_WIN_GAME 11
// For example if both players have 10 points one of them has to get to 12, not 11, to win.
#define MIN_POINT_DIFFERENCE 2
// First to 3 games won (max 5 games played)
#define GAMES_TO_WIN_MATCH 3

static void update_display(squash_state_t *state) {
    char buf[16];
    
    watch_clear_display();
    
    // The colon makes it easier to distinguis each players score
    watch_set_colon();
    
    // Show games won in small digits
    sprintf(buf, "%d  %d", state->player1_games, state->player2_games);
    watch_display_string(buf, 0);

    // Show current score: P1-P2
    sprintf(buf, "%02d%02d", state->player1_score, state->player2_score);
    watch_display_string(buf, 4);

    // If game over, show indicator
    if (state->is_game_over) {
        watch_set_indicator(WATCH_INDICATOR_LAP);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_LAP);
    }
}

static void check_game_status(squash_state_t *state) {
    // Check if a player has won the current game
    if ((state->player1_score >= POINTS_TO_WIN_GAME || state->player2_score >= POINTS_TO_WIN_GAME) && 
        abs(state->player1_score - state->player2_score) >= MIN_POINT_DIFFERENCE) {
        
        // Award a game to the winner
        if (state->player1_score > state->player2_score) {
            state->player1_games++;
            movement_play_signal();
        } else {
            state->player2_games++;
            movement_play_signal();
        }
        
        // Check if the match is over
        if (state->player1_games >= GAMES_TO_WIN_MATCH || state->player2_games >= GAMES_TO_WIN_MATCH) {
            state->is_game_over = true;
            movement_play_signal();
        } else {
            // Reset for next game
            state->player1_score = 0;
            state->player2_score = 0;
        }
    }
}

static void reset_match(squash_state_t *state) {
    state->player1_score = 0;
    state->player2_score = 0;
    state->player1_games = 0;
    state->player2_games = 0;
    state->is_game_over = false;
    
    movement_play_signal();
}

void squash_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(squash_state_t));
        memset(*context_ptr, 0, sizeof(squash_state_t));
    }
}

void squash_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    squash_state_t *state = (squash_state_t *)context;
    
    update_display(state);
}

bool squash_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    squash_state_t *state = (squash_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            update_display(state);
            break;
            
        case EVENT_LIGHT_BUTTON_DOWN:
            // Suppress default LED behavior
            break;
            
        case EVENT_LIGHT_BUTTON_UP:
            if (!state->is_game_over) {
                // Increment player 1's score
                state->player1_score++;
                check_game_status(state);
                update_display(state);
            }
            break;
            
        case EVENT_ALARM_BUTTON_UP:
            if (!state->is_game_over) {
                // Increment player 2's score
                state->player2_score++;
                check_game_status(state);
                update_display(state);
            }
            break;
            
        case EVENT_MODE_LONG_PRESS:
            // Reset the match
            reset_match(state);
            update_display(state);
            return true;
            
        case EVENT_ALARM_LONG_PRESS:
            update_display(state);
            break;
            
        case EVENT_TIMEOUT:
            break;
            
        case EVENT_LOW_ENERGY_UPDATE:
            update_display(state);
            watch_start_tick_animation(500);
            break;
            
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void squash_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

