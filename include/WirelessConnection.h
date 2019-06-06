// Copyright 2018 Project March.

#ifndef WII_NUNCHUK_UNO_ROS_WIFI_H
#define WII_NUNCHUK_UNO_ROS_WIFI_H
//////////////////////
// WiFi Definitions //
//////////////////////

//todo
char ssid[] = "Bear";
char password[] =  "dikkepanda";

IPAddress server(192, 168, 137, 110); // ip of your ROS server
IPAddress ip_address;
//int status = WL_IDLE_STATUS;

WiFiClient client;

class WiFiHardware {

public:
    WiFiHardware() {};

    void init() {
        //Initialization of TCP server/client setup
        client.connect(server, 11411);
    }

    // read a byte from the serial port. -1 = failure
    int read() {
        //Read byte from the TCP connection and returns it. returns -1 when not working
        return client.read();
    }

    // write data to the connection to ROS
    void write(uint8_t* data, int length) {
        // write arguments to TCP connection
        for(int i=0; i<length; i++)
            client.write(data[i]);
    }

    // returns milliseconds since start of program
    unsigned long time() {
        return millis();
    }
};

#endif //WII_NUNCHUK_UNO_ROS_WIFI_H
