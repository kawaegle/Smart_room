#include "client.hpp"

void white_init(CRGB leds[])
{
    for (int i = 0; i < NB_LED_CLIENT; i++)
        leds[i] = CRGB::WhiteSmoke;
    return;
}

void user_color_init(CRGB leds[])
{
    for (int i = 0; i < NB_LED_CLIENT; i++)
        leds[i] = CRGB::DarkViolet;
    return;
}

void rainbow_init(CRGB leds[])
{
    for (int i = 0; i < 8; i++)
        leds[i] = CRGB::Blue;
    for (int i = 8; i < 16; i++)
        leds[i] = CRGB::Green;
    for (int i = 16; i < 29; i++)
        leds[i] = CRGB::Red;
    return;
}

void HORNY_init(CRGB leds[])
{
    for (int i = 0; i < NB_LED_CLIENT; i++)
        leds[i] = CRGB::HotPink;
    return;
}
