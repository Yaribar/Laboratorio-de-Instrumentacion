#include "RGB_LED.h"
#include "PWM_ESP32.h"

RGBLED::RGBLED(uint8_t pin_red, uint8_t pin_green, uint8_t pin_blue)
{
    _pin_red=pin_red;
    _pin_green=pin_green;
    _pin_blue=pin_blue;

    PWM_Red.setup(_pin_red, 0, 10000, _bits_resolution, true);
	PWM_Green.setup(_pin_green, 1, 10000, _bits_resolution, true);
    PWM_Blue.setup(_pin_blue, 3, 10000, _bits_resolution, true);
	
}

RGBLED::~RGBLED()
{

}

void RGBLED::setIntstRed(float intensity)
{
    PWM_Red.setDuty(intensity);
}
void RGBLED::setIntstGreen(float intensity)
{
    PWM_Green.setDuty(intensity);
}
void RGBLED::setIntstBlue(float intensity)
{
    PWM_Blue.setDuty(intensity);
}
