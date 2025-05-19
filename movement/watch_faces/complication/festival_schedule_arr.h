// Genre - https://docs.google.com/document/d/1aEJK7fxm-8BUmWOp24QD2GEpIR2YVU3pmbc23-I2vgc/edit?tab=t.0
// Line-up - https://clashfinder.com/data/event/lolla2025.json
#include "festival_schedule_face.h"

#define NUM_ACTS 172

const schedule_t festival_acts[NUM_ACTS + 1]=
{
    {
        .artist = "2HOLLIS",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .genre = EMORAP,
        .popularity = 49
    },
    {
        .artist = "a$aP ROCKY",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = TRAP,
        .popularity = 4
    },
    {
        .artist = "aLEMEda",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 152
    },
    {
        .artist = "aLEX WaRREN",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .genre = DREAM_POP,
        .popularity = 10
    },
    {
        .artist = "aLEXSUCKS",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 50},
        .genre = ALT,
        .popularity = 142
    },
    {
        .artist = "aLIYaH'S INTERLUdE",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 10},
        .genre = HOUSE,
        .popularity = 87
    },
    {
        .artist = "aLLEYCVT",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 109
    },
    {
        .artist = "aMaaRaE",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 40},
        .genre = OTHER,
        .popularity = 52
    },
    {
        .artist = "aRTEMaS",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 30},
        .genre = POP,
        .popularity = 22
    },
    {
        .artist = "aZZECCa",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 138
    },
    {
        .artist = "B:a   ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .genre = ALT,
        .popularity = 165
    },
    {
        .artist = "BaRRY CaN'T SWIM",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 58
    },
    {
        .artist = "BENCHES",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 40},
        .genre = ROCK,
        .popularity = 123
    },
    {
        .artist = "BILMURI",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 15},
        .genre = PUNK,
        .popularity = 77
    },
    {
        .artist = "BLaCK PaRTY",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 30},
        .genre = RnB,
        .popularity = 134
    },
    {
        .artist = "BLadEE",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = EMORAP,
        .popularity = 45
    },
    {
        .artist = "BLEaCHERS",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 43
    },
    {
        .artist = "BLESSEd MadONNa",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 55},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 50},
        .genre = HOUSE,
        .popularity = 55
    },
    {
        .artist = "BLK OdYSSY",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 20},
        .genre = SOUL,
        .popularity = 106
    },
    {
        .artist = "BO STaLOCH",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 10},
        .genre = POP,
        .popularity = 133
    },
    {
        .artist = "BOSSMaN dLOW",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .genre = TRAP,
        .popularity = 37
    },
    {
        .artist = "BOYNEXTdOOR",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 15},
        .genre = K_POP,
        .popularity = 35
    },
    {
        .artist = "BUNT_ ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 44
    },
    {
        .artist = "Ca7RIEL Y PaCO aMOROSO",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .genre = SOUL,
        .popularity = 166
    },
    {
        .artist = "CaGE THE ELEPHaNT",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 45},
        .genre = ALT,
        .popularity = 20
    },
    {
        .artist = "CaROL adES",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 20},
        .genre = INDIE,
        .popularity = 147
    },
    {
        .artist = "CaROLINE KINGSBURY",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .genre = POP,
        .popularity = 143
    },
    {
        .artist = "CaRTER VaIL",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 50},
        .genre = INDIE,
        .popularity = 128
    },
    {
        .artist = "CaSSaNdRa COLEMaN",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 50},
        .genre = DREAM_POP,
        .popularity = 167
    },
    {
        .artist = "CHaRLOTTE LaWRENCE",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .genre = POP,
        .popularity = 86
    },
    {
        .artist = "CHaSE `n STaTUS",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = DnB,
        .popularity = 36
    },
    {
        .artist = "CHICaGO MadE",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .genre = OTHER,
        .popularity = 168
    },
    {
        .artist = "CHICaGO YOUTH ORCHESTRa",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = OTHER,
        .popularity = 169
    },
    {
        .artist = "CLaIRO",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .genre = DREAM_POP,
        .popularity = 11
    },
    {
        .artist = "CLOONEE",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 25},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 25},
        .genre = HOUSE,
        .popularity = 59
    },
    {
        .artist = "COLBY aCUFF",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 20},
        .genre = COUNTRY,
        .popularity = 96
    },
    {
        .artist = "CRITICaLS",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = PUNK,
        .popularity = 155
    },
    {
        .artist = "daMIaNO daVId",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .genre = POP,
        .popularity = 33
    },
    {
        .artist = "daNIEL aLLaN",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 15},
        .genre = HOUSE,
        .popularity = 126
    },
    {
        .artist = "daRE  ",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 0},
        .genre = POP,
        .popularity = 90
    },
    {
        .artist = "dEL WaTER GaP",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 70
    },
    {
        .artist = "dJO   ",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 40},
        .genre = PSYCH_ROCK,
        .popularity = 170
    },
    {
        .artist = "dOECHII",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .genre = RAP,
        .popularity = 9
    },
    {
        .artist = "dOGPaRK",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .genre = INDIE,
        .popularity = 140
    },
    {
        .artist = "dOM dOLLa",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 32
    },
    {
        .artist = "dOMINIC FIKE",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 17
    },
    {
        .artist = "dR_ FRESCH",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .genre = BASS,
        .popularity = 117
    },
    {
        .artist = "dROPTINES",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .genre = ROCK,
        .popularity = 127
    },
    {
        .artist = "dUa SaLEH",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 30},
        .genre = RnB,
        .popularity = 135
    },
    {
        .artist = "dURaNd BERNaRR",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .genre = RnB,
        .popularity = 99
    },
    {
        .artist = "EddIE aNd THE GETaWaY",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 40},
        .genre = ALT,
        .popularity = 107
    },
    {
        .artist = "FCUKERS",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .genre = DANCE,
        .popularity = 130
    },
    {
        .artist = "FINNEaS",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 38
    },
    {
        .artist = "FLIPTURN",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 71
    },
    {
        .artist = "FLOWEROVLOVE",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 112
    },
    {
        .artist = "FLUX PaVILION",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 84
    },
    {
        .artist = "FOSTER THE PEOPLE",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 40},
        .genre = INDIE,
        .popularity = 26
    },
    {
        .artist = "FUJII KaZE",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 30},
        .genre = K_POP,
        .popularity = 24
    },
    {
        .artist = "GIGI PEREZ",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 40},
        .genre = ALT,
        .popularity = 16
    },
    {
        .artist = "GIRL TONES",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 40},
        .genre = ALT,
        .popularity = 159
    },
    {
        .artist = "GLaSS BEaMS",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 0},
        .genre = ROCK,
        .popularity = 103
    },
    {
        .artist = "GRaCIE aBRaMS",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 7
    },
    {
        .artist = "GRaHaM BaRHaM",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 30},
        .genre = COUNTRY,
        .popularity = 68
    },
    {
        .artist = "GRYFFIN",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = BASS,
        .popularity = 42
    },
    {
        .artist = "HaLF aLIVE",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 163
    },
    {
        .artist = "HEX COUGaR",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 148
    },
    {
        .artist = "HEY, NOTHING",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .genre = ALT,
        .popularity = 110
    },
    {
        .artist = "IaN   ",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .genre = TRAP,
        .popularity = 171
    },
    {
        .artist = "ISaBEL LaROSa",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 45},
        .genre = POP,
        .popularity = 27
    },
    {
        .artist = "ISaIaH RaSHad",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = RAP,
        .popularity = 41
    },
    {
        .artist = "ISOXO ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 101
    },
    {
        .artist = "JadE LEMaC",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .genre = POP,
        .popularity = 63
    },
    {
        .artist = "JaNE REMOVER",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .genre = EMORAP,
        .popularity = 78
    },
    {
        .artist = "JESSE dETOR",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 30},
        .genre = ALT,
        .popularity = 157
    },
    {
        .artist = "JEV   ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 20},
        .genre = HOUSE,
        .popularity = 172
    },
    {
        .artist = "JIGITZ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 81
    },
    {
        .artist = "JOE P ",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 118
    },
    {
        .artist = "JOEY VaLENCE `n BRaE",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = RAP,
        .popularity = 50
    },
    {
        .artist = "JPEGMaFIa",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .genre = RAP,
        .popularity = 48
    },
    {
        .artist = "JULIE ",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 93
    },
    {
        .artist = "JUNIOR VaRSITY",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 10},
        .genre = ALT,
        .popularity = 124
    },
    {
        .artist = "KaICREWSadE",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .genre = RAP,
        .popularity = 158
    },
    {
        .artist = "KaTSEYE",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = POP,
        .popularity = 30
    },
    {
        .artist = "KENNY MaSON",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .genre = RAP,
        .popularity = 82
    },
    {
        .artist = "KICKFLIP",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .genre = K_POP,
        .popularity = 119
    },
    {
        .artist = "KNOCK2",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 21, .unit.minute = 45},
        .genre = BASS,
        .popularity = 75
    },
    {
        .artist = "KORN  ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = NU_METAL,
        .popularity = 12
    },
    {
        .artist = "La FEMME",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 45},
        .genre = PSYCH_ROCK,
        .popularity = 80
    },
    {
        .artist = "LaILa!",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 15},
        .genre = RnB,
        .popularity = 105
    },
    {
        .artist = "LaNdON BaRKER",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 15},
        .genre = PUNK,
        .popularity = 146
    },
    {
        .artist = "LaNdON CONRaTH",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 129
    },
    {
        .artist = "LaTIN MaFIa",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = RnB,
        .popularity = 21
    },
    {
        .artist = "LaYZ  ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 149
    },
    {
        .artist = "LEKaN ",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 10},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 50},
        .genre = SOUL,
        .popularity = 141
    },
    {
        .artist = "LEVITY",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 97
    },
    {
        .artist = "LUKE COMBS",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = COUNTRY,
        .popularity = 6
    },
    {
        .artist = "MaGdaLENa BaY",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 0},
        .genre = POP,
        .popularity = 47
    },
    {
        .artist = "MaRIaH THE SCIENTIST",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .genre = RnB,
        .popularity = 39
    },
    {
        .artist = "MaRIaS",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 164
    },
    {
        .artist = "MaRIBOU STaTE",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 19, .unit.minute = 15},
        .genre = DANCE,
        .popularity = 46
    },
    {
        .artist = "MaRINa",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 45},
        .genre = POP,
        .popularity = 15
    },
    {
        .artist = "MaRK aMBOR",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 45},
        .genre = FOLK,
        .popularity = 31
    },
    {
        .artist = "MaRLON HOFFSTadT",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 15},
        .genre = TECHNO,
        .popularity = 67
    },
    {
        .artist = "MaRTIN GaRRIX",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 8
    },
    {
        .artist = "MaRY dROPPINZ",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .genre = BASS,
        .popularity = 153
    },
    {
        .artist = "MaRY dROPPINZ 2",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 35},
        .genre = BASS,
        .popularity = 153
    },
    {
        .artist = "MaTT CHaMPION",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 0},
        .genre = RAP,
        .popularity = 122
    },
    {
        .artist = "MaU P ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 35},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 35},
        .genre = HOUSE,
        .popularity = 54
    },
    {
        .artist = "MaX MCNOWN",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 45},
        .genre = COUNTRY,
        .popularity = 34
    },
    {
        .artist = "MIdNIGHT GENERaTION",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 10},
        .genre = OTHER,
        .popularity = 113
    },
    {
        .artist = "MK_GEE",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 65
    },
    {
        .artist = "MONTELL FISH",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .genre = SOUL,
        .popularity = 23
    },
    {
        .artist = "MURda BEaTZ",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 15},
        .genre = TRAP,
        .popularity = 83
    },
    {
        .artist = "NaOMI SCOTT",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 45},
        .genre = POP,
        .popularity = 72
    },
    {
        .artist = "NEWdad",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 111
    },
    {
        .artist = "NIMINO",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 61
    },
    {
        .artist = "NOURISHEd BY TIME",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 0},
        .genre = POP,
        .popularity = 137
    },
    {
        .artist = "OCEaN aLLEY",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 15},
        .genre = PSYCH_ROCK,
        .popularity = 64
    },
    {
        .artist = "OLd MERVS",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 12, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .genre = ALT,
        .popularity = 115
    },
    {
        .artist = "OLE 60",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 30},
        .genre = ROCK,
        .popularity = 57
    },
    {
        .artist = "OLIVIa ROdRIGO",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 22, .unit.minute = 0},
        .genre = POP,
        .popularity = 1
    },
    {
        .artist = "ORION SUN",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 0},
        .genre = RnB,
        .popularity = 76
    },
    {
        .artist = "ORLa GaRTLaNd",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 45},
        .genre = ROCK,
        .popularity = 104
    },
    {
        .artist = "OTOBOKE BEaVER",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .genre = PUNK,
        .popularity = 154
    },
    {
        .artist = "OVERMONO",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 15},
        .genre = DnB,
        .popularity = 95
    },
    {
        .artist = "PEOPLE R UGLY",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 19, .unit.minute = 30},
        .genre = PUNK,
        .popularity = 132
    },
    {
        .artist = "PROSPa",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 35},
        .genre = HOUSE,
        .popularity = 79
    },
    {
        .artist = "R;F;S dU SOL",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 19
    },
    {
        .artist = "RaCHEL GRaE",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 89
    },
    {
        .artist = "RaECOLa",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 12, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 160
    },
    {
        .artist = "RaTBOYS",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 15},
        .genre = ALT,
        .popularity = 150
    },
    {
        .artist = "RaVYN LENaE",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 40},
        .genre = SOUL,
        .popularity = 25
    },
    {
        .artist = "REBECCa BLaCK",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 45},
        .genre = TECHNO,
        .popularity = 98
    },
    {
        .artist = "REBECCa BLaCK 2",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = TECHNO,
        .popularity = 98
    },
    {
        .artist = "REMI WOLF",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 0},
        .genre = POP,
        .popularity = 51
    },
    {
        .artist = "ROLE MOdEL",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 28
    },
    {
        .artist = "ROYEL OTIS",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 40
    },
    {
        .artist = "SaBRINa CaRPENTER",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 22, .unit.minute = 0},
        .genre = POP,
        .popularity = 2
    },
    {
        .artist = "SaLUTE",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 108
    },
    {
        .artist = "SaM aUSTINS",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .genre = POP,
        .popularity = 92
    },
    {
        .artist = "SaMMY VIRJI",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 18, .unit.minute = 45},
        .genre = DnB,
        .popularity = 60
    },
    {
        .artist = "SIERRa FERRELL",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 17, .unit.minute = 45},
        .genre = FOLK,
        .popularity = 66
    },
    {
        .artist = "SOFIa CaMaRa",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 91
    },
    {
        .artist = "STaR BaNdZ",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 30},
        .genre = TRAP,
        .popularity = 121
    },
    {
        .artist = "STILL WOOZY",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 21, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 56
    },
    {
        .artist = "SUNaMI",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 30},
        .genre = PUNK,
        .popularity = 120
    },
    {
        .artist = "SYMPOSIUM",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 15},
        .genre = PSYCH_ROCK,
        .popularity = 131
    },
    {
        .artist = "T-PaIN",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 17, .unit.minute = 30},
        .genre = RnB,
        .popularity = 13
    },
    {
        .artist = "TaNNER adELL",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 0},
        .genre = COUNTRY,
        .popularity = 100
    },
    {
        .artist = "TaPE B",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 0},
        .genre = DUBSTEP,
        .popularity = 114
    },
    {
        .artist = "TESSLa",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 35},
        .genre = HOUSE,
        .popularity = 162
    },
    {
        .artist = "TORREN B2B aIRWOLF",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 13, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 116
    },
    {
        .artist = "TWICE ",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = K_POP,
        .popularity = 5
    },
    {
        .artist = "TWO FRIENdS",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 22, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 88
    },
    {
        .artist = "TYLER, THE CREaTOR",
        .stage = T_MOBILE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = RAP,
        .popularity = 3
    },
    {
        .artist = "VINCENT LIMa",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 13, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 30},
        .genre = POP,
        .popularity = 102
    },
    {
        .artist = "VIPERaCTIVE",
        .stage = PERRYS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 151
    },
    {
        .artist = "WaLLOWS",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 40},
        .genre = INDIE,
        .popularity = 29
    },
    {
        .artist = "WaSIa PROJECT",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 14, .unit.minute = 30},
        .genre = POP,
        .popularity = 94
    },
    {
        .artist = "WaVE TO EaRTH",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 17, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 18
    },
    {
        .artist = "WILd RIVERS",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 16, .unit.minute = 0},
        .genre = FOLK,
        .popularity = 62
    },
    {
        .artist = "WILLOW aVaLON",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 30},
        .genre = COUNTRY,
        .popularity = 85
    },
    {
        .artist = "WINNETKa BOWLING LEaGUE",
        .stage = LAKESHORE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 12, .unit.minute = 15},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 13, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 136
    },
    {
        .artist = "WINYaH",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 13, .unit.minute = 40},
        .genre = ROCK,
        .popularity = 145
    },
    {
        .artist = "WUNdERHORSE",
        .stage = TITOS,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 3, .unit.hour = 15, .unit.minute = 0},
        .genre = ALT,
        .popularity = 73
    },
    {
        .artist = "WYaTT FLORES",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 20, .unit.minute = 30},
        .genre = COUNTRY,
        .popularity = 53
    },
    {
        .artist = "XaVIERSOBaSEd",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 18, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 19, .unit.minute = 30},
        .genre = EMORAP,
        .popularity = 74
    },
    {
        .artist = "XdINaRY HEROES",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 22, .unit.minute = 0},
        .genre = ROCK,
        .popularity = 69
    },
    {
        .artist = "YaNa  ",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 15, .unit.minute = 20},
        .end_time = {.unit.year = 5, .unit.month = 7, .unit.day = 31, .unit.hour = 16, .unit.minute = 0},
        .genre = DREAM_POP,
        .popularity = 125
    },
    {
        .artist = "YOUNG MIKO",
        .stage = BUD_LIGHT,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 30},
        .genre = RAP,
        .popularity = 14
    },
    {
        .artist = "ZINadELPHIa",
        .stage = THE_GROVE,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 14, .unit.minute = 50},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 1, .unit.hour = 15, .unit.minute = 30},
        .genre = RnB,
        .popularity = 139
    },
    {
        .artist = "ZOE KO",
        .stage = BMI,
        .start_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 17, .unit.minute = 40},
        .end_time = {.unit.year = 5, .unit.month = 8, .unit.day = 2, .unit.hour = 18, .unit.minute = 20},
        .genre = POP,
        .popularity = 144
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
