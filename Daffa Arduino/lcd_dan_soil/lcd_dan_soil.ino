#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C (0x27, 16, 2);

const int soilMoisturePin = A0;

void setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  float moisture_percentage;

  moisture_percentage = ( 100.00 - ( (analogRead(soilMoisturePin)/1023.00) * 100.00 ) );
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisture_percentage);
  lcd.print("%");

  delay(1000);
  lcd.clear();
}
