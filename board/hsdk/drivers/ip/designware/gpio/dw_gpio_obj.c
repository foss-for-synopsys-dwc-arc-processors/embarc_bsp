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
#include "dw_gpio_obj.h"

#include "hsdk/hsdk.h"
/*
 * Uncomment this to enable default
 * gpio bit handler output message
 * by uart
 */

#if (USE_CPU_DW_GPIO_PORT_A)
static DEV_GPIO cpu_port_a;
static DW_GPIO_PORT cpu_dw_gpio_port_a;
static DEV_GPIO_HANDLER cpu_dw_gpio_bit_handler_a[HSDK_CPU_GPIO_A_INT_MAX_COUNT];
static DW_GPIO_BIT_ISR cpu_dw_gpio_bit_isr_a = {
	HSDK_CPU_GPIO_A_INT_MAX_COUNT, cpu_dw_gpio_bit_handler_a
};

static int32_t cpu_porta_open(uint32_t dir)
{
	return dw_gpio_open(&cpu_port_a, dir);
}

static int32_t cpu_porta_close(void)
{
	return dw_gpio_close(&cpu_port_a);
}

static int32_t cpu_porta_control(uint32_t ctrl_cmd, void *param)
{
	uint32_t val32;
	uint32_t i;

	switch (ctrl_cmd) {
	case GPIO_CMD_ENA_BIT_INT:
		val32 = (uint32_t)param;
		for (i = 0; i < cpu_dw_gpio_bit_isr_a.int_bit_max_cnt; i++) {
			if ((1 << i) & val32) {
				int_enable(HSDC_GPIO0_ISR + i);
			}
		}
		break;
	case GPIO_CMD_DIS_BIT_INT:
		val32 = (uint32_t)param;
		for (i = 0; i < cpu_dw_gpio_bit_isr_a.int_bit_max_cnt; i++) {
			if ((1 << i) & val32) {
				int_disable(HSDC_GPIO0_ISR + i);
			}
		}
		break;
	default:
		break;
	}
	return dw_gpio_control(&cpu_port_a, ctrl_cmd, param);
}

static int32_t cpu_porta_write(uint32_t val, uint32_t mask)
{
	return dw_gpio_write(&cpu_port_a, val, mask);
}

static int32_t cpu_porta_read(uint32_t *val, uint32_t mask)
{
	return dw_gpio_read(&cpu_port_a, val, mask);
}

static void cpu_porta_isr(void *ptr)
{
	dw_gpio_isr_handler(&cpu_port_a, ptr);
}

static void cpu_porta_install(void)
{
	uint32_t i;
	DEV_GPIO_PTR port_ptr = &cpu_port_a;
	DEV_GPIO_INFO_PTR info_ptr = &(cpu_port_a.gpio_info);
	DW_GPIO_PORT_PTR dw_port_ptr = &(cpu_dw_gpio_port_a);

	info_ptr->gpio_ctrl = (void *)dw_port_ptr;
	info_ptr->opn_cnt = 0;
	info_ptr->method = 0;
	info_ptr->direction = 0;
	info_ptr->extra = 0;

	dw_port_ptr->no = DW_GPIO_PORT_A;
	dw_port_ptr->regs = (DW_GPIO_REG_PTR)(HSDC_GPIO_REGBASE);
	dw_port_ptr->valid_bit_mask = HSDK_CPU_GPIO_A_VALID_MASK;
	dw_port_ptr->intno = DW_GPIO_INVALID_INTNO; /* pass invalid interrupt number */
	dw_port_ptr->int_handler = cpu_porta_isr;

	for (i = 0; i < cpu_dw_gpio_bit_isr_a.int_bit_max_cnt; i++) {
		int_handler_install(HSDC_GPIO0_ISR + i, cpu_porta_isr);
		int_disable(HSDC_GPIO0_ISR + i);
		cpu_dw_gpio_bit_isr_a.int_bit_handler_ptr[i] = NULL;
	}
	dw_port_ptr->gpio_bit_isr = &cpu_dw_gpio_bit_isr_a;

	port_ptr->gpio_open = cpu_porta_open;
	port_ptr->gpio_close = cpu_porta_close;
	port_ptr->gpio_control = cpu_porta_control;
	port_ptr->gpio_write = cpu_porta_write;
	port_ptr->gpio_read = cpu_porta_read;
}
#endif

static void dw_gpio_all_install(void)
{
#if (USE_CPU_DW_GPIO_PORT_A)
	cpu_porta_install();
#endif
}

DEV_GPIO_PTR gpio_get_dev(int32_t gpio_id)
{
	static uint32_t install_flag = 0;

	/* intall device objects */
	if (install_flag == 0) {
		install_flag = 1;
		dw_gpio_all_install();
	}

	switch (gpio_id) {
#if (USE_CPU_DW_GPIO_PORT_A)
	case CPU_DW_GPIO_PORT_A: return &cpu_port_a;
#endif
	default:
		break;
	}
	return NULL;
}
