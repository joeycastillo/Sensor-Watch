#ifndef DAY_ONE_FACE_H_
#define DAY_ONE_FACE_H_

#include "movement.h"

// The Day One face is designed to count upwards from the wearer's date of birth. It also functions as an
// interface for setting the birth date register, which other watch faces can use for various purposes.

typedef struct {
    uint8_t current_page;
    uint16_t current_year;
    uint16_t birth_year;
    uint8_t birth_month;
    uint8_t birth_day;
    bool birthday_changed;
} day_one_state_t;

void day_one_face_setup(movement_settings_t *settings, void ** context_ptr);
void day_one_face_activate(movement_settings_t *settings, void *context);
bool day_one_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void day_one_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t day_one_face = {
    day_one_face_setup,
    day_one_face_activate,
    day_one_face_loop,
    day_one_face_resign,
    NULL
};

#endif // DAY_ONE_FACE_H_
