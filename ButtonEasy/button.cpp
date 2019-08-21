// 
// 
// 

#include "button.h"



Bt::Bt(uint8_t pin)
{
	_pin = pin;
	pinMode(_pin, INPUT);
}

bool Bt::getState(bool edge)
{
	bool button = false;
	_button_state = digitalRead(_pin);
	if (_button_state != _last_button_state)
	{
		if (edge) { // Rising Edge
			if (_button_state) {

				button = true;
				delay(10);
			}
			else {
				_read = true;
			}
		}
		else { // Falling edge
			if (!_button_state) {
				button = true;
				delay(10);
			}
			else {
				_read = true;
			}
		}
	}
	_last_button_state = _button_state;
	return button;
}

