#ifndef STOPWATCH_FACE_H_
#define STOPWATCH_FACE_H_

#include "movement.h"

typedef struct {
    bool running;
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
} stopwatch_state_t;

void stopwatch_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void stopwatch_face_activate(movement_settings_t *settings, void *context);
bool stopwatch_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void stopwatch_face_resign(movement_settings_t *settings, void *context);

#define stopwatch_face ((const watch_face_t){ \
    stopwatch_face_setup, \
    stopwatch_face_activate, \
    stopwatch_face_loop, \
    stopwatch_face_resign, \
    NULL, \
})

#endif // STOPWATCH_FACE_H_
