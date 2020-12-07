#ifndef _ESP_SERVO_h
#define _ESP_SERVO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "PWM_ESP32.h"

#define CLOCKWISE 0
#define COUNTERCLOCKWISE 1
//Servo VIGOR VS 2
#define MIN_PULSE_WIDTH       800     // the shortest pulse sent to a servo  
#define MAX_PULSE_WIDTH      2200     // the longest pulse sent to a servo 
#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define REFRESH_USEC         20000
#define DEFAULT_TIMER_WIDTH_TICKS 65536
#define DEFAULT_TIMER_WIDTH 16

class ESPServo
{
    public:
        ESPServo();
        ~ESPServo();
        PWM CONTROL_PIN;
        void setup(uint8_t pin, uint8_t channel, bool on_state = HIGH);
        void write(uint16_t value); // if value is < MIN_PULSE_WIDTH its treated as an angle, otherwise as pulse width in microseconds
        void writeMicroseconds(uint16_t value);
        int usToTicks(int usec);
    
    private:
        int _ticks = DEFAULT_TIMER_WIDTH_TICKS;    
};

#endif