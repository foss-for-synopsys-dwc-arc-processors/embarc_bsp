.. _introduction_embarc_bsp:

Overview
========

Introduction
############

The embARC **Board support Package** (BSP) is a software distribution aimed at facilitating the development and evaluation of embedded systems based on
ARCv2 processors.

Unlike the `embARC OSP <https://github.com/foss-for-synopsys-dwc-arc-processors/embarc_osp>`_ which is a full-featured distribution for ARC embedded systems,
the embARC BSP is designed to provide a minimalistic board support package for ARC users by defining consistent and simple software interfaces to the processors
and onboard devices.

The embARC BSP code is originated from embARC OSP. The code is reorganized with the same ARC HAL, device HAL and driver implementations for DesignWare IP
peripherals. The operating systems, common libraries and applications are not included in the embARC BSP. The code in embARC BSP is
independent from the build system. It can be ported to various build system easily. The lightweight makefile and Eclipse IDE are both supported in embARC BSP
as reference.

- Support MetaWare & ARC GNU toolchains
- Support various build systems and compiling environments, such as simple makefile, ARC MetaWare & GNU IDE, makefile, IDE support
- Use embARC ARC Hardware Abstraction Layer (HAL), C & C++ support, assembly support
- Simple UART and GPIO, I2C, SPI drivers
- No middleware, no OS
- Hello & blinky example (UART, GPIO, timer)




Architecture
############

The embARC BSP general architecture and components are shown
in the block diagram below.

.. image:: /pic/embARC.png
    :alt: embARC
    :align: center


- :ref:`ARC Hardware Abstraction Layer (ARC HAL)<arc_hal>` provides the
  necessary hardware abstraction for |arc| ISA compatible processors.

- :ref:`Device Hardware Abstraction Layer (HAL)<device_hal>` provides hardware
  abstraction for common platform devices and implementation of DesignWare IP
  drivers, such as UART, IIC, and SPI.

- :ref:`Board Support Package (BSP) Layer<board_bsp>` provides support for
  different boards based on the ARCv2 processors.

- :ref:`Library Layer<library_layer>` provides basic common library support
  for embedded systems, such as C library, dlmalloc library ,and SecureShield
  library.

Many :ref:`examples<example>` are also provided to help get started quickly with |arc| and the embARC BSP software.


Toolchain Support
#################

The embARC BSP software is supported by the following toolchain offerings from Synopsys:

- The `DesignWare ARC MetaWare Development Toolkit <https://www.synopsys.com/dw/ipdir.php?ds=sw_metaware>`__
  builds on a long legacy of industry-leading compiler and debugger products for embedded applications.
  It is a complete solution that contains all the components needed to support the
  development, debugging and tuning of embedded applications for the |arc|.

- The `GNU Toolchain for DesignWare ARC Processors <https://github.com/foss-for-synopsys-dwc-arc-processors/toolchain/releases>`__
  provides a pre-built GNU toolchain for |arc| integrated into the Eclipse IDE.
  The GNU tools are maintained by Synopsys with new releases being published at
  regular intervals.

- The `DesignWare ARC MetaWare Development Toolkit Lite Edition <https://www.synopsys.com/cgi-bin/arcmwtk_lite/reg1.cgi>`__
  is a functioning demonstration of the MetaWare Development Toolkit, but has a
  number of restrictions, including a code-size limit of 32 Kb and no run-time
  library sources. It is available for free download and use for academic, personal,
  and non-competitive evaluation purposes.

Copyright Notice
################

Copyright (c) |today|, Synopsys, Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the Synopsys, Inc., nor the names of its contributors
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. NY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**For complete embARC license information, please refer to the embARC FOSS Notice**.

Fundamental Terms and Concepts
##############################

See :ref:`glossary`
