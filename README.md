# Artifical Plant Lights

[![Arduino](https://img.shields.io/badge/Arduino-Genuino-00979D.svg?style=flat&logo=arduino)](https://www.arduino.cc) 
[![jhc twitter](https://img.shields.io/badge/Twitter-@JoshDoesA-00aced.svg?style=flat&logo=twitter)](https://twitter.com/JoshDoesa)
[![jhc website](https://img.shields.io/badge/Website-Joshua_Cook-5087B2.svg?style=flat&logo=telegram)](https://joshuacook.netlify.com)

This is the second version of my LED, artifical-lighting system for my plants.
The current system is just a single set of 6 LEDs controlled by an Arduino.
The new system will have three levels of varying lighting intensity for different types of plants.

When everything is built, there will be two posts on my website detailing the construction of the lights and a walk-through of the code.


## Lighting

### Parts

**Level 1** (high-intensity): 

* 2 x 12" heatsink
* 2 x 6 Cree XLamp XP-G2 cool white 6500K LEDs
* LPC-60-1050 Mean Well driver (60 W, 1050 mA)

**Level 2** (standard intensity):

* 18" heatsink
* 8 Cree XLamp XP-G2 cool white 6500K LEDs
* LPC-60-1050 Mean Well driver (60 W, 1050 mA)

**Level 3** (low intensity - seedlings):

* 24" aluminium U-chanel heatsink
* 4 Cree XLamp XP-G2 cool white 6500K LEDs
* APC-25-1050 Mean Well driver (25 W, 1050 mA)

**Miscellaneous**:

* thermal adhesive
* wire
* hanging machinary and wire
* PVC pipe
* electrical tape
* barrel power connectors
* electronics enclosure



## Controller

### Parts

* [Arduino Uno](https://www.arduino.cc)
* Real Time Clock module
* 3 x push buttons
* breadboard wires

### Features

* Controls three sets of lights through a relay board.
* Each set of lights has a separate override button.
* A Real Time Clock (RTC) module accurately maintains the correct time, even if power goes out.

---

### Status

All of the parts have been ordered, but need assembling.

The code is written and ready to go.
