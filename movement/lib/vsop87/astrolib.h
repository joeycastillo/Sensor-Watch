/*
 * Partial C port of Greg Miller's public domain astro library (gmiller@gregmiller.net) 2019
 * https://github.com/gmiller123456/astrogreg *
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

#ifndef ASTROLIB_H_
#define ASTROLIB_H_

typedef enum {
    ASTRO_BODY_SUN = 0,
    ASTRO_BODY_MERCURY,
    ASTRO_BODY_VENUS,
    ASTRO_BODY_EARTH,
    ASTRO_BODY_MARS,
    ASTRO_BODY_JUPITER,
    ASTRO_BODY_SATURN,
    ASTRO_BODY_URANUS,
    ASTRO_BODY_NEPTUNE,
    ASTRO_BODY_EMB,
    ASTRO_BODY_MOON
} astro_body_t;

typedef struct {
    double elements[3][3];
} astro_matrix_t;

typedef struct {
    double x;
    double y;
    double z;
} astro_cartesian_coordinates_t;

typedef struct {
    double right_ascension;
    double declination;
    double distance;
} astro_equatorial_coordinates_t;

typedef struct {
    double altitude;
    double azimuth;
} astro_horizontal_coordinates_t;

astro_equatorial_coordinates_t astro_get_ra_dec(double jd, astro_body_t bodyNum, double lat, double lon, bool calculate_precession);

//Converts a Julian Date in UTC to Terrestrial Time (TT)
double astro_convert_utc_to_tt(double jd) ;

//Converts a Julan Date to Julian Millenia since J2000, which is what VSOP87 expects as input
double astro_convert_jd_to_julian_millenia_since_j2000(double jd);

astro_cartesian_coordinates_t astro_subtract_cartesian(astro_cartesian_coordinates_t a, astro_cartesian_coordinates_t b);

// Performs the rotation from ecliptic coordinates to J2000 coordinates for the given vector x
astro_cartesian_coordinates_t astro_rotate_from_vsop_to_J2000(astro_cartesian_coordinates_t c);

double astro_get_GMST(double ut1);

//Gets a rotation matrix about the x axis.  Angle R is in radians
astro_matrix_t astro_get_x_rotation_matrix(double r);

//Gets a rotation matrix about the y axis.  Angle R is in radians
astro_matrix_t astro_get_y_rotation_matrix(double r);

//Gets a rotation matrix about the z axis.  Angle R is in radians
astro_matrix_t astro_get_z_rotation_matrix(double r);

astro_matrix_t astro_transpose_matrix(astro_matrix_t m);

astro_cartesian_coordinates_t astro_vector_multiply_vector_by_matrix(astro_cartesian_coordinates_t v, astro_matrix_t m);

//Converts cartesian XYZ coordinates to polar (e.g. J2000 xyz to Right Accention and Declication)
astro_equatorial_coordinates_t astro_convert_cartesian_to_polar(astro_cartesian_coordinates_t xyz);

//Convert Geodedic Lat Lon to geocentric XYZ position vector
//All angles are input as radians
astro_cartesian_coordinates_t astro_convert_geodedic_latlon_to_ITRF_XYZ(double lat, double lon, double height);

//Convert position vector to celestial "of date" system.
//g(t)=R3(-GAST) r
//(Remember to use UT1 for GAST, not ET)
//All angles are input and output as radians
astro_cartesian_coordinates_t astro_convert_ITRF_to_GCRS(astro_cartesian_coordinates_t r, double ut1);

astro_cartesian_coordinates_t astro_convert_coordinates_from_meters_to_AU(astro_cartesian_coordinates_t c);

astro_cartesian_coordinates_t astro_get_observer_geocentric_coords(double jd, double lat, double lon);

astro_cartesian_coordinates_t get_body_coordinates(astro_body_t bodyNum, double et);

astro_cartesian_coordinates_t astro_get_body_light_time_adjusted(double t, astro_cartesian_coordinates_t origin, astro_body_t bodyNum);

astro_horizontal_coordinates_t astro_convert_equatorial_coordinates_to_horizontal(double jd, double lat, double lon, double ra, double dec);

astro_matrix_t astro_dot_product(astro_matrix_t a, astro_matrix_t b);

astro_matrix_t astro_get_precession_matrix(double jd);

#endif // ASTROLIB_H_
