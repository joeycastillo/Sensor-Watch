#!/bin/bash

LAT="46.97"
LON="-64.10"
ALT="16"

OPENUV_API_KEY="openuv-5rtarlzefb7lr-io"
PIRATE_WEATHER_API_KEY="3s61kZ7eFhtuK98DXZ1vF7ztWanCWHqU"

NOW=$(date +%Y-%m-%d-%H-%M)

curl -sS -X GET "https://api.openuv.io/api/v1/uv?lat=$LAT&lng=$LON&alt=$ALT&dt=" \
                                        -H 'x-access-token: $OPENUV_API_KEY' \
                                        -o "weather/openuv-$NOW.json"

curl -sS "https://api.pirateweather.net/forecast/$PIRATE_WEATHER_API_KEY/$LAT,$LON?excluse=minutely,hourly,daily,alerts" \
    -o "weather/pirateweather-$NOW.json"

jq .currently.uvIndex < "weather/pirateweather-$NOW.json"
