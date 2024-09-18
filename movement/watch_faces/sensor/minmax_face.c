/*
 * MIT License
 *
 * Copyright (c) 2023 Mark Blyth
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include "minmax_face.h"
#include "thermistor_driver.h"
#include "watch.h"


static float _get_displayed_temperature_c(minmax_state_t *state){
    float min_temp = 1000;
    float max_temp = -1000;
    for(int i = 0; i < LOGGING_DATA_POINTS; i++){
      if(state->hourly_maxs[i] > max_temp){
	  max_temp = state->hourly_maxs[i];
	}
      if(state->hourly_mins[i] < min_temp){
	  min_temp = state->hourly_mins[i];
	}
    }
    if(state->show_min) return min_temp;
    return max_temp;
}


static void _minmax_face_log_data(minmax_state_t *logger_state) {
    thermistor_driver_enable();
    size_t pos = (size_t) watch_rtc_get_date_time().unit.hour;
    float temp_c = thermistor_driver_get_temperature();
    // If no data yet, initialise with current temperature
    if(!logger_state->have_logged){
      logger_state->have_logged = true;
      for(int i=0; i<LOGGING_DATA_POINTS; i++){
	logger_state->hourly_mins[i] = temp_c;
	logger_state->hourly_maxs[i] = temp_c;
      }
    }
    // On new hour, update lists to current temperature
    else if(watch_rtc_get_date_time().unit.minute < 2){
      logger_state->hourly_mins[pos] = temp_c;
      logger_state->hourly_maxs[pos] = temp_c;
    }
    // Log hourly highs and lows
    else if(logger_state->hourly_mins[pos] > temp_c){
      logger_state->hourly_mins[pos] = temp_c;
    }
    else if(logger_state->hourly_maxs[pos] < temp_c){
      logger_state->hourly_maxs[pos] = temp_c;
    }
    thermistor_driver_disable();
}

static void _minmax_face_update_display(float temperature_c, bool in_fahrenheit) {
    char buf[14];
    if (in_fahrenheit) {
        sprintf(buf, "%4.0f#F", temperature_c * 1.8 + 32.0);
    } else {
        sprintf(buf, "%4.0f#C", temperature_c);
    }
    watch_display_string(buf, 4);
}


void minmax_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(minmax_state_t));
        memset(*context_ptr, 0, sizeof(minmax_state_t));
    }
}


void minmax_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    minmax_state_t *state = (minmax_state_t *)context;
    state->show_min = true;
    watch_display_string("MN", 0); // Start with minimum temp
}

bool minmax_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    minmax_state_t *state = (minmax_state_t *)context;
    float temp_c;

    switch (event.event_type) {
	case EVENT_ACTIVATE:
	    temp_c = _get_displayed_temperature_c(state);
	    _minmax_face_update_display(temp_c, settings->bit.use_imperial_units);
            break;

	case EVENT_LIGHT_LONG_PRESS:
            settings->bit.use_imperial_units = !settings->bit.use_imperial_units;
	    temp_c = _get_displayed_temperature_c(state);
	    _minmax_face_update_display(temp_c, settings->bit.use_imperial_units);
            break;

	case EVENT_ALARM_BUTTON_UP:
	    state->show_min = !state->show_min;
	    if(state->show_min){
		watch_display_string("MN", 0);
	    } else {
		watch_display_string("MX", 0);
	    }
	    temp_c = _get_displayed_temperature_c(state);
	    _minmax_face_update_display(temp_c, settings->bit.use_imperial_units);
            break;

	case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
	case EVENT_BACKGROUND_TASK:
            _minmax_face_log_data(state);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}


void minmax_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}


bool minmax_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    // this will get called at the top of each minute; always request bg task
    return true;
}
