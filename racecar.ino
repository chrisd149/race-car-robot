#include <SoftwareSerial.h> 
#include "lib/NewPing/src/NewPing.cpp"
#include "src/Driver.c"

// Lights
#define FRONT_LIGHTS 10
#define BACK_LIGHTS 11
#define BLUETOOTH_LIGHT 12
// Defines pins for IR sensor 
#define RIGHT A2
#define LEFT A3
// Defines pins for sonar sensor
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100

int com_time; 
int interval;
char data;
bool mode = false;
bool debug = true;
bool paired = false;

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
  // LEDs
  pinMode(FRONT_LIGHTS, OUTPUT);
  pinMode(BACK_LIGHTS, OUTPUT);
  pinMode(BLUETOOTH_LIGHT, OUTPUT);
  // Assign pins for motors
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void manual_input(){
// Drive command sent, send to Driver input
  switch (data){
  case 'S':
    // No user input - stop 
    station();
    digitalWrite(BACK_LIGHTS, HIGH);
    break;
  case 'F':
    // Forward
    forward();
    digitalWrite(BACK_LIGHTS, LOW);
    break;
  case 'B':
    // Backward
    backward();
    digitalWrite(BACK_LIGHTS, HIGH);
    break;
  case 'R':
    // Right
    right();
    digitalWrite(BACK_LIGHTS, LOW);
    break;
  case 'L':
    // Left
    left();
    digitalWrite(BACK_LIGHTS, LOW);
    break;
  case 'I':
    // Heartbeat - do nothing
    break;
  case 'M':
    mode = !mode;
    station();
    break;
  default:
    // Big error, stop
    station();
    break;
  }
}

char input(){
  // Check bluetooth is connected
  if (tooth.available() > 0){
    // Read Bluetooth data (should be a single digit char)
    com_time = millis();
    digitalWrite(BLUETOOTH_LIGHT, HIGH);
    paired = true;
    return tooth.read();
  }
  else{
    return ':';
  }
}

void output(int sonar){
  // Send Serial stuff to app
  tooth.write(sonar); // In cm
}

void loop(){
  data = input();
  if (data == ':' && paired == false){
      data = 'S';
  }
  
  // Stop if no command has been sent in 2.5 seconds
  if (data == ':' && (com_time + 2.5) < millis()){
    digitalWrite(BLUETOOTH_LIGHT, LOW);
    digitalWrite(BACK_LIGHTS, HIGH);
    station();
    Serial.print("LOS - Stopping");
    paired = false;
    mode = false;
  }
  
  // Assign distance variable to the sonar distance
  unsigned int distance = sonar.ping_cm();

  // Manual Drive mode
  if (mode == false){
    interval = 25;
    manual_input();
    output(distance);
  }
  
  // Object Following mode
  if (mode == true){
    interval = 50;
    // Assign IR sensor values to the correct variables
    int Right_Value = digitalRead(RIGHT);
    int Left_Value = digitalRead(LEFT);
    
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
  delayMicroseconds(interval);
}
