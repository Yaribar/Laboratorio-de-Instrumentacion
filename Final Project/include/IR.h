#ifndef _IR_h
#define _IR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class IR{
public:
    IR(uint8_t pin);
    ~IR();
    bool pulse();
private:
uint8_t _pin;

};

#endif