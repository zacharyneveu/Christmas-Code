#This is a makefile for the family's christmas present
clean:
	rm *.exe && rm *test*.*

leds:
	gcc -Wall -pthread -o leds led_control.c -lpigpio -lrt
	


