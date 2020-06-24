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
 * @ingroup ARC_HAL_EXCEPTION_CPU
 * @brief  Assembly part of exception and interrupt processing
 */

/**
 * @addtogroup ARC_HAL_EXCEPTION_CPU
 * @{
 */

/* function documentation */
/**
 * @fn void exc_entry_cpu(void)
 * @brief Default entry of CPU exceptions, such as TLB miss and swap.
 *
 * @fn void exc_entry_int(void)
 * @brief Normal interrupt exception entry.
 * In default, all interrupt exceptions are installed with normal entry.
 *
 */
/** }@ */

/** @cond EXCEPTION_ASM */

#define __ASSEMBLY__
#include "arc/arc.h"
#include "arc/arc_asm_common.h"

	.file "arc_exc_asm.s"

.macro ASM_MACRO1(VECTOR, entry)
	j   MACRO_ARG(entry)
.endm

.macro ASM_MACRO3(HANDLE_EXC, fun, dst, excno)
	.section .vector, "ax"
	.global MACRO_ARG(fun)
	.align 4
#if defined(__GNU__)
\fun :
#else
fun :
#endif
    push r0
	mov r0, MACRO_ARG(excno)
	j MACRO_ARG(dst)
.endm

	.section .vector, "ax"
	.global exc_entry_table
	.weak exe_entry_table
	.align 1024
exc_entry_table:
/* CPU exceptions */
VECTOR _start  			  /* 0x0, Reset Vector                 (0x0) */
#if ARC_FEATURE_CORE_600
VECTOR exc_entry_mem      /* 0x8, Mem error exception          (0x1) */
VECTOR exc_entry_instr    /* 0x10, Instruction error exception (0x2) */
/* ARC 600 has no icause reg, the int no must be given in entry */
VECTOR exc_entry_int3	/* irq 3 */
VECTOR exc_entry_int4	/* irq 4 */
VECTOR exc_entry_int5	/* irq 5 */
VECTOR exc_entry_int6	/* irq 6 */
VECTOR exc_entry_int7	/* irq 7 */
VECTOR exc_entry_int8	/* irq 8 */
VECTOR exc_entry_int9	/* irq 9 */
VECTOR exc_entry_int10	/* irq 10 */
VECTOR exc_entry_int11	/* irq 11 */
VECTOR exc_entry_int12	/* irq 12 */
VECTOR exc_entry_int13	/* irq 13 */
VECTOR exc_entry_int14	/* irq 14 */
VECTOR exc_entry_int15	/* irq 15 */
#if NUM_EXC_ALL > 16
VECTOR exc_entry_int16	/* irq 16 */
VECTOR exc_entry_int17	/* irq 17 */
VECTOR exc_entry_int18	/* irq 18 */
VECTOR exc_entry_int19	/* irq 19 */
VECTOR exc_entry_int20	/* irq 20 */
VECTOR exc_entry_int21	/* irq 21 */
VECTOR exc_entry_int22	/* irq 22 */
VECTOR exc_entry_int23	/* irq 23 */
VECTOR exc_entry_int24	/* irq 24 */
VECTOR exc_entry_int25	/* irq 25 */
VECTOR exc_entry_int26	/* irq 26 */
VECTOR exc_entry_int27	/* irq 27 */
VECTOR exc_entry_int28	/* irq 28 */
VECTOR exc_entry_int29	/* irq 29 */
VECTOR exc_entry_int30	/* irq 30 */
VECTOR exc_entry_int31	/* irq 31 */
#endif

HANDLE_EXC exc_entry_mem, exc_entry_cpu, 1
HANDLE_EXC exc_entry_instr, exc_entry_cpu, 2
HANDLE_EXC exc_entry_int3, exc_entry_int, 3
HANDLE_EXC exc_entry_int4, exc_entry_int, 4
HANDLE_EXC exc_entry_int5, exc_entry_int, 5
HANDLE_EXC exc_entry_int6, exc_entry_int, 6
HANDLE_EXC exc_entry_int7, exc_entry_int, 7
HANDLE_EXC exc_entry_int8, exc_entry_int, 8
HANDLE_EXC exc_entry_int9, exc_entry_int, 9
HANDLE_EXC exc_entry_int10, exc_entry_int, 10
HANDLE_EXC exc_entry_int11, exc_entry_int, 11
HANDLE_EXC exc_entry_int12, exc_entry_int, 12
HANDLE_EXC exc_entry_int13, exc_entry_int, 13
HANDLE_EXC exc_entry_int14, exc_entry_int, 14
HANDLE_EXC exc_entry_int15, exc_entry_int, 15
#if NUM_EXC_ALL > 16
HANDLE_EXC exc_entry_int16, exc_entry_int, 16
HANDLE_EXC exc_entry_int17, exc_entry_int, 17
HANDLE_EXC exc_entry_int18, exc_entry_int, 18
HANDLE_EXC exc_entry_int19, exc_entry_int, 19
HANDLE_EXC exc_entry_int20, exc_entry_int, 20
HANDLE_EXC exc_entry_int21, exc_entry_int, 21
HANDLE_EXC exc_entry_int22, exc_entry_int, 22
HANDLE_EXC exc_entry_int23, exc_entry_int, 23
HANDLE_EXC exc_entry_int24, exc_entry_int, 24
HANDLE_EXC exc_entry_int25, exc_entry_int, 25
HANDLE_EXC exc_entry_int26, exc_entry_int, 26
HANDLE_EXC exc_entry_int27, exc_entry_int, 27
HANDLE_EXC exc_entry_int28, exc_entry_int, 28
HANDLE_EXC exc_entry_int29, exc_entry_int, 29
HANDLE_EXC exc_entry_int30, exc_entry_int, 30
HANDLE_EXC exc_entry_int31, exc_entry_int, 31
#endif

#elif ARC_FEATURE_CORE_700
VECTOR exc_entry_cpu    /* 0x8, Mem error exception          (0x1) */
VECTOR exc_entry_cpu    /* 0x10, Instruction error exception (0x2) */
/* interrupt entries */
VECTOR exc_entry_int	/* irq 3 */
VECTOR exc_entry_int	/* irq 4 */
VECTOR exc_entry_int	/* irq 5 */
VECTOR exc_entry_int	/* irq 6 */
VECTOR exc_entry_int	/* irq 7 */
VECTOR exc_entry_int	/* irq 8 */
VECTOR exc_entry_int	/* irq 9 */
VECTOR exc_entry_int	/* irq 10 */
VECTOR exc_entry_int	/* irq 11 */
VECTOR exc_entry_int	/* irq 12 */
VECTOR exc_entry_int	/* irq 13 */
VECTOR exc_entry_int	/* irq 14 */
VECTOR exc_entry_int	/* irq 15 */
VECTOR exc_entry_int	/* irq 16 */
VECTOR exc_entry_int	/* irq 17 */
VECTOR exc_entry_int	/* irq 18 */
VECTOR exc_entry_int	/* irq 19 */
VECTOR exc_entry_int	/* irq 20 */
VECTOR exc_entry_int	/* irq 21 */
VECTOR exc_entry_int	/* irq 22 */
VECTOR exc_entry_int	/* irq 23 */
VECTOR exc_entry_int	/* irq 24 */
VECTOR exc_entry_int	/* irq 25 */
VECTOR exc_entry_int	/* irq 26 */
VECTOR exc_entry_int	/* irq 27 */
VECTOR exc_entry_int	/* irq 28 */
VECTOR exc_entry_int	/* irq 29 */
VECTOR exc_entry_int	/* irq 30 */
VECTOR exc_entry_int	/* irq 31 */
VECTOR exc_entry_cpu    /* Machine check */
VECTOR exc_entry_cpu    /* TLBMissI */
VECTOR exc_entry_cpu    /* TLBMissD */
VECTOR exc_entry_cpu    /* TLBProtV */
VECTOR exc_entry_cpu    /* PrivilegeV */
VECTOR exc_entry_cpu    /* Trap */
#endif

/****** entry for cpu exception handling *******/
	.text
	.global exc_entry_cpu
	.weak exc_entry_cpu
	.align 4
exc_entry_cpu:

	EXCEPTION_PROLOGUE

/* find the exception cause */
#if ARC_FEATURE_CORE_700
	lr	r0, [AUX_ECR]
	lsr	r0, r0, 16
	bmsk	r0, r0, 7
#endif
	mov	r1, exc_int_handler_table
	ld.as	r2, [r1, r0]

/* jump to exception handler where interrupts are not allowed! */
	mov	r0, sp
	jl	[r2]
exc_return:

	EXCEPTION_EPILOGUE

#if ARC_FEATURE_CORE_600
	rtie ilink2
#else
	rtie
#endif

/****** entry for normal interrupt exception handling ******/
	.global exc_entry_int
	.weak exc_entry_int
	.align 4
exc_entry_int:
/* save scratch regs */
	INTERRUPT_PROLOGUE

#if ARC_FEATURE_CORE_700
/* critical area */
	lr	r0, [AUX_IRQ_CAUSE1]
#endif
	mov	r1, exc_int_handler_table
/* r2 = _kernel_exc_tbl + irqno *4 */
	ld.as	r2, [r1, r0]

/* for the case of software triggered interrupt */
	lr	r3, [AUX_IRQ_HINT]
	cmp	r3, r0
	bne.d	irq_hint_handled
	xor	r3, r3, r3
	sr	r3, [AUX_IRQ_HINT]
irq_hint_handled:

/* jump to interrupt handler */
	mov	r0, sp
	jl	[r2]
int_return:
	INTERRUPT_EPILOGUE
#if ARC_FEATURE_CORE_600
	rtie ilink1
#else
	rtie
#endif

/** @endcond */
