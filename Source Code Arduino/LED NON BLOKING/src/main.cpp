#include <Arduino.h>

const int LED_INTERNAL = LED_BUILTIN;
const int LED_EXTERNAL = 8;

// Timer LED internal
unsigned long previousMillisInternal = 0;
const unsigned long intervalInternal = 500;

// Timer LED eksternal
unsigned long previousMillisExternal = 0;
const unsigned long intervalExternal = 2000;

// Timer Serial
unsigned long previousMillisSerial = 0;
const unsigned long intervalSerial = 1000;

// Status LED
bool stateInternal = LOW;
bool stateExternal = LOW;

// Counter Serial
unsigned long counter = 0;

void setup() {

  pinMode(LED_INTERNAL, OUTPUT);
  pinMode(LED_EXTERNAL, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  unsigned long currentMillis = millis();

  // LED bawaan Arduino
  if (currentMillis - previousMillisInternal >= intervalInternal) {

    previousMillisInternal = currentMillis;

    stateInternal = !stateInternal;

    digitalWrite(LED_INTERNAL, stateInternal);
  }

  // LED eksternal
  if (currentMillis - previousMillisExternal >= intervalExternal) {

    previousMillisExternal = currentMillis;

    stateExternal = !stateExternal;

    digitalWrite(LED_EXTERNAL, stateExternal);
  }

  // Serial Monitor
  if (currentMillis - previousMillisSerial >= intervalSerial) {

    previousMillisSerial = currentMillis;

    Serial.println(counter);

    counter++;
  }
}