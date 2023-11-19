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
#include "watch_private_display.h"

static const uint32_t IndicatorSegments[] = {
    SLCD_SEGID(0, 17), // WATCH_INDICATOR_SIGNAL
    SLCD_SEGID(0, 16), // WATCH_INDICATOR_BELL
    SLCD_SEGID(2, 17), // WATCH_INDICATOR_PM
    SLCD_SEGID(2, 16), // WATCH_INDICATOR_24H
    SLCD_SEGID(1, 10), // WATCH_INDICATOR_LAP
};

void watch_display_character(uint8_t character, uint8_t position) {
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
        if (character == 'a') character = 'A'; // A needs to be uppercase
        else if (character == 'o') character = 'O'; // O needs to be uppercase
        else if (character == 'i') character = 'l'; // I needs to be uppercase (use an l, it looks the same)
        else if (character == 'n') character = 'N'; // N needs to be uppercase
        else if (character == 'r') character = 'R'; // R needs to be uppercase
        else if (character == 'd') character = 'D'; // D needs to be uppercase
        else if (character == 'v' || character == 'V' || character == 'u') character = 'U'; // side segments shared, make uppercase
        else if (character == 'b') character = 'B'; // B needs to be uppercase
        else if (character == 'c') character = 'C'; // C needs to be uppercase
    } else {
        if (character == 'R') character = 'r'; // R needs to be lowercase almost everywhere
    }
    if (position == 0) {
        watch_clear_pixel(0, 15); // clear funky ninth segment
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

        if (segdata & 1)
          watch_set_pixel(com, seg);
        else
          watch_clear_pixel(com, seg);

        segmap = segmap >> 8;
        segdata = segdata >> 1;
    }

    if (character == 'T' && position == 1) watch_set_pixel(1, 12); // add descender
    else if (position == 0 && (character == 'B' || character == 'D' || character == '@')) watch_set_pixel(0, 15); // add funky ninth segment
    else if (position == 1 && (character == 'B' || character == 'D' || character == '@')) watch_set_pixel(0, 12); // add funky ninth segment
}

void watch_display_character_lp_seconds(uint8_t character, uint8_t position) {
    // Will only work for digits and for positions  8 and 9 - but less code & checks to reduce power consumption

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

        if (segdata & 1)
          watch_set_pixel(com, seg);
        else
          watch_clear_pixel(com, seg);

        segmap = segmap >> 8;
        segdata = segdata >> 1;
    }
}

void watch_display_string(char *string, uint8_t position) {
    size_t i = 0;
    while(string[i] != 0) {
        watch_display_character(string[i], position + i);
        i++;
        if (position + i >= Num_Chars) break;
    }
    // uncomment this line to see screen output on terminal, i.e.
    //   FR  29
    // 11 50 23
    // note that for partial displays (positon > 0) it will only show the characters that were updated.
    // printf("________\n  %c%c  %c%c\n%c%c %c%c %c%c\n--------\n", (position > 0) ? ' ' : string[0], (position > 1) ? ' ' : string[1 - position], (position > 2) ? ' ' : string[2 - position], (position > 3) ? ' ' : string[3 - position], (position > 4) ? ' ' : string[4 - position], (position > 5) ? ' ' : string[5 - position], (position > 6) ? ' ' : string[6 - position], (position > 7) ? ' ' : string[7 - position], (position > 8) ? ' ' : string[8 - position], (position > 9) ? ' ' : string[9 - position]);
}

void watch_set_colon(void) {
    watch_set_pixel(1, 16);
}

void watch_clear_colon(void) {
    watch_clear_pixel(1, 16);
}

void watch_set_indicator(WatchIndicatorSegment indicator) {
    uint32_t value = IndicatorSegments[indicator];
    uint8_t com = SLCD_COMNUM(value);
    uint8_t seg = SLCD_SEGNUM(value);
    watch_set_pixel(com, seg);
}

void watch_clear_indicator(WatchIndicatorSegment indicator) {
    uint32_t value = IndicatorSegments[indicator];
    uint8_t com = SLCD_COMNUM(value);
    uint8_t seg = SLCD_SEGNUM(value);
    watch_clear_pixel(com, seg);
}

void watch_clear_all_indicators(void) {
    watch_clear_pixel(2, 17);
    watch_clear_pixel(2, 16);
    watch_clear_pixel(0, 17);
    watch_clear_pixel(0, 16);
    watch_clear_pixel(1, 10);
}
