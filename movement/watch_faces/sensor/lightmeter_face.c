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

uint16_t lightmeter_mod(uint16_t m, uint16_t n) { return (m%n + n)%n; }  

void lightmeter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(lightmeter_state_t));
        lightmeter_state_t *state = (lightmeter_state_t*) *context_ptr;
        state->waiting_for_conversion = 0;
        state->lux = 0.0;
        state->mode = 0;
        state->iso = LIGHTMETER_ISO_100;
        state->ap = LIGHTMETER_AP_4P0;
    }
}

void lightmeter_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    lightmeter_state_t *state = (lightmeter_state_t*) context;
    state->waiting_for_conversion = 0;
    lightmeter_show_ev(state); // Print most current reading
    watch_enable_i2c();
    return;
}

void lightmeter_show_ev(lightmeter_state_t *state) {

    float ev = max(min(
                 log2(state->lux) + 
                 lightmeter_isos[state->iso].ev + 
                 LIGHTMETER_CALIBRATION,
            99), -9);
    int evt = round(2*ev); // Truncated EV

    // Print EV
    char strbuff[7];
    watch_clear_all_indicators();
    watch_display_string("EV        ", 0); 

    sprintf(strbuff, "%2i", (uint16_t) abs(evt/2)); // Print whole part of EV 
    watch_display_string(strbuff, 2); 
    if(evt%2) watch_set_indicator(WATCH_INDICATOR_LAP); // Indicate half stop
    if(ev<0) watch_set_pixel(1,9);  // Indicate negative EV

    // Handle lux mode
    if(state->mode == 1) {
        sprintf(strbuff, "%6.0f", min(state->lux, 999999.0)); 
        watch_display_string(strbuff, 4); 
        return;
    }

    // Find and print best shutter speed
    uint16_t bestsh = 0;
    float besterr = 1.0/0.0;
    float errbuf = 1.0/0.0;
    float comp_ev = ev + lightmeter_aps[state->ap].ev; 
    for(uint16_t ind = 2; ind < LIGHTMETER_N_SHS; ind++) {
        errbuf = comp_ev + lightmeter_shs[ind].ev;
        if( fabs(errbuf) < fabs(besterr)) {
            besterr = errbuf;
            bestsh = ind;
        }
    }
    if(besterr >= 0.5) watch_display_string(lightmeter_shs[LIGHTMETER_SH_HIGH].str, 4); 
    else if(besterr <= -0.5) watch_display_string(lightmeter_shs[LIGHTMETER_SH_LOW].str, 4); 
    else watch_display_string(lightmeter_shs[bestsh].str, 4); 

    // Print aperture
    watch_display_string(lightmeter_aps[state->ap].str, 7); 
    return;
}

bool lightmeter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    lightmeter_state_t *state = (lightmeter_state_t*) context;
    
    opt3001_Config_t c;
    switch (event.event_type) {
        case EVENT_TICK:
            if(state->waiting_for_conversion) { // Check if measurement is ready...
                c = opt3001_readConfig(lightmeter_addr);
                if(c.ConversionReady) {
                    state->waiting_for_conversion = 0;
                    opt3001_t result = opt3001_readResult(lightmeter_addr);
                    state->lux = result.lux;
                    lightmeter_show_ev(state); 
                } 
            }
            break;

        case EVENT_ALARM_BUTTON_UP: // Increment aperture 
            state->ap = lightmeter_mod(state->ap+1, LIGHTMETER_N_APS);

            lightmeter_show_ev(state); 
            break;

        case EVENT_LIGHT_BUTTON_UP: // Decrement aperture 
            if(state->ap == 0) state->ap = LIGHTMETER_N_APS-1; 
            else state->ap = lightmeter_mod(state->ap-1, LIGHTMETER_N_APS);

            lightmeter_show_ev(state); 
            break;

        case EVENT_LIGHT_LONG_PRESS: // Cycle ISO
            state->iso = lightmeter_mod(state->iso+1, LIGHTMETER_N_ISOS);

            watch_clear_all_indicators();
            watch_display_string("EV  ", 0); 
            watch_display_string(lightmeter_isos[state->iso].str, 4); 
            break;

        case EVENT_ALARM_LONG_PRESS: // Take measurement
            opt3001_writeConfig(lightmeter_addr, lightmeter_takeNewReading);
            state->waiting_for_conversion = 1;

            watch_clear_all_indicators();
            watch_display_string("EV  ", 0); 
            watch_display_string(lightmeter_isos[state->iso].str, 4); 
            watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            break;

        case EVENT_MODE_LONG_PRESS: // Toggle mode
            state->mode = !state->mode;
            lightmeter_show_ev(state); 
            break;

        case EVENT_TIMEOUT:
            movement_move_to_face(0);
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
    opt3001_writeConfig(lightmeter_addr, lightmeter_off);
    watch_disable_i2c();
    return;
}
