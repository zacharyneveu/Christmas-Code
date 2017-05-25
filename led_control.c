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


/* declare statusToColor function */
struct color statusToColor(int status);

/* Declare writeLED function */
void writeLED(int personNum, int status);



int main(int argc, char *argv[]){
	if(argc!=6){
		printf("Wrong number of args (%d)\n", argc);
		return 0;
	}

	int red[5]={17, 2, 18, 16, 13};
	int green[5]={27, 25, 23, 20, 19};
	int blue[5]={22, 4, 24, 21, 26};

	gpioInitialise();
	//reset pins each iteration
	int l=0;
	for(l; l<5; l++){
		gpioSetMode(red[l], PI_INPUT); 
		usleep(100000);
		gpioSetMode(green[l], PI_INPUT);
		usleep(100000);
		gpioSetMode(blue[l], PI_INPUT);
		usleep(100000);
	}

	int j=0;
	for(j; j<5; j++){
		gpioSetMode(red[j], PI_OUTPUT);
		usleep(10000);
		gpioSetMode(green[j], PI_OUTPUT);
		usleep(10000);
		gpioSetMode(blue[j], PI_OUTPUT);
		usleep(10000);
	}
	printf("Gpio Initialized");

	/* For status, 0=home=green, 1=away=red, 2=school=blue, 3=work=purple  */
	//int status[5]={0, 1, 3, 2, 1};
	int status[5];
	status[0]=atoi(argv[1]); //Matt's status
	status[1]=atoi(argv[2]); //nick's status
	status[2]=atoi(argv[3]); //zach's status
	status[3]=atoi(argv[4]); //katy's status
	status[4]=atoi(argv[5]); //bob's status

	int i=0;
	for(i; i<5; i++){
		writeLED(i, 4); //stop all leds? how do I do this?
		usleep(100000);
		writeLED(i, status[i]);
	}
	gpioTerminate();

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
		newColor.red=255;
		newColor.green=0;
		newColor.blue=255;
	}
	else{
		newColor.red=128;
		newColor.green=128;
		newColor.blue=128;
	}
	return newColor;
}

void writeLED(int personNum, int status){
	int red[5]={17, 2, 18, 16, 13};
	int green[5]={27, 25, 23, 20, 19};
	int blue[5]={22, 4, 24, 21, 26};
	struct color writeColor=statusToColor(status);
	//gpioPWM(red[personNum], 0);
	gpioPWM(red[personNum], writeColor.red);
	usleep(10000);

	//gpioPWM(green[personNum], 0);
	gpioPWM(green[personNum], writeColor.green);
	usleep(10000);

	//gpioPWM(blue[personNum], 0);
	gpioPWM(blue[personNum], writeColor.blue);
	usleep(10000);

	printf("person: %d\n", personNum);
	printf("color printed...\n");
	printf("red: %d green: %d blue: %d\n", writeColor.red, writeColor.green, writeColor.blue);
	printf("\n");	
}

