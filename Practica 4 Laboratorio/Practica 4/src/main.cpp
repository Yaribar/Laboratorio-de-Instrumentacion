#include <Arduino.h>
#include "ADC_Read.h"
#include <BluetoothSerial.h>
#include "Comulative_AVG.h"
#include "RGB.h"

#define RED 1
#define GREEN 2
#define BLUE 3
#define RESOLUTION 10
#define VREF 5
#define ON_INTENSITY 100

ADCRead ADC_RED(RED, RESOLUTION, VREF);
ADCRead ADC_GREEN(GREEN, RESOLUTION, VREF);
ADCRead ADC_BLUE(BLUE, RESOLUTION, VREF);
AVG AVG_Red,AVG_Green,AVG_Blue;
BluetoothSerial SerialBT;
RGB RGB1(RED,GREEN,BLUE);

uint8_t on_led_time=5;
float

void setup() {

  SerialBT.begin("Wano");

}

void loop() {


  switch (x)
  {
  case 1:
    RGB1.setIntstRed(ON_INTENSITY); 
    RGB1.setIntstRed(0);    
    break;
  case 2:
    RGB1.setIntstGreen(ON_INTENSITY);
    RGB1.setIntstGreen(0);
    break;
  case 3:
    RGB1.setIntstBlue(ON_INTENSITY);
    RGB1.setIntstBlue(0);
    break;
  
  default:
    break;
  }

  if (SerialBT.available()) {
    SerialBT.printf("%.1f",AVG_Red.avg(ADC_RED.readVoltage()));
    SerialBT.printf(",%.1f ", AVG_Green.avg(ADC_GREEN.readVoltage()));
    SerialBT.printf(",%.1f \r\n", AVG_Blue.avg(ADC_BLUE.readVoltage()));
  }
}