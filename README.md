# embARC Board Support Package (BSP)

## Introduction
The embARC **Board Support Package** (BSP) is a software distribution aimed at facilitating the development and evaluation of embedded systems based on
ARCv2 processors.

Unlike the [embARC OSP](https://github.com/foss-for-synopsys-dwc-arc-processors/embarc_osp) which is a full-featured distribution for ARC embedded systems,
the embARC BSP is designed to provide a minimal board support package for ARC users by defining consistent and simple software interfaces to the processors
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


## Contribute to embARC BSP
We welcome community contributions to embARC BSP and follow similar guidelines of embARC OSP. Please check out the [Contributing to embARC OSP](https://github.com/foss-for-synopsys-dwc-arc-processors/embarc_osp/blob/master/.github/CONTRIBUTING.md) for guidelines on how to proceed.
Users participating in the embARC Community and its sub-projects codebases and issue trackers are expected to follow the [embARC code of conduct](https://github.com/foss-for-synopsys-dwc-arc-processors/embarc_osp/blob/master/.github/CODE_OF_CONDUCT.md).
