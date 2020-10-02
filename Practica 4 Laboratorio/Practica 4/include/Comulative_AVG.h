#ifndef _RGB_LED_h
#define _RGB_LED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class AVG{
public:
    AVG();
    ~AVG();
    float avg(float dato);
    void resetAvg();

private:

    float _acumulative_avg;
    uint16_t _count=0;
};

#endif
