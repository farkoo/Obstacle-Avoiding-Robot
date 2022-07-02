#include <AFMotor.h>  // include AFMotor library

AF_DCMotor motorLeft(4);  // left motor connected to M4
AF_DCMotor motorRight(3); // right motor connected to M3

#define trig 20 // trig pin connected to PIN 20
#define echo 21 // echo pin connected to PIN 21

float timePassed, distance; // timePassed & distance variables


void setup() {  // setup routine
  // put your setup code here, to run once:
  motorLeft.setSpeed(250);  // set left motor speed
  motorLeft.run(RELEASE); // release left motor
  motorRight.setSpeed(200); // set right motor speed
  motorRight.run(RELEASE);  // release right motor
  pinMode(trig, OUTPUT);  // set trig PIN as output
  pinMode(echo, INPUT); // set echo PIN as input
}


void loop() { // loop routine
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW); // reset trig PIN
  delayMicroseconds(2); // delay 2 ms
  digitalWrite(trig, HIGH); // set trig PIN
  delayMicroseconds(10);  // delay 10 ms
  digitalWrite(trig, LOW);  // reset trig PIN
  timePassed = pulseIn(echo, HIGH); // calculate round trip time
  distance = timePassed * 0.0343 / 2; // calculate distance
  if ( distance > 50 )  // no barrier
  {
    motorLeft.run(FORWARD); // go forward
    motorRight.run(FORWARD);  // go forward
    delay(100); // delay 100 ms
  }
  else  // barrier
  {
    motorLeft.run(RELEASE); // release left motor
    motorRight.run(RELEASE);  // release right motor
    delay(100); // delay 100 ms
    motorLeft.run(FORWARD); // turn right
    motorRight.run(BACKWARD); // turn right
    delay(500); // delay 500 ms
    motorLeft.run(RELEASE); // release left motor
    motorRight.run(RELEASE);  // release right motor
    delay(100); // delay 100 ms
  }
}