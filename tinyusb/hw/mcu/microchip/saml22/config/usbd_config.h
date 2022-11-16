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

// ---- USB Device Stack Mass Storage Options ----

// <e> Enable String Descriptors
// <id> usb_msc_str_en
#ifndef CONF_USB_MSC_STR_EN
#define CONF_USB_MSC_STR_EN 1
#endif
// <s> Language IDs
// <i> Language IDs in c format, split by comma (E.g., 0x0409 ...)
// <id> usb_msc_langid
#ifndef CONF_USB_MSC_LANGID
#define CONF_USB_MSC_LANGID "0x0409"
#endif

#ifndef CONF_USB_MSC_LANGID_DESC
#define CONF_USB_MSC_LANGID_DESC 4, 0x03, 0x09, 0x04,
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
#define CONF_USB_MSC_ISERIALNUM_EN 1
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
#define CONF_USB_MSC_ISERIALNUM_STR_DESC                                                                               \
	32, 0x03, '1', 0x00, '2', 0x00, '3', 0x00, '4', 0x00, '5', 0x00, '6', 0x00, '7', 0x00, '8', 0x00, '9', 0x00, 'A',  \
	    0x00, 'B', 0x00, 'C', 0x00, 'D', 0x00, 'E', 0x00, 'F', 0x00,
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

// <<< end of configuration section >>>

#endif // USBD_CONFIG_H
