#include "client.hpp"

const char *SSID = "Smart_R00M_LED";
const char *PSK = "LED_password";

void connect_wifi(CRGB leds[])
{
    WiFi.begin(SSID, PSK, 11);
    while (WiFi.status() != WL_CONNECTED)
        blink(leds);
    Serial.print("conneted");
}
