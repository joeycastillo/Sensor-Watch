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

/*
## Morse-code-based RPN calculator 

The calculator is operated by first composing a **token** in Morse code, then submitting it to the calculator. A token specifies either a calculator operation or a float value.

These two parts of the codebase are totally independent:

 1. The Morse-code reader (`mc.h`, `mc.c`) 
 2. The RPN calculator (`calc.h`, `calc.c`, `calc_fn.h`, `calc_fn.c`, `small_strtod.c`)

The user interface (`morsecalc_face.h`, `morsecalc_face.c`) lets you talk to the RPN calculator through Morse code.

## Controls

 - `light` is dash
 - `alarm` is dot
 - `mode` is "finish character"
 - long-press `mode` to quit
 - long-press `alarm` to show stack
 - long-press `light` to toggle the light
   
## Morse code token entry
As you enter `.`s and `-`s, the morse code char you've entered will appear in the top center digit.
At the top right is the # of morse code `.`/`-` you've input so far. The character resets at the 6th `.`/`-`.
Once you have the character you want to enter, push `mode` to enter it. 
The character will be appended to the current token, whose 6 trailing chars are shown on the main display.

Once you've typed in the token you want, enter a blank Morse code character and then push `mode`.
This submits it to the calculator.
   
Special characters:

 - Backspace is `(` (`-.--.`). 
 - Clear token input without submitting to calculator is `Start transmission` (`-.-.-`).
    
## Writing commands
First the calculator will try to interpret the token as a command/stack operation. 
Commands are defined in `calc_dict[]` in `movement/lib/morsecalc/calc_fns.h`.
If the command doesn't appear in the dictionary, the calculator tries to interpret the token as a number.
 
## Writing numbers
Numbers are written like floating point strings. 
Entering a number pushes it to the top of the stack if there's room.
This can get long, so for convenience numerals can also be written in binary with .- = 01.

    0   1    2    3    4    5    6    7    8    9
    .   -    -.   --   -..  -.-  --.  ---  -... -..-
    e   t    n    m    d    k    g    o    b    x

 - Exponent signs must be entered as "p".
 - Decimal place "." can be entered as "h" (code ....)
 - Sign "-" can be entered as "Ch digraph" (code ----)
 
For example: "4.2e-3" can be entered directly, or as "4h2pC3"
  similarly, "0.0042" can also be entered as "eheedn"

Once you submit a number to the watch face, it pushes it to the top of the stack if there's room.
        
## Number display
After a command runs, the top of the stack is displayed in this format:
   
  - Main 4 digits = leading 4 digits
  - Last 2 digits = exponent
  - Top middle = [Stack location, Sign of number]
  - Top right = [Stack exponent, Sign of exponent]
  
Blank sign digit means positive.
So for example, the watch face might look like this:

    [   0 -5]
    [4200 03]

... representing `+4.200e-3` is in stack location 0 (the top) and it's one of five items in the stack.

## Looking at the stack

To show the top of the stack, push and hold `light`/`alarm` or submit a blank token by pushing `mode` a bunch of times.
To show the N-th stack item (0 through 9):

 - Put in the Morse code for N without pushing the mode button.
 - Push and hold `alarm`.
    
To show the memory register, use `m` instead of a number. 
   
To see all the calculator operations and their token aliases, see the `calc_dict[]` struct in `calc_fns.h` 
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "morsecalc_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"

// Display float on screen
void morsecalc_print_float(double d) { 
    // Special cases 
    if(d == 0) {
        watch_display_string("     0", 4); 
        return;
    }
    else if(isnan(d)) {
        watch_display_string("   nan", 4);
        return;
    }
    else if(d == (1.0)/(0.0)) {
        watch_display_string("   inf", 4);
        return;
    }
    else if(d == (-1.0)/(0.0)) {
        watch_display_character('X', 1);
        watch_display_string("   inf", 4);
        return;
    }

    // Record number properties
    // Sign
    int is_negative = d<0;
    if(is_negative) d = -d; 

    // Order of magnitude
    int om = (int) floor(log(d)/log(10));
    int om_is_negative = (om<0);

    // Get the first 4 significant figures
    int digits;
    digits = round(d*pow(10.0, 3-om));
    if(digits>9999) {
        digits = 1000;
        om++;
    }

    // Print signs
    if(is_negative) {
		// Xi; see https://joeycastillo.github.io/Sensor-Watch-Documentation/segmap
		watch_set_pixel(0,11);
		watch_set_pixel(2,12);
		watch_set_pixel(2,11); 
	}
    else watch_display_character(' ', 1); 
    if(om_is_negative) watch_set_pixel(1,9); 
    else watch_display_character(' ', 2); 

    // Print first 4 significant figures
    watch_display_character('0'+(digits/1000)%10, 4);
    watch_display_character('0'+(digits/100 )%10, 5);
    watch_display_character('0'+(digits/10  )%10, 6);
    watch_display_character('0'+(digits/1   )%10, 7);

    // Prinat exponent
    if(om_is_negative) om = -om; // Make exponent positive for display
    if(om<=99) {
        watch_display_character('0'+(om/10  )%10, 8);
        watch_display_character('0'+(om/1   )%10, 9);
    } else { // Over/underflow
        if(om_is_negative) watch_display_string("    uf", 4);
        else watch_display_string("    of", 4);
        if(om<9999) { // Use main display to show order of magnitude
            // (Should always succeed; max double is <2e308)
            watch_display_character('0'+(om/1000)%10, 4);
            watch_display_character('0'+(om/100 )%10, 5);
            watch_display_character('0'+(om/10  )%10, 6);
            watch_display_character('0'+(om/1   )%10, 7);
        }
    }
    return;
}

// Print current input token
void morsecalc_print_token(morsecalc_state_t *mcs) {
    watch_display_string("          ", 0); // Clear display

    // Print morse code buffer
    char c = mc_dec(mcs->mc->b); // Decode the morse code buffer's current contents
    if('\0' == c) c = ' '; // Needed for watch_display_character
    watch_display_character(c, 0); // Display current morse code char in mode position
    watch_display_character('0'+(mcs->mc->bidx), 3); // Display buffer position in top right

    // Print last 6 chars of current input line 
    uint8_t nlen = strlen(mcs->token); // number of characters in token
    uint8_t nprint = min(nlen,6); // number of characters to print
    watch_display_string(mcs->token+nlen-nprint, 10-nprint); // print right-aligned
    return;
}

// Clear token buffer
void morsecalc_reset_token(morsecalc_state_t *mcs) { 
    memset(mcs->token, '\0', MORSECALC_TOKEN_LEN*sizeof(mcs->token[0]));
    mcs->idxt = 0;
    return;
}

// Print stack or memory register contents. 
void morsecalc_print_stack(morsecalc_state_t * mcs) {
    watch_display_string("          ", 0); // Clear display

    char c = mc_dec(mcs->mc->b); 
    if('m' == c) { // Display memory 
        morsecalc_print_float(mcs->cs->mem);
        watch_display_character(c, 0);
    } 
    else {
        // If the morse code buffer has a numeral in it, print that stack item 
        // Otherwise print top of stack
        uint8_t idx = 0;
        if(c >= '0' && c <= '9') idx = c - '0';
        if(idx >= mcs->cs->s) watch_display_string(" empty", 4); // Stack empty
        else morsecalc_print_float(mcs->cs->stack[mcs->cs->s-1-idx]); // Print stack item

        watch_display_character('0'+idx, 0); // Print which stack item this is top center
    }
    watch_display_character('0'+(mcs->cs->s), 3); // Print the # of stack items top right 
    return;
}

// Write something into the morse code buffer.
// Input: c = dot (0), dash (1), or 'complete' ('x')
void morsecalc_input(morsecalc_state_t * mcs, char c) {
    int status = 0;
    if( c != 'x' ) { // Dot or dash received
        mc_input(mcs->mc, c);
        morsecalc_print_token(mcs);
    } 
    else { // Morse code character finished
        char dec = mc_dec(mcs->mc->b); 
        mc_reset(mcs->mc);
        switch(dec) {
            case '\0': // Invalid character, do nothing
                morsecalc_print_token(mcs);
                break;
                
            case ' ': // Submit token to calculator
                if(strlen(mcs->token) > 0) {
                    status = calc_input(mcs->cs, mcs->token);
                    morsecalc_reset_token(mcs); 
                } 
                morsecalc_print_stack(mcs);   
                break;
                
            case '(': // -.--. Erase previous character in token
                if(mcs->idxt>0) {
                    mcs->idxt--;
                    mcs->token[mcs->idxt] = '\0';
                }
                morsecalc_print_token(mcs);
                break;
                
            case 'S': // -.-.- Erase entire token without submitting
                morsecalc_reset_token(mcs); 
                morsecalc_print_stack(mcs);   
                break;
                
            default: // Add character to token
                if(mcs->idxt < MORSECALC_TOKEN_LEN-1) {
                    mcs->token[mcs->idxt] = dec;
                    mcs->idxt++; 
                    morsecalc_print_token(mcs);
                }
                else  watch_display_string("  full", 4); 
                break;
        }
    }
    
    // Print errors if there are any
    switch(status) {
        case  0: break; // Success
        case -1: watch_display_string("cmderr", 4); break; // Unrecognized command
        case -2: watch_display_string("stkerr", 4); break; // Bad stack size
        default: watch_display_string("   err", 4); break; // Other error 
    }
    
    return;    
}

void morsecalc_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(morsecalc_state_t)); 
        morsecalc_state_t *mcs = (morsecalc_state_t *)*context_ptr;
        morsecalc_reset_token(mcs); 
        
        mcs->cs = (calc_state_t *) malloc(sizeof(calc_state_t));
        calc_init(mcs->cs); 
        
        mcs->mc = (mc_state_t *) malloc(sizeof(mc_state_t));
        mc_reset(mcs->mc);

        mcs->led_is_on = 0;
    }
    return;
}

void morsecalc_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    morsecalc_state_t *mcs = (morsecalc_state_t *) context;
    mc_reset(mcs->mc);
    morsecalc_print_stack(mcs);
    return;
}

bool morsecalc_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    morsecalc_state_t *mcs = (morsecalc_state_t *) context;
    switch(event.event_type) {
    // input
    case EVENT_ALARM_BUTTON_UP:
    // dot
        morsecalc_input(mcs, '.');    
        break;
    case EVENT_LIGHT_BUTTON_UP:
    // dash
        morsecalc_input(mcs, '-'); 
        break;
    case EVENT_MODE_BUTTON_UP:
    // submit character
        morsecalc_input(mcs, 'x'); 
        break;

    // show stack
    case EVENT_ALARM_LONG_PRESS:
        morsecalc_print_stack(mcs);
		mc_reset(mcs->mc);
        break;

    // toggle light
    case EVENT_LIGHT_LONG_PRESS:
        mcs->led_is_on = !mcs->led_is_on;
        if(mcs->led_is_on) {
			watch_set_led_color(settings->bit.led_red_color ? (0xF | settings->bit.led_red_color << 4) : 0,
								settings->bit.led_green_color ? (0xF | settings->bit.led_green_color << 4) : 0);
            movement_request_tick_frequency(4);
        }
        else {
            watch_set_led_off();
            movement_request_tick_frequency(1);
        }
        break;

    // quit
    case EVENT_TIMEOUT:
        movement_move_to_next_face();
        break;
    case EVENT_MODE_LONG_PRESS:
        movement_move_to_next_face();
        break;

    case EVENT_TICK:
        if(mcs->led_is_on) { 
			watch_set_led_color(settings->bit.led_red_color ? (0xF | settings->bit.led_red_color << 4) : 0,
				settings->bit.led_green_color ? (0xF | settings->bit.led_green_color << 4) : 0);
		}
        break;
    case EVENT_LIGHT_BUTTON_DOWN:
        // don't light up every time light is hit
        break;
    default:
        movement_default_loop_handler(event, settings);
        break;
	}
    
    return true;
}

void morsecalc_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    morsecalc_state_t *mcs = (morsecalc_state_t *) context;
    mcs->led_is_on = 0;
	watch_set_led_off();
    return;
}

