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

typedef struct {
    int16_t degrees;
    uint8_t minutes;
    uint8_t seconds; // you may want this to be a float, watch just can't display any more digits
} astro_angle_dms_t;

typedef struct {
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds; // you may want this to be a float, watch just can't display any more digits
} astro_angle_hms_t;

// Convert a date to a julian date. Must be in UTC+0 time zone!
double astro_convert_date_to_julian_date(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);

// Converts a Julan Date to Julian Millenia since J2000, which is what VSOP87 expects as input.
double astro_convert_jd_to_julian_millenia_since_j2000(double jd);

// Get right ascension / declination for a given body in the list above.
astro_equatorial_coordinates_t astro_get_ra_dec(double jd, astro_body_t bodyNum, double lat, double lon, bool calculate_precession);

// Convert right ascension / declination to altitude/azimuth for a given location.
astro_horizontal_coordinates_t astro_ra_dec_to_alt_az(double jd, double lat, double lon, double ra, double dec);

// these are self-explanatory
double astro_degrees_to_radians(double degrees);
double astro_radians_to_degrees(double radians);
astro_angle_dms_t astro_radians_to_dms(double radians);
astro_angle_hms_t astro_radians_to_hms(double radians);

#endif // ASTROLIB_H_
