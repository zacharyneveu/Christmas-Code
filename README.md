Smart Home Location Tracker
===========================

About
=====
This project implements a the code for a simple device using IFTTT to display whether members of my family are home, at school, at work etc.
The code runs on a Raspberry Pi with attached LEDs in a custom enclosure.  

Structure
=========
```file_to_leds.sh``` uses a Google Drive client on the Raspberry Pi to download the locations file and parse the contents. A C program is then called with the locations as arguments to write to the LEDS.

