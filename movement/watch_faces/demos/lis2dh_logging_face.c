#include <stdlib.h>
#include <string.h>
#include "lis2dh_logging_face.h"
#include "lis2dh.h"
#include "watch.h"

// This watch face is just for testing; if we want to build accelerometer support, it will likely have to be part of Movement itself.
// The watch face only logs events when it is on screen and not in low energy mode, so you should set LE mode to Never when using it
// and make it the first watch face in the list (so we come back to it from other modes).
// On an interrupt, it flashes the Signal icon, and displays the axis or axes that were over the threshold.
// The main display contains, from left to right, the number of interrupt events that were detected in each of the last three minutes.
// Pressing the alarm button enters the log mode, where the main display shows the number of interrupts detected in each of the last
// 24 hours (the hour is shown in the top right digit and AM/PM indicator, if the clock is set to 12 hour mode)

void _lis2dh_logging_face_log_data(lis2dh_logger_state_t *logger_state) {
    watch_date_time date_time = watch_rtc_get_date_time();
    size_t pos = logger_state->data_points % LIS2DH_LOGGING_NUM_DATA_POINTS;
    logger_state->data[pos].timestamp.reg = date_time.reg;
    logger_state->data[pos].interrupts = logger_state->interrupts_this_hour;
    logger_state->data_points++;
    logger_state->interrupts_this_hour = 0;
}

void lis2dh_logging_face_setup(movement_settings_t *settings, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(lis2dh_logger_state_t));
        memset(*context_ptr, 0, sizeof(lis2dh_logger_state_t));
        gpio_set_pin_direction(A0, GPIO_DIRECTION_OUT);
        gpio_set_pin_function(A0, GPIO_PIN_FUNCTION_OFF);
        gpio_set_pin_level(A0, true);
        watch_enable_i2c();
        lis2dh_begin();
        lis2dh_set_data_rate(LIS2DH_DATA_RATE_10_HZ);
        lis2dh_configure_aoi_int1(
            LIS2DH_INTERRUPT_CONFIGURATION_OR |
            LIS2DH_INTERRUPT_CONFIGURATION_X_HIGH_ENABLE |
            LIS2DH_INTERRUPT_CONFIGURATION_Y_HIGH_ENABLE |
            LIS2DH_INTERRUPT_CONFIGURATION_Z_HIGH_ENABLE, 96, 0, true);
    }
}

void lis2dh_logging_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    lis2dh_logger_state_t *logger_state = (lis2dh_logger_state_t *)context;
    logger_state->display_index = 0;
    logger_state->log_ticks = 0;
    watch_enable_digital_input(A1);
}

bool tick = false;

bool lis2dh_logging_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    lis2dh_logger_state_t *logger_state = (lis2dh_logger_state_t *)context;
    lis2dh_interrupt_state interrupt_state = 0;
    watch_date_time date_time;
    char buf[14];
    char time_indication_character;
    int8_t pos;

    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_LONG_PRESS:
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (logger_state->log_ticks) {
                logger_state->display_index = (logger_state->display_index + 1) % LIS2DH_LOGGING_NUM_DATA_POINTS;
            }
            logger_state->log_ticks = 60;
            // fall through
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            tick = !tick;
            if (watch_get_pin_level(A1)) {
                watch_set_indicator(WATCH_INDICATOR_SIGNAL);
                interrupt_state = lis2dh_get_int1_state();
                logger_state->interrupts[0]++;
                logger_state->interrupts_this_hour++;
            } else {
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            }
            if (logger_state->log_ticks) {
                pos = (logger_state->data_points - 1 - logger_state->display_index) % LIS2DH_LOGGING_NUM_DATA_POINTS;
                if (pos < 0) {
                    watch_clear_colon();
                    sprintf(buf, "NO   data ");
                } else {
                    date_time = logger_state->data[pos].timestamp;
                    watch_set_colon();
                    if (settings->bit.clock_mode_24h) {
                        watch_set_indicator(WATCH_INDICATOR_24H);
                    } else {
                        if (date_time.unit.hour > 11) watch_set_indicator(WATCH_INDICATOR_PM);
                        date_time.unit.hour %= 12;
                        if (date_time.unit.hour == 0) date_time.unit.hour = 12;
                    }
                    sprintf(buf, "AT%2d1n%4ld", date_time.unit.hour, logger_state->data[pos].interrupts);
                }
            } else {
                date_time = watch_rtc_get_date_time();
                watch_clear_colon();
                if ((59 - date_time.unit.second) < 10) time_indication_character = '0' + (59 - date_time.unit.second);
                else time_indication_character = (date_time.unit.second % 2) ? 'i' : '_';
                sprintf(buf, "%c%c%c%c%2d%2d%2d",
                    (interrupt_state & LIS2DH_INTERRUPT_STATE_Y_HIGH) ? 'Y' : ' ',
                    (interrupt_state & LIS2DH_INTERRUPT_STATE_X_HIGH) ? 'X' : ' ',
                    (interrupt_state & LIS2DH_INTERRUPT_STATE_Z_HIGH) ? '2' : ' ',
                    time_indication_character,
                    logger_state->interrupts[0],
                    logger_state->interrupts[1],
                    logger_state->interrupts[2]);
            }

            watch_display_string(buf, 0);
            break;
        case EVENT_BACKGROUND_TASK:
            _lis2dh_logging_face_log_data(logger_state);
            break;
        default:
            break;
    }

    return true;
}

void lis2dh_logging_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_disable_digital_input(A1);
}

bool lis2dh_logging_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    lis2dh_logger_state_t *logger_state = (lis2dh_logger_state_t *)context;

    // this is kind of an abuse of the API, but, let's use the 1 minute tick to shift all our data over.
    logger_state->interrupts[2] = logger_state->interrupts[1];
    logger_state->interrupts[1] = logger_state->interrupts[0];
    logger_state->interrupts[0] = 0;

    // and do our logging task at the top of the hour
    return watch_rtc_get_date_time().unit.minute == 0;
}
