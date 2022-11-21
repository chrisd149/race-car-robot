#include "Driver.h"
#include "Arduino.h"

// in1, in2, enA - Front Left
// in3, in4, enB - Front Right
// in5, in6, enC - Back Left
// in7, in8, enD - Back Right

void forward(int rpm){
  // All motors move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, rpm);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, rpm);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, rpm);

  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, rpm);
}

void forward_r(int rpm){
  // All motors move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, rpm/1.5);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, rpm);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, rpm/1.5);

  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, rpm);
}

void forward_l(int rpm){
  // All motors move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, rpm);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, rpm/1.5);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, rpm);

  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, rpm/1.5);
}

void backward(int rpm){
  // All motors move backwards at the set rpm
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, rpm);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, rpm);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, rpm);

  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, rpm);
}

void backward_r(int rpm){
  // All motors move backwards at the set rpm
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, rpm/1.5);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, rpm);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, rpm/1.5);

  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, rpm);
}

void backward_l(int rpm){
  // All motors move backwards at the set rpm
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, rpm);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, rpm/1.5);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, rpm);

  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, rpm/1.5);
}

void right(int rpm){
  // Right motors move backward, left motors move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, rpm);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, rpm);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, rpm);

  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, rpm);   
}

void left(int rpm){
  // Right motors move forward, left motors move backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, rpm);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, rpm);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, rpm);

  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, rpm);  
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
}
