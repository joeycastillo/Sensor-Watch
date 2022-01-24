/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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

#include <stdio.h>
#include "watch.h"

#include <emscripten.h>
#include <emscripten/html5.h>

static bool sleeping = true;

static EM_BOOL main_loop(double time, void *userData) {
    if (sleeping) {
        sleeping = false;
        app_wake_from_standby();
    }

    bool can_sleep = app_loop();

    if (can_sleep) {
        app_prepare_for_standby();
        sleeping = true;
        return EM_FALSE;
    }

    return EM_TRUE;
}

// make compiler happy
void resume_main_loop(void);

EMSCRIPTEN_KEEPALIVE
void resume_main_loop(void) {
    if (sleeping) {
        emscripten_request_animation_frame_loop(main_loop, NULL);
    }
}

int main(void) {
    printf("Hello, world!\n");

    app_init();
    _watch_init();
    app_setup();

    resume_main_loop();

    return 0;
}
