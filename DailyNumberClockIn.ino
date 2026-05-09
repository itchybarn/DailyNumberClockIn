const int startButton = 9;

void setup() {
  Serial.begin(9600);
  pinMMode(startButton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(startButton) == LOW) {
    Serial.println("Start pressed!")
    delay(200);
  }
}