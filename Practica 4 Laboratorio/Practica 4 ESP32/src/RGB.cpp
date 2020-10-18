#include "PWM_ESP32.h"
#include "RGB.h"


RGB::RGB(uint8_t pin_red, uint8_t pin_green, uint8_t pin_blue)
{
  _pin_red=pin_red;
  _pin_green=pin_green;
  _pin_blue=pin_blue;

  PWM_Red.setup(_pin_red, 1, 10000, _bits_resolution, true);
	PWM_Green.setup(_pin_green, 2, 10000, _bits_resolution, true);
  PWM_Blue.setup(_pin_blue, 3, 10000, _bits_resolution, true);
	
}

RGB::~RGB()
{

}
void RGB::setRGB(float intensity_red,float intensity_green, float instensity_blue)
{
    
    PWM_Red.setDuty(intensity_red);
    PWM_Green.setDuty(intensity_green);
    PWM_Blue.setDuty(instensity_blue);
    
}

void RGB::setRGB(byte state){
    switch (state)
  {
  case RED:
    setRGB(0,100,100);
    break;
  case GREEN:
    setRGB(100,0,100);
    break;
  case BLUE:
    setRGB(100,100,0);
    break;
  case WHITE:
    setRGB(0,0,0);
    break;
  case BLACK:
    setRGB(100,100,100);

    break;  
  default:
    break;
  }
}

