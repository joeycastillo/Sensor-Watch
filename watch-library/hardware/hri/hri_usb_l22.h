/**
 * \file
 *
 * \brief SAM USB
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
 *
 */

#ifdef _SAML22_USB_COMPONENT_
#ifndef _HRI_USB_L22_H_INCLUDED_
#define _HRI_USB_L22_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_USB_CRITICAL_SECTIONS)
#define USB_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define USB_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define USB_CRITICAL_SECTION_ENTER()
#define USB_CRITICAL_SECTION_LEAVE()
#endif

typedef uint16_t hri_usb_padcal_reg_t;
typedef uint16_t hri_usbdesc_bank_extreg_reg_t;
typedef uint16_t hri_usbdescriptordevice_extreg_reg_t;
typedef uint16_t hri_usbdevice_ctrlb_reg_t;
typedef uint16_t hri_usbdevice_epintsmry_reg_t;
typedef uint16_t hri_usbdevice_fnum_reg_t;
typedef uint16_t hri_usbdevice_intenset_reg_t;
typedef uint16_t hri_usbdevice_intflag_reg_t;
typedef uint32_t hri_usb_descadd_reg_t;
typedef uint32_t hri_usbdesc_bank_addr_reg_t;
typedef uint32_t hri_usbdesc_bank_pcksize_reg_t;
typedef uint32_t hri_usbdescriptordevice_addr_reg_t;
typedef uint32_t hri_usbdescriptordevice_pcksize_reg_t;
typedef uint8_t  hri_usb_ctrla_reg_t;
typedef uint8_t  hri_usb_fsmstatus_reg_t;
typedef uint8_t  hri_usb_qosctrl_reg_t;
typedef uint8_t  hri_usb_syncbusy_reg_t;
typedef uint8_t  hri_usbdesc_bank_status_bk_reg_t;
typedef uint8_t  hri_usbdescriptordevice_status_bk_reg_t;
typedef uint8_t  hri_usbdevice_dadd_reg_t;
typedef uint8_t  hri_usbdevice_epcfg_reg_t;
typedef uint8_t  hri_usbdevice_epintenset_reg_t;
typedef uint8_t  hri_usbdevice_epintflag_reg_t;
typedef uint8_t  hri_usbdevice_epstatus_reg_t;
typedef uint8_t  hri_usbdevice_status_reg_t;
typedef uint8_t  hri_usbendpoint_epcfg_reg_t;
typedef uint8_t  hri_usbendpoint_epintenset_reg_t;
typedef uint8_t  hri_usbendpoint_epintflag_reg_t;
typedef uint8_t  hri_usbendpoint_epstatus_reg_t;

static inline void hri_usb_wait_for_sync(const void *const hw, hri_usb_syncbusy_reg_t reg)
{
	while (((Usb *)hw)->DEVICE.SYNCBUSY.reg & reg) {
	};
}

static inline bool hri_usb_is_syncing(const void *const hw, hri_usb_syncbusy_reg_t reg)
{
	return ((Usb *)hw)->DEVICE.SYNCBUSY.reg & reg;
}

static inline bool hri_usbendpoint_get_EPINTFLAG_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRCPT0)
	       >> USB_DEVICE_EPINTFLAG_TRCPT0_Pos;
}

static inline void hri_usbendpoint_clear_EPINTFLAG_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRCPT0;
}

static inline bool hri_usbendpoint_get_EPINTFLAG_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRCPT1)
	       >> USB_DEVICE_EPINTFLAG_TRCPT1_Pos;
}

static inline void hri_usbendpoint_clear_EPINTFLAG_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRCPT1;
}

static inline bool hri_usbendpoint_get_EPINTFLAG_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRFAIL0)
	       >> USB_DEVICE_EPINTFLAG_TRFAIL0_Pos;
}

static inline void hri_usbendpoint_clear_EPINTFLAG_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRFAIL0;
}

static inline bool hri_usbendpoint_get_EPINTFLAG_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRFAIL1)
	       >> USB_DEVICE_EPINTFLAG_TRFAIL1_Pos;
}

static inline void hri_usbendpoint_clear_EPINTFLAG_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRFAIL1;
}

static inline bool hri_usbendpoint_get_EPINTFLAG_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_RXSTP)
	       >> USB_DEVICE_EPINTFLAG_RXSTP_Pos;
}

static inline void hri_usbendpoint_clear_EPINTFLAG_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_RXSTP;
}

static inline bool hri_usbendpoint_get_EPINTFLAG_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_STALL0)
	       >> USB_DEVICE_EPINTFLAG_STALL0_Pos;
}

static inline void hri_usbendpoint_clear_EPINTFLAG_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_STALL0;
}

static inline bool hri_usbendpoint_get_EPINTFLAG_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_STALL1)
	       >> USB_DEVICE_EPINTFLAG_STALL1_Pos;
}

static inline void hri_usbendpoint_clear_EPINTFLAG_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_STALL1;
}

static inline bool hri_usbendpoint_get_interrupt_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRCPT0)
	       >> USB_DEVICE_EPINTFLAG_TRCPT0_Pos;
}

static inline void hri_usbendpoint_clear_interrupt_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRCPT0;
}

static inline bool hri_usbendpoint_get_interrupt_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRCPT1)
	       >> USB_DEVICE_EPINTFLAG_TRCPT1_Pos;
}

static inline void hri_usbendpoint_clear_interrupt_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRCPT1;
}

static inline bool hri_usbendpoint_get_interrupt_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRFAIL0)
	       >> USB_DEVICE_EPINTFLAG_TRFAIL0_Pos;
}

static inline void hri_usbendpoint_clear_interrupt_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRFAIL0;
}

static inline bool hri_usbendpoint_get_interrupt_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRFAIL1)
	       >> USB_DEVICE_EPINTFLAG_TRFAIL1_Pos;
}

static inline void hri_usbendpoint_clear_interrupt_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRFAIL1;
}

static inline bool hri_usbendpoint_get_interrupt_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_RXSTP)
	       >> USB_DEVICE_EPINTFLAG_RXSTP_Pos;
}

static inline void hri_usbendpoint_clear_interrupt_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_RXSTP;
}

static inline bool hri_usbendpoint_get_interrupt_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_STALL0)
	       >> USB_DEVICE_EPINTFLAG_STALL0_Pos;
}

static inline void hri_usbendpoint_clear_interrupt_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_STALL0;
}

static inline bool hri_usbendpoint_get_interrupt_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_STALL1)
	       >> USB_DEVICE_EPINTFLAG_STALL1_Pos;
}

static inline void hri_usbendpoint_clear_interrupt_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_STALL1;
}

static inline hri_usbendpoint_epintflag_reg_t
hri_usbendpoint_get_EPINTFLAG_reg(const void *const hw, uint8_t submodule_index, hri_usbendpoint_epintflag_reg_t mask)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbendpoint_epintflag_reg_t hri_usbendpoint_read_EPINTFLAG_reg(const void *const hw,
                                                                                 uint8_t           submodule_index)
{
	return ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg;
}

static inline void hri_usbendpoint_clear_EPINTFLAG_reg(const void *const hw, uint8_t submodule_index,
                                                       hri_usbendpoint_epintflag_reg_t mask)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTFLAG.reg = mask;
}

static inline void hri_usbendpoint_set_EPSTATUS_DTGLOUT_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_DTGLOUT;
}

static inline bool hri_usbendpoint_get_EPSTATUS_DTGLOUT_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_DTGLOUT)
	       >> USB_DEVICE_EPSTATUS_DTGLOUT_Pos;
}

static inline void hri_usbendpoint_write_EPSTATUS_DTGLOUT_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_DTGLOUT;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_DTGLOUT;
	}
}

static inline void hri_usbendpoint_clear_EPSTATUS_DTGLOUT_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_DTGLOUT;
}

static inline void hri_usbendpoint_set_EPSTATUS_DTGLIN_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_DTGLIN;
}

static inline bool hri_usbendpoint_get_EPSTATUS_DTGLIN_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_DTGLIN)
	       >> USB_DEVICE_EPSTATUS_DTGLIN_Pos;
}

static inline void hri_usbendpoint_write_EPSTATUS_DTGLIN_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_DTGLIN;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_DTGLIN;
	}
}

static inline void hri_usbendpoint_clear_EPSTATUS_DTGLIN_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_DTGLIN;
}

static inline void hri_usbendpoint_set_EPSTATUS_CURBK_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_CURBK;
}

static inline bool hri_usbendpoint_get_EPSTATUS_CURBK_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_CURBK)
	       >> USB_DEVICE_EPSTATUS_CURBK_Pos;
}

static inline void hri_usbendpoint_write_EPSTATUS_CURBK_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_CURBK;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_CURBK;
	}
}

static inline void hri_usbendpoint_clear_EPSTATUS_CURBK_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_CURBK;
}

static inline void hri_usbendpoint_set_EPSTATUS_STALLRQ0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_STALLRQ0;
}

static inline bool hri_usbendpoint_get_EPSTATUS_STALLRQ0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_STALLRQ0)
	       >> USB_DEVICE_EPSTATUS_STALLRQ0_Pos;
}

static inline void hri_usbendpoint_write_EPSTATUS_STALLRQ0_bit(const void *const hw, uint8_t submodule_index,
                                                               bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_STALLRQ0;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_STALLRQ0;
	}
}

static inline void hri_usbendpoint_clear_EPSTATUS_STALLRQ0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_STALLRQ0;
}

static inline void hri_usbendpoint_set_EPSTATUS_STALLRQ1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_STALLRQ1;
}

static inline bool hri_usbendpoint_get_EPSTATUS_STALLRQ1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_STALLRQ1)
	       >> USB_DEVICE_EPSTATUS_STALLRQ1_Pos;
}

static inline void hri_usbendpoint_write_EPSTATUS_STALLRQ1_bit(const void *const hw, uint8_t submodule_index,
                                                               bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_STALLRQ1;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_STALLRQ1;
	}
}

static inline void hri_usbendpoint_clear_EPSTATUS_STALLRQ1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_STALLRQ1;
}

static inline void hri_usbendpoint_set_EPSTATUS_BK0RDY_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_BK0RDY;
}

static inline bool hri_usbendpoint_get_EPSTATUS_BK0RDY_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_BK0RDY)
	       >> USB_DEVICE_EPSTATUS_BK0RDY_Pos;
}

static inline void hri_usbendpoint_write_EPSTATUS_BK0RDY_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_BK0RDY;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_BK0RDY;
	}
}

static inline void hri_usbendpoint_clear_EPSTATUS_BK0RDY_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_BK0RDY;
}

static inline void hri_usbendpoint_set_EPSTATUS_BK1RDY_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_BK1RDY;
}

static inline bool hri_usbendpoint_get_EPSTATUS_BK1RDY_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_BK1RDY)
	       >> USB_DEVICE_EPSTATUS_BK1RDY_Pos;
}

static inline void hri_usbendpoint_write_EPSTATUS_BK1RDY_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_BK1RDY;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_BK1RDY;
	}
}

static inline void hri_usbendpoint_clear_EPSTATUS_BK1RDY_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_BK1RDY;
}

static inline void hri_usbendpoint_set_EPSTATUS_reg(const void *const hw, uint8_t submodule_index,
                                                    hri_usbendpoint_epstatus_reg_t mask)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = mask;
}

static inline hri_usbendpoint_epstatus_reg_t
hri_usbendpoint_get_EPSTATUS_reg(const void *const hw, uint8_t submodule_index, hri_usbendpoint_epstatus_reg_t mask)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbendpoint_epstatus_reg_t hri_usbendpoint_read_EPSTATUS_reg(const void *const hw,
                                                                               uint8_t           submodule_index)
{
	return ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUS.reg;
}

static inline void hri_usbendpoint_write_EPSTATUS_reg(const void *const hw, uint8_t submodule_index,
                                                      hri_usbendpoint_epstatus_reg_t data)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSSET.reg = data;
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = ~data;
}

static inline void hri_usbendpoint_clear_EPSTATUS_reg(const void *const hw, uint8_t submodule_index,
                                                      hri_usbendpoint_epstatus_reg_t mask)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = mask;
}

static inline void hri_usbendpoint_set_EPINTEN_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRCPT0;
}

static inline bool hri_usbendpoint_get_EPINTEN_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_TRCPT0)
	       >> USB_DEVICE_EPINTENSET_TRCPT0_Pos;
}

static inline void hri_usbendpoint_write_EPINTEN_TRCPT0_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRCPT0;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRCPT0;
	}
}

static inline void hri_usbendpoint_clear_EPINTEN_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRCPT0;
}

static inline void hri_usbendpoint_set_EPINTEN_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRCPT1;
}

static inline bool hri_usbendpoint_get_EPINTEN_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_TRCPT1)
	       >> USB_DEVICE_EPINTENSET_TRCPT1_Pos;
}

static inline void hri_usbendpoint_write_EPINTEN_TRCPT1_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRCPT1;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRCPT1;
	}
}

static inline void hri_usbendpoint_clear_EPINTEN_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRCPT1;
}

static inline void hri_usbendpoint_set_EPINTEN_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRFAIL0;
}

static inline bool hri_usbendpoint_get_EPINTEN_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_TRFAIL0)
	       >> USB_DEVICE_EPINTENSET_TRFAIL0_Pos;
}

static inline void hri_usbendpoint_write_EPINTEN_TRFAIL0_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRFAIL0;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRFAIL0;
	}
}

static inline void hri_usbendpoint_clear_EPINTEN_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRFAIL0;
}

static inline void hri_usbendpoint_set_EPINTEN_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRFAIL1;
}

static inline bool hri_usbendpoint_get_EPINTEN_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_TRFAIL1)
	       >> USB_DEVICE_EPINTENSET_TRFAIL1_Pos;
}

static inline void hri_usbendpoint_write_EPINTEN_TRFAIL1_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRFAIL1;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRFAIL1;
	}
}

static inline void hri_usbendpoint_clear_EPINTEN_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRFAIL1;
}

static inline void hri_usbendpoint_set_EPINTEN_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_RXSTP;
}

static inline bool hri_usbendpoint_get_EPINTEN_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_RXSTP)
	       >> USB_DEVICE_EPINTENSET_RXSTP_Pos;
}

static inline void hri_usbendpoint_write_EPINTEN_RXSTP_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_RXSTP;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_RXSTP;
	}
}

static inline void hri_usbendpoint_clear_EPINTEN_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_RXSTP;
}

static inline void hri_usbendpoint_set_EPINTEN_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_STALL0;
}

static inline bool hri_usbendpoint_get_EPINTEN_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_STALL0)
	       >> USB_DEVICE_EPINTENSET_STALL0_Pos;
}

static inline void hri_usbendpoint_write_EPINTEN_STALL0_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_STALL0;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_STALL0;
	}
}

static inline void hri_usbendpoint_clear_EPINTEN_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_STALL0;
}

static inline void hri_usbendpoint_set_EPINTEN_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_STALL1;
}

static inline bool hri_usbendpoint_get_EPINTEN_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_STALL1)
	       >> USB_DEVICE_EPINTENSET_STALL1_Pos;
}

static inline void hri_usbendpoint_write_EPINTEN_STALL1_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_STALL1;
	} else {
		((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_STALL1;
	}
}

static inline void hri_usbendpoint_clear_EPINTEN_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_STALL1;
}

static inline void hri_usbendpoint_set_EPINTEN_reg(const void *const hw, uint8_t submodule_index,
                                                   hri_usbendpoint_epintenset_reg_t mask)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = mask;
}

static inline hri_usbendpoint_epintenset_reg_t
hri_usbendpoint_get_EPINTEN_reg(const void *const hw, uint8_t submodule_index, hri_usbendpoint_epintenset_reg_t mask)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbendpoint_epintenset_reg_t hri_usbendpoint_read_EPINTEN_reg(const void *const hw,
                                                                                uint8_t           submodule_index)
{
	return ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg;
}

static inline void hri_usbendpoint_write_EPINTEN_reg(const void *const hw, uint8_t submodule_index,
                                                     hri_usbendpoint_epintenset_reg_t data)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENSET.reg = data;
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = ~data;
}

static inline void hri_usbendpoint_clear_EPINTEN_reg(const void *const hw, uint8_t submodule_index,
                                                     hri_usbendpoint_epintenset_reg_t mask)
{
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPINTENCLR.reg = mask;
}

static inline void hri_usbendpoint_set_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg |= USB_DEVICE_EPCFG_NYETDIS;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbendpoint_get_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_NYETDIS) >> USB_DEVICE_EPCFG_NYETDIS_Pos;
	return (bool)tmp;
}

static inline void hri_usbendpoint_write_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp &= ~USB_DEVICE_EPCFG_NYETDIS;
	tmp |= value << USB_DEVICE_EPCFG_NYETDIS_Pos;
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_clear_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg &= ~USB_DEVICE_EPCFG_NYETDIS;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_toggle_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg ^= USB_DEVICE_EPCFG_NYETDIS;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_set_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index,
                                                        hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg |= USB_DEVICE_EPCFG_EPTYPE0(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbendpoint_epcfg_reg_t
hri_usbendpoint_get_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index, hri_usbendpoint_epcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_EPTYPE0(mask)) >> USB_DEVICE_EPCFG_EPTYPE0_Pos;
	return tmp;
}

static inline void hri_usbendpoint_write_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index,
                                                          hri_usbendpoint_epcfg_reg_t data)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp &= ~USB_DEVICE_EPCFG_EPTYPE0_Msk;
	tmp |= USB_DEVICE_EPCFG_EPTYPE0(data);
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_clear_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index,
                                                          hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg &= ~USB_DEVICE_EPCFG_EPTYPE0(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_toggle_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index,
                                                           hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg ^= USB_DEVICE_EPCFG_EPTYPE0(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbendpoint_epcfg_reg_t hri_usbendpoint_read_EPCFG_EPTYPE0_bf(const void *const hw,
                                                                                uint8_t           submodule_index)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_EPTYPE0_Msk) >> USB_DEVICE_EPCFG_EPTYPE0_Pos;
	return tmp;
}

static inline void hri_usbendpoint_set_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index,
                                                        hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg |= USB_DEVICE_EPCFG_EPTYPE1(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbendpoint_epcfg_reg_t
hri_usbendpoint_get_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index, hri_usbendpoint_epcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_EPTYPE1(mask)) >> USB_DEVICE_EPCFG_EPTYPE1_Pos;
	return tmp;
}

static inline void hri_usbendpoint_write_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index,
                                                          hri_usbendpoint_epcfg_reg_t data)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp &= ~USB_DEVICE_EPCFG_EPTYPE1_Msk;
	tmp |= USB_DEVICE_EPCFG_EPTYPE1(data);
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_clear_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index,
                                                          hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg &= ~USB_DEVICE_EPCFG_EPTYPE1(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_toggle_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index,
                                                           hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg ^= USB_DEVICE_EPCFG_EPTYPE1(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbendpoint_epcfg_reg_t hri_usbendpoint_read_EPCFG_EPTYPE1_bf(const void *const hw,
                                                                                uint8_t           submodule_index)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_EPTYPE1_Msk) >> USB_DEVICE_EPCFG_EPTYPE1_Pos;
	return tmp;
}

static inline void hri_usbendpoint_set_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                 hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbendpoint_epcfg_reg_t hri_usbendpoint_get_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                                        hri_usbendpoint_epcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbendpoint_write_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                   hri_usbendpoint_epcfg_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_clear_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                   hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbendpoint_toggle_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                    hri_usbendpoint_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbendpoint_epcfg_reg_t hri_usbendpoint_read_EPCFG_reg(const void *const hw, uint8_t submodule_index)
{
	return ((UsbDevice *)hw)->DeviceEndpoint[submodule_index].EPCFG.reg;
}

static inline bool hri_usbdevice_get_EPINTFLAG_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRCPT0)
	       >> USB_DEVICE_EPINTFLAG_TRCPT0_Pos;
}

static inline void hri_usbdevice_clear_EPINTFLAG_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRCPT0;
}

static inline bool hri_usbdevice_get_EPINTFLAG_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRCPT1)
	       >> USB_DEVICE_EPINTFLAG_TRCPT1_Pos;
}

static inline void hri_usbdevice_clear_EPINTFLAG_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRCPT1;
}

static inline bool hri_usbdevice_get_EPINTFLAG_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRFAIL0)
	       >> USB_DEVICE_EPINTFLAG_TRFAIL0_Pos;
}

static inline void hri_usbdevice_clear_EPINTFLAG_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRFAIL0;
}

static inline bool hri_usbdevice_get_EPINTFLAG_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRFAIL1)
	       >> USB_DEVICE_EPINTFLAG_TRFAIL1_Pos;
}

static inline void hri_usbdevice_clear_EPINTFLAG_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRFAIL1;
}

static inline bool hri_usbdevice_get_EPINTFLAG_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_RXSTP)
	       >> USB_DEVICE_EPINTFLAG_RXSTP_Pos;
}

static inline void hri_usbdevice_clear_EPINTFLAG_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_RXSTP;
}

static inline bool hri_usbdevice_get_EPINTFLAG_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_STALL0)
	       >> USB_DEVICE_EPINTFLAG_STALL0_Pos;
}

static inline void hri_usbdevice_clear_EPINTFLAG_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_STALL0;
}

static inline bool hri_usbdevice_get_EPINTFLAG_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_STALL1)
	       >> USB_DEVICE_EPINTFLAG_STALL1_Pos;
}

static inline void hri_usbdevice_clear_EPINTFLAG_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_STALL1;
}

static inline bool hri_usbdevice_get_interrupt_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRCPT0)
	       >> USB_DEVICE_EPINTFLAG_TRCPT0_Pos;
}

static inline void hri_usbdevice_clear_interrupt_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRCPT0;
}

static inline bool hri_usbdevice_get_interrupt_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRCPT1)
	       >> USB_DEVICE_EPINTFLAG_TRCPT1_Pos;
}

static inline void hri_usbdevice_clear_interrupt_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRCPT1;
}

static inline bool hri_usbdevice_get_interrupt_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRFAIL0)
	       >> USB_DEVICE_EPINTFLAG_TRFAIL0_Pos;
}

static inline void hri_usbdevice_clear_interrupt_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRFAIL0;
}

static inline bool hri_usbdevice_get_interrupt_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_TRFAIL1)
	       >> USB_DEVICE_EPINTFLAG_TRFAIL1_Pos;
}

static inline void hri_usbdevice_clear_interrupt_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_TRFAIL1;
}

static inline bool hri_usbdevice_get_interrupt_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_RXSTP)
	       >> USB_DEVICE_EPINTFLAG_RXSTP_Pos;
}

static inline void hri_usbdevice_clear_interrupt_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_RXSTP;
}

static inline bool hri_usbdevice_get_interrupt_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_STALL0)
	       >> USB_DEVICE_EPINTFLAG_STALL0_Pos;
}

static inline void hri_usbdevice_clear_interrupt_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_STALL0;
}

static inline bool hri_usbdevice_get_interrupt_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg & USB_DEVICE_EPINTFLAG_STALL1)
	       >> USB_DEVICE_EPINTFLAG_STALL1_Pos;
}

static inline void hri_usbdevice_clear_interrupt_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = USB_DEVICE_EPINTFLAG_STALL1;
}

static inline hri_usbdevice_epintflag_reg_t
hri_usbdevice_get_EPINTFLAG_reg(const void *const hw, uint8_t submodule_index, hri_usbdevice_epintflag_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbdevice_epintflag_reg_t hri_usbdevice_read_EPINTFLAG_reg(const void *const hw,
                                                                             uint8_t           submodule_index)
{
	return ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg;
}

static inline void hri_usbdevice_clear_EPINTFLAG_reg(const void *const hw, uint8_t submodule_index,
                                                     hri_usbdevice_epintflag_reg_t mask)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTFLAG.reg = mask;
}

static inline void hri_usbdevice_set_EPSTATUS_DTGLOUT_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_DTGLOUT;
}

static inline bool hri_usbdevice_get_EPSTATUS_DTGLOUT_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_DTGLOUT)
	       >> USB_DEVICE_EPSTATUS_DTGLOUT_Pos;
}

static inline void hri_usbdevice_write_EPSTATUS_DTGLOUT_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_DTGLOUT;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_DTGLOUT;
	}
}

static inline void hri_usbdevice_clear_EPSTATUS_DTGLOUT_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_DTGLOUT;
}

static inline void hri_usbdevice_set_EPSTATUS_DTGLIN_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_DTGLIN;
}

static inline bool hri_usbdevice_get_EPSTATUS_DTGLIN_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_DTGLIN)
	       >> USB_DEVICE_EPSTATUS_DTGLIN_Pos;
}

static inline void hri_usbdevice_write_EPSTATUS_DTGLIN_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_DTGLIN;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_DTGLIN;
	}
}

static inline void hri_usbdevice_clear_EPSTATUS_DTGLIN_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_DTGLIN;
}

static inline void hri_usbdevice_set_EPSTATUS_CURBK_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_CURBK;
}

static inline bool hri_usbdevice_get_EPSTATUS_CURBK_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_CURBK)
	       >> USB_DEVICE_EPSTATUS_CURBK_Pos;
}

static inline void hri_usbdevice_write_EPSTATUS_CURBK_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_CURBK;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_CURBK;
	}
}

static inline void hri_usbdevice_clear_EPSTATUS_CURBK_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_CURBK;
}

static inline void hri_usbdevice_set_EPSTATUS_STALLRQ0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_STALLRQ0;
}

static inline bool hri_usbdevice_get_EPSTATUS_STALLRQ0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_STALLRQ0)
	       >> USB_DEVICE_EPSTATUS_STALLRQ0_Pos;
}

static inline void hri_usbdevice_write_EPSTATUS_STALLRQ0_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_STALLRQ0;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_STALLRQ0;
	}
}

static inline void hri_usbdevice_clear_EPSTATUS_STALLRQ0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_STALLRQ0;
}

static inline void hri_usbdevice_set_EPSTATUS_STALLRQ1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_STALLRQ1;
}

static inline bool hri_usbdevice_get_EPSTATUS_STALLRQ1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_STALLRQ1)
	       >> USB_DEVICE_EPSTATUS_STALLRQ1_Pos;
}

static inline void hri_usbdevice_write_EPSTATUS_STALLRQ1_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_STALLRQ1;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_STALLRQ1;
	}
}

static inline void hri_usbdevice_clear_EPSTATUS_STALLRQ1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_STALLRQ1;
}

static inline void hri_usbdevice_set_EPSTATUS_BK0RDY_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_BK0RDY;
}

static inline bool hri_usbdevice_get_EPSTATUS_BK0RDY_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_BK0RDY)
	       >> USB_DEVICE_EPSTATUS_BK0RDY_Pos;
}

static inline void hri_usbdevice_write_EPSTATUS_BK0RDY_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_BK0RDY;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_BK0RDY;
	}
}

static inline void hri_usbdevice_clear_EPSTATUS_BK0RDY_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_BK0RDY;
}

static inline void hri_usbdevice_set_EPSTATUS_BK1RDY_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_BK1RDY;
}

static inline bool hri_usbdevice_get_EPSTATUS_BK1RDY_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg & USB_DEVICE_EPSTATUS_BK1RDY)
	       >> USB_DEVICE_EPSTATUS_BK1RDY_Pos;
}

static inline void hri_usbdevice_write_EPSTATUS_BK1RDY_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_BK1RDY;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = USB_DEVICE_EPSTATUS_BK1RDY;
	}
}

static inline void hri_usbdevice_clear_EPSTATUS_BK1RDY_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = USB_DEVICE_EPSTATUS_BK1RDY;
}

static inline void hri_usbdevice_set_EPSTATUS_reg(const void *const hw, uint8_t submodule_index,
                                                  hri_usbdevice_epstatus_reg_t mask)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = mask;
}

static inline hri_usbdevice_epstatus_reg_t hri_usbdevice_get_EPSTATUS_reg(const void *const hw, uint8_t submodule_index,
                                                                          hri_usbdevice_epstatus_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbdevice_epstatus_reg_t hri_usbdevice_read_EPSTATUS_reg(const void *const hw,
                                                                           uint8_t           submodule_index)
{
	return ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUS.reg;
}

static inline void hri_usbdevice_write_EPSTATUS_reg(const void *const hw, uint8_t submodule_index,
                                                    hri_usbdevice_epstatus_reg_t data)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSSET.reg = data;
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = ~data;
}

static inline void hri_usbdevice_clear_EPSTATUS_reg(const void *const hw, uint8_t submodule_index,
                                                    hri_usbdevice_epstatus_reg_t mask)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPSTATUSCLR.reg = mask;
}

static inline void hri_usbdevice_set_EPINTEN_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRCPT0;
}

static inline bool hri_usbdevice_get_EPINTEN_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_TRCPT0)
	       >> USB_DEVICE_EPINTENSET_TRCPT0_Pos;
}

static inline void hri_usbdevice_write_EPINTEN_TRCPT0_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRCPT0;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRCPT0;
	}
}

static inline void hri_usbdevice_clear_EPINTEN_TRCPT0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRCPT0;
}

static inline void hri_usbdevice_set_EPINTEN_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRCPT1;
}

static inline bool hri_usbdevice_get_EPINTEN_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_TRCPT1)
	       >> USB_DEVICE_EPINTENSET_TRCPT1_Pos;
}

static inline void hri_usbdevice_write_EPINTEN_TRCPT1_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRCPT1;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRCPT1;
	}
}

static inline void hri_usbdevice_clear_EPINTEN_TRCPT1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRCPT1;
}

static inline void hri_usbdevice_set_EPINTEN_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRFAIL0;
}

static inline bool hri_usbdevice_get_EPINTEN_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_TRFAIL0)
	       >> USB_DEVICE_EPINTENSET_TRFAIL0_Pos;
}

static inline void hri_usbdevice_write_EPINTEN_TRFAIL0_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRFAIL0;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRFAIL0;
	}
}

static inline void hri_usbdevice_clear_EPINTEN_TRFAIL0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRFAIL0;
}

static inline void hri_usbdevice_set_EPINTEN_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRFAIL1;
}

static inline bool hri_usbdevice_get_EPINTEN_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_TRFAIL1)
	       >> USB_DEVICE_EPINTENSET_TRFAIL1_Pos;
}

static inline void hri_usbdevice_write_EPINTEN_TRFAIL1_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRFAIL1;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_TRFAIL1;
	}
}

static inline void hri_usbdevice_clear_EPINTEN_TRFAIL1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_TRFAIL1;
}

static inline void hri_usbdevice_set_EPINTEN_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_RXSTP;
}

static inline bool hri_usbdevice_get_EPINTEN_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_RXSTP)
	       >> USB_DEVICE_EPINTENSET_RXSTP_Pos;
}

static inline void hri_usbdevice_write_EPINTEN_RXSTP_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_RXSTP;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_RXSTP;
	}
}

static inline void hri_usbdevice_clear_EPINTEN_RXSTP_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_RXSTP;
}

static inline void hri_usbdevice_set_EPINTEN_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_STALL0;
}

static inline bool hri_usbdevice_get_EPINTEN_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_STALL0)
	       >> USB_DEVICE_EPINTENSET_STALL0_Pos;
}

static inline void hri_usbdevice_write_EPINTEN_STALL0_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_STALL0;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_STALL0;
	}
}

static inline void hri_usbdevice_clear_EPINTEN_STALL0_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_STALL0;
}

static inline void hri_usbdevice_set_EPINTEN_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_STALL1;
}

static inline bool hri_usbdevice_get_EPINTEN_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	return (((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg & USB_DEVICE_EPINTENSET_STALL1)
	       >> USB_DEVICE_EPINTENSET_STALL1_Pos;
}

static inline void hri_usbdevice_write_EPINTEN_STALL1_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_STALL1;
	} else {
		((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = USB_DEVICE_EPINTENSET_STALL1;
	}
}

static inline void hri_usbdevice_clear_EPINTEN_STALL1_bit(const void *const hw, uint8_t submodule_index)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = USB_DEVICE_EPINTENSET_STALL1;
}

static inline void hri_usbdevice_set_EPINTEN_reg(const void *const hw, uint8_t submodule_index,
                                                 hri_usbdevice_epintenset_reg_t mask)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = mask;
}

static inline hri_usbdevice_epintenset_reg_t
hri_usbdevice_get_EPINTEN_reg(const void *const hw, uint8_t submodule_index, hri_usbdevice_epintenset_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbdevice_epintenset_reg_t hri_usbdevice_read_EPINTEN_reg(const void *const hw,
                                                                            uint8_t           submodule_index)
{
	return ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg;
}

static inline void hri_usbdevice_write_EPINTEN_reg(const void *const hw, uint8_t submodule_index,
                                                   hri_usbdevice_epintenset_reg_t data)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENSET.reg = data;
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = ~data;
}

static inline void hri_usbdevice_clear_EPINTEN_reg(const void *const hw, uint8_t submodule_index,
                                                   hri_usbdevice_epintenset_reg_t mask)
{
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPINTENCLR.reg = mask;
}

static inline void hri_usbdevice_set_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg |= USB_DEVICE_EPCFG_NYETDIS;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_NYETDIS) >> USB_DEVICE_EPCFG_NYETDIS_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp &= ~USB_DEVICE_EPCFG_NYETDIS;
	tmp |= value << USB_DEVICE_EPCFG_NYETDIS_Pos;
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg &= ~USB_DEVICE_EPCFG_NYETDIS;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_EPCFG_NYETDIS_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg ^= USB_DEVICE_EPCFG_NYETDIS;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index,
                                                      hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg |= USB_DEVICE_EPCFG_EPTYPE0(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_epcfg_reg_t
hri_usbdevice_get_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index, hri_usbdevice_epcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_EPTYPE0(mask)) >> USB_DEVICE_EPCFG_EPTYPE0_Pos;
	return tmp;
}

static inline void hri_usbdevice_write_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index,
                                                        hri_usbdevice_epcfg_reg_t data)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp &= ~USB_DEVICE_EPCFG_EPTYPE0_Msk;
	tmp |= USB_DEVICE_EPCFG_EPTYPE0(data);
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index,
                                                        hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg &= ~USB_DEVICE_EPCFG_EPTYPE0(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_EPCFG_EPTYPE0_bf(const void *const hw, uint8_t submodule_index,
                                                         hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg ^= USB_DEVICE_EPCFG_EPTYPE0(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_epcfg_reg_t hri_usbdevice_read_EPCFG_EPTYPE0_bf(const void *const hw,
                                                                            uint8_t           submodule_index)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_EPTYPE0_Msk) >> USB_DEVICE_EPCFG_EPTYPE0_Pos;
	return tmp;
}

static inline void hri_usbdevice_set_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index,
                                                      hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg |= USB_DEVICE_EPCFG_EPTYPE1(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_epcfg_reg_t
hri_usbdevice_get_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index, hri_usbdevice_epcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_EPTYPE1(mask)) >> USB_DEVICE_EPCFG_EPTYPE1_Pos;
	return tmp;
}

static inline void hri_usbdevice_write_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index,
                                                        hri_usbdevice_epcfg_reg_t data)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp &= ~USB_DEVICE_EPCFG_EPTYPE1_Msk;
	tmp |= USB_DEVICE_EPCFG_EPTYPE1(data);
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index,
                                                        hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg &= ~USB_DEVICE_EPCFG_EPTYPE1(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_EPCFG_EPTYPE1_bf(const void *const hw, uint8_t submodule_index,
                                                         hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg ^= USB_DEVICE_EPCFG_EPTYPE1(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_epcfg_reg_t hri_usbdevice_read_EPCFG_EPTYPE1_bf(const void *const hw,
                                                                            uint8_t           submodule_index)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp = (tmp & USB_DEVICE_EPCFG_EPTYPE1_Msk) >> USB_DEVICE_EPCFG_EPTYPE1_Pos;
	return tmp;
}

static inline void hri_usbdevice_set_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                               hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_epcfg_reg_t hri_usbdevice_get_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                                    hri_usbdevice_epcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdevice_write_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                 hri_usbdevice_epcfg_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                 hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_EPCFG_reg(const void *const hw, uint8_t submodule_index,
                                                  hri_usbdevice_epcfg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_epcfg_reg_t hri_usbdevice_read_EPCFG_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Usb *)hw)->DEVICE.DeviceEndpoint[submodule_index].EPCFG.reg;
}

static inline bool hri_usbdevice_get_INTFLAG_SUSPEND_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_SUSPEND) >> USB_DEVICE_INTFLAG_SUSPEND_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_SUSPEND_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_SUSPEND;
}

static inline bool hri_usbdevice_get_INTFLAG_MSOF_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_MSOF) >> USB_DEVICE_INTFLAG_MSOF_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_MSOF_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_MSOF;
}

static inline bool hri_usbdevice_get_INTFLAG_SOF_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_SOF) >> USB_DEVICE_INTFLAG_SOF_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_SOF_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_SOF;
}

static inline bool hri_usbdevice_get_INTFLAG_EORST_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_EORST) >> USB_DEVICE_INTFLAG_EORST_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_EORST_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_EORST;
}

static inline bool hri_usbdevice_get_INTFLAG_WAKEUP_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_WAKEUP) >> USB_DEVICE_INTFLAG_WAKEUP_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_WAKEUP_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_WAKEUP;
}

static inline bool hri_usbdevice_get_INTFLAG_EORSM_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_EORSM) >> USB_DEVICE_INTFLAG_EORSM_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_EORSM_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_EORSM;
}

static inline bool hri_usbdevice_get_INTFLAG_UPRSM_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_UPRSM) >> USB_DEVICE_INTFLAG_UPRSM_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_UPRSM_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_UPRSM;
}

static inline bool hri_usbdevice_get_INTFLAG_RAMACER_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_RAMACER) >> USB_DEVICE_INTFLAG_RAMACER_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_RAMACER_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_RAMACER;
}

static inline bool hri_usbdevice_get_INTFLAG_LPMNYET_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_LPMNYET) >> USB_DEVICE_INTFLAG_LPMNYET_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_LPMNYET_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_LPMNYET;
}

static inline bool hri_usbdevice_get_INTFLAG_LPMSUSP_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_LPMSUSP) >> USB_DEVICE_INTFLAG_LPMSUSP_Pos;
}

static inline void hri_usbdevice_clear_INTFLAG_LPMSUSP_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_LPMSUSP;
}

static inline bool hri_usbdevice_get_interrupt_SUSPEND_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_SUSPEND) >> USB_DEVICE_INTFLAG_SUSPEND_Pos;
}

static inline void hri_usbdevice_clear_interrupt_SUSPEND_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_SUSPEND;
}

static inline bool hri_usbdevice_get_interrupt_MSOF_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_MSOF) >> USB_DEVICE_INTFLAG_MSOF_Pos;
}

static inline void hri_usbdevice_clear_interrupt_MSOF_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_MSOF;
}

static inline bool hri_usbdevice_get_interrupt_SOF_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_SOF) >> USB_DEVICE_INTFLAG_SOF_Pos;
}

static inline void hri_usbdevice_clear_interrupt_SOF_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_SOF;
}

static inline bool hri_usbdevice_get_interrupt_EORST_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_EORST) >> USB_DEVICE_INTFLAG_EORST_Pos;
}

static inline void hri_usbdevice_clear_interrupt_EORST_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_EORST;
}

static inline bool hri_usbdevice_get_interrupt_WAKEUP_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_WAKEUP) >> USB_DEVICE_INTFLAG_WAKEUP_Pos;
}

static inline void hri_usbdevice_clear_interrupt_WAKEUP_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_WAKEUP;
}

static inline bool hri_usbdevice_get_interrupt_EORSM_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_EORSM) >> USB_DEVICE_INTFLAG_EORSM_Pos;
}

static inline void hri_usbdevice_clear_interrupt_EORSM_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_EORSM;
}

static inline bool hri_usbdevice_get_interrupt_UPRSM_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_UPRSM) >> USB_DEVICE_INTFLAG_UPRSM_Pos;
}

static inline void hri_usbdevice_clear_interrupt_UPRSM_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_UPRSM;
}

static inline bool hri_usbdevice_get_interrupt_RAMACER_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_RAMACER) >> USB_DEVICE_INTFLAG_RAMACER_Pos;
}

static inline void hri_usbdevice_clear_interrupt_RAMACER_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_RAMACER;
}

static inline bool hri_usbdevice_get_interrupt_LPMNYET_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_LPMNYET) >> USB_DEVICE_INTFLAG_LPMNYET_Pos;
}

static inline void hri_usbdevice_clear_interrupt_LPMNYET_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_LPMNYET;
}

static inline bool hri_usbdevice_get_interrupt_LPMSUSP_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTFLAG.reg & USB_DEVICE_INTFLAG_LPMSUSP) >> USB_DEVICE_INTFLAG_LPMSUSP_Pos;
}

static inline void hri_usbdevice_clear_interrupt_LPMSUSP_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = USB_DEVICE_INTFLAG_LPMSUSP;
}

static inline hri_usbdevice_intflag_reg_t hri_usbdevice_get_INTFLAG_reg(const void *const           hw,
                                                                        hri_usbdevice_intflag_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.INTFLAG.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbdevice_intflag_reg_t hri_usbdevice_read_INTFLAG_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.INTFLAG.reg;
}

static inline void hri_usbdevice_clear_INTFLAG_reg(const void *const hw, hri_usbdevice_intflag_reg_t mask)
{
	((Usb *)hw)->DEVICE.INTFLAG.reg = mask;
}

static inline void hri_usbdevice_set_INTEN_SUSPEND_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_SUSPEND;
}

static inline bool hri_usbdevice_get_INTEN_SUSPEND_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_SUSPEND) >> USB_DEVICE_INTENSET_SUSPEND_Pos;
}

static inline void hri_usbdevice_write_INTEN_SUSPEND_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_SUSPEND;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_SUSPEND;
	}
}

static inline void hri_usbdevice_clear_INTEN_SUSPEND_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_SUSPEND;
}

static inline void hri_usbdevice_set_INTEN_MSOF_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_MSOF;
}

static inline bool hri_usbdevice_get_INTEN_MSOF_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_MSOF) >> USB_DEVICE_INTENSET_MSOF_Pos;
}

static inline void hri_usbdevice_write_INTEN_MSOF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_MSOF;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_MSOF;
	}
}

static inline void hri_usbdevice_clear_INTEN_MSOF_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_MSOF;
}

static inline void hri_usbdevice_set_INTEN_SOF_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_SOF;
}

static inline bool hri_usbdevice_get_INTEN_SOF_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_SOF) >> USB_DEVICE_INTENSET_SOF_Pos;
}

static inline void hri_usbdevice_write_INTEN_SOF_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_SOF;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_SOF;
	}
}

static inline void hri_usbdevice_clear_INTEN_SOF_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_SOF;
}

static inline void hri_usbdevice_set_INTEN_EORST_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_EORST;
}

static inline bool hri_usbdevice_get_INTEN_EORST_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_EORST) >> USB_DEVICE_INTENSET_EORST_Pos;
}

static inline void hri_usbdevice_write_INTEN_EORST_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_EORST;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_EORST;
	}
}

static inline void hri_usbdevice_clear_INTEN_EORST_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_EORST;
}

static inline void hri_usbdevice_set_INTEN_WAKEUP_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_WAKEUP;
}

static inline bool hri_usbdevice_get_INTEN_WAKEUP_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_WAKEUP) >> USB_DEVICE_INTENSET_WAKEUP_Pos;
}

static inline void hri_usbdevice_write_INTEN_WAKEUP_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_WAKEUP;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_WAKEUP;
	}
}

static inline void hri_usbdevice_clear_INTEN_WAKEUP_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_WAKEUP;
}

static inline void hri_usbdevice_set_INTEN_EORSM_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_EORSM;
}

static inline bool hri_usbdevice_get_INTEN_EORSM_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_EORSM) >> USB_DEVICE_INTENSET_EORSM_Pos;
}

static inline void hri_usbdevice_write_INTEN_EORSM_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_EORSM;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_EORSM;
	}
}

static inline void hri_usbdevice_clear_INTEN_EORSM_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_EORSM;
}

static inline void hri_usbdevice_set_INTEN_UPRSM_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_UPRSM;
}

static inline bool hri_usbdevice_get_INTEN_UPRSM_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_UPRSM) >> USB_DEVICE_INTENSET_UPRSM_Pos;
}

static inline void hri_usbdevice_write_INTEN_UPRSM_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_UPRSM;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_UPRSM;
	}
}

static inline void hri_usbdevice_clear_INTEN_UPRSM_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_UPRSM;
}

static inline void hri_usbdevice_set_INTEN_RAMACER_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_RAMACER;
}

static inline bool hri_usbdevice_get_INTEN_RAMACER_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_RAMACER) >> USB_DEVICE_INTENSET_RAMACER_Pos;
}

static inline void hri_usbdevice_write_INTEN_RAMACER_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_RAMACER;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_RAMACER;
	}
}

static inline void hri_usbdevice_clear_INTEN_RAMACER_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_RAMACER;
}

static inline void hri_usbdevice_set_INTEN_LPMNYET_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_LPMNYET;
}

static inline bool hri_usbdevice_get_INTEN_LPMNYET_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_LPMNYET) >> USB_DEVICE_INTENSET_LPMNYET_Pos;
}

static inline void hri_usbdevice_write_INTEN_LPMNYET_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_LPMNYET;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_LPMNYET;
	}
}

static inline void hri_usbdevice_clear_INTEN_LPMNYET_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_LPMNYET;
}

static inline void hri_usbdevice_set_INTEN_LPMSUSP_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_LPMSUSP;
}

static inline bool hri_usbdevice_get_INTEN_LPMSUSP_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.INTENSET.reg & USB_DEVICE_INTENSET_LPMSUSP) >> USB_DEVICE_INTENSET_LPMSUSP_Pos;
}

static inline void hri_usbdevice_write_INTEN_LPMSUSP_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_LPMSUSP;
	} else {
		((Usb *)hw)->DEVICE.INTENSET.reg = USB_DEVICE_INTENSET_LPMSUSP;
	}
}

static inline void hri_usbdevice_clear_INTEN_LPMSUSP_bit(const void *const hw)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = USB_DEVICE_INTENSET_LPMSUSP;
}

static inline void hri_usbdevice_set_INTEN_reg(const void *const hw, hri_usbdevice_intenset_reg_t mask)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = mask;
}

static inline hri_usbdevice_intenset_reg_t hri_usbdevice_get_INTEN_reg(const void *const            hw,
                                                                       hri_usbdevice_intenset_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.INTENSET.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbdevice_intenset_reg_t hri_usbdevice_read_INTEN_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.INTENSET.reg;
}

static inline void hri_usbdevice_write_INTEN_reg(const void *const hw, hri_usbdevice_intenset_reg_t data)
{
	((Usb *)hw)->DEVICE.INTENSET.reg = data;
	((Usb *)hw)->DEVICE.INTENCLR.reg = ~data;
}

static inline void hri_usbdevice_clear_INTEN_reg(const void *const hw, hri_usbdevice_intenset_reg_t mask)
{
	((Usb *)hw)->DEVICE.INTENCLR.reg = mask;
}

static inline bool hri_usb_get_SYNCBUSY_SWRST_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.SYNCBUSY.reg & USB_SYNCBUSY_SWRST) >> USB_SYNCBUSY_SWRST_Pos;
}

static inline bool hri_usb_get_SYNCBUSY_ENABLE_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.SYNCBUSY.reg & USB_SYNCBUSY_ENABLE) >> USB_SYNCBUSY_ENABLE_Pos;
}

static inline hri_usb_syncbusy_reg_t hri_usb_get_SYNCBUSY_reg(const void *const hw, hri_usb_syncbusy_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.SYNCBUSY.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usb_syncbusy_reg_t hri_usb_read_SYNCBUSY_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.SYNCBUSY.reg;
}

static inline hri_usbdevice_status_reg_t hri_usbdevice_get_STATUS_SPEED_bf(const void *const          hw,
                                                                           hri_usbdevice_status_reg_t mask)
{
	return (((Usb *)hw)->DEVICE.STATUS.reg & USB_DEVICE_STATUS_SPEED(mask)) >> USB_DEVICE_STATUS_SPEED_Pos;
}

static inline hri_usbdevice_status_reg_t hri_usbdevice_read_STATUS_SPEED_bf(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.STATUS.reg & USB_DEVICE_STATUS_SPEED_Msk) >> USB_DEVICE_STATUS_SPEED_Pos;
}

static inline hri_usbdevice_status_reg_t hri_usbdevice_get_STATUS_LINESTATE_bf(const void *const          hw,
                                                                               hri_usbdevice_status_reg_t mask)
{
	return (((Usb *)hw)->DEVICE.STATUS.reg & USB_DEVICE_STATUS_LINESTATE(mask)) >> USB_DEVICE_STATUS_LINESTATE_Pos;
}

static inline hri_usbdevice_status_reg_t hri_usbdevice_read_STATUS_LINESTATE_bf(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.STATUS.reg & USB_DEVICE_STATUS_LINESTATE_Msk) >> USB_DEVICE_STATUS_LINESTATE_Pos;
}

static inline hri_usbdevice_status_reg_t hri_usbdevice_get_STATUS_reg(const void *const          hw,
                                                                      hri_usbdevice_status_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.STATUS.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbdevice_status_reg_t hri_usbdevice_read_STATUS_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.STATUS.reg;
}

static inline hri_usb_fsmstatus_reg_t hri_usb_get_FSMSTATUS_FSMSTATE_bf(const void *const       hw,
                                                                        hri_usb_fsmstatus_reg_t mask)
{
	return (((Usb *)hw)->DEVICE.FSMSTATUS.reg & USB_FSMSTATUS_FSMSTATE(mask)) >> USB_FSMSTATUS_FSMSTATE_Pos;
}

static inline hri_usb_fsmstatus_reg_t hri_usb_read_FSMSTATUS_FSMSTATE_bf(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.FSMSTATUS.reg & USB_FSMSTATUS_FSMSTATE_Msk) >> USB_FSMSTATUS_FSMSTATE_Pos;
}

static inline hri_usb_fsmstatus_reg_t hri_usb_get_FSMSTATUS_reg(const void *const hw, hri_usb_fsmstatus_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.FSMSTATUS.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usb_fsmstatus_reg_t hri_usb_read_FSMSTATUS_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.FSMSTATUS.reg;
}

static inline bool hri_usbdevice_get_FNUM_FNCERR_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.FNUM.reg & USB_DEVICE_FNUM_FNCERR) >> USB_DEVICE_FNUM_FNCERR_Pos;
}

static inline hri_usbdevice_fnum_reg_t hri_usbdevice_get_FNUM_MFNUM_bf(const void *const        hw,
                                                                       hri_usbdevice_fnum_reg_t mask)
{
	return (((Usb *)hw)->DEVICE.FNUM.reg & USB_DEVICE_FNUM_MFNUM(mask)) >> USB_DEVICE_FNUM_MFNUM_Pos;
}

static inline hri_usbdevice_fnum_reg_t hri_usbdevice_read_FNUM_MFNUM_bf(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.FNUM.reg & USB_DEVICE_FNUM_MFNUM_Msk) >> USB_DEVICE_FNUM_MFNUM_Pos;
}

static inline hri_usbdevice_fnum_reg_t hri_usbdevice_get_FNUM_FNUM_bf(const void *const        hw,
                                                                      hri_usbdevice_fnum_reg_t mask)
{
	return (((Usb *)hw)->DEVICE.FNUM.reg & USB_DEVICE_FNUM_FNUM(mask)) >> USB_DEVICE_FNUM_FNUM_Pos;
}

static inline hri_usbdevice_fnum_reg_t hri_usbdevice_read_FNUM_FNUM_bf(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.FNUM.reg & USB_DEVICE_FNUM_FNUM_Msk) >> USB_DEVICE_FNUM_FNUM_Pos;
}

static inline hri_usbdevice_fnum_reg_t hri_usbdevice_get_FNUM_reg(const void *const hw, hri_usbdevice_fnum_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.FNUM.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbdevice_fnum_reg_t hri_usbdevice_read_FNUM_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.FNUM.reg;
}

static inline bool hri_usbdevice_get_EPINTSMRY_EPINT0_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.EPINTSMRY.reg & USB_DEVICE_EPINTSMRY_EPINT0) >> USB_DEVICE_EPINTSMRY_EPINT0_Pos;
}

static inline bool hri_usbdevice_get_EPINTSMRY_EPINT1_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.EPINTSMRY.reg & USB_DEVICE_EPINTSMRY_EPINT1) >> USB_DEVICE_EPINTSMRY_EPINT1_Pos;
}

static inline bool hri_usbdevice_get_EPINTSMRY_EPINT2_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.EPINTSMRY.reg & USB_DEVICE_EPINTSMRY_EPINT2) >> USB_DEVICE_EPINTSMRY_EPINT2_Pos;
}

static inline bool hri_usbdevice_get_EPINTSMRY_EPINT3_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.EPINTSMRY.reg & USB_DEVICE_EPINTSMRY_EPINT3) >> USB_DEVICE_EPINTSMRY_EPINT3_Pos;
}

static inline bool hri_usbdevice_get_EPINTSMRY_EPINT4_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.EPINTSMRY.reg & USB_DEVICE_EPINTSMRY_EPINT4) >> USB_DEVICE_EPINTSMRY_EPINT4_Pos;
}

static inline bool hri_usbdevice_get_EPINTSMRY_EPINT5_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.EPINTSMRY.reg & USB_DEVICE_EPINTSMRY_EPINT5) >> USB_DEVICE_EPINTSMRY_EPINT5_Pos;
}

static inline bool hri_usbdevice_get_EPINTSMRY_EPINT6_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.EPINTSMRY.reg & USB_DEVICE_EPINTSMRY_EPINT6) >> USB_DEVICE_EPINTSMRY_EPINT6_Pos;
}

static inline bool hri_usbdevice_get_EPINTSMRY_EPINT7_bit(const void *const hw)
{
	return (((Usb *)hw)->DEVICE.EPINTSMRY.reg & USB_DEVICE_EPINTSMRY_EPINT7) >> USB_DEVICE_EPINTSMRY_EPINT7_Pos;
}

static inline hri_usbdevice_epintsmry_reg_t hri_usbdevice_get_EPINTSMRY_reg(const void *const             hw,
                                                                            hri_usbdevice_epintsmry_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.EPINTSMRY.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_usbdevice_epintsmry_reg_t hri_usbdevice_read_EPINTSMRY_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.EPINTSMRY.reg;
}

static inline void hri_usb_set_CTRLA_SWRST_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg |= USB_CTRLA_SWRST;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_SWRST);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usb_get_CTRLA_SWRST_bit(const void *const hw)
{
	uint8_t tmp;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_SWRST);
	tmp = ((Usb *)hw)->DEVICE.CTRLA.reg;
	tmp = (tmp & USB_CTRLA_SWRST) >> USB_CTRLA_SWRST_Pos;
	return (bool)tmp;
}

static inline void hri_usb_set_CTRLA_ENABLE_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg |= USB_CTRLA_ENABLE;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_SWRST | USB_SYNCBUSY_ENABLE);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usb_get_CTRLA_ENABLE_bit(const void *const hw)
{
	uint8_t tmp;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_SWRST | USB_SYNCBUSY_ENABLE);
	tmp = ((Usb *)hw)->DEVICE.CTRLA.reg;
	tmp = (tmp & USB_CTRLA_ENABLE) >> USB_CTRLA_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_usb_write_CTRLA_ENABLE_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLA.reg;
	tmp &= ~USB_CTRLA_ENABLE;
	tmp |= value << USB_CTRLA_ENABLE_Pos;
	((Usb *)hw)->DEVICE.CTRLA.reg = tmp;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_SWRST | USB_SYNCBUSY_ENABLE);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_CTRLA_ENABLE_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg &= ~USB_CTRLA_ENABLE;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_SWRST | USB_SYNCBUSY_ENABLE);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_CTRLA_ENABLE_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg ^= USB_CTRLA_ENABLE;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_SWRST | USB_SYNCBUSY_ENABLE);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_set_CTRLA_RUNSTDBY_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg |= USB_CTRLA_RUNSTDBY;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usb_get_CTRLA_RUNSTDBY_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLA.reg;
	tmp = (tmp & USB_CTRLA_RUNSTDBY) >> USB_CTRLA_RUNSTDBY_Pos;
	return (bool)tmp;
}

static inline void hri_usb_write_CTRLA_RUNSTDBY_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLA.reg;
	tmp &= ~USB_CTRLA_RUNSTDBY;
	tmp |= value << USB_CTRLA_RUNSTDBY_Pos;
	((Usb *)hw)->DEVICE.CTRLA.reg = tmp;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_CTRLA_RUNSTDBY_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg &= ~USB_CTRLA_RUNSTDBY;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_CTRLA_RUNSTDBY_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg ^= USB_CTRLA_RUNSTDBY;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_set_CTRLA_MODE_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg |= USB_CTRLA_MODE;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usb_get_CTRLA_MODE_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLA.reg;
	tmp = (tmp & USB_CTRLA_MODE) >> USB_CTRLA_MODE_Pos;
	return (bool)tmp;
}

static inline void hri_usb_write_CTRLA_MODE_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLA.reg;
	tmp &= ~USB_CTRLA_MODE;
	tmp |= value << USB_CTRLA_MODE_Pos;
	((Usb *)hw)->DEVICE.CTRLA.reg = tmp;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_CTRLA_MODE_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg &= ~USB_CTRLA_MODE;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_CTRLA_MODE_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg ^= USB_CTRLA_MODE;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_set_CTRLA_reg(const void *const hw, hri_usb_ctrla_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg |= mask;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_ctrla_reg_t hri_usb_get_CTRLA_reg(const void *const hw, hri_usb_ctrla_reg_t mask)
{
	uint8_t tmp;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	tmp = ((Usb *)hw)->DEVICE.CTRLA.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usb_write_CTRLA_reg(const void *const hw, hri_usb_ctrla_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg = data;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_CTRLA_reg(const void *const hw, hri_usb_ctrla_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg &= ~mask;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_CTRLA_reg(const void *const hw, hri_usb_ctrla_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLA.reg ^= mask;
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_ctrla_reg_t hri_usb_read_CTRLA_reg(const void *const hw)
{
	hri_usb_wait_for_sync(hw, USB_SYNCBUSY_MASK);
	return ((Usb *)hw)->DEVICE.CTRLA.reg;
}

static inline void hri_usb_set_QOSCTRL_CQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg |= USB_QOSCTRL_CQOS(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_qosctrl_reg_t hri_usb_get_QOSCTRL_CQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.QOSCTRL.reg;
	tmp = (tmp & USB_QOSCTRL_CQOS(mask)) >> USB_QOSCTRL_CQOS_Pos;
	return tmp;
}

static inline void hri_usb_write_QOSCTRL_CQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t data)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.QOSCTRL.reg;
	tmp &= ~USB_QOSCTRL_CQOS_Msk;
	tmp |= USB_QOSCTRL_CQOS(data);
	((Usb *)hw)->DEVICE.QOSCTRL.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_QOSCTRL_CQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg &= ~USB_QOSCTRL_CQOS(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_QOSCTRL_CQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg ^= USB_QOSCTRL_CQOS(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_qosctrl_reg_t hri_usb_read_QOSCTRL_CQOS_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.QOSCTRL.reg;
	tmp = (tmp & USB_QOSCTRL_CQOS_Msk) >> USB_QOSCTRL_CQOS_Pos;
	return tmp;
}

static inline void hri_usb_set_QOSCTRL_DQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg |= USB_QOSCTRL_DQOS(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_qosctrl_reg_t hri_usb_get_QOSCTRL_DQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.QOSCTRL.reg;
	tmp = (tmp & USB_QOSCTRL_DQOS(mask)) >> USB_QOSCTRL_DQOS_Pos;
	return tmp;
}

static inline void hri_usb_write_QOSCTRL_DQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t data)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.QOSCTRL.reg;
	tmp &= ~USB_QOSCTRL_DQOS_Msk;
	tmp |= USB_QOSCTRL_DQOS(data);
	((Usb *)hw)->DEVICE.QOSCTRL.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_QOSCTRL_DQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg &= ~USB_QOSCTRL_DQOS(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_QOSCTRL_DQOS_bf(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg ^= USB_QOSCTRL_DQOS(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_qosctrl_reg_t hri_usb_read_QOSCTRL_DQOS_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.QOSCTRL.reg;
	tmp = (tmp & USB_QOSCTRL_DQOS_Msk) >> USB_QOSCTRL_DQOS_Pos;
	return tmp;
}

static inline void hri_usb_set_QOSCTRL_reg(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_qosctrl_reg_t hri_usb_get_QOSCTRL_reg(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.QOSCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usb_write_QOSCTRL_reg(const void *const hw, hri_usb_qosctrl_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_QOSCTRL_reg(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_QOSCTRL_reg(const void *const hw, hri_usb_qosctrl_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.QOSCTRL.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_qosctrl_reg_t hri_usb_read_QOSCTRL_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.QOSCTRL.reg;
}

static inline void hri_usbdevice_set_CTRLB_DETACH_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_DETACH;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_CTRLB_DETACH_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_DETACH) >> USB_DEVICE_CTRLB_DETACH_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_CTRLB_DETACH_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_DETACH;
	tmp |= value << USB_DEVICE_CTRLB_DETACH_Pos;
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_DETACH_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_DETACH;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_DETACH_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_DETACH;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_CTRLB_UPRSM_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_UPRSM;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_CTRLB_UPRSM_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_UPRSM) >> USB_DEVICE_CTRLB_UPRSM_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_CTRLB_UPRSM_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_UPRSM;
	tmp |= value << USB_DEVICE_CTRLB_UPRSM_Pos;
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_UPRSM_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_UPRSM;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_UPRSM_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_UPRSM;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_CTRLB_NREPLY_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_NREPLY;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_CTRLB_NREPLY_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_NREPLY) >> USB_DEVICE_CTRLB_NREPLY_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_CTRLB_NREPLY_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_NREPLY;
	tmp |= value << USB_DEVICE_CTRLB_NREPLY_Pos;
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_NREPLY_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_NREPLY;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_NREPLY_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_NREPLY;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_CTRLB_TSTJ_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_TSTJ;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_CTRLB_TSTJ_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_TSTJ) >> USB_DEVICE_CTRLB_TSTJ_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_CTRLB_TSTJ_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_TSTJ;
	tmp |= value << USB_DEVICE_CTRLB_TSTJ_Pos;
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_TSTJ_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_TSTJ;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_TSTJ_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_TSTJ;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_CTRLB_TSTK_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_TSTK;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_CTRLB_TSTK_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_TSTK) >> USB_DEVICE_CTRLB_TSTK_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_CTRLB_TSTK_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_TSTK;
	tmp |= value << USB_DEVICE_CTRLB_TSTK_Pos;
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_TSTK_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_TSTK;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_TSTK_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_TSTK;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_CTRLB_TSTPCKT_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_TSTPCKT;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_CTRLB_TSTPCKT_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_TSTPCKT) >> USB_DEVICE_CTRLB_TSTPCKT_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_CTRLB_TSTPCKT_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_TSTPCKT;
	tmp |= value << USB_DEVICE_CTRLB_TSTPCKT_Pos;
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_TSTPCKT_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_TSTPCKT;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_TSTPCKT_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_TSTPCKT;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_CTRLB_OPMODE2_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_OPMODE2;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_CTRLB_OPMODE2_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_OPMODE2) >> USB_DEVICE_CTRLB_OPMODE2_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_CTRLB_OPMODE2_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_OPMODE2;
	tmp |= value << USB_DEVICE_CTRLB_OPMODE2_Pos;
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_OPMODE2_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_OPMODE2;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_OPMODE2_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_OPMODE2;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_CTRLB_GNAK_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_GNAK;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_CTRLB_GNAK_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_GNAK) >> USB_DEVICE_CTRLB_GNAK_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_CTRLB_GNAK_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_GNAK;
	tmp |= value << USB_DEVICE_CTRLB_GNAK_Pos;
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_GNAK_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_GNAK;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_GNAK_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_GNAK;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_CTRLB_SPDCONF_bf(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_SPDCONF(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_ctrlb_reg_t hri_usbdevice_get_CTRLB_SPDCONF_bf(const void *const         hw,
                                                                           hri_usbdevice_ctrlb_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_SPDCONF(mask)) >> USB_DEVICE_CTRLB_SPDCONF_Pos;
	return tmp;
}

static inline void hri_usbdevice_write_CTRLB_SPDCONF_bf(const void *const hw, hri_usbdevice_ctrlb_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_SPDCONF_Msk;
	tmp |= USB_DEVICE_CTRLB_SPDCONF(data);
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_SPDCONF_bf(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_SPDCONF(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_SPDCONF_bf(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_SPDCONF(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_ctrlb_reg_t hri_usbdevice_read_CTRLB_SPDCONF_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_SPDCONF_Msk) >> USB_DEVICE_CTRLB_SPDCONF_Pos;
	return tmp;
}

static inline void hri_usbdevice_set_CTRLB_LPMHDSK_bf(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= USB_DEVICE_CTRLB_LPMHDSK(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_ctrlb_reg_t hri_usbdevice_get_CTRLB_LPMHDSK_bf(const void *const         hw,
                                                                           hri_usbdevice_ctrlb_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_LPMHDSK(mask)) >> USB_DEVICE_CTRLB_LPMHDSK_Pos;
	return tmp;
}

static inline void hri_usbdevice_write_CTRLB_LPMHDSK_bf(const void *const hw, hri_usbdevice_ctrlb_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= ~USB_DEVICE_CTRLB_LPMHDSK_Msk;
	tmp |= USB_DEVICE_CTRLB_LPMHDSK(data);
	((Usb *)hw)->DEVICE.CTRLB.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_LPMHDSK_bf(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~USB_DEVICE_CTRLB_LPMHDSK(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_LPMHDSK_bf(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= USB_DEVICE_CTRLB_LPMHDSK(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_ctrlb_reg_t hri_usbdevice_read_CTRLB_LPMHDSK_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp = (tmp & USB_DEVICE_CTRLB_LPMHDSK_Msk) >> USB_DEVICE_CTRLB_LPMHDSK_Pos;
	return tmp;
}

static inline void hri_usbdevice_set_CTRLB_reg(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_ctrlb_reg_t hri_usbdevice_get_CTRLB_reg(const void *const         hw,
                                                                    hri_usbdevice_ctrlb_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.CTRLB.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdevice_write_CTRLB_reg(const void *const hw, hri_usbdevice_ctrlb_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_CTRLB_reg(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_CTRLB_reg(const void *const hw, hri_usbdevice_ctrlb_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.CTRLB.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_ctrlb_reg_t hri_usbdevice_read_CTRLB_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.CTRLB.reg;
}

static inline void hri_usbdevice_set_DADD_ADDEN_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg |= USB_DEVICE_DADD_ADDEN;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevice_get_DADD_ADDEN_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DADD.reg;
	tmp = (tmp & USB_DEVICE_DADD_ADDEN) >> USB_DEVICE_DADD_ADDEN_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevice_write_DADD_ADDEN_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.DADD.reg;
	tmp &= ~USB_DEVICE_DADD_ADDEN;
	tmp |= value << USB_DEVICE_DADD_ADDEN_Pos;
	((Usb *)hw)->DEVICE.DADD.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_DADD_ADDEN_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg &= ~USB_DEVICE_DADD_ADDEN;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_DADD_ADDEN_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg ^= USB_DEVICE_DADD_ADDEN;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_set_DADD_DADD_bf(const void *const hw, hri_usbdevice_dadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg |= USB_DEVICE_DADD_DADD(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_dadd_reg_t hri_usbdevice_get_DADD_DADD_bf(const void *const        hw,
                                                                      hri_usbdevice_dadd_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DADD.reg;
	tmp = (tmp & USB_DEVICE_DADD_DADD(mask)) >> USB_DEVICE_DADD_DADD_Pos;
	return tmp;
}

static inline void hri_usbdevice_write_DADD_DADD_bf(const void *const hw, hri_usbdevice_dadd_reg_t data)
{
	uint8_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.DADD.reg;
	tmp &= ~USB_DEVICE_DADD_DADD_Msk;
	tmp |= USB_DEVICE_DADD_DADD(data);
	((Usb *)hw)->DEVICE.DADD.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_DADD_DADD_bf(const void *const hw, hri_usbdevice_dadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg &= ~USB_DEVICE_DADD_DADD(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_DADD_DADD_bf(const void *const hw, hri_usbdevice_dadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg ^= USB_DEVICE_DADD_DADD(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_dadd_reg_t hri_usbdevice_read_DADD_DADD_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DADD.reg;
	tmp = (tmp & USB_DEVICE_DADD_DADD_Msk) >> USB_DEVICE_DADD_DADD_Pos;
	return tmp;
}

static inline void hri_usbdevice_set_DADD_reg(const void *const hw, hri_usbdevice_dadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_dadd_reg_t hri_usbdevice_get_DADD_reg(const void *const hw, hri_usbdevice_dadd_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DADD.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdevice_write_DADD_reg(const void *const hw, hri_usbdevice_dadd_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_clear_DADD_reg(const void *const hw, hri_usbdevice_dadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevice_toggle_DADD_reg(const void *const hw, hri_usbdevice_dadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DADD.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdevice_dadd_reg_t hri_usbdevice_read_DADD_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.DADD.reg;
}

static inline void hri_usb_set_DESCADD_DESCADD_bf(const void *const hw, hri_usb_descadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DESCADD.reg |= USB_DESCADD_DESCADD(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_descadd_reg_t hri_usb_get_DESCADD_DESCADD_bf(const void *const hw, hri_usb_descadd_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DESCADD.reg;
	tmp = (tmp & USB_DESCADD_DESCADD(mask)) >> USB_DESCADD_DESCADD_Pos;
	return tmp;
}

static inline void hri_usb_write_DESCADD_DESCADD_bf(const void *const hw, hri_usb_descadd_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.DESCADD.reg;
	tmp &= ~USB_DESCADD_DESCADD_Msk;
	tmp |= USB_DESCADD_DESCADD(data);
	((Usb *)hw)->DEVICE.DESCADD.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_DESCADD_DESCADD_bf(const void *const hw, hri_usb_descadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DESCADD.reg &= ~USB_DESCADD_DESCADD(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_DESCADD_DESCADD_bf(const void *const hw, hri_usb_descadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DESCADD.reg ^= USB_DESCADD_DESCADD(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_descadd_reg_t hri_usb_read_DESCADD_DESCADD_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DESCADD.reg;
	tmp = (tmp & USB_DESCADD_DESCADD_Msk) >> USB_DESCADD_DESCADD_Pos;
	return tmp;
}

static inline void hri_usb_set_DESCADD_reg(const void *const hw, hri_usb_descadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DESCADD.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_descadd_reg_t hri_usb_get_DESCADD_reg(const void *const hw, hri_usb_descadd_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Usb *)hw)->DEVICE.DESCADD.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usb_write_DESCADD_reg(const void *const hw, hri_usb_descadd_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DESCADD.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_DESCADD_reg(const void *const hw, hri_usb_descadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DESCADD.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_DESCADD_reg(const void *const hw, hri_usb_descadd_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.DESCADD.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_descadd_reg_t hri_usb_read_DESCADD_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.DESCADD.reg;
}

static inline void hri_usb_set_PADCAL_TRANSP_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg |= USB_PADCAL_TRANSP(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_padcal_reg_t hri_usb_get_PADCAL_TRANSP_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp = (tmp & USB_PADCAL_TRANSP(mask)) >> USB_PADCAL_TRANSP_Pos;
	return tmp;
}

static inline void hri_usb_write_PADCAL_TRANSP_bf(const void *const hw, hri_usb_padcal_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp &= ~USB_PADCAL_TRANSP_Msk;
	tmp |= USB_PADCAL_TRANSP(data);
	((Usb *)hw)->DEVICE.PADCAL.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_PADCAL_TRANSP_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg &= ~USB_PADCAL_TRANSP(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_PADCAL_TRANSP_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg ^= USB_PADCAL_TRANSP(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_padcal_reg_t hri_usb_read_PADCAL_TRANSP_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp = (tmp & USB_PADCAL_TRANSP_Msk) >> USB_PADCAL_TRANSP_Pos;
	return tmp;
}

static inline void hri_usb_set_PADCAL_TRANSN_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg |= USB_PADCAL_TRANSN(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_padcal_reg_t hri_usb_get_PADCAL_TRANSN_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp = (tmp & USB_PADCAL_TRANSN(mask)) >> USB_PADCAL_TRANSN_Pos;
	return tmp;
}

static inline void hri_usb_write_PADCAL_TRANSN_bf(const void *const hw, hri_usb_padcal_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp &= ~USB_PADCAL_TRANSN_Msk;
	tmp |= USB_PADCAL_TRANSN(data);
	((Usb *)hw)->DEVICE.PADCAL.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_PADCAL_TRANSN_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg &= ~USB_PADCAL_TRANSN(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_PADCAL_TRANSN_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg ^= USB_PADCAL_TRANSN(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_padcal_reg_t hri_usb_read_PADCAL_TRANSN_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp = (tmp & USB_PADCAL_TRANSN_Msk) >> USB_PADCAL_TRANSN_Pos;
	return tmp;
}

static inline void hri_usb_set_PADCAL_TRIM_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg |= USB_PADCAL_TRIM(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_padcal_reg_t hri_usb_get_PADCAL_TRIM_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp = (tmp & USB_PADCAL_TRIM(mask)) >> USB_PADCAL_TRIM_Pos;
	return tmp;
}

static inline void hri_usb_write_PADCAL_TRIM_bf(const void *const hw, hri_usb_padcal_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp &= ~USB_PADCAL_TRIM_Msk;
	tmp |= USB_PADCAL_TRIM(data);
	((Usb *)hw)->DEVICE.PADCAL.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_PADCAL_TRIM_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg &= ~USB_PADCAL_TRIM(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_PADCAL_TRIM_bf(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg ^= USB_PADCAL_TRIM(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_padcal_reg_t hri_usb_read_PADCAL_TRIM_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp = (tmp & USB_PADCAL_TRIM_Msk) >> USB_PADCAL_TRIM_Pos;
	return tmp;
}

static inline void hri_usb_set_PADCAL_reg(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_padcal_reg_t hri_usb_get_PADCAL_reg(const void *const hw, hri_usb_padcal_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Usb *)hw)->DEVICE.PADCAL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usb_write_PADCAL_reg(const void *const hw, hri_usb_padcal_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_clear_PADCAL_reg(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usb_toggle_PADCAL_reg(const void *const hw, hri_usb_padcal_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((Usb *)hw)->DEVICE.PADCAL.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usb_padcal_reg_t hri_usb_read_PADCAL_reg(const void *const hw)
{
	return ((Usb *)hw)->DEVICE.PADCAL.reg;
}

static inline void hri_usbdescbank_set_ADDR_ADDR_bf(const void *const hw, hri_usbdesc_bank_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->ADDR.reg |= USB_DEVICE_ADDR_ADDR(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_addr_reg_t hri_usbdescbank_get_ADDR_ADDR_bf(const void *const           hw,
                                                                           hri_usbdesc_bank_addr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->ADDR.reg;
	tmp = (tmp & USB_DEVICE_ADDR_ADDR(mask)) >> USB_DEVICE_ADDR_ADDR_Pos;
	return tmp;
}

static inline void hri_usbdescbank_write_ADDR_ADDR_bf(const void *const hw, hri_usbdesc_bank_addr_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescBank *)hw)->ADDR.reg;
	tmp &= ~USB_DEVICE_ADDR_ADDR_Msk;
	tmp |= USB_DEVICE_ADDR_ADDR(data);
	((UsbDeviceDescBank *)hw)->ADDR.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_ADDR_ADDR_bf(const void *const hw, hri_usbdesc_bank_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->ADDR.reg &= ~USB_DEVICE_ADDR_ADDR(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_ADDR_ADDR_bf(const void *const hw, hri_usbdesc_bank_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->ADDR.reg ^= USB_DEVICE_ADDR_ADDR(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_addr_reg_t hri_usbdescbank_read_ADDR_ADDR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->ADDR.reg;
	tmp = (tmp & USB_DEVICE_ADDR_ADDR_Msk) >> USB_DEVICE_ADDR_ADDR_Pos;
	return tmp;
}

static inline void hri_usbdescbank_set_ADDR_reg(const void *const hw, hri_usbdesc_bank_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->ADDR.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_addr_reg_t hri_usbdescbank_get_ADDR_reg(const void *const           hw,
                                                                       hri_usbdesc_bank_addr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->ADDR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdescbank_write_ADDR_reg(const void *const hw, hri_usbdesc_bank_addr_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->ADDR.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_ADDR_reg(const void *const hw, hri_usbdesc_bank_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->ADDR.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_ADDR_reg(const void *const hw, hri_usbdesc_bank_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->ADDR.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_addr_reg_t hri_usbdescbank_read_ADDR_reg(const void *const hw)
{
	return ((UsbDeviceDescBank *)hw)->ADDR.reg;
}

static inline void hri_usbdescbank_set_PCKSIZE_AUTO_ZLP_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg |= USB_DEVICE_PCKSIZE_AUTO_ZLP;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdescbank_get_PCKSIZE_AUTO_ZLP_bit(const void *const hw)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_AUTO_ZLP) >> USB_DEVICE_PCKSIZE_AUTO_ZLP_Pos;
	return (bool)tmp;
}

static inline void hri_usbdescbank_write_PCKSIZE_AUTO_ZLP_bit(const void *const hw, bool value)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp &= ~USB_DEVICE_PCKSIZE_AUTO_ZLP;
	tmp |= value << USB_DEVICE_PCKSIZE_AUTO_ZLP_Pos;
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_PCKSIZE_AUTO_ZLP_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg &= ~USB_DEVICE_PCKSIZE_AUTO_ZLP;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_PCKSIZE_AUTO_ZLP_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg ^= USB_DEVICE_PCKSIZE_AUTO_ZLP;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_set_PCKSIZE_BYTE_COUNT_bf(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg |= USB_DEVICE_PCKSIZE_BYTE_COUNT(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_pcksize_reg_t
hri_usbdescbank_get_PCKSIZE_BYTE_COUNT_bf(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_BYTE_COUNT(mask)) >> USB_DEVICE_PCKSIZE_BYTE_COUNT_Pos;
	return tmp;
}

static inline void hri_usbdescbank_write_PCKSIZE_BYTE_COUNT_bf(const void *const              hw,
                                                               hri_usbdesc_bank_pcksize_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp &= ~USB_DEVICE_PCKSIZE_BYTE_COUNT_Msk;
	tmp |= USB_DEVICE_PCKSIZE_BYTE_COUNT(data);
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_PCKSIZE_BYTE_COUNT_bf(const void *const              hw,
                                                               hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg &= ~USB_DEVICE_PCKSIZE_BYTE_COUNT(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_PCKSIZE_BYTE_COUNT_bf(const void *const              hw,
                                                                hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg ^= USB_DEVICE_PCKSIZE_BYTE_COUNT(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_pcksize_reg_t hri_usbdescbank_read_PCKSIZE_BYTE_COUNT_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_BYTE_COUNT_Msk) >> USB_DEVICE_PCKSIZE_BYTE_COUNT_Pos;
	return tmp;
}

static inline void hri_usbdescbank_set_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const              hw,
                                                                    hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg |= USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_pcksize_reg_t
hri_usbdescbank_get_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(mask)) >> USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE_Pos;
	return tmp;
}

static inline void hri_usbdescbank_write_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const              hw,
                                                                      hri_usbdesc_bank_pcksize_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp &= ~USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE_Msk;
	tmp |= USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(data);
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const              hw,
                                                                      hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg &= ~USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const              hw,
                                                                       hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg ^= USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_pcksize_reg_t hri_usbdescbank_read_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE_Msk) >> USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE_Pos;
	return tmp;
}

static inline void hri_usbdescbank_set_PCKSIZE_SIZE_bf(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg |= USB_DEVICE_PCKSIZE_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_pcksize_reg_t hri_usbdescbank_get_PCKSIZE_SIZE_bf(const void *const              hw,
                                                                                 hri_usbdesc_bank_pcksize_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_SIZE(mask)) >> USB_DEVICE_PCKSIZE_SIZE_Pos;
	return tmp;
}

static inline void hri_usbdescbank_write_PCKSIZE_SIZE_bf(const void *const hw, hri_usbdesc_bank_pcksize_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp &= ~USB_DEVICE_PCKSIZE_SIZE_Msk;
	tmp |= USB_DEVICE_PCKSIZE_SIZE(data);
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_PCKSIZE_SIZE_bf(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg &= ~USB_DEVICE_PCKSIZE_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_PCKSIZE_SIZE_bf(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg ^= USB_DEVICE_PCKSIZE_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_pcksize_reg_t hri_usbdescbank_read_PCKSIZE_SIZE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_SIZE_Msk) >> USB_DEVICE_PCKSIZE_SIZE_Pos;
	return tmp;
}

static inline void hri_usbdescbank_set_PCKSIZE_reg(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_pcksize_reg_t hri_usbdescbank_get_PCKSIZE_reg(const void *const              hw,
                                                                             hri_usbdesc_bank_pcksize_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdescbank_write_PCKSIZE_reg(const void *const hw, hri_usbdesc_bank_pcksize_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_PCKSIZE_reg(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_PCKSIZE_reg(const void *const hw, hri_usbdesc_bank_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->PCKSIZE.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_pcksize_reg_t hri_usbdescbank_read_PCKSIZE_reg(const void *const hw)
{
	return ((UsbDeviceDescBank *)hw)->PCKSIZE.reg;
}

static inline void hri_usbdescbank_set_EXTREG_SUBPID_bf(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg |= USB_DEVICE_EXTREG_SUBPID(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_extreg_reg_t hri_usbdescbank_get_EXTREG_SUBPID_bf(const void *const             hw,
                                                                                 hri_usbdesc_bank_extreg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->EXTREG.reg;
	tmp = (tmp & USB_DEVICE_EXTREG_SUBPID(mask)) >> USB_DEVICE_EXTREG_SUBPID_Pos;
	return tmp;
}

static inline void hri_usbdescbank_write_EXTREG_SUBPID_bf(const void *const hw, hri_usbdesc_bank_extreg_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescBank *)hw)->EXTREG.reg;
	tmp &= ~USB_DEVICE_EXTREG_SUBPID_Msk;
	tmp |= USB_DEVICE_EXTREG_SUBPID(data);
	((UsbDeviceDescBank *)hw)->EXTREG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_EXTREG_SUBPID_bf(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg &= ~USB_DEVICE_EXTREG_SUBPID(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_EXTREG_SUBPID_bf(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg ^= USB_DEVICE_EXTREG_SUBPID(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_extreg_reg_t hri_usbdescbank_read_EXTREG_SUBPID_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->EXTREG.reg;
	tmp = (tmp & USB_DEVICE_EXTREG_SUBPID_Msk) >> USB_DEVICE_EXTREG_SUBPID_Pos;
	return tmp;
}

static inline void hri_usbdescbank_set_EXTREG_VARIABLE_bf(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg |= USB_DEVICE_EXTREG_VARIABLE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_extreg_reg_t hri_usbdescbank_get_EXTREG_VARIABLE_bf(const void *const             hw,
                                                                                   hri_usbdesc_bank_extreg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->EXTREG.reg;
	tmp = (tmp & USB_DEVICE_EXTREG_VARIABLE(mask)) >> USB_DEVICE_EXTREG_VARIABLE_Pos;
	return tmp;
}

static inline void hri_usbdescbank_write_EXTREG_VARIABLE_bf(const void *const hw, hri_usbdesc_bank_extreg_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescBank *)hw)->EXTREG.reg;
	tmp &= ~USB_DEVICE_EXTREG_VARIABLE_Msk;
	tmp |= USB_DEVICE_EXTREG_VARIABLE(data);
	((UsbDeviceDescBank *)hw)->EXTREG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_EXTREG_VARIABLE_bf(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg &= ~USB_DEVICE_EXTREG_VARIABLE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_EXTREG_VARIABLE_bf(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg ^= USB_DEVICE_EXTREG_VARIABLE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_extreg_reg_t hri_usbdescbank_read_EXTREG_VARIABLE_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->EXTREG.reg;
	tmp = (tmp & USB_DEVICE_EXTREG_VARIABLE_Msk) >> USB_DEVICE_EXTREG_VARIABLE_Pos;
	return tmp;
}

static inline void hri_usbdescbank_set_EXTREG_reg(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_extreg_reg_t hri_usbdescbank_get_EXTREG_reg(const void *const             hw,
                                                                           hri_usbdesc_bank_extreg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->EXTREG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdescbank_write_EXTREG_reg(const void *const hw, hri_usbdesc_bank_extreg_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_clear_EXTREG_reg(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdescbank_toggle_EXTREG_reg(const void *const hw, hri_usbdesc_bank_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->EXTREG.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_extreg_reg_t hri_usbdescbank_read_EXTREG_reg(const void *const hw)
{
	return ((UsbDeviceDescBank *)hw)->EXTREG.reg;
}

static inline bool hri_usbdescbank_get_STATUS_BK_CRCERR_bit(const void *const hw)
{
	return (((UsbDeviceDescBank *)hw)->STATUS_BK.reg & USB_DEVICE_STATUS_BK_CRCERR) >> USB_DEVICE_STATUS_BK_CRCERR_Pos;
}

static inline void hri_usbdescbank_clear_STATUS_BK_CRCERR_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->STATUS_BK.reg = USB_DEVICE_STATUS_BK_CRCERR;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdescbank_get_STATUS_BK_ERRORFLOW_bit(const void *const hw)
{
	return (((UsbDeviceDescBank *)hw)->STATUS_BK.reg & USB_DEVICE_STATUS_BK_ERRORFLOW)
	       >> USB_DEVICE_STATUS_BK_ERRORFLOW_Pos;
}

static inline void hri_usbdescbank_clear_STATUS_BK_ERRORFLOW_bit(const void *const hw)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->STATUS_BK.reg = USB_DEVICE_STATUS_BK_ERRORFLOW;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_status_bk_reg_t hri_usbdescbank_get_STATUS_BK_reg(const void *const                hw,
                                                                                 hri_usbdesc_bank_status_bk_reg_t mask)
{
	uint8_t tmp;
	tmp = ((UsbDeviceDescBank *)hw)->STATUS_BK.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdescbank_clear_STATUS_BK_reg(const void *const hw, hri_usbdesc_bank_status_bk_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescBank *)hw)->STATUS_BK.reg = mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdesc_bank_status_bk_reg_t hri_usbdescbank_read_STATUS_BK_reg(const void *const hw)
{
	return ((UsbDeviceDescBank *)hw)->STATUS_BK.reg;
}

static inline void hri_usbdevicedescriptor_set_ADDR_ADDR_bf(const void *const hw, uint8_t submodule_index,
                                                            hri_usbdescriptordevice_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg |= USB_DEVICE_ADDR_ADDR(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_addr_reg_t
hri_usbdevicedescriptor_get_ADDR_ADDR_bf(const void *const hw, uint8_t submodule_index,
                                         hri_usbdescriptordevice_addr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg;
	tmp = (tmp & USB_DEVICE_ADDR_ADDR(mask)) >> USB_DEVICE_ADDR_ADDR_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_write_ADDR_ADDR_bf(const void *const hw, uint8_t submodule_index,
                                                              hri_usbdescriptordevice_addr_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg;
	tmp &= ~USB_DEVICE_ADDR_ADDR_Msk;
	tmp |= USB_DEVICE_ADDR_ADDR(data);
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_ADDR_ADDR_bf(const void *const hw, uint8_t submodule_index,
                                                              hri_usbdescriptordevice_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg &= ~USB_DEVICE_ADDR_ADDR(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_ADDR_ADDR_bf(const void *const hw, uint8_t submodule_index,
                                                               hri_usbdescriptordevice_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg ^= USB_DEVICE_ADDR_ADDR(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_addr_reg_t hri_usbdevicedescriptor_read_ADDR_ADDR_bf(const void *const hw,
                                                                                           uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg;
	tmp = (tmp & USB_DEVICE_ADDR_ADDR_Msk) >> USB_DEVICE_ADDR_ADDR_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_set_ADDR_reg(const void *const hw, uint8_t submodule_index,
                                                        hri_usbdescriptordevice_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_addr_reg_t
hri_usbdevicedescriptor_get_ADDR_reg(const void *const hw, uint8_t submodule_index,
                                     hri_usbdescriptordevice_addr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdevicedescriptor_write_ADDR_reg(const void *const hw, uint8_t submodule_index,
                                                          hri_usbdescriptordevice_addr_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_ADDR_reg(const void *const hw, uint8_t submodule_index,
                                                          hri_usbdescriptordevice_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_ADDR_reg(const void *const hw, uint8_t submodule_index,
                                                           hri_usbdescriptordevice_addr_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_addr_reg_t hri_usbdevicedescriptor_read_ADDR_reg(const void *const hw,
                                                                                       uint8_t submodule_index)
{
	return ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].ADDR.reg;
}

static inline void hri_usbdevicedescriptor_set_PCKSIZE_AUTO_ZLP_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg |= USB_DEVICE_PCKSIZE_AUTO_ZLP;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevicedescriptor_get_PCKSIZE_AUTO_ZLP_bit(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_AUTO_ZLP) >> USB_DEVICE_PCKSIZE_AUTO_ZLP_Pos;
	return (bool)tmp;
}

static inline void hri_usbdevicedescriptor_write_PCKSIZE_AUTO_ZLP_bit(const void *const hw, uint8_t submodule_index,
                                                                      bool value)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp &= ~USB_DEVICE_PCKSIZE_AUTO_ZLP;
	tmp |= value << USB_DEVICE_PCKSIZE_AUTO_ZLP_Pos;
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_PCKSIZE_AUTO_ZLP_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg &= ~USB_DEVICE_PCKSIZE_AUTO_ZLP;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_PCKSIZE_AUTO_ZLP_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg ^= USB_DEVICE_PCKSIZE_AUTO_ZLP;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_set_PCKSIZE_BYTE_COUNT_bf(const void *const hw, uint8_t submodule_index,
                                                                     hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg |= USB_DEVICE_PCKSIZE_BYTE_COUNT(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_pcksize_reg_t
hri_usbdevicedescriptor_get_PCKSIZE_BYTE_COUNT_bf(const void *const hw, uint8_t submodule_index,
                                                  hri_usbdescriptordevice_pcksize_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_BYTE_COUNT(mask)) >> USB_DEVICE_PCKSIZE_BYTE_COUNT_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_write_PCKSIZE_BYTE_COUNT_bf(const void *const hw, uint8_t submodule_index,
                                                                       hri_usbdescriptordevice_pcksize_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp &= ~USB_DEVICE_PCKSIZE_BYTE_COUNT_Msk;
	tmp |= USB_DEVICE_PCKSIZE_BYTE_COUNT(data);
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_PCKSIZE_BYTE_COUNT_bf(const void *const hw, uint8_t submodule_index,
                                                                       hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg &= ~USB_DEVICE_PCKSIZE_BYTE_COUNT(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_PCKSIZE_BYTE_COUNT_bf(const void *const hw, uint8_t submodule_index,
                                                                        hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg ^= USB_DEVICE_PCKSIZE_BYTE_COUNT(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_pcksize_reg_t
hri_usbdevicedescriptor_read_PCKSIZE_BYTE_COUNT_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_BYTE_COUNT_Msk) >> USB_DEVICE_PCKSIZE_BYTE_COUNT_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_set_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const hw,
                                                                            uint8_t           submodule_index,
                                                                            hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg
	    |= USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_pcksize_reg_t
hri_usbdevicedescriptor_get_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                                         hri_usbdescriptordevice_pcksize_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(mask)) >> USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE_Pos;
	return tmp;
}

static inline void
hri_usbdevicedescriptor_write_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                                           hri_usbdescriptordevice_pcksize_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp &= ~USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE_Msk;
	tmp |= USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(data);
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void
hri_usbdevicedescriptor_clear_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                                           hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg
	    &= ~USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void
hri_usbdevicedescriptor_toggle_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                                            hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg
	    ^= USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_pcksize_reg_t
hri_usbdevicedescriptor_read_PCKSIZE_MULTI_PACKET_SIZE_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE_Msk) >> USB_DEVICE_PCKSIZE_MULTI_PACKET_SIZE_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_set_PCKSIZE_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                                               hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg |= USB_DEVICE_PCKSIZE_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_pcksize_reg_t
hri_usbdevicedescriptor_get_PCKSIZE_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                            hri_usbdescriptordevice_pcksize_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_SIZE(mask)) >> USB_DEVICE_PCKSIZE_SIZE_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_write_PCKSIZE_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                                                 hri_usbdescriptordevice_pcksize_reg_t data)
{
	uint32_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp &= ~USB_DEVICE_PCKSIZE_SIZE_Msk;
	tmp |= USB_DEVICE_PCKSIZE_SIZE(data);
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_PCKSIZE_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                                                 hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg &= ~USB_DEVICE_PCKSIZE_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_PCKSIZE_SIZE_bf(const void *const hw, uint8_t submodule_index,
                                                                  hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg ^= USB_DEVICE_PCKSIZE_SIZE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_pcksize_reg_t
hri_usbdevicedescriptor_read_PCKSIZE_SIZE_bf(const void *const hw, uint8_t submodule_index)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp = (tmp & USB_DEVICE_PCKSIZE_SIZE_Msk) >> USB_DEVICE_PCKSIZE_SIZE_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_set_PCKSIZE_reg(const void *const hw, uint8_t submodule_index,
                                                           hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_pcksize_reg_t
hri_usbdevicedescriptor_get_PCKSIZE_reg(const void *const hw, uint8_t submodule_index,
                                        hri_usbdescriptordevice_pcksize_reg_t mask)
{
	uint32_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdevicedescriptor_write_PCKSIZE_reg(const void *const hw, uint8_t submodule_index,
                                                             hri_usbdescriptordevice_pcksize_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_PCKSIZE_reg(const void *const hw, uint8_t submodule_index,
                                                             hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_PCKSIZE_reg(const void *const hw, uint8_t submodule_index,
                                                              hri_usbdescriptordevice_pcksize_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_pcksize_reg_t hri_usbdevicedescriptor_read_PCKSIZE_reg(const void *const hw,
                                                                                             uint8_t submodule_index)
{
	return ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].PCKSIZE.reg;
}

static inline void hri_usbdevicedescriptor_set_EXTREG_SUBPID_bf(const void *const hw, uint8_t submodule_index,
                                                                hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg |= USB_DEVICE_EXTREG_SUBPID(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_extreg_reg_t
hri_usbdevicedescriptor_get_EXTREG_SUBPID_bf(const void *const hw, uint8_t submodule_index,
                                             hri_usbdescriptordevice_extreg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg;
	tmp = (tmp & USB_DEVICE_EXTREG_SUBPID(mask)) >> USB_DEVICE_EXTREG_SUBPID_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_write_EXTREG_SUBPID_bf(const void *const hw, uint8_t submodule_index,
                                                                  hri_usbdescriptordevice_extreg_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg;
	tmp &= ~USB_DEVICE_EXTREG_SUBPID_Msk;
	tmp |= USB_DEVICE_EXTREG_SUBPID(data);
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_EXTREG_SUBPID_bf(const void *const hw, uint8_t submodule_index,
                                                                  hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg &= ~USB_DEVICE_EXTREG_SUBPID(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_EXTREG_SUBPID_bf(const void *const hw, uint8_t submodule_index,
                                                                   hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg ^= USB_DEVICE_EXTREG_SUBPID(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_extreg_reg_t
hri_usbdevicedescriptor_read_EXTREG_SUBPID_bf(const void *const hw, uint8_t submodule_index)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg;
	tmp = (tmp & USB_DEVICE_EXTREG_SUBPID_Msk) >> USB_DEVICE_EXTREG_SUBPID_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_set_EXTREG_VARIABLE_bf(const void *const hw, uint8_t submodule_index,
                                                                  hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg |= USB_DEVICE_EXTREG_VARIABLE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_extreg_reg_t
hri_usbdevicedescriptor_get_EXTREG_VARIABLE_bf(const void *const hw, uint8_t submodule_index,
                                               hri_usbdescriptordevice_extreg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg;
	tmp = (tmp & USB_DEVICE_EXTREG_VARIABLE(mask)) >> USB_DEVICE_EXTREG_VARIABLE_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_write_EXTREG_VARIABLE_bf(const void *const hw, uint8_t submodule_index,
                                                                    hri_usbdescriptordevice_extreg_reg_t data)
{
	uint16_t tmp;
	USB_CRITICAL_SECTION_ENTER();
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg;
	tmp &= ~USB_DEVICE_EXTREG_VARIABLE_Msk;
	tmp |= USB_DEVICE_EXTREG_VARIABLE(data);
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg = tmp;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_EXTREG_VARIABLE_bf(const void *const hw, uint8_t submodule_index,
                                                                    hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg &= ~USB_DEVICE_EXTREG_VARIABLE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_EXTREG_VARIABLE_bf(const void *const hw, uint8_t submodule_index,
                                                                     hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg ^= USB_DEVICE_EXTREG_VARIABLE(mask);
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_extreg_reg_t
hri_usbdevicedescriptor_read_EXTREG_VARIABLE_bf(const void *const hw, uint8_t submodule_index)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg;
	tmp = (tmp & USB_DEVICE_EXTREG_VARIABLE_Msk) >> USB_DEVICE_EXTREG_VARIABLE_Pos;
	return tmp;
}

static inline void hri_usbdevicedescriptor_set_EXTREG_reg(const void *const hw, uint8_t submodule_index,
                                                          hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg |= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_extreg_reg_t
hri_usbdevicedescriptor_get_EXTREG_reg(const void *const hw, uint8_t submodule_index,
                                       hri_usbdescriptordevice_extreg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdevicedescriptor_write_EXTREG_reg(const void *const hw, uint8_t submodule_index,
                                                            hri_usbdescriptordevice_extreg_reg_t data)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg = data;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_clear_EXTREG_reg(const void *const hw, uint8_t submodule_index,
                                                            hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg &= ~mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_usbdevicedescriptor_toggle_EXTREG_reg(const void *const hw, uint8_t submodule_index,
                                                             hri_usbdescriptordevice_extreg_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg ^= mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_extreg_reg_t hri_usbdevicedescriptor_read_EXTREG_reg(const void *const hw,
                                                                                           uint8_t submodule_index)
{
	return ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].EXTREG.reg;
}

static inline bool hri_usbdevicedescriptor_get_STATUS_BK_CRCERR_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].STATUS_BK.reg & USB_DEVICE_STATUS_BK_CRCERR)
	       >> USB_DEVICE_STATUS_BK_CRCERR_Pos;
}

static inline void hri_usbdevicedescriptor_clear_STATUS_BK_CRCERR_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].STATUS_BK.reg = USB_DEVICE_STATUS_BK_CRCERR;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_usbdevicedescriptor_get_STATUS_BK_ERRORFLOW_bit(const void *const hw, uint8_t submodule_index)
{
	return (((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].STATUS_BK.reg & USB_DEVICE_STATUS_BK_ERRORFLOW)
	       >> USB_DEVICE_STATUS_BK_ERRORFLOW_Pos;
}

static inline void hri_usbdevicedescriptor_clear_STATUS_BK_ERRORFLOW_bit(const void *const hw, uint8_t submodule_index)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].STATUS_BK.reg = USB_DEVICE_STATUS_BK_ERRORFLOW;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_status_bk_reg_t
hri_usbdevicedescriptor_get_STATUS_BK_reg(const void *const hw, uint8_t submodule_index,
                                          hri_usbdescriptordevice_status_bk_reg_t mask)
{
	uint8_t tmp;
	tmp = ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].STATUS_BK.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_usbdevicedescriptor_clear_STATUS_BK_reg(const void *const hw, uint8_t submodule_index,
                                                               hri_usbdescriptordevice_status_bk_reg_t mask)
{
	USB_CRITICAL_SECTION_ENTER();
	((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].STATUS_BK.reg = mask;
	USB_CRITICAL_SECTION_LEAVE();
}

static inline hri_usbdescriptordevice_status_bk_reg_t
hri_usbdevicedescriptor_read_STATUS_BK_reg(const void *const hw, uint8_t submodule_index)
{
	return ((UsbDeviceDescriptor *)hw)->DeviceDescBank[submodule_index].STATUS_BK.reg;
}

/* Below section is for legacy hri apis name, not recommended to use below left side apis in application */
#define hri_usbdevice_wait_for_sync(a, b) hri_usb_wait_for_sync(a, b)
#define hri_usbdevice_is_syncing(a, b) hri_usb_is_syncing(a, b)
#define hri_usbdevice_set_CTRLA_SWRST_bit(a) hri_usb_set_CTRLA_SWRST_bit(a)
#define hri_usbdevice_get_CTRLA_SWRST_bit(a) hri_usb_get_CTRLA_SWRST_bit(a)
#define hri_usbdevice_set_CTRLA_ENABLE_bit(a) hri_usb_set_CTRLA_ENABLE_bit(a)
#define hri_usbdevice_get_CTRLA_ENABLE_bit(a) hri_usb_get_CTRLA_ENABLE_bit(a)
#define hri_usbdevice_write_CTRLA_ENABLE_bit(a, b) hri_usb_write_CTRLA_ENABLE_bit(a, b)
#define hri_usbdevice_clear_CTRLA_ENABLE_bit(a) hri_usb_clear_CTRLA_ENABLE_bit(a)
#define hri_usbdevice_toggle_CTRLA_ENABLE_bit(a) hri_usb_toggle_CTRLA_ENABLE_bit(a)
#define hri_usbdevice_set_CTRLA_RUNSTDBY_bit(a) hri_usb_set_CTRLA_RUNSTDBY_bit(a)
#define hri_usbdevice_get_CTRLA_RUNSTDBY_bit(a) hri_usb_get_CTRLA_RUNSTDBY_bit(a)
#define hri_usbdevice_write_CTRLA_RUNSTDBY_bit(a, b) hri_usb_write_CTRLA_RUNSTDBY_bit(a, b)
#define hri_usbdevice_clear_CTRLA_RUNSTDBY_bit(a) hri_usb_clear_CTRLA_RUNSTDBY_bit(a)
#define hri_usbdevice_toggle_CTRLA_RUNSTDBY_bit(a) hri_usb_toggle_CTRLA_RUNSTDBY_bit(a)
#define hri_usbdevice_set_CTRLA_MODE_bit(a) hri_usb_set_CTRLA_MODE_bit(a)
#define hri_usbdevice_get_CTRLA_MODE_bit(a) hri_usb_get_CTRLA_MODE_bit(a)
#define hri_usbdevice_write_CTRLA_MODE_bit(a, b) hri_usb_write_CTRLA_MODE_bit(a, b)
#define hri_usbdevice_clear_CTRLA_MODE_bit(a) hri_usb_clear_CTRLA_MODE_bit(a)
#define hri_usbdevice_toggle_CTRLA_MODE_bit(a) hri_usb_toggle_CTRLA_MODE_bit(a)
#define hri_usbdevice_set_CTRLA_reg(a, b) hri_usb_set_CTRLA_reg(a, b)
#define hri_usbdevice_get_CTRLA_reg(a, b) hri_usb_get_CTRLA_reg(a, b)
#define hri_usbdevice_write_CTRLA_reg(a, b) hri_usb_write_CTRLA_reg(a, b)
#define hri_usbdevice_clear_CTRLA_reg(a, b) hri_usb_clear_CTRLA_reg(a, b)
#define hri_usbdevice_toggle_CTRLA_reg(a, b) hri_usb_toggle_CTRLA_reg(a, b)
#define hri_usbdevice_read_CTRLA_reg(a) hri_usb_read_CTRLA_reg(a)
#define hri_usbdevice_set_QOSCTRL_CQOS_bf(a, b) hri_usb_set_QOSCTRL_CQOS_bf(a, b)
#define hri_usbdevice_get_QOSCTRL_CQOS_bf(a, b) hri_usb_get_QOSCTRL_CQOS_bf(a, b)
#define hri_usbdevice_write_QOSCTRL_CQOS_bf(a, b) hri_usb_write_QOSCTRL_CQOS_bf(a, b)
#define hri_usbdevice_clear_QOSCTRL_CQOS_bf(a, b) hri_usb_clear_QOSCTRL_CQOS_bf(a, b)
#define hri_usbdevice_toggle_QOSCTRL_CQOS_bf(a, b) hri_usb_toggle_QOSCTRL_CQOS_bf(a, b)
#define hri_usbdevice_read_QOSCTRL_CQOS_bf(a) hri_usb_read_QOSCTRL_CQOS_bf(a)
#define hri_usbdevice_set_QOSCTRL_DQOS_bf(a, b) hri_usb_set_QOSCTRL_DQOS_bf(a, b)
#define hri_usbdevice_get_QOSCTRL_DQOS_bf(a, b) hri_usb_get_QOSCTRL_DQOS_bf(a, b)
#define hri_usbdevice_write_QOSCTRL_DQOS_bf(a, b) hri_usb_write_QOSCTRL_DQOS_bf(a, b)
#define hri_usbdevice_clear_QOSCTRL_DQOS_bf(a, b) hri_usb_clear_QOSCTRL_DQOS_bf(a, b)
#define hri_usbdevice_toggle_QOSCTRL_DQOS_bf(a, b) hri_usb_toggle_QOSCTRL_DQOS_bf(a, b)
#define hri_usbdevice_read_QOSCTRL_DQOS_bf(a) hri_usb_read_QOSCTRL_DQOS_bf(a)
#define hri_usbdevice_set_QOSCTRL_reg(a, b) hri_usb_set_QOSCTRL_reg(a, b)
#define hri_usbdevice_get_QOSCTRL_reg(a, b) hri_usb_get_QOSCTRL_reg(a, b)
#define hri_usbdevice_write_QOSCTRL_reg(a, b) hri_usb_write_QOSCTRL_reg(a, b)
#define hri_usbdevice_clear_QOSCTRL_reg(a, b) hri_usb_clear_QOSCTRL_reg(a, b)
#define hri_usbdevice_toggle_QOSCTRL_reg(a, b) hri_usb_toggle_QOSCTRL_reg(a, b)
#define hri_usbdevice_read_QOSCTRL_reg(a) hri_usb_read_QOSCTRL_reg(a)
#define hri_usbdevice_set_DESCADD_DESCADD_bf(a, b) hri_usb_set_DESCADD_DESCADD_bf(a, b)
#define hri_usbdevice_get_DESCADD_DESCADD_bf(a, b) hri_usb_get_DESCADD_DESCADD_bf(a, b)
#define hri_usbdevice_write_DESCADD_DESCADD_bf(a, b) hri_usb_write_DESCADD_DESCADD_bf(a, b)
#define hri_usbdevice_clear_DESCADD_DESCADD_bf(a, b) hri_usb_clear_DESCADD_DESCADD_bf(a, b)
#define hri_usbdevice_toggle_DESCADD_DESCADD_bf(a, b) hri_usb_toggle_DESCADD_DESCADD_bf(a, b)
#define hri_usbdevice_read_DESCADD_DESCADD_bf(a) hri_usb_read_DESCADD_DESCADD_bf(a)
#define hri_usbdevice_set_DESCADD_reg(a, b) hri_usb_set_DESCADD_reg(a, b)
#define hri_usbdevice_get_DESCADD_reg(a, b) hri_usb_get_DESCADD_reg(a, b)
#define hri_usbdevice_write_DESCADD_reg(a, b) hri_usb_write_DESCADD_reg(a, b)
#define hri_usbdevice_clear_DESCADD_reg(a, b) hri_usb_clear_DESCADD_reg(a, b)
#define hri_usbdevice_toggle_DESCADD_reg(a, b) hri_usb_toggle_DESCADD_reg(a, b)
#define hri_usbdevice_read_DESCADD_reg(a) hri_usb_read_DESCADD_reg(a)
#define hri_usbdevice_set_PADCAL_TRANSP_bf(a, b) hri_usb_set_PADCAL_TRANSP_bf(a, b)
#define hri_usbdevice_get_PADCAL_TRANSP_bf(a, b) hri_usb_get_PADCAL_TRANSP_bf(a, b)
#define hri_usbdevice_write_PADCAL_TRANSP_bf(a, b) hri_usb_write_PADCAL_TRANSP_bf(a, b)
#define hri_usbdevice_clear_PADCAL_TRANSP_bf(a, b) hri_usb_clear_PADCAL_TRANSP_bf(a, b)
#define hri_usbdevice_toggle_PADCAL_TRANSP_bf(a, b) hri_usb_toggle_PADCAL_TRANSP_bf(a, b)
#define hri_usbdevice_read_PADCAL_TRANSP_bf(a) hri_usb_read_PADCAL_TRANSP_bf(a)
#define hri_usbdevice_set_PADCAL_TRANSN_bf(a, b) hri_usb_set_PADCAL_TRANSN_bf(a, b)
#define hri_usbdevice_get_PADCAL_TRANSN_bf(a, b) hri_usb_get_PADCAL_TRANSN_bf(a, b)
#define hri_usbdevice_write_PADCAL_TRANSN_bf(a, b) hri_usb_write_PADCAL_TRANSN_bf(a, b)
#define hri_usbdevice_clear_PADCAL_TRANSN_bf(a, b) hri_usb_clear_PADCAL_TRANSN_bf(a, b)
#define hri_usbdevice_toggle_PADCAL_TRANSN_bf(a, b) hri_usb_toggle_PADCAL_TRANSN_bf(a, b)
#define hri_usbdevice_read_PADCAL_TRANSN_bf(a) hri_usb_read_PADCAL_TRANSN_bf(a)
#define hri_usbdevice_set_PADCAL_TRIM_bf(a, b) hri_usb_set_PADCAL_TRIM_bf(a, b)
#define hri_usbdevice_get_PADCAL_TRIM_bf(a, b) hri_usb_get_PADCAL_TRIM_bf(a, b)
#define hri_usbdevice_write_PADCAL_TRIM_bf(a, b) hri_usb_write_PADCAL_TRIM_bf(a, b)
#define hri_usbdevice_clear_PADCAL_TRIM_bf(a, b) hri_usb_clear_PADCAL_TRIM_bf(a, b)
#define hri_usbdevice_toggle_PADCAL_TRIM_bf(a, b) hri_usb_toggle_PADCAL_TRIM_bf(a, b)
#define hri_usbdevice_read_PADCAL_TRIM_bf(a) hri_usb_read_PADCAL_TRIM_bf(a)
#define hri_usbdevice_set_PADCAL_reg(a, b) hri_usb_set_PADCAL_reg(a, b)
#define hri_usbdevice_get_PADCAL_reg(a, b) hri_usb_get_PADCAL_reg(a, b)
#define hri_usbdevice_write_PADCAL_reg(a, b) hri_usb_write_PADCAL_reg(a, b)
#define hri_usbdevice_clear_PADCAL_reg(a, b) hri_usb_clear_PADCAL_reg(a, b)
#define hri_usbdevice_toggle_PADCAL_reg(a, b) hri_usb_toggle_PADCAL_reg(a, b)
#define hri_usbdevice_read_PADCAL_reg(a) hri_usb_read_PADCAL_reg(a)
#define hri_usbdevice_get_SYNCBUSY_SWRST_bit(a) hri_usb_get_SYNCBUSY_SWRST_bit(a)
#define hri_usbdevice_get_SYNCBUSY_ENABLE_bit(a) hri_usb_get_SYNCBUSY_ENABLE_bit(a)
#define hri_usbdevice_get_SYNCBUSY_reg(a, b) hri_usb_get_SYNCBUSY_reg(a, b)
#define hri_usbdevice_read_SYNCBUSY_reg(a) hri_usb_read_SYNCBUSY_reg(a)
#define hri_usbdevice_get_FSMSTATUS_FSMSTATE_bf(a, b) hri_usb_get_FSMSTATUS_FSMSTATE_bf(a, b)
#define hri_usbdevice_read_FSMSTATUS_FSMSTATE_bf(a) hri_usb_read_FSMSTATUS_FSMSTATE_bf(a)
#define hri_usbdevice_get_FSMSTATUS_reg(a, b) hri_usb_get_FSMSTATUS_reg(a, b)
#define hri_usbdevice_read_FSMSTATUS_reg(a) hri_usb_read_FSMSTATUS_reg(a)

#ifdef __cplusplus
}
#endif

#endif /* _HRI_USB_L22_H_INCLUDED */
#endif /* _SAML22_USB_COMPONENT_ */
