/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 */
#ifndef USB_DEVICE_MAIN_H
#define USB_DEVICE_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "mscdf.h"
#include "mscdf_desc.h"

void usbd_msc_init(void);
void usbd_msc_example(uint8_t *ramd_buf, uint8_t *usbdisk_buf);

/**
 * \brief Initialize MSC for LUN accessing that is called before usbdc_start()
 * \param[in] ramd_buf Pointer to memory for RAM Disk (if RAM Disk demo enabled).
 *                     The size is defined by configuration of \c CONF_USB_MSC_LUN0_CAPACITY.
 * \param[in] usbdisk_buf Pointer to memory/cache for USB and Disk to exchange data (if a non-RAM Disk demo enabled).
 *                        The size is defined by configuration of \c CONF_USB_MSC_LUN_BUF_SECTORS.
 */
void mscdf_demo_init(uint8_t *ramd_buf, uint8_t *usbdisk_buf);
/**
 * \brief Non-blocking task that is invoked in main loop, to process USB and disk tasks
 */
void mscdf_demo_task(void);

/**
 * \berif Initialize USB
 */
void usb_init(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // USB_DEVICE_MAIN_H
