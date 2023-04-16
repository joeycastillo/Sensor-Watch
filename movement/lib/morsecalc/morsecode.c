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
 
#ifndef MORSECODE_
#define MORSECODE_ 

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
#endif
