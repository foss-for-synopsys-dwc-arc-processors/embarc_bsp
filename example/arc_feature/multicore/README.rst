.. _example_arc_feature_smp:

ARC Symmetric Multi-Processor (SMP) Example
###########################################

Overview
********
   This example is designed to show how SMP works and is supported in |embarc|

Detailed Description
====================

* Extra Required Tools
      NO

 * Extra Required Peripherals
      NO

* Design Concept

     This example is designed to show how SMP works and is supported in |embarc|. Core 0 is the master
     core and will start other slave cores.  Cores will do simple inter-core communication through inter-core
     interrupt.

.. note::
      Hardware support: all |arc| based platform with multi arc processors configured

Building and Running
********************

To run this example, better to use |mwdt| as mdb has better debug support of multi-core.

Taking |hsdk| as example, the commands to run this example are as follows:

.. code-block:: console

    $ cd <embarc_root>/example/arc_feature/multicore
    $ make BOARD=hsdk TOOLCHAIN=mw mp_run

Sample Output
=============

.. code-block:: console

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

        embARC Build Time: Dec 26 2019, 15:32:03
        Compiler Version: Metaware, 4.2.1 Compatible Clang 6.0.1 (branches/release_60)
        core 0 starts to run
        core 0 in arc connect is 0
        core 1 starts to run
        core 1 in arc connect is 1
        core 0 delay 5 ticks
        core 1 receives int from core 0
        core 1 delay 9 ticks
        core 0 receives int from core 1
        core 0 delay 5 ticks
        core 1 receives int from core 0
