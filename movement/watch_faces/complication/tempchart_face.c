/*
 * MIT License
 *
 * Copyright (c) 2022 Mikhail Svarichevsky
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
#include <math.h>
#include "tempchart_face.h"
#include "watch.h"
#include "watch_private_display.h"
#include "filesystem.h"
#include "thermistor_driver.h"

struct {
    uint8_t stat[24 * 70];
    uint16_t num_div;
} tempchart_state;

static void tempchart_save(void) {
    filesystem_write_file("tempchart.ini", (char*)&tempchart_state, sizeof(tempchart_state));
}

void tempchart_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    // These next two lines just silence the compiler warnings associated with unused parameters.
    // We have no use for the settings or the watch_face_index, so we make that explicit here.
    (void) settings;
    (void) context_ptr;
    (void) watch_face_index;
    // At boot, context_ptr will be NULL indicating that we don't have anyplace to store our context.
    if (filesystem_get_file_size("tempchart.ini") != sizeof(tempchart_state)) {
        // No previous ini or old version of ini file - create new config file
        tempchart_state.num_div = 0;
        for (int i = 0; i < 24 * 70; i++)
            tempchart_state.stat[i] = 0;
        tempchart_save();
    } else
        filesystem_read_file("tempchart.ini", (char*)&tempchart_state, sizeof(tempchart_state));

}

void tempchart_face_activate(movement_settings_t *settings, void *context) {
    // same as above: silence the warning, we don't need to check the settings.
    (void) settings;
    (void) context;
}

static void display(void) {
    int sum = 0;
    for (int i = 0; i < 24 * 70; i++)
        sum += tempchart_state.stat[i];

    char buf[24];
    sprintf(buf, "TS%2d%6d", tempchart_state.num_div, sum);
    watch_display_string(buf, 0);
}

bool tempchart_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
             display();
        case EVENT_TICK:
            // on activate and tick, if we are animating,
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // This low energy mode update occurs once a minute, if the watch face is in the
            // foreground when Movement enters low energy mode. We have the option of supporting
            // this mode, but since our watch face animates once a second, the "Hello there" face
            // isn't very useful in this mode. So we choose not to support it. (continued below)
            break;
        case EVENT_TIMEOUT:
            // ... Instead, we respond to the timeout event. This event happens after a configurable
            // interval on screen (1-30 minutes). The watch will give us this event as a chance to
            // resign control if we want to, and in this case, we do.
            // This function will return the watch to the first screen (usually a simple clock),
            // and it will do it long before the watch enters low energy mode. This ensures we
            // won't be on screen, and thus opts us out of getting the EVENT_LOW_ENERGY_UPDATE above.
            movement_move_to_face(0);
            break;
        case EVENT_BACKGROUND_TASK:
            // Here we measure temperature and do main frequency correction
            thermistor_driver_enable();
            float temperature_c = thermistor_driver_get_temperature();
            thermistor_driver_disable();
            watch_date_time date_time = watch_rtc_get_date_time();

            int temp = round(temperature_c * 2);
            if ((temp < 0) || (temp >= 70)) break;

            if (tempchart_state.stat[date_time.unit.hour + temp * 24] == 255) { // We've reached the limit
              tempchart_state.num_div++;
              for (int i = 0; i < 24 * 70; i++)
                tempchart_state.stat[i] = (tempchart_state.stat[i] + 1) >> 1; // So that we don't lose 1
            }
            tempchart_state.stat[date_time.unit.hour+temp*24]++;

            if (date_time.unit.hour == 0 && date_time.unit.minute == 10)
                tempchart_save();

            break;

        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void tempchart_face_resign(movement_settings_t *settings, void *context) {
    // our watch face, like most watch faces, has nothing special to do when resigning.
    // watch faces that enable a peripheral or interact with a sensor may want to turn it off here.
    (void) settings;
    (void) context;
}

//background freq correction
bool tempchart_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_date_time date_time = watch_rtc_get_date_time();

    //Updating data every 5 minutes
    return date_time.unit.minute % 5 == 0;
}
