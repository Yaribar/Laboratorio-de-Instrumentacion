#ifndef _ADC_H
#define _ADC_H
#endif

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



class ADC{
public:
	ADC(uint8_t pin, uint8_t vref, uint8_t bits_resolution, uint16_t raw_voltage);
	~ADC();

	private:
	
};

class RGB{
public:
	RGB(uint8_t red, uint8_t green, uint8_t blue, uint8_t intensity);
	~RGB();


private:
	
};