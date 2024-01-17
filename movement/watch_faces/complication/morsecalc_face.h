/*
 * MIT License
 *
 * Copyright (c) 2023 Christian Chapman
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

#ifndef MORSECALC_FACE_H_
#define MORSECALC_FACE_H_

/*
 * MORSECALC face
 * Morse-code-based RPN calculator
 *
 * The calculator is operated by first composing a **token** in Morse code,
 * then submitting it to the calculator. A token specifies either a calculator
 * operation or a float value.
 *
 * These two parts of the codebase are totally independent:
 *  1. The Morse-code reader (`mc.h`, `mc.c`)
 *  2. The RPN calculator (`calc.h`, `calc.c`, `calc_fn.h`, `calc_fn.c`, `small_strtod.c`)
 *
 * The user interface (`morsecalc_face.h`, `morsecalc_face.c`) lets you talk
 * to the RPN calculator through Morse code.
 *
 * ## Controls
 *  - `light` is dash
 *  - `alarm` is dot
 *  - `mode` is "finish character"
 *  - long-press `mode` or submit a blank token to switch faces
 *  - long-press `alarm` to show stack
 *  - long-press `light` to toggle the light
 *
 * ## Morse code token entry
 * As you enter `.`s and `-`s, the morse code char you've entered will
 * appear in the top center digit. At the top right is the # of morse code
 * `.`/`-` you've input so far. The character resets at the 6th `.`/`-`.
 *
 * Once you have the character you want to enter, push `mode` to enter it.
 *
 * The character will be appended to the current token, whose 6 trailing
 * chars are shown on the main display. Once you've typed in the token you
 * want, enter a blank Morse code character and then push `mode`.
 * This submits it to the calculator.
 *
 * Special characters:
 *  - Backspace is `(` (`-.--.`).
 *  - Clear token input without submitting to calculator is `Start
 *    transmission` (`-.-.-`).
 *
 * ## Writing commands
 * First the calculator will try to interpret the token as a command/stack operation.
 * Commands are defined in `calc_dict[]` in `movement/lib/morsecalc/calc_fns.h`.
 * If the command doesn't appear in the dictionary, the calculator tries to interpret the token as a number.
 *
 * ## Writing numbers
 * Numbers are written like floating point strings.
 * Entering a number pushes it to the top of the stack if there's room.
 * This can get long, so for convenience numerals can also be written in binary with .- = 01.
 *
 *     0   1    2    3    4    5    6    7    8    9
 *     .   -    -.   --   -..  -.-  --.  ---  -... -..-
 *     e   t    n    m    d    k    g    o    b    x
 *
 *  - Exponent signs must be entered as "p".
 *  - Decimal place "." can be entered as "h" (code ....)
 *  - Sign "-" can be entered as "Ch digraph" (code ----)
 *
 * For example: "4.2e-3" can be entered directly, or as "4h2pC3"
 *   similarly, "0.0042" can also be entered as "eheedn"
 * Once you submit a number to the watch face, it pushes it to the top of the stack if there's room.
 *
 * ## Number display
 * After a command runs, the top of the stack is displayed in this format:
 *
 *   - Main 4 digits = leading 4 digits
 *   - Last 2 digits = exponent
 *   - Top middle = [Stack location, Sign of number]
 *   - Top right = [Stack exponent, Sign of exponent]
 *
 * Blank sign digit means positive.
 * So for example, the watch face might look like this:
 *
 *     [   0 -5]
 *     [4200 03]
 *
 * ... representing `+4.200e-3` is in stack location 0 (the top) and it's one of five items in the stack.
 *
 * ## Looking at the stack
 * To show the top of the stack, push and hold `light`/`alarm` or submit a blank token by pushing `mode` a bunch of times.
 * To show the N-th stack item (0 through 9):
 *
 *  - Put in the Morse code for N without pushing the mode button.
 *  - Push and hold `alarm`.
 *
 * To show the memory register, use `m` instead of a number.
 *
 * To see all the calculator operations and their token aliases, see the `calc_dict[]` struct in `calc_fns.h`
 */

#define MORSECALC_TOKEN_LEN 32
#define MORSECODE_LEN 5

#include "movement.h"
#include "calc.h"

/*
 * MC International Morse Code binary tree
 * Levels of the tree are concatenated.
 * '.' = 0 and '-' = 1.
 *
 * Capitals denote special characters:
 * C = Ch digraph
 * V = VERIFY (ITU-R "UNDERSTOOD")
 * R = REPEAT
 * W = WAIT
 * S = START TRANSMISSION
 * E = END OF WORK
 */
static const char MORSECODE_TREE[] = " etianmsurwdkgohvf\0l\0pjbxcyzq\0C\x35\x34V\x33\0R\0\x32W\0+\0\0\0\0\x31\x36=/\0\0S(\0\x37\0\0\0\x38\0\x39\x30\0\0\0\0\0E\0\0\0\0\0\0?_\0\0\0\0\"\0\0.\0\0\0\0@\0\0\0'\0\0-\0\0\0\0\0\0\0\0;!\0)\0\0\0\0\0,\0\0\0\0:\0\0\0\0\0\0";

void morsecalc_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void morsecalc_face_activate(movement_settings_t *settings, void *context);
bool morsecalc_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void morsecalc_face_resign(movement_settings_t *settings, void *context);

typedef struct {
	calc_state_t *cs;
	unsigned int mc; // Morse code character
	char token[MORSECALC_TOKEN_LEN];
	uint8_t idxt;
	uint8_t led_is_on;
} morsecalc_state_t;

void morsecalc_reset_token(morsecalc_state_t *mcs);
void morsecalc_input(morsecalc_state_t *mcs);

#define morsecalc_face ((const watch_face_t){ \
    morsecalc_face_setup, \
    morsecalc_face_activate, \
    morsecalc_face_loop, \
    morsecalc_face_resign, \
    NULL, \
})

#endif // MORSECALC_FACE_H_
