.. _arc_hal_mpu:

MPU
####

The ARCv2-based Memory Protection Unit (MPU) provides memory protection by dividing
the address space into regions associated with specific attributes such as
Read, Write, and Execute. If an attempt is made to access a region for which
an associated attribute is not permitted, the ARCv2-based processors raise a
Protection Violation exception, and this exception prevents the faulting
instruction from completing.

API Reference
*************

.. doxygengroup:: ARC_HAL_MISC_MPU
   :project: embARC_bsp