# Cosmic Sans

A 90's and early 2000's themed exploded 60%. No official sources have been released, so I got my multimeter out and whipped this up. There are pads for through-hole indicator LEDs on caps lock, the top right key, and right shift, which I have mapped to indicators for caps lock, num lock, and scroll lock, respectively; of course, you can reprogram them.

* Keyboard Maintainer (unofficial): [chillKB](https://github.com/chillKB)
* Hardware Supported: Cosmic Sans rev1 solder PCB
* Hardware Availability: [Typface](https://typface.com/)

Make example for this keyboard (after setting up your build environment):

    make typface/cosmic_sans:default

Flashing example for this keyboard:

    make typface/cosmic_sans:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key (usually Escape) and plug in the keyboard
* **Physical reset button**: Short the boot pads and tap the reset button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
