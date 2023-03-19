# The Sensor Watch

### Settings watch-face for location coordinate management

fork of [Sensor Watch](https://github.com/joeycastillo/Sensor-Watch/)

## Work in Progress

* Decimal Latitude & Longitude support to up to 5 decimal digits (~10m accuracy)
* Support for Latitude & Longitude in Degrees, Minutes, Seconds (~50m accuracy)
* 5 Locations with custom 6 letter names
* Open Location Code support for 10 digits (~10m accuracy)

## To do

* memory optimization
* documentation
* simplified button logic:
    * ALARM: switch PLACE/DD/DMS/OLC/GH
    * LIGHT: switch places (edit: digits)
    * LONG LIGHT: switch to edit mode
    * LONG ALARM:
        * PLACE: switch to DATA
        * DD/DMS: switch to just toggle between DD/DMS
        * OL/GH: switch to help mode
