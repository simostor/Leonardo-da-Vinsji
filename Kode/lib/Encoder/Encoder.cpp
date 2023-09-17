#include "Encoder.h"

volatile int Encoder::encoderPulses = 0;
const int Encoder::encoderPinA = 21;
const int Encoder::encoderPinB = 3;
volatile int Encoder::encoderAState = LOW;
volatile int Encoder::encoderBState = LOW;

Encoder::Encoder() {}

void Encoder::setupEncoder() {
    pinMode(encoderPinA, INPUT);
    pinMode(encoderPinB, INPUT);
    digitalWrite(encoderPinA, HIGH);  // enable pull-up resistors
    digitalWrite(encoderPinB, HIGH);
    attachInterrupt(digitalPinToInterrupt(encoderPinA), Encoder::countPulse, CHANGE);
}

void Encoder::countPulse() {
    int newStateA = digitalRead(encoderPinA);
    int newStateB = digitalRead(encoderPinB);

    if (newStateA != encoderAState) {
        if (newStateA != newStateB) {
            encoderPulses++;
        } else {
            encoderPulses--;
        }
        encoderAState = newStateA;
    }
    encoderBState = newStateB;
}

int Encoder::getPulses() const {
    return encoderPulses;
}

