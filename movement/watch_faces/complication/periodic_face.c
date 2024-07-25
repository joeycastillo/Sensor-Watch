/*
 * MIT License
 *
 * Copyright (c) 2023 PrimmR
 * Copyright (c) 2024 David Volovskiy
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

#define FREQ_FAST 8
#define FREQ 2

static bool _quick_ticks_running;
static uint8_t _ts_ticks = 0;
static int16_t _text_pos;
static const char* _text_looping;
static const char title_text[] = "Periodic Table";

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

    state->atomic_num = 0;
    state->mode = 0;
    state->selection_index = 0;
    _quick_ticks_running = false;
    movement_request_tick_frequency(FREQ);
}

typedef struct
{
    char symbol[3];
    char name[14];  // Longest is Rutherfordium
    int16_t year_discovered;  // Negative is BC
    uint16_t atomic_mass;  // In units of 0.01 AMU
    uint16_t electronegativity;  // In units of 0.01
    char group[3];
} element;

typedef enum {
    SCREEN_TITLE = 0,
    SCREEN_ELEMENT,
    SCREEN_ATOMIC_MASS,
    SCREEN_DISCOVER_YEAR,
    SCREEN_ELECTRONEGATIVITY,
    SCREEN_FULL_NAME,    
    SCREENS_COUNT
} PeriodicScreens;

const char screen_name[SCREENS_COUNT][3] = {
    [SCREEN_ATOMIC_MASS] = "am",
    [SCREEN_DISCOVER_YEAR] = " y",
    [SCREEN_ELECTRONEGATIVITY] = "EL",
    [SCREEN_FULL_NAME] = " n",
};

// Comments on the table denote symbols that cannot be displayed
#define MAX_ELEMENT 118
const element table[MAX_ELEMENT] = {
    { .symbol = "H", .name = "Hydrogen", .year_discovered = 1671, .atomic_mass = 101, .electronegativity = 220, .group = "  " },
    { .symbol = "HE", .name = "Helium", .year_discovered = 1868, .atomic_mass = 400, .electronegativity = 0, .group = "0" },
    { .symbol = "LI", .name = "Lithium", .year_discovered = 1817, .atomic_mass = 694, .electronegativity = 98, .group = "1" },
    { .symbol = "BE", .name = "Beryllium", .year_discovered = 1798, .atomic_mass = 901, .electronegativity = 157, .group = "2" },
    { .symbol = "B", .name = "Boron", .year_discovered = 1787, .atomic_mass = 1081, .electronegativity = 204, .group = "3" },
    { .symbol = "C", .name = "Carbon", .year_discovered = -26000, .atomic_mass = 1201, .electronegativity = 255, .group = "4" },
    { .symbol = "N", .name = "Nitrogen", .year_discovered = 1772, .atomic_mass = 1401, .electronegativity = 304, .group = "5" },
    { .symbol = "O", .name = "Oxygen", .year_discovered = 1771, .atomic_mass = 1600, .electronegativity = 344, .group = "6" },
    { .symbol = "F", .name = "Fluorine", .year_discovered = 1771, .atomic_mass = 1900, .electronegativity = 398, .group = "7" },
    { .symbol = "NE", .name = "Neon", .year_discovered = 1898, .atomic_mass = 2018, .electronegativity = 0, .group = "0" },
    { .symbol = "NA", .name = "Sodium", .year_discovered = 1702, .atomic_mass = 2299, .electronegativity = 93, .group = "1" },
    { .symbol = "MG", .name = "Magnesium", .year_discovered = 1755, .atomic_mass = 2431, .electronegativity = 131, .group = "2" },
    { .symbol = "AL", .name = "Aluminium", .year_discovered = 1746, .atomic_mass = 2698, .electronegativity = 161, .group = "3" },
    { .symbol = "SI", .name = "Silicon", .year_discovered = 1739, .atomic_mass = 2809, .electronegativity = 190, .group = "4" },
    { .symbol = "P", .name = "Phosphorus", .year_discovered = 1669, .atomic_mass = 3097, .electronegativity = 219, .group = "5" },
    { .symbol = "S", .name = "Sulfur", .year_discovered = -2000, .atomic_mass = 3206, .electronegativity = 258, .group = "6" },
    { .symbol = "CL", .name = "Chlorine", .year_discovered = 1774, .atomic_mass = 3545., .electronegativity = 316, .group = "7" },
    { .symbol = "AR", .name = "Argon", .year_discovered = 1894, .atomic_mass = 3995., .electronegativity = 0, .group = "0" },
    { .symbol = "K", .name = "Potassium", .year_discovered = 1702, .atomic_mass = 3910, .electronegativity = 82, .group = "1" },
    { .symbol = "CA", .name = "Calcium", .year_discovered = 1739, .atomic_mass = 4008, .electronegativity = 100, .group = "2" },
    { .symbol = "SC", .name = "Scandium", .year_discovered = 1879, .atomic_mass = 4496, .electronegativity = 136, .group = " T" },
    { .symbol = "TI", .name = "Titanium", .year_discovered = 1791, .atomic_mass = 4787, .electronegativity = 154, .group = " T" },
    { .symbol = "W", .name = "Vanadium", .year_discovered = 1801, .atomic_mass = 5094, .electronegativity = 163, .group = " T" },
    { .symbol = "CR", .name = "Chromium", .year_discovered = 1797, .atomic_mass = 5200, .electronegativity = 166, .group = " T" },
    { .symbol = "MN", .name = "Manganese", .year_discovered = 1774, .atomic_mass = 5494, .electronegativity = 155, .group = " T" },
    { .symbol = "FE", .name = "Iron", .year_discovered = -5000, .atomic_mass = 5585, .electronegativity = 183, .group = " T" },
    { .symbol = "CO", .name = "Cobalt", .year_discovered = 1735, .atomic_mass = 5893, .electronegativity = 188, .group = " T" },
    { .symbol = "NI", .name = "Nickel", .year_discovered = 1751, .atomic_mass = 5869, .electronegativity = 191, .group = " T" },
    { .symbol = "CU", .name = "Copper", .year_discovered = -9000, .atomic_mass = 6355, .electronegativity = 190, .group = " T" },
    { .symbol = "ZN", .name = "Zinc", .year_discovered = -1000, .atomic_mass = 6538, .electronegativity = 165, .group = " T" },
    { .symbol = "GA", .name = "Gallium", .year_discovered = 1875, .atomic_mass = 6972, .electronegativity = 181, .group = "3" },
    { .symbol = "GE", .name = "Germanium", .year_discovered = 1886, .atomic_mass = 7263, .electronegativity = 201, .group = "4" },
    { .symbol = "AS", .name = "Arsenic", .year_discovered = 300, .atomic_mass = 7492, .electronegativity = 218, .group = "5" },
    { .symbol = "SE", .name = "Selenium", .year_discovered = 1817, .atomic_mass = 7897, .electronegativity = 255, .group = "6" },
    { .symbol = "BR", .name = "Bromine", .year_discovered = 1825, .atomic_mass = 7990., .electronegativity = 296, .group = "7" },
    { .symbol = "KR", .name = "Krypton", .year_discovered = 1898, .atomic_mass = 8380, .electronegativity = 300, .group = "0" },
    { .symbol = "RB", .name = "Rubidium", .year_discovered = 1861, .atomic_mass = 8547, .electronegativity = 82, .group = "1" },
    { .symbol = "SR", .name = "Strontium", .year_discovered = 1787, .atomic_mass = 8762, .electronegativity = 95, .group = "2" },
    { .symbol = "Y", .name = "Yttrium", .year_discovered = 1794, .atomic_mass = 8891, .electronegativity = 122, .group = " T" },
    { .symbol = "ZR", .name = "Zirconium", .year_discovered = 1789, .atomic_mass = 9122, .electronegativity = 133, .group = " T" },
    { .symbol = "NB", .name = "Niobium", .year_discovered = 1801, .atomic_mass = 9291, .electronegativity = 160, .group = " T" },
    { .symbol = "MO", .name = "Molybdenum", .year_discovered = 1778, .atomic_mass = 9595, .electronegativity = 216, .group = " T" },
    { .symbol = "TC", .name = "Technetium", .year_discovered = 1937, .atomic_mass = 9700, .electronegativity = 190, .group = " T" },
    { .symbol = "RU", .name = "Ruthenium", .year_discovered = 1844, .atomic_mass = 10107, .electronegativity = 220, .group = " T" },
    { .symbol = "RH", .name = "Rhodium", .year_discovered = 1804, .atomic_mass = 10291, .electronegativity = 228, .group = " T" },
    { .symbol = "PD", .name = "Palladium", .year_discovered = 1802, .atomic_mass = 10642, .electronegativity = 220, .group = " T" },
    { .symbol = "AG", .name = "Silver", .year_discovered = -5000, .atomic_mass = 10787, .electronegativity = 193, .group = " T" },
    { .symbol = "CD", .name = "Cadmium", .year_discovered = 1817, .atomic_mass = 11241, .electronegativity = 169, .group = " T" },
    { .symbol = "IN", .name = "Indium", .year_discovered = 1863, .atomic_mass = 11482, .electronegativity = 178, .group = "3" },
    { .symbol = "SN", .name = "Tin", .year_discovered = -3500, .atomic_mass = 11871, .electronegativity = 196, .group = "4" },
    { .symbol = "SB", .name = "Antimony", .year_discovered = -3000, .atomic_mass = 12176, .electronegativity = 205, .group = "5" },
    { .symbol = "TE", .name = "Tellurium", .year_discovered = 1782, .atomic_mass = 12760, .electronegativity = 210, .group = "6" },
    { .symbol = "I", .name = "Iodine", .year_discovered = 1811, .atomic_mass = 12690, .electronegativity = 266, .group = "7" },
    { .symbol = "XE", .name = "Xenon", .year_discovered = 1898, .atomic_mass = 13129, .electronegativity = 260, .group = "0" },
    { .symbol = "CS", .name = "Caesium", .year_discovered = 1860, .atomic_mass = 13291, .electronegativity = 79, .group = "1" },
    { .symbol = "BA", .name = "Barium", .year_discovered = 1772, .atomic_mass = 13733., .electronegativity = 89, .group = "2" },
    { .symbol = "LA", .name = "Lanthanum", .year_discovered = 1838, .atomic_mass = 13891, .electronegativity = 110, .group = "1a" },
    { .symbol = "CE", .name = "Cerium", .year_discovered = 1803, .atomic_mass = 14012, .electronegativity = 112, .group = "1a" },
    { .symbol = "PR", .name = "Praseodymium", .year_discovered = 1885, .atomic_mass = 14091, .electronegativity = 113, .group = "1a" },
    { .symbol = "ND", .name = "Neodymium", .year_discovered = 1841, .atomic_mass = 14424, .electronegativity = 114, .group = "1a" },
    { .symbol = "PM", .name = "Promethium", .year_discovered = 1945, .atomic_mass = 14500, .electronegativity = 113, .group = "1a" },
    { .symbol = "SM", .name = "Samarium", .year_discovered = 1879, .atomic_mass = 15036., .electronegativity = 117, .group = "1a" },
    { .symbol = "EU", .name = "Europium", .year_discovered = 1896, .atomic_mass = 15196, .electronegativity = 120, .group = "1a" },
    { .symbol = "GD", .name = "Gadolinium", .year_discovered = 1880, .atomic_mass = 15725, .electronegativity = 120, .group = "1a" },
    { .symbol = "TB", .name = "Terbium", .year_discovered = 1843, .atomic_mass = 15893, .electronegativity = 120, .group = "1a" },
    { .symbol = "DY", .name = "Dysprosium", .year_discovered = 1886, .atomic_mass = 16250, .electronegativity = 122, .group = "1a" },
    { .symbol = "HO", .name = "Holmium", .year_discovered = 1878, .atomic_mass = 16493, .electronegativity = 123, .group = "1a" },
    { .symbol = "ER", .name = "Erbium", .year_discovered = 1843, .atomic_mass = 16726, .electronegativity = 124, .group = "1a" },
    { .symbol = "TM", .name = "Thulium", .year_discovered = 1879, .atomic_mass = 16893, .electronegativity = 125, .group = "1a" },
    { .symbol = "YB", .name = "Ytterbium", .year_discovered = 1878, .atomic_mass = 17305, .electronegativity = 110, .group = "1a" },
    { .symbol = "LU", .name = "Lutetium", .year_discovered = 1906, .atomic_mass = 17497, .electronegativity = 127, .group = "1a" },
    { .symbol = "HF", .name = "Hafnium", .year_discovered = 1922, .atomic_mass = 17849, .electronegativity = 130, .group = " T" },
    { .symbol = "TA", .name = "Tantalum", .year_discovered = 1802, .atomic_mass = 18095, .electronegativity = 150, .group = " T" },
    { .symbol = "W", .name = "Tungsten", .year_discovered = 1781, .atomic_mass = 18384, .electronegativity = 236, .group = " T" },
    { .symbol = "RE", .name = "Rhenium", .year_discovered = 1908, .atomic_mass = 18621, .electronegativity = 190, .group = " T" },
    { .symbol = "OS", .name = "Osmium", .year_discovered = 1803, .atomic_mass = 19023, .electronegativity = 220, .group = " T" },
    { .symbol = "IR", .name = "Iridium", .year_discovered = 1803, .atomic_mass = 19222, .electronegativity = 220, .group = " T" },
    { .symbol = "PT", .name = "Platinum", .year_discovered = -600, .atomic_mass = 19508, .electronegativity = 228, .group = " T" },
    { .symbol = "AU", .name = "Gold", .year_discovered = -6000, .atomic_mass = 19697, .electronegativity = 254, .group = " T" },
    { .symbol = "HG", .name = "Mercury", .year_discovered = -1500, .atomic_mass = 20059, .electronegativity = 200, .group = " T" },
    { .symbol = "TL", .name = "Thallium", .year_discovered = 1861, .atomic_mass = 20438, .electronegativity = 162, .group = "3" },
    { .symbol = "PB", .name = "Lead", .year_discovered = -7000, .atomic_mass = 20720, .electronegativity = 187, .group = "4" },
    { .symbol = "BI", .name = "Bismuth", .year_discovered = 1500, .atomic_mass = 20898, .electronegativity = 202, .group = "5" },
    { .symbol = "PO", .name = "Polonium", .year_discovered = 1898, .atomic_mass = 20900, .electronegativity = 200, .group = "6" },
    { .symbol = "AT", .name = "Astatine", .year_discovered = 1940, .atomic_mass = 21000, .electronegativity = 220, .group = "7" },
    { .symbol = "RN", .name = "Radon", .year_discovered = 1899, .atomic_mass = 22200, .electronegativity = 220, .group = "0" },
    { .symbol = "FR", .name = "Francium", .year_discovered = 1939, .atomic_mass = 22300, .electronegativity = 79, .group = "1" },
    { .symbol = "RA", .name = "Radium", .year_discovered = 1898, .atomic_mass = 22600, .electronegativity = 90, .group = "2" },
    { .symbol = "AC", .name = "Actinium", .year_discovered = 1902, .atomic_mass = 22700, .electronegativity = 110, .group = "Ac" },
    { .symbol = "TH", .name = "Thorium", .year_discovered = 1829, .atomic_mass = 23204, .electronegativity = 130, .group = "Ac" },
    { .symbol = "PA", .name = "Protactinium", .year_discovered = 1913, .atomic_mass = 23104, .electronegativity = 150, .group = "Ac" },
    { .symbol = "U", .name = "Uranium", .year_discovered = 1789, .atomic_mass = 23803, .electronegativity = 138, .group = "Ac" },
    { .symbol = "NP", .name = "Neptunium", .year_discovered = 1940, .atomic_mass = 23700, .electronegativity = 136, .group = "Ac" },
    { .symbol = "PU", .name = "Plutonium", .year_discovered = 1941, .atomic_mass = 24400, .electronegativity = 128, .group = "Ac" },
    { .symbol = "AM", .name = "Americium", .year_discovered = 1944, .atomic_mass = 24300, .electronegativity = 113, .group = "Ac" },
    { .symbol = "CM", .name = "Curium", .year_discovered = 1944, .atomic_mass = 24700, .electronegativity = 128, .group = "Ac" },
    { .symbol = "BK", .name = "Berkelium", .year_discovered = 1949, .atomic_mass = 24700, .electronegativity = 130, .group = "Ac" },
    { .symbol = "CF", .name = "Californium", .year_discovered = 1950, .atomic_mass = 25100, .electronegativity = 130, .group = "Ac" },
    { .symbol = "ES", .name = "Einsteinium", .year_discovered = 1952, .atomic_mass = 25200, .electronegativity = 130, .group = "Ac" },
    { .symbol = "FM", .name = "Fermium", .year_discovered = 1953, .atomic_mass = 25700, .electronegativity = 130, .group = "Ac" },
    { .symbol = "MD", .name = "Mendelevium", .year_discovered = 1955, .atomic_mass = 25800, .electronegativity = 130, .group = "Ac" },
    { .symbol = "NO", .name = "Nobelium", .year_discovered = 1965, .atomic_mass = 25900, .electronegativity = 130, .group = "Ac" },
    { .symbol = "LR", .name = "Lawrencium", .year_discovered = 1961, .atomic_mass = 26600, .electronegativity = 130, .group = "Ac" },
    { .symbol = "RF", .name = "Rutherfordium", .year_discovered = 1969, .atomic_mass = 26700, .electronegativity = 0, .group = " T" },
    { .symbol = "DB", .name = "Dubnium", .year_discovered = 1970, .atomic_mass = 26800, .electronegativity = 0, .group = " T" },
    { .symbol = "SG", .name = "Seaborgium", .year_discovered = 1974, .atomic_mass = 26700, .electronegativity = 0, .group = " T" },
    { .symbol = "BH", .name = "Bohrium", .year_discovered = 1981, .atomic_mass = 27000, .electronegativity = 0, .group = " T" },
    { .symbol = "HS", .name = "Hassium", .year_discovered = 1984, .atomic_mass = 27100, .electronegativity = 0, .group = " T" },
    { .symbol = "MT", .name = "Meitnerium", .year_discovered = 1982, .atomic_mass = 27800, .electronegativity = 0, .group = " T" },
    { .symbol = "DS", .name = "Darmstadtium", .year_discovered = 1994, .atomic_mass = 28100, .electronegativity = 0, .group = " T" },
    { .symbol = "RG", .name = "Roentgenium", .year_discovered = 1994, .atomic_mass = 28200, .electronegativity = 0, .group = " T" },
    { .symbol = "CN", .name = "Copernicium", .year_discovered = 1996, .atomic_mass = 28500, .electronegativity = 0, .group = " T" },
    { .symbol = "NH", .name = "Nihonium", .year_discovered = 2004, .atomic_mass = 28600, .electronegativity = 0, .group = "3" },
    { .symbol = "FL", .name = "Flerovium", .year_discovered = 1999, .atomic_mass = 28900, .electronegativity = 0, .group = "4" },
    { .symbol = "MC", .name = "Moscovium", .year_discovered = 2003, .atomic_mass = 29000, .electronegativity = 0, .group = "5" },
    { .symbol = "LW", .name = "Livermorium", .year_discovered = 2000, .atomic_mass = 29300, .electronegativity = 0, .group = "6" },
    { .symbol = "TS", .name = "Tennessine", .year_discovered = 2009, .atomic_mass = 29400, .electronegativity = 0, .group = "7" },
    { .symbol = "OG", .name = "Oganesson", .year_discovered = 2002, .atomic_mass = 29400, .electronegativity = 0, .group = "0" },
};

static void _make_upper(char *string) {
    size_t i = 0;
    while(string[i] != 0) {
        if (string[i] >= 'a' && string[i] <= 'z')
            string[i]-=32;  // 32 = 'a'-'A'
        i++;
    }
}

static void _display_element(periodic_state_t *state)
{
    char buf[9];
    char ele[3];
    uint8_t atomic_num = state->atomic_num;
    strcpy(ele, table[atomic_num - 1].symbol);
    _make_upper(ele);
    sprintf(buf, "%2s%3d %-2s", table[atomic_num - 1].group, atomic_num, ele);
    watch_display_string(buf, 2);
}

static void _display_atomic_mass(periodic_state_t *state)
{
    char buf[11];
    uint16_t mass = table[state->atomic_num - 1].atomic_mass;
    uint16_t integer = mass / 100;
    uint16_t decimal = mass % 100;
    if (decimal == 0)
        sprintf(buf, "%-2s%2s%4d", table[state->atomic_num - 1].symbol, screen_name[state->mode], integer);
    else
        sprintf(buf, "%-2s%2s%3d_%.2d", table[state->atomic_num - 1].symbol, screen_name[state->mode], integer, decimal);
    watch_display_string(buf, 0); 
}

static void _display_year_discovered(periodic_state_t *state)
{
    char buf[11];
    char year_buf[7];
    int16_t year = table[state->atomic_num - 1].year_discovered;
    if (abs(year) > 9999)
        sprintf(year_buf, "----  ");
    else
        sprintf(year_buf, "%4d  ", abs(year));
    if (year < 0) {
        year_buf[4] = 'b';
        year_buf[5] = 'c';
    }
    sprintf(buf, "%-2s%-2s%s", table[state->atomic_num - 1].symbol, screen_name[state->mode], year_buf);
    watch_display_string(buf, 0); 
}

static void _display_name(periodic_state_t *state)
{
    char buf[11];
    _text_looping = table[state->atomic_num - 1].name;
    _text_pos = 0;
    sprintf(buf, "%-2s%-2s%s", table[state->atomic_num - 1].symbol, screen_name[state->mode], table[state->atomic_num - 1].name);
    watch_display_string(buf, 0); 
}

static void _display_electronegativity(periodic_state_t *state)
{
    char buf[11];
    uint16_t electronegativity = table[state->atomic_num - 1].electronegativity;
    uint16_t integer = electronegativity / 100;
    uint16_t decimal = electronegativity % 100;
    if (decimal == 0)
        sprintf(buf, "%-2s%2s%4d", table[state->atomic_num - 1].symbol, screen_name[state->mode], integer);
    else
        sprintf(buf, "%-2s%2s%3d_%.2d", table[state->atomic_num - 1].symbol, screen_name[state->mode], integer, decimal);
    watch_display_string(buf, 0); 
}

static void start_quick_cyc(void){
    _quick_ticks_running = true;
    movement_request_tick_frequency(FREQ_FAST);
}

static void stop_quick_cyc(void){
    _quick_ticks_running = false;
    movement_request_tick_frequency(FREQ);
}

static int16_t _loop_text(const char* text, int8_t curr_loc, uint8_t char_len){
    // if curr_loc, then use that many ticks as a delay before looping
    char buf[15];
    uint8_t next_pos;
    uint8_t text_len = strlen(text);
    uint8_t pos = 10 - char_len;
    if (curr_loc == -1) curr_loc = 0;  // To avoid double-showing the 0
    if (char_len >= text_len || curr_loc < 0) {
        sprintf(buf, "%s", text);
        watch_display_string(buf, pos);
        if (curr_loc < 0) return ++curr_loc;
        return 0;
    }
    else if (curr_loc == (text_len + 1))
        curr_loc = 0;
    next_pos = curr_loc + 1;
    sprintf(buf, "%.6s %.6s", text + curr_loc, text);
    watch_display_string(buf, pos);
    return next_pos;
}

static void _display_title(periodic_state_t *state){
    state->atomic_num = 0;
    watch_clear_colon();
    watch_clear_all_indicators();
    _text_looping = title_text;
    _text_pos = FREQ * -1;
    _text_pos = _loop_text(_text_looping, _text_pos, 5);
}

static void _display_screen(periodic_state_t *state, bool should_sound){
    watch_clear_display();
    watch_clear_all_indicators();
    switch (state->mode)
    {
    case SCREEN_TITLE:
        _display_title(state);
        break;
    case SCREEN_ELEMENT:
    case SCREENS_COUNT:
        _display_element(state);
        break;
    case SCREEN_ATOMIC_MASS:
        _display_atomic_mass(state);
        break;
    case SCREEN_DISCOVER_YEAR:
        _display_year_discovered(state);
        break;
    case SCREEN_ELECTRONEGATIVITY:
        _display_electronegativity(state);
        break;
    case SCREEN_FULL_NAME:
        _display_name(state);
        break;
    }
    if (should_sound) watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
}

static void _handle_forward(periodic_state_t *state, bool should_sound){
    state->atomic_num = (state->atomic_num % MAX_ELEMENT) + 1; // Wraps back to 1
    state->mode = SCREEN_ELEMENT;
    _display_screen(state, false);
    if (should_sound) watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
}

static void _handle_backward(periodic_state_t *state, bool should_sound){
    if (state->atomic_num <= 1) state->atomic_num = MAX_ELEMENT;
    else state->atomic_num = state->atomic_num - 1;
    state->mode = SCREEN_ELEMENT;
    _display_screen(state, false);
    if (should_sound) watch_buzzer_play_note(BUZZER_NOTE_A6, 50);
}

static void _handle_mode_still_pressed(periodic_state_t *state, bool should_sound) {
    if (_ts_ticks != 0){
        if (!watch_get_pin_level(BTN_MODE)) {
            _ts_ticks = 0;
            return;
        }
        else if (--_ts_ticks == 0){
            switch (state->mode)
            {
            case SCREEN_TITLE:
                movement_move_to_face(0);
                return;
            case SCREEN_ELEMENT:
                state->mode = SCREEN_TITLE;
                _display_screen(state, should_sound);
                break;
            default:
                state->mode = SCREEN_ELEMENT;
                _display_screen(state, should_sound);
                break;
            }
            _ts_ticks = 2;
        }
    }
}

bool periodic_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    periodic_state_t *state = (periodic_state_t *)context;
    switch (event.event_type)
    {
    case EVENT_ACTIVATE:
        state->mode = SCREEN_TITLE;
        _display_screen(state, false);
        break;
    case EVENT_TICK:
        if (state->mode == SCREEN_TITLE) _text_pos = _loop_text(_text_looping, _text_pos, 5);
        else if (state->mode == SCREEN_FULL_NAME) _text_pos = _loop_text(_text_looping, _text_pos, 6);
        if (_quick_ticks_running) {
            if (watch_get_pin_level(BTN_LIGHT)) _handle_backward(state, false);
            else if (watch_get_pin_level(BTN_ALARM)) _handle_forward(state, false);
            else stop_quick_cyc();
        }

        _handle_mode_still_pressed(state, settings->bit.button_should_sound);
        break;
    case EVENT_LIGHT_BUTTON_UP:
        if (state->mode <= SCREEN_ELEMENT) {
            _handle_backward(state, settings->bit.button_should_sound);
        }
        else {
            state->mode = SCREEN_ELEMENT;
            _display_screen(state, settings->bit.button_should_sound);
        }
        break;
    case EVENT_LIGHT_BUTTON_DOWN:
        break;
    case EVENT_ALARM_BUTTON_UP:
        if (state->mode <= SCREEN_ELEMENT) {
            _handle_forward(state, settings->bit.button_should_sound);
        }
        else {
            state->mode = SCREEN_ELEMENT;
            _display_screen(state, settings->bit.button_should_sound);
        }
        break;
    case EVENT_ALARM_LONG_PRESS:
        if (state->mode <= SCREEN_ELEMENT) {
            start_quick_cyc();
            _handle_forward(state, settings->bit.button_should_sound);
        }
        break;
    case EVENT_LIGHT_LONG_PRESS:
        if (state->mode <= SCREEN_ELEMENT) {
            start_quick_cyc();
            _handle_backward(state, settings->bit.button_should_sound);
        }
        else {
            movement_illuminate_led();
        }
        break;
    case EVENT_MODE_BUTTON_UP:
        if (state->mode == SCREEN_TITLE) movement_move_to_next_face();
        else {
            state->mode = (state->mode + 1) % SCREENS_COUNT;
            if (state->mode == SCREEN_TITLE)
                state->mode = (state->mode + 1) % SCREENS_COUNT;
            if (state->mode == SCREEN_ELEMENT){
                _display_screen(state, false);
                if (settings->bit.button_should_sound) watch_buzzer_play_note(BUZZER_NOTE_A6, 50);
            }
            else
                _display_screen(state, settings->bit.button_should_sound);
        }
        break;
    case EVENT_MODE_LONG_PRESS:
        switch (state->mode)
        {
        case SCREEN_TITLE:
            movement_move_to_face(0);
            return true;
        case SCREEN_ELEMENT:
            state->mode = SCREEN_TITLE;
            _display_screen(state, settings->bit.button_should_sound);
            break;
        default:
            state->mode = SCREEN_ELEMENT;
            _display_screen(state, settings->bit.button_should_sound);
            break;
        }
        _ts_ticks = 2;
        break;
    case EVENT_TIMEOUT:
        // Display title after timeout
        if (state->mode == SCREEN_TITLE) break;
        state->mode = SCREEN_TITLE;
        _display_screen(state, false);
        break;
    case EVENT_LOW_ENERGY_UPDATE:
        // Display static title and tick animation during LE
        watch_display_string("Pd   Table", 0);
        watch_start_tick_animation(500);
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
