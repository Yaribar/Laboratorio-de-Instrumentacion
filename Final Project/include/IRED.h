#ifndef _IRED_h
#define _IRED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class IRED{
public:
    IRED(uint8_t pin);
    ~IRED();
    bool pulse();
private:
uint8_t _pin;

};

#endif