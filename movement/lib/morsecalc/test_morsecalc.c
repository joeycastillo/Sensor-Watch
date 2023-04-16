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

// Computer console interface to calc and morsecode for testing without involving watch stuff.
// cc calc_strtof.c calc.c calc_fns.c test_morsecalc.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "calc.h"
#include "calc_fns.h"

int main(void) {
    calc_state_t cs;
    calc_init(&cs);
    
    char * word = malloc(0);
    unsigned int nword = 0;
    char c;
    int retval = 0;
    for(unsigned int ii = 0; ii < 100; ii++) {
        c = getchar();
        word = realloc(word, (++nword)*sizeof(char));
        word[nword-1] = c;    
        if((nword > 0) && isspace(c)) { // Word is finished
            word[nword-1] = '\0';
            retval = calc_input(&cs, word); // Submit word
            word = realloc(word, 0); nword = 0; // Clear word
            
            switch(retval) {
                case 0: printf("Success.\n"); break; 
                case -1: printf("Bad command.\n"); break;
                case -2: printf("Stack over/underflow.\n"); break;
                case -3: printf("Error.\n"); break;
            }
            if(cs.s > 0) printf("[%i]: %.4f\n", cs.s, cs.stack[cs.s-1]);
            else printf("[%i]\n", cs.s);
        }
    }
    
    free(word);
    return 0;
}
