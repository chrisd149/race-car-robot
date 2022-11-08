#include <SoftwareSerial.h> 
#include "src/Driver.h"

// Lights
#define FRONT_LIGHTS 3
#define BACK_LIGHTS 4
#define BLUETOOTH_LIGHT 13

bool front = false;
int interval = 25;
int timeout = 0;
int timeout_limit = 25;
char data = 'I';
char last_input = 'I';
bool debug = true;
bool paired = false;
bool parked = true;

// Initalize the bluetooth module
SoftwareSerial tooth(0, 1); // RX | TX 

// Setup code - only ran at start-up
void setup() {
  Serial.begin(9600);
  tooth.begin(9600);
  // LEDs
  pinMode(FRONT_LIGHTS, OUTPUT);
  pinMode(BACK_LIGHTS, OUTPUT);
  pinMode(BLUETOOTH_LIGHT, OUTPUT);
  // Assign pins for motors
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  digitalWrite(FRONT_LIGHTS, HIGH);
  front = true;
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
    Serial.println("Forward");
    digitalWrite(BACK_LIGHTS, LOW);
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
  case 'O':
    if (front == true){
      digitalWrite(FRONT_LIGHTS, LOW);
      Serial.print("LOW");
      front = false;
    }
    else{
      digitalWrite(FRONT_LIGHTS, HIGH);
      Serial.print("HIGH");
      front = true;
    }
    break;
  case 'I':
    // Heartbeat - do nothing
    break;
  }
}

char input(){
  // Check bluetooth is connected
  if (tooth.available() > 0){
    // Read Bluetooth data (should be a single digit char)
    digitalWrite(BLUETOOTH_LIGHT, HIGH);
    paired = true;
    char text = tooth.read();
    return text;
  }
  else{
    return ':';
  }
}

// Drive test - only use via serial connection
void test(){
  Serial.println("<---Drive Test--->");
  Serial.println("Forward");
  digitalWrite(13, LOW);
  delay(2000);
  Serial.println("Right");
  right();
  digitalWrite(13, LOW);
  delay(2000);
  Serial.println("Left");
  left();
  digitalWrite(13, LOW);
  delay(2000);
  Serial.println("Backward");
  backward();
  digitalWrite(13, HIGH);
  delay(2000);
  Serial.println("Stop");
  station();
  digitalWrite(13, HIGH);
  delay(10000);
}

void loop(){
  // Get any Bluetooth data
  data = input();

  // Drive test
  if (data == 'D'){
    test();
  }

  // Sets parking if not paired 
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
    // Good data - reset timeout
    if (data != ':'){
      timeout = 0;
      parked = false;
      manual_input();
    }
    // No/bad data - add to timeout
    else if (data == ':'){
      timeout += 1;
    }
    // timeout limit reached, disonnect & stop procedures
    if (timeout > timeout_limit){
      digitalWrite(BLUETOOTH_LIGHT, LOW);
      digitalWrite(BACK_LIGHTS, HIGH);
      Serial.print("!");
      station();
      paired = false;
      timeout = 0;
    }
  }
  // Wait for 25 miliseconds 
  delay(25);
}