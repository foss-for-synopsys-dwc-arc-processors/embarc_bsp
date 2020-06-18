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
 * @ingroup ARCV2_HAL_MISC
 * @brief common macro definitions for assembly file
 */
/** @cond ARCV2_HAL_ASM_COMMON */

#ifndef H_ARCV2_ASM_COMMON
#define H_ARCV2_ASM_COMMON

#include "arc/v1/arc.h"

#ifdef __ASSEMBLY__
/* the assembly macro definitions in ARC GNU and MWDT are
 * different, so need different processing
 */
#if defined(__GNU__)
#define MACRO_ARG(x) \ x
#define ASM_MACRO1(name, arg1) name arg1
#define ASM_MACRO2(name, arg1, arg2) name arg1, arg2
#define ASM_MACRO3(name, arg1, arg2, arg3) name, arg1, arg2, arg3
#define ASM_MACRO4(name, arg1, arg2, arg3, arg4) name, arg1, arg2, arg3, arg4
#else
#define MACRO_ARG(x) x
#define ASM_MACRO1(name, arg1) name, arg1
#define ASM_MACRO2(name, arg1, arg2) name, arg1, arg2
#define ASM_MACRO3(name, arg1, arg2, arg3) name, arg1, arg2, arg3
#define ASM_MACRO4(name, arg1, arg2, arg3, arg4) name, arg1, arg2, arg3, arg4
#endif


/* ARC 600 has no rtie instruction, so use a macro here */
#if ARC_FEATURE_CORE_600
.macro ASM_MACRO1(rtie, reg)
/* r0 is used to store into, now recover it */
      pop r0
      j.f [MACRO_ARG(reg)]
.endm
#endif


.macro ASM_MACRO1(PUSHAX, aux)
      lr r10, [MACRO_ARG(aux)]
      push r10
.endm


.macro ASM_MACRO1(POPAX, aux)
      pop r10
      sr r10, [MACRO_ARG(aux)]
.endm

/*--------------------------------------------------------------
* Helpers to save/restore callee-saved regs:
* used by several macros below
*-------------------------------------------------------------*/
.macro SAVE_CALLEE_REGS
      push r13
      push r14
      push r15

#ifndef ARC_FEATURE_RF16
      push r16
      push r17
      push r18
      push r19
      push r20
      push r21
      push r22
      push r23
      push r24
      push r25
#endif
.endm


.macro RESTORE_CALLEE_REGS
#ifndef ARC_FEATURE_RF16
      pop r25
      pop r24
      pop r23
      pop r22
      pop r21
      pop r20
      pop r19
      pop r18
      pop r17
      pop r16
#endif

      pop r15
      pop r14
      pop r13
.endm


.macro SAVE_R58_R59
.endm


.macro RESTORE_R58_R59
.endm


.macro SAVE_LP_REGS
      push r60
      PUSHAX AUX_LP_START
      PUSHAX AUX_LP_END
.endm


.macro RESTORE_LP_REGS
      POPAX AUX_LP_END
      POPAX AUX_LP_START
      pop r10
/* must not use the LP_COUNT register(r60) as the destination of multi-cycle instruction */
      mov r60, r10
.endm


.macro INTERRUPT_PROLOGUE
/* save r10 first, free up a register*/
      st.as r10, [sp, -8]
      PUSHAX AUX_STATUS32_L1
      push ilink1

      SAVE_LP_REGS

      push blink
      push r11
      sub sp, sp, 4 /* r10 is pushed before */
#ifndef ARC_FEATURE_RF16
      push r9
      push r8
      push r7
      push r6
      push r5
      push r4
#endif
      push r3
      push r2
      push r1
      push r0

      push r12

      SAVE_R58_R59
      push gp
      push fp
#if ARC_FEATURE_CORE_700
      PUSHAX AUX_BTA
#endif
.endm


.macro INTERRUPT_EPILOGUE
#if ARC_FEATURE_CORE_700
      POPAX AUX_BTA_L1
#endif
      pop fp
      pop gp

      RESTORE_R58_R59

      pop r12
      pop r0
      pop r1
      pop r2
      pop r3
#ifndef ARC_FEATURE_RF16
      pop r4
      pop r5
      pop r6
      pop r7
      pop r8
      pop r9
#endif
      add sp, sp, 4
      pop r11
      pop blink

      RESTORE_LP_REGS

      pop ilink1
      POPAX AUX_STATUS32_L1

/* restore r10 */
      ld.as r10, [sp, -8]
.endm


.macro EXCEPTION_PROLOGUE
/* save r10 first, free up a register*/
      st.as r10, [sp, -8]
#if ARC_FEATURE_CORE_600
      PUSHAX AUX_STATUS32_L2
      push ilink2
#elif ARC_FEATURE_CORE_700
      PUSHAX AUX_ERSTATUS
      PUSHAX AUX_ERRET
#endif

      SAVE_LP_REGS

      push blink
      push r11
      sub sp, sp, 4 /* r10 is pushed before */
#ifndef ARC_FEATURE_RF16
      push r9
      push r8
      push r7
      push r6
      push r5
      push r4
#endif
      push r3
      push r2
      push r1
      push r0

      push r12

      SAVE_R58_R59
      push gp
      push fp
#if ARC_FEATURE_CORE_700
      PUSHAX AUX_ERBTA
#endif
.endm

.macro EXCEPTION_EPILOGUE
#if ARC_FEATURE_CORE_700
      POPAX AUX_ERBTA
#endif
      pop fp
      pop gp

      RESTORE_R58_R59

      pop r12
      pop r0
      pop r1
      pop r2
      pop r3
#ifndef ARC_FEATURE_RF16
      pop r4
      pop r5
      pop r6
      pop r7
      pop r8
      pop r9
#endif
      add sp, sp, 4
      pop r11
      pop blink

      RESTORE_LP_REGS

#if ARC_FEATURE_CORE_600
      pop ilink2
      POPAX AUX_STATUS32_L2
#elif ARC_FEATURE_CORE_700
      POPAX AUX_ERRET
      POPAX AUX_ERSTATUS
#endif

/* restore r10 */
      ld.as r10, [sp, -8]
.endm

#endif  /* __ASSEMBLY__ */
#endif  /* H_ARCV1_ASM_COMMON */
/** @endcond */
