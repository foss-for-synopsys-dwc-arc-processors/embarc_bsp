.. _board_emsk:

ARC EM Starter Kit
==================

Introduction
------------

The DesignWare® ARC® EM Starter Kit (EMSK, emsk) enables rapid
software development, code porting, software debugging, and profiling for ARC
EM4, EM6 (EMSK 1.1), EM5D, EM7D, EM9D and EM11D (EMSK 2.3) processors.

.. Note::
	Caches are not integrated in EM5D and EM9D configurations. If program code runs in DDR memory, SPI and IIC devices should run at a slower frequency.
	EMSK 1.0 must be upgraded to EMSK 1.1 using EMSK 1.1's firmware, EMSK 2.0, 2.1 and 2.2 must be upgraded to EMSK 2.3 using EMSK 2.3's firmware.


The EMSK consists of a hardware platform and a software package, including
pre-installed FPGA images of different configurations of the ARC EM Processor
with peripherals.

The development board is based on a Xilinx Spartan-6 LX45 FPGA. It
supports hardware extensions using six 2x6 connectors supporting a total of 48
user I/O pins (plus power and ground pins) that can be used to connect
components such as sensors, actuators, memories, displays, buttons, switches,
and communication devices. A Digilent Pmod™ compatible extension board
containing a four-channel 12-bit A/D converter with an IIC interface and an AC
power adapter are included in the package.

.. image:: /pic/emsk_board.png
    :alt: EM Starter Kit Board
    :align: center


Usage
-----

EM core configurations
**********************

The FPGA board includes a SPI flash storage device pre-programmed with FPGA
images containing different configurations of DesignWare® ARC EM cores.

The FPGA image can be selected using the pins 1 and 2 of the SW1 switch on the
board:

.. image:: /pic/emsk_dipswitch.jpg
    :alt: EM Starter Kit DIP Switch
    :align: center

The following tables provide the details of supported EM Core configurations
for different suported versions of EMSK board.

- **EMSK 1.1**

+--------+-------+------------+----------------------------------------------------------------------------------------------------------+
| Bit 1  | Bit 2 | Core       |Configuration                                                                                             |
|        |       |            +-----+------+---------------------------+---------------------------+--------+--------------+-------------+
|        |       |            |ICCM | DCCM | Instruction Cache         | Data cache                |Timers  |Core Registers|Address Width|
+========+=======+============+=====+======+===========================+===========================+========+==============+=============+
| OFF    | OFF   | ARC_EM4    |128KB| 64KB | -                         | -                         |2       |32            |  32         |
+--------+-------+------------+-----+------+---------------------------+---------------------------+--------+--------------+-------------+
| ON     | OFF   |ARC_EM4_16CR|128KB| 64KB | -                         | -                         |1       |16            |  24         |
+--------+-------+------------+-----+------+---------------------------+---------------------------+--------+--------------+-------------+
| OFF    | ON    |ARC_EM6     |32KB | -    |32KB,4-way,Line Length 128 | 32KB,4-way,Line Length 128|2       |32            |  32         |
+--------+-------+------------+-----+------+---------------------------+---------------------------+--------+--------------+-------------+
| ON     | ON    |ARC_EM6_GP  |32KB | -    |16KB,2-way,Line Length 32  | 16KB,2-way,Line Length 32 |1       |32            |  32         |
+--------+-------+------------+-----+------+---------------------------+---------------------------+--------+--------------+-------------+

The system clock is 35 MHz in the ARC_EM4 and ARC_EM4_16CR configurations and 30 MHz in the ARC_EM6 and ARC_EM6_GP configurations. The peripheral clock is always 50 MHz.

- **EMSK 2.3**

+--------+-------+---------+-----------------------------------------------------------------------------------------------------------------------------------------------+
| Bit 1  | Bit 2 | Core    |Configuration                                                                                                                                  |
|        |       |         +-----+------+-----+-----------------+------------+--------+-----------+-------------+--------------------+--------------------------+----+-----+
|        |       |         |ICCM | DCCM | DDR2|Instruction Cache| Data cache |Timers  |XY         |Address Width| DSP                |FPU                       |MPU |Fmax |
+========+=======+=========+=====+======+=====+=================+============+========+===========+=============+====================+==========================+====+=====+
| OFF    | OFF   | ARC_EM7D|256KB| 128KB|128MB|16KB             | 16KB       |2       |-          |  32         |complex             |-                         |True|25MHz|
+--------+-------+---------+-----+------+-----+-----------------+------------+--------+-----------+-------------+--------------------+--------------------------+----+-----+
| ON     | OFF   |ARC_EM9D |256KB| 128KB|128MB|-                | -          |2       |DCCM+X+Y,8K|  32         |complex,itu,accshift|sigle precision-          |-   |20MHz|
+--------+-------+---------+-----+------+-----+-----------------+------------+--------+-----------+-------------+--------------------+--------------------------+----+-----+
| OFF    | ON    |ARC_EM11D|64KB | 64KB |128MB|16KB             | 16KB       |2       |DCCM+Y,8K  |  32         |complex,itu,accshift|sigle and double precision|-   |20MHz|
+--------+-------+---------+-----+------+-----+-----------------+------------+--------+-----------+-------------+--------------------+--------------------------+----+-----+
| ON     | ON    |Reserved |-    | -    |-    |-                | -          |-       |-          |  -          |-                   | -                        |-   |-    |
+--------+-------+---------+-----+------+-----+-----------------+------------+--------+-----------+-------------+--------------------+--------------------------+----+-----+

The select configuration is downloaded from the on-board SPI flash device automatically after power on or after you press the FPGA configure button located above the letter ``C`` pf the ARC logo on the baseboard.

.. note::
	After the FPGA is programmed, the DIP switches are available for user applications. They must be switched back to the position for the desired predefined FPGA image, before you press the FPGA configuration button and power the board up. The ARC EM4, ARC EM5 and ARC EM6 processors are subsets of ARC EM7D. So software may be built for ARC EM4, ARC EM5 and ARC EM6 processors but then run on the ARC EM7D.

Peripherals
***********

There are many peripheral devices available, such as SPI master, SPI slave,
IIC, UART, GPIO. External hardware interface devices can be connected to the
EMSK using Pmod Connectors. The Pmod connectors are controlled by Pmod mux
controller.

The peripheral memory mapping depends on the AHB address width. The
configuration *ARC_EM4_16CR* uses an address width of 24 bits. The other
configurations use an address width of 32 bits. The peripheral connections and
memory mappings for different supported versions of EMSK board are shown below:

1. Peripheral Devices Connection to Pmods

    - **EMSK 1.1**

        +--------+-----------------+---------------------------------------------------------------------------------------------------------------+
        | Pmod   | Pmod connectore | Peripherals                                                                                                   |
        |        |                 +--------------+------------------------------------------------------------------------------------------------+
        |        |                 | MUX option 0 | MUX option 1                                                                                   |
        +========+=================+==============+================================================================================================+
        | Pmod1  | J1              | GPIOs        |External SPI master + UART                                                                      |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod2  | J2              | GPIOs        |ARC EM control/status signals + I2C                                                             |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod3  | J3              | GPIOs        |GPIO + I2C                                                                                      |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod4  | J4              | GPIOs        |GPIO + I2C                                                                                      |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod5  | J5              | GPIOs        |External SPI slaves 1 and 2                                                                     |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod6  | J6              | GPIOs        |External SPI slaves 0 and CS outputs for all other SPI slaves + ARC EM control/status signals   |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod7  | J20             | GPIOs        |ARC EM control/status signals                                                                   |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+


        .. note::
            The internal SPI slaves is not available fro ARC_EM6 and ARC_EM6_GP configurations. Consequently, an external SPI master can't be connected to the Pmod1 connector for these configurations.


    - **EMSK 2.3**

        +--------+-----------------+---------------------------------------------------------------------------------------------------------------+
        | Pmod   | Pmod connectore | Peripherals                                                                                                   |
        |        |                 +--------------+------------------------------------------------------------------------------------------------+
        |        |                 | MUX option 0 | MUX option 1                                                                                   |
        +========+=================+==============+================================================================================================+
        | Pmod1  | J1              | GPIOs        |External SPI master + UART                                                                      |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod2  | J2              | GPIOs        |ARC EM control/status signals + I2C_0                                                           |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod3  | J3              | GPIOs        |Reserved                                                                                        |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod4  | J4              | GPIOs        |GPIO + I2C_1                                                                                    |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod5  | J5              | GPIOs        |External SPI slaves 1 + UART2                                                                   |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod6  | J6              | GPIOs        |External SPI slaves 0 and CS outputs for all other SPI slaves + ARC EM control/status signals   |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+
        | Pmod7  | J20             | GPIOs        |ARC EM control/status signals                                                                   |
        +--------+-----------------+--------------+------------------------------------------------------------------------------------------------+


2. Peripheral Memory Mapping


    - **EMSK 1.1**

        The peripheral memory mapping depending on the AHB address width. The configuration ARC_EM_16CR uses an address width of 24 bits. The other thress configurations use an address width of 32 bits.

        +---------------------+-------------------------+-------------------------+--------+
        | Name                | Address width: 32 bit   |  Address width: 24 bit  |  Size  |
        |                     +------------+------------+------------+------------+        |
        |                     |      Start | End        |      Start | End        |        |
        +=====================+============+============+============+============+========+
        | Pin Mux Controller  | 0xF0000000 | 0xF0000FFF |   0xF00000 |   0xF00FFF |4KB     |
        +---------------------+------------+------------+------------+------------+--------+
        | GPIO                | 0xF0002000 | 0xF0002FFF |   0xF02000 |   0xF02FFF |4KB     |
        +---------------------+------------+------------+------------+------------+--------+
        | I2C                 | 0xF0004000 | 0xF0004FFF |   0xF04000 |   0xF04FFF |4KB     |
        +---------------------+------------+------------+------------+------------+--------+
        | SPI Master          | 0xF0006000 | 0xF0006FFF |   0xF06000 |   0xF06FFF |4KB     |
        +---------------------+------------+------------+------------+------------+--------+
        | SPI Slave           | 0xF0007000 | 0xF0007FFF |   0xF07000 |   0xF07FFF |4KB     |
        +---------------------+------------+------------+------------+------------+--------+
        | UART0               | 0xF0008000 | 0xF0008FFF |   0xF08000 |   0xF08FFF |4KB     |
        +---------------------+------------+------------+------------+------------+--------+
        | UART1               | 0xF0009000 | 0xF0009FFF |   0xF09000 |   0xF09FFF |4KB     |
        +---------------------+------------+------------+------------+------------+--------+

    - **EMSK 2.3**


        +---------------------+-------------------------+--------+
        | Name                | Address width: 32 bit   |  Size  |
        |                     +------------+------------+        |
        |                     |      Start | End        |        |
        +=====================+============+============+========+
        |    CREG Controller  | 0xF0000000 | 0xF0000FFF |4KB     |
        +---------------------+------------+------------+--------+
        | GPIO                | 0xF0002000 | 0xF0002FFF |4KB     |
        +---------------------+------------+------------+--------+
        | Timer               | 0xF0003000 | 0xF0003FFF |4KB     |
        +---------------------+------------+------------+--------+
        | I2C_0               | 0xF0004000 | 0xF0004FFF |4KB     |
        +---------------------+------------+------------+--------+
        | I2C_1               | 0xF0005000 | 0xF0005FFF |4KB     |
        +---------------------+------------+------------+--------+
        | SPI Master          | 0xF0006000 | 0xF0006FFF |4KB     |
        +---------------------+------------+------------+--------+
        | SPI Slave           | 0xF0007000 | 0xF0007FFF |4KB     |
        +---------------------+------------+------------+--------+
        | UART0               | 0xF0008000 | 0xF0008FFF |4KB     |
        +---------------------+------------+------------+--------+
        | UART1               | 0xF0009000 | 0xF0009FFF |4KB     |
        +---------------------+------------+------------+--------+
        | UART2               | 0xF000A000 | 0xF000AFFF |4KB     |
        +---------------------+------------+------------+--------+
        | WDT                 | 0xF000B000 | 0xF000BFFF |4KB     |
        +---------------------+------------+------------+--------+
        | Reserved            | 0xF000C000 | 0xF000CFFF |4KB     |
        +---------------------+------------+------------+--------+
        | Reserved            | 0xF000D000 | 0xF000DFFF |4KB     |
        +---------------------+------------+------------+--------+
        | Reserved            | 0xF000F000 | 0xF000FFFF |8KB     |
        +---------------------+------------+------------+--------+


PMOD pins Definition
********************

The location of the pins on the PMOD connectors is shown:

.. image:: /pic/iotdk_pinout_diagram_of_pmod.png
    :alt: ARC EMSK Pinout Diagram of PMOD
    :align: center

=====  ============  ============       =====  ============  ============
POMD1(J1)                               POMD2(J2)
---------------------------------       ---------------------------------
Pins    CFG1         CFG2               Pin    CFG1          CFG2
=====  ============  ============       =====  ============  ============
1      Port C[8]     UART1_CTS          1      Port C[12]    run_req
2      Port C[9]     UART1_TXD          2      Port C[13]    run_ack
3      Port C[10]    UART1_RXD          3      Port C[14]    I2C0_SCL
4      Port C[11]    UART1_RTS          4      Port C[15]    I2C0_SDA
5      GND           GND                5      GND           GND
6      3V3           3V3                6      3V3           3V3
7      Port A[8]     SPI1_CS_N          7      Port A[12]    halt_req
8      Port A[9]     SPI1_MOSI          8      Port A[13]    halt_ack
9      Port A[10]    SPI1_MISO          9      Port A[14]    N.C
10     Port A[11]    SPI1_SCLK          10     Port A[15]    N.C
11     GND           GND                11     GND           GND
12     3V3           3V3                12     3V3           3V3
=====  ============  ============       =====  ============  ============

=====  ============  ============       =====  ============  ============
POMD3(J3)                               POMD4(J4)
---------------------------------       ---------------------------------
Pins    CFG1         CFG2               Pin    CFG1          CFG2
=====  ============  ============       =====  ============  ============
1      Port C[16]    N.C                1      Port C[20]    Port D[4]
2      Port C[17]    N.C                2      Port C[21]    Port D[5]
3      Port C[18]    N.C                3      Port C[22]    I2C1_SCL
4      Port C[19]    N.C                4      Port C[23]    i2C1_SDA
5      GND           GND                5      GND           GND
6      3V3           3V3                6      3V3           3V3
7      Port A[16]    N.C                7      Port A[20]    Port D[6]
8      Port A[17]    N.C                8      Port A[21]    Port D[7]
9      Port A[18]    N.C                9      Port A[22]    N.C
10     Port A[19]    N.C                10     Port A[23]    N.C
11     GND           GND                11     GND           GND
12     3V3           3V3                12     3V3           3V3
=====  ============  ============       =====  ============  ============

=====  ============  ============       =====  ============  ============
POMD5(J5)                               POMD6(J6)
---------------------------------       ---------------------------------
Pins    CFG1         CFG2               Pin    CFG1          CFG2
=====  ============  ============       =====  ============  ============
1      Port C[24]    SPI0_CS1_N         1      Port C[28]    SPI0_CS0_N
2      Port C[25]    SPI0_MOSI          2      Port C[29]    SPI0_MOSI
3      Port C[26]    SPI0_MISO          3      Port C[30]    SPI0_MISO
4      Port C[27]    SPI0_SCLK          4      Port C[31]    SPI0_SCLK
5      GND           GND                5      GND           GND
6      3V3           3V3                6      3V3           3V3
7      Port A[24]    UART2_CTS          7      Port A[28]    SPI0_CS1_N
8      Port A[25]    UART2_TXD          8      Port A[29]    SPI0_CS2_N
9      Port A[26]    UART2_RXD          9      Port A[30]    halt
10     Port A[27]    UART2_RTS          10     Port A[31]    sleep
11     GND           GND                11     GND           GND
12     3V3           3V3                12     3V3           3V3
=====  ============  ============       =====  ============  ============



Peripherals interrupts
**********************

Peripherals can generate interrupts to the CPU. The interrupt irq assignments
are as follows.

.. csv-table:: EMSK 1.1 - Interrupts Connections
   :header: Interrupt, Component
   :widths: 30,50

    irq_18,GPIO controllor
    irq_19,I2C controllor 
    irq_20,Reserved
    irq_21,SPI Master controllor
    irq_22,SPI Slave controllor
    irq_23,UART0
    irq_24,UART1

.. note::
    The SPI Slave controller is not present in the ARC_EM6 and ARC_EM6_GP configurations.

.. csv-table:: EMSK 2.0, 2.1 - Interrupts Connections
   :header: Interrupt, Component
   :widths: 30,50

    irq_18,GPIO controllor
    irq_19,I2C_0 controllor
    irq_20,I2C_1 controllor 
    irq_21,SPI Master controllor
    irq_22,SPI Slave controllor
    irq_23,UART0
    irq_24,UART1
    irq_25,UART2
    irq_26,WDT
    irq_27,DW Timer 0
    irq_28,DW Timer 1

.. csv-table:: EMSK 2.2 - Interrupts Connections
   :header: Interrupt, Component
   :widths: 30,50

    irq_22,GPIO controllor
    irq_23,I2C_0 controllor
    irq_24,I2C_1 controllor 
    irq_25,SPI Master controllor
    irq_26,SPI Slave controllor
    irq_27,UART0
    irq_28,UART1
    irq_29,UART2
    irq_30,WDT
    irq_31,DW Timer 0
    irq_32,DW Timer 1
    irq_33,I2S_Master_In
    irq_34,I2S_Master_Out
    irq_35,GMAC


.. csv-table:: EMSK 2.3 - Interrupts Connections
   :header: Interrupt, Component
   :widths: 30,50

    irq_0...irq_15,Internal EM core interrupts
    irq_16,Core Timer 0
    irq_17,Core Timer 1
    irq_20,Core Secure Timer 0
    irq_22,Core DMA controller
    irq_23,Core DMA controller
    irq_24,GPIO controllor
    irq_15,I2C_0 controllor
    irq_26,I2C_1 controllor 
    irq_27,SPI Master controllor
    irq_28,SPI Slave controllor
    irq_29,UART0
    irq_30,UART1
    irq_31,UART2
    irq_32,WDT
    irq_33,Timer 0
    irq_34,Timer 1
    irq_35,Reserved
    irq_36,Reserved
    irq_36,Reserved

.. note::
    Core Secure Timer 0 and Core DMA controller only available for ARC EM7D base configuration.


.. _getting_started_with_em_starter_kit:

Programming and Debugging
-------------------------

Required Hardware and Software
******************************

To use embARC BSP applications on the IoTDK board, the following items are required

* USB Cable
* The USB cable provides power to the board (maximum 500 mA). However, if the board is to run
  standalone, the universal switching power adaptor (110-240V AC to 5V DC),
  can be used to power the board
* :ref:`software_requirement`.
* (optional) A collection of PMOD modules.

Set up the EMSK
***************

#. The EMSK has a bank of DIP switches labeled SW1 that are used to select a configuration. For example, to select ARC EM11D for EMSK 2.3, set bit 2 to the ON position (down), and the others to OFF (up) as shown.

.. image:: /pic/images/getting_started/emsk23_dipswitch.jpg
    :alt: DIP switch settings for ARC EM11D on EMSK 2.3
    :align: center
   

For exact DIP switch settings for various ARC EM Starter Kit versions, refer to EM Starter Kit section in provided embARC documentation. For complete ARC EM Starter Kit information, see the **EM Starter Kit User's Guide** provided with the ARC EM Starter Kit.

#. Connect the USB cable to connector J7 on the EMSK to USB port on your development host. If using the Ashling Opella-XD for ARC Debug Probe, connect it to the J15 connector on EMSK.

.. note:: Despite the fact that EMSK 2.3 can be powered by connector J7, it is recommended to always use an AC adapter to supply power of the board.

#. You can use any terminal emulation program to view UART output from the EMSK. The USB connection provides both the debug channel and RS232 transport. Use PuTTY application on Windows as an example.

   * Determine which COM port the EMSK is using.

      * Open the **Windows Control Panel** and select **Device Manager** in a Windows environment.
      * Expand **Ports (COM and LPT)** in the list. Select **USB Serial Port (COM x)** and note the COM port number for the ARC board.

   * Configure serial terminal connection.

      * Launch PuTTY. Select **Serial** under **Connection type** and enter the appropriate COM port string under **Serial line**.
      * Choose 115200 baud, 8 bits, 1 stop bit, no parity (115200-8-N-1) in settings.
      * You can optionally save your settings so they can be easily retrieved every time PuTTY is launched.
      * Click Open to open the console.

#. Test serial output with EMSK.

      * Press the middle ("R"eset) button above the **ARC** label on the EMSK board to reset the board and run the self-test.
      * Use EMSK 2.3 as an example. Confirm that you can see the header and self-test message printed to the console.

      .. code-block:: console

         ***********************************
         **       Synopsys, Inc.          **
         **     ARC EM Starter kit        **
         **                               **
         ** Comprehensive software stacks **
         **   available from embARC.org   **
         **                               **
         ***********************************
         Firmware   Feb 22 2017, v2.3
         Bootloader Feb 22 2017, v1.1
         ARC EM11D, core configuration #3

         ARC IDENTITY = 0x43
         RF_BUILD = 0xc902
         TIMER_BUILD = 0x10304
         ICCM_BUILD = 0x804
         DCCM_BUILD = 0x10804
         I_CACHE_BUILD = 0x135104
         D_CACHE_BUILD = 0x215104

         SelfTest PASSED

         Info: No boot image found


Building
********

Take :ref:`example_blinky` as an example and use the em7d configuration of EMSK 2.2

.. code-block:: console

   cd embarc_bsp\example\baremetal\blinky
   # for ARC GNU toolchain
   make TOOLCHAIN=gnu BOARD=emsk BD_VER=22 CUR_CORE=arcem7d
   # for MWDT toolchain
   make TOOLCHAIN=mw  BOARD=emsk BD_VER=22 CUR_CORE=arcem7d

Running
*******

.. code-block:: console

   cd embarc_bsp\example\baremetal\blinky
   # for ARC GNU toolchain
   make TOOLCHAIN=gnu  BOARD=emsk BD_VER=22 CUR_CORE=arcem7d
   # for MWDT toolchain
   make TOOLCHAIN=mw  BOARD=emsk BD_VER=22 CUR_CORE=arcem7d

Debugging
*********

.. code-block:: console

   cd embarc_bsp\example\baremetal\blinky
   # for ARC GNU toolchain
   make TOOLCHAIN=gnu  BOARD=emsk BD_VER=22 CUR_CORE=arcem7d
   # for MWDT toolchain
   make TOOLCHAIN=mw  BOARD=emsk BD_VER=22 CUR_CORE=arcem7d

Flashing
********

EMSK has an on board SPI flash, but you cannot directly flash your
application into EMSK through debugger. You need other tools/applications
(e.g., embarc bootloader) to do this.