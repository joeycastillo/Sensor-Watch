=============
Sleep Manager
=============

The sleep manager is the middle-ware which provides means to control the sleep of
an MCU by multiple software modules.

The sleep manager uses publish-subscribe pattern to ask subscribers if they are
ready to sleep and to notify them about preparation to sleep and waking up.

If any of the subscribers is not ready to go to sleep, an MCU may stay in active
mode. To let the sleep manager know that a software module is not ready to sleep,
the parameter passed to callback must to set to false. No additional action is
required from the software module to state that it is ready to go to sleep.
Notification about waking up is delivered to all subscribers with information
about wake-up reason.

There are currently only two wake-up reasons: internal interrupt and external
interrupt. It is up to the user to extend this list if required.

Features
--------

* Sleep control
* Notifications:
	* ready to sleep
	* preparation to sleep
	* waking up

Dependencies
------------

* The sleep driver

Limitations
-----------

* Only two wake-up reasons are supported by default
