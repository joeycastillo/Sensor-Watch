#ifndef DISCGOLF_FACE_H_
#define DISCGOLF_FACE_H_

#include "movement.h"
#define courses 11

typedef enum {
  dg_setting,                   // We are selecting a course
  dg_scoring,                   // We are inputting our score
  dg_idle,                      // We have input our score and are playing a hole
} discgolf_mode_t;

typedef struct {
    uint8_t course;             // Index for course selection, from 0
    uint8_t hole;               // Index for current hole, from 1
    uint8_t playing;            // Current hole
    int scores[18];             // Scores for each played hole    
    discgolf_mode_t mode;       // Watch face mode
} discgolf_state_t;

void discgolf_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void discgolf_face_activate(movement_settings_t *settings, void *context);
bool discgolf_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void discgolf_face_resign(movement_settings_t *settings, void *context);

#define discgolf_face ((const watch_face_t){ \
    discgolf_face_setup, \
    discgolf_face_activate, \
    discgolf_face_loop, \
    discgolf_face_resign, \
    NULL, \
})

#endif // DISCGOLF_FACE_H_
