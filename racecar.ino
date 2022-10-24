#include <SoftwareSerial.h> 
#include "lib/NewPing/src/NewPing.cpp"
#include "src/Driver.c"

// Defines pins for IR sensor 
#define RIGHT A2
#define LEFT A3
// Defines pins for sonar sensor
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100

int flag = 0; 
char data;
bool mode = false;
bool debug = true;

// Initalize the sonar sensor  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// Initalize the bluetooth module
SoftwareSerial tooth(4, 5); // RX | TX 

// Setup code - only ran at start-up
void setup() {
  Serial.begin(9600);
  tooth.begin(9600);
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
  // TODO: add checks
  return 1;
}

void drive(){
// Drive command sent, send to Driver input
  switch (data){
  case 'S':
    // No user input - stop 
    station();
    break;
  case 'F':
    // Forward
    forward();
    break;
  case 'B':
    // Backward
    backward();
    break;
  case 'R':
    // Right
    right();
    break;
  case 'L':
    // Left
    left();
    break;
  default:
    // No input at all - stop 
    // TODO: LOS stuff
    station();
    break;
  }
}

char input(){
  // Check bluetooth is connected
  if (tooth.available() > 0){
    // Read Bluetooth data (should be a single digit char)
    return tooth.read();
  }
  else{
    return ':';
  }
}

void output(int sonar, int command){
  // Send Serial stuff to app
  tooth.write(sonar); // In cm
  tooth.write(command); 
}

void loop(){
  data = input();
  if (data == ':'){
    Serial.print("No signal");
  }
  if (data == 'M'){
    mode = !mode;
  }
  if (data == 'D'){
    debug = !debug;
  }
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

  // Manual Drive mode
  if (mode == false){
    drive();
    output(distance, data);
  }
  
  // Object Following mode
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
  // Wait for x miliseconds 
  delayMicroseconds(delay);
}
