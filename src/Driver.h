#ifndef Driver
#define Driver

// Motor RPM pins
const int enA = 5;
const int enB = 6;
const int enC = 9;
const int enD = 10;

// Defines some constants for the motor pins
#define in1 A3
#define in2 A2
#define in3 A1
#define in4 A0
const int in5 = 7;
const int in6 = 8;
const int in7 = 11;
const int in8 = 12;

// Driver function prototypes
void forward(int);
void backward(int);
void right(int);
void left(int);
void station();

#endif
