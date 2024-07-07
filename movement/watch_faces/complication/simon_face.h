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
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SIMON_FACE_H_
#define SIMON_FACE_H_

#include "movement.h"

/*
 * simon_face
 * -----------
 * The classic electronic game, Simon, reduced to be played on a Sensor-Watch
 *
 * How to play:
 *
 * When first arriving at the face, it will show your best score.
 *
 * Press the light button to start the game.
 *
 * A sequence will be played, starting with length 1. The sequence can be
 * made up of tones corresponding to any of the three buttons.
 *
 * light button: "LI" will display at the top of the screen, the LED will be yellow, and a high D will play
 * mode button: "DE" will display at the left of the screen, the LED will be red, and a high E will play
 * alarm button: "AL" will display on the right of the screen, the LED will be green, and a high C will play
 *
 * Once the sequence has finished, press the same buttons to recreate the sequence.
 *
 * If correct, the sequence will get one tone longer and play again. See how long of a sequence you can get.
 *
 * If you recreate the sequence incorrectly, a low note will play with "OH NOOOOO" displayed and the game is over.
 * Press light to play again.
 *
 * Once playing, long press the mode button when it is your turn to exit the game early.
 */

#define MAX_SEQUENCE 99

typedef enum SimonNote {
    SIMON_LED_NOTE = 1,
    SIMON_MODE_NOTE,
    SIMON_ALARM_NOTE,
    SIMON_WRONG_NOTE
} SimonNote;

typedef enum SimonPlayingState {
    SIMON_NOT_PLAYING = 0,
    SIMON_TEACHING,
    SIMON_LISTENING_BACK,
    SIMON_READY_FOR_NEXT_NOTE
} SimonPlayingState;

typedef enum SimonMode {
    SIMON_MODE_NORMAL = 0,  // 5 Second timeout if nothing is input
    SIMON_MODE_EASY,  // There is no timeout in this mode
    SIMON_MODE_HARD,  // The speed of the teaching is doubled and th etimeout is halved
    SIMON_MODE_TOTAL
} SimonMode;

typedef struct {
    uint8_t best_score;
    SimonNote sequence[MAX_SEQUENCE];
    uint8_t sequence_length;
    uint8_t teaching_index;
    uint8_t listen_index;
    bool soundOff;
    bool lightOff;
    uint8_t mode:6;
    SimonPlayingState playing_state;
} simon_state_t;

void simon_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void simon_face_activate(movement_settings_t *settings, void *context);
bool simon_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void simon_face_resign(movement_settings_t *settings, void *context);

#define simon_face                                                             \
    ((const watch_face_t){                                                       \
     simon_face_setup,                                                        \
     simon_face_activate,                                                     \
     simon_face_loop,                                                         \
     simon_face_resign,                                                       \
     NULL,                                                                    \
     })

#define TIMER_MAX 5
#define SIMON_FACE_FREQUENCY 8
#define DELAY_FOR_TONE_MS 300

#endif // SIMON_FACE_H_
