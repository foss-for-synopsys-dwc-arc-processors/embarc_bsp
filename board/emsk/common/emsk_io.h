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
 * @ingroup	BOARD_EMSK_DRV_GPIO
 * @brief	EMSK gpio implementation
 */
/**
 * @addtogroup	BOARD_EMSK_DRV_GPIO
 * @{
 */
#ifndef H_EMSK_GPIO
#define H_EMSK_GPIO

#include "device/ip_hal/dev_gpio.h"

/**
 * @name	EMSK LED Port Configuration
 * @{
 */
#define EMSK_LED_OFFSET     (0)
#define EMSK_LED_MASK       ((0x1ff) << EMSK_LED_OFFSET)
#define EMSK_LED_PORT       (DEV_GPIO_PORT_B)
#define EMSK_LED_DIR        ((0x1ff) << EMSK_LED_OFFSET)
/** @} end of name */

/**
 * @name	EMSK Switch Port Configuration
 * @{
 */
#define EMSK_SWITCH_OFFSET  (0)
#define EMSK_SWITCH_MASK    ((0xf) << EMSK_SWITCH_OFFSET)
#define EMSK_SWITCH_PORT    (DEV_GPIO_PORT_C)
#define EMSK_SWITCH_DIR     ((0x0) << EMSK_SWITCH_OFFSET)
/** @} end of name */

/**
 * @name	EMSK Button Port Configuration
 * @{
 */
#define EMSK_BUTTON_OFFSET  (0)
#define EMSK_BUTTON_MASK    ((0x7) << EMSK_BUTTON_OFFSET)
#define EMSK_BUTTON_PORT    (DEV_GPIO_PORT_A)
#define EMSK_BUTTON_DIR     ((0x0) << EMSK_BUTTON_OFFSET)
/** @} end of name */

#ifdef __cplusplus
extern "C" {
#endif

extern void emsk_led_init(void);
extern void emsk_button_init(void);
extern void emsk_switch_init(void);
extern void emsk_io_init(void);
extern void led_write(uint32_t led_val, uint32_t mask);
extern uint32_t led_read(uint32_t mask);
extern void led_toggle(uint32_t mask);
extern uint32_t switch_read(uint32_t mask);
extern uint32_t button_read(uint32_t mask);

#ifdef __cplusplus
}
#endif

#endif /* H_EMSK_GPIO */

/** @} end of group BOARD_EMSK_DRV_GPIO */