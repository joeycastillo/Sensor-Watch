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
#include "endless_runner_face.h"

typedef enum {
    JUMPING_FINAL_FRAME = 0,
    NOT_JUMPING,
    JUMPING_START,
} RunnerJumpState;

typedef enum {
    SCREEN_TITLE = 0,
    SCREEN_PLAYING,
    SCREEN_LOSE,
    SCREEN_COUNT
} RunnerCurrScreen;

typedef enum {
    DIFF_BABY = 0,  // 0.5x speed; 4 0's min; jump is 3 frames
    DIFF_EASY,      //   1x speed; 4 0's min; jump is 3 frames
    DIFF_NORM,      //   1x speed; 4 0's min; jump is 2 frames
    DIFF_HARD,      //   1x speed; 3 0's min; jump is 2 frames
    DIFF_COUNT
} RunnerDifficulty;

#define NUM_GRID 12
#define FREQ 8
#define FREQ_SLOW 4
#define JUMP_FRAMES 2
#define JUMP_FRAMES_EASY 20
#define MIN_ZEROES 4
#define MIN_ZEROES_HARD 3
#define MAX_DISP_SCORE 39  // The top-right digits can't properly display above 39

typedef struct {
    uint32_t obst_pattern;
    uint16_t obst_indx : 8;
    uint16_t jump_state : 5;
    uint16_t sec_before_moves : 3;
    bool loc_2_on;
    bool loc_3_on;
} game_state_t;

static game_state_t game_state;
static const uint8_t _num_bits_obst_pattern = sizeof(game_state.obst_pattern) * 8;

static uint32_t get_random(uint32_t max) {
    #if __EMSCRIPTEN__
    return rand() % max;
    #else
    return arc4random_uniform(max);
    #endif
}

static uint32_t get_random_legal(uint32_t prev_val, uint16_t difficulty) {
/** @brief A legal random number starts with the previous number (which should be the 12 bits on the screen).
  * @param prev_val The previous value to tack onto. The return will have its first NUM_GRID MSBs be the same as prev_val, and the rest be new
  * @param difficulty To dictate how spread apart the obsticles must be
  * @return the new random value, where it's first NUM_GRID MSBs are the same as prev_val
  */
    uint8_t min_zeros = (difficulty == DIFF_HARD) ? MIN_ZEROES_HARD : MIN_ZEROES;
    uint32_t max = (1 << (_num_bits_obst_pattern - NUM_GRID)) - 1;
    uint32_t rand = get_random(max);
    uint32_t rand_legal = 0;
    prev_val = prev_val & ~max;

    for (int i = (NUM_GRID + 1); i <= _num_bits_obst_pattern; i++) {
        uint32_t mask = 1 << (_num_bits_obst_pattern - i);
        bool msb = (rand & mask) >> (_num_bits_obst_pattern - i);
        if (msb) {
            rand_legal = rand_legal << min_zeros;
            i+=min_zeros;
        }
        rand_legal |= msb;
        rand_legal = rand_legal << 1;
    }

    rand_legal = rand_legal & max;
    for (int i = 0; i <= min_zeros; i++) {
        if (prev_val & (1 << (i + _num_bits_obst_pattern - NUM_GRID))){
            rand_legal = rand_legal >> (min_zeros - i);
            break;
        }
    }
    rand_legal = prev_val | rand_legal;
    return rand_legal;
}

static void display_ball(bool jumping) {
    if (!jumping) {
        watch_set_pixel(0, 21);
        watch_set_pixel(1, 21);
        watch_set_pixel(0, 20);
        watch_set_pixel(1, 20);
        watch_clear_pixel(1, 17);
        watch_clear_pixel(2, 20);
        watch_clear_pixel(2, 21);     
    }
    else {
        watch_clear_pixel(0, 21);
        watch_clear_pixel(1, 21);
        watch_clear_pixel(0, 20);
        watch_set_pixel(1, 20);
        watch_set_pixel(1, 17);
        watch_set_pixel(2, 20);
        watch_set_pixel(2, 21);
    }
}

static void display_score(uint8_t score) {
    char buf[3];
    if (score > MAX_DISP_SCORE) watch_display_string(" -", 2);
    else{
        sprintf(buf, "%2d", score);
        watch_display_string(buf, 2);
    }
}

static void display_difficulty(uint16_t difficulty) {
    switch (difficulty)
    {
    case DIFF_BABY:
        watch_display_string("b", 9);
        break;
    case DIFF_EASY:
        watch_display_string("E", 9);
        break;
    case DIFF_HARD:
        watch_display_string("H", 9);
        break;
    case DIFF_NORM:
    default:
        watch_display_string("n", 9);
        break;
    }
}

static void display_title(endless_runner_state_t *state) {
    state -> curr_screen = SCREEN_TITLE;
    memset(&game_state, 0, sizeof(game_state));
    game_state.sec_before_moves = 1; // The first obstacles will all be 0s, which is about an extra second of delay.
    if (state -> soundOn) game_state.sec_before_moves--; // Start chime is about 1 second
    watch_display_string("ER   SEL  ", 0);
    display_score(state -> hi_score);
    display_difficulty(state -> difficulty);
}

static void begin_playing(endless_runner_state_t *state) {
    state -> curr_screen = SCREEN_PLAYING;
    movement_request_tick_frequency((state -> difficulty == DIFF_BABY) ? FREQ_SLOW : FREQ);
    watch_display_string("ER         ", 0);
    game_state.jump_state = NOT_JUMPING;
    display_ball(game_state.jump_state != NOT_JUMPING);
    do  // Avoid the first array of obstacles being a boring line of 0s 
    {
        game_state.obst_pattern = get_random_legal(0, state -> difficulty);
    } while (game_state.obst_pattern == 0);
    display_score(state -> curr_score);
    if (state -> soundOn){
        watch_buzzer_play_note(BUZZER_NOTE_C5, 200);
        watch_buzzer_play_note(BUZZER_NOTE_E5, 200);
        watch_buzzer_play_note(BUZZER_NOTE_G5, 200);
    }
}

static void display_lose_screen(endless_runner_state_t *state) {
    movement_request_tick_frequency(1);
    state -> curr_screen = SCREEN_LOSE;
    state -> curr_score = 0;
    watch_display_string(" U   LOSE ", 0);
    if (state -> soundOn)
        watch_buzzer_play_note(BUZZER_NOTE_A1, 600);
    else
        delay_ms(600);
}

static bool display_obstacle(bool obstacle, int grid_loc, endless_runner_state_t *state) {
    bool success_jump = false;
    switch (grid_loc)
    {
    case 2:
        game_state.loc_2_on = obstacle;
        if (obstacle)
            watch_set_pixel(0, 20);
        else if (game_state.jump_state != NOT_JUMPING)
            watch_clear_pixel(0, 20);
        break;
    case 3:
        game_state.loc_3_on = obstacle;
        if (obstacle)
            watch_set_pixel(1, 21);
        else if (game_state.jump_state != NOT_JUMPING)
            watch_clear_pixel(1, 21);
        break;
    
    case 1:
        if (obstacle) {  // If an obstacle is here, it means the ball cleared it
            // Counter will continuously roll over, but high score will max out on the first roll-over
            state -> curr_score = (state -> curr_score + 1) % (MAX_DISP_SCORE + 1);
            if (state -> curr_score == 0)  // This means the counter rolled over
                state -> hi_score = MAX_DISP_SCORE + 1;
            else if (state -> curr_score > state -> hi_score)
                state -> hi_score = state -> curr_score;
            display_score(state -> curr_score);
        }
        //fall through
    case 0:
        if (obstacle)  // If an obstacle is here, it means the ball cleared it
            success_jump = true;
        //fall through
    case 5:
        if (obstacle)
            watch_set_pixel(0, 18 + grid_loc);
        else
            watch_clear_pixel(0, 18 + grid_loc);
        break;
    case 4:
        if (obstacle)
            watch_set_pixel(1, 22);
        else
            watch_clear_pixel(1, 22);
        break;
    case 6:
        if (obstacle)
            watch_set_pixel(1, 0);
        else
            watch_clear_pixel(1, 0);
        break;
    case 7:
    case 8:
        if (obstacle)
            watch_set_pixel(0, grid_loc - 6);
        else
            watch_clear_pixel(0, grid_loc - 6);
        break;
    case 9:
    case 10:
        if (obstacle)
            watch_set_pixel(0, grid_loc - 5);
        else
            watch_clear_pixel(0, grid_loc - 5);
        break;
    case 11:
        if (obstacle)
            watch_set_pixel(1, 6);
        else
            watch_clear_pixel(1, 6);
        break;
    default:
        break;
    }
    return success_jump;
}

static bool display_obstacles(endless_runner_state_t *state) {
    bool success_jump = false;
    for (int i = 0; i < NUM_GRID; i++) {
        // Use a bitmask to isolate each bit and shift it to the least significant position
        uint32_t mask = 1 << ((_num_bits_obst_pattern - 1) - i);
        bool obstacle = (game_state.obst_pattern & mask) >> ((_num_bits_obst_pattern - 1) - i);
        if (display_obstacle(obstacle, i, state)) success_jump = true;

    }
    game_state.obst_pattern = game_state.obst_pattern << 1;
    game_state.obst_indx++;
    if (game_state.obst_indx >= _num_bits_obst_pattern - NUM_GRID) {
        game_state.obst_indx = 0;
        game_state.obst_pattern = get_random_legal(game_state.obst_pattern, state -> difficulty);
    }
    return success_jump;
}

void endless_runner_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(endless_runner_state_t));
        memset(*context_ptr, 0, sizeof(endless_runner_state_t));
        endless_runner_state_t *state = (endless_runner_state_t *)*context_ptr;
        state->difficulty = DIFF_NORM;
    }
}

void endless_runner_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool endless_runner_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    endless_runner_state_t *state = (endless_runner_state_t *)context;
    bool success_jump = false;
    uint8_t curr_jump_frame = 0;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            if (state -> soundOn) watch_set_indicator(WATCH_INDICATOR_BELL);
            display_title(state);
            break;
        case EVENT_TICK:
            switch (state -> curr_screen)
            {
            case SCREEN_TITLE:
            case SCREEN_LOSE:
                break;
            default:
                if (game_state.sec_before_moves != 0) {
                    if (event.subsecond == 0) --game_state.sec_before_moves;
                    break;
                }
                success_jump = display_obstacles(state);
                switch (game_state.jump_state)
                {
                case NOT_JUMPING:
                    break;
                case JUMPING_FINAL_FRAME:
                    game_state.jump_state = NOT_JUMPING;
                    display_ball(game_state.jump_state != NOT_JUMPING);
                    if (state -> soundOn){
                        if (success_jump)
                            watch_buzzer_play_note(BUZZER_NOTE_C5, 60);
                        else
                            watch_buzzer_play_note(BUZZER_NOTE_C3, 60);
                    }
                    break;
                default:
                    curr_jump_frame = game_state.jump_state - NOT_JUMPING;
                    if (curr_jump_frame >= JUMP_FRAMES_EASY || (state -> difficulty >= DIFF_NORM && curr_jump_frame >= JUMP_FRAMES))
                        game_state.jump_state = JUMPING_FINAL_FRAME;
                    else
                        game_state.jump_state++;
                    //if (!watch_get_pin_level(BTN_ALARM) && !watch_get_pin_level(BTN_LIGHT)) game_state.jump_state = JUMPING_FINAL_FRAME;  // Uncomment to have depressing the buttons cause the ball to drop regardless of its current frame.
                    break;
                }
                if (game_state.jump_state == NOT_JUMPING && (game_state.loc_2_on || game_state.loc_3_on)) {
                    delay_ms(200);  // To show the player jumping onto the obstacle before displaying the lose screen.
                    display_lose_screen(state);
                }
                break;
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
        case EVENT_ALARM_BUTTON_UP:
            if (state -> curr_screen == SCREEN_TITLE)
                begin_playing(state);
            else if (state -> curr_screen == SCREEN_LOSE)
                display_title(state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state -> curr_screen == SCREEN_TITLE) {
                state -> difficulty = (state -> difficulty + 1) % DIFF_COUNT;
                display_difficulty(state -> difficulty);
                if (state -> soundOn) {
                    if (state -> difficulty == 0) watch_buzzer_play_note(BUZZER_NOTE_B4, 30);
                    else  watch_buzzer_play_note(BUZZER_NOTE_C5, 30);
                }
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
        case EVENT_ALARM_BUTTON_DOWN:
            if (state -> curr_screen == SCREEN_PLAYING && game_state.jump_state == NOT_JUMPING){
                game_state.jump_state = JUMPING_START;
                display_ball(game_state.jump_state != NOT_JUMPING);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state -> curr_screen != SCREEN_PLAYING)
            {
                state -> soundOn = !state -> soundOn;
                if (state -> soundOn){
                    watch_buzzer_play_note(BUZZER_NOTE_C5, 30);
                    watch_set_indicator(WATCH_INDICATOR_BELL);
                }
                else {
                    watch_clear_indicator(WATCH_INDICATOR_BELL);
                }
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void endless_runner_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

