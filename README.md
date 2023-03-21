# The Sensor Watch

### Settings watch-face for location coordinate management

fork of [Sensor Watch](https://github.com/joeycastillo/Sensor-Watch/)

```
/*
 * PLACE FACE
 * ==========
 *
 * Based on and expanded from the Sunrise/Sunset face. Outsourced the location setting functionality to 
 * its own face. Also serves as a converter between different coordinate notation formats.
 * 
 * With the LIGHT button each place coordinate can be shown and edited in 4 different display modes:
 * 
 * 1) Decimal Latitude and Longitude (WGS84) up to 5 decimal points
 * 2) Latitude and Longitude (WGS84) in traditional DD°MM'SS" notation
 * 3) Ten digit Open Location Code (aka. PlusCode) format
 * 4) Ten digit Geohash format
 * 
 * Using the ALARM button the user can flip through 2 pages of coordinate info to see the first and
 * second sets of digits.
 * 
 * (please also refer to the notes on precision below)
 *
 * Editing Mode
 * ============
 * 
 * A LONG PRESS of the LIGHT button toggles editing mode for each of the selected notations.
 * 
 * In this mode LIGHT moves the cursor and ALARM changes the letter cycling through the available
 * alphabet or numbers. 
 * 
 * When OLC or Geohash display are edited, Digit Info mode is activated. It serves as a workaround 
 * for the limitation of how ambiguously alphanumeric characters are displayed on the main seven segment 
 * digits of the watch face ( S or 5, I or 1, U or W?).
 * 
 * The selected letter is also shown in the much easier to read alphanumeric 8 segment weekday digit above.
 * In addition the '24H' indicator is active when the selected digit represents a number and the 'PM' 
 * indicator for a letter. 
 * 
 * A LONG PRESS of LIGHT saves the changes, a LONG PRESS of ALARM discards them.
 * 
 * Coordinates are read or stored to both the traditional internal location register and a file on 
 * the LFS file system ("place.loc"). By default the Watch Face loads the coordinates from file
 * when activated. If no file is present, the coordinates are loaded from the register.
 * (please also see the notes on precision below)
 * 
 * Auxiliary Mode: Digit Info
 * ==========================
 * 
 * A LONG PRESS of the ALARM button toggles Digit Info mode when OLC or Geohash display is active.
 * (LAP indicator is on) It is a means of being able to see the detailed Digit Info as described above
 * but without the risk of accidentally editing any of digits.
 * 
 * Both ALARM and LIGHT buttons can be used to flip through the letters.
 * 
 * Notes on Coordinate Precision
 * =============================
 * 
 * The common WGS84 Latitude and Longitude degrees naturally do not represent meters in distance 
 * on the ground. 1° Longitude on the equatorial line equals a width of 111.32 kilometers, but 
 * at 40° latitude further North or South it is approximately 85 kilometers wide. The closer to 
 * the poles the narrower (and more precise) the latitude degrees get.
 * 
 * The Sensor Watch's traditional 16bit location register only stores latitudes and longitudes 
 * with two decimal points. That equals a longitudal precision of 36 arc seconds, or ~1111 meters
 * at the equator - precise enough for astronomical calculations, but not if you want to store the 
 * location of let's say a building.
 * 
 * Hence we propose the <place.loc> file that serves the same purpose, but with a precision of 
 * five decimal digits. That equals 0.04 arc seconds or 1.11 meters at the equator.
 * 
 * Please also note that the different notations of this watch face also have varying magnitudes 
 * of precision:
 * 
 * | Format             | Notation               | Precision at Equator | Precision at 67° N/S |
 * | ------------------ | ---------------------- | -------------------- | -------------------- |
 * | 2d. Decimal LatLon | 29.98, 31.13           |           1111.320 m |            435.125 m |
 * | 5d. Decimal LatLon | 29.97916, 31.13417     |              1.111 m |              0.435 m |
 * | DMS LatLon         | N 29°58′45″, E 31°8′3″ |             30.833 m |             12.083 m |
 * | Open Location Code | 7GXHX4HM+MM            |             13.875 m |             13.875 m |
 * | Geohash            | stq4s3x1qu             |              1.189 m |              0.596 m |
 * 
 * Since all notations are internally converted into degrees with 5 decimal points, expect some
 * rounding errors when editing or loading the coordinates in other notation formats.
 * 
 */
 ```