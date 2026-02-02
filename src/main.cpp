#include <Arduino.h>
#include "rgb_lcd.h"
#include <ESP32Encoder.h> // https://github.com/madhephaestus/ESP32Encoder.git 
 
#define CLK 23 // CLK ENCODER 
#define DT 19 // DT ENCODER

rgb_lcd lcd;
int pwm = 27;
int frequence = 25000;
int canal = 0;
int resolution = 11;
ESP32Encoder encoder;

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
  pinMode(26, OUTPUT);
  ledcSetup(canal, frequence, resolution);
  ledcAttachPin(pwm, canal);
  ledcWrite(canal, 0);
  encoder.attachHalfQuad ( DT, CLK );
  encoder.setCount ( 0 );

}

void loop() {

int BP0=digitalRead(0);
int BP1=digitalRead(2);
int BP2=digitalRead(12);
int Pot=analogRead(33);
//Serial.print("Pot=");
//Serial.println(Pot);
long newPosition = encoder.getCount() / 2;
Serial.println(newPosition);

if (BP0 == 0) { // bouton appuyé (car PULLUP)
   digitalWrite(26, HIGH); // active la sortie 
   } 
else { digitalWrite(26, LOW); // désactive la sortie 
  }


lcd.setCursor(0,1);
lcd.print("Pot=");
lcd.print(Pot);
lcd.print("");
int duty = map(Pot, 0, 4095, 0, 2047); 
ledcWrite(canal, duty);

}
