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

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"

#include "morsecalc_face.h"
#include "morsecalc_display.h"

/* mc_input Read an input into a morse code buffer 
 * Input: mc = index of MORSECODE_TREE[]
 *        len = max morse code char length
 *        in = character to read into buffer (0='.', 1='-', ignored otherwise).
 * If the buffer is full, reset it instead of entering the new character.
 */
static void morsecode_input(unsigned int *mc, unsigned int len, char in) {
    if(*mc >= (unsigned int) ((1<<len)-1)) *mc = 0;
    else if((in == 0) | (in == 1)) *mc = (*mc)*2+in+1;
    return;
}


// Clear token buffer
void morsecalc_reset_token(morsecalc_state_t *mcs) { 
    memset(mcs->token, '\0', MORSECALC_TOKEN_LEN*sizeof(mcs->token[0]));
    mcs->idxt = 0;
    return;
}

// Write a completed morse code character to the calculator
void morsecalc_input(morsecalc_state_t * mcs) {
    int status = 0;
    char dec = MORSECODE_TREE[mcs->mc]; 
    mcs->mc = 0;
    switch(dec) {
        case '\0': // Invalid character, do nothing
            morsecalc_display_token(mcs);
            break;
            
        case ' ': // Submit token to calculator
            if(mcs->idxt > 0) {
                mcs->token[mcs->idxt] = '\0';
                status = calc_input(mcs->cs, mcs->token);
                morsecalc_reset_token(mcs); 
            } 
            morsecalc_display_stack(mcs);   
            break;
            
        case '(': // -.--. Erase previous character in token
            if(mcs->idxt>0) {
                mcs->idxt--;
                mcs->token[mcs->idxt] = '\0';
            }
            morsecalc_display_token(mcs);
            break;
            
        case 'S': // -.-.- Erase entire token without submitting
            morsecalc_reset_token(mcs); 
            morsecalc_display_stack(mcs);   
            break;
            
        default: // Add character to token
            if(mcs->idxt < MORSECALC_TOKEN_LEN-1) {
                mcs->token[mcs->idxt] = dec;
                mcs->idxt = min(mcs->idxt+1, MORSECALC_TOKEN_LEN); 
                morsecalc_display_token(mcs);
            }
            else  watch_display_string("  full", 4); 
            break;
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
        mcs->mc = 0;
        mcs->led_is_on = 0;
    }
    return;
}

void morsecalc_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    morsecalc_state_t *mcs = (morsecalc_state_t *) context;
    mcs->mc = 0;
    morsecalc_display_stack(mcs);
    return;
}

bool morsecalc_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    morsecalc_state_t *mcs = (morsecalc_state_t *) context;
    switch(event.event_type) {
    // input
    case EVENT_ALARM_BUTTON_UP:
    // dot
        morsecode_input(&mcs->mc, MORSECODE_LEN, 0);
        morsecalc_display_token(mcs);
        break;
    case EVENT_LIGHT_BUTTON_UP:
    // dash
        morsecode_input(&mcs->mc, MORSECODE_LEN, 1);
        morsecalc_display_token(mcs);
        break;
    case EVENT_MODE_BUTTON_UP:
    // submit character (or quit)
        if(mcs->mc || mcs->idxt) morsecalc_input(mcs); 
        else movement_move_to_next_face();
        break;

    // show stack
    case EVENT_ALARM_LONG_PRESS:
        morsecalc_display_stack(mcs);
        mcs->mc = 0;
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
        movement_move_to_face(0);
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

