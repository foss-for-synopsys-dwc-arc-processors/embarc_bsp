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
 * @file
 * @ingroup	BOARD_EMSK_DRV_DW_UART_OBJ
 * @brief	Designware uart object instantiation for emsk
 */

/**
 * @addtogroup	BOARD_EMSK_DRV_DW_UART_OBJ
 * @{
 */
#ifndef H_DW_UART_OBJ
#define H_DW_UART_OBJ

#include "device/ip_hal/dev_uart.h"

/**
 * @name	DesignWare UART Object Number
 * @{
 */
#if defined(HW_VERSION) && (HW_VERSION > 11)
#define DW_UART_NUM (3) /*!< DesignWare UART valid number */
#else
#define DW_UART_NUM (2) /*!< DesignWare UART valid number */
#endif
/** @} end of name */

/**
 * @name	Designware UART Object ID Macros
 * @{
 */
#define DW_UART_0_ID    0       /*!< uart 0 id macro */
#define DW_UART_1_ID    1       /*!< uart 1 id macro */
#define DW_UART_2_ID    2       /*!< uart 2 id macro */
/** @} end of name */

/**
 * @name	Designware UART Object Control Macros
 * @{
 */
#define USE_DW_UART_0   1       /*!< enable use designware uart 0 */
#define USE_DW_UART_1   1       /*!< enable use designware uart 1 */
#if defined(HW_VERSION) && (HW_VERSION > 11)
#define USE_DW_UART_2   1       /*!< enable use designware uart 2 */
#endif

/** @} end of name */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* H_DW_UART_OBJ */
/** @}*/
