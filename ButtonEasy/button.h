// button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define Rise 0
#define Fall 1

class Bt
{
public:
	Bt(uint8_t pin);
	bool getState(bool edge);

private:
	bool _button_state;
	bool _last_button_state;
	bool _read;
	uint8_t _pin;
};

#endif

