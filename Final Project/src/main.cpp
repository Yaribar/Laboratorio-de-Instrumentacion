#include <Arduino.h>
#include "Useful_Methods.h"
#include "NiMOV.h"
#include "IR.h"
#include "ENCODER.h"
#include "ESP_SERVO.h"


const byte encoderPin = 25;
const byte picturePin = 26;
const byte servoPin = 32;
volatile uint8_t interruptCounter = 0;
uint8_t numberOfInterrupts = 0;
uint rev=0;
uint32_t tiempo=0;
float speed=0;
uint8_t pulse=0;
String input;
float data[2];


IR IR(26);
NiMOV HBRIDGE(AIN1,0, AIN2, 1,10000, 10,100);
ESPServo Servo1;


portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
 
void IRAM_ATTR encoderInterrupt() {
  portENTER_CRITICAL_ISR(&mux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&mux);
}

void setup() {
 
  Serial.begin(115200);
  pinMode(encoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin), encoderInterrupt, FALLING);
  pinMode(picturePin,INPUT_PULLUP);
  Servo1.setup(servoPin,2);
   
}
 
void loop() {

  if (Serial.available()) {
		input = Serial.readStringUntil('\n');
		parseString(input, ",", data);
		Serial.printf("%.1f,%.1f\r\n", data[0],data[1]);
    Servo1.write((int)data[1]);
    delay(200);  
	}
 
  if(IR.pulse()){
    Serial.println("pulse");
    HBRIDGE.setSpeed(data[0]);
  }

  if(interruptCounter>0){
 
      portENTER_CRITICAL(&mux);
      interruptCounter--;
      portEXIT_CRITICAL(&mux);
 
      numberOfInterrupts++;
      Serial.print("Interrupt Total: ");
      Serial.println(numberOfInterrupts);
  }

  if(numberOfInterrupts==228){
    rev++;
    Serial.println(rev);
    numberOfInterrupts=0;
    }

  if(numberOfInterrupts==10){
    HBRIDGE.setStop(0);
    
  }
}


