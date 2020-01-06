.. _arc_hal_res_cache:

Cache
######

|arc| can be configured with both data cache (dcache) and
instruction cache (icache). The cache configuration can be selected as
desired. The cache can be controlled through specific auxiliary registers.

embARC provides unified interfaces to enable/disable, flush, invalidate, lock,
and unlock cache lines and to access cache-internal RAM.

API Reference
*************

.. doxygengroup:: ARC_HAL_MISC_CACHE
   :project: embARC_bsp