.. _example_freertos_kernel:

FreeRTOS kernel Demo
####################

Overview
********

 This example demostrates FreeRTOS system services. It also provides cycle measurements for benchmark reference.

Detailed Description
====================
 * Extra Required Tools

    NO

 * Extra Required Peripherals

    NO

 * Design Concept

    This example is designed to test board without any extra peripheral

 * Usage Manual

    Toggle all leds on board in 1s period

 * Extra Comments

    NO

Buidling and Running
********************

This example outputs to the console. It is supported by all platform. The commands
to run this example are as follows:

.. code-block:: console

    $ cd <embarc_root>/example/freertos_demo
    $ make BOARD=emsk BD_VER=11 CUR_CORE=arcem6 TOOLCHAIN=gnu run

If you do not have an EMSK development board, you can use the nSIM simulator
which have been installed in MetaWare IDE.

.. code-block:: console

    $ cd <embarc_root>/example/freertos_demo
    $ gmake BOARD=nsim BD_VER=1506 CUR_CORE=arcemfull TOOLCHAIN=mw run

.. note:: Make sure you have selected the correct configuration of EMSK via dipswitches and that you have reset the board (button above “R”) to confirme its configuration

If you wish to run ARC v1 series cores on nSIM simulator
which have been installed in MetaWare IDE.
As in example, core is specified to arc610d, other choices are arc605, arc710d

.. code-block:: console

    $ cd <embarc_root>/example/freertos_demo
    $ gmake BOARD=nsim CUR_CORE=arc610d TOOLCHAIN=mw_mcc run

.. note:: ARC v1 600 series (arc605, arc610d) does not support trap exception. Nest interrupt test would be skipped. Therefore in the demo int-> nest int cycle would be 0 and nest int -> int cycle would be (extra measurement cost + 1) cycles

Sample Output
=============

.. code-block:: console

    C:\embarc_bsp\example\freertos_kernel> gmake BOARD=nsim CUR_CORE=arc710d TOOLCHAIN=mw_mcc run
    "Download & Run obj_nsim_10/mw_mcc_arc710d/freertos_kernel_demo_mw_mcc_arc710d.elf"
    mdb -nooptions -nogoifmain -toggle=include_local_symbols=1 -nsim -off=binary_stdin -off=binary_stdout  -on=load_at_paddr -on=reset_upon_restart -off=flush_pipe -off=cr_for_more -OKN  @obj_nsim_10/mw_mcc_arc710d/embARC_generated/mdb.arg -run obj_nsim_10/mw_mcc_arc710d/freertos_kernel_demo_mw_mcc_arc710d.elf
    -----------------------------------------------------------
     ____                                _ ____
    |  _ \ _____      _____ _ __ ___  __| | __ ) _   _
    | |_) / _ \ \ /\ / / _ \ '__/ _ \/ _` |  _ \| | | |
    |  __/ (_) \ V  V /  __/ | |  __/ (_| | |_) | |_| |
    |_|   \___/ \_/\_/ \___|_|  \___|\__,_|____/ \__, |
                                                 |___/
                         _       _    ____   ____
           ___ _ __ ___ | |__   / \  |  _ \ / ___|
          / _ \ '_ ` _ \| '_ \ / _ \ | |_) | |
         |  __/ | | | | | |_) / ___ \|  _ <| |___
          \___|_| |_| |_|_.__/_/   \_\_| \_\\____|
    ------------------------------------------------------------

    embARC Build Time: Aug  5 2020, 10:31:22
    Compiler Version: Metaware, mcc

    Benchmark CPU Frequency: 1000000 Hz
    Benchmark will run 200 times, please wait about 400 ms

    Average benchmark result list as follows:
    extra measurement cost : 31 cycles
    task2     ->  task1    : 368 cycles
    task1     ->  int      : 82 cycles
    int       ->  nest int : 71 cycles
    nest int  ->  int      : 64 cycles
    int       ->  task1    : 161 cycles
    task1     ->  task2    : 285 cycles
    mux: tsk1 ->  tsk2     : 521 cycles
    sem: tsk1 ->  tsk2     : 396 cycles
    evt: tsk1 ->  tsk2     : 404 cycles
    dtq: tsk1 ->  tsk2     : 492 cycles

    The End of Demo
