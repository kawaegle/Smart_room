#include "server.hpp"

const char *SSID = "Smart_R00M_LED";
const char *PSK = "LED_password";

void create_wifi()
{
    WiFi.mode(WIFI_AP);
    WiFi.softAP(SSID, PSK, 11, true, NB_CLIENT);
    Serial.print(WiFi.softAPIP());
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
        blink();
        read_packet(client, UDP);
        blink();
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

void send_packet(bool *client, WiFiUDP UDP, int mode)
{
    led_cmd_t msg;
    msg.mode = mode; 
//    send_data.data = data; 
    for (int i = 0; i < NB_CLIENT; i++) {
        IPAddress ip(192, 168 , 4, 2 + i);
        UDP.beginPacket(ip, 4444);
        Serial.printf("send %d to", mode);
        Serial.print(ip);
        Serial.print("\n\r");
        UDP.write((char*)&msg, sizeof(led_cmd_t));
        UDP.endPacket();
    }
}
