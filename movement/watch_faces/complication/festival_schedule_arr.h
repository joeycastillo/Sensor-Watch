// Genre - https://docs.google.com/document/d/1aEJK7fxm-8BUmWOp24QD2GEpIR2YVU3pmbc23-I2vgc/edit?tab=t.0
// Line-up - https://clashfinder.com/data/event/lolla2025.json
#include "festival_schedule_face.h"

#define NUM_ACTS 172

const schedule_t festival_acts[NUM_ACTS + 1]=
{
    {
        .artist = "2HOLLIS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_EMORAP,
        .popularity = 49
    },
    {
        .artist = "a$aP ROCKY",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 4
    },
    {
        .artist = "aLEMEda",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 152
    },
    {
        .artist = "aLEX WaRREN",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 10
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
        .popularity = 87
    },
    {
        .artist = "aLLEYCVT",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 109
    },
    {
        .artist = "aMaaRaE",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_OTHER,
        .popularity = 52
    },
    {
        .artist = "aRTEMaS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 22
    },
    {
        .artist = "aZZECCa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 138
    },
    {
        .artist = "B:a   ",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 165
    },
    {
        .artist = "BaRRY CaN'T SWIM",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 63
    },
    {
        .artist = "BENCHES",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 123
    },
    {
        .artist = "BILMURI",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 77
    },
    {
        .artist = "BLaCK PaRTY",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 134
    },
    {
        .artist = "BLadEE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_EMORAP,
        .popularity = 45
    },
    {
        .artist = "BLEaCHERS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 43
    },
    {
        .artist = "BLESSEd MadONNa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 55
    },
    {
        .artist = "BLK OdYSSY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 106
    },
    {
        .artist = "BO STaLOCH",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 133
    },
    {
        .artist = "BOSSMaN dLOW",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 36
    },
    {
        .artist = "BOYNEXTdOOR",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_K_POP,
        .popularity = 35
    },
    {
        .artist = "BUNT_ ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 44
    },
    {
        .artist = "Ca7RIEL Y PaCO aMOROSO",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 166
    },
    {
        .artist = "CaGE THE ELEPHaNT",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 20
    },
    {
        .artist = "CaROL adES",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 147
    },
    {
        .artist = "CaROLINE KINGSBURY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 143
    },
    {
        .artist = "CaRTER VaIL",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 128
    },
    {
        .artist = "CaSSaNdRa COLEMaN",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 167
    },
    {
        .artist = "CHaRLOTTE LaWRENCE",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 86
    },
    {
        .artist = "CHaSE `n STaTUS",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DnB,
        .popularity = 37
    },
    {
        .artist = "CHICaGO MadE",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_OTHER,
        .popularity = 168
    },
    {
        .artist = "CHICaGO YOUTH ORCHESTRa",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_OTHER,
        .popularity = 169
    },
    {
        .artist = "CLaIRO",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 11
    },
    {
        .artist = "CLOONEE",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 25},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 58
    },
    {
        .artist = "COLBY aCUFF",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 96
    },
    {
        .artist = "CRITICaLS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 155
    },
    {
        .artist = "daMIaNO daVId",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 31
    },
    {
        .artist = "daNIEL aLLaN",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 126
    },
    {
        .artist = "daRE  ",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 90
    },
    {
        .artist = "dEL WaTER GaP",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 70
    },
    {
        .artist = "dJO   ",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_PSYCH_ROCK,
        .popularity = 170
    },
    {
        .artist = "dOECHII",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 9
    },
    {
        .artist = "dOGPaRK",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 140
    },
    {
        .artist = "dOM dOLLa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 33
    },
    {
        .artist = "dOMINIC FIKE",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 16
    },
    {
        .artist = "dR_ FRESCH",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 117
    },
    {
        .artist = "dROPTINES",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 127
    },
    {
        .artist = "dUa SaLEH",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 135
    },
    {
        .artist = "dURaNd BERNaRR",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 99
    },
    {
        .artist = "EddIE aNd THE GETaWaY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 107
    },
    {
        .artist = "FCUKERS",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_DANCE,
        .popularity = 130
    },
    {
        .artist = "FINNEaS",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 38
    },
    {
        .artist = "FLIPTURN",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 71
    },
    {
        .artist = "FLOWEROVLOVE",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 112
    },
    {
        .artist = "FLUX PaVILION",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 84
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
        .popularity = 24
    },
    {
        .artist = "GIGI PEREZ",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 15
    },
    {
        .artist = "GIRL TONES",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 159
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
        .popularity = 68
    },
    {
        .artist = "GRYFFIN",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 42
    },
    {
        .artist = "HaLF aLIVE",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 163
    },
    {
        .artist = "HEX COUGaR",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 148
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
        .popularity = 171
    },
    {
        .artist = "ISaBEL LaROSa",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 28
    },
    {
        .artist = "ISaIaH RaSHad",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 41
    },
    {
        .artist = "ISOXO ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 101
    },
    {
        .artist = "JadE LEMaC",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 62
    },
    {
        .artist = "JaNE REMOVER",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_EMORAP,
        .popularity = 78
    },
    {
        .artist = "JESSE dETOR",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 157
    },
    {
        .artist = "JEV   ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 172
    },
    {
        .artist = "JIGITZ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 81
    },
    {
        .artist = "JOE P ",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 118
    },
    {
        .artist = "JOEY VaLENCE `n BRaE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 50
    },
    {
        .artist = "JPEGMaFIa",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 48
    },
    {
        .artist = "JULIE ",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 93
    },
    {
        .artist = "JUNIOR VaRSITY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 124
    },
    {
        .artist = "KaICREWSadE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 158
    },
    {
        .artist = "KaTSEYE",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 27
    },
    {
        .artist = "KENNY MaSON",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 82
    },
    {
        .artist = "KICKFLIP",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_K_POP,
        .popularity = 119
    },
    {
        .artist = "KNOCK2",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 21, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 75
    },
    {
        .artist = "KORN  ",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_NU_METAL,
        .popularity = 12
    },
    {
        .artist = "La FEMME",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_PSYCH_ROCK,
        .popularity = 80
    },
    {
        .artist = "LaILa!",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 105
    },
    {
        .artist = "LaNdON BaRKER",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 146
    },
    {
        .artist = "LaNdON CONRaTH",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 129
    },
    {
        .artist = "LaTIN MaFIa",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 21
    },
    {
        .artist = "LaYZ  ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 149
    },
    {
        .artist = "LEKaN ",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 50},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 141
    },
    {
        .artist = "LEVITY",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DUBSTEP,
        .popularity = 97
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
        .popularity = 47
    },
    {
        .artist = "MaRIaH THE SCIENTIST",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 39
    },
    {
        .artist = "MaRIaS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 164
    },
    {
        .artist = "MaRIBOU STaTE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DANCE,
        .popularity = 46
    },
    {
        .artist = "MaRINa",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 17
    },
    {
        .artist = "MaRK aMBOR",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_FOLK,
        .popularity = 32
    },
    {
        .artist = "MaRLON HOFFSTadT",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_TECHNO,
        .popularity = 67
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
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 153
    },
    {
        .artist = "MaRY dROPPINZ 2",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 35},
        .genre = FESTIVAL_SCHEDULE_BASS,
        .popularity = 153
    },
    {
        .artist = "MaTT CHaMPION",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 122
    },
    {
        .artist = "MaU P ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 35},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 54
    },
    {
        .artist = "MaX MCNOWN",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 34
    },
    {
        .artist = "MIdNIGHT GENERaTION",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 10},
        .genre = FESTIVAL_SCHEDULE_OTHER,
        .popularity = 113
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
        .popularity = 23
    },
    {
        .artist = "MURda BEaTZ",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 83
    },
    {
        .artist = "NaOMI SCOTT",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 72
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
        .popularity = 60
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
        .popularity = 115
    },
    {
        .artist = "OLE 60",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 57
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
        .popularity = 76
    },
    {
        .artist = "ORLa GaRTLaNd",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 104
    },
    {
        .artist = "OTOBOKE BEaVER",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 154
    },
    {
        .artist = "OVERMONO",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_DnB,
        .popularity = 95
    },
    {
        .artist = "PEOPLE R UGLY",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 132
    },
    {
        .artist = "PROSPa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 35},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 79
    },
    {
        .artist = "R;F;S dU SOL",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 19
    },
    {
        .artist = "RaCHEL GRaE",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 89
    },
    {
        .artist = "RaECOLa",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 160
    },
    {
        .artist = "RaTBOYS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 150
    },
    {
        .artist = "RaVYN LENaE",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_SOUL,
        .popularity = 25
    },
    {
        .artist = "REBECCa BLaCK",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_TECHNO,
        .popularity = 98
    },
    {
        .artist = "REBECCa BLaCK 2",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_TECHNO,
        .popularity = 98
    },
    {
        .artist = "REMI WOLF",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 51
    },
    {
        .artist = "ROLE MOdEL",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 30
    },
    {
        .artist = "ROYEL OTIS",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 40
    },
    {
        .artist = "SaBRINa CaRPENTER",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 2
    },
    {
        .artist = "SaLUTE",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 108
    },
    {
        .artist = "SaM aUSTINS",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 92
    },
    {
        .artist = "SaMMY VIRJI",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 45},
        .genre = FESTIVAL_SCHEDULE_DnB,
        .popularity = 59
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
        .artist = "SOFIa CaMaRa",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 91
    },
    {
        .artist = "STaR BaNdZ",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_TRAP,
        .popularity = 121
    },
    {
        .artist = "STILL WOOZY",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 56
    },
    {
        .artist = "SUNaMI",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_PUNK,
        .popularity = 120
    },
    {
        .artist = "SYMPOSIUM",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 15},
        .genre = FESTIVAL_SCHEDULE_PSYCH_ROCK,
        .popularity = 131
    },
    {
        .artist = "T-PaIN",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 13
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
        .popularity = 162
    },
    {
        .artist = "TORREN B2B aIRWOLF",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 116
    },
    {
        .artist = "TWICE ",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_K_POP,
        .popularity = 5
    },
    {
        .artist = "TWO FRIENdS",
        .stage = FESTIVAL_SCHEDULE_PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_HOUSE,
        .popularity = 88
    },
    {
        .artist = "TYLER, THE CREaTOR",
        .stage = FESTIVAL_SCHEDULE_T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 3
    },
    {
        .artist = "VINCENT LIMa",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 102
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
        .popularity = 29
    },
    {
        .artist = "WaSIa PROJECT",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 94
    },
    {
        .artist = "WaVE TO EaRTH",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 18
    },
    {
        .artist = "WILd RIVERS",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_FOLK,
        .popularity = 61
    },
    {
        .artist = "WILLOW aVaLON",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 85
    },
    {
        .artist = "WINNETKa BOWLING LEaGUE",
        .stage = FESTIVAL_SCHEDULE_LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_INDIE,
        .popularity = 136
    },
    {
        .artist = "WINYaH",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 40},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 145
    },
    {
        .artist = "WUNdERHORSE",
        .stage = FESTIVAL_SCHEDULE_TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_ALT,
        .popularity = 73
    },
    {
        .artist = "WYaTT FLORES",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_COUNTRY,
        .popularity = 53
    },
    {
        .artist = "XaVIERSOBaSEd",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_EMORAP,
        .popularity = 74
    },
    {
        .artist = "XdINaRY HEROES",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_ROCK,
        .popularity = 69
    },
    {
        .artist = "YaNa  ",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .genre = FESTIVAL_SCHEDULE_DREAM_POP,
        .popularity = 125
    },
    {
        .artist = "YOUNG MIKO",
        .stage = FESTIVAL_SCHEDULE_BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RAP,
        .popularity = 14
    },
    {
        .artist = "ZINadELPHIa",
        .stage = FESTIVAL_SCHEDULE_THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .genre = FESTIVAL_SCHEDULE_RnB,
        .popularity = 139
    },
    {
        .artist = "ZOE KO",
        .stage = FESTIVAL_SCHEDULE_BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 20},
        .genre = FESTIVAL_SCHEDULE_POP,
        .popularity = 144
    },
    [NUM_ACTS]  = { //Fall back
        .artist = "No Act",
        .stage = FESTIVAL_SCHEDULE_STAGE_COUNT,
        .start_time = {.unit.year = 0, .unit.month = 0, .unit.day = 0, .unit.hour = 0, .unit.minute = 0},
        .end_time = {.unit.year = 63, .unit.month = 15, .unit.day = 31, .unit.hour = 31, .unit.minute = 63},
        .genre = FESTIVAL_SCHEDULE_GENRE_COUNT,
        .popularity = 0
    }
};
