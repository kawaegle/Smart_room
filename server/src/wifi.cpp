#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "FastLED.h"
#include "server.hpp"
#include "client.hpp"

IPAddress apIP(10, 10, 10, 1);


void create_wifi()
{
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
    WiFi.softAP("Smartr00m_led", "smartled", 11, true, NB_CLIENT);
}
