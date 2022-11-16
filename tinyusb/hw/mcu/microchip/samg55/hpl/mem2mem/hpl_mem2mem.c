/**
 * \file
 *
 * \brief MEM2MEM related functionality.
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

#include <hpl_dma.h>
#include <utils.h>
#include <hpl_mem2mem_config.h>

#if CONF_MEM2MEM_ENABLE
/* Array containing callbacks for DMAC channels */
static struct _dma_resource _resources;

/**
 * \brief Initialize DMAC
 */
int32_t _dma_init(void)
{
	hri_mem2mem_write_MR_reg(MEM2MEM, CONF_MEM2MEM_MR_TSIZE);
	NVIC_DisableIRQ(MEM2MEM_IRQn);
	NVIC_ClearPendingIRQ(MEM2MEM_IRQn);

	return ERR_NONE;
}

/**
 * \brief Enable/disable DMA interrupt
 */
void _dma_set_irq_state(const uint8_t channel, const enum _dma_callback_type type, const bool state)
{
	(void)channel;
	/* Ignore channel since currently only MEM2MEM */

	if (DMA_TRANSFER_COMPLETE_CB == type) {
		hri_mem2mem_write_IMR_RXEND_bit(MEM2MEM, state);
	}

	/* Not support DMA_TRANSFER_ERROR_CB */
}

int32_t _dma_set_destination_address(const uint8_t channel, const void *const dst)
{
	(void)channel;
	hri_mem2mem_write_RPR_reg(MEM2MEM, (uint32_t)dst);

	return ERR_NONE;
}

int32_t _dma_set_source_address(const uint8_t channel, const void *const src)
{
	(void)channel;
	hri_mem2mem_write_TPR_reg(MEM2MEM, (uint32_t)src);

	return ERR_NONE;
}

int32_t _dma_srcinc_enable(const uint8_t channel, const bool enable)
{
	(void)channel;
	if (enable == false) {
		/* The transmit channel buffer size must be equal to the
		   receive channel buffer size */
		return ERR_UNSUPPORTED_OP;
	}

	return ERR_NONE;
}

int32_t _dma_dstinc_enable(const uint8_t channel, const bool enable)
{
	(void)channel;
	if (enable == false) {
		/* The transmit channel buffer size must be equal to the
		   receive channel buffer size */
		return ERR_UNSUPPORTED_OP;
	}

	return ERR_NONE;
}

int32_t _dma_set_data_amount(const uint8_t channel, const uint32_t amount)
{
	(void)channel;

	hri_mem2mem_write_TCR_reg(MEM2MEM, amount);
	hri_mem2mem_write_RCR_reg(MEM2MEM, amount);
	return ERR_NONE;
}

int32_t _dma_enable_transaction(const uint8_t channel, const bool software_trigger)
{
	(void)channel;

	if (software_trigger) {
		hri_mem2mem_write_PTCR_reg(MEM2MEM, MEM2MEM_PTCR_RXTEN | MEM2MEM_PTCR_TXTEN);

		NVIC_EnableIRQ(MEM2MEM_IRQn);
	} else {
		hri_mem2mem_write_PTCR_reg(MEM2MEM, MEM2MEM_PTCR_TXTDIS | MEM2MEM_PTCR_RXTDIS);
	}

	return ERR_NONE;
}

int32_t _dma_get_channel_resource(struct _dma_resource **resource, const uint8_t channel)
{
	*resource = &_resources;
	/* SAMG MEM2MEM PDC Channel Number is 28 */
	(void)channel;

	return ERR_NONE;
}

/**
 * \internal MEM2MEM interrupt handler
 */
void MEM2MEM_Handler(void)
{
	if (hri_mem2mem_get_ISR_RXEND_bit(MEM2MEM) && (hri_mem2mem_read_TCR_reg(MEM2MEM) == 0)) {
		NVIC_DisableIRQ(MEM2MEM_IRQn);
		_resources.dma_cb.transfer_done(&_resources);
	}
}

#endif /* CONF_MEM2MEM_ENABLE */
