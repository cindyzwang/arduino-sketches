/*
  Arduino Starter Kit example
  Project 4 - Color Mixing Lamp

  This sketch is written to accompany Project 3 in the Arduino Starter Kit

  Parts required:
  - one RGB LED
  - three 10 kilohm resistors
  - three 220 ohm resistors
  - three photoresistors
  - red green and blue colored gels

  created 13 Sep 2012
  modified 14 Nov 2012
  by Scott Fitzgerald
  Thanks to Federico Vanzati for improvements

  http://www.arduino.cc/starterKit

  This example code is part of the public domain.
*/

const int redLEDPin = 9;
const int greenLEDPin = 10;
const int blueLEDPin = 11;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  // set the digital pins as outputs
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {

  /*
    Now that you have a usable value, it's time to PWM the LED.
  */
  for (int r = 0; r < 256; r++) {
    for (int g = 0; g < 256; g++) {
      for (int b = 0; b < 256; b++) {
          analogWrite(redLEDPin, r);
          analogWrite(greenLEDPin, g);
          analogWrite(blueLEDPin, b);
      }
    }
  }
}
