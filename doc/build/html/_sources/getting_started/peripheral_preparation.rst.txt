.. _peripheral_preparation:

Peripheral Preparation
======================

This is a quick manual helping you to connect your peripheral modules with your embARC boards.

MUX Controller Setting
######################
On most of embARC boards, pins are multiplexed for various usages: uart, i2c, spi, etc. One pin can not be accessed by different usage simultaneously, that's where MUX controller comes in.
We will take PMOD interface as an example to explain the setting method. Other interfaces (Andruino, MikroBUS, etc.) can take PMOD as a reference, and use the same method for the setting.

1. You need to find mux controller code at ``embarc_bsp/board/[board_type]/drivers/mux``.
[board_type] should be replaced to board type name, such as *emsk*, *hsdk* or *iotdk*.

2. If you are using EMSK, go to ``mux.c`` and find ``io_mux_init()`` function, you will see it calls ``set_pmod_mux()`` with MUX options as parameters.
MUX options are defined in mux.h and you can change them as you see fit.

For example, you want to connect your EMSK with two i2c sensor modules. By default setting, you only have PM2 as i2c interface.
So now you have to check mux.h or EMSK manual to see if it supports one more i2c interface.
Notice that there is a ``PM3_I2C_GPIO_D`` macro in ``mux.h`` meaning that PM3 supports i2c interface. Now all you need to do is to replace the default PM3 setting in ``set_pmod_mux()`` to ``PM3_I2C_GPIO_D``.
Now your code should be like this:

.. code-block:: c

	set_pmod_mux(PM1_UR_UART_0 | PM1_LR_SPI_S	\
				| PM2_I2C_HRI		\
				| PM3_I2C_GPIO_D	\
				| PM4_I2C_GPIO_D	\
				| PM5_UR_SPI_M1 | PM5_LR_GPIO_A	\
				| PM6_UR_SPI_M0 | PM6_LR_GPIO_A );

.. note:: Notice that ``UR`` means Upper Layer of Pmod interface and ``LR`` means Lower Layer of Pmod

3. If you are using HSDK, go to ``mux.c`` and find ``io_mux_init()`` function, you will find it calls ``creg_hsdc_set_gpio_mux()`` with parameter array ``gpio_mux_config`` as MUX options.
By default all pins are set to GPIO, other MUX options are defined in ``PINMUX_TYPE`` in ``embarc_bsp/device/inc/dev_pinmux.h``

4. If you are using IoTDK, go to ``mux.c`` and find ``int32_t  io_pmod_config(uint32_t pmod, uint32_t type, uint32_t config)`` function.
All three parameters should use definitions in ``embarc_bsp/device/inc/dev_pinmux.h``.

	* The first parameter can be chosen from ``PMOD_PORT`` (e.g. ``PMOD_A``, ``PMOD_B``, ``PMOD_C``), other inputs will be ignored.
	* The second parameter should be in ``PMOD_TYPE``, unsupported options will have no effect.
	* The third parameter should be ``IO_PINMUX_ENABLE`` or ``IO_PINMUX_DISABLE``, enabling or disabling the mux controller respectively.

5. If you are using EMSDP, go to ``mux.c`` and find ``io_mux_init()`` function, you will find it calls ``set_pmod_mux()`` with MUX options as parameters.
MUX options are defined in mux.h and you can change them as you see fit.

.. note:: In EMSDP, notice that ``CFG0`` means Upper Layer of Pmod interface and ``CFG1`` means Lower Layer of Pmod

.. note:: To learn what interface your board has, please go to :ref:`board_bsp`