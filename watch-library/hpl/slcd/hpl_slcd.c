/**
 * \file
 *
 * \brief SLCD Segment Liquid Crystal Display Controller(Sync) functionality
 *        Implementation.
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
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

#include <utils_assert.h>
#include <hpl_slcd_sync.h>
#include <hpl_slcd_config.h>
#include <hpl_slcd_cm_7_seg_mapping.h>
#include <hpl_slcd_cm_14_seg_mapping.h>

static int32_t _slcd_sync_set_segment(struct _slcd_sync_device *dev, const uint32_t com, const uint32_t seg,
                                      const bool on);

/**
 * \brief SLCD configuration type
 */
struct slcd_configuration {
	hri_slcd_ctrla_reg_t ctrla; /*!< Control A Register */
	hri_slcd_ctrlb_reg_t ctrlb; /*!< Control B Register */
	hri_slcd_ctrlc_reg_t ctrlc; /*!< Control C Register */
	hri_slcd_ctrld_reg_t ctrld; /*!< Control D Register */
};

/**
 * \brief Array of AC configurations
 */
static struct slcd_configuration _slcd
    = {SLCD_CTRLA_DUTY(CONF_SLCD_COM_NUM) | CONF_SLCD_WMOD << SLCD_CTRLA_WMOD_Pos
           | CONF_SLCD_RUNSTDBY << SLCD_CTRLA_RUNSTDBY_Pos | SLCD_CTRLA_PRESC(CONF_SLCD_PRESC)
           | SLCD_CTRLA_CKDIV(CONF_SLCD_CKDIV) | SLCD_CTRLA_BIAS(CONF_SLCD_BIAS)
           | CONF_SLCD_XVLCD << SLCD_CTRLA_XVLCD_Pos | SLCD_CTRLA_PRF(CONF_SLCD_PRF) | SLCD_CTRLA_RRF(CONF_SLCD_RRF),
       CONF_SLCD_BBEN << SLCD_CTRLB_BBEN_Pos | SLCD_CTRLB_BBD(CONF_SLCD_BBD - 1),
       SLCD_CTRLC_CTST(CONF_SLCD_CONTRAST_ADJUST),
       SLCD_CTRLD_DISPEN};
static const struct slcd_char_setting cm_setting[] = SLCD_CHAR_SETTING_TABLE;
static const struct slcd_char_mapping cm7_lut[]    = SLCD_SEG7_LUT;
static const struct slcd_char_mapping cm14_lut[]   = SLCD_SEG14_LUT;
/**
 * \brief              Initialize SLCD Device Descriptor
 */
int32_t _slcd_sync_init(struct _slcd_sync_device *dev, void *const hw)
{
	if (!hri_slcd_is_syncing(hw, SLCD_SYNCBUSY_SWRST)) {
		if (hri_slcd_get_CTRLA_ENABLE_bit(hw)) {
			hri_slcd_clear_CTRLA_ENABLE_bit(hw);
			hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_ENABLE);
		}
		hri_slcd_write_CTRLA_reg(hw, SLCD_CTRLA_SWRST);
	}
	hri_slcd_wait_for_sync(hw, SLCD_SYNCBUSY_SWRST);

	dev->hw = hw;
	hri_slcd_write_CTRLA_reg(hw, _slcd.ctrla);
	hri_slcd_write_CTRLB_reg(hw, _slcd.ctrlb);
	hri_slcd_write_CTRLC_reg(hw, _slcd.ctrlc);
	hri_slcd_write_CTRLD_reg(hw, _slcd.ctrld);
	hri_slcd_write_LPENL_reg(hw, CONF_SLCD_LPENL);
	hri_slcd_write_LPENH_reg(hw, CONF_SLCD_LPENH);
	hri_slcd_write_SDATAL0_reg(hw, 0);
	hri_slcd_write_SDATAH0_reg(hw, 0);
	hri_slcd_write_SDATAL1_reg(hw, 0);
	hri_slcd_write_SDATAH1_reg(hw, 0);
	hri_slcd_write_SDATAL2_reg(hw, 0);
	hri_slcd_write_SDATAH2_reg(hw, 0);
	hri_slcd_write_SDATAL3_reg(hw, 0);
	hri_slcd_write_SDATAH3_reg(hw, 0);
	hri_slcd_write_SDATAL4_reg(hw, 0);
	hri_slcd_write_SDATAH4_reg(hw, 0);
	hri_slcd_write_SDATAL5_reg(hw, 0);
	hri_slcd_write_SDATAH5_reg(hw, 0);
	hri_slcd_write_SDATAL6_reg(hw, 0);
	hri_slcd_write_SDATAH6_reg(hw, 0);
	hri_slcd_write_SDATAL7_reg(hw, 0);
	hri_slcd_write_SDATAH7_reg(hw, 0);
	hri_slcd_set_BCFG_MODE_bit(dev->hw);
	return ERR_NONE;
}

/**
 * \brief              DeInitialize SLCD Device Descriptor
 */
int32_t _slcd_sync_deinit(struct _slcd_sync_device *dev)
{
	hri_slcd_clear_CTRLA_ENABLE_bit(dev->hw);
	hri_slcd_wait_for_sync(dev->hw, SLCD_SYNCBUSY_ENABLE);
	hri_slcd_set_CTRLA_SWRST_bit(dev->hw);
	dev->hw = NULL;

	return ERR_NONE;
}

/**
 * \brief              Enable SLCD driver
 *
 * \param[in] dev      SLCD device descriptor to be enabled
 */
int32_t _slcd_sync_enable(struct _slcd_sync_device *dev)
{
	hri_slcd_set_CTRLA_ENABLE_bit(dev->hw);
	return ERR_NONE;
}

/**
 * \brief              Disable SLCD driver
 */
int32_t _slcd_sync_disable(struct _slcd_sync_device *dev)
{
	hri_slcd_clear_CTRLA_ENABLE_bit(dev->hw);
	return ERR_NONE;
}

/**
 * \brief               Turn on a Segment
 */
int32_t _slcd_sync_seg_on(struct _slcd_sync_device *dev, uint32_t seg)
{
	return _slcd_sync_set_segment(dev, SLCD_COMNUM(seg), SLCD_SEGNUM(seg), true);
}

/**
 * \brief               Turn off a Segment
 */
int32_t _slcd_sync_seg_off(struct _slcd_sync_device *dev, uint32_t seg)
{
	return _slcd_sync_set_segment(dev, SLCD_COMNUM(seg), SLCD_SEGNUM(seg), false);
}

/**
 * \brief               Blink a Segment
 */
int32_t _slcd_sync_seg_blink(struct _slcd_sync_device *dev, uint32_t seg, const uint32_t period)
{
	if ((SLCD_COMNUM(seg) >= CONF_SLCD_COM_NUM) || (SLCD_SEGNUM(seg) >= CONF_SLCD_SEG_NUM)) {
		return ERR_INVALID_ARG;
	}
	/* COM[0..7], Seg[0,1] support blink */
	if (SLCD_SEGNUM(seg) >= 2) {
		return ERR_INVALID_ARG;
	}
	/* Verify period */
	if (period > SLCD_FC_MAX_MS || period < SLCD_FC_MIN_MS) {
		return ERR_INVALID_ARG;
	}
	/* Set Period, use Frame Counter 0 for blink */
	hri_slcd_clear_CTRLD_FC0EN_bit(dev->hw);
	hri_slcd_wait_for_sync(dev->hw, SLCD_SYNCBUSY_CTRLD);
	if (period <= SLCD_FC_BYPASS_MAX_MS) {
		hri_slcd_set_FC0_reg(dev->hw, SLCD_FC0_PB | ((period / (1000 / SLCD_FRAME_FREQUENCY)) - 1));
	} else {
		hri_slcd_set_FC0_reg(dev->hw, (((period / (1000 / SLCD_FRAME_FREQUENCY)) / 8 - 1)));
	}
	hri_slcd_set_CTRLD_FC0EN_bit(dev->hw);

	/* Set Blink Segments */
	_slcd_sync_set_segment(dev, SLCD_COMNUM(seg), SLCD_SEGNUM(seg), true);
	hri_slcd_clear_CTRLD_BLINK_bit(dev->hw);

	hri_slcd_clear_CTRLA_ENABLE_bit(dev->hw);
	hri_slcd_wait_for_sync(dev->hw, SLCD_SYNCBUSY_ENABLE);

	/* Update BCFG */
	if (SLCD_SEGNUM(seg) == 0) {
		hri_slcd_set_BCFG_BSS0_bf(dev->hw, 1 << SLCD_COMNUM(seg));
	} else {
		hri_slcd_set_BCFG_BSS1_bf(dev->hw, 1 << SLCD_COMNUM(seg));
	}
	hri_slcd_set_CTRLA_ENABLE_bit(dev->hw);
	hri_slcd_set_CTRLD_BLINK_bit(dev->hw);

	return ERR_NONE;
}

/**
 * \brief              Displays a character
 */
int32_t _slcd_sync_write_char(struct _slcd_sync_device *dev, const uint8_t character, uint32_t index)
{
	uint32_t i;
	uint32_t data = ~0;
	if (cm_setting[index].size == 7) {
		for (i = 0; i<sizeof(cm7_lut)>> 2; i++) {
			if (cm7_lut[i].character == character) {
				data = cm7_lut[i].mapping;
				break;
			}
		}
	} else if (cm_setting[index].size == 14) {
		for (i = 0; i<sizeof(cm14_lut)>> 2; i++) {
			if (cm14_lut[i].character == character) {
				data = cm14_lut[i].mapping;
				break;
			}
		}
	}
	if (data == 0xFFFFFFFF) {
		return ERR_INVALID_ARG;
	}

	hri_slcd_write_CMCFG_NSEG_bf(dev->hw, cm_setting[index].nseg);
	hri_slcd_write_CMINDEX_CINDEX_bf(dev->hw, cm_setting[index].com_index);
	hri_slcd_write_CMINDEX_SINDEX_bf(dev->hw, cm_setting[index].seg_index);

	if (cm_setting[index].size == 7) {
		hri_slcd_write_CMDMASK_reg(dev->hw, SEG7_MASK);
	} else if (cm_setting[index].size == 14) {
		hri_slcd_write_CMDMASK_reg(dev->hw, SEG14_MASK);
	}
	while (hri_slcd_get_STATUS_CMWRBUSY_bit(dev->hw))
		;
	hri_slcd_write_CMDATA_reg(dev->hw, data);

	return ERR_NONE;
}

/**
 * \brief               Start animation play by a segment array
 */
int32_t _slcd_sync_start_animation(struct _slcd_sync_device *dev, const uint32_t segs[], uint32_t len,
                                   const uint32_t period)
{
	uint32_t i;
	uint32_t csrlen = 0;
	if (len > 16) {
		return ERR_INVALID_ARG;
	}
	/* COM[0..7], Seg[2,3] support animation */
	for (i = 0; i < len; i++) {
		if ((SLCD_SEGNUM(segs[i]) != 2 && SLCD_SEGNUM(segs[i]) != 3)) {
			return ERR_INVALID_ARG;
		}
	}
	/* Verify period */
	if (period > SLCD_FC_MAX_MS || period < SLCD_FC_MIN_MS) {
		return ERR_INVALID_ARG;
	}
	/* Set Period */
	_slcd_sync_set_animation_period(dev, period);

	/* Set animation segments */
	hri_slcd_clear_CTRLA_ENABLE_bit(dev->hw);
	hri_slcd_clear_CTRLD_CSREN_bit(dev->hw);

	hri_slcd_wait_for_sync(dev->hw, SLCD_SYNCBUSY_ENABLE | SLCD_SYNCBUSY_CTRLD);
	hri_slcd_set_CSRCFG_FCS_bf(dev->hw, 1);
	hri_slcd_write_CSRCFG_DATA_bf(dev->hw, 0);
	for (i = 0; i < len; i++) {
		hri_slcd_set_CSRCFG_DATA_bf(dev->hw, (1 << ((SLCD_COMNUM(segs[i]) * 2) + (SLCD_SEGNUM(segs[i]) - 2))));
		if (((SLCD_COMNUM(segs[i]) * 2) + (SLCD_SEGNUM(segs[i]) - 2)) > csrlen) {
			csrlen = (SLCD_COMNUM(segs[i]) * 2) + (SLCD_SEGNUM(segs[i]) - 2);
		}
	}
	hri_slcd_set_CSRCFG_SIZE_bf(dev->hw, csrlen + 1);
	hri_slcd_set_BCFG_MODE_bit(dev->hw);
	hri_slcd_set_CTRLD_CSREN_bit(dev->hw);
	hri_slcd_set_CTRLA_ENABLE_bit(dev->hw);

	return ERR_NONE;
}

/**
 * \brief               Stop animation play by a segment array
 */
int32_t _slcd_sync_stop_animation(struct _slcd_sync_device *dev, const uint32_t segs[], uint32_t len)
{
	/* Not used because of the current version is not supported, Reserved */
	(void)segs;
	(void)len;
	hri_slcd_wait_for_sync(dev->hw, SLCD_SYNCBUSY_CTRLD);
	hri_slcd_clear_CTRLD_CSREN_bit(dev->hw);
	return ERR_NONE;
}

/**
 * \brief               Set animation Frequency
 */
int32_t _slcd_sync_set_animation_period(struct _slcd_sync_device *dev, const uint32_t period)
{
	hri_slcd_clear_CTRLD_FC1EN_bit(dev->hw);
	hri_slcd_wait_for_sync(dev->hw, SLCD_SYNCBUSY_CTRLD);
	/* Use Frame Counter 1 for blink */
	if (period <= SLCD_FC_BYPASS_MAX_MS) {
		hri_slcd_set_FC1_reg(dev->hw, SLCD_FC1_PB | ((period / (1000 / SLCD_FRAME_FREQUENCY)) - 1));
	} else {
		hri_slcd_set_FC1_reg(dev->hw, (((period / (1000 / SLCD_FRAME_FREQUENCY)) / 8 - 1)));
	}
	hri_slcd_set_CTRLD_FC1EN_bit(dev->hw);
	return ERR_NONE;
}

static int32_t _slcd_sync_set_segment(struct _slcd_sync_device *dev, const uint32_t com, const uint32_t seg,
                                      const bool on)
{
	if ((SLCD_COMNUM(seg) >= CONF_SLCD_COM_NUM) || (SLCD_SEGNUM(seg) >= CONF_SLCD_SEG_NUM)) {
		return ERR_INVALID_ARG;
	}
	/* Use register instead hri interface to optimization code */
	if (on) {
		((uint32_t *)&(((Slcd *)dev->hw)->SDATAL0))[(com * 2) + (seg >> 5)]
		    |= (seg < 32) ? (1 << seg) : (1 << (seg >> 5));
	} else {
		((uint32_t *)&(((Slcd *)dev->hw)->SDATAL0))[(com * 2) + (seg >> 5)]
		    &= ~((seg < 32) ? (1 << seg) : (1 << (seg >> 5)));
	}

	return ERR_NONE;
}
