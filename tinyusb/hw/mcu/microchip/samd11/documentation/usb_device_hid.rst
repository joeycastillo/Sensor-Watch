==============
USB Device HID
==============

USB Device HID is a part of the USB Device Stack library. It provides support for
USB Keyboard and Mouse implementation. Furthermore, it also gives a group of generic
API for user to implement a customized HID compliant device. For more detailed
definition and description about this class, user can refer to <Device Class Definition
for Human Interface Devices (HID), Vision 1.11>

Features
--------

* Initialization/de-initialization.
* Notifications about key state change for HID Keyboard.
* Notifications about button state change for HID Mouse.
* Notifications about mouse pointer move for HID Mouse.
* Data transfer for HID Generic.
* Callbacks management for HID Generic on:

  * Transmission done
  * Reception done
  * Setting a new report

Applications
------------

* Used as a HID Keyboard.
* Used as a HID Mouse.
* Used as a customized HID compliant device.


Dependencies
------------

* USB Device Driver
* USB Device Stack Core
* USB Protocol HID


Limitations
-----------

* If user wants to combine HID with other classes into one device, USB
  Device Stack Composite component should be added from the web page
  rather than USB Device Stack HID Keyboard/Mouse/Generic.




