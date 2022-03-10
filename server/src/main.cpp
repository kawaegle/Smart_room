#include "server.hpp"

CRGB leds[NB_LED];
int mode = 1;

void blink(CRGB leds[])
{
    leds[0] = CRGB::Purple;
    FastLED.show(); delay(500);
    leds[0] = CRGB::Black;
    FastLED.show(); delay(500);
}

void setup()
{
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, STATUS_LED>(leds, NB_LED);
    pinMode(STATUS_BUTTON, INPUT);
    create_wifi();
    while (WiFi.softAPgetStationNum() != NB_CLIENT)
        blink(leds);
    Serial.println(WiFi.softAPIP());
}

void loop()
{
    check_button(&mode);
    switch (mode) {
        case 1:
            leds[0] = CRGB::WhiteSmoke; FastLED.show();
        case 2:
            leds[0] = CRGB::BlueViolet; FastLED.show();
        case 3:
            leds[0] = CRGB::Red; FastLED.show();
        case 4:
            leds[0] = CRGB::OrangeRed; FastLED.show();
        case 5:
            leds[0] = CRGB::Yellow; FastLED.show();
    }
}


