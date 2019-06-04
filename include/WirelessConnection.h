// Copyright 2018 Project March.

#ifndef WII_NUNCHUK_UNO_ROS_WIFI_H
#define WII_NUNCHUK_UNO_ROS_WIFI_H
//////////////////////
// WiFi Definitions //
//////////////////////

//todo
const char* ssid = "OnePlus5";
const char* password =  "timisdik";

IPAddress server(192, 168, 43, 83); // ip of your ROS server
IPAddress ip_address;
//int status = WL_IDLE_STATUS;

WiFiClient client;


void setupWiFi()
{
    WiFi.begin(ssid, password);
    Serial.print("\nConnecting to "); Serial.println(ssid);
    uint8_t i = 0;
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print("Could not connect to"); Serial.println(ssid);
    }

    Serial.print("Ready! Use ");
    Serial.print(WiFi.localIP());
    Serial.println(" to access client");
}

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
