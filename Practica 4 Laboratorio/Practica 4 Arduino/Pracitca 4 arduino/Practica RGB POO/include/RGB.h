#ifndef _RGB_h
#define _RGB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define RED 0
#define GREEN 1
#define BLUE 2 
#define WHITE 3
#define BLACK 4

class RGB
{
public:
	RGB();
	~RGB();
    void begin(const byte rgb_pins[3]);
    void setColor(uint8_t state);
    

private:
	uint8_t _bits_resolution=10;
    byte _rgb_pins[3]; 

};

#endif