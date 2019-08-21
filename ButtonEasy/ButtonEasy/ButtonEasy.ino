/*
 Name:		ButtonEasy.ino
 Created:	20/08/2019 15:18:45
 Author:	Gabriel Ichcanziho
*/

// the setup function runs once when you press reset or power the board
#include "button.h"
#define led 3
#define levels 3
#define pRed 6
#define pGreen 5
#define pBlue 3
uint8_t pin = 0;
Bt bUp(2);
Bt bLow(10);
Bt bRed(12);
Bt bGreen(8);
Bt bBlue(7);
int lum;


uint8_t intensidad;

void setup() {
	Serial.begin(9600);
	pinMode(led, OUTPUT);
	pinMode(pRed, OUTPUT);
	pinMode(pGreen, OUTPUT);
	pinMode(pBlue, OUTPUT);
	digitalWrite(pRed, 1);
	digitalWrite(pGreen, 1);
	digitalWrite(pBlue, 1);
	intensidad = 0;
}

// the loop function runs over and over again until power down or reset
void loop() {
	
	if (bUp.getState(Rise)) {
		Serial.println("Picado UP");
		if(intensidad<levels)
			intensidad++;
		Serial.println(intensidad);
	}
	if (bLow.getState(Rise)) {
		Serial.println("Picado Low");
		if(intensidad>0)
			intensidad--;
		Serial.println(intensidad);
	}
	//analogWrite(led, (255/levels) * intensidad);
	
	if (bRed.getState(Rise)) {
		digitalWrite(pGreen, 1);
		digitalWrite(pBlue, 1);
		pin = pRed;
	}
	if (bGreen.getState(Rise)) {
		digitalWrite(pRed, 1);
		digitalWrite(pBlue, 1);
		pin = pGreen;
	}
	if (bBlue.getState(Rise)) {
		digitalWrite(pGreen, 1);
		digitalWrite(pRed, 1);
		pin = pBlue;
	}
	analogWrite(pin, (255 / levels) * intensidad);
}
