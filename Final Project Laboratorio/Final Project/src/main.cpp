#include <Arduino.h>
#include "Useful_Methods.h"
#include "NiMOV.h"
#include "IRED.h"

#include "ESP_SERVO.h"

#define PHOTODISTANCE 7.5f
#define SERVOSTOP 15.5f
#define TRIANGLE 18.5f

const byte encoderPin = 25;
const byte picturePin = 26;5
const byte servoPin = 32;
const byte ledRed = 19;
const byte ledGreen = 5;
const byte ledBlue = 33;
volatile uint8_t interruptCounter = 0;
uint16_t numberOfInterrupts = 0;
uint32_t rev=0;
String input;
float data[5];
boolean on=false;
bool picture=true;
bool object=true;
bool triangle=false;
float cm_per_pulse=0.013998;



IRED IR(26);
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
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(encoderPin), encoderInterrupt,  CHANGE);
  pinMode(picturePin,INPUT_PULLUP);
  Servo1.setup(servoPin,2);
  data[0]=100; 
  data[1]=0; 
  digitalWrite(ledRed,LOW);
  digitalWrite(ledGreen,LOW);
  digitalWrite(ledRed,LOW);

}
 
void loop() {

  if (Serial.available()) {
		input = Serial.readStringUntil('\n');
		parseString(input, ",", data);
		//Serial.printf("%.1f,%.1f\r\n", data[0],data[1]);
      if(data[1]!=0){
        HBRIDGE.setSpeed(data[0]);
        switch((int)(data[1])){
        case 1:
          Servo1.write(0);
        break;
        case 2:
          Servo1.write(180);
        break;
        case 3:
          Servo1.write(0);
          triangle=true;
        break;
        default:
        break;
      }
      if(data[2]>180)
        digitalWrite(ledRed,HIGH); 
      else if(data[3]>130)
        digitalWrite(ledGreen,HIGH);
      else if(data[4]>140)
        digitalWrite(ledBlue,HIGH);
      } 
	}
 
  if(IR.pulse()){
      HBRIDGE.setSpeed(data[0]);
      picture=true;
      object=true;
      numberOfInterrupts=0;
      digitalWrite(ledRed,LOW);
      digitalWrite(ledGreen,LOW);
      digitalWrite(ledBlue,LOW);
      Serial.printf("0,%d,%d\n",(int)(cm_per_pulse*numberOfInterrupts),6);
  }

  if(interruptCounter>0){
 
      portENTER_CRITICAL(&mux);
      interruptCounter--;
      portEXIT_CRITICAL(&mux);
 
      numberOfInterrupts++;
      //Serial.println(numberOfInterrupts);
  }
 

  if(numberOfInterrupts==(int)(PHOTODISTANCE/cm_per_pulse)&&picture==true){
    digitalWrite(ledRed,LOW);
    digitalWrite(ledGreen,LOW);
    digitalWrite(ledBlue,LOW);
    Serial.printf("1,%d,%d\n",(int)(cm_per_pulse*numberOfInterrupts),6);
    HBRIDGE.setStop(0);
    picture=false;
      
    }

  if(numberOfInterrupts==(int)(SERVOSTOP/cm_per_pulse)&&object==true&&triangle==false){
    Serial.printf("0,%d,%d\n",(int)(cm_per_pulse*numberOfInterrupts),6);
    HBRIDGE.setStop(0);
    object=false;
      switch((int)(data[1])){
        case 1:
          Servo1.write(180);
        break;
        case 2:
          Servo1.write(0);
        break;
        case 3:
          Servo1.write(0);
        break;
        default:
        break;
        numberOfInterrupts=0;
      }
    data[1]=0.0;  
    }
    if(numberOfInterrupts==(int)(TRIANGLE/cm_per_pulse)&&object==true&&triangle==true){
      Serial.printf("0,%d,%d\n",(int)(cm_per_pulse*numberOfInterrupts),6);
      HBRIDGE.setStop(0);
      object=false;
      triangle=false;
      data[1]=0.0; 
    }

 }


