#ifndef THERMISTOR_LOGGING_FACE_H_
#define THERMISTOR_LOGGING_FACE_H_

#include "movement.h"
#include "watch.h"

#define THERMISTOR_LOGGING_NUM_DATA_POINTS (36)

typedef struct {
    watch_date_time timestamp;
    float temperature_c;
} thermistor_logger_data_point_t;

typedef struct {
    uint8_t display_index;  // the index we are displaying on screen
    uint8_t ts_ticks;       // when the user taps the LIGHT button, we show the timestamp for a few ticks.
    int32_t data_points;    // the absolute number of data points logged
    thermistor_logger_data_point_t data[THERMISTOR_LOGGING_NUM_DATA_POINTS];
} thermistor_logger_state_t;

void thermistor_logging_face_setup(movement_settings_t *settings, void ** context_ptr);
void thermistor_logging_face_activate(movement_settings_t *settings, void *context);
bool thermistor_logging_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void thermistor_logging_face_resign(movement_settings_t *settings, void *context);
bool thermistor_logging_face_wants_background_task(movement_settings_t *settings, void *context);

static const watch_face_t thermistor_logging_face = {
    thermistor_logging_face_setup,
    thermistor_logging_face_activate,
    thermistor_logging_face_loop,
    thermistor_logging_face_resign,
    thermistor_logging_face_wants_background_task
};

#endif // THERMISTOR_LOGGING_FACE_H_
