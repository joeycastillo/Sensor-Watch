import spotipy
from spotipy.oauth2 import SpotifyClientCredentials
from unidecode import unidecode
import json
from bs4 import BeautifulSoup
from datetime import datetime
import urllib.request
import difflib
import pytz

TZ = pytz.timezone('US/Central')  # Clashfinder is in Central time

MAKE_ARR_FILE = 1 # 0 = Don't make the file; 1= Make the file; 2 = Make the file and print it to the console
PRINT_RANKINGs = 1
USE_TEST_ARR = 0
PRINT_SEARCH_RESULTS = 1
SORT_POP_BY_FOLLOWERS = 0
GENRE_DEFAULT = "NO_GENRE"
STAGES = [ "T_MOBILE", "COINBASE", "BUD_LIGHT", "TITOS", "PERRYS", "BACARDI", "BMI"]
STAGE_DEFAULT = "NO_STAGE"
URL = "https://clashfinder.com/m/lolla2025/"

testPop = [
    {'name': '2Hollis', 'followers': 236642, 'popularity': 65}, {'name': 'A$AP Rocky', 'followers': 16210405, 'popularity': 86},
    {'name': 'Alemeda', 'followers': 50590, 'popularity': 40}, {'name': 'Alex Warren', 'followers': 995524, 'popularity': 83},
    {'name': 'ALEXSUCKS', 'followers': 26202, 'popularity': 44}, {'name': "Aliyah's Interlude", 'followers': 288187, 'popularity': 57},
    {'name': 'ALLEYCVT', 'followers': 61934, 'popularity': 52}, {'name': 'Amaarae', 'followers': 508201, 'popularity': 66},
    {'name': 'Artemas', 'followers': 1173774, 'popularity': 76}, {'name': 'Azzecca', 'followers': 24656, 'popularity': 43},
    {'name': "Barry Can't Swim", 'followers': 224248, 'popularity': 64}, {'name': 'benches', 'followers': 48473, 'popularity': 48},
    {'name': 'Bilmuri', 'followers': 199045, 'popularity': 61}, {'name': 'Black Party', 'followers': 250213, 'popularity': 44},
    {'name': 'Bladee', 'followers': 571806, 'popularity': 68}, {'name': 'Bleachers', 'followers': 842156, 'popularity': 69},
    {'name': 'The Blessed Madonna', 'followers': 115076, 'popularity': 66}, {'name': 'BLK Odyssy', 'followers': 106263, 'popularity': 54},
    {'name': 'Bo Staloch', 'followers': 19093, 'popularity': 48}, {'name': 'Bossman Dlow', 'followers': 625379, 'popularity': 72},
    {'name': 'Boynextdoor', 'followers': 1316289, 'popularity': 70}, {'name': 'BUNT.', 'followers': 224449, 'popularity': 69},
    {'name': 'Bôa', 'followers': 1054227, 'popularity': 71}, {'name': 'Ca7riel y Paco Amoroso', 'followers': 0, 'popularity': 0},
    {'name': 'Cage the Elephant', 'followers': 4080179, 'popularity': 75}, {'name': 'Carole Ades', 'followers': 0, 'popularity': 0},
    {'name': 'Caroline Kingsbury', 'followers': 20217, 'popularity': 46}, {'name': 'Carter Vail', 'followers': 109493, 'popularity': 48},
    {'name': 'Cassandra Coleman', 'followers': 0, 'popularity': 0}, {'name': 'Charlotte Lawrence', 'followers': 1180094, 'popularity': 57},
    {'name': 'Chase & Status', 'followers': 1126432, 'popularity': 71}, {'name': 'Chicago Made', 'followers': 0, 'popularity': 0},
    {'name': 'Chicago Youth Symphony Orchestra', 'followers': 132, 'popularity': 3}, {'name': 'Clairo', 'followers': 5886511, 'popularity': 81},
    {'name': 'Cloonee', 'followers': 191526, 'popularity': 63}, {'name': 'Colby Acuff', 'followers': 131456, 'popularity': 55},
    {'name': 'The Criticals', 'followers': 20252, 'popularity': 35}, {'name': 'Damiano David', 'followers': 421147, 'popularity': 71},
    {'name': 'Daniel Allan', 'followers': 21076, 'popularity': 49}, {'name': 'The Dare', 'followers': 144408, 'popularity': 56},
    {'name': 'Del Water Gap', 'followers': 245530, 'popularity': 63}, {'name': 'DJ Heather', 'followers': 1929, 'popularity': 6},
    {'name': 'DJO', 'followers': 0, 'popularity': 0}, {'name': 'Doechii', 'followers': 2520225, 'popularity': 88},
    {'name': 'Dogpark', 'followers': 31619, 'popularity': 43}, {'name': 'Dom Dolla', 'followers': 541154, 'popularity': 72},
    {'name': 'Dominic Fike', 'followers': 2062334, 'popularity': 79}, {'name': 'Dr. Fresch', 'followers': 134848, 'popularity': 52},
    {'name': 'The Droptines', 'followers': 16473, 'popularity': 49}, {'name': 'Dua Saleh', 'followers': 109124, 'popularity': 46},
    {'name': 'Durand Bernarr', 'followers': 122109, 'popularity': 54}, {'name': 'Eddie and the Getaway', 'followers': 86838, 'popularity': 54},
    {'name': 'Fcukers', 'followers': 30607, 'popularity': 47}, {'name': 'Finneas', 'followers': 2203078, 'popularity': 70},
    {'name': 'Flipturn', 'followers': 223775, 'popularity': 63}, {'name': 'Flowerovlove', 'followers': 108283, 'popularity': 54},
    {'name': 'Flux Pavilion', 'followers': 717298, 'popularity': 58}, {'name': 'Foster the People', 'followers': 3963438, 'popularity': 73},
    {'name': 'Fujii Kaze', 'followers': 4017200, 'popularity': 74}, {'name': 'Gigi Perez', 'followers': 1013366, 'popularity': 80},
    {'name': 'Girl Tones', 'followers': 3976, 'popularity': 28}, {'name': 'Glass Beams', 'followers': 444275, 'popularity': 54},
    {'name': 'Gracie Abrams', 'followers': 5003797, 'popularity': 89}, {'name': 'Graham Barham', 'followers': 86809, 'popularity': 63},
    {'name': 'Gryffin', 'followers': 983894, 'popularity': 69}, {'name': 'Half Alive', 'followers': 73, 'popularity': 0},
    {'name': 'Hex Cougar', 'followers': 33313, 'popularity': 41}, {'name': 'hey, nothing', 'followers': 147397, 'popularity': 54},
    {'name': 'Ian', 'followers': 0, 'popularity': 0}, {'name': 'Isabel LaRosa', 'followers': 2235427, 'popularity': 74},
    {'name': 'Isaiah Rashad', 'followers': 1549139, 'popularity': 70}, {'name': 'ISOxo', 'followers': 78305, 'popularity': 55},
    {'name': 'Jade LeMac', 'followers': 216106, 'popularity': 66}, {'name': 'Jane Remover', 'followers': 89988, 'popularity': 54},
    {'name': 'Jesse Detor', 'followers': 14512, 'popularity': 35}, {'name': 'Jev', 'followers': 0, 'popularity': 0},
    {'name': 'Jigitz', 'followers': 22061, 'popularity': 56}, {'name': 'Joe P', 'followers': 138718, 'popularity': 49},
    {'name': 'Joey Valence & Brae', 'followers': 594240, 'popularity': 65}, {'name': 'JPEGMafia', 'followers': 966369, 'popularity': 69},
    {'name': 'Julie', 'followers': 346363, 'popularity': 56}, {'name': 'Junior Varsity', 'followers': 36665, 'popularity': 49},
    {'name': 'Kaicrewsade', 'followers': 4032, 'popularity': 30}, {'name': 'KATSEYE', 'followers': 1280847, 'popularity': 68},
    {'name': 'Kenny Mason', 'followers': 207819, 'popularity': 59}, {'name': 'Kickflip', 'followers': 180136, 'popularity': 54},
    {'name': 'KNOCK2', 'followers': 137658, 'popularity': 63}, {'name': 'Korn', 'followers': 8789407, 'popularity': 77},
    {'name': 'La Femme', 'followers': 568895, 'popularity': 59}, {'name': 'Laila!', 'followers': 218927, 'popularity': 55},
    {'name': 'Landon Barker', 'followers': 39846, 'popularity': 42}, {'name': 'Landon Conrath,', 'followers': 0, 'popularity': 0},
    {'name': 'Latin Mafia', 'followers': 1418802, 'popularity': 75}, {'name': 'Layz', 'followers': 29928, 'popularity': 41},
    {'name': 'Lekan', 'followers': 14583, 'popularity': 37}, {'name': 'Levity', 'followers': 90345, 'popularity': 54},
    {'name': 'Luke Combs', 'followers': 12439664, 'popularity': 86}, {'name': 'Magdalena Bay', 'followers': 410014, 'popularity': 68},
    {'name': 'Mariah the Scientist', 'followers': 752998, 'popularity': 68}, {'name': 'The Marias', 'followers': 12, 'popularity': 0},
    {'name': 'Maribou State', 'followers': 443041, 'popularity': 69}, {'name': 'Mark Ambor', 'followers': 602452, 'popularity': 72},
    {'name': 'Marlon Hoffstadt', 'followers': 144803, 'popularity': 64}, {'name': 'Martin Garrix', 'followers': 15173248, 'popularity': 77},
    {'name': 'Mary Droppinz', 'followers': 12141, 'popularity': 32}, {'name': 'Matt Champion', 'followers': 174254, 'popularity': 50},
    {'name': 'Mau P', 'followers': 150564, 'popularity': 65}, {'name': 'Max McNown', 'followers': 443103, 'popularity': 72},
    {'name': 'Midnight Generation', 'followers': 82113, 'popularity': 52}, {'name': 'Mk.gee', 'followers': 351347, 'popularity': 64},
    {'name': 'Montell Fish', 'followers': 1924827, 'popularity': 75}, {'name': 'Murda Beatz', 'followers': 167094, 'popularity': 58},
    {'name': 'Naomi Scott', 'followers': 382345, 'popularity': 62}, {'name': 'New Dad', 'followers': 985, 'popularity': 0},
    {'name': 'Nimino', 'followers': 113867, 'popularity': 66}, {'name': 'Nourished By Time', 'followers': 29797, 'popularity': 44},
    {'name': 'Ocean Alley', 'followers': 620717, 'popularity': 64}, {'name': 'Old Mervs', 'followers': 37575, 'popularity': 53},
    {'name': 'Ole 60', 'followers': 271599, 'popularity': 64}, {'name': 'Olivia Rodrigo', 'followers': 44539271, 'popularity': 87},
    {'name': 'Orion Sun', 'followers': 393702, 'popularity': 63}, {'name': 'Orla Gartland', 'followers': 273116, 'popularity': 52},
    {'name': 'Otoboke Beaver', 'followers': 153292, 'popularity': 37}, {'name': 'Overmono', 'followers': 165736, 'popularity': 55},
    {'name': 'People R Ugly', 'followers': 41053, 'popularity': 45}, {'name': 'Prospa', 'followers': 55864, 'popularity': 53},
    {'name': 'Rachel Grae', 'followers': 212819, 'popularity': 56}, {'name': 'Raecola', 'followers': 1533, 'popularity': 12},
    {'name': 'Ratboys', 'followers': 51734, 'popularity': 40}, {'name': 'Ravyn Lenae', 'followers': 531497, 'popularity': 71},
    {'name': 'Rebecca Black', 'followers': 165702, 'popularity': 58}, {'name': 'Remi Wolf', 'followers': 590733, 'popularity': 66},
    {'name': 'Role Model', 'followers': 588282, 'popularity': 74}, {'name': 'Royel Otis', 'followers': 422890, 'popularity': 71},
    {'name': 'RÜFÜS DU SOL', 'followers': 2016509, 'popularity': 75}, {'name': 'Sabrina Carpenter', 'followers': 20591996, 'popularity': 92},
    {'name': 'Salute', 'followers': 85690, 'popularity': 53}, {'name': 'Sam Austins', 'followers': 44082, 'popularity': 60},
    {'name': 'Sammy Virji', 'followers': 167412, 'popularity': 65}, {'name': 'Sierra Ferrell', 'followers': 356087, 'popularity': 63},
    {'name': 'Silly Goose', 'followers': 29215, 'popularity': 33}, {'name': 'Sofia Camara', 'followers': 57467, 'popularity': 57},
    {'name': 'Star Bandz', 'followers': 119244, 'popularity': 51}, {'name': 'Still Woozy', 'followers': 1069174, 'popularity': 66},
    {'name': 'Sunami', 'followers': 150013, 'popularity': 50}, {'name': 'The Symposium', 'followers': 95546, 'popularity': 47},
    {'name': 'T-Pain', 'followers': 5367567, 'popularity': 79}, {'name': 'Tanner Adell', 'followers': 116218, 'popularity': 54},
    {'name': 'Tape B', 'followers': 72494, 'popularity': 53}, {'name': 'Tessla', 'followers': 358, 'popularity': 4},
    {'name': 'Torren Foot , Airwolf Paradise', 'followers': 0, 'popularity': 0}, {'name': 'TWICE', 'followers': 21586371, 'popularity': 79},
    {'name': 'Two Friends', 'followers': 237167, 'popularity': 56}, {'name': 'Tyler, the Creator', 'followers': 20926976, 'popularity': 91},
    {'name': 'Vincent Lima', 'followers': 60660, 'popularity': 54}, {'name': 'Viperactive', 'followers': 13688, 'popularity': 40},
    {'name': 'Wallows', 'followers': 2922933, 'popularity': 72}, {'name': 'Wasia Project', 'followers': 335672, 'popularity': 57},
    {'name': 'Wave to Earth', 'followers': 4162678, 'popularity': 76}, {'name': 'Wild Rivers', 'followers': 278270, 'popularity': 65},
    {'name': 'Willow Avalon', 'followers': 158903, 'popularity': 52}, {'name': 'Winnetka Bowling League', 'followers': 78904, 'popularity': 46},
    {'name': 'Winyah', 'followers': 3986, 'popularity': 35}, {'name': 'Wunderhorse', 'followers': 155400, 'popularity': 63},
    {'name': 'Wyatt Flores', 'followers': 372174, 'popularity': 67}, {'name': 'Xaviersobased', 'followers': 128173, 'popularity': 61},
    {'name': 'Xdinary Heroes', 'followers': 1163270, 'popularity': 60}, {'name': 'Yana', 'followers': 24319, 'popularity': 50},
    {'name': 'Young Miko', 'followers': 3703506, 'popularity': 77}, {'name': 'Zinadelphia', 'followers': 46263, 'popularity': 44},
    {'name': 'Zoe KoMARINA', 'followers': 0, 'popularity': 0}
]

test_content = """
<div class="stage"><h2 class="stageName">T-Mobile</h2>
<div class="day" data-date="1753938000" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">31/7/25</h3>
<div class="actLists"><div class="act id-noname-1 " data-id="noname-1" data-start-time="1753985700000" data-end-time="1753988400000" ><span class="actTime">13:15 - 14:00</span><span class="actNm">??</span></div><div class="act id-2holli-1 " data-id="2holli-1" data-start-time="1753992000000" data-end-time="1753995600000" ><span class="actTime">15:00 - 16:00</span><span class="actNm">2hollis</span></div><div class="act id-magdal-1 " data-id="magdal-1" data-start-time="1753998300000" data-end-time="1754001900000" data-mbid="68c261d5-48c8-4ea9-9466-9fc908dc79bb" ><span class="actTime">16:45 - 17:45</span><span class="actNm">Magdalena Bay</span></div><div class="act id-gracie-1 " data-id="gracie-1" data-start-time="1754005500000" data-end-time="1754009100000" data-mbid="f7441bc7-d7de-4813-a2fc-31a4033d396d" ><span class="actTime">18:45 - 19:45</span><span class="actNm">Gracie Abrams</span></div><div class="act id-tylerc-1 " data-id="tylerc-1" data-start-time="1754012700000" data-end-time="1754017200000" data-mbid="f6beac20-5dfe-4d1f-ae02-0b0a740aafd6" ><span class="actTime">20:45 - 22:00</span><span class="actNm">Tyler, the Creator</span></div></div>
</div><div class="day" data-date="1754024400" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">1/8/25</h3>
<div class="actLists"><div class="act id-alemed-1 " data-id="alemed-1" data-start-time="1754072100000" data-end-time="1754074800000" ><span class="actTime">13:15 - 14:00</span><span class="actNm">Alemeda</span></div><div class="act id-amaara-1 " data-id="amaara-1" data-start-time="1754078700000" data-end-time="1754082300000" data-mbid="29fab96f-c3a2-4251-80f6-7ccda50da706" ><span class="actTime">15:05 - 16:05</span><span class="actNm">Amaarae</span></div><div class="act id-tpain-1 " data-id="tpain-1" data-start-time="1754084700000" data-end-time="1754088300000" data-mbid="f5c2233f-20ee-48f1-ae21-53a6103acfe5" ><span class="actTime">16:45 - 17:45</span><span class="actNm">T-Pain</span></div><div class="act id-bleach-1 " data-id="bleach-1" data-start-time="1754091900000" data-end-time="1754095500000" data-mbid="58e235fc-f6ea-4614-9ed4-9855a5665ae1" ><span class="actTime">18:45 - 19:45</span><span class="actNm">Bleachers</span></div><div class="act id-olivia-1 " data-id="olivia-1" data-start-time="1754099100000" data-end-time="1754103600000" data-mbid="6925db17-f35e-42f3-a4eb-84ee6bf5d4b0" ><span class="actTime">20:45 - 22:00</span><span class="actNm">Olivia Rodrigo</span></div></div>
</div><div class="day" data-date="1754110800" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">2/8/25</h3>
<div class="actLists"><div class="act id-naomis-1 " data-id="naomis-1" data-start-time="1754158500000" data-end-time="1754161200000" ><span class="actTime">13:15 - 14:00</span><span class="actNm">Naomi Scott</span></div><div class="act id-orions-1 " data-id="orions-1" data-start-time="1754163900000" data-end-time="1754167500000" ><span class="actTime">14:45 - 15:45</span><span class="actNm">Orion Sun</span></div><div class="act id-marina-1 " data-id="marina-1" data-start-time="1754171100000" data-end-time="1754174700000" data-mbid="7f3d82ee-3817-4367-9eec-f33a312247a1" ><span class="actTime">16:45 - 17:45</span><span class="actNm">MARINA</span></div><div class="act id-clairo-1 " data-id="clairo-1" data-start-time="1754178300000" data-end-time="1754181900000" data-mbid="d786f59b-1836-4ddb-8393-ab753edbe984" ><span class="actTime">18:45 - 19:45</span><span class="actNm">Clairo</span></div><div class="act id-doechi-1 " data-id="doechi-1" data-start-time="1754185500000" data-end-time="1754190000000" data-mbid="9f75277c-b283-4846-ac8c-f932255cd0ac" ><span class="actTime">20:45 - 22:00</span><span class="actNm">Doechii</span></div></div>
</div><div class="day" data-date="1754197200" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">3/8/25</h3>
<div class="actLists"><div class="act id-rebecc-1 " data-id="rebecc-1" data-start-time="1754244900000" data-end-time="1754247600000" data-mbid="312c7cc1-9b5c-4406-963b-9f73f50674c0" ><span class="actTime">13:15 - 
14:00</span><span class="actNm">Rebecca Black</span></div><div class="act id-mariah-1 " data-id="mariah-1" data-start-time="1754250300000" data-end-time="1754253900000" data-mbid="5fc55ebf-21bd-4eda-954c-dd250132331e" ><span class="actTime">14:45 - 15:45</span><span class="actNm">Mariah the Scientist</span></div><div class="act id-stillw-1 " data-id="stillw-1" data-start-time="1754257500000" data-end-time="1754261100000" data-mbid="bfa6929d-8375-488d-b027-8a0691c73643" ><span class="actTime">16:45 - 17:45</span><span class="actNm">Still Woozy</span></div><div class="act id-domini-1 " data-id="domini-1" data-start-time="1754264700000" data-end-time="1754268300000" data-mbid="e337c918-098f-418e-97a2-81dc224b1bf9" ><span class="actTime">18:45 - 19:45</span><span class="actNm">Dominic Fike</span></div><div class="act id-sabrin-1 " data-id="sabrin-1" data-start-time="1754271900000" data-end-time="1754276400000" data-mbid="1882fe91-cdd9-49c9-9956-8e06a3810bd4" ><span class="actTime">20:45 - 22:00</span><span class="actNm">Sabrina Carpenter</span></div></div>
</div></div><div class="stage"><h2 class="stageName">IHG/Coinbase</h2>
<div class="day" data-date="1753938000" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">31/7/25</h3>
<div class="actLists"><div class="act id-sillyg-1 " data-id="sillyg-1" data-start-time="1753983000000" data-end-time="1753985700000" ><span class="actTime">12:30 - 13:15</span><span class="actNm">Silly Goose</span></div><div class="act id-sunami-1 " data-id="sunami-1" data-start-time="1753988400000" data-end-time="1753992000000" data-mbid="1b53aa11-ccef-457f-90d9-5165b270fdc5" ><span class="actTime">14:00 - 15:00</span><span class="actNm">Sunami</span></div><div class="act id-durand-1 " data-id="durand-1" data-start-time="1753995600000" data-end-time="1753998300000" data-mbid="dc346e8d-b930-4878-b0f7-7e50e197388f" ><span class="actTime">16:00 - 16:45</span><span class="actNm">Durand Bernarr</span></div><div class="act id-mattch-1 " data-id="mattch-1" data-start-time="1754001900000" data-end-time="1754005500000" ><span class="actTime">17:45 
- 18:45</span><span class="actNm">Matt Champion</span></div><div class="act id-rolemo-1 " data-id="rolemo-1" data-start-time="1754009100000" data-end-time="1754012700000" ><span class="actTime">19:45 - 20:45</span><span class="actNm">Role Model</span></div></div>
</div><div class="day" data-date="1754024400" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">1/8/25</h3>
<div class="actLists"><div class="act id-janere-1 " data-id="janere-1" data-start-time="1754069400000" data-end-time="1754072100000" ><span class="actTime">12:30 - 13:15</span><span class="actNm">Jane Remover</span></div><div class="act id-otobok-1 " data-id="otobok-1" data-start-time="1754074800000" data-end-time="1754078400000" ><span class="actTime">14:00 - 15:00</span><span class="actNm">Otoboke Beaver</span></div><div class="act id-ravenl-1 " data-id="ravenl-1" data-start-time="1754082000000" data-end-time="1754084700000" ><span class="actTime">16:00 - 16:45</span><span class="actNm">Raven Lenae</span></div><div class="act id-bladee-1 " data-id="bladee-1" data-start-time="1754088300000" data-end-time="1754091900000" data-mbid="cd689e77-dfdd-4f81-b50c-5e5a3f5e38a4" ><span class="actTime">17:45 - 18:45</span><span class="actNm">Bladee</span></div><div class="act id-foster-1 " data-id="foster-1" data-start-time="1754095500000" data-end-time="1754099100000" data-mbid="e0e1a584-dd0a-4bd1-88d1-c4c62895039d" ><span class="actTime">19:45 - 20:45</span><span class="actNm">Foster the People</span></div></div>
</div><div class="day" data-date="1754110800" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">2/8/25</h3>
<div class="actLists"><div class="act id-duasal-1 " data-id="duasal-1" data-start-time="1754155800000" data-end-time="1754158500000" ><span class="actTime">12:30 - 13:15</span><span class="actNm">Dua Saleh</span></div><div class="act id-ca7rie-1 " data-id="ca7rie-1" data-start-time="1754161200000" data-end-time="1754163900000" ><span class="actTime">14:00 - 14:45</span><span class="actNm">CA7RIEL & Paco Amoroso</span></div><div class="act id-ole60-1 " data-id="ole60-1" data-start-time="1754167500000" data-end-time="1754171100000" ><span class="actTime">15:45 - 16:45</span><span class="actNm">Ole 60</span></div><div class="act id-jpegma-1 " data-id="jpegma-1" data-start-time="1754174700000" data-end-time="1754178300000" data-mbid="c42e60f4-4520-4954-b6e4-82bbdf532c11" ><span class="actTime">17:45 - 18:45</span><span class="actNm">JPEGMAFIA</span></div><div class="act id-mkgee-1 " data-id="mkgee-1" data-start-time="1754181900000" data-end-time="1754185500000" data-mbid="262cf0ce-2af2-4686-a8cc-d6b33e97336d" ><span class="actTime">19:45 - 20:45</span><span class="actNm">Mk.gee</span></div></div>
</div><div class="day" data-date="1754197200" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">3/8/25</h3>
<div class="actLists"><div class="act id-blkody-1 " data-id="blkody-1" data-start-time="1754242200000" data-end-time="1754244900000" ><span class="actTime">12:30 - 13:15</span><span class="actNm">BLK ODYSSY</span></div><div class="act id-joeyva-1 " data-id="joeyva-1" data-start-time="1754247600000" data-end-time="1754250300000" data-mbid="93a4d03b-4f0e-42da-ae0b-a62876e46071" ><span class="actTime">14:00 - 14:45</span><span class="actNm">Joey Valence & Brae</span></div><div class="act id-artema-1 " data-id="artema-1" data-start-time="1754253900000" data-end-time="1754257500000" ><span class="actTime">15:45 - 16:45</span><span class="actNm">Artemas</span></div><div class="act id-latinm-1 " data-id="latinm-1" data-start-time="1754261100000" data-end-time="1754264700000" ><span class="actTime">17:45 - 18:45</span><span class="actNm">Latin Mafia</span></div><div class="act id-remiwo-1 " data-id="remiwo-1" data-start-time="1754268300000" data-end-time="1754271900000" data-mbid="afb6cc6d-a060-4f5e-bc3a-00d4b6832e41" ><span class="actTime">19:45 - 20:45</span><span class="actNm">Remi Wolf</span></div></div>
</div></div><div class="stage"><h2 class="stageName">Bud Light</h2>
<div class="day" data-date="1753938000" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">31/7/25</h3>
<div class="actLists"><div class="act id-yana-1 " data-id="yana-1" data-start-time="1753984800000" data-end-time="1753987500000" ><span class="actTime">13:00 - 13:45</span><span class="actNm">Yana</span></div><div class="act id-alexwa-1 " data-id="alexwa-1" data-start-time="1753991100000" data-end-time="1753994700000" ><span class="actTime">14:45 - 15:45</span><span class="actNm">Alex Warren</span></div><div class="act id-sierra-1 " data-id="sierra-1" data-start-time="1753998300000" data-end-time="1754001900000" ><span class="actTime">16:45 - 17:45</span><span class="actNm">Sierra Ferrell</span></div><div class="act id-cageel-1 " data-id="cageel-1" data-start-time="1754005500000" data-end-time="1754009100000" data-mbid="b41b38d4-ef3e-4f37-8c75-cfe9af999696" ><span class="actTime">18:45 - 19:45</span><span class="actNm">Cage the Elephant</span></div><div class="act id-lukeco-1 " data-id="lukeco-1" data-start-time="1754011800000" data-end-time="1754017200000" data-mbid="c20ee61f-071f-4e65-9c81-45ee931a54ce" ><span class="actTime">20:30 - 22:00</span><span class="actNm">Luke Combs</span></div></div>
</div><div class="day" data-date="1754024400" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">1/8/25</h3>
<div class="actLists"><div class="act id-oldmer-1 " data-id="oldmer-1" data-start-time="1754071200000" data-end-time="1754073900000" ><span class="actTime">13:00 - 13:45</span><span class="actNm">Old Mervs</span></div><div class="act id-gigipe-1 " data-id="gigipe-1" data-start-time="1754077500000" data-end-time="1754081100000" ><span class="actTime">14:45 - 15:45</span><span class="actNm">Gigi Perez</span></div><div class="act id-wallow-1 " data-id="wallow-1" data-start-time="1754084700000" data-end-time="1754088300000" ><span class="actTime">16:45 - 17:45</span><span class="actNm">Wallows</span></div><div class="act id-djo-1 " data-id="djo-1" data-start-time="1754091900000" data-end-time="1754095500000" ><span class="actTime">18:45 - 19:45</span><span class="actNm">Djo</span></div><div class="act id-korn-1 " data-id="korn-1" data-start-time="1754098200000" data-end-time="1754103600000" data-mbid="ac865b2e-bba8-4f5a-8756-dd40d5e39f46" ><span class="actTime">20:30 - 22:00</span><span class="actNm">Korn</span></div></div>
</div><div class="day" data-date="1754110800" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">2/8/25</h3>
<div class="actLists"><div class="act id-chicag1-1 " data-id="chicag1-1" data-start-time="1754157600000" data-end-time="1754160300000" ><span class="actTime">13:00 - 13:45</span><span class="actNm">Chicago Youth Symphony Orchestra</span></div><div class="act id-fujiik-1 " data-id="fujiik-1" data-start-time="1754163900000" data-end-time="1754167500000" ><span class="actTime">14:45 - 15:45</span><span class="actNm">Fujii Kaze</span></div><div class="act id-levity-1 " data-id="levity-1" data-start-time="1754171100000" data-end-time="1754174700000" data-mbid="204407c3-26ab-469a-b487-40ae6b067c1b" ><span class="actTime">16:45 - 17:45</span><span class="actNm">Levity</span></div><div class="act id-youngm-1 " data-id="youngm-1" data-start-time="1754178300000" data-end-time="1754181900000" data-mbid="c4442130-e7f2-40aa-bcab-b921cc45a365" ><span class="actTime">18:45 - 19:45</span><span class="actNm">Young Miko</span></div><div class="act id-twice-1 " data-id="twice-1" data-start-time="1754184600000" data-end-time="1754190000000" ><span class="actTime">20:30 - 22:00</span><span class="actNm">Twice</span></div></div>
</div><div class="day" data-date="1754197200" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">3/8/25</h3>
<div class="actLists"><div class="act id-wunder-1 " data-id="wunder-1" data-start-time="1754244000000" data-end-time="1754246700000" data-mbid="5126db33-86ad-469d-88fb-4158350e1515" ><span class="actTime">13:00 - 
13:45</span><span class="actNm">Wunderhorse</span></div><div class="act id-isaiah-1 " data-id="isaiah-1" data-start-time="1754250300000" data-end-time="1754253900000" data-mbid="37547347-ea75-45fa-9766-ff36b44d8147" ><span class="actTime">14:45 - 15:45</span><span class="actNm">Isaiah Rashad</span></div><div class="act id-finnea-1 " data-id="finnea-1" data-start-time="1754257500000" data-end-time="1754261100000" data-mbid="151cd917-1ee2-4702-859f-90899ad897f8" ><span class="actTime">16:45 - 17:45</span><span class="actNm">Finneas</span></div><div class="act id-maras-1 " data-id="maras-1" data-start-time="1754264700000" data-end-time="1754268300000" data-mbid="7a3970c9-ecd8-4eee-a267-4d8c77d97ff3" ><span class="actTime">18:45 - 19:45</span><span class="actNm">The Marías</span></div><div class="act id-aaproc-1 " data-id="aaproc-1" data-start-time="1754271000000" data-end-time="1754276400000" data-mbid="25b7b584-d952-4662-a8b9-dd8cdfbfeb64" ><span class="actTime">20:30 - 22:00</span><span class="actNm">A$AP Rocky</span></div></div>
</div></div><div class="stage"><h2 class="stageName">Tito's</h2>
<div class="day" data-date="1753938000" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">31/7/25</h3>
<div class="actLists"><div class="act id-xavier-1 " data-id="xavier-1" data-start-time="1753982100000" data-end-time="1753984800000" ><span class="actTime">12:15 - 13:00</span><span class="actNm">xaviersobased</span></div><div class="act id-blackp-1 " data-id="blackp-1" data-start-time="1753987500000" data-end-time="1753991100000" ><span class="actTime">13:45 - 14:45</span><span class="actNm">bLAck pARty</span></div><div class="act id-glassb-1 " data-id="glassb-1" data-start-time="1753994700000" data-end-time="1753998300000" data-mbid="5bb54b77-2caa-4377-bdc3-3b8c0f5e507f" ><span class="actTime">15:45 - 16:45</span><span class="actNm">Glass Beams</span></div><div class="act id-markam-1 " data-id="markam-1" data-start-time="1754001900000" data-end-time="1754005500000" data-mbid="483e1216-3eb3-4996-a45d-55f6169689a0" ><span class="actTime">17:45 - 18:45</span><span class="actNm">Mark Ambor</span></div><div class="act id-djheat-1 " data-id="djheat-1" data-start-time="1754009100000" data-end-time="1754011800000" data-mbid="8c2d581b-4482-4653-9d02-f44506604b57" ><span class="actTime">19:45 - 20:30</span><span class="actNm">DJ Heather</span></div></div>
</div><div class="day" data-date="1754024400" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">1/8/25</h3>
<div class="actLists"><div class="act id-heynot-1 " data-id="heynot-1" data-start-time="1754068500000" data-end-time="1754071200000" ><span class="actTime">12:15 - 13:00</span><span class="actNm">Hey, Nothing</span></div><div class="act id-oceana-1 " data-id="oceana-1" data-start-time="1754073900000" data-end-time="1754077500000" data-mbid="8cf32b06-c5a3-4804-a967-376f88d12aad" ><span class="actTime">13:45 - 14:45</span><span class="actNm">Ocean Alley</span></div><div class="act id-dare-1 " data-id="dare-1" data-start-time="1754081100000" data-end-time="1754084700000" data-mbid="7fe3380a-8e35-48d1-ac5a-174fe6b5060b" ><span class="actTime">15:45 - 16:45</span><span class="actNm">The Dare</span></div><div class="act id-fliptu-1 " data-id="fliptu-1" data-start-time="1754088300000" data-end-time="1754091900000" ><span class="actTime">17:45 - 18:45</span><span class="actNm">flipturn</span></div><div class="act id-starba1-1 " data-id="starba1-1" data-start-time="1754095500000" data-end-time="1754098200000" ><span class="actTime">19:45 - 20:30</span><span 
class="actNm">STAR BANDZ</span></div></div>
</div><div class="day" data-date="1754110800" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">2/8/25</h3>
<div class="actLists"><div class="act id-ba-1 " data-id="ba-1" data-start-time="1754154900000" data-end-time="1754157600000" ><span class="actTime">12:15 - 13:00</span><span class="actNm">Bôa</span></div><div class="act id-salute-1 " data-id="salute-1" data-start-time="1754160300000" data-end-time="1754163900000" data-mbid="87484a93-1aae-4917-8d2f-7af0d16a2129" ><span class="actTime">13:45 - 14:45</span><span class="actNm">Salute</span></div><div class="act id-maxmck-1 " data-id="maxmck-1" data-start-time="1754167500000" data-end-time="1754171100000" ><span class="actTime">15:45 - 16:45</span><span class="actNm">Max McKnown</span></div><div class="act id-damian-1 " data-id="damian-1" data-start-time="1754174700000" data-end-time="1754178300000" data-mbid="852c198a-75ee-4e2b-9aba-4453c52260b2" ><span class="actTime">17:45 - 18:45</span><span class="actNm">Damiano David</span></div><div class="act id-starba-1 " data-id="starba-1" data-start-time="1754181900000" data-end-time="1754184600000" ><span class="actTime">19:45 - 20:30</span><span class="actNm">Starbandz</span></div></div>
</div><div class="day" data-date="1754197200" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">3/8/25</h3>
<div class="actLists"><div class="act id-benche-1 " data-id="benche-1" data-start-time="1754241300000" data-end-time="1754244000000" ><span class="actTime">12:15 - 13:00</span><span class="actNm">Benches</span></div><div class="act id-laila-1 " data-id="laila-1" data-start-time="1754246700000" data-end-time="1754250300000" ><span class="actTime">13:45 - 14:45</span><span class="actNm">Laila!</span></div><div class="act id-wildri-1 " data-id="wildri-1" data-start-time="1754253900000" data-end-time="1754257500000" data-mbid="ffd11889-af95-42ed-b0ee-315df62510f5" ><span class="actTime">15:45 - 16:45</span><span class="actNm">Wild Rivers</span></div><div class="act id-ian-1 " data-id="ian-1" data-start-time="1754261100000" data-end-time="1754264700000" ><span class="actTime">17:45 - 18:45</span><span class="actNm">ian</span></div><div class="act id-aliyah-1 " data-id="aliyah-1" data-start-time="1754268300000" data-end-time="1754271000000" ><span class="actTime">19:45 - 20:30</span><span class="actNm">Aliyah's Interlude</span></div></div>
</div></div><div class="stage"><h2 class="stageName">Perry's/Solana</h2>
<div class="day" data-date="1753938000" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">31/7/25</h3>
<div class="actLists"><div class="act id-torren-1 " data-id="torren-1" data-start-time="1753981200000" data-end-time="1753984800000" ><span class="actTime">12:00 - 13:00</span><span class="actNm">Torren Foot b2b Airwolf Paradise</span></div><div class="act id-azzecc-1 " data-id="azzecc-1" data-start-time="1753985400000" data-end-time="1753987500000" ><span class="actTime">13:10 - 13:45</span><span class="actNm">Azzecca</span></div><div class="act id-prospa-1 " data-id="prospa-1" data-start-time="1753987800000" data-end-time="1753990500000" data-mbid="4c3cffca-37b7-4ecd-9320-e6dcc2cb837a" ><span class="actTime">13:50 - 14:35</span><span class="actNm">Prospa</span></div><div class="act id-blesse-1 " data-id="blesse-1" data-start-time="1753991100000" data-end-time="1753994400000" data-mbid="3f351696-75a2-4167-86b1-c5cd37770600" ><span class="actTime">14:45 - 15:40</span><span class="actNm">The Blessed Madonna</span></div><div class="act id-overmo-1 " data-id="overmo-1" data-start-time="1753995300000" data-end-time="1753998900000" data-mbid="b841d0f2-0a2a-4cb2-a2d8-9895b7f90bfa" ><span class="actTime">15:55 - 16:55</span><span class="actNm">Overmono</span></div><div class="act id-cloone-1 " data-id="cloone-1" data-start-time="1753999800000" data-end-time="1754003400000" data-mbid="b643c24d-4cd6-4531-88bc-62b39ce43ee1" ><span class="actTime">17:10 - 18:10</span><span class="actNm">Cloonee</span></div><div class="act id-barryc-1 " data-id="barryc-1" data-start-time="1754003700000" data-end-time="1754007900000" data-mbid="7dcf3b98-701a-4309-a90c-eb4179b96ea9" ><span class="actTime">18:15 - 19:25</span><span class="actNm">Barry Can't Swim</span></div><div class="act id-maup-1 " data-id="maup-1" data-start-time="1754008500000" data-end-time="1754012100000" data-mbid="933d5cd2-a70a-44b5-96e5-332b32209592" ><span class="actTime">19:35 - 20:35</span><span class="actNm">Mau P</span></div><div class="act id-domdol-1 " data-id="domdol-1" data-start-time="1754012700000" data-end-time="1754017200000" data-mbid="9b8548a9-5991-42a9-ba96-fe83bd238b7a" ><span class="actTime">20:45 - 22:00</span><span class="actNm">Dom Dolla</span></div></div>
</div><div class="day" data-date="1754024400" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">1/8/25</h3>
<div class="actLists"><div class="act id-hexcou-1 " data-id="hexcou-1" data-start-time="1754067600000" data-end-time="1754069700000" ><span class="actTime">12:00 - 12:35</span><span class="actNm">Hex Cougar</span></div><div class="act id-marydr-1 " data-id="marydr-1" data-start-time="1754070900000" data-end-time="1754073300000" ><span class="actTime">12:55 - 13:35</span><span class="actNm">Mary Droppinz</span></div><div class="act id-vipera-1 " data-id="vipera-1" data-start-time="1754073900000" data-end-time="1754076600000" data-mbid="54eb87ac-5fcf-41de-b86e-9fafd1e771de" ><span class="actTime">13:45 - 14:30</span><span class="actNm">Viperactive</span></div><div class="act id-alleyc-1 " data-id="alleyc-1" data-start-time="1754077200000" data-end-time="1754081100000" data-mbid="2590b6d4-648a-4092-9850-f614d6df51ca" ><span class="actTime">14:40 - 15:45</span><span class="actNm">ALLEYCVT</span></div><div class="act id-murdab-1 " data-id="murdab-1" data-start-time="1754081700000" data-end-time="1754085300000" ><span class="actTime">15:55 - 16:55</span><span class="actNm">Murda Beats</span></div><div class="act id-bunt-1 " data-id="bunt-1" data-start-time="1754085900000" data-end-time="1754089500000" ><span class="actTime">17:05 - 18:05</span><span class="actNm">BUNT.</span></div><div class="act id-tapeb-1 " data-id="tapeb-1" data-start-time="1754089800000" data-end-time="1754094000000" data-mbid="cdee470d-8167-4c15-808e-c4ce7fa3d6e7" ><span class="actTime">18:10 - 19:20</span><span class="actNm">Tape B</span></div><div class="act id-isoxo-1 " data-id="isoxo-1" data-start-time="1754094600000" data-end-time="1754098200000" data-mbid="8f9a7d46-778a-48b6-8b4c-0c0938a95053" ><span class="actTime">19:30 - 20:30</span><span class="actNm">ISOxo</span></div><div class="act id-knock2-1 " data-id="knock2-1" data-start-time="1754099100000" data-end-time="1754103600000" ><span class="actTime">20:45 - 
22:00</span><span class="actNm">Knock2</span></div></div>
</div><div class="day" data-date="1754110800" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">2/8/25</h3>
<div class="actLists"><div class="act id-tessla-1 " data-id="tessla-1" data-start-time="1754154000000" data-end-time="1754156700000" ><span class="actTime">12:00 - 12:45</span><span class="actNm">Tessla</span></div><div class="act id-jev-1 " data-id="jev-1" data-start-time="1754157600000" data-end-time="1754160300000" ><span class="actTime">13:00 - 13:45</span><span class="actNm">JEV</span></div><div class="act id-daniel-1 " data-id="daniel-1" data-start-time="1754160900000" data-end-time="1754163600000" ><span class="actTime">13:55 - 14:40</span><span class="actNm">Daniel Allan</span></div><div class="act id-layz-1 " data-id="layz-1" data-start-time="1754164500000" data-end-time="1754167500000" data-mbid="60c0c427-ef03-4d63-b47e-9ab08bf48d04" ><span class="actTime">14:55 - 15:45</span><span class="actNm">LAYZ</span></div><div class="act id-fluxpa-1 " data-id="fluxpa-1" data-start-time="1754167800000" data-end-time="1754171400000" data-mbid="3ce513c5-bdd4-492c-a875-07e0f3e1993b" ><span class="actTime">15:50 - 16:50</span><span class="actNm">Flux Pavilion</span></div><div class="act id-drfres-1 " data-id="drfres-1" data-start-time="1754172300000" data-end-time="1754175900000" data-mbid="6bc0fa87-4d85-4387-94f0-f99094c32ea6" ><span class="actTime">17:05 - 18:05</span><span class="actNm">Dr. Fresch</span></div><div class="act id-chases-1 " data-id="chases-1" data-start-time="1754176500000" data-end-time="1754180100000" data-mbid="82e454e2-38ee-4e69-89a6-cc65167753d1" ><span class="actTime">18:15 - 19:15</span><span class="actNm">Chase & Status</span></div><div class="act id-twofri-1 " data-id="twofri-1" data-start-time="1754180700000" data-end-time="1754184300000" data-mbid="c394e9ff-888f-4c03-a494-147d5aa53ccb" ><span class="actTime">19:25 - 20:25</span><span class="actNm">Two Friends</span></div><div class="act id-rfsdus-1 " data-id="rfsdus-1" data-start-time="1754184600000" data-end-time="1754190000000" ><span class="actTime">20:30 - 22:00</span><span class="actNm">Rüfüs Du Sol</span></div></div>
</div><div class="day" data-date="1754197200" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">3/8/25</h3>
<div class="actLists"><div class="act id-raecol-1 " data-id="raecol-1" data-start-time="1754240400000" data-end-time="1754243100000" ><span class="actTime">12:00 - 12:45</span><span class="actNm">RaeCola</span></div><div class="act id-jigitz-1 " data-id="jigitz-1" data-start-time="1754244300000" data-end-time="1754247600000" ><span class="actTime">13:05 - 14:00</span><span class="actNm">jigitz</span></div><div class="act id-nimino-1 " data-id="nimino-1" data-start-time="1754248800000" data-end-time="1754252400000" ><span class="actTime">14:20 - 15:20</span><span class="actNm">nimino</span></div><div class="act id-maribo-1 " data-id="maribo-1" data-start-time="1754254500000" data-end-time="1754258100000" data-mbid="72034a05-bcd8-40c2-8255-3ee4ac0e7ef0" ><span class="actTime">15:55 - 16:55</span><span class="actNm">Maribou State</span></div><div class="act id-marlon-1 " data-id="marlon-1" data-start-time="1754258700000" data-end-time="1754262900000" ><span class="actTime">17:05 - 18:15</span><span class="actNm">Marlon Hoffstadt</span></div><div class="act id-sammyv-1 " data-id="sammyv-1" data-start-time="1754263200000" data-end-time="1754267100000" data-mbid="e23abc5f-478a-4594-ad18-b3805b3c5316" ><span class="actTime">18:20 - 19:25</span><span class="actNm">Sammy Virji</span></div><div class="act id-gryffi-1 " data-id="gryffi-1" data-start-time="1754267400000" data-end-time="1754271000000" data-mbid="f1348139-efb5-43c7-9204-199827efad3c" ><span class="actTime">19:30 - 20:30</span><span class="actNm">Gryffin</span></div><div class="act id-martin-1 " data-id="martin-1" data-start-time="1754271900000" data-end-time="1754276400000" data-mbid="3e1f2ee4-16be-4406-bf18-6173840cf2b1" 
><span class="actTime">20:45 - 22:00</span><span class="actNm">Martin Garrix</span></div></div>
</div></div><div class="stage"><h2 class="stageName">Bacardi</h2>
<div class="day" data-date="1753938000" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">31/7/25</h3>
<div class="actLists"><div class="act id-alexsu-1 " data-id="alexsu-1" data-start-time="1753984200000" data-end-time="1753986900000" ><span class="actTime">12:50 - 13:35</span><span class="actNm">ALEXSUCKS</span></div><div class="act id-sympos-1 " data-id="sympos-1" data-start-time="1753988400000" data-end-time="1753991100000" ><span class="actTime">14:00 - 14:45</span><span class="actNm">The Symposium</span></div><div class="act id-nouris-1 " data-id="nouris-1" data-start-time="1753992300000" data-end-time="1753995000000" data-mbid="6420dd6b-8232-42db-9cb9-90bec8f40e91" ><span class="actTime">15:05 - 15:50</span><span class="actNm">Nourished By Time</span></div><div class="act id-ratboy-1 " data-id="ratboy-1" data-start-time="1753996500000" data-end-time="1753999200000" ><span class="actTime">16:15 - 17:00</span><span class="actNm">Ratboys</span></div><div class="act id-julie-1 " data-id="julie-1" data-start-time="1754000700000" data-end-time="1754003400000" data-mbid="1e79565e-60d5-498d-aa73-fa24d9065df1" ><span class="actTime">17:25 - 18:10</span><span class="actNm">julie</span></div><div class="act id-fcuker-1 " data-id="fcuker-1" data-start-time="1754004900000" data-end-time="1754007600000" data-mbid="5e23e428-d9f5-4679-bd7c-8254d6f0a437" ><span class="actTime">18:35 - 19:20</span><span class="actNm">Fcukers</span></div><div class="act id-halfal-1 " data-id="halfal-1" data-start-time="1754009100000" data-end-time="1754011800000" ><span class="actTime">19:45 - 20:30</span><span class="actNm">Half-Alive</span></div><div class="act id-xdinar-1 " data-id="xdinar-1" data-start-time="1754013600000" data-end-time="1754017200000" ><span class="actTime">21:00 - 22:00</span><span 
class="actNm">Xdinary Heroes</span></div></div>
</div><div class="day" data-date="1754024400" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">1/8/25</h3>
<div class="actLists"><div class="act id-midnig-1 " data-id="midnig-1" data-start-time="1754070600000" data-end-time="1754073300000" ><span class="actTime">12:50 - 13:35</span><span class="actNm">Midnight Generation</span></div><div class="act id-dogpar-1 " data-id="dogpar-1" data-start-time="1754075100000" data-end-time="1754077800000" ><span class="actTime">14:05 - 14:50</span><span class="actNm">Dogpark</span></div><div class="act id-zinade-1 " data-id="zinade-1" data-start-time="1754079300000" data-end-time="1754082000000" ><span class="actTime">15:15 - 16:00</span><span class="actNm">Zinadelphia</span></div><div class="act id-isabel-1 " data-id="isabel-1" data-start-time="1754083500000" data-end-time="1754086200000" ><span class="actTime">16:25 - 17:10</span><span class="actNm">Isabel Larosa</span></div><div class="act id-orlaga-1 " data-id="orlaga-1" data-start-time="1754087700000" data-end-time="1754090400000" data-mbid="8094a83b-86ce-4a13-b25f-90af829c9ed6" ><span class="actTime">17:35 - 18:20</span><span class="actNm">Orla Gartland</span></div><div class="act id-delwat-1 " data-id="delwat-1" data-start-time="1754091900000" data-end-time="1754094600000" data-mbid="5f606b3d-fab7-4d39-bcdb-f5d42edae945" ><span class="actTime">18:45 - 19:30</span><span 
class="actNm">Del Water Gap</span></div><div class="act id-kennym-1 " data-id="kennym-1" data-start-time="1754095800000" data-end-time="1754098500000" ><span class="actTime">19:50 - 20:35</span><span class="actNm">Kenny Mason</span></div><div class="act id-wyattf-1 " data-id="wyattf-1" data-start-time="1754100000000" data-end-time="1754103600000" data-mbid="4ae67eb7-c01c-4d71-b995-21b093fcb888" ><span class="actTime">21:00 - 22:00</span><span class="actNm">Wyatt Flores</span></div></div>
</div><div class="day" data-date="1754110800" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">2/8/25</h3>
<div class="actLists"><div class="act id-eddiea-1 " data-id="eddiea-1" data-start-time="1754154000000" data-end-time="1754156700000" ><span class="actTime">12:00 - 12:45</span><span class="actNm">Eddie and the Getaway</span></div><div class="act id-junior-1 " data-id="junior-1" data-start-time="1754157600000" data-end-time="1754160300000" ><span class="actTime">13:00 - 13:45</span><span class="actNm">Junior Varsity</span></div><div class="act id-winnet-1 " data-id="winnet-1" data-start-time="1754161200000" data-end-time="1754163900000" ><span class="actTime">14:00 - 14:45</span><span class="actNm">Winnetka Bowling League</span></div><div class="act id-kickfl-1 " data-id="kickfl-1" data-start-time="1754164800000" data-end-time="1754167500000" ><span class="actTime">15:00 - 15:45</span><span class="actNm">Kickflip</span></div><div class="act 
id-newdad-1 " data-id="newdad-1" data-start-time="1754168400000" data-end-time="1754171100000" data-mbid="038bd27c-ebec-44e5-9880-1f5eb933db11" ><span class="actTime">16:00 - 16:45</span><span class="actNm">NewDad</span></div><div class="act id-charlo-1 " data-id="charlo-1" data-start-time="1754172000000" data-end-time="1754174700000" ><span class="actTime">17:00 - 17:45</span><span class="actNm">Charlotte Lawrence</span></div><div class="act id-wasiap-1 " data-id="wasiap-1" data-start-time="1754175600000" data-end-time="1754178300000" ><span class="actTime">18:00 - 18:45</span><span class="actNm">Wasia Project</span></div><div class="act id-montel-1 " data-id="montel-1" data-start-time="1754179200000" data-end-time="1754181900000" ><span class="actTime">19:00 - 19:45</span><span class="actNm">Montell Fish</span></div><div class="act id-bossma-1 " data-id="bossma-1" data-start-time="1754182800000" data-end-time="1754185500000" ><span class="actTime">20:00 - 20:45</span><span class="actNm">Bossman Dlow</span></div><div class="act id-bilmur-1 " data-id="bilmur-1" data-start-time="1754186400000" data-end-time="1754190000000" data-mbid="b09de30a-09ac-4cc9-8812-49bb12e2bfa6" ><span class="actTime">21:00 - 22:00</span><span class="actNm">Bilmuri</span></div></div></div><div class="day" data-date="1754197200" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">3/8/25</h3>
<div class="actLists"><div class="act id-lekan-1 " data-id="lekan-1" data-start-time="1754243400000" data-end-time="1754246400000" ><span class="actTime">12:50 - 13:40</span><span class="actNm">Lekan</span></div><div class="act id-critic-1 " data-id="critic-1" data-start-time="1754247900000" data-end-time="1754250600000" ><span class="actTime">14:05 - 14:50</span><span class="actNm">The Criticals</span></div><div class="act id-joep-1 " data-id="joep-1" data-start-time="1754251800000" data-end-time="1754254500000" ><span class="actTime">15:10 - 15:55</span><span class="actNm">Joe P</span></div><div class="act id-flower-1 " data-id="flower-1" data-start-time="1754256000000" data-end-time="1754258700000" data-mbid="cc082564-87b8-405c-97b0-7c2a8e84212a" ><span class="actTime">16:20 - 17:05</span><span class="actNm">Flowerovlove</span></div><div class="act id-boynex-1 " data-id="boynex-1" data-start-time="1754260200000" data-end-time="1754262900000" ><span class="actTime">17:30 - 18:15</span><span class="actNm">Boynextdoor</span></div><div class="act id-femme-1 " data-id="femme-1" data-start-time="1754264400000" data-end-time="1754267100000" data-mbid="45ce3d4f-3cb5-474a-a3b0-614b0f517349" ><span class="actTime">18:40 - 19:25</span><span class="actNm">La Femme</span></div><div class="act id-katsey-1 " data-id="katsey-1" data-start-time="1754268600000" data-end-time="1754271300000" ><span class="actTime">19:50 - 20:35</span><span class="actNm">KATSEYE</span></div><div class="act id-waveto-1 " data-id="waveto-1" data-start-time="1754272800000" data-end-time="1754276400000" ><span class="actTime">21:00 - 22:00</span><span class="actNm">wave to earth</span></div></div>
</div></div><div class="stage"><h2 class="stageName">BMI</h2>
<div class="day" data-date="1753938000" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">31/7/25</h3>
<div class="actLists"><div class="act id-girlto-1 " data-id="girlto-1" data-start-time="1753984800000" data-end-time="1753987200000" ><span class="actTime">13:00 - 13:40</span><span class="actNm">Girl Tones</span></div><div class="act id-chicag-1 " data-id="chicag-1" data-start-time="1753989300000" data-end-time="1753991700000" ><span class="actTime">14:15 - 14:55</span><span class="actNm">Chicago Made</span></div><div class="act id-bostal-1 " data-id="bostal-1" data-start-time="1753993500000" data-end-time="1753995900000" ><span class="actTime">15:25 - 16:05</span><span class="actNm">Bo Staloch</span></div><div class="act id-colbya-1 " data-id="colbya-1" data-start-time="1753997700000" data-end-time="1754000100000" ><span class="actTime">16:35 - 17:15</span><span class="actNm">Colby Acuff</span></div><div class="act id-jadele-1 " data-id="jadele-1" data-start-time="1754001900000" data-end-time="1754004300000" ><span class="actTime">17:45 - 18:25</span><span class="actNm">Jade Lemac</span></div><div class="act id-dropti-1 " data-id="dropti-1" data-start-time="1754005800000" data-end-time="1754008200000" ><span class="actTime">18:50 - 19:30</span><span class="actNm">The Droptines</span></div></div>
</div><div class="day" data-date="1754024400" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">1/8/25</h3>
<div class="actLists"><div class="act id-winyah-1 " data-id="winyah-1" data-start-time="1754071200000" data-end-time="1754073600000" ><span class="actTime">13:00 - 13:40</span><span class="actNm">Winyah</span></div><div class="act id-cassan-1 " data-id="cassan-1" data-start-time="1754075700000" data-end-time="1754078100000" ><span class="actTime">14:15 - 14:55</span><span class="actNm">Cassandra Coleman</span></div><div class="act id-caroli-1 " data-id="caroli-1" data-start-time="1754079900000" data-end-time="1754082300000" ><span class="actTime">15:25 - 16:05</span><span class="actNm">Caroline Kingsbury</span></div><div class="act id-carola-1 " data-id="carola-1" data-start-time="1754084100000" data-end-time="1754086500000" ><span class="actTime">16:35 - 17:15</span><span class="actNm">Carol Ades</span></div><div class="act id-jessed-1 " data-id="jessed-1" data-start-time="1754088000000" data-end-time="1754090400000" ><span class="actTime">17:40 - 18:20</span><span class="actNm">Jesse Detor</span></div><div class="act id-tanner-1 " data-id="tanner-1" data-start-time="1754092200000" data-end-time="1754094600000" data-mbid="dc5aa749-10d1-4e58-a18d-9e2c8cadaa7c" ><span class="actTime">18:50 - 19:30</span><span class="actNm">Tanner Adell</span></div></div>     
</div><div class="day" data-date="1754110800" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">2/8/25</h3>
<div class="actLists"><div class="act id-zoeko-1 " data-id="zoeko-1" data-start-time="1754157600000" data-end-time="1754160000000" ><span class="actTime">13:00 - 13:40</span><span class="actNm">Zoe Ko</span></div><div class="act id-people-1 " data-id="people-1" data-start-time="1754161800000" data-end-time="1754164200000" ><span class="actTime">14:10 - 14:50</span><span class="actNm">People R Ugly</span></div><div class="act id-landon-1 " data-id="landon-1" data-start-time="1754165700000" data-end-time="1754168100000" ><span class="actTime">15:15 - 15:55</span><span class="actNm">Landon Conrath</span></div><div class="act id-rachel-1 " data-id="rachel-1" data-start-time="1754169600000" data-end-time="1754172000000" ><span class="actTime">16:20 - 17:00</span><span class="actNm">Rachel Grae</span></div><div class="act id-carter-1 " data-id="carter-1" data-start-time="1754174100000" data-end-time="1754176500000" ><span class="actTime">17:35 - 18:15</span><span class="actNm">Carter Vail</span></div><div class="act id-samaus-1 " data-id="samaus-1" data-start-time="1754178600000" data-end-time="1754181000000" ><span class="actTime">18:50 - 19:30</span><span class="actNm">Sam Austins</span></div></div>
</div><div class="day" data-date="1754197200" data-first-start="43200" data-last-stop="79200"><h3 class="dayName">3/8/25</h3>
<div class="actLists"><div class="act id-kaicre-1 " data-id="kaicre-1" data-start-time="1754244000000" data-end-time="1754246400000" ><span class="actTime">13:00 - 13:40</span><span class="actNm">Kaicrewsade</span></div><div class="act id-graham-1 " data-id="graham-1" data-start-time="1754248200000" data-end-time="1754250600000" data-mbid="0ddd210b-12f5-43f5-ba4b-17c9da267d4c" ><span class="actTime">14:10 - 14:50</span><span class="actNm">Graham Barham</span></div><div class="act id-sofiac-1 " data-id="sofiac-1" data-start-time="1754252400000" data-end-time="1754254800000" ><span class="actTime">15:20 - 16:00</span><span class="actNm">Sofia Camara</span></div><div class="act id-landon1-1 " data-id="landon1-1" data-start-time="1754256300000" data-end-time="1754258700000" data-mbid="f5b25786-81c6-4d48-9042-76b7ea75a0ce" ><span class="actTime">16:25 - 17:05</span><span class="actNm">Landon Barker</span></div><div class="act id-vincen-1 " data-id="vincen-1" data-start-time="1754260500000" data-end-time="1754262900000" ><span class="actTime">17:35 - 18:15</span><span class="actNm">Vincent Lima</span></div><div class="act id-willow-1 " data-id="willow-1" data-start-time="1754265000000" data-end-time="1754267400000" data-mbid="a7c5cd9d-861f-4500-9958-ec4a50b7d80f" 
><span class="actTime">18:50 - 19:30</span><span class="actNm">Willow Avalon</span></div></div>
</div></div></div>
"""

genre_source =  "https://docs.google.com/document/d/1aEJK7fxm-8BUmWOp24QD2GEpIR2YVU3pmbc23-I2vgc/edit?tab=t.0"
dicto = { # POP
    "POP": [
        "Sabrina Carpenter", "The Dare", "KATSEYE", "Charlotte Lawrence",
        "Isabel LaRosa", "Naomi Scott", "Jade LeMac", "Zoe Ko"
        "MARINA", "Artemas", "Nourished By Time", "Caroline Kingsbury",
        "Olivia Rodrigo", "Damiano David", "Remi Wolf", "Magdalena Bay", 
        "Sam Austins", "Wasia Project", "Vincent Lima", "Bo Staloch"],
    "INDIE": [
        "Dominic Fike", "Bleachers", "Wallows", "Foster the People",
        "Role Model", "Finneas", "Royel Otis", "Flipturn", "Half Alive",
        "Del Water Gap", "Alemeda", "New Dad", "Dogpark", "Joe P",
        "Winnetka Bowling League", "Carole Ades", "Carter Vail",
        "Landon Conrath,", "RÜFÜS DU SOL"],
    "DREAM_POP": [
        "Gracie Abrams", "Clairo", "The Marias", "Mk.gee", "Still Woozy",
        "Wave to Earth", "Flowerovlove", "Yana", "Julie", "Alex Warren", 
        "Rachel Grae", "Sofia Camara", "Cassandra Coleman"],
    "K_POP": ["TWICE", "Boynextdoor", "Kickflip", "Fujii Kaze"],
    # ROCK
    "ROCK": ["Glass Beams", "benches", "Orla Gartland", 
             "Ole 60", "The Droptines", "Winyah",
             "Xdinary Heroes"],
    "ALT" : ["Cage the Elephant", 
            "Gigi Perez", "Wunderhorse", "hey, nothing",
            "Ratboys", "Bôa", "Old Mervs", "Jesse Detor", "Junior Varsity",
            "ALEXSUCKS", "Girl Tones", "Eddie and the Getaway"],
    "PUNK": ["Landon Barker", "People R Ugly", "Sunami", 
             "The Criticals", "Otoboke Beaver", "Bilmuri"],
    "NU_METAL": ["Korn", "Silly Goose"],
    "PSYCH_ROCK": ["DJO", "Ocean Alley", "La Femme", "The Symposium"],
    #EDM
    "HOUSE": ["Martin Garrix", "Two Friends", "The Blessed Madonna",
              "Barry Can't Swim", "Prospa", "Azzecca", "DJ Heather",
              "Tessla", "Aliyah's Interlude", "BUNT.", "Salute",
              "Nimino", "Jigitz", "Daniel Allan", "Jev", "Dom Dolla",
              "Mau P", "Cloonee", "Torren Foot , Airwolf Paradise",
              "Raecola"],
    "DUBSTEP": ["ISOxo", "Tape B", "Flux Pavilion", "Levity",
                "Layz", "ALLEYCVT", "Hex Cougar", "Viperactive"],
    "BASS": ["KNOCK2", "Dr. Fresch", "Gryffin", "Mary Droppinz"],
    "TECHNO": ["Marlon Hoffstadt", "Rebecca Black"],
    "DnB": ["Sammy Virji", "Overmono", "Chase & Status"],
    "DANCE": ["Fcukers", "Maribou State"],
    # RAP
    "RAP": ["Tyler, the Creator", "Doechii", "Isaiah Rashad", "Joey Valence & Brae",
        "Matt Champion", "Kenny Mason", "Kaicrewsade", "JPEGMafia", "Young Miko"],
    "TRAP": ["A$AP Rocky", "Ian", "Bossman Dlow", "Murda Beatz", "Star Bandz"],
    "EMORAP": ["Bladee", "2Hollis", "Jane Remover", "Xaviersobased"],
    # R&B
    "SOUL": ["Ravyn Lenae", "Montell Fish", "BLK Odyssy", "Lekan", "Ca7riel y Paco Amoroso"],
    "RnB": ["T-Pain", "Durand Bernarr", "Zinadelphia", "Mariah the Scientist",
            "Orion Sun", "Laila!", "Black Party", "Dua Saleh", "Latin Mafia"],
    # OTHER
    "COUNTRY": ["Luke Combs", "Wyatt Flores", "Max McNown", "Willow Avalon",
                "Colby Acuff", "Graham Barham", "Tanner Adell"],
    "FOLK": ["Sierra Ferrell", "Wild Rivers", "Mark Ambor"],
    "OTHER": ["Chicago Youth Symphony Orchestra", "Amaarae", "Chicago Made", "Midnight Generation"],
}

duoActs = {"Torren Foot B2B Airwolf Paradise" : ["Torren Foot", "Airwolf Paradise"]}

forClashFinder = {} # k:v is name in clash finder : name in genre list

def get_client_credentials(file_path="creds.json"):
    try:
        with open(file_path, 'r') as file:
            data = json.load(file)
            client_id = data['client_id']
            client_secret = data['client_secret']
            return client_id, client_secret
    except (KeyError, FileNotFoundError, json.decoder.JSONDecodeError) as e:
        print(f"No Spotify credentials found. {e}. Setting all acts to a popularity of 0.")
        return None, None

def get_artist(artist_name, client_id, client_secret):
    first_match = False
    if "'" in artist_name:
        first_match = True
        artist_name = artist_name.replace("'", "")
            
    # Authenticate with Spotify
    auth_manager = SpotifyClientCredentials(client_id=client_id, client_secret=client_secret)
    sp = spotipy.Spotify(auth_manager=auth_manager)
    
    
    # Search for the artist
    result = sp.search(q='artist:' + artist_name, type='artist')
    artist_results = result['artists']['items']
    if not artist_results:
        if PRINT_SEARCH_RESULTS:
            print(f"FAILED TO FIND: {artist_name}")
        return None
    artist_info = None
    names_in_search = []
    for option in artist_results:
        names_in_search.append(option['name'] )
    dupes = names_in_search.count(artist_name)
    if PRINT_SEARCH_RESULTS and dupes > 1:
        print(f"{dupes} EXACT MATCHES FOUND FOR: {artist_name}: {names_in_search}")
    for option in artist_results:
        name = option['name'] 
        if first_match:
            if PRINT_SEARCH_RESULTS:
                print(f"Best for {artist_name} is {name} | Choices were {names_in_search}")
            artist_info = option
            break
        if name.upper() == artist_name.upper():
            if PRINT_SEARCH_RESULTS and dupes <= 1:
                print(f"Found {name} | Choices were {names_in_search}")
            artist_info = option
            break
    if artist_info is None:
        if PRINT_SEARCH_RESULTS:
            print(f"FAILED TO FIND: {artist_name}, BUT FOUND {names_in_search}")
        return None   
    return artist_info

def get_artist_followers_popularity(artist_name, client_id, client_secret):
    if findGenre(artist_name) == GENRE_DEFAULT:
        return 0,0, True
    artist_info = get_artist(artist_name, client_id, client_secret)
    if artist_info is None:
        return 0,0, False
    followers = artist_info['followers']['total']
    popularity = artist_info['popularity']
    return followers, popularity, True

def strip_word(text, words_to_remove):
    words = text.split()
    stripped_words = [word for word in words if word.lower() not in map(str.lower, words_to_remove)]
    stripped_text = ' '.join(stripped_words)
    return stripped_text

def rank_artists_by_popularity(artists):
    # Sort artists by popularity in descending order
    sorted_artists = sorted(artists, key=lambda x: x['followers'], reverse=True)
    
    # Create a dictionary to store the ranks
    artist_ranks = {}
    
    # Assign ranks starting from 1
    for rank, artist in enumerate(sorted_artists, start=1):
        artist_ranks[artist['name']] = rank
    
    return artist_ranks

def findGenre(act):
    for key in dicto:
        for i in dicto[key]:
            if i.upper() == act.upper():
                return key
    return "GENRE_COUNT"

def get_ranking(artists, name):
    for artist in artists:
        if artist['name'].lower() == name.lower():
            if artist['popularity'] == 0:
                return 0
            return artist['overall']
    return 0

def set_pop_follow_manually(artists, name, pop, follower):
    for artist in artists:
        if artist['name'].lower() == name.lower():
            artist['popularity'] = pop
            artist['followers'] = follower
    return artists

def convert_timestamp(ts):
    ts = datetime.fromtimestamp(ts / 1000, TZ)
    return ts

def get_html_data(content):
    fullData = {}
    # Parsing the HTML
    soup = BeautifulSoup(content, 'html.parser')
    stage_div = soup.find_all('div', class_='stage')
    for stage in stage_div:
        stage_name = stage.find('h2', class_='stageName').text.strip()
        day_div = stage.find_all('div', class_='day')
        for day in day_div:
            acts = day.find_all('div', class_='act')
            for act in acts:
                artist = act.find('span', class_='actNm').text.strip()
                
                start_time = convert_timestamp(int(act['data-start-time']))
                end_time = convert_timestamp(int(act['data-end-time']))        
                act_info = {"stage" : stage_name, "start_time" : start_time, "end_time" : end_time}
                if artist in fullData:  # For when an act has multiple sets
                    if isinstance(fullData[artist], dict):
                        fullData[artist] = [fullData[artist]]
                    fullData[artist].append(act_info)
                else:
                    fullData[artist] = act_info
    return fullData

def get_url_content(url):
    fp = urllib.request.urlopen(url)
    mybytes = fp.read()
    mystr = mybytes.decode("utf8")
    fp.close()
    return mystr

def getFullArray(listActs):
    # Spits out the array of acts in alphabetically order
    duo_mult = 1.2  # Since duos are more hype, add a multiplier to their popularity and follower averages
    listActsPop = []
    listActsNotFound = []
    listActsInListDuos = []
    client_id, client_secret = get_client_credentials()
    if client_id is None and client_secret is None:  # If there aren't any Spotify credentials, just set the popularity of all acts to zero
        for act in listActs:
            listActsPop.append({'name':act, 'followers' : 0, "popularity" : 0})
        return listActsPop
    for act in listActs:
        act_spot = duoActs.get(act, act)
        if isinstance(act_spot,list):
            listActsInListDuos.append(act)
            continue # We'll get and average the duos later.
        followers, popularity, found = get_artist_followers_popularity(act_spot, client_id, client_secret)
        listActsPop.append({'name':act, 'followers' : followers, "popularity" : popularity})
        if not found:
            listActsNotFound.append(act_spot)
    # This logic is to average duos
    for duo in duoActs:
        if duo not in listActsInListDuos:
            continue
        artists = duoActs[duo]
        if not isinstance(artists,list):
            continue
        followers = 0
        popularity = 0
        for artist in artists:
            fol, pop, found = get_artist_followers_popularity(artist, client_id, client_secret)
            followers += fol
            popularity += pop
        followers = int((followers / len(artists)) * duo_mult)
        popularity = int((popularity / len(artists)) * duo_mult)
        listActsPop.append({'name':duo, 'followers' : followers, "popularity" : popularity})
        if not found:
            listActsNotFound.append(act_spot)
    if PRINT_SEARCH_RESULTS and len(listActsNotFound) > 0:
        print(f"Unable to find the following Acts in Spotify: {listActsNotFound}")            
    return listActsPop

def dates_to_act(act, day_info, genre_list, element = 0):
    defaultStart = datetime(2024, 6, 20, 15, 0)
    defaultEnd = datetime(2024, 6, 20, 16, 0)
    if act not in genre_list:
        return STAGE_DEFAULT, defaultStart, defaultEnd, 1
    
    datInfoAct = day_info[act]
    timesTheyPlay = 1
    if isinstance(datInfoAct, list):
        timesTheyPlay = len(datInfoAct)
        datInfoAct = datInfoAct[element]
    stageToSearch = datInfoAct.get("stage")
    if stageToSearch is None:
        stage = None
    else:
        stageToSearch = stageToSearch.upper()
        stage = difflib.get_close_matches(stageToSearch, STAGES, n=1)
    if not stage:
        stage = f"[{stageToSearch}]"  # Returns the stage found, around curly brackets if it couldn't be matched in the list
    else:
        stage = stage[0]
    return stage, datInfoAct["start_time"], datInfoAct["end_time"], timesTheyPlay
    

def slow_sort(popList):
    sortedFully = False
    pop_priority = 0.4  # Sorts the acts combining the followers and popularity and weighting the popularity by this amount.
    maxPop = 0
    maxFol = 0
    for pop in popList:
        maxPop = max(maxPop, pop['popularity'])
        maxFol = max(maxFol, pop['followers'])
    if maxPop == 0:
        return popList
    fol_pop_ratio = int((pop_priority / (1 - pop_priority)) * (maxFol / maxPop))
    print(f"Ratio for prioritizing followers to popularity: {fol_pop_ratio} followers for 1 pop")
    while not sortedFully:
        sortedFully = True
        for i, _ in enumerate(popList):
            if i + 1 == len(popList):
                break
            scoreCurr = (pop_priority * (popList[i]['popularity']/maxPop)) + ((1 - pop_priority) * (popList[i]['followers']/maxFol))
            scoreNext = (pop_priority * (popList[i+1]['popularity']/maxPop)) + ((1 - pop_priority) * (popList[i+1]['followers']/maxFol))
            if scoreNext > scoreCurr:
                sortedFully = False
                popList[i+1], popList[i] = popList[i], popList[i+1]
    return popList
        

def print_md_lst(sorted_listing, genre_list):
    longestNum = 5
    longestAct = 27
    longestPop = 15
    longestFol = 10
    longestStg = 15
    stageDict = {}
    for item in sorted_listing:
        stage, _, _, _ = dates_to_act(item['name'], day_info, genre_list)
        stageDict[item['name']] = stage
        longestAct = max(longestAct, len(item['name']))
        longestPop = max(longestPop, len(str(item['popularity'])))
        longestFol = max(longestFol, len(str(item['followers'])))
        longestStg = max(longestStg, len(stage))
    numTitle = "Num"
    actTitle = "Act"
    popTitle = "Popularity"
    folTitle = "Followers"
    stgTitle = "Stage"
    print(f"| {numTitle: ^{longestNum}} | {actTitle: ^{longestAct}} | {popTitle : ^{longestPop}} | {folTitle : ^{longestFol}} | {stgTitle : ^{longestStg}} |")
    print(f"| {'-' * longestNum} | {'-' * longestAct} | {'-' * longestPop} | {'-' * longestFol} | {'-' * longestStg} |")
    for num, item in enumerate(sorted_listing):
        act = item['name']
        popularity = item['popularity']
        followers = item['followers']
        stage = stageDict[act]
        print(f"| {num + 1 : ^{longestNum}} | {act : ^{longestAct}} | {popularity : ^{longestPop}} | {followers : ^{longestFol}} | {stage : ^{longestStg}} |")


def get_name_to_display(act, i=0):
    actToDisp = unidecode(act)
    actToDisp = strip_word(actToDisp,["The"])
    actToDisp = f"{actToDisp.upper()[:6]: <6}"
    if act == "Yoga":
        actToDisp = f" YOGA{i+1}"
    elif act == "Pretty Lights":
        actToDisp = "PRETYL"
    elif act == "Pretty Pink":
        actToDisp = "PRETYP"
    elif act == "TBA":
        actToDisp = " TBA  "
    elif act == "it's murph":
        actToDisp = "MURPH"
    elif act == "Exclusive: 6 in the Forest":
        actToDisp = "6,nFor"
    return actToDisp

def writeAndPrint(file, text):
    file.write(f"{text}\n")
    if MAKE_ARR_FILE == 2:
        print(text)

def print_array_for_watch(listActs, sorted_listing, day_info, filename, genre_list):
    with open(f'{filename}.txt', 'w') as f:
        artistDateNotFound = []
        writeAndPrint(f, f"// Genre - {genre_source}")
        writeAndPrint(f, f"// Line-up - {URL}")
        writeAndPrint(f, '#include "festival_schedule_face.h"')
        writeAndPrint(f, "")
        totalActs = 0
        listActsPrint = []
        for act in listActs:       
            stage, start, end, timesPerformed = dates_to_act(act, day_info, genre_list, element=0)
            for i in range(timesPerformed):
                stage, start, end, timesPerformed = dates_to_act(act, day_info, genre_list, element=i)
                if stage == STAGE_DEFAULT:
                    artistDateNotFound.append(act)
                actToDisp = get_name_to_display(act, i)
                listActsPrint.append({'dispAct': actToDisp, 'act': act, 'start':start, 'end':end, 'stage':stage})
                totalActs += 1
        listActsPrint = sorted(listActsPrint, key=lambda d: d['dispAct'].lstrip().lower())
        writeAndPrint(f, f"#define NUM_ACTS {totalActs}")
        writeAndPrint(f, "")
        writeAndPrint(f, "const schedule_t festival_acts[NUM_ACTS + 1]=")
        writeAndPrint(f, "{")
        for actData in listActsPrint:     
            writeAndPrint(f, "    {")
            writeAndPrint(f, f'        .artist = "{actData["dispAct"]}",')
            writeAndPrint(f, f'        .stage = {actData["stage"].upper()},')
            writeAndPrint(f, f'        .start_time = {{.unit.year = {actData["start"].year - 2020}, .unit.month = {actData["start"].month}, .unit.day = {actData["start"].day}, .unit.hour = {actData["start"].hour}, .unit.minute = {actData["start"].minute}}},')
            writeAndPrint(f, f'        .end_time = {{.unit.year = {actData["end"].year - 2020}, .unit.month = {actData["end"].month}, .unit.day = {actData["end"].day}, .unit.hour = {actData["end"].hour}, .unit.minute = {actData["end"].minute}}},')
            writeAndPrint(f, f'        .genre = {findGenre(actData["act"])},')
            writeAndPrint(f, f'        .popularity = {get_ranking(sorted_listing, actData["act"])}')
            writeAndPrint(f, "    },")
        writeAndPrint(f, '    [NUM_ACTS]  = { //Fall back')
        writeAndPrint(f, '        .artist = "No Act",')
        writeAndPrint(f, '        .stage = STAGE_COUNT,')
        writeAndPrint(f, '        .start_time = {.unit.year = 0, .unit.month = 0, .unit.day = 0, .unit.hour = 0, .unit.minute = 0},')
        writeAndPrint(f, '        .end_time = {.unit.year = 63, .unit.month = 15, .unit.day = 31, .unit.hour = 31, .unit.minute = 63},')
        writeAndPrint(f, '        .genre = GENRE_COUNT,')
        writeAndPrint(f, '        .popularity = 0')
        writeAndPrint(f, '    }')
        writeAndPrint(f, '};')
    
    if PRINT_SEARCH_RESULTS and artistDateNotFound:
        print(f"\nFAILED TO FIND DATE INFO FOR {artistDateNotFound}\n")


if __name__ == "__main__":
    html_str = test_content if USE_TEST_ARR else get_url_content(URL)
    day_info = get_html_data(html_str)
    day_info = {key.split(" (")[0]: value for key, value in day_info.items()}
        
    listActs = []
    for key in dicto:
        for i in dicto[key]:
            listActs.append(i)
    listActs = sorted(listActs, key=lambda x: x.lower().replace("the ",""))
    in_genre_list = []
    not_in_genre_list = []

    day_info_keys = day_info.keys()

    for key in list(day_info_keys):
        if key in forClashFinder.keys():
            val = forClashFinder[key]
            day_info[val] = day_info.pop(key)
    
    for actDate in list(day_info_keys):
        actInDates = difflib.get_close_matches(actDate.upper(), list(map(lambda x: x.upper(), listActs)), n=1)
        if actInDates:
            actInDates = actInDates[0]
            for key1 in listActs:
                if key1.upper() == actInDates:
                    day_info[key1] = day_info.pop(actDate)
                    in_genre_list.append(key1)
                    break
        else:
            not_in_genre_list.append(actDate)
           
    in_genre_list = sorted(in_genre_list, key=lambda x: x.lower().replace("the ", "") if x[0].startswith("the ") else x[0].lower())
    not_in_genre_list = sorted(not_in_genre_list, key=lambda x: x.lower().replace("the ", "") if x[0].startswith("the ") else x[0].lower())
    listActsPop = testPop if USE_TEST_ARR else getFullArray(listActs)
    listActsPopMissing = [] if USE_TEST_ARR else getFullArray(not_in_genre_list)

    if SORT_POP_BY_FOLLOWERS:  
        sortKey = lambda x: (x['followers'])
        sorted_listing = sorted(listActsPop, key=sortKey, reverse=True)
        sorted_listing_missing = sorted(listActsPopMissing, key=sortKey, reverse=True)
    else:
        sortKey = lambda x: (x['popularity'], x['followers']) # Sort by Spotify popularity w/ followers being the tie-breaker
        sorted_listing = sorted(listActsPop, key=sortKey, reverse=True)
        sorted_listing = slow_sort(sorted_listing)
        sorted_listing_missing = sorted(listActsPopMissing, key=sortKey, reverse=True)
        sorted_listing_missing = slow_sort(sorted_listing_missing)
    
    for i, artist in enumerate(sorted_listing):
        artist['overall'] = i + 1

    
    for i, artist in enumerate(sorted_listing_missing):
        artist['overall'] = i + 1 
        
    if PRINT_RANKINGs: 
        print_md_lst(sorted_listing, in_genre_list)
        if sorted_listing_missing:
            print("\r\n\r\nAND THESE WERE MISSING")
            print_md_lst(sorted_listing_missing, not_in_genre_list)
        
    if MAKE_ARR_FILE:
        print_array_for_watch(listActs, sorted_listing, day_info ,"festival_schedule_arr", in_genre_list)
        if sorted_listing_missing:
            print_array_for_watch(not_in_genre_list, sorted_listing_missing, day_info, "missing_festival_schedule_arr", not_in_genre_list)