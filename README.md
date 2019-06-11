# Input Device
The input device is embedded in the crutch, it allows the pilot to control the exoskeleton.

## Install ros_lib
Follow this tutorial to install ros on arduino (make sure to clone the jade-devel branch, which supports kinetic):
http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup

However running this on a ESP32 is automatically using the ArduinoTcpHardware instead of the default. See this issue:
https://github.com/ros-drivers/rosserial/issues/354
For now this can be fixed by adjusting the ros.h file and deleting the define(ESP32) in the if statement.

## Use Custom Messages
Add your custom messages to the rosserial_msgs package in rosserial. And build again ros_lib in the lib folder of this project. http://wiki.ros.org/rosserial/Tutorials/Adding%20Other%20Messages. However, the master (the terminal that run the roscore) should also have access to the custom messages. This means that the rosserial project with the custom messages should be sourced.
