#include <Adafruit_Keypad.h>

const byte ROWS = 4, COLS = 4;

const char KEYS[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(KEYS), rowPins, colPins, ROWS, COLS);

const byte RED = 10, BLUE = 11, YELLOW = 12;

void setup() {
  Serial.begin(9600);
  customKeypad.begin();

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();

    char key = e.bit.KEY;

    if (key == '1' || key == '2' || key == '3') {
      digitalWrite(key - 39, HIGH);
      delay(500);
      digitalWrite(key - 39, LOW);
    }
  }
}