/*
 * Partial C port of Greg Miller's public domain astro library (gmiller@gregmiller.net) 2019
 * https://github.com/gmiller123456/astrogreg
 * 
 * Ported by Joey Castillo for Sensor Watch
 * https://github.com/joeycastillo/Sensor-Watch/
 *
 * Public Domain
 *
 * THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "astrolib.h"
#include "vsop87a_milli.h"

double astro_convert_utc_to_tt(double jd) ;
double astro_get_GMST(double ut1);
astro_cartesian_coordinates_t astro_subtract_cartesian(astro_cartesian_coordinates_t a, astro_cartesian_coordinates_t b);
astro_cartesian_coordinates_t astro_rotate_from_vsop_to_J2000(astro_cartesian_coordinates_t c);
astro_matrix_t astro_get_x_rotation_matrix(double r);
astro_matrix_t astro_get_y_rotation_matrix(double r);
astro_matrix_t astro_get_z_rotation_matrix(double r);
astro_matrix_t astro_transpose_matrix(astro_matrix_t m);
astro_matrix_t astro_dot_product(astro_matrix_t a, astro_matrix_t b);
astro_matrix_t astro_get_precession_matrix(double jd);
astro_cartesian_coordinates_t astro_matrix_multiply(astro_cartesian_coordinates_t v, astro_matrix_t m);
astro_cartesian_coordinates_t astro_convert_geodedic_latlon_to_ITRF_XYZ(double lat, double lon, double height);
astro_cartesian_coordinates_t astro_convert_ITRF_to_GCRS(astro_cartesian_coordinates_t r, double ut1);
astro_cartesian_coordinates_t astro_convert_coordinates_from_meters_to_AU(astro_cartesian_coordinates_t c);
astro_cartesian_coordinates_t astro_get_observer_geocentric_coords(double jd, double lat, double lon);
astro_cartesian_coordinates_t astro_get_body_coordinates(astro_body_t bodyNum, double et);
astro_cartesian_coordinates_t astro_get_body_coordinates_light_time_adjusted(astro_body_t body, astro_cartesian_coordinates_t origin, double t);
astro_equatorial_coordinates_t astro_convert_cartesian_to_polar(astro_cartesian_coordinates_t xyz);

//Special "Math.floor()" function used by convertDateToJulianDate()
static double _astro_special_floor(double d) {
    if(d > 0) {
        return floor(d);
    }
    return floor(d) - 1;
}

double astro_convert_date_to_julian_date(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second) {
    if (month < 3){
        year = year - 1;
        month = month + 12;
    }

    double b = 0;
    if (!(year < 1582 || (year == 1582 && (month < 10 || (month == 10 && day < 5))))) {
        double a = _astro_special_floor(year / 100.0);
        b = 2 - a + _astro_special_floor(a / 4.0);
    }

    double jd = _astro_special_floor(365.25 * (year + 4716)) + _astro_special_floor(30.6001 * (month + 1)) + day + b - 1524.5;
    jd += hour / 24.0;
    jd += minute / 24.0 / 60.0;
    jd += second / 24.0 / 60.0 / 60.0;

    return jd;
}

//Return all values in radians.
//The positions are adjusted for the parallax of the Earth, and the offset of the observer from the Earth's center
//All input and output angles are in radians!
astro_equatorial_coordinates_t astro_get_ra_dec(double jd, astro_body_t body, double lat, double lon, bool calculate_precession) {
    double jdTT = astro_convert_utc_to_tt(jd);
    double t = astro_convert_jd_to_julian_millenia_since_j2000(jdTT);
    
    // Get current position of Earth and the target body
    astro_cartesian_coordinates_t earth_coords = astro_get_body_coordinates(ASTRO_BODY_EARTH, t);
    astro_cartesian_coordinates_t body_coords = astro_get_body_coordinates_light_time_adjusted(body, earth_coords, t);

    // Convert to Geocentric coordinate
    body_coords = astro_subtract_cartesian(body_coords, earth_coords);

    //Rotate ecliptic coordinates to J2000 coordinates
    body_coords = astro_rotate_from_vsop_to_J2000(body_coords);

    astro_matrix_t precession;
    // TODO: rotate body for precession, nutation and bias
    if(calculate_precession) {
        precession = astro_get_precession_matrix(jdTT);
        body_coords = astro_matrix_multiply(body_coords, precession);
    }

    //Convert to topocentric
    astro_cartesian_coordinates_t observerXYZ = astro_get_observer_geocentric_coords(jdTT, lat, lon);

    if(calculate_precession) {
        //TODO: rotate observerXYZ for precession, nutation and bias
        astro_matrix_t precessionInv = astro_transpose_matrix(precession);
        observerXYZ = astro_matrix_multiply(observerXYZ, precessionInv);
    }

    body_coords = astro_subtract_cartesian(body_coords, observerXYZ);

    //Convert to topocentric RA DEC by converting from cartesian coordinates to polar coordinates
    astro_equatorial_coordinates_t retval = astro_convert_cartesian_to_polar(body_coords);
    
    retval.declination = M_PI/2.0 - retval.declination;  //Dec.  Offset to make 0 the equator, and the poles +/-90 deg
    if(retval.right_ascension < 0) retval.right_ascension += 2*M_PI; //Ensure RA is positive
    
    return retval;
}

//Converts a Julian Date in UTC to Terrestrial Time (TT)
double astro_convert_utc_to_tt(double jd) {
    //Leap seconds are hard coded, should be updated from the IERS website for other times
    
    //TAI = UTC + leap seconds (e.g. 32)
    //TT=TAI + 32.184

    //return jd + (32.0 + 32.184) / 24.0 / 60.0 / 60.0;
    return jd + (37.0 + 32.184) / 24.0 / 60.0 / 60.0;

    /*
    https://data.iana.org/time-zones/tzdb-2018a/leap-seconds.list
    2272060800  10  # 1 Jan 1972
    2287785600  11  # 1 Jul 1972
    2303683200  12  # 1 Jan 1973
    2335219200  13  # 1 Jan 1974
    2366755200  14  # 1 Jan 1975
    2398291200  15  # 1 Jan 1976
    2429913600  16  # 1 Jan 1977
    2461449600  17  # 1 Jan 1978
    2492985600  18  # 1 Jan 1979
    2524521600  19  # 1 Jan 1980
    2571782400  20  # 1 Jul 1981
    2603318400  21  # 1 Jul 1982
    2634854400  22  # 1 Jul 1983
    2698012800  23  # 1 Jul 1985
    2776982400  24  # 1 Jan 1988
    2840140800  25  # 1 Jan 1990
    2871676800  26  # 1 Jan 1991
    2918937600  27  # 1 Jul 1992
    2950473600  28  # 1 Jul 1993
    2982009600  29  # 1 Jul 1994
    3029443200  30  # 1 Jan 1996
    3076704000  31  # 1 Jul 1997
    3124137600  32  # 1 Jan 1999
    3345062400  33  # 1 Jan 2006
    3439756800  34  # 1 Jan 2009
    3550089600  35  # 1 Jul 2012
    3644697600  36  # 1 Jul 2015
    3692217600  37  # 1 Jan 2017
    */
}

double astro_convert_jd_to_julian_millenia_since_j2000(double jd) {
    return (jd - 2451545.0) / 365250.0;
}

astro_cartesian_coordinates_t astro_subtract_cartesian(astro_cartesian_coordinates_t a, astro_cartesian_coordinates_t b) {
    astro_cartesian_coordinates_t retval;

    retval.x = a.x - b.x;
    retval.y = a.y - b.y;
    retval.z = a.z - b.z;

    return retval;
}

// Performs the rotation from ecliptic coordinates to J2000 coordinates for the given vector x
astro_cartesian_coordinates_t astro_rotate_from_vsop_to_J2000(astro_cartesian_coordinates_t c) {
    /* From VSOP87.doc
        X        +1.000000000000  +0.000000440360  -0.000000190919   X
        Y     =  -0.000000479966  +0.917482137087  -0.397776982902   Y
        Z FK5     0.000000000000  +0.397776982902  +0.917482137087   Z VSOP87A
    */
    astro_cartesian_coordinates_t t;
    t.x = c.x + c.y * 0.000000440360 + c.z * -0.000000190919;
    t.y = c.x * -0.000000479966 + c.y * 0.917482137087 + c.z * -0.397776982902;
    t.z = c.y * 0.397776982902 + c.z * 0.917482137087;

    return t;
}

double astro_get_GMST(double ut1) {
    double D = ut1 - 2451545.0;
    double T = D/36525.0;
    double gmst = fmod((280.46061837 + 360.98564736629*D + 0.000387933*T*T - T*T*T/38710000.0), 360.0);

    if(gmst<0) {
        gmst+=360;
    }

    return gmst/15;
}

static astro_matrix_t _astro_get_empty_matrix() {
    astro_matrix_t t;
    for(uint8_t i = 0; i < 3 ; i++) {
        for(uint8_t j = 0 ; j < 3 ; j++) {
            t.elements[i][j] = 0;
        }
    }
    return t;
}

//Gets a rotation matrix about the x axis.  Angle R is in radians
astro_matrix_t astro_get_x_rotation_matrix(double r) {
    astro_matrix_t t = _astro_get_empty_matrix();

    t.elements[0][0]=1;
    t.elements[0][1]=0;
    t.elements[0][2]=0;
    t.elements[1][0]=0;
    t.elements[1][1]=cos(r);
    t.elements[1][2]=sin(r);
    t.elements[2][0]=0;
    t.elements[2][1]=-sin(r);
    t.elements[2][2]=cos(r);

    return t;
}

//Gets a rotation matrix about the y axis.  Angle R is in radians
astro_matrix_t astro_get_y_rotation_matrix(double r) {
    astro_matrix_t t = _astro_get_empty_matrix();

    t.elements[0][0]=cos(r);
    t.elements[0][1]=0;
    t.elements[0][2]=-sin(r);
    t.elements[1][0]=0;
    t.elements[1][1]=1;
    t.elements[1][2]=0;
    t.elements[2][0]=sin(r);
    t.elements[2][1]=0;
    t.elements[2][2]=cos(r);

    return t;
}

//Gets a rotation matrix about the z axis.  Angle R is in radians
astro_matrix_t astro_get_z_rotation_matrix(double r) {
    astro_matrix_t t = _astro_get_empty_matrix();

    t.elements[0][0]=cos(r);
    t.elements[0][1]=sin(r);
    t.elements[0][2]=0;
    t.elements[1][0]=-sin(r);
    t.elements[1][1]=cos(r);
    t.elements[1][2]=0;
    t.elements[2][0]=0;
    t.elements[2][1]=0;
    t.elements[2][2]=1;

    return t;
}

void astro_print_matrix(char * title, astro_matrix_t matrix);
void astro_print_matrix(char * title, astro_matrix_t matrix) {
    printf("%s\n", title);
    for(uint8_t i = 0; i < 3 ; i++) {
        printf("\t");
        for(uint8_t j = 0 ; j < 3 ; j++) {
            printf("%12f", matrix.elements[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

astro_matrix_t astro_dot_product(astro_matrix_t a, astro_matrix_t b) {
    astro_matrix_t retval;

    for(uint8_t i = 0; i < 3 ; i++) {
        for(uint8_t j = 0 ; j < 3 ; j++) {
            double temp = 0;
            for(uint8_t k = 0; k < 3 ; k++) {
                temp += a.elements[i][k] * b.elements[k][j];
            }
            retval.elements[i][j]=temp;
        }
    }

    return retval;
}

astro_matrix_t astro_transpose_matrix(astro_matrix_t m) {
    astro_matrix_t retval;
    for(uint8_t i = 0; i < 3 ; i++) {
        for(uint8_t j = 0 ; j < 3 ; j++) {
            retval.elements[i][j] = m.elements[j][i];
        }
    }
    return retval;
}

astro_matrix_t astro_get_precession_matrix(double jd) {
    //2006 IAU Precession.  Implemented from IERS Technical Note No 36 ch5.
    //https://www.iers.org/SharedDocs/Publikationen/EN/IERS/Publications/tn/TechnNote36/tn36_043.pdf?__blob=publicationFile&v=1

    double t = (jd - 2451545.0) / 36525.0;  //5.2
    const double Arcsec2Radians = M_PI/180.0/60.0/60.0; //Converts arc seconds used in equations below to radians

    double e0 = 84381.406 * Arcsec2Radians; //5.6.4
    double omegaA = e0 + ((-0.025754 + (0.0512623 +	(-0.00772503 + (-0.000000467 + 0.0000003337*t) * t) * t) * t) * t) * Arcsec2Radians; //5.39
    double psiA = ((5038.481507 +	(-1.0790069 + (-0.00114045 + (0.000132851 - 0.0000000951*t) * t) * t) * t) * t) * Arcsec2Radians; //5.39
    double chiA = ((10.556403 + (-2.3814292 + (-0.00121197 + (0.000170663 - 0.0000000560*t) * t) * t) * t) * t) * Arcsec2Radians; //5.40
    //Rotation matrix from 5.4.5
    //(R1(−e0) · R3(psiA) · R1(omegaA) · R3(−chiA))
    //Above eq rotates from "of date" to J2000, so we reverse the signs to go from J2000 to "of date"
    astro_matrix_t m1 = astro_get_x_rotation_matrix(e0);
    astro_matrix_t m2 = astro_get_z_rotation_matrix(-psiA);
    astro_matrix_t m3 = astro_get_x_rotation_matrix(-omegaA);
    astro_matrix_t m4 = astro_get_z_rotation_matrix(chiA);

    astro_matrix_t m5 = astro_dot_product(m4, m3);
    astro_matrix_t m6 = astro_dot_product(m5, m2);
    astro_matrix_t precessionMatrix = astro_dot_product(m6, m1);

    return precessionMatrix;
}

astro_cartesian_coordinates_t astro_matrix_multiply(astro_cartesian_coordinates_t v, astro_matrix_t m) {
    astro_cartesian_coordinates_t t;

    t.x = v.x*m.elements[0][0] + v.y*m.elements[0][1] + v.z*m.elements[0][2];
    t.y = v.x*m.elements[1][0] + v.y*m.elements[1][1] + v.z*m.elements[1][2];
    t.z = v.x*m.elements[2][0] + v.y*m.elements[2][1] + v.z*m.elements[2][2];

    return t;
}

//Converts cartesian XYZ coordinates to polar (e.g. J2000 xyz to Right Accention and Declication)
astro_equatorial_coordinates_t astro_convert_cartesian_to_polar(astro_cartesian_coordinates_t xyz) {
    astro_equatorial_coordinates_t t;

    t.distance = sqrt(xyz.x * xyz.x + xyz.y * xyz.y + xyz.z * xyz.z);
    t.declination = acos(xyz.z / t.distance);
    t.right_ascension = atan2(xyz.y, xyz.x);

    if(t.declination < 0) t.declination += 2 * M_PI;

    if(t.right_ascension < 0) t.right_ascension += 2 * M_PI;

    return t;
}

//Convert Geodedic Lat Lon to geocentric XYZ position vector
//All angles are input as radians
astro_cartesian_coordinates_t astro_convert_geodedic_latlon_to_ITRF_XYZ(double lat, double lon, double height) {
    //Algorithm from Explanatory Supplement to the Astronomical Almanac 3rd ed. P294
    const double a = 6378136.6;
    const double f = 1 / 298.25642;

    const double C = sqrt(((cos(lat)*cos(lat)) + (1.0-f)*(1.0-f) * (sin(lat)*sin(lat))));

    const double S = (1-f)*(1-f)*C;
    
    double h = height;

    astro_cartesian_coordinates_t r;
    r.x = (a*C+h) * cos(lat) * cos(lon);
    r.y = (a*C+h) * cos(lat) * sin(lon);
    r.z = (a*S+h) * sin(lat);
    
    return r;
}

//Convert position vector to celestial "of date" system.
//g(t)=R3(-GAST) r
//(Remember to use UT1 for GAST, not ET)
//All angles are input and output as radians
astro_cartesian_coordinates_t astro_convert_ITRF_to_GCRS(astro_cartesian_coordinates_t r, double ut1) {
    //This is a simple rotation matrix implemenation about the Z axis, rotation angle is -GMST

    double GMST = astro_get_GMST(ut1);
    GMST =- GMST * 15.0 * M_PI / 180.0;

    astro_matrix_t m = astro_get_z_rotation_matrix(GMST);
    astro_cartesian_coordinates_t t = astro_matrix_multiply(r, m);

    return t;
}

astro_cartesian_coordinates_t astro_convert_coordinates_from_meters_to_AU(astro_cartesian_coordinates_t c) {
    astro_cartesian_coordinates_t t;
    
    t.x = c.x / 1.49597870691E+11;
    t.y = c.y / 1.49597870691E+11;
    t.z = c.z / 1.49597870691E+11;
    
    return t;
}

astro_cartesian_coordinates_t astro_get_observer_geocentric_coords(double jd, double lat, double lon) {
    astro_cartesian_coordinates_t r = astro_convert_geodedic_latlon_to_ITRF_XYZ(lat, lon,0);
    r = astro_convert_ITRF_to_GCRS(r, jd);
    r = astro_convert_coordinates_from_meters_to_AU(r);
    
    return r;
}

//Returns a body's cartesian coordinates centered on the Sun.
//Requires vsop87a_milli_js, if you wish to use a different version of VSOP87, replace the class name vsop87a_milli below
astro_cartesian_coordinates_t astro_get_body_coordinates(astro_body_t body, double et) {
    astro_cartesian_coordinates_t retval = {0};
    double coords[3];
    switch(body) {
        case ASTRO_BODY_SUN: 
            return retval; //Sun is at the center for vsop87a
        case ASTRO_BODY_MERCURY:
             vsop87a_milli_getMercury(et, coords);
             break;
        case ASTRO_BODY_VENUS:
             vsop87a_milli_getVenus(et, coords);
             break;
        case ASTRO_BODY_EARTH:
             vsop87a_milli_getEarth(et, coords);
             break;
        case ASTRO_BODY_MARS:
             vsop87a_milli_getMars(et, coords);
             break;
        case ASTRO_BODY_JUPITER:
             vsop87a_milli_getJupiter(et, coords);
             break;
        case ASTRO_BODY_SATURN:
             vsop87a_milli_getSaturn(et, coords);
             break;
        case ASTRO_BODY_URANUS:
             vsop87a_milli_getUranus(et, coords);
             break;
        case ASTRO_BODY_NEPTUNE:
             vsop87a_milli_getNeptune(et, coords);
             break;
        case ASTRO_BODY_EMB:
             vsop87a_milli_getEmb(et, coords);
             break;
        case ASTRO_BODY_MOON:
            {
                double earth_coords[3];
                double emb_coords[3];
                vsop87a_milli_getEarth(et, earth_coords);
                vsop87a_milli_getEmb(et, emb_coords);
                vsop87a_milli_getMoon(earth_coords, emb_coords, coords);
            }
             break;
    }

    retval.x = coords[0];
    retval.y = coords[1];
    retval.z = coords[2];

    return retval;
}

astro_cartesian_coordinates_t astro_get_body_coordinates_light_time_adjusted(astro_body_t body, astro_cartesian_coordinates_t origin, double t) {
    //Get current position of body
    astro_cartesian_coordinates_t body_coords = astro_get_body_coordinates(body, t);

    double newT = t;

    for(uint8_t i = 0 ; i < 2 ; i++) {
        //Calculate light time to body
        body_coords = astro_subtract_cartesian(body_coords, origin);
        double distance = sqrt(body_coords.x*body_coords.x + body_coords.y*body_coords.y + body_coords.z*body_coords.z);
        distance *= 1.496e+11; //Convert from AU to meters
        double lightTime = distance / 299792458.0;

        //Convert light time to Julian Millenia, and subtract it from the original value of t
        newT -= lightTime / 24.0 / 60.0 / 60.0 / 365250.0;  
        //Recalculate body position adjusted for light time
        body_coords = astro_get_body_coordinates(body, newT);
    }

    return body_coords;
}

astro_horizontal_coordinates_t astro_ra_dec_to_alt_az(double jd, double lat, double lon, double ra, double dec) {
    double GMST = astro_get_GMST(jd) * M_PI/180.0 * 15.0;
    double h = GMST + lon - ra;

    double sina = sin(dec)*sin(lat) + cos(dec)*cos(h)*cos(lat);
    double a = asin(sina);

    double cosAz = (sin(dec)*cos(lat) - cos(dec)*cos(h)*sin(lat)) / cos(a);
    double Az = acos(cosAz);

    if(sin(h) > 0) Az = 2.0*M_PI - Az;

    astro_horizontal_coordinates_t retval;
    retval.altitude = a;
    retval.azimuth = Az;

    return retval;
}

double astro_degrees_to_radians(double degrees) {
    return degrees * M_PI / 180;
}

double astro_radians_to_degrees(double radians) {
    return radians * 180.0 / M_PI;
}

astro_angle_dms_t astro_radians_to_dms(double radians) {
    astro_angle_dms_t retval;
    int8_t sign = (radians < 0) ? -1 : 1;
    double degrees = fabs(astro_radians_to_degrees(radians));

    retval.degrees = (uint16_t)degrees;
    double temp = 60.0 * (degrees - retval.degrees);
    retval.minutes = (uint8_t)temp;
    retval.seconds = (uint8_t)round(60.0 * (temp - retval.minutes));

    if (retval.seconds > 59) {
        retval.seconds = 0.0;
        retval.minutes++;
    }

    if (retval.minutes > 59) {
        retval.minutes = 0;
        retval.degrees++;
    }

    degrees *= sign;

    return retval;
}

astro_angle_hms_t astro_radians_to_hms(double radians) {
    astro_angle_hms_t retval;
    double degrees = astro_radians_to_degrees(radians);
    double temp = degrees / 15.0;

    retval.hours = (uint8_t)temp;
    temp = 60.0 * (temp - retval.hours);
    retval.minutes = (uint8_t)temp;
    retval.seconds = (uint8_t)round(60.0 * (temp - retval.minutes));

    if (retval.seconds > 59) {
        retval.seconds = 0;
        retval.minutes++;
    }

    if (retval.minutes > 59) {
        retval.minutes = 0;
        retval.hours++;
    }

    return retval;
}
