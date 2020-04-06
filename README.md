# Artifical Plant Lights

This is the second version of my LED, artifical-lighting system for my plants.
The current system is just a single set of 6 LEDs controlled by an Arduino.
The new system will have three levels of varying lighting intensity and be controlled by a Raspberry Pi.


## Lighting

### Parts

**Level 1** (high-intensity): 

* 2 $\times$ 12" heatsink
* 2 $\times$ 6 Cree XLamp XP-G2 cool white 6500K LEDs
* LPC-60-1050 Mean Well driver (60 W, 1050 mA)

**Level 2** (standard intensity):

* 18" heatsink
* 6 Cree XLamp XP-G2 cool white 6500K LEDs
* APC-25-1050 Mean Well driver (25 W, 1050 mA)

**Level 3** (low intensity - seedlings):

* 24" aluminium U-chanel heatsink
* 3 Cree XLamp XP-G2 cool white 6500K LEDs
* APC-25-1050 Mean Well driver (25 W, 1050 mA)

**Miscellaneous**:

* thermal adhesive
* wire
* hanging machinary and wire
* PVC pipe
* electrical tape
* wire nuts
* barrel power connectors
* electronics enclosure



## Controller

### Parts

* Raspberry Pi
* Raspberry Pi breakout
* breadboard
* breadboard prototyping wires
* switches

### Features

* Controls the lighting for each level (each driver) separately.
* The sunrise-sunset times can be tied to specific global locations.
* On/Off switches for each lighting system.
