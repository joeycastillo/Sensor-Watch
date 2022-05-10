#!/bin/bash

fw_dir="firmware/download"
sim_dir="firmware/simulate"
colors=("green" "blue")
variants=("standard" "alt_time" "deep_space_now" "focus" "the_athlete" "the_backpacker" "the_stargazer")

if [ -d "$fw_dir" ] ; then
    rm -r "$fw_dir"
fi
if [ -d "$sim_dir" ] ; then
    rm -r "$sim_dir"
fi

mkdir -p "$fw_dir"
mkdir -p "$sim_dir"

for variant in "${variants[@]}"
do
    VARIANT=$(echo "$variant" | tr '[:lower:]' '[:upper:]')
    for color in "${colors[@]}"
    do
        COLOR=$(echo "$color" | tr '[:lower:]' '[:upper:]')
        make clean
        make LED=$COLOR FIRMWARE=$VARIANT
        mv "build/watch.uf2" "$fw_dir/$variant-$color.uf2"
    done
    make clean
    emmake make FIRMWARE=$VARIANT
    mkdir "$sim_dir/$variant/"
    mv "build/watch.wasm" "$sim_dir/$variant/"
    mv "build/watch.js" "$sim_dir/$variant/"
    mv "build/watch.html" "$sim_dir/$variant/index.html"
done

echo "Done."
