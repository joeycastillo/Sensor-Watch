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
#include "periodic_face.h"

void periodic_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr)
{
    (void)settings;
    (void)watch_face_index;
    if (*context_ptr == NULL)
    {
        *context_ptr = malloc(sizeof(periodic_state_t));
        memset(*context_ptr, 0, sizeof(periodic_state_t));
    }
}

void periodic_face_activate(movement_settings_t *settings, void *context)
{
    (void)settings;
    periodic_state_t *state = (periodic_state_t *)context;

    state->atomic_num = 1;
    state->mode = 0;
    state->selection_index = 0;

    movement_request_tick_frequency(2);
}

typedef struct
{
    char name[3];
    uint16_t atomic_mass;
    char group[3];
} element;

// Comments on the table denote symbols that cannot be displayed
#define MAX_ELEMENT 118
const element table[MAX_ELEMENT] = {
    {"H ", 1, "  "},
    {"He", 4, " 0"},
    {"Li", 7, " 1"},
    {"Be", 9, " 2"},
    {"B ", 11, " 3"},
    {"C ", 12, " 4"},
    {"N ", 14, " 5"},
    {"O ", 16, " 6"},
    {"F ", 19, " 7"},
    {"Ne", 20, " 0"},
    {"Na", 23, " 1"},
    {"Mg", 24, " 2"}, //
    {"Al", 27, " 3"},
    {"Si", 28, " 4"},
    {"P ", 31, " 5"},
    {"S ", 32, " 6"},
    {"Cl", 355, " 7"},
    {"Ar", 40, " 0"},
    {"K ", 39, " 1"},
    {"Ca", 40, " 2"},
    {"Sc", 45, " T"},
    {"Ti", 48, " T"},
    {" W", 51, " T"}, // "V"
    {"Cr", 52, " T"},
    {"Mn", 55, " T"},
    {"Fe", 56, " T"},
    {"Co", 59, " T"},
    {"Ni", 59, " T"},
    {"Cu", 635, " T"},
    {"Zn", 65, " T"},
    {"Ga", 70, " 3"},
    {"Ge", 73, " 4"},
    {"As", 75, " 5"}, //
    {"Se", 79, " 6"},
    {"Br", 80, " 7"},
    {"Kr", 84, " 0"},
    {"Rb", 85, " 1"},
    {"Sr", 88, " 2"},
    {"Y ", 89, " T"},
    {"Zr", 91, " T"},
    {"Nb", 93, " T"},
    {"Mo", 96, " T"},
    {"Tc", 97, " T"},
    {"Ru", 101, " T"},
    {"Rh", 103, " T"},
    {"Pd", 106, " T"},
    {"Ag", 108, " T"}, //
    {"Cd", 112, " T"},
    {"In", 115, " 3"},
    {"Sn", 119, " 4"},
    {"Sb", 122, " 5"},
    {"Te", 128, " 6"},
    {"I ", 127, " 7"},
    {"Xe", 131, " 0"},
    {"CS", 133, " 1"},
    {"Ba", 137, " 2"},
    {"La", 139, "1a"}, // La
    {"Ce", 140, "1a"},
    {"Pr", 141, "1a"},
    {"Nd", 144, "1a"},
    {"Pm", 145, "1a"},
    {"Sm", 150, "1a"},
    {"Eu", 152, "1a"},
    {"Gd", 157, "1a"},
    {"Tb", 159, "1a"},
    {"Dy", 163, "1a"}, // .5 Rounded up due to space constraints
    {"Ho", 165, "1a"},
    {"Er", 167, "1a"},
    {"Tm", 169, "1a"},
    {"Yb", 173, "1a"},
    {"Lu", 175, "1a"},
    {"Hf", 179, " T"},
    {"Ta", 181, " T"},
    {"W ", 184, " T"},
    {"Re", 186, " T"},
    {"OS", 190, " T"},
    {"Ir", 192, " T"},
    {"Pt", 195, " T"},
    {"Au", 197, " T"},
    {"Hg", 201, " T"}, //
    {"Tl", 204, " 3"},
    {"Pb", 207, " 4"},
    {"Bi", 209, " 5"},
    {"Po", 209, " 6"},
    {"At", 210, " 7"},
    {"Rn", 222, " 0"},
    {"Fr", 223, " 1"},
    {"Ra", 226, " 2"},
    {"Ac", 227, "Ac"},
    {"Th", 232, "Ac"},
    {"Pa", 231, "Ac"},
    {"U ", 238, "Ac"},
    {"Np", 237, "Ac"}, //
    {"Pu", 244, "Ac"},
    {"Am", 243, "Ac"},
    {"Cm", 247, "Ac"},
    {"Bk", 247, "Ac"}, //
    {"Cf", 251, "Ac"},
    {"Es", 252, "Ac"}, //
    {"Fm", 257, "Ac"},
    {"Md", 258, "Ac"},
    {"No", 259, "Ac"},
    {"Lr", 262, "Ac"},
    {"Rf", 267, " T"},
    {"Db", 262, " T"},
    {"Sg", 269, " T"}, //
    {"Bh", 264, " T"},
    {"Hs", 269, " T"},
    {"Mt", 278, " T"},
    {"Ds", 281, " T"}, //
    {"Rg", 282, " T"}, //
    {"Cn", 285, " T"},
    {"Nh", 286, " 3"},
    {"Fl", 289, " 4"},
    {"Mc", 289, " 5"},
    {"LW", 293, " 6"}, // Lv
    {"Ts", 294, " 7"}, //
    {"Og", 294, " 0"}, //
};

// Warning light for symbols that can't be displayed
static void _warning(periodic_state_t *state)
{
    char second_char = table[state->atomic_num - 1].name[1];
    if (second_char == 'p' || second_char == 'g' || second_char == 'y' || second_char == 's')
    {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    }
    else
    {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
}

// Regular mode display
static void _periodic_face_update_lcd(periodic_state_t *state)
{
    // Colon as a decimal for Cl & Cu
    if (state->atomic_num == 17 || state->atomic_num == 29)
    {
        watch_set_colon();
    }
    else
    {
        watch_clear_colon();
    }

    _warning(state);

    char buf[11];
    sprintf(buf, "%s%s%-3d%3d", table[state->atomic_num - 1].name, table[state->atomic_num - 1].group, table[state->atomic_num - 1].atomic_mass, state->atomic_num);
    watch_display_string(buf, 0);
}

// Selection mode logic
static void _periodic_face_selection_increment(periodic_state_t *state)
{
    uint8_t digit0 = (state->atomic_num / 100) % 10;
    uint8_t digit1 = (state->atomic_num / 10) % 10;
    uint8_t digit2 = (state->atomic_num) % 10;

    // Increment the selected digit by 1
    switch (state->selection_index)
    {
    case 0:
        digit0 ^= 1;
        break;
    case 1:
        if (digit0 == MAX_ELEMENT / 100 && digit1 == (MAX_ELEMENT / 10) % 10)
            digit1 = 0;
        else
            digit1 = (digit1 + 1) % 10;
        break;
    case 2:
        if (digit0 == MAX_ELEMENT / 100 && digit1 == (MAX_ELEMENT / 10) % 10 && digit2 == MAX_ELEMENT % 10)
            digit2 = 0;
        else
            digit2 = (digit2 + 1) % 10;
        break;
    }

    // Prevent 000
    if (digit0 == 0 && digit1 == 0 && digit2 == 0) {
        digit2 = 1;
    }

    // Prevent Overflow
    if (digit0 == (MAX_ELEMENT / 100) % 10 && digit1 > (MAX_ELEMENT / 10) % 10)
    {
        digit2 = MAX_ELEMENT % 10;
        digit1 = (MAX_ELEMENT / 10) % 10;
    }

    state->atomic_num = digit0 * 100 + digit1 * 10 + digit2;
}

// Selection mode display
static void _periodic_face_selection(periodic_state_t *state, uint8_t subsec)
{
    uint8_t digit0 = (state->atomic_num / 100) % 10;
    uint8_t digit1 = (state->atomic_num / 10) % 10;
    uint8_t digit2 = (state->atomic_num) % 10;

    watch_display_string("          ", 0);

    char buf[2] = {'\0'};

    buf[0] = (state->selection_index == 0 && subsec == 0) ? ' ' : digit0 + '0';
    watch_display_string(buf, 5);

    buf[0] = (state->selection_index == 1 && subsec == 0) ? ' ' : digit1 + '0';
    watch_display_string(buf, 6);

    buf[0] = (state->selection_index == 2 && subsec == 0) ? ' ' : digit2 + '0';
    watch_display_string(buf, 7);

    char buf2[3];
    sprintf(buf2, "%s", table[state->atomic_num - 1].name);
    watch_display_string(buf2, 0);

    _warning(state);
}

bool periodic_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    periodic_state_t *state = (periodic_state_t *)context;

    switch (event.event_type)
    {
    case EVENT_ACTIVATE:
        _periodic_face_update_lcd(state);
        break;
    case EVENT_TICK:
        if (state->mode != 0)
        {
            _periodic_face_selection(state, event.subsecond % 2);
        }
        break;
    case EVENT_LIGHT_BUTTON_UP:
        // Only light LED when in regular mode
        if (state->mode != MODE_VIEW)
        {
            state->selection_index = (state->selection_index + 1) % 3;
            _periodic_face_selection(state, event.subsecond % 2);
        }
        break;
    case EVENT_LIGHT_BUTTON_DOWN:
        if (state->mode != MODE_SELECT)
            movement_illuminate_led();
        break;
    case EVENT_ALARM_BUTTON_UP:
        if (state->mode == MODE_VIEW)
        {
            state->atomic_num = (state->atomic_num % MAX_ELEMENT) + 1; // Wraps back to 1
            _periodic_face_update_lcd(state);
            if (settings->bit.button_should_sound) watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
        }
        else
        {
            _periodic_face_selection_increment(state);
            _periodic_face_selection(state, event.subsecond % 2);
        }
        break;
    case EVENT_ALARM_LONG_PRESS:
        // Toggle between selection mode and regular
        if (state->mode == MODE_VIEW)
        {
            state->mode = MODE_SELECT;
            _periodic_face_selection(state, event.subsecond % 2);
        }
        else
        {
            state->mode = MODE_VIEW;
            _periodic_face_update_lcd(state);
        }
            if (settings->bit.button_should_sound) watch_buzzer_play_note(BUZZER_NOTE_C8, 50);

        break;
    case EVENT_TIMEOUT:
        break;
    case EVENT_LOW_ENERGY_UPDATE:
        break;
    default:
        return movement_default_loop_handler(event, settings);
    }

    return true;
}

void periodic_face_resign(movement_settings_t *settings, void *context)
{
    (void)settings;
    (void)context;

    // handle any cleanup before your watch face goes off-screen.
}
