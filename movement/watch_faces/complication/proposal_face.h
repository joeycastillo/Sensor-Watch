/*
 * MIT License
 *
 * Copyright (c) 2023 Hieu Nguyen / @cheehieu
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

#ifndef PROPOSAL_FACE_H_
#define PROPOSAL_FACE_H_

#include "movement.h"

/*
 * PROPOSAL FACE
 * =============
 * This complication is more of an easter egg and tongue-in-cheek way of 
 * proposing to someone. I used it on my gf in Sep 2023, and she said yes!
 *
 * The watch face simply cycles through a series of word array buffers such as 
 * the name of the person being proposed to, a "Will you marry me?" proposal 
 * with Yes/No response, and then a subsequent reaction sequence. This example 
 * is Mario-themed (https://youtu.be/imSefM4GPpE), but you can customize it to 
 * your liking.
 *
 * The architecture is a state machine with 4 states:
 * - NAME: "animation" of the name being proposed to
 * - PROPOSAL: the "Will you marry me?" proposal
 * - RESPONSE: Yes/No screen awaiting a user button press
 * - REACTION: reaction sequence to celebrate or commiserate
 *
 * ┌──────┐     ┌──────────┐     ┌──────────┐  light_btn   ┌────────────┐
 * │ NAME ├────►│ PROPOSAL ├────►│ RESPONSE ├─────────────►│ REACTION_Y │
 * └──────┘     └──────────┘     └─────┬────┘              └────────────┘
 *                                     │
 *                                     │       alarm_btn   ┌────────────┐
 *                                     └──────────────────►│ REACTION_N │
 *                                                         └────────────┘
 *
 * The state machine is managed synchronously in proposal_face_loop() on every
 * EVENT_TICK. This function determines the transitions between states and
 * handles displaying the correct word at the right time. The tick frequency is
 * defined by TICK_FREQ_<state> to allow for different animation speeds in each
 * state. For the NAME and PROPOSAL states, the watch face simply cycles through
 * the word array buffers then moves on to the next state. For the RESPONSE
 * state, the watch face awaits a button press from EVENT_LIGHT_BUTTON or
 * EVENT_ALARM_BUTTON to determine the response. For the REACTION state, the
 * watch face uses the LEDs and buzzer in a looped reaction sequence.
 *
 * A long press of EVENT_ALARM_BUTTON can be used at any time to reset back to
 * the NAME state. The default loop handler is still used, so presses of
 * EVENT_MODE_BUTTON will move to the next watch face or return to the first
 * watch face. An EVENT_TIMEOUT will also trigger a return to the first watch
 * face (the looped buzzer songs can get annoying after a while).
 *
 * NOTE: Button presses don't seem to register while the buzzer is playing.
 */

typedef enum States {
    STATE_NAME = 0,
    STATE_PROPOSAL,
    STATE_RESPONSE,
    STATE_REACTION,
} state_t;

typedef struct {
    state_t current_state; // Keeps track of the current state
    uint8_t word_index; // Keeps track of which word to display
    bool proposal_response; // Response to proposal; true if accepted, false if rejected
} proposal_state_t;

void proposal_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void proposal_face_activate(movement_settings_t *settings, void *context);
bool proposal_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void proposal_face_resign(movement_settings_t *settings, void *context);

#define proposal_face ((const watch_face_t){ \
    proposal_face_setup, \
    proposal_face_activate, \
    proposal_face_loop, \
    proposal_face_resign, \
    NULL, \
})

#endif // PROPOSAL_FACE_H_
