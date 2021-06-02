const int LED_PIN_A = 2, LED_PIN_B = 3, LED_PIN_C = 4, LED_PIN_D = 5, LED_PIN_E = 6, LED_PIN_F = 7, LED_PIN_G = 8;

const int ZERO_PINS[] = {LED_PIN_A, LED_PIN_B, LED_PIN_C, LED_PIN_D, LED_PIN_E, LED_PIN_F};
const int ONE_PINS[] = {LED_PIN_B, LED_PIN_C};
const int TWO_PINS[] = {LED_PIN_A, LED_PIN_B, LED_PIN_G, LED_PIN_E, LED_PIN_D};
const int THREE_PINS[] = {LED_PIN_A, LED_PIN_B, LED_PIN_G, LED_PIN_C, LED_PIN_D};
const int FOUR_PINS[] = {LED_PIN_F, LED_PIN_G, LED_PIN_B, LED_PIN_C};
const int FIVE_PINS[] = {LED_PIN_A, LED_PIN_F, LED_PIN_G, LED_PIN_C, LED_PIN_D};
const int SIX_PINS[] = {LED_PIN_A, LED_PIN_F, LED_PIN_E, LED_PIN_D, LED_PIN_C, LED_PIN_G};
const int SEVEN_PINS[] = {LED_PIN_A, LED_PIN_B, LED_PIN_C};
const int EIGHT_PINS[] = {LED_PIN_A, LED_PIN_B, LED_PIN_C, LED_PIN_D, LED_PIN_E, LED_PIN_F, LED_PIN_G};
const int NINE_PINS[] = {LED_PIN_A, LED_PIN_B, LED_PIN_C, LED_PIN_D, LED_PIN_F, LED_PIN_G};

void setup() {
  pinMode(LED_PIN_A, OUTPUT);
  pinMode(LED_PIN_B, OUTPUT);
  pinMode(LED_PIN_C, OUTPUT);
  pinMode(LED_PIN_D, OUTPUT);
  pinMode(LED_PIN_E, OUTPUT);
  pinMode(LED_PIN_F, OUTPUT);
  pinMode(LED_PIN_G, OUTPUT);

  turnOffAllPins();
}

void loop() {
  for (int digit = 9; digit >= 0; digit--) {
    displayDigit(digit);
    delay(1000);
    turnOffAllPins();
  }
}

void loading() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(ZERO_PINS[i], LOW);
    delay(500);
    digitalWrite(ZERO_PINS[i], HIGH);
  }
}

void displayDigit(int digit) {
  const int* pins;
  int count;

  switch(digit) {
    case 0:
      pins = ZERO_PINS;
      count = 6;
      break;
    case 1:
      pins = ONE_PINS;
      count = 2;
      break;
    case 2:
      pins =  TWO_PINS;
      count = 5;
      break;
    case 3:
      pins = THREE_PINS;
      count = 5;
      break;
    case 4:
      pins = FOUR_PINS;
      count = 4;
      break;
    case 5:
      pins = FIVE_PINS;
      count = 5;
      break;
    case 6:
      pins = SIX_PINS;
      count = 6;
      break;
    case 7:
      pins = SEVEN_PINS;
      count = 3;
      break;
    case 8:
      pins = EIGHT_PINS;
      count = 7;
      break;
    case 9:
      pins = NINE_PINS;
      count = 6;
      break;
    default:
      return;
  }

  for (int pin = 0; pin < count; pin++) {
    digitalWrite(pins[pin], LOW);
  }
}

void turnOffAllPins() {
  // HIGH is off
  for (int i = 0; i < 7; i++) {
    digitalWrite(EIGHT_PINS[i], HIGH);
  }
}
