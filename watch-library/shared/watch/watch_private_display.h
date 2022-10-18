/*
 * MIT License
 *
 * Copyright (c) 2020 Joey Castillo
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
#ifndef _WATCH_PRIVATE_DISPLAY_H_INCLUDED
#define _WATCH_PRIVATE_DISPLAY_H_INCLUDED

#include "hpl_slcd_config.h"
#include "driver_init.h"

// Bit position -> segment mapping for Character_Set.
//  --0-- 
// |     | 
// 5     1 
// |     | 
//  --6-- 
// |     | 
// 4     2 
// |     | 
//  --3--


static const uint8_t Character_Set[] =
{
    0b00000000, //  
    0b01100000, // ! (L in the top half for positions 4 and 6)
    0b00100010, // "
    0b01100011, // # (degree symbol, hash mark doesn't fit)
    0b00101101, // $ (S without the center segment)
    0b00000000, // % (unused)
    0b01000100, // & ("lowercase 7" for positions 4 and 6)
    0b00100000, // '
    0b00111001, // (
    0b00001111, // )
    0b11000000, // * (The + sign for use in position 0)
    0b01110000, // + (segments E, F and G; looks like ┣╸)
    0b00000100, // ,
    0b01000000, // -
    0b01000000, // . (same as -, semantically most useful)
    0b00010010, // /
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b00000000, // : (unused)
    0b00000000, // ; (unused)
    0b01011000, // <
    0b01001000, // =
    0b01001100, // >
    0b01010011, // ?
    0b11111111, // @ (all segments on)
    0b01110111, // A
    0b01111111, // B
    0b00111001, // C
    0b00111111, // D
    0b01111001, // E
    0b01110001, // F
    0b00111101, // G
    0b01110110, // H
    0b10001001, // I (only works in position 0)
    0b00001110, // J
    0b01110101, // K
    0b00111000, // L
    0b10110111, // M (only works in position 0)
    0b00110111, // N
    0b00111111, // O
    0b01110011, // P
    0b01100111, // Q
    0b11110111, // R (only works in position 1)
    0b01101101, // S
    0b10000001, // T (only works in position 0; set (1, 12) to make it work in position 1)
    0b00111110, // U
    0b00111110, // V
    0b10111110, // W (only works in position 0)
    0b01111110, // X
    0b01101110, // Y
    0b00011011, // Z
    0b00111001, // [
    0b00100100, // backslash
    0b00001111, // ]
    0b00100011, // ^
    0b00001000, // _
    0b00000010, // `
    0b01011111, // a
    0b01111100, // b
    0b01011000, // c
    0b01011110, // d
    0b01111011, // e
    0b01110001, // f
    0b01101111, // g
    0b01110100, // h
    0b00010000, // i
    0b01000010, // j (appears as superscript to work in more positions)
    0b01110101, // k
    0b00110000, // l
    0b10110111, // m (only works in position 0)
    0b01010100, // n
    0b01011100, // o
    0b01110011, // p
    0b01100111, // q
    0b01010000, // r
    0b01101101, // s
    0b01111000, // t
    0b01100010, // u (appears in (u)pper half to work in more positions)
    0b00011100, // v (looks like u but in the lower half)
    0b10111110, // w (only works in position 0)
    0b01111110, // x
    0b01101110, // y
    0b00011011, // z
    0b00010110, // { (open brace doesn't really work; overriden to represent the two character ligature "il")
    0b00110110, // | (overriden to represent the two character ligature "ll")
    0b00110100, // } (overriden to represent the two character ligature "li")
    0b00000001, // ~
};

static const uint64_t Segment_Map[] = {
    0x4e4f0e8e8f8d4d0d, // Position 0, mode
    0xc8c4c4c8b4b4b0b,  // Position 1, mode (Segments B and C shared, as are segments E and F)
    0xc049c00a49890949, // Position 2, day of month (Segments A, D, G shared; missing segment F)
    0xc048088886874707, // Position 3, day of month
    0xc053921252139352, // Position 4, clock hours (Segments A and D shared)
    0xc054511415559594, // Position 5, clock hours
    0xc057965616179716, // Position 6, clock minutes (Segments A and D shared)
    0xc041804000018a81, // Position 7, clock minutes
    0xc043420203048382, // Position 8, clock seconds
    0xc045440506468584, // Position 9, clock seconds
};

static const uint8_t Num_Chars = 10;

void watch_display_character(uint8_t character, uint8_t position);

#endif
