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
#include "watch_main_loop.h"

#include <emscripten.h>
#include <emscripten/html5.h>

#define ANIMATION_FRAME_ID_IS_VALID(id) ((id) >= 0)
#define ANIMATION_FRAME_ID_INVALID (-1)
#define ANIMATION_FRAME_ID_SUSPENDED (-2)

static bool sleeping = true;
static volatile long animation_frame_id = ANIMATION_FRAME_ID_INVALID;

// make compiler happy
static void main_loop_set_sleeping(bool sleeping);
static EM_BOOL main_loop(double time, void *userData);

static inline void request_next_frame(void) {
    if (animation_frame_id == ANIMATION_FRAME_ID_INVALID) {
        animation_frame_id = emscripten_request_animation_frame(main_loop, NULL);
    }
}

static EM_BOOL main_loop(double time, void *userData) {
    if (main_loop_is_sleeping()) {
        request_next_frame();
        return EM_FALSE;
    }

    if (sleeping) {
        sleeping = false;
        app_wake_from_standby();
    }

    animation_frame_id = ANIMATION_FRAME_ID_INVALID;
    bool can_sleep = app_loop();

    if (can_sleep) {
        app_prepare_for_standby();
        sleeping = true;
        animation_frame_id = ANIMATION_FRAME_ID_INVALID;
        return EM_FALSE;
    }

    request_next_frame();
    return EM_FALSE;
}

void resume_main_loop(void) {
    if (!ANIMATION_FRAME_ID_IS_VALID(animation_frame_id)) {
        animation_frame_id = emscripten_request_animation_frame(main_loop, NULL);
    }
}

void suspend_main_loop(void) {
    if (ANIMATION_FRAME_ID_IS_VALID(animation_frame_id)) {
        emscripten_cancel_animation_frame(animation_frame_id);
    }

    animation_frame_id = ANIMATION_FRAME_ID_SUSPENDED;
}

void main_loop_sleep(uint32_t ms) {
    main_loop_set_sleeping(true);
    emscripten_sleep(ms);
    main_loop_set_sleeping(false);
    animation_frame_id = ANIMATION_FRAME_ID_INVALID;
}

bool main_loop_is_sleeping(void) {
    return EM_ASM_INT({ return Module['suspended']; }) != 0;
}

static void main_loop_set_sleeping(bool sleeping) {
    EM_ASM({
        Module['suspended'] = $0;
    }, sleeping);
}

void delay_ms(const uint16_t ms) {
    main_loop_sleep(ms);
}

int main(void) {
    app_init();
    _watch_init();
    app_setup();

    resume_main_loop();

    return 0;
}
