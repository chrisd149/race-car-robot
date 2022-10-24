#ifndef DRIVER
#define DRIVER

// Defines some constants for the motor pins
const int in1 = 5;
const int in2 = 4;
const int in3 = 3;
const int in4 = 2;
const int enA = 6;
const int enB = 7;

// Driver function prototypes
void forward();
void backward();
void right();
void left();
void station();

#endif
