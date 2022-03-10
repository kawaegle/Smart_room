#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "FastLED.h"
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
