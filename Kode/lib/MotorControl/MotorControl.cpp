#include "MotorControl.h"

int pwm = 0; // Initialize pwm to be zero
bool dir;


MotorControl::MotorControl(){}

void MotorControl::setupMotorControl(const int fwdPin, const int bckwrdPin)
{
    pin1 = fwdPin;
    pin2 = bckwrdPin;
}

void MotorControl::operateMotor(bool direction, int pwm)
{
    if(direction == true)
    {
        analogWrite(pin2, 0);
        analogWrite(pin1, pwm);
    }
    else
    {
        analogWrite(pin1, 0);
        analogWrite(pin2, pwm);
    }
}
