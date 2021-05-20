=========
TC driver
=========
The TC consists of a counter, a prescaler, compare/capture channels and control logic. The counter can be set to count events, or it can be configured to count clock pulses. The counter, together with the compare/capture channels, can be configured to timestamp input events, allowing capture of frequency and pulse width. It can also perform waveform generation, such as frequency generation and pulse-width modulation (PWM) 

The timer/counter is clocked by the peripheral clock with optional prescaling or from the event system.

Features
--------
* Initialization

Applications
------------
* Frequency Generation
* Single-slope PWM (pulse width modulation)
* Dual-slope PWM
* Count on event
* Quadrature decoding

Dependencies
------------
* CLK for clock
* CPUINT/PMIC for Interrupt
* EVSYS for events
* UPDI/PDI/JTAG for debug
* PORT for Waveform Generation

Concurrency
-----------
N/A

Limitations
-----------
N/A

Knows issues and workarounds
----------------------------
N/A

