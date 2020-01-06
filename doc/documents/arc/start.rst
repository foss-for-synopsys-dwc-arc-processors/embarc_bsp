.. _arc_hal_start:

Start up in embARC BSP
######################

The start-up in embARC BSP can be divided into two parts.

Processor level start up
::::::::::::::::::::::::

The processor level start up process is implemented in ``arc_startup.s``. The
program jumps to the ``board_main()`` function after the startup process,
which runs in three stages.

.. image:: /pic/startup.png
    :alt: processor-level start up
    :align: center

- Stage 1: Hardware Initialization

  * Initialize necessary status and registers.
  * Initialize system clock (if necessary, in user-defined ``hardware_init_hook``).
  * Initialize memory controller (if necessary, in user-defined ``hardware_init_hook``).

- Stage 2: C Runtime Initialization

  * Initialize the stack.
  * Copy section, e.g. data section, text section if necessary.
  * Clear Block Started by Symbol (BSS) section.

- Stage 3: Go to ``board_main()``

  * Early initialization of software (if necessary, in user-defined ``software_init_hook``).
  * Call arc_exc_init, or other initialization functions.
  * Jump to ``board_main()`` function.

Board level start up
::::::::::::::::::::

The board level start up process is implemented ``board.c`` with an entry of ``board_main``.

The following pre-defined work is done in ``board_main`` function:

* board-level hardware initialization in ``board_init``

* Library initialization

  * initialize the ``xprintf`` function to have a console output

* jump to ``main`` function.

.. Note:: User can undefine the macro ``EMBARC_USE_BOARD_MAIN`` to bypass the pre-defined board-level initialization and do customized initialization.