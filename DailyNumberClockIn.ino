#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int startButton = 9;
const int stopButton = 8;

int countdown = 10;
const int originalCountdown = countdown;
bool running = false;
unsigned long lastTick = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.noCursor();
  pinMode(startButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(startButton) == LOW) {
    running = true;
    delay(200);
  }

  if (digitalRead(stopButton) == LOW) {
    running = false;
    delay(200);
  }

  if (millis() - lastTick >= 1000) {
    lastTick = millis();
    
    lcd.clear();

    lcd.setCursor(0, 1);
    lcd.print(String(countdown) + "/" + String(originalCountdown));
    if (countdown <= 0) {
      lcd.print(" DONE!");
    }

    lcd.setCursor(0, 0);
    if (running) {
      countdown--;
      lcd.print("CLOCKED IN");
    } else {
      lcd.print("CLOCKED OUT");
    }
  }
}