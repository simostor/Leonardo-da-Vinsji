#pragma once

#include "Arduino.h"

// Used to control L298N motor controller
class MotorControl
{
    private:
    int pin1;
    int pin2;


    public:
    MotorControl();
    void setupMotorControl(const int fwdPin, const int bckwrdPin);
    void operateMotor(bool direction, int pwm);
};