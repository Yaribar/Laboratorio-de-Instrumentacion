#include <Arduino.h>
#include "ADC_Read.h"
#include <BluetoothSerial.h>
#include "Comulative_AVG.h"
#include "RGB_LED.h"

#define RED 1
#define GREEN 2
#define BLUE 3

AVG AVG_Red,AVG_Green,AVG_Blue;
BluetoothSerial SerialBT;
RGBLED RGB1(RED,GREEN,BLUE);

x=0;

void setup() {

  SerialBT.begin("Wano");

}

void loop() {


  switch (x)
  {
  case 1:
    RGB1.
    SerialBT.printf("%.1f \r\n",AVG_Red.avg(x));
    break;
  case 2:
    SerialBT.printf("%.1f \r\n", AVG_Green.avg(x));
    break;
  case 3:
    SerialBT.printf("%.1f \r\n", AVG_Blue.avg(x));
    break;
  
  default:
    break;
  }
}