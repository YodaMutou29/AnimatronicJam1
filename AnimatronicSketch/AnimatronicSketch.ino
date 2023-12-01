#include <Servo.h>

int const LEFT_KNEE_PIN = 9;
int const RIGHT_KNEE_PIN = 10;

const int WALK_SWITCH_PIN = 2;
const int JUMP_SWITCH_PIN = 3;
const int DANCE_SWITCH_PIN = 4;

Servo leftKnee;
Servo rightKnee;

int leftKneeAngle = 30;
int rightKneeAngle = 60;

int leftKneeAngleReading = 0;
int rightKneeAngleReading = 0;

void readAngles() {
  leftKneeAngleReading = analogRead(LEFT_KNEE_PIN);
  rightKneeAngleReading = analogRead(RIGHT_KNEE_PIN);
}

void printAngles() {
  Serial.print("Left knee angle: ");
  Serial.print(leftKneeAngleReading);
  Serial.print(" Right knee angle: ");
  Serial.print(rightKneeAngleReading);
}

void walk() {
  rightKnee.write(0);
  leftKnee.write(90);
  delay(1000);
  rightKnee.write(90);
  leftKnee.write(0);
  delay(1000);
}

void jump() {
  leftKnee.write(0);
  rightKnee.write(0);
  delay(1000);
  leftKnee.write(90);
  rightKnee.write(90);
  delay(1000);
}

void dance() {

}

void still() {
  leftKnee.write(0);
  rightKnee.write(0);
  delay(1000);
}

void setup() {
  leftKnee.attach(LEFT_KNEE_PIN);
  rightKnee.attach(RIGHT_KNEE_PIN);

  Serial.begin(9600);
  still();
}

void loop() {
  readAngles();
  printAngles();

  int walkBool = digitalRead(WALK_SWITCH_PIN);
  int jumpBool = digitalRead(JUMP_SWITCH_PIN);
  int danceBool = digitalRead(DANCE_SWITCH_PIN);

  if (walkBool == HIGH) {
    for (int i = 0; i < 5; i++) {
      walk();
    }
    delay(5000);
  } else if (jumpBool == HIGH) {
    jump();
    delay(5000);
  } else {
    still();
  }
}
