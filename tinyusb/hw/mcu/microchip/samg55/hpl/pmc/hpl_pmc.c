/**
 * \file
 *
 * \brief Power Management Controller register related functionality.
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
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

#include <hpl_init.h>
#include <hpl_pmc.h>
#include <hpl_pmc_config.h>

/**
 * \brief Initialize clock sources
 *
 * All clock sources are running when this function returns.
 */
static void _pmc_init_sources(void)
{
#if CONF_PMC_SLCK_CONFIG == 1
#if (CONF_PMC_XOSC32K_ENABLE && (CONF_PMC_SLCK_SRC == 1))
#if (CONF_PMC_XOSC32K_BYPASS)
	hri_supc_set_MR_reg(SUPC, (SUPC_MR_KEY_PASSWD | SUPC_MR_OSCBYPASS));
#endif
	hri_supc_write_CR_reg(SUPC, (SUPC_CR_KEY_PASSWD | SUPC_CR_XTALSEL));
	while (!(hri_supc_get_SR_OSCSEL_bit(SUPC) && hri_pmc_get_SR_OSCSELS_bit(PMC))) {
		/* Wait until the oscillator is ready */
	}
#endif
#endif

#if (CONF_PMC_MAINCK_ENABLE == 1)
	uint32_t data = 0;
#if (CONF_PMC_OSC24M_ENABLE && (CONF_PMC_MAINCK_SRC == 0))
	/* Enable Fast RC oscillator but DO NOT switch to RC now */
	hri_pmc_set_CKGR_MOR_reg(PMC, (CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCRCEN));
	while (!hri_pmc_get_SR_MOSCRCS_bit(PMC)) {
		/* Wait until the Fast RC to stabilize */
	}
	/* Change Fast RC oscillator frequency */
	data = hri_pmc_read_CKGR_MOR_reg(PMC) & ~CKGR_MOR_MOSCRCF_Msk;
	data |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCRCF(CONF_PMC_OSC24M_SELECTOR);
	hri_pmc_write_CKGR_MOR_reg(PMC, data);
	while (!hri_pmc_get_SR_MOSCRCS_bit(PMC)) {
		/* Wait until the Fast RC to stabilize */
	}
	/* Switch to Fast RC */
	data = hri_pmc_read_CKGR_MOR_reg(PMC) & ~CKGR_MOR_MOSCSEL;
	data |= CKGR_MOR_KEY_PASSWD;
	hri_pmc_write_CKGR_MOR_reg(PMC, data);
#endif

#if (CONF_PMC_XOSC20M_ENABLE && (CONF_PMC_MAINCK_SRC == 1))
#if (CONF_PMC_XOSC20M_BYPASS)
	/* Enable Main XTAL oscillator */
	data = hri_pmc_read_CKGR_MOR_reg(PMC) & ~CKGR_MOR_MOSCXTEN;
	data |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCXTBY | CKGR_MOR_MOSCSEL;
	hri_pmc_write_CKGR_MOR_reg(PMC, data);
#else
	data = hri_pmc_read_CKGR_MOR_reg(PMC) & ~CKGR_MOR_MOSCXTBY;
	data |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCXTEN | CKGR_MOR_MOSCXTST(CONF_PMC_XOSC20M_STARTUP_TIME);
	hri_pmc_write_CKGR_MOR_reg(PMC, data);
	while (!hri_pmc_get_SR_MOSCXTS_bit(PMC)) {
		/* Wait until the XTAL to stabilize */
	}
	hri_pmc_set_CKGR_MOR_reg(PMC, CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCSEL);
#endif
#endif
#endif /* CONF_PMC_MAINCK_ENABLE == 1 */

#if (CONF_PMC_PLLACK_ENABLE == 1)
	hri_pmc_write_CKGR_PLLAR_reg(PMC,
	                             CKGR_PLLAR_PLLAEN(1) | CKGR_PLLAR_MULA(CONF_PMC_PLLACK_MUL - 1)
	                                 | CKGR_PLLAR_PLLACOUNT(CONF_PMC_PLLACK_COUNTER));
	while (!hri_pmc_get_SR_LOCKA_bit(PMC)) {
		/* Wait until PLLACK stabilize */
	}
#endif

#if (CONF_PMC_PLLBCK_ENABLE == 1)
	hri_pmc_write_CKGR_PLLBR_reg(PMC,
	                             CKGR_PLLBR_PLLBEN(1) | CKGR_PLLBR_MULB(CONF_PMC_PLLBCK_MUL - 1)
	                                 | CKGR_PLLBR_PLLBCOUNT(CONF_PMC_PLLBCK_COUNTER));
	while (!hri_pmc_get_SR_LOCKB_bit(PMC)) {
		/* Wait until PLLBCK stabilize */
	}
#endif

#if (CONF_PMC_MAINCK_ENABLE == 1)
#if (CONF_PMC_CFDEN_ENABLE == 1)
	/* Enable main clock failure detection */
	hri_pmc_set_CKGR_MOR_CFDEN_bit(PMC);
#endif
#endif
}

/**
 * \brief Initialize master clock
 */
static void _pmc_init_master_clock(void)
{
#if ((CONF_PMC_MCK_ENABLE == 1))
#if (CONF_PMC_PLLACK_ENABLE == 1)
	hri_pmc_write_MCKR_PLLADIV2_bit(PMC, CONF_PMC_PLLACK_DIV);
	while (!hri_pmc_get_SR_MCKRDY_bit(PMC)) {
		/* Wait until master clock is ready */
	}
#endif

#if (CONF_PMC_PLLBCK_ENABLE == 1)
	hri_pmc_write_MCKR_PLLBDIV2_bit(PMC, CONF_PMC_PLLBCK_DIV);
	while (!hri_pmc_get_SR_MCKRDY_bit(PMC)) {
		/* Wait until master clock is ready */
	}
#endif

#if ((CONF_PMC_MCK_SRC == PMC_MCKR_CSS_SLOW_CLK_Val) || (CONF_PMC_MCK_SRC == PMC_MCKR_CSS_MAIN_CLK_Val))
	hri_pmc_write_MCKR_CSS_bf(PMC, CONF_PMC_MCK_SRC);
	while (!hri_pmc_get_SR_MCKRDY_bit(PMC)) {
		/* Wait until master clock is ready */
	}
	hri_pmc_write_MCKR_PRES_bf(PMC, CONF_PMC_MCK_PRESC);
	while (!hri_pmc_get_SR_MCKRDY_bit(PMC)) {
		/* Wait until master clock is ready */
	}
#elif ((CONF_PMC_MCK_SRC == PMC_MCKR_CSS_PLLA_CLK_Val) || (CONF_PMC_MCK_SRC == PMC_MCKR_CSS_PLLB_CLK_Val))
	hri_pmc_write_MCKR_PRES_bf(PMC, CONF_PMC_MCK_PRESC);
	while (!hri_pmc_get_SR_MCKRDY_bit(PMC)) {
		/* Wait until master clock is ready */
	}
	hri_pmc_write_MCKR_CSS_bf(PMC, CONF_PMC_MCK_SRC);
	while (!hri_pmc_get_SR_MCKRDY_bit(PMC)) {
		/* Wait until master clock is ready */
	}
#endif
#endif
}

/**
 * \brief Initializes programmable clock generators
 *
 * Programmable clock are running when this function returns.
 */
static void _pmc_init_program_clock(void)
{
#if (CONF_PMC_PCK0_ENABLE == 1)
	hri_pmc_write_PCK_reg(PMC, 0, PMC_PCK_CSS(CONF_PMC_PCK0_SRC) | PMC_PCK_PRES(CONF_PMC_PCK0_PRESC - 1));
	hri_pmc_set_SCSR_PCK0_bit(PMC);
	while (!hri_pmc_get_SR_PCKRDY0_bit(PMC)) {
		/* Wait until PCK0 clock is ready */
	}
#endif

#if (CONF_PMC_PCK1_ENABLE == 1)
	hri_pmc_write_PCK_reg(PMC, 1, PMC_PCK_CSS(CONF_PMC_PCK1_SRC) | PMC_PCK_PRES(CONF_PMC_PCK1_PRESC - 1));
	hri_pmc_set_SCSR_PCK1_bit(PMC);
	while (!hri_pmc_get_SR_PCKRDY1_bit(PMC)) {
		/* Wait until PCK1 clock is ready */
	}

#endif

#if (CONF_PMC_PCK2_ENABLE == 1)
	hri_pmc_write_PCK_reg(PMC, 2, PMC_PCK_CSS(CONF_PMC_PCK2_SRC) | PMC_PCK_PRES(CONF_PMC_PCK2_PRESC - 1));
	hri_pmc_set_SCSR_PCK2_bit(PMC);
	while (!hri_pmc_get_SR_PCKRDY2_bit(PMC)) {
		/* Wait until PCK2 clock is ready */
	}
#endif

#if (CONF_PMC_PCK3_ENABLE == 1)
	hri_pmc_write_PCK_reg(PMC, 3, PMC_PCK_CSS(CONF_PMC_PCK3_SRC) | PMC_PCK_PRES(CONF_PMC_PCK3_PRESC - 1));
	hri_pmc_set_SCSR_PCK3_bit(PMC);
	while (!hri_pmc_get_SR_PCKRDY3_bit(PMC)) {
		/* Wait until PCK3 clock is ready */
	}
#endif

#if (CONF_PMC_PCK4_ENABLE == 1)
	hri_pmc_write_PCK_reg(PMC, 4, PMC_PCK_CSS(CONF_PMC_PCK4_SRC) | PMC_PCK_PRES(CONF_PMC_PCK4_PRESC - 1));
	hri_pmc_set_SCSR_PCK4_bit(PMC);
	while (!hri_pmc_get_SR_PCKRDY4_bit(PMC)) {
		/* Wait until PCK4 clock is ready */
	}
#endif

#if (CONF_PMC_PCK5_ENABLE == 1)
	hri_pmc_write_PCK_reg(PMC, 5, PMC_PCK_CSS(CONF_PMC_PCK5_SRC) | PMC_PCK_PRES(CONF_PMC_PCK5_PRESC - 1));
	hri_pmc_set_SCSR_PCK5_bit(PMC);
	while (!hri_pmc_get_SR_PCKRDY5_bit(PMC)) {
		/* Wait until PCK5 clock is ready */
	}
#endif

#if (CONF_PMC_PCK6_ENABLE == 1)
	hri_pmc_write_PCK_reg(PMC, 6, PMC_PCK_CSS(CONF_PMC_PCK6_SRC) | PMC_PCK_PRES(CONF_PMC_PCK6_PRESC - 1));
	hri_pmc_set_SCSR_PCK6_bit(PMC);
	while (!hri_pmc_get_SR_PCKRDY6_bit(PMC)) {
		/* Wait until PCK6 clock is ready */
	}
#endif

#if (CONF_PMC_PCK7_ENABLE == 1)
	hri_pmc_write_PCK_reg(PMC, 7, PMC_PCK_CSS(CONF_PMC_PCK7_SRC) | PMC_PCK_PRES(CONF_PMC_PCK7_PRESC - 1));
	hri_pmc_set_SCSR_PCK7_bit(PMC);
	while (!hri_pmc_get_SR_PCKRDY7_bit(PMC)) {
		/* Wait until PCK7 clock is ready */
	}
#endif
}

/**
 * \brief Initializes USB FS clock generators
 *
 * USB FS clock are running when this function returns.
 */
static void _pmc_init_usb_clock(void)
{
#if (CONF_PMC_USB_CONFIG == 1)
	uint32_t data = CONF_PMC_USB_SRC ? PMC_USB_USBS : 0;
	data |= PMC_USB_USBDIV(CONF_PMC_USB_USBDIV - 1);
	hri_pmc_write_USB_reg(PMC, data);
	hri_pmc_set_SCSR_UDP_bit(PMC);
#endif
}

/**
 * \brief Initializes cortex M4 core clock
 *
 */
void _pmc_init(void)
{
	_pmc_init_sources();
	_pmc_init_master_clock();
	_pmc_init_program_clock();
	_pmc_init_usb_clock();
}
