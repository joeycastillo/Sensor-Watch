
SLCD Synchronous driver
=======================

An LCD display is made of several segments (pixels or complete symbols) which
can be block light or let light through. In each segment is one electrode
connected to the common terminal (COM pin) and one is connected to the segment
terminal (SEG pin). When a voltage above a certain threshold level is applied
across the liquid crystal, it will change orientation and either let light
through or block it.

The driver supports segment on/off/blink, animation and character display.

Each segment has a unique int32 segment id which is used by the driver. The id is
combined by common number(COM) and segment number(SEG), the COM and SEG start from 0.
The unique segment id is calculated by this formula: (COM << 16) | SEG
For example a 8(coms)*8(segments)SLCD, the unique segment id for segment should be

    +-----+-----+---------+
    | COM | SEG |   ID    |
    +-----+-----+---------+
    |  0  |  0  | 0x00000 |
    +-----+-----+---------+
    |  1  |  0  | 0x10000 |
    +-----+-----+---------+
    |  7  |  7  | 0x70007 |
    +-----+-----+---------+

Segment ID can be calculated using the pre-defined macro SLCD_SEGID(com, seg).

For character display, the "segment character mapping table" and "character mapping table"
should be setup in configuration. The driver have no API to setup/change those
mapping setting.
There are two pre-defined "segment character mapping table" in this driver, 7 segments
and 14 segments. The 7 segment character mapping can display 0-9 and a-f, the 14
segments character mapping can display 0-9, A-Z and some special ASCII, for more
details please refer to hpl_slcd_cm_7_seg_mapping.h and hpl_slcd_cm_14_seg_mapping.h.
Application can also adjust this mapping table in the configuration header file,
to add more character mapping or remove some unused character.

The "character mapping" is used to setup each character in SLCD display screen.
The driver supports multiple character mapping, the max number varies on different
MCU/MPU. For example if an LCD display screen has five "7-segments character" and
eight "14-segments character", and the MCU support max 44 characters setting, then
the 13 character should be setup in configuration. Application can select any
position from those 44 characters setting to save those 13 character.
The index of character setting will be used in the driver API. For example:
five "7-segments character" setting to 0 to 4 and eight "14-segments character" setting
to 10 to 17. Then the application can use index from 0 to 4 to display the
"7-segments character" and use index from 10 to 14 to display "14-segments character".

Features
--------

* Initialization and de-initialization
* Enabling and Disabling
* Switching segment on/off
* Set segment blink
* Autonomous animation
* Character display

Applications
------------
* SLCD display control, segment on/off/blink
* Play battery animation, running wheel, wifi signal, etc.
* Display Time Clock by 7 segments character mapping
* Display ASCII character by 14 segments character mapping

Dependencies
------------
* SLCD capable hardware

Concurrency
-----------
N/A

Limitations
-----------

Known issues and workarounds
----------------------------
N/A
