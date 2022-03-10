#include "client.hpp"

void blink(CRGB leds[])
{
    for (int i = 0; i <= NB_LED_CLIENT; i++)
        leds[i] = CRGB::Purple;
    FastLED.show(); delay(500);
    for (int i = 0; i <=NB_LED_CLIENT; i++)
        leds[i] = CRGB::Black;
    FastLED.show(); delay(500);
}
