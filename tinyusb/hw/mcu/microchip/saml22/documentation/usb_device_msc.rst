==============
USB Device MSC
==============

USB Device MSC is a part of the USB Device Stack library. It provides support for
mass storage design. For more detailed definition and description about this class,
user can refer to Mass Storage Control/Bulk/Interrupt (CBI) Specification 1.1, Mass
Storage UFI Command Specification 1.0 and USB Attached SCSI Protocol (UASP) v1.0.

Features
--------

* Initialization/de-initialization.
* Data transfer between USB and RAM.
* Callbacks management for MSC on:

  * Inquirying disk information
  * Getting disk capacity
  * Starting disk read process
  * Starting disk write process
  * Ejecting disk
  * Testing disk status
  * Data transfer done

Applications
------------

* Used as a mass storage such as removable disk.

Dependencies
------------

* USB Device Driver
* USB Device Stack Core
* USB Protocol MSC


Limitations
-----------

* N/A
