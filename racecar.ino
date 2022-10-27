#include <SoftwareSerial.h> 
#include "lib/NewPing/src/NewPing.cpp"
#include "src/Driver.c"

// Lights
#define FRONT_LIGHTS 10
#define BACK_LIGHTS 11
#define BLUETOOTH_LIGHT 13
// Defines pins for IR sensor 
#define RIGHT 6
#define LEFT 5
// Defines pins for sonar sensor
#define TRIGGER_PIN 7
#define ECHO_PIN 8
#define MAX_DISTANCE 100

int interval;
int timeout = 0;
int timeout_limit = 50;
char data = 'I';
char last_input = 'I';
bool mode = false;
bool debug = true;
bool paired = false;
bool parked = true;

// Initalize the sonar sensor  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// Initalize the bluetooth module
SoftwareSerial tooth(2, 3); // RX | TX 

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
  if (last_input == data){
    data = 'I';
  }
  else {
    last_input = data;
  }
  //if (data != 'I'){
    //Serial.print(data);
  //}
  switch (data){
  case 'S':
    // Stop 
    station();
    digitalWrite(BACK_LIGHTS, HIGH);
    Serial.println("Stop");
    break;
  case 'F':
    // Forward
    forward();
    digitalWrite(BACK_LIGHTS, LOW);
    Serial.println("Forward");
    break;
  case 'B':
    // Backward
    backward();
    digitalWrite(BACK_LIGHTS, HIGH);
    Serial.println("Backward");
    break;
  case 'R':
    // Right
    right();
    digitalWrite(BACK_LIGHTS, LOW);
    Serial.println("Right");
    break;
  case 'L':
    // Left
    left();
    digitalWrite(BACK_LIGHTS, LOW);
    Serial.println("Left");
    break;
  case 'I':
    // Heartbeat - do nothing
    break;
  }
}

char input(){
  // Check bluetooth is connected
  if (Serial.available() > 0){
    // Read Bluetooth data (should be a single digit char)
    digitalWrite(BLUETOOTH_LIGHT, HIGH);
    paired = true;
    return Serial.read();
  }
  else{
    return ':';
  }
}

void output(int sonar){
  // Send Serial stuff to app
  tooth.write(sonar); // In cm
}

void test(){
  Serial.println("Forward");
  forward();
  delay(2500);
  Serial.println("Right");
  right();
  delay(2500);
  Serial.println("Left");
  left();
  delay(2500);
  Serial.println("Backward");
  backward();
  delay(2500);
  Serial.println("Stop");
  station();
  delay(2500);
}

void loop(){
  if (mode == false){
    timeout_limit = 50;
  }
  else{
    timeout_limit = 5;
  }
  data = input();
  if (data == 'D'){
    test();
  }
  // TODO: fixed this up a bit
  // Currently spams stop commands in parked, not bad, but wastes resources
  if (paired == false){
    if (parked == false){
      data = 'S';
      parked = true;
    }
    else {
      data = 'I';
    }
  }
  
  if (paired == true){
    if (data != ':'){
      timeout = 0;
    }
    else if (data == ':'){
      timeout += 1;
    }
    if (timeout > timeout_limit){
      digitalWrite(BLUETOOTH_LIGHT, LOW);
      digitalWrite(BACK_LIGHTS, HIGH);
      Serial.print("!");
      station();
      paired = false;
      mode = false;
      timeout = 0;
    }
  }

  if (data == 'M'){
    mode = !mode;
    station();
  }

  if (data == 'S'){
    mode = false;
  }
  
  // Assign distance variable to the sonar distance
  unsigned int distance = sonar.ping_cm();
    
  // Manual Drive mode
  if (mode == false && data != 'M'){
    parked = false;
    interval = 25;
    manual_input();
    output(distance);
  }
  
  // Object Following mode
  if (mode == true){
    interval = 1000;
    // Assign IR sensor values to the correct variables
    int Right_Value = digitalRead(RIGHT);
    int Left_Value = digitalRead(LEFT);

    if (distance == 0){
      Serial.println("Sonar not connected");
      mode = false;
      station();
      parked = true;
      paired = false;
    }
    // Sonar detects distance of less than 10cm
    else if(distance < 10) 
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
    else if(Right_Value==0 && Left_Value==1) // Turn left
    {
      left();
      if (debug == true){
        Serial.print("Left");
        Serial.print(distance);
        Serial.print(Right_Value, Left_Value);
      }
    }
    // Right IR sensor detects an object
    else if(Right_Value==1 && Left_Value==0) 
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
  delay(interval);
}
