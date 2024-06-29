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
STAGES = [ "RANCH_ARENA", "SHERWOOD_COURT", "TRIPOLEE", "CAROUSEL_CLUB", "OBSERVATORY", "HONEYCOMB"]
STAGE_DEFAULT = "NO_STAGE"
URL = "https://clashfinder.com/m/elecfor24/"

junNine = [{'name': 'ACRAZE', 'followers': 127991, 'popularity': 63}, {'name': 'AK Sports', 'followers': 3347, 'popularity': 19}, 
           {'name': 'ALLEYCVT', 'followers': 37270, 'popularity': 41}, {'name': 'ATLiens', 'followers': 99093, 'popularity': 45}, 
           {'name': 'AYYBO', 'followers': 53574, 'popularity': 56}, {'name': 'Baggi', 'followers': 4171, 'popularity': 20}, 
           {'name': 'Barclay Crenshaw', 'followers': 31513, 'popularity': 35}, {'name': 'Ben Böhmer', 'followers': 499334, 'popularity': 63}, 
           {'name': 'Black Tiger Sex Machine', 'followers': 167574, 'popularity': 46}, {'name': 'Blastoyz', 'followers': 112730, 'popularity': 44}, 
           {'name': 'Boogie T', 'followers': 90700, 'popularity': 43}, {'name': 'Boogie T.rio', 'followers': 19383, 'popularity': 28}, 
           {'name': 'Brandi Cyrus', 'followers': 0, 'popularity': 0}, {'name': 'Calussa', 'followers': 8695, 'popularity': 45}, 
           {'name': 'CanaBliss', 'followers': 13543, 'popularity': 34}, {'name': 'Cannons', 'followers': 363542, 'popularity': 60}, 
           {'name': 'Caspa', 'followers': 68386, 'popularity': 31}, {'name': 'Cassian', 'followers': 57359, 'popularity': 53}, 
           {'name': 'Chaos in the CBD', 'followers': 102272, 'popularity': 47}, {'name': 'Charlotte De Witte', 'followers': 941867, 'popularity': 59}, 
           {'name': 'Chase & Status', 'followers': 921270, 'popularity': 68}, {'name': 'Coco & Breezy', 'followers': 20356, 'popularity': 45}, 
           {'name': 'Cuco', 'followers': 1059, 'popularity': 32}, {'name': 'Dave Yaden', 'followers': 668, 'popularity': 5}, 
           {'name': 'Dimension', 'followers': 127706, 'popularity': 61}, {'name': 'Dirtwire', 'followers': 97097, 'popularity': 42}, 
           {'name': 'The Disco Biscuits', 'followers': 86290, 'popularity': 33}, {'name': "Dixon's Violin", 'followers': 4937, 'popularity': 11}, 
           {'name': 'DJ Brownie', 'followers': 248, 'popularity': 5}, {'name': 'DJ Susan', 'followers': 32295, 'popularity': 32}, 
           {'name': 'DRAMA', 'followers': 144295, 'popularity': 56}, {'name': 'Dumpstaphunk', 'followers': 52008, 'popularity': 30}, 
           {'name': 'Eggy', 'followers': 10710, 'popularity': 28}, {'name': 'Emo Nite', 'followers': 0, 'popularity': 0}, 
           {'name': 'Equanimous', 'followers': 49140, 'popularity': 46}, {'name': 'Excision', 'followers': 728513, 'popularity': 59}, 
           {'name': 'Exclusive 6 In The Forest Celebration', 'followers': 0, 'popularity': 0}, {'name': 'G jones', 'followers': 91272, 'popularity': 37}, 
           {'name': 'Goodboys', 'followers': 67202, 'popularity': 66}, {'name': 'Green Velvet', 'followers': 231089, 'popularity': 52}, 
           {'name': 'H&RRY', 'followers': 0, 'popularity': 0}, {'name': 'Hamdi', 'followers': 53651, 'popularity': 55}, 
           {'name': 'Hiatus Kaiyote', 'followers': 629430, 'popularity': 56}, {'name': 'INZO', 'followers': 154911, 'popularity': 51}, 
           {'name': "it's murph", 'followers': 47756, 'popularity': 58}, {'name': 'Ivy Lab', 'followers': 85173, 'popularity': 40}, 
           {'name': 'Jason Leech', 'followers': 7228, 'popularity': 26}, {'name': 'Jjuujjuu', 'followers': 9052, 'popularity': 21}, 
           {'name': 'John Summit', 'followers': 304278, 'popularity': 71}, {'name': 'Juelz', 'followers': 31279, 'popularity': 43}, 
           {'name': 'Kallaghan', 'followers': 517, 'popularity': 16}, {'name': 'Kenny Beats', 'followers': 204558, 'popularity': 61}, 
           {'name': 'Kiltro', 'followers': 34151, 'popularity': 42}, {'name': 'Knock2', 'followers': 94524, 'popularity': 57}, 
           {'name': 'Layton Giordani', 'followers': 76037, 'popularity': 57}, {'name': 'Le Youth', 'followers': 113548, 'popularity': 52}, 
           {'name': 'League of Sound Disciples', 'followers': 0, 'popularity': 0}, {'name': 'Lettuce', 'followers': 212698, 'popularity': 41}, 
           {'name': 'LEVEL UP', 'followers': 36418, 'popularity': 44}, {'name': 'levity', 'followers': 35512, 'popularity': 45}, 
           {'name': 'Libianca', 'followers': 468493, 'popularity': 64}, {'name': 'Little stranger', 'followers': 57325, 'popularity': 49}, 
           {'name': 'LP Giobbi', 'followers': 75790, 'popularity': 59}, {'name': 'Lucii', 'followers': 67428, 'popularity': 42}, 
           {'name': 'Ludacris', 'followers': 2966337, 'popularity': 75}, {'name': 'LYNY', 'followers': 14540, 'popularity': 42}, 
           {'name': "Maddy O'Neal", 'followers': 18515, 'popularity': 35}, {'name': 'Major League Djz', 'followers': 850784, 'popularity': 49}, 
           {'name': 'marsh', 'followers': 70606, 'popularity': 51}, {'name': 'Mascolo', 'followers': 2373, 'popularity': 37}, 
           {'name': 'MASONIC', 'followers': 102, 'popularity': 0}, {'name': 'Matroda', 'followers': 126927, 'popularity': 57}, 
           {'name': 'Mau P', 'followers': 103816, 'popularity': 62}, {'name': 'Michaël Brun', 'followers': 49231, 'popularity': 49}, 
           {'name': 'Mojave Grey', 'followers': 3796, 'popularity': 25}, {'name': 'Moontricks', 'followers': 58681, 'popularity': 44}, 
           {'name': 'NEIL FRANCES', 'followers': 210548, 'popularity': 64}, {'name': 'Nelly Furtado', 'followers': 3882375, 'popularity': 75}, 
           {'name': 'Neoma', 'followers': 12670, 'popularity': 27}, {'name': 'ODEN & Fatzo', 'followers': 37472, 'popularity': 56}, 
           {'name': 'Only fire', 'followers': 41241, 'popularity': 38}, {'name': 'PAPERWATER', 'followers': 1449, 'popularity': 20}, 
           {'name': 'Peach Tree Rascals', 'followers': 228444, 'popularity': 54}, {'name': 'Politik', 'followers': 330, 'popularity': 6}, 
           {'name': 'Polyrhythmics', 'followers': 28934, 'popularity': 31}, {'name': 'Pretty Lights', 'followers': 559572, 'popularity': 49}, 
           {'name': 'Pretty Pink', 'followers': 45668, 'popularity': 47}, {'name': 'Próxima Parada', 'followers': 66700, 'popularity': 49}, 
           {'name': 'Ranger Trucco', 'followers': 10676, 'popularity': 32}, {'name': 'Rawayana', 'followers': 665608, 'popularity': 64}, 
           {'name': 'Rayben', 'followers': 42199, 'popularity': 40}, {'name': 'Redrum', 'followers': 2622, 'popularity': 13}, 
           {'name': 'Sammy Virji', 'followers': 109855, 'popularity': 61}, {'name': 'Sara Landry', 'followers': 201195, 'popularity': 52}, 
           {'name': 'Seven lions', 'followers': 488549, 'popularity': 58}, {'name': 'Shae District', 'followers': 2679, 'popularity': 15}, 
           {'name': 'Shaun Ross', 'followers': 5632, 'popularity': 41}, {'name': 'Slayyyter', 'followers': 398930, 'popularity': 53}, 
           {'name': 'The String Cheese Incident', 'followers': 226925, 'popularity': 41}, {'name': 'Subtronics', 'followers': 309365, 'popularity': 61}, 
           {'name': 'Sultan + Shepard', 'followers': 126480, 'popularity': 55}, {'name': 'Super Future', 'followers': 13470, 'popularity': 28}, 
           {'name': 'Swaylo', 'followers': 3, 'popularity': 0}, {'name': 'Thought process', 'followers': 8411, 'popularity': 29}, 
           {'name': 'Tripp St.', 'followers': 14955, 'popularity': 29}, {'name': 'TSHA', 'followers': 71923, 'popularity': 49}, 
           {'name': "Umphrey's McGee", 'followers': 201758, 'popularity': 41}, {'name': 'Unusual demont', 'followers': 43679, 'popularity': 41}, 
           {'name': 'venbee', 'followers': 79458, 'popularity': 55}, {'name': 'Vini Vici', 'followers': 528186, 'popularity': 62}, 
           {'name': 'Westend', 'followers': 47387, 'popularity': 57}, {'name': 'Whyte Fang', 'followers': 15233, 'popularity': 28}, 
           {'name': 'Will Clarke', 'followers': 50419, 'popularity': 42}, {'name': 'Wooli', 'followers': 113411, 'popularity': 56}, 
           {'name': 'Yoga', 'followers': 0, 'popularity': 0}, {'name': 'Zen Selekta', 'followers': 3820, 'popularity': 16}, 
           {'name': 'Gigantic NGHTMRE', 'followers': 432631, 'popularity': 55}, {'name': 'EVERYTHING ALWAYS', 'followers': 426118, 'popularity': 72}, 
           {'name': 'LSZEE', 'followers': 202854, 'popularity': 53}, {'name': 'VNSSA B2B Nala', 'followers': 16650, 'popularity': 37}, 
           {'name': 'Hyperbeam', 'followers': 56415, 'popularity': 56}]

test_content = """
<div class="day" data-date="1718859600" data-first-start="52200" data-last-stop="93600"><h2 class="dayName">Thurs&#8203;day 20th June</h2>
<div class="stage"><h3 class="stageName">Ranch Arena</h3>
<div class="actLists"><div class="act id-brandi-1 " data-id="brandi-1" data-start-time="1718913600000" data-end-time="1718917200000" ><span class="actTime">15:00 - 16:00</span><span class="actNm">Brandi Cyrus</span></div><div class="act id-westen-1 " data-id="westen-1" data-start-time="1718919000000" data-end-time="1718922600000" ><span class="actTime">16:30 - 17:30</span><span class="actNm">Westend</span></div><div class="act id-drama-1 " data-id="drama-1" data-start-time="1718924400000" data-end-time="1718928000000" data-mbid="c3505299-5cb9-4a30-a7c8-e74d0aa3e1b0" ><span class="actTime">18:00 - 19:00</span><span class="actNm">Drama</span></div><div class="act id-greenv-1 " data-id="greenv-1" data-start-time="1718930700000" data-end-time="1718935200000" data-mbid="e425b041-c28a-4ae8-9d5c-997890433cd4" ><span class="actTime">19:45 - 21:00</span><span class="actNm">Green Velvet</span></div><div class="act id-nellyf-1 " data-id="nellyf-1" data-start-time="1718937000000" data-end-time="1718940600000" data-mbid="13655113-cd16-4b43-9dca-cadbbf26ee05" ><span class="actTime">21:30 - 22:30</span><span class="actNm">Nelly Furtado</span></div><div class="act id-everyt-1 " data-id="everyt-1" data-start-time="1718944200000" data-end-time="1718949600000" ><span class="actTime">23:30 - 01:00</span><span class="actNm">Everything Always</span></div></div>
</div><div class="stage"><h3 class="stageName">Sherwood Court</h3>
<div class="actLists"><div class="act id-maddyo-1 " data-id="maddyo-1" data-start-time="1718920800000" data-end-time="1718924400000" ><span class="actTime">17:00 - 18:00</span><span class="actNm">Maddy O'Neal</span></div><div class="act id-eggy-1 " data-id="eggy-1" data-start-time="1718927100000" data-end-time="1718931600000" data-mbid="ba0b9dc6-bd61-42c7-a28f-5179b1c04391" ><span class="actTime">18:45 - 20:00</span><span class="actNm">Eggy</span></div><div class="act id-discob-1 " data-id="discob-1" data-start-time="1718937000000" data-end-time="1718944200000" data-mbid="4e43632a-afef-4b54-a822-26311110d5c5" ><span class="actTime">21:30 - 23:30</span><span class="actNm">The Disco Biscuits</span></div><div class="act id-knock2-1 " data-id="knock2-1" data-start-time="1718948700000" data-end-time="1718953200000" ><span class="actTime">00:45 - 02:00</span><span class="actNm">Knock 2</span></div></div>
</div><div class="stage"><h3 class="stageName">Tripolee</h3>
<div class="actLists"><div class="act id-maeson-1 " data-id="maeson-1" data-start-time="1718911800000" data-end-time="1718915400000" ><span class="actTime">14:30 - 15:30</span><span class="actNm">Maesonic</span></div><div class="act id-chaosi-1 " data-id="chaosi-1" data-start-time="1718919000000" data-end-time="1718923500000" data-mbid="ae534b5f-95e5-40d9-9ce0-75e4b777cad1" ><span class="actTime">16:30 - 17:45</span><span class="actNm">Chaos in the CBD</span></div><div class="act id-vnssab-1 " data-id="vnssab-1" data-start-time="1718923500000" data-end-time="1718928000000" ><span class="actTime">17:45 - 19:00</span><span class="actNm">VNSSA b2b Nala</span></div><div class="act id-tsha-1 " data-id="tsha-1" data-start-time="1718928000000" data-end-time="1718932500000" data-mbid="0e3ca88b-910e-4daa-97db-68f3722edd5f" ><span class="actTime">19:00 - 20:15</span><span class="actNm">TSHA</span></div><div class="act id-sultan-1 " data-id="sultan-1" data-start-time="1718932500000" data-end-time="1718937000000" data-mbid="30ae649d-142a-4a97-b38d-bd02efebf4b0" ><span class="actTime">20:15 - 21:30</span><span class="actNm">Sultan + Shepard</span></div><div class="act id-cassia-1 " data-id="cassia-1" data-start-time="1718937000000" data-end-time="1718941500000" ><span class="actTime">21:30 - 22:45</span><span class="actNm">Cassian</span></div><div class="act id-youth-1 " data-id="youth-1" data-start-time="1718941500000" data-end-time="1718946000000" data-mbid="60584cf9-69a4-48e8-929a-935e7f8d74b3" ><span class="actTime">22:45 - 00:00</span><span class="actNm">Le Youth</span></div><div class="act id-benboh-1 " data-id="benboh-1" data-start-time="1718946000000" data-end-time="1718951400000" ><span class="actTime">00:00 - 01:30</span><span class="actNm">Ben Bohmer</span></div></div>
</div><div class="stage"><h3 class="stageName">Carousel Club</h3>
<div class="actLists"><div class="act id-dumpst-1 " data-id="dumpst-1" data-start-time="1718924400000" data-end-time="1718928900000" ><span class="actTime">18:00 - 19:15</span><span class="actNm">Dumpstaphunk</span></div><div class="act id-lettuc-1 " data-id="lettuc-1" data-start-time="1718930700000" data-end-time="1718935200000" data-mbid="e88313e2-22f6-4f6d-9656-6d2ad20ea415" ><span class="actTime">19:45 - 21:00</span><span class="actNm">Lettuce</span></div><div class="act id-goodbo-1 " data-id="goodbo-1" data-start-time="1718939700000" data-end-time="1718944200000" ><span class="actTime">22:15 - 23:30</span><span class="actNm">Goodboys</span></div><div class="act id-emonit-1 " data-id="emonit-1" data-start-time="1718947800000" data-end-time="1718953200000" ><span class="actTime">00:30 - 02:00</span><span class="actNm">Emo Nite</span></div></div>
</div><div class="stage"><h3 class="stageName">The Observatory</h3>
<div class="actLists"><div class="act id-dixons-1 " data-id="dixons-1" data-start-time="1718919000000" data-end-time="1718922600000" data-mbid="2cc0c42d-a27a-43fe-bee4-ea12b8572322" ><span class="actTime">16:30 - 17:30</span><span class="actNm">Dixon's Violin</span></div><div class="act id-redrum-1 " data-id="redrum-1" data-start-time="1718924400000" data-end-time="1718928000000" data-mbid="885fb011-4334-483b-954a-6b931eb3f125" ><span class="actTime">18:00 - 19:00</span><span class="actNm">Redrum</span></div><div class="act id-zensel-1 " data-id="zensel-1" data-start-time="1718928000000" data-end-time="1718931600000" ><span class="actTime">19:00 - 20:00</span><span class="actNm">Zen Selecta</span></div><div class="act id-superf-1 " data-id="superf-1" data-start-time="1718931600000" data-end-time="1718935200000" ><span class="actTime">20:00 - 21:00</span><span class="actNm">Super Future</span></div><div class="act id-tripps-1 " data-id="tripps-1" data-start-time="1718935200000" data-end-time="1718938800000" data-mbid="253df878-ce2a-496c-b568-762ba44493cc" ><span class="actTime">21:00 - 22:00</span><span class="actNm">Tripp St.</span></div><div class="act id-zingar-1 " data-id="zingar-1" data-start-time="1718938800000" data-end-time="1718942400000" data-mbid="6d9e2ce3-5557-469c-a99d-ec2d0b9be7f0" ><span class="actTime">22:00 - 23:00</span><span class="actNm">Zingara</span></div><div class="act id-tba-1 " data-id="tba-1" data-start-time="1718942400000" data-end-time="1718946300000" data-mbid="6ee649c3-b301-474a-a98f-527ef2cf064a" ><span class="actTime">23:00 - 00:05</span><span class="actNm">TBA</span></div><div class="act id-marsh-1 " data-id="marsh-1" data-start-time="1718947800000" data-end-time="1718952300000" ><span class="actTime">00:30 - 01:45</span><span class="actNm">Marsh</span></div></div>
</div><div class="stage"><h3 class="stageName">Honeycomb</h3>
<div class="actLists"><div class="act id-hrry-1 " data-id="hrry-1" data-start-time="1718915400000" data-end-time="1718919000000" ><span class="actTime">15:30 - 16:30</span><span class="actNm">H&RRY</span></div><div class="act id-moontr-1 " data-id="moontr-1" data-start-time="1718920800000" data-end-time="1718924400000" ><span class="actTime">17:00 - 18:00</span><span class="actNm">Moontricks</span></div><div class="act id-equani-1 " data-id="equani-1" data-start-time="1718925300000" data-end-time="1718928600000" ><span class="actTime">18:15 - 19:10</span><span class="actNm">Equanimous</span></div><div class="act id-levity-1 " data-id="levity-1" data-start-time="1718929800000" data-end-time="1718933400000" ><span class="actTime">19:30 - 20:30</span><span class="actNm">Levity</span></div><div class="act id-swaylo-1 " data-id="swaylo-1" data-start-time="1718935200000" data-end-time="1718938800000" ><span class="actTime">21:00 - 22:00</span><span class="actNm">SWAYLO</span></div><div class="act id-paperw-1 " data-id="paperw-1" data-start-time="1718940600000" data-end-time="1718944200000" ><span class="actTime">22:30 - 23:30</span><span class="actNm">Paperwater</span></div><div class="act id-politi-1 " data-id="politi-1" data-start-time="1718945100000" data-end-time="1718949600000" ><span class="actTime">23:45 - 01:00</span><span class="actNm">Politik</span></div><div class="act id-brandi-2 " data-id="brandi-2" data-start-time="1718949600000" data-end-time="1718953200000" ><span class="actTime">01:00 - 02:00</span><span class="actNm">Brandi Cyrus</span></div></div>
</div></div><div class="day" data-date="1718946000" data-first-start="43200" data-last-stop="99000"><h2 class="dayName">Fri&#8203;day 21st June</h2>
<div class="stage"><h3 class="stageName">Ranch Arena</h3>
<div class="actLists"><div class="act id-ludacr-1 " data-id="ludacr-1" data-start-time="1719014400000" data-end-time="1719018900000" ><span class="actTime">19:00 - 20:15</span><span class="actNm">Ludacris</span></div><div class="act id-string-1 " data-id="string-1" data-start-time="1719021600000" data-end-time="1719028800000" data-mbid="cff95140-6d57-498a-8834-10eb72865b29" ><span class="actTime">21:00 - 23:00</span><span class="actNm">The String Cheese Incident</span></div><div class="act id-pretty-1 " data-id="pretty-1" data-start-time="1719032400000" data-end-time="1719039600000" data-mbid="3a07764c-7cc5-42e9-8205-3de7532f4771" ><span class="actTime">00:00 - 02:00</span><span class="actNm">Pretty Lights</span></div></div>
</div><div class="stage"><h3 class="stageName">Sherwood Court</h3>
<div class="actLists"><div class="act id-rawaya-1 " data-id="rawaya-1" data-start-time="1719011700000" data-end-time="1719016200000" ><span class="actTime">18:15 - 19:30</span><span class="actNm">Rawayana</span></div><div class="act id-cannon-1 " data-id="cannon-1" data-start-time="1719018900000" data-end-time="1719023400000" ><span class="actTime">20:15 - 21:30</span><span class="actNm">Cannons</span></div><div class="act id-whytef-1 " data-id="whytef-1" data-start-time="1719027900000" data-end-time="1719031500000" data-mbid="6273570e-518b-44e7-80ef-a9280c79b3bf" ><span class="actTime">22:45 - 23:45</span><span class="actNm">Whyte Fang</span></div><div class="act id-sevenl-1 " data-id="sevenl-1" data-start-time="1719039600000" data-end-time="1719043200000" data-mbid="75c016da-48e4-4992-8a10-b7128189b272" ><span class="actTime">02:00 - 03:00</span><span class="actNm">Seven Lions</span></div></div>
</div><div class="stage"><h3 class="stageName">Tripolee</h3>
<div class="actLists"><div class="act id-yoga-1 " data-id="yoga-1" data-start-time="1718989200000" data-end-time="1718993700000" data-mbid="409b911e-1496-4238-a63a-25bcefe0f872" ><span class="actTime">12:00 - 13:15</span><span class="actNm">Yoga</span></div><div class="act id-canabl-1 " data-id="canabl-1" data-start-time="1719003600000" data-end-time="1719007200000" data-mbid="96b74b9c-6adb-4448-8bdf-1a55666de0d3" ><span class="actTime">16:00 - 17:00</span><span class="actNm">Canabliss</span></div><div class="act id-alleyc-1 " data-id="alleyc-1" data-start-time="1719007200000" data-end-time="1719011700000" data-mbid="2590b6d4-648a-4092-9850-f614d6df51ca" ><span class="actTime">17:00 - 18:15</span><span class="actNm">Alleycvt</span></div><div class="act id-levelu-1 " data-id="levelu-1" data-start-time="1719011700000" data-end-time="1719015300000" ><span class="actTime">18:15 - 19:15</span><span class="actNm">Level Up</span></div><div class="act id-ivylab-1 " data-id="ivylab-1" data-start-time="1719015300000" data-end-time="1719019800000" data-mbid="05a8fca6-3178-4f95-ad82-d325bc6102fe" ><span class="actTime">19:15 - 20:30</span><span class="actNm">Ivy Lab</span></div><div class="act id-caspa-1 " data-id="caspa-1" data-start-time="1719019800000" data-end-time="1719023400000" data-mbid="dc9b8085-fe1e-4b83-8d41-6dd8d295513c" ><span class="actTime">20:30 - 21:30</span><span class="actNm">Caspa</span></div><div class="act id-boogie-1 " data-id="boogie-1" data-start-time="1719023400000" data-end-time="1719027000000" data-mbid="906b8f09-9e3b-4063-ba9e-5ce1f1a45227" ><span class="actTime">21:30 - 22:30</span><span class="actNm">Boogie T</span></div><div class="act id-dimens-1 " data-id="dimens-1" data-start-time="1719027000000" data-end-time="1719031500000" data-mbid="50b41344-7a92-4e53-8c93-f38c66cf68f3" ><span class="actTime">22:30 - 23:45</span><span class="actNm">Dimension</span></div><div class="act id-atlien-1 " data-id="atlien-1" data-start-time="1719031500000" data-end-time="1719035100000" ><span class="actTime">23:45 - 00:45</span><span class="actNm">ATLiens</span></div><div class="act id-wooli-1 " data-id="wooli-1" data-start-time="1719035100000" data-end-time="1719039000000" ><span class="actTime">00:45 - 01:50</span><span class="actNm">Wooli</span></div><div class="act id-blackt-1 " data-id="blackt-1" data-start-time="1719039600000" data-end-time="1719044100000" data-mbid="8a672f30-4ed6-4fb4-9b8a-4f28e1d1be1c" ><span class="actTime">02:00 - 03:15</span><span class="actNm">Black Tiger Sex Machine</span></div></div>
</div><div class="stage"><h3 class="stageName">Carousel Club</h3>
<div class="actLists"><div class="act id-neoma-1 " data-id="neoma-1" data-start-time="1719009000000" data-end-time="1719012600000" ><span class="actTime">17:30 - 18:30</span><span class="actNm">Neoma</span></div><div class="act id-jjuujj-1 " data-id="jjuujj-1" data-start-time="1719014400000" data-end-time="1719018000000" data-mbid="95a895f4-760c-40f9-a66d-94f9c3eb22b6" ><span class="actTime">19:00 - 20:00</span><span class="actNm">jjuujjuu</span></div><div class="act id-djsusa-1 " data-id="djsusa-1" data-start-time="1719019800000" data-end-time="1719023400000" ><span class="actTime">20:30 - 21:30</span><span class="actNm">DJ Susan</span></div><div class="act id-odenfa-1 " data-id="odenfa-1" data-start-time="1719025200000" data-end-time="1719029700000" data-mbid="70768b77-fa4f-4ce5-afc5-8cf71129cadc" ><span class="actTime">22:00 - 23:15</span><span class="actNm">Oden & Fatzo</span></div><div class="act id-itsmur-1 " data-id="itsmur-1" data-start-time="1719039600000" data-end-time="1719044100000" ><span class="actTime">02:00 - 03:15</span><span class="actNm">It's Murph</span></div></div>        
</div><div class="stage"><h3 class="stageName">The Observatory</h3>
<div class="actLists"><div class="act id-baggi-1 " data-id="baggi-1" data-start-time="1719015300000" data-end-time="1719018900000" data-mbid="15a25819-cc15-44e0-aec4-1cb717e55812" ><span class="actTime">19:15 - 20:15</span><span class="actNm">Baggi</span></div><div class="act id-swaylo-2 " data-id="swaylo-2" data-start-time="1719018900000" data-end-time="1719023400000" ><span class="actTime">20:15 - 21:30</span><span class="actNm">SWAYLO</span></div><div class="act id-pretty1-1 " data-id="pretty1-1" data-start-time="1719023400000" data-end-time="1719027900000" ><span class="actTime">21:30 - 22:45</span><span class="actNm">Pretty Pink</span></div><div class="act id-vinivi-1 " data-id="vinivi-1" data-start-time="1719027900000" data-end-time="1719033300000" data-mbid="14276a83-d21d-41ab-b809-09b494645645" ><span class="actTime">22:45 - 00:15</span><span class="actNm">Vini Vici</span></div><div class="act id-blasto-1 " data-id="blasto-1" data-start-time="1719033300000" data-end-time="1719038700000" data-mbid="cf1d0ddf-9794-4c7b-9758-a43b261f5a97" ><span class="actTime">00:15 - 01:45</span><span class="actNm">Blastoyz</span></div><div class="act id-layton-1 " data-id="layton-1" data-start-time="1719039600000" data-end-time="1719044100000" data-mbid="81f494b2-bd4b-486c-aae5-8c789165d14c" ><span class="actTime">02:00 - 03:15</span><span class="actNm">Layton Giordani</span></div></div>
</div><div class="stage"><h3 class="stageName">Honeycomb</h3>
<div class="actLists"><div class="act id-humani-1 " data-id="humani-1" data-start-time="1718998200000" data-end-time="1719001800000" ><span class="actTime">14:30 - 15:30</span><span class="actNm">Humanity Circle</span></div><div class="act id-rumble-1 " data-id="rumble-1" data-start-time="1719003900000" data-end-time="1719010800000" ><span class="actTime">16:05 - 18:00</span><span class="actNm">Rumble in the Bumble</span></div><div class="act id-boogie1-1 " data-id="boogie1-1" data-start-time="1719014400000" data-end-time="1719018900000" data-mbid="52a2a50e-6a46-42be-9131-071cef564644" ><span class="actTime">19:00 - 20:15</span><span class="actNm">Boogie T.Rio</span></div><div class="act id-westen-2 " data-id="westen-2" data-start-time="1719020700000" data-end-time="1719025200000" ><span class="actTime">20:45 - 22:00</span><span class="actNm">Westend</span></div><div class="act id-sultan-2 " data-id="sultan-2" data-start-time="1719027000000" data-end-time="1719031500000" data-mbid="30ae649d-142a-4a97-b38d-bd02efebf4b0" ><span class="actTime">22:30 - 23:45</span><span class="actNm">Sultan + Shepard</span></div><div class="act id-djsusa-2 " data-id="djsusa-2" data-start-time="1719033300000" data-end-time="1719036900000" ><span class="actTime">00:15 - 01:15</span><span class="actNm">DJ Susan</span></div><div class="act id-djbrow-1 " data-id="djbrow-1" data-start-time="1719038700000" data-end-time="1719042900000" ><span class="actTime">01:45 - 02:55</span><span class="actNm">DJ Brownie</span></div></div>
</div></div><div class="day" data-date="1719032400" data-first-start="43200" data-last-stop="102600"><h2 class="dayName">Sat&#8203;urday 22nd June</h2>
<div class="stage"><h3 class="stageName">Ranch Arena</h3>
<div class="actLists"><div class="act id-kennyb-1 " data-id="kennyb-1" data-start-time="1719095400000" data-end-time="1719099900000" data-mbid="22ba00db-f132-4f3c-ab06-4ddaa4cc066b" ><span class="actTime">17:30 - 18:45</span><span class="actNm">Kenny Beats</span></div><div class="act id-string-2 " data-id="string-2" data-start-time="1719102600000" data-end-time="1719117000000" data-mbid="cff95140-6d57-498a-8834-10eb72865b29" ><span class="actTime">19:30 - 23:30</span><span class="actNm">The String Cheese Incident</span></div><div class="act id-subtro-1 " data-id="subtro-1" data-start-time="1719119700000" data-end-time="1719125100000" data-mbid="f576b153-85ea-4538-b28d-51c9552b50dd" ><span class="actTime">00:15 - 01:45</span><span class="actNm">Subtronics</span></div></div>
</div><div class="stage"><h3 class="stageName">Sherwood Court</h3>
<div class="actLists"><div class="act id-polyrh-1 " data-id="polyrh-1" data-start-time="1719094500000" data-end-time="1719099000000" ><span class="actTime">17:15 - 18:30</span><span class="actNm">Polyrhythmics</span></div><div class="act id-juelz-1 " data-id="juelz-1" data-start-time="1719101700000" data-end-time="1719105300000" ><span class="actTime">19:15 - 20:15</span><span class="actNm">Juelz</span></div><div class="act id-barcla-1 " data-id="barcla-1" data-start-time="1719109800000" data-end-time="1719113400000" data-mbid="c74ae9aa-37e4-460e-a91a-36914a670691" ><span class="actTime">21:30 - 22:30</span><span class="actNm">Barclay Crenshaw</span></div><div class="act id-gjones-1 " data-id="gjones-1" data-start-time="1719115200000" data-end-time="1719119700000" data-mbid="20bb2a85-e6ab-42e2-bfa8-ec048b60bbdb" ><span class="actTime">23:00 - 00:15</span><span class="actNm">G Jones</span></div><div class="act id-lszeec-1 " data-id="lszeec-1" data-start-time="1719125100000" data-end-time="1719129600000" ><span class="actTime">01:45 - 03:00</span><span class="actNm">LSZEE (CloZee + LSDream)</span></div><div class="act id-unusua-2 " data-id="unusua-2" data-start-time="1719132300000" data-end-time="1719135000000" ><span class="actTime">03:45 - 04:30</span><span class="actNm">Unusual Demont</span></div></div>       
</div><div class="stage"><h3 class="stageName">Tripolee</h3>
<div class="actLists"><div class="act id-yoga-2 " data-id="yoga-2" data-start-time="1719075600000" data-end-time="1719079800000" data-mbid="409b911e-1496-4238-a63a-25bcefe0f872" ><span class="actTime">12:00 - 13:10</span><span class="actNm">Yoga</span></div><div class="act id-cardio-1 " data-id="cardio-1" data-start-time="1719093600000" data-end-time="1719097200000" ><span class="actTime">17:00 - 18:00</span><span class="actNm">Cardio</span></div><div class="act id-ranger-1 " data-id="ranger-1" data-start-time="1719097200000" data-end-time="1719101700000" data-mbid="39de9c60-14bb-4148-a29e-08df6303476a" ><span class="actTime">18:00 - 19:15</span><span class="actNm">Ranger Trucco</span></div><div class="act id-luci-1 " data-id="luci-1" data-start-time="1719101700000" data-end-time="1719106200000" ><span class="actTime">19:15 - 20:30</span><span class="actNm">Luci</span></div><div class="act id-itsmur-2 " data-id="itsmur-2" data-start-time="1719106200000" data-end-time="1719110700000" ><span class="actTime">20:30 - 21:45</span><span class="actNm">It's Murph</span></div><div class="act id-willcl-1 " data-id="willcl-1" data-start-time="1719110700000" data-end-time="1719115200000" ><span class="actTime">21:45 - 23:00</span><span class="actNm">Will Clarke</span></div><div class="act id-sammyv-1 " data-id="sammyv-1" data-start-time="1719115200000" data-end-time="1719119700000" data-mbid="e23abc5f-478a-4594-ad18-b3805b3c5316" ><span class="actTime">23:00 - 00:15</span><span class="actNm">Sammy Virji</span></div><div class="act id-maup-1 " data-id="maup-1" data-start-time="1719119700000" data-end-time="1719125100000" ><span class="actTime">00:15 - 01:45</span><span class="actNm">Mau P</span></div><div class="act id-johnsu-1 " data-id="johnsu-1" data-start-time="1719125100000" data-end-time="1719130500000" ><span class="actTime">01:45 - 03:15</span><span class="actNm">John Summit</span></div></div>
</div><div class="stage"><h3 class="stageName">Carousel Club</h3>
<div class="actLists"><div class="act id-libian-1 " data-id="libian-1" data-start-time="1719097200000" data-end-time="1719100800000" ><span class="actTime">18:00 - 19:00</span><span class="actNm">Libianca</span></div><div class="act id-peacht-1 " data-id="peacht-1" data-start-time="1719102600000" data-end-time="1719107100000" data-mbid="49e3f8be-6c8d-4e4b-b8dd-af5571cc82ce" ><span class="actTime">19:30 - 20:45</span><span class="actNm">Peach Tree Rascals</span></div><div class="act id-unusua-1 " data-id="unusua-1" data-start-time="1719108900000" data-end-time="1719112500000" ><span class="actTime">21:15 - 22:15</span><span class="actNm">Unusual Demont</span></div><div class="act id-neilfr-1 " data-id="neilfr-1" data-start-time="1719115200000" data-end-time="1719118800000" data-mbid="c4a1d94a-b37b-4d1a-8449-e3f8c65beecb" ><span class="actTime">23:00 - 00:00</span><span class="actNm">Neil Frances</span></div><div class="act id-hiatus-1 " data-id="hiatus-1" data-start-time="1719120600000" data-end-time="1719125100000" data-mbid="55c03773-59ea-4d4e-9057-87c2ecab005d" ><span class="actTime">00:30 - 01:45</span><span class="actNm">Hiatus Kaiyote</span></div></div>
</div><div class="stage"><h3 class="stageName">The Observatory</h3>
<div class="actLists"><div class="act id-rayben-1 " data-id="rayben-1" data-start-time="1719093600000" data-end-time="1719097200000" ><span class="actTime">17:00 - 18:00</span><span class="actNm">RAYBEN</span></div><div class="act id-kiltro-1 " data-id="kiltro-1" data-start-time="1719099000000" data-end-time="1719102600000" ><span class="actTime">18:30 - 19:30</span><span class="actNm">Kiltro</span></div><div class="act id-cucodj-1 " data-id="cucodj-1" data-start-time="1719103500000" data-end-time="1719107100000" ><span class="actTime">19:45 - 20:45</span><span class="actNm">Cuco (DJ Set)</span></div><div class="act id-caluss-1 " data-id="caluss-1" data-start-time="1719107100000" data-end-time="1719110700000" ><span class="actTime">20:45 - 21:45</span><span class="actNm">Calussa</span></div><div class="act id-michae-1 " data-id="michae-1" data-start-time="1719110700000" data-end-time="1719114300000" data-mbid="dbb214e0-53b8-467b-8ba8-296817d5bc16" ><span class="actTime">21:45 - 22:45</span><span class="actNm">Michael Brun</span></div><div class="act id-majorl-1 " data-id="majorl-1" data-start-time="1719114300000" data-end-time="1719117900000" ><span class="actTime">22:45 - 23:45</span><span class="actNm">Major League DJz</span></div><div class="act id-akspor-1 " data-id="akspor-1" data-start-time="1719117900000" data-end-time="1719122400000" ><span class="actTime">23:45 - 01:00</span><span class="actNm">AK Sports</span></div><div class="act id-jennas-1 " data-id="jennas-1" data-start-time="1719122400000" data-end-time="1719126000000" ><span class="actTime">01:00 - 02:00</span><span class="actNm">Jenna Shaw</span></div><div class="act id-sarala-1 " data-id="sarala-1" data-start-time="1719126000000" data-end-time="1719130500000" data-mbid="e7891efe-8326-4b04-bbc4-1271da101932" ><span class="actTime">02:00 - 03:15</span><span class="actNm">Sara Landry</span></div></div>
</div><div class="stage"><h3 class="stageName">Honeycomb</h3>
<div class="actLists"><div class="act id-femmei-1 " data-id="femmei-1" data-start-time="1719088200000" data-end-time="1719091800000" ><span class="actTime">15:30 - 16:30</span><span class="actNm">Femme Identifying Circle</span></div><div class="act id-rumble-2 " data-id="rumble-2" data-start-time="1719093600000" data-end-time="1719100800000" ><span class="actTime">17:00 - 19:00</span><span class="actNm">Rumble in the Bumble</span></div><div class="act id-dixons-2 " data-id="dixons-2" data-start-time="1719101700000" data-end-time="1719104400000" data-mbid="2cc0c42d-a27a-43fe-bee4-ea12b8572322" ><span class="actTime">19:15 - 20:00</span><span class="actNm">Dixon's Violin</span></div><div class="act id-mascol-1 " data-id="mascol-1" data-start-time="1719109800000" data-end-time="1719113400000" ><span class="actTime">21:30 - 22:30</span><span class="actNm">Mascolo</span></div><div class="act id-mojave-1 " data-id="mojave-1" data-start-time="1719115200000" data-end-time="1719118800000" ><span class="actTime">23:00 - 00:00</span><span class="actNm">Mojave Grey</span></div><div class="act id-lpgiob1-1 " data-id="lpgiob1-1" data-start-time="1719120600000" data-end-time="1719127800000" ><span class="actTime">00:30 - 02:30</span><span class="actNm">LP Giobbi (Dead House Set)</span></div></div>
</div></div><div class="day" data-date="1719118800" data-first-start="43200" data-last-stop="93600"><h2 class="dayName">Sun&#8203;day 23rd June</h2>
<div class="stage"><h3 class="stageName">Ranch Arena</h3>
<div class="actLists"><div class="act id-dirtwi-1 " data-id="dirtwi-1" data-start-time="1719180000000" data-end-time="1719183600000" data-mbid="cb761761-4f52-4f29-9825-314c6e3d20ac" ><span class="actTime">17:00 - 18:00</span><span class="actNm">Dirtwire</span></div><div class="act id-umphre-1 " data-id="umphre-1" data-start-time="1719186300000" data-end-time="1719192600000" ><span class="actTime">18:45 - 20:30</span><span class="actNm">Umphrey's Mcgee</span></div><div class="act id-gigant-1 " data-id="gigant-1" data-start-time="1719195300000" data-end-time="1719200700000" ><span class="actTime">21:15 - 22:45</span><span class="actNm">Gigantic NGHTMRE</span></div><div class="act id-excisi-1 " data-id="excisi-1" data-start-time="1719203400000" data-end-time="1719208800000" data-mbid="733c6e6f-0306-403e-9243-82b16a4f82d8" ><span class="actTime">23:30 - 01:00</span><span class="actNm">Excision</span></div></div>
</div><div class="stage"><h3 class="stageName">Sherwood Court</h3>
<div class="actLists"><div class="act id-lightc-1 " data-id="lightc-1" data-start-time="1719174600000" data-end-time="1719179100000" ><span class="actTime">15:30 - 16:45</span><span class="actNm">Lightcode by LSDream</span></div><div class="act id-little-1 " data-id="little-1" data-start-time="1719181800000" data-end-time="1719185400000" ><span class="actTime">17:30 - 18:30</span><span class="actNm">Little Stranger</span></div><div class="act id-inzo-1 " data-id="inzo-1" data-start-time="1719191700000" data-end-time="1719196200000" ><span class="actTime">20:15 - 21:30</span><span class="actNm">Inzo</span></div><div class="act id-chases-1 " data-id="chases-1" data-start-time="1719198000000" data-end-time="1719202500000" data-mbid="82e454e2-38ee-4e69-89a6-cc65167753d1" ><span class="actTime">22:00 - 23:15</span><span class="actNm">Chase & Status</span></div><div class="act id-charlo-1 " data-id="charlo-1" data-start-time="1719205200000" data-end-time="1719209700000" ><span class="actTime">00:00 - 01:15</span><span class="actNm">Charlotte De Witte presents Overdrive</span></div></div>
</div><div class="stage"><h3 class="stageName">Tripolee</h3>
<div class="actLists"><div class="act id-yoga-3 " data-id="yoga-3" data-start-time="1719162000000" data-end-time="1719166500000" data-mbid="409b911e-1496-4238-a63a-25bcefe0f872" ><span class="actTime">12:00 - 13:15</span><span class="actNm">Yoga</span></div><div class="act id-ayybo-1 " data-id="ayybo-1" data-start-time="1719184500000" data-end-time="1719189000000" ><span class="actTime">18:15 - 19:30</span><span class="actNm">Ayybo</span></div><div class="act id-cocobr-1 " data-id="cocobr-1" data-start-time="1719189000000" data-end-time="1719193500000" ><span class="actTime">19:30 - 20:45</span><span class="actNm">Coco & Breezy</span></div><div class="act id-oddmob-1 " data-id="oddmob-1" data-start-time="1719193500000" data-end-time="1719198000000" ><span class="actTime">20:45 - 22:00</span><span class="actNm">Odd Mob & Omnom present Hyperbeam</span></div><div class="act id-acraze-1 " data-id="acraze-1" data-start-time="1719198000000" data-end-time="1719201600000" ><span class="actTime">22:00 - 23:00</span><span class="actNm">acraze</span></div><div class="act id-matrod-1 " data-id="matrod-1" data-start-time="1719201600000" data-end-time="1719206100000" ><span class="actTime">23:00 - 00:15</span><span class="actNm">Matroda</span></div><div class="act id-closin-1 " data-id="closin-1" data-start-time="1719207000000" data-end-time="1719212400000" ><span class="actTime">00:30 - 02:00</span><span class="actNm">Closing Party</span></div></div>
</div><div class="stage"><h3 class="stageName">Carousel Club</h3>
<div class="actLists"><div class="act id-pridep-1 " data-id="pridep-1" data-start-time="1719178200000" data-end-time="1719183600000" ><span class="actTime">16:30 - 18:00</span><span class="actNm">Pride Party</span></div><div class="act id-onlyfi-1 " data-id="onlyfi-1" data-start-time="1719183600000" data-end-time="1719188100000" ><span class="actTime">18:00 - 19:15</span><span class="actNm">Only Fire</span></div><div class="act id-shaunr-1 " data-id="shaunr-1" data-start-time="1719189900000" data-end-time="1719194400000" ><span class="actTime">19:45 - 21:00</span><span class="actNm">Shaun Ross</span></div><div class="act id-slayyy-1 " data-id="slayyy-1" data-start-time="1719196200000" data-end-time="1719199800000" ><span class="actTime">21:30 - 22:30</span><span class="actNm">Slayyyter</span></div><div class="act id-lpgiob-1 " data-id="lpgiob-1" data-start-time="1719201600000" data-end-time="1719207000000" data-mbid="dae7874c-3428-4e16-be51-5cb1968c8a97" ><span class="actTime">23:00 - 00:30</span><span class="actNm">LP Giobbi</span></div></div>
</div><div class="stage"><h3 class="stageName">The Observatory</h3>
<div class="actLists"><div class="act id-shaedi-1 " data-id="shaedi-1" data-start-time="1719179100000" data-end-time="1719182700000" ><span class="actTime">16:45 - 17:45</span><span class="actNm">Shae District</span></div><div class="act id-though-1 " data-id="though-1" data-start-time="1719184500000" data-end-time="1719188100000" data-mbid="1666ed7f-c66d-491a-874a-1536385d5267" ><span class="actTime">18:15 - 19:15</span><span class="actNm">Thought Process</span></div><div class="act id-levity-2 " data-id="levity-2" data-start-time="1719189000000" data-end-time="1719192600000" ><span class="actTime">19:30 - 20:30</span><span class="actNm">Levity</span></div><div class="act id-lyny-1 " data-id="lyny-1" data-start-time="1719193500000" data-end-time="1719197100000" ><span class="actTime">20:45 - 21:45</span><span class="actNm">LYNY</span></div><div class="act id-venbee-1 " data-id="venbee-1" data-start-time="1719198000000" data-end-time="1719201300000" data-mbid="28121910-a402-451d-b471-0085a8db0e5c" ><span class="actTime">22:00 - 22:55</span><span class="actNm">Venbee</span></div><div class="act id-hamdi-1 " data-id="hamdi-1" data-start-time="1719202500000" data-end-time="1719207000000" ><span class="actTime">23:15 - 00:30</span><span class="actNm">Hamdi</span></div><div class="act id-dixons-3 " data-id="dixons-3" data-start-time="1719208800000" data-end-time="1719212400000" data-mbid="2cc0c42d-a27a-43fe-bee4-ea12b8572322" ><span class="actTime">01:00 - 02:00</span><span class="actNm">Dixon's Violin</span></div></div>
</div><div class="stage"><h3 class="stageName">Honeycomb</h3>
<div class="actLists"><div class="act id-proxim-1 " data-id="proxim-1" data-start-time="1719182700000" data-end-time="1719186300000" ><span class="actTime">17:45 - 18:45</span><span class="actNm">Proxima Parada</span></div><div class="act id-jasonl-1 " data-id="jasonl-1" data-start-time="1719188100000" data-end-time="1719191700000" ><span class="actTime">19:15 - 20:15</span><span class="actNm">Jason Leech</span></div><div class="act id-maddyo-2 " data-id="maddyo-2" data-start-time="1719192600000" data-end-time="1719196200000" ><span class="actTime">20:30 - 21:30</span><span class="actNm">Maddy O'Neal</span></div><div class="act id-kallag-1 " data-id="kallag-1" data-start-time="1719198000000" data-end-time="1719201600000" ><span class="actTime">22:00 - 23:00</span><span class="actNm">Kallaghan</span></div><div class="act id-acraze-2 " data-id="acraze-2" data-start-time="1719208800000" data-end-time="1719212400000" ><span class="actTime">01:00 - 02:00</span><span class="actNm">acraze</span></div></div>
</div></div></div>
"""

# https://old.reddit.com/r/ElectricForest/comments/1bqbwlv/electric_forest_2024_lineup_broken_down_by_genre/
dicto = {"BASS" : ["Barclay Crenshaw",
                  "Whyte Fang", 
                  "LSZEE",
                  "Seven lions",
                  "Pretty Lights",
                  "Zingara"],
        "DUBSTEP": ["ALLEYCVT",
                    "ATLiens",
                    "Black Tiger Sex Machine",
                    "Caspa",
                    "Excision",
                    "Gigantic NGHTMRE",
                    "Hamdi",
                    "LEVEL UP",
                    "Lucii",
                    "LYNY",
                    "Subtronics",
                    "Boogie T",
                    "CanaBliss",
                    "levity",
                    "Hyperbeam",
                    ],
        "DnB":   ["Chase & Status",
                  "Dimension",
                  "AK Sports",
                  "Sammy Virji",
                  "venbee",
                  "Wooli",
                  "G jones",
                  "Ivy Lab",
                  "Super Future",
                  "Zen Selekta",],
         "HOUSE": ["ACRAZE",
                   "AYYBO",
                   "Ben Böhmer",
                   "Calussa",
                   "Cassian",
                   "EVERYTHING ALWAYS",
                   "Green Velvet",
                   "John Summit",
                   "Knock2",
                   "Major League Djz",
                   "Matroda",
                   "Mau P",
                   "ODEN & Fatzo",
                   "Ranger Trucco",
                   "TSHA",
                   "VNSSA B2B Nala",
                   "Westend",
                   "Will Clarke",
                   "Baggi",
                   "Brandi Cyrus",
                   "Chaos in the CBD",
                   "H&RRY",
                   "marsh",
                   "MASONIC",
                   "Mojave Grey",
                   "Only fire",
                   "Rayben",
                   "Shae District",
                   "Swaylo",
                   "DJ Brownie",
                   "Kallaghan",
                   "Pretty Pink",],
         "DANCE": ["Coco & Breezy",
                   "DRAMA",
                   "it's murph",
                   "LP Giobbi",
                   "Michaël Brun",
                   "DJ Susan",
                   "Jason Leech",
                   "Shaun Ross",],
         "TECHNO" :["Charlotte De Witte",
                    "Sara Landry",
                    "Layton Giordani",
                    "Vini Vici",
                    "Jenna Shaw",
                    "Blastoyz",],
         "INDIE": ["Cuco",
                   "Cannons",
                   "NEIL FRANCES",
                   "Peach Tree Rascals",
                   "Emo Nite",
                   "Equanimous",
                   "Kiltro",
                   "Goodboys",],
         "POP": ["Mascolo",
                 "Nelly Furtado",
                 "Slayyyter",
                 "Neoma",
                 "Unusual demont",],
         "JAM": ["Dirtwire",
                 "Dumpstaphunk",
                 "Eggy",
                 "Lettuce",

                 "The Disco Biscuits",
                 "The String Cheese Incident",
                 "Umphrey's McGee",
                 "Jjuujjuu",
                 "Próxima Parada",
                 "League of Sound Disciples",
                 "Boogie T.rio",
                 "Dave Yaden"],
         "CHILL": ["INZO",
                  "Juelz",
                  "Maddy O'Neal",
                  "Redrum",
                  "Thought process",
                  "Tripp St.",
                  "Politik",
                  "Le Youth",
                  "Sultan + Shepard",
                  ],
         "RAP": ["Kenny Beats",
                 "Libianca",
                 "Ludacris",
                 "PAPERWATER",
                 "Little stranger",],
         "SOUL": ["Dixon's Violin",
                  "Rawayana",
                  "Hiatus Kaiyote",
                  "Polyrhythmics",
                  "Moontricks"],
         GENRE_DEFAULT : ["Yoga",
                          "Rumble in the Bumble",
                          "Exclusive: 6 in the Forest",
                          "Pride Party",
                          "Cardio",
                          "Closing Party",
                          "Femme Identifying Circle",
                          "Humanity Circle",
                          "Lightcode by LSDream",
                          "TBA"
                          ]
         }


duoActs = {"Gigantic NGHTMRE" : ["Big Gigantic","NGHTMRE"],
              "EVERYTHING ALWAYS" : ["Dom Dolla","John Summit"],
              "LSZEE": ["CloZee","LSDREAM"],
              "VNSSA B2B Nala" : ["VNSSA","Nala"],
              "Hyperbeam" : ["odd Mob", "Omnom"]}

forClashFinder = {"Odd Mob & Omnom present Hyperbeam" : "Hyperbeam"} # k:v is name in clash finder : name in genre list

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
        return 0,0
    artist_info = get_artist(artist_name, client_id, client_secret)
    if artist_info is None:
        return 0,0
    followers = artist_info['followers']['total']
    popularity = artist_info['popularity']
    return followers, popularity

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
    day_div = soup.find_all('div', class_='day')
    for day in day_div:
        # Extracting stages and acts
        stages = day.find_all('div', class_='stage')
        for stage in stages:
            stage_name = stage.find('h3', class_='stageName').text.strip()
            acts = stage.find_all('div', class_='act')
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
        followers, popularity = get_artist_followers_popularity(act_spot, client_id, client_secret)
        listActsPop.append({'name':act, 'followers' : followers, "popularity" : popularity})
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
            fol, pop = get_artist_followers_popularity(artist, client_id, client_secret)
            followers += fol
            popularity += pop
        followers = int((followers / len(artists)) * duo_mult)
        popularity = int((popularity / len(artists)) * duo_mult)
        listActsPop.append({'name':duo, 'followers' : followers, "popularity" : popularity})
    listActsPop = set_pop_follow_manually(listActsPop, "Cuco", 32, 1059)  # Wrong Cuco is the first option in Spotify query.
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
        writeAndPrint(f, "// Genre - https://old.reddit.com/r/ElectricForest/comments/1bqbwlv/electric_forest_2024_lineup_broken_down_by_genre/")
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
    listActsPop = junNine if USE_TEST_ARR else getFullArray(listActs)
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