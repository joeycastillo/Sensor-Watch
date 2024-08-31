#!/bin/bash
set -e

# start JLink GBD server
echo "starting JLinkGDBServer in background"
nohup JLinkGDBServer -device ATSAML22J18A -if SWD &
sleep 5

arm-none-eabi-gdb <<EOF
set pagination off

target remote :2331
monitor halt
monitor reset 2
file ../movement/make/build/watch.elf
load

break save_history
command 1
p new_reading
append value raw/$(date +%Y-%m-%d-%H-%M).raw new_reading
continue
end

continue
EOF
