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

void white(CRGB leds[])
{
    for (int i = 0; i < NB_LED_CLIENT; i++)
        leds[i] = CRGB::WhiteSmoke;
    FastLED.show();
}

void user_color(CRGB leds[])
{
    for (int i = 0; i < NB_LED_CLIENT; i++)
        leds[i] = CRGB::PaleVioletRed;
    FastLED.show();
    return;
}

void rainbow_move(CRGB leds[])
{
    for (int i = 0; i < 8; i++)
        leds[i] = CRGB::Blue;
    for (int i = 8; i < 16; i++)
        leds[i] = CRGB::Green;
    for (int i = 16; i < 29; i++)
        leds[i] = CRGB::Red;
    FastLED.show();
    return;
}

void rainbow_sound(CRGB leds[])
{
    for (int i = 0; i < 8; i++)
        leds[i] = CRGB::Violet;
    for (int i = 8; i < 16; i++)
        leds[i] = CRGB:: DeepSkyBlue;
    for (int i = 16; i < 29; i++)
        leds[i] = CRGB::Yellow;
    FastLED.show();

    return;
}

void HORNY(CRGB leds[])
{
    for (int i = 0; i < NB_LED_CLIENT; i++)
        leds[i] = CRGB::HotPink;
    FastLED.show();

    return;
}
