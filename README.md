# Race Car Robot "STEM Mobile" - USF Engineering Project
This is the project repo for Team 10 EGN3000L Section 6. Our robot is a muscle car design that canbe driven manually via a phone app.

![image](https://user-images.githubusercontent.com/48182689/200449319-cee9cf16-b141-4b34-815f-8229b2992e76.png)

The robot with the top shell removed (Note: a breadboard is not required, as it was removed in further design iterations)

## Materials
The following materials are required for the robot:
* 1 Arduino Uno 
* 4 6V DC motors & 4 wheels
* 2 L298N Dual H-Bridge
* 3 9V batteries
* 3D printed chassis
* 1 HC-05 Bluetooth module
* *and a lot of time*

## Software Installation
* Install the [Arduino IDE](https://www.arduino.cc/en/software)
* Upload racecar.ino to Arduino via USB

## Operation
Once the software is properly installed and the circuitry is completed, all lights on the robot should come on without flashing. If the back lights and/or front lights are not on, please recheck all connections to verfiy the ciruit is properly completed.

Next, using either an iOS or Android device, open the controller app, click the "Devices" button and look for a device named *HC-05*. Tap on the device, and the app should take a moment to connect to the robot. Once connected, you will now have the ability to drive the robot

Simply click the directional buttons to move the robot in the respective directions (up button = move forward, right button = turn right, etc.)

The back lights will only turn on when the robot is backing up or is stopped, while the front lights can be toggled on/off via the "Lights" button.
