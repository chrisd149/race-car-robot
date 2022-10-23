/* Source code was adopted from 
 *  https://create.arduino.cc/projecthub/diy_burner/how-to-make-arduino-human-following-robot-32ca7d 
 *  and from the Robotic Behavior assignment code.*/
// Include library for the sonar sensor
#include<NewPing.h>

// Defines some constants for the motor pins
const int in1 = 5;
const int in2 = 4;
const int in3 = 3;
const int in4 = 2;
const int enA = 6;
const int enB = 7;

// Define motor RPM
#define motorArpm 170
#define motorBrpm 170
// Defines pins for IR sensor 
#define RIGHT A2
#define LEFT A3
// Defines pins for sonar sensor
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100

// Initalize the sonar sensor  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Setup code - only ran at start-up
void setup() {
  Serial.begin(9600);
  // Define right IR sensor
  pinMode(RIGHT, INPUT);
  // Define left IR sensor
  pinMode(LEFT, INPUT);
  // Assign pins for motors
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}
    
void loop(){
  // Assign distance variable to the sonar distance
  unsigned int distance = sonar.ping_cm();

  // Assign IR sensor values to the correct variables
  // Right IR sensor
  int Right_Value = digitalRead(RIGHT);
  // Left IR sensor
  int Left_Value = digitalRead(LEFT);
  
  // Wait for 10 miliseconds
  delayMicroseconds(10);
  
  // Sonar detects distance of less than 10cm
  if(distance < 10) 
  {
    // All motors move backwards at the set rpm
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, motorArpm);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, motorBrpm);
  }
  // Sonar detects distance of more than 50cm
  else if(distance > 50 && Right_Value==0 && Left_Value==0) 
  {
    // All motors stop moving
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }
  // Sonar  detects distance between 10cm and 50cm
  else if(distance > 10 && distance < 50) 
  // Move forward
  { 
    // All motors move forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, motorArpm);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, motorBrpm);
  }
  // Left IR sensor detects an object
  if(Right_Value==0 && Left_Value==1) // Turn left
  {
    // Right motors move forward, left motors move backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 150);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 160);
  }
  // Right IR sensor detects an object
  if(Right_Value==1 && Left_Value==0) 
  // Turn right
  {
    // Right motors move backward, left motors move forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, motorArpm);  
  }
}
