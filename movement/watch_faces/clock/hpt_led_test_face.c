/*
 * MIT License
 *
 * Copyright (c) 2024 <#author_name#>
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
#include "hpt_led_test_face.h"
#include <inttypes.h>

void hpt_led_test_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr)
{
    (void)settings;
    (void)watch_face_index;
    if (*context_ptr == NULL)
    {
        *context_ptr = malloc(sizeof(hpt_led_test_state_t));
        memset(*context_ptr, 0, sizeof(hpt_led_test_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
        hpt_led_test_state_t *state = (hpt_led_test_state_t *)context_ptr;
        state->face_idx = watch_face_index;
        state->leds_off = false;
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void hpt_led_test_face_activate(movement_settings_t *settings, void *context)
{
    (void)settings;
    hpt_led_test_state_t *state = (hpt_led_test_state_t *)context;

    watch_enable_leds();
    movement_hpt_request_face(state->face_idx);

    movement_request_tick_frequency(2);
    //movement_hpt_schedule_face(movement_hpt_get() + 2048, state->face_idx);


    // Handle any tasks related to your watch face coming on screen.
}

bool hpt_led_test_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    hpt_led_test_state_t *state = (hpt_led_test_state_t *)context;

    uint8_t tick;

    switch (event.event_type)
    {
    case EVENT_ACTIVATE:
        // Show your initial UI here.
        break;
    case EVENT_LIGHT_BUTTON_DOWN:
        state->leds_off = true;
        
        movement_hpt_schedule(movement_hpt_get() + 2048);
        break;
    case EVENT_TICK:
        //If needed, update your display here.
        printf("ft:%" PRIu64 "\r\n", movement_hpt_get());

        if (state->leds_off == true)
        {
            watch_set_led_off();
        }
        else
        {
            if (((movement_hpt_get() / 512) % 2) == 0)
            {
                watch_set_led_green();
            }
            else
            {
                watch_set_led_red();
            }
        }
        break;
    case EVENT_HPT:
        state->leds_off = false;
        printf("fe:%" PRIu64 "\r\n", movement_hpt_get());
        break;
    case EVENT_ALARM_BUTTON_UP:
        // Just in case you have need for another button.
        break;
    case EVENT_TIMEOUT:
        // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
        // you may uncomment this line to move back to the first watch face in the list:
        // movement_move_to_face(0);
        break;
    case EVENT_LOW_ENERGY_UPDATE:
        // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
        // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
        // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
        // watch_start_tick_animation(500);
        break;
    default:
        // Movement's default loop handler will step in for any cases you don't handle above:
        // * EVENT_LIGHT_BUTTON_DOWN lights the LED
        // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
        // * EVENT_MODE_LONG_PRESS returns to the first watch face (or skips to the secondary watch face, if configured)
        // You can override any of these behaviors by adding a case for these events to this switch statement.
        return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void hpt_led_test_face_resign(movement_settings_t *settings, void *context)
{
    (void)settings;
        hpt_led_test_state_t *state = (hpt_led_test_state_t *)context;

    // handle any cleanup before your watch face goes off-screen.
    movement_hpt_relenquish_face(state->face_idx);
}
