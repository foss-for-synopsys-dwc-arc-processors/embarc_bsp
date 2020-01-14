.. _device_hal:

Devices
=======

Overview
########

In the root directory of embARC, the ``device`` folder contains the necessary software APIs
and implementations for common device IP and external peripheral drivers.
The device layer consists of the following components:

- **Device HAL**: a device hardware abstraction layer including UART (Universal Asynchronous
  Receiver/Transmitter), SPI (Serial Peripheral Interface), IIC (Inter-
  Integrated Circuit), I2S (Inter-IC Sound), GPIO (General Purpose Input Output) and SDIO (Secure
  Digital Input and Output).

- **IP Driver Implementation**: Based on the device HAL, the IP drivers
  include DesignWare IP implementations of UART, IIC, SPI, GPIO and
  SDIO devices and Designware ARC Subsystem IP implementation.

- **Peripheral Driver Implementation**: on-board peripheral driver implementations such as
  flash, ADC, sensors.

.. image:: /pic/embARC_device_hal.png
    :alt: embARC Device HAL
    :align: center


Device HAL
##########

The Device HAL provides abstraction for the following devices:

.. toctree::
   :maxdepth: 1

   gpio.rst
   i2c.rst
   i2s.rst
   spi.rst
   uart.rst
   sdio.rst
   trng.rst
   pwm_timer.rst


These \*.h files in ``device/inc`` and ``device/ip/up_hal/inc`` provide abstraction APIs and macros that require corresponding
implementations. embARC BSP provides the device implementations in
``device/ip/designware``, ``device/ip/subsystem``, ``device/peripheral``, and ``board/xxxx/drivers``.

Different device features are abstracted in the device HAL, such as UART, IIC,
and SPI. Object-oriented concepts are adopted to provide common device
operation APIs and device access APIs.

IP Drivers
##########

The IP drivers are placed in ``device/ip`` folder. Currently, the following
Designware IP drivers are supported:

* GPIO
* I2S
* I2C
* PWM_TIMER
* SDIO
* SPI
* TRNG
* UART

and the follong Designware ARC subsystem IP drivers are supported:

* GPIO
* UART
* I2C master
* SPI master
* I2S master

In the future, more Designware IP drivers will be added, e.g., USB, ethernet

Not limited to Designware IP drivers, other IP drivers can be easily supported which
can take Designware IP drivers as a reference.

Driver Instantiation
####################

The device drivers will be instantiated in board BSP based on specific hardware
information. Taking EMSK board as an example, its drivers' instantiation is located in
``board/emsk/drivers/ip/designware``. Different instantiations of same type driver will be
differentiated through ID.

There are 3 UART ports in EMSK, their instantiations locate in ``dw_uart_obj.c``.
ID allocations as well as other related definitions are in ``dw_uart_obj.h``.
