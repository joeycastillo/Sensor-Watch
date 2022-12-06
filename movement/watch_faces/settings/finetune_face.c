/*
 * MIT License
 *
 * Copyright (c) 2022 <#author_name#>
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
#include "finetune_face.h"

int total_adjustment; 

void finetune_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    (void) context_ptr;
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void finetune_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // Handle any tasks related to your watch face coming on screen.
    watch_display_string("FT", 0);
    total_adjustment = 0;
}

void finetune_adjust_subseconds(int delta)
{
    while (RTC->MODE2.SYNCBUSY.reg);
    RTC->MODE2.CTRLA.bit.ENABLE = 0;
    while (RTC->MODE2.SYNCBUSY.reg);
    delay_ms(delta);
    if(delta>500)
    {
       watch_date_time date_time = watch_rtc_get_date_time();
       date_time.unit.second=(date_time.unit.second+1)%60;
       watch_rtc_set_date_time(date_time);
        
       total_adjustment+=(delta-1000);    
    } else
        total_adjustment+=delta;
    while (RTC->MODE2.SYNCBUSY.reg);
    RTC->MODE2.CTRLA.bit.ENABLE = 1;
    while (RTC->MODE2.SYNCBUSY.reg);
}

bool finetune_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {

    (void) settings;
    (void) context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            break;
        case EVENT_TICK:
            // If needed, update your display here, at canonical 0.5sec position.
            {
                watch_date_time date_time = watch_rtc_get_date_time();
                char buf[11];
                sprintf(buf, "%02d", date_time.unit.second);
                watch_display_string(buf, 8);

                sprintf(buf, "%04d", abs(total_adjustment));
                watch_display_string(buf, 4);
                
                if(total_adjustment<0)
                    watch_display_string("--", 2);else
                    watch_display_string("  ", 2);
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            // You shouldn't need to change this case; Mode almost always moves to the next watch face.
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_LONG_PRESS:
            // We are making it faster by 250ms
            finetune_adjust_subseconds(750);
            break;

        case EVENT_LIGHT_BUTTON_UP:
            // We are making it faster by 25ms
            finetune_adjust_subseconds(975);
            break;
        
        case EVENT_ALARM_LONG_PRESS:
            // Just in case you have need for another button.
            finetune_adjust_subseconds(250);
            break;
        
        case EVENT_ALARM_BUTTON_UP:
            // Just in case you have need for another button.
            finetune_adjust_subseconds(25);
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        default:
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void finetune_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

