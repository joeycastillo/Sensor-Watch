/*
 * MIT License
 *
 * Copyright © 2024 Constantin Buschmeyer /metrast (github)
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
#include "beer_counter_face.h"
#include "watch.h"
#include "watch_utility.h"

#define BEER_VOLUME_ML 500
#define BEER_ALCOHOL_PERCENT 0.05
#define ALCOHOL_DENSITY 0.789  // g/ml
#define ELIMINATION_RATE 0.15f // Average elimination rate (g/kg/hour)
#define RESORPTION_DEFICIT 0.9 // 100% - 10%
/* resorption deficit is between 10% and 30% depending on enzyme activity, 
 * filling of the stomach, concentration of alcohol in different beverages, etc.
 * here it is chosen to be on the safer side, so that the probability for sobriety is higher
 * when sobertime reaches 0.
 */

static bool quick_ticks_running = false;

static void print_sober_time(beer_counter_state_t *state);
//static uint32_t calculate_time_to_sober(float current_bac);
static void abort_quick_ticks(void);

static void abort_quick_ticks(void) {
    if (quick_ticks_running) {
        quick_ticks_running = false;
        movement_request_tick_frequency(4);
    }
}

// Setup function
void beer_counter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void)settings;
    (void)watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(beer_counter_state_t));
        memset(*context_ptr, 0, sizeof(beer_counter_state_t));
        beer_counter_state_t *state = (beer_counter_state_t *)*context_ptr;
        state->weight = 30;  // Default weight in kg (you can modify this as needed)
        state->height = 130; //Default height in cm
        state->sex = 0;    // Default sex (0 for male, 1 for female)
        state->is_bac_screen = false;  // Start with beer count screen
        state->is_weight_screen = false;  // Initialize the weight screen flag
        state->is_height_screen = false; //Initialize the weight screen flag
        state->is_sex_screen = false;  // Initialize the sex screen flag
        state->is_sober_screen = false;   // Initialize the sober screen flag
        state->beer_count = 0; // Initialize beer count
    }
}

// Activate function
void beer_counter_face_activate(movement_settings_t *settings, void *context) {
    (void)settings;
    movement_request_tick_frequency(4);
    quick_ticks_running = false;
    watch_set_led_off(); // Ensure LED is off when activating the face

    // Get the current date and time
    watch_date_time now = watch_rtc_get_date_time();
    uint32_t current_time_unix = watch_utility_date_time_to_unix_time(now, 0);
    beer_counter_state_t *state = (beer_counter_state_t *)context;
    //state->last_time = current_time_unix; // Store the current time in last_time
}

// Main loop function
bool beer_counter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    beer_counter_state_t *state = (beer_counter_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Always start at the beer counter screen
            state->is_weight_screen = false;
            state->is_height_screen = false;
            state->is_sex_screen = false;
            state->is_bac_screen = false;
            state->is_sober_screen = false;
            print_beer_count(state); // Show the beer count screen
            break;
        case EVENT_LIGHT_BUTTON_UP:
            watch_set_led_off(); // Ensure the LED stays off when pressing the light button
            if (state->is_sober_screen) {
                // From sober screen, go back to beer counter
                state->is_sober_screen = false;
                print_beer_count(state);
            } else if (state->is_bac_screen) {
                // From BAC screen, switch to sober screen
                state->is_bac_screen = false; // Exit BAC screen
                state->is_sober_screen = true; // Enter sober screen
                print_sober_time(state);
            } else if (state->is_weight_screen) {
                // From weight screen, switch to sex screen
                state->is_weight_screen = false; // Exit weight screen
                state->is_height_screen = true; //Enter height screen
                print_height(state);
            } else if (state->is_height_screen) {
                // From height screen, switch to sex screen
                state->is_height_screen = false; // Exit weight screen
                state->is_sex_screen = true; //Enter sex screen
                print_sex(state);
            } else if (state->is_sex_screen) {
                // From sex screen, switch back to weight screen
                state->is_sex_screen = false; // Exit sex screen
                state->is_weight_screen = true; // Enter weight screen
                print_weight(state);
            } else {
                // From beer counter screen, switch to BAC screen
                state->is_bac_screen = true; // Enter BAC screen
                print_bac(state);
            }
            quick_ticks_running = false; // Stop any quick ticks
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            watch_set_led_off(); // Ensure LED stays off
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Stop quick ticks when button is released
            abort_quick_ticks();
            if (state->is_weight_screen) {
                 //Increase weight (only on weight screen)
                if (state->weight < 295) {
                    state->weight++; // Increment weight up to 295
                } else {
                    state->weight = 30; // Reset weight to 30 when reaching 295
                }
                print_weight(state); // Update display to reflect new weight
            } else if (state->is_height_screen) {
                if (state->height < 250) {
                    state->height++; // Increment height up to 250
                } else {
                    state->height = 130; // Reset height to 130 when reaching 250
                }
                print_height(state); // Update display to reflect new height
            } else if (state->is_sex_screen) {
                // Toggle sex (0 for male, 1 for female)
                state->sex = !state->sex; // Switch sex
                print_sex(state); // Stay on the sex screen and show new sex
            } else if (state->is_bac_screen) {
            } else if (state->is_sober_screen) {
                // BAC screen actions can be added here if needed
            } else {
                // Increase beer count on beer counter screen
                state->beer_count++;
                // Get the current date and time
                watch_date_time now = watch_rtc_get_date_time();
                state->last_time = watch_utility_date_time_to_unix_time(now, 0); // Store the timestamp of this increment
                print_beer_count(state); // Update display to reflect new beer count
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            if (!quick_ticks_running) {
                quick_ticks_running = true;
                movement_request_tick_frequency(4);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            // Reset beer count only when on beer counter screen
            if (!state->is_weight_screen && !state->is_height_screen && !state->is_sex_screen && !state->is_bac_screen && !state->is_sober_screen) {
                state->beer_count = 0; // Reset beer count
                // Reset last_time to the current time
                watch_date_time now = watch_rtc_get_date_time();
                state->last_time = watch_utility_date_time_to_unix_time(now, 0); // Using zero offset as no tz_offset is available
                print_beer_count(state); // Show the beer count screen
            }
            break;
        case EVENT_TICK:
            // Handle quick tick updates
            if (quick_ticks_running) {
                if (watch_get_pin_level(BTN_ALARM)) {
                    if (state->is_weight_screen) {
                        if (state->weight < 295) {
                            state->weight++; // Increment weight
                        }
                        print_weight(state); // Update display to reflect new weight
                    } else if (state->is_height_screen) {
                        if (state->height < 250) {
                            state->height++; // Increment height
                        }
                        print_height(state);
                    }
                } else {
                    abort_quick_ticks();
                }
            }
            break;
        case EVENT_MODE_LONG_PRESS:
            // Switch to beer counter screen from any settings screen
            if (state->is_weight_screen || state->is_height_screen || state->is_sex_screen || state->is_bac_screen || state->is_sober_screen) {
                state->is_weight_screen = false; // Reset weight screen flag
                state->is_height_screen = false; // Reset height screen flag
                state->is_sex_screen = false; // Reset sex screen flag
                state->is_bac_screen = false;     // Reset BAC screen flag
                state->is_sober_screen = false;  // Reset sober screen flag
                print_beer_count(state); // Show the beer count screen
            } else {
                // Switch from beer counter to weight screen
                state->is_weight_screen = true; // Enter weight screen
                print_weight(state);
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

// Function to display an error message
static void print_error_message(void) {
    char buf[14];
    snprintf(buf, sizeof(buf), "BM I ERROR");
    watch_display_string(buf, 0);
}

// Resign function
void beer_counter_face_resign(movement_settings_t *settings, void *context) {
    (void)settings;
    // Handle any cleanup before your watch face goes off-screen.
}

// Function to print the beer count
static void print_beer_count(beer_counter_state_t *state) {
    int body_weight = state->weight; // weight in kg
    int body_height = state->height; // height in cm
    int sex = state->sex; // sex (0 for male, 1 for female)

    if (body_height <= 0) {
        // Display an error message if height is not set
        print_error_message();
        return;
    }

    float height_in_meters = body_height / 100.0;
    float bmi = body_weight / (height_in_meters * height_in_meters);

    if (bmi > 45.0 || bmi < 16.0) {
        // Display an error message if BMI is out of range
        print_error_message();
        return;
    }

    char buf[14];
    sprintf(buf, "BC    %02d  ", state->beer_count); // Display the beer count on the LCD
    watch_display_string(buf, 0);
}

// Function to print BAC
static void print_bac(beer_counter_state_t *state) {
    float bac = calculate_bac(state);
    char buf[14];
    sprintf(buf, "BA C  %.2f", (bac)); // Convert BAC to promille and format
    watch_display_string(buf, 0);
}

// Function to print the time to be sober
static void print_sober_time(beer_counter_state_t *state) {
    float bac = calculate_bac(state);
    uint32_t time_to_sober_seconds = calculate_time_to_sober(bac);
    uint32_t hours = time_to_sober_seconds / 3600;
    uint32_t minutes = (time_to_sober_seconds % 3600) / 60;
    char buf[14];
    sprintf(buf, "ST   %03d%02d", hours, minutes); // Format as HH:MM Sober-Time
    watch_display_string(buf, 0);
    if (time_to_sober_seconds == 0) {
        state->beer_count = 0; // Reset beer count when BAC reaches 0
        return; // Exit the function as we have reset the beer count
    }
}

// Function to print weight
static void print_weight(beer_counter_state_t *state) {
    char buf[14];
    sprintf(buf, "WE   %03d  ", state->weight); // Display weight with leading zeros
    watch_display_string(buf, 0);
}

// Function to print height
static void print_height(beer_counter_state_t *state) {
    char buf[14];
    sprintf(buf, "HE   %03d  ", state->height); // Display height with leading zeros
    watch_display_string(buf, 0);
}

// Function to print sex
static void print_sex(beer_counter_state_t *state) {
    char buf[14];
    sprintf(buf, "%s     SEX", state->sex == 0 ? "MA" : "FE"); // Display sex
    watch_display_string(buf, 0);
}

// Function to calculate BAC using Widmark or Seidl formula
static float calculate_bac(beer_counter_state_t *state) {
    // Get the current date and time
    watch_date_time now = watch_rtc_get_date_time();
    uint32_t current_time_unix = watch_utility_date_time_to_unix_time(now, 0);
    
    // Calculate the time elapsed since last drink (in hours)
    uint32_t time_elapsed_seconds = current_time_unix - state->last_time;
    float time_elapsed_hours = time_elapsed_seconds / 3600.0;

    // Calculate total alcohol consumed in grams
    float total_alcohol_g = state->beer_count * BEER_VOLUME_ML * BEER_ALCOHOL_PERCENT * ALCOHOL_DENSITY;

    // Calculate Widmark factor based on sex
    //float widmark_factor = (state->sex == 0) ? 0.68 : 0.55;
    
    // Calculate Seidl et al. reduction factor based on height and sex
    float seidl_factor;
    if (state->sex == 0) {
        // Male Seidl factor calculation
        seidl_factor = (0.31608 - (0.004821 * state->weight) + (0.004432 * state->height));
    } else {
        // Female Seidl factor calculation
        seidl_factor = (0.31223 - (0.006446 * state->weight) + (0.004466 * state->height));
    }
    
    // Calculate initial BAC (g/kg)
    float bac = (total_alcohol_g / (state->weight * seidl_factor)) * RESORPTION_DEFICIT;

    // Adjust BAC for metabolism over time
    float adjusted_bac = bac - (ELIMINATION_RATE * time_elapsed_hours);

    // Ensure BAC does not go below zero
    if (adjusted_bac < 0) {
        adjusted_bac = 0;
    }
    return adjusted_bac;
}

// Function to calculate the time required to be sober
static uint32_t calculate_time_to_sober(float current_bac) {
    // Calculate the time required to reach zero BAC (in hours)
    float time_to_sober_hours = current_bac / ELIMINATION_RATE;

    // Convert hours to seconds
    uint32_t time_to_sober_seconds = (uint32_t)(time_to_sober_hours * 3600);

    return time_to_sober_seconds;
}
