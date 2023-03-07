/*
 * MIT License
 *
 * Copyright (c) 2022 CC
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
#include "lightmeter_face.h"
#include "watch_utility.h"
#include "watch_slcd.h"

void lightmeter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    //lightmeter_state_t *state = (lightmeter_state_t *)*context_ptr;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(lightmeter_state_t));
        memset(*context_ptr, 0, sizeof(lightmeter_state_t));
        //state = (lightmeter_state_t *)*context_ptr;
    }
}

void lightmeter_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_enable_i2c();
}

bool indstate = false; 

bool lightmeter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    //lightmeter_state_t *state = lightmeter_state_t *context;
    
    opt3001_Config_t c;
    char strbuff[8];
    uint16_t res;
    switch (event.event_type) {
        case EVENT_TICK:
            c = opt3001_readConfig(lightmeter_addr);
            if(c.ConversionReady) {
                opt3001_t result = opt3001_readResult(lightmeter_addr);
                watch_clear_all_indicators();
                watch_display_string("          ", 0); // Clear display
                //res = max(min(log2(result.lux/2.5), 99), -99);
                res = round(max(min(result.lux, 100000), 0));
                sprintf(strbuff, "%6i", res);
                watch_display_string(strbuff,4);
            } else if(!indstate) {
                watch_set_indicator(WATCH_INDICATOR_SIGNAL); 
                indstate = !indstate;
            } else {
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL); 
                indstate = !indstate;
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            opt3001_writeConfig(lightmeter_addr, lightmeter_takeNewReading);
            watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            indstate = 1;
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }
    return true;
}

void lightmeter_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    //lightmeter_state_t *state = (lightmeter_state_t *)context;
    opt3001_writeConfig(lightmeter_addr, lightmeter_off);
    watch_disable_i2c();
    return;
}
