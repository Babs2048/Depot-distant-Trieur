#include <Arduino.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() {
  // Initialise la liaison avec le terminal
  Serial.begin(115200);

  // Initialise l'écran LCD
  Wire1.setPins(15, 5);
  lcd.begin(16, 2, LCD_5x8DOTS, Wire1);
  lcd.setRGB(255,255,0); // Rétroéclairage Rouge
  lcd.printf("Trieur de balles");
  pinMode(0, INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);



}

void loop() {
int BP0=digitalRead(0);
int BP1=digitalRead(2);
int BP2=digitalRead(12);
int Pot=analogRead(33);

Serial.print("Pot=");
Serial.println(Pot);

lcd.setCursor(0,1);
lcd.print("Pot=");
lcd.print(Pot);
lcd.print("");
  

}
