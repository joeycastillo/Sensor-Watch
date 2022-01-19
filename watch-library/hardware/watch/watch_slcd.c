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

#include "watch_slcd.h"
#include "hpl_slcd_config.h"

 //////////////////////////////////////////////////////////////////////////////////////////
// Segmented Display

static const uint8_t Character_Set[] =
{
    0b00000000, //  
    0b01100000, // ! (L in the top half for positions 4 and 6)
    0b00100010, // "
    0b01100011, // # (degree symbol, hash mark doesn't fit)
    0b00000000, // $ (unused)
    0b00000000, // % (unused)
    0b01000100, // & ("lowercase 7" for positions 4 and 6)
    0b00100000, // '
    0b00111001, // (
    0b00001111, // )
    0b00000000, // * (unused)
    0b11000000, // + (only works in position 0)
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
    0b00111001, // {
    0b00110000, // |
    0b00001111, // }
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

static const uint32_t IndicatorSegments[6] = {
    SLCD_SEGID(0, 17), // WATCH_INDICATOR_SIGNAL
    SLCD_SEGID(0, 16), // WATCH_INDICATOR_BELL
    SLCD_SEGID(2, 17), // WATCH_INDICATOR_PM
    SLCD_SEGID(2, 16), // WATCH_INDICATOR_24H
    SLCD_SEGID(1, 10), // WATCH_INDICATOR_LAP
};

static void _sync_slcd(void) {
    while (SLCD->SYNCBUSY.reg);
}

void watch_enable_display(void) {
    SEGMENT_LCD_0_init();
    slcd_sync_enable(&SEGMENT_LCD_0);
}

inline void watch_set_pixel(uint8_t com, uint8_t seg) {
    slcd_sync_seg_on(&SEGMENT_LCD_0, SLCD_SEGID(com, seg));
}

inline void watch_clear_pixel(uint8_t com, uint8_t seg) {
    slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(com, seg));
}

void watch_clear_display(void) {
    SLCD->SDATAL0.reg = 0;
    SLCD->SDATAL1.reg = 0;
    SLCD->SDATAL2.reg = 0;
}

static void watch_display_character(uint8_t character, uint8_t position) {
    // special cases for positions 4 and 6
    if (position == 4 || position == 6) {
        if (character == '7') character = '&'; // "lowercase" 7
        else if (character == 'A') character = 'a'; // A needs to be lowercase
        else if (character == 'o') character = 'O'; // O needs to be uppercase
        else if (character == 'L') character = '!'; // L needs to be in top half
        else if (character == 'M' || character == 'm' || character == 'N') character = 'n'; // M and uppercase N need to be lowercase n
        else if (character == 'c') character = 'C'; // C needs to be uppercase
        else if (character == 'J') character = 'j'; // same
        else if (character == 'v' || character == 'V' || character == 'U' || character == 'W' || character == 'w') character = 'u'; // bottom segment duplicated, so show in top half
    } else {
        if (character == 'u') character = 'v'; // we can use the bottom segment; move to lower half
        else if (character == 'j') character = 'J'; // same but just display a normal J
    }
    if (position > 1) {
        if (character == 'T') character = 't'; // uppercase T only works in positions 0 and 1
    }
    if (position == 1) {
        if (character == 'o') character = 'O'; // O needs to be uppercase
        if (character == 'i') character = 'l'; // I needs to be uppercase (use an l, it looks the same)
        if (character == 'n') character = 'N'; // N needs to be uppercase
        if (character == 'r') character = 'R'; // R needs to be uppercase
        if (character == 'd') character = 'D'; // D needs to be uppercase
        if (character == 'v' || character == 'V' || character == 'u') character = 'U'; // side segments shared, make uppercase
        if (character == 'b') character = 'B'; // B needs to be uppercase
        if (character == 'c') character = 'C'; // C needs to be uppercase
    } else {
        if (character == 'R') character = 'r'; // R needs to be lowercase almost everywhere
    }
    if (position == 0) {
        slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(0, 15)); // clear funky ninth segment
    } else {
        if (character == 'I') character = 'l'; // uppercase I only works in position 0
    }

    uint64_t segmap = Segment_Map[position];
    uint64_t segdata = Character_Set[character - 0x20];

    for (int i = 0; i < 8; i++) {
        uint8_t com = (segmap & 0xFF) >> 6;
        if (com > 2) {
            // COM3 means no segment exists; skip it.
            segmap = segmap >> 8;
            segdata = segdata >> 1;
            continue;
        }
        uint8_t seg = segmap & 0x3F;
        slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(com, seg));
        if (segdata & 1) slcd_sync_seg_on(&SEGMENT_LCD_0, SLCD_SEGID(com, seg));
        segmap = segmap >> 8;
        segdata = segdata >> 1;
    }
    if (character == 'T' && position == 1) slcd_sync_seg_on(&SEGMENT_LCD_0, SLCD_SEGID(1, 12)); // add descender
    else if (position == 0 && (character == 'B' || character == 'D')) slcd_sync_seg_on(&SEGMENT_LCD_0, SLCD_SEGID(0, 15)); // add funky ninth segment
    else if (position == 1 && (character == 'B' || character == 'D' || character == '@')) slcd_sync_seg_on(&SEGMENT_LCD_0, SLCD_SEGID(0, 12)); // add funky ninth segment
}

void watch_display_string(char *string, uint8_t position) {
    size_t i = 0;
    while(string[i] != 0) {
        watch_display_character(string[i], position + i);
        i++;
        if (i >= Num_Chars) break;
    }
    // uncomment this line to see screen output on terminal, i.e.
    //   FR  29
    // 11 50 23
    // note that for partial displays (positon > 0) it will only show the characters that were updated.
    // printf("________\n  %c%c  %c%c\n%c%c %c%c %c%c\n--------\n", (position > 0) ? ' ' : string[0], (position > 1) ? ' ' : string[1 - position], (position > 2) ? ' ' : string[2 - position], (position > 3) ? ' ' : string[3 - position], (position > 4) ? ' ' : string[4 - position], (position > 5) ? ' ' : string[5 - position], (position > 6) ? ' ' : string[6 - position], (position > 7) ? ' ' : string[7 - position], (position > 8) ? ' ' : string[8 - position], (position > 9) ? ' ' : string[9 - position]);
}

inline void watch_set_colon(void) {
    slcd_sync_seg_on(&SEGMENT_LCD_0, SLCD_SEGID(1, 16));
}

inline void watch_clear_colon(void) {
    slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(1, 16));
}

inline void watch_set_indicator(WatchIndicatorSegment indicator) {
    slcd_sync_seg_on(&SEGMENT_LCD_0, IndicatorSegments[indicator]);
}

inline void watch_clear_indicator(WatchIndicatorSegment indicator) {
    slcd_sync_seg_off(&SEGMENT_LCD_0, IndicatorSegments[indicator]);
}

void watch_clear_all_indicators(void) {
    slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(2, 17));
    slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(2, 16));
    slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(0, 17));
    slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(0, 16));
    slcd_sync_seg_off(&SEGMENT_LCD_0, SLCD_SEGID(1, 10));
}

void watch_start_character_blink(char character, uint32_t duration) {
    SLCD->CTRLD.bit.FC0EN = 0;
    _sync_slcd();

    if (duration <= SLCD_FC_BYPASS_MAX_MS) {
        SLCD->FC0.reg = SLCD_FC0_PB | ((duration / (1000 / SLCD_FRAME_FREQUENCY)) - 1);
    } else {
        SLCD->FC0.reg = (((duration / (1000 / SLCD_FRAME_FREQUENCY)) / 8 - 1));
    }
    SLCD->CTRLD.bit.FC0EN = 1;

    watch_display_character(character, 7);
    watch_clear_pixel(2, 10); // clear segment B of position 7 since it can't blink

    SLCD->CTRLD.bit.BLINK = 0;
    SLCD->CTRLA.bit.ENABLE = 0;
    _sync_slcd();

    SLCD->BCFG.bit.BSS0 = 0x07;
    SLCD->BCFG.bit.BSS1 = 0x07;

    SLCD->CTRLD.bit.BLINK = 1;
    _sync_slcd();
    SLCD->CTRLA.bit.ENABLE = 1;
    _sync_slcd();
}

void watch_stop_blink(void) {
    SLCD->CTRLD.bit.FC0EN = 0;
    SLCD->CTRLD.bit.BLINK = 0;
}

void watch_start_tick_animation(uint32_t duration) {
    watch_display_character(' ', 8);
    const uint32_t segs[] = { SLCD_SEGID(0, 2)};
    slcd_sync_start_animation(&SEGMENT_LCD_0, segs, 1, duration);
}

bool watch_tick_animation_is_running(void) {
    return hri_slcd_get_CTRLD_CSREN_bit(SLCD);
}

void watch_stop_tick_animation(void) {
    const uint32_t segs[] = { SLCD_SEGID(0, 2)};
    slcd_sync_stop_animation(&SEGMENT_LCD_0, segs, 1);
    watch_display_character(' ', 8);
}
