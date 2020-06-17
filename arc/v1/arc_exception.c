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
 * @ingroup ARC_HAL_EXCEPTION_CPU ARC_HAL_EXCEPTION_INTERRUPT
 * @brief ARC interrupt and exception handling
 */
#include "arc/arc_exception.h"
#include "arc/arc_cache.h"

#define  DBG_LESS
#include "embARC_debug.h"

/**
 * @addtogroup ARC_HAL_EXCEPTION_CPU
 * @{
 * @var EXC_ENTRY_T exc_entry_table
 * @brief exception entry table
 *
 * Install exception entry table to ARC_AUX_INT_VECT_BASE in startup.
 * According to ARCv2 ISA, vectors are fetched in instruction space and thus
 * may be present in ICCM, Instruction Cache, or
 * main memory accessed by instruction fetch logic.
 * So it is put into a specific section .vector.
 *
 * Please note that the exc_entry_table maybe cached in ARC. Some functions is
 * defined in .s files.
 *
 */

#ifdef CONFIG_ARC_EXCEPTION_DEBUG
static void dump_exception_info(uint32_t vector, uint32_t cause, uint32_t param)
{
	/* Names are exactly as they appear in Designware ARCv2 ISA
	 * Programmer's reference manual for easy searching
	 */
	switch (vector) {
	case EXC_NO_RESET:
		EMBARC_PRINTF("Reset");
		break;
	case EXC_NO_MEM_ERR:
		EMBARC_PRINTF("Memory Error");
		break;
	case EXC_NO_INS_ERR:
		EMBARC_PRINTF("Instruction Error");
		break;
	default:
		EMBARC_PRINTF("unknown exception vector");
		break;
	}

	EMBARC_PRINTF("\n");
}

#endif /* CONFIG_ARC_EXCEPTION_DEBUG */

/**
 * @ingroup ARC_HAL_EXCEPTION_CPU
 * @brief  Install default cpu exception handler
 * @param p_excinf Pointer to the exception frame
 */
static void exc_handler_default(void *p_excinf)
{
}

/**
 * @ingroup ARC_HAL_EXCEPTION_INTERRUPT
 * @brief  Register default interrupt handler
 * @param p_excinf	Information for interrupt handler
 */
static void int_handler_default(void *p_excinf)
{
#if ARC_FEATURE_CORE_700
	uint32_t int_cause_reg = 0;
	uint32_t level;

	level = arc_aux_read(AUX_IRQ_LV12);
	if (level & 0x2) {
		int_cause_reg = arc_aux_read(AUX_IRQ_CAUSE2);
	} else if (level & 0x1) {
		int_cause_reg = arc_aux_read(AUX_IRQ_CAUSE1);
	}
	
	EMBARC_PRINTF("default interrupt handler\r\n");
	dbg_printf(DBG_LESS_INFO, "last sp:0x%08x, icause:0x%08x\r\n", p_excinf, int_cause_reg);
#endif
	arc_kflag(1);
}

/**
 * @var EXC_HANDLER_T exc_int_handler_table
 * @brief CPU exception and interrupt exception handler table
 * called in exc_entry_default and exc_entry_int
 */
EXC_HANDLER_T exc_int_handler_table[NUM_EXC_ALL] = {
	[0 ... NUM_EXC_CPU - 1] = exc_handler_default,
	[NUM_EXC_CPU ... NUM_EXC_ALL - 1] = int_handler_default
};

/**
 * @endcond
 */
/**
 * @ingroup ARC_HAL_EXCEPTION_INTERRUPT
 * @brief  Initialize the exception and interrupt handling
 */
void exc_int_init(void)
{
	/* ARC 600's interrupt configuration is almost fixed */
}

/**
 * @ingroup ARC_HAL_EXCEPTION_CPU
 * @brief  Install a CPU exception entry
 * @param excno Exception number
 * @param entry Exception entry to install
 */
int32_t exc_entry_install(const uint32_t excno, EXC_ENTRY_T entry)
{
	return -1;
}

/**
 * @ingroup ARC_HAL_EXCEPTION_CPU
 * @brief  Get the installed CPU exception entry
 * @param excno Exception number
 * @return The installed CPU exception entry
 */
EXC_ENTRY_T exc_entry_get(const uint32_t excno)
{
	return NULL;
}

/**
 * @ingroup ARC_HAL_EXCEPTION_CPU
 * @brief  Install an exception handler
 * @param excno Exception number
 * @param handler The installed CPU exception handler
 */
int32_t exc_handler_install(const uint32_t excno, EXC_HANDLER_T handler)
{
	if (excno < NUM_EXC_ALL && handler != NULL) {
		exc_int_handler_table[excno] = handler;
		return 0;
	}

	return -1;
}

/**
 * @ingroup ARC_HAL_EXCEPTION_CPU
 * @brief Get the installed exception handler
 * @param excno Exception number
 * @return The installed exception handler or NULL
 */
EXC_HANDLER_T exc_handler_get(const uint32_t excno)
{
	if (excno < NUM_EXC_ALL) {
		return exc_int_handler_table[excno];
	}

	return NULL;
}

/**
 * @brief Disable interrupt
 *
 * @param intno Interrupt number
 */
int32_t int_disable(const uint32_t intno)
{
	return -1;
}

/**
 * @brief Enable interrupt
 *
 * @param intno Interrupt number
 */
int32_t int_enable(const uint32_t intno)
{
	return -1;
}

/**
 * @brief Get interrupt enable state
 *
 * @param intno Interrupt number
 * @return 0 disabled, 1 enabled, < 0 error
 */
int32_t int_enabled(const uint32_t intno)
{
	return -1;
}

/**
 * @brief Get interrupt priority masking threshold
 *
 * @returns Interrupt priority masking threshold, negative num
 */
int32_t int_ipm_get(void)
{
	return ((int32_t)arc_int_ipm_get() + INT_PRI_MIN);
}

/**
 * @brief Set interrupt priority masking threshold
 *
 * @param intpri Interrupt priority masking threshold
 */
int32_t int_ipm_set(int32_t intpri)
{
	if (intpri >= INT_PRI_MIN && intpri <= INT_PRI_MAX) {
		arc_int_ipm_set(intpri - INT_PRI_MIN);
		return 0;
	}

	return -1;
}

/**
 * @brief Get current interrupt priority masking threshold
 *
 * @param intno Interrupt number
 * @return  < 0 interrupt priority, 0 error
 */
int32_t int_pri_get(const uint32_t intno)
{
	if (intno >= NUM_EXC_CPU && intno < NUM_EXC_ALL) {
		return INT_PRI_MAX - (int32_t)arc_int_pri_get(intno);
	}

	return 0;
}

/**
 * @brief Set interrupt priority
 *
 * @param intno Interrupt number
 * @param intpri Interrupt priority
 * @return  < 0 error, 0 ok
 */
int32_t int_pri_set(const uint32_t intno, int32_t intpri)
{
	uint32_t status;

	if (intno >= NUM_EXC_CPU && intno < NUM_EXC_ALL) {
		status = cpu_lock_save();
		intpri = INT_PRI_MAX - intpri;
		arc_int_pri_set(intno, (uint32_t)intpri);
		cpu_unlock_restore(status);
		return 0;
	}
	return -1;
}

/**
 * @brief Probe interrupt pending state
 *
 * @param intno Interrupt number
 *
 * @returns 1 pending, 0 no pending, -1 error
 */
int32_t int_probe(const uint32_t intno)
{
	if (intno >= NUM_EXC_CPU && intno < NUM_EXC_ALL) {
		return arc_int_probe(intno);
	}
	return -1;
}

/**
 * @brief Trigger interrupt through software
 *
 * @param intno Interrupt number
 * @return 0 ok, -1 error
 */
int32_t int_sw_trigger(const uint32_t intno)
{
	if (intno >= NUM_EXC_CPU && intno < NUM_EXC_ALL) {
		arc_int_sw_trigger(intno);
		return 0;
	}
	return -1;
}

/**
 * @brief Configure interrupt trigger mode
 *
 * @param intno Interrupt number
 * @param level 0-level triggered, 1-pulse triggered
 * @return 0 ok, -1 error
 */
int32_t int_level_config(const uint32_t intno, const uint32_t level)
{
	if (intno >= NUM_EXC_CPU && intno < NUM_EXC_ALL) {
		arc_int_level_config(intno, level);
		return 0;
	}
	return -1;
}

/**
 * \brief Get interrupt request mode
 *
 * @param intno Interrupt number
 */
int32_t int_level_get(const uint32_t intno)
{
	if (intno >= NUM_EXC_CPU && intno < NUM_EXC_ALL) {
		return (int32_t)arc_int_level_get(intno);
	}
	return -1;
}

/**
 * @brief lock cpu, disable interrupts
 */
void cpu_lock(void)
{
	arc_lock();
}

/**
 * @brief Unlock cpu to enable interrupts
 */
void cpu_unlock(void)
{
	arc_unlock();
}

/**
 * @brief Lock cpu and return status
 *
 * @returns CPU status
 */
uint32_t cpu_lock_save(void)
{
	return arc_lock_save();
}

/**
 * @brief Unlock cpu with the specific status
 *
 * @param status  CPU status saved by cpu_lock_save
 */
void cpu_unlock_restore(const uint32_t status)
{
	arc_unlock_restore(status);
}

/**
 * @ingroup ARC_HAL_EXCEPTION_INTERRUPT
 * @brief Install interrupt handler
 * @param intno	Interrupt number
 * @param handler Interrupt handler
 */
int32_t int_handler_install(const uint32_t intno, INT_HANDLER_T handler)
{
	/*!< @todo parameter check ? */
	if (intno >= NUM_EXC_CPU) {
		return exc_handler_install(intno, handler);
	}

	return -1;
}

/**
 * @ingroup ARC_HAL_EXCEPTION_INTERRUPT
 * @brief Get the installed interrupt handler
 * @param intno Interrupt number
 * @return The installed interrupt handler or NULL
 */
INT_HANDLER_T int_handler_get(const uint32_t intno)
{
	if (intno >= NUM_EXC_CPU) {
		return exc_handler_get(intno);
	}

	return NULL;
}
/** @} end of group ARC_HAL_EXCEPTION_CPU */
