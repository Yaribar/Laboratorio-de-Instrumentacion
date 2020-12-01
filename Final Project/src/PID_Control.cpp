// 
// 
// 

#include "PID_Control.h"

PIDCONTROL::PIDCONTROL(float kp, float kd, float ki)
{
	_kp = kp;
	_kd = kd;
	_ki = ki;
}

float PIDCONTROL::Data(float error,float interval_i, float elapsed_time)
{
	_pid_p = _kp*error;
	_interval_i = interval_i;
	_elapsed_time = elapsed_time;
	if ((-1*(_interval_i)) <error <_interval_i)
	{
	_pid_i += (_ki*error);
	}
	_pid_d = _kd*((error - _previous_error) / _elapsed_time);
	_pid = _pid_p + _pid_i + _pid_d;
	_previous_error = _elapsed_time;
	return _pid;
}
