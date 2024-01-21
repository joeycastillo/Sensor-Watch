/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Aptekar-Cassels
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
#ifndef _WATCH_PRIVATE_BUZZER_H_INCLUDED
#define _WATCH_PRIVATE_BUZZER_H_INCLUDED

// note: the buzzer uses a 1 MHz clock. these values were determined by dividing 1,000,000 by the target frequency.
// i.e. for a 440 Hz tone (A4 on the piano), 1MHz/440Hz = 2273
const uint16_t NotePeriods[108] = {18182,17161,16197,15288,14430,13620,12857,12134,11453,10811,10204,9631,9091,8581,8099,7645,7216,6811,6428,6068,5727,5405,5102,4816,4545,4290,4050,3822,3608,3405,3214,3034,2863,2703,2551,2408,2273,2145,2025,1911,1804,1703,1607,1517,1432,1351,1276,1204,1136,1073,1012,956,902,851,804,758,716,676,638,602,568,536,506,478,451,426,402,379,358,338,319,301,284,268,253,239,225,213,201,190,179,169,159,150,142,134,127};

uint16_t sequence_length(int8_t *sequence);

#endif
