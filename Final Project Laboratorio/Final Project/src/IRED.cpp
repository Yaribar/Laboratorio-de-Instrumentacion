#include "IRED.h"

#define SAMPLING_PERIOD 200

uint8_t count=0;
uint32_t start_time =0;
bool datoAnterior = LOW;
bool dato = LOW;
bool val=LOW;

IRED::IRED(uint8_t pin){
    _pin=pin;
}

IRED::~IRED(){

}

bool IRED::pulse(){

    dato = digitalRead(_pin);
  if (dato == HIGH &&  datoAnterior ==LOW)
  {  
    count++;
      if(count==1){
        start_time = millis();
        val=true;
        return true;
      }
      if (millis() - start_time > SAMPLING_PERIOD && val == true) {
		    start_time = 0;
        count=0;
        val=false;
	    }
    
  }
  datoAnterior=dato;
  return false;
}