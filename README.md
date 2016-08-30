# CoCA Emerge + Tech - Musical plants project

[CoCA](http://www.cocaartists.com) "Emerge + Tech" - Musical plants is an electronics, software and plants base exhibit we initially developed for [Cinnamon Colomboscope](http://www.cinnamoncolomboscope.com/) 2016 exhibition. This installation will feature a touch sensitive sensor that will generate a soothing sound from each plant. By interacting with individual plants, the audience can create musical compositions.

Sensor unit of this project consists with 14 high sensitive, configurable voltage detectors and USB interface. In this sensor unit we use Samsung's KA2284 as amplifier, level detector, and PIC18F4550 8-bit MCU as data multiplexer and USB I/O controller. PC817 opto isolators are used to interface between analog front-end and digital data processor. In this design both analog and digital circuits are physically and electronically isolated to minimize the noises and interferences.

### Compiling source code

PC application of this project is developed by using [HIDAPI](https://github.com/signal11/hidapi) and [irrKlang](http://www.ambiera.com/irrklang) libraries. This application is designed to work with <I>Microsoft Windows</I> operating systems and we tested it on Windows 7 and Windows 10. 

PC application of this project is developed using <I>Microsoft Visual C++ 2015</I> edition. To compile the application <I>HIDAPI</I> and <I>irrKlang</I> source codes and libraries are need to copy into \frontend directory. 

PIC18F4550 firmware is developed using <I>MikroElektronika's mikroC PRO for PIC</I> compiler. Recommended MCU configuration register values for this firmware is listed in below:

* PLL prescaler : /5 (20 MHz)
* System clock postscaler : /2 (/1)
* USB clock : 96 MHz PLL /2
* Osciliator : HSPLL
* Fail safe clock monitor : OFF
* Internal external switching : OFF
* Power-up timer : OFF
* Brown-out reset : OFF
* Brown-out reset voltage : 2.0V
* USB voltage regulator : ON
* Watchdog timer : OFF
* Watchdog timer postscaler : 1:32768
* CCP2 multiplexed with : RC1
* PortB reset state : Digital
* Low power timer 1 osc : High power
* MCLR pin : Reset
* Stack overflow / underflow : ON
* In-circuit port : OFF
* Enhanced CPU : OFF
* Boot block : OPEN
* Code lock : OPEN
* Data EEPROM : OPEN
* Table write boot block : OPEN
* Table write code : OPEN
* Table read boot block : OPEN
* Table read code : OPEN

### Licenses

All the audio clips used in this project are produced by using xylophone and released under the terms of [Creative Commons Attribution-ShareAlike 4.0 International License](https://creativecommons.org/licenses/by-sa/4.0) (CC BY-SA 4.0).

This musical plants project is an open source hardware project and all the source codes and compiled binaries are released under the [MIT Licenses](https://opensource.org/licenses/MIT).