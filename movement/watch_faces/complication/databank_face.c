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
#include "databank_face.h"
#include "watch.h"
#include "watch_private_display.h"

const char *pi_data[] = {
    "PI", "314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442",
    "S ", "9192631770",
    "31", "2147483648",
    "32", "4294967296",
    "63", "9223372036854775808",
    "64", "18446744073709551616",
};
//we show 6 characters per screen

const int databank_num_pages = (sizeof(pi_data) / sizeof(char*) / 2);

struct {
    uint8_t current_word;
    uint8_t databank_page;
    bool animating;
} databank_state;

void databank_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    // These next two lines just silence the compiler warnings associated with unused parameters.
    // We have no use for the settings or the watch_face_index, so we make that explicit here.
    (void) settings;
    (void) context_ptr;
    (void) watch_face_index;
    // At boot, context_ptr will be NULL indicating that we don't have anyplace to store our context.
}

void databank_face_activate(movement_settings_t *settings, void *context) {
    // same as above: silence the warning, we don't need to check the settings.
    (void) settings;
    (void) context;
    // we do however need to set some things in our context. Here we cast it to the correct type...
    databank_state.current_word = 0;
    databank_state.animating = true;
}

static void display()
{
    char buf[14];
    int page = databank_state.current_word;
    sprintf(buf, "%s%2d", pi_data[databank_state.databank_page * 2 + 0], page);
    watch_display_string(buf, 0);
    bool data_ended = false;
    for (int i = 0; i < 6; i++) {
        if (pi_data[databank_state.databank_page * 2 + 1][page * 6 + i] == 0) {
            data_ended = true;
        }

        if (!data_ended) {
            watch_display_character(pi_data[databank_state.databank_page * 2 + 1][page * 6 + i], 4 + i);
        } else {
            // only 6 digits per page
            watch_display_character(' ', 4 + i);
        }
    }
}

bool databank_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    int max_words = (strlen(pi_data[databank_state.databank_page * 2 + 1]) - 1) / 6 + 1;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
             display();
        case EVENT_TICK:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            databank_state.current_word = (databank_state.current_word + max_words - 1) % max_words;
            display();
            break;
        case EVENT_LIGHT_LONG_PRESS:
            databank_state.databank_page = (databank_state.databank_page + databank_num_pages - 1) % databank_num_pages;
            databank_state.current_word = 0;
            display();
            break;
        case EVENT_ALARM_LONG_PRESS:
            databank_state.databank_page = (databank_state.databank_page + 1) % databank_num_pages;
            databank_state.current_word = 0;
            display();
            break;
        case EVENT_ALARM_BUTTON_UP:
            databank_state.current_word = (databank_state.current_word + 1) % max_words;
            display();
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
        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void databank_face_resign(movement_settings_t *settings, void *context) {
    // our watch face, like most watch faces, has nothing special to do when resigning.
    // watch faces that enable a peripheral or interact with a sensor may want to turn it off here.
    (void) settings;
    (void) context;
}
