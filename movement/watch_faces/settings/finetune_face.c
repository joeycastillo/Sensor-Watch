/*
 * MIT License
 *
 * Copyright (c) 2022 Mikhail Svarichevsky https://3.14.by/
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
#include "finetune_face.h"
#include "nanosec_face.h"
#include "watch_utility.h"

extern nanosec_state_t nanosec_state;

int total_adjustment;
int8_t finetune_page;

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
    finetune_page = 0;
}

static float finetune_get_hours_passed(void) {
    uint32_t current_time = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), 0);
    return (current_time - nanosec_state.last_correction_time) / 3600.0f;
}

static float finetune_get_correction(void) {
    return total_adjustment / (finetune_get_hours_passed() * 3600.0f) * 1000.0f;
}

static void finetune_update_display(void) {
    char buf[25];

    if (finetune_page == 0) {
        watch_display_string("FT", 0);
        watch_date_time date_time = watch_rtc_get_date_time();
        sprintf(buf, "%02d", date_time.unit.second);
        watch_display_string(buf, 8);

        sprintf(buf, "%04d", abs(total_adjustment));
        watch_display_string(buf, 4);

        if (total_adjustment < 0) {
            watch_display_string("--", 2);
        } else {
            watch_display_string("  ", 2);
        }
    } else if (finetune_page == 1) {
        float hours = finetune_get_hours_passed();

        sprintf(buf, "DT  %4d%02d", (int)hours, (int)(fmodf(hours, 1.) * 100));
        watch_display_string(buf, 0);
    } else if (finetune_page == 2) {
        if (finetune_get_hours_passed() < 6) {
            sprintf(buf, " F  6HR   ");
            watch_display_string(buf, 0);
        } else {
            float correction = finetune_get_correction();
            sprintf(buf, " F%s%2d%04d", (total_adjustment < 0) ? " -" : "  ", (int)fabsf(correction), (int)(remainderf(fabsf(correction), 1.) * 10000));
            watch_display_string(buf, 0);
        }
    }
}

static void finetune_adjust_subseconds(int delta) {
    // Update display first ot make it appear faster for the user
    if (delta > 500)
        total_adjustment += (delta - 1000);
    else
        total_adjustment += delta;
    finetune_update_display();

    // Then delay clock
    watch_rtc_enable(false);
    delay_ms(delta);
    if (delta > 500) {
        watch_date_time date_time = watch_rtc_get_date_time();
        date_time.unit.second = (date_time.unit.second + 1) % 60;
        if (date_time.unit.second == 0) { // Overflow
            date_time.unit.minute = (date_time.unit.minute + 1) % 60;
            if (date_time.unit.minute == 0) { // Overflow
                date_time.unit.hour = (date_time.unit.hour + 1) % 24;
                if (date_time.unit.hour == 0) // Overflow
                    date_time.unit.day++;
            }
        }
        watch_rtc_set_date_time(date_time);
    }
    watch_rtc_enable(true);
}

static void finetune_update_correction_time(void) {
    // Update aging, as we update correciton time - we must bake accrued aging into static offset
    nanosec_state.freq_correction += roundf(nanosec_get_aging() * 100);

    // Remember when we last corrected time
    nanosec_state.last_correction_time = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), 0);
    nanosec_save();
    movement_move_to_face(0); // Go to main face after saving settings
}

bool finetune_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {

    (void) settings;
    (void) context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            finetune_update_display();
            break;

        case EVENT_TICK:
            // If needed, update your display here, at canonical 0.5sec position.
            // We flash green LED once per minute to measure clock error, when we are not on first screen
            if (finetune_page!=0) {
                watch_date_time date_time;
                date_time = watch_rtc_get_date_time();
                if (date_time.unit.second == 0) {
                    watch_set_led_green();
                    #ifndef __EMSCRIPTEN__
                    delay_us(500);
                    #endif
                    watch_set_led_off();
                }
            }

            finetune_update_display();
            break;

        case EVENT_MODE_BUTTON_UP:
            // Only allow for fast exit when correction is 0!!!
            if (finetune_page == 0 && total_adjustment == 0) {
                movement_move_to_next_face();
            } else {
                finetune_page = (finetune_page + 1) % 3;
                finetune_update_display();
            }
            break;

        case EVENT_MODE_LONG_PRESS:
            // You shouldn't need to change this case; Mode almost always moves to the next watch face.
            finetune_page = (finetune_page + 1) % 3;
            finetune_update_display();
            break;

        case EVENT_LIGHT_LONG_PRESS:
            // We are making it slower by 250ms
            if (finetune_page == 0) {
                finetune_adjust_subseconds(250);
            } else if (finetune_page == 2 && finetune_get_hours_passed() >= 6) {
                // Applying ppm correction, only if >6 hours passed
                nanosec_state.freq_correction += (int)round(finetune_get_correction() * 100);
                finetune_update_correction_time();
            }
            break;

        case EVENT_LIGHT_BUTTON_UP:
            // We are making it slower by 25ms
            if (finetune_page == 0) {
                finetune_adjust_subseconds(25);
            }
            break;

        case EVENT_ALARM_LONG_PRESS:
            if (finetune_page == 0) {
                finetune_adjust_subseconds(750);
            } else if (finetune_page == 2) {
                // Exit without applying correction to ppm, but update correction time
                finetune_update_correction_time();
            }
            break;

        case EVENT_ALARM_BUTTON_UP:
            if (finetune_page == 0) {
                finetune_adjust_subseconds(975);
            }
            break;

        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            if (total_adjustment == 0) // Timeout only works if no adjustment was made
                movement_move_to_face(0);
            break;

        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;

        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void finetune_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    if (total_adjustment != 0) {
        finetune_update_correction_time();
    }
}
