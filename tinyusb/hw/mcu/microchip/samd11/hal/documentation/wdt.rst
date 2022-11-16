Watchdog Timer Driver
=====================

The Watchdog Timer(WDT) is a system function for monitoring correct operation.

WDT makes it possible to recover from error situations such as runway or
deadlocked code. The WDT is configured to a predefined time-out period, and
is constantly running when enabled. If the WDT is not reset within the
time-out period, it will issue a system reset.

Features
--------

* Initialization/de-initialization
* Enabling/disabling
* Resetting the watchdog(wdt_feed)
* Time-out period set/get

Applications
------------

Provides a means of recovering from a hardware or software fault stopping the
application from resetting the watchdog.

Dependencies
------------

N/A

Concurrency
-----------

N/A

Limitations
-----------
Available time-out period is device specific, user must refer the
corresponding device to set the time-out period.

Time-out period can not be changed when WDT is enabled.

Known issues and workarounds
----------------------------

N/A
