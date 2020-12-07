#include "ESP_SERVO.h"
#include "PWM_ESP32.h"

ESPServo::ESPServo()
{

}

ESPServo::~ESPServo()
{

}

void ESPServo::setup(uint8_t pin, uint8_t channel, bool on_state)
{
    CONTROL_PIN.setup(pin, channel,50, 16, on_state);
}

void ESPServo::write(uint16_t value)
{
    // treat values less than MIN_PULSE_WIDTH (800) as angles in degrees (valid values in microseconds are handled as microseconds)
    if (value < MIN_PULSE_WIDTH)
    {
        if (value < 0)
            value = 0;
        else if (value > 360)
            value = 360;

        value = map(value, 0, 360,MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    }
    writeMicroseconds(value);
}

void ESPServo::writeMicroseconds(uint16_t value)
{
        if (value < MIN_PULSE_WIDTH)          // ensure pulse width is valid
            value = MIN_PULSE_WIDTH;
        else if (value > MAX_PULSE_WIDTH)
            value = MAX_PULSE_WIDTH;

        value = usToTicks(value);  // convert to ticks
        _ticks = value;
        // do the actual write
        CONTROL_PIN.write(_ticks);
}


int ESPServo::usToTicks(int usec)
{
    return (int)((float)usec / ((float)REFRESH_USEC / (float)DEFAULT_TIMER_WIDTH_TICKS));
}