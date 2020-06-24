/* ------------------------------------------
 * Copyright (c) 2020, Synopsys, Inc. All rights reserved.

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
 * @ingroup ARCV1_HAL_CORE_COMM
 * @brief  Header file for common core definitions
 */

/**
 * @addtogroup ARCV1_HAL_CORE_COMM
 * @{
 */

#ifndef H_ARCV1_CORE
#define H_ARCV1_CORE

#include "arc/v1/arc_feature_config.h"

/**
 * @name exception number definitions
 * @{
 */

/* ARC exception number */
#define EXC_NO_RESET            (0)     /*!< reset vector, the entry of power up and reset */
#define EXC_NO_MEM_ERR          (1)     /*!< external memory bus error */
#define EXC_NO_INS_ERR          (2)     /*!< illegal instruction or illegal instruction sequence */

/** @} */

/**
 * @name exception vector offset
 * @{
 */
#define EXC_NO_TO_OFFSET(no)    (no << 2)

/* ARC exception vector offset */

/** @} */
#define AUX_STATUS              (0x0)  /*!< status register */
#define AUX_SEMAPHORE           (0x1)  /*!< inter-process/host semaphore register */
#define AUX_LP_START             (0x2)  /*!< loop start address */
#define AUX_LP_END               (0x3)  /*!< loop end address */
#define AUX_IDENTIY             (0x4)  /*!< identification register */
#define AUX_DEBUG               (0x5)  /*!< debug register */
#define AUX_PC                  (0x6)  /*!< program conter register */
#define AUX_STATUS32            (0xa)  /*!< status register */
#define AUX_STATUS32_L1         (0xb)  /*!< status register save for level 1 */
#define AUX_STATUS32_L2         (0xc)  /*!< status register save for level 2 */
#define AUX_BPU_FLUSH           (0xf)  /*!< flush the branch prediction unit */
#define AUX_IC_IVIC             (0x10) /*!< invalidate instruction cache */
#define AUX_IC_CTRL             (0x11) /*!< instruction cache control register */
#define AUX_IC_LIL              (0x13) /*!< lock instruction cache line */
#define AUX_LOCKLINE            (0x13)
#define AUX_DMC_CODE_RAM        (0x14)
#define AUX_TAG_ADDR_MASK       (0x15)
#define AUX_TAG_DATA_MASK       (0x16)
#define AUX_LINE_LENGTH_MASK    (0x17) /*!< master for line length counter */
#define AUX_LDST_RAM            (0x18) /*!< address of local store ram */
#define AUX_IC_IVIL             (0x19) /*!< invalidate instruction cache line */
#define AUX_UNLOCKLINE          (0x19) /*!< unlock line at this address */
#define AUX_IC_RAM_ADDR         (0x1a) /*!< instruction cache external access address */
#define AUX_IC_TAG              (0x1b) /*!< instruction cache tag access */
#define AUX_IC_WP               (0x1c) /*!< Way pointer access */
#define AUX_IC_DATA             (0x1d) /*!< Icache data ram access  */
#define AUX_SRAM_SEQ            (0x20) /*!< SRAM sequencer mode control NOTE: Not on the ARC700  */
#define AUX_TIMER0_LIMIT        (0x23) /*!< timer 0 limit value */
#define AUX_TIMER0_CTRL         (0x22) /*!< timer 0 control value */
#define AUX_TIMER0_CNT          (0x21) /*!< timer 0 count value */
#define AUX_TIMER1_LIMIT        (0x102) /*!< timer 1 limit value */
#define AUX_TIMER1_CTRL         (0x101) /*!< timer 1 control value */
#define AUX_TIMER1_CNT          (0x100) /*!< timer 1 count value */
#define AUX_PCPORT              (0x24) /*!< control for PC_SEL line */
#define AUX_INT_VECT_BASE       (0x25) /*!< interrupt vector base register */
#define AUX_IRQ_LV12            (0x43) /*!< Interrupt Level Status register */
#define AUX_DC_IVDC             (0x47) /*!< invalidate data cache */
#define AUX_DC_CTRL             (0x48) /*!< data cache control register */
#define AUX_DC_LDL              (0x49) /*!< lock data cache line */
#define AUX_DC_IVDL             (0x4a) /*!< invalidate data cache line */
#define AUX_DC_FLSH             (0x4b) /*!< flush data cache */
#define AUX_DC_FLDL             (0x4c) /*!< flush data line */
#define AUX_DC_STARTR           (0x4d) /*!< flush region start address */
#define AUX_DC_ENDR             (0x4e) /*!< flush region end address */
#define AUX_DC_RAM_ADDR         (0x58) /*!< data cache external access address */
#define AUX_DC_TAG              (0x59) /*!< data cache tag access */
#define AUX_DC_WP               (0x5a) /*!< data longword associated with dc_ram_addr */
#define AUX_DC_DATA             (0x5b) /*!< data cache data access */
#define AUX_DC_PTAG             (0x5c) /*!< data cache external access RAM address physical tag */

#define AUX_BCR_TIMERS          (0x75) /*!< build configuration for processor timers */

#define AUX_IRQ_LEV             (0x200) /*!< interrupt level programming register */
#define AUX_IRQ_HINT            (0x201) /*!< software interrupt trigger */

/* stack checking registers */
#define AUX_USTACK_TOP          (0x260)
#define AUX_USTACK_BASE         (0x261)

#define AUX_IRQ_CAUSE1          (0x40a) /*!< L1 interrupt cause register */
#define AUX_IRQ_CAUSE2          (0x40b) /*!< L2 interrupt cause register */


/* exception related aux regs */
#define AUX_ERRET               (0x400) /*!< exception return address */
#define AUX_ERBTA               (0x401) /*!< BTA saved on exception entry */
#define AUX_ERSTATUS            (0x402) /*!< STATUS32 saved on exception */
#define AUX_ECR                 (0x403) /*!< exception cause register */
#define AUX_EFA                 (0x404) /*!< exception fault address */

#define AUX_IRQ_ENABLE          (0x40c) /*!< interrupt enable register */
#define AUX_IRQ_TRIGGER         (0x40d) /*!< interrupt trigger: level or pulse */
#define AUX_BTA                 (0x412) /*!< branch target address */
#define AUX_BTA_L1              (0x413) /*!< L1 return branch target address */
#define AUX_BTA_L2              (0x414) /*!< L2 return branch target address */
#define AUX_IRQ_PENDING         (0x416) /*!< interrupt pending register */
#define AUX_IRQ_PLUSE_CLR       (0x415) /*!< interrupt pulse cancel register */


/* STATUS32 bit-field definition */
#define AUX_STATUS_BIT_HALT     (0)     /*!< halt bit */
#define AUX_STATUS_BIT_E1       (1)     /*!< E1 bit */
#define AUX_STATUS_BIT_E2       (2)     /*!< E2 bit */
#define AUX_STATUS_BIT_A1       (3)     /*!< E1 bit */
#define AUX_STATUS_BIT_A2       (4)     /*!< E2 bit */
#define AUX_STATUS_BIT_AE       (5)     /*!< processor is in an exception */
#define AUX_STATUS_BIT_DE       (6)     /*!< delayed branch is pending */
#define AUX_STATUS_BIT_U        (7)     /*!< user mode */
#define AUX_STATUS_BIT_L        (12)    /*!< zero-overhead loop enable */
#define AUX_STATUS_BIT_SC       (14)    /*!< stack check bit, also called SE bit */

/* masks correspond to STATUS32 bit-field */
#define AUX_STATUS_MASK_AE      (1 << AUX_STATUS_BIT_AE)
#define AUX_STATUS_MASK_HALT    (1 << AUX_STATUS_BIT_HALT)
#define AUX_STATUS_MASK_U       (1 << AUX_STATUS_BIT_U)
#define AUX_STATUS_MASK_L       (1 << AUX_STATUS_BIT_L)
#define AUX_STATUS_MASK_DE      (1 << AUX_STATUS_BIT_DE)
#define AUX_STATUS_MASK_E1      (1 << AUX_STATUS_BIT_E1)
#define AUX_STATUS_MASK_E2      (1 << AUX_STATUS_BIT_E2)
#define AUX_STATUS_MASK_A1      (1 << AUX_STATUS_BIT_A1)
#define AUX_STATUS_MASK_A2      (1 << AUX_STATUS_BIT_A2)
#define AUX_STATUS_MASK_IE      (AUX_STATUS_MASK_E1 | AUX_STATUS_MASK_E2)

#define STATUS32_RESET_VALUE 0

#define AUX_IRQ_LV12_MASK 0x3


#ifndef __ASSEMBLY__
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif  /* __ASSEMBLY__ */

#endif  /* H_ARCV1_CORE */

/**  @} */
