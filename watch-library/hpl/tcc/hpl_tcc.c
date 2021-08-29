/**
 * \file
 *
 * \brief SAM TCC
 *
 * Copyright (c) 2014-2019 Microchip Technology Inc. and its subsidiaries.
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

#include <compiler.h>
#include <hpl_pwm.h>
#include <hpl_tcc.h>
#include <hpl_tcc_config.h>
#include <hpl_timer.h>
#include <utils.h>
#include <utils_assert.h>

/**
 * \brief TCC configuration type
 */
struct tcc_cfg {
	void *                 hw; /*!< instance of TCC */
	IRQn_Type              irq;
	hri_tcc_ctrla_reg_t    ctrl_a;
	hri_tcc_ctrlbset_reg_t ctrl_b;
	hri_tcc_dbgctrl_reg_t  dbg_ctrl;
	hri_tcc_evctrl_reg_t   event_ctrl;
	hri_tcc_cc_reg_t       cc0;
	hri_tcc_cc_reg_t       cc1;
	hri_tcc_cc_reg_t       cc2;
	hri_tcc_cc_reg_t       cc3;
	hri_tcc_per_reg_t      per;
};
/**
 * \brief pwm configuration type
 */
struct tcc_pwm_cfg {
	void *    hw; /*!< instance of TCC */
	IRQn_Type irq;
	uint8_t   sel_ch;
	uint32_t  period;
	uint32_t  duty_cycle;
	uint32_t  wave;
};

/**
 * \internal Retrieve configuration
 *
 * \param[in] hw The pointer of TCC base address
 *
 * \return The configuration
 */
static struct tcc_cfg *_get_tcc_cfg(void *hw);

/**
 * \brief Array of TCC configurations
 */
static struct tcc_cfg _cfgs[1] = {
    {(void *)TCC0,
     TCC0_IRQn,
     CONF_TCC0_CTRLA,
     CONF_TCC0_CTRLB,
     CONF_TCC0_DBGCTRL,
     CONF_TCC0_EVCTRL,
     CONF_TCC0_CC0,
     CONF_TCC0_CC1,
     CONF_TCC0_CC2,
     CONF_TCC0_CC3,
     CONF_TCC0_PER},
};

/**
 * \internal Retrieve configuration
 *
 * \param[in] hw The pointer of TCC base address
 *
 * \return The configuration
 */
static struct tcc_pwm_cfg *_get_tcc_pwm_cfg(void *hw);

/**
 * \brief Array of PWM configurations
 */
static struct tcc_pwm_cfg _cfgs_pwm[1] = {
    {(void *)TCC0,
     TCC0_IRQn,
     CONF_TCC0_SEL_CH,
     CONF_TCC0_PER_REG,
     CONF_TCC0_CCX_REG,
     (CONF_TCC0_WAVEGEN << TCC_WAVE_WAVEGEN_Pos)},
};
/* Renamed access REG name PERB -> PERBUF */
#define hri_tcc_write_PERB_reg hri_tcc_write_PERBUF_reg
#define hri_tcc_read_PERB_reg hri_tcc_read_PERBUF_reg

/** Renamed access REG name CCB -> CCBUF */
#define hri_tcc_write_CCB_reg hri_tcc_write_CCBUF_reg
#define hri_tcc_read_CCB_reg hri_tcc_read_CCBUF_reg

static struct _pwm_device *_tcc0_dev = NULL;

/**
 * \brief Set of pointer to hal_pwm helper functions
 */
static struct _pwm_hpl_interface _tcc_pwm_functions = {
    _tcc_pwm_init,
    _tcc_pwm_deinit,
    _tcc_start_pwm,
    _tcc_stop_pwm,
    _tcc_set_pwm_param,
    _tcc_is_pwm_enabled,
    _tcc_pwm_get_period,
    _tcc_pwm_get_duty,
    _tcc_pwm_set_irq_state,
};

/**
 * \brief Init irq param with the given tcc hardware instance
 */
static void _tcc_init_irq_param(const void *const hw, void *dev)
{
	if (hw == TCC0) {
		_tcc0_dev = (struct _pwm_device *)dev;
	}
}
/**
 * \brief Initialize TCC for PWM mode
 */
int32_t _tcc_pwm_init(struct _pwm_device *const device, void *const hw)
{
	struct tcc_cfg *cfg = _get_tcc_cfg(hw);
	if (cfg == NULL) {
		return ERR_NOT_FOUND;
	}
	struct tcc_pwm_cfg *cfg_pwm = _get_tcc_pwm_cfg(hw);
	if (cfg_pwm == NULL) {
		return ERR_NOT_FOUND;
	}

	device->hw = hw;

	if (!hri_tcc_is_syncing(hw, TCC_SYNCBUSY_SWRST)) {
		if (hri_tcc_get_CTRLA_reg(hw, TCC_CTRLA_ENABLE)) {
			hri_tcc_clear_CTRLA_ENABLE_bit(hw);
			hri_tcc_wait_for_sync(hw, TCC_SYNCBUSY_ENABLE);
		}
		hri_tcc_write_CTRLA_reg(hw, TCC_CTRLA_SWRST);
	}
	hri_tcc_wait_for_sync(hw, TCC_SYNCBUSY_SWRST);

	hri_tcc_write_CTRLA_reg(hw, cfg->ctrl_a);
	hri_tcc_set_CTRLB_reg(hw, cfg->ctrl_b);
	hri_tcc_write_DBGCTRL_reg(hw, cfg->dbg_ctrl);
	hri_tcc_write_EVCTRL_reg(hw, cfg->event_ctrl);

	hri_tcc_write_WAVE_reg(hw, cfg_pwm->wave);
	hri_tcc_write_PER_reg(hw, cfg_pwm->period);
	cfg->per = cfg_pwm->period;
	switch (cfg_pwm->sel_ch) {
	case 0:
		cfg->cc0 = cfg_pwm->duty_cycle;
		hri_tcc_write_CC_reg(hw, 0, cfg->cc0);
		break;
	case 1:
		cfg->cc1 = cfg_pwm->duty_cycle;
		hri_tcc_write_CC_reg(hw, 1, cfg->cc1);
		break;
	case 2:
		cfg->cc2 = cfg_pwm->duty_cycle;
		hri_tcc_write_CC_reg(hw, 2, cfg->cc2);
		break;
	case 3:
		cfg->cc3 = cfg_pwm->duty_cycle;
		hri_tcc_write_CC_reg(hw, 3, cfg->cc3);
		break;
	default:
		return ERR_NO_RESOURCE;
		break;
	}
	hri_tcc_clear_CTRLB_LUPD_bit(hw);

	_tcc_init_irq_param(hw, (void *)device);
	NVIC_DisableIRQ((IRQn_Type)cfg_pwm->irq);
	NVIC_ClearPendingIRQ((IRQn_Type)cfg_pwm->irq);
	NVIC_EnableIRQ((IRQn_Type)cfg_pwm->irq);

	return ERR_NONE;
}
/**
 * \brief De-initialize TCC for PWM mode
 */
void _tcc_pwm_deinit(struct _pwm_device *const device)
{
	void *const         hw      = device->hw;
	struct tcc_pwm_cfg *cfg_pwm = _get_tcc_pwm_cfg(hw);
	if (cfg_pwm != NULL) {
		NVIC_DisableIRQ((IRQn_Type)cfg_pwm->irq);
		hri_tcc_clear_CTRLA_ENABLE_bit(hw);
		hri_tcc_set_CTRLA_SWRST_bit(hw);
	}
}
/**
 * \brief Start PWM
 */
void _tcc_start_pwm(struct _pwm_device *const device)
{
	hri_tcc_set_CTRLA_ENABLE_bit(device->hw);
}
/**
 * \brief Stop PWM
 */
void _tcc_stop_pwm(struct _pwm_device *const device)
{
	hri_tcc_clear_CTRLA_ENABLE_bit(device->hw);
}
/**
 * \brief Set PWM parameter
 */
void _tcc_set_pwm_param(struct _pwm_device *const device, const pwm_period_t period, const pwm_period_t duty_cycle)
{
	void *const         hw      = device->hw;
	struct tcc_pwm_cfg *cfg_pwm = _get_tcc_pwm_cfg(hw);
	if (cfg_pwm != NULL) {
		hri_tcc_write_PERB_reg(hw, period);
		hri_tcc_write_CCB_reg(hw, cfg_pwm->sel_ch, duty_cycle);
		;
	}
}
/**
 * \brief Get pwm waveform period value
 */
pwm_period_t _tcc_pwm_get_period(const struct _pwm_device *const device)
{
	return (pwm_period_t)(hri_tcc_read_PERB_reg(device->hw));
}
/**
 * \brief Get pwm waveform duty cycle
 */
uint32_t _tcc_pwm_get_duty(const struct _pwm_device *const device)
{
	void *const         hw      = device->hw;
	struct tcc_pwm_cfg *cfg_pwm = _get_tcc_pwm_cfg(hw);
	if (cfg_pwm == NULL) {
		return ERR_NOT_FOUND;
	}
	uint32_t per        = hri_tcc_read_PERB_reg(hw);
	uint32_t duty_cycle = hri_tcc_read_CCB_reg(hw, cfg_pwm->sel_ch);

	return ((duty_cycle * 1000) / per);
}
/**
 * \brief Check if PWM is running
 */
bool _tcc_is_pwm_enabled(const struct _pwm_device *const device)
{
	return hri_tcc_get_CTRLA_ENABLE_bit(device->hw);
}
/**
 * \brief Enable/disable PWM interrupt
 */
void _tcc_pwm_set_irq_state(struct _pwm_device *const device, const enum _pwm_callback_type type, const bool disable)
{
	ASSERT(device);

	if (PWM_DEVICE_PERIOD_CB == type) {
		hri_tcc_write_INTEN_OVF_bit(device->hw, disable);
	} else if (PWM_DEVICE_ERROR_CB == type) {
		hri_tcc_write_INTEN_ERR_bit(device->hw, disable);
	}
}

/**
 * \brief Retrieve timer helper functions
 */
struct _timer_hpl_interface *_tcc_get_timer(void)
{
	return NULL;
}

/**
 * \brief Retrieve pwm helper functions
 */
struct _pwm_hpl_interface *_tcc_get_pwm(void)
{
	return &_tcc_pwm_functions;
}
/**
 * \internal TC interrupt handler for PWM
 *
 * \param[in] instance TC instance number
 */
static void tcc_pwm_interrupt_handler(struct _pwm_device *device)
{
	void *const hw = device->hw;

	if (hri_tcc_get_interrupt_OVF_bit(hw)) {
		hri_tcc_clear_interrupt_OVF_bit(hw);
		if (NULL != device->callback.pwm_period_cb) {
			device->callback.pwm_period_cb(device);
		}
	}
	if (hri_tcc_get_INTEN_ERR_bit(hw)) {
		hri_tcc_clear_interrupt_ERR_bit(hw);
		if (NULL != device->callback.pwm_error_cb) {
			device->callback.pwm_error_cb(device);
		}
	}
}


static struct tcc_cfg *_get_tcc_cfg(void *hw)
{
	uint8_t i;

	for (i = 0; i < ARRAY_SIZE(_cfgs); i++) {
		if (_cfgs[i].hw == hw) {
			return &(_cfgs[i]);
		}
	}
	return NULL;
}

static struct tcc_pwm_cfg *_get_tcc_pwm_cfg(void *hw)
{
	uint8_t i;

	for (i = 0; i < ARRAY_SIZE(_cfgs_pwm); i++) {
		if (_cfgs_pwm[i].hw == hw) {
			return &(_cfgs_pwm[i]);
		}
	}
	return NULL;
}
