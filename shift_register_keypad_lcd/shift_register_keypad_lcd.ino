#include <Adafruit_Keypad.h>
#include <LiquidCrystal.h>

// this is the code to show numbers 0-9 for 7 segment using shift register common Anode
const int CLOCK_PIN = 10, SERIAL_PIN = 12, LATCH_PIN = 11;

// the pinsets as a binary number that display 0-9
int dataArray[10] = {
  0B00000011,
  0B10011111,
  0B00100101,
  0B00001101,
  0B10011001,
  0B01001001,
  0B01000001,
  0B00011111,
  0B00000001,
  0B00001001
}; 

const byte ROWS = 4, COLS = 4;

const char KEYS[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(KEYS), rowPins, colPins, ROWS, COLS);

const int rs = A0, enable = 13;
const int d4 = A1, d5 = A2, d6 = A3, d7 = A4;

LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

void setup() {
  customKeypad.begin();
  lcd.begin(16, 2);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(SERIAL_PIN, OUTPUT);

  // make sure it's off
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(SERIAL_PIN, CLOCK_PIN, MSBFIRST, 0B11111111);
  digitalWrite(LATCH_PIN, HIGH);
}

void loop() {
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      char key = e.bit.KEY;
      int num = (String(key)).toInt();

      if (num >= 0 && num < 10) {
        digitalWrite(LATCH_PIN, LOW);
        shiftOut(SERIAL_PIN, CLOCK_PIN, MSBFIRST, dataArray[num]);
        digitalWrite(LATCH_PIN, HIGH);
        lcd.print(key);
      }
    }

  }
  delay(200);
}
