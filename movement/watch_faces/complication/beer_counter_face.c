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
#define ELIMINATION_RATE_H 0.15f // Average elimination rate (g/kg/hour)
#define ELIMINATION_RATE 0.00004167f // Average elimination rate (g/kg/seconds)
#define RESORPTION_DEFICIT 0.9 // 100% - 10%
/* resorption deficit is between 10% and 30% depending on enzyme activity, 
 * filling of the stomach, concentration of alcohol in different beverages, etc.
 * here it is chosen to be on the safer side, so that the probability for sobriety is higher
 * when sobertime reaches 0.
 */

static bool quick_ticks_running = false;

static void print_sober_time(beer_counter_state_t *state);

static void abort_quick_ticks(void) {
    if (quick_ticks_running) {
        quick_ticks_running = false;
        movement_request_tick_frequency(4);
    }
}

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
        state->is_bac_screen = false;
        state->is_weight_screen = false;
        state->is_height_screen = false;
        state->is_sex_screen = false;
        state->is_sober_screen = false;
        state->beer_count = 0;
    }
}

void beer_counter_face_activate(movement_settings_t *settings, void *context) {
    (void)settings;
    movement_request_tick_frequency(4);
    quick_ticks_running = false;
    watch_set_led_off();

    watch_date_time now = watch_rtc_get_date_time();
    uint32_t current_time_unix = watch_utility_date_time_to_unix_time(now, 0);
    beer_counter_state_t *state = (beer_counter_state_t *)context;

    float bac = calculate_bac(state);
    if (bac == 0) {
        state->beer_count = 0; 
        state->old_beer_count = 0;
        state->old_bac = 0;
    }
    print_beer_count(state);
}

bool beer_counter_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    beer_counter_state_t *state = (beer_counter_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            state->is_weight_screen = false;
            state->is_height_screen = false;
            state->is_sex_screen = false;
            state->is_bac_screen = false;
            state->is_sober_screen = false;
            print_beer_count(state);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            watch_set_led_off();
            if (state->is_sober_screen) {
                state->is_sober_screen = false;
                print_beer_count(state);
            } else if (state->is_bac_screen) {
                state->is_bac_screen = false;
                state->is_sober_screen = true;
                print_sober_time(state);
            } else if (state->is_weight_screen) {
                state->is_weight_screen = false; 
                state->is_height_screen = true;
                print_height(state);
            } else if (state->is_height_screen) {
                state->is_height_screen = false;
                state->is_sex_screen = true;
                print_sex(state);
            } else if (state->is_sex_screen) {
                state->is_sex_screen = false; 
                state->is_weight_screen = true;
                print_weight(state);
            } else {
                state->is_bac_screen = true;
                print_bac(state);
            }
            quick_ticks_running = false;
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            watch_set_led_off();
            break;
        case EVENT_ALARM_BUTTON_UP:
            abort_quick_ticks();
            if (state->is_weight_screen) {
                if (state->weight < 250) {
                    state->weight++;
                } else {
                    state->weight = 30;
                }
                print_weight(state);
            } else if (state->is_height_screen) {
                if (state->height < 220) {
                    state->height++;
                } else {
                    state->height = 130;
                }
                print_height(state);
            } else if (state->is_sex_screen) {
                state->sex = !state->sex;
                print_sex(state);
            } else if (state->is_bac_screen) {
            } else if (state->is_sober_screen) {
            } else {
                state->beer_count++;
                watch_date_time now = watch_rtc_get_date_time();
                state->last_time = watch_utility_date_time_to_unix_time(now, 0);
                print_beer_count(state);
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            if (!quick_ticks_running) {
                quick_ticks_running = true;
                movement_request_tick_frequency(4);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (!state->is_weight_screen && !state->is_height_screen && !state->is_sex_screen && !state->is_bac_screen && !state->is_sober_screen) {
                state->beer_count = 0;
                state->old_beer_count = 0;
                state->old_bac = 0;
                watch_date_time now = watch_rtc_get_date_time();
                state->last_time = watch_utility_date_time_to_unix_time(now, 0); // Using zero offset as no tz_offset is available
                print_beer_count(state);
            }
            break;
        case EVENT_TICK:
            if (quick_ticks_running) {
                if (watch_get_pin_level(BTN_ALARM)) {
                    if (state->is_weight_screen) {
                        if (state->weight < 250) {
                            state->weight++;
                        }
                        print_weight(state);
                    } else if (state->is_height_screen) {
                        if (state->height < 220) {
                            state->height++;
                        }
                        print_height(state);
                    }
                } else {
                    abort_quick_ticks();
                }
            }
            break;
        case EVENT_MODE_LONG_PRESS:
            if (state->is_weight_screen || state->is_height_screen || state->is_sex_screen || state->is_bac_screen || state->is_sober_screen) {
                state->is_weight_screen = false;
                state->is_height_screen = false;
                state->is_sex_screen = false;
                state->is_bac_screen = false;
                state->is_sober_screen = false;
                print_beer_count(state);
            } else {
                state->is_weight_screen = true;
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

static void print_error_message(void) {
    char buf[14];
    snprintf(buf, sizeof(buf), "BM I ERROR");
    watch_display_string(buf, 0);
}

void beer_counter_face_resign(movement_settings_t *settings, void *context) {
    (void)settings;
}

static void print_beer_count(beer_counter_state_t *state) {
    int body_weight = state->weight;
    int body_height = state->height;
    int sex = state->sex;
    float height_in_meters = body_height / 100.0;
    float bmi = body_weight / (height_in_meters * height_in_meters);
    if (bmi > 45.0 || bmi < 16.0) {
        print_error_message();
        return;
    }

    char buf[14];
    sprintf(buf, "BC    %02d  ", state->beer_count);
    watch_display_string(buf, 0);
}

static void print_bac(beer_counter_state_t *state) {
    float bac = calculate_bac(state);
    char buf[14];
    sprintf(buf, "BA C  %.2f", (bac));
    watch_display_string(buf, 0);
}

static void print_sober_time(beer_counter_state_t *state) {
    float bac = state->old_bac;
    uint32_t time_to_sober_seconds = calculate_time_to_sober(bac);
    uint32_t hours = time_to_sober_seconds / 3600;
    uint32_t minutes = (time_to_sober_seconds % 3600) / 60;
    char buf[14];
    sprintf(buf, "TT S %03d%02d", hours, minutes);
    watch_display_string(buf, 0);
    if (time_to_sober_seconds == 0) {
        state->beer_count = 0;
        return;
    }
}

static void print_weight(beer_counter_state_t *state) {
    char buf[14];
    sprintf(buf, "WE   %03d  ", state->weight);
    watch_display_string(buf, 0);
}

static void print_height(beer_counter_state_t *state) {
    char buf[14];
    sprintf(buf, "HE   %03d  ", state->height);
    watch_display_string(buf, 0);
}

static void print_sex(beer_counter_state_t *state) {
    char buf[14];
    sprintf(buf, "%s     SEX", state->sex == 0 ? "MA" : "FE");
    watch_display_string(buf, 0);
}

static float calculate_bac(beer_counter_state_t *state) {
    watch_date_time now = watch_rtc_get_date_time();
    uint32_t current_time_unix = watch_utility_date_time_to_unix_time(now, 0);
    uint32_t time_elapsed_seconds = current_time_unix - state->last_time_bac;
    if (time_elapsed_seconds < 0) {
        time_elapsed_seconds = 0;
    }

    float new_alcohol_g = state->beer_count * BEER_VOLUME_ML * BEER_ALCOHOL_PERCENT * ALCOHOL_DENSITY;
    float old_alcohol_g = state->old_beer_count * BEER_VOLUME_ML * BEER_ALCOHOL_PERCENT * ALCOHOL_DENSITY;

    float widmark_factor = (state->sex == 0) ? 0.68 : 0.55;
    
    float seidl_factor;
    if (state->sex == 0) {
        seidl_factor = (0.31608 - (0.004821 * state->weight) + (0.004432 * state->height));
        if (seidl_factor < 0.64) {
            seidl_factor = widmark_factor;
        }
    } else {
        seidl_factor = (0.31223 - (0.006446 * state->weight) + (0.004466 * state->height));
        if (seidl_factor < 0.54) {
            seidl_factor = widmark_factor;
        }
    }
    
    float old_bac = ((old_alcohol_g / (state->weight * seidl_factor)) *RESORPTION_DEFICIT);
    float new_bac = (new_alcohol_g / (state->weight * seidl_factor)) * RESORPTION_DEFICIT;
    float delta_bac = new_bac - old_bac;

    float current_bac;
    if (state->beer_count == state->old_beer_count) {
        current_bac = state->old_bac - (ELIMINATION_RATE * time_elapsed_seconds);
    } else {
        current_bac = (state->old_bac + delta_bac) - (ELIMINATION_RATE * time_elapsed_seconds);
        state->old_beer_count = state->beer_count;
    }
    
    if (current_bac < 0) {
        current_bac = 0;
    }

    state->old_bac = current_bac;
    state->last_time_bac = current_time_unix;
    return current_bac;
}

static uint32_t calculate_time_to_sober(float current_bac) {
    float time_to_sober_hours = current_bac / ELIMINATION_RATE_H;
    uint32_t time_to_sober_seconds = (uint32_t)(time_to_sober_hours * 3600);
    return time_to_sober_seconds;
}
