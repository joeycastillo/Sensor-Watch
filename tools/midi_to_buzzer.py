#!/usr/bin/env python3
"""
MIDI to Sensor Watch Buzzer Sequence Converter

Converts a standard MIDI file to a C array of BUZZER_NOTE_* values
suitable for use with watch_buzzer_play_sequence().

Usage:
    python3 midi_to_buzzer.py <input.mid> [options]

Options:
    --track N       Select track N (0-based, default: auto-detect melody track)
    --tempo-scale F Scale tempo by factor F (default: 1.0, >1 = slower, <1 = faster)
    --max-notes N   Limit output to first N notes (default: unlimited)
    --transpose N   Transpose by N semitones (default: 0)
    --name NAME     Variable name for the C array (default: _melody_sequence)
    --list-tracks   List all tracks and their info, then exit
"""

import struct
import sys
import argparse

# BUZZER_NOTE enum names indexed by (midi_note - 33)
# MIDI 33 = A1 = enum 0, up to MIDI 119 = B8 = enum 86
BUZZER_NOTE_NAMES = []

def _build_note_names():
    """Build the mapping from enum index to BUZZER_NOTE_* string."""
    note_names_in_octave = [
        ('A', None),
        ('A', 'B'),    # A#/Bb
        ('B', None),
        ('C', None),
        ('C', 'D'),    # C#/Db
        ('D', None),
        ('D', 'E'),    # D#/Eb
        ('E', None),
        ('F', None),
        ('F', 'G'),    # F#/Gb
        ('G', None),
        ('G', 'A'),    # G#/Ab
    ]

    for midi_note in range(33, 120):  # A1 through B8
        # note_in_octave: 0=C, 1=C#, ..., 9=A, 10=A#, 11=B
        note_in_octave = midi_note % 12
        octave = (midi_note // 12) - 1

        # Map from MIDI's C-based indexing to our note names
        # MIDI: 0=C, 1=C#, 2=D, 3=D#, 4=E, 5=F, 6=F#, 7=G, 8=G#, 9=A, 10=A#, 11=B
        midi_to_idx = [3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2]
        idx = midi_to_idx[note_in_octave]

        name_info = note_names_in_octave[idx]

        if name_info[1] is None:
            # Natural note
            BUZZER_NOTE_NAMES.append(f"BUZZER_NOTE_{name_info[0]}{octave}")
        else:
            # Sharp/flat
            sharp_note = name_info[0]
            flat_note = name_info[1]
            # For A#/Bb, G#/Ab etc., the sharp and flat are in the same octave
            # But for notes like G#/Ab where G# is in one octave context:
            # The octave follows the MIDI convention
            sharp_oct = octave
            flat_oct = octave
            # Special case: A# and B are in the same octave, but Bb could be thought
            # of differently. In the enum, it's named by the octave of the base note.
            # e.g., MIDI 34 = A#1/Bb1 → BUZZER_NOTE_A1SHARP_B1FLAT
            # The enum uses the natural note's octave for both parts
            if sharp_note == 'G' and flat_note == 'A':
                # G#4/Ab4 - same octave
                pass
            elif sharp_note == 'A' and flat_note == 'B':
                # A#4/Bb4 - same octave
                pass

            BUZZER_NOTE_NAMES.append(
                f"BUZZER_NOTE_{sharp_note}{sharp_oct}SHARP_{flat_note}{flat_oct}FLAT"
            )

_build_note_names()


def midi_note_to_buzzer(midi_note):
    """Convert MIDI note number to BUZZER_NOTE_* enum name."""
    idx = midi_note - 33
    if idx < 0 or idx >= len(BUZZER_NOTE_NAMES):
        return None
    return BUZZER_NOTE_NAMES[idx]


def read_variable_length(data, offset):
    """Read a MIDI variable-length quantity."""
    value = 0
    while True:
        byte = data[offset]
        offset += 1
        value = (value << 7) | (byte & 0x7F)
        if not (byte & 0x80):
            break
    return value, offset


def parse_midi(filepath):
    """Parse a MIDI file and return header info and tracks."""
    with open(filepath, 'rb') as f:
        data = f.read()

    # Parse header
    if data[0:4] != b'MThd':
        raise ValueError("Not a valid MIDI file")

    header_len = struct.unpack('>I', data[4:8])[0]
    fmt, num_tracks, ticks_per_beat = struct.unpack('>HHH', data[8:14])

    tracks = []
    offset = 8 + header_len

    for t in range(num_tracks):
        if data[offset:offset+4] != b'MTrk':
            raise ValueError(f"Expected MTrk at offset {offset}")
        track_len = struct.unpack('>I', data[offset+4:offset+8])[0]
        track_data = data[offset+8:offset+8+track_len]
        tracks.append(track_data)
        offset += 8 + track_len

    return fmt, num_tracks, ticks_per_beat, tracks


def extract_events(track_data):
    """Extract MIDI events from a track."""
    events = []
    offset = 0
    running_status = None
    track_name = None

    while offset < len(track_data):
        delta, offset = read_variable_length(track_data, offset)

        if offset >= len(track_data):
            break

        status = track_data[offset]

        if status == 0xFF:
            # Meta event
            offset += 1
            meta_type = track_data[offset]
            offset += 1
            length, offset = read_variable_length(track_data, offset)
            meta_data = track_data[offset:offset+length]
            offset += length

            if meta_type == 0x03:
                # Track name
                try:
                    track_name = meta_data.decode('ascii', errors='replace')
                except:
                    track_name = repr(meta_data)
            elif meta_type == 0x51:
                # Tempo
                tempo = (meta_data[0] << 16) | (meta_data[1] << 8) | meta_data[2]
                events.append(('tempo', delta, tempo))
            elif meta_type == 0x2F:
                # End of track
                events.append(('end', delta, None))
                break
            else:
                events.append(('meta', delta, (meta_type, meta_data)))

        elif status == 0xF0 or status == 0xF7:
            # SysEx
            offset += 1
            length, offset = read_variable_length(track_data, offset)
            offset += length

        elif status & 0x80:
            # Regular MIDI event
            offset += 1
            running_status = status
            event_type = (status >> 4) & 0x0F
            channel = status & 0x0F

            if event_type == 0x09:
                # Note On
                note = track_data[offset]; offset += 1
                velocity = track_data[offset]; offset += 1
                if velocity == 0:
                    events.append(('note_off', delta, (channel, note, 0)))
                else:
                    events.append(('note_on', delta, (channel, note, velocity)))
            elif event_type == 0x08:
                # Note Off
                note = track_data[offset]; offset += 1
                velocity = track_data[offset]; offset += 1
                events.append(('note_off', delta, (channel, note, velocity)))
            elif event_type == 0x0A:
                # Aftertouch
                offset += 2
            elif event_type == 0x0B:
                # Control Change
                offset += 2
            elif event_type == 0x0C:
                # Program Change
                offset += 1
            elif event_type == 0x0D:
                # Channel Pressure
                offset += 1
            elif event_type == 0x0E:
                # Pitch Bend
                offset += 2
            else:
                offset += 2  # default: skip 2 bytes
        else:
            # Running status
            if running_status is None:
                offset += 1
                continue

            event_type = (running_status >> 4) & 0x0F
            channel = running_status & 0x0F

            if event_type == 0x09:
                note = track_data[offset]; offset += 1
                velocity = track_data[offset]; offset += 1
                if velocity == 0:
                    events.append(('note_off', delta, (channel, note, 0)))
                else:
                    events.append(('note_on', delta, (channel, note, velocity)))
            elif event_type == 0x08:
                note = track_data[offset]; offset += 1
                velocity = track_data[offset]; offset += 1
                events.append(('note_off', delta, (channel, note, velocity)))
            elif event_type == 0x0A:
                offset += 2
            elif event_type == 0x0B:
                offset += 2
            elif event_type == 0x0C:
                offset += 1
            elif event_type == 0x0D:
                offset += 1
            elif event_type == 0x0E:
                offset += 2
            else:
                offset += 1

    return events, track_name


def events_to_buzzer_sequence(events, ticks_per_beat, tempo_scale=1.0, transpose=0, max_notes=None):
    """Convert MIDI events to buzzer note/duration pairs."""
    # Default tempo: 120 BPM = 500000 microseconds per beat
    us_per_beat = 500000

    # Build absolute-time event list
    abs_time = 0
    abs_events = []
    for ev in events:
        abs_time += ev[1]
        abs_events.append((abs_time, ev[0], ev[2]))

    # Extract note on/off pairs
    active_notes = {}  # note -> (start_time, velocity)
    note_pairs = []    # (start_tick, end_tick, midi_note, velocity)
    tempo_changes = [(0, us_per_beat)]

    for abs_t, ev_type, ev_data in abs_events:
        if ev_type == 'tempo':
            tempo_changes.append((abs_t, ev_data))
        elif ev_type == 'note_on':
            ch, note, vel = ev_data
            active_notes[note] = (abs_t, vel)
        elif ev_type == 'note_off':
            ch, note, vel = ev_data
            if note in active_notes:
                start_t, start_vel = active_notes.pop(note)
                note_pairs.append((start_t, abs_t, note, start_vel))

    # Sort by start time
    note_pairs.sort(key=lambda x: x[0])

    def ticks_to_64hz(start_tick, end_tick):
        """Convert MIDI tick range to duration in 64Hz ticks."""
        # Find the active tempo at start_tick
        active_tempo = us_per_beat
        for t, tempo in tempo_changes:
            if t <= start_tick:
                active_tempo = tempo
            else:
                break

        midi_ticks = end_tick - start_tick
        seconds = (midi_ticks / ticks_per_beat) * (active_tempo / 1_000_000) * tempo_scale
        hz64_ticks = int(round(seconds * 64))
        return max(1, min(127, hz64_ticks))  # clamp to int8_t range

    # Generate buzzer sequence
    sequence = []
    last_end = 0
    count = 0

    for start_t, end_t, midi_note, velocity in note_pairs:
        if max_notes and count >= max_notes:
            break

        # Add rest if there's a gap
        gap = start_t - last_end
        if gap > 0:
            rest_dur = ticks_to_64hz(last_end, start_t)
            if rest_dur > 0:
                sequence.append(('BUZZER_NOTE_REST', rest_dur))

        # Add note
        transposed = midi_note + transpose
        buzzer_name = midi_note_to_buzzer(transposed)
        if buzzer_name is None:
            # Out of range, skip
            continue

        dur = ticks_to_64hz(start_t, end_t)
        sequence.append((buzzer_name, dur))
        last_end = end_t
        count += 1

    return sequence


def format_c_array(sequence, var_name="_melody_sequence"):
    """Format a buzzer sequence as a C array."""
    lines = [f"static const int8_t {var_name}[] = {{"]

    max_name_len = max(len(note) for note, dur in sequence) if sequence else 0

    for note, dur in sequence:
        padding = ' ' * (max_name_len - len(note))
        lines.append(f"    {note},{padding} {dur},")

    lines.append("")
    lines.append("    BUZZER_NOTE_REST, 16,")
    lines.append("")
    lines.append("    0 // end")
    lines.append("};")

    return '\n'.join(lines)


def list_tracks(filepath):
    """List all tracks in a MIDI file."""
    fmt, num_tracks, ticks_per_beat, tracks = parse_midi(filepath)
    print(f"MIDI Format: {fmt}")
    print(f"Tracks: {num_tracks}")
    print(f"Ticks per beat: {ticks_per_beat}")
    print()

    for i, track_data in enumerate(tracks):
        events, track_name = extract_events(track_data)
        note_count = sum(1 for e in events if e[0] == 'note_on')
        note_range = []
        for e in events:
            if e[0] == 'note_on':
                note_range.append(e[2][1])

        if note_range:
            lo = min(note_range)
            hi = max(note_range)
            lo_name = midi_note_to_buzzer(lo) or f"MIDI {lo}"
            hi_name = midi_note_to_buzzer(hi) or f"MIDI {hi}"
            print(f"  Track {i}: {track_name or '(unnamed)'} - {note_count} notes, range {lo_name} to {hi_name}")
        else:
            print(f"  Track {i}: {track_name or '(unnamed)'} - {note_count} notes (tempo/meta only)")


def auto_select_track(tracks):
    """Auto-select the most likely melody track (highest note count in a reasonable range)."""
    best_track = 0
    best_score = -1

    for i, track_data in enumerate(tracks):
        events, _ = extract_events(track_data)
        note_count = sum(1 for e in events if e[0] == 'note_on')
        # Prefer tracks with notes in the melody range (C4-C7)
        melody_notes = sum(1 for e in events if e[0] == 'note_on' and 60 <= e[2][1] <= 96)
        score = note_count + melody_notes * 2  # weight melody range notes
        if score > best_score:
            best_score = score
            best_track = i

    return best_track


def main():
    parser = argparse.ArgumentParser(description='Convert MIDI to Sensor Watch buzzer sequence')
    parser.add_argument('input', help='Input MIDI file')
    parser.add_argument('--track', type=int, default=None, help='Track number (0-based)')
    parser.add_argument('--tempo-scale', type=float, default=1.0, help='Tempo scale factor')
    parser.add_argument('--max-notes', type=int, default=None, help='Max notes to include')
    parser.add_argument('--transpose', type=int, default=0, help='Transpose by N semitones')
    parser.add_argument('--name', default='_melody_sequence', help='C variable name')
    parser.add_argument('--list-tracks', action='store_true', help='List tracks and exit')

    args = parser.parse_args()

    if args.list_tracks:
        list_tracks(args.input)
        return

    fmt, num_tracks, ticks_per_beat, tracks = parse_midi(args.input)

    track_idx = args.track
    if track_idx is None:
        track_idx = auto_select_track(tracks)
        events, track_name = extract_events(tracks[track_idx])
        print(f"// Auto-selected track {track_idx}: {track_name or '(unnamed)'}", file=sys.stderr)
    else:
        events, track_name = extract_events(tracks[track_idx])

    # If format 1, merge tempo events from track 0
    if fmt == 1 and track_idx != 0:
        tempo_events, _ = extract_events(tracks[0])
        tempo_only = [e for e in tempo_events if e[0] == 'tempo']
        events = tempo_only + events

    sequence = events_to_buzzer_sequence(
        events, ticks_per_beat,
        tempo_scale=args.tempo_scale,
        transpose=args.transpose,
        max_notes=args.max_notes
    )

    if not sequence:
        print("No notes found in the selected track.", file=sys.stderr)
        sys.exit(1)

    print(f"// Source: {args.input}, track {track_idx}" +
          (f" ({track_name})" if track_name else ""))
    print(f"// {len(sequence)} note/rest entries")
    print(format_c_array(sequence, args.name))


if __name__ == '__main__':
    main()
