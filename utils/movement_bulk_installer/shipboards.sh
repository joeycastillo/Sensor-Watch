#!/bin/bash
RED='\033[0;101m'
GREEN='\033[1;32m'
END='\033[0m'
while [ true ] ; do
    echo "Waiting for board"
    false
    while [ true ] ; do
        stat /Volumes/WATCHBOOT &> /dev/null
        if [ $? -eq 0 ]
        then
            break
        fi
        sleep 0.5
    done
    sleep 0.5
    clear
    cp ./standard-red.uf2 /Volumes/WATCHBOOT/
    if [ $? -eq 0 ]
    then
        echo -e "${GREEN}Success!${END} Board flashed successfully!"
    else
        echo -e "${RED}FAILURE:${END} Board did not flash successfully."
        echo -ne '\a'
        echo -ne '\a'
    fi
    while [ true ] ; do
        stat /Volumes/WATCHBOOT &> /dev/null
        if [ $? -eq 0 ]
        then
            sleep 0.5
        else
            break
        fi
    done
    echo -ne '\a'
done
