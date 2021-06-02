// this is the code to show numbers 0-9 for 7 segment using shift register common Anode
const int CLOCK_PIN = 9, SERIAL_PIN = 8, LATCH_PIN = 10;

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


void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(SERIAL_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(SERIAL_PIN, CLOCK_PIN, MSBFIRST, dataArray[i]);
    digitalWrite(LATCH_PIN, HIGH);
    delay(1000);
  }
}
