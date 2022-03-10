#include "client.hpp"

CRGB leds[NB_LED_CLIENT];

unsigned long last_received = 0;
unsigned long last_send = 0;

WiFiUDP UDP;

void setup(){
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, PIN_LED>(leds, NB_LED_CLIENT);
    connect_wifi(leds);
    last_send = send_message(UDP);
}

void loop()
{
    if (millis() - last_send > check_delay)
        last_send = send_message(UDP);
    delay(500);
}
