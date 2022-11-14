#ifndef Driver
#define Driver

// Motor RPM pins
#define enA A0
#define enB A1
#define enC A2
#define enD A3

// Defines some constants for the motor pins
const int in1 = 9;
const int in2 = 10;
const int in3 = 11;
const int in4 = 12;
const int in5 = 5;
const int in6 = 6;
const int in7 = 7;
const int in8 = 8;

// Driver function prototypes
void forward(int);
void backward(int);
void right(int);
void left(int);
void station();

#endif
