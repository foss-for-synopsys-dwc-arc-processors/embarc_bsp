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
 * @ingroup ARCV1_HAL_EXCEPTION_CPU ARCV1_HAL_EXCEPTION_INTERRUPT
 * @brief Public interface for configuring interrupts and exceptions
 */

#ifndef H_ARCV1_EXCEPTION
#define H_ARCV1_EXCEPTION

#include "arc/v1/arc_builtin.h"

#ifndef __ASSEMBLY__
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup ARCV1_HAL_EXCEPTION_CPU
 * @{
 */

/*!< number of CPU exceptions */
#define NUM_EXC_CPU     3

/*!< total number of interrupt and cpu exceptions, defined in arc_feature_config.h */
#ifndef NUM_EXC_ALL
#define NUM_EXC_ALL     16
#endif

#ifndef NUM_EXC_INT
#define NUM_EXC_INT     (NUM_EXC_ALL - NUM_EXC_CPU)
#endif


typedef struct {
#if ARC_FEATURE_CORE_700
	uint32_t erbta;
#endif
	/* r28 is sp, saved other place */
	uint32_t fp;    /* r27 */
	uint32_t gp;    /* r26 */

#if ARC_FEATURE_DSP || ARC_FEATURE_FPU || ARC_FEATURE_MPU_OPTION_NUM > 6
	/* accl and acch, common for mpy_option >6 and fpu_fma option */
	uint32_t r59;
	uint32_t r58;
#endif
	uint32_t r12;

	uint32_t r0, r1, r2, r3;

#ifndef ARC_FEATURE_RF16
	uint32_t r4, r5, r6, r7, r8, r9;
#endif

	uint32_t r10, r11;

	uint32_t blink; /* r31 */

	uint32_t lp_end, lp_start, lp_count;

	uint32_t ret;
	uint32_t status32;
} EMBARC_PACKED INT_EXC_FRAME_T;


typedef struct {
#ifndef ARC_FEATURE_RF16
	uint32_t r25;
	uint32_t r24;
	uint32_t r23;
	uint32_t r22;
	uint32_t r21;
	uint32_t r20;
	uint32_t r19;
	uint32_t r18;
	uint32_t r17;
	uint32_t r16;
#endif
	uint32_t r15;
	uint32_t r14;
	uint32_t r13;

} EMBARC_PACKED CALLEE_FRAME_T;

typedef struct {
	CALLEE_FRAME_T callee_regs;
	INT_EXC_FRAME_T exc_frame;
} EMBARC_PACKED PROCESSOR_FRAME_T;

#define ARC_PROCESSOR_FRAME_T_SIZE    (sizeof(PROCESSOR_FRAME_T) / sizeof(uint32_t))
#define ARC_INT_EXC_FRAME_T_SIZE      (sizeof(INT_EXC_FRAME_T) / sizeof(uint32_t))
#define ARC_CALLEE_FRAME_T_SIZE       (sizeof(CALLEE_FRAME_T) / sizeof(uint32_t))

/**
 * @fn void arc_vector_base_write(uint32_t vec_base)
 * @brief Write exception vector base
 * 
 * @param vec_base Target vector base
 */
Inline void arc_vector_base_write(uint32_t vec_base)
{
	arc_aux_write(AUX_INT_VECT_BASE, vec_base);
}

/**
 * @fn uint32_t arc_vector_base_read(void)
 * @brief Read current exception vector base
 * 
 * @return Exception vector base (uint32_t)
 */
Inline uint32_t arc_vector_base_read(void)
{
	return arc_aux_read(AUX_INT_VECT_BASE);
}
/** @}*/

/**
 * @addtogroup ARCV1_HAL_EXCEPTION_INTERRUPT
 * @{
 */
#define INT_PRI_MIN -2        /*!< the minimum interrupt priority */
#define INT_PRI_MAX -1        /*!< the maximum interrupt priority */


/* ARC 600 has no interrupt enable register
 * ARC 700 has interrupt enable register 
 */
/**
 * @fn void arc_int_disable(const uint32_t intno)
 * @brief Disable interrupt
 * 
 * @param intno Interrupt number
 */
Inline void arc_int_disable(const uint32_t intno)
{

}

/**
 * @fn void arc_int_enable(const uint32_t intno)
 * @brief Enable interrupt
 * 
 * @param intno Interrupt number
 */
Inline void arc_int_enable(const uint32_t intno)
{

}

/**
 * @fn uint32_t arc_int_enabled(const uint32_t intno)
 * @brief Check whether the specific interrupt is enabled
 * 
 * @param intno Interrupt number
 * @return 0 disabled, 1 enabled
 */
Inline uint32_t arc_int_enabled(const uint32_t intno)
{
	return 0;
}

/**
 * @fn uint32_t arc_int_ipm_get(void)
 * @brief Get interrupt priority masking threshold
 * 
 * @return Interrupt priority masking threshold, negative num
 */
Inline uint32_t arc_int_ipm_get(void)
{
	return ((arc_aux_read(AUX_STATUS32) >> 1) & 0x03);
}

/**
 * @fn void arc_int_ipm_set(uint32_t intpri)
 * @brief Set interrupt priority masking threshold
 * 
 * @param intpri Interrupt priority masking threshold, negative num
 */
Inline void arc_int_ipm_set(uint32_t intpri)
{

}

/* ARC compat only support 2 levels */
/**
 * @fn uint32_t arc_int_pri_get(const uint32_t intno)
 * @brief Get current interrupt priority masking threshold
 * 
 * @param intno Interrupt number
 */
Inline uint32_t arc_int_pri_get(const uint32_t intno)
{
	return ((arc_aux_read(AUX_IRQ_LEV) >> intno) & 0x1);
}

/**
 * @fn void arc_int_pri_set(const uint32_t intno, uint32_t intpri)
 * @brief Set interrupt priority
 *
 * @param intno Interrupt number
 * @param intpri Interrupt priority
 */
Inline void arc_int_pri_set(const uint32_t intno, uint32_t intpri)
{
	uint32_t val;

	intpri &= 0x1;
	val = arc_aux_read(AUX_IRQ_LEV) & (~(1 << intno));
	val = val | (intpri << intno);

	arc_aux_write(AUX_IRQ_LEV, val);
}

/**
 * @fn uint32_t arc_int_probe(const uint32_t intno) 
 * @brief Probe interrupt pending state
 *
 * @param intno Interrupt number
 * @returns 1 pending, 0 no pending, -1 error
 */
Inline uint32_t arc_int_probe(const uint32_t intno)
{
/* arc 600 does not support interrupt probe */
	return 0;
}

/**
 * @fn void arc_int_sw_trigger(const uint32_t intno)
 * @brief Trigger software interrupt
 *
 * @param intno Interrupt number
 */
Inline void arc_int_sw_trigger(const uint32_t intno)
{
	arc_aux_write(AUX_IRQ_HINT, intno);
}

/* arc 600 does not support level config
 * arc 700 supports level config
 */
/**
 * @fn void arc_int_level_config(const uint32_t intno, const uint32_t level)
 * @brief Configure interrupt request mode.
 *
 * @param intno Interrupt number
 * @param level 0-level triggered, 1-pluse triggered
 */
Inline void arc_int_level_config(const uint32_t intno, const uint32_t level)
{
}

/**
 * @fn uint32_t arc_int_level_get(const uint32_t intno)
 * @brief Get interrupt request mode
 *
 * @param intno Interrupt number
 * @return 0-level triggered, 1-pluse triggered
 */
Inline uint32_t arc_int_level_get(const uint32_t intno)
{
	return 0;
}

/**
 * @fn void arc_lock(void)
 * @brief Lock cpu to disable interrupts
 */
Inline void arc_lock(void)
{
	arc_clri();
}

/**
 * @fn void arc_unlock(void)
 * @brief Unlock cpu to enable interrupts
 */
Inline void arc_unlock(void)
{
	arc_seti(AUX_STATUS_MASK_IE);
}

/**
 * @fn uint32_t arc_locked(void)
 * @brief Check if cpu is locked
 *
 * @return 1 locked, 0 unlocked
 */
Inline uint32_t arc_locked(void)
{
	uint32_t v = arc_aux_read(AUX_STATUS32);

	if ((v & AUX_STATUS_MASK_IE) != 0) {
		return 0;
	} else {
		return 1;
	}
}

/**
 * @fn uint32_t arc_lock_save(void)
 * @brief Lock cpu and return status
 *
 * @return CPU status
 */
Inline uint32_t arc_lock_save(void)
{
	return arc_clri();
}

/**
 * @fn void arc_unlock_restore(const uint32_t status)
 * @brief Unlock cpu with the specific status
 *
 * @param status  CPU status saved by cpu_lock_save
 */
Inline void arc_unlock_restore(const uint32_t status)
{
	arc_seti(status);
}

/**
 * @fn uint32_t arc_int_active(void)
 * @brief Check if interrupt is active
 *
 * @return 1 active, 0 inactive
 */
Inline uint32_t arc_int_active(void)
{
	if ((arc_aux_read(AUX_IRQ_LV12) & AUX_IRQ_LV12_MASK)  == 0) {
		return 0;
	} else {
		return 1;
	}
}
/** @}*/

/**
 * @addtogroup ARCV1_HAL_EXCEPTION_CPU
 * @{
 */
/**
 * @typedef EXC_ENTRY_T
 * @brief Data type for exception entry
 */
typedef void (*EXC_ENTRY_T) (void);
/**
 * @typedef EXC_HANDLER_T
 * @brief Data type for exception handler
 */
typedef void (*EXC_HANDLER_T) (void *exc_frame);
/** @}*/

/**
 * @ingroup ARCV1_HAL_EXCEPTION_INTERRUPT
 * @typedef INT_HANDLER_T
 * @brief Data type for interrupt handler
 */
typedef void (*INT_HANDLER_T) (void *ptr);

extern EXC_ENTRY_T exc_entry_table[NUM_EXC_ALL];
extern EXC_HANDLER_T exc_int_handler_table[NUM_EXC_ALL];

/** @ingroup ARCV1_HAL_EXCEPTION_CPU
 * @{
 */
/**
 * @fn exc_entry_reset
 * @brief Reset entry
 */
extern void exc_entry_reset(void);
/**
 * @fn exc_entry_cpu
 * @brief Default CPU exception entry
 */
extern void exc_entry_cpu(void);

/**
 * @fn exc_entry_int
 * @brief Interrupt exception entry
 */
extern void exc_entry_int(void);
/** @}*/

/* exception related apis */
extern void exc_int_init(void);
extern int32_t exc_entry_install(const uint32_t excno, EXC_ENTRY_T entry);
extern EXC_ENTRY_T exc_entry_get(const uint32_t excno);
extern int32_t exc_handler_install(const uint32_t excno, EXC_HANDLER_T handler);
extern EXC_HANDLER_T exc_handler_get(const uint32_t excno);

/* interrupt related apis */
extern int32_t int_disable(const uint32_t intno);
extern int32_t int_enable(const uint32_t intno);
extern int32_t int_enabled(const uint32_t intno);
extern int32_t int_ipm_get(void);
extern int32_t int_ipm_set(int32_t intpri);
extern int32_t int_pri_get(const uint32_t intno);
extern int32_t int_pri_set(const uint32_t intno, int32_t intpri);
extern int32_t int_probe(const uint32_t intno);
extern int32_t int_sw_trigger(const uint32_t intno);
extern int32_t int_level_config(const uint32_t intno, const uint32_t level);
extern int32_t int_level_get(const uint32_t intno);
extern void cpu_lock(void);
extern void cpu_unlock(void);
extern uint32_t cpu_lock_save(void);
extern void cpu_unlock_restore(const uint32_t status);
extern int32_t int_handler_install(const uint32_t intno, INT_HANDLER_T handler);
extern INT_HANDLER_T int_handler_get(const uint32_t intno);

#ifdef __cplusplus
}
#endif
#endif  /* __ASSEMBLY__ */

#endif  /* H_ARCV1_EXCEPTION*/
