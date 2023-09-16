
/*
 * MIT License
 *
 * Copyright (c) 2023 Konrad Rieck
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

#ifndef ANIMATIONS_H_
#define ANIMATIONS_H_

#define NUM_ANIMATIONS (2)

#define WYOSCAN_MAX_ISEGMENTS (16)
#define WYOSCAN_TOTAL_FRAMES (64)
#define WYOSCAN_TOTAL_RUNS (3)

typedef struct {
    uint8_t start, end;
    uint8_t run;
    bool colon;
    uint8_t position, segment;
    char *segments;
    uint8_t x, y;
    uint8_t time_digits[6];
    uint8_t illuminated_segments[WYOSCAN_MAX_ISEGMENTS][2];
} wyoscan_state_t;

/* Support animations for animated clock face */
void ani_scroll_clock(movement_event_t, movement_settings_t *, animated_clock_state_t *);
void ani_wyoscan_clock(movement_event_t, movement_settings_t *, animated_clock_state_t *);

#endif
