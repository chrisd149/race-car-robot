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
  digitalWrite(enA, rpm);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enB, rpm);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(enC, rpm);

  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  digitalWrite(enD, rpm);
}

void backward(int rpm){
  // All motors move backwards at the set rpm
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(enA, rpm);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enB, rpm);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(enC, rpm);

  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  digitalWrite(enD, rpm);
}

void right(int rpm){
  // Right motors move backward, left motors move forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(enA, rpm);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(enB, rpm);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(enC, rpm);

  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  digitalWrite(enD, rpm);   
}

void left(int rpm){
  // Right motors move forward, left motors move backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(enA, rpm);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(enB, rpm);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(enC, rpm);

  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  digitalWrite(enD, rpm);  
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
