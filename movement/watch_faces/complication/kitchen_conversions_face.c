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

#include <stdlib.h>
#include <string.h>
#include "kitchen_conversions_face.h"

typedef struct
{
    char name[6];          // Name to display on selection
    double conv_factor_uk; // Unit as represented in base units (UK)
    double conv_factor_us; // Unit as represented in base units (US)
    int16_t linear_factor; // Addition of constant (For temperatures)
} unit;

#define TICK_FREQ 4

#define MEASURES_COUNT 3 // Number of different measurement 'types'
#define WEIGHT 0
#define TEMP 1
#define VOL 2

// Names of measurements
static char measures[MEASURES_COUNT][6] = {"WeIght", " Temp", " VOL"};

// Number of items in each category
#define WEIGHT_COUNT 4
#define TEMP_COUNT 3
#define VOL_COUNT 9
const uint8_t units_count[4] = {WEIGHT_COUNT, TEMP_COUNT, VOL_COUNT};

static const unit weights[WEIGHT_COUNT] = {
    {" g", 1., 1., 0}, // BASE
    {" kg", 1000., 1000, 0},
    {"Ounce", 28.34952, 28.34952, 0},
    {" Pound", 453.5924, 453.5924, 0},
};

static const unit temps[TEMP_COUNT] = {
    {" # C", 1.8, 1.8, 32},
    {" # F", 1., 1., 0}, // BASE
    {"Gas Mk", 25., 25., 250},
};

static const unit vols[VOL_COUNT] = {
    {"  n&L", 1., 1., 0}, // BASE (ml)
    {"   L", 1000., 1000., 0},
    {" Fl Oz", 28.41306, 29.57353, 0},
    {" Tbsp", 17.75816, 14.78677, 0},
    {" Tsp", 5.919388, 4.928922, 0},
    {"  Cup", 284.1306, 236.5882, 0},
    {" Pint", 568.2612, 473.1765, 0},
    {" Quart", 1136.522, 946.353, 0},
    {"Gallon", 4546.09, 3785.412, 0},
};

static int8_t calc_success_seq[5] = {BUZZER_NOTE_G6, 10, BUZZER_NOTE_C7, 10, 0};
static int8_t calc_fail_seq[5] = {BUZZER_NOTE_C7, 10, BUZZER_NOTE_G6, 10, 0};

// Resets all state variables to 0
static void reset_state(kitchen_conversions_state_t *state, movement_settings_t *settings)
{
    state->pg = measurement;
    state->measurement_i = 0;
    state->from_i = 0;
    state->from_is_us = settings->bit.use_imperial_units; // If uses imperial, most likely to be US
    state->to_i = 0;
    state->to_is_us = settings->bit.use_imperial_units;
    state->selection_value = 0;
    state->selection_index = 0;
    state->light_held = false;
}

void kitchen_conversions_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr)
{
    (void)settings;
    (void)watch_face_index;
    if (*context_ptr == NULL)
    {
        *context_ptr = malloc(sizeof(kitchen_conversions_state_t));
        memset(*context_ptr, 0, sizeof(kitchen_conversions_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void kitchen_conversions_face_activate(movement_settings_t *settings, void *context)
{
    (void)settings;
    kitchen_conversions_state_t *state = (kitchen_conversions_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
    movement_request_tick_frequency(TICK_FREQ);

    reset_state(state, settings);
}

// Increments index pointer by 1, wrapping
#define increment_wrapping(index, wrap) ({(index)++; index %= wrap; })

static uint32_t pow_10(uint8_t n)
{
    uint32_t result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= 10;
    }
    return result;
}

// Returns correct list of units for the measurement index
static unit *get_unit_list(uint8_t measurement_i)
{
    switch (measurement_i)
    {
    case WEIGHT:
        return (unit *)weights;

    case TEMP:
        return (unit *)temps;

    case VOL:
        return (unit *)vols;

    default:
        return (unit *)weights;
    }
}

// Increment digit by 1 in input (wraps)
static void increment_input(kitchen_conversions_state_t *state)
{
    uint8_t digit = state->selection_value / pow_10(DISPLAY_DIGITS - 1 - state->selection_index) % 10;
    if (digit != 9)
    {
        state->selection_value += pow_10(DISPLAY_DIGITS - 1 - state->selection_index);
    }
    else
    {
        state->selection_value -= 9 * pow_10(DISPLAY_DIGITS - 1 - state->selection_index);
    }
}

// Displays the list of units in the selected category
static void display_units(uint8_t measurement_i, uint8_t list_i)
{
    watch_display_string(get_unit_list(measurement_i)[list_i].name, 4);
}

static void display(kitchen_conversions_state_t *state, movement_settings_t *settings, uint8_t subsec)
{
    watch_clear_display();

    switch (state->pg)
    {
    case measurement:
    {
        watch_display_string("Un", 0);
        watch_display_string(measures[state->measurement_i], 4);
    }
    break;

    case from:
        display_units(state->measurement_i, state->from_i);

        // Display Fr if non-locale specific, else display locale and F
        if (state->measurement_i == VOL)
        {
            watch_display_string("F", 3);

            char *locale = state->from_is_us ? "A " : "GB";
            watch_display_string(locale, 0);
        }
        else
        {
            watch_display_string("Fr", 0);
        }

        break;

    case to:
        display_units(state->measurement_i, state->to_i);

        // Display To if non-locale specific, else display locale and T
        if (state->measurement_i == VOL)
        {
            watch_display_string("T", 3);

            char *locale = state->to_is_us ? "A " : "GB";
            watch_display_string(locale, 0);
        }
        else
        {
            watch_display_string("To", 0);
        }

        break;

    case input:
    {
        char buf[7];
        sprintf(buf, "%06lu", state->selection_value);
        watch_display_string(buf, 4);

        // Only allow ints for Gas Mk
        if (state->measurement_i == TEMP && state->from_i == 2)
        {
            watch_display_string("  ", 8);
        }

        // Blink digit (on & off) twice a second
        if (subsec % 2)
        {
            watch_display_string(" ", 4 + state->selection_index);
        }

        watch_display_string("In", 0);
    }
    break;

    case result:
    {
        unit froms = get_unit_list(state->measurement_i)[state->from_i];
        unit tos = get_unit_list(state->measurement_i)[state->to_i];
        // Chooses correct factor for locale
        double f_conv_factor = state->from_is_us ? froms.conv_factor_us : froms.conv_factor_uk;
        double t_conv_factor = state->to_is_us ? tos.conv_factor_us : tos.conv_factor_uk;
        // Converts
        double to_base = (state->selection_value * f_conv_factor) + 100 * froms.linear_factor;
        double conversion = ((to_base - 100 * tos.linear_factor) / t_conv_factor);

        // If number too large or too small
        uint8_t lower_bound = (state->measurement_i == TEMP && state->to_i == 2) ? 100 : 0;
        if (conversion >= 1000000 || conversion < lower_bound)
        {
            watch_set_indicator(WATCH_INDICATOR_BELL);
            watch_display_string("Err", 5);

            if (settings->bit.button_should_sound)
                watch_buzzer_play_sequence(calc_fail_seq, NULL);
        }
        else
        {
            uint32_t rounded = conversion + .5;
            char buf[7];
            sprintf(buf, "%6lu", rounded);
            watch_display_string(buf, 4);

            // Make sure LSDs always filled
            if (rounded < 10)
            {
                watch_display_string("00", 7);
            }
            else if (rounded < 100)
            {
                watch_display_string("0", 7);
            }

            if (settings->bit.button_should_sound)
                watch_buzzer_play_sequence(calc_success_seq, NULL);
        }
        watch_display_string("=", 1);
    }

    break;

    default:
        break;
    }
}

bool kitchen_conversions_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    kitchen_conversions_state_t *state = (kitchen_conversions_state_t *)context;

    switch (event.event_type)
    {
    case EVENT_ACTIVATE:
        // Initial UI
        display(state, settings, event.subsecond);
        break;
    case EVENT_TICK:
        // Update for blink animation on input
        if (state->pg == input)
        {
            display(state, settings, event.subsecond);

            // Increments input twice a second when light button held
            if (state->light_held && event.subsecond % 2)
                increment_input(state);
        }
        break;
    case EVENT_LIGHT_BUTTON_UP:
        // Cycles options
        switch (state->pg)
        {
        case measurement:
            increment_wrapping(state->measurement_i, MEASURES_COUNT);
            break;

        case from:
            increment_wrapping(state->from_i, units_count[state->measurement_i]);
            break;

        case to:
            increment_wrapping(state->to_i, units_count[state->measurement_i]);
            break;

        case input:
            increment_input(state);
            break;

        default:
            break;
        }

        // Light button does nothing on final screen
        if (state->pg != result)
            display(state, settings, event.subsecond);

        state->light_held = false;

        break;

    case EVENT_ALARM_BUTTON_UP:
        // Increments selected digit
        if (state->pg == input)
        {

            // Moves between digits in input
            // Wraps at 6 digits unless gas mark selected
            if (state->selection_index < (DISPLAY_DIGITS - 1) - 2 * (state->measurement_i == TEMP && state->from_i == 2))
            {
                state->selection_index++;
            }
            else
            {
                state->pg++;
                display(state, settings, event.subsecond);
            }
        }
        // Moves forward 1 page
        else
        {
            if (state->pg == SCREEN_NUM - 1)
            {
                reset_state(state, settings);
            }
            else
            {
                state->pg++;
            }

            // Play boop
            if (settings->bit.button_should_sound)
                watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
        }

        display(state, settings, event.subsecond);

        state->light_held = false;

        break;

    case EVENT_ALARM_LONG_PRESS:
        // Moves backwards through pages, resetting certain values
        if (state->pg != measurement)
        {
            switch (state->pg)
            {
            case measurement:
                state->measurement_i = 0;
                break;

            case from:
                state->from_i = 0;
                state->from_is_us = settings->bit.use_imperial_units;
                break;

            case to:
                state->to_i = 0;
                state->to_is_us = settings->bit.use_imperial_units;
                break;

            case input:
                state->selection_index = 0;
                state->selection_value = 0;
                break;

            case result:
                state->selection_index = 0;
                break;

            default:
                break;
            }

            state->pg--;
            display(state, settings, event.subsecond);

            // Play beep
            if (settings->bit.button_should_sound)
                watch_buzzer_play_note(BUZZER_NOTE_C8, 50);

            state->light_held = false;
        }
        break;

    case EVENT_LIGHT_LONG_PRESS:
        // Switch between locales
        if (state->measurement_i == VOL)
        {
            if (state->pg == from)
            {
                state->from_is_us = !state->from_is_us;
            }
            else if (state->pg == to)
            {
                state->to_is_us = !state->to_is_us;
            }

            if (state->pg == from || state->pg == to)
            {
                display(state, settings, event.subsecond);

                // Play bleep
                if (settings->bit.button_should_sound)
                    watch_buzzer_play_note(BUZZER_NOTE_E7, 50);
            }
        }

        // Sets flag to increment input digit when light held
        if (state->pg == input)
            state->light_held = true;

        break;

    case EVENT_LIGHT_LONG_UP:
        state->light_held = false;
        break;

    case EVENT_TIMEOUT:
        movement_move_to_face(0);
        break;

    default:
        return movement_default_loop_handler(event, settings);
    }

    return true;
}

void kitchen_conversions_face_resign(movement_settings_t *settings, void *context)
{
    (void)settings;
    (void)context;

    // handle any cleanup before your watch face goes off-screen.
}
