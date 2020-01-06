.. _arc_hal_exc_int:

Exception and Interrupt Management
####################################

ARC exceptions and interrupts
:::::::::::::::::::::::::::::

|arc| are designed to allow exceptions to be taken and handled by
interrupt service routines in user or kernel mode. All exceptions and
interrupts cause an immediate switch into kernel mode. Interrupts are disabled
on entry to an exception handler.

Exceptions can be divided into two types: CPU exceptions and interrupt
exceptions. CPU exceptions are triggered by errors such as illegal
instructions, invalid or illegal memory accesses, and protection violations.
Most CPU exceptions are synchronous. Interrupt exceptions are triggered by
device interrupts and are always asynchronous.

Exception vectors are fetched in the instruction space (``ICCM or main memory,
but not DCCM``) with an alignment 1024 bytes. Every exception contains the
following information:

* Vector Name is a symbolic equivalent of the vector number.

* Vector Number is a unique eight-bit index in the exception or interrupt
  vector table. Vector Offset is an offset value calculated as four times the
  vector number (vector offset = 4*vector_number), which is used to determine
  the position of the appropriate exception or interrupt service routine.

* Cause Code is an eight-bit number to identify the exact cause of an exception.

* Parameter is an eight-bit field to pass a single parameter from the exception
  to the exception handler and identify exceptions with the same cause code.

For more details, see the ``ARCv2 ISA Programmer's Reference Manual (PRM)``.

Exception and interrupt processing framework
::::::::::::::::::::::::::::::::::::::::::::

A basic exception and interrupt processing framework is implemented in embARC BSP.
Through this framework, you can handle specific exceptions or interrupts by
installing the desired handlers. This can help you analyze the underlying
details of saving and operating registers.

For CPU exceptions and interrupts, entry(``exc_entry_cpu`` for CPU exception, ``exc_entry_int`` for interrupts) is called first, after some processing then the specific exception handler is
called in the entry. You can define your entry using ``exc_entry_install`` to replace the default behavior.

For interrupts, a standard interrupt processing model is shown in the picture below.

.. image:: /pic/interrupt.png
    :alt: interrupt and exception processing
    :align: center


Interrupts of this model have the following features:

* Devices request interrupts through their interrupt vectors and they can
  share the same interrupt vectors.

* An interrupt can be level-sensitive or pulse-sensitive.

* An interrupt can be enabled (unmasked) and disabled (masked).

* The priority of each interrupt can be programmed by software.

* Interrupt priority order is from INT_PRI_HIGH (highest, -1 default) to
  INT_PRI_MIN (lowest, -2 default).

* CPU lock and unlock are used to disable and enable interrupt processing.

For most Real-Time Operating Systems (RTOS), the task/process/thread priority
is a positive number and starts from 1 (the highest priority).

Negative numbers are used to define a unified priority scheme in embARC BSP.
Priority 0 (highest priority) is always assigned to the OS scheduler. A
higher-priority task can preempt a lower-priority task. The OS scheduler can
preempt any other tasks. But interrupt handling tasks with negative numbers
cannot be scheduled or switched by the OS scheduler.

API Reference
*************

.. doxygengroup:: ARC_HAL_EXCEPTION_CPU
   :project: embARC_bsp