/*
 * MIT License
 *
 * Copyright (c) 2026 Stebbs
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

#include "melody_library.h"

// --- Melody 1: "The Gambler" by fun. - opening piano riff ---
static const int8_t _gambler_sequence[] = {
    BUZZER_NOTE_A4SHARP_B4FLAT, 9,
    BUZZER_NOTE_D5, 9,
    BUZZER_NOTE_F5, 9,

    BUZZER_NOTE_A4, 9,
    BUZZER_NOTE_D5, 9,
    BUZZER_NOTE_F5, 9,

    BUZZER_NOTE_G4, 9,
    BUZZER_NOTE_A4SHARP_B4FLAT, 9,
    BUZZER_NOTE_D5, 9,

    BUZZER_NOTE_F4, 9,
    BUZZER_NOTE_A4, 9,
    BUZZER_NOTE_C5, 9,

    BUZZER_NOTE_D4SHARP_E4FLAT, 9,
    BUZZER_NOTE_G4, 9,
    BUZZER_NOTE_A4SHARP_B4FLAT, 9,

    BUZZER_NOTE_F4, 9,
    BUZZER_NOTE_A4, 9,
    BUZZER_NOTE_C5, 9,

    BUZZER_NOTE_A4SHARP_B4FLAT, 9,
    BUZZER_NOTE_D5, 9,
    BUZZER_NOTE_A4, 9,
    BUZZER_NOTE_A4SHARP_B4FLAT, 14,

    BUZZER_NOTE_REST, 16,

    0 // end
};

// --- Melody 2: "Who Wants to Be a Millionaire" - rising tension motif ---
static const int8_t _millionaire_sequence[] = {
    BUZZER_NOTE_F5, 22,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_G5, 22,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_G5SHARP_A5FLAT, 20,
    BUZZER_NOTE_REST, 4,

    BUZZER_NOTE_F5, 18,
    BUZZER_NOTE_REST, 3,
    BUZZER_NOTE_G5, 16,
    BUZZER_NOTE_REST, 3,
    BUZZER_NOTE_G5SHARP_A5FLAT, 8,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_A5SHARP_B5FLAT, 8,
    BUZZER_NOTE_REST, 2,

    BUZZER_NOTE_C6, 40,
    BUZZER_NOTE_REST, 6,

    BUZZER_NOTE_A5SHARP_B5FLAT, 6,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_G5SHARP_A5FLAT, 6,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_G5, 14,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F5, 22,

    BUZZER_NOTE_REST, 16,

    0 // end
};

// --- Melody 3: "Pokemon RBY Intro 2" - title screen melody ---
static const int8_t _pokemon_sequence[] = {
    BUZZER_NOTE_D4, 4,
    BUZZER_NOTE_F4SHARP_G4FLAT, 4,

    BUZZER_NOTE_G4, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_G4, 15,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_G4, 4,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_G4, 4,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_G4, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_G4, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_G4, 10,
    BUZZER_NOTE_REST, 2,

    BUZZER_NOTE_F4, 4,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F4, 4,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F4, 4,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F4, 4,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F4, 4,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_F4SHARP_G4FLAT, 4,
    BUZZER_NOTE_REST, 1,

    BUZZER_NOTE_G4, 15,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_B4, 6,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_D5, 18,
    BUZZER_NOTE_REST, 4,

    BUZZER_NOTE_C4, 14,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_F4, 6,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_F5, 14,
    BUZZER_NOTE_REST, 2,

    BUZZER_NOTE_E5, 4,
    BUZZER_NOTE_D5SHARP_E5FLAT, 4,
    BUZZER_NOTE_D5, 22,
    BUZZER_NOTE_REST, 4,

    BUZZER_NOTE_F4, 14,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_E4, 4,
    BUZZER_NOTE_D4SHARP_E4FLAT, 4,
    BUZZER_NOTE_D4, 22,

    BUZZER_NOTE_REST, 16,

    0 // end
};

// --- Melody 4: Tetris Theme (Korobeiniki) ---
static const int8_t _tetris_sequence[] = {
    BUZZER_NOTE_E5, 12,
    BUZZER_NOTE_B4, 6,
    BUZZER_NOTE_C5, 6,
    BUZZER_NOTE_D5, 12,
    BUZZER_NOTE_C5, 6,
    BUZZER_NOTE_B4, 6,

    BUZZER_NOTE_A4, 12,
    BUZZER_NOTE_A4, 6,
    BUZZER_NOTE_C5, 6,
    BUZZER_NOTE_E5, 12,
    BUZZER_NOTE_D5, 6,
    BUZZER_NOTE_C5, 6,

    BUZZER_NOTE_B4, 18,
    BUZZER_NOTE_C5, 6,
    BUZZER_NOTE_D5, 12,
    BUZZER_NOTE_E5, 12,

    BUZZER_NOTE_C5, 12,
    BUZZER_NOTE_A4, 12,
    BUZZER_NOTE_A4, 12,
    BUZZER_NOTE_REST, 12,

    BUZZER_NOTE_D5, 18,
    BUZZER_NOTE_F5, 6,
    BUZZER_NOTE_A5, 12,
    BUZZER_NOTE_G5, 6,
    BUZZER_NOTE_F5, 6,

    BUZZER_NOTE_E5, 18,
    BUZZER_NOTE_C5, 6,
    BUZZER_NOTE_E5, 12,
    BUZZER_NOTE_D5, 6,
    BUZZER_NOTE_C5, 6,

    BUZZER_NOTE_B4, 12,
    BUZZER_NOTE_B4, 6,
    BUZZER_NOTE_C5, 6,
    BUZZER_NOTE_D5, 12,
    BUZZER_NOTE_E5, 12,

    BUZZER_NOTE_C5, 12,
    BUZZER_NOTE_A4, 12,
    BUZZER_NOTE_A4, 12,

    BUZZER_NOTE_REST, 16,

    0 // end
};

// --- Melody 5: Jeopardy Think Music ---
static const int8_t _jeopardy_sequence[] = {
    BUZZER_NOTE_A3SHARP_B3FLAT, 12,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_D4SHARP_E4FLAT, 12,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_A3SHARP_B3FLAT, 12,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_D4SHARP_E4FLAT, 12,
    BUZZER_NOTE_REST, 2,

    BUZZER_NOTE_A3SHARP_B3FLAT, 12,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_F4, 12,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_D4, 26,
    BUZZER_NOTE_REST, 4,

    BUZZER_NOTE_A3SHARP_B3FLAT, 12,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_D4SHARP_E4FLAT, 12,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_A3SHARP_B3FLAT, 12,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_D4SHARP_E4FLAT, 12,
    BUZZER_NOTE_REST, 2,

    BUZZER_NOTE_F4, 14,
    BUZZER_NOTE_REST, 2,

    BUZZER_NOTE_D4SHARP_E4FLAT, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_D4, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_C4, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_A3SHARP_B3FLAT, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_A3, 28,

    BUZZER_NOTE_REST, 16,

    0 // end
};

// --- Melody 6: Nickelodeon Jingle ---
static const int8_t _nickelodeon_sequence[] = {
    BUZZER_NOTE_G4, 8,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_G4, 8,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_G4, 8,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_G4, 8,
    BUZZER_NOTE_REST, 6,

    BUZZER_NOTE_E4, 6,
    BUZZER_NOTE_REST, 1,
    BUZZER_NOTE_G4, 8,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_A4, 8,
    BUZZER_NOTE_REST, 4,
    BUZZER_NOTE_G4, 12,
    BUZZER_NOTE_REST, 10,

    BUZZER_NOTE_C5, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_C5, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_E5, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_E5, 10,
    BUZZER_NOTE_REST, 2,
    BUZZER_NOTE_F5, 26,

    BUZZER_NOTE_REST, 16,

    0 // end
};

// --- Tune table ---
const melody_tune_t melody_tunes[MELODY_NUM_TUNES] = {
    { "      GAMblr", 12, 'G', _gambler_sequence },
    { "      MIllNR", 12, 'M', _millionaire_sequence },
    { "      POkEMN", 12, 'P', _pokemon_sequence },
    { "      tEtrIS", 12, 'T', _tetris_sequence },
    { "      JPRDY ", 12, 'J', _jeopardy_sequence },
    { "      nICk  ", 12, 'N', _nickelodeon_sequence },
};
