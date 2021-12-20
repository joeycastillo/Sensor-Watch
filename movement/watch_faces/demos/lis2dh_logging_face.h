#ifndef LIS2DH_LOGGING_FACE_H_
#define LIS2DH_LOGGING_FACE_H_

#include "movement.h"
#include "watch.h"

#define LIS2DH_LOGGING_NUM_DATA_POINTS (96)

typedef struct {
    watch_date_time timestamp;
    uint32_t x_interrupts;
    uint32_t y_interrupts;
    uint32_t z_interrupts;
} lis2dh_logger_data_point_t;

typedef struct {
    uint8_t display_index;  // the index we are displaying on screen
    uint8_t axis_index;     // the index we are displaying on screen
    uint8_t log_ticks;      // when the user taps the ALARM button, we enter log mode
    int32_t data_points;    // the absolute number of data points logged
    uint8_t interrupts[3];  // the number of interrupts we have logged in each of the last 3 minutes
    uint32_t x_interrupts_this_hour;  // the number of interrupts we have logged in the last hour
    uint32_t y_interrupts_this_hour;  // the number of interrupts we have logged in the last hour
    uint32_t z_interrupts_this_hour;  // the number of interrupts we have logged in the last hour
    lis2dh_logger_data_point_t data[LIS2DH_LOGGING_NUM_DATA_POINTS];
} lis2dh_logger_state_t;

void lis2dh_logging_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void lis2dh_logging_face_activate(movement_settings_t *settings, void *context);
bool lis2dh_logging_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void lis2dh_logging_face_resign(movement_settings_t *settings, void *context);
bool lis2dh_logging_face_wants_background_task(movement_settings_t *settings, void *context);

static const watch_face_t lis2dh_logging_face = {
    lis2dh_logging_face_setup,
    lis2dh_logging_face_activate,
    lis2dh_logging_face_loop,
    lis2dh_logging_face_resign,
    lis2dh_logging_face_wants_background_task
};

#endif // LIS2DH_LOGGING_FACE_H_
