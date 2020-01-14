.. _hardware_requirement:

Hardware Requirement
====================

Board Requirement
#################
* ARC Board

  * ARC Software Development Platform
  * `ARC EM Starter Kit <https://www.synopsys.com/dw/ipdir.php?ds=arc_em_starter_kit>`_
  * `ARC HS Development Kit <https://www.synopsys.com/dw/ipdir.php?ds=arc-hs-development-kit>`_
  * `ARC IoT Development Kit <https://www.synopsys.com/dw/ipdir.php?ds=arc_iot_development_kit>`_
  * `ARC AXS <https://www.synopsys.com/dw/ipdir.php?ds=arc-software-development-platform>`_
  * `ARC Virtual Board based on nSIM <https://www.synopsys.com/dw/ipdir.php?ds=sim_nSIM>`_


Board Connections
###################
* EMSK

  * Pmod WiFi is connected to Pmod J5 connector.
  * Pmod RF2 is connected to Pmod J6 connector.
  * BLE HM-10 is connected to the Pmod J1 connector.
  * Pmod AD2 is connected to the Pmod J2 connector.
  * Pmod TMP2/TMP3 is connected to the Pmod J2 connector.
  * SSD1306 OLED module is connected to the Pmod J2 or J4 connector, depending on your application.
  * SD Card plugged into card slot J9.

.. _emsk_board_settings:
.. figure:: /pic/images/getting_started/emsk_board_settings.jpg
   :scale: 20 %
   :alt: emsk board setting

   EMSK board connections

All versions of EMSK have the same board connections.

.. note:: The above connections are set as default in the embARC BSP. You can set your board connections in *<embARC>/board*. The hardware may be damaged by wrong connections.

Setting Board Environment
##########################
* Set serial terminal

  * The default UART baudrate is 115200 bps.
  * For example, in the Tera Term menu, select **Setup -> Serial Port** and change the settings for port and baudrate.
