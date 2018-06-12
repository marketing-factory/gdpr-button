#include <Keyboard.h>

const int buttonPin = 2;
const char lockSequence[] = {
  KEY_LEFT_CTRL,
  KEY_LEFT_GUI, // Left-Cmd-Key / Left-Windows-Key
  'q'
};

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (LOW == digitalRead(buttonPin)) {
    for (int i = 0; i < sizeof(lockSequence); i++) {
      Keyboard.press(lockSequence[i]);
    }
    delay(100);
    Keyboard.releaseAll();
  }

  delay(500);
}
