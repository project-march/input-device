# Input Device
The input device is embedded in the crutch, it allows the pilot to control the exoskeleton.

## Install ros_lib
Follow this tutorial to install ros on arduino (make sure to clone the jade-devel branch, which supports kinetic):
http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup

However running this on a ESP32 is automatically using the ArduinoTcpHardware instead of the default. See this issue:
https://github.com/ros-drivers/rosserial/issues/354
For now this can be fixed by adjusting the ros.h file and deleting the define(ESP32) in the if statement

## Add Custom Messages
Add your custom messages to the rosserial_msgs package in rosserial. And build again ros_lib in the lib folder of this project. http://wiki.ros.org/rosserial/Tutorials/Adding%20Other%20Messages. However, the master (the terminal that run the roscore) should also have access to the custom messages. This means that the rosserial project with the custom messages should be sourced.

## Add Messages from package
http://wiki.ros.org/rosserial_arduino/Tutorials/Adding%20Custom%20Messages

## Building
The project can be built with `pio run`.
There exist three environments for building:

1. `demo`: builds in debug mode and does not wait for a response from the
   master.
2. `debug`: builds in debug mode.
2. `release`: builds in release mode.

To choose an environment use the `--environment (-e)` option. For example to
build the release environment run:

    pio run -e release

This only builds the project. To actually upload the project, connect the
input device and use the `--target (-t)` option.

    pio run -e <choose an env> -t upload

## Configure CLion
1. Install platformio and integrate it within the Clion ide, using the
   following
   [tutorial](https://docs.platformio.org/en/latest/ide/clion.html)
2. Git clone the balance repository
3. Initialise platformio through the terminal using ```platformio init
   --ide clion ``` in the balance_ipd_firmware directory. 
4. Before the device can be connected a wifi access point needs to be
   made. The SSID and password of which needs to be specified at the top
   of ros_wifi.h in the ipd_firmware directory. In addition the ip
   address of the computer running ROS needs to be known and added to
   the same header file.
5. You can build the project with ```pio run``` and upload with ```pio run --target upload```

## Launch process
Once a connection is made through wifi, there are two ways that the
input from the ipd can be seen through ROS:

1. run ```roscore``` and ``` rosrun rosserial_python serial_node.py
   tcp``` in terminal 
2. launch ```roslaunch balance_ipd balance_ipd.launch```
