/*
 * MIT License
 *
 * Copyright (c) 2024 Evgeny Stepanischev
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
#include <stdarg.h>
#include "wumpus_face.h"

#if __EMSCRIPTEN__
#include <time.h>
#endif

#define WUMPUS_FACE_ROWS 20
#define WUMPUS_FACE_COLS 3
#define WUMPUS_CLEAR_ROOM 255
#define WUMPUS_NUM_PITS 2
#define WUMPUS_NUM_BATS 2
#define WUMPUS_NUM_ARROWS 5
#define WUMPUS_MOVE_PROB 75 // %

typedef enum {
    wumpus_hazard_none = 0,
    wumpus_hazard_wumpus,
    wumpus_hazard_bat,
    wumpus_hazard_pitfall,
    wumpus_hazard_arrow,
} wumpus_hazard_type_t;

typedef enum {
    wumpus_face_shoot,
    wumpus_face_shoot_n,
    wumpus_face_shoot_rooms,
    wumpus_face_go,
    wumpus_face_choosing_room,
    wumpus_face_died,
    wumpus_face_won,
} wumpus_current_action_t;

typedef struct {
    uint8_t player_room;
    int8_t selected_room_n;
    wumpus_current_action_t current_action;

    uint8_t arrows;
    wumpus_hazard_type_t hazards[WUMPUS_FACE_ROWS];
    uint8_t hazard_point;

    bool digits_tick_show;
    bool action_tick_show;

    uint8_t shots_path_len;
    uint8_t shots_picked;
    uint8_t shots_room;
    uint8_t shots_path[WUMPUS_NUM_ARROWS];

    uint8_t led_cnt;
} wumpus_game_state_t;

static wumpus_game_state_t _state;

static const uint8_t cave_map[WUMPUS_FACE_ROWS][WUMPUS_FACE_COLS] = {
    {1, 4, 7},
    {0, 2, 9},
    {1, 3, 11},
    {2, 4, 13},
    {0, 3, 5},
    {4, 6, 14},
    {5, 7, 16},
    {0, 6, 8},
    {7, 9, 17},
    {1, 8, 10},
    {9, 11, 18},
    {2, 10, 12},
    {11, 13, 19},
    {3, 12, 14},
    {5, 13, 15},
    {14, 16, 19},
    {6, 15, 17},
    {8, 16, 18},
    {10, 17, 19},
    {12, 15, 18}
};

static inline uint8_t _get_rand_num(uint8_t num_values) {
#if __EMSCRIPTEN__
    return rand() % num_values;
#else
    return arc4random_uniform(num_values);
#endif
}

static wumpus_hazard_type_t _go_to_selected_room() {
    if (_state.selected_room_n >= 0) {
        _state.player_room = cave_map[_state.player_room][_state.selected_room_n];

        return _state.hazards[_state.player_room];
    }

    return wumpus_hazard_none;
}

static void _display_room(uint8_t room) {
    watch_display_string("  ", 2);

    if (room < 100) {
        char room_str[3];
        sprintf(room_str, "%2d", room + 1);
        watch_display_string(room_str, 2);
    }    
}

static void _display_current_room() {
    _display_room(_state.player_room);
}

static void _display_selected_room() {
    if (_state.digits_tick_show) {
        uint8_t room = _state.selected_room_n >= 0 ?
            cave_map[_state.player_room][_state.selected_room_n] :
            _state.player_room;

        _display_room(room);
    } else {
        _display_room(WUMPUS_CLEAR_ROOM);
    }
}

static void _display_current_action() {
    char buf[5];
    watch_clear_colon();

    if (_state.action_tick_show) {
        switch (_state.current_action) {
            case wumpus_face_shoot:
                _display_current_room();
                watch_display_string("SHOT", 4);
                break;

            case wumpus_face_shoot_n:
                _display_current_room();
                sprintf(buf, "rn%-2d", _state.shots_path_len);
                watch_set_colon();
                watch_display_string(buf, 4);
                break;

            case wumpus_face_shoot_rooms:
                _display_current_room();
                sprintf(buf, "r%d%-2d", _state.shots_picked + 1, _state.shots_room + 1);
                watch_set_colon();
                watch_display_string(buf, 4);
                break;

            case wumpus_face_go:
                _display_current_room();
                watch_display_string("GO  ", 4);
                break;

            case wumpus_face_choosing_room:
                _display_selected_room();
                break;

            case wumpus_face_died:
            case wumpus_face_won:
                break;
        }
    } else {
        if (_state.current_action == wumpus_face_shoot_n || _state.current_action == wumpus_face_shoot_rooms) {
            watch_set_colon();
            watch_display_string("  ", 6);
        } else {
            watch_display_string("    ", 4);
        }
    }
}

static bool _wumpus_move() {
    if (_get_rand_num(100) > WUMPUS_MOVE_PROB) {
        for (size_t i = 0; i < WUMPUS_FACE_ROWS; i++) {
            if (_state.hazards[i] == wumpus_hazard_wumpus) {
                _state.hazards[i] = wumpus_hazard_none;

                uint8_t wumpus_room = cave_map[i][_get_rand_num(3)];
                _state.hazards[wumpus_room] = wumpus_hazard_wumpus;
                return true;
            }
        }
    }

    return false;
}

static void _display_hazard(wumpus_hazard_type_t h) {
    switch (h) {
        case wumpus_hazard_wumpus:
            watch_display_string("UU", 8);
            watch_clear_pixel(1, 4);
            watch_clear_pixel(0, 5);
        break;

        case wumpus_hazard_bat:
            watch_display_string("Bt", 8);
            break;

        case wumpus_hazard_pitfall:
            watch_display_string("Pt", 8);
            break;

        case wumpus_hazard_arrow:
            watch_display_string("Ar", 8);
            break;

        case wumpus_hazard_none:
            watch_display_string("  ", 8);
            break;
    }
}

static void _display_hazards() {
    uint8_t hazards_cnt = 0;
    uint8_t hazards[WUMPUS_FACE_COLS];

    for (size_t i = 0; i < WUMPUS_FACE_COLS; i++) {
        wumpus_hazard_type_t hazard = _state.hazards[cave_map[_state.player_room][i]];

        if (hazard != wumpus_hazard_none) {
            hazards[hazards_cnt++] = hazard;
        }
    }

    if (hazards_cnt) {
        _display_hazard(hazards[_state.hazard_point]);

        if (++_state.hazard_point >= hazards_cnt) {
            _state.hazard_point = 0;
        }
    } else {
        _display_hazard(wumpus_hazard_none);
    }
}

static uint8_t _generate_unique(uint8_t player_room) {
    uint8_t value;
    bool unique;

    do {
        value =_get_rand_num(WUMPUS_FACE_ROWS);
        unique = value != player_room;

        if (unique) {
            for (size_t i = 0; i < WUMPUS_FACE_ROWS; i++) {
                if (_state.hazards[value] != wumpus_hazard_none) {
                    unique = false;
                    break;
                }
            }
        }
    } while (!unique);

    return value;
}

static void _generate_hazards(uint8_t player_room) {
    for (size_t i = 0; i < WUMPUS_FACE_ROWS; i++) {
        _state.hazards[i] = wumpus_hazard_none;
    }

    for (size_t i = 0; i < WUMPUS_NUM_PITS; i++) {
        _state.hazards[_generate_unique(player_room)] = wumpus_hazard_pitfall;
    }

    for (size_t i = 0; i < WUMPUS_NUM_BATS; i++) {
        _state.hazards[_generate_unique(player_room)] = wumpus_hazard_bat;
    }

    _state.hazards[_generate_unique(player_room)] = wumpus_hazard_wumpus;
}

static void _display_death(wumpus_hazard_type_t hazard) {
    _display_hazard(hazard);
    watch_display_string("DIED", 4);
    watch_set_led_red();
    _state.led_cnt = 3;
}

static void _display_won() {
    _display_hazard(wumpus_hazard_none);
    watch_display_string("Great", 4);
    watch_set_led_green();
    _state.led_cnt = 3;
}

static void _init_game() {
    _state.current_action = wumpus_face_shoot;
    _state.player_room = _get_rand_num(WUMPUS_FACE_ROWS);
    _state.selected_room_n = -1;
    _state.digits_tick_show = true;
    _state.action_tick_show = true;
    _state.hazard_point = 0;
    _state.shots_path_len = 0;
    _state.shots_picked = 0;
    _state.shots_room = 0;
    _state.arrows = WUMPUS_NUM_ARROWS;
    _state.led_cnt = 0;

    _generate_hazards(_state.player_room);
}

static wumpus_current_action_t _shot() {
    if (--_state.arrows < 0) {
        // Out of arrows

        _display_death(wumpus_hazard_arrow);
        return wumpus_face_died;
    }

    for (size_t i = 0; i < _state.shots_path_len; i++) {
        if (i > 0) {
            for (size_t j = 0; j < WUMPUS_FACE_COLS; j++) {
                if (cave_map[_state.shots_path[i - 1]][j] == _state.shots_path[i]) {
                    goto found;
                }
            }

            uint8_t rnd = _get_rand_num(WUMPUS_FACE_COLS);
            _state.shots_path[i] = cave_map[_state.shots_path[i - 1]][rnd];
        }

        found:

        if (_state.shots_path[i] == _state.player_room) {
            _display_death(wumpus_hazard_arrow);
            return wumpus_face_died;
        }

        // надо посмотреть можно ли пролететь дальше

        wumpus_hazard_type_t *hazard = & _state.hazards[_state.shots_path[i]];

        if (*hazard == wumpus_hazard_bat) {
            *hazard = wumpus_hazard_none;
        } else if (*hazard == wumpus_hazard_wumpus) {
            return wumpus_face_won;
        }
    }


    return wumpus_face_shoot;
}

void wumpus_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
}

void wumpus_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

#if __EMSCRIPTEN__
    time_t t;
    srand((unsigned) time(&t));
#endif    

    _init_game();
}

bool wumpus_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_display_string("WH", 0);
            _display_current_action();
            _display_hazards();
            break;
        case EVENT_TICK:
            if (_state.led_cnt > 0) {
                if (_state.led_cnt == 1) {
                    watch_set_led_off();
                    _init_game();
                    _display_current_action();
                    _display_hazards();

                    return false;
                }

                _state.led_cnt--;
            } else {
                if (_state.current_action == wumpus_face_choosing_room) {
                    _display_selected_room();
                    _state.digits_tick_show = !_state.digits_tick_show;
                } else if (_state.current_action != wumpus_face_died) {
                    _display_current_action();
                    _state.action_tick_show = !_state.action_tick_show;
                }

                if (_state.current_action != wumpus_face_died) {
                    _display_hazards();
                }
            }

            break;

        // ROLL
        case EVENT_LIGHT_BUTTON_UP:
            switch (_state.current_action) {
                case wumpus_face_shoot:
                case wumpus_face_go:
                    _state.current_action = _state.current_action == wumpus_face_go
                        ? wumpus_face_shoot : wumpus_face_go;

                    _state.action_tick_show = true;

                    break;

                case wumpus_face_shoot_n:
                    if (++_state.shots_path_len > 5) {
                        _state.shots_path_len = 1;
                    }
                    _state.action_tick_show = true;

                    break;

                case wumpus_face_shoot_rooms:
                    if (_state.shots_picked) {
                        if (++_state.shots_room >= WUMPUS_FACE_ROWS) {
                            _state.shots_room = 0;
                        }
                    } else {
                        for (size_t i = 0; i < WUMPUS_FACE_COLS; i++) {
                            if (cave_map[_state.player_room][i] == _state.shots_room) {
                                _state.shots_room = cave_map[_state.player_room][ (i + 1) % WUMPUS_FACE_COLS];
                                break;
                            }
                        }
                    }

                    _state.action_tick_show = true;
                    break;

                case wumpus_face_choosing_room:
                    if (++_state.selected_room_n >= WUMPUS_FACE_COLS) {
                        _state.selected_room_n = -1;
                    }

                    break;

                case wumpus_face_won:
                case wumpus_face_died:
                    break;
            }

            _display_current_action();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // to avoid LED default behavior
            break;

        // SELECT
        case EVENT_ALARM_BUTTON_UP:
            switch (_state.current_action) {
                case wumpus_face_go:
                    _state.selected_room_n = -1;
                    _state.digits_tick_show = false;
                    _state.action_tick_show = true;

                    _display_current_action();
                    _state.current_action = wumpus_face_choosing_room;
                    break;

                case wumpus_face_shoot:
                    _state.shots_path_len = 1;
                    _state.action_tick_show = true;
                    _state.current_action = wumpus_face_shoot_n;
                    break;

                case wumpus_face_shoot_n:
                    _state.shots_room = cave_map[_state.player_room][0];
                    _state.shots_picked = 0;
                    _state.action_tick_show = true;
                    _state.current_action = wumpus_face_shoot_rooms;
                    break;

                case wumpus_face_choosing_room:
                    {
                        wumpus_hazard_type_t result = _go_to_selected_room();

                        if (result == wumpus_hazard_none) {
                            _state.current_action = wumpus_face_go;
                            _state.digits_tick_show = true;
                            _display_hazards();
                        } else {
                            _display_death(result);
                            _state.current_action = wumpus_face_died;
                        }
                    }
                    break;

                case wumpus_face_shoot_rooms:
                    _state.shots_path[_state.shots_picked] = _state.shots_room;
                    _state.shots_room = 0;
                    _state.action_tick_show = true;
                    if (++_state.shots_picked >= _state.shots_path_len) {
                        _state.current_action = _shot();

                        if (_state.current_action == wumpus_face_won) {
                            _display_won();
                        }
                    }
                    break;


                case wumpus_face_won:
                case wumpus_face_died:
                    break;

                default:
                    break;
            }

            _display_current_action();

            if (_wumpus_move() && _state.hazards[_state.player_room] == wumpus_hazard_wumpus) {
                _display_death(wumpus_hazard_wumpus);
                _state.current_action = wumpus_face_died;
            }
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return _state.led_cnt > 0;
}

void wumpus_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

