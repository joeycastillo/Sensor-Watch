/*
 * MIT License
 *
 * Copyright (c) 2023 Chris Ellis
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

// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include "higher_lower_game_face.h"
#include "watch_private_display.h"

#define TITLE_TEXT "Hi-Lo"
#define GAME_BOARD_SIZE 6
#define MAX_BOARDS 40
#define GUESSES_PER_SCREEN 5
#define WIN_SCORE (MAX_BOARDS * GUESSES_PER_SCREEN)
#define STATUS_DISPLAY_START 0
#define BOARD_SCORE_DISPLAY_START 2
#define BOARD_DISPLAY_START 4
#define BOARD_DISPLAY_END 9
#define MIN_CARD_VALUE 2
#define MAX_CARD_VALUE 14
#define CARD_RANK_COUNT (MAX_CARD_VALUE - MIN_CARD_VALUE + 1)
#define CARD_SUIT_COUNT 4
#define DECK_SIZE (CARD_SUIT_COUNT * CARD_RANK_COUNT)
#define FLIP_BOARD_DIRECTION false

typedef struct card_t {
    uint8_t value;
    bool revealed;
} card_t;

typedef enum {
    A, B, C, D, E, F, G
} segment_t;

typedef enum {
    HL_GUESS_EQUAL,
    HL_GUESS_HIGHER,
    HL_GUESS_LOWER
} guess_t;

typedef enum {
    HL_GS_TITLE_SCREEN,
    HL_GS_GUESSING,
    HL_GS_WIN,
    HL_GS_LOSE,
    HL_GS_SHOW_SCORE,
} game_state_t;

static game_state_t game_state = HL_GS_TITLE_SCREEN;
static card_t game_board[GAME_BOARD_SIZE] = {0};
static uint8_t guess_position = 0;
static uint8_t score = 0;
static uint8_t completed_board_count = 0;
static uint8_t deck[DECK_SIZE] = {0};
static uint8_t current_card = 0;

static uint8_t generate_random_number(uint8_t num_values) {
    // Emulator: use rand. Hardware: use arc4random.
#if __EMSCRIPTEN__
    return rand() % num_values;
#else
    return arc4random_uniform(num_values);
#endif
}

static void stack_deck(void) {
    for (size_t i = 0; i < CARD_RANK_COUNT; i++) {
        for (size_t j = 0; j < CARD_SUIT_COUNT; j++)
            deck[(i * CARD_SUIT_COUNT) + j] = MIN_CARD_VALUE + i;
    }
}

static void shuffle_deck(void) {
    // Randomize shuffle with Fisher Yates
    size_t i;
    size_t j;
    uint8_t tmp;

    for (i = DECK_SIZE - 1; i > 0; i--) {
        j = generate_random_number(0xFF) % (i + 1);
        tmp = deck[j];
        deck[j] = deck[i];
        deck[i] = tmp;
    }
}

static void reset_deck(void) {
    current_card = 0;
    stack_deck();
    shuffle_deck();
}

static uint8_t get_next_card(void) {
    if (current_card >= DECK_SIZE)
        reset_deck();
    return deck[current_card++];
}

static void reset_board(bool first_round) {
    // First card is random on the first board, and carried over from the last position on subsequent boards
    const uint8_t first_card_value = first_round
                                     ? get_next_card()
                                     : game_board[GAME_BOARD_SIZE - 1].value;

    game_board[0].value = first_card_value;
    game_board[0].revealed = true; // Always reveal first card

    // Fill remainder of board
    for (size_t i = 1; i < GAME_BOARD_SIZE; ++i) {
        game_board[i] = (card_t) {
                .value = get_next_card(),
                .revealed = false
        };
    }
}

static void init_game(void) {
    watch_clear_display();
    watch_display_string(TITLE_TEXT, BOARD_DISPLAY_START);
    watch_display_string("GA", STATUS_DISPLAY_START);
    reset_deck();
    reset_board(true);
    score = 0;
    completed_board_count = 0;
    guess_position = 1;
}

static void set_segment_at_position(segment_t segment, uint8_t position) {
    const uint64_t position_segment_data = (Segment_Map[position] >> (8 * (uint8_t) segment)) & 0xFF;
    const uint8_t com_pin = position_segment_data >> 6;
    const uint8_t seg = position_segment_data & 0x3F;
    watch_set_pixel(com_pin, seg);
}

static void render_board_position(size_t board_position) {
    const size_t display_position = FLIP_BOARD_DIRECTION
                                    ? BOARD_DISPLAY_START + board_position
                                    : BOARD_DISPLAY_END - board_position;
    const bool revealed = game_board[board_position].revealed;

    //// Current position indicator spot
    //if (board_position == guess_position) {
    //    watch_display_character('-', display_position);
    //    return;
    //}

    if (!revealed) {
        // Higher or lower indicator (currently just an empty space)
        watch_display_character(' ', display_position);
        //set_segment_at_position(F, display_position);
        return;
    }

    const uint8_t value = game_board[board_position].value;
    switch (value) {
        case 14: // A (≡)
            watch_display_character(' ', display_position);
            set_segment_at_position(A, display_position);
            set_segment_at_position(D, display_position);
            set_segment_at_position(G, display_position);
            break;
        case 13: // K (=)
            watch_display_character(' ', display_position);
            set_segment_at_position(A, display_position);
            set_segment_at_position(D, display_position);
            break;
        case 12: // Q (-)
            watch_display_character('-', display_position);
            break;
        default: {
            const char display_char = (value - MIN_CARD_VALUE) + '0';
            watch_display_character(display_char, display_position);
        }
    }
}

static void render_board(void) {
    for (size_t i = 0; i < GAME_BOARD_SIZE; ++i) {
        render_board_position(i);
    }
}

static void render_board_count(void) {
    // Render completed boards (screens)
    char buf[3] = {0};
    snprintf(buf, sizeof(buf), "%2hhu", completed_board_count);
    watch_display_string(buf, BOARD_SCORE_DISPLAY_START);
}

static void render_final_score(void) {
    watch_display_string("SC", STATUS_DISPLAY_START);
    char buf[7] = {0};
    const uint8_t complete_boards = score / GUESSES_PER_SCREEN;
    snprintf(buf, sizeof(buf), "%2hu %03hu", complete_boards, score);
    watch_set_colon();
    watch_display_string(buf, BOARD_DISPLAY_START);
}

static guess_t get_answer(void) {
    if (guess_position < 1 || guess_position > GAME_BOARD_SIZE)
        return HL_GUESS_EQUAL; // Maybe add an error state, shouldn't ever hit this.

    game_board[guess_position].revealed = true;
    const uint8_t previous_value = game_board[guess_position - 1].value;
    const uint8_t current_value = game_board[guess_position].value;

    if (current_value > previous_value)
        return HL_GUESS_HIGHER;
    else if (current_value < previous_value)
        return HL_GUESS_LOWER;
    else
        return HL_GUESS_EQUAL;
}

static void do_game_loop(guess_t user_guess) {
    switch (game_state) {
        case HL_GS_TITLE_SCREEN:
            init_game();
            render_board();
            render_board_count();
            game_state = HL_GS_GUESSING;
            break;
        case HL_GS_GUESSING: {
            const guess_t answer = get_answer();

            // Render answer indicator
            switch (answer) {
                case HL_GUESS_EQUAL:
                    watch_display_string("==", STATUS_DISPLAY_START);
                    break;
                case HL_GUESS_HIGHER:
                    watch_display_string("HI", STATUS_DISPLAY_START);
                    break;
                case HL_GUESS_LOWER:
                    watch_display_string("LO", STATUS_DISPLAY_START);
                    break;
            }

            // Scoring
            if (answer == user_guess) {
                score++;
            } else if (answer == HL_GUESS_EQUAL) {
                // No score for two consecutive identical cards
            } else {
                // Incorrect guess, game over
                watch_display_string("GO", STATUS_DISPLAY_START);
                game_board[guess_position].revealed = true;
                render_board_position(guess_position);
                game_state = HL_GS_LOSE;
                return;
            }

            if (score >= WIN_SCORE) {
                // Win, perhaps some kind of animation sequence?
                watch_display_string("WI", STATUS_DISPLAY_START);
                watch_display_string("  ", BOARD_SCORE_DISPLAY_START);
                watch_display_string("------", BOARD_DISPLAY_START);
                game_state = HL_GS_WIN;
                return;
            }

            // Next guess position
            const bool final_board_guess = guess_position == GAME_BOARD_SIZE - 1;
            if (final_board_guess) {
                // Seed new board
                completed_board_count++;
                render_board_count();
                guess_position = 1;
                reset_board(false);
                render_board();
            } else {
                guess_position++;
                render_board_position(guess_position - 1);
                render_board_position(guess_position);
            }
            break;
        }
        case HL_GS_WIN:
        case HL_GS_LOSE:
            // Show score screen on button press from either state
            watch_clear_display();
            render_final_score();
            game_state = HL_GS_SHOW_SCORE;
            break;
        case HL_GS_SHOW_SCORE:
            watch_clear_display();
            watch_display_string(TITLE_TEXT, BOARD_DISPLAY_START);
            watch_display_string("GA", STATUS_DISPLAY_START);
            game_state = HL_GS_TITLE_SCREEN;
            break;
        default:
            watch_display_string("ERROR", BOARD_DISPLAY_START);
            break;
    }
}

static void light_button_handler(void) {
    do_game_loop(HL_GUESS_HIGHER);
}

static void alarm_button_handler(void) {
    do_game_loop(HL_GUESS_LOWER);
}

void higher_lower_game_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(higher_lower_game_face_state_t));
        memset(*context_ptr, 0, sizeof(higher_lower_game_face_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
        memset(game_board, 0, sizeof(game_board));
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void higher_lower_game_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    higher_lower_game_face_state_t *state = (higher_lower_game_face_state_t *) context;
    (void) state;
    // Handle any tasks related to your watch face coming on screen.
    game_state = HL_GS_TITLE_SCREEN;
}

bool higher_lower_game_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    higher_lower_game_face_state_t *state = (higher_lower_game_face_state_t *) context;
    (void) state;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            watch_display_string(TITLE_TEXT, BOARD_DISPLAY_START);
            watch_display_string("GA", STATUS_DISPLAY_START);
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            break;
        case EVENT_LIGHT_BUTTON_UP:
            light_button_handler();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // Don't trigger light
            break;
        case EVENT_ALARM_BUTTON_UP:
            alarm_button_handler();
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void higher_lower_game_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}
