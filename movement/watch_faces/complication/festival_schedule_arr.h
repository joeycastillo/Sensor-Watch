// Genre - https://docs.google.com/document/d/1aEJK7fxm-8BUmWOp24QD2GEpIR2YVU3pmbc23-I2vgc/edit?tab=t.0
// Line-up - https://clashfinder.com/data/event/lollapalooza2025chicago.json
#include "festival_schedule_face.h"

#define FESTIVAL_SCHEDULE_NUM_ACTS 200

const festival_schedule_t festival_acts[FESTIVAL_SCHEDULE_NUM_ACTS + 1]=
{
    {
        .artist = "2HOLLIS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_EMORAP,
        .popularity = 43
    },
    {
        .artist = "a$aP ROCKY",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 5
    },
    {
        .artist = "aLEMEda",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 144
    },
    {
        .artist = "aLEX WaRREN",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 9
    },
    {
        .artist = "aLEXSUCKS",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 142
    },
    {
        .artist = "aLIYaH'S INTERLUdE",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 94
    },
    {
        .artist = "aLLEYCVT",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 115
    },
    {
        .artist = "aMaaRaE",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 54
    },
    {
        .artist = "aRTEMaS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 27
    },
    {
        .artist = "aZZECCa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 55},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 138
    },
    {
        .artist = "B:a   ",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 40
    },
    {
        .artist = "BaRRY CaN'T SWIM",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 53
    },
    {
        .artist = "BENCHES",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 128
    },
    {
        .artist = "BILMURI",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 75
    },
    {
        .artist = "BLaCK PaRTY",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 139
    },
    {
        .artist = "BLadEE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_EMORAP,
        .popularity = 49
    },
    {
        .artist = "BLEaCHERS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 48
    },
    {
        .artist = "BLESSEd MadONNa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 63
    },
    {
        .artist = "BLK OdYSSY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 113
    },
    {
        .artist = "BO STaLOCH",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 135
    },
    {
        .artist = "BO STaLOCH 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 135
    },
    {
        .artist = "BOSSMaN dLOW",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 55},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 45
    },
    {
        .artist = "BOYNEXTdOOR",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_K_POP,
        .popularity = 37
    },
    {
        .artist = "BUNT_ ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 38
    },
    {
        .artist = "Ca7RIEL Y PaCO aMOROSO",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 55},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 170
    },
    {
        .artist = "CaGE THE ELEPHaNT",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 21
    },
    {
        .artist = "CaROL adES",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 146
    },
    {
        .artist = "CaROL adES 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 146
    },
    {
        .artist = "CaROLINE KINGSBURY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 149
    },
    {
        .artist = "CaROLINE KINGSBURY 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 149
    },
    {
        .artist = "CaRTER VaIL",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 132
    },
    {
        .artist = "CaSSaNdRa COLEMaN",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 165
    },
    {
        .artist = "CHaCHI",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 164
    },
    {
        .artist = "CHaRLOTTE LaWRENCE",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 55},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 86
    },
    {
        .artist = "CHaSE `n STaTUS",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DnB,
        .popularity = 39
    },
    {
        .artist = "CHICaGO MadE",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_OTHER,
        .popularity = 171
    },
    {
        .artist = "CHICaGO YOUTH ORCHESTRa",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_CLASSICAL,
        .popularity = 172
    },
    {
        .artist = "CLaIRO",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 13
    },
    {
        .artist = "CLOONEE",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 62
    },
    {
        .artist = "COLBY aCUFF",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 92
    },
    {
        .artist = "CRITICaLS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 158
    },
    {
        .artist = "CRITICaLS 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 158
    },
    {
        .artist = "daMIaNO daVId",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 29
    },
    {
        .artist = "daNIEL aLLaN",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 127
    },
    {
        .artist = "daRE  ",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 91
    },
    {
        .artist = "dEL WaTER GaP",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 73
    },
    {
        .artist = "dEROZa dJ SET",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 173
    },
    {
        .artist = "dJ HEaTHER",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 167
    },
    {
        .artist = "dJO   ",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_PSYCH_ROCK,
        .popularity = 174
    },
    {
        .artist = "dOECHII",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 15
    },
    {
        .artist = "dOGPaRK",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 141
    },
    {
        .artist = "dOM dOLLa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 36
    },
    {
        .artist = "dOMINIC FIKE",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 20
    },
    {
        .artist = "dR_ FRESCH",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 112
    },
    {
        .artist = "dROPTINES",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 118
    },
    {
        .artist = "dROPTINES 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 118
    },
    {
        .artist = "dUa SaLEH",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 140
    },
    {
        .artist = "dURaNd BERNaRR",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 108
    },
    {
        .artist = "EddIE aNd THE GETaWaY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 102
    },
    {
        .artist = "FCUKERS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_DANCE,
        .popularity = 134
    },
    {
        .artist = "FINNEaS",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 41
    },
    {
        .artist = "FLIPTURN",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 74
    },
    {
        .artist = "FLOWEROVLOVE",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 104
    },
    {
        .artist = "FLUX PaVILION",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 87
    },
    {
        .artist = "FOSTER THE PEOPLE",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 26
    },
    {
        .artist = "FUJII KaZE",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_K_POP,
        .popularity = 25
    },
    {
        .artist = "GIGI PEREZ",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 19
    },
    {
        .artist = "GIRL TONES",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 161
    },
    {
        .artist = "GIRL TONES 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 161
    },
    {
        .artist = "GLaSS BEaMS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 103
    },
    {
        .artist = "GOO   ",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 175
    },
    {
        .artist = "GRaCIE aBRaMS",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 7
    },
    {
        .artist = "GRaHaM BaRHaM",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 71
    },
    {
        .artist = "GRYFFIN",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 44
    },
    {
        .artist = "HaLF aLIVE",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 169
    },
    {
        .artist = "HEaVY dJ SET",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 176
    },
    {
        .artist = "HEX COUGaR",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 154
    },
    {
        .artist = "HEY, NOTHING",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 110
    },
    {
        .artist = "IaN   ",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 177
    },
    {
        .artist = "ISaBEL LaROSa",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 31
    },
    {
        .artist = "ISaIaH RaSHad",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 47
    },
    {
        .artist = "ISOXO ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 97
    },
    {
        .artist = "JadE LEMaC",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 67
    },
    {
        .artist = "JaNE REMOVER",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_EMORAP,
        .popularity = 89
    },
    {
        .artist = "JESSE dETOR",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 160
    },
    {
        .artist = "JEV   ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 178
    },
    {
        .artist = "JIGITZ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 80
    },
    {
        .artist = "JOE P ",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 124
    },
    {
        .artist = "JOE P 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 124
    },
    {
        .artist = "JOEY VaLENCE `n BRaE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 52
    },
    {
        .artist = "JPEGMaFIa",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 60
    },
    {
        .artist = "JULIE ",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 55},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 93
    },
    {
        .artist = "JUNIOR VaRSITY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 125
    },
    {
        .artist = "JUNIOR VaRSITY 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 125
    },
    {
        .artist = "KaICREWSadE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 162
    },
    {
        .artist = "KaTSEYE",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 12
    },
    {
        .artist = "KENNY MaSON",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 84
    },
    {
        .artist = "KICKFLIP",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_K_POP,
        .popularity = 120
    },
    {
        .artist = "KNOCK2",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 21, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 79
    },
    {
        .artist = "KORN  ",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_NU_METAL,
        .popularity = 14
    },
    {
        .artist = "KUPYd ",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 179
    },
    {
        .artist = "La FEMME",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_PSYCH_ROCK,
        .popularity = 81
    },
    {
        .artist = "LaILa!",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 107
    },
    {
        .artist = "LaNdON BaRKER",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 152
    },
    {
        .artist = "LaNdON CONRaTH",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 136
    },
    {
        .artist = "LaNdON CONRaTH 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 136
    },
    {
        .artist = "LaTIN MaFIa",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 24
    },
    {
        .artist = "LaYZ  ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 148
    },
    {
        .artist = "LEKaN ",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 147
    },
    {
        .artist = "LEVITY",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 101
    },
    {
        .artist = "LUCKY LOU",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 159
    },
    {
        .artist = "LUKE COMBS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 6
    },
    {
        .artist = "MaGdaLENa BaY",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 46
    },
    {
        .artist = "MaRIaH THE SCIENTIST",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 35
    },
    {
        .artist = "MaRIaS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 10
    },
    {
        .artist = "MaRIBOU STaTE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DANCE,
        .popularity = 50
    },
    {
        .artist = "MaRINa",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 55},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 17
    },
    {
        .artist = "MaRK aMBOR",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_FOLK,
        .popularity = 42
    },
    {
        .artist = "MaRK aMBOR 2",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_FOLK,
        .popularity = 42
    },
    {
        .artist = "MaRLON HOFFSTadT",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_TECHNO,
        .popularity = 68
    },
    {
        .artist = "MaRTIN GaRRIX",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 8
    },
    {
        .artist = "MaRY dROPPINZ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 35},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 150
    },
    {
        .artist = "MaRY dROPPINZ 2",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 150
    },
    {
        .artist = "MaTT CHaMPION",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 130
    },
    {
        .artist = "MaU P ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 51
    },
    {
        .artist = "MaX MCNOWN",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 30
    },
    {
        .artist = "MIdNIGHT GENERaTION",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 121
    },
    {
        .artist = "MIdNIGHT GENERaTION 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 121
    },
    {
        .artist = "MK_GEE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 65
    },
    {
        .artist = "MONTELL FISH",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 28
    },
    {
        .artist = "MR_ SHaW",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 180
    },
    {
        .artist = "MURda BEaTZ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 88
    },
    {
        .artist = "NaOMI SCOTT",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 77
    },
    {
        .artist = "NEWdad",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 111
    },
    {
        .artist = "NIMINO",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 58
    },
    {
        .artist = "NOURISHEd BY TIME",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 137
    },
    {
        .artist = "OCEaN aLLEY",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_PSYCH_ROCK,
        .popularity = 64
    },
    {
        .artist = "OLd MERVS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 116
    },
    {
        .artist = "OLd MERVS 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 116
    },
    {
        .artist = "OLE 60",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 56
    },
    {
        .artist = "OLIVIa ROdRIGO",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 1
    },
    {
        .artist = "ORION SUN",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 82
    },
    {
        .artist = "ORLa GaRTLaNd",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 119
    },
    {
        .artist = "OTOBOKE BEaVER",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 156
    },
    {
        .artist = "OVERMONO",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DnB,
        .popularity = 90
    },
    {
        .artist = "PEOPLE R UGLY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 129
    },
    {
        .artist = "PROSPa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 72
    },
    {
        .artist = "R;F;S dU SOL",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 23
    },
    {
        .artist = "RaCHEL GRaE",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 95
    },
    {
        .artist = "RaCHEL GRaE 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 95
    },
    {
        .artist = "RaECOLa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 166
    },
    {
        .artist = "RaTBOYS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 153
    },
    {
        .artist = "RaVYN LENaE",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 18
    },
    {
        .artist = "REBECCa BLaCK",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_TECHNO,
        .popularity = 109
    },
    {
        .artist = "REBECCa BLaCK 2",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_TECHNO,
        .popularity = 109
    },
    {
        .artist = "REMI WOLF",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 61
    },
    {
        .artist = "ROLE MOdEL",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 33
    },
    {
        .artist = "ROYEL OTIS",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 34
    },
    {
        .artist = "SaBRINa CaRPENTER",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 3
    },
    {
        .artist = "SaLUTE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 105
    },
    {
        .artist = "SaM aUSTINS",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 55},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 98
    },
    {
        .artist = "SaMMY VIRJI",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_DnB,
        .popularity = 57
    },
    {
        .artist = "SIERRa FERRELL",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_FOLK,
        .popularity = 66
    },
    {
        .artist = "SILLY GOOSE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_NU_METAL,
        .popularity = 157
    },
    {
        .artist = "SOFIa CaMaRa",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 85
    },
    {
        .artist = "STaR BaNdZ",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 131
    },
    {
        .artist = "STILL WOOZY",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 59
    },
    {
        .artist = "SUNaMI",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 123
    },
    {
        .artist = "SYMPOSIUM",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_PSYCH_ROCK,
        .popularity = 133
    },
    {
        .artist = "T-PaIN",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 11
    },
    {
        .artist = "TaNNER adELL",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 100
    },
    {
        .artist = "TaPE B",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 114
    },
    {
        .artist = "TESSLa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 35},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 168
    },
    {
        .artist = "TORREN B2B aIRWOLF",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 117
    },
    {
        .artist = "TWICE ",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_K_POP,
        .popularity = 4
    },
    {
        .artist = "TWO FRIENdS",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 21, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 83
    },
    {
        .artist = "TYLER, THE CREaTOR",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 2
    },
    {
        .artist = "VINCENT LIMa",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 106
    },
    {
        .artist = "VINCENT LIMa 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 106
    },
    {
        .artist = "VIPERaCTIVE",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 151
    },
    {
        .artist = "WaLLOWS",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 32
    },
    {
        .artist = "WaSIa PROJECT",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 99
    },
    {
        .artist = "WaVE TO EaRTH",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 22
    },
    {
        .artist = "WILd RIVERS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_FOLK,
        .popularity = 69
    },
    {
        .artist = "WILd RIVERS 2",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_FOLK,
        .popularity = 69
    },
    {
        .artist = "WILLOW aVaLON",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 96
    },
    {
        .artist = "WINNETKa BOWLING LEaGUE",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 143
    },
    {
        .artist = "WINNETKa BOWLING LEaGUE 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 143
    },
    {
        .artist = "WINYaH",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 122
    },
    {
        .artist = "WUNdERHORSE",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 70
    },
    {
        .artist = "WYaTT FLORES",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 55
    },
    {
        .artist = "XaVIERSOBaSEd",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_EMORAP,
        .popularity = 78
    },
    {
        .artist = "XdINaRY HEROES",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 76
    },
    {
        .artist = "YaNa  ",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 126
    },
    {
        .artist = "YaNa 2",
        .stage = FESTIVAL_SCHEDULE_MUSIC_DEN,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 126
    },
    {
        .artist = "YOUNG MIKO",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 16
    },
    {
        .artist = "ZILLION",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 163
    },
    {
        .artist = "ZINadELPHIa",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 145
    },
    {
        .artist = "ZINadELPHIa 2",
        .stage = FESTIVAL_SCHEDULE_BACKYARD,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 145
    },
    {
        .artist = "ZOE KO",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 155
    },
    [FESTIVAL_SCHEDULE_NUM_ACTS]  = { //Fall back
        .artist = "No Act",
        .stage = FESTIVAL_SCHEDULE_STAGE_COUNT,
        .start_time = {.unit.year = 0, .unit.month = 0, .unit.day = 0, .unit.hour = 0, .unit.minute = 0},
        .end_time = {.unit.year = 63, .unit.month = 15, .unit.day = 31, .unit.hour = 31, .unit.minute = 63},
        .genre = FESTIVAL_SCHEDULE_GENRE_COUNT,
        .popularity = 0
    }
};
