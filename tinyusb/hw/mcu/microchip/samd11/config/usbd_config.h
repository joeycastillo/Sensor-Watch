/* Auto-generated config file usbd_config.h */
#ifndef USBD_CONFIG_H
#define USBD_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// ---- USB Device Stack Core Options ----

// <q> High Speed Support
// <i> Enable high speed specific descriptors support, e.g., DeviceQualifierDescriptor and OtherSpeedConfiguration Descriptor.
// <i> High speed support require descriptors description array on start, for LS/FS and HS support in first and second place.
// <id> usbd_hs_sp
#ifndef CONF_USBD_HS_SP
#define CONF_USBD_HS_SP 0
#endif

// ---- USB Device Stack CDC ACM Options ----

// <e> Enable String Descriptors
// <id> usb_cdcd_acm_str_en
#ifndef CONF_USB_CDCD_ACM_STR_EN
#define CONF_USB_CDCD_ACM_STR_EN 0
#endif
// <s> Language IDs
// <i> Language IDs in c format, split by comma (E.g., 0x0409 ...)
// <id> usb_cdcd_acm_langid
#ifndef CONF_USB_CDCD_ACM_LANGID
#define CONF_USB_CDCD_ACM_LANGID "0x0409"
#endif

#ifndef CONF_USB_CDCD_ACM_LANGID_DESC
#define CONF_USB_CDCD_ACM_LANGID_DESC
#endif
// </e>

// <h> CDC ACM Device Descriptor

// <o> bcdUSB
// <0x0200=> USB 2.0 version
// <0x0210=> USB 2.1 version
// <id> usb_cdcd_acm_bcdusb
#ifndef CONF_USB_CDCD_ACM_BCDUSB
#define CONF_USB_CDCD_ACM_BCDUSB 0x200
#endif

// <o> bMaxPackeSize0
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_cdcd_acm_bmaxpksz0
#ifndef CONF_USB_CDCD_ACM_BMAXPKSZ0
#define CONF_USB_CDCD_ACM_BMAXPKSZ0 0x40
#endif

// <o> idVender <0x0000-0xFFFF>
// <id> usb_cdcd_acm_idvender
#ifndef CONF_USB_CDCD_ACM_IDVENDER
#define CONF_USB_CDCD_ACM_IDVENDER 0x3eb
#endif

// <o> idProduct <0x0000-0xFFFF>
// <id> usb_cdcd_acm_idproduct
#ifndef CONF_USB_CDCD_ACM_IDPRODUCT
#define CONF_USB_CDCD_ACM_IDPRODUCT 0x2404
#endif

// <o> bcdDevice <0x0000-0xFFFF>
// <id> usb_cdcd_acm_bcddevice
#ifndef CONF_USB_CDCD_ACM_BCDDEVICE
#define CONF_USB_CDCD_ACM_BCDDEVICE 0x100
#endif

// <e> Enable string descriptor of iManufact
// <id> usb_cdcd_acm_imanufact_en
#ifndef CONF_USB_CDCD_ACM_IMANUFACT_EN
#define CONF_USB_CDCD_ACM_IMANUFACT_EN 0
#endif

#ifndef CONF_USB_CDCD_ACM_IMANUFACT
#define CONF_USB_CDCD_ACM_IMANUFACT (CONF_USB_CDCD_ACM_IMANUFACT_EN * (CONF_USB_CDCD_ACM_IMANUFACT_EN))
#endif

// <s> Unicode string of iManufact
// <id> usb_cdcd_acm_imanufact_str
#ifndef CONF_USB_CDCD_ACM_IMANUFACT_STR
#define CONF_USB_CDCD_ACM_IMANUFACT_STR "Atmel"
#endif

#ifndef CONF_USB_CDCD_ACM_IMANUFACT_STR_DESC
#define CONF_USB_CDCD_ACM_IMANUFACT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iProduct
// <id> usb_cdcd_acm_iproduct_en
#ifndef CONF_USB_CDCD_ACM_IPRODUCT_EN
#define CONF_USB_CDCD_ACM_IPRODUCT_EN 0
#endif

#ifndef CONF_USB_CDCD_ACM_IPRODUCT
#define CONF_USB_CDCD_ACM_IPRODUCT                                                                                     \
	(CONF_USB_CDCD_ACM_IPRODUCT_EN * (CONF_USB_CDCD_ACM_IMANUFACT_EN + CONF_USB_CDCD_ACM_IPRODUCT_EN))
#endif

// <s> Unicode string of iProduct
// <id> usb_cdcd_acm_iproduct_str
#ifndef CONF_USB_CDCD_ACM_IPRODUCT_STR
#define CONF_USB_CDCD_ACM_IPRODUCT_STR "CDC ACM Serial Bridge Demo"
#endif

#ifndef CONF_USB_CDCD_ACM_IPRODUCT_STR_DESC
#define CONF_USB_CDCD_ACM_IPRODUCT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iSerialNum
// <id> usb_cdcd_acm_iserialnum_en
#ifndef CONF_USB_CDCD_ACM_ISERIALNUM_EN
#define CONF_USB_CDCD_ACM_ISERIALNUM_EN 0
#endif

#ifndef CONF_USB_CDCD_ACM_ISERIALNUM
#define CONF_USB_CDCD_ACM_ISERIALNUM                                                                                   \
	(CONF_USB_CDCD_ACM_ISERIALNUM_EN                                                                                   \
	 * (CONF_USB_CDCD_ACM_IMANUFACT_EN + CONF_USB_CDCD_ACM_IPRODUCT_EN + CONF_USB_CDCD_ACM_ISERIALNUM_EN))
#endif

// <s> Unicode string of iSerialNum
// <id> usb_cdcd_acm_iserialnum_str
#ifndef CONF_USB_CDCD_ACM_ISERIALNUM_STR
#define CONF_USB_CDCD_ACM_ISERIALNUM_STR "123456789ABCDEF"
#endif

#ifndef CONF_USB_CDCD_ACM_ISERIALNUM_STR_DESC
#define CONF_USB_CDCD_ACM_ISERIALNUM_STR_DESC
#endif

// </e>

// <o> bNumConfigurations <0x01-0xFF>
// <id> usb_cdcd_acm_bnumconfig
#ifndef CONF_USB_CDCD_ACM_BNUMCONFIG
#define CONF_USB_CDCD_ACM_BNUMCONFIG 0x1
#endif

// </h>

// <h> CDC ACM Configuration Descriptor
// <o> bConfigurationValue <0x01-0xFF>
// <id> usb_cdcd_acm_bconfigval
#ifndef CONF_USB_CDCD_ACM_BCONFIGVAL
#define CONF_USB_CDCD_ACM_BCONFIGVAL 0x1
#endif
// <e> Enable string descriptor of iConfig
// <id> usb_cdcd_acm_iconfig_en
#ifndef CONF_USB_CDCD_ACM_ICONFIG_EN
#define CONF_USB_CDCD_ACM_ICONFIG_EN 0
#endif

#ifndef CONF_USB_CDCD_ACM_ICONFIG
#define CONF_USB_CDCD_ACM_ICONFIG                                                                                      \
	(CONF_USB_CDCD_ACM_ICONFIG_EN                                                                                      \
	 * (CONF_USB_CDCD_ACM_IMANUFACT_EN + CONF_USB_CDCD_ACM_IPRODUCT_EN + CONF_USB_CDCD_ACM_ISERIALNUM_EN               \
	    + CONF_USB_CDCD_ACM_ICONFIG_EN))
#endif

// <s> Unicode string of iConfig
// <id> usb_cdcd_acm_iconfig_str
#ifndef CONF_USB_CDCD_ACM_ICONFIG_STR
#define CONF_USB_CDCD_ACM_ICONFIG_STR ""
#endif

#ifndef CONF_USB_CDCD_ACM_ICONFIG_STR_DESC
#define CONF_USB_CDCD_ACM_ICONFIG_STR_DESC
#endif

// </e>

// <o> bmAttributes
// <0x80=> Bus power supply, not support for remote wakeup
// <0xA0=> Bus power supply, support for remote wakeup
// <0xC0=> Self powered, not support for remote wakeup
// <0xE0=> Self powered, support for remote wakeup
// <id> usb_cdcd_acm_bmattri
#ifndef CONF_USB_CDCD_ACM_BMATTRI
#define CONF_USB_CDCD_ACM_BMATTRI 0x80
#endif

// <o> bMaxPower <0x00-0xFF>
// <id> usb_cdcd_acm_bmaxpower
#ifndef CONF_USB_CDCD_ACM_BMAXPOWER
#define CONF_USB_CDCD_ACM_BMAXPOWER 0x32
#endif
// </h>

// <h> CDC ACM Communication Interface Descriptor

// <o> bInterfaceNumber <0x00-0xFF>
// <id> usb_cdcd_acm_comm_bifcnum
#ifndef CONF_USB_CDCD_ACM_COMM_BIFCNUM
#define CONF_USB_CDCD_ACM_COMM_BIFCNUM 0x0
#endif
// <o> bAlternateSetting <0x00-0xFF>
// <id> usb_cdcd_acm_comm_baltset
#ifndef CONF_USB_CDCD_ACM_COMM_BALTSET
#define CONF_USB_CDCD_ACM_COMM_BALTSET 0x0
#endif

// <o> iInterface <0x00-0xFF>
// <id> usb_cdcd_acm_comm_iifc
#ifndef CONF_USB_CDCD_ACM_COMM_IIFC
#define CONF_USB_CDCD_ACM_COMM_IIFC 0x0
#endif

// <o> Interrupt IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_cdcd_acm_epaddr
#ifndef CONF_USB_CDCD_ACM_COMM_INT_EPADDR
#define CONF_USB_CDCD_ACM_COMM_INT_EPADDR 0x82
#endif

// <o> Interrupt IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_cdcd_acm_comm_int_maxpksz
#ifndef CONF_USB_CDCD_ACM_COMM_INT_MAXPKSZ
#define CONF_USB_CDCD_ACM_COMM_INT_MAXPKSZ 0x40
#endif

// <o> Interrupt IN Endpoint Interval <0x00-0xFF>
// <id> usb_cdcd_acm_comm_int_interval
#ifndef CONF_USB_CDCD_ACM_COMM_INT_INTERVAL
#define CONF_USB_CDCD_ACM_COMM_INT_INTERVAL 0xa
#endif
// </h>

// <h> CDC ACM Data Interface Descriptor

// <o> bInterfaceNumber <0x00-0xFF>
// <id> usb_cdcd_acm_data_bifcnum
#ifndef CONF_USB_CDCD_ACM_DATA_BIFCNUM
#define CONF_USB_CDCD_ACM_DATA_BIFCNUM 0x1
#endif
// <o> bAlternateSetting <0x00-0xFF>
// <id> usb_cdcd_acm_data_baltset
#ifndef CONF_USB_CDCD_ACM_DATA_BALTSET
#define CONF_USB_CDCD_ACM_DATA_BALTSET 0x0
#endif

// <o> iInterface <0x00-0xFF>
// <id> usb_cdcd_acm_data_iifc
#ifndef CONF_USB_CDCD_ACM_DATA_IIFC
#define CONF_USB_CDCD_ACM_DATA_IIFC 0x0
#endif

// <o> BULK IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_cdcd_acm_data_bulkin_epaddr
#ifndef CONF_USB_CDCD_ACM_DATA_BULKIN_EPADDR
#define CONF_USB_CDCD_ACM_DATA_BULKIN_EPADDR 0x81
#endif

// <o> BULK IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_cdcd_acm_data_builin_maxpksz
#ifndef CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ
#define CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ 0x40
#endif

// <o> BULK IN Endpoint wMaxPacketSize for High Speed
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <0x0200=> 512 bytes
// <id> usb_cdcd_acm_data_builin_maxpksz_hs
#ifndef CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ_HS
#define CONF_USB_CDCD_ACM_DATA_BULKIN_MAXPKSZ_HS 0x200
#endif

// <o> BULK OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <id> usb_cdcd_acm_data_bulkout_epaddr
#ifndef CONF_USB_CDCD_ACM_DATA_BULKOUT_EPADDR
#define CONF_USB_CDCD_ACM_DATA_BULKOUT_EPADDR 0x1
#endif

// <o> BULK OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_cdcd_acm_data_buckout_maxpksz
#ifndef CONF_USB_CDCD_ACM_DATA_BULKOUT_MAXPKSZ
#define CONF_USB_CDCD_ACM_DATA_BULKOUT_MAXPKSZ 0x40
#endif

// <o> BULK OUT Endpoint wMaxPacketSize for High Speed
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <0x0200=> 512 bytes
// <id> usb_cdcd_acm_data_buckout_maxpksz_hs
#ifndef CONF_USB_CDCD_ACM_DATA_BULKOUT_MAXPKSZ_HS
#define CONF_USB_CDCD_ACM_DATA_BULKOUT_MAXPKSZ_HS 0x200
#endif
// </h>

// ---- USB Device Stack HID mouse Options ----

// <e> Enable String Descriptors
// <id> usb_hid_mouse_str_en
#ifndef CONF_USB_HID_MOUSE_STR_EN
#define CONF_USB_HID_MOUSE_STR_EN 0
#endif
// <s> Language IDs
// <i> Language IDs in c format, split by comma (E.g., 0x0409 ...)
// <id> usb_hid_mouse_langid
#ifndef CONF_USB_HID_MOUSE_LANGID
#define CONF_USB_HID_MOUSE_LANGID "0x0409"
#endif

#ifndef CONF_USB_HID_MOUSE_LANGID_DESC
#define CONF_USB_HID_MOUSE_LANGID_DESC
#endif
// </e>

// <h> HID Mouse Device Descriptor

// <o> bcdUSB
// <0x0200=> USB 2.0 version
// <0x0210=> USB 2.1 version
// <id> usb_hid_mouse_bcdusb
#ifndef CONF_USB_HID_MOUSE_BCDUSB
#define CONF_USB_HID_MOUSE_BCDUSB 0x200
#endif

// <o> bMaxPackeSize0
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_hid_mouse_bmaxpksz0
#ifndef CONF_USB_HID_MOUSE_BMAXPKSZ0
#define CONF_USB_HID_MOUSE_BMAXPKSZ0 0x40
#endif

// <o> idVender <0x0000-0xFFFF>
// <id> usb_hid_mouse_idvender
#ifndef CONF_USB_HID_MOUSE_IDVENDER
#define CONF_USB_HID_MOUSE_IDVENDER 0x3eb
#endif

// <o> idProduct <0x0000-0xFFFF>
// <id> usb_hid_mouse_idproduct
#ifndef CONF_USB_HID_MOUSE_IDPRODUCT
#define CONF_USB_HID_MOUSE_IDPRODUCT 0x2400
#endif

// <o> bcdDevice <0x0000-0xFFFF>
// <id> usb_hid_mouse_bcddevice
#ifndef CONF_USB_HID_MOUSE_BCDDEVICE
#define CONF_USB_HID_MOUSE_BCDDEVICE 0x100
#endif

// <e> Enable string descriptor of iManufact
// <id> usb_hid_mouse_imanufact_en
#ifndef CONF_USB_HID_MOUSE_IMANUFACT_EN
#define CONF_USB_HID_MOUSE_IMANUFACT_EN 0
#endif

#ifndef CONF_USB_HID_MOUSE_IMANUFACT
#define CONF_USB_HID_MOUSE_IMANUFACT (CONF_USB_HID_MOUSE_IMANUFACT_EN * (CONF_USB_HID_MOUSE_IMANUFACT_EN))
#endif

// <s> Unicode string of iManufact
// <id> usb_hid_mouse_imanufact_str
#ifndef CONF_USB_HID_MOUSE_IMANUFACT_STR
#define CONF_USB_HID_MOUSE_IMANUFACT_STR "Atmel"
#endif

#ifndef CONF_USB_HID_MOUSE_IMANUFACT_STR_DESC
#define CONF_USB_HID_MOUSE_IMANUFACT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iProduct
// <id> usb_hid_mouse_iproduct_en
#ifndef CONF_USB_HID_MOUSE_IPRODUCT_EN
#define CONF_USB_HID_MOUSE_IPRODUCT_EN 0
#endif

#ifndef CONF_USB_HID_MOUSE_IPRODUCT
#define CONF_USB_HID_MOUSE_IPRODUCT                                                                                    \
	(CONF_USB_HID_MOUSE_IPRODUCT_EN * (CONF_USB_HID_MOUSE_IMANUFACT_EN + CONF_USB_HID_MOUSE_IPRODUCT_EN))
#endif

// <s> Unicode string of iProduct
// <id> usb_hid_mouse_iproduct_str
#ifndef CONF_USB_HID_MOUSE_IPRODUCT_STR
#define CONF_USB_HID_MOUSE_IPRODUCT_STR "HID Mouse Demo"
#endif

#ifndef CONF_USB_HID_MOUSE_IPRODUCT_STR_DESC
#define CONF_USB_HID_MOUSE_IPRODUCT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iSerialNum
// <id> usb_hid_mouse_iserialnum_en
#ifndef CONF_USB_HID_MOUSE_ISERIALNUM_EN
#define CONF_USB_HID_MOUSE_ISERIALNUM_EN 0
#endif

#ifndef CONF_USB_HID_MOUSE_ISERIALNUM
#define CONF_USB_HID_MOUSE_ISERIALNUM                                                                                  \
	(CONF_USB_HID_MOUSE_ISERIALNUM_EN                                                                                  \
	 * (CONF_USB_HID_MOUSE_IMANUFACT_EN + CONF_USB_HID_MOUSE_IPRODUCT_EN + CONF_USB_HID_MOUSE_ISERIALNUM_EN))
#endif

// <s> Unicode string of iSerialNum
// <id> usb_hid_mouse_iserialnum_str
#ifndef CONF_USB_HID_MOUSE_ISERIALNUM_STR
#define CONF_USB_HID_MOUSE_ISERIALNUM_STR "123456789ABCDEF"
#endif

#ifndef CONF_USB_HID_MOUSE_ISERIALNUM_STR_DESC
#define CONF_USB_HID_MOUSE_ISERIALNUM_STR_DESC
#endif

// </e>

// </h>

// <h> HID Mouse Configuration Descriptor

// <e> Enable string descriptor of iConfig
// <id> usb_hid_mouse_iconfig_en
#ifndef CONF_USB_HID_MOUSE_ICONFIG_EN
#define CONF_USB_HID_MOUSE_ICONFIG_EN 0
#endif

#ifndef CONF_USB_HID_MOUSE_ICONFIG
#define CONF_USB_HID_MOUSE_ICONFIG                                                                                     \
	(CONF_USB_HID_MOUSE_ICONFIG_EN                                                                                     \
	 * (CONF_USB_HID_MOUSE_IMANUFACT_EN + CONF_USB_HID_MOUSE_IPRODUCT_EN + CONF_USB_HID_MOUSE_ISERIALNUM_EN            \
	    + CONF_USB_HID_MOUSE_ICONFIG_EN))
#endif

// <s> Unicode string of iConfig
// <id> usb_hid_mouse_iconfig_str
#ifndef CONF_USB_HID_MOUSE_ICONFIG_STR
#define CONF_USB_HID_MOUSE_ICONFIG_STR ""
#endif

#ifndef CONF_USB_HID_MOUSE_ICONFIG_STR_DESC
#define CONF_USB_HID_MOUSE_ICONFIG_STR_DESC
#endif

// </e>

// <o> bmAttributes
// <0x80=> Bus power supply, not support for remote wakeup
// <0xA0=> Bus power supply, support for remote wakeup
// <0xC0=> Self powered, not support for remote wakeup
// <0xE0=> Self powered, support for remote wakeup
// <id> usb_hid_mouse_bmattri
#ifndef CONF_USB_HID_MOUSE_BMATTRI
#define CONF_USB_HID_MOUSE_BMATTRI 0x80
#endif

// <o> bMaxPower <0x00-0xFF>
// <id> usb_hid_mouse_bmaxpower
#ifndef CONF_USB_HID_MOUSE_BMAXPOWER
#define CONF_USB_HID_MOUSE_BMAXPOWER 0x32
#endif
// </h>

// <h> HID Mouse Interface Descriptor

// <o> bInterfaceNumber <0x00-0xFF>
// <id> usb_hid_mouse_bifcnum
#ifndef CONF_USB_HID_MOUSE_BIFCNUM
#define CONF_USB_HID_MOUSE_BIFCNUM 0x0
#endif

// <o> iInterface <0x00-0xFF>
// <id> usb_hid_mouse_iifc
#ifndef CONF_USB_HID_MOUSE_IIFC
#define CONF_USB_HID_MOUSE_IIFC 0x0
#endif

// <o> INTERRUPT IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_hid_mouse_intin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_MOUSE_INTIN_EPADDR
#define CONF_USB_HID_MOUSE_INTIN_EPADDR 0x81
#endif

// <o> INTERRUPT IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_hid_mouse_intin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_MOUSE_INTIN_MAXPKSZ
#define CONF_USB_HID_MOUSE_INTIN_MAXPKSZ 0x8
#endif

// </h>

// ---- USB Device Stack HID keyboard Options ----

// <e> Enable String Descriptors
// <id> usb_hid_keyboard_str_en
#ifndef CONF_USB_HID_KEYBOARD_STR_EN
#define CONF_USB_HID_KEYBOARD_STR_EN 0
#endif
// <s> Language IDs
// <i> Language IDs in c format, split by comma (E.g., 0x0409 ...)
// <id> usb_hid_keyboard_langid
#ifndef CONF_USB_HID_KEYBOARD_LANGID
#define CONF_USB_HID_KEYBOARD_LANGID "0x0409"
#endif

#ifndef CONF_USB_HID_KEYBOARD_LANGID_DESC
#define CONF_USB_HID_KEYBOARD_LANGID_DESC
#endif
// </e>

// <h> HID Keyboard Device Descriptor

// <o> bcdUSB
// <0x0200=> USB 2.0 version
// <0x0210=> USB 2.1 version
// <id> usb_hid_keyboard_bcdusb
#ifndef CONF_USB_HID_KEYBOARD_BCDUSB
#define CONF_USB_HID_KEYBOARD_BCDUSB 0x200
#endif

// <o> bMaxPackeSize0
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_hid_keyboard_bmaxpksz0
#ifndef CONF_USB_HID_KEYBOARD_BMAXPKSZ0
#define CONF_USB_HID_KEYBOARD_BMAXPKSZ0 0x40
#endif

// <o> idVender <0x0000-0xFFFF>
// <id> usb_hid_keyboard_idvender
#ifndef CONF_USB_HID_KEYBOARD_IDVENDER
#define CONF_USB_HID_KEYBOARD_IDVENDER 0x3eb
#endif

// <o> idProduct <0x0000-0xFFFF>
// <id> usb_hid_keyboard_idproduct
#ifndef CONF_USB_HID_KEYBOARD_IDPRODUCT
#define CONF_USB_HID_KEYBOARD_IDPRODUCT 0x2401
#endif

// <o> bcdDevice <0x0000-0xFFFF>
// <id> usb_hid_keyboard_bcddevice
#ifndef CONF_USB_HID_KEYBOARD_BCDDEVICE
#define CONF_USB_HID_KEYBOARD_BCDDEVICE 0x100
#endif

// <e> Enable string descriptor of iManufact
// <id> usb_hid_keyboard_imanufact_en
#ifndef CONF_USB_HID_KEYBOARD_IMANUFACT_EN
#define CONF_USB_HID_KEYBOARD_IMANUFACT_EN 0
#endif

#ifndef CONF_USB_HID_KEYBOARD_IMANUFACT
#define CONF_USB_HID_KEYBOARD_IMANUFACT (CONF_USB_HID_KEYBOARD_IMANUFACT_EN * (CONF_USB_HID_KEYBOARD_IMANUFACT_EN))
#endif

// <s> Unicode string of iManufact
// <id> usb_hid_keyboard_imanufact_str
#ifndef CONF_USB_HID_KEYBOARD_IMANUFACT_STR
#define CONF_USB_HID_KEYBOARD_IMANUFACT_STR "Atmel"
#endif

#ifndef CONF_USB_HID_KEYBOARD_IMANUFACT_STR_DESC
#define CONF_USB_HID_KEYBOARD_IMANUFACT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iProduct
// <id> usb_hid_keyboard_iproduct_en
#ifndef CONF_USB_HID_KEYBOARD_IPRODUCT_EN
#define CONF_USB_HID_KEYBOARD_IPRODUCT_EN 0
#endif

#ifndef CONF_USB_HID_KEYBOARD_IPRODUCT
#define CONF_USB_HID_KEYBOARD_IPRODUCT                                                                                 \
	(CONF_USB_HID_KEYBOARD_IPRODUCT_EN * (CONF_USB_HID_KEYBOARD_IMANUFACT_EN + CONF_USB_HID_KEYBOARD_IPRODUCT_EN))
#endif

// <s> Unicode string of iProduct
// <id> usb_hid_keyboard_iproduct_str
#ifndef CONF_USB_HID_KEYBOARD_IPRODUCT_STR
#define CONF_USB_HID_KEYBOARD_IPRODUCT_STR "HID Keyboard Demo"
#endif

#ifndef CONF_USB_HID_KEYBOARD_IPRODUCT_STR_DESC
#define CONF_USB_HID_KEYBOARD_IPRODUCT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iSerialNum
// <id> usb_hid_keyboard_iserialnum_en
#ifndef CONF_USB_HID_KEYBOARD_ISERIALNUM_EN
#define CONF_USB_HID_KEYBOARD_ISERIALNUM_EN 0
#endif

#ifndef CONF_USB_HID_KEYBOARD_ISERIALNUM
#define CONF_USB_HID_KEYBOARD_ISERIALNUM                                                                               \
	(CONF_USB_HID_KEYBOARD_ISERIALNUM_EN                                                                               \
	 * (CONF_USB_HID_KEYBOARD_IMANUFACT_EN + CONF_USB_HID_KEYBOARD_IPRODUCT_EN + CONF_USB_HID_KEYBOARD_ISERIALNUM_EN))
#endif

// <s> Unicode string of iSerialNum
// <id> usb_hid_keyboard_iserialnum_str
#ifndef CONF_USB_HID_KEYBOARD_ISERIALNUM_STR
#define CONF_USB_HID_KEYBOARD_ISERIALNUM_STR "123456789ABCDEF"
#endif

#ifndef CONF_USB_HID_KEYBOARD_ISERIALNUM_STR_DESC
#define CONF_USB_HID_KEYBOARD_ISERIALNUM_STR_DESC
#endif

// </e>

// </h>

// <h> HID Keyboard Configuration Descriptor

// <e> Enable string descriptor of iConfig
// <id> usb_hid_keyboard_iconfig_en
#ifndef CONF_USB_HID_KEYBOARD_ICONFIG_EN
#define CONF_USB_HID_KEYBOARD_ICONFIG_EN 0
#endif

#ifndef CONF_USB_HID_KEYBOARD_ICONFIG
#define CONF_USB_HID_KEYBOARD_ICONFIG                                                                                  \
	(CONF_USB_HID_KEYBOARD_ICONFIG_EN                                                                                  \
	 * (CONF_USB_HID_KEYBOARD_IMANUFACT_EN + CONF_USB_HID_KEYBOARD_IPRODUCT_EN + CONF_USB_HID_KEYBOARD_ISERIALNUM_EN   \
	    + CONF_USB_HID_KEYBOARD_ICONFIG_EN))
#endif

// <s> Unicode string of iConfig
// <id> usb_hid_keyboard_iconfig_str
#ifndef CONF_USB_HID_KEYBOARD_ICONFIG_STR
#define CONF_USB_HID_KEYBOARD_ICONFIG_STR ""
#endif

#ifndef CONF_USB_HID_KEYBOARD_ICONFIG_STR_DESC
#define CONF_USB_HID_KEYBOARD_ICONFIG_STR_DESC
#endif

// </e>

// <o> bmAttributes
// <0x80=> Bus power supply, not support for remote wakeup
// <0xA0=> Bus power supply, support for remote wakeup
// <0xC0=> Self powered, not support for remote wakeup
// <0xE0=> Self powered, support for remote wakeup
// <id> usb_hid_keyboard_bmattri
#ifndef CONF_USB_HID_KEYBOARD_BMATTRI
#define CONF_USB_HID_KEYBOARD_BMATTRI 0x80
#endif

// <o> bMaxPower <0x00-0xFF>
// <id> usb_hid_keyboard_bmaxpower
#ifndef CONF_USB_HID_KEYBOARD_BMAXPOWER
#define CONF_USB_HID_KEYBOARD_BMAXPOWER 0x32
#endif
// </h>

// <h> HID Keyboard Interface Descriptor

// <o> bInterfaceNumber <0x00-0xFF>
// <id> usb_hid_keyboard_bifcnum
#ifndef CONF_USB_HID_KEYBOARD_BIFCNUM
#define CONF_USB_HID_KEYBOARD_BIFCNUM 0x0
#endif

// <o> iInterface <0x00-0xFF>
// <id> usb_hid_keyboard_iifc
#ifndef CONF_USB_HID_KEYBOARD_IIFC
#define CONF_USB_HID_KEYBOARD_IIFC 0x0
#endif

// <o> INTERRUPT IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_hid_keyboard_intin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_KEYBOARD_INTIN_EPADDR
#define CONF_USB_HID_KEYBOARD_INTIN_EPADDR 0x81
#endif

// <o> INTERRUPT IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_hid_keyboard_intin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_KEYBOARD_INTIN_MAXPKSZ
#define CONF_USB_HID_KEYBOARD_INTIN_MAXPKSZ 0x8
#endif

// <o> INTERRUPT OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <id> usb_hid_keyboard_intout_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_KEYBOARD_INTOUT_EPADDR
#define CONF_USB_HID_KEYBOARD_INTOUT_EPADDR 0x1
#endif

// <o> INTERRUPT OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_hid_keyboard_intout_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_KEYBOARD_INTOUT_MAXPKSZ
#define CONF_USB_HID_KEYBOARD_INTOUT_MAXPKSZ 0x8
#endif

// </h>

// ---- USB Device Stack HID generic Options ----

// <e> Enable String Descriptors
// <id> usb_hid_generic_str_en
#ifndef CONF_USB_HID_GENERIC_STR_EN
#define CONF_USB_HID_GENERIC_STR_EN 0
#endif
// <s> Language IDs
// <i> Language IDs in c format, split by comma (E.g., 0x0409 ...)
// <id> usb_hid_generic_langid
#ifndef CONF_USB_HID_GENERIC_LANGID
#define CONF_USB_HID_GENERIC_LANGID "0x0409"
#endif

#ifndef CONF_USB_HID_GENERIC_LANGID_DESC
#define CONF_USB_HID_GENERIC_LANGID_DESC
#endif
// </e>

// <h> HID Generic Device Descriptor

// <o> bcdUSB
// <0x0200=> USB 2.0 version
// <0x0210=> USB 2.1 version
// <id> usb_hid_generic_bcdusb
#ifndef CONF_USB_HID_GENERIC_BCDUSB
#define CONF_USB_HID_GENERIC_BCDUSB 0x200
#endif

// <o> bMaxPackeSize0
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_hid_generic_bmaxpksz0
#ifndef CONF_USB_HID_GENERIC_BMAXPKSZ0
#define CONF_USB_HID_GENERIC_BMAXPKSZ0 0x40
#endif

// <o> idVender <0x0000-0xFFFF>
// <id> usb_hid_generic_idvender
#ifndef CONF_USB_HID_GENERIC_IDVENDER
#define CONF_USB_HID_GENERIC_IDVENDER 0x3eb
#endif

// <o> idProduct <0x0000-0xFFFF>
// <id> usb_hid_generic_idproduct
#ifndef CONF_USB_HID_GENERIC_IDPRODUCT
#define CONF_USB_HID_GENERIC_IDPRODUCT 0x2402
#endif

// <o> bcdDevice <0x0000-0xFFFF>
// <id> usb_hid_generic_bcddevice
#ifndef CONF_USB_HID_GENERIC_BCDDEVICE
#define CONF_USB_HID_GENERIC_BCDDEVICE 0x100
#endif

// <e> Enable string descriptor of iManufact
// <id> usb_hid_generic_imanufact_en
#ifndef CONF_USB_HID_GENERIC_IMANUFACT_EN
#define CONF_USB_HID_GENERIC_IMANUFACT_EN 0
#endif

#ifndef CONF_USB_HID_GENERIC_IMANUFACT
#define CONF_USB_HID_GENERIC_IMANUFACT (CONF_USB_HID_GENERIC_IMANUFACT_EN * (CONF_USB_HID_GENERIC_IMANUFACT_EN))
#endif

// <s> Unicode string of iManufact
// <id> usb_hid_generic_imanufact_str
#ifndef CONF_USB_HID_GENERIC_IMANUFACT_STR
#define CONF_USB_HID_GENERIC_IMANUFACT_STR "Atmel"
#endif

#ifndef CONF_USB_HID_GENERIC_IMANUFACT_STR_DESC
#define CONF_USB_HID_GENERIC_IMANUFACT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iProduct
// <id> usb_hid_generic_iproduct_en
#ifndef CONF_USB_HID_GENERIC_IPRODUCT_EN
#define CONF_USB_HID_GENERIC_IPRODUCT_EN 0
#endif

#ifndef CONF_USB_HID_GENERIC_IPRODUCT
#define CONF_USB_HID_GENERIC_IPRODUCT                                                                                  \
	(CONF_USB_HID_GENERIC_IPRODUCT_EN * (CONF_USB_HID_GENERIC_IMANUFACT_EN + CONF_USB_HID_GENERIC_IPRODUCT_EN))
#endif

// <s> Unicode string of iProduct
// <id> usb_hid_generic_iproduct_str
#ifndef CONF_USB_HID_GENERIC_IPRODUCT_STR
#define CONF_USB_HID_GENERIC_IPRODUCT_STR "HID Generic Demo"
#endif

#ifndef CONF_USB_HID_GENERIC_IPRODUCT_STR_DESC
#define CONF_USB_HID_GENERIC_IPRODUCT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iSerialNum
// <id> usb_hid_generic_iserialnum_en
#ifndef CONF_USB_HID_GENERIC_ISERIALNUM_EN
#define CONF_USB_HID_GENERIC_ISERIALNUM_EN 0
#endif

#ifndef CONF_USB_HID_GENERIC_ISERIALNUM
#define CONF_USB_HID_GENERIC_ISERIALNUM                                                                                \
	(CONF_USB_HID_GENERIC_ISERIALNUM_EN                                                                                \
	 * (CONF_USB_HID_GENERIC_IMANUFACT_EN + CONF_USB_HID_GENERIC_IPRODUCT_EN + CONF_USB_HID_GENERIC_ISERIALNUM_EN))
#endif

// <s> Unicode string of iSerialNum
// <id> usb_hid_generic_iserialnum_str
#ifndef CONF_USB_HID_GENERIC_ISERIALNUM_STR
#define CONF_USB_HID_GENERIC_ISERIALNUM_STR "123456789ABCDEF"
#endif

#ifndef CONF_USB_HID_GENERIC_ISERIALNUM_STR_DESC
#define CONF_USB_HID_GENERIC_ISERIALNUM_STR_DESC
#endif

// </e>

// </h>

// <h> HID Generic Configuration Descriptor

// <e> Enable string descriptor of iConfig
// <id> usb_hid_generic_iconfig_en
#ifndef CONF_USB_HID_GENERIC_ICONFIG_EN
#define CONF_USB_HID_GENERIC_ICONFIG_EN 0
#endif

#ifndef CONF_USB_HID_GENERIC_ICONFIG
#define CONF_USB_HID_GENERIC_ICONFIG                                                                                   \
	(CONF_USB_HID_GENERIC_ICONFIG_EN                                                                                   \
	 * (CONF_USB_HID_GENERIC_IMANUFACT_EN + CONF_USB_HID_GENERIC_IPRODUCT_EN + CONF_USB_HID_GENERIC_ISERIALNUM_EN      \
	    + CONF_USB_HID_GENERIC_ICONFIG_EN))
#endif

// <s> Unicode string of iConfig
// <id> usb_hid_generic_iconfig_str
#ifndef CONF_USB_HID_GENERIC_ICONFIG_STR
#define CONF_USB_HID_GENERIC_ICONFIG_STR ""
#endif

#ifndef CONF_USB_HID_GENERIC_ICONFIG_STR_DESC
#define CONF_USB_HID_GENERIC_ICONFIG_STR_DESC
#endif

// </e>

// <o> bmAttributes
// <0x80=> Bus power supply, not support for remote wakeup
// <0xA0=> Bus power supply, support for remote wakeup
// <0xC0=> Self powered, not support for remote wakeup
// <0xE0=> Self powered, support for remote wakeup
// <id> usb_hid_generic_bmattri
#ifndef CONF_USB_HID_GENERIC_BMATTRI
#define CONF_USB_HID_GENERIC_BMATTRI 0x80
#endif

// <o> bMaxPower <0x00-0xFF>
// <id> usb_hid_generic_bmaxpower
#ifndef CONF_USB_HID_GENERIC_BMAXPOWER
#define CONF_USB_HID_GENERIC_BMAXPOWER 0x32
#endif
// </h>

// <h> HID Generic Interface Descriptor

// <o> bInterfaceNumber <0x00-0xFF>
// <id> usb_hid_generic_bifcnum
#ifndef CONF_USB_HID_GENERIC_BIFCNUM
#define CONF_USB_HID_GENERIC_BIFCNUM 0x0
#endif

// <o> iInterface <0x00-0xFF>
// <id> usb_hid_generic_iifc
#ifndef CONF_USB_HID_GENERIC_IIFC
#define CONF_USB_HID_GENERIC_IIFC 0x0
#endif

// <o> HID Generic Report Descriptor Length <0x0000-0xFFFF>
// <id> usb_hid_generic_report_desc_length
#ifndef CONF_USB_HID_GENERIC_REPORT_LEN
#define CONF_USB_HID_GENERIC_REPORT_LEN 53
#endif

#ifndef CONF_USB_HID_GENERIC_REPORT
#define CONF_USB_HID_GENERIC_REPORT                                                                                    \
	0x06, 0xFF, 0xFF, 0x09, 0x01, 0xA1, 0x01, 0x09, 0x02, 0x09, 0x03, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x75, 0x08, 0x95,  \
	    0x40, 0x81, 0x02, 0x09, 0x04, 0x09, 0x05, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x75, 0x08, 0x95, 0x40, 0x91, 0x02,    \
	    0x09, 0x06, 0x09, 0x07, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x75, 0x08, 0x95, 0x04, 0xB1, 0x02, 0xC0
#endif

// <o> INTERRUPT IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_hid_generic_intin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_GENERIC_INTIN_EPADDR
#define CONF_USB_HID_GENERIC_INTIN_EPADDR 0x81
#endif

// <o> INTERRUPT IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_hid_generic_intin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_GENERIC_INTIN_MAXPKSZ
#define CONF_USB_HID_GENERIC_INTIN_MAXPKSZ 0x40
#endif

// <o> INTERRUPT OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <id> usb_hid_generic_intout_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_GENERIC_INTOUT_EPADDR
#define CONF_USB_HID_GENERIC_INTOUT_EPADDR 0x1
#endif

// <o> INTERRUPT OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_hid_generic_intout_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_HID_GENERIC_INTOUT_MAXPKSZ
#define CONF_USB_HID_GENERIC_INTOUT_MAXPKSZ 0x40
#endif

// </h>

// ---- USB Device Stack Mass Storage Options ----

// <e> Enable String Descriptors
// <id> usb_msc_str_en
#ifndef CONF_USB_MSC_STR_EN
#define CONF_USB_MSC_STR_EN 0
#endif
// <s> Language IDs
// <i> Language IDs in c format, split by comma (E.g., 0x0409 ...)
// <id> usb_msc_langid
#ifndef CONF_USB_MSC_LANGID
#define CONF_USB_MSC_LANGID "0x0409"
#endif

#ifndef CONF_USB_MSC_LANGID_DESC
#define CONF_USB_MSC_LANGID_DESC
#endif
// </e>

// <h> Mass Storage Class (MSC) Device Descriptor

// <o> bcdUSB
// <0x0200=> USB 2.0 version
// <0x0210=> USB 2.1 version
// <id> usb_msc_bcdusb
#ifndef CONF_USB_MSC_BCDUSB
#define CONF_USB_MSC_BCDUSB 0x200
#endif

// <o> bMaxPackeSize0
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_msc_bmaxpksz0
#ifndef CONF_USB_MSC_BMAXPKSZ0
#define CONF_USB_MSC_BMAXPKSZ0 0x40
#endif

// <o> idVender <0x0000-0xFFFF>
// <id> usb_msc_idvender
#ifndef CONF_USB_MSC_IDVENDER
#define CONF_USB_MSC_IDVENDER 0x3eb
#endif

// <o> idProduct <0x0000-0xFFFF>
// <id> usb_msc_idproduct
#ifndef CONF_USB_MSC_IDPRODUCT
#define CONF_USB_MSC_IDPRODUCT 0x2403
#endif

// <o> bcdDevice <0x0000-0xFFFF>
// <id> usb_msc_bcddevice
#ifndef CONF_USB_MSC_BCDDEVICE
#define CONF_USB_MSC_BCDDEVICE 0x100
#endif

// <e> Enable string descriptor of iManufact
// <id> usb_msc_imanufact_en
#ifndef CONF_USB_MSC_IMANUFACT_EN
#define CONF_USB_MSC_IMANUFACT_EN 0
#endif

#ifndef CONF_USB_MSC_IMANUFACT
#define CONF_USB_MSC_IMANUFACT (CONF_USB_MSC_IMANUFACT_EN * (CONF_USB_MSC_IMANUFACT_EN))
#endif

// <s> Unicode string of iManufact
// <id> usb_msc_imanufact_str
#ifndef CONF_USB_MSC_IMANUFACT_STR
#define CONF_USB_MSC_IMANUFACT_STR "Atmel"
#endif

#ifndef CONF_USB_MSC_IMANUFACT_STR_DESC
#define CONF_USB_MSC_IMANUFACT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iProduct
// <id> usb_msc_iproduct_en
#ifndef CONF_USB_MSC_IPRODUCT_EN
#define CONF_USB_MSC_IPRODUCT_EN 0
#endif

#ifndef CONF_USB_MSC_IPRODUCT
#define CONF_USB_MSC_IPRODUCT (CONF_USB_MSC_IPRODUCT_EN * (CONF_USB_MSC_IMANUFACT_EN + CONF_USB_MSC_IPRODUCT_EN))
#endif

// <s> Unicode string of iProduct
// <id> usb_msc_iproduct_str
#ifndef CONF_USB_MSC_IPRODUCT_STR
#define CONF_USB_MSC_IPRODUCT_STR "Mass Storage Class (MSC) Demo"
#endif

#ifndef CONF_USB_MSC_IPRODUCT_STR_DESC
#define CONF_USB_MSC_IPRODUCT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iSerialNum
// <id> usb_msc_iserialnum_en
#ifndef CONF_USB_MSC_ISERIALNUM_EN
#define CONF_USB_MSC_ISERIALNUM_EN 0
#endif

#ifndef CONF_USB_MSC_ISERIALNUM
#define CONF_USB_MSC_ISERIALNUM                                                                                        \
	(CONF_USB_MSC_ISERIALNUM_EN * (CONF_USB_MSC_IMANUFACT_EN + CONF_USB_MSC_IPRODUCT_EN + CONF_USB_MSC_ISERIALNUM_EN))
#endif

// <s> Unicode string of iSerialNum
// <id> usb_msc_iserialnum_str
#ifndef CONF_USB_MSC_ISERIALNUM_STR
#define CONF_USB_MSC_ISERIALNUM_STR "123456789ABCDEF"
#endif

#ifndef CONF_USB_MSC_ISERIALNUM_STR_DESC
#define CONF_USB_MSC_ISERIALNUM_STR_DESC
#endif

// </e>

// </h>

// <h> MSC Configuration Descriptor

// <e> Enable string descriptor of iConfig
// <id> usb_msc_iconfig_en
#ifndef CONF_USB_MSC_ICONFIG_EN
#define CONF_USB_MSC_ICONFIG_EN 0
#endif

#ifndef CONF_USB_MSC_ICONFIG
#define CONF_USB_MSC_ICONFIG                                                                                           \
	(CONF_USB_MSC_ICONFIG_EN                                                                                           \
	 * (CONF_USB_MSC_IMANUFACT_EN + CONF_USB_MSC_IPRODUCT_EN + CONF_USB_MSC_ISERIALNUM_EN + CONF_USB_MSC_ICONFIG_EN))
#endif

// <s> Unicode string of iConfig
// <id> usb_msc_iconfig_str
#ifndef CONF_USB_MSC_ICONFIG_STR
#define CONF_USB_MSC_ICONFIG_STR ""
#endif

#ifndef CONF_USB_MSC_ICONFIG_STR_DESC
#define CONF_USB_MSC_ICONFIG_STR_DESC
#endif

// </e>

// <o> bmAttributes
// <0x80=> Bus power supply, not support for remote wakeup
// <0xA0=> Bus power supply, support for remote wakeup
// <0xC0=> Self powered, not support for remote wakeup
// <0xE0=> Self powered, support for remote wakeup
// <id> usb_msc_bmattri
#ifndef CONF_USB_MSC_BMATTRI
#define CONF_USB_MSC_BMATTRI 0x80
#endif

// <o> bMaxPower <0x00-0xFF>
// <id> usb_msc_bmaxpower
#ifndef CONF_USB_MSC_BMAXPOWER
#define CONF_USB_MSC_BMAXPOWER 0x32
#endif
// </h>

// <h> MSC Interface Descriptor

#ifndef CONF_USB_MSC_BIFCNUM
#define CONF_USB_MSC_BIFCNUM 0x00
#endif

#ifndef CONF_USB_MSC_IIFC
#define CONF_USB_MSC_IIFC 0x00
#endif

// <o> BULK IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_msc_bulkin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_MSC_BULKIN_EPADDR
#define CONF_USB_MSC_BULKIN_EPADDR 0x81
#endif

// <o> BULK IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_msc_bulkin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_MSC_BULKIN_MAXPKSZ
#define CONF_USB_MSC_BULKIN_MAXPKSZ 0x40
#endif

// <o> BULK IN Endpoint wMaxPacketSize for High Speed
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <0x0200=> 512 bytes
// <id> usb_msc_bulkin_maxpksz_hs
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_MSC_BULKIN_MAXPKSZ_HS
#define CONF_USB_MSC_BULKIN_MAXPKSZ_HS 0x200
#endif

// <o> BULK OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <id> usb_msc_bulkout_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_MSC_BULKOUT_EPADDR
#define CONF_USB_MSC_BULKOUT_EPADDR 0x1
#endif

// <o> BULK OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_msc_bulkout_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_MSC_BULKOUT_MAXPKSZ
#define CONF_USB_MSC_BULKOUT_MAXPKSZ 0x40
#endif

// <o> BULK OUT Endpoint wMaxPacketSize for High Speed
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <0x0200=> 512 bytes
// <id> usb_msc_bulkout_maxpksz_hs
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_MSC_BULKOUT_MAXPKSZ_HS
#define CONF_USB_MSC_BULKOUT_MAXPKSZ_HS 0x200
#endif
// </h>

// <e> Enable Demo code for Disk LUN handling
// <id> conf_usb_msc_demo_en
#ifndef CONF_USB_MSC_LUN_DEMO
#define CONF_USB_MSC_LUN_DEMO 1
#endif

// <o> Disk access cache/buffer of sectors if non-RAM disk (e.g., SD/MMC) enabled <1-64>
// <id> conf_usb_msc_lun_buf_sectors
#ifndef CONF_USB_MSC_LUN_BUF_SECTORS
#define CONF_USB_MSC_LUN_BUF_SECTORS 4
#endif

// <e> Enable Demo for RAM Disk
// <id> conf_usb_msc_lun0_enable
#ifndef CONF_USB_MSC_LUN0_ENABLE
#define CONF_USB_MSC_LUN0_ENABLE 1
#endif

#ifndef CONF_USB_MSC_LUN0_TYPE
#define CONF_USB_MSC_LUN0_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun0_rmb
#ifndef CONF_USB_MSC_LUN0_RMB
#define CONF_USB_MSC_LUN0_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN0_ISO
#define CONF_USB_MSC_LUN0_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_ECMA
#define CONF_USB_MSC_LUN0_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_ANSI
#define CONF_USB_MSC_LUN0_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_REPO
#define CONF_USB_MSC_LUN0_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN0_FACTORY
#define CONF_USB_MSC_LUN0_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_PRODUCT
#define CONF_USB_MSC_LUN0_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_PRODUCT_VERSION
#define CONF_USB_MSC_LUN0_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <i> Windows will not show disk less than 20K, so 22K is used to reserve more RAM for APP
// <id> conf_usb_msc_lun0_capacity

#ifndef CONF_USB_MSC_LUN0_CAPACITY
#define CONF_USB_MSC_LUN0_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN0_BLOCK_SIZE
#define CONF_USB_MSC_LUN0_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN0_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN0_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN0_CAPACITY * 1024 / CONF_USB_MSC_LUN0_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for SD/MMC Disk
// <i> SD/MMC stack must be added before enable SD/MMC demo
// <i> SD/MMC insert/eject not supported by this simple demo
// <id> conf_usb_msc_lun1_enable
#ifndef CONF_USB_MSC_LUN1_ENABLE
#define CONF_USB_MSC_LUN1_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN1_TYPE
#define CONF_USB_MSC_LUN1_TYPE 0x00
#endif

// <q> The disk is removable
// <i> SD/MMC stack must be added before enable SD/MMC demo
// <i> SD/MMC insert/eject not supported by this simple demo
// <id> conf_usb_msc_lun1_rmb
#ifndef CONF_USB_MSC_LUN1_RMB
#define CONF_USB_MSC_LUN1_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN1_ISO
#define CONF_USB_MSC_LUN1_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_ECMA
#define CONF_USB_MSC_LUN1_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_ANSI
#define CONF_USB_MSC_LUN1_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_REPO
#define CONF_USB_MSC_LUN1_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN1_FACTORY
#define CONF_USB_MSC_LUN1_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_PRODUCT
#define CONF_USB_MSC_LUN1_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_PRODUCT_VERSION
#define CONF_USB_MSC_LUN1_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_CAPACITY
#define CONF_USB_MSC_LUN1_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN1_BLOCK_SIZE
#define CONF_USB_MSC_LUN1_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN1_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN1_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN1_CAPACITY * 1024 / CONF_USB_MSC_LUN1_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for LUN 2
// <id> conf_usb_msc_lun2_enable
#ifndef CONF_USB_MSC_LUN2_ENABLE
#define CONF_USB_MSC_LUN2_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN2_TYPE
#define CONF_USB_MSC_LUN2_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun2_rmb
#ifndef CONF_USB_MSC_LUN2_RMB
#define CONF_USB_MSC_LUN2_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN2_ISO
#define CONF_USB_MSC_LUN2_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_ECMA
#define CONF_USB_MSC_LUN2_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_ANSI
#define CONF_USB_MSC_LUN2_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_REPO
#define CONF_USB_MSC_LUN2_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN2_FACTORY
#define CONF_USB_MSC_LUN2_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_PRODUCT
#define CONF_USB_MSC_LUN2_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_PRODUCT_VERSION
#define CONF_USB_MSC_LUN2_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <id> conf_usb_msc_lun2_capacity

#ifndef CONF_USB_MSC_LUN2_CAPACITY
#define CONF_USB_MSC_LUN2_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN2_BLOCK_SIZE
#define CONF_USB_MSC_LUN2_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN2_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN2_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN2_CAPACITY * 1024 / CONF_USB_MSC_LUN2_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for LUN 3
// <id> conf_usb_msc_lun3_enable
#ifndef CONF_USB_MSC_LUN3_ENABLE
#define CONF_USB_MSC_LUN3_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN3_TYPE
#define CONF_USB_MSC_LUN3_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun3_rmb
#ifndef CONF_USB_MSC_LUN3_RMB
#define CONF_USB_MSC_LUN3_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN3_ISO
#define CONF_USB_MSC_LUN3_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_ECMA
#define CONF_USB_MSC_LUN3_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_ANSI
#define CONF_USB_MSC_LUN3_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_REPO
#define CONF_USB_MSC_LUN3_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN3_FACTORY
#define CONF_USB_MSC_LUN3_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_PRODUCT
#define CONF_USB_MSC_LUN3_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_PRODUCT_VERSION
#define CONF_USB_MSC_LUN3_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <id> conf_usb_msc_lun3_capacity

#ifndef CONF_USB_MSC_LUN3_CAPACITY
#define CONF_USB_MSC_LUN3_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN3_BLOCK_SIZE
#define CONF_USB_MSC_LUN3_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN3_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN3_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN3_CAPACITY * 1024 / CONF_USB_MSC_LUN3_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for LUN 4
// <id> conf_usb_msc_lun4_enable
#ifndef CONF_USB_MSC_LUN4_ENABLE
#define CONF_USB_MSC_LUN4_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN4_TYPE
#define CONF_USB_MSC_LUN4_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun4_rmb
#ifndef CONF_USB_MSC_LUN4_RMB
#define CONF_USB_MSC_LUN4_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN4_ISO
#define CONF_USB_MSC_LUN4_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN4_ECMA
#define CONF_USB_MSC_LUN4_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN4_ANSI
#define CONF_USB_MSC_LUN4_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN4_REPO
#define CONF_USB_MSC_LUN4_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN4_FACTORY
#define CONF_USB_MSC_LUN4_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN4_PRODUCT
#define CONF_USB_MSC_LUN4_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN4_PRODUCT_VERSION
#define CONF_USB_MSC_LUN4_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <id> conf_usb_msc_lun4_capacity

#ifndef CONF_USB_MSC_LUN4_CAPACITY
#define CONF_USB_MSC_LUN4_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN4_BLOCK_SIZE
#define CONF_USB_MSC_LUN4_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN4_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN4_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN4_CAPACITY * 1024 / CONF_USB_MSC_LUN4_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for LUN 5
// <id> conf_usb_msc_lun5_enable
#ifndef CONF_USB_MSC_LUN5_ENABLE
#define CONF_USB_MSC_LUN5_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN5_TYPE
#define CONF_USB_MSC_LUN5_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun5_rmb
#ifndef CONF_USB_MSC_LUN5_RMB
#define CONF_USB_MSC_LUN5_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN5_ISO
#define CONF_USB_MSC_LUN5_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN5_ECMA
#define CONF_USB_MSC_LUN5_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN5_ANSI
#define CONF_USB_MSC_LUN5_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN5_REPO
#define CONF_USB_MSC_LUN5_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN5_FACTORY
#define CONF_USB_MSC_LUN5_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN5_PRODUCT
#define CONF_USB_MSC_LUN5_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN5_PRODUCT_VERSION
#define CONF_USB_MSC_LUN5_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <id> conf_usb_msc_lun5_capacity

#ifndef CONF_USB_MSC_LUN5_CAPACITY
#define CONF_USB_MSC_LUN5_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN5_BLOCK_SIZE
#define CONF_USB_MSC_LUN5_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN5_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN5_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN5_CAPACITY * 1024 / CONF_USB_MSC_LUN5_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for LUN 6
// <id> conf_usb_msc_lun6_enable
#ifndef CONF_USB_MSC_LUN6_ENABLE
#define CONF_USB_MSC_LUN6_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN6_TYPE
#define CONF_USB_MSC_LUN6_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun6_rmb
#ifndef CONF_USB_MSC_LUN6_RMB
#define CONF_USB_MSC_LUN6_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN6_ISO
#define CONF_USB_MSC_LUN6_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN6_ECMA
#define CONF_USB_MSC_LUN6_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN6_ANSI
#define CONF_USB_MSC_LUN6_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN6_REPO
#define CONF_USB_MSC_LUN6_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN6_FACTORY
#define CONF_USB_MSC_LUN6_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN6_PRODUCT
#define CONF_USB_MSC_LUN6_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN6_PRODUCT_VERSION
#define CONF_USB_MSC_LUN6_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <id> conf_usb_msc_lun6_capacity

#ifndef CONF_USB_MSC_LUN6_CAPACITY
#define CONF_USB_MSC_LUN6_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN6_BLOCK_SIZE
#define CONF_USB_MSC_LUN6_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN6_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN6_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN6_CAPACITY * 1024 / CONF_USB_MSC_LUN6_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for LUN 7
// <id> conf_usb_msc_lun7_enable
#ifndef CONF_USB_MSC_LUN7_ENABLE
#define CONF_USB_MSC_LUN7_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN7_TYPE
#define CONF_USB_MSC_LUN7_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun7_rmb
#ifndef CONF_USB_MSC_LUN7_RMB
#define CONF_USB_MSC_LUN7_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN7_ISO
#define CONF_USB_MSC_LUN7_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN7_ECMA
#define CONF_USB_MSC_LUN7_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN7_ANSI
#define CONF_USB_MSC_LUN7_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN7_REPO
#define CONF_USB_MSC_LUN7_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN7_FACTORY
#define CONF_USB_MSC_LUN7_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN7_PRODUCT
#define CONF_USB_MSC_LUN7_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN7_PRODUCT_VERSION
#define CONF_USB_MSC_LUN7_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <id> conf_usb_msc_lun7_capacity

#ifndef CONF_USB_MSC_LUN7_CAPACITY
#define CONF_USB_MSC_LUN7_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN7_BLOCK_SIZE
#define CONF_USB_MSC_LUN7_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN7_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN7_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN7_CAPACITY * 1024 / CONF_USB_MSC_LUN7_BLOCK_SIZE - 1)
#endif

// </e>

// </e>

// ---- USB Device Stack Vendor Options ----

// <e> Enable String Descriptors
// <id> usb_vendor_str_en
#ifndef CONF_USB_VENDOR_STR_EN
#define CONF_USB_VENDOR_STR_EN 0
#endif
// <s> Language IDs
// <i> Language IDs in c format, split by comma (E.g., 0x0409 ...)
// <id> usb_vendor_langid
#ifndef CONF_USB_VENDOR_LANGID
#define CONF_USB_VENDOR_LANGID "0x0409"
#endif

#ifndef CONF_USB_VENDOR_LANGID_DESC
#define CONF_USB_VENDOR_LANGID_DESC
#endif
// </e>

// <h> Vendor Class Device Descriptor

// <o> bcdUSB
// <0x0200=> USB 2.0 version
// <0x0210=> USB 2.1 version
// <id> usb_vendor_bcdusb
#ifndef CONF_USB_VENDOR_BCDUSB
#define CONF_USB_VENDOR_BCDUSB 0x200
#endif

// <o> bMaxPackeSize0
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_vendor_bmaxpksz0
#ifndef CONF_USB_VENDOR_BMAXPKSZ0
#define CONF_USB_VENDOR_BMAXPKSZ0 0x40
#endif

// <o> idVender <0x0000-0xFFFF>
// <id> usb_vendor_idvender
#ifndef CONF_USB_VENDOR_IDVENDER
#define CONF_USB_VENDOR_IDVENDER 0x3eb
#endif

// <o> idProduct <0x0000-0xFFFF>
// <id> usb_vendor_idproduct
#ifndef CONF_USB_VENDOR_IDPRODUCT
#define CONF_USB_VENDOR_IDPRODUCT 0x2423
#endif

// <o> bcdDevice <0x0000-0xFFFF>
// <id> usb_vendor_bcddevice
#ifndef CONF_USB_VENDOR_BCDDEVICE
#define CONF_USB_VENDOR_BCDDEVICE 0x100
#endif

// <e> Enable string descriptor of iManufact
// <id> usb_vendor_imanufact_en
#ifndef CONF_USB_VENDOR_IMANUFACT_EN
#define CONF_USB_VENDOR_IMANUFACT_EN 0
#endif

#ifndef CONF_USB_VENDOR_IMANUFACT
#define CONF_USB_VENDOR_IMANUFACT (CONF_USB_VENDOR_IMANUFACT_EN * (CONF_USB_VENDOR_IMANUFACT_EN))
#endif

// <s> Unicode string of iManufact
// <id> usb_vendor_imanufact_str
#ifndef CONF_USB_VENDOR_IMANUFACT_STR
#define CONF_USB_VENDOR_IMANUFACT_STR "Atmel"
#endif

#ifndef CONF_USB_VENDOR_IMANUFACT_STR_DESC
#define CONF_USB_VENDOR_IMANUFACT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iProduct
// <id> usb_vendor_iproduct_en
#ifndef CONF_USB_VENDOR_IPRODUCT_EN
#define CONF_USB_VENDOR_IPRODUCT_EN 0
#endif

#ifndef CONF_USB_VENDOR_IPRODUCT
#define CONF_USB_VENDOR_IPRODUCT                                                                                       \
	(CONF_USB_VENDOR_IPRODUCT_EN * (CONF_USB_VENDOR_IMANUFACT_EN + CONF_USB_VENDOR_IPRODUCT_EN))
#endif

// <s> Unicode string of iProduct
// <id> usb_vendor_iproduct_str
#ifndef CONF_USB_VENDOR_IPRODUCT_STR
#define CONF_USB_VENDOR_IPRODUCT_STR "Vendor Class Demo"
#endif

#ifndef CONF_USB_VENDOR_IPRODUCT_STR_DESC
#define CONF_USB_VENDOR_IPRODUCT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iSerialNum
// <id> usb_vendor_iserialnum_en
#ifndef CONF_USB_VENDOR_ISERIALNUM_EN
#define CONF_USB_VENDOR_ISERIALNUM_EN 0
#endif

#ifndef CONF_USB_VENDOR_ISERIALNUM
#define CONF_USB_VENDOR_ISERIALNUM                                                                                     \
	(CONF_USB_VENDOR_ISERIALNUM_EN                                                                                     \
	 * (CONF_USB_VENDOR_IMANUFACT_EN + CONF_USB_VENDOR_IPRODUCT_EN + CONF_USB_VENDOR_ISERIALNUM_EN))
#endif

// <s> Unicode string of iSerialNum
// <id> usb_vendor_iserialnum_str
#ifndef CONF_USB_VENDOR_ISERIALNUM_STR
#define CONF_USB_VENDOR_ISERIALNUM_STR "123456789ABCDEF"
#endif

#ifndef CONF_USB_VENDOR_ISERIALNUM_STR_DESC
#define CONF_USB_VENDOR_ISERIALNUM_STR_DESC
#endif

// </e>

// </h>

// <h> Vendor Class Configuration Descriptor

// <e> Enable string descriptor of iConfig
// <id> usb_vendor_iconfig_en
#ifndef CONF_USB_VENDOR_ICONFIG_EN
#define CONF_USB_VENDOR_ICONFIG_EN 0
#endif

#ifndef CONF_USB_VENDOR_ICONFIG
#define CONF_USB_VENDOR_ICONFIG                                                                                        \
	(CONF_USB_VENDOR_ICONFIG_EN                                                                                        \
	 * (CONF_USB_VENDOR_IMANUFACT_EN + CONF_USB_VENDOR_IPRODUCT_EN + CONF_USB_VENDOR_ISERIALNUM_EN                     \
	    + CONF_USB_VENDOR_ICONFIG_EN))
#endif

// <s> Unicode string of iConfig
// <id> usb_vendor_iconfig_str
#ifndef CONF_USB_VENDOR_ICONFIG_STR
#define CONF_USB_VENDOR_ICONFIG_STR ""
#endif

#ifndef CONF_USB_VENDOR_ICONFIG_STR_DESC
#define CONF_USB_VENDOR_ICONFIG_STR_DESC
#endif

// </e>

// <o> bmAttributes
// <0x80=> Bus power supply, not support for remote wakeup
// <0xA0=> Bus power supply, support for remote wakeup
// <0xC0=> Self powered, not support for remote wakeup
// <0xE0=> Self powered, support for remote wakeup
// <id> usb_vendor_bmattri
#ifndef CONF_USB_VENDOR_BMATTRI
#define CONF_USB_VENDOR_BMATTRI 0x80
#endif

// <o> bMaxPower <0x00-0xFF>
// <id> usb_vendor_bmaxpower
#ifndef CONF_USB_VENDOR_BMAXPOWER
#define CONF_USB_VENDOR_BMAXPOWER 0x32
#endif
// </h>

// <h> Vendor Interface Descriptor

// <o> bInterfaceNumber <0x00-0xFF>
// <id> usb_vendor_bifcnum
#ifndef CONF_USB_VENDOR_BIFCNUM
#define CONF_USB_VENDOR_BIFCNUM 0x0
#endif

// <o> iInterface <0x00-0xFF>
// <id> usb_vendor_iifc
#ifndef CONF_USB_VENDOR_IIFC
#define CONF_USB_VENDOR_IIFC 0x0
#endif

// <o> INTERRUPT IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_vendor_intin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_INTIN_EPADDR
#define CONF_USB_VENDOR_INTIN_EPADDR 0x81
#endif

// <o> INTERRUPT IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_vendor_intin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_INTIN_MAXPKSZ
#define CONF_USB_VENDOR_INTIN_MAXPKSZ 0x40
#endif

// <o> INTERRUPT OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <id> usb_vendor_intout_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_INTOUT_EPADDR
#define CONF_USB_VENDOR_INTOUT_EPADDR 0x2
#endif

// <o> INTERRUPT OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_vendor_intout_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_INTOUT_MAXPKSZ
#define CONF_USB_VENDOR_INTOUT_MAXPKSZ 0x40
#endif

// <o> BULK IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_vendor_bulkin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_BULKIN_EPADDR
#define CONF_USB_VENDOR_BULKIN_EPADDR 0x83
#endif

// <o> BULK IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_vendor_bulkin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_BULKIN_MAXPKSZ
#define CONF_USB_VENDOR_BULKIN_MAXPKSZ 0x40
#endif

// <o> BULK OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <id> usb_vendor_bulkout_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_BULKOUT_EPADDR
#define CONF_USB_VENDOR_BULKOUT_EPADDR 0x4
#endif

// <o> BULK OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_vendor_bulkout_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_BULKOUT_MAXPKSZ
#define CONF_USB_VENDOR_BULKOUT_MAXPKSZ 0x40
#endif

// <o> ISOCHRONOUS IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <id> usb_vendor_isoin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_ISOIN_EPADDR
#define CONF_USB_VENDOR_ISOIN_EPADDR 0x85
#endif

// <o> ISOCHRONOUS IN Endpoint wMaxPacketSize
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <id> usb_vendor_isoin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_ISOIN_MAXPKSZ
#define CONF_USB_VENDOR_ISOIN_MAXPKSZ 0x100
#endif

// <o> ISOCHRONOUS OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <id> usb_vendor_isoout_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_ISOOUT_EPADDR
#define CONF_USB_VENDOR_ISOOUT_EPADDR 0x6
#endif

// <o> ISOCHRONOUS OUT Endpoint wMaxPacketSize
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <id> usb_vendor_isoout_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_VENDOR_ISOOUT_MAXPKSZ
#define CONF_USB_VENDOR_ISOOUT_MAXPKSZ 0x100
#endif
// </h>

// ---- USB Device Stack Composite Options ----

// <e> Enable String Descriptors
// <id> usb_composite_str_en
#ifndef CONF_USB_COMPOSITE_STR_EN
#define CONF_USB_COMPOSITE_STR_EN 0
#endif
// <s> Language IDs
// <i> Language IDs in c format, split by comma (E.g., 0x0409 ...)
// <id> usb_composite_langid
#ifndef CONF_USB_COMPOSITE_LANGID
#define CONF_USB_COMPOSITE_LANGID "0x0409"
#endif

#ifndef CONF_USB_COMPOSITE_LANGID_DESC
#define CONF_USB_COMPOSITE_LANGID_DESC
#endif
// </e>

// <h> Composite Device Descriptor

// <o> bcdUSB
// <0x0200=> USB 2.0 version
// <0x0210=> USB 2.1 version
// <id> usb_composite_bcdusb
#ifndef CONF_USB_COMPOSITE_BCDUSB
#define CONF_USB_COMPOSITE_BCDUSB 0x200
#endif

// <o> bMaxPackeSize0
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_composite_bmaxpksz0
#ifndef CONF_USB_COMPOSITE_BMAXPKSZ0
#define CONF_USB_COMPOSITE_BMAXPKSZ0 0x40
#endif

// <o> idVender <0x0000-0xFFFF>
// <id> usb_composite_idvender
#ifndef CONF_USB_COMPOSITE_IDVENDER
#define CONF_USB_COMPOSITE_IDVENDER 0x3eb
#endif

// <o> idProduct <0x0000-0xFFFF>
// <id> usb_composite_idproduct
#ifndef CONF_USB_COMPOSITE_IDPRODUCT
#define CONF_USB_COMPOSITE_IDPRODUCT 0x2421
#endif

// <o> bcdDevice <0x0000-0xFFFF>
// <id> usb_composite_bcddevice
#ifndef CONF_USB_COMPOSITE_BCDDEVICE
#define CONF_USB_COMPOSITE_BCDDEVICE 0x100
#endif

// <e> Enable string descriptor of iManufact
// <id> usb_composite_imanufact_en
#ifndef CONF_USB_COMPOSITE_IMANUFACT_EN
#define CONF_USB_COMPOSITE_IMANUFACT_EN 0
#endif

#ifndef CONF_USB_COMPOSITE_IMANUFACT
#define CONF_USB_COMPOSITE_IMANUFACT (CONF_USB_COMPOSITE_IMANUFACT_EN * (CONF_USB_COMPOSITE_IMANUFACT_EN))
#endif

// <s> Unicode string of iManufact
// <id> usb_composite_imanufact_str
#ifndef CONF_USB_COMPOSITE_IMANUFACT_STR
#define CONF_USB_COMPOSITE_IMANUFACT_STR "Atmel"
#endif

#ifndef CONF_USB_COMPOSITE_IMANUFACT_STR_DESC
#define CONF_USB_COMPOSITE_IMANUFACT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iProduct
// <id> usb_composite_iproduct_en
#ifndef CONF_USB_COMPOSITE_IPRODUCT_EN
#define CONF_USB_COMPOSITE_IPRODUCT_EN 0
#endif

#ifndef CONF_USB_COMPOSITE_IPRODUCT
#define CONF_USB_COMPOSITE_IPRODUCT                                                                                    \
	(CONF_USB_COMPOSITE_IPRODUCT_EN * (CONF_USB_COMPOSITE_IMANUFACT_EN + CONF_USB_COMPOSITE_IPRODUCT_EN))
#endif

// <s> Unicode string of iProduct
// <id> usb_composite_iproduct_str
#ifndef CONF_USB_COMPOSITE_IPRODUCT_STR
#define CONF_USB_COMPOSITE_IPRODUCT_STR "Composite Demo"
#endif

#ifndef CONF_USB_COMPOSITE_IPRODUCT_STR_DESC
#define CONF_USB_COMPOSITE_IPRODUCT_STR_DESC
#endif

// </e>

// <e> Enable string descriptor of iSerialNum
// <id> usb_composite_iserialnum_en
#ifndef CONF_USB_COMPOSITE_ISERIALNUM_EN
#define CONF_USB_COMPOSITE_ISERIALNUM_EN 0
#endif

#ifndef CONF_USB_COMPOSITE_ISERIALNUM
#define CONF_USB_COMPOSITE_ISERIALNUM                                                                                  \
	(CONF_USB_COMPOSITE_ISERIALNUM_EN                                                                                  \
	 * (CONF_USB_COMPOSITE_IMANUFACT_EN + CONF_USB_COMPOSITE_IPRODUCT_EN + CONF_USB_COMPOSITE_ISERIALNUM_EN))
#endif

// <s> Unicode string of iSerialNum
// <id> usb_composite_iserialnum_str
#ifndef CONF_USB_COMPOSITE_ISERIALNUM_STR
#define CONF_USB_COMPOSITE_ISERIALNUM_STR "123456789ABCDEF"
#endif

#ifndef CONF_USB_COMPOSITE_ISERIALNUM_STR_DESC
#define CONF_USB_COMPOSITE_ISERIALNUM_STR_DESC
#endif

// </e>

// <o> bNumConfigurations <0x01-0xFF>
// <id> usb_composite_bnumconfig
#ifndef CONF_USB_COMPOSITE_BNUMCONFIG
#define CONF_USB_COMPOSITE_BNUMCONFIG 0x1
#endif

// </h>

// <h> Composite Configuration Descriptor
// <o> bConfigurationValue <0x01-0xFF>
// <id> usb_composite_bconfigval
#ifndef CONF_USB_COMPOSITE_BCONFIGVAL
#define CONF_USB_COMPOSITE_BCONFIGVAL 0x1
#endif
// <e> Enable string descriptor of iConfig
// <id> usb_composite_iconfig_en
#ifndef CONF_USB_COMPOSITE_ICONFIG_EN
#define CONF_USB_COMPOSITE_ICONFIG_EN 0
#endif

#ifndef CONF_USB_COMPOSITE_ICONFIG
#define CONF_USB_COMPOSITE_ICONFIG                                                                                     \
	(CONF_USB_COMPOSITE_ICONFIG_EN                                                                                     \
	 * (CONF_USB_COMPOSITE_IMANUFACT_EN + CONF_USB_COMPOSITE_IPRODUCT_EN + CONF_USB_COMPOSITE_ISERIALNUM_EN            \
	    + CONF_USB_COMPOSITE_ICONFIG_EN))
#endif

// <s> Unicode string of iConfig
// <id> usb_composite_iconfig_str
#ifndef CONF_USB_COMPOSITE_ICONFIG_STR
#define CONF_USB_COMPOSITE_ICONFIG_STR ""
#endif

#ifndef CONF_USB_COMPOSITE_ICONFIG_STR_DESC
#define CONF_USB_COMPOSITE_ICONFIG_STR_DESC
#endif

// </e>

// <o> bmAttributes
// <0x80=> Bus power supply, not support for remote wakeup
// <0xA0=> Bus power supply, support for remote wakeup
// <0xC0=> Self powered, not support for remote wakeup
// <0xE0=> Self powered, support for remote wakeup
// <id> usb_composite_bmattri
#ifndef CONF_USB_COMPOSITE_BMATTRI
#define CONF_USB_COMPOSITE_BMATTRI 0x80
#endif

// <o> bMaxPower <0x00-0xFF>
// <id> usb_composite_bmaxpower
#ifndef CONF_USB_COMPOSITE_BMAXPOWER
#define CONF_USB_COMPOSITE_BMAXPOWER 0x32
#endif
// </h>

// <e> CDC ACM Support
// <id> usb_composite_cdc_acm_support
#ifndef CONF_USB_COMPOSITE_CDC_ACM_EN
#define CONF_USB_COMPOSITE_CDC_ACM_EN 0
#endif

// <o> CDC ACM Comm Interrupt IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <0x88=> EndpointAddress = 0x88
// <0x89=> EndpointAddress = 0x89

// <id> usb_composite_cdc_acm_epaddr
#ifndef CONF_USB_COMPOSITE_CDC_ACM_COMM_INT_EPADDR
#define CONF_USB_COMPOSITE_CDC_ACM_COMM_INT_EPADDR 0x82
#endif

// <o> CDC ACM Comm Interrupt IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes

// <id> usb_composite_cdc_acm_comm_int_maxpksz
#ifndef CONF_USB_COMPOSITE_CDC_ACM_COMM_INT_MAXPKSZ
#define CONF_USB_COMPOSITE_CDC_ACM_COMM_INT_MAXPKSZ 0x40
#endif

// <o> CDC ACM Data BULK IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <0x88=> EndpointAddress = 0x88
// <0x89=> EndpointAddress = 0x89

// <id> usb_composite_cdc_acm_data_bulkin_epaddr
#ifndef CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_EPADDR
#define CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_EPADDR 0x81
#endif

// <o> CDC ACM Data BULK IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes

// <id> usb_composite_cdc_acm_data_builin_maxpksz
#ifndef CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_MAXPKSZ
#define CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_MAXPKSZ 0x40
#endif

// <o> CDC ACM Data BULK IN Endpoint wMaxPacketSize for High Speed
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <0x0200=> 512 bytes

// <id> usb_composite_cdc_acm_data_builin_maxpksz_hs
#ifndef CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_MAXPKSZ_HS
#define CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKIN_MAXPKSZ_HS 0x200
#endif

// <o> CDC ACM Data BULK OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <0x08=> EndpointAddress = 0x08
// <0x09=> EndpointAddress = 0x09

// <id> usb_composite_cdc_acm_data_bulkout_epaddr
#ifndef CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_EPADDR
#define CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_EPADDR 0x1
#endif

// <o> CDC ACM Data BULK OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes

// <id> usb_composite_cdc_acm_data_buckout_maxpksz
#ifndef CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_MAXPKSZ
#define CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_MAXPKSZ 0x40
#endif

// <o> CDC ACM Data BULK OUT Endpoint wMaxPacketSize for High Speed
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <0x0200=> 512 bytes

// <id> usb_composite_cdc_acm_data_buckout_maxpksz_hs
#ifndef CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_MAXPKSZ_HS
#define CONF_USB_COMPOSITE_CDC_ACM_DATA_BULKOUT_MAXPKSZ_HS 0x200
#endif

// <q> CDC ACM Echo Demo generation
// <id> conf_usb_composite_cdc_echo_demo
// <i> Invoke cdcdf_acm_demo_init(buf[wMaxPacketSize]) to enable the echo demo.
// <i> Buf is packet buffer for data receive and echo back.
// <i> The buffer is 4 byte aligned to support DMA.
#ifndef CONF_USB_COMPOSITE_CDC_ECHO_DEMO
#define CONF_USB_COMPOSITE_CDC_ECHO_DEMO 0
#endif

// </e>

// <e> HID Mouse Support
// <id> usb_composite_hid_mouse_support
#ifndef CONF_USB_COMPOSITE_HID_MOUSE_EN
#define CONF_USB_COMPOSITE_HID_MOUSE_EN 0
#endif

// <o> HID Mouse INTERRUPT IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <0x88=> EndpointAddress = 0x88
// <0x89=> EndpointAddress = 0x89

// <id> usb_composite_hid_mouse_intin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_MOUSE_INTIN_EPADDR
#define CONF_USB_COMPOSITE_HID_MOUSE_INTIN_EPADDR 0x83
#endif

// <o> HID Mouse INTERRUPT IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes

// <id> usb_composite_hid_mouse_intin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_MOUSE_INTIN_MAXPKSZ
#define CONF_USB_COMPOSITE_HID_MOUSE_INTIN_MAXPKSZ 0x8
#endif

// <q> HID Mouse Move Demo generation
// <id> conf_usb_composite_hid_mouse_demo
// <i> Invoke hiddf_demo_init(button1, button2, button3) to enabled the move demo.
// <i> Button1 and button3 are the pins used for mouse moving left and right.
#ifndef CONF_USB_COMPOSITE_HID_MOUSE_DEMO
#define CONF_USB_COMPOSITE_HID_MOUSE_DEMO 0
#endif

// </e>

// <e> HID Keyboard Support
// <id> usb_composite_hid_keyboard_support
#ifndef CONF_USB_COMPOSITE_HID_KEYBOARD_EN
#define CONF_USB_COMPOSITE_HID_KEYBOARD_EN 0
#endif

// <o> HID Keyboard INTERRUPT IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <0x88=> EndpointAddress = 0x88
// <0x89=> EndpointAddress = 0x89

// <id> usb_composite_hid_keyboard_intin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_KEYBOARD_INTIN_EPADDR
#define CONF_USB_COMPOSITE_HID_KEYBOARD_INTIN_EPADDR 0x84
#endif

// <o> HID Keyboard INTERRUPT IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes

// <id> usb_composite_hid_keyboard_intin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_KEYBOARD_INTIN_MAXPKSZ
#define CONF_USB_COMPOSITE_HID_KEYBOARD_INTIN_MAXPKSZ 0x8
#endif

// <o> HID Keyboard INTERRUPT OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <0x08=> EndpointAddress = 0x08
// <0x09=> EndpointAddress = 0x09

// <id> usb_composite_hid_keyboard_intout_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_KEYBOARD_INTOUT_EPADDR
#define CONF_USB_COMPOSITE_HID_KEYBOARD_INTOUT_EPADDR 0x2
#endif

// <o> HID Keyboard INTERRUPT OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes

// <id> usb_composite_hid_keyboard_intout_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_KEYBOARD_INTOUT_MAXPKSZ
#define CONF_USB_COMPOSITE_HID_KEYBOARD_INTOUT_MAXPKSZ 0x8
#endif

// <q> HID Keyboard Caps Lock Demo generation
// <id> conf_usb_composite_hid_keyboard_demo
// <i> Invoke hiddf_demo_init(button1, button2, button3) to enabled the move demo.
// <i> Buffon2 is the pin used for keyboard CAPS LOCK simulation.
#ifndef CONF_USB_COMPOSITE_HID_KEYBOARD_DEMO
#define CONF_USB_COMPOSITE_HID_KEYBOARD_DEMO 0
#endif

// </e>

// <e> HID Generic Support
// <id> usb_composite_hid_generic_support
#ifndef CONF_USB_COMPOSITE_HID_GENERIC_EN
#define CONF_USB_COMPOSITE_HID_GENERIC_EN 0
#endif

#ifndef CONF_USB_COMPOSITE_HID_GENERIC_REPORT_LEN
#define CONF_USB_COMPOSITE_HID_GENERIC_REPORT_LEN 53
#endif

#ifndef CONF_USB_COMPOSITE_HID_GENERIC_REPORT
#define CONF_USB_COMPOSITE_HID_GENERIC_REPORT                                                                          \
	0x06, 0xFF, 0xFF, 0x09, 0x01, 0xA1, 0x01, 0x09, 0x02, 0x09, 0x03, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x75, 0x08, 0x95,  \
	    0x40, 0x81, 0x02, 0x09, 0x04, 0x09, 0x05, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x75, 0x08, 0x95, 0x40, 0x91, 0x02,    \
	    0x09, 0x06, 0x09, 0x07, 0x15, 0x00, 0x26, 0xFF, 0x00, 0x75, 0x08, 0x95, 0x04, 0xB1, 0x02, 0xC0
#endif

// <o> HID Generic INTERRUPT IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <0x88=> EndpointAddress = 0x88
// <0x89=> EndpointAddress = 0x89

// <id> usb_composite_hid_generic_intin_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_GENERIC_INTIN_EPADDR
#define CONF_USB_COMPOSITE_HID_GENERIC_INTIN_EPADDR 0x85
#endif

// <o> HID Generic INTERRUPT IN Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes

// <id> usb_composite_hid_generic_intin_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_GENERIC_INTIN_MAXPKSZ
#define CONF_USB_COMPOSITE_HID_GENERIC_INTIN_MAXPKSZ 0x40
#endif

// <o> HID Generic INTERRUPT OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <0x08=> EndpointAddress = 0x08
// <0x09=> EndpointAddress = 0x09

// <id> usb_composite_hid_generic_intout_epaddr
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_GENERIC_INTOUT_EPADDR
#define CONF_USB_COMPOSITE_HID_GENERIC_INTOUT_EPADDR 0x3
#endif

// <o> HID Generic INTERRUPT OUT Endpoint wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <id> usb_composite_hid_generic_intout_maxpksz
// <i> Please make sure that the setting here is coincide with the endpoint setting in USB device driver.
#ifndef CONF_USB_COMPOSITE_HID_GENERIC_INTOUT_MAXPKSZ
#define CONF_USB_COMPOSITE_HID_GENERIC_INTOUT_MAXPKSZ 0x40
#endif

// </e>

// <e> MSC Support
// <id> usb_composite_msc_support
#ifndef CONF_USB_COMPOSITE_MSC_EN
#define CONF_USB_COMPOSITE_MSC_EN 0
#endif

// <o> MSC BULK Endpoints wMaxPacketSize
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes

// <id> usb_composite_msc_bulk_maxpksz
#ifndef CONF_USB_COMPOSITE_MSC_BULK_MAXPKSZ
#define CONF_USB_COMPOSITE_MSC_BULK_MAXPKSZ 0x40
#endif

// <o> MSC BULK Endpoints wMaxPacketSize for High Speed
// <0x0008=> 8 bytes
// <0x0010=> 16 bytes
// <0x0020=> 32 bytes
// <0x0040=> 64 bytes
// <0x0080=> 128 bytes
// <0x0100=> 256 bytes
// <0x0200=> 512 bytes

// <id> usb_composite_msc_bulk_maxpksz_hs
#ifndef CONF_USB_COMPOSITE_MSC_BULK_MAXPKSZ_HS
#define CONF_USB_COMPOSITE_MSC_BULK_MAXPKSZ_HS 0x200
#endif

// <o> MSC BULK IN Endpoint Address
// <0x81=> EndpointAddress = 0x81
// <0x82=> EndpointAddress = 0x82
// <0x83=> EndpointAddress = 0x83
// <0x84=> EndpointAddress = 0x84
// <0x85=> EndpointAddress = 0x85
// <0x86=> EndpointAddress = 0x86
// <0x87=> EndpointAddress = 0x87
// <0x88=> EndpointAddress = 0x88
// <0x89=> EndpointAddress = 0x89

// <id> usb_composite_msc_bulkin_epaddr
#ifndef CONF_USB_COMPOSITE_MSC_BULKIN_EPADDR
#define CONF_USB_COMPOSITE_MSC_BULKIN_EPADDR 0x86
#endif

// <o> MSC BULK OUT Endpoint Address
// <0x01=> EndpointAddress = 0x01
// <0x02=> EndpointAddress = 0x02
// <0x03=> EndpointAddress = 0x03
// <0x04=> EndpointAddress = 0x04
// <0x05=> EndpointAddress = 0x05
// <0x06=> EndpointAddress = 0x06
// <0x07=> EndpointAddress = 0x07
// <0x08=> EndpointAddress = 0x08
// <0x09=> EndpointAddress = 0x09

// <id> usb_composite_msc_bulkout_epaddr
#ifndef CONF_USB_COMPOSITE_MSC_BULKOUT_EPADDR
#define CONF_USB_COMPOSITE_MSC_BULKOUT_EPADDR 0x4
#endif

// <e> Enable Demo code for Disk LUN handling
// <id> usb_composite_msc_demo_en
#ifndef CONF_USB_COMPOSITE_MSC_LUN_DEMO
#define CONF_USB_COMPOSITE_MSC_LUN_DEMO 1
#endif

// <o> Disk access cache/buffer of sectors if non-RAM disk (e.g., SD/MMC) enabled <1-64>
// <id> conf_usb_msc_lun_buf_sectors
#ifndef CONF_USB_MSC_LUN_BUF_SECTORS
#define CONF_USB_MSC_LUN_BUF_SECTORS 4
#endif

// <e> Enable Demo for RAM Disk
// <id> conf_usb_msc_lun0_enable
#ifndef CONF_USB_MSC_LUN0_ENABLE
#define CONF_USB_MSC_LUN0_ENABLE 1
#endif

#ifndef CONF_USB_MSC_LUN0_TYPE
#define CONF_USB_MSC_LUN0_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun0_rmb
#ifndef CONF_USB_MSC_LUN0_RMB
#define CONF_USB_MSC_LUN0_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN0_ISO
#define CONF_USB_MSC_LUN0_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_ECMA
#define CONF_USB_MSC_LUN0_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_ANSI
#define CONF_USB_MSC_LUN0_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_REPO
#define CONF_USB_MSC_LUN0_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN0_FACTORY
#define CONF_USB_MSC_LUN0_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_PRODUCT
#define CONF_USB_MSC_LUN0_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN0_PRODUCT_VERSION
#define CONF_USB_MSC_LUN0_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <i> Windows will not show disk less than 20K, so 22K is used to reserve more RAM for APP
// <id> conf_usb_msc_lun0_capacity

#ifndef CONF_USB_MSC_LUN0_CAPACITY
#define CONF_USB_MSC_LUN0_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN0_BLOCK_SIZE
#define CONF_USB_MSC_LUN0_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN0_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN0_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN0_CAPACITY * 1024 / CONF_USB_MSC_LUN0_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for SD/MMC Disk
// <i> SD/MMC stack must be added before enable SD/MMC demo
// <i> SD/MMC insert/eject not supported by this simple demo
// <id> conf_usb_msc_lun1_enable
#ifndef CONF_USB_MSC_LUN1_ENABLE
#define CONF_USB_MSC_LUN1_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN1_TYPE
#define CONF_USB_MSC_LUN1_TYPE 0x00
#endif

// <q> The disk is removable
// <i> SD/MMC stack must be added before enable SD/MMC demo
// <i> SD/MMC insert/eject not supported by this simple demo
// <id> conf_usb_msc_lun1_rmb
#ifndef CONF_USB_MSC_LUN1_RMB
#define CONF_USB_MSC_LUN1_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN1_ISO
#define CONF_USB_MSC_LUN1_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_ECMA
#define CONF_USB_MSC_LUN1_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_ANSI
#define CONF_USB_MSC_LUN1_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_REPO
#define CONF_USB_MSC_LUN1_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN1_FACTORY
#define CONF_USB_MSC_LUN1_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_PRODUCT
#define CONF_USB_MSC_LUN1_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_PRODUCT_VERSION
#define CONF_USB_MSC_LUN1_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN1_CAPACITY
#define CONF_USB_MSC_LUN1_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN1_BLOCK_SIZE
#define CONF_USB_MSC_LUN1_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN1_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN1_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN1_CAPACITY * 1024 / CONF_USB_MSC_LUN1_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for LUN 2
// <id> conf_usb_msc_lun2_enable
#ifndef CONF_USB_MSC_LUN2_ENABLE
#define CONF_USB_MSC_LUN2_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN2_TYPE
#define CONF_USB_MSC_LUN2_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun2_rmb
#ifndef CONF_USB_MSC_LUN2_RMB
#define CONF_USB_MSC_LUN2_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN2_ISO
#define CONF_USB_MSC_LUN2_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_ECMA
#define CONF_USB_MSC_LUN2_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_ANSI
#define CONF_USB_MSC_LUN2_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_REPO
#define CONF_USB_MSC_LUN2_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN2_FACTORY
#define CONF_USB_MSC_LUN2_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_PRODUCT
#define CONF_USB_MSC_LUN2_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN2_PRODUCT_VERSION
#define CONF_USB_MSC_LUN2_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <id> conf_usb_msc_lun2_capacity

#ifndef CONF_USB_MSC_LUN2_CAPACITY
#define CONF_USB_MSC_LUN2_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN2_BLOCK_SIZE
#define CONF_USB_MSC_LUN2_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN2_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN2_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN2_CAPACITY * 1024 / CONF_USB_MSC_LUN2_BLOCK_SIZE - 1)
#endif

// </e>

// <e> Enable Demo for LUN 3
// <id> conf_usb_msc_lun3_enable
#ifndef CONF_USB_MSC_LUN3_ENABLE
#define CONF_USB_MSC_LUN3_ENABLE 0
#endif

#ifndef CONF_USB_MSC_LUN3_TYPE
#define CONF_USB_MSC_LUN3_TYPE 0x00
#endif

// <q> The disk is removable
// <id> conf_usb_msc_lun3_rmb
#ifndef CONF_USB_MSC_LUN3_RMB
#define CONF_USB_MSC_LUN3_RMB 0x1
#endif

#ifndef CONF_USB_MSC_LUN3_ISO
#define CONF_USB_MSC_LUN3_ISO 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_ECMA
#define CONF_USB_MSC_LUN3_ECMA 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_ANSI
#define CONF_USB_MSC_LUN3_ANSI 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_REPO
#define CONF_USB_MSC_LUN3_REPO 0x01
#endif

#ifndef CONF_USB_MSC_LUN3_FACTORY
#define CONF_USB_MSC_LUN3_FACTORY 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_PRODUCT
#define CONF_USB_MSC_LUN3_PRODUCT 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif

#ifndef CONF_USB_MSC_LUN3_PRODUCT_VERSION
#define CONF_USB_MSC_LUN3_PRODUCT_VERSION 0x00, 0x00, 0x00, 0x00
#endif

// <o> Disk Size (in KB) <0x1-0xFFFFFFFF>
// <id> conf_usb_msc_lun3_capacity

#ifndef CONF_USB_MSC_LUN3_CAPACITY
#define CONF_USB_MSC_LUN3_CAPACITY 22
#endif

#ifndef CONF_USB_MSC_LUN3_BLOCK_SIZE
#define CONF_USB_MSC_LUN3_BLOCK_SIZE 512
#endif

#ifndef CONF_USB_MSC_LUN3_LAST_BLOCK_ADDR
#define CONF_USB_MSC_LUN3_LAST_BLOCK_ADDR                                                                              \
	((uint32_t)CONF_USB_MSC_LUN3_CAPACITY * 1024 / CONF_USB_MSC_LUN3_BLOCK_SIZE - 1)
#endif

// </e>

// </e>
// </e>

// <<< end of configuration section >>>

#endif // USBD_CONFIG_H
