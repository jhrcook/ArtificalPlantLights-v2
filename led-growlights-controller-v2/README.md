# Arduino Grow Light Controller

**author: Joshua Cook**  
**date: 2020-05-31**

[![arduino](https://img.shields.io/badge/Arduino-sketch-00979D.svg?style=flat&logo=arduino)](https://www.arduino.cc)

The Arduino sketch [`led_growlights_controller_v2.ino`](led_growlights_controller_v2.ino) controls the LED light system.
Each light system is controlled by a separate relay switch connecting the LED driver and AC mains.
Each relay is controlled by a [`sunGrowLight`](https://github.com/jhrcook/sunGrowLight) object that I made as a separate library.
This object takes the relay pin to control and the latitude, longitude, and time zone of a location to from which to use the sunrise and sunset times to turn the lights on and off.
The calculation is handled by the [`sfrwmaker/sunMoon`](https://github.com/sfrwmaker/sunMoon) Arduino library.
