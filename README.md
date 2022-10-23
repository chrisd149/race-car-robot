# Autonomous Racecar - Team 10
This is the project repo for Team 10 EGN3000L Section 6. Our robot is a muscle car design that can autonomously follow an object or be driven manually via a phone app.

[COOL IMAGE HERE]

## Materials
The following materials are required for the robot:
* 1 Arduino Uno 
* 2 IR sensors
* 1 HC-SR04 Sonar sensor
* 4 6V DC motors & 4 wheels
* 1 L298N Dual H-Bridge
* Batteries (TODO: exact number/size)
* 3D printed chassis (link)
* *and a lot of time*

## Software Installation
* Install [Arduino IDE](https://www.arduino.cc/en/software)
* Configure libraries (TODO: add link(s))
* Upload src/main.ino to Arduino via USB

## Operation
Once the software is properly installed, all lights on the robot should come on without flashing. If the lights are flashing, please ensure all eletrical connections are proper and secured. 

Next, using an Android device, open the controller app and look for a device named *Racecar10*. Tap on the icon, and the app should take a moment to connect to the robot. Once connected, you will have some options. You can set the following distance range, top speed, turn aggresiveness and some other cool features. The options that we will go indepth here are the two main options for driving the robot: Object Following and Manual Drive mode.

### Object Following Mode
Click the *Object Follow* button in the (TODO: specify where the button is).

The robot will begin running through a loop of automated commands to follow an object in front of itself. It is intended to keep a close distance to any object it detects, whether it be a human, hand, cat or anything that you trust to put in front of a robot with a top speed of 5mp/h. Please note that at any time you wish to stop the robot, you can click the *STOP* button on the app or disconnect the app from the robot (it is designed to stop moving if connection is lost with the host phone.) 

### Manual Drive Mode
First, ensure that Object Following Mode is not active, and if it is active, disable it by clicking the *STOP* button. Simply click the directional buttons to move the robot in the respective directions (up button = move forward, right button = turn right, etc.) 

OPTIONAL: Enabling *Auto Stop* will use the sonar sensor to automatically stop the robot if it gets too close to an object. This can be handy for first time users!
