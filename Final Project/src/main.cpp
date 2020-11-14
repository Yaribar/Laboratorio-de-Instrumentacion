#include <Arduino.h>

const byte encoderPin = 25;
volatile uint8_t interruptCounter = 0;
uint8_t numberOfInterrupts = 0;
uint rev=0;
 
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
 
void IRAM_ATTR encoderInterrupt() {
  portENTER_CRITICAL_ISR(&mux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&mux);
}
 
void setup() {
 
  Serial.begin(115200);
  Serial.println("Monitoring interrupts: ");
  pinMode(encoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin), encoderInterrupt, FALLING);
 
}
 
void loop() {
 
  if(interruptCounter>0){
 
      portENTER_CRITICAL(&mux);
      interruptCounter--;
      portEXIT_CRITICAL(&mux);
 
      numberOfInterrupts++;
      Serial.print("An interrupt has occurred. Total: ");
      Serial.println(numberOfInterrupts);
  }
  if(numberOfInterrupts==228){
    rev++;
    Serial.println(rev);
    numberOfInterrupts=0;
    }
}


