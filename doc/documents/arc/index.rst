.. _arc_hal:

ARC Processors
==============

Overview
########

The ARC **Hardware Abstraction Layer** (HAL) (``embarc_bsp/arc`` folder) provides hardware abstraction for
|arc|. The following functionality is provided by the ARC HAL:

.. toctree::
   :maxdepth: 1

   start.rst
   exception_interrupt.rst
   build_in.rst
   resource.rst

Related files
#############

The files relevant to the ARC HAL are described in the table below.

+-------------------------------------------+--------------------------------------------+
| File/Folder                               | Content                                    |
+-------------------------------------------+--------------------------------------------+
| arc.h, arc_em.h, arc_hs.h                 | Processor resources definition             |
+-------------------------------------------+--------------------------------------------+
| arc_asm_common.h                          | Common macro definitions for assembly code |
+-------------------------------------------+--------------------------------------------+
| arc_builtin.h                             | Compiler built-in and helper functions     |
+-------------------------------------------+--------------------------------------------+
| arc_cache.c, arc_cache.h                  | ARC cache module                           |
+-------------------------------------------+--------------------------------------------+
| arc_exc_asm.s                             | Assembly part of exception handling        |
+-------------------------------------------+--------------------------------------------+
| arc_startup.s                             | Common startup routine                     |
+-------------------------------------------+--------------------------------------------+
| arc_timer.c, arc_timer.h                  | ARC internal timer module                  |
+-------------------------------------------+--------------------------------------------+
| arc_udma.c, arc_udma.h, arc_udma_config.h | ARC uDMA module                            |
+-------------------------------------------+--------------------------------------------+
| arc_mpu.c, arc_mpu.h                      | ARC MPU module                             |
+-------------------------------------------+--------------------------------------------+
