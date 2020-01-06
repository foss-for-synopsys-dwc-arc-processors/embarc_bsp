/* ------------------------------------------
 * Copyright (c) 2017, Synopsys, Inc. All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * 1) Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.

 * 2) Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.

 * 3) Neither the name of the Synopsys, Inc., nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
   --------------------------------------------- */
/**
 *
 * @file
 * @ingroup	BOARD_EMSK_COMMON_INIT
 * @brief	emsk hardware resource definitions
 */

/**
 * @addtogroup BOARD_EMSK_COMMON_INIT
 * @{
 */
#ifndef H_EMSK_HARDWARE
#define H_EMSK_HARDWARE

#include "arc/arc_feature_config.h"

/** CPU Clock Frequency definition */
#if defined(BOARD_CPU_FREQ)
/*!< Get cpu clock frequency definition from build system */
	#define CLK_CPU         (BOARD_CPU_FREQ)
#elif defined(ARC_FEATURE_CPU_CLOCK_FREQ)
/*!< Get cpu clock frequency definition from tcf file */
	#define CLK_CPU         (ARC_FEATURE_CPU_CLOCK_FREQ)
#else
/*!< Default cpu clock frequency */
	#define CLK_CPU         (30000000)
#endif

/** Peripheral Bus Reference Clock definition */
#ifdef BOARD_DEV_FREQ
/*!< Get peripheral bus reference clock defintion from build system */
	#define CLK_BUS_APB     (BOARD_DEV_FREQ)
#else
/*!< Default peripheral bus reference clock defintion */
	#define CLK_BUS_APB     (50000000U)
#endif

/* Device Register Base Address */
#define REL_REGBASE_PINMUX      (0x00000000U)           /*!< PINMUX */
#define REL_REGBASE_SPI_MST_CS_CTRL (0x00000014U)       /*!< SPI Master Select Ctrl */
#define REL_REGBASE_GPIO0       (0x00002000U)           /*!< GPIO 0 Onboard */
#define REL_REGBASE_TIMERS      (0x00003000U)           /*!< DW TIMER */
#define REL_REGBASE_I2C0        (0x00004000U)           /*!< I2C 0 */
#define REL_REGBASE_I2C1        (0x00005000U)           /*!< I2C 1 */
#define REL_REGBASE_SPI0        (0x00006000U)           /*!< SPI Master  */
#define REL_REGBASE_SPI1        (0x00007000U)           /*!< SPI Slave   */
#define REL_REGBASE_UART0       (0x00008000U)           /*!< UART0 is connected to PMOD */
#define REL_REGBASE_UART1       (0x00009000U)           /*!< UART1 is USB-UART， use UART1 as default */
#define REL_REGBASE_UART2       (0x0000A000U)           /*!< UART2 */
#define REL_REGBASE_WDT         (0x0000B000U)           /*!< WDT  */
#define REL_REGBASE_I2S_MASTER_IN   (0x0000C000U)       /*!< I2S Master In  */
#define REL_REGBASE_I2S_MASTER_OUT  (0x0000D000U)       /*!< I2S Master Out  */
#define REL_REGBASE_GMAC        (0x0000E000U)           /*!< GMAC  */

/* Interrupt Connection */
#define INTNO_GPIO          22          /*!< GPIO controller */
#define INTNO_I2C0          23          /*!< I2C_0 controller */
#define INTNO_I2C1          24          /*!< I2C_1 controller */
#define INTNO_SPI_MASTER        25      /*!< SPI Master controller */
#define INTNO_SPI_SLAVE         26      /*!< SPI Slave controller */
#define INTNO_UART0         27          /*!< UART0 */
#define INTNO_UART1         28          /*!< UART1 */
#define INTNO_UART2         29          /*!< UART2 */
#define INTNO_DW_WDT            30      /*!< WDT */
#define INTNO_DW_TMR0           31      /*!< DW Timer 0 */
#define INTNO_DW_TMR1           32      /*!< DW Timer 1 */
#define INTNO_I2S_Master_In     33      /*!< I2S Master In */
#define INTNO_I2S_Master_Out        34  /*!< I2S Master Out */
#define INTNO_GMAC          35          /*!< GMAC */

/* SPI Mater Signals Usage */
#define EMSK_SPI_LINE_0         0               /*!< CS0 -- Pmod 6 pin1 */
#define EMSK_SPI_LINE_1         1               /*!< CS1 -- Pmod 5 pin1 or Pmod 6 pin 7 */
#define EMSK_SPI_LINE_2         2               /*!< CS2 -- Pmod 6 pin8 */
#define EMSK_SPI_LINE_SDCARD        3           /*!< CS3 -- On-board SD card  */
#define EMSK_SPI_LINE_SPISLAVE      4           /*!< CS4 -- Internal SPI slave */
#define EMSK_SPI_LINE_SFLASH        5           /*!< CS5 -- On-board SPI Flash memory */

#endif  /* H_EMSK_HARDWARE */

/** @} end of group BOARD_EMSK_COMMON_INIT */