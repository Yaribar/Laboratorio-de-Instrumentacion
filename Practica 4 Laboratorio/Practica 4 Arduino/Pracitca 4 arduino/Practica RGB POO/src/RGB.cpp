#include "RGB.h"


RGB::RGB()
{	
}

RGB::~RGB()
{
}

void RGB::begin(const byte rgb_pins[3])
{
    for (byte i = RED; i <= BLUE; i++)
    {
        _rgb_pins[i] = rgb_pins[i];
        pinMode(rgb_pins[i],OUTPUT);
    }
}

void RGB::setColor(byte state){
    switch (state)
  {
  case RED:
    analogWrite(_rgb_pins[RED],255);
    analogWrite(_rgb_pins[GREEN],0);
    analogWrite(_rgb_pins[BLUE],0);
    break;
  case GREEN:
    analogWrite(_rgb_pins[GREEN],255);
    analogWrite(_rgb_pins[BLUE],0);
    analogWrite(_rgb_pins[RED],0);
    break;
  case BLUE:
    analogWrite(_rgb_pins[BLUE],255);
    analogWrite(_rgb_pins[RED],0);
    analogWrite(_rgb_pins[GREEN],0);
    break;
  case WHITE:
    analogWrite(_rgb_pins[RED, GREEN, BLUE],255);
    break;
  case BLACK:
    analogWrite(_rgb_pins[RED, GREEN, BLUE], 255);

    break;  
  default:
    break;
  }
}