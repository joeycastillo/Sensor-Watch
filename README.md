# The Sensor Watch

### Settings watch-face for location coordinate management

fork of [Sensor Watch](https://github.com/joeycastillo/Sensor-Watch/)

## Places

Based on and expanded from the Sunrise/Sunset face. Initially just intended to outsource 
the location setting functionality to its own face it has become an advanced managing
application for location data.

Using the ALARM button the user can flip through 5 available place slots.

With the LIGHT button each place coordinate can be shown and edited in 5 different display modes:

1. Place Name
2. Decimal Latitude and Longitude (WGS84) up to 5 decimal points
3. Latitude and Longitude (WGS84) in traditional DD°MM'SS" notation
4. Ten digit Open Location Code (aka. PlusCode) format
5. Ten digit Geohash format

(please also refer to the notes on precision below)

A LONG PRESS of the LIGHT button toggles editing mode for each of the selected notations.

A LONG PRESS of the ALARM button toggles DATA import/export mode when Place Name or one of the
Latitude/Longitude notations are selected. It toggles Digit Info auxiliary modes when 
Open Location Code or Geohash are selected.

### Data Import and Export

In this mode ALARM toggles between File and Registry and LIGHT toggles between 'R'ead and 'W'rite.

Coordinates can be read into the selected place slot either from the traditional internal
register or from a file on the LFS file system (`place.loc`).

When 'W'rite is active the current place coordinate can be saved in the selected destination.

The actual read/write operation is triggered by LONG PRESS of the LIGHT button.

### Digit Info Auxiliary Mode

The Open Location Code and Geohash notations employ ten digits of alphanumeric characters.
Due to the limited nature of the seven segment display, some of the characters appear
ambiguous. For example it is unclear whether a digit represents a 5 or an S, a 6 or a G.

To work around this limitation Digit Info can be activated when in OLC or Geohash mode.

The LAP indicator is active when in this mode. Now the LIGHT button can be used to flip 
through the alphaumeric letters and the selected one is also shown in the much easier
to read alphanumeric 8 segment weekday digit above. In addition the '24H' indicator is
active when the selected digit represents a number and the 'PM' indicator for a letter.

This mode is also automatically activated when editing an OLC or Geohash code.

### Notes on Coordinate Precision

A general limitation of the common WGS84 Latitude and Longitude system is that its degrees
do not translate 1:1 to meters in distance on the ground. 1° Longitude on the equator equals
a width of 111.32 kilometers, but at 40° latitude it is approximately 85 kilometers wide. The
closer to the poles the narrower (and more precise) the latitude degrees get.

The Sensor Watch's traditional 16bit location register only stores latitudes and longitudes 
with two decimal points to make them fit. That equals a longitudal precision of 36 seconds
of a degree, or ~1111 meters at the equator - precise enough for astronomical calculations, 
but not if you want to store the location of a building, for example.

Hence we propose the `place.loc` file that serves the same purpose, but with five decimal digits.
That equals 0.04 seconds of a longitudal degree, or a precision of 1.11 meters at the equator.

The different notations which this watch face offers also have varying magnitudes of precision:

In contrast to the aforementioned default decimal notation, coordinates entered in traditional
full Degrees, Minutes, and Seconds naturally have only a max. resolution of 1 second of a degree,
which equals a precision of ~31 meters.

Both, Open Location Code and Geohash standards support different lengths. The default OLC length 
is ten. which translates to 0.45 seconds of a degree - or ~14 meters longitude at the equator.
The same amount of digits in a Geohash allows to encode coordinates with a ten times higher
precision of around 1.2 meters in longitude at the equator.

Since all notations are internally converted into degrees with 5 decimal points, expect some
rounding errors when editing or loading the coordinates in other notation formats.

| Format | Notation | Precision 0° N/S | Precision 67° N/S |
| :--- | :--- | ---: | ---: |
| Decimal LatLon | DDD.DDDDD | 1.11 m | 0.435 m |
| DMS LatLon | DD°MM'SS" | 30.833 m | 12.083  m |
| OLC | 2C3F4G5H+6J | 13.875 m | 13.875 m |
| Geohash | 0b1c2d3e4f | 1.19 m | 0.596 m |
