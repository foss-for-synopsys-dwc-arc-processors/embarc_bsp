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
#ifndef H_DFSS_GPIO_OBJ
#define H_DFSS_GPIO_OBJ

#include "io_config.h"
#include "device/ip_hal/dev_gpio.h"

#define DFSS_GPIO_0_ID          0       /* GPIO 0 ID macro (io_gpio0) */
#define DFSS_GPIO_1_ID          1       /* GPIO 1 ID macro (io_gpio1) */
#define DFSS_GPIO_2_ID          2       /* GPIO 2 ID macro (io_gpio2) */
#define DFSS_GPIO_3_ID          3       /* GPIO 3 ID macro (io_gpio3) */
#define DFSS_GPIO_8B0_ID        4       /* GPIO 8 ID macro (io_gpio_8b0) */
#define DFSS_GPIO_8B1_ID        5       /* GPIO 9 ID macro (io_gpio_8b1) */
#define DFSS_GPIO_8B2_ID        6       /* GPIO 10 ID macro (io_gpio_8b2) */
#define DFSS_GPIO_8B3_ID        7       /* GPIO 11 ID macro (io_gpio_8b3) */
#define DFSS_GPIO_4B0_ID        8       /* GPIO 4 ID macro (io_gpio_4b0) */
#define DFSS_GPIO_4B1_ID        9       /* GPIO 5 ID macro (io_gpio_4b1) */
#define DFSS_GPIO_4B2_ID        10      /* GPIO 6 ID macro (io_gpio_4b2) */
#define DFSS_GPIO_4B3_ID        11      /* GPIO 7 ID macro (io_gpio_4b3) */

#ifdef IO_GPIO_4B0_PRESENT
#define USE_DFSS_GPIO_4B0       1       /* enable use DFSS GPIO 4B 0 */
#else
#define USE_DFSS_GPIO_4B0       0       /* disable use DFSS GPIO 4B 0 */
#endif

#ifdef IO_GPIO_4B1_PRESENT
#define USE_DFSS_GPIO_4B1       1       /* enable use DFSS GPIO 4B 1 */
#else
#define USE_DFSS_GPIO_4B1       0       /* disable use DFSS GPIO 4B 1 */
#endif

#ifdef IO_GPIO_4B2_PRESENT
#define USE_DFSS_GPIO_4B2       1       /* enable use DFSS GPIO 4B 2 */
#else
#define USE_DFSS_GPIO_4B2       0       /* disable use DFSS GPIO 4B 2 */
#endif

#ifdef IO_GPIO_8B0_PRESENT
#define USE_DFSS_GPIO_8B0       1       /* enable use DFSS GPIO 8B 0 */
#else
#define USE_DFSS_GPIO_8B0       0       /* disable use DFSS GPIO 8B 0 */
#endif

#ifdef IO_GPIO_8B1_PRESENT
#define USE_DFSS_GPIO_8B1       1       /* enable use DFSS GPIO 8B 1 */
#else
#define USE_DFSS_GPIO_8B1       0       /* disable use DFSS GPIO 8B 1 */
#endif

#ifdef IO_GPIO_8B2_PRESENT
#define USE_DFSS_GPIO_8B2       1       /* enable use DFSS GPIO 8B 2 */
#else
#define USE_DFSS_GPIO_8B2       0       /* disable use DFSS GPIO 8B 2 */
#endif

#ifdef IO_GPIO_8B3_PRESENT
#define USE_DFSS_GPIO_8B3       1       /* enable use DFSS GPIO 8B 3 */
#else
#define USE_DFSS_GPIO_8B3       0       /* disable use DFSS GPIO 8B 3 */
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* H_DFSS_GPIO_OBJ*/