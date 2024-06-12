/*
 * MIT License
 *
 * Copyright (c) 2024 Klingon Jane, based on simple_clock_face by:
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

#include <stdlib.h>
#include "prime_clock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"

// Each minute has one of three possible patterns based on modulus of hours + minutes
const uint8_t lookup [ 3 ] [ 16 ] = { {1,7,11,13,17,19,23,29,31,37,41,43,47,49,53,59},
	{1,3,7,9,13,19,21,27,31,33,37,39,43,49,51,57},
	{3,9,11,17,21,23,27,29,33,39,41,47,51,53,57,59} };

// Each uint16_t contains one minute of data.
// This is a binary bitfield ( 1 if prime ) for each of the 16 candidate numbers.
const uint16_t primes_bitfield [ 1440 ] = {
57342,60831,22500,62238,47977,19507,56635,55977,58102,22182,27512,12459,
41945,  231,48098,59716,34045,44338, 4421,25365, 8909,20364,23638,24326,
38484,63810,51482,26030,54819,25163, 9829, 1128,61595,39403,41492,53196,
35674, 2729,14641, 6646,57591,58308,52661,44160,23602,12410,64578,37297,
  281,55082,37431,20523, 1928, 6435,12090,33255,65056,11797,63701, 8801,
 3084,38661,55364,38739,57792,33161,51605, 9126,54016,44042,51265,41272,
55312,12444, 6724,24738,16664, 2353, 3029,42851,11782,45117,13893, 6337,
50777,11853,54829,38994, 9394,50294,13839,38995,42160, 3480,21532,16968,
 8880,53430,34178,  855,20870,59394,28740, 3185,13159,63010,25552,55128,
20944,23200,16664,11589,34120,41386,22673,37956,15523,12160,32811,33387,
 6324,14555, 8993,60768, 3334,29260, 1604,63794,40972,35473,33149,47173,
 2132, 5240,  549,49337,12317,52369,38425, 2692,19858,59814,36992,12294,
11522,11525,23664, 5722,49174, 5189,59101,35088,16523,17236,37136,44296,
  483,23584,33713,16526,10467,18014, 6817,33424, 6260, 6474,33092, 8712,
39954,18546,34576,10332,23200,47183,27174, 1600,39499,36105,13345,23346,
37004, 3642,42021, 5226, 8578,57994,11008,32918,46731, 9988,18992,47664,
62304,34532,    0, 7452,45189, 5360,45072,32772,53443,35888,50706,42099,
 3277, 1798,10519, 8250, 6915,18190,25288,24628, 2085,63893,32922, 2449,
 5881,59474,20678, 1860,35616,52448,49436,17587,17041,10797,24854,51857,
15394,10288,45152,58518,49345, 8812,12899, 6092,    9,53632,19723, 4388,
 3352,12516,18184,53248,33248,35234, 3208,37378,29929,10882,23084,11544,
37843,21760,18444,14452,40031,33440,28697,60485, 2168,35073,17010,41794,
54798,16642,11268,21675,42640,19137,25650,37129,  579,  368,21573, 3088,
25244,40988,16385,21008,42200,33253,41031,20480,24592,14117,23864,17541,
22568,41546,16394, 3552,35072, 3762, 2706,25889,34056,50180, 9592,59392,
14640,53733,  452,34196,33876,30866, 6208,17474,43584,20642,39169,50952,
18057,15490,11764, 4637,37642, 8304,41673, 9354,49352,10321,57921,   81,
24832,19605, 2440,18774,33306,50211, 6153,12441, 2817,41058,17959,24710,
25518,33072,41264,37480,41485,19009, 4104, 4452,13435,36377, 4561,16600,
 4480,42034,57417, 2123,43195,24336,17924, 5253, 2922,  284,11002, 9155,
 1688,10887,53290,19216,45200,  594,45911,34466,32788,19065,53637,13456,
16708,39680, 1035,55334,54682,20649, 2600, 8840,27149, 4000,  565, 6245,
32849,10757,41801,18753,16545,  721,33152, 8594, 3076,21276, 6248,34128,
45207, 5290,26147, 8331, 1588,28706,  848,  675,13057,16392,  729, 2058,
24596,17633, 8645, 5349,34834,24674,12906,56416,22922,  443,23944,20688,
18475,17980, 9923,16600,53920, 8835,35044, 8330,27712,58481,33316,22688,
42504,45000,19116,25730, 2304, 1070,13388, 3338,22816, 2059,12532,17930,
  320,39169,14424, 2725,32808,58183, 7224, 1360,35328,16778,41240,20688,
21532,20562,45152,22532, 6232,43265,33067,24620,25644,16844, 8230,37306,
37312,34209, 1692, 8712, 8814,21186, 1287,26453,50356, 4430, 8464, 1800,
 4624,29702,19276, 3210,12418,33936,20693,12809, 9002, 8622,15737,33057,
  801,59650,34889,47434,12964, 9351,10760,19361,19806, 9856, 1906,26629,
16400,41346,49721,49392, 4620, 2066,34851,  529,37862,17924,43859,33792,
 9754,  561,37392,  789,53268, 5568, 2740,12346,46405,37171,57728,17713,
49222, 4136, 9416,35091,39625,  786,15044, 8536, 6373, 4365,23472,  778,
49527, 8388, 2633,49160, 3079, 2532,38192, 8458, 3377, 4375,  552,46800,
27264,  266,57636, 1160, 2368,24837, 1615,55368, 5379,18470,22242,26892,
33065,49158,20064,16978,41289,54352,53249,19218,30336,  738,  164,57505,
  643, 2083, 4166, 9805,41484,12318,16547,29132, 3920,40328,24658, 2146,
13924,25094,   83,18695,35634,  588, 3241,10628, 4505, 4955,32819,51372,
45090,12419,  522,37392,34829,45685, 8280, 3329,20677,38292, 4178,42046,
   78,36128, 8356, 1939, 9285,13921, 3588,17048,35177,10311,46473,33425,
17932,39713,22534,    1,33924,16780,12293, 1056,  784,41508,20530,24708,
53296,   33, 3597,16434,43283,12394, 6916, 2150,32784,29840,37408,35031,
24963,43276,  864, 5124,12996,34656, 9221,17867,24619,17025,  136,18570,
37416,  160,17984,33332,34592,37507, 7331,24964, 8308, 7034,27008,12522,
 8396, 5713, 6536,  786,50756,17216,18896,57384,  288, 8853,30282,11650,
32897,34819,36931,50176,35074,18681, 5756,63828,  664,50368,16912,35857,
18480,41328, 5160,18707, 3337,36880,32921, 2212,16420,10240,44057,45072,
35138, 1033,32881,12648,41541, 5611,32912,20552,34067,21824,58182,  771,
13332,32834, 2338, 8480,  401,20997, 5218,11352, 6572, 7858, 2165,21024,
32896,62168,11793,53571, 1868,   84,18432,25928,14292,12560,16687, 2160,
26625,33419,12294,19489,10912,25232,41235, 4304,33419, 1094,43685,14409,
17185,34725, 8601,17732,   65,11056,12552,31755,35264, 3208, 4609,41497,
20576,16428, 8329, 9531, 4453, 8837,17602,18572,38488,19222,   82,34256,
53442, 2128,50245,13318,18982,20824,64352,  128,35990,32896,33830,10381,
24914,16413,14088, 4133, 1612,43279,11264,36674,45089,50202,19840, 4488,
 3146, 3556, 4966,59469,53512,28804,18960,24603,17417,25826, 6665,35872,
41728,  302,18701, 8224,43776,16512,37044,42816, 2577,   22,  514,17666,
52228, 6202,43186,16673,17430,28833, 9098,33028,12891,37345,38016,  652,
24578,34884, 9412, 4888,26743,58048,33485,34192, 3472,  642, 1088,33093,
17714,49191, 6162, 4742,25321,  300,12677,34578,43300,53284,  852,32928,
 8529,55937,32813,49412, 1540,10246, 8192,34318,47104,16768, 2089,17595,
12426, 2212,  980,10242,  776, 2050,44065, 9286,18588, 1540,32900,50473,
 2696, 1296, 5452,  786,49194, 8198,38184,14621, 5635,57395,  226, 8962,
17413,16644, 2623, 2241, 2453,37161,40982, 4164, 2368,32931,57500,25616,
24073,39938, 4512,25426,21774,  393,13336, 3083, 1737, 4164,10546,    4,
36082, 2849,18088,16592,56936,44546,32769,17940,34816,51752,46284,16822,
 9286,47649, 1032,29836,36993,57412, 6284,19026,33322, 2113, 4208,10592,
 9282, 5760, 2123,16928,16683,  329,18504,35913,24658, 5490,25161,   16,
 9001,33800,18707,36920, 9251,17410,27874,29222, 1178,  518,43786,42560,
 1601, 1827,49158, 4550,34372,19856, 2308,18484,49174, 4136,20626,34816,
51248,24808, 9413,27034,43696, 4627,  226, 6346,43076,17612,  271, 2064,
 5841, 9600,54308,  137,21028,12312,27401,17426,14760,  274, 8312, 2179,
 3400, 8196,46593,  514, 2437,10524,46080,46436,16405, 8319,16780, 5377,
18577, 1093,14740,15424, 5128,52234, 3395,41991,54425,24656,30914,  258,
12545, 1168,10371,42632,50832,33332, 4197, 4816, 8649,26688,34936,53588,
 1908,17458,45606,37914,57475,  512,41520, 9728, 8236,51202,  384,14593,
39048, 3210,18596,  298,12338,46145,50192, 4996,37140,  320,58136, 9282,
37008,35219, 2066, 1153,  132, 8842,10501, 2144, 9025,57442,51844,11304,
18499, 1024,36628, 4886, 1072, 3845, 4304,24833, 2052,40962, 2339,17440,
18477,    3,49682,25161, 2094,53916,  520,37298,52422,34247, 6665, 9986,
18768, 9258,58953, 4109,51282,25040,38464,16416,34817,10419,19456,  103,
  516,   28,  162,43058,39190,24844,34052,17992, 3082,49236,25484, 8533,
35776,40979,20560,25408, 4672,32867, 1153,56224, 5136,29254, 9072,55337,
16768,34960,10242,35153,    3, 2754,43540,40974, 2758,   89,19280, 3680,
25984, 9728,62472,18220,16464,12306, 1923, 8325,23178, 8786,37760, 7282,
  260,27264,  925,46080,43276, 8528,53530,11008, 6145,33921, 7456,41994,
 8231,21601,37900,56320,16457, 9257, 2050, 8226, 2312, 4292,43010, 8410,
 2232,  268,30912,34242,42113,52388,37013, 1604,32768,24328,   10,  426,
 1451,49424,34177,21664, 2563,   16,16898,  328, 4100,  195, 8966,18533,
 6407,33410,25619,18444,16580,37129, 2546,21094, 8513,  210, 2337,39048,
 1027, 8352, 3280,31112,33872, 9028,21036, 1040, 8924,13886,41392, 8448,
58440,    8,36940,10262,36970,22021, 4352,49573, 7552,16414, 1097,25124,
49169, 4440, 4896,21893,16973,34980, 9592,58018,49830,32785, 4688,58384,
17188,39321,19842,36976, 1095,16736,35105, 2360,25191, 2255,26628,12416,
 5560,10800,17729,34819,38944, 3172,32789,13184,17024, 1360, 6286, 8192,
21092,32773, 4416,    1,21633,   43, 2272,11040,10411,41634, 8196,25376,
42572,17616,35152,30881,21326, 3456,35372,16392,21248,34098,51462,34208,
24854, 6160, 4096,19520,10240,45194,38928,  326,40968,16960,53889,41554,
32888, 7200, 2064,49797, 2069,51852,   16,18450,33798, 2855,34832,32769,
19115,   77,20493,11272,57393, 4858, 8596,29698,36038,25756, 2048,13012,
 1058,24900,38953,  276,17952,21800,25644, 4481,56502, 3378, 1697,14466,
 1600,59396,12224, 2146,19780,24969,19017,36939,10433,  145,  397,35476,
  272, 6294,  576,45608,17528,31746,33152,  227,  685,25152,33426,11552,
34825,10835,35538,26183,24832,18437,10244, 2208, 8868,34688,17713,  268,
 1056,45392, 4904,39297, 2318,   41,34418, 6241,24598, 8331,32786,33286,
54030, 8264, 4676,13318,20581, 1061,   16,35864,18753,27872,  626,57352,
 1050,38920,17408, 1596, 2178,10562,33293, 3440,33024, 3780,49288,13008,
 6407,37138,53278,32780, 3332, 9228, 3584,50792,   69, 6176, 8204,16545
};


// Read an entry from the primes bitfield containing one minutes worth of bitwise data in a uint16_t.
static void pc_read_bitfield(prime_clock_state_t *state, watch_date_time *date_time) {
	uint8_t hours;
	uint16_t tableIndex;

	hours = date_time->unit.hour;
	if ( !state->mode_24h ) {
		hours = hours % 12;
		if ( hours == 0 ) hours = 12;
	}
	state->my_mod = ( hours + date_time->unit.minute ) % 3;		// There are three different 'pattern' types for a given minute.
	tableIndex = hours * 60 + date_time->unit.minute;
	state->seconds_bitfield = primes_bitfield [ tableIndex ];	// Exact bitfield for this minute
	state->indexer = 0;		// Haven't started looking for next prime second yet.
	state->next_required = true;	// We must calculate next prime second
	state->this_minute_displayed = false;
}

// Calculate next prime second, starting/including current second
static void pc_next_prime_second(prime_clock_state_t *state, watch_date_time *date_time) {
	bool done = false;
	state->next_prime_second = 61;		// In case there are no more this minute
	while ( !done ) {
		if ( lookup [ state->my_mod ] [ state->indexer ] >= date_time->unit.second ) {  // High enough, can use it if its prime.
			if ( state->seconds_bitfield & ( 1 << state->indexer ) ) {	// It's prime, we're done.
				state->next_prime_second = lookup [state->my_mod][ state->indexer ];
				done = true;
			}
		}
		state->indexer++;
		if ( state->indexer > 15 ) done = true;
	}
	state->next_required = false;
}

static void _update_alarm_indicator(bool settings_alarm_enabled, prime_clock_state_t *state) {
    state->alarm_enabled = settings_alarm_enabled;
    if (state->alarm_enabled) watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    else watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

void prime_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(prime_clock_state_t));
        prime_clock_state_t *state = (prime_clock_state_t *)*context_ptr;
        state->signal_enabled = false;
        state->watch_face_index = watch_face_index;
    }
}

void prime_clock_face_activate(movement_settings_t *settings, void *context) {
    prime_clock_state_t *state = (prime_clock_state_t *)context;

    if (watch_tick_animation_is_running()) watch_stop_tick_animation();

    if (settings->bit.clock_mode_24h) watch_set_indicator(WATCH_INDICATOR_24H);
	state->mode_24h = settings->bit.clock_mode_24h;
    // handle chime indicator
    if (state->signal_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
    else watch_clear_indicator(WATCH_INDICATOR_BELL);

    // show alarm indicator if there is an active alarm
    _update_alarm_indicator(settings->bit.alarm_enabled, state);

    watch_set_colon();

    // this ensures that none of the timestamp fields will match, so we can re-render them all.
    state->previous_date_time = 0xFFFFFFFF;
	state->force_print = true;
	state->this_minute_displayed = false;
	state->this_hour_displayed = false;
}

bool prime_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    prime_clock_state_t *state = (prime_clock_state_t *)context;
    char buf[11];
    uint8_t pos;

    watch_date_time date_time;
    uint32_t previous_date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:
            date_time = watch_rtc_get_date_time();
            previous_date_time = state->previous_date_time;
            state->previous_date_time = date_time.reg;

            // check the battery voltage once a day...
            if (date_time.unit.day != state->last_battery_check) {
                state->last_battery_check = date_time.unit.day;
                watch_enable_adc();
                uint16_t voltage = watch_get_vcc_voltage();
                watch_disable_adc();
                // 2.2 volts will happen when the battery has maybe 5-10% remaining?
                // we can refine this later.
                state->battery_low = (voltage < 2200);
            }

            // ...and set the LAP indicator if low.
            if (state->battery_low) watch_set_indicator(WATCH_INDICATOR_LAP);

            if ((date_time.reg >> 6) == (previous_date_time >> 6) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                // everything before seconds is the same, don't waste cycles setting those segments.
                if ( state->next_required ) pc_next_prime_second ( state, &date_time );
                if ( date_time.unit.second == state->next_prime_second ) {
					if ( state->this_minute_displayed ) {
                        watch_display_character_lp_seconds('0' + date_time.unit.second / 10, 8);
                        watch_display_character_lp_seconds('0' + date_time.unit.second % 10, 9);
					} else if ( state->this_hour_displayed ) {
						pos = 6;
                        sprintf(buf, "%02d%02d", date_time.unit.minute, date_time.unit.second);
                        watch_display_string(buf, pos);
						state->this_minute_displayed = true;
					} else {
						pos = 4;
                        if (!settings->bit.clock_mode_24h) {
						    date_time.unit.hour %= 12;
						    if (date_time.unit.hour == 0) date_time.unit.hour = 12;
					    }
                        sprintf(buf, "%2d%02d%02d", date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
                        watch_display_string(buf, pos);
						state->this_minute_displayed = true;
						state->this_hour_displayed = true;
						watch_set_colon();
					}
                    state->next_required = true;	// We used this one up.
				}
                break;
            } else if ((date_time.reg >> 12) == (previous_date_time >> 12) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                // everything before minutes is the same - new minute, nothing to display just yet
				pc_read_bitfield ( state, &date_time );
				pc_next_prime_second ( state, &date_time );
				break;
            } else {
                // other stuff changed; let's do it all.
                if (!settings->bit.clock_mode_24h) {
                    // if we are in 12 hour mode, do some cleanup.
                    if (date_time.unit.hour < 12) {
                        watch_clear_indicator(WATCH_INDICATOR_PM);
                    } else {
                        watch_set_indicator(WATCH_INDICATOR_PM);
                    }
                    date_time.unit.hour %= 12;
                    if (date_time.unit.hour == 0) date_time.unit.hour = 12;
                }
				pc_read_bitfield ( state, &date_time );
				state->this_hour_displayed = false;
				pc_next_prime_second ( state, &date_time );
                pos = 0;
                if (event.event_type == EVENT_LOW_ENERGY_UPDATE) {
                    if (!watch_tick_animation_is_running()) watch_start_tick_animation(500);
                    sprintf(buf, "%s%2d%2d%02d  ", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute);
					state->this_minute_displayed = true;
					state->this_hour_displayed = true;
                } else {
					if ( date_time.unit.second == state->next_prime_second ) {
						sprintf(buf, "%s%2d%2d%02d%02d", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
						state->next_required = true;
						state->this_minute_displayed = true;
						state->this_hour_displayed = true;
					} else if ( state->force_print ) {
							sprintf(buf, "%s%2d%2d%02d--", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute);
							state->force_print = false;
                            state->this_minute_displayed = true;
                            state->this_hour_displayed = true;
					}
					else break;		
                }
            }
            watch_display_string(buf, pos);
            // handle alarm indicator
            if (state->alarm_enabled != settings->bit.alarm_enabled) _update_alarm_indicator(settings->bit.alarm_enabled, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
			watch_display_string ( "SPEnCr", 4 );	// Or better, put your name here.
            state->this_minute_displayed = false;
            state->this_hour_displayed = false;
			watch_clear_colon();
/*
            state->signal_enabled = !state->signal_enabled;
            if (state->signal_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
            else watch_clear_indicator(WATCH_INDICATOR_BELL);
*/
            break;
        case EVENT_LIGHT_LONG_PRESS:
			watch_display_string ( "2024MA", 4 );	// Version date.
            state->this_minute_displayed = false;
            state->this_hour_displayed = false;
			watch_clear_colon();
			break;
        case EVENT_BACKGROUND_TASK:
            // uncomment this line to snap back to the clock face when the hour signal sounds:
            // movement_move_to_face(state->watch_face_index);
            #ifdef SIGNAL_TUNE_DEFAULT
            movement_play_signal();
            #else
            movement_play_tune();
            #endif
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void prime_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool prime_clock_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    prime_clock_state_t *state = (prime_clock_state_t *)context;
    if (!state->signal_enabled) return false;

    watch_date_time date_time = watch_rtc_get_date_time();

    return date_time.unit.minute == 0;
}
