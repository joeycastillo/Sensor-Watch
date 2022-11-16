/**
 * \file
 *
 * \brief RTC Driver (Calendar Mode)
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

#include "hpl_calendar.h"
#include "hpl_timer.h"
#include <hpl_rtc_config.h>
#include <utils_assert.h>

/*!< Pointer to hpl device */

static struct _timer_device *_rtc_dev = NULL;

/**
 * \brief Initialize Timer
 */
int32_t _timer_init(struct _timer_device *const dev, void *const hw)
{
	ASSERT(dev);

	uint16_t register_value;
	dev->hw = hw;

	hri_rtcmode0_write_CTRL_reg(dev->hw, RTC_MODE0_CTRL_SWRST);
	hri_rtcmode0_wait_for_sync(dev->hw);

	/* Set mode 0 */
	register_value = RTC_MODE0_CTRL_MODE(0);

	/* Set prescaler */
	register_value |= RTC_MODE0_CTRL_PRESCALER(CONF_RTC_PRESCALER);

	/* clear counter on compare/timer match */
	register_value |= RTC_MODE0_CTRL_MATCHCLR;

	hri_rtcmode0_write_CTRL_reg(dev->hw, register_value);

	hri_rtcmode0_write_COMP_COMP_bf(dev->hw, 0, CONF_RTC_COMP_VAL);
	hri_rtcmode0_set_INTEN_CMP0_bit(dev->hw);

	/* set event control */
#if CONF_RTC_EVENT_CONTROL_ENABLE == 1
	hri_rtcmode0_write_EVCTRL_reg(
	    dev->hw,
	    (CONF_RTC_PEREO0 << RTC_MODE0_EVCTRL_PEREO0_Pos) | (CONF_RTC_PEREO1 << RTC_MODE0_EVCTRL_PEREO1_Pos)
	        | (CONF_RTC_PEREO2 << RTC_MODE0_EVCTRL_PEREO2_Pos) | (CONF_RTC_PEREO3 << RTC_MODE0_EVCTRL_PEREO3_Pos)
	        | (CONF_RTC_PEREO4 << RTC_MODE0_EVCTRL_PEREO4_Pos) | (CONF_RTC_PEREO5 << RTC_MODE0_EVCTRL_PEREO5_Pos)
	        | (CONF_RTC_PEREO6 << RTC_MODE0_EVCTRL_PEREO6_Pos) | (CONF_RTC_PEREO7 << RTC_MODE0_EVCTRL_PEREO7_Pos)
	        | (CONF_RTC_COMPE0 << RTC_MODE0_EVCTRL_CMPEO_Pos) | (CONF_RTC_OVFEO << RTC_MODE0_EVCTRL_OVFEO_Pos));
#endif

	_rtc_dev = dev;

	return ERR_NONE;
}

/**
 * \brief De-initialize Timer
 */
void _timer_deinit(struct _timer_device *const dev)
{
	ASSERT(dev && dev->hw);

	NVIC_DisableIRQ(RTC_IRQn);

	hri_rtcmode0_write_CTRL_reg(dev->hw, RTC_MODE0_CTRL_SWRST);
}

/**
 * \brief Start hardware timer
 */
void _timer_start(struct _timer_device *const dev)
{
	ASSERT(dev && dev->hw);

	NVIC_EnableIRQ(RTC_IRQn);
	hri_rtcmode0_write_COUNT_COUNT_bf(dev->hw, 0);
	hri_rtcmode0_wait_for_sync(dev->hw);
	hri_rtcmode0_set_CTRL_ENABLE_bit(dev->hw);
}

/**
 * \brief Stop hardware timer
 */
void _timer_stop(struct _timer_device *const dev)
{
	ASSERT(dev && dev->hw);

	hri_rtcmode0_clear_CTRL_ENABLE_bit(dev->hw);
}

/**
 * \brief Set timer period
 */
void _timer_set_period(struct _timer_device *const dev, const uint32_t clock_cycles)
{
	hri_rtcmode0_write_COMP_COMP_bf(dev->hw, 0, clock_cycles);
}

/**
 * \brief Retrieve timer period
 */
uint32_t _timer_get_period(const struct _timer_device *const dev)
{
	return hri_rtcmode0_read_COMP_COMP_bf(dev->hw, 0);
}

/**
 * \brief Check if timer is running
 */
bool _timer_is_started(const struct _timer_device *const dev)
{
	return hri_rtcmode0_get_CTRL_ENABLE_bit(dev->hw);
}

/**
 * \brief Set timer IRQ
 */
void _timer_set_irq(struct _timer_device *const dev)
{
	(void)dev;
}

/**
 * \brief RTC Timer interrupt handler
 *
 * \param[in] p The pointer to calendar device struct
 */
static void _rtc_timer_interrupt_handler(struct _timer_device *dev)
{
	/* Read and mask interrupt flag register */
	uint16_t flag = hri_rtcmode0_read_INTFLAG_reg(dev->hw);

	if (flag & RTC_MODE0_INTFLAG_CMP0) {
		if (dev->timer_cb.period_expired) {
			dev->timer_cb.period_expired(dev);
		}

		/* Clear interrupt flag */
		hri_rtcmode0_clear_interrupt_CMP0_bit(dev->hw);
	}
}

/**
 * \brief Retrieve timer helper functions
 */
struct _timer_hpl_interface *_rtc_get_timer(void)
{
	return NULL;
}

/**
 * \brief Rtc interrupt handler
 */
void RTC_Handler(void)
{
	_rtc_timer_interrupt_handler(_rtc_dev);
}
