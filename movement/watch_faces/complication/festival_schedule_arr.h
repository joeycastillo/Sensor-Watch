// Genre - https://docs.google.com/document/d/1aEJK7fxm-8BUmWOp24QD2GEpIR2YVU3pmbc23-I2vgc/edit?tab=t.0
// Line-up - https://clashfinder.com/m/lolla2025/
#include "festival_schedule_face.h"

#define NUM_ACTS 171

const schedule_t festival_acts[NUM_ACTS + 1]=
{
    {
        .artist = "2HOLLI",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .genre = EMORAP,
        .popularity = 59
    },
    {
        .artist = "A$AP R",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = TRAP,
        .popularity = 5
    },
    {
        .artist = "ALEMED",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 144
    },
    {
        .artist = "ALEX W",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 45},
        .genre = DREAM_POP,
        .popularity = 17
    },
    {
        .artist = "ALEXSU",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 35},
        .genre = ALT,
        .popularity = 137
    },
    {
        .artist = "ALIYAH",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 86
    },
    {
        .artist = "ALLEYC",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 45},
        .genre = DUBSTEP,
        .popularity = 116
    },
    {
        .artist = "AMAARA",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 5},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 5},
        .genre = OTHER,
        .popularity = 52
    },
    {
        .artist = "ARTEMA",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 45},
        .genre = POP,
        .popularity = 25
    },
    {
        .artist = "AZZECC",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 139
    },
    {
        .artist = "BARRY ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 25},
        .genre = HOUSE,
        .popularity = 64
    },
    {
        .artist = "BENCHE",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 0},
        .genre = ROCK,
        .popularity = 126
    },
    {
        .artist = "BILMUR",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = PUNK,
        .popularity = 76
    },
    {
        .artist = "BLACK ",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 45},
        .genre = RnB,
        .popularity = 134
    },
    {
        .artist = "BLADEE",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 45},
        .genre = EMORAP,
        .popularity = 46
    },
    {
        .artist = "BLEACH",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 43
    },
    {
        .artist = "BLESSE",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 40},
        .genre = HOUSE,
        .popularity = 55
    },
    {
        .artist = "BLK OD",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 15},
        .genre = SOUL,
        .popularity = 103
    },
    {
        .artist = "BO STA",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 5},
        .genre = POP,
        .popularity = 127
    },
    {
        .artist = "BOA   ",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .genre = ALT,
        .popularity = 31
    },
    {
        .artist = "BOSSMA",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .genre = TRAP,
        .popularity = 33
    },
    {
        .artist = "BOYNEX",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 15},
        .genre = K_POP,
        .popularity = 32
    },
    {
        .artist = "BUNT. ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 5},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 5},
        .genre = HOUSE,
        .popularity = 47
    },
    {
        .artist = "CA7RIE",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .genre = SOUL,
        .popularity = 0
    },
    {
        .artist = "CAGE E",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .genre = ALT,
        .popularity = 15
    },
    {
        .artist = "CAROLE",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 15},
        .genre = INDIE,
        .popularity = 0
    },
    {
        .artist = "CAROLI",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 5},
        .genre = POP,
        .popularity = 132
    },
    {
        .artist = "CARTER",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 15},
        .genre = INDIE,
        .popularity = 125
    },
    {
        .artist = "CASSAN",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 55},
        .genre = DREAM_POP,
        .popularity = 0
    },
    {
        .artist = "CHARLO",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .genre = POP,
        .popularity = 79
    },
    {
        .artist = "CHASE ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 15},
        .genre = DnB,
        .popularity = 30
    },
    {
        .artist = "CHICAG",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 55},
        .genre = OTHER,
        .popularity = 0
    },
    {
        .artist = "CHICAG",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .genre = OTHER,
        .popularity = 158
    },
    {
        .artist = "CLAIRO",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .genre = DREAM_POP,
        .popularity = 10
    },
    {
        .artist = "CLOONE",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 10},
        .genre = HOUSE,
        .popularity = 71
    },
    {
        .artist = "COLBY ",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 15},
        .genre = COUNTRY,
        .popularity = 95
    },
    {
        .artist = "CRITIC",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 5},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 50},
        .genre = PUNK,
        .popularity = 148
    },
    {
        .artist = "DAMIAN",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .genre = POP,
        .popularity = 39
    },
    {
        .artist = "DANIEL",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 40},
        .genre = HOUSE,
        .popularity = 123
    },
    {
        .artist = "DARE  ",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 45},
        .genre = POP,
        .popularity = 91
    },
    {
        .artist = "DEL WA",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 68
    },
    {
        .artist = "DJ HEA",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 156
    },
    {
        .artist = "DJO   ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 45},
        .genre = PSYCH_ROCK,
        .popularity = 0
    },
    {
        .artist = "DOECHI",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = RAP,
        .popularity = 11
    },
    {
        .artist = "DOGPAR",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 5},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 50},
        .genre = INDIE,
        .popularity = 138
    },
    {
        .artist = "DOM DO",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 35
    },
    {
        .artist = "DOMINI",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 18
    },
    {
        .artist = "DR. FR",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 5},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 5},
        .genre = BASS,
        .popularity = 114
    },
    {
        .artist = "DROPTI",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 30},
        .genre = ROCK,
        .popularity = 124
    },
    {
        .artist = "DUA SA",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 15},
        .genre = RnB,
        .popularity = 130
    },
    {
        .artist = "DURAND",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .genre = RnB,
        .popularity = 100
    },
    {
        .artist = "EDDIE ",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 45},
        .genre = ALT,
        .popularity = 106
    },
    {
        .artist = "FCUKER",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 20},
        .genre = DANCE,
        .popularity = 129
    },
    {
        .artist = "FINNEA",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 27
    },
    {
        .artist = "FLIPTU",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 69
    },
    {
        .artist = "FLOWER",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 5},
        .genre = DREAM_POP,
        .popularity = 102
    },
    {
        .artist = "FLUX P",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 50},
        .genre = DUBSTEP,
        .popularity = 80
    },
    {
        .artist = "FOSTER",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 19
    },
    {
        .artist = "FUJII ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .genre = K_POP,
        .popularity = 16
    },
    {
        .artist = "GIGI P",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 45},
        .genre = ALT,
        .popularity = 20
    },
    {
        .artist = "GIRL T",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 40},
        .genre = ALT,
        .popularity = 154
    },
    {
        .artist = "GLASS ",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .genre = ROCK,
        .popularity = 96
    },
    {
        .artist = "GRACIE",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .genre = DREAM_POP,
        .popularity = 8
    },
    {
        .artist = "GRAHAM",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 50},
        .genre = COUNTRY,
        .popularity = 74
    },
    {
        .artist = "GRYFFI",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 30},
        .genre = BASS,
        .popularity = 40
    },
    {
        .artist = "HALF A",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 0
    },
    {
        .artist = "HEX CO",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 35},
        .genre = DUBSTEP,
        .popularity = 141
    },
    {
        .artist = "HEY, N",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 0},
        .genre = ALT,
        .popularity = 99
    },
    {
        .artist = "IAN   ",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 45},
        .genre = TRAP,
        .popularity = 0
    },
    {
        .artist = "ISABEL",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 10},
        .genre = POP,
        .popularity = 24
    },
    {
        .artist = "ISAIAH",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 45},
        .genre = RAP,
        .popularity = 29
    },
    {
        .artist = "ISOXO ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 97
    },
    {
        .artist = "JADE L",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 25},
        .genre = POP,
        .popularity = 54
    },
    {
        .artist = "JANE R",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .genre = EMORAP,
        .popularity = 105
    },
    {
        .artist = "JESSE ",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 20},
        .genre = ALT,
        .popularity = 149
    },
    {
        .artist = "JEV   ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 0
    },
    {
        .artist = "JIGITZ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 5},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 92
    },
    {
        .artist = "JOE P ",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 55},
        .genre = INDIE,
        .popularity = 121
    },
    {
        .artist = "JOEY V",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 45},
        .genre = RAP,
        .popularity = 53
    },
    {
        .artist = "JPEGMA",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .genre = RAP,
        .popularity = 41
    },
    {
        .artist = "JULIE ",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 10},
        .genre = DREAM_POP,
        .popularity = 88
    },
    {
        .artist = "JUNIOR",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .genre = ALT,
        .popularity = 122
    },
    {
        .artist = "KAICRE",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 40},
        .genre = RAP,
        .popularity = 153
    },
    {
        .artist = "KATSEY",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 35},
        .genre = POP,
        .popularity = 42
    },
    {
        .artist = "KENNY ",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 35},
        .genre = RAP,
        .popularity = 82
    },
    {
        .artist = "KICKFL",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .genre = K_POP,
        .popularity = 98
    },
    {
        .artist = "KNOCK2",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = BASS,
        .popularity = 73
    },
    {
        .artist = "KORN  ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = NU_METAL,
        .popularity = 9
    },
    {
        .artist = "LA FEM",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 25},
        .genre = PSYCH_ROCK,
        .popularity = 78
    },
    {
        .artist = "LAILA!",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 45},
        .genre = RnB,
        .popularity = 93
    },
    {
        .artist = "LANDON",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 5},
        .genre = PUNK,
        .popularity = 140
    },
    {
        .artist = "LANDON",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 55},
        .genre = INDIE,
        .popularity = 0
    },
    {
        .artist = "LATIN ",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 45},
        .genre = RnB,
        .popularity = 26
    },
    {
        .artist = "LAYZ  ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .genre = DUBSTEP,
        .popularity = 142
    },
    {
        .artist = "LEKAN ",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 40},
        .genre = SOUL,
        .popularity = 147
    },
    {
        .artist = "LEVITY",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .genre = DUBSTEP,
        .popularity = 104
    },
    {
        .artist = "LUKE C",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = COUNTRY,
        .popularity = 6
    },
    {
        .artist = "MAGDAL",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .genre = POP,
        .popularity = 49
    },
    {
        .artist = "MARIAH",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 45},
        .genre = RnB,
        .popularity = 45
    },
    {
        .artist = "MARIAS",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 45},
        .genre = DREAM_POP,
        .popularity = 0
    },
    {
        .artist = "MARIBO",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 55},
        .genre = DANCE,
        .popularity = 44
    },
    {
        .artist = "MARK A",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .genre = FOLK,
        .popularity = 34
    },
    {
        .artist = "MARLON",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 5},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 15},
        .genre = TECHNO,
        .popularity = 65
    },
    {
        .artist = "MARTIN",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 7
    },
    {
        .artist = "MARY D",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 35},
        .genre = BASS,
        .popularity = 152
    },
    {
        .artist = "MATT C",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .genre = RAP,
        .popularity = 118
    },
    {
        .artist = "MAU P ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 35},
        .genre = HOUSE,
        .popularity = 61
    },
    {
        .artist = "MAX MC",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .genre = COUNTRY,
        .popularity = 36
    },
    {
        .artist = "MIDNIG",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 35},
        .genre = OTHER,
        .popularity = 115
    },
    {
        .artist = "MK.GEE",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .genre = DREAM_POP,
        .popularity = 62
    },
    {
        .artist = "MONTEL",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .genre = SOUL,
        .popularity = 23
    },
    {
        .artist = "MURDA ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 55},
        .genre = TRAP,
        .popularity = 83
    },
    {
        .artist = "NAOMI ",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 0},
        .genre = POP,
        .popularity = 75
    },
    {
        .artist = "NEW DA",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 0
    },
    {
        .artist = "NIMINO",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 20},
        .genre = HOUSE,
        .popularity = 56
    },
    {
        .artist = "NOURIS",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 5},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 50},
        .genre = POP,
        .popularity = 136
    },
    {
        .artist = "OCEAN ",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 45},
        .genre = PSYCH_ROCK,
        .popularity = 57
    },
    {
        .artist = "OLD ME",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 45},
        .genre = ALT,
        .popularity = 111
    },
    {
        .artist = "OLE 60",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .genre = ROCK,
        .popularity = 63
    },
    {
        .artist = "OLIVIA",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = POP,
        .popularity = 1
    },
    {
        .artist = "ORION ",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .genre = RnB,
        .popularity = 66
    },
    {
        .artist = "ORLA G",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 20},
        .genre = ROCK,
        .popularity = 112
    },
    {
        .artist = "OTOBOK",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 0},
        .genre = PUNK,
        .popularity = 146
    },
    {
        .artist = "OVERMO",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 55},
        .genre = DnB,
        .popularity = 94
    },
    {
        .artist = "PEOPLE",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 50},
        .genre = PUNK,
        .popularity = 133
    },
    {
        .artist = "PROSPA",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 35},
        .genre = HOUSE,
        .popularity = 110
    },
    {
        .artist = "RACHEL",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 90
    },
    {
        .artist = "RAECOL",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 155
    },
    {
        .artist = "RATBOY",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 0},
        .genre = ALT,
        .popularity = 143
    },
    {
        .artist = "RAVYN ",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 45},
        .genre = SOUL,
        .popularity = 37
    },
    {
        .artist = "REBECC",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .genre = TECHNO,
        .popularity = 84
    },
    {
        .artist = "REMI W",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .genre = POP,
        .popularity = 51
    },
    {
        .artist = "ROLE M",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 28
    },
    {
        .artist = "ROYEL ",
        .stage = NO_STAGE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 38
    },
    {
        .artist = "RUFUS ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 21
    },
    {
        .artist = "SABRIN",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = POP,
        .popularity = 3
    },
    {
        .artist = "SALUTE",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 108
    },
    {
        .artist = "SAM AU",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .genre = POP,
        .popularity = 81
    },
    {
        .artist = "SAMMY ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 25},
        .genre = DnB,
        .popularity = 60
    },
    {
        .artist = "SIERRA",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .genre = FOLK,
        .popularity = 67
    },
    {
        .artist = "SILLY ",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 15},
        .genre = NU_METAL,
        .popularity = 151
    },
    {
        .artist = "SOFIA ",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 87
    },
    {
        .artist = "STAR B",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = TRAP,
        .popularity = 117
    },
    {
        .artist = "STILL ",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 45},
        .genre = DREAM_POP,
        .popularity = 48
    },
    {
        .artist = "SUNAMI",
        .stage = COINBASE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .genre = PUNK,
        .popularity = 119
    },
    {
        .artist = "SYMPOS",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 45},
        .genre = PSYCH_ROCK,
        .popularity = 128
    },
    {
        .artist = "T-PAIN",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 45},
        .genre = RnB,
        .popularity = 12
    },
    {
        .artist = "TANNER",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .genre = COUNTRY,
        .popularity = 101
    },
    {
        .artist = "TAPE B",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 20},
        .genre = DUBSTEP,
        .popularity = 109
    },
    {
        .artist = "TESSLA",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 157
    },
    {
        .artist = "TORREN",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 0
    },
    {
        .artist = "TWICE ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = K_POP,
        .popularity = 4
    },
    {
        .artist = "TWO FR",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 25},
        .genre = HOUSE,
        .popularity = 89
    },
    {
        .artist = "TYLER,",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = RAP,
        .popularity = 2
    },
    {
        .artist = "VINCEN",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 15},
        .genre = POP,
        .popularity = 107
    },
    {
        .artist = "VIPERA",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 145
    },
    {
        .artist = "WALLOW",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 22
    },
    {
        .artist = "WASIA ",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .genre = POP,
        .popularity = 85
    },
    {
        .artist = "WAVE T",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 13
    },
    {
        .artist = "WILD R",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 45},
        .genre = FOLK,
        .popularity = 58
    },
    {
        .artist = "WILLOW",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 30},
        .genre = COUNTRY,
        .popularity = 113
    },
    {
        .artist = "WINNET",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 131
    },
    {
        .artist = "WINYAH",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 40},
        .genre = ROCK,
        .popularity = 150
    },
    {
        .artist = "WUNDER",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 45},
        .genre = ALT,
        .popularity = 72
    },
    {
        .artist = "WYATT ",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = COUNTRY,
        .popularity = 50
    },
    {
        .artist = "XAVIER",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .genre = EMORAP,
        .popularity = 77
    },
    {
        .artist = "XDINAR",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = ROCK,
        .popularity = 70
    },
    {
        .artist = "YANA  ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 45},
        .genre = DREAM_POP,
        .popularity = 120
    },
    {
        .artist = "YOUNG ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .genre = RAP,
        .popularity = 14
    },
    {
        .artist = "ZINADE",
        .stage = BACARDI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .genre = RnB,
        .popularity = 135
    },
    {
        .artist = "ZOE KO",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 40},
        .genre = POP,
        .popularity = 0
    },
    [NUM_ACTS]  = { //Fall back
        .artist = "No Act",
        .stage = STAGE_COUNT,
        .start_time = {.unit.year = 0, .unit.month = 0, .unit.day = 0, .unit.hour = 0, .unit.minute = 0},
        .end_time = {.unit.year = 63, .unit.month = 15, .unit.day = 31, .unit.hour = 31, .unit.minute = 63},
        .genre = GENRE_COUNT,
        .popularity = 0
    }
};
