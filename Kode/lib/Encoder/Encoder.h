#pragma once

#include "Arduino.h"

class Encoder {
private:
    static volatile int encoderPulses;
    static const int encoderPinA;
    static const int encoderPinB;
    static volatile int encoderAState;
    static volatile int encoderBState;

public:
    Encoder();
    static void countPulse();
    int getPulses() const;
    void setupEncoder();
};

