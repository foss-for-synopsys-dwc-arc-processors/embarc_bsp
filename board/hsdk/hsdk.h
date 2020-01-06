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
#ifndef H_HSDK
#define H_HSDK

#include "arc/arc_hs.h"

#include "drivers/ip/designware/iic/dw_iic_obj.h"
#include "drivers/ip/designware/spi/dw_spi_obj.h"
#include "drivers/ip/designware/uart/dw_uart_obj.h"
#include "drivers/ip/designware/gpio/dw_gpio_obj.h"
#include "drivers/ip/designware/sdio/dw_sdio_obj.h"
#include "drivers/creg/creg_hsdc.h"
#include "drivers/cgu/cgu_hsdc.h"
#include "common/hsdk_io.h"
#include "device/dev_pinmux.h"

#include "hsdk_hardware.h"

/* common macros must be defined by all boards */

#define BOARD_CONSOLE_UART_ID       DW_UART_3_ID
#define BOARD_CONSOLE_UART_BAUD     UART_BAUDRATE_115200
#define BOARD_ADC_IIC_ID        DW_IIC_0_ID
#define BOARD_TEMP_SENSOR_IIC_ID    DW_IIC_0_ID

#define BOARD_SFLASH_SPI_ID     DW_SPI_0_ID

#define BOARD_SDCARD_SPI_LINE       HSDC_SPI_CS_0
#define BOARD_SFLASH_SPI_LINE       HSDC_SPI_CS_0

#ifndef BOARD_SPI_FREQ
#define BOARD_SPI_FREQ          (15000000)
#endif

#define BOARD_SYS_TIMER_ID      TIMER_0
#define BOARD_SYS_TIMER_INTNO       INTNO_TIMER0
#define BOARD_SYS_TIMER_HZ      (1000)

/** board timer count frequency (HZ) */
#define BOARD_SYS_TIMER_MS_HZ       (1000)
/** board timer count frequency convention based on the global timer counter */
#define BOARD_SYS_TIMER_MS_CONV     (BOARD_SYS_TIMER_MS_HZ / BOARD_SYS_TIMER_HZ)

#define BOARD_OS_TIMER_ID       TIMER_0
#define BOARD_OS_TIMER_INTNO        INTNO_TIMER0

#define BOARD_CPU_CLOCK         CLK_CPU
#define BOARD_DEV_CLOCK         CLK_BUS_APB

#define BOARD_LED_MASK          (0xff)
#define BOARD_LED_CNT           (4)

// Un-implemented Switch/Button functions and macros
#define BOARD_BTN_MASK          (0x0)
#define BOARD_BTN_CNT           (0)
#define BOARD_SWT_MASK          (0x0)
#define BOARD_SWT_CNT           (0)

#define switch_read(mask)       (0x0)
#define button_read(mask)       (0x0)

#endif  /* H_HSDK */
