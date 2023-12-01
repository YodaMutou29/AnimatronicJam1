#include <Servo.h>

const int SHOULDERS_PIN = 11;
const int HIPS_PIN = 10;
const int LEFT_ARM_PIN = 9;
const int RIGHT_ARM_PIN = 6;

const int WALK_SWITCH_PIN = 2;
const int JUMP_SWITCH_PIN = 3;
const int DANCE_SWITCH_PIN = 4;

Servo shoulders;
Servo hips;
Servo leftArm;
Servo rightArm;

void walk() {
  shoulders.write(15);
  hips.write(-15);
  leftArm.write(45);
  rightArm.write(90);
  delay(1000);
  shoulders.write(-15);
  hips.write(15);
  leftArm.write(90);
  rightArm.write(45);
  delay(6000);
}

void jump() {
  hips.write(0);
  leftArm.write(90);
  rightArm.write(90);
  delay(100);
  shoulders.write(0);
  hips.write(0);
  leftArm.write(90);
  rightArm.write(90);
  delay(5000);
}

void dance() {
  shoulders.write(20);
  hips.write(-30);
  shoulders.write(-20);
  hips.write(20);
  leftArm.write(-45);
  rightArm.write(45);
  shoulders.write(20);
  hips.write(-20);
  shoulders.write(20);
  hips.write(20);
  shoulders.write(20);
  leftArm.write(-45);
  rightArm.write(45);
}

void still() {
  shoulders.write(0);
  hips.write(0);
  leftArm.write(90);
  rightArm.write(90);
  delay(1000);
}

void keepMoving() {
  shoulders.write(20);
  hips.write(-20);
  leftArm.write(45);
  rightArm.write(45);
  delay(100);
}


void setup() {
  shoulders.attach(SHOULDERS_PIN);
  hips.attach(HIPS_PIN);
  leftArm.attach(LEFT_ARM_PIN);
  rightArm.attach(RIGHT_ARM_PIN);

  Serial.begin(9600);
  still();
}

void loop() {
  int walkBool = digitalRead(WALK_SWITCH_PIN);
  int jumpBool = digitalRead(JUMP_SWITCH_PIN);
  int danceBool = digitalRead(DANCE_SWITCH_PIN);

  if (walkBool == HIGH) {
    for (int i = 0; i < 10; i++) {
      walk();
    }
  } else if (jumpBool == HIGH) {
    jump();
  } else if (danceBool == HIGH)  {
      for (int i = 0; i < 200; i++) {
        keepMoving();
      }
  }
}
