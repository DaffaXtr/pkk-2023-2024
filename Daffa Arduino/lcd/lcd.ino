#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C (0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Saya Daffaaa");
  delay(1000);

  lcd.setCursor(0, 1);
  lcd.print("THANNKS");
  delay(800);

  lcd.clear();
  
  
  // Additional LCD control code
}
