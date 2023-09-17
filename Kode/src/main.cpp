#include "Arduino.h"
#include "Encoder.h"

Encoder encoder;

void setup() {
    Serial.begin(9600);
    encoder.setupEncoder();
}

void loop() {
    Serial.println(encoder.getPulses());
    delay(100);
}
