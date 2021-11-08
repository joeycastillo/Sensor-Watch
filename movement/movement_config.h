#ifndef MOVEMENT_CONFIG_H_
#define MOVEMENT_CONFIG_H_

#include "simple_clock_face.h"
#include "preferences_face.h"
#include "set_time_face.h"
#include "pulsometer_face.h"
#include "thermistor_readout_face.h"
#include "thermistor_logging_face.h"
#include "character_set_face.h"
#include "beats_face.h"
#include "day_one_face.h"
#include "voltage_face.h"

const watch_face_t watch_faces[] = {
    simple_clock_face,
    preferences_face,
    set_time_face,
};

#define MOVEMENT_NUM_FACES (sizeof(watch_faces) / sizeof(watch_face_t))

#endif // MOVEMENT_CONFIG_H_
