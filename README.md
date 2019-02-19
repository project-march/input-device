# Input Device
The input device is embedded in the crutch, it allows the pilot to control the exoskeleton.

Follow this tutorial to install ros on arduino (make sure to clone the jade-devel branch, which supports kinetic):
http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup

However running this on a ESP32 is automatically using the ArduinoTcpHardware instead of the default. See this issue:
https://github.com/ros-drivers/rosserial/issues/354
For now this can be fixed by adjusting the ros.h file and deleting the define(ESP32) in the if statement.
