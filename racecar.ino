/* Source code was adopted from 
 *  https://create.arduino.cc/projecthub/diy_burner/how-to-make-arduino-human-following-robot-32ca7d 
 *  and from the Robotic Behavior assignment code.*/
// Include library for the sonar sensor
#include <SoftwareSerial.h> 
#include "libraries/NewPing/src/NewPing.cpp"
#include "src/Driver.c"

// Defines pins for IR sensor 
#define RIGHT A2
#define LEFT A3
// Defines pins for sonar sensor
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100

int flag = 0; 
int LED = 8; 
bool mode = true;
bool debug = true;

// Initalize the sonar sensor  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// Initalize the bluetooth module
SoftwareSerial MyBlue(2, 3); // RX | TX 

// Setup code - only ran at start-up
void setup() {
  Serial.begin(9600);
  MyBlue.begin(9600);
  // Define right IR sensor
  pinMode(RIGHT, INPUT);
  // Define left IR sensor
  pinMode(LEFT, INPUT);
  // Assign pins for motors
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

int check_sensors(){
  return 1;
}

void loop(){
  int delay = 10;
  
  // Assign distance variable to the sonar distance
  unsigned int distance = sonar.ping_cm();

  // Assign IR sensor values to the correct variables
  // Right IR sensor
  int Right_Value = digitalRead(RIGHT);
  // Left IR sensor
  int Left_Value = digitalRead(LEFT);

  if (debug == true){
    delay = 500;
  }
  
  /**
  if (check_sensors()== 1){
    continue;
  if (check_sensors()== 2){
    continue; 
  if (check_sensors()== 2){
    continue; 
  }**/
  
  if (mode == false){
    
  }
  if (mode == true){
    // Sonar detects distance of less than 10cm
    if(distance < 10) 
    {
      backward();
      if (debug == true){
        Serial.print("Back");
        Serial.print(distance);
        Serial.print(Right_Value, Left_Value);
      }
    }
    // Sonar detects distance of more than 50cm
    else if(distance > 50 && Right_Value==0 && Left_Value==0) 
    {
      station();
      if (debug == true){
        Serial.print("Stop");
        Serial.print(distance);
        Serial.print(Right_Value, Left_Value);
      }
    }
    // Sonar  detects distance between 10cm and 50cm
    else if(distance > 10 && distance < 50) 
    // Move forward
    { 
      forward();
      if (debug == true){
        Serial.print("Forward");
        Serial.print(distance);
        Serial.print(Right_Value, Left_Value);
      }
    }
    // Left IR sensor detects an object
    if(Right_Value==0 && Left_Value==1) // Turn left
    {
      left();
      if (debug == true){
        Serial.print("Left");
        Serial.print(distance);
        Serial.print(Right_Value, Left_Value);
      }
    }
    // Right IR sensor detects an object
    if(Right_Value==1 && Left_Value==0) 
    // Turn right
    {
      right();
      if (debug == true){
        Serial.print("Right");
        Serial.print(distance);
        Serial.print(Right_Value, Left_Value);
      }
    }
  }
  delayMicroseconds(delay);
}
