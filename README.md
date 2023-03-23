# The Sensor Watch

### Settings watch-face for location coordinate management

fork of [Sensor Watch](https://github.com/joeycastillo/Sensor-Watch/)

```
/*
 * PLACES FACE
 * ===========
 *
 * Based on and expanded from the Sunrise/Sunset face. Initially just intended to outsource 
 * the location setting functionality to its own face it has become an advanced managing
 * application for location data that also serves as a converter between different coordinate
 * notation formats.
 * 
 * Using the ALARM button the user can flip through 5 available place slots. The first place is
 * always the one that is activated across all watch faces.
 * 
 * With the LIGHT button each place coordinate can be shown and edited in 5 different display modes:
 * 
 * 1) Place Name
 * 2) Decimal Latitude and Longitude (WGS84) up to 5 decimal points
 * 3) Latitude and Longitude (WGS84) in traditional DD°MM'SS" notation
 * 4) Ten digit Open Location Code (aka. PlusCode) format
 * 5) Ten digit Geohash format
 * 
 * (please also refer to the notes on precision below)
 *
 * Editing Mode
 * ============
 * 
 * A LONG PRESS of the LIGHT button toggles editing mode for each of the selected notations.
 * 
 * In this mode LIGHT moves the cursor and ALARM changes the letter cycling through the available
 * alphabet or numbers. Another LONG PRESS of LIGHT saves the changes, a LONG PRESS of ALARM discards
 * them.
 * 
 * Swapping Places
 * ===============
 * 
 * This is inspired by the Casio FA-1500 World Time watch where you can swap the current timezone
 * with another one while traveling simply by pressing two of the available buttons simultaneously.
 * 
 * When one of the places 2 - 5 is selected, pressing and holding ALARM and then pressing LIGHT
 * swaps the place with slot 1 and saving it as active location across all watch faces.
 * 
 * (When in Place Name display mode, simply LONG PRESSING ALARM does the same thing)
 * 
 * Auxiliary Modes
 * ===============
 * 
 * A LONG PRESS of the ALARM button toggles one of two auxiliary functions when displaying
 * one of the coordinate formats (LAP indicator turns on):
 * 
 * 1) DIGIT INFO when Open Location Code or Geohash are selected.
 * 2) REMAIN when any of the Latitude and Longitude modes are selected.
 * 
 * Auxiliary Mode: Digit Info
 * ==========================
 * 
 * To work around the limitation of how ambiguously alphanumeric characters are displayed on 
 * the main seven segment digits of the watch face ( S or 5, G or 6?) Digit Info mode can be 
 * activated when in OLC or Geohash mode (shows LAP when toggled).
 * 
 * Now the LIGHT button can be used to flip through the alphaumeric letters. The selected one
 * is now also shown in the much easier to read alphanumeric 8 segment weekday digit above.
 * In addition the '24H' indicator is active when the selected digit represents a number and 
 * the 'PM' indicator for a letter. 
 * 
 * This mode is also automatically activated when editing an OLC or Geohash code.
 * 
 * Auxiliary Mode: Remain
 * ======================
 * 
 * When this mode (LAP) is activated on the decimal or DMS Latitude & Longitude modes the 
 * automatic switching to the next place when pressing ALARM is prevented.
 * 
 * Instead the display remains at the current place and ALARM cycles the available screens
 * for easier recollection of the available coordinate information.
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