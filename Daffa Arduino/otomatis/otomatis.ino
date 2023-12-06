#define BLYNK_TEMPLATE_ID "TMPL6Bq3X8yuf"
#define BLYNK_TEMPLATE_NAME "testt"
#define BLYNK_AUTH_TOKEN "KBrljnt6kCloNqblMHFOM7M2r7KZtpKp"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "yaaa";
char pass[] = "20052005";

BlynkTimer timer;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C (0x27, 16, 2);
const int soilMoisturePin = A0;

void moisture() {
  int value = analogRead(A0);
  value = ( 100.00 - ( (analogRead(soilMoisturePin)/1023.00) * 100.00 ) );
  Blynk.virtualWrite(V0, value);
  Serial.println(value);

  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(value);
  lcd.print("%");

  if (value < 20) {
    digitalWrite(16, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor is ON ");
  } else if (value > 30) {
    digitalWrite(16, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor is OFF");
  }
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  pinMode(16, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(100L, moisture);
}

void loop()
{
  Blynk.run();
  timer.run();
}

