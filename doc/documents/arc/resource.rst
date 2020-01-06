.. _arc_hal_res_def:

Resource Definitions
####################

The structure of resource definitions is
architecture->series->processor->board.

``arc.h`` includes the common resource definitions for the |arc|,
such as macros for exceptions and auxiliary register access.

``arc_em.h`` includes the common resource definitions for ARC EM Processors.

.. toctree::
   :maxdepth: 1

   resource/timer.rst
   resource/cache.rst
   resource/udma.rst
   resource/mpu.rst
