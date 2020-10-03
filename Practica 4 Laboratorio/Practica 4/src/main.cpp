#include <Arduino.h>
#include "ADC_Read.h"
#include <BluetoothSerial.h>
#include "Comulative_AVG.h"
#include "RGB.h"

#define RED 32
#define GREEN 33
#define BLUE 34
#define RESOLUTION 10
#define VREF 3.3f
#define SAMPLING_PERIOD 5

ADCRead ADC(RED, RESOLUTION, VREF);
AVG AVG_Red,AVG_Green,AVG_Blue;
BluetoothSerial SerialBT;
RGB RGB1(RED,GREEN,BLUE);

uint8_t on_led_time=5;
unsigned long start_time;

void setup() {
  SerialBT.begin("Wano");
  start_time=0;
}

void loop() {

  
  if (SerialBT.available()) {
    on_led_time=SerialBT.readStringUntil("\n");
  }

  if (millis() - start_time > SAMPLING_PERIOD) {
		start_time = millis();
    SerialBT.printf("%.1f,%.1f,%.1f \n",AVG_Red.getCurrentAvg(),AVG_Green.getCurrentAvg(),AVG_Blue.getCurrentAvg());      
  }  
}