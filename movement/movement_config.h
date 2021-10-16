#ifndef MOVEMENT_CONFIG_H_
#define MOVEMENT_CONFIG_H_

#include "simple_clock_face.h"
#include "preferences_face.h"
#include "set_time_face.h"
#include "pulseometer_face.h"

#define MOVEMENT_NUM_FACES 3

WatchFace watch_faces[MOVEMENT_NUM_FACES] = {
    simple_clock_face,
    preferences_face,
    set_time_face,
};


#endif // MOVEMENT_CONFIG_H_
