---
layout: default
---

# Novelty Soldering
Pushing the limits of creative bodgery, one RoHS-compliant joint at a time. Some of these examples are part of larger projects, while others serve no purpose beyond entertainment.

## Hand-Carved FR4
I don't have a PCB mill, so I tend to hand-carve FR4 when I need to throw together a quick-but-durable prototype. The method takes practice but can produce excellent results. I gave a talk about this at Sketching in Hardware 2017; it wasn't recorded but you can see the slides [here](https://www.dropbox.com/sh/hyhu9ugzqjm3rpa/AADzmDjt3YaXpK__I8fdOgkTa?dl=0&preview=zach+fredin+-+ZF_sketching.pdf).

### phonetroller I (2017)

![phonetrollerI_1](/assets/img/phonetrollerI_1.jpg)

The first prototype of the Phonetroller project; see [electronics](/electronics.md) for the newer (but still bodgy) version. This build made extensive use of FR4 as both a structural and an electronic material, and was sized to fit my phone while in its case. Based on a Teensy 3.2 in USB HID mode. Buttons were uncomfortable to use and the joystick was garbage, but it worked.

![phonetrollerI_2](/assets/img/phonetrollerI_2.jpg)

### NeuroScope (2016)

![neuroscope](/assets/img/neuroscope.jpg)

I spent a weekend building a Teensy 3.2-based prototype membrane potential visualizer for the [NeuroBytes](/neurobytes.md) project. It ended up being one of the most important prototypes I've ever built -- we got our best response from our customers, and its technical requirements drove our development efforts for the next few years. Survived in my bag before being retired when we switched from ATtiny88s to STM32L011s. I even built a second, slightly more compact version:

![neuroscope2](/assets/img/neuroscope2.jpg)

[more documentation](https://hackaday.io/project/3339-neurobytes/log/41994-neuroscope-a-real-time-membrane-potential-waveform-viewer)

### auto dice (2016)

![auto dice](/assets/img/autodice.gif "auto dice")

Uses fourteen 0402 LEDs, an ATtiny44A, and a few coin cells to emulate a pair of dice. I sprayed the circuit with polyurethane and it has survived a few years bouncing around in my bag.

![auto dice 2](/assets/img/autodice2.jpg "auto dice")

[more documentation](https://hackaday.io/project/8160-weekend-novelty-projects/log/42852-auto-dice)

### simon suggests (2016)

![simon suggests](/assets/img/simon.jpg)

Suspiciously similar in function and coloration to the popular 1978 electronic game Simon. Built as a holiday present, and as an excuse to play around with SMT piezo buzzers and 12mm buttons. Video with sound [here](https://youtu.be/lXgxr6eGAZU), more documentation [here](https://hackaday.io/project/8160-weekend-novelty-projects/log/50668-simon-uh-suggests).

## Badge Bodgery
Electronic conference badges are now **a thing**. I like to hack them into weird delicate blinky sculptures.

### supercon monster matrix (2016)
![hackaday 2016 badge](/assets/img/hackaday2016badge.jpg)

The 2016 Hackaday Supercon badge had an 8x16 red LED matrix. I felt it was too small, so I used a few chunks of FR4 and a bunch of magnet wire to embiggen it. Won Best Dead Bug in the badge hacking contest. More documentation [here](https://hackaday.io/project/8160-weekend-novelty-projects/log/48843-badgery-bodgery), article [here](https://hackaday.com/2016/11/21/showing-off-the-badge-hacks-from-supercon/).

### tindie binary counter eyes (2017)
![tindie badge 1](/assets/img/tindiebadge1.gif)

The Tindie Badge is a simple learn-to-solder project, where the user solders a pair of insertion mount T1-3/4 color-changing LEDs to the front and a battery/switch to the back. I swapped the LEDs for a pair of 5-element midair loops:

![tindie badge 3](/assets/img/tindiebadge3.jpg)

... and added a QFN ATTiny84A to the back, along with a few support components:

![tindie badge 2](/assets/img/tindiebadge2.jpg)

[more documentation](https://hackaday.io/project/8160-weekend-novelty-projects/log/71347-tindie-badge-bodge)

### Jolly Wrencher + Teensy (2018)

Like the Tindie badge, the Jolly Wrencher originally was a learn-to-solder project with a few blinky LED eyes. I added all the parts of a Teensy 3.2 (ARM Cortex M4 microcontroller, bootloader, bypassing, oscillator, etc), along with a MEMS microphone, analog amplifier, power supply, and ten LEDs. The badge used the ARM CMSIS DSP FFT capabilities to display a real-time audio spectrum from the microphone (LEDs in test mode below).

![jolly wrencher](/assets/img/jollywrencher1.jpg)

That is, until something broke. Some things are too delicate to survive. More documentation [here](https://hackaday.io/project/8160-weekend-novelty-projects/log/154333-jolly-wrencher-diy-teensy-bodgery).

### Dead-Bug Linux computer (2018)

Based on the Octavo OSD335x SiP running BeagleBone firmware. The chip enumerated over USB but I never got it to boot, but to be fair it was a busy weekend and SD cards can be fussy.

![octavo](/assets/img/octavo.jpg)

## Free Air Sculptures
Sometimes you just don't have time for a fussy substrate. This work differs from most free-air work in that it concentrates on being tiny at the expense of rigidity and durability.

### blinktronicator (2016)
A free-air version of the [blinktronicator](/electronics.md). Still works, still my favorite creation to date.

![blinktronicator](/assets/img/blinktronicator3.jpg)

[more documentation](https://hackaday.io/project/8331-blinktronicator/log/41277-free-air-blinktronicator)

### DIP-ified QFN (2017)
I wanted to experiment with TI's constant-current LED drivers and was too impatient to wait for a PCB. Presto, quick 0.1" breadboard compatibility!

![dipify](/assets/img/dipify.jpg)

### Rotovis-Mod1 (2018)
A free-air verison of [Rotovis-Mod1](/electronics.md), perched atop a Teensy 3.5 like a tiny light-up peacock. Since they're effectively 2-terminal LGAs, hand-soldering 0201 LEDs is actually a bit easier this way.

![Rotovis-Mod1](/assets/img/rotovis3.jpg)

[more documentation](https://hackaday.io/project/27829-rotovis-mod1/log/147666-the-obligatory-free-air-version)
