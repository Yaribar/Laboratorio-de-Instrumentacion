#ifndef _RGB_h
#define _RGB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "PWM_ESP32.h"
#define RED 1
#define GREEN 2
#define BLUE 3 
#define WHITE 4
#define BLACK 5

class RGB
{
public:
	RGB(uint8_t pin_red, uint8_t pin_green, uint8_t pin_blue);
	~RGB();
    void setRGB(float intensity_red,float intensity_green, float instensity_blue);
    void setRGB(byte state);
    PWM PWM_Red,PWM_Green,PWM_Blue;

private:
    uint8_t _pin_red,_pin_green,_pin_blue;
	uint8_t _bits_resolution=10;
};

#endif