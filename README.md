# Race Car Robot "STEM Mobile" - USF Engineering Project 
This is the project repo for Team 10's robot in Foundations of Engineering Lab, section 6 for the Fall 2022 semester. 

## Purpose
This is a group project aimed to provide an affordable, easy-to-build, and STEM-engaging robot for kids aged 11 to 14. The robot is controllable via Bluetooth by a phone app. 

| ![robot image](https://user-images.githubusercontent.com/48182689/200449319-cee9cf16-b141-4b34-815f-8229b2992e76.png) | 
|:--:| 
| The robot with the top shell removed (Note: a breadboard is not required, as it was removed in further design iterations) |

## Materials
The following materials are required for the robot:
* 1 Arduino Uno 
* 4 6V DC motors & 4 wheels
* 2 L298N Dual H-Bridge
* 3 9V batteries
* 3D printed chassis
* 1 HC-05 Bluetooth module
* Included screws and screwdriver

## Hardware Assembly
Once all materials are obtained, you may assemble the robot. 

First, assemble the baseplate by lining up the screw holes on plates #1 and #2 and use the included screws to attached them together. The screws should be nice and snug, but take care to not overtighten them, as it can mar the baseplate material.

Next, you will assemble the wiring and circuitry of the robot. Please use the below image as a wiring and general placement guide for all of the materials. 
[image coming soon]

Finally, attach the top shell to the baseplate using the included screws. The robot should be secure and solid. If any part of the robot feels loose, please recheck all screws are snugly installed, and zip-ties are tight.

## Software Installation
* Install the [Arduino IDE](https://www.arduino.cc/en/software)
* Upload racecar.ino to Arduino via USB
* Install the [phone app](https://tinyurl.com/3mm6v4je). *Currently, only Android is supported. However, a version for iOS is coming soon.*

## Operation
Once the software is properly installed and the circuitry is completed, all lights on the robot should come on. If the back lights and/or front lights are not on, please recheck all connections to verfiy the ciruit is properly completed.

Next, using either an iOS or Android device, open the controller app, click the "Devices" button and look for a device named *HC-05*. Tap on the device, and the app should take a moment to connect to the robot. Once connected, you will now have the ability to drive the robot. An extra way to verify the Bluetooth connection is to look at the back lights when the robot is 

Simply click the directional buttons to move the robot in the respective directions (up button = move forward, right button = turn right, etc.)

The back lights will only turn on when the robot is backing up or is stopped, while the front lights can be toggled on/off via the "Lights" button.

| ![app image](https://user-images.githubusercontent.com/48182689/200457770-ab3af917-7ce6-4f1a-b08d-8e4dc4db1636.png) | 
|:--:| 
| The current app iteration. *Layout is subject to change before 11/28 deadline* |

## Project Status
*As of 11/14/2022*

* **Design** - 100% complete (Completed October 2022)
* **Electronics/Circuitry** - 100% complete (Completed Early November 2022)
* **Software** - 95% complete
* **Hardware** - 95% complete 
* **Testing** - 90% complete

### Outstanding tasks
* **App** - Tests with the Android app have shown it to ocassionally crash after 5 minutes of use. This is due to an issue with the app maker we have chosen, and will be solved once we migrate to a new app maker (which will also support iOS). 
* **Suspension** - From testing, we have decided to add spring-based suspension to each wheel. This is virtually done, we are awaiting final assembly soon.
* **Testing** - Testing so far has shown the robot to be very fun and easy to use, and is meeting our engineering targets.

The project deadline is 11/28/2022. We are on-track for hardware & software complete by 11/21/2022, with testing concluding on 11/23/2022.

The next project status update will be made here on 11/21/2022.
