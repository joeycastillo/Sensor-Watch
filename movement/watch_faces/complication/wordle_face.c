/*
 * MIT License
 *
 * Copyright (c) 2024 <#author_name#>
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
#include "wordle_face.h"

/*
TODO:
* Add quick iteration (8x freq to get to the letter we want)
* Fix the word matching (if answer is AAAAA and we put in AACAA, the C blinks)
* Verify pressing back always work when the board is G_G_G
* Add daily streak and wait for next day
*/


/*
Letter | Usage in Text
E      | 12.7%
T      | 9.1%  But looks bad across all positions
A      | 8.2%
O      | 7.5%
I      | 7.0%
N      | 6.7%  Few uses in 5 letter words than C
S      | 6.3%
H      | 6.1%
R      | 6.0%
D      | 4.3%
L      | 4.0%
C      | 2.8%
*/
static const char _valid_letters[] = {'A', 'C', 'd', 'E', 'H', 'I', 'L', 'O', 'R', 'S'};

// From: https://github.com/charlesreid1/five-letter-words/blob/master/sgb-words.txt
static const char _legal_words[][WORDLE_LENGTH + 1] = {
"AAAAA", "SHALL", "HEARd", "ORdER", "CLOSE", "CLASS", "HORSE", "AddEd", "COLOR", "IdEAS", 
"HEARd", "ORdER", "CLOSE", "CLASS", "HORSE", "AddEd", "COLOR", "IdEAS", "CRIEd",
"ORdER", "CLOSE", "CLASS", "HORSE", "AddEd", "COLOR", "IdEAS", "CRIEd", "CLEAR",
"CLOSE", "CLASS", "HORSE", "AddEd", "COLOR", "IdEAS", "CRIEd", "CLEAR", "CHILd",
"CLASS", "HORSE", "AddEd", "COLOR", "IdEAS", "CRIEd", "CLEAR", "CHILd", "SIdES",
"HORSE", "AddEd", "COLOR", "IdEAS", "CRIEd", "CLEAR", "CHILd", "SIdES", "AREAS",
"AddEd", "COLOR", "IdEAS", "CRIEd", "CLEAR", "CHILd", "SIdES", "AREAS", "SCALE",
"COLOR", "IdEAS", "CRIEd", "CLEAR", "CHILd", "SIdES", "AREAS", "SCALE", "CELLS",
"IdEAS", "CRIEd", "CLEAR", "CHILd", "SIdES", "AREAS", "SCALE", "CELLS", "AHEAd",
"CRIEd", "CLEAR", "CHILd", "SIdES", "AREAS", "SCALE", "CELLS", "AHEAd", "REACH",
"CLEAR", "CHILd", "SIdES", "AREAS", "SCALE", "CELLS", "AHEAd", "REACH", "RAdIO",
"CHILd", "SIdES", "AREAS", "SCALE", "CELLS", "AHEAd", "REACH", "RAdIO", "LOCAL",
"SIdES", "AREAS", "SCALE", "CELLS", "AHEAd", "REACH", "RAdIO", "LOCAL", "SEEdS",
"AREAS", "SCALE", "CELLS", "AHEAd", "REACH", "RAdIO", "LOCAL", "SEEdS", "CROSS",
"SCALE", "CELLS", "AHEAd", "REACH", "RAdIO", "LOCAL", "SEEdS", "CROSS", "CASES",
"CELLS", "AHEAd", "REACH", "RAdIO", "LOCAL", "SEEdS", "CROSS", "CASES", "OLdER",
"AHEAd", "REACH", "RAdIO", "LOCAL", "SEEdS", "CROSS", "CASES", "OLdER", "SHOES",
"REACH", "RAdIO", "LOCAL", "SEEdS", "CROSS", "CASES", "OLdER", "SHOES", "CHAIR",
"RAdIO", "LOCAL", "SEEdS", "CROSS", "CASES", "OLdER", "SHOES", "CHAIR", "SCORE",
"LOCAL", "SEEdS", "CROSS", "CASES", "OLdER", "SHOES", "CHAIR", "SCORE", "SHORE",
"SEEdS", "CROSS", "CASES", "OLdER", "SHOES", "CHAIR", "SCORE", "SHORE", "HEAdS",
"CROSS", "CASES", "OLdER", "SHOES", "CHAIR", "SCORE", "SHORE", "HEAdS", "dRESS",
"CASES", "OLdER", "SHOES", "CHAIR", "SCORE", "SHORE", "HEAdS", "dRESS", "SHARE",
"OLdER", "SHOES", "CHAIR", "SCORE", "SHORE", "HEAdS", "dRESS", "SHARE", "SOLId",
"SHOES", "CHAIR", "SCORE", "SHORE", "HEAdS", "dRESS", "SHARE", "SOLId", "HILLS",
"CHAIR", "SCORE", "SHORE", "HEAdS", "dRESS", "SHARE", "SOLId", "HILLS", "RAISE",
"SCORE", "SHORE", "HEAdS", "dRESS", "SHARE", "SOLId", "HILLS", "RAISE", "ROAdS",
"SHORE", "HEAdS", "dRESS", "SHARE", "SOLId", "HILLS", "RAISE", "ROAdS", "CHORd",
"HEAdS", "dRESS", "SHARE", "SOLId", "HILLS", "RAISE", "ROAdS", "CHORd", "HOLES",
"dRESS", "SHARE", "SOLId", "HILLS", "RAISE", "ROAdS", "CHORd", "HOLES", "HOLdS",
"SHARE", "SOLId", "HILLS", "RAISE", "ROAdS", "CHORd", "HOLES", "HOLdS", "CALLS",
"SOLId", "HILLS", "RAISE", "ROAdS", "CHORd", "HOLES", "HOLdS", "CALLS", "dOORS",
"HILLS", "RAISE", "ROAdS", "CHORd", "HOLES", "HOLdS", "CALLS", "dOORS", "LOOSE",
"RAISE", "ROAdS", "CHORd", "HOLES", "HOLdS", "CALLS", "dOORS", "LOOSE", "ASIdE",
"ROAdS", "CHORd", "HOLES", "HOLdS", "CALLS", "dOORS", "LOOSE", "ASIdE", "SHELL",
"CHORd", "HOLES", "HOLdS", "CALLS", "dOORS", "LOOSE", "ASIdE", "SHELL", "dRIEd",
"HOLES", "HOLdS", "CALLS", "dOORS", "LOOSE", "ASIdE", "SHELL", "dRIEd", "SHAdE",
"HOLdS", "CALLS", "dOORS", "LOOSE", "ASIdE", "SHELL", "dRIEd", "SHAdE", "CARdS",
"CALLS", "dOORS", "LOOSE", "ASIdE", "SHELL", "dRIEd", "SHAdE", "CARdS", "CHOSE",
"dOORS", "LOOSE", "ASIdE", "SHELL", "dRIEd", "SHAdE", "CARdS", "CHOSE", "SOLAR",
"LOOSE", "ASIdE", "SHELL", "dRIEd", "SHAdE", "CARdS", "CHOSE", "SOLAR", "RISES",
"ASIdE", "SHELL", "dRIEd", "SHAdE", "CARdS", "CHOSE", "SOLAR", "RISES", "SALES",
"SHELL", "dRIEd", "SHAdE", "CARdS", "CHOSE", "SOLAR", "RISES", "SALES", "ACRES",
"dRIEd", "SHAdE", "CARdS", "CHOSE", "SOLAR", "RISES", "SALES", "ACRES", "SLIdE",
"SHAdE", "CARdS", "CHOSE", "SOLAR", "RISES", "SALES", "ACRES", "SLIdE", "ERROR",
"CARdS", "CHOSE", "SOLAR", "RISES", "SALES", "ACRES", "SLIdE", "ERROR", "RACEd",
"CHOSE", "SOLAR", "RISES", "SALES", "ACRES", "SLIdE", "ERROR", "RACEd", "dRILL",
"SOLAR", "RISES", "SALES", "ACRES", "SLIdE", "ERROR", "RACEd", "dRILL", "HELLO",
"RISES", "SALES", "ACRES", "SLIdE", "ERROR", "RACEd", "dRILL", "HELLO", "LEAdS",
"SALES", "ACRES", "SLIdE", "ERROR", "RACEd", "dRILL", "HELLO", "LEAdS", "COACH",
"ACRES", "SLIdE", "ERROR", "RACEd", "dRILL", "HELLO", "LEAdS", "COACH", "REAdS",
"SLIdE", "ERROR", "RACEd", "dRILL", "HELLO", "LEAdS", "COACH", "REAdS", "HERdS",
"ERROR", "RACEd", "dRILL", "HELLO", "LEAdS", "COACH", "REAdS", "HERdS", "AROSE",
"RACEd", "dRILL", "HELLO", "LEAdS", "COACH", "REAdS", "HERdS", "AROSE", "RACES", 
"dRILL", "HELLO", "LEAdS", "COACH", "REAdS", "HERdS", "AROSE", "RACES", "HEELS",
"HELLO", "LEAdS", "COACH", "REAdS", "HERdS", "AROSE", "RACES", "HEELS", "RIdER",
"LEAdS", "COACH", "REAdS", "HERdS", "AROSE", "RACES", "HEELS", "RIdER", "ROLLS",
"COACH", "REAdS", "HERdS", "AROSE", "RACES", "HEELS", "RIdER", "ROLLS", "CRASH",
"REAdS", "HERdS", "AROSE", "RACES", "HEELS", "RIdER", "ROLLS", "CRASH", "SAILS",
"HERdS", "AROSE", "RACES", "HEELS", "RIdER", "ROLLS", "CRASH", "SAILS", "ARISE",
"AROSE", "RACES", "HEELS", "RIdER", "ROLLS", "CRASH", "SAILS", "ARISE", "IdEAL",
"RACES", "HEELS", "RIdER", "ROLLS", "CRASH", "SAILS", "ARISE", "IdEAL", "CRIES",
"HEELS", "RIdER", "ROLLS", "CRASH", "SAILS", "ARISE", "IdEAL", "CRIES", "ASHES",
"RIdER", "ROLLS", "CRASH", "SAILS", "ARISE", "IdEAL", "CRIES", "ASHES", "CHASE",
"ROLLS", "CRASH", "SAILS", "ARISE", "IdEAL", "CRIES", "ASHES", "CHASE", "SLICE",
"CRASH", "SAILS", "ARISE", "IdEAL", "CRIES", "ASHES", "CHASE", "SLICE", "CHEER",
"SAILS", "ARISE", "IdEAL", "CRIES", "ASHES", "CHASE", "SLICE", "CHEER", "HIdES",
"ARISE", "IdEAL", "CRIES", "ASHES", "CHASE", "SLICE", "CHEER", "HIdES", "dEEdS",
"IdEAL", "CRIES", "ASHES", "CHASE", "SLICE", "CHEER", "HIdES", "dEEdS", "RIdES",
"CRIES", "ASHES", "CHASE", "SLICE", "CHEER", "HIdES", "dEEdS", "RIdES", "ROSES",
"ASHES", "CHASE", "SLICE", "CHEER", "HIdES", "dEEdS", "RIdES", "ROSES", "HIREd",
"CHASE", "SLICE", "CHEER", "HIdES", "dEEdS", "RIdES", "ROSES", "HIREd", "SALAd",
"SLICE", "CHEER", "HIdES", "dEEdS", "RIdES", "ROSES", "HIREd", "SALAd", "LOAdS",
"CHEER", "HIdES", "dEEdS", "RIdES", "ROSES", "HIREd", "SALAd", "LOAdS", "HEARS",
"HIdES", "dEEdS", "RIdES", "ROSES", "HIREd", "SALAd", "LOAdS", "HEARS", "LOSES",
"dEEdS", "RIdES", "ROSES", "HIREd", "SALAd", "LOAdS", "HEARS", "LOSES", "CORAL",
"RIdES", "ROSES", "HIREd", "SALAd", "LOAdS", "HEARS", "LOSES", "CORAL", "dAREd",
"ROSES", "HIREd", "SALAd", "LOAdS", "HEARS", "LOSES", "CORAL", "dAREd", "RAdAR",
"HIREd", "SALAd", "LOAdS", "HEARS", "LOSES", "CORAL", "dAREd", "RAdAR", "HAIRS",
"SALAd", "LOAdS", "HEARS", "LOSES", "CORAL", "dAREd", "RAdAR", "HAIRS", "dOLLS",
"LOAdS", "HEARS", "LOSES", "CORAL", "dAREd", "RAdAR", "HAIRS", "dOLLS", "CAREd",
"HEARS", "LOSES", "CORAL", "dAREd", "RAdAR", "HAIRS", "dOLLS", "CAREd", "SELLS",
"LOSES", "CORAL", "dAREd", "RAdAR", "HAIRS", "dOLLS", "CAREd", "SELLS", "COOLS",
"CORAL", "dAREd", "RAdAR", "HAIRS", "dOLLS", "CAREd", "SELLS", "COOLS", "HARSH",
"dAREd", "RAdAR", "HAIRS", "dOLLS", "CAREd", "SELLS", "COOLS", "HARSH", "SOILS",
"RAdAR", "HAIRS", "dOLLS", "CAREd", "SELLS", "COOLS", "HARSH", "SOILS", "REEdS",
"HAIRS", "dOLLS", "CAREd", "SELLS", "COOLS", "HARSH", "SOILS", "REEdS", "SHEER",
"dOLLS", "CAREd", "SELLS", "COOLS", "HARSH", "SOILS", "REEdS", "SHEER", "CHILL",
"CAREd", "SELLS", "COOLS", "HARSH", "SOILS", "REEdS", "SHEER", "CHILL", "CORdS",
"SELLS", "COOLS", "HARSH", "SOILS", "REEdS", "SHEER", "CHILL", "CORdS", "RAILS",
"COOLS", "HARSH", "SOILS", "REEdS", "SHEER", "CHILL", "CORdS", "RAILS", "dEALS",
"HARSH", "SOILS", "REEdS", "SHEER", "CHILL", "CORdS", "RAILS", "dEALS", "ACIdS",
"SOILS", "REEdS", "SHEER", "CHILL", "CORdS", "RAILS", "dEALS", "ACIdS", "COCOA",
"REEdS", "SHEER", "CHILL", "CORdS", "RAILS", "dEALS", "ACIdS", "COCOA", "SCARE",
"SHEER", "CHILL", "CORdS", "RAILS", "dEALS", "ACIdS", "COCOA", "SCARE", "CEASE",
"CHILL", "CORdS", "RAILS", "dEALS", "ACIdS", "COCOA", "SCARE", "CEASE", "SEALS",
"CORdS", "RAILS", "dEALS", "ACIdS", "COCOA", "SCARE", "CEASE", "SEALS", "LORdS",
"RAILS", "dEALS", "ACIdS", "COCOA", "SCARE", "CEASE", "SEALS", "LORdS", "HALLS",
"dEALS", "ACIdS", "COCOA", "SCARE", "CEASE", "SEALS", "LORdS", "HALLS", "COALS",
"ACIdS", "COCOA", "SCARE", "CEASE", "SEALS", "LORdS", "HALLS", "COALS", "ROdEO",
"COCOA", "SCARE", "CEASE", "SEALS", "LORdS", "HALLS", "COALS", "ROdEO", "COdES",
"SCARE", "CEASE", "SEALS", "LORdS", "HALLS", "COALS", "ROdEO", "COdES", "ELdER",
"CEASE", "SEALS", "LORdS", "HALLS", "COALS", "ROdEO", "COdES", "ELdER", "ROLES",
"SEALS", "LORdS", "HALLS", "COALS", "ROdEO", "COdES", "ELdER", "ROLES", "dREAd",
"LORdS", "HALLS", "COALS", "ROdEO", "COdES", "ELdER", "ROLES", "dREAd", "CEdAR",
"HALLS", "COALS", "ROdEO", "COdES", "ELdER", "ROLES", "dREAd", "CEdAR", "SLASH",
"COALS", "ROdEO", "COdES", "ELdER", "ROLES", "dREAd", "CEdAR", "SLASH", "CARES",
"ROdEO", "COdES", "ELdER", "ROLES", "dREAd", "CEdAR", "SLASH", "CARES", "IdOLS",
"COdES", "ELdER", "ROLES", "dREAd", "CEdAR", "SLASH", "CARES", "IdOLS", "OdORS",
"ELdER", "ROLES", "dREAd", "CEdAR", "SLASH", "CARES", "IdOLS", "OdORS", "EASEd",
"ROLES", "dREAd", "CEdAR", "SLASH", "CARES", "IdOLS", "OdORS", "EASEd", "CHOIR",
"dREAd", "CEdAR", "SLASH", "CARES", "IdOLS", "OdORS", "EASEd", "CHOIR", "AIdEd",
"CEdAR", "SLASH", "CARES", "IdOLS", "OdORS", "EASEd", "CHOIR", "AIdEd", "CHAOS",
"SLASH", "CARES", "IdOLS", "OdORS", "EASEd", "CHOIR", "AIdEd", "CHAOS", "LEASE",
"CARES", "IdOLS", "OdORS", "EASEd", "CHOIR", "AIdEd", "CHAOS", "LEASE", "SHEAR",
"IdOLS", "OdORS", "EASEd", "CHOIR", "AIdEd", "CHAOS", "LEASE", "SHEAR", "SLEdS",
"OdORS", "EASEd", "CHOIR", "AIdEd", "CHAOS", "LEASE", "SHEAR", "SLEdS", "COILS",
"EASEd", "CHOIR", "AIdEd", "CHAOS", "LEASE", "SHEAR", "SLEdS", "COILS", "ACHEd",
"CHOIR", "AIdEd", "CHAOS", "LEASE", "SHEAR", "SLEdS", "COILS", "ACHEd", "CELLO",
"AIdEd", "CHAOS", "LEASE", "SHEAR", "SLEdS", "COILS", "ACHEd", "CELLO", "dRIES",
"CHAOS", "LEASE", "SHEAR", "SLEdS", "COILS", "ACHEd", "CELLO", "dRIES", "OASIS",
"LEASE", "SHEAR", "SLEdS", "COILS", "ACHEd", "CELLO", "dRIES", "OASIS", "dRIER",
"SHEAR", "SLEdS", "COILS", "ACHEd", "CELLO", "dRIES", "OASIS", "dRIER", "CACAO",
"SLEdS", "COILS", "ACHEd", "CELLO", "dRIES", "OASIS", "dRIER", "CACAO", "EERIE",
"COILS", "ACHEd", "CELLO", "dRIES", "OASIS", "dRIER", "CACAO", "EERIE", "SCARS",
"ACHEd", "CELLO", "dRIES", "OASIS", "dRIER", "CACAO", "EERIE", "SCARS", "RAIdS",
"CELLO", "dRIES", "OASIS", "dRIER", "CACAO", "EERIE", "SCARS", "RAIdS", "SOLES",
"dRIES", "OASIS", "dRIER", "CACAO", "EERIE", "SCARS", "RAIdS", "SOLES", "CAROL",
"OASIS", "dRIER", "CACAO", "EERIE", "SCARS", "RAIdS", "SOLES", "CAROL", "CHESS",
"dRIER", "CACAO", "EERIE", "SCARS", "RAIdS", "SOLES", "CAROL", "CHESS", "OASES",
"CACAO", "EERIE", "SCARS", "RAIdS", "SOLES", "CAROL", "CHESS", "OASES", "ASSES",
"EERIE", "SCARS", "RAIdS", "SOLES", "CAROL", "CHESS", "OASES", "ASSES", "SHEdS",
"SCARS", "RAIdS", "SOLES", "CAROL", "CHESS", "OASES", "ASSES", "SHEdS", "CLASH",
"RAIdS", "SOLES", "CAROL", "CHESS", "OASES", "ASSES", "SHEdS", "CLASH", "dISCS",
"SOLES", "CAROL", "CHESS", "OASES", "ASSES", "SHEdS", "CLASH", "dISCS", "ERASE",
"CAROL", "CHESS", "OASES", "ASSES", "SHEdS", "CLASH", "dISCS", "ERASE", "CIdER",
"CHESS", "OASES", "ASSES", "SHEdS", "CLASH", "dISCS", "ERASE", "CIdER", "SHALE",
"OASES", "ASSES", "SHEdS", "CLASH", "dISCS", "ERASE", "CIdER", "SHALE", "AISLE",
"ASSES", "SHEdS", "CLASH", "dISCS", "ERASE", "CIdER", "SHALE", "AISLE", "HEIRS",
"SHEdS", "CLASH", "dISCS", "ERASE", "CIdER", "SHALE", "AISLE", "HEIRS", "ROARS",
"CLASH", "dISCS", "ERASE", "CIdER", "SHALE", "AISLE", "HEIRS", "ROARS", "SCOLd",
"dISCS", "ERASE", "CIdER", "SHALE", "AISLE", "HEIRS", "ROARS", "SCOLd", "LEASH",
"ERASE", "CIdER", "SHALE", "AISLE", "HEIRS", "ROARS", "SCOLd", "LEASH", "LASSO",
"CIdER", "SHALE", "AISLE", "HEIRS", "ROARS", "SCOLd", "LEASH", "LASSO", "CHORE",
"SHALE", "AISLE", "HEIRS", "ROARS", "SCOLd", "LEASH", "LASSO", "CHORE", "LACEd",
"AISLE", "HEIRS", "ROARS", "SCOLd", "LEASH", "LASSO", "CHORE", "LACEd", "dOSES",
"HEIRS", "ROARS", "SCOLd", "LEASH", "LASSO", "CHORE", "LACEd", "dOSES", "COLdS",
"ROARS", "SCOLd", "LEASH", "LASSO", "CHORE", "LACEd", "dOSES", "COLdS", "CORES",
"SCOLd", "LEASH", "LASSO", "CHORE", "LACEd", "dOSES", "COLdS", "CORES", "CHILI",
"LEASH", "LASSO", "CHORE", "LACEd", "dOSES", "COLdS", "CORES", "CHILI", "EASEL",
"LASSO", "CHORE", "LACEd", "dOSES", "COLdS", "CORES", "CHILI", "EASEL", "LACES",
"CHORE", "LACEd", "dOSES", "COLdS", "CORES", "CHILI", "EASEL", "LACES", "HORdE",
"LACEd", "dOSES", "COLdS", "CORES", "CHILI", "EASEL", "LACES", "HORdE", "LASER",
"dOSES", "COLdS", "CORES", "CHILI", "EASEL", "LACES", "HORdE", "LASER", "HARES",
"COLdS", "CORES", "CHILI", "EASEL", "LACES", "HORdE", "LASER", "HARES", "CREEd",
"CORES", "CHILI", "EASEL", "LACES", "HORdE", "LASER", "HARES", "CREEd", "LILAC",
"CHILI", "EASEL", "LACES", "HORdE", "LASER", "HARES", "CREEd", "LILAC", "HOOdS",
"EASEL", "LACES", "HORdE", "LASER", "HARES", "CREEd", "LILAC", "HOOdS", "ROACH",
"LACES", "HORdE", "LASER", "HARES", "CREEd", "LILAC", "HOOdS", "ROACH", "dIALS",
"HORdE", "LASER", "HARES", "CREEd", "LILAC", "HOOdS", "ROACH", "dIALS", "SOLOS",
"LASER", "HARES", "CREEd", "LILAC", "HOOdS", "ROACH", "dIALS", "SOLOS", "SISAL",
"HARES", "CREEd", "LILAC", "HOOdS", "ROACH", "dIALS", "SOLOS", "SISAL", "HOSES",
"CREEd", "LILAC", "HOOdS", "ROACH", "dIALS", "SOLOS", "SISAL", "HOSES", "dARES",
"LILAC", "HOOdS", "ROACH", "dIALS", "SOLOS", "SISAL", "HOSES", "dARES", "ACHES",
"HOOdS", "ROACH", "dIALS", "SOLOS", "SISAL", "HOSES", "dARES", "ACHES", "LOSER",
"ROACH", "dIALS", "SOLOS", "SISAL", "HOSES", "dARES", "ACHES", "LOSER", "LAdLE",
"dIALS", "SOLOS", "SISAL", "HOSES", "dARES", "ACHES", "LOSER", "LAdLE", "RAdII",
"SOLOS", "SISAL", "HOSES", "dARES", "ACHES", "LOSER", "LAdLE", "RAdII", "SORES",
"SISAL", "HOSES", "dARES", "ACHES", "LOSER", "LAdLE", "RAdII", "SORES", "RELIC",
"HOSES", "dARES", "ACHES", "LOSER", "LAdLE", "RAdII", "SORES", "RELIC", "AIdES",
"dARES", "ACHES", "LOSER", "LAdLE", "RAdII", "SORES", "RELIC", "AIdES", "ALdER",
"ACHES", "LOSER", "LAdLE", "RAdII", "SORES", "RELIC", "AIdES", "ALdER", "COdEd",
"LOSER", "LAdLE", "RAdII", "SORES", "RELIC", "AIdES", "ALdER", "COdEd", "ISLES",
"LAdLE", "RAdII", "SORES", "RELIC", "AIdES", "ALdER", "COdEd", "ISLES", "CLOdS",
"RAdII", "SORES", "RELIC", "AIdES", "ALdER", "COdEd", "ISLES", "CLOdS", "AdORE",
"SORES", "RELIC", "AIdES", "ALdER", "COdEd", "ISLES", "CLOdS", "AdORE", "RARER", 
"RELIC", "AIdES", "ALdER", "COdEd", "ISLES", "CLOdS", "AdORE", "RARER", "SILLS",
"AIdES", "ALdER", "COdEd", "ISLES", "CLOdS", "AdORE", "RARER", "SILLS", "SHOAL",
"ALdER", "COdEd", "ISLES", "CLOdS", "AdORE", "RARER", "SILLS", "SHOAL", "CACHE",
"COdEd", "ISLES", "CLOdS", "AdORE", "RARER", "SILLS", "SHOAL", "CACHE", "REELS",
"ISLES", "CLOdS", "AdORE", "RARER", "SILLS", "SHOAL", "CACHE", "REELS", "LIARS",
"CLOdS", "AdORE", "RARER", "SILLS", "SHOAL", "CACHE", "REELS", "LIARS", "SOARS",
"AdORE", "RARER", "SILLS", "SHOAL", "CACHE", "REELS", "LIARS", "SOARS", "SIdEd",
"RARER", "SILLS", "SHOAL", "CACHE", "REELS", "LIARS", "SOARS", "SIdEd", "HEALS",
"SILLS", "SHOAL", "CACHE", "REELS", "LIARS", "SOARS", "SIdEd", "HEALS", "SOdAS",
"SHOAL", "CACHE", "REELS", "LIARS", "SOARS", "SIdEd", "HEALS", "SOdAS", "ERREd",
"CACHE", "REELS", "LIARS", "SOARS", "SIdEd", "HEALS", "SOdAS", "ERREd", "ARdOR",
"REELS", "LIARS", "SOARS", "SIdEd", "HEALS", "SOdAS", "ERREd", "ARdOR", "HIRES",
"LIARS", "SOARS", "SIdEd", "HEALS", "SOdAS", "ERREd", "ARdOR", "HIRES", "LEECH",
"SOARS", "SIdEd", "HEALS", "SOdAS", "ERREd", "ARdOR", "HIRES", "LEECH", "EROdE",
"SIdEd", "HEALS", "SOdAS", "ERREd", "ARdOR", "HIRES", "LEECH", "EROdE", "HOARd",
"HEALS", "SOdAS", "ERREd", "ARdOR", "HIRES", "LEECH", "EROdE", "HOARd", "COOEd",
"SOdAS", "ERREd", "ARdOR", "HIRES", "LEECH", "EROdE", "HOARd", "COOEd", "SHREd",
"ERREd", "ARdOR", "HIRES", "LEECH", "EROdE", "HOARd", "COOEd", "SHREd", "SLOSH",
"ARdOR", "HIRES", "LEECH", "EROdE", "HOARd", "COOEd", "SHREd", "SLOSH", "CHIdE",
"HIRES", "LEECH", "EROdE", "HOARd", "COOEd", "SHREd", "SLOSH", "CHIdE", "EASES",
"LEECH", "EROdE", "HOARd", "COOEd", "SHREd", "SLOSH", "CHIdE", "EASES", "HALOS",
"EROdE", "HOARd", "COOEd", "SHREd", "SLOSH", "CHIdE", "EASES", "HALOS", "ACRId",
"HOARd", "COOEd", "SHREd", "SLOSH", "CHIdE", "EASES", "HALOS", "ACRId", "EIdER",
"COOEd", "SHREd", "SLOSH", "CHIdE", "EASES", "HALOS", "ACRId", "EIdER", "AddER",
"SHREd", "SLOSH", "CHIdE", "EASES", "HALOS", "ACRId", "EIdER", "AddER", "dEARS",
"SLOSH", "CHIdE", "EASES", "HALOS", "ACRId", "EIdER", "AddER", "dEARS", "SEERS",
"CHIdE", "EASES", "HALOS", "ACRId", "EIdER", "AddER", "dEARS", "SEERS", "OddER",
"EASES", "HALOS", "ACRId", "EIdER", "AddER", "dEARS", "SEERS", "OddER", "SIdLE",
"HALOS", "ACRId", "EIdER", "AddER", "dEARS", "SEERS", "OddER", "SIdLE", "dOLEd",
"ACRId", "EIdER", "AddER", "dEARS", "SEERS", "OddER", "SIdLE", "dOLEd", "HAILS",
"EIdER", "AddER", "dEARS", "SEERS", "OddER", "SIdLE", "dOLEd", "HAILS", "AIREd",
"AddER", "dEARS", "SEERS", "OddER", "SIdLE", "dOLEd", "HAILS", "AIREd", "COCCI",
"dEARS", "SEERS", "OddER", "SIdLE", "dOLEd", "HAILS", "AIREd", "COCCI", "SILOS",
"SEERS", "OddER", "SIdLE", "dOLEd", "HAILS", "AIREd", "COCCI", "SILOS", "dOSEd",
"OddER", "SIdLE", "dOLEd", "HAILS", "AIREd", "COCCI", "SILOS", "dOSEd", "RILLS",
"SIdLE", "dOLEd", "HAILS", "AIREd", "COCCI", "SILOS", "dOSEd", "RILLS", "EARLS",
"dOLEd", "HAILS", "AIREd", "COCCI", "SILOS", "dOSEd", "RILLS", "EARLS", "LAIRS",
"HAILS", "AIREd", "COCCI", "SILOS", "dOSEd", "RILLS", "EARLS", "LAIRS", "IdLER",
"AIREd", "COCCI", "SILOS", "dOSEd", "RILLS", "EARLS", "LAIRS", "IdLER", "SCALd",
"COCCI", "SILOS", "dOSEd", "RILLS", "EARLS", "LAIRS", "IdLER", "SCALd", "AdIOS",
"SILOS", "dOSEd", "RILLS", "EARLS", "LAIRS", "IdLER", "SCALd", "AdIOS", "dALES",
"dOSEd", "RILLS", "EARLS", "LAIRS", "IdLER", "SCALd", "AdIOS", "dALES", "HEEdS",
"RILLS", "EARLS", "LAIRS", "IdLER", "SCALd", "AdIOS", "dALES", "HEEdS", "CEdEd",
"EARLS", "LAIRS", "IdLER", "SCALd", "AdIOS", "dALES", "HEEdS", "CEdEd", "LARCH",
"LAIRS", "IdLER", "SCALd", "AdIOS", "dALES", "HEEdS", "CEdEd", "LARCH", "dOLES",
"IdLER", "SCALd", "AdIOS", "dALES", "HEEdS", "CEdEd", "LARCH", "dOLES", "dROOL",
"SCALd", "AdIOS", "dALES", "HEEdS", "CEdEd", "LARCH", "dOLES", "dROOL", "dELLS",
"AdIOS", "dALES", "HEEdS", "CEdEd", "LARCH", "dOLES", "dROOL", "dELLS", "COCOS",
"dALES", "HEEdS", "CEdEd", "LARCH", "dOLES", "dROOL", "dELLS", "COCOS", "LEERS",
"HEEdS", "CEdEd", "LARCH", "dOLES", "dROOL", "dELLS", "COCOS", "LEERS", "ALIAS",
"CEdEd", "LARCH", "dOLES", "dROOL", "dELLS", "COCOS", "LEERS", "ALIAS", "dICEd",
"LARCH", "dOLES", "dROOL", "dELLS", "COCOS", "LEERS", "ALIAS", "dICEd", "LOdES",
"dOLES", "dROOL", "dELLS", "COCOS", "LEERS", "ALIAS", "dICEd", "LOdES", "IdLEd",
"dROOL", "dELLS", "COCOS", "LEERS", "ALIAS", "dICEd", "LOdES", "IdLEd", "RACER",
"dELLS", "COCOS", "LEERS", "ALIAS", "dICEd", "LOdES", "IdLEd", "RACER", "AILEd",
"COCOS", "LEERS", "ALIAS", "dICEd", "LOdES", "IdLEd", "RACER", "AILEd", "HERES",
"LEERS", "ALIAS", "dICEd", "LOdES", "IdLEd", "RACER", "AILEd", "HERES", "IdLES",
"ALIAS", "dICEd", "LOdES", "IdLEd", "RACER", "AILEd", "HERES", "IdLES", "dOdOS",
"dICEd", "LOdES", "IdLEd", "RACER", "AILEd", "HERES", "IdLES", "dOdOS", "HELLS",
"LOdES", "IdLEd", "RACER", "AILEd", "HERES", "IdLES", "dOdOS", "HELLS", "SOLEd",
"IdLEd", "RACER", "AILEd", "HERES", "IdLES", "dOdOS", "HELLS", "SOLEd", "CASEd",
"RACER", "AILEd", "HERES", "IdLES", "dOdOS", "HELLS", "SOLEd", "CASEd", "COEdS",
"AILEd", "HERES", "IdLES", "dOdOS", "HELLS", "SOLEd", "CASEd", "COEdS", "LORES",
"HERES", "IdLES", "dOdOS", "HELLS", "SOLEd", "CASEd", "COEdS", "LORES", "REARS",
"IdLES", "dOdOS", "HELLS", "SOLEd", "CASEd", "COEdS", "LORES", "REARS", "COLIC",
"dOdOS", "HELLS", "SOLEd", "CASEd", "COEdS", "LORES", "REARS", "COLIC", "SIRES",
"HELLS", "SOLEd", "CASEd", "COEdS", "LORES", "REARS", "COLIC", "SIRES", "SORER",
"SOLEd", "CASEd", "COEdS", "LORES", "REARS", "COLIC", "SIRES", "SORER", "LOLLS",
"CASEd", "COEdS", "LORES", "REARS", "COLIC", "SIRES", "SORER", "LOLLS", "SCAdS",
"COEdS", "LORES", "REARS", "COLIC", "SIRES", "SORER", "LOLLS", "SCAdS", "LEACH",
"LORES", "REARS", "COLIC", "SIRES", "SORER", "LOLLS", "SCAdS", "LEACH", "ARCEd",
"REARS", "COLIC", "SIRES", "SORER", "LOLLS", "SCAdS", "LEACH", "ARCEd", "COREd",
"COLIC", "SIRES", "SORER", "LOLLS", "SCAdS", "LEACH", "ARCEd", "COREd", "dEAdS",
"SIRES", "SORER", "LOLLS", "SCAdS", "LEACH", "ARCEd", "COREd", "dEAdS", "dROLL",
"SORER", "LOLLS", "SCAdS", "LEACH", "ARCEd", "COREd", "dEAdS", "dROLL", "dICES",
"LOLLS", "SCAdS", "LEACH", "ARCEd", "COREd", "dEAdS", "dROLL", "dICES", "CEdES",
"SCAdS", "LEACH", "ARCEd", "COREd", "dEAdS", "dROLL", "dICES", "CEdES", "HOSEd",
"LEACH", "ARCEd", "COREd", "dEAdS", "dROLL", "dICES", "CEdES", "HOSEd", "CRESS",
"ARCEd", "COREd", "dEAdS", "dROLL", "dICES", "CEdES", "HOSEd", "CRESS", "ICIER",
"COREd", "dEAdS", "dROLL", "dICES", "CEdES", "HOSEd", "CRESS", "ICIER", "LARdS",
"dEAdS", "dROLL", "dICES", "CEdES", "HOSEd", "CRESS", "ICIER", "LARdS", "HEROS",
"dROLL", "dICES", "CEdES", "HOSEd", "CRESS", "ICIER", "LARdS", "HEROS", "SHOOS",
"dICES", "CEdES", "HOSEd", "CRESS", "ICIER", "LARdS", "HEROS", "SHOOS", "dECAL",
"CEdES", "HOSEd", "CRESS", "ICIER", "LARdS", "HEROS", "SHOOS", "dECAL", "CILIA",
"HOSEd", "CRESS", "ICIER", "LARdS", "HEROS", "SHOOS", "dECAL", "CILIA", "SEARS",
"CRESS", "ICIER", "LARdS", "HEROS", "SHOOS", "dECAL", "CILIA", "SEARS", "SARIS",
"ICIER", "LARdS", "HEROS", "SHOOS", "dECAL", "CILIA", "SEARS", "SARIS", "dILLS",
"LARdS", "HEROS", "SHOOS", "dECAL", "CILIA", "SEARS", "SARIS", "dILLS", "OILEd",
"HEROS", "SHOOS", "dECAL", "CILIA", "SEARS", "SARIS", "dILLS", "OILEd", "dOERS",
"SHOOS", "dECAL", "CILIA", "SEARS", "SARIS", "dILLS", "OILEd", "dOERS", "ALOHA",
"dECAL", "CILIA", "SEARS", "SARIS", "dILLS", "OILEd", "dOERS", "ALOHA", "RISER",
"CILIA", "SEARS", "SARIS", "dILLS", "OILEd", "dOERS", "ALOHA", "RISER", "CRIER",
"SEARS", "SARIS", "dILLS", "OILEd", "dOERS", "ALOHA", "RISER", "CRIER", "LOESS",
"SARIS", "dILLS", "OILEd", "dOERS", "ALOHA", "RISER", "CRIER", "LOESS", "dECOR",
"dILLS", "OILEd", "dOERS", "ALOHA", "RISER", "CRIER", "LOESS", "dECOR", "SHIEd",
"OILEd", "dOERS", "ALOHA", "RISER", "CRIER", "LOESS", "dECOR", "SHIEd", "dROSS",
"dOERS", "ALOHA", "RISER", "CRIER", "LOESS", "dECOR", "SHIEd", "dROSS", "CREdO",
"ALOHA", "RISER", "CRIER", "LOESS", "dECOR", "SHIEd", "dROSS", "CREdO", "ALOES",
"RISER", "CRIER", "LOESS", "dECOR", "SHIEd", "dROSS", "CREdO", "ALOES", "dIOdE",
"CRIER", "LOESS", "dECOR", "SHIEd", "dROSS", "CREdO", "ALOES", "dIOdE", "COHOS",
"LOESS", "dECOR", "SHIEd", "dROSS", "CREdO", "ALOES", "dIOdE", "COHOS", "SIREE",
"dECOR", "SHIEd", "dROSS", "CREdO", "ALOES", "dIOdE", "COHOS", "SIREE", "OCHRE",
"SHIEd", "dROSS", "CREdO", "ALOES", "dIOdE", "COHOS", "SIREE", "OCHRE", "SIREd",
"dROSS", "CREdO", "ALOES", "dIOdE", "COHOS", "SIREE", "OCHRE", "SIREd", "CAdRE",
"CREdO", "ALOES", "dIOdE", "COHOS", "SIREE", "OCHRE", "SIREd", "CAdRE", "ECHOS",
"ALOES", "dIOdE", "COHOS", "SIREE", "OCHRE", "SIREd", "CAdRE", "ECHOS", "RILEd",
"dIOdE", "COHOS", "SIREE", "OCHRE", "SIREd", "CAdRE", "ECHOS", "RILEd", "CIRCA",
"COHOS", "SIREE", "OCHRE", "SIREd", "CAdRE", "ECHOS", "RILEd", "CIRCA", "HALLO",
"SIREE", "OCHRE", "SIREd", "CAdRE", "ECHOS", "RILEd", "CIRCA", "HALLO", "SHIES",
"OCHRE", "SIREd", "CAdRE", "ECHOS", "RILEd", "CIRCA", "HALLO", "SHIES", "HOLEd",
"SIREd", "CAdRE", "ECHOS", "RILEd", "CIRCA", "HALLO", "SHIES", "HOLEd", "SEdER",
"CAdRE", "ECHOS", "RILEd", "CIRCA", "HALLO", "SHIES", "HOLEd", "SEdER", "REALS",
"ECHOS", "RILEd", "CIRCA", "HALLO", "SHIES", "HOLEd", "SEdER", "REALS", "AERIE",
"RILEd", "CIRCA", "HALLO", "SHIES", "HOLEd", "SEdER", "REALS", "AERIE", "CRASS",
"CIRCA", "HALLO", "SHIES", "HOLEd", "SEdER", "REALS", "AERIE", "CRASS", "dACHA",
"HALLO", "SHIES", "HOLEd", "SEdER", "REALS", "AERIE", "CRASS", "dACHA", "ACHOO",
"SHIES", "HOLEd", "SEdER", "REALS", "AERIE", "CRASS", "dACHA", "ACHOO", "dREAR",
"HOLEd", "SEdER", "REALS", "AERIE", "CRASS", "dACHA", "ACHOO", "dREAR", "ARIAS",
"SEdER", "REALS", "AERIE", "CRASS", "dACHA", "ACHOO", "dREAR", "ARIAS", "HOOCH",
"REALS", "AERIE", "CRASS", "dACHA", "ACHOO", "dREAR", "ARIAS", "HOOCH", "SHILL",
"AERIE", "CRASS", "dACHA", "ACHOO", "dREAR", "ARIAS", "HOOCH", "SHILL", "AHHHH",
"CRASS", "dACHA", "ACHOO", "dREAR", "ARIAS", "HOOCH", "SHILL", "AHHHH", "SHISH",
"dACHA", "ACHOO", "dREAR", "ARIAS", "HOOCH", "SHILL", "AHHHH", "SHISH", "RILES",
"ACHOO", "dREAR", "ARIAS", "HOOCH", "SHILL", "AHHHH", "SHISH", "RILES", "HEERd",
"dREAR", "ARIAS", "HOOCH", "SHILL", "AHHHH", "SHISH", "RILES", "HEERd", "CREEL",
"ARIAS", "HOOCH", "SHILL", "AHHHH", "SHISH", "RILES", "HEERd", "CREEL", "RHEAS",
"HOOCH", "SHILL", "AHHHH", "SHISH", "RILES", "HEERd", "CREEL", "RHEAS", "COdER",
"SHILL", "AHHHH", "SHISH", "RILES", "HEERd", "CREEL", "RHEAS", "COdER", "HALEd",
"AHHHH", "SHISH", "RILES", "HEERd", "CREEL", "RHEAS", "COdER", "HALEd", "CHARd",
"SHISH", "RILES", "HEERd", "CREEL", "RHEAS", "COdER", "HALEd", "CHARd", "SHOEd",
"RILES", "HEERd", "CREEL", "RHEAS", "COdER", "HALEd", "CHARd", "SHOEd", "ESSES",
"HEERd", "CREEL", "RHEAS", "COdER", "HALEd", "CHARd", "SHOEd", "ESSES", "EAREd",
"CREEL", "RHEAS", "COdER", "HALEd", "CHARd", "SHOEd", "ESSES", "EAREd", "ELIdE",
"RHEAS", "COdER", "HALEd", "CHARd", "SHOEd", "ESSES", "EAREd", "ELIdE", "SALSA",
"COdER", "HALEd", "CHARd", "SHOEd", "ESSES", "EAREd", "ELIdE", "SALSA", "AHOLd",
"HALEd", "CHARd", "SHOEd", "ESSES", "EAREd", "ELIdE", "SALSA", "AHOLd", "SHAHS",
"CHARd", "SHOEd", "ESSES", "EAREd", "ELIdE", "SALSA", "AHOLd", "SHAHS", "dISCO",
"SHOEd", "ESSES", "EAREd", "ELIdE", "SALSA", "AHOLd", "SHAHS", "dISCO", "SHARd",
"ESSES", "EAREd", "ELIdE", "SALSA", "AHOLd", "SHAHS", "dISCO", "SHARd", "CORER",
"EAREd", "ELIdE", "SALSA", "AHOLd", "SHAHS", "dISCO", "SHARd", "CORER", "COLAS", 
"ELIdE", "SALSA", "AHOLd", "SHAHS", "dISCO", "SHARd", "CORER", "COLAS", "dROId",
"SALSA", "AHOLd", "SHAHS", "dISCO", "SHARd", "CORER", "COLAS", "dROId", "OLdIE",
"AHOLd", "SHAHS", "dISCO", "SHARd", "CORER", "COLAS", "dROId", "OLdIE", "COdAS",
"SHAHS", "dISCO", "SHARd", "CORER", "COLAS", "dROId", "OLdIE", "COdAS", "ORCAS",
"dISCO", "SHARd", "CORER", "COLAS", "dROId", "OLdIE", "COdAS", "ORCAS", "HALES",
"SHARd", "CORER", "COLAS", "dROId", "OLdIE", "COdAS", "ORCAS", "HALES", "REdId",
"CORER", "COLAS", "dROId", "OLdIE", "COdAS", "ORCAS", "HALES", "REdId", "dAdOS",
"COLAS", "dROId", "OLdIE", "COdAS", "ORCAS", "HALES", "REdId", "dAdOS", "CLAdS",
"dROId", "OLdIE", "COdAS", "ORCAS", "HALES", "REdId", "dAdOS", "CLAdS", "OOdLE",
"OLdIE", "COdAS", "ORCAS", "HALES", "REdId", "dAdOS", "CLAdS", "OOdLE", "HIdER",
"COdAS", "ORCAS", "HALES", "REdId", "dAdOS", "CLAdS", "OOdLE", "HIdER", "dELIS",
"ORCAS", "HALES", "REdId", "dAdOS", "CLAdS", "OOdLE", "HIdER", "dELIS", "SCROd",
"HALES", "REdId", "dAdOS", "CLAdS", "OOdLE", "HIdER", "dELIS", "SCROd", "SHIRE",
"REdId", "dAdOS", "CLAdS", "OOdLE", "HIdER", "dELIS", "SCROd", "SHIRE", "AddLE",
"dAdOS", "CLAdS", "OOdLE", "HIdER", "dELIS", "SCROd", "SHIRE", "AddLE", "dEICE",
"CLAdS", "OOdLE", "HIdER", "dELIS", "SCROd", "SHIRE", "AddLE", "dEICE", "ORALS",
"OOdLE", "HIdER", "dELIS", "SCROd", "SHIRE", "AddLE", "dEICE", "ORALS", "HIRER",
"HIdER", "dELIS", "SCROd", "SHIRE", "AddLE", "dEICE", "ORALS", "HIRER", "ROILS",
"dELIS", "SCROd", "SHIRE", "AddLE", "dEICE", "ORALS", "HIRER", "ROILS", "dOLOR",
"SCROd", "SHIRE", "AddLE", "dEICE", "ORALS", "HIRER", "ROILS", "dOLOR", "ILIAC",
"SHIRE", "AddLE", "dEICE", "ORALS", "HIRER", "ROILS", "dOLOR", "ILIAC", "CILLS",
"AddLE", "dEICE", "ORALS", "HIRER", "ROILS", "dOLOR", "ILIAC", "CILLS", "LOCOS",
"dEICE", "ORALS", "HIRER", "ROILS", "dOLOR", "ILIAC", "CILLS", "LOCOS", "HILAR",
"ORALS", "HIRER", "ROILS", "dOLOR", "ILIAC", "CILLS", "LOCOS", "HILAR", "CROCS",
"HIRER", "ROILS", "dOLOR", "ILIAC", "CILLS", "LOCOS", "HILAR", "CROCS", "OHHHH",
"ROILS", "dOLOR", "ILIAC", "CILLS", "LOCOS", "HILAR", "CROCS", "OHHHH", "SECCO",
"dOLOR", "ILIAC", "CILLS", "LOCOS", "HILAR", "CROCS", "OHHHH", "SECCO", "SHAdS",
"ILIAC", "CILLS", "LOCOS", "HILAR", "CROCS", "OHHHH", "SECCO", "SHAdS", "CHOOS",
"CILLS", "LOCOS", "HILAR", "CROCS", "OHHHH", "SECCO", "SHAdS", "CHOOS", "AREAL",
"LOCOS", "HILAR", "CROCS", "OHHHH", "SECCO", "SHAdS", "CHOOS", "AREAL", "dIdOS",
"HILAR", "CROCS", "OHHHH", "SECCO", "SHAdS", "CHOOS", "AREAL", "dIdOS", "COOCH",
"CROCS", "OHHHH", "SECCO", "SHAdS", "CHOOS", "AREAL", "dIdOS", "COOCH", "CHILE",
"OHHHH", "SECCO", "SHAdS", "CHOOS", "AREAL", "dIdOS", "COOCH", "CHILE", "OCHER",
"SECCO", "SHAdS", "CHOOS", "AREAL", "dIdOS", "COOCH", "CHILE", "OCHER", "dOLCE",
"SHAdS", "CHOOS", "AREAL", "dIdOS", "COOCH", "CHILE", "OCHER", "dOLCE", "SLOES",
"CHOOS", "AREAL", "dIdOS", "COOCH", "CHILE", "OCHER", "dOLCE", "SLOES", "LAIRd",
"AREAL", "dIdOS", "COOCH", "CHILE", "OCHER", "dOLCE", "SLOES", "LAIRd", "SHERd",
"dIdOS", "COOCH", "CHILE", "OCHER", "dOLCE", "SLOES", "LAIRd", "SHERd", "CHARS",
"COOCH", "CHILE", "OCHER", "dOLCE", "SLOES", "LAIRd", "SHERd", "CHARS", "HAdES",
"CHILE", "OCHER", "dOLCE", "SLOES", "LAIRd", "SHERd", "CHARS", "HAdES", "HOARS",
"OCHER", "dOLCE", "SLOES", "LAIRd", "SHERd", "CHARS", "HAdES", "HOARS", "dARER",
"dOLCE", "SLOES", "LAIRd", "SHERd", "CHARS", "HAdES", "HOARS", "dARER", "ROIdS",
"SLOES", "LAIRd", "SHERd", "CHARS", "HAdES", "HOARS", "dARER", "ROIdS", "ARRAS",
"LAIRd", "SHERd", "CHARS", "HAdES", "HOARS", "dARER", "ROIdS", "ARRAS", "HALER",
"SHERd", "CHARS", "HAdES", "HOARS", "dARER", "ROIdS", "ARRAS", "HALER", "AIRER",
"CHARS", "HAdES", "HOARS", "dARER", "ROIdS", "ARRAS", "HALER", "AIRER", "CASAS",
"HAdES", "HOARS", "dARER", "ROIdS", "ARRAS", "HALER", "AIRER", "CASAS", "CARER",
"HOARS", "dARER", "ROIdS", "ARRAS", "HALER", "AIRER", "CASAS", "CARER", "OAREd",
"dARER", "ROIdS", "ARRAS", "HALER", "AIRER", "CASAS", "CARER", "OAREd", "RILLE",
"ROIdS", "ARRAS", "HALER", "AIRER", "CASAS", "CARER", "OAREd", "RILLE", "RICEd",
"ARRAS", "HALER", "AIRER", "CASAS", "CARER", "OAREd", "RILLE", "RICEd", "LIRAS",
"HALER", "AIRER", "CASAS", "CARER", "OAREd", "RILLE", "RICEd", "LIRAS", "AIdER",
"AIRER", "CASAS", "CARER", "OAREd", "RILLE", "RICEd", "LIRAS", "AIdER", "ICHOR",
"CASAS", "CARER", "OAREd", "RILLE", "RICEd", "LIRAS", "AIdER", "ICHOR", "LOCHS",
"CARER", "OAREd", "RILLE", "RICEd", "LIRAS", "AIdER", "ICHOR", "LOCHS", "CALLA",
"OAREd", "RILLE", "RICEd", "LIRAS", "AIdER", "ICHOR", "LOCHS", "CALLA", "COCAS",
"RILLE", "RICEd", "LIRAS", "AIdER", "ICHOR", "LOCHS", "CALLA", "COCAS", "OILER",
"RICEd", "LIRAS", "AIdER", "ICHOR", "LOCHS", "CALLA", "COCAS", "OILER", "ASSAI",
"LIRAS", "AIdER", "ICHOR", "LOCHS", "CALLA", "COCAS", "OILER", "ASSAI", "LAdES",
"AIdER", "ICHOR", "LOCHS", "CALLA", "COCAS", "OILER", "ASSAI", "LAdES", "SHIER",
"ICHOR", "LOCHS", "CALLA", "COCAS", "OILER", "ASSAI", "LAdES", "SHIER", "dICER",
"LOCHS", "CALLA", "COCAS", "OILER", "ASSAI", "LAdES", "SHIER", "dICER", "OLEOS",
"CALLA", "COCAS", "OILER", "ASSAI", "LAdES", "SHIER", "dICER", "OLEOS", "SHOER",
"COCAS", "OILER", "ASSAI", "LAdES", "SHIER", "dICER", "OLEOS", "SHOER", "HOdAd",
"OILER", "ASSAI", "LAdES", "SHIER", "dICER", "OLEOS", "SHOER", "HOdAd", "IOdIC",
"ASSAI", "LAdES", "SHIER", "dICER", "OLEOS", "SHOER", "HOdAd", "IOdIC", "LIERS",
"LAdES", "SHIER", "dICER", "OLEOS", "SHOER", "HOdAd", "IOdIC", "LIERS", "AIOLI",
"SHIER", "dICER", "OLEOS", "SHOER", "HOdAd", "IOdIC", "LIERS", "AIOLI", "HOERS",
"dICER", "OLEOS", "SHOER", "HOdAd", "IOdIC", "LIERS", "AIOLI", "HOERS", "SLIER",
"OLEOS", "SHOER", "HOdAd", "IOdIC", "LIERS", "AIOLI", "HOERS", "SLIER", "LASES",
"SHOER", "HOdAd", "IOdIC", "LIERS", "AIOLI", "HOERS", "SLIER", "LASES", "RASAE",
"HOdAd", "IOdIC", "LIERS", "AIOLI", "HOERS", "SLIER", "LASES", "RASAE", "SOCLE",
"IOdIC", "LIERS", "AIOLI", "HOERS", "SLIER", "LASES", "RASAE", "SOCLE", "RICER",
"LIERS", "AIOLI", "HOERS", "SLIER", "LASES", "RASAE", "SOCLE", "RICER", "HAddA",
"AIOLI", "HOERS", "SLIER", "LASES", "RASAE", "SOCLE", "RICER", "HAddA", "RICES",
"HOERS", "SLIER", "LASES", "RASAE", "SOCLE", "RICER", "HAddA", "RICES", "ROOdS",
"SLIER", "LASES", "RASAE", "SOCLE", "RICER", "HAddA", "RICES", "ROOdS", "CEdER",
"LASES", "RASAE", "SOCLE", "RICER", "HAddA", "RICES", "ROOdS", "CEdER", "CEILS",
"RASAE", "SOCLE", "RICER", "HAddA", "RICES", "ROOdS", "CEdER", "CEILS", "LISLE",
"SOCLE", "RICER", "HAddA", "RICES", "ROOdS", "CEdER", "CEILS", "LISLE", "OLIOS",
"RICER", "HAddA", "RICES", "ROOdS", "CEdER", "CEILS", "LISLE", "OLIOS", "dOSER",
"HAddA", "RICES", "ROOdS", "CEdER", "CEILS", "LISLE", "OLIOS", "dOSER", "dILdO",
"RICES", "ROOdS", "CEdER", "CEILS", "LISLE", "OLIOS", "dOSER", "dILdO", "SELAH",
"ROOdS", "CEdER", "CEILS", "LISLE", "OLIOS", "dOSER", "dILdO", "SELAH", "RIALS",
"CEdER", "CEILS", "LISLE", "OLIOS", "dOSER", "dILdO", "SELAH", "RIALS", "ICERS",
"CEILS", "LISLE", "OLIOS", "dOSER", "dILdO", "SELAH", "RIALS", "ICERS", "SHIRR",
"LISLE", "OLIOS", "dOSER", "dILdO", "SELAH", "RIALS", "ICERS", "SHIRR", "LAdEd",
"OLIOS", "dOSER", "dILdO", "SELAH", "RIALS", "ICERS", "SHIRR", "LAdEd", "LASEd",
"dOSER", "dILdO", "SELAH", "RIALS", "ICERS", "SHIRR", "LAdEd", "LASEd", "HOLER",
"SELAH", "RIALS", "ICERS", "SHIRR", "LAdEd", "LASEd", "HOLER", "LACER", "ARSES",
"dILdO", "SELAH", "RIALS", "ICERS", "SHIRR", "LAdEd", "LASEd", "HOLER", "LACER",
"RIALS", "ICERS", "SHIRR", "LAdEd", "LASEd", "HOLER", "LACER", "ARSES", "CIRRI",
"ICERS", "SHIRR", "LAdEd", "LASEd", "HOLER", "LACER", "ARSES", "CIRRI", "dIRER",
"SHIRR", "LAdEd", "LASEd", "HOLER", "LACER", "ARSES", "CIRRI", "dIRER", "ASSEd",
"LAdEd", "LASEd", "HOLER", "LACER", "ARSES", "CIRRI", "dIRER", "ASSEd", "OSIER",
};

static const uint32_t _num_words = (sizeof(_legal_words) / sizeof(_legal_words[0]));
static const uint8_t _num_valid_letters = (sizeof(_valid_letters) / sizeof(_valid_letters[0]));

static uint32_t get_random(uint32_t max) {
    #if __EMSCRIPTEN__
    return rand() % max;
    #else
    return arc4random_uniform(max);
    #endif
}

static void display_letter(wordle_state_t *state) {
    char buf[1 + 1];
    if (state->word_elements[state->position] >= _num_valid_letters) {
        watch_display_string("-", state->position + 5);
        return;
    }
    sprintf(buf, "%c", _valid_letters[state->word_elements[state->position]]);
    watch_display_string(buf, state->position + 5);
}

static void display_all_letters(wordle_state_t *state) {
    uint8_t prev_pos = state->position;
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        state->position = i;
        display_letter(state);
    }
    state->position = prev_pos;
}

static bool check_word(wordle_state_t *state) {

    // Exact
    bool is_exact_match = true;
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (_valid_letters[state->word_elements[i]] == _legal_words[state->curr_answer][i])
            state->word_elements_result[i] = WORDLE_LETTER_CORRECT;
        else {
            state->word_elements_result[i] = WORDLE_LETTER_WRONG;
            is_exact_match = false;
        }
    }
    
    // Wrong Location
     for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (state->word_elements_result[i] != WORDLE_LETTER_WRONG) continue;
        for (size_t j = 0; j < WORDLE_LENGTH; j++) {
            if (_valid_letters[state->word_elements[i]] == _legal_words[state->curr_answer][j]) {
                printf("me: %c them: %c\r\n", _valid_letters[state->word_elements[i]], _legal_words[state->curr_answer][j]);
                state->word_elements_result[j] = WORDLE_LETTER_WRONG_LOC;
                break;
            }
        }
    }

    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        printf("%d : %d\r\n", i, state->word_elements_result[i]);
    }



    return is_exact_match;
}

static void display_attempt(uint8_t attempt) {
    char buf[2];
    sprintf(buf, "%d", attempt);
    watch_display_string(buf, 3);
}

static void reset_board(wordle_state_t *state) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        state->word_elements[i] = _num_valid_letters;
        state->word_elements_result[i] = WORDLE_LETTER_WRONG;
    }
    state->curr_answer = get_random(_num_words);
    state->position = 0;
    state->attempt = 1;
    state->curr_screen = SCREEN_PLAYING;
    watch_clear_colon();
    watch_display_string(" ", 4);
    display_attempt(state->attempt);
    display_all_letters(state);
    printf("rand: %s\r\n", _legal_words[state->curr_answer]);
}

static void display_title(wordle_state_t *state) {
    char buf[11];
    state->curr_screen = SCREEN_TITLE;
    printf("streak %d \r\n", state->streak);
    sprintf(buf, "WO  St%2ddy", state->streak);
    watch_display_string(buf, 0);
    watch_set_colon();
}

static void display_lose(wordle_state_t *state, uint8_t subsecond) {
    char buf[WORDLE_LENGTH + 5];
    sprintf(buf," L   %s", subsecond % 2 ? _legal_words[state->curr_answer] : "     ");
    watch_display_string(buf, 0);
}

static void display_win(wordle_state_t *state, uint8_t subsecond) {
    char buf[11];
    sprintf(buf," W   %s  ", subsecond % 2 ? "NICE" : "JOb ");
    watch_display_string(buf, 0);
}

static uint8_t get_first_pos(WordleLetterResult *word_elements_result) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (word_elements_result[i] != WORDLE_LETTER_CORRECT)
            return i;
    }
    return 0;
}

static uint8_t get_next_pos(uint8_t curr_pos, WordleLetterResult *word_elements_result) {
    uint8_t pos = curr_pos;
    do {
        pos++;
        if (pos > WORDLE_LENGTH) return WORDLE_LENGTH + 1;
    } while (word_elements_result[pos] == WORDLE_LETTER_CORRECT);
    return pos;
}

static uint8_t get_prev_pos(uint8_t curr_pos, WordleLetterResult *word_elements_result) {
    int8_t pos = curr_pos;
    do {
        pos--;
        if (pos < 0) return curr_pos;
    } while (word_elements_result[pos] == WORDLE_LETTER_CORRECT);
    return pos;
}

static void display_result(wordle_state_t *state, uint8_t subsecond) {
    char buf[WORDLE_LENGTH + 1];
    for (size_t i = 0; i < WORDLE_LENGTH; i++)
    {
        switch (state->word_elements_result[i])
        {
        case WORDLE_LETTER_WRONG:
            buf[i] = '-';
            break;
        case WORDLE_LETTER_CORRECT:
            buf[i] = _valid_letters[state->word_elements[i]];
            break;
        case WORDLE_LETTER_WRONG_LOC:
            if (subsecond % 2)
                buf[i] = ' ';
            else
               buf[i] = _valid_letters[state->word_elements[i]]; 
        default:
            break;
        }
    }
    watch_display_string(buf, 5);
}

static bool act_on_btn(wordle_state_t *state) {
    if (state->curr_screen == SCREEN_RESULT) {
        for (size_t i = 0; i < WORDLE_LENGTH; i++) {
            if (state->word_elements_result[i] != WORDLE_LETTER_CORRECT)
                state->word_elements[i] = _num_valid_letters;
        }
        display_attempt(state->attempt);
        display_all_letters(state);
        state->position = get_first_pos(state->word_elements_result);
        state->curr_screen = SCREEN_PLAYING;
        return true;
    }
    if (state->curr_screen == SCREEN_TITLE) {
        reset_board(state);
        return true;
    }
    if (state->curr_screen >= SCREEN_WIN) {
        display_title(state);
        return true; 
    }
    return false;
}

void wordle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(wordle_state_t));
        memset(*context_ptr, 0, sizeof(wordle_state_t));
        wordle_state_t *state = (wordle_state_t *)*context_ptr;
        state->curr_screen = SCREEN_TITLE;

    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void wordle_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    wordle_state_t *state = (wordle_state_t *)context;
    movement_request_tick_frequency(2);
    if (state->curr_screen == SCREEN_TITLE)
        display_title(state);
}

bool wordle_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    wordle_state_t *state = (wordle_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            if (state->curr_screen == SCREEN_PLAYING)
                display_all_letters(state);
            break;
        case EVENT_TICK:
            switch (state->curr_screen)
            {
            case SCREEN_PLAYING:
                if (event.subsecond % 2) {
                    display_letter(state);
                } else {
                    watch_display_string(" ", state->position + 5);
                }
                break;
            case SCREEN_RESULT:
                display_result(state, event.subsecond);
                break;
            case SCREEN_LOSE:
                display_lose(state, event.subsecond);
                break;
            case SCREEN_WIN:
                display_win(state, event.subsecond);
                break;
            default:
                break;
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (act_on_btn(state)) break;
            if (state->word_elements[state->position] >= _num_valid_letters) state->word_elements[state->position] = 0;
            else state->word_elements[state->position] = (state->word_elements[state->position] + 1) % _num_valid_letters;
            display_letter(state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->word_elements[state->position] >= _num_valid_letters) state->word_elements[state->position] = _num_valid_letters - 1;
            else state->word_elements[state->position] = (state->word_elements[state->position] + _num_valid_letters - 1) % _num_valid_letters;
            display_letter(state);
            break; 
        case EVENT_ALARM_BUTTON_UP:
            if (act_on_btn(state)) break;
            display_letter(state);
            if (state->word_elements[state->position] == _num_valid_letters) break;
            state->position = get_next_pos(state->position, state->word_elements_result);
            if(WORDLE_LENGTH == (state->position)) {
                bool exact_match = check_word(state);
                if (exact_match) {
                    state->curr_screen = SCREEN_WIN;
                    state->streak++;
                    break;
                }
                if (state->attempt++ > WORDLE_MAX_ATTEMPTS) {
                    state->curr_screen = SCREEN_LOSE;
                    state->streak = 0;
                    break;
                }
                state->curr_screen = SCREEN_RESULT;
                break;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            display_letter(state);
            state->position = get_prev_pos(state->position, state->word_elements_result);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_TIMEOUT:
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void wordle_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

