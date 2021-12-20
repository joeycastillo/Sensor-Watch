#ifndef VOLTAGE_FACE_H_
#define VOLTAGE_FACE_H_

#include "movement.h"

void voltage_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void voltage_face_activate(movement_settings_t *settings, void *context);
bool voltage_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void voltage_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t voltage_face = {
    voltage_face_setup,
    voltage_face_activate,
    voltage_face_loop,
    voltage_face_resign,
    NULL
};

#endif // VOLTAGE_FACE_H_