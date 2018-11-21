---
layout: default
---

# Electronics
A selection of electronics projects from the last few years.

## cyborg ring (2017-present)

![cyborg ring](/assets/img/cyborg-ring.gif "cyborg ring")

An exploration into the world of [cordwood construction](https://en.wikipedia.org/wiki/Printed_circuit_board#Cordwood_construction), implemented as a wearable blinky ring powered by tiny zinc-air hearing aide batteries. Soon after releasing the source files a number of other hobbyists started building their own rings, and I was recently paid to supply ten ring kits as awards for a conference. [Certified Open Hardware](https://certification.oshwa.org/us000141.html).

![cyborg ring construction](/assets/img/cyborg-ring2.jpg "cyborg ring construction")

[Source files and build instructions](https://github.com/zakqwy/cyborg_ring), [more documentation](https://hackaday.io/project/34160-cyborg-ring), [livestream build recording](https://www.youtube.com/watch?v=spNg8LhxJz0)

## TP-BMP (2017)

![TP-BMP PCBA](/assets/img/tp-bmp1.jpg "TP-BMP PCBA")

A PCB remix of the [Black Magic Probe](https://1bitsquared.com/collections/frontpage/products/black-magic-probe), a terrific open-source JTAG debugger with an onboard GDB server. My verison replaces the thumbprint reader board in my Thinkpad X220 and lets me program NeuroBytes (or pretty much any other ARM-based device) on the road.

![TP-BMP in use](/assets/img/tp-bmp2.jpg "TP-BMP in use")

[Source files](https://github.com/zakqwy/TP-BMP), [more documentation](https://hackaday.io/project/27272-tp-bmp)

## blinktronicator (2015-2016)

![blinktronicator](/assets/img/blinktronicator1.jpg "blinktronicator")

A USB dongle with all sixteen dominant wavelengths from the Rohm PicoLED series. Includes a mode that allows the user to turn on multiple LEDs at once at varied brightness levels to see which work well together. Used as a design guide for many subsequent projects, most recently the NeuroBytes [Network Interface Device](https://github.com/neurotinker/neurobytes_nid). Received an [Honorable Mention](https://hackaday.com/2016/01/13/the-best-projects-that-fit-in-a-square-inch/) in the 2015 Hackday Square Inch Contest.

![blinktronicator bodge](/assets/img/blinktronicator2.jpg "blinktronicator bodge")

[Source files](https://github.com/zakqwy/blinktronicator), [more documentation](https://hackaday.io/project/8331-blinktronicator)

## $50 ESD pre-tester (2018)
You thought electrostatic discharge testing at a lab was expensive? Try buying one of the sweet looking ray guns the labs use to run the tests, so you can pre-check boards yourself!

[img: sweet ray gun for ESD testing NeuroBytes]

After a few of our [NeuroBytes boards](/neurobytes.md) failed the first round of ESD testing (shown above), I built an ESD pre-tester out of an eBay-sourced modular 8kV power supply, a few 100 pF capacitors, a bit of copper clad FR4, and a length of insulating Delrin rod. Most of the work involved building the circuit to trick the power supply into thinking it was in a mass spectrometer. The resultant device saved us thousands of dollars and months of lab testing, and makes cool sparks as a bonus.

[img: tester]

## Rotovis-Mod1 (2017-2018)

![rotovis1](/assets/img/rotovis1.png)

A tiny castellated board designed to help designers build high-DPI persistence-of-vision displays. DIP8-sized with 16 LEDs and a driver chip, allowing TI-83 resolution (40 DPI) with 8-bit greyscale. Led to development of a [novel dual-stencil technique](https://hackaday.io/project/27829-rotovis-mod1/log/70110-building-these-boards-is-its-own-special-brand-of-hell) for hand-assembling closely spaced 0201 LEDs. [Runner Up](https://hackaday.com/2018/10/18/packing-a-lot-into-a-little-pcb-winners-of-the-square-inch-project/), 2018 Hackaday Square Inch Contest.

![rotovis2](/assets/img/rotovis2.jpg)

[Source files](https://github.com/zakqwy/rotovis_mod1), [more documentation](https://hackaday.io/project/27829-rotovis-mod1)

## Phonetroller II (2018-present)

![phonetrollerII_1](/assets/img/phonetrollerII_1.jpg)

I chopped an XBOX360 wireless controller in half, bolted on a bunch of carved up FR4, wired in a Teensy 3.2 with a USB-C plug, and fitted it to my phone. Boom, Nintendo Switch without the DRM.

![phonetrollerII_2](/assets/img/phonetrollerII_2.jpg)

This project is still very much in progress. The next step is to design a kit that encourages a user to chop _their_ old game controller (XBOX or otherwise) in half, and provides replacement PCBs that mate up with the factory "ergonomics package" from the original device. During assembly, the user would customize the exact dimensions of the structure to snugly fit their device. Less E-waste, more upcycling, funner mobile gaming.

[Version One (bodgy)](https://hackaday.io/project/8160-weekend-novelty-projects/log/69162-phonetroller), [Version Two (slightly less bodgy)](https://hackaday.io/project/112177-phonetroller)

## Illumi-Loupe (2016)

[img: illumi-loupe 1]

A simple concept and probably the most useful (or at least the most used) tool I have ever built. Copper tape, Kapton, and a bit of solder mashed together with a 10x B&L Hastings triplet, a coin cell, and a few high brightness right angle LEDs. Great for examining solder joints on the go!

[img: illumi-loupe 2]
