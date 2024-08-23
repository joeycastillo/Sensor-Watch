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

#include <stdlib.h>
#include <string.h>
#include "wordle_face.h"
#if USE_DAILY_STREAK
#include "watch_utility.h"
#endif


static const char _valid_letters[] = {'A', 'C', 'E', 'H', 'I', 'L', 'N', 'O', 'P', 'R', 'S', 'T'};

// From: https://matthewminer.name/projects/calculators/wordle-words-left/
// Number of words found: 432
static const char _valid_words[][WORDLE_LENGTH + 1] = {
    "STALE", "TRACE", "CLOSE", "ARISE", "SNIPE", "SHIRE", "LEASH", "SAINT", "CLEAN", 
    "RELIC", "CHORE", "CRONE", "REACH", "CHAOS", "TAPIR", "CAIRN", "TENOR", "STARE", 
    "HEART", "SCOPE", "SNARL", "SLEPT", "SINCE", "EPOCH", "SPACE", "SHARE", "SPOIL", 
    "LITER", "LEAPT", "LANCE", "RANCH", "HORSE", "LEACH", "LATER", "STEAL", "CHEAP", 
    "SHORT", "ETHIC", "CHANT", "ACTOR", "SPARE", "SEPIA", "ONSET", "SPLAT", "LEANT", 
    "REACT", "OCTAL", "SPORE", "IRATE", "CORAL", "NICER", "SPILT", "SCENT", "PANIC", 
    "SHIRT", "PECAN", "SLAIN", "SPLIT", "ROACH", "ASCOT", "PHONE", "LITHE", "STOIC", 
    "STRIP", "RENAL", "POISE", "ENACT", "CHEAT", "PITCH", "NOISE", "INLET", "PEARL", 
    "POLAR", "PEACH", "STOLE", "CASTE", "CREST", "SCARE", "ETHOS", "THEIR", "STONE", 
    "SLATE", "LATCH", "HASTE", "SNARE", "SPINE", "SLANT", "SPEAR", "SCALE", "CAPER", 
    "RETCH", "PESTO", "CHIRP", "SPORT", "OPTIC", "SNAIL", "PRICE", "PLANE", "TORCH", 
    "PASTE", "RECAP", "SOLAR", "CRASH", "LINER", "OPINE", "ASHEN", "PALER", "ECLAT", 
    "SPELT", "TRIAL", "PERIL", "SLICE", "SCANT", "RAISE", "POSIT", "ATONE", "SPIRE", 
    "COAST", "INEPT", "SHOAL", "CLASH", "THORN", "PHASE", "SCORE", "TRICE", "PERCH", 
    "PORCH", "SHEAR", "CHOIR", "RHINO", "PLANT", "SHONE", "SANER", "LEARN", "ALTER", 
    "CHAIN", "PANEL", "PLIER", "STEIN", "COPSE", "SONIC", "ALIEN", "CHOSE", "ACORN", 
    "ANTIC", "CHEST", "OTHER", "CHINA", "TALON", "SCORN", "PLAIN", "PILOT", "RIPEN", 
    "PATCH", "SPICE", "CLONE", "SCION", "SCONE", "STRAP", "PARSE", "SHALE", "RISEN", 
    "CANOE", "INTER", "CRATE", "ISLET", "PRINT", "SHINE", "NORTH", "CLEAT", "PLAIT", 
    "SCRAP", "CLEAR", "SLOTH", "LAPSE", "CHAIR", "SNORT", "SHARP", "OPERA", "STAIN", 
    "TEACH", "TRAIL", "TRAIN", "LATHE", "PIANO", "PINCH", "PETAL", "STERN", "PRONE", 
    "PROSE", "PLEAT", "TROPE", "PLACE", "POSER", "INERT", "CHASE", "CAROL", "STAIR", 
    "SATIN", "SPITE", "LOATH", "ROAST", "ARSON", "SHAPE", "CLASP", "LOSER", "SALON", 
    "CATER", "SHALT", "INTRO", "ALERT", "PENAL", "SHORE", "RINSE", "CREPT", "APRON", 
    "SONAR", "AISLE", "AROSE", "HATER", "NICHE", "POINT", "EARTH", "PINTO", "THOSE", 
    "CLOTH", "NOTCH", "TOPIC", "RESIN", "SCALP", "HEIST", "HERON", "TRIPE", "TONAL", 
    "TAPER", "SHORN", "TONIC", "HOIST", "SNORE", "STORE", "SLOPE", "OCEAN", "CHART", 
    "PAINT", "SPENT", "CRANE", "CRISP", "TRASH", "PATIO", "PLATE", "HOTEL", "LEAST", 
    "ALONE", "RALPH", "SPIEL", "SIREN", "RATIO", "STOOP", "TROLL", "ATOLL", "SLASH", 
    "RETRO", "CREEP", "STILT", "SPREE", "TASTE", "CACHE", "CANON", "EATEN", "TEPEE", 
    "SHEET", "SNEER", "ERROR", "NATAL", "SLEEP", "STINT", "TROOP", "SHALL", "STALL", 
    "PIPER", "TOAST", "NASAL", "CORER", "THERE", "POOCH", "SCREE", "ELITE", "ALTAR", 
    "PENCE", "EATER", "ALPHA", "TENTH", "LINEN", "SHEER", "TAINT", "HEATH", "CRIER", 
    "TENSE", "CARAT", "CANAL", "APNEA", "THESE", "HATCH", "SHELL", "CIRCA", "APART", 
    "SPILL", "STEEL", "LOCAL", "STOOL", "SHEEN", "RESET", "STEEP", "ELATE", "PRESS", 
    "SLEET", "CROSS", "TOTAL", "TREAT", "ONION", "STATE", "CINCH", "ASSET", "THREE", 
    "TORSO", "SNOOP", "PENNE", "SPOON", "SHEEP", "PAPAL", "STILL", "CHILL", "THETA", 
    "LEECH", "INNER", "HONOR", "LOOSE", "CONIC", "SCENE", "COACH", "CONCH", "LATTE", 
    "ERASE", "ESTER", "PEACE", "PASTA", "INANE", "SPOOL", "TEASE", "HARSH", "PIECE", 
    "STEER", "SCOOP", "NINTH", "OTTER", "OCTET", "EERIE", "RISER", "LAPEL", "HIPPO", 
    "PREEN", "ETHER", "AORTA", "SENSE", "TRACT", "SHOOT", "SLOOP", "REPEL", "TITHE", 
    "IONIC", "CELLO", "CHESS", "SOOTH", "COCOA", "TITAN", "TOOTH", "TIARA", "CRESS", 
    "SLOSH", "RARER", "TERSE", "ERECT", "HELLO", "PARER", "RIPER", "NOOSE", "CREPE", 
    "CACAO", "ILIAC", "POSSE", "CACTI", "EASEL", "LASSO", "ROOST", "ALLOT", "COLON", 
    "LEPER", "TEETH", "TITLE", "HENCE", "NIECE", "PAPER", "TRITE", "SPELL", "RACER", 
    "ATTIC", "CRASS", "HITCH", "LEASE", "CEASE", "ROTOR", "ELOPE", "APPLE", "CHILI", 
    "START", "PHOTO", "SALSA", "STASH", "PRIOR", "TAROT", "COLOR", "CHEER", "CLASS", 
    "ARENA", "ELECT", "ENTER", "CATCH", "TENET", "TACIT", "TRAIT", "TERRA", "LILAC", 
};

// These are words that'll never be used, but still need to be in the dictionary for guesses.
static const char _possible_words[][WORDLE_LENGTH + 1] = {
    "AALII", "AARTI", "ACAIS", "ACARI", "ACCAS", "ACERS", "ACETA", "ACHAR", "ACHES", 
    "ACHOO", "ACINI", "ACNES", "ACRES", "ACROS", "ACTIN", "ACTON", "AECIA", "AEONS", 
    "AERIE", "AEROS", "AESIR", "AHEAP", "AHENT", "AHINT", "AINEE", "AIOLI", "AIRER", 
    "AIRNS", "AIRTH", "AIRTS", "AITCH", "ALAAP", "ALANE", "ALANS", "ALANT", "ALAPA", 
    "ALAPS", "ALATE", "ALCOS", "ALECS", "ALEPH", "ALIAS", "ALINE", "ALIST", "ALLEE", 
    "ALLEL", "ALLIS", "ALOES", "ALOHA", "ALOIN", "ALOOS", "ALTHO", "ALTOS", "ANANA", 
    "ANATA", "ANCHO", "ANCLE", "ANCON", "ANEAR", "ANELE", "ANENT", "ANILE", "ANILS", 
    "ANION", "ANISE", "ANLAS", "ANNAL", "ANNAS", "ANNAT", "ANOAS", "ANOLE", "ANSAE", 
    "ANTAE", "ANTAR", "ANTAS", "ANTES", "ANTIS", "ANTRA", "ANTRE", "APACE", "APERS", 
    "APERT", "APHIS", "APIAN", "APIOL", "APISH", "APOOP", "APORT", "APPAL", "APPEL", 
    "APPRO", "APRES", "APSES", "APSIS", "APSOS", "APTER", "ARARS", "ARCHI", "ARCOS", 
    "AREAE", "AREAL", "AREAR", "AREAS", "ARECA", "AREIC", "ARENE", "AREPA", "ARERE", 
    "ARETE", "ARETS", "ARETT", "ARHAT", "ARIAS", "ARIEL", "ARILS", "ARIOT", "ARISH", 
    "ARLES", "ARNAS", "AROHA", "ARPAS", "ARPEN", "ARRAH", "ARRAS", "ARRET", "ARRIS", 
    "ARSES", "ARSIS", "ARTAL", "ARTEL", "ARTIC", "ARTIS", "ASANA", "ASCON", "ASHES", 
    "ASHET", "ASPEN", "ASPER", "ASPIC", "ASPIE", "ASPIS", "ASPRO", "ASSAI", "ASSES", 
    "ASSOT", "ASTER", "ASTIR", "ATAPS", "ATILT", "ATLAS", "ATOCS", "ATRIA", "ATRIP", 
    "ATTAP", "ATTAR", "CACAS", "CAECA", "CAESE", "CAINS", "CALLA", "CALLS", "CALOS", 
    "CALPA", "CALPS", "CANEH", "CANER", "CANES", "CANNA", "CANNS", "CANSO", "CANST", 
    "CANTO", "CANTS", "CAPAS", "CAPES", "CAPHS", "CAPLE", "CAPON", "CAPOS", "CAPOT", 
    "CAPRI", "CARAP", "CARER", "CARES", "CARET", "CARLE", "CARLS", "CARNS", "CARON", 
    "CARPI", "CARPS", "CARRS", "CARSE", "CARTA", "CARTE", "CARTS", "CASAS", "CASCO", 
    "CASES", "CASTS", "CATES", "CECAL", "CEILI", "CEILS", "CELLA", "CELLI", "CELLS", 
    "CELTS", "CENSE", "CENTO", "CENTS", "CEORL", "CEPES", "CERCI", "CERES", "CERIA", 
    "CERIC", "CERNE", "CEROC", "CEROS", "CERTS", "CESSE", "CESTA", "CESTI", "CETES", 
    "CHACE", "CHACO", "CHAIS", "CHALS", "CHANA", "CHAPE", "CHAPS", "CHAPT", "CHARA", 
    "CHARE", "CHARR", "CHARS", "CHATS", "CHEEP", "CHELA", "CHELP", "CHERE", "CHERT", 
    "CHETH", "CHIAO", "CHIAS", "CHICA", "CHICH", "CHICO", "CHICS", "CHIEL", "CHILE", 
    "CHINE", "CHINO", "CHINS", "CHIPS", "CHIRL", "CHIRO", "CHIRR", "CHIRT", "CHITS", 
    "CHOCO", "CHOCS", "CHOIL", "CHOLA", "CHOLI", "CHOLO", "CHONS", "CHOON", "CHOPS", 
    "CHOTA", "CHOTT", "CIELS", "CILIA", "CILLS", "CINCT", "CINES", "CIONS", "CIPPI", 
    "CIRCS", "CIRES", "CIRLS", "CIRRI", "CISCO", "CISTS", "CITAL", "CITER", "CITES", 
    "CLACH", "CLAES", "CLANS", "CLAPS", "CLAPT", "CLARO", "CLART", "CLAST", "CLATS", 
    "CLEEP", "CLEPE", "CLEPT", "CLIES", "CLINE", "CLINT", "CLIPE", "CLIPS", "CLIPT", 
    "CLITS", "CLONS", "CLOOP", "CLOOT", "CLOPS", "CLOTE", "CLOTS", "COACT", "COALA", 
    "COALS", "COAPT", "COATE", "COATI", "COATS", "COCAS", "COCCI", "COCCO", "COCOS", 
    "COHEN", "COHOE", "COHOS", "COILS", "COINS", "COIRS", "COITS", "COLAS", "COLES", 
    "COLIC", "COLIN", "COLLS", "COLTS", "CONES", "CONIA", "CONIN", "CONNE", "CONNS", 
    "CONTE", "CONTO", "COOCH", "COOEE", "COOER", "COOLS", "COONS", "COOPS", "COOPT", 
    "COOST", "COOTS", "COPAL", "COPEN", "COPER", "COPES", "COPRA", "CORES", "CORIA", 
    "CORNI", "CORNO", "CORNS", "CORPS", "CORSE", "CORSO", "COSEC", "COSES", "COSET", 
    "COSIE", "COSTA", "COSTE", "COSTS", "COTAN", "COTES", "COTHS", "COTTA", "COTTS", 
    "CRAAL", "CRAIC", "CRANS", "CRAPE", "CRAPS", "CRARE", "CREEL", "CREES", "CRENA", 
    "CREPS", "CRIAS", "CRIES", "CRINE", "CRIOS", "CRIPE", "CRIPS", "CRISE", "CRITH", 
    "CRITS", "CROCI", "CROCS", "CRONS", "CROOL", "CROON", "CROPS", "CRORE", "CROST", 
    "CTENE", "EALES", "EARLS", "EARNS", "EARNT", "EARST", "EASER", "EASES", "EASLE", 
    "EASTS", "EATHE", "ECHES", "ECHOS", "EISEL", "ELAIN", "ELANS", "ELCHI", "ELINT", 
    "ELOIN", "ELOPS", "ELPEE", "ELSIN", "ENATE", "ENIAC", "ENLIT", "ENOLS", "ENROL", 
    "ENTIA", "EORLS", "EOSIN", "EPACT", "EPEES", "EPHAH", "EPHAS", "EPHOR", "EPICS", 
    "EPOPT", "EPRIS", "ERICA", "ERICS", "ERNES", "EROSE", "ERSES", "ESCAR", "ESCOT", 
    "ESILE", "ESNES", "ESSES", "ESTOC", "ESTOP", "ESTRO", "ETAPE", "ETATS", "ETENS", 
    "ETHAL", "ETHNE", "ETICS", "ETNAS", "ETTIN", "ETTLE", "HAARS", "HAETS", "HAHAS", 
    "HAILS", "HAINS", "HAINT", "HAIRS", "HAITH", "HALAL", "HALER", "HALES", "HALLO", 
    "HALLS", "HALON", "HALOS", "HALSE", "HALTS", "HANAP", "HANCE", "HANCH", "HANSA", 
    "HANSE", "HANTS", "HAOLE", "HAPPI", "HARES", "HARLS", "HARNS", "HAROS", "HARPS", 
    "HARTS", "HASPS", "HASTA", "HATES", "HATHA", "HEALS", "HEAPS", "HEARE", "HEARS", 
    "HEAST", "HEATS", "HECHT", "HEELS", "HEILS", "HEIRS", "HELES", "HELIO", "HELLS", 
    "HELOS", "HELOT", "HELPS", "HENCH", "HENNA", "HENTS", "HEPAR", "HERES", "HERLS", 
    "HERNS", "HEROS", "HERSE", "HESPS", "HESTS", "HETES", "HETHS", "HIANT", "HILAR", 
    "HILCH", "HILLO", "HILLS", "HILTS", "HINTS", "HIOIS", "HIREE", "HIRER", "HIRES", 
    "HISTS", "HITHE", "HOARS", "HOAST", "HOERS", "HOISE", "HOLES", "HOLLA", "HOLLO", 
    "HOLON", "HOLOS", "HOLTS", "HONAN", "HONER", "HONES", "HOOCH", "HOONS", "HOOPS", 
    "HOORS", "HOOSH", "HOOTS", "HOPER", "HOPES", "HORAH", "HORAL", "HORAS", "HORIS", 
    "HORNS", "HORST", "HOSEL", "HOSEN", "HOSER", "HOSES", "HOSTA", "HOSTS", "HOTCH", 
    "HOTEN", "ICERS", "ICHES", "ICHOR", "ICIER", "ICONS", "ICTAL", "ICTIC", "ILEAC", 
    "ILEAL", "ILIAL", "ILLER", "ILLTH", "INAPT", "INCEL", "INCLE", "INION", "INNIT", 
    "INSET", "INSPO", "INTEL", "INTIL", "INTIS", "INTRA", "IOTAS", "IPPON", "IRONE", 
    "IRONS", "ISHES", "ISLES", "ISNAE", "ISSEI", "ISTLE", "ITHER", "LAARI", "LACER", 
    "LACES", "LACET", "LAERS", "LAHAL", "LAHAR", "LAICH", "LAICS", "LAIRS", "LAITH", 
    "LALLS", "LANAI", "LANAS", "LANCH", "LANES", "LANTS", "LAPIN", "LAPIS", "LARCH", 
    "LAREE", "LARES", "LARIS", "LARNS", "LARNT", "LASER", "LASES", "LASSI", "LASTS", 
    "LATAH", "LATEN", "LATHI", "LATHS", "LEANS", "LEAPS", "LEARE", "LEARS", "LEATS", 
    "LEEAR", "LEEPS", "LEERS", "LEESE", "LEETS", "LEHRS", "LEIRS", "LEISH", "LENES", 
    "LENIS", "LENOS", "LENSE", "LENTI", "LENTO", "LEONE", "LEPRA", "LEPTA", "LERES", 
    "LERPS", "LESES", "LESTS", "LETCH", "LETHE", "LIANA", "LIANE", "LIARS", "LIART", 
    "LICHI", "LICHT", "LICIT", "LIENS", "LIERS", "LILLS", "LILOS", "LILTS", "LINAC", 
    "LINCH", "LINES", "LININ", "LINNS", "LINOS", "LINTS", "LIONS", "LIPAS", "LIPES", 
    "LIPIN", "LIPOS", "LIRAS", "LIROT", "LISLE", "LISPS", "LISTS", "LITAI", "LITAS", 
    "LITES", "LITHO", "LITHS", "LITRE", "LLANO", "LOACH", "LOANS", "LOAST", "LOCHE", 
    "LOCHS", "LOCIE", "LOCIS", "LOCOS", "LOESS", "LOHAN", "LOINS", "LOIPE", "LOIRS", 
    "LOLLS", "LONER", "LOOIE", "LOONS", "LOOPS", "LOOTS", "LOPER", "LOPES", "LORAL", 
    "LORAN", "LOREL", "LORES", "LORIC", "LORIS", "LOSEL", "LOSEN", "LOSES", "LOTAH", 
    "LOTAS", "LOTES", "LOTIC", "LOTOS", "LOTSA", "LOTTA", "LOTTE", "LOTTO", "NAANS", 
    "NACHE", "NACHO", "NACRE", "NAHAL", "NAILS", "NAIRA", "NALAS", "NALLA", "NANAS", 
    "NANCE", "NANNA", "NANOS", "NAPAS", "NAPES", "NAPOO", "NAPPA", "NAPPE", "NARAS", 
    "NARCO", "NARCS", "NARES", "NARIC", "NARIS", "NARRE", "NASHI", "NATCH", "NATES", 
    "NATIS", "NEALS", "NEAPS", "NEARS", "NEATH", "NEATS", "NEELE", "NEEPS", "NEESE", 
    "NEIST", "NELIS", "NENES", "NEONS", "NEPER", "NEPIT", "NERAL", "NEROL", "NERTS", 
    "NESTS", "NETES", "NETOP", "NETTS", "NICHT", "NICOL", "NIHIL", "NILLS", "NINER", 
    "NINES", "NINON", "NIPAS", "NIRLS", "NISEI", "NISSE", "NITER", "NITES", "NITON", 
    "NITRE", "NITRO", "NOAHS", "NOELS", "NOILS", "NOINT", "NOIRS", "NOLES", "NOLLS", 
    "NOLOS", "NONAS", "NONCE", "NONES", "NONET", "NONIS", "NOOIT", "NOONS", "NOOPS", 
    "NOPAL", "NORIA", "NORIS", "NOSER", "NOSES", "NOTAL", "NOTER", "NOTES", "OASES", 
    "OASIS", "OASTS", "OATEN", "OATER", "OATHS", "OCHER", "OCHES", "OCHRE", "OCREA", 
    "OCTAN", "OCTAS", "OHIAS", "OHONE", "OILER", "OINTS", "OLEIC", "OLEIN", "OLENT", 
    "OLEOS", "OLIOS", "OLLAS", "OLLER", "OLLIE", "OLPAE", "OLPES", "ONCER", "ONCES", 
    "ONCET", "ONERS", "ONTIC", "OONTS", "OORIE", "OOSES", "OPAHS", "OPALS", "OPENS", 
    "OPEPE", "OPPOS", "OPSIN", "OPTER", "ORACH", "ORALS", "ORANT", "ORATE", "ORCAS", 
    "ORCIN", "ORIEL", "ORLES", "ORLON", "ORLOP", "ORNIS", "ORPIN", "ORRIS", "ORTHO", 
    "OSCAR", "OSHAC", "OSIER", "OSSIA", "OSTIA", "OTTAR", "OTTOS", "PAALS", "PAANS", 
    "PACAS", "PACER", "PACES", "PACHA", "PACOS", "PACTA", "PACTS", "PAEAN", "PAEON", 
    "PAILS", "PAINS", "PAIRE", "PAIRS", "PAISA", "PAISE", "PALAS", "PALEA", "PALES", 
    "PALET", "PALIS", "PALLA", "PALLS", "PALPI", "PALPS", "PALSA", "PANCE", "PANES", 
    "PANNE", "PANNI", "PANTO", "PANTS", "PAOLI", "PAOLO", "PAPAS", "PAPES", "PAPPI", 
    "PARAE", "PARAS", "PARCH", "PAREN", "PAREO", "PARES", "PARIS", "PARLE", "PAROL", 
    "PARPS", "PARRA", "PARRS", "PARTI", "PARTS", "PASEO", "PASES", "PASHA", "PASSE", 
    "PASTS", "PATEN", "PATER", "PATES", "PATHS", "PATIN", "PATTE", "PEALS", "PEANS", 
    "PEARE", "PEARS", "PEART", "PEASE", "PEATS", "PECHS", "PEECE", "PEELS", "PEENS", 
    "PEEPE", "PEEPS", "PEERS", "PEINS", "PEISE", "PELAS", "PELES", "PELLS", "PELON", 
    "PELTA", "PELTS", "PENES", "PENIE", "PENIS", "PENNA", "PENNI", "PENTS", "PEONS", 
    "PEPLA", "PEPOS", "PEPSI", "PERAI", "PERCE", "PERCS", "PEREA", "PERES", "PERIS", 
    "PERNS", "PERPS", "PERSE", "PERST", "PERTS", "PESOS", "PESTS", "PETAR", "PETER", 
    "PETIT", "PETRE", "PETRI", "PETTI", "PETTO", "PHARE", "PHEER", "PHENE", "PHEON", 
    "PHESE", "PHIAL", "PHISH", "PHOCA", "PHONO", "PHONS", "PHOTS", "PHPHT", "PIANI", 
    "PIANS", "PICAL", "PICAS", "PICOT", "PICRA", "PIERS", "PIERT", "PIETA", "PIETS", 
    "PILAE", "PILAO", "PILAR", "PILCH", "PILEA", "PILEI", "PILER", "PILES", "PILIS", 
    "PILLS", "PINAS", "PINES", "PINNA", "PINON", "PINOT", "PINTA", "PINTS", "PIONS", 
    "PIPAL", "PIPAS", "PIPES", "PIPET", "PIPIS", "PIPIT", "PIRAI", "PIRLS", "PIRNS", 
    "PISCO", "PISES", "PISOS", "PISTE", "PITAS", "PITHS", "PITON", "PITOT", "PITTA", 
    "PLAAS", "PLANS", "PLAPS", "PLASH", "PLAST", "PLATS", "PLATT", "PLEAS", "PLENA", 
    "PLEON", "PLESH", "PLICA", "PLIES", "PLOAT", "PLOPS", "PLOTS", "POACH", "POEPS", 
    "POETS", "POLER", "POLES", "POLIO", "POLIS", "POLLS", "POLOS", "POLTS", "PONCE", 
    "PONES", "PONTS", "POOHS", "POOLS", "POONS", "POOPS", "POORI", "POORT", "POOTS", 
    "POPES", "POPPA", "PORAE", "PORAL", "PORER", "PORES", "PORIN", "PORNO", "PORNS", 
    "PORTA", "PORTS", "POSES", "POSHO", "POSTS", "POTAE", "POTCH", "POTES", "POTIN", 
    "POTOO", "POTTO", "POTTS", "PRANA", "PRAOS", "PRASE", "PRATE", "PRATS", "PRATT", 
    "PREES", "PRENT", "PREON", "PREOP", "PREPS", "PRESA", "PRESE", "PREST", "PRIAL", 
    "PRIER", "PRIES", "PRILL", "PRION", "PRISE", "PRISS", "PROAS", "PROIN", "PROLE", 
    "PROLL", "PROPS", "PRORE", "PROSO", "PROSS", "PROST", "PROTO", "PSION", "PSOAE", 
    "PSOAI", "PSOAS", "PSORA", "RACES", "RACHE", "RACON", "RAIAS", "RAILE", "RAILS", 
    "RAINE", "RAINS", "RAITA", "RAITS", "RALES", "RANAS", "RANCE", "RANEE", "RANIS", 
    "RANTS", "RAPER", "RAPES", "RAPHE", "RAPPE", "RAREE", "RARES", "RASER", "RASES", 
    "RASPS", "RASSE", "RASTA", "RATAL", "RATAN", "RATAS", "RATCH", "RATEL", "RATER", 
    "RATES", "RATHA", "RATHE", "RATHS", "RATOO", "RATOS", "REAIS", "REALO", "REALS", 
    "REANS", "REAPS", "REARS", "REAST", "REATA", "REATE", "RECAL", "RECCE", "RECCO", 
    "RECIT", "RECON", "RECTA", "RECTI", "RECTO", "REECH", "REELS", "REENS", "REEST", 
    "REINS", "REIST", "RELET", "RELIE", "RELIT", "RELLO", "RENIN", "RENNE", "RENOS", 
    "RENTE", "RENTS", "REOIL", "REPIN", "REPLA", "REPOS", "REPOT", "REPPS", "REPRO", 
    "RERAN", "RESAT", "RESEE", "RESES", "RESIT", "RESTO", "RESTS", "RETIA", "RETIE", 
    "RHEAS", "RHIES", "RHINE", "RHONE", "RIALS", "RIANT", "RIATA", "RICER", "RICES", 
    "RICHT", "RICIN", "RIELS", "RILES", "RILLE", "RILLS", "RINES", "RIOTS", "RIPES", 
    "RIPPS", "RISES", "RISHI", "RISPS", "RITES", "RITTS", "ROANS", "ROARS", "ROATE", 
    "ROHES", "ROILS", "ROINS", "ROIST", "ROLES", "ROLLS", "RONEO", "RONES", "RONIN", 
    "RONNE", "RONTE", "RONTS", "ROONS", "ROOPS", "ROOSA", "ROOSE", "ROOTS", "ROPER", 
    "ROPES", "RORAL", "RORES", "RORIC", "RORIE", "RORTS", "ROSES", "ROSET", "ROSHI", 
    "ROSIN", "ROSIT", "ROSTI", "ROSTS", "ROTAL", "ROTAN", "ROTAS", "ROTCH", "ROTES", 
    "ROTIS", "ROTLS", "ROTON", "ROTOS", "ROTTE", "SACRA", "SAICE", "SAICS", "SAILS", 
    "SAINE", "SAINS", "SAIRS", "SAIST", "SAITH", "SALAL", "SALAT", "SALEP", "SALES", 
    "SALET", "SALIC", "SALLE", "SALOL", "SALOP", "SALPA", "SALPS", "SALSE", "SALTO", 
    "SALTS", "SANES", "SANSA", "SANTO", "SANTS", "SAOLA", "SAPAN", "SAPOR", "SARAN", 
    "SAREE", "SARIN", "SARIS", "SAROS", "SASER", "SASIN", "SASSE", "SATAI", "SATES", 
    "SATIS", "SCAIL", "SCALA", "SCALL", "SCANS", "SCAPA", "SCAPE", "SCAPI", "SCARP", 
    "SCARS", "SCART", "SCATH", "SCATS", "SCATT", "SCEAT", "SCENA", "SCOOT", "SCOPA", 
    "SCOPS", "SCOTS", "SCRAE", "SCRAN", "SCRAT", "SCRIP", "SEALS", "SEANS", "SEARE", 
    "SEARS", "SEASE", "SEATS", "SECCO", "SECHS", "SECTS", "SEELS", "SEEPS", "SEERS", 
    "SEHRI", "SEILS", "SEINE", "SEIRS", "SEISE", "SELAH", "SELES", "SELLA", "SELLE", 
    "SELLS", "SENAS", "SENES", "SENNA", "SENOR", "SENSA", "SENSI", "SENTE", "SENTI", 
    "SENTS", "SEPAL", "SEPIC", "SEPTA", "SEPTS", "SERAC", "SERAI", "SERAL", "SERER", 
    "SERES", "SERIC", "SERIN", "SERON", "SERRA", "SERRE", "SERRS", "SESSA", "SETAE", 
    "SETAL", "SETON", "SETTS", "SHAHS", "SHANS", "SHAPS", "SHARN", "SHASH", "SHCHI", 
    "SHEAL", "SHEAS", "SHEEL", "SHENT", "SHEOL", "SHERE", "SHERO", "SHETS", "SHIAI", 
    "SHIEL", "SHIER", "SHIES", "SHILL", "SHINS", "SHIPS", "SHIRR", "SHIRS", "SHISH", 
    "SHISO", "SHIST", "SHITE", "SHITS", "SHLEP", "SHOAT", "SHOER", "SHOES", "SHOLA", 
    "SHOOL", "SHOON", "SHOOS", "SHOPE", "SHOPS", "SHORL", "SHOTE", "SHOTS", "SHOTT", 
    "SHRIS", "SIALS", "SICES", "SICHT", "SIENS", "SIENT", "SIETH", "SILEN", "SILER", 
    "SILES", "SILLS", "SILOS", "SILTS", "SINES", "SINHS", "SIPES", "SIREE", "SIRES", 
    "SIRIH", "SIRIS", "SIROC", "SIRRA", "SISAL", "SISES", "SISTA", "SISTS", "SITAR", 
    "SITES", "SITHE", "SLAES", "SLANE", "SLAPS", "SLART", "SLATS", "SLEER", "SLIER", 
    "SLIPE", "SLIPS", "SLIPT", "SLISH", "SLITS", "SLOAN", "SLOES", "SLOOT", "SLOPS", 
    "SLOTS", "SNAPS", "SNARS", "SNASH", "SNATH", "SNEAP", "SNEES", "SNELL", "SNIES", 
    "SNIPS", "SNIRT", "SNITS", "SNOEP", "SNOOL", "SNOOT", "SNOTS", "SOAPS", "SOARE", 
    "SOARS", "SOCAS", "SOCES", "SOCLE", "SOILS", "SOLAH", "SOLAN", "SOLAS", "SOLEI", 
    "SOLER", "SOLES", "SOLON", "SOLOS", "SONCE", "SONES", "SONNE", "SONSE", "SOOLE", 
    "SOOLS", "SOOPS", "SOOTE", "SOOTS", "SOPHS", "SOPOR", "SOPRA", "SORAL", "SORAS", 
    "SOREE", "SOREL", "SORER", "SORES", "SORNS", "SORRA", "SORTA", "SORTS", "SOTHS", 
    "SOTOL", "SPAER", "SPAES", "SPAHI", "SPAIL", "SPAIN", "SPAIT", "SPALE", "SPALL", 
    "SPALT", "SPANE", "SPANS", "SPARS", "SPART", "SPATE", "SPATS", "SPEAL", "SPEAN", 
    "SPEAT", "SPECS", "SPECT", "SPEEL", "SPEER", "SPEIL", "SPEIR", "SPEOS", "SPETS", 
    "SPIAL", "SPICA", "SPICS", "SPIER", "SPIES", "SPILE", "SPINA", "SPINS", "SPIRT", 
    "SPITS", "SPOOR", "SPOOT", "SPOSH", "SPOTS", "SPRAT", "SPRIT", "STANE", "STAPH", 
    "STAPS", "STARN", "STARR", "STARS", "STATS", "STEAN", "STEAR", "STEEN", "STEIL", 
    "STELA", "STELE", "STELL", "STENO", "STENS", "STENT", "STEPS", "STEPT", "STERE", 
    "STETS", "STICH", "STIES", "STILE", "STIPA", "STIPE", "STIRE", "STIRP", "STIRS", 
    "STOAE", "STOAI", "STOAS", "STOAT", "STOEP", "STOIT", "STOLN", "STONN", "STOOR", 
    "STOPE", "STOPS", "STOPT", "STOSS", "STOTS", "STOTT", "STRAE", "STREP", "STRIA", 
    "STROP", "TAALS", "TAATA", "TACAN", "TACES", "TACET", "TACHE", "TACHO", "TACHS", 
    "TACOS", "TACTS", "TAELS", "TAHAS", "TAHRS", "TAILS", "TAINS", "TAIRA", "TAISH", 
    "TAITS", "TALAR", "TALAS", "TALCS", "TALEA", "TALER", "TALES", "TALLS", "TALPA", 
    "TANAS", "TANHS", "TANNA", "TANTI", "TANTO", "TAPAS", "TAPEN", "TAPES", "TAPET", 
    "TAPIS", "TAPPA", "TARAS", "TARES", "TARNS", "TAROC", "TAROS", "TARPS", "TARRE", 
    "TARSI", "TARTS", "TASAR", "TASER", "TASES", "TASSA", "TASSE", "TASSO", "TATAR", 
    "TATER", "TATES", "TATHS", "TATIE", "TATTS", "TEALS", "TEARS", "TEATS", "TECHS", 
    "TECTA", "TEELS", "TEENE", "TEENS", "TEERS", "TEHRS", "TEILS", "TEINS", "TELAE", 
    "TELCO", "TELES", "TELIA", "TELIC", "TELLS", "TELOI", "TELOS", "TENCH", "TENES", 
    "TENIA", "TENNE", "TENNO", "TENON", "TENTS", "TEPAL", "TEPAS", "TERAI", "TERAS", 
    "TERCE", "TERES", "TERNE", "TERNS", "TERTS", "TESLA", "TESTA", "TESTE", "TESTS", 
    "TETES", "TETHS", "TETRA", "TETRI", "THALE", "THALI", "THANA", "THANE", "THANS", 
    "THARS", "THECA", "THEES", "THEIC", "THEIN", "THENS", "THESP", "THETE", "THILL", 
    "THINE", "THINS", "THIOL", "THIRL", "THOLE", "THOLI", "THORO", "THORP", "THRAE", 
    "THRIP", "THROE", "TIANS", "TIARS", "TICAL", "TICCA", "TICES", "TIERS", "TILER", 
    "TILES", "TILLS", "TILTH", "TILTS", "TINAS", "TINCT", "TINEA", "TINES", "TINTS", 
    "TIPIS", "TIRES", "TIRLS", "TIROS", "TIRRS", "TITCH", "TITER", "TITIS", "TITRE", 
    "TOCOS", "TOEAS", "TOHOS", "TOILE", "TOILS", "TOISE", "TOITS", "TOLAN", "TOLAR", 
    "TOLAS", "TOLES", "TOLLS", "TOLTS", "TONER", "TONES", "TONNE", "TOOLS", "TOONS", 
    "TOOTS", "TOPEE", "TOPER", "TOPES", "TOPHE", "TOPHI", "TOPHS", "TOPIS", "TOPOI", 
    "TOPOS", "TORAH", "TORAN", "TORAS", "TORCS", "TORES", "TORIC", "TORII", "TOROS", 
    "TOROT", "TORRS", "TORSE", "TORSI", "TORTA", "TORTE", "TORTS", "TOSAS", "TOSES", 
    "TOTER", "TOTES", "TRANS", "TRANT", "TRAPE", "TRAPS", "TRAPT", "TRASS", "TRATS", 
    "TRATT", "TREEN", "TREES", "TRESS", "TREST", "TRETS", "TRIAC", "TRIER", "TRIES", 
    "TRILL", "TRINE", "TRINS", "TRIOL", "TRIOR", "TRIOS", "TRIPS", "TRIST", "TROAT", 
    "TROIS", "TRONA", "TRONC", "TRONE", "TRONS", "TROTH", "TROTS", "TSARS", 
};

static const uint16_t _num_words = (sizeof(_valid_words) / sizeof(_valid_words[0]));
static const uint16_t _num_possible_words = (sizeof(_possible_words) / sizeof(_possible_words[0]));
static const uint8_t _num_valid_letters = (sizeof(_valid_letters) / sizeof(_valid_letters[0]));

static uint32_t get_random(uint32_t max) {
    #if __EMSCRIPTEN__
    return rand() % max;
    #else
    return arc4random_uniform(max);
    #endif
}

static uint8_t get_first_pos(WordleLetterResult *word_elements_result) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (word_elements_result[i] != WORDLE_LETTER_CORRECT)
            return i;
    }
    return 0;
}

static uint8_t get_next_pos(uint8_t curr_pos, WordleLetterResult *word_elements_result) {
    for (size_t pos = curr_pos; pos < WORDLE_LENGTH;) {
        if (word_elements_result[++pos] != WORDLE_LETTER_CORRECT)
            return pos;
    }
    return WORDLE_LENGTH;
}

static uint8_t get_prev_pos(uint8_t curr_pos, WordleLetterResult *word_elements_result) {
    if (curr_pos == 0) return 0;
    for (int8_t pos = curr_pos; pos >= 0;) {
        if (word_elements_result[--pos] != WORDLE_LETTER_CORRECT)
            return pos;
    }
    return curr_pos;
}

static void get_next_letter(uint8_t curr_pos, uint8_t *word_elements) {
    if (word_elements[curr_pos] >= _num_valid_letters) word_elements[curr_pos] = 0;
    else word_elements[curr_pos] = (word_elements[curr_pos] + 1) % _num_valid_letters;
}

static void get_prev_letter(uint8_t curr_pos, uint8_t *word_elements) {
    if (word_elements[curr_pos] >= _num_valid_letters) word_elements[curr_pos] = _num_valid_letters - 1;
    else word_elements[curr_pos] = (word_elements[curr_pos] + _num_valid_letters - 1) % _num_valid_letters;
}

static void display_letter(wordle_state_t *state, bool display_dash) {
    char buf[1 + 1];
    if (state->word_elements[state->position] >= _num_valid_letters) {
        if (display_dash)
            watch_display_string("-", state->position + 5);
        else
            watch_display_string(" ", state->position + 5);
        return;
    }
    sprintf(buf, "%c", _valid_letters[state->word_elements[state->position]]);
    watch_display_string(buf, state->position + 5);
}

static void display_all_letters(wordle_state_t *state) {
    uint8_t prev_pos = state->position;
    watch_display_string(" ", 4);
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        state->position = i;
        display_letter(state, false);
    }
    state->position = prev_pos;
}

static uint32_t check_word_in_dict(uint8_t *word_elements) {
    bool is_exact_match;
    for (uint16_t i = 0; i < _num_words; i++) {
        is_exact_match = true;
        for (size_t j = 0; j < WORDLE_LENGTH; j++) {
            if (_valid_letters[word_elements[j]] != _valid_words[i][j]) {
                is_exact_match = false;
                break;  
            }
        }
        if (is_exact_match) return i;
    }
    for (uint16_t i = 0; i < _num_possible_words; i++) {
        is_exact_match = true;
        for (size_t j = 0; j < WORDLE_LENGTH; j++) {
            if (_valid_letters[word_elements[j]] != _possible_words[i][j]) {
                is_exact_match = false;
                break;  
            }
        }
        if (is_exact_match) return _num_words + i;
    }
    return _num_words + _num_possible_words;
}

static bool check_word(wordle_state_t *state) {
    // Exact
    bool is_exact_match = true;
    bool answer_already_accounted[WORDLE_LENGTH] = { false };
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (_valid_letters[state->word_elements[i]] == _valid_words[state->curr_answer][i]) {
            state->word_elements_result[i] = WORDLE_LETTER_CORRECT;
            answer_already_accounted[i] = true;
        }
        else {
            state->word_elements_result[i] = WORDLE_LETTER_WRONG;
            is_exact_match = false;
        }
    }
    if (is_exact_match) return true;
    // Wrong Location
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (state->word_elements_result[i] != WORDLE_LETTER_WRONG) continue;
        for (size_t j = 0; j < WORDLE_LENGTH; j++) {
            if (answer_already_accounted[j]) continue;
            if (_valid_letters[state->word_elements[i]] == _valid_words[state->curr_answer][j]) {
                state->word_elements_result[i] = WORDLE_LETTER_WRONG_LOC;
                answer_already_accounted[j] = true;
                break;
            }
        }
    }
    return false;
}

static void display_attempt(uint8_t attempt) {
    char buf[3];
    sprintf(buf, "%d", attempt+1);
    watch_display_string(buf, 3);
}

static void display_playing(wordle_state_t *state) {
    display_attempt(state->attempt);
    display_all_letters(state);
    state->curr_screen = SCREEN_PLAYING;
}

static void reset_all_elements(wordle_state_t *state) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        state->word_elements[i] = _num_valid_letters;
        state->word_elements_result[i] = WORDLE_LETTER_WRONG;
    }
    for (size_t i = 0; i < WORDLE_MAX_ATTEMPTS; i++) {
        state->guessed_words[i] = _num_words + _num_possible_words;
    }
    state->using_random_guess = false;
    state->attempt = 0;
}

static void reset_incorrect_elements(wordle_state_t *state) {
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (state->word_elements_result[i] != WORDLE_LETTER_CORRECT)
            state->word_elements[i] = _num_valid_letters;
    }
}

static void reset_board(wordle_state_t *state) {
    reset_all_elements(state);
    state->curr_answer = get_random(_num_words);
    watch_clear_colon();
    state->position = get_first_pos(state->word_elements_result);
    display_playing(state);
    watch_display_string(" -", 4);
#if __EMSCRIPTEN__
    printf("ANSWER: %s\r\n", _valid_words[state->curr_answer]);
#endif
}

static void display_title(wordle_state_t *state) {
    state->curr_screen = SCREEN_TITLE;
    watch_display_string("WO  WordLE", 0);
}

#if !USE_DAILY_STREAK
static void display_continue_result(bool continuing) {
    watch_display_string(continuing ? "y" : "n", 9);
}

static void display_continue(wordle_state_t *state) {
    state->curr_screen = SCREEN_CONTINUE;
    watch_display_string("Cont ", 4);
    display_continue_result(state->continuing);
}
#endif

static void display_streak(wordle_state_t *state) {
    char buf[12];
    state->curr_screen = SCREEN_STREAK;
#if USE_DAILY_STREAK
    if (state->streak > 99)
        sprintf(buf, "WO  St--dy");
    else
        sprintf(buf, "WO  St%2ddy", state->streak);
#else
    sprintf(buf, "WO  St%4d", state->streak);
#endif
    watch_display_string(buf, 0);
    watch_set_colon();
}

#if USE_DAILY_STREAK
static void display_wait(wordle_state_t *state) {
    state->curr_screen = SCREEN_WAIT;
    if (state->streak < 40) {
        char buf[13];
        sprintf(buf,"WO%2d WaIt ", state->streak);
        watch_display_string(buf, 0);
    }
    else {  // Streak too long to display in top-right
        watch_display_string("WO   WaIt ", 0);
    }
}

static uint32_t get_day_unix_time(void) {
    watch_date_time now = watch_rtc_get_date_time();
    now.unit.hour = now.unit.minute = now.unit.second = 0;
    return watch_utility_date_time_to_unix_time(now, 0);
}
#endif

static void display_not_in_dict(wordle_state_t *state) {
    state->curr_screen = SCREEN_NO_DICT;
    watch_display_string("nodict", 4);
}

static void display_already_guessed(wordle_state_t *state) {
    state->curr_screen = SCREEN_ALREADY_GUESSED;
    watch_display_string("GUESSD", 4);
}

static void display_lose(wordle_state_t *state, uint8_t subsecond) {
    char buf[WORDLE_LENGTH + 6];
    sprintf(buf," L   %s", subsecond % 2 ? _valid_words[state->curr_answer] : "     ");
    watch_display_string(buf, 0);
}

static void display_win(wordle_state_t *state, uint8_t subsecond) {
    (void) state;
    char buf[13];
    sprintf(buf," W   %s  ", subsecond % 2 ? "NICE" : "JOb ");
    watch_display_string(buf, 0);
}

static bool is_playing(const wordle_state_t *state) {
    if (state->attempt > 0) return true;
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        if (state->word_elements[i] != _num_valid_letters)
            return true;
    }
    return false;
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

static bool act_on_btn(wordle_state_t *state, const uint8_t pin) {
    switch (state->curr_screen)
    {
    case SCREEN_RESULT:
        reset_incorrect_elements(state);
        state->position = get_first_pos(state->word_elements_result);
        display_playing(state);
        return true;
    case SCREEN_TITLE:
#if USE_DAILY_STREAK
        if (state->prev_day == get_day_unix_time()) {
            display_wait(state);
        }
        else if (is_playing(state))
            display_playing(state);
        else
            display_streak(state);
#else
        if (is_playing(state)) {
            state->continuing = true;
            display_continue(state);
        }
        else
            display_streak(state);
#endif
        return true;
    case SCREEN_STREAK:
#if USE_DAILY_STREAK
        state->curr_day = get_day_unix_time();
#endif
        reset_board(state);
        return true;
    case SCREEN_WIN:
    case SCREEN_LOSE:
        display_title(state);
        return true;
    case SCREEN_NO_DICT:
    case SCREEN_ALREADY_GUESSED:
        state->position = get_first_pos(state->word_elements_result);
        display_playing(state);
        return true;
#if USE_DAILY_STREAK
    case SCREEN_WAIT:
        (void) pin;
        display_title(state);
        return true;
#else
    case SCREEN_CONTINUE:
        switch (pin)
        {
        case BTN_ALARM:
            if (state->continuing)
                display_playing(state);
            else {
                reset_board(state);
                display_streak(state);
            }
            break;
        case BTN_LIGHT:
            state->continuing = !state->continuing;
            display_continue_result(state->continuing);
            break;
        }
        return true;
#endif
    default:
        return false;
    }
    return false;
}

static void get_result(wordle_state_t *state) {
    // Check if it's in the dict
    uint16_t in_dict = check_word_in_dict(state->word_elements);
    if (in_dict == _num_words + _num_possible_words) {
        display_not_in_dict(state);
        return;
    }

    // Check if already guessed
    for (size_t i = 0; i < WORDLE_MAX_ATTEMPTS; i++) {
        if(in_dict == state->guessed_words[i]) {
            display_already_guessed(state);
            return;
        }
    }

    state->guessed_words[state->attempt] = in_dict;
    bool exact_match = check_word(state);
    if (exact_match) {
        reset_all_elements(state);
        state->curr_screen = SCREEN_WIN;
        if (state->streak < 0x7F)
            state->streak++;
#if USE_DAILY_STREAK
        state->prev_day = get_day_unix_time();
#endif
        return;
    }
    if (++state->attempt >= WORDLE_MAX_ATTEMPTS) {
        reset_all_elements(state);
        state->curr_screen = SCREEN_LOSE;
        state->streak = 0;
        return;
    }
    state->curr_screen = SCREEN_RESULT;
    return;
}

#if (USE_RANDOM_GUESS != 0)
static const uint16_t _num_unique_words = 257;  // The _valid_words array begins with this many words where each letter is different.
static void insert_random_guess(wordle_state_t *state) {
    uint16_t random_guess;
    do {  // Don't allow the guess to be the same as the answer
        random_guess = get_random(USE_RANDOM_GUESS == 2 ? _num_unique_words : _num_words);
    } while (random_guess == state->curr_answer); 
    for (size_t i = 0; i < WORDLE_LENGTH; i++) {
        for (size_t j = 0; j < _num_valid_letters; j++)
        {
            if (_valid_words[random_guess][i] == _valid_letters[j])
                state->word_elements[i] = j;     
        }
    } 
    state->position = WORDLE_LENGTH - 1;
    display_all_letters(state);
    state->using_random_guess = true;
}
#endif

void wordle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(wordle_state_t));
        memset(*context_ptr, 0, sizeof(wordle_state_t));
        wordle_state_t *state = (wordle_state_t *)*context_ptr;
        state->curr_screen = SCREEN_TITLE;
        reset_all_elements(state);
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void wordle_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    wordle_state_t *state = (wordle_state_t *)context;
#if USE_DAILY_STREAK
    uint32_t now = get_day_unix_time() ;
    if (state->prev_day <= (now + (60 *60 * 24))) state->streak = 0;
    if (state->curr_day != now) reset_all_elements(state);
#endif
    state->using_random_guess = false;
    if (is_playing(state) && state->curr_screen >= SCREEN_RESULT) {
        reset_incorrect_elements(state);
        state->position = get_first_pos(state->word_elements_result); 
    }
    movement_request_tick_frequency(2);
    display_title(state);
}

bool wordle_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    wordle_state_t *state = (wordle_state_t *)context;

    switch (event.event_type) {
        case EVENT_TICK:
            switch (state->curr_screen)
            {
            case SCREEN_PLAYING:
                if (event.subsecond % 2) {
                    display_letter(state, true);
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
            if (act_on_btn(state, BTN_LIGHT)) break;
            get_next_letter(state->position, state->word_elements);
            display_letter(state, true);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->curr_screen != SCREEN_PLAYING) break;
            get_prev_letter(state->position, state->word_elements);
            display_letter(state, true);
            break; 
        case EVENT_ALARM_BUTTON_UP:
            if (act_on_btn(state, BTN_ALARM)) break;
            display_letter(state, true);
            if (state->word_elements[state->position] == _num_valid_letters) break;
#if (USE_RANDOM_GUESS != 0)
            if (watch_get_pin_level(BTN_LIGHT) &&
            (state->using_random_guess || (state->attempt == 0 && state->position == 0))) {
                insert_random_guess(state);
                break;
            }
#endif
            state->position = get_next_pos(state->position, state->word_elements_result);
            if (state->position >= WORDLE_LENGTH) {
                get_result(state);
                state->using_random_guess = false;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->curr_screen != SCREEN_PLAYING) break;
            display_letter(state, true);
            state->position = get_prev_pos(state->position, state->word_elements_result);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
        case EVENT_ACTIVATE:
            break;
        case EVENT_TIMEOUT:
            if (state->curr_screen >= SCREEN_RESULT) {
                reset_incorrect_elements(state);
                state->position = get_first_pos(state->word_elements_result); 
                display_title(state);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (state->curr_screen != SCREEN_TITLE)
                display_title(state);
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

