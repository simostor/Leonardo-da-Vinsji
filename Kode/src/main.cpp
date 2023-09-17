#include "Arduino.h"



// define pins for encoder
const int encoderPinA = 21;
const int encoderPinB = 3;

// define variables for encoder state and pulse count
volatile int encoderAState = LOW;
volatile int encoderBState = LOW;
volatile int encoderPulses = 0;


void countPulse() {
  // read current state of encoder pins
  int newStateA = digitalRead(encoderPinA);
  int newStateB = digitalRead(encoderPinB);

  // check if the A state has changed
  if (newStateA != encoderAState) {
    // if A and B states are different, we have a pulse
    if (newStateA != newStateB) {
      encoderPulses++;
    }
    // otherwise, we have a direction change
    else {
      encoderPulses--;
    }

    // update A state
    encoderAState = newStateA;
  }

  // update B state
  encoderBState = newStateB;
}




void setup() {
  // set encoder pins as inputs
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);

  // enable pullup resistors on encoder pins
  digitalWrite(encoderPinA, HIGH);
  digitalWrite(encoderPinB, HIGH);

  // set up interrupt on encoder pin A
  attachInterrupt(digitalPinToInterrupt(encoderPinA), countPulse, CHANGE);

  // start serial communication
  Serial.begin(9600);
}

void loop() {
  // print the pulse count to the serial monitor
  Serial.println(encoderPulses);

  // wait a short time to avoid overloading the serial monitor
  delay(100);
}

