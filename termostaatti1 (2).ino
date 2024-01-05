// C++ code

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

#define sensorPin A0
#define targetTempPin A1
#define heatingPin 6
#define coolingPin 5
#define redPin 4
#define bluePin 3
#define greenPin 2

#define MIN_TEMP 15
#define MAX_TEMP 25


float targetTemperature = 0;
float currentTemperature = 0;
int margin = 1;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Set: 15-25 C     ");
  lcd.setCursor(0, 1);
  lcd.print("Now: --.- C     ");
  pinMode(heatingPin, OUTPUT);
  pinMode(coolingPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  targetTemperature = map(analogRead(targetTempPin), 0, 1023, MIN_TEMP, MAX_TEMP);
  currentTemperature = analogRead(sensorPin);
  currentTemperature = (currentTemperature * 5.0 * 100.0) / 1024.0;

  lcd.setCursor(5, 0);
  lcd.print(targetTemperature);
  lcd.setCursor(5, 1);
  lcd.print(currentTemperature, 1);
  lcd.print(" C   ");

if (currentTemperature < (targetTemperature - margin)) {
    digitalWrite(heatingPin, HIGH); // Kytketään lämmitys päälle
    digitalWrite(coolingPin, LOW); // Kytketään jäähdytys pois päältä
    digitalWrite(redPin, LOW); // Punainen LED pois päältä
    digitalWrite(bluePin, LOW); // Sininen LED pois päältä
    digitalWrite(greenPin, HIGH); // Vihreä LED päälle

  } else if (currentTemperature > (targetTemperature + margin + 2)) {
    digitalWrite(heatingPin, LOW); // Kytketään lämmitys pois päältä
    digitalWrite(coolingPin, HIGH); // Kytketään jäähdytys päälle
    digitalWrite(redPin, LOW); // Punainen LED pois päältä
    digitalWrite(bluePin, HIGH); // Sininen LED päälle
    digitalWrite(greenPin, LOW); // Vihreä LED pois päältä

  } else {
    digitalWrite(heatingPin, LOW); // Kytketään lämmitys pois päältä
    digitalWrite(coolingPin, LOW); // Kytketään jäähdytys pois päältä
    digitalWrite(redPin, HIGH); // Punainen LED päälle
    digitalWrite(bluePin, LOW); // Sininen LED pois päältä
    digitalWrite(greenPin, LOW); // Vihreä LED pois päältä
  }
  delay(1000); // Pieni viive
}

