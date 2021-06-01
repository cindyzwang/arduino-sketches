#include <LiquidCrystal.h>

const int rs = 12, enable = 11;
const int d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

int randNumbers[27];

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  
  for (int i = 0; i < 27; i++) {
    randNumbers[i] = random(9);
    lcd.print(randNumbers[i]);
    lcd.scrollDisplayLeft();
    lcd.print(" ");
    delay(500);
  }
}
