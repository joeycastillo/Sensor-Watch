/*
 * MIT License
 *
 * Copyright (c) 2023 Curtis J. Brown <mrbrown8@juno.com>
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
#include "decimal_time_face.h"
#include "watch.h"



void decimal_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    // These next two lines just silence the compiler warnings associated with unused parameters.
    // We have no use for the settings or the watch_face_index, so we make that explicit here.
    (void) settings;
    (void) watch_face_index;
    (void) context_ptr;
    // At boot, context_ptr will be NULL indicating that we don't have anyplace to store our context.
    if (*context_ptr == NULL) {
        // in this case, we allocate an area of memory sufficient to store the stuff we need to track.
        *context_ptr = malloc(sizeof(decimal_time_face_state_t));
        decimal_time_face_state_t *state = (decimal_time_face_state_t *)*context_ptr;
        state->chime_enabled = false;
        state->features_to_show = 0 ;
    }


}


void decimal_time_face_activate(movement_settings_t *settings, void *context) {

    // same as above: silence the warning, we don't need to check the settings.
    (void) settings;

    // we do however need to set some things in our context. Here we cast it to the correct type...
    decimal_time_face_state_t *state = (decimal_time_face_state_t *)context;

    watch_set_indicator(WATCH_INDICATOR_24H);  // This face is always 24h, so just set the indicators
    watch_clear_indicator(WATCH_INDICATOR_PM);

    if (state->chime_enabled) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    }


}



bool decimal_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {

    (void) settings;
    decimal_time_face_state_t *state = (decimal_time_face_state_t *)context;

    char buf[16];
    uint8_t centihours, decimal_seconds;
    watch_date_time date_time;
    
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            // on activate and tick
            
            date_time = watch_rtc_get_date_time();
            
            centihours = (( date_time.unit.minute * 60 + date_time.unit.second ) * 100 ) / 3600;  // Integer division, fractions get dropped, no need for abs() (bonus)

            decimal_seconds = ( date_time.unit.minute * 60 + date_time.unit.second ) % 36 ;
            
            switch (state->features_to_show) {
                case 0:
                    sprintf( buf, "dT  %02d%02d  ",                       date_time.unit.hour, centihours );
                    break;
                case 1:
                    sprintf( buf, "dT  %02d%02d%2d",                      date_time.unit.hour, centihours, decimal_seconds );
                    break;
                case 2:
                    sprintf( buf, "dT%2d%02d%02d  ",  date_time.unit.day, date_time.unit.hour, centihours );
                    break;
                case 3:
                    sprintf( buf, "dT%2d%02d%02d%2d", date_time.unit.day, date_time.unit.hour, centihours, decimal_seconds );
                    break;
            }

            watch_display_string(buf, 0);  // display calculated time
            
            // at the top of every hour...
            if (date_time.unit.minute == 0 && date_time.unit.second == 0 && state->chime_enabled) {
                watch_set_indicator(WATCH_INDICATOR_SIGNAL);
                watch_buzzer_play_note(BUZZER_NOTE_E6, 75);
                watch_buzzer_play_note(BUZZER_NOTE_REST, 15);
                watch_buzzer_play_note(BUZZER_NOTE_E6, 75);
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            }
            
            break;

        case EVENT_ALARM_LONG_PRESS:   
            state->chime_enabled = !state->chime_enabled;   // just like from simple_watch_face
            if (state->chime_enabled) 
                watch_set_indicator(WATCH_INDICATOR_BELL);
            else
                watch_clear_indicator(WATCH_INDICATOR_BELL);
            break;

        case EVENT_ALARM_BUTTON_UP:
            state->features_to_show += 1 ;  // cycle thru what's to be shown
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
            //movement_move_to_face(0);
            break;

        default:
            movement_default_loop_handler(event, settings);
            break;

    }

    return true;
}

void decimal_time_face_resign(movement_settings_t *settings, void *context) {
    // our watch face, like most watch faces, has nothing special to do when resigning.
    // there are no peripherals or sensors here to worry about turning off.
    (void) settings;
    (void) context;

}


// void decimal_time_face_wants_background_task() {
// 
// }











