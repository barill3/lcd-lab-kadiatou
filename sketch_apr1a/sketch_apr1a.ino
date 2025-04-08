#include <LiquidCrystal.h>
const int buttonPin = 3;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(buttonPin, 3);
  lcd.begin(16, 2);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  lcd.clear();
  lcd.print("Press to Start");
  
  while (digitalRead(buttonPin) == HIGH) {}
  
  delay(200);
  
  reactionGame();
}

void reactionGame() {
  lcd.clear();
  lcd.print("kadiatou ?");

  int rand = random(3000, 6000);
  delay(rand);
  
  lcd.clear();
  lcd.print("1234");
  
  unsigned long startTime = millis();

  while(digitalRead(buttonPin) == HIGH) {}

  unsigned long reactionTime = millis()-startTime;

  lcd.clear();
  lcd.print("ABCD:");
  lcd.setCursor(0, 1);      
  lcd.print(reactionTime);  
  lcd.print(" ms");
  
  delay(3000);  
}