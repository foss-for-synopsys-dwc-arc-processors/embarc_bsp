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
 * @ingroup ARC_HAL_MISC
 * @brief Header file for arc feature configuration
 */

/**
 * @addtogroup ARC_HAL_MISC
 * @{
 */

#ifndef H_ARCV1_FEATURE_CONFIG
#define H_ARCV1_FEATURE_CONFIG

#ifdef EMBARC_TCF_GENERATED
#include "core_config.h"
#endif

/** ARC baseline instruction set version number */
#if !defined(ARC_FEATURE_ISA_VER)
#if defined(core_config_cir_identity_arcver)
#define ARC_FEATURE_ISA_VER         core_config_cir_identity_arcver
#else
#define ARC_FEATURE_ISA_VER         0x42
#endif
#endif


#define ARC_FEATURE_CORE_600 ((ARC_FEATURE_ISA_VER > 0x20) && (ARC_FEATURE_ISA_VER < 0x30))
#define ARC_FEATURE_CORE_700 ((ARC_FEATURE_ISA_VER > 0x30) && (ARC_FEATURE_ISA_VER < 0x40))

#if !defined(ARC_FEATURE_ARC_FAMILY)
#if defined(core_config_cir_identity_family)
#define ARC_FEATURE_ARC_FAMILY      core_config_cir_identity_family
#else
#define ARC_FEATURE_ARC_FAMILY      ARC_FEATURE_ARC_EM
#endif
#endif


#if !defined(ARC_FEATURE_ARC_CORE_VER)
#if defined(core_config_cir_identity_corever)
#define ARC_FEATURE_ARC_CORE_VER    core_config_cir_identity_corever
#else
#define ARC_FEATURE_ARC_CORE_VER    2
#endif
#endif


/** ARC CPU Clock Frequency in Hz unit */
#if !defined(ARC_FEATURE_CPU_CLOCK_FREQ)
#if defined(core_config_clock_speed)
#define ARC_FEATURE_CPU_CLOCK_FREQ  (core_config_clock_speed * 1000000)
#endif
#endif


/** ARC PC size */
#if !defined(ARC_FEATURE_PC_SIZE)
#if defined(core_config_pc_size)
#define ARC_FEATURE_PC_SIZE         core_config_pc_size
#else
#define ARC_FEATURE_PC_SIZE         32
#endif
#endif


/** ARC LPC size */
#if !defined(ARC_FEATURE_LPC_SIZE)
#if defined(core_config_lpc_size)
#define ARC_FEATURE_LPC_SIZE        core_config_lpc_size
#else
#define ARC_FEATURE_LPC_SIZE        32
#endif
#endif


/** ARC Addr size */
#if !defined(ARC_FEATURE_ADDR_SIZE)
#if defined(core_config_addr_size)
#define ARC_FEATURE_ADDR_SIZE       core_config_addr_size
#else
#define ARC_FEATURE_ADDR_SIZE       32
#endif
#endif


/** ARC Endian/Byte Order */
#define ARC_FEATURE_LITTLE_ENDIAN   1234
#define ARC_FEATURE_BIG_ENDIAN      4321

#if !defined(ARC_FEATURE_BYTE_ORDER)
#if defined(core_config_bcr_isa_config_b)
#if core_config_bcr_isa_config_b == 0
#define ARC_FEATURE_BYTE_ORDER      ARC_FEATURE_LITTLE_ENDIAN
#else
#define ARC_FEATURE_BYTE_ORDER      ARC_FEATURE_BIG_ENDIAN
#endif
#else
#define ARC_FEATURE_BYTE_ORDER      ARC_FEATURE_LITTLE_ENDIAN
#endif
#endif


/** Reduced register option, if enabled, ARC_FEATURE_RF16 will be defined */
#if !defined(ARC_FEATURE_RF16)
#if defined(core_config_bcr_rf_build_e) && core_config_bcr_rf_build_e == 1
#define ARC_FEATURE_RF16
#endif
#endif


/** Unaligned access option, if enabled, ARC_FEATURE_UNALIGNED will be defined */
#if !defined(ARC_FEATURE_UNALIGNED)
#if defined(core_config_unaligned) && core_config_unaligned == 1
#define ARC_FEATURE_UNALIGNED
#endif
#endif


/** Interrupt unit presence */
#if !defined(ARC_FEATURE_INTERRUPTS_PRESENT)
#if defined(core_config_interrupts_present)
#define ARC_FEATURE_INTERRUPTS_PRESENT  core_config_interrupts_present
#endif
#endif


/** The number of exceptions/interrupts */
#if !defined(NUM_EXC_ALL)
#if core_config_bcr_vecbase_ac_build_E == 1
#define NUM_EXC_ALL             (32)  /* 32 exceptions/interrupts */
#elif core_config_bcr_vecbase_ac_build_E == 2
#define NUM_EXC_ALL             (38)  /* 38 exceptions/interrupts */
#else
#define NUM_EXC_ALL             (16)  /* 16 exceptions/interrupts */
#endif
#endif


/** ICCM Presence, base address and size */
#if !defined(ARC_FEATURE_ICCM_PRESENT)
#if defined(core_config_iccm_present) && core_config_iccm_present == 1
#define ARC_FEATURE_ICCM_PRESENT    1
#define ARC_FEATURE_ICCM_BASE       core_config_iccm_base
#define ARC_FEATURE_ICCM_SIZE       core_config_iccm_size
#endif
#endif

/** DCCM Presence, base address and size */
#if !defined(ARC_FEATURE_DCCM_PRESENT)
#if defined(core_config_dccm_size)
#define ARC_FEATURE_DCCM_PRESENT    1
#define ARC_FEATURE_DCCM_BASE       core_config_dccm_base
#define ARC_FEATURE_DCCM_SIZE       core_config_dccm_size
#endif
#endif


/** Peripheral memory region(DMP) base address, if dmp configured, this macro will be defined as base address */
#if !defined(ARC_FEATURE_DMP_PERIPHERAL)
#if defined(core_config_cir_dmp_peripheral)
#define ARC_FEATURE_DMP_PERIPHERAL  core_config_cir_dmp_peripheral
#endif
#endif

/** MPU options */
#if !defined(ARC_FEATURE_MPU_PRESENT)
#if defined(core_config_mpu_present) && core_config_mpu_present == 1
#define ARC_FEATURE_MPU_PRESENT     1
#define ARC_FEATURE_MPU_VERSION     core_config_bcr_mpu_build_version
#define ARC_FEATURE_MPU_REGIONS     core_config_mpu_regions
#ifdef core_config_bcr_mpu_build_i
#define ARC_FEATURE_MPU_BUILD_I     core_config_bcr_mpu_build_i
#endif
#endif
#endif


/** Data Cache options */
#if !defined(ARC_FEATURE_DCACHE_PRESENT)
#if defined(core_config_dcache_present) && core_config_dcache_present == 1
#define ARC_FEATURE_DCACHE_PRESENT          1
#define ARC_FEATURE_DCACHE_BUILD            core_config_bcr_d_cache_build
#define ARC_FEATURE_DCACHE_BUILD_VERSION    core_config_bcr_d_cache_build_version
#define ARC_FEATURE_DCACHE_BUILD_ASSOC      core_config_bcr_d_cache_build_assoc
#define ARC_FEATURE_DCACHE_BUILD_CAPACITY   core_config_bcr_d_cache_build_capacity
#define ARC_FEATURE_DCACHE_BUILD_BSIZE      core_config_bcr_d_cache_build_bsize
#define ARC_FEATURE_DCACHE_BUILD_FL         core_config_bcr_d_cache_build_fl
#define ARC_FEATURE_DCACHE_BUILD_U          core_config_bcr_d_cache_build_u
#define ARC_FEATURE_DCACHE_SIZE             core_config_dcache_size
#define ARC_FEATURE_DCACHE_LINE_SIZE        core_config_dcache_line_size
#define ARC_FEATURE_DCACHE_WAYS             core_config_dcache_ways
#define ARC_FEATURE_DCACHE_FEATURE          core_config_dcache_feature
#endif
#endif


/** Instruction Cache options */
#if !defined(ARC_FEATURE_ICACHE_PRESENT)
#if defined(core_config_icache_present) && core_config_icache_present == 1
#define ARC_FEATURE_ICACHE_PRESENT          1
#define ARC_FEATURE_ICACHE_BUILD            core_config_bcr_i_cache_build
#define ARC_FEATURE_ICACHE_BUILD_VERSION    core_config_bcr_i_cache_build_version
#define ARC_FEATURE_ICACHE_BUILD_ASSOC      core_config_bcr_i_cache_build_assoc
#define ARC_FEATURE_ICACHE_BUILD_CAPACITY   core_config_bcr_i_cache_build_capacity
#define ARC_FEATURE_ICACHE_BUILD_BSIZE      core_config_bcr_i_cache_build_bsize
#define ARC_FEATURE_ICACHE_BUILD_FL         core_config_bcr_i_cache_build_fl
#define ARC_FEATURE_ICACHE_BUILD_D          core_config_bcr_i_cache_build_d
#define ARC_FEATURE_ICACHE_SIZE             core_config_icache_size
#define ARC_FEATURE_ICACHE_LINE_SIZE        core_config_icache_line_size
#define ARC_FEATURE_ICACHE_WAYS             core_config_icache_ways
#define ARC_FEATURE_ICACHE_FEATURE          core_config_icache_feature
#endif
#endif


/** ARC mpy option  */
#if !defined(ARC_FEATURE_MPU_OPTION_NUM)
#define ARC_FEATURE_MPU_OPTION_NUM  core_config_mpy_option_num
#endif

#if !defined(ARC_FEATURE_FPU_DSP_CONTEXT)
#define ARC_FEATURE_FPU_DSP_CONTEXT 1   /* whether to put FPU and DSP regs into the context */
#endif


/** ARC FPU options */
#if !defined(ARC_FEATURE_FPU)
#if core_config_bcr_fpu_build_sp || core_config_bcr_fpu_build_dp
#define ARC_FEATURE_FPU             1
#if core_config_bcr_fpu_build_da
#define ARC_FEATURE_FPU_DA          1
#endif
#endif
#endif


/** ARC DSP options */
#if !defined(ARC_FEATURE_DSP)
#if core_config_dsp1 || core_config_dsp2
#define ARC_FEATURE_DSP             1
#if core_config_dsp_complex
#define ARC_FEATURE_DSP_COMPLEX     1
#endif
#endif
#endif


/** ARC Stack check options */
#if !defined(ARC_FEATURE_STACK_CHECK)
#if core_config_stack_check
#define ARC_FEATURE_STACK_CHECK     1
#endif
#endif


/* ARC multi processors/cores related features */
#if  !defined(ARC_FEATURE_MP_NUM_CPUS)
#define ARC_FEATURE_MP_NUM_CPUS     1
#endif


#if !defined(ARC_FEATURE_CONNECT_PRESENT)
#if defined(core_config_connect_idu) && core_config_connect_idu > 1
#define ARC_FEATURE_CONNECT_PRESENT 1
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* H_ARCV1_FEATURE_CONFIG */

/** @} */
