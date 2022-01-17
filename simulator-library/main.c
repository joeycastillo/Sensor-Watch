#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
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
