
/**
 * \file
 *
 * \brief SAM TC
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
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

#include <hpl_pwm.h>
#include <hpl_tc_config.h>
#include <hpl_timer.h>
#include <utils.h>
#include <utils_assert.h>
#include <hpl_tc_base.h>

#ifndef CONF_TC0_ENABLE
#define CONF_TC0_ENABLE 0
#endif
#ifndef CONF_TC1_ENABLE
#define CONF_TC1_ENABLE 0
#endif
#ifndef CONF_TC2_ENABLE
#define CONF_TC2_ENABLE 0
#endif
#ifndef CONF_TC3_ENABLE
#define CONF_TC3_ENABLE 0
#endif
#ifndef CONF_TC4_ENABLE
#define CONF_TC4_ENABLE 0
#endif
#ifndef CONF_TC5_ENABLE
#define CONF_TC5_ENABLE 0
#endif
#ifndef CONF_TC6_ENABLE
#define CONF_TC6_ENABLE 0
#endif
#ifndef CONF_TC7_ENABLE
#define CONF_TC7_ENABLE 0
#endif

/**
 * \brief Macro is used to fill usart configuration structure based on its
 * number
 *
 * \param[in] n The number of structures
 */
#define TC_CONFIGURATION(n)                                                                                            \
	{                                                                                                                  \
		n, TC##n##_IRQn,                                                                                               \
		    TC_CTRLA_MODE(CONF_TC##n##_MODE) | TC_CTRLA_PRESCSYNC(CONF_TC##n##_PRESCSYNC)                              \
		        | (CONF_TC##n##_RUNSTDBY << TC_CTRLA_RUNSTDBY_Pos) | (CONF_TC##n##_ONDEMAND << TC_CTRLA_ONDEMAND_Pos)  \
		        | TC_CTRLA_PRESCALER(CONF_TC##n##_PRESCALER) | (CONF_TC##n##_ALOCK << TC_CTRLA_ALOCK_Pos),             \
		    (CONF_TC##n##_OVFEO << TC_EVCTRL_OVFEO_Pos) | (CONF_TC##n##_TCEI << TC_EVCTRL_TCEI_Pos)                    \
		        | (CONF_TC##n##_TCINV << TC_EVCTRL_TCINV_Pos) | (CONF_TC##n##_EVACT << TC_EVCTRL_EVACT_Pos)            \
		        | (CONF_TC##n##_MCEO0 << TC_EVCTRL_MCEO0_Pos) | (CONF_TC##n##_MCEO1 << TC_EVCTRL_MCEO1_Pos),           \
		    (CONF_TC##n##_DBGRUN << TC_DBGCTRL_DBGRUN_Pos), CONF_TC##n##_PER, CONF_TC##n##_CC0, CONF_TC##n##_CC1,      \
	}
/**
 * \brief TC configuration type
 */
struct tc_configuration {
	uint8_t                number;
	IRQn_Type              irq;
	hri_tc_ctrla_reg_t     ctrl_a;
	hri_tc_evctrl_reg_t    event_ctrl;
	hri_tc_dbgctrl_reg_t   dbg_ctrl;
	hri_tccount8_per_reg_t per;
	hri_tccount32_cc_reg_t cc0;
	hri_tccount32_cc_reg_t cc1;
};

/**
 * \brief Array of TC configurations
 */
static struct tc_configuration _tcs[] = {
#if CONF_TC0_ENABLE == 1
    TC_CONFIGURATION(0),
#endif
#if CONF_TC1_ENABLE == 1
    TC_CONFIGURATION(1),
#endif
#if CONF_TC2_ENABLE == 1
    TC_CONFIGURATION(2),
#endif
#if CONF_TC3_ENABLE == 1
    TC_CONFIGURATION(3),
#endif
#if CONF_TC4_ENABLE == 1
    TC_CONFIGURATION(4),
#endif
#if CONF_TC5_ENABLE == 1
    TC_CONFIGURATION(5),
#endif
#if CONF_TC6_ENABLE == 1
    TC_CONFIGURATION(6),
#endif
#if CONF_TC7_ENABLE == 1
    TC_CONFIGURATION(7),
#endif
};

static struct _timer_device *_tc0_dev = NULL;

static int8_t         get_tc_index(const void *const hw);
static void           _tc_init_irq_param(const void *const hw, void *dev);
static inline uint8_t _get_hardware_offset(const void *const hw);
/**
 * \brief Initialize TC
 */
int32_t _timer_init(struct _timer_device *const device, void *const hw)
{
	int8_t i = get_tc_index(hw);

	device->hw = hw;
	ASSERT(ARRAY_SIZE(_tcs));

	if (!hri_tc_is_syncing(hw, TC_SYNCBUSY_SWRST)) {
		if (hri_tc_get_CTRLA_reg(hw, TC_CTRLA_ENABLE)) {
			hri_tc_clear_CTRLA_ENABLE_bit(hw);
			hri_tc_wait_for_sync(hw, TC_SYNCBUSY_ENABLE);
		}
		hri_tc_write_CTRLA_reg(hw, TC_CTRLA_SWRST);
	}
	hri_tc_wait_for_sync(hw, TC_SYNCBUSY_SWRST);

	hri_tc_write_CTRLA_reg(hw, _tcs[i].ctrl_a);
	hri_tc_write_DBGCTRL_reg(hw, _tcs[i].dbg_ctrl);
	hri_tc_write_EVCTRL_reg(hw, _tcs[i].event_ctrl);
	hri_tc_write_WAVE_reg(hw, TC_WAVE_WAVEGEN_MFRQ);

	if ((_tcs[i].ctrl_a & TC_CTRLA_MODE_Msk) == TC_CTRLA_MODE_COUNT32) {
		hri_tccount32_write_CC_reg(hw, 0, _tcs[i].cc0);
		hri_tccount32_write_CC_reg(hw, 1, _tcs[i].cc1);

	} else if ((_tcs[i].ctrl_a & TC_CTRLA_MODE_Msk) == TC_CTRLA_MODE_COUNT16) {
		hri_tccount16_write_CC_reg(hw, 0, (uint16_t)_tcs[i].cc0);
		hri_tccount16_write_CC_reg(hw, 1, (uint16_t)_tcs[i].cc1);

	} else if ((_tcs[i].ctrl_a & TC_CTRLA_MODE_Msk) == TC_CTRLA_MODE_COUNT8) {
		hri_tccount8_write_CC_reg(hw, 0, (uint8_t)_tcs[i].cc0);
		hri_tccount8_write_CC_reg(hw, 1, (uint8_t)_tcs[i].cc1);
		hri_tccount8_write_PER_reg(hw, _tcs[i].per);
	}
	hri_tc_set_INTEN_OVF_bit(hw);

	_tc_init_irq_param(hw, (void *)device);
	NVIC_DisableIRQ(_tcs[i].irq);
	NVIC_ClearPendingIRQ(_tcs[i].irq);
	NVIC_EnableIRQ(_tcs[i].irq);

	return ERR_NONE;
}
/**
 * \brief De-initialize TC
 */
void _timer_deinit(struct _timer_device *const device)
{
	void *const hw = device->hw;
	int8_t      i  = get_tc_index(hw);
	ASSERT(ARRAY_SIZE(_tcs));

	NVIC_DisableIRQ(_tcs[i].irq);

	hri_tc_clear_CTRLA_ENABLE_bit(hw);
	hri_tc_set_CTRLA_SWRST_bit(hw);
}
/**
 * \brief Start hardware timer
 */
void _timer_start(struct _timer_device *const device)
{
	hri_tc_set_CTRLA_ENABLE_bit(device->hw);
}
/**
 * \brief Stop hardware timer
 */
void _timer_stop(struct _timer_device *const device)
{
	hri_tc_clear_CTRLA_ENABLE_bit(device->hw);
}
/**
 * \brief Set timer period
 */
void _timer_set_period(struct _timer_device *const device, const uint32_t clock_cycles)
{
	void *const hw = device->hw;

	if (TC_CTRLA_MODE_COUNT32_Val == hri_tc_read_CTRLA_MODE_bf(hw)) {
		hri_tccount32_write_CC_reg(hw, 0, clock_cycles);
	} else if (TC_CTRLA_MODE_COUNT16_Val == hri_tc_read_CTRLA_MODE_bf(hw)) {
		hri_tccount16_write_CC_reg(hw, 0, (uint16_t)clock_cycles);
	} else if (TC_CTRLA_MODE_COUNT8_Val == hri_tc_read_CTRLA_MODE_bf(hw)) {
		hri_tccount8_write_PER_reg(hw, clock_cycles);
	}
}
/**
 * \brief Retrieve timer period
 */
uint32_t _timer_get_period(const struct _timer_device *const device)
{
	void *const hw = device->hw;

	if (TC_CTRLA_MODE_COUNT32_Val == hri_tc_read_CTRLA_MODE_bf(hw)) {
		return hri_tccount32_read_CC_reg(hw, 0);
	} else if (TC_CTRLA_MODE_COUNT16_Val == hri_tc_read_CTRLA_MODE_bf(hw)) {
		return hri_tccount16_read_CC_reg(hw, 0);
	} else if (TC_CTRLA_MODE_COUNT8_Val == hri_tc_read_CTRLA_MODE_bf(hw)) {
		return hri_tccount8_read_PER_reg(hw);
	}

	return 0;
}
/**
 * \brief Check if timer is running
 */
bool _timer_is_started(const struct _timer_device *const device)
{
	return hri_tc_get_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief Retrieve timer helper functions
 */
struct _timer_hpl_interface *_tc_get_timer(void)
{
	return NULL;
}

/**
 * \brief Retrieve pwm helper functions
 */
struct _pwm_hpl_interface *_tc_get_pwm(void)
{
	return NULL;
}
/**
 * \brief Set timer IRQ
 *
 * \param[in] hw The pointer to hardware instance
 */
void _timer_set_irq(struct _timer_device *const device)
{
	void *const hw = device->hw;
	int8_t      i  = get_tc_index(hw);
	ASSERT(ARRAY_SIZE(_tcs));

	_irq_set(_tcs[i].irq);
}
/**
 * \internal TC interrupt handler for Timer
 *
 * \param[in] instance TC instance number
 */
static void tc_interrupt_handler(struct _timer_device *device)
{
	void *const hw = device->hw;

	if (hri_tc_get_interrupt_OVF_bit(hw)) {
		hri_tc_clear_interrupt_OVF_bit(hw);
		device->timer_cb.period_expired(device);
	}
}

/**
 * \brief TC interrupt handler
 */
void TC0_Handler(void)
{
	tc_interrupt_handler(_tc0_dev);
}

/**
 * \internal Retrieve TC index
 *
 * \param[in] hw The pointer to hardware instance
 *
 * \return The index of TC configuration
 */
static int8_t get_tc_index(const void *const hw)
{
	uint8_t index = _get_hardware_offset(hw);
	uint8_t i;

	for (i = 0; i < ARRAY_SIZE(_tcs); i++) {
		if (_tcs[i].number == index) {
			return i;
		}
	}

	ASSERT(false);
	return -1;
}

/**
 * \brief Init irq param with the given tc hardware instance
 */
static void _tc_init_irq_param(const void *const hw, void *dev)
{
	if (hw == TC0) {
		_tc0_dev = (struct _timer_device *)dev;
	}
}

/**
 * \internal Retrieve TC hardware index
 *
 * \param[in] hw The pointer to hardware instance
 */
static inline uint8_t _get_hardware_offset(const void *const hw)
{
	return (((uint32_t)hw - (uint32_t)TC0) >> 10);
}
