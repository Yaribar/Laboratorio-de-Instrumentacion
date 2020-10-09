#include <Arduino.h>
#include "ADC_Read.h"
#include <BluetoothSerial.h>
#include "Comulative_AVG.h"
#include "RGB.h"

#define PIN_RED 32
#define PIN_GREEN 33
#define PIN_BLUE 34
#define RESOLUTION 10
#define VREF 3.3f
#define SAMPLING_PERIOD 5

ADCRead ADC(36, RESOLUTION, VREF);
AVG AVG_Red,AVG_Green,AVG_Blue;
BluetoothSerial SerialBT;
RGB RGB1(PIN_RED,PIN_GREEN,PIN_BLUE);

String on_led_time;
unsigned long start_time;

void setup() {
  SerialBT.begin("Wano");
  Serial.begin(115200);
  start_time=0;
}

void loop() {

  
  printf("%.1f,%.1f,%.1f \n",255.1,255.1,255.1);
  delay(300);
  //if (millis() - start_time > SAMPLING_PERIOD) {
		//start_time = millis();
    //SerialBT.printf("%.1f,%.1f,%.1f \n",AVG_Red.getCurrentAvg(),AVG_Green.getCurrentAvg(),AVG_Blue.getCurrentAvg());
    //SerialBT.printf("%.1f,%.1f,%.1f \n",255.1,255.1,255.1);       
  //}  
}