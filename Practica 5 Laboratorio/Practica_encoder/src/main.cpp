#include <Arduino.h>
#define D1 2
#define D2 3

volatile uint8_t count1=0;
volatile uint8_t count2=0;
bool direction=true,forward=false,backward=false;
double  angular_speed=0;
uint32_t degrees=0;
double tiempo1=0,tiempo2=0;
bool pulse=false;
uint8_t dir=0;

void isr1(){
  if(count1 < 2){
    count1++;
    pulse=false;
    }
 if(count1==2){
    pulse=true;
    tiempo2=millis();
  } 
  if(count1==1)
    tiempo1=millis(); 
}

void isr2(){
  if(count2 < 2){
    count2++;
    pulse=false;
    }
}

void setup() {
  Serial.begin(9600);
  pinMode(D1,INPUT_PULLUP);
  pinMode(D2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(D1), isr1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(D2), isr2, CHANGE);
  Serial.println("WORKING");
}

void loop() {
  if(count2>count1 && direction==true){
    forward=true;
    backward=false;
    direction=false;
    dir=1;
  }
  else if(count2<count1 && direction==true){
    backward=true;
    forward=false;
    direction=false;
    dir=0;
  }
  
  if(pulse==true){
  degrees=degrees+60;
  angular_speed=60/((tiempo2-tiempo1)/1000);
  Serial.print(angular_speed);
  Serial.print(",");
  Serial.print(degrees);
  Serial.print(",");
  Serial.println(dir);
  pulse=false;
  count1=1;
  count2=1;
  tiempo1=millis();
  }
}

