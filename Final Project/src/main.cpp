#include <Arduino.h>

const byte encoderPin = 25;
const byte picturePin = 26;
volatile uint8_t interruptCounter = 0;
volatile uint8_t interruptCounter2 = 0;
uint8_t numberOfInterrupts = 0;
uint rev=0;
uint32_t tiempo=0;
float speed=0;
uint8_t pulse=0;
int contador = 0;
bool dato = LOW;
bool datoAnterior = LOW;
 
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

  
dato = digitalRead(26);
 if (dato == HIGH && datoAnterior == LOW)
 {
  Serial.println("Pic");
   }
 datoAnterior = dato;

  if(numberOfInterrupts==228){
    rev++;
    Serial.println(rev);
    numberOfInterrupts=0;
    }

    
}


