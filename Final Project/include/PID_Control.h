// PID_Control.h

#ifndef _PID_CONTROL_h
#define _PID_CONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class PIDCONTROL {
public:
	PIDCONTROL(float kp,float kd, float ki);
	float Data(float error, float interval_i, float time);
private:
	float _kp = 0, _kd = 0, _ki = 0;
	float _pid, _pid_p, _pid_d, _pid_i;
	float _interval_i, _previous_error = 0, _elapsed_time;
};

#endif

