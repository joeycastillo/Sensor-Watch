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
#include "mc.h"

/* mc_reset Initialize or reset an MC buffer
 * Input: mc = location of buffer to reset
 */
void mc_reset(mc_state_t * mc) {
    memset(mc->b, '\0', BUFFLEN*sizeof(mc->b[0]));
    mc->bidx = 0;
    return;
   return;
}

/* mc_input Read an input into a morse code buffer 
 * Input: mc = buffer to read into
 *        c = character to read into buffer ('.' or '-', ignored otherwise).
 * If the buffer is full, reset it instead of entering the new character.
 */
void mc_input(mc_state_t * mc, char c) {
    if(mc->bidx >= BUFFLEN) mc_reset(mc);
    else if( ('.' == c) || ('-' == c) ) {
        mc->b[mc->bidx] = c;
        mc->bidx++;
    }
    return;
}

/* mc_dec Decode a Morse code character (descend MC_DEC_KEY[])
 * Input: b = BUFFLEN-length char array with '.'s and '-'s
 * Output: c = Character b represents, or '\0' if not a Morse code. 
 */
char mc_dec(char b[BUFFLEN]) {
    uint8_t pos = 1; // Binary tree position ('.'=0; '-'=1)
    for(uint8_t idx=0; idx<BUFFLEN; idx++) {
        if('.' == b[idx]) pos = 2*pos; // Descend in . direction
        else if('-' == b[idx]) pos = 2*pos+1; // Descend in - direction
        else break; // End of morse code segment; finished descending
    }
    return MC_DEC_KEY[pos-1];
}

