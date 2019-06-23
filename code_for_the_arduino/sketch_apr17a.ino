#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *leftMotor = AFMS.getMotor(2);

Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);

void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  pinMode(27, INPUT);
  pinMode(29, INPUT);
  pinMode(39, INPUT);
  pinMode(41, INPUT);
  leftMotor->setSpeed(230);
  rightMotor->setSpeed(230);
}

void loop() {
  if(digitalRead(27) == HIGH) {
    leftMotor->run(FORWARD);
  }
  if(digitalRead(29) == HIGH) {
    leftMotor->run(BACKWARD);
  }
  if(digitalRead(39) == HIGH) {
    rightMotor->run(FORWARD);
  }
  if(digitalRead(41) == HIGH) {
    rightMotor->run(BACKWARD);
  }
  if(digitalRead(27) == LOW && digitalRead(29) == LOW) {
    leftMotor->run(RELEASE);
  }
  if(digitalRead(39) == LOW && digitalRead(41) == LOW) {
    rightMotor->run(RELEASE);
  }
}
