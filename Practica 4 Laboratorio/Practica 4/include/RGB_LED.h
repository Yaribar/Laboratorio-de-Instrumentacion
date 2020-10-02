#ifndef _RGB_LED_h
#define _RGB_LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "PWM_ESP32.h"



class RGBLED{
public:
	RGBLED(uint8_t pin_red, uint8_t pin_green, uint8_t pin_blue);
	~RGBLED();
    void setIntstRed(float intensity);
    void setIntstGreen(float intensity);
    void setIntstBlue(float intensity);

    PWM PWM_Red,PWM_Green,PWM_Blue;

private:
    uint8_t _pin_red,_pin_green,_pin_blue;
	uint8_t _bits_resolution=10;
};

#endif