#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "watch.h"

#include <emscripten.h>
#include <emscripten/html5.h>

static EM_BOOL one_iter(double time, void *userData) {
    bool can_sleep = app_loop();

    if (can_sleep) {
        app_prepare_for_standby();
        // sleep(4);
        app_wake_from_standby();
    }

    // Return true to keep the loop running.
    return EM_TRUE;
}

int main(void) {
    printf("Hello, world!\n");

    app_init();
    _watch_init();
    app_setup();

    emscripten_request_animation_frame_loop(one_iter, NULL);

    return 0;
}
