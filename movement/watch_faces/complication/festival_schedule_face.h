/*
 * MIT License
 *
 * Copyright (c) 2024 <David Volovskiy>
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


 /*
 * Festival Schedule Face
 * Shows acts performing in different stages at a Festival
 * Use festival_act_popularity_sorter.ipynb to create the Festival array
 * 
 * Screens:
 *    Title - Shows the either what day of the festival it is or how many days until the festival
 *    Act - Displays the name of the performing act. The top shows the stage they're on
 *    Genre - Displays the act's genre
 *    Start Time - Displays the act's start time
 *    End Time - Displays the act's end time
 * 
 * Loop Through All Acts:
 *    Normally, you can only view acts that are currently performing. If no acts are currently performing,
 *    you'll see 'no Act'. But by holding the Light of Alarm button on the title will allow you to loop through
 *    all acts in alphabetical order (or whatever order they are in festival_schedule_arr.h).
 *    Looping through all acts will be indicated by LAP.
 *    Most of the screens will be the same, except the Genre screen will now show the weekday that the act is performing at.
 * 
 * Controls:
 *    Alarm Press
 *        Show next act
 *    Alarm Hold
 *        If on Title: Enter looping through all acts, displaying the last act alphabetically
 *        Else: Fast-scroll through acts forward
 * 
 *    Light Press
 *        Show previous act
 *    Light Hold
 *        If on Title: Enter looping through all acts, displaying the first act alphabetically
 *        If diplaying Genre of Start/End times: Turn on LED
 *        Else: Fast-scroll through acts backwards
 * 
 *    Mode Press
 *        If on Title: Move to next watch face
 *        If text is not looping but can: Loop text.
 *        If text is looping or is too small to loop: show Genre -> Start Time -> End Time
 *    Mode Hold
 *        If on Title: Jump to first movement on watch; normally the watch face
 *        Else: Move out of current screen
 *     Holding mode will chain its action. So if you're in Genre, if you keep holding Mode, 
 *     then Genre will move to Act, which will move to Title, which will leave the face.
 */


#ifndef FESTIVAL_SCHEDULE_FACE_H_
#define FESTIVAL_SCHEDULE_FACE_H_

#include "movement.h"


typedef enum {
    FESTIVAL_SCHEDULE_NO_STAGE = 0,
    FESTIVAL_SCHEDULE_T_MOBILE,
    FESTIVAL_SCHEDULE_BUD_LIGHT,
    FESTIVAL_SCHEDULE_PERRYS,
    FESTIVAL_SCHEDULE_THE_GROVE,
    FESTIVAL_SCHEDULE_LAKESHORE,
    FESTIVAL_SCHEDULE_TITOS,
    FESTIVAL_SCHEDULE_BMI,
    FESTIVAL_SCHEDULE_MUSIC_DEN,
    FESTIVAL_SCHEDULE_BACKYARD,
    FESTIVAL_SCHEDULE_STAGE_COUNT
} festival_schedule_stage;

typedef enum {
    FESTIVAL_SCHEDULE_NO_GENRE = 0,
    FESTIVAL_SCHEDULE_POP,
    FESTIVAL_SCHEDULE_INDIE,
    FESTIVAL_SCHEDULE_DREAM_POP,
    FESTIVAL_SCHEDULE_K_POP,
    FESTIVAL_SCHEDULE_ROCK,
    FESTIVAL_SCHEDULE_ALT,
    FESTIVAL_SCHEDULE_PUNK,
    FESTIVAL_SCHEDULE_NU_METAL,
    FESTIVAL_SCHEDULE_PSYCH_ROCK,
    FESTIVAL_SCHEDULE_HOUSE,
    FESTIVAL_SCHEDULE_DUBSTEP,
    FESTIVAL_SCHEDULE_BASS,
    FESTIVAL_SCHEDULE_TECHNO,
    FESTIVAL_SCHEDULE_DnB,
    FESTIVAL_SCHEDULE_DANCE,
    FESTIVAL_SCHEDULE_RAP,
    FESTIVAL_SCHEDULE_TRAP,
    FESTIVAL_SCHEDULE_EMORAP,
    FESTIVAL_SCHEDULE_SOUL,
    FESTIVAL_SCHEDULE_RnB,
    FESTIVAL_SCHEDULE_COUNTRY,
    FESTIVAL_SCHEDULE_FOLK,
    FESTIVAL_SCHEDULE_OTHER,
    FESTIVAL_SCHEDULE_GENRE_COUNT
} festival_schedule_genre;

typedef enum {
    FESTIVAL_SCHEDULE_SCREEN_TITLE = 0,
    FESTIVAL_SCHEDULE_SCREEN_ACT,
    FESTIVAL_SCHEDULE_SCREEN_GENRE,
    FESTIVAL_SCHEDULE_SCREEN_START_TIME,
    FESTIVAL_SCHEDULE_SCREEN_END_TIME,    
    FESTIVAL_SCHEDULE_SCREENS_COUNT
} festival_schedule_screens;

typedef enum {
    FESTIVAL_SCHEDULE_TICK_NONE = 0,
    FESTIVAL_SCHEDULE_TICK_SCREEN,
    FESTIVAL_SCHEDULE_TICK_LEAVE,
    FESTIVAL_SCHEDULE_TICK_CYCLE
} festival_schedule_tick_reason;

typedef struct {
    char artist[25];
    festival_schedule_stage stage;
    watch_date_time start_time;
    watch_date_time end_time;
    festival_schedule_genre genre;
    uint8_t popularity;
} festival_schedule_t;

#define SHOW_EMPTY_STAGES false

typedef struct {
    festival_schedule_stage curr_stage;
    festival_schedule_stage prev_stage;
    uint8_t curr_act;
    uint8_t prev_act;
    uint16_t prev_day : 15;
    festival_schedule_screens curr_screen;
    bool cyc_through_all_acts;
    bool festival_occurring;
    
} festival_schedule_state_t;

void festival_schedule_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void festival_schedule_face_activate(movement_settings_t *settings, void *context);
bool festival_schedule_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void festival_schedule_face_resign(movement_settings_t *settings, void *context);

#define festival_schedule_face ((const watch_face_t){ \
    festival_schedule_face_setup, \
    festival_schedule_face_activate, \
    festival_schedule_face_loop, \
    festival_schedule_face_resign, \
    NULL, \
})

#endif // FESTIVAL_SCHEDULE_FACE_H_

