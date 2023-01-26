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

#include <string.h>
#include <math.h>

#include "watch_private_display.h"
#include "morsecalc_display.h"

// Display float on screen
void morsecalc_display_float(double d) { 
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
void morsecalc_display_token(morsecalc_state_t *mcs) {
    watch_display_string("          ", 0); // Clear display

    // Print morse code buffer
    char c = MORSECODE_TREE[mcs->mc]; // Decode the morse code buffer's current contents
    if('\0' == c) c = ' '; // Needed for watch_display_character
    watch_display_character(c, 0); // Display current morse code char in mode position
    
    unsigned int v = mcs->mc+1;
    char bidx = 0; while (v >>= 1) bidx++; 
    watch_display_character('0'+bidx, 3); // Display buffer position in top right

    // Print last 6 chars of current input line 
    uint8_t nlen = strlen(mcs->token); // number of characters in token
    uint8_t nprint = min(nlen,6); // number of characters to print
    watch_display_string(mcs->token+nlen-nprint, 10-nprint); // print right-aligned
    return;
}

// Print stack or memory register contents. 
void morsecalc_display_stack(morsecalc_state_t * mcs) {
    watch_display_string("          ", 0); // Clear display

    char c = MORSECODE_TREE[mcs->mc]; 
    if('m' == c) { // Display memory 
        morsecalc_display_float(mcs->cs->mem);
        watch_display_character(c, 0);
    } 
    else {
        // If the morse code buffer has a numeral in it, print that stack item 
        // Otherwise print top of stack
        uint8_t idx = 0;
        if(c >= '0' && c <= '9') idx = c - '0';
        if(idx >= mcs->cs->s) watch_display_string(" empty", 4); // Stack empty
        else morsecalc_display_float(mcs->cs->stack[mcs->cs->s-1-idx]); // Print stack item

        watch_display_character('0'+idx, 0); // Print which stack item this is top center
    }
    watch_display_character('0'+(mcs->cs->s), 3); // Print the # of stack items top right 
    return;
}

