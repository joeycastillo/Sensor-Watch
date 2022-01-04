#ifndef SIMPLE_CLOCK_FACE_H_
#define SIMPLE_CLOCK_FACE_H_

#include "movement.h"

typedef struct {
    uint32_t previous_date_time;
    uint8_t watch_face_index;
    bool signal_enabled;
} simple_clock_state_t;

void simple_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void simple_clock_face_activate(movement_settings_t *settings, void *context);
bool simple_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void simple_clock_face_resign(movement_settings_t *settings, void *context);
bool simple_clock_face_wants_background_task(movement_settings_t *settings, void *context);

static const watch_face_t simple_clock_face = {
    simple_clock_face_setup,
    simple_clock_face_activate,
    simple_clock_face_loop,
    simple_clock_face_resign,
    simple_clock_face_wants_background_task
};

#endif // SIMPLE_CLOCK_FACE_H_
