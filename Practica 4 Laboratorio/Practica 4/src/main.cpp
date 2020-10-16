#include <Arduino.h>
#include "ADC_Read.h"
#include "Comulative_AVG.h"
#include "RGB.h"

#define PIN_RED 32
#define PIN_GREEN 33
#define PIN_BLUE 25
#define RESOLUTION 12
#define VREF 3.3

ADCRead ADC(27, RESOLUTION, VREF);
AVG AVG_Red,AVG_Green,AVG_Blue;
RGB RGB1(PIN_RED,PIN_GREEN,PIN_BLUE);

uint8_t on_led_time=250;
uint8_t state=RED;
unsigned long start_time;
String data_in;

void setup() {
  Serial.begin(115200);
  start_time=millis();
  RGB1.setRGB(RED);
}

void loop() {
  if((millis() - start_time) > on_led_time){
    switch(state){
      case RED:
      AVG_Red.avg(ADC.readRaw());
      state = GREEN;
      RGB1.setRGB(GREEN);
      break;
      
      case GREEN:
      AVG_Green.avg(ADC.readRaw());
      state = BLUE;
      RGB1.setRGB(BLUE);
      break;

      case BLUE:
      AVG_Blue.avg(ADC.readRaw());
      state = RED;
      Serial.printf("%.1f,%.1f,%.1f\n",AVG_Red.getCurrentAvg(),AVG_Green.getCurrentAvg(),AVG_Blue.getCurrentAvg());
      RGB1.setRGB(RED);
      break;
    }
    start_time = millis();
  }
  
  if (Serial.available()){
    data_in = Serial.readStringUntil('\n');
    on_led_time = data_in.toInt();
    AVG_Red.resetAvg();
    AVG_Green.resetAvg();
    AVG_Blue.resetAvg();
  }
}