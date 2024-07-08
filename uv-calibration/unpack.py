"""
Turn gdb dump of uv readings from UV sensor watch into file
"""

import argparse
import struct

def main(filename: str):
    with open(filename, "rb") as f:
        buffer = f.read()
    readings = [s[0] for s in struct.iter_unpack("<H", buffer)]
    print(*readings, sep="\n")

if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog = 'ProgramName')
    parser.add_argument('filename')           # positional argument
    args = parser.parse_args()
    main(args.filename)

