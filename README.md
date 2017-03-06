# ROBOCON_2017
Codes in Arduino IDE for theme "The Landing Disk"

These are the codes that Team Robocon Cummins, Pune used for Robocon 2017. Our attempt was to divide the tasks, easier debugging 
and multiprocessing in Arduino atmega 2560, also known as Arduino Mega.
The Mega has a crystal frequency of 16Mhz.

The Master code communicated with ps2 wireless, angle and feeding assembly.
The angle and feeding were designed with relay circuits, to provide pwm and direction,so the pin connections on the 
controller were reduced. 
The Base and Throwing codes communicated with the Master.
We had  very simple form of communication viz, setting and resetting digital I/Os.
Serial data was used only in the Throwing code, for tranfer of set points,ie hardcoded pwm values for the throwing motor.

There are a few redundancies in the code for the throwing assembly, but these were kept intentionally, and we didn't get 
the time to eliminate them.
Thank you for your time!
