/**
 * \file
 *
 * \brief USB Device Stack MSC Function Definition.
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 */

#ifndef USBDF_MSC_H_
#define USBDF_MSC_H_

#include "usbdc.h"
#include "usb_protocol_msc.h"
#include "spc_protocol.h"
#include "sbc_protocol.h"

/** MSC Class Callback Type */
enum mscdf_cb_type {
	MSCDF_CB_INQUIRY_DISK,
	MSCDF_CB_GET_DISK_CAPACITY,
	MSCDF_CB_START_READ_DISK,
	MSCDF_CB_START_WRITE_DISK,
	MSCDF_CB_EJECT_DISK,
	MSCDF_CB_TEST_DISK_READY,
	MSCDF_CB_XFER_BLOCKS_DONE
};

/** MSC Inquiry Disk Callback. */
typedef uint8_t *(*mscdf_inquiry_disk_t)(uint8_t);

/** MSC Get Disk Capacity Callback. */
typedef uint8_t *(*mscdf_get_disk_capacity_t)(uint8_t);

/** MSC Read Data From Disk Callback. */
typedef int32_t (*mscdf_start_read_disk_t)(uint8_t, uint32_t, uint32_t);

/** MSC Write Data To Disk Callback. */
typedef int32_t (*mscdf_start_write_disk_t)(uint8_t, uint32_t, uint32_t);

/** MSC Eject Disk Callback. */
typedef int32_t (*mscdf_eject_disk_t)(uint8_t);

/** MSC Test Disk Ready Callback. */
typedef int32_t (*mscdf_test_disk_ready_t)(uint8_t);

/** MSC Tansfer Block Done Callback. */
typedef int32_t (*mscdf_xfer_blocks_done_t)(uint8_t);

/**
 * \brief Initialize the USB MSC Function Driver
 * \param[in] max_lun max logic unit support
 * \return Operation status.
 */
int32_t mscdf_init(uint8_t max_lun);

/**
 * \brief Deinitialize the USB MSC Function Driver
 * \return Operation status.
 */
int32_t mscdf_deinit(void);

/**
 * \brief USB MSC Function Register Callback
 * \param[in] cb_type Callback type of MSC Function
 * \param[in] func Pointer to callback function
 * \return Operation status.
 */
int32_t mscdf_register_callback(enum mscdf_cb_type cb_type, FUNC_PTR func);

/**
 * \brief Check whether MSC Function is enabled
 * \return Operation status.
 * \return true MSC Function is enabled
 * \return false MSC Function is disabled
 */
bool mscdf_is_enabled(void);

/**
 * \brief USB MSC multi-blocks data transfer between USB and Memory.
 * \param[in] rd true read disk command, false write disk command.
 * \param[in] blk_addr transfer block address.
 * \param[in] blk_cnt transfer block count. It is regarded as disk
 *            writing done when input blk_cnt as zero.
 * \return Operation status.
 */
int32_t mscdf_xfer_blocks(bool rd, uint8_t *blk_addr, uint32_t blk_cnt);

/**
 * \brief Return version
 */
uint32_t mscdf_get_version(void);

#endif /* USBDF_MSC_H_ */
