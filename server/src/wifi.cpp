#include "server.hpp"

IPAddress apIP(10, 10, 10, 1);

const char *SSID = "Smart_R00M_LED";
const char *PSK = "LED_password";

void create_wifi()
{
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP(SSID, PSK, 11, true, NB_CLIENT);
}

void reset_client(bool *client)
{
    for (int i = 0; i <= NB_CLIENT; i++) {
        client[i] = false;
        Serial.printf("Client %d is %d\r\n", i, client[i]);
    }
}

bool check_connected(bool *client) {
    for (int i = 0; i < NB_CLIENT; i++) 
        if (client[i] == false) {
            reset_client(client);
            return (false);
        }
    return (true);
}

void wait_connection(bool *client, WiFiUDP UDP, CRGB led[])
{
    while(true) {
        led[0] = CRGB::Yellow; FastLED.show();
        delay(500);
        read_packet(client, UDP);
        led[0] = CRGB::Blue; FastLED.show();
        delay(500);
        if (check_connected(client))
            return;
        delay(500);
        reset_client(client);
    }
}

void read_packet(bool *client, WiFiUDP UDP)
{
    client_msg_t msg;
    int packetSize = 0;
    while(true) {
        packetSize = UDP.parsePacket();
        if (!packetSize)
            break;
        UDP.read((char *)&msg, sizeof(client_msg_t));
        if (msg.client > NB_CLIENT) {
            Serial.println("Error: invalid client_id received");
            continue;
        }
        client[msg.client - 1] = true;
        Serial.printf("Client %d is %d\n\r", msg.client , client[msg.client - 1]);
    }
}
