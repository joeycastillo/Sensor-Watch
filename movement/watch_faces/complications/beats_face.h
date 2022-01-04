#ifndef BEATS_FACE_H_
#define BEATS_FACE_H_

#include "movement.h"

typedef struct {
    int8_t next_subsecond_update;
    uint32_t last_centibeat_displayed;
} beats_face_state_t;

uint32_t clock2beats(uint32_t hours, uint32_t minutes, uint32_t seconds, uint32_t subseconds, int16_t utc_offset);
void beats_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void beats_face_activate(movement_settings_t *settings, void *context);
bool beats_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void beats_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t beats_face = {
    beats_face_setup,
    beats_face_activate,
    beats_face_loop,
    beats_face_resign,
    NULL
};

#endif // BEATS_FACE_H_