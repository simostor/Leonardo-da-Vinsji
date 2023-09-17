#pragma once

#include "Arduino.h"


class Encoder
{
    public:
    volatile int encoderPulses = 0;
    void countPulse();
}

