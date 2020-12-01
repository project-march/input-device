This repository has been archived. A recent version can be found on https://gitlab.com/project-march.

# 🕹️ Input Device
The input device is embedded in the crutch, it allows the pilot to control the exoskeleton.

| Branch | Build Status |
| ------ |:------------:|
| master | [![Build Status](https://api.travis-ci.com/project-march/input-device.svg?branch=master)](https://travis-ci.com/project-march/input-device) |
| develop | [![Build Status](https://api.travis-ci.com/project-march/input-device.svg?branch=develop)](https://travis-ci.com/project-march/input-device) |

## 🛠️ Building
This project uses the cross platform builder [platformio](https://docs.platformio.org/en/latest/what-is-platformio.html).
So you will need to install that first.
Then to install the libraries run:

    pio lib install

The project can then be built with `pio run`.
There exist three environments for building:

1. `demo`: builds in debug mode and does not wait for a response from the
   master.
2. `debug`: builds in debug mode. _This is the default._
2. `release`: builds in release mode.

To choose an environment use the `--environment (-e)` option. For example to
build the release environment run:

    pio run -e release

This only builds the project. To actually upload the project, connect the
input device and use the `--target (-t)` option. This will by default upload
the `debug` environment.

    pio run -t upload

When you run the input device you can read the messages sent over the
USB serial by adding the `monitor` target.

    pio run -t upload -t monitor

This will build, upload and then print messages sent over the serial
by the input device using `Serial.println()`.

## 🚀 Launch process
The input device can be launched with a ROS serial connection.
For this a workspace with the [march repository](https://github.com/project-march/march)
is required.

    roslaunch march_launch serial_connection.launch

## 🤖 Install ros_lib
This project uses ROS messages from the [`march_shared_resources`](https://github.com/project-march/march/tree/develop/march_shared_resources) package.
So when these messages are changed the `ros_lib` in the `lib/` directory will need to be updated. How to do this is described here: <http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup>.
