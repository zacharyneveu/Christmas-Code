/* Written by Zachary Neveu
 * This program takes the status of five people and displays them as colors on five RGB leds.  This program is to be run on a raspberry pi */
#include<stdio.h>
/* In order to use atoi need the folowing */
#include<stdlib.h>

//pigpio is for controlling LEDS */
#include<pigpio.h>

/* These assign led numbers to people */
#define katyNum 0
#define bobNum 1
#define zachNum 2
#define nickNum 3
#define mattNum 4


/* Struct to store RGB color */
struct color{
	int red;
	int green;
	int blue;
};

/* Struct for storing 3 different pins for each RGB led */
struct LED{
	int redPin;
	int bluePin;
	int greenPin;
};

/* declare statusToColor function */
struct color statusToColor(int status);

/* Declare writeLED function */
void writeLED(int personNum, int status);



int main(int argc, char *argv[]){
	if(argc!=6){
		printf("Wrong number of args (%d)\n", argc);
		return 0;
	}

	/* For status, 0=home=green, 1=away=red, 2=school=blue, 3=work=purple  */
	//int status[5]={0, 1, 3, 2, 1};
	int status[5];
	status[0]=atoi(argv[1]); //Matt's status
	status[1]=atoi(argv[2]); //nick's status
	status[2]=atoi(argv[3]); //zach's status
	status[3]=atoi(argv[4]); //katy's status
	status[4]=atoi(argv[5]); //bob's status

	/* Print statuses */
	printf("Statuses are:");
	int z=0;
	for(z; z<=4; z++){
		printf("%d, ", status[z]);
	}
	printf("\n");

	/* Test print color values */
	//struct color zachColor=statusToColor(status[zachNum]);
	//printf("Zach's color is: %d red, %d green, %d blue \n", zachColor.red, zachColor.green, zachColor.blue);
}



/* This function takes an integer status and returns the RGB values of the LED */
struct color statusToColor(int status){
	struct color newColor;
	if(status==0){
		newColor.red=0;
		newColor.green=255;
		newColor.blue=0;
	}
	else if(status==1){
		newColor.red=255;
		newColor.green=0;
		newColor.blue=0;
	}
	else if(status==2){
		newColor.red=0;
		newColor.green=0;
		newColor.blue=255;
	}
	else if(status==3){
		newColor.red=128;
		newColor.green=0;
		newColor.blue=128;
	}
	return newColor;
}


void writeLED(int personNum, int status){
	int red[5]={1, 2, 3, 4, 5};
	int green[5]={6, 7, 8, 9, 10};
	int blue[5]={11, 12, 13, 14, 15};
	struct color writeColor=statusToColor(status);
	gpioPWM(red[personNum], writeColor.red);
	gpioPWM(green[personNum], writeColor.green);
	gpioPWM(blue[personNum], writeColor.blue);
}

