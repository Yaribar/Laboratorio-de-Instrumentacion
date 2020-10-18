#include <Arduino.h>
#include <ADC_Read.h>
#include <RGB.h>

ADCRead adc_ldr(9,10,5);
RGB rgb;
const byte pins[]={6,5,3};
byte state;
uint16_t led_on_time = 200;
unsigned long start_time;
uint16_t adc_measurement[3];
String data_in;

void setup() {
  Serial.begin(9600);
  rgb.begin(pins);
  start_time = millis();
  state = RED;
  rgb.setColor(RED);
}

void loop() {
  if(millis()-start_time>led_on_time){
    switch(state){
      case RED:
      adc_measurement[RED] = adc_ldr.readRaw();
      state = GREEN;
      rgb.setColor(GREEN);
      break;
      
      case GREEN:
      adc_measurement[GREEN] = adc_ldr.readRaw();
      state = BLUE;
      rgb.setColor(BLUE);
      break;

      case BLUE:
      adc_measurement[BLUE] = adc_ldr.readRaw();
      state = RED;
      Serial.print(adc_measurement[RED]);
      Serial.print(",");
      Serial.print(adc_measurement[GREEN]);
      Serial.print(",");
      Serial.println(adc_measurement[BLUE]);
      rgb.setColor(RED);
      break;
    }
    start_time = millis();
  }
  if (Serial.available()){
    data_in = Serial.readStringUntil('\n');
    led_on_time = data_in.toInt();

  }
}