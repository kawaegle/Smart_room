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
    IPAddress ip(10, 10, 10, 1);
    UDP.beginPacket(ip, 4444); 
    int ret = UDP.write((char*)&msg,sizeof(msg));
    Serial.printf("Returned: %d, also sizeof hbm: %ld \n", ret, sizeof(msg));
    UDP.endPacket();
    return (millis());
}
