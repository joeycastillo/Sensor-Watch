#ifndef SET_TIME_FACE_H_
#define SET_TIME_FACE_H_

#include "movement.h"

void set_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void set_time_face_activate(movement_settings_t *settings, void *context);
bool set_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void set_time_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t set_time_face = {
    set_time_face_setup,
    set_time_face_activate,
    set_time_face_loop,
    set_time_face_resign,
    NULL
};

#endif // SET_TIME_FACE_H_
