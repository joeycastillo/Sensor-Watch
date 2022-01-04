#ifndef HELLO_THERE_FACE_H_
#define HELLO_THERE_FACE_H_

#include "movement.h"

typedef struct {
    uint8_t current_word;
    bool animating;
} hello_there_state_t;

void hello_there_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void hello_there_face_activate(movement_settings_t *settings, void *context);
bool hello_there_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void hello_there_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t hello_there_face = {
    hello_there_face_setup,
    hello_there_face_activate,
    hello_there_face_loop,
    hello_there_face_resign,
    NULL
};

#endif // HELLO_THERE_FACE_H_
