/*
 * MIT License
 *
 * Copyright (c) 2021 Joey Castillo
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
#ifndef _WATCH_PRIVATE_H_INCLUDED
#define _WATCH_PRIVATE_H_INCLUDED

#include "watch.h"

/// Called by main.c while setting up the app. You should not call this from your app.
void _watch_init(void);

/// Initializes the real-time clock peripheral.
void _watch_rtc_init(void);

/// Called by buzzer and LED setup functions. You should not call this from your app.
void _watch_enable_tcc(void);

/// Called by buzzer and LED teardown functions. You should not call this from your app.
void _watch_disable_tcc(void);

/// Called by main.c if plugged in to USB. You should not call this from your app.
void _watch_enable_usb(void);

// this function ends up getting called by printf to log stuff to the USB console.
int _write(int file, char *ptr, int len);

// this method could be overridden to read stuff from the USB console? but no need rn.
int _read(void);

#endif
