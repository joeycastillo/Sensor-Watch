/*
 * MIT License
 *
 * Copyright (c) 2023 PrimmR
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

#ifndef KITCHEN_CONVERSIONS_FACE_H_
#define KITCHEN_CONVERSIONS_FACE_H_

#include "movement.h"

/*
 * Kitchen Conversions
 * A face that allows the user to convert between common kitchen units of measurement
 *
 * How to use
 * ----------
 * Short press the alarm button to move forward through menus, and long press to move backwards
 *
 * Press the light button to cycle through options in the menus
 *
 * When inputting a number, the light button moves forward one place and the alarm button increments a digit by one
 *
 * To convert between Imperial (GB) and US (A) measurements of volume, hold the light button
 *
 */

#define SCREEN_NUM 5

// Names of each page
typedef enum
{
    measurement,
    from,
    to,
    input,
    result,
} page_t;

#define DISPLAY_DIGITS 6

// Settings when app is running
typedef struct
{
    page_t pg;
    uint8_t measurement_i;
    uint8_t from_i;
    bool from_is_us;
    uint8_t to_i;
    bool to_is_us;
    uint32_t selection_value;
    uint8_t selection_index;
    bool light_held;
} kitchen_conversions_state_t;

void kitchen_conversions_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void kitchen_conversions_face_activate(movement_settings_t *settings, void *context);
bool kitchen_conversions_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void kitchen_conversions_face_resign(movement_settings_t *settings, void *context);

#define kitchen_conversions_face ((const watch_face_t){ \
    kitchen_conversions_face_setup,                     \
    kitchen_conversions_face_activate,                  \
    kitchen_conversions_face_loop,                      \
    kitchen_conversions_face_resign,                    \
    NULL,                                               \
})

#endif // KITCHEN_CONVERSIONS_FACE_H_
