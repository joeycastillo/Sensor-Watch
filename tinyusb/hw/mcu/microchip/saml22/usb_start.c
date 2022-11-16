/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 */
#include "atmel_start.h"
#include "usb_start.h"

/* Max LUN number */
#define CONF_USB_MSC_MAX_LUN 0

#if CONF_USB_MSC_LUN_DEMO

/* MSC LUN number */
#define LUN_RAM 0

/* MSC LUN definitions */
#define DISK_INFORMATION(n)                                                                                            \
	{                                                                                                                  \
		CONF_USB_MSC_LUN##n##_TYPE, (CONF_USB_MSC_LUN##n##_RMB << 7),                                                  \
		    ((CONF_USB_MSC_LUN##n##_ISO << 6) + (CONF_USB_MSC_LUN##n##_ECMA << 3) + CONF_USB_MSC_LUN##n##_ANSI),       \
		    CONF_USB_MSC_LUN##n##_REPO, 31, 0x00, 0x00, 0x00, CONF_USB_MSC_LUN##n##_FACTORY,                           \
		    CONF_USB_MSC_LUN##n##_PRODUCT, CONF_USB_MSC_LUN##n##_PRODUCT_VERSION                                       \
	}

#define DISK_CAPACITY(n)                                                                                               \
	{                                                                                                                  \
		(uint8_t)(CONF_USB_MSC_LUN##n##_LAST_BLOCK_ADDR >> 24),                                                        \
		    (uint8_t)(CONF_USB_MSC_LUN##n##_LAST_BLOCK_ADDR >> 16),                                                    \
		    (uint8_t)(CONF_USB_MSC_LUN##n##_LAST_BLOCK_ADDR >> 8),                                                     \
		    (uint8_t)(CONF_USB_MSC_LUN##n##_LAST_BLOCK_ADDR >> 0),                                                     \
		    (uint8_t)((uint32_t)(CONF_USB_MSC_LUN##n##_BLOCK_SIZE) >> 24),                                             \
		    (uint8_t)((uint32_t)(CONF_USB_MSC_LUN##n##_BLOCK_SIZE) >> 16),                                             \
		    (uint8_t)((uint32_t)(CONF_USB_MSC_LUN##n##_BLOCK_SIZE) >> 8),                                              \
		    (uint8_t)((uint32_t)(CONF_USB_MSC_LUN##n##_BLOCK_SIZE) >> 0)                                               \
	}

/* MSC LUN settings */

static uint8_t *ram_disk_buf;

static uint8_t       msc_lun;
static bool          xfer_dir;
static volatile bool usb_busy;
static uint32_t      disk_addr;
static uint32_t      usb_remain = 0;

/* Inquiry Information */
static uint8_t inquiry_info[CONF_USB_MSC_MAX_LUN + 1][36] = {DISK_INFORMATION(0)};

/* Capacities of Disk */
static uint8_t format_capa[CONF_USB_MSC_MAX_LUN + 1][8] = {DISK_CAPACITY(0)};

#endif

#if CONF_USBD_HS_SP
static uint8_t single_desc_bytes[] = {
    /* Device descriptors and Configuration descriptors list. */
    MSC_HS_DESCES_LS_FS};
static uint8_t single_desc_bytes_hs[] = {
    /* Device descriptors and Configuration descriptors list. */
    MSC_HS_DESCES_HS};
#else
static uint8_t single_desc_bytes[] = {
    /* Device descriptors and Configuration descriptors list. */
    MSC_DESCES_LS_FS};
#endif

static struct usbd_descriptors single_desc[]
    = {{single_desc_bytes, single_desc_bytes + sizeof(single_desc_bytes)}
#if CONF_USBD_HS_SP
       ,
       {single_desc_bytes_hs, single_desc_bytes_hs + sizeof(single_desc_bytes_hs)}
#endif
};

/* Ctrl endpoint buffer */
static uint8_t ctrl_buffer[64];

#if CONF_USB_MSC_LUN_DEMO

/**
 * \brief Eject Disk
 * \param[in] lun logic unit number
 * \return Operation status.
 */
static int32_t msc_disk_eject(uint8_t lun)
{
	if (lun > CONF_USB_MSC_MAX_LUN) {
		return ERR_NOT_FOUND;
	}
	return ERR_NONE;
}

/**
 * \brief Inquiry whether Disk is ready
 * \param[in] lun logic unit number
 * \return Operation status.
 */
static int32_t msc_disk_is_ready(uint8_t lun)
{
	if (lun > CONF_USB_MSC_MAX_LUN) {
		return ERR_NOT_FOUND;
	}
	return ERR_NONE;
}

/**
 * \brief Callback invoked when a new read blocks command received
 * \param[in] lun logic unit number
 * \param[in] addr start address of disk to be read
 * \param[in] nblocks block amount to be read
 * \return Operation status.
 */
static int32_t msc_new_read(uint8_t lun, uint32_t addr, uint32_t nblocks)
{
	int32_t  rc  = msc_disk_is_ready(lun);
	uint32_t lba = 0;
	if (rc != ERR_NONE) {
		return rc;
	}
	lba = (format_capa[lun][0] << 24) + (format_capa[lun][1] << 16) + (format_capa[lun][2] << 8) + format_capa[lun][3];
	if (addr > lba || addr + nblocks > lba + 1) {
		return ERR_BAD_ADDRESS;
	}
	msc_lun  = lun;
	xfer_dir = true;

	disk_addr  = addr;
	usb_remain = nblocks;

	return ERR_NONE;
}

/**
 * \brief Callback invoked when a new write blocks command received
 * \param[in] lun logic unit number
 * \param[in] addr start address of disk to be written
 * \param[in] nblocks block amount to be written
 * \return Operation status.
 */
static int32_t msc_new_write(uint8_t lun, uint32_t addr, uint32_t nblocks)
{
	int32_t  rc  = msc_disk_is_ready(lun);
	uint32_t lba = 0;
	if (rc != ERR_NONE) {
		return rc;
	}
	lba = (format_capa[lun][0] << 24) + (format_capa[lun][1] << 16) + (format_capa[lun][2] << 8) + format_capa[lun][3];
	if (addr > lba || addr + nblocks > lba + 1) {
		return ERR_BAD_ADDRESS;
	}
	msc_lun  = lun;
	xfer_dir = false;

	disk_addr  = addr;
	usb_remain = nblocks;

	return ERR_NONE;
}

/**
 * \brief Callback invoked when a blocks transfer is done
 * \param[in] lun logic unit number
 * \return Operation status.
 */
static int32_t msc_xfer_done(uint8_t lun)
{
	if (lun > CONF_USB_MSC_MAX_LUN) {
		return ERR_DENIED;
	}
	usb_busy = false;
	if (LUN_RAM == msc_lun) {
		usb_remain = 0;
		if (!xfer_dir) {
			/* Terminate write */
			mscdf_xfer_blocks(false, NULL, 0);
		}
		return ERR_NONE;
	}
	return ERR_NONE;
} /**
   * \brief Disk loop
   */
static void msc_disk_task(void)
{
	/* RAM Disk transfer directly between RAM and USB */
}

/**
 * \brief USB loop
 */
static void msc_usb_task(void)
{
	if (false == usb_busy && 0 != usb_remain) {
		if (0 == xfer_dir) {
			/* RAM Disk directly exchange data with USB */
			if (msc_lun == LUN_RAM) {
				usb_busy = true;
				mscdf_xfer_blocks(false, &ram_disk_buf[disk_addr << 9], usb_remain);
				return;
			}
		} else {
			/* RAM Disk directly exchange data with USB */
			if (msc_lun == LUN_RAM) {
				usb_busy = true;
				mscdf_xfer_blocks(true, &ram_disk_buf[disk_addr << 9], usb_remain);
				return;
			}
		}
	}
}

/**
 * \brief Callback invoked when inquiry data command received
 * \param[in] lun logic unit number
 * \return Operation status.
 */
static uint8_t *msc_inquiry_info(uint8_t lun)
{
	if (lun > CONF_USB_MSC_MAX_LUN) {
		return NULL;
	} else {
		usb_busy   = false;
		usb_remain = 0;
		return &inquiry_info[lun][0];
	}
}

/**
 * \brief Callback invoked when read format capacities command received
 * \param[in] lun logic unit number
 * \return Operation status.
 */
static uint8_t *msc_get_capacity(uint8_t lun)
{
	if (lun > CONF_USB_MSC_MAX_LUN) {
		return NULL;
	} else {
		return &format_capa[lun][0];
	}
}

void mscdf_demo_init(uint8_t *ramd_buf, uint8_t *usbdisk_buf)
{
	ram_disk_buf = ramd_buf;
	mscdf_register_callback(MSCDF_CB_INQUIRY_DISK, (FUNC_PTR)msc_inquiry_info);
	mscdf_register_callback(MSCDF_CB_GET_DISK_CAPACITY, (FUNC_PTR)msc_get_capacity);
	mscdf_register_callback(MSCDF_CB_START_READ_DISK, (FUNC_PTR)msc_new_read);
	mscdf_register_callback(MSCDF_CB_START_WRITE_DISK, (FUNC_PTR)msc_new_write);
	mscdf_register_callback(MSCDF_CB_EJECT_DISK, (FUNC_PTR)msc_disk_eject);
	mscdf_register_callback(MSCDF_CB_TEST_DISK_READY, (FUNC_PTR)msc_disk_is_ready);
	mscdf_register_callback(MSCDF_CB_XFER_BLOCKS_DONE, (FUNC_PTR)msc_xfer_done);
}

void mscdf_demo_task(void)
{
	msc_disk_task();
	msc_usb_task();
}

#endif

/**
 * \brief USB MSC Init
 */
void usbd_msc_init(void)
{
	/* usb stack init */
	usbdc_init(ctrl_buffer);

	/* usbdc_register_funcion inside */
	mscdf_init(CONF_USB_MSC_MAX_LUN);
}

/**
 * \brief Example of using MSC Function.
 * \param[in] ramd_buf Pointer to the memory block for RAM Disk. Size of the
 *            disk is defined by \ref CONF_USB_MSC_LUN0_CAPACITY in KB.
 * \param[in] usbdisk_buf Pointer to the buffer for disk read/write,
 *            e.g., during reading from SD/MMC, data is read to the buffer and
 *            then sent to host from the buffer. Size of the buffer is defined
 *            by \ref CONF_USB_MSC_LUN_BUF_SECTORS in number of sectors.
 * \note
 * In this example, we will use a PC as a USB host:
 * - Connect the DEBUG USB on XPLAINED board to PC for program download.
 * - Connect the TARGET USB on XPLAINED board to PC for running program.
 * The application will behave as a massive storage device which can be
 * recognized by PC. Only one logic unit is supported in this example.
 */
void usbd_msc_example(uint8_t *ramd_buf, uint8_t *usbdisk_buf)
{

#if CONF_USB_MSC_LUN_DEMO
	mscdf_demo_init(ramd_buf, usbdisk_buf);
#endif

	usbdc_start(single_desc);
	usbdc_attach();

	while (!mscdf_is_enabled()) {
		/* wait massive storage to be installed */
	};

	while (1) {

#if CONF_USB_MSC_LUN_DEMO
		mscdf_demo_task();
#endif
	}
}

void usb_init(void)
{

	usbd_msc_init();
}
