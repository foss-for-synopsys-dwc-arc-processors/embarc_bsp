/* ------------------------------------------
 * Copyright (c) 2018, Synopsys, Inc. All rights reserved.

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
#ifndef H_DW_GPIO_OBJ
#define H_DW_GPIO_OBJ

#include "device/designware/dw_gpio.h"

/**
 * Designware GPIO Port Bank Control Macros
 */
#define USE_DW_GPIO_PORT_A      1
#define USE_DW_GPIO_PORT_B      1
#define USE_DW_GPIO_PORT_C      1
#define USE_DW_GPIO_PORT_D      1

/**
 * Designware GPIO Port Interrupt Available Number Macros
 */
#define EMSDP_GPIO_A_INT_MAX_COUNT  32
#define EMSDP_GPIO_B_INT_MAX_COUNT  0
#define EMSDP_GPIO_C_INT_MAX_COUNT  0
#define EMSDP_GPIO_D_INT_MAX_COUNT  0

/**
 * Designware GPIO Port Available Bits Macros
 */
#define EMSDP_GPIO_A_VALID_MASK     DW_GPIO_MASK_ALL
#define EMSDP_GPIO_B_VALID_MASK     DW_GPIO_MASK_ALL
#define EMSDP_GPIO_C_VALID_MASK     DW_GPIO_MASK_ALL
#define EMSDP_GPIO_D_VALID_MASK     DW_GPIO_MASK_ALL

#ifdef __cplusplus
extern "C" {
#endif

extern DEV_GPIO_PTR dw_gpio_get_dev(int32_t);

#ifdef __cplusplus
}
#endif

#endif /* H_DW_GPIO_OBJ*/
