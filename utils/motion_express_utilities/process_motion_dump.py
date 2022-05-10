#!/usr/bin/env python3
import sys
from pathlib import Path

if not sys.stdin.isatty():
    input_stream = sys.stdin

else:
    try:
        input_filename = sys.argv[1]
    except IndexError:
        message = 'need filename as first argument if stdin is not full'
        raise IndexError(message)
    else:
        input_stream = open(input_filename, 'r')

Path("output/plots").mkdir(parents=True, exist_ok=True)

s = open(f'output/makeplots.sh', 'w')
f = None
num_events = 0
num_records = 0

for line in input_stream:
    if not len(line):
        continue
    if line.strip() == '=== END ===':
        if f is not None:
            f.close()
    elif line.upper().strip().endswith('.CSV'):
        num_events += 1
        components = line.strip().split('.')[:-1]
        if components[0] == 'TE':
            components[0] = 'testing'
        elif components[0] == 'ID':
            components[0] = 'idle'
        elif components[0] == 'OF':
            components[0] = 'off_wrist'
        elif components[0] == 'SL':
            components[0] = 'sleeping'
        elif components[0] == 'WH':
            components[0] = 'washing_hands'
        elif components[0] == 'WA':
            components[0] = 'walking'
        elif components[0] == 'WB':
            components[0] = 'walking_with_beverage'
        elif components[0] == 'JO':
            components[0] = 'jogging'
        elif components[0] == 'RU':
            components[0] = 'running'
        elif components[0] == 'BI':
            components[0] = 'biking'
        elif components[0] == 'HI':
            components[0] = 'hiking'
        elif components[0] == 'EL':
            components[0] = 'elliptical'
        elif components[0] == 'SU':
            components[0] = 'stairs_up'
        elif components[0] == 'SD':
            components[0] = 'stairs_down'
        elif components[0] == 'WL':
            components[0] = 'weight_lifting'
        name = '.'.join(components).lower().replace('_', '-')
        s.write(f'../csv2gnuplot.sh -i "{name}.csv" -O "./plots/{name}.png"  -g "{name}.gnuplot" -F png -W 1200 -H 675 -e -l -G ../plot.options && rm "{name}.gnuplot"\n')
        if f is not None:
            f.close()
        f = open(f'output/{name}.csv', 'w')
    else:
        num_records += 1
        f.write(line)

s.close()

print(f"Processed {num_records} records in {num_events} events!")
print("To generate plots: cd output && bash makeplots.sh")