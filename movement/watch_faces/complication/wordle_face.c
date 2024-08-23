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


static const char _valid_letters[] = {'A', 'C', 'E', 'G', 'H', 'I', 'L', 'N', 'O', 'P', 'R', 'S'};

// From: https://matthewminer.name/projects/calculators/wordle-words-left/
// Number of words found: 298
static const char _valid_words[][WORDLE_LENGTH + 1] = {
    "PLACE", "SHONE", "POSER", "CHAIN", "CAPER", "POLAR", "LEARN", "SHORN", "PORCH", 
    "GRAPE", "GNASH", "CHAIR", "SCORE", "CIGAR", "GRASP", "SINCE", "SPIRE", "NEIGH", 
    "SHORE", "CHASE", "RAISE", "CAIRN", "PLIER", "LOSER", "GRACE", "LEASH", "PENAL", 
    "SLING", "RISEN", "LOGIC", "PRICE", "POISE", "SCALE", "SINGE", "SNARL", "LINER", 
    "ANGEL", "SNAIL", "PALER", "SCION", "ALONE", "AGILE", "APRON", "PERIL", "GRIPE", 
    "SPICE", "LOGIN", "REGAL", "CAROL", "SLICE", "CRONE", "LEACH", "COPSE", "SHEAR", 
    "ALIGN", "LARGE", "LAPSE", "AISLE", "NICER", "OCEAN", "OPERA", "ALIEN", "ACORN", 
    "ASHEN", "SHINE", "PANEL", "SPORE", "SCOPE", "SPACE", "PHASE", "AROSE", "CHOIR", 
    "SNIPE", "CHAOS", "RALPH", "EPOCH", "GRAIN", "SANER", "GROIN", "SLANG", "SLAIN", 
    "CRASH", "CLASP", "SHIRE", "SCONE", "ALONG", "APING", "NICHE", "CHEAP", "CHIRP", 
    "LAGER", "CHORE", "SNORE", "SHAPE", "RESIN", "PERCH", "PECAN", "GLARE", "GROAN", 
    "RHINO", "RENAL", "SALON", "GRAIL", "SEPIA", "LANCE", "PRONG", "RECAP", "CLONE", 
    "CLASH", "HORSE", "SOLAR", "HERON", "PEACH", "ARSON", "HINGE", "CLEAN", "CLING", 
    "PHONE", "CRANE", "CLANG", "SCORN", "SPEAR", "PLAIN", "PROSE", "SPOIL", "GONER", 
    "SHOAL", "REIGN", "CLEAR", "ANGER", "CHINA", "GRAPH", "PEARL", "CARGO", "CHOSE", 
    "SCALP", "CANOE", "RINSE", "RANGE", "LINGO", "RANCH", "PLANE", "SPINE", "REACH", 
    "CRISP", "PARSE", "RIPEN", "SNARE", "CLOSE", "SHARE", "CORAL", "NOISE", "SHARP", 
    "SPARE", "SONIC", "SCRAP", "SPIEL", "RELIC", "OPINE", "SCARE", "SPRIG", "SHALE", 
    "PANIC", "SONAR", "GROPE", "SLOPE", "ANGLE", "ORGAN", "PIANO", "PINCH", "GLEAN", 
    "PRONE", "ARISE", "ROACH", "SIREN", "CLASS", "POSSE", "INANE", "HENCE", "SNEER", 
    "PAGAN", "PREEN", "ROGER", "SPELL", "SHEEP", "SENSE", "INNER", "ALPHA", "SHEEN", 
    "SCREE", "CIRCA", "PRIOR", "RARER", "PEACE", "GENRE", "HELLO", "CACAO", "GORGE", 
    "GLOSS", "CRIER", "CROSS", "CREPE", "COLON", "CHILL", "ONION", "LINEN", "PIPER", 
    "SLOOP", "LEGAL", "SNOOP", "PAPER", "ALGAE", "LAPEL", "CHEER", "HIPPO", "PIECE", 
    "LILAC", "HONOR", "PAPAL", "ARENA", "APNEA", "RIPER", "SCENE", "SHALL", "NASAL", 
    "SPREE", "RIGOR", "EAGER", "LIEGE", "LEPER", "LEASE", "CORER", "SPOON", "GROSS", 
    "COACH", "CEASE", "GENIE", "HARSH", "PENCE", "CHILI", "SHELL", "CREEP", "RISER", 
    "ERASE", "CINCH", "SIEGE", "GOING", "SCOOP", "SPILL", "NOOSE", "EAGLE", "AGING", 
    "NIECE", "SPOOL", "APPLE", "SALSA", "LEECH", "GREEN", "IONIC", "LASSO", "CONCH", 
    "PENNE", "SLASH", "CANAL", "CRASS", "REPEL", "COCOA", "CRESS", "AGAPE", "EASEL", 
    "CELLO", "CONIC", "IGLOO", "RACER", "GOOSE", "ICING", "POOCH", "ILIAC", "GRASS", 
    "SHEER", "CANON", "ELOPE", "LOCAL", "EERIE", "COLOR", "AGREE", "PRESS", "GEESE", 
    "SLOSH", "SLEEP", "GRILL", "AGAIN", "GLASS", "PARER", "CHESS", "CACHE", "ERROR", 
    "LOOSE", 
};

// These are words that'll never be used, but still need to be in the dictionary for guesses.
static const char _possible_words[][WORDLE_LENGTH + 1] = {
    "AALII", "AARGH", "ACAIS", "ACARI", "ACCAS", "ACERS", "ACHAR", "ACHES", "ACHOO", 
    "ACING", "ACINI", "ACNES", "ACRES", "ACROS", "AECIA", "AEGIS", "AEONS", "AERIE", 
    "AEROS", "AESIR", "AGARS", "AGENE", "AGERS", "AGGER", "AGGIE", "AGGRI", "AGGRO", 
    "AGHAS", "AGILA", "AGIOS", "AGLEE", "AGLOO", "AGOGE", "AGONE", "AGONS", "AGORA", 
    "AGRIA", "AGRIN", "AGROS", "AHEAP", "AHIGH", "AHING", "AIGAS", "AINEE", "AINGA", 
    "AIOLI", "AIRER", "AIRNS", "ALAAP", "ALANE", "ALANG", "ALANS", "ALAPA", "ALAPS", 
    "ALCOS", "ALECS", "ALEPH", "ALGAL", "ALGAS", "ALGIN", "ALGOR", "ALIAS", "ALINE", 
    "ALLEE", "ALLEL", "ALLIS", "ALOES", "ALOHA", "ALOIN", "ALOOS", "ANANA", "ANCHO", 
    "ANCLE", "ANCON", "ANEAR", "ANELE", "ANGAS", "ANGLO", "ANIGH", "ANILE", "ANILS", 
    "ANION", "ANISE", "ANLAS", "ANNAL", "ANNAS", "ANOAS", "ANOLE", "ANSAE", "APACE", 
    "APAGE", "APERS", "APGAR", "APHIS", "APIAN", "APIOL", "APISH", "APOOP", "APPAL", 
    "APPEL", "APPRO", "APRES", "APSES", "APSIS", "APSOS", "ARARS", "ARCHI", "ARCOS", 
    "AREAE", "AREAL", "AREAR", "AREAS", "ARECA", "AREIC", "ARENE", "AREPA", "ARERE", 
    "ARGAL", "ARGAN", "ARGIL", "ARGLE", "ARGOL", "ARGON", "ARIAS", "ARIEL", "ARILS", 
    "ARISH", "ARLES", "ARNAS", "AROHA", "ARPAS", "ARPEN", "ARRAH", "ARRAS", "ARRIS", 
    "ARSES", "ARSIS", "ASANA", "ASCON", "ASHES", "ASPEN", "ASPER", "ASPIC", "ASPIE", 
    "ASPIS", "ASPRO", "ASSAI", "ASSES", "CACAS", "CAECA", "CAESE", "CAGER", "CAGES", 
    "CAINS", "CALLA", "CALLS", "CALOS", "CALPA", "CALPS", "CANEH", "CANER", "CANES", 
    "CANGS", "CANNA", "CANNS", "CANSO", "CAPAS", "CAPES", "CAPHS", "CAPLE", "CAPON", 
    "CAPOS", "CAPRI", "CARAP", "CARER", "CARES", "CARLE", "CARLS", "CARNS", "CARON", 
    "CARPI", "CARPS", "CARRS", "CARSE", "CASAS", "CASCO", "CASES", "CECAL", "CEILI", 
    "CEILS", "CELLA", "CELLI", "CELLS", "CENSE", "CEORL", "CEPES", "CERCI", "CERES", 
    "CERGE", "CERIA", "CERIC", "CERNE", "CEROC", "CEROS", "CESSE", "CHACE", "CHACO", 
    "CHAIS", "CHALS", "CHANA", "CHANG", "CHAPE", "CHAPS", "CHARA", "CHARE", "CHARR", 
    "CHARS", "CHEEP", "CHELA", "CHELP", "CHERE", "CHIAO", "CHIAS", "CHICA", "CHICH", 
    "CHICO", "CHICS", "CHIEL", "CHILE", "CHINE", "CHING", "CHINO", "CHINS", "CHIPS", 
    "CHIRL", "CHIRO", "CHIRR", "CHOCO", "CHOCS", "CHOGS", "CHOIL", "CHOLA", "CHOLI", 
    "CHOLO", "CHONS", "CHOON", "CHOPS", "CIELS", "CILIA", "CILLS", "CINES", "CIONS", 
    "CIPPI", "CIRCS", "CIRES", "CIRLS", "CIRRI", "CISCO", "CLACH", "CLAES", "CLAGS", 
    "CLANS", "CLAPS", "CLARO", "CLEEP", "CLEGS", "CLEPE", "CLIES", "CLINE", "CLIPE", 
    "CLIPS", "CLOGS", "CLONS", "CLOOP", "CLOPS", "COALA", "COALS", "COCAS", "COCCI", 
    "COCCO", "COCOS", "COGIE", "COGON", "COHEN", "COHOE", "COHOG", "COHOS", "COIGN", 
    "COILS", "COINS", "COIRS", "COLAS", "COLES", "COLIC", "COLIN", "COLLS", "COLOG", 
    "CONES", "CONGA", "CONGE", "CONGO", "CONIA", "CONIN", "CONNE", "CONNS", "COOCH", 
    "COOEE", "COOER", "COOLS", "COONS", "COOPS", "COPAL", "COPEN", "COPER", "COPES", 
    "COPRA", "CORES", "CORGI", "CORIA", "CORNI", "CORNO", "CORNS", "CORPS", "CORSE", 
    "CORSO", "COSEC", "COSES", "COSIE", "CRAAL", "CRAGS", "CRAIC", "CRAIG", "CRANS", 
    "CRAPE", "CRAPS", "CRARE", "CREEL", "CREES", "CRENA", "CREPS", "CRIAS", "CRIES", 
    "CRINE", "CRIOS", "CRIPE", "CRIPS", "CRISE", "CROCI", "CROCS", "CROGS", "CRONS", 
    "CROOL", "CROON", "CROPS", "CRORE", "EAGRE", "EALES", "EARLS", "EARNS", "EASER", 
    "EASES", "EASLE", "ECHES", "ECHOS", "EGERS", "EGGAR", "EGGER", "EHING", "EIGNE", 
    "EISEL", "ELAIN", "ELANS", "ELCHI", "ELOGE", "ELOIN", "ELOPS", "ELPEE", "ELSIN", 
    "ENIAC", "ENNOG", "ENOLS", "ENROL", "EORLS", "EOSIN", "EPEES", "EPHAH", "EPHAS", 
    "EPHOR", "EPICS", "EPRIS", "ERGON", "ERGOS", "ERICA", "ERICS", "ERING", "ERNES", 
    "EROSE", "ERSES", "ESCAR", "ESILE", "ESNES", "ESSES", "GAGER", "GAGES", "GAINS", 
    "GAIRS", "GALAH", "GALAS", "GALEA", "GALES", "GALLS", "GALOP", "GANCH", "GANGS", 
    "GAOLS", "GAPER", "GAPES", "GAPOS", "GARES", "GARIS", "GARNI", "GARRE", "GASES", 
    "GASPS", "GEALS", "GEANS", "GEARE", "GEARS", "GEEPS", "GELEE", "GENAL", "GENAS", 
    "GENES", "GENIC", "GENII", "GENIP", "GENOA", "GENRO", "GERAH", "GERES", "GERLE", 
    "GERNE", "GESSE", "GESSO", "GHEES", "GIGAS", "GIGHE", "GILAS", "GILLS", "GINCH", 
    "GINGE", "GINGS", "GIPON", "GIPPO", "GIRLS", "GIRNS", "GIRON", "GIROS", "GIRRS", 
    "GIRSH", "GLACE", "GLAIR", "GLANS", "GLEES", "GLEIS", "GLENS", "GLIAL", "GLIAS", 
    "GLOGG", "GLOOP", "GLOPS", "GNARL", "GNARR", "GNARS", "GOALS", "GOELS", "GOERS", 
    "GOGGA", "GOGOS", "GOIER", "GOLES", "GOLPE", "GOLPS", "GONCH", "GONGS", "GONIA", 
    "GONNA", "GOOGS", "GOOLS", "GOONS", "GOOPS", "GOORS", "GORAL", "GORAS", "GORES", 
    "GORIS", "GORPS", "GORSE", "GOSSE", "GRAAL", "GRAIP", "GRANA", "GRANS", "GRECE", 
    "GREES", "GREGE", "GREGO", "GREIN", "GRENS", "GRESE", "GRICE", "GRIGS", "GRINS", 
    "GRIPS", "GRISE", "GROGS", "GRONE", "GRRLS", "GRRRL", "HAARS", "HAGGS", "HAHAS", 
    "HAILS", "HAINS", "HAIRS", "HALAL", "HALER", "HALES", "HALLO", "HALLS", "HALON", 
    "HALOS", "HALSE", "HANAP", "HANCE", "HANCH", "HANGI", "HANGS", "HANSA", "HANSE", 
    "HAOLE", "HAPPI", "HARES", "HARLS", "HARNS", "HAROS", "HARPS", "HASPS", "HEALS", 
    "HEAPS", "HEARE", "HEARS", "HEELS", "HEIGH", "HEILS", "HEIRS", "HELES", "HELIO", 
    "HELLS", "HELOS", "HELPS", "HENCH", "HENGE", "HENNA", "HEPAR", "HERES", "HERLS", 
    "HERNS", "HEROS", "HERSE", "HESPS", "HIGHS", "HILAR", "HILCH", "HILLO", "HILLS", 
    "HINGS", "HIOIS", "HIREE", "HIRER", "HIRES", "HOARS", "HOERS", "HOGAN", "HOGEN", 
    "HOGGS", "HOGHS", "HOING", "HOISE", "HOLES", "HOLLA", "HOLLO", "HOLON", "HOLOS", 
    "HONAN", "HONER", "HONES", "HONGI", "HONGS", "HOOCH", "HOONS", "HOOPS", "HOORS", 
    "HOOSH", "HOPER", "HOPES", "HORAH", "HORAL", "HORAS", "HORIS", "HORNS", "HOSEL", 
    "HOSEN", "HOSER", "HOSES", "ICERS", "ICHES", "ICHOR", "ICIER", "ICONS", "IGAPO", 
    "ILEAC", "ILEAL", "ILIAL", "ILLER", "INCEL", "INCLE", "INCOG", "INGAN", "INGLE", 
    "INION", "INSPO", "IPPON", "IRING", "IRONE", "IRONS", "ISHES", "ISLES", "ISNAE", 
    "ISSEI", "LAARI", "LACER", "LACES", "LAERS", "LAGAN", "LAHAL", "LAHAR", "LAICH", 
    "LAICS", "LAIGH", "LAIRS", "LALLS", "LANAI", "LANAS", "LANCH", "LANES", "LAPIN", 
    "LAPIS", "LARCH", "LAREE", "LARES", "LARGO", "LARIS", "LARNS", "LASER", "LASES", 
    "LASSI", "LEANS", "LEAPS", "LEARE", "LEARS", "LEEAR", "LEEPS", "LEERS", "LEESE", 
    "LEGER", "LEGES", "LEGGE", "LEGGO", "LEHRS", "LEIRS", "LEISH", "LENES", "LENGS", 
    "LENIS", "LENOS", "LENSE", "LEONE", "LEPRA", "LERES", "LERPS", "LESES", "LIANA", 
    "LIANE", "LIANG", "LIARS", "LICHI", "LIENS", "LIERS", "LIGAN", "LIGER", "LIGGE", 
    "LIGNE", "LILLS", "LILOS", "LINAC", "LINCH", "LINES", "LINGA", "LINGS", "LININ", 
    "LINNS", "LINOS", "LIONS", "LIPAS", "LIPES", "LIPIN", "LIPOS", "LIRAS", "LISLE", 
    "LISPS", "LLANO", "LOACH", "LOANS", "LOCHE", "LOCHS", "LOCIE", "LOCIS", "LOCOS", 
    "LOESS", "LOGAN", "LOGES", "LOGIA", "LOGIE", "LOGOI", "LOGON", "LOGOS", "LOHAN", 
    "LOINS", "LOIPE", "LOIRS", "LOLLS", "LOLOG", "LONER", "LONGA", "LONGE", "LONGS", 
    "LOOIE", "LOONS", "LOOPS", "LOPER", "LOPES", "LORAL", "LORAN", "LOREL", "LORES", 
    "LORIC", "LORIS", "LOSEL", "LOSEN", "LOSES", "NAANS", "NACHE", "NACHO", "NACRE", 
    "NAGAS", "NAGOR", "NAHAL", "NAILS", "NAIRA", "NALAS", "NALLA", "NANAS", "NANCE", 
    "NANNA", "NANOS", "NAPAS", "NAPES", "NAPOO", "NAPPA", "NAPPE", "NARAS", "NARCO", 
    "NARCS", "NARES", "NARIC", "NARIS", "NARRE", "NASHI", "NEALS", "NEAPS", "NEARS", 
    "NEELE", "NEEPS", "NEESE", "NEGRO", "NELIS", "NENES", "NEONS", "NEPER", "NERAL", 
    "NEROL", "NGAIO", "NGANA", "NICOL", "NIGER", "NIGHS", "NIHIL", "NILLS", "NINER", 
    "NINES", "NINON", "NIPAS", "NIRLS", "NISEI", "NISSE", "NOAHS", "NOELS", "NOGGS", 
    "NOILS", "NOIRS", "NOLES", "NOLLS", "NOLOS", "NONAS", "NONCE", "NONES", "NONGS", 
    "NONIS", "NOONS", "NOOPS", "NOPAL", "NORIA", "NORIS", "NOSER", "NOSES", "OASES", 
    "OASIS", "OCHER", "OCHES", "OCHRE", "OCREA", "OGEES", "OGGIN", "OGLER", "OGLES", 
    "OGRES", "OHIAS", "OHING", "OHONE", "OILER", "OLEIC", "OLEIN", "OLEOS", "OLIOS", 
    "OLLAS", "OLLER", "OLLIE", "OLPAE", "OLPES", "ONCER", "ONCES", "ONERS", "OORIE", 
    "OOSES", "OPAHS", "OPALS", "OPENS", "OPEPE", "OPING", "OPPOS", "OPSIN", "ORACH", 
    "ORALS", "ORANG", "ORCAS", "ORCIN", "ORGIA", "ORGIC", "ORIEL", "ORLES", "ORLON", 
    "ORLOP", "ORNIS", "ORPIN", "ORRIS", "OSCAR", "OSHAC", "OSIER", "OSSIA", "PAALS", 
    "PAANS", "PACAS", "PACER", "PACES", "PACHA", "PACOS", "PAEAN", "PAEON", "PAGER", 
    "PAGES", "PAGLE", "PAGRI", "PAILS", "PAINS", "PAIRE", "PAIRS", "PAISA", "PAISE", 
    "PALAS", "PALEA", "PALES", "PALIS", "PALLA", "PALLS", "PALPI", "PALPS", "PALSA", 
    "PANCE", "PANES", "PANGA", "PANGS", "PANNE", "PANNI", "PAOLI", "PAOLO", "PAPAS", 
    "PAPES", "PAPPI", "PARAE", "PARAS", "PARCH", "PAREN", "PAREO", "PARES", "PARGE", 
    "PARGO", "PARIS", "PARLE", "PAROL", "PARPS", "PARRA", "PARRS", "PASEO", "PASES", 
    "PASHA", "PASSE", "PEAGE", "PEAGS", "PEALS", "PEANS", "PEARE", "PEARS", "PEASE", 
    "PECHS", "PEECE", "PEELS", "PEENS", "PEEPE", "PEEPS", "PEERS", "PEGHS", "PEINS", 
    "PEISE", "PELAS", "PELES", "PELLS", "PELON", "PENES", "PENGO", "PENIE", "PENIS", 
    "PENNA", "PENNI", "PEONS", "PEPLA", "PEPOS", "PEPSI", "PERAI", "PERCE", "PERCS", 
    "PEREA", "PERES", "PERIS", "PERNS", "PEROG", "PERPS", "PERSE", "PESOS", "PHAGE", 
    "PHANG", "PHARE", "PHEER", "PHENE", "PHEON", "PHESE", "PHIAL", "PHISH", "PHOCA", 
    "PHONO", "PHONS", "PIANI", "PIANS", "PICAL", "PICAS", "PICRA", "PIERS", "PIING", 
    "PILAE", "PILAO", "PILAR", "PILCH", "PILEA", "PILEI", "PILER", "PILES", "PILIS", 
    "PILLS", "PINAS", "PINES", "PINGO", "PINGS", "PINNA", "PINON", "PIONS", "PIPAL", 
    "PIPAS", "PIPES", "PIPIS", "PIRAI", "PIRLS", "PIRNS", "PIROG", "PISCO", "PISES", 
    "PISOS", "PLAAS", "PLAGE", "PLANS", "PLAPS", "PLASH", "PLEAS", "PLENA", "PLEON", 
    "PLESH", "PLICA", "PLIES", "PLING", "PLONG", "PLOPS", "POACH", "POEPS", "POGGE", 
    "POGOS", "POLER", "POLES", "POLIO", "POLIS", "POLLS", "POLOS", "PONCE", "PONES", 
    "PONGA", "PONGO", "PONGS", "POOHS", "POOLS", "POONS", "POOPS", "POORI", "POPES", 
    "POPPA", "PORAE", "PORAL", "PORER", "PORES", "PORGE", "PORIN", "PORNO", "PORNS", 
    "POSES", "POSHO", "PRANA", "PRANG", "PRAOS", "PRASE", "PREES", "PREON", "PREOP", 
    "PREPS", "PRESA", "PRESE", "PRIAL", "PRIER", "PRIES", "PRIGS", "PRILL", "PRION", 
    "PRISE", "PRISS", "PROAS", "PROGS", "PROIN", "PROLE", "PROLL", "PROPS", "PRORE", 
    "PROSO", "PROSS", "PSION", "PSOAE", "PSOAI", "PSOAS", "PSORA", "RACES", "RACHE", 
    "RACON", "RAGAS", "RAGEE", "RAGER", "RAGES", "RAGGA", "RAGGS", "RAGIS", "RAIAS", 
    "RAILE", "RAILS", "RAINE", "RAINS", "RALES", "RANAS", "RANCE", "RANEE", "RANGA", 
    "RANGI", "RANGS", "RANIS", "RAPER", "RAPES", "RAPHE", "RAPPE", "RAREE", "RARES", 
    "RASER", "RASES", "RASPS", "RASSE", "REAIS", "REALO", "REALS", "REANS", "REAPS", 
    "REARS", "RECAL", "RECCE", "RECCO", "RECON", "REECH", "REELS", "REENS", "REGAR", 
    "REGES", "REGGO", "REGIE", "REGNA", "REGOS", "REINS", "RELIE", "RELLO", "RENGA", 
    "RENIG", "RENIN", "RENNE", "RENOS", "REOIL", "REORG", "REPEG", "REPIN", "REPLA", 
    "REPOS", "REPPS", "REPRO", "RERAN", "RERIG", "RESEE", "RESES", "RHEAS", "RHIES", 
    "RHINE", "RHONE", "RIALS", "RICER", "RICES", "RICIN", "RIELS", "RIGGS", "RIGOL", 
    "RILES", "RILLE", "RILLS", "RINES", "RINGS", "RIPES", "RIPPS", "RISES", "RISHI", 
    "RISPS", "ROANS", "ROARS", "ROHES", "ROILS", "ROINS", "ROLAG", "ROLES", "ROLLS", 
    "RONEO", "RONES", "RONIN", "RONNE", "ROONS", "ROOPS", "ROOSA", "ROOSE", "ROPER", 
    "ROPES", "RORAL", "RORES", "RORIC", "RORIE", "ROSES", "ROSHI", "ROSIN", "SAAGS", 
    "SACRA", "SAGAS", "SAGER", "SAGES", "SAGOS", "SAICE", "SAICS", "SAIGA", "SAILS", 
    "SAINE", "SAINS", "SAIRS", "SALAL", "SALEP", "SALES", "SALIC", "SALLE", "SALOL", 
    "SALOP", "SALPA", "SALPS", "SALSE", "SANES", "SANGA", "SANGH", "SANGO", "SANGS", 
    "SANSA", "SAOLA", "SAPAN", "SAPOR", "SARAN", "SAREE", "SARGE", "SARGO", "SARIN", 
    "SARIS", "SAROS", "SASER", "SASIN", "SASSE", "SCAGS", "SCAIL", "SCALA", "SCALL", 
    "SCANS", "SCAPA", "SCAPE", "SCAPI", "SCARP", "SCARS", "SCENA", "SCOGS", "SCOOG", 
    "SCOPA", "SCOPS", "SCRAE", "SCRAG", "SCRAN", "SCRIP", "SCROG", "SEALS", "SEANS", 
    "SEARE", "SEARS", "SEASE", "SECCO", "SECHS", "SEELS", "SEEPS", "SEERS", "SEGAR", 
    "SEGNI", "SEGNO", "SEGOL", "SEGOS", "SEHRI", "SEILS", "SEINE", "SEIRS", "SEISE", 
    "SELAH", "SELES", "SELLA", "SELLE", "SELLS", "SENAS", "SENES", "SENGI", "SENNA", 
    "SENOR", "SENSA", "SENSI", "SEPAL", "SEPIC", "SERAC", "SERAI", "SERAL", "SERER", 
    "SERES", "SERGE", "SERIC", "SERIN", "SERON", "SERRA", "SERRE", "SERRS", "SESSA", 
    "SHAGS", "SHAHS", "SHANS", "SHAPS", "SHARN", "SHASH", "SHCHI", "SHEAL", "SHEAS", 
    "SHEEL", "SHEOL", "SHERE", "SHERO", "SHIAI", "SHIEL", "SHIER", "SHIES", "SHILL", 
    "SHINS", "SHIPS", "SHIRR", "SHIRS", "SHISH", "SHISO", "SHLEP", "SHOER", "SHOES", 
    "SHOGI", "SHOGS", "SHOLA", "SHOOL", "SHOON", "SHOOS", "SHOPE", "SHOPS", "SHORL", 
    "SHRIS", "SIALS", "SICES", "SIENS", "SIGHS", "SIGIL", "SIGLA", "SIGNA", "SIGNS", 
    "SILEN", "SILER", "SILES", "SILLS", "SILOS", "SINES", "SINGS", "SINHS", "SIPES", 
    "SIREE", "SIRES", "SIRIH", "SIRIS", "SIROC", "SIRRA", "SISAL", "SISES", "SLAES", 
    "SLAGS", "SLANE", "SLAPS", "SLEER", "SLIER", "SLIPE", "SLIPS", "SLISH", "SLOAN", 
    "SLOES", "SLOGS", "SLOPS", "SNAGS", "SNAPS", "SNARS", "SNASH", "SNEAP", "SNEES", 
    "SNELL", "SNIES", "SNIGS", "SNIPS", "SNOEP", "SNOGS", "SNOOL", "SOAPS", "SOARE", 
    "SOARS", "SOCAS", "SOCES", "SOCLE", "SOGER", "SOILS", "SOLAH", "SOLAN", "SOLAS", 
    "SOLEI", "SOLER", "SOLES", "SOLON", "SOLOS", "SONCE", "SONES", "SONGS", "SONNE", 
    "SONSE", "SOOLE", "SOOLS", "SOOPS", "SOPHS", "SOPOR", "SOPRA", "SORAL", "SORAS", 
    "SOREE", "SOREL", "SORER", "SORES", "SORGO", "SORNS", "SORRA", "SPAER", "SPAES", 
    "SPAGS", "SPAHI", "SPAIL", "SPAIN", "SPALE", "SPALL", "SPANE", "SPANG", "SPANS", 
    "SPARS", "SPEAL", "SPEAN", "SPECS", "SPEEL", "SPEER", "SPEIL", "SPEIR", "SPEOS", 
    "SPIAL", "SPICA", "SPICS", "SPIER", "SPIES", "SPILE", "SPINA", "SPINS", "SPLOG", 
    "SPOOR", "SPOSH", "SPRAG", "SPROG", 
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
static const uint16_t _num_unique_words = 157;  // The _valid_words array begins with this many words where each letter is different.
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

