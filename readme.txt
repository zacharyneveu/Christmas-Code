This is the code for a device to show the status of five people on five RGB
leds based on the location of the peopleś phones.

This project used IFTTT to append to a google drive file when each user enters
or leaves a specified area.  Using the bash script, the google drive file is
then downloaded, each personś status is interpreted, and the statuses are
pushed to the leds through the GPIO with PWM as colors for the RGB leds.
