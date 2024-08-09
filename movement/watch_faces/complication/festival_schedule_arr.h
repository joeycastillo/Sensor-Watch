// Genre - https://old.reddit.com/r/ElectricForest/comments/1bqbwlv/electric_forest_2024_lineup_broken_down_by_genre/
// Line-up - https://clashfinder.com/m/elecfor24/
#include "festival_schedule_face.h"

#define NUM_ACTS 146

const schedule_t festival_acts[NUM_ACTS + 1]=
{
    {
        .artist = "ACRAZE",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 22, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 19
    },
    {
        .artist = "ACRAZE",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 24, .unit.hour = 0, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 24, .unit.hour = 1, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 19
    },
    {
        .artist = "AK SPO",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 22, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 0, .unit.minute = 0},
        .genre = DnB,
        .popularity = 106
    },
    {
        .artist = "ALLEYC",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 17, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 71
    },
    {
        .artist = "ATLIEN",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 22, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 23, .unit.minute = 45},
        .genre = DUBSTEP,
        .popularity = 55
    },
    {
        .artist = "AYYBO ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 18, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 39
    },
    {
        .artist = "BAGGI ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 15},
        .genre = HOUSE,
        .popularity = 105
    },
    {
        .artist = "BARCLA",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 21, .unit.minute = 30},
        .genre = BASS,
        .popularity = 84
    },
    {
        .artist = "BEN B:",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 23, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 0, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 11
    },
    {
        .artist = "BLACK ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 1, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 2, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 51
    },
    {
        .artist = "BLASTO",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 23, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 0, .unit.minute = 45},
        .genre = TECHNO,
        .popularity = 62
    },
    {
        .artist = "BOOGIE",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 21, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 64
    },
    {
        .artist = "BOOGIE",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 15},
        .genre = JAM,
        .popularity = 96
    },
    {
        .artist = "BRANDI",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 14, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 15, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 0
    },
    {
        .artist = "BRANDI",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 0, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 1, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 0
    },
    {
        .artist = "CALUSS",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 20, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 66
    },
    {
        .artist = "CANABL",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 16, .unit.minute = 0},
        .genre = DUBSTEP,
        .popularity = 87
    },
    {
        .artist = "CANNON",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 20, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 17
    },
    {
        .artist = "CARDIO",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 17, .unit.minute = 0},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "CASPA ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 20, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 88
    },
    {
        .artist = "CASSIA",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 21, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 46
    },
    {
        .artist = "CHAOS ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 54
    },
    {
        .artist = "CHARLO",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 23, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 24, .unit.hour = 0, .unit.minute = 15},
        .genre = TECHNO,
        .popularity = 4
    },
    {
        .artist = "CHASE ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 22, .unit.minute = 15},
        .genre = DnB,
        .popularity = 3
    },
    {
        .artist = "CLOSIN",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 23, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 24, .unit.hour = 1, .unit.minute = 0},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "COCO &",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 19, .unit.minute = 45},
        .genre = DANCE,
        .popularity = 65
    },
    {
        .artist = "CUCO  ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 19, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 91
    },
    {
        .artist = "DAVE Y",
        .stage = NO_STAGE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 0},
        .genre = JAM,
        .popularity = 114
    },
    {
        .artist = "DIMENS",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 21, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 22, .unit.minute = 45},
        .genre = DnB,
        .popularity = 26
    },
    {
        .artist = "DIRTWI",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 17, .unit.minute = 0},
        .genre = JAM,
        .popularity = 67
    },
    {
        .artist = "DISCO ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 22, .unit.minute = 30},
        .genre = JAM,
        .popularity = 85
    },
    {
        .artist = "DIXON'",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 30},
        .genre = SOUL,
        .popularity = 110
    },
    {
        .artist = "DIXON'",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 19, .unit.minute = 0},
        .genre = SOUL,
        .popularity = 110
    },
    {
        .artist = "DIXON'",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 24, .unit.hour = 0, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 24, .unit.hour = 1, .unit.minute = 0},
        .genre = SOUL,
        .popularity = 110
    },
    {
        .artist = "DJ BRO",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 0, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 1, .unit.minute = 55},
        .genre = HOUSE,
        .popularity = 113
    },
    {
        .artist = "DJ SUS",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 23, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 0, .unit.minute = 15},
        .genre = DANCE,
        .popularity = 89
    },
    {
        .artist = "DJ SUS",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 20, .unit.minute = 30},
        .genre = DANCE,
        .popularity = 89
    },
    {
        .artist = "DRAMA ",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 0},
        .genre = DANCE,
        .popularity = 32
    },
    {
        .artist = "DUMPST",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 15},
        .genre = JAM,
        .popularity = 93
    },
    {
        .artist = "EGGY  ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 19, .unit.minute = 0},
        .genre = JAM,
        .popularity = 99
    },
    {
        .artist = "EMO NI",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 23, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 1, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 0
    },
    {
        .artist = "EQUANI",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 10},
        .genre = INDIE,
        .popularity = 57
    },
    {
        .artist = "EVERYT",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 22, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 0, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 5
    },
    {
        .artist = "EXCISI",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 22, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 24, .unit.hour = 0, .unit.minute = 0},
        .genre = DUBSTEP,
        .popularity = 7
    },
    {
        .artist = "FEMME ",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 15, .unit.minute = 30},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "G JONE",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 22, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 23, .unit.minute = 15},
        .genre = DnB,
        .popularity = 81
    },
    {
        .artist = "GIGANT",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 20, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 21, .unit.minute = 45},
        .genre = DUBSTEP,
        .popularity = 20
    },
    {
        .artist = "GOODBO",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 21, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 22, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 18
    },
    {
        .artist = "GREEN ",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 20, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 34
    },
    {
        .artist = "H&RRY ",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 15, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 0
    },
    {
        .artist = "HAMDI ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 22, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 23, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 44
    },
    {
        .artist = "HIATUS",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 23, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 0, .unit.minute = 45},
        .genre = SOUL,
        .popularity = 13
    },
    {
        .artist = "HUMANI",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 14, .unit.minute = 30},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "HYPERB",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 21, .unit.minute = 0},
        .genre = DUBSTEP,
        .popularity = 43
    },
    {
        .artist = "INZO  ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 19, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 20, .unit.minute = 30},
        .genre = CHILL,
        .popularity = 47
    },
    {
        .artist = "IVY LA",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 30},
        .genre = DnB,
        .popularity = 76
    },
    {
        .artist = "JASON ",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 19, .unit.minute = 15},
        .genre = DANCE,
        .popularity = 101
    },
    {
        .artist = "JENNA ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 0, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 1, .unit.minute = 0},
        .genre = TECHNO,
        .popularity = 115
    },
    {
        .artist = "JJUUJJ",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 0},
        .genre = JAM,
        .popularity = 104
    },
    {
        .artist = "JOHN S",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 0, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 2, .unit.minute = 15},
        .genre = HOUSE,
        .popularity = 8
    },
    {
        .artist = "JUELZ ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 19, .unit.minute = 15},
        .genre = CHILL,
        .popularity = 70
    },
    {
        .artist = "KALLAG",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 22, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 109
    },
    {
        .artist = "KENNY ",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 17, .unit.minute = 45},
        .genre = RAP,
        .popularity = 21
    },
    {
        .artist = "KILTRO",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 17, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 30},
        .genre = INDIE,
        .popularity = 72
    },
    {
        .artist = "KNOCK2",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 23, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 1, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 33
    },
    {
        .artist = "LAYTON",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 1, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 2, .unit.minute = 15},
        .genre = TECHNO,
        .popularity = 36
    },
    {
        .artist = "LE YOU",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 21, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 23, .unit.minute = 0},
        .genre = CHILL,
        .popularity = 45
    },
    {
        .artist = "LEAGUE",
        .stage = NO_STAGE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 15, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 0},
        .genre = JAM,
        .popularity = 0
    },
    {
        .artist = "LETTUC",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 20, .unit.minute = 0},
        .genre = JAM,
        .popularity = 59
    },
    {
        .artist = "LEVEL ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 18, .unit.minute = 15},
        .genre = DUBSTEP,
        .popularity = 69
    },
    {
        .artist = "LEVITY",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 19, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 63
    },
    {
        .artist = "LEVITY",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 19, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 63
    },
    {
        .artist = "LIBIAN",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 0},
        .genre = RAP,
        .popularity = 10
    },
    {
        .artist = "LIGHTC",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 14, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 15, .unit.minute = 45},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "LITTLE",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 17, .unit.minute = 30},
        .genre = RAP,
        .popularity = 52
    },
    {
        .artist = "LP GIO",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 22, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 23, .unit.minute = 30},
        .genre = DANCE,
        .popularity = 27
    },
    {
        .artist = "LSZEE ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 0, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 2, .unit.minute = 15},
        .genre = BASS,
        .popularity = 38
    },
    {
        .artist = "LUCII ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 19, .unit.minute = 30},
        .genre = DUBSTEP,
        .popularity = 73
    },
    {
        .artist = "LUDACR",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 15},
        .genre = RAP,
        .popularity = 2
    },
    {
        .artist = "LYNY  ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 20, .unit.minute = 45},
        .genre = DUBSTEP,
        .popularity = 77
    },
    {
        .artist = "MADDY ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 17, .unit.minute = 0},
        .genre = CHILL,
        .popularity = 86
    },
    {
        .artist = "MADDY ",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 20, .unit.minute = 30},
        .genre = CHILL,
        .popularity = 86
    },
    {
        .artist = "MAJOR ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 21, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 22, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 12
    },
    {
        .artist = "MARSH ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 23, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 0, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 49
    },
    {
        .artist = "MASCOL",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 21, .unit.minute = 30},
        .genre = POP,
        .popularity = 82
    },
    {
        .artist = "MASONI",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 13, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 14, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 0
    },
    {
        .artist = "MATROD",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 22, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 23, .unit.minute = 15},
        .genre = HOUSE,
        .popularity = 29
    },
    {
        .artist = "MAU P ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 23, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 0, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 23
    },
    {
        .artist = "MICHAE",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 21, .unit.minute = 45},
        .genre = DANCE,
        .popularity = 53
    },
    {
        .artist = "MOJAVE",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 22, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 23, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 102
    },
    {
        .artist = "MOONTR",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 17, .unit.minute = 0},
        .genre = SOUL,
        .popularity = 68
    },
    {
        .artist = "MURPH",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 1, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 2, .unit.minute = 15},
        .genre = DANCE,
        .popularity = 31
    },
    {
        .artist = "MURPH",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 19, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 20, .unit.minute = 45},
        .genre = DANCE,
        .popularity = 31
    },
    {
        .artist = "NEIL F",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 22, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 23, .unit.minute = 0},
        .genre = INDIE,
        .popularity = 15
    },
    {
        .artist = "NELLY ",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 21, .unit.minute = 30},
        .genre = POP,
        .popularity = 1
    },
    {
        .artist = "NEOMA ",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 16, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 17, .unit.minute = 30},
        .genre = POP,
        .popularity = 100
    },
    {
        .artist = "ODEN &",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 22, .unit.minute = 15},
        .genre = HOUSE,
        .popularity = 42
    },
    {
        .artist = "ONLY F",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 18, .unit.minute = 15},
        .genre = HOUSE,
        .popularity = 80
    },
    {
        .artist = "PAPERW",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 21, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 22, .unit.minute = 30},
        .genre = RAP,
        .popularity = 103
    },
    {
        .artist = "PEACH ",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 19, .unit.minute = 45},
        .genre = INDIE,
        .popularity = 30
    },
    {
        .artist = "POLITI",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 22, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 0, .unit.minute = 0},
        .genre = CHILL,
        .popularity = 112
    },
    {
        .artist = "POLYRH",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 16, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 17, .unit.minute = 30},
        .genre = SOUL,
        .popularity = 92
    },
    {
        .artist = "PRETYL",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 23, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 1, .unit.minute = 0},
        .genre = BASS,
        .popularity = 22
    },
    {
        .artist = "PRETYP",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 21, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 58
    },
    {
        .artist = "PRIDE ",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 17, .unit.minute = 0},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "PROXIM",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 17, .unit.minute = 45},
        .genre = JAM,
        .popularity = 50
    },
    {
        .artist = "RANGER",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 15},
        .genre = HOUSE,
        .popularity = 90
    },
    {
        .artist = "RAWAYA",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 18, .unit.minute = 30},
        .genre = SOUL,
        .popularity = 6
    },
    {
        .artist = "RAYBEN",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 17, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 79
    },
    {
        .artist = "REDRUM",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 17, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 0},
        .genre = CHILL,
        .popularity = 111
    },
    {
        .artist = "RUMBLE",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 15, .unit.minute = 5},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 17, .unit.minute = 0},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "RUMBLE",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 16, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 0},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "SAMMY ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 22, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 23, .unit.minute = 15},
        .genre = DnB,
        .popularity = 25
    },
    {
        .artist = "SARA L",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 1, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 2, .unit.minute = 15},
        .genre = TECHNO,
        .popularity = 37
    },
    {
        .artist = "SEVEN ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 1, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 2, .unit.minute = 0},
        .genre = BASS,
        .popularity = 14
    },
    {
        .artist = "SHAE D",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 15, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 16, .unit.minute = 45},
        .genre = HOUSE,
        .popularity = 108
    },
    {
        .artist = "SHAUN ",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 18, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 20, .unit.minute = 0},
        .genre = DANCE,
        .popularity = 78
    },
    {
        .artist = "SLAYYY",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 20, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 21, .unit.minute = 30},
        .genre = POP,
        .popularity = 24
    },
    {
        .artist = "STRING",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 22, .unit.minute = 0},
        .genre = JAM,
        .popularity = 56
    },
    {
        .artist = "STRING",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 18, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 22, .unit.minute = 30},
        .genre = JAM,
        .popularity = 56
    },
    {
        .artist = "SUBTRO",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 23, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 0, .unit.minute = 45},
        .genre = DUBSTEP,
        .popularity = 16
    },
    {
        .artist = "SULTAN",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 21, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 22, .unit.minute = 45},
        .genre = CHILL,
        .popularity = 28
    },
    {
        .artist = "SUPER ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 19, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 20, .unit.minute = 0},
        .genre = DnB,
        .popularity = 97
    },
    {
        .artist = "SWAYLO",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 21, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 0
    },
    {
        .artist = "SWAYLO",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 20, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 0
    },
    {
        .artist = " TBA  ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 22, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 23, .unit.minute = 5},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "THOUGH",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 17, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 18, .unit.minute = 15},
        .genre = CHILL,
        .popularity = 98
    },
    {
        .artist = "TRIPP ",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 20, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 21, .unit.minute = 0},
        .genre = CHILL,
        .popularity = 95
    },
    {
        .artist = "TSHA  ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 19, .unit.minute = 15},
        .genre = HOUSE,
        .popularity = 48
    },
    {
        .artist = "UMPHRE",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 17, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 19, .unit.minute = 30},
        .genre = JAM,
        .popularity = 60
    },
    {
        .artist = "UNUSUA",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 2, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 3, .unit.minute = 30},
        .genre = POP,
        .popularity = 75
    },
    {
        .artist = "UNUSUA",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 20, .unit.minute = 15},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 21, .unit.minute = 15},
        .genre = POP,
        .popularity = 75
    },
    {
        .artist = "VENBEE",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 21, .unit.minute = 55},
        .genre = DnB,
        .popularity = 41
    },
    {
        .artist = "VINI V",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 21, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 23, .unit.minute = 15},
        .genre = TECHNO,
        .popularity = 9
    },
    {
        .artist = "VNSSA ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 83
    },
    {
        .artist = "WESTEN",
        .stage = RANCH_ARENA,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 15, .unit.minute = 30},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 16, .unit.minute = 30},
        .genre = HOUSE,
        .popularity = 40
    },
    {
        .artist = "WESTEN",
        .stage = HONEYCOMB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 19, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 21, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 40
    },
    {
        .artist = "WHYTE ",
        .stage = SHERWOOD_COURT,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 21, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 22, .unit.minute = 45},
        .genre = BASS,
        .popularity = 94
    },
    {
        .artist = "WILL C",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 20, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 22, .unit.minute = 0},
        .genre = HOUSE,
        .popularity = 74
    },
    {
        .artist = "WOOLI ",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 23, .unit.minute = 45},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 0, .unit.minute = 50},
        .genre = DnB,
        .popularity = 35
    },
    {
        .artist = " YOGA1",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 11, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 21, .unit.hour = 12, .unit.minute = 15},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = " YOGA2",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 11, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 22, .unit.hour = 12, .unit.minute = 10},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = " YOGA3",
        .stage = TRIPOLEE,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 11, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 12, .unit.minute = 15},
        .genre = NO_GENRE,
        .popularity = 0
    },
    {
        .artist = "ZEN SE",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 18, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 19, .unit.minute = 0},
        .genre = DnB,
        .popularity = 107
    },
    {
        .artist = "ZINGAR",
        .stage = OBSERVATORY,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 21, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 20, .unit.hour = 22, .unit.minute = 0},
        .genre = BASS,
        .popularity = 61
    },
    {
        .artist = "6,nFor",
        .stage = CAROUSEL_CLUB,
        .start_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 12, .unit.minute = 0},
        .end_time = {.unit.year = 4, .unit.month = 6, .unit.day = 23, .unit.hour = 13, .unit.minute = 0},
        .genre = NO_GENRE,
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
