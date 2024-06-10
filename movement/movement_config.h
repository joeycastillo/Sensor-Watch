/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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

#ifndef MOVEMENT_CONFIG_H_
#define MOVEMENT_CONFIG_H_

#include "movement_faces.h"

const watch_face_t watch_faces[] = {
    //CLOCKS
	beats_face,
	clock_face,
	day_night_percentage_face,
	decimal_time_face,
	mars_time_face,
	minute_repeater_decimal_face,
	repetition_minute_face,
	simple_clock_bin_led_face,
	simple_clock_face,
	weeknumber_clock_face,
	world_clock2_face,
	world_clock_face,
	wyoscan_face,
    //COMPLICATION
	activity_face,
	alarm_face,
	astronomy_face,
	blink_face,
	blinky_face,
	breathing_face,
	couch_to_5k_face,
	countdown_face,
	counter_face,
	databank_face,
	day_one_face,
	discgolf_face,
	dmvwc_face,
//	dual_timer_face,
	flashlight_face,
	geomancy_face,
	habit_face,
	interval_face,
	invaders_face,
	kitchen_conversions_face,
	moon_phase_face,
	morsecalc_face,
	orrery_face,
	planetary_hours_face,
	planetary_time_face,
	probability_face,
	pulsometer_face,
	randonaut_face,
	ratemeter_face,
	rpn_calculator_alt_face,
	rpn_calculator_face,
	sailing_face,
	ships_bell_face,
	simple_coin_flip_face,
	solstice_face,
	stock_stopwatch_face,
	stopwatch_face,
	sunrise_sunset_face,
	tachymeter_face,
	tally_face,
	tarot_face,
	tempchart_face,
	time_left_face,
	timer_face,
	tomato_face,
	toss_up_face,
	totp_face,
	totp_face_lfs,
	tuning_tones_face,
	wake_face,
    //DEMO
	character_set_face,
	chirpy_demo_face,
	demo_face,
	frequency_correction_face,
	hello_there_face,
//	lis2dw_logging_face,
	voltage_face,
    //SENSOR
//	accelerometer_data_acquisition_face,
	lightmeter_face,
	thermistor_logging_face,
	thermistor_readout_face,
	thermistor_testing_face,
    //SETTINGS
	finetune_face,
	nanosec_face,
	preferences_face,
	save_load_face,
	set_time_face,
	set_time_hackwatch_face,
};

#define MOVEMENT_NUM_FACES (sizeof(watch_faces) / sizeof(watch_face_t))

/* Determines what face to go to from the first face on long press of the Mode button.
 * Also excludes these faces from the normal rotation.
 * In the default firmware, this lets you access temperature and battery voltage with a long press of Mode.
 * Some folks also like to use this to hide the preferences and time set faces from the normal rotation.
 * If you don't want any faces to be excluded, set this to 0 and a long Mode press will have no effect.
 */
#define MOVEMENT_SECONDARY_FACE_INDEX (MOVEMENT_NUM_FACES - 4) // or (0)

/* Custom hourly chime tune. Check movement_custom_signal_tunes.h for options. */
#define SIGNAL_TUNE_DEFAULT

/* Determines the intensity of the led colors
 * Set a hex value 0-15 with 0x0 being off and 0xF being max intensity
 */
#define MOVEMENT_DEFAULT_GREEN_COLOR 0xF
#define MOVEMENT_DEFAULT_RED_COLOR 0x0

/* Set to true for 24h mode or false for 12h mode */
#define MOVEMENT_DEFAULT_24H_MODE false

/* Enable or disable the sound on mode button press */
#define MOVEMENT_DEFAULT_BUTTON_SOUND true

/* Set the timeout before switching back to the main watch face
 * Valid values are:
 * 0: 60 seconds
 * 1: 2 minutes
 * 2: 5 minutes
 * 3: 30 minutes
 */
#define MOVEMENT_DEFAULT_TIMEOUT_INTERVAL 0

/* Set the timeout before switching to low energy mode
 * Valid values are:
 * 0: Never
 * 1: 1 hour
 * 2: 2 hours
 * 3: 6 hours
 * 4: 12 hours
 * 5: 1 day
 * 6: 2 days
 * 7: 7 days
 */
#define MOVEMENT_DEFAULT_LOW_ENERGY_INTERVAL 1

/* Set the led duration
 * Valid values are:
 * 0: No LED
 * 1: 1 second
 * 2: 3 seconds
 * 3: 5 seconds
 */
#define MOVEMENT_DEFAULT_LED_DURATION 1

#endif // MOVEMENT_CONFIG_H_
