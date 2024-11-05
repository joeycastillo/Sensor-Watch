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

#ifndef BEER_COUNTER_FACE_H_
#define BEER_COUNTER_FACE_H_

#include "movement.h"

/*
 * BEER COUNTER
 *
 * This watchfaces let's you track how many beers you've had, 
 * your current blood alcohol content (BAC) 
 * and how much time it takes to be completely sober again (TTS).
 * It takes the the formula by Seidl et al.[1] to calculate the BAC using your sex and weight.
 * When you drink another beer and track it, BAC and TTS update to the new values.
 * Also as time progresses BAC and TTS also update but you have to switch between
 * the screens to see the updated time.
 * For extreme values the BAC doesn't make sense anymore so the range is limited to a BMI = 16 < x < 45.
 *
 * 
 * USAGE:
 *
 * from EVERY screen:
 * - Mode Short Press: go to next watchface
 * - Mode Long Press goes to BC (except from BC)
 *
 * beer counter (BC) -> displays and adjusts the number of beers drunk
 * - Alarm Short Press: increase beer counter by 1
 * - Alarm Long Press:  reset beer counter to 0
 * - Mode Long Press: go to weight screen (WE) ("nested" in the first screen are the settings for weight and sex)
 * - Light Short Press: go to blood alcohol content screen (BAC)
 *
 * weight (WE) -> displays and adjusts the weight in kg (starts at 30, ends at 300)
 * - Alarm Short Press: increase weight by 1 kg
 * - Alarm Long Press: increase weight by 1 kg FAST, let go and it stops
 * - Light Short Press: switch to sex screen (SEx)
 *
 * sex (SEx) -> displays and switches between male and female this time using the first two characters of the display
 * - Alarm Short Press: switch between Male (MA) and female (FE)
 * - Light Short Press: switch to weight screen (WE)
 *
 * blood alcohol content (BA C) -> displays the blood alcohol content in g/kg bodyweight AKA per mille (‰); the - represents a decimal point
 * - Light Short Press: switch to time to sobriety screen (TTS)
 * 
 * time to sobriety (TTS) -> displays the time until bac reaches 0. the first 3 digits are hours and the last 2 (smaller ones) are minutes.
 * - Light Short Press: switch to BC
 *
 * [1] Seidl et al. (2000) The calculation of blood ethanol concentrations in males and females. Int J Legal Med (2000) 114:71–77
 * 
 * DISCLAIMER
 * This watchface is for entertainment purposes only. 
 * There are many variables that mean this tool cannot fully determine your BAC level, 
 * and therefore whether an individual is able to lawfully drive a vehicle. 
 * I strongly suggest that if you have any alcohol in your body: do not drive.
 *
 * By using this tool, you acknowledge that any information presented may 
 * contain inaccuracies or errors and I expressly exclude liability for any 
 * such inaccuracies or errors to the fullest extent permitted by law.
 */

typedef struct {
    uint8_t beer_count;
    uint32_t last_time; // Store last time of beer consumption
    uint32_t weight;
    uint32_t height;
    uint8_t sex; // 0 for male, 1 for female
    bool is_weight_screen;
    bool is_height_screen;
    bool is_sex_screen;
    bool is_bac_screen;
    bool is_sober_screen; // Add this line
} beer_counter_state_t;

void beer_counter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void beer_counter_face_activate(movement_settings_t *settings, void *context);
bool beer_counter_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void beer_counter_face_resign(movement_settings_t *settings, void *context);

// Function prototypes for internal uses
static void print_beer_count(beer_counter_state_t *state);
static void print_bac(beer_counter_state_t *state);
static void print_weight(beer_counter_state_t *state); // Add this line
static void print_height(beer_counter_state_t *state);
static void print_sex(beer_counter_state_t *state); // Add this line
static void print_error_message(void);
static float calculate_bac(beer_counter_state_t *state);
static uint32_t calculate_time_to_sober(float current_bac);

#define beer_counter_face ((const watch_face_t){ \
    beer_counter_face_setup, \
    beer_counter_face_activate, \
    beer_counter_face_loop, \
    beer_counter_face_resign, \
    NULL, \
})

#endif // BEER_COUNTER_FACE_H_
