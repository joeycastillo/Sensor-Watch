"""
Turn gdb dump of uv readings from UV sensor watch into file

Assumes the gdb file contains uint_32t of each reading
"""

import argparse
import base64
import datetime
import json
import struct
import statistics

def main(filename: str, sw_gain: int, hw_gain: int, uvi: int, recorded_at: datetime.datetime):
    with open(filename, "rb") as f:
        buffer = f.read()
    readings = [s[0] for s in struct.iter_unpack("<L", buffer)]

    session = {
            "recorded_at": recorded_at.isoformat(),
            "uvi": uvi,
            "sw_gain": sw_gain,
            "hw_gain": hw_gain,
            "derived": {
                "min": min(readings),
                "max": max(readings),
                "mean": statistics.mean(readings),
                "mode": statistics.mode(readings),
                "stdev": statistics.stdev(readings),
                "variance": statistics.variance(readings),
            },
            "raw_readings": readings,
            "raw_dump": base64.b64encode(buffer).decode("utf-8"),
    }
    print("stats: ", session["derived"])
    parsed_filename = f"sessions/{recorded_at.strftime('%Y-%m-%d-%H-%M')}_uvi-{uvi}.json"
    with open(parsed_filename, "x") as out:
        json.dump(session, out)
    print("Wrote to ", parsed_filename)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog = 'Sensorwatch UV Calibration')
    parser.add_argument('raw_readings', help="Raw file containing readings from GDB")           # positional argument
    parser.add_argument("--sw_gain", help="The software gain setting used", required=True, type=int)
    parser.add_argument("--hw_gain", help="The hardware gain used", required=True, type=int)
    parser.add_argument("--uvi", help="The apparent UV index (from https://www.theweathernetwork.com/en/marine/ca/prince-edward-island/skinners-pond/uv", required=True, type=float)
    parser.add_argument("--recorded_at", type=datetime.datetime.fromisoformat, help='ISOformat - YYYY-MM-DD:HH:mm:ss', default=datetime.datetime.now())
    args = parser.parse_args()
    main(args.raw_readings, args.sw_gain, args.hw_gain, args.uvi, args.recorded_at)

