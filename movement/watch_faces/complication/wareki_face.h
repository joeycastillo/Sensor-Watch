#ifndef WAREKI_FACE_H_
#define WAREKI_FACE_H_

#include "movement.h"

#define REIWA_LIMIT 2018 + 31
#define REIWA_GANNEN  2019
#define HEISEI_GANNEN 1989

typedef struct {
    bool active;
    uint32_t disp_year;     //Current displayed year 
    uint32_t start_year;    //Year when this screen was launched
    uint32_t real_year;     //The actual current year     
} wareki_state_t;


void wareki_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void wareki_activate(movement_settings_t *settings, void *context);
bool wareki_loop(movement_event_t event, movement_settings_t *settings, void *context);
void wareki_resign(movement_settings_t *settings, void *context);
void addYear(wareki_state_t* state,int count);
void subYear(wareki_state_t* state,int count);

#define wareki_face ((const watch_face_t){ \
    wareki_setup, \
    wareki_activate, \
    wareki_loop, \
    wareki_resign, \
    NULL, \
})

#endif // WAREKI_FACE_H_

