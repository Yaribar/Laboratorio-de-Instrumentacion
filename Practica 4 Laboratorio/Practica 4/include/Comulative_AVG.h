#ifndef _COMULATIVE_AVG_h
#define _COMULATIVE_AVG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class AVG{
public:
    AVG();
    ~AVG();
    void avg(uint16_t dato);
    void resetAvg();
    float getCurrentAvg();
private:

    float _acumulative_avg=0.0;
    float _count=0.0;
};

#endif
