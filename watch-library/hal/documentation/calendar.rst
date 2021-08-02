===============================
The Calendar driver (bare-bone)
===============================

The Calendar driver provides means to set and get current date and time.
After enabling, an instance of the driver starts counting time from the base date with
the resolution of one second. The default base date is 00:00:00 1st of January 1970.
Only the base year of the base date can be changed via the driver API.

The current date and time is kept internally in a relative form as the difference between
current date and time and the base date and time. This means that changing the base year changes
current date.

The base date and time defines time "zero" or the earliest possible point in time that the calender driver can describe,
this means that current time and alarms can not be set to anything earlier than this time.

The Calendar driver provides alarm functionality.
An alarm is a software trigger which fires on particular date and time with particular periodicity.
Upon firing the given callback function is called.

An alarm can be in single-shot mode, firing only once at matching time; or in repeating mode, meaning that it will
reschedule a new alarm automatically based on repeating mode configuration.
In single-shot mode an alarm is removed from the alarm queue before its callback is called. It allows an application to
reuse the memory of expired alarm in the callback.

An alarm can be triggered on the following events: match on second, minute, hour, day, month or year.
Matching on second means that the alarm is triggered when the value of seconds of the current time is equal to
the alarm's value of seconds. This means repeating alarm with match on seconds is triggered with the period of a minute.
Matching on minute means that the calendars minute and seconds values has to match the alarms, the rest of the date-time
value is ignored. In repeating mode this means a new alarm every hour.
The same logic is applied to match on hour, day, month and year.

Each instance of the Calendar driver supports infinite amount of software alarms, only limited by the amount of RAM available.

Features
--------
* Initialization and de-initialization
* Enabling and disabling
* Date and time operations
* Software alarms

Applications
------------
* A source of current date and time for an embedded system.
* Periodical functionality in low-power applications since the driver is designed to use 1Hz clock.
* Periodical function calls in case if it is more convenient to operate with absolute time.

Dependencies
------------
* This driver expects a counter to be increased by one every second to count date and time correctly.
* Each instance of the driver requires separate hardware timer.

Concurrency
-----------
The Calendar driver is an interrupt driven driver.This means that the interrupt that triggers an alarm may occur during
the process of adding or removing an alarm via the driver's API. In such case the interrupt processing is postponed
until the alarm adding or removing is complete.

The alarm queue is not protected from the access by interrupts not used by the driver. Due to this
it is not recommended to add or remove an alarm from such interrupts: in case if a higher priority interrupt supersedes
the driver's interrupt, adding or removing an alarm may cause unpredictable behavior of the driver.

Limitations
-----------
* Only years divisible by 4 are deemed a leap year, this gives a correct result between the years 1901 to 2099.
* The driver is designed to work outside of an operating system environment, the software alarm queue is therefore processed in interrupt context which may delay execution of other interrupts.
* If there are a lot of frequently called interrupts with the priority higher than the driver's one, it may cause delay in alarm's triggering.
* Changing the base year or setting current date or time does not shift alarms' date and time accordingly or expires alarms.

Knows issues and workarounds
----------------------------
Not applicable
