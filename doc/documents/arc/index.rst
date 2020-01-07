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

+-------------------------------------------+----------------------------------------------+
| File/Folder                               | Content                                      |
+-------------------------------------------+----------------------------------------------+
| arc.h, arc_em.h, arc_hs.h                 | Processor resources definition               |
+-------------------------------------------+----------------------------------------------+
| arc_feature_config.h                      | Processor resources interface                |
+-------------------------------------------+----------------------------------------------+
| arc_asm_common.h                          | Common macro definitions for assembly code   |
+-------------------------------------------+----------------------------------------------+
| arc_builtin.h                             | Compiler built-in and helper functions       |
+-------------------------------------------+----------------------------------------------+
| arc_exception.c, arc_exc_asm.s            | Exception and interrupt handling             |
+-------------------------------------------+----------------------------------------------+
| arc_startup.s                             | Common startup routine                       |
+-------------------------------------------+----------------------------------------------+
| arc_cxx_support.c                         | C++ constructor & destructor routines        |
+-------------------------------------------+----------------------------------------------+
| arc_cache.c, arc_cache.h                  | ARC cache module                             |
+-------------------------------------------+----------------------------------------------+
| arc_timer.c, arc_timer.h                  | ARC internal timer module                    |
+-------------------------------------------+----------------------------------------------+
| arc_udma.c, arc_udma.h, arc_udma_config.h | ARC uDMA module                              |
+-------------------------------------------+----------------------------------------------+
| arc_mpu.c, arc_mpu.h                      | ARC MPU module                               |
+-------------------------------------------+----------------------------------------------+
| arc_connect.c                             | ARConnect module support                     |
+-------------------------------------------+----------------------------------------------+
| arc_mp.c, arc_mp.h                        | Multi-processor support                      |
+-------------------------------------------+----------------------------------------------+
| arc_xy_agu.h                              | ARC XY memory support                        |
+-------------------------------------------+----------------------------------------------+
| arc_util.s                                | Other assembly utilities                     |
+-------------------------------------------+----------------------------------------------+
