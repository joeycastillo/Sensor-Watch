/*
 * MIT License
 *
 * Copyright (c) 2022 Navaneeth Bhardwaj
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
#include "milk_log_face.h"
#include <math.h>

/*
    UI Notes
    * Home screen displays the total milk purchased in litres
    * Light shows the outstanding amount in Rs (total_litres x price_per_litre) for a few ticks
    * Alarm long press starts the edit mode for the log entry
        * Light advances the value by 0.5l
        * Alram decreases the value by 0.5l
        * Mode enters the value into the log and exits the edit mode
*/

#define PRICE_PER_LITRE     (50)    //Rs

/*Private Functions*/
static void _milk_log_face_update_display(movement_settings_t *settings, milk_log_state_t *logger_state) {
    (void) settings;
    char buf[12];
    uint16_t outstanding_amt = ceilf(logger_state->consumption*logger_state->price_per_litre);

    switch(logger_state->curr_view) {
        case SUMMARY_VIEW:
            sprintf(buf, "ML   %2.1fL ", logger_state->consumption);
            break;
        case LOG_ENTRY_VIEW:
            if(logger_state->new_log_entry >=0)
                sprintf(buf, "Ad   %2.1fL ", logger_state->new_log_entry);
            else
                sprintf(buf, "Ad  %2.1fL ", logger_state->new_log_entry);
            break;
        case OUTSTANDING_AMT_VIEW:
            sprintf(buf, "ML  %4drs", outstanding_amt);
            break;
        default: break;
    }
    watch_display_string(buf, 0);
}

/*Public Functions*/
void milk_log_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(milk_log_state_t));
        memset(*context_ptr, 0, sizeof(milk_log_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void milk_log_face_activate(movement_settings_t *settings, void *context) {
    // Handle any tasks related to your watch face coming on screen.
    (void) settings;
    milk_log_state_t *logger_state = (milk_log_state_t *)context;
    logger_state->ts_ticks = 0;
    logger_state->curr_view = SUMMARY_VIEW;
    logger_state->price_per_litre = PRICE_PER_LITRE;
}

bool milk_log_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    milk_log_state_t *logger_state = (milk_log_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            _milk_log_face_update_display(settings, logger_state);
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            if (logger_state->ts_ticks && --logger_state->ts_ticks == 0) {
                logger_state->curr_view = SUMMARY_VIEW;
            }
            _milk_log_face_update_display(settings, logger_state);
            break;
        case EVENT_MODE_BUTTON_UP:
            if(logger_state->curr_view == LOG_ENTRY_VIEW) {
                logger_state->consumption += logger_state->new_log_entry;
                logger_state->new_log_entry = 0.0f;
                logger_state->curr_view = SUMMARY_VIEW;
                _milk_log_face_update_display(settings, logger_state);
            }else {
                movement_move_to_next_face();
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            // light button shows the outstanding amount, but if you need the light, long press it.
            movement_illuminate_led();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // Briefly show the amount from the summary view
            if(logger_state->curr_view == SUMMARY_VIEW) {
                logger_state->ts_ticks = OUTSTANDING_AMOUnT_VIEW_TIMEOUT;
                logger_state->curr_view = OUTSTANDING_AMT_VIEW;
                _milk_log_face_update_display(settings, logger_state);
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if(logger_state->curr_view == LOG_ENTRY_VIEW) {
                logger_state->new_log_entry -= 0.5f;
                _milk_log_face_update_display(settings, logger_state);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if(logger_state->curr_view == LOG_ENTRY_VIEW) {
                logger_state->consumption = 0;
                logger_state->curr_view = SUMMARY_VIEW;
            }
            else {
                logger_state->curr_view = LOG_ENTRY_VIEW;
            }
            _milk_log_face_update_display(settings, logger_state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            if(logger_state->curr_view == LOG_ENTRY_VIEW) {
                logger_state->new_log_entry += 0.5f;
                _milk_log_face_update_display(settings, logger_state);
            }
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

void milk_log_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

