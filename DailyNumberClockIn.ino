const int startButton = 9;
const int stopButton = 8;

void setup() {
  Serial.begin(9600);
  pinMode(startButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(startButton) == LOW) {
    Serial.println("Start pressed!");
    delay(200);
  }

  if (digitalRead(stopButton) == LOW) {
    Serial.println("Stop pressed!");
    delay(200);
  }
}