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
 * @ingroup	BOARD_EMSK_DRV_DW_IIC_OBJ
 * @brief	Designware iic object instantiation for emsk
 */

/**
 * @addtogroup	BOARD_EMSK_DRV_DW_IIC_OBJ
 * @{
 */
#ifndef H_DW_IIC_OBJ
#define H_DW_IIC_OBJ

#include "device/ip_hal/dev_iic.h"

/**
 * @name	DesignWare IIC Object Number
 * @{
 */
#if defined(HW_VERSION) && (HW_VERSION > 11)
#define DW_IIC_NUM      (2)     /*!< DesignWare IIC valid number */
#else
#define DW_IIC_NUM      (1)     /*!< DesignWare IIC valid number */
#endif
/** @} end of name */

/**
 * @name	Designware IIC Object ID Macros
 * @{
 */
#define DW_IIC_0_ID     0       /*!< iic 0 id macro */
#define DW_IIC_1_ID     1       /*!< iic 1 id macro */
/** @} end of name */

/**
 * @name	Designware IIC Object Control Macros
 * @{
 */
#define USE_DW_IIC_0        1   /*!< enable use designware iic 0 */
#if defined(HW_VERSION) && (HW_VERSION > 11)
#define USE_DW_IIC_1        1   /*!< enable use designware iic 1 */
#endif
/** @} end of name */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* H_DW_IIC_OBJ */

/** @} end of group BOARD_EMSK_IIC_OBJ */
