.. _arc_hal_res_timer:

Internal timers
###############

|arc| have two independent 32-bit timers and a 64-bit real-time
counter (RTC). Timer 0 and Timer 1 are identical in operation. The only
difference is that these timers are connected to different interrupts. Each
timer is optional with a fixed interrupt: interrupt 16 for timer 0 and
interrupt 17 for timer 1.

The internal timers are connected to a system clock signal that always runs
even when the ARC EM processor is in the SLEEP state. The timers can be used
to generate interrupt signals that wake the processor from the SLEEP state.
The processor timers automatically reset and restart after reaching the limit
value. The processor timers can be programmed to count the clock cycles only
if the processor is not halted. The processor timers can also be programmed to
generate an interrupt or a system reset if they reach the limit value. The
64-bit RTC cannot generate any interrupts. This timer is used to count the
clock cycles automatically.

embARC BSP provides interfaces for internal timers such as start, stop, poll, and read.

API Reference
*************

.. doxygengroup:: ARC_HAL_MISC_TIMER
   :project: embARC_bsp