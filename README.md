BLEMini
=======

BLE Mini is a small, certified BLE development board for makers to do their innovative projects. It can be used for BLE development using TI CC254x SDK.

We also provide some examples to show how to integrate this board to other platform such as Arduino. It can also be run independently.

You can write your own firmware for the BLE Mini, get TI CC254x SDK and IAR 8051 C compiler from their website. The current version for CC254x SDK is v1.4.0 and IAR 8051 C compiler is v8.20.2.

Note:

1. For firmware update, since TI's bootloader (UBL) on the BLE Mini does not work on Windows 8.1 or later, OSX and Linux. It only works fine on Windows 7.

2. The CC254x SDK can only work on Windows platform (using IAR C Compiler). Suggest you using TI's CC Debugger for doing your own firmware.

3. If you are using Windows 8.1 or later, Linux or Mac, highly recommend you to install a copy of Windows 7 using Virtual Box or Parallels Desktop.


Dependency
==========

BLE Mini requires different firmwares to function, so it depends on some opensource projects:<br/>
- [Biscuit Firmware](https://github.com/RedBearLab/Biscuit) (a BLE to UART firmware, factory default)
- [MiniBeacon Firmware](https://github.com/RedBearLab/MiniBeacon)
- [BLE_HCI](https://github.com/RedBearLab/BLE_HCI)

All are hosted at https://github.com/RedBearLab

Please refers to those repositories for source code and details.


Examples
========

Samples show how to connect iOS/Mac to your Arduino via BLE link (with the Biscuit firmware). More interesting resource will be added soon.

SimpleControls
- This demo shows how to create controls for common Arduino pin settings
- Please refer to "Readme_SimpleControls.txt" for details

Chat
- A simple chat demo for iOS to talk to Arduino
- Please refer to "Readme_Chat.txt" for details

MiniBeacon
- Implemented Apple's iBeacon spec.
- Use our MiniBeacon iOS App to set the parameters.


Update Firmawre
===============

Only work on Windows PC, press and hold the button on the board and connect it to an USB port, a MSD drive will be mounted and then drag and drop the firmware file (.bin) to the drive.


Resources
=========

1. TI CC254x SDK<br/>
http://www.ti.com/tool/ble-stack

2. TI CC254x forum<br/>
http://e2e.ti.com/support/low_power_rf/f/538.aspx 

3. TI CC2540 Datasheet
http://www.ti.com/lit/ds/symlink/cc2540.pdf

4. TI CC254x Software Developer's Guide
http://www.ti.com/lit/swru271
 
5. IAR C compiler for 8051 (CC254x is based on 8051)<br/>
http://www.iar.com/Products/IAR-Embedded-Workbench/8051/

6. RBL BLE Mini<br/>
http://redbearlab.com/blemini/

7. RBL BLE Mini Forum - Discussion and sharing<br/>
https://redbearlab.zendesk.com/forums


License
=======

Copyright (c) 2013-2014 RedBearLab

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
