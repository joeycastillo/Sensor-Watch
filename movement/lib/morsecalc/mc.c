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

