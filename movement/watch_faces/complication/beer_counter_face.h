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
 * This watchfaces let's you track how many drinks you've had, 
 * your current blood alcohol content (BAC) 
 * and how much time it takes to be completely sober again (TTS).
 * It takes the the formula by Seidl et al.[1] to calculate the BAC using your sex and weight.
 * When you drink another drink and track it, BAC and TTS update to the new values.
 * Also as time progresses BAC and TTS also update but you have to switch between
 * the screens to see the updated time.
 * You can also adjust the volume and content of alcohol of the drink. At first it is set to 500ml and 5% (1 Beer).
 * For extreme values the BAC doesn't make sense anymore so the range is limited to a BMI = 16 < x < 45.
 *
 * 
 * USAGE:
 *
 * from EVERY screen:
 * - Mode Short Press: go to next watchface
 * - Mode Long Press goes to BC (except from BC and TTS)
 *
 * beer counter (BC) -> displays and adjusts the number of beers/drinks drunk
 * - Alarm Short Press: increase beer counter by 1
 * - Alarm Long Press:  reset beer counter to 0
 * - Mode Long Press: go to volume of drink screen (VD) 
 *   ("nested behind" the first screen are the settings for volume of drink and content of alcohol of the drink)
 * - Light Short Press: go to blood alcohol content screen (BAC)
 *
 * volume of drink (VD) -> displays and adjusts the volume of the next drink (starts at 20, ends at 1000)
 * - Alarm Short Press: increase volume by 10 ml
 * - Alarm Long Press: increase weight by 10 ml FAST, let go and it stops
 * - Light Short Press: switch to alcohol content screen (AC)
 *
 * alcohol content (AC) -> displays and adjusts the percentage of alcohol of the next drink (starts at 1, ends at 100)
 * - Alarm Short Press: increase percentage by 1%
 * - Alarm Long Press: increase percentage by 1% FAST, let go and it stops
 * - Light Short Press: switch to volume of drink screen (VD)
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
 * - Mode Long Press: go to weight screen (WE)
 *
 * weight (WE) -> displays and adjusts the weight in kg (starts at 30, ends at 250)
 * - Alarm Short Press: increase weight by 1 kg
 * - Alarm Long Press: increase weight by 1 kg FAST, let go and it stops
 * - Light Short Press: switch to height screen (HE)

 * height (HE) -> displays and adjusts the height in cm (starts at 130, ends at 220)
 * - Alarm Short Press: increase height by 1 cm
 * - Alarm Long Press: increase weight by 1 cm FAST, let go and it stops
 * - Light Short Press: switch to sex screen (SEx)
 *
 * sex (SEx) -> displays and switches between male and female this time using the first two characters of the display
 * - Alarm Short Press: switch between Male (MA) and female (FE)
 * - Light Short Press: switch to weight screen (WE)
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
    uint8_t old_beer_count;
    uint32_t last_time; // Store last time of beer consumption
    uint32_t last_time_bac;
    uint32_t weight;
    uint32_t height;
    uint8_t sex; // 0 for male, 1 for female
    uint32_t drink_vol;
    uint32_t alc_cont;
    bool is_weight_screen;
    bool is_height_screen;
    bool is_sex_screen;
    bool is_bac_screen;
    bool is_sober_screen; 
    bool is_drink_vol_screen; //volume of drink
    bool is_alc_cont_screen; //alcohol content of drink
    float old_bac;
} beer_counter_state_t;

void beer_counter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void beer_counter_face_activate(movement_settings_t *settings, void *context);
bool beer_counter_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void beer_counter_face_resign(movement_settings_t *settings, void *context);

// Function prototypes for internal uses
static void print_beer_count(beer_counter_state_t *state);
static void print_bac(beer_counter_state_t *state);
static void print_weight(beer_counter_state_t *state); 
static void print_height(beer_counter_state_t *state);
static void print_sex(beer_counter_state_t *state); 
static void print_drink_vol(beer_counter_state_t *state);
static void print_alc_cont(beer_counter_state_t *state);
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
