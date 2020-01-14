.. _arc_hal_res_udma:

uDMA
#####

The DMA controller is an optional high performance, low area/energy
consumption DMA engine for use in the ARC EM 2.0 cores.

The DMA controller supports the following features:

* 1 to 16 independent programmable DMA channels (number of channels is configurable)
* User-programmable prioritization scheme for all available channels
* Concurrent operation with the CPU
* Software/Hardware–triggered DMA transfers
* Two addressing modes
* Five data transfer modes (configurable down to one)
* Internal and external interrupt support

API Reference
*************

.. doxygengroup:: ARC_HAL_MISC_UDMA
   :project: embARC_bsp