/* ------------------------------------------
 * Copyright (c) 2019, Synopsys, Inc. All rights reserved.

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
#ifndef H_ARCV1_MP
#define H_ARCV1_MP

/* ARC multi processors/cores related functions */
#include "arc/v1/arc_builtin.h"

#ifndef __ASSEMBLY__
#ifdef __cplusplus
extern "C" {
#endif

/* smp barrier */
#define arc_smp_mb()    arc_mb()

typedef struct {
	volatile uint32_t slock;
} ARC_SPINLOCK_T;

#define ARC_SPIN_LOCK_LOCKED    1
#define ARC_SPIN_LOCK_UNLOCKED  0

/**
 * @fn void arc_spinlock_get(ARC_SPINLOCK_T *lock)
 * @brief Get a spin lock
 *
 * @param lock Spin lock to get
 */
Inline void arc_spinlock_get(ARC_SPINLOCK_T *lock)
{
	lock->slock = arc_clri();
}

/**
 * @fn int32_t arc_spinlock_try(ARC_SPINLOCK_T *lock)
 * @brief Try to get a spinlock
 *
 * @param lock Spin lock to get
 * @return 0 failed, 1 success
 */
Inline int32_t arc_spinlock_try(ARC_SPINLOCK_T *lock)
{

	lock->slock = arc_clri();

	return 1;
}

/**
 * @fn void arc_spinlock_release(ARC_SPINLOCK_T *lock)
 * @brief release a spin lock
 *
 * @param lock Spin lock to release
 */
Inline void arc_spinlock_release(ARC_SPINLOCK_T *lock)
{
	arc_seti(lock->slock);
}

/* variables required by start up of multi-core */
extern volatile uint32_t arc_cpu_wake_flag;
extern volatile uint8_t *arc_cpu_sp;

extern void arc_start_slave_cpu(uint32_t cpu_num, uint8_t *stack, uint32_t sz,
				void (*fn)(uint32_t, void *), void *arg);
extern void arc_slave_start(uint32_t cpu_num);

#ifdef __cplusplus
}
#endif
#endif  /* __ASSEMBLY__ */

#endif  /* H_ARCV1_MP */
