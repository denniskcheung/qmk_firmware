# Ginkgo65 Multi PCB

![Ginkgo65](https://raw.githubusercontent.com/rhmokey/123.github.io/main/2021/08/15/hello-world/ginkgo65.png)

Support Atmega32u4 keyboard,With a variety of configurations

* Keyboard Maintainer: [mokey](https://github.com/rhmokey)
* Hardware Supported: Atmega32u4
## Bootloader
* **Physical reset button**: Short press the button on the back of the PCB to enter the Bootloader and flash the firmware


Make example for this keyboard (after setting up your build environment):

    make mokey/ginkgo65:default 

Flashing example for this keyboard:

    make mokey/ginkgo65:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).