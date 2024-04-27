/*
 * MIT License
 *
 * Copyright (c) 2023 Curtis J. Brown <mrbrown8@juno.com>
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

#ifndef DECIMAL_TIME_FACE_H_
#define DECIMAL_TIME_FACE_H_

/*
 * DECIMAL TIME face
 * 
 * This face presents the current time as hours and hundredths of an hour. Every hundreth of an hour, or "centihour", 
 * occurs every 36 seconds. Because they range from 0 to 99, centihours, in the seventies range, will be displayed with a lowercase 7.
 * 
 * See https://en.wikipedia.org/wiki/Decimal_time#Decimal_hours
 *  
 * This method of timekeeping is used by the United States Postal Service.
 * http://www.branch38nalc.com/sitebuildercontent/sitebuilderfiles/CONVERSION_TABLE_TIME.pdf
 * https://postalemployeenetwork.com/time-conversion-print.htm
 * 
 * This method may be used by other organizations as well
 * https://www.labor.nc.gov/workplace-rights/employer-responsibilities/time-conversion-chart-minutes-decimal-hours
 * https://uh.edu/office-of-finance/payroll/time_conversion_chart_minutes_to_decimalhours.pdf
 * https://www.placer.ca.gov/DocumentCenter/View/3860/Decimals-to-Minutes-Conversion-Table-PDF
 * https://hr.colostate.edu/minute-to-decimal-conversion-chart/
 * 
 * Many thanks go to Joey Castillo for making this project happen.
 */

#include "movement.h"

typedef struct {
    bool chime_enabled;            // did the user enable hourly chime for this face? 
    uint8_t features_to_show : 2 ; // what features are to be displayed?
} decimal_time_face_state_t;

void decimal_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void decimal_time_face_activate(movement_settings_t *settings, void *context);
bool decimal_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void decimal_time_face_resign(movement_settings_t *settings, void *context);
// void decimal_time_face_wants_background_task();


#define decimal_time_face ((const watch_face_t){ \
    decimal_time_face_setup, \
    decimal_time_face_activate, \
    decimal_time_face_loop, \
    decimal_time_face_resign, \
    NULL, \
})

#endif // DECIMAL_TIME_FACE_H_
