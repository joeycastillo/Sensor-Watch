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

#include "watch_private.h"
#include "watch_utility.h"
#include <sys/time.h>

void _watch_init(void) {
    // External wake depends on RTC; calendar is a required module.
    _watch_rtc_init();
}

// this function is called by arc4random to get entropy for random number generation.
// let's use the SAM L22's true random number generator to seed the PRNG!
int getentropy(void *buf, size_t buflen);
int getentropy(void *buf, size_t buflen) {
    // TODO: (a2) hook to RNG
    return 0;
}

int _gettimeofday(struct timeval *tv, void *tzvp);
int _gettimeofday(struct timeval *tv, void *tzvp) {
    (void)tzvp;
    watch_date_time date_time = watch_rtc_get_date_time();

    // FIXME: this assumes the system time is UTC! Will break for any other time zone.
    tv->tv_sec = watch_utility_date_time_to_unix_time(date_time, 0);
    tv->tv_usec = 0;

    return 0;
}

void _watch_enable_tcc(void) {}

void _watch_disable_tcc(void) {}

void _watch_enable_usb(void) {}

void watch_disable_TRNG() {}

// this function ends up getting called by printf to log stuff to the USB console.
int _write(int file, char *ptr, int len) {
    // TODO: (a2) hook to UI
    return 0;
}

int _read(int file, char *ptr, int len) {
    // TODO: hook to UI
    return 0;
}
