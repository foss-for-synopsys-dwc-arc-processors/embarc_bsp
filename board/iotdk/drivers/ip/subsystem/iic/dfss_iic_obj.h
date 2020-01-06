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

#ifndef H_DFSS_IIC_OBJ
#define H_DFSS_IIC_OBJ

#include "io_config.h"
#include "device/ip_hal/dev_iic.h"

#define DFSS_IIC_NUM        (3) /*!< DFSS IIC valid number */

#define DFSS_IIC_0_ID       0   /*!< IIC 0 ID macro */
#define DFSS_IIC_1_ID       1   /*!< IIC 1 ID macro */

#ifdef IO_I2C_MST0_PRESENT
#define USE_DFSS_IIC_0      1   /*!< enable use DFSS IIC 0 */
#else
#define USE_DFSS_IIC_0      0   /*!< enable use DFSS IIC 0 */
#endif

#ifdef IO_I2C_MST1_PRESENT
#define USE_DFSS_IIC_1      1   /*!< enable use DFSS IIC 1 */
#else
#define USE_DFSS_IIC_1      0   /*!< enable use DFSS IIC 1 */
#endif

#ifdef IO_I2C_MST2_PRESENT
#define USE_DFSS_IIC_2      1   /*!< enable use DFSS IIC 2 */
#else
#define USE_DFSS_IIC_2      0   /*!< enable use DFSS IIC 2 */
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* H_DFSS_IIC_OBJ */
