#include <Arduino.h>

const uint8_t TOGGLE_RIGHT_RED_PIN = 5;
const uint8_t TOGGLE_RIGHT_GREEN_PIN = 6;
const uint8_t TOGGLE_LEFT_RED_PIN = 5;
const uint8_t TOGGLE_LEFT_BLUE_PIN = 7;
const uint8_t TOGGLE_UP_WHITE_PIN = 8;
const uint8_t TOGGLE_UP_YELLOW_PIN = 9;
const uint8_t PUSH_BUTTON_BROWN_PIN = 10;
const uint8_t PUSH_BUTTON_ORANGE_PIN = 11;

const unsigned long debounceDelay = 50;  // debounce delay in milliseconds
unsigned long lastDebounceTime = 0;

bool lastToggleRightState = LOW;
bool lastToggleLeftState = LOW;
bool lastToggleUpState = LOW;
bool lastPushButtonState = LOW;

void setup() {
  Serial.begin(9600);

  pinMode(TOGGLE_RIGHT_RED_PIN, INPUT);
  pinMode(TOGGLE_RIGHT_GREEN_PIN, INPUT);
  pinMode(TOGGLE_LEFT_RED_PIN, INPUT);
  pinMode(TOGGLE_LEFT_BLUE_PIN, INPUT);
  pinMode(TOGGLE_UP_WHITE_PIN, INPUT);
  pinMode(TOGGLE_UP_YELLOW_PIN, INPUT);
  pinMode(PUSH_BUTTON_BROWN_PIN, INPUT);
  pinMode(PUSH_BUTTON_ORANGE_PIN, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  bool toggleRightPressed = digitalRead(TOGGLE_RIGHT_RED_PIN) == HIGH && digitalRead(TOGGLE_RIGHT_GREEN_PIN) == HIGH;
  bool toggleLeftPressed = digitalRead(TOGGLE_LEFT_RED_PIN) == HIGH && digitalRead(TOGGLE_LEFT_BLUE_PIN) == HIGH;
  bool toggleUpPressed = digitalRead(TOGGLE_UP_WHITE_PIN) == HIGH && digitalRead(TOGGLE_UP_YELLOW_PIN) == HIGH;
  bool pushButtonPressed = digitalRead(PUSH_BUTTON_BROWN_PIN) == HIGH && digitalRead(PUSH_BUTTON_ORANGE_PIN) == HIGH;

  if (toggleRightPressed != lastToggleRightState) {
    lastDebounceTime = currentMillis;
    lastToggleRightState = toggleRightPressed;
  }

  if (toggleLeftPressed != lastToggleLeftState) {
    lastDebounceTime = currentMillis;
    lastToggleLeftState = toggleLeftPressed;
  }

  if (toggleUpPressed != lastToggleUpState) {
    lastDebounceTime = currentMillis;
    lastToggleUpState = toggleUpPressed;
  }

  if (pushButtonPressed != lastPushButtonState) {
    lastDebounceTime = currentMillis;
    lastPushButtonState = pushButtonPressed;
  }

  if ((currentMillis - lastDebounceTime) > debounceDelay) {
    if (toggleRightPressed) {
      Serial.println("Toggle Right Pressed");
    }
    if (toggleLeftPressed) {
      Serial.println("Toggle Left Pressed");
    }
    if (toggleUpPressed) {
      Serial.println("Toggle Up Pressed");
    }
    if (pushButtonPressed) {
      Serial.println("Push Button Pressed");
    }
  }

  delay(10);
}
