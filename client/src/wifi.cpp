#include "client.hpp"

const char *SSID = "Smart_R00M_LED";
const char *PSK = "LED_password";

void connect_wifi(CRGB leds[])
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PSK, 11);
    while (WiFi.status() != WL_CONNECTED)
        blink(leds);
    Serial.print("conneted\r\n");
}

unsigned long send_message(WiFiUDP UDP) {
    client_msg_t msg;
    msg.client = ID;
    msg.check = (uint8_t) 77777;
    Serial.println("Sending heartbeat");
    IPAddress ip(192, 168, 4, 1);
    UDP.beginPacket(ip, PORT); 
    int ret = UDP.write((char*)&msg,sizeof(msg));
    UDP.endPacket();
    return (millis());
}

unsigned long receive_message(WiFiUDP UDP, int *mode)
{
    led_cmd_t msg;
    int packetSize = 0;
    while(true) {
        packetSize = UDP.parsePacket();
        if (!packetSize)
            break;
        UDP.read((char *)&msg, sizeof(led_cmd_t));
        if (msg.mode > MODE_MAX) {
            continue;
        }
        *mode = msg.mode;
    }
    return (millis());
}
