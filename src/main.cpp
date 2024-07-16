#include <Arduino.h>

const uint8_t TOGGLE_RIGHT_GREEN_PIN = 6;
const uint8_t TOGGLE_LEFT_BLUE_PIN = 7;
const uint8_t TOGGLE_UP_WHITE_PIN = 8;
const uint8_t TOGGLE_UP_YELLOW_PIN = 9;
//const uint8_t PUSH_BUTTON_BROWN_PIN = 10;
const uint8_t PUSH_BUTTON_ORANGE_PIN = 11;

const uint8_t RIGHT = 2;
const uint8_t LEFT = 3;
const uint8_t HEADLIGHTS = 4;

const unsigned long debounceDelay = 50;  // debounce delay in milliseconds
unsigned long lastDebounceTime = 0;

bool lastToggleRightState = LOW;
bool lastToggleLeftState = LOW;
bool lastToggleUpState = LOW;
bool lastPushButtonState = LOW;

const uint8_t pins[] = {11, 10, 9, 8, 7, 6 };
const uint8_t relays[] = {4, 3, 2};

void setup() {
  Serial.begin(9600);

  for (uint8_t pin : pins) {
    pinMode(pin, INPUT);
  }
  for (uint8_t pin : relays) {
    pinMode(pin, OUTPUT);
  }
    /*
  pinMode(TOGGLE_RIGHT_GREEN_PIN, INPUT);
  pinMode(TOGGLE_LEFT_BLUE_PIN, INPUT);

  pinMode(TOGGLE_UP_WHITE_PIN, INPUT);
  pinMode(TOGGLE_UP_YELLOW_PIN, INPUT);
  //pinMode(PUSH_BUTTON_BROWN_PIN, INPUT);
  //pinMode(PUSH_BUTTON_ORANGE_PIN, INPUT);

  pinMode(RIGHT, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(HEADLIGHTS, OUTPUT);

  digitalWrite(RIGHT,HIGH);
  digitalWrite(LEFT,HIGH);
  digitalWrite(HEADLIGHTS,LOW);
  */
}

void flash(uint8_t pin, int wait = 750){
    digitalWrite(pin, LOW);
    delay(wait);
    digitalWrite(pin, HIGH);
    delay(wait);
}
void flash2(uint8_t pin0, uint8_t pin1, int wait = 750){
    digitalWrite(pin0, LOW);
    digitalWrite(pin1, LOW);
    delay(wait);
    digitalWrite(pin0, HIGH);
    digitalWrite(pin1, HIGH);
    delay(wait);
}
void loop() {

  bool toggleRightPressed = digitalRead(TOGGLE_RIGHT_GREEN_PIN) == HIGH;
  bool toggleLeftPressed =  digitalRead(TOGGLE_LEFT_BLUE_PIN) == HIGH;

  bool toggleUpPressed = digitalRead(8) == HIGH || digitalRead(9) == HIGH || digitalRead(10) == HIGH || digitalRead(11) == HIGH;


  if (toggleRightPressed) {
    Serial.println("Toggle Right Pressed");
    digitalWrite(RIGHT, HIGH);
  }else{
    digitalWrite(RIGHT, LOW);
  }

  if (toggleLeftPressed) {
    Serial.println("Toggle Left Pressed");
    digitalWrite(LEFT, HIGH);
  }else{
    digitalWrite(LEFT, LOW);
  }

  if (toggleUpPressed){
    Serial.println("Toggle Up Pressed");
    digitalWrite(HEADLIGHTS, HIGH);
  } else{
    digitalWrite(HEADLIGHTS, LOW);
  }


  //for (uint8_t pin : pins) {
  //Serial.print(" Pin ");
  //Serial.print(pin);
  //Serial.print(": ");
  //Serial.print(digitalRead(pin));
  //}
  //Serial.println();
}
