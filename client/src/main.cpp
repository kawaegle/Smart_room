#include "client.hpp"

CRGB leds[NB_LED_CLIENT];

void setup(){
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, PIN_LED>(leds, NB_LED_CLIENT);
    connect_wifi(leds);
}

void loop(){
}

