#include "Driver.h"
#include "Arduino.h"

// Define motor RPM
#define motorArpm 100
#define motorBrpm 100
// in1, in2 - Front Left
// in3, in4 - Front Right
// in5, in6 - Back Left
// in7, in8 - Back Right

void forward(){
  // All motors move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(enA, motorArpm);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //analogWrite(enB, motorBrpm);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  //analogWrite(enA, motorArpm);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  //analogWrite(enB, motorBrpm);
}

void backward(){
  // All motors move backwards at the set rpm
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //analogWrite(enA, motorArpm);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  //analogWrite(enB, motorBrpm);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  //analogWrite(enA, motorArpm);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  //analogWrite(enB, motorBrpm);
}

void right(){
  // Right motors move backward, left motors move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  //analogWrite(enB, 75);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  //analogWrite(enA, 0);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  //analogWrite(enB, 75);   
}

void left(){
  // Right motors move forward, left motors move backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //analogWrite(enA, 0);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //analogWrite(enB, 75);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  //analogWrite(enA, 0);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  //analogWrite(enB, 75);  
}

void station(){
  // All motors stop moving
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  //analogWrite(enA, 0);
  //analogWrite(enB, 0);
}
