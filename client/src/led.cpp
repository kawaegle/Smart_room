#include "client.hpp"

unsigned long last_rainbow = 0;

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
    return;
}

void user_color(CRGB leds[])
{
    return;
}

void rainbow_move(CRGB leds[])
{
    if (millis() - last_rainbow > rainbow_delay) {
        CRGB back = leds[NB_LED_CLIENT - 1];
        for (int i = NB_LED_CLIENT - 1; i > 0; i--)
            leds[i] = leds[i - 1];
        leds[0] = back;
        last_rainbow = millis();
    }
    return;
}

void rainbow_sound(CRGB leds[])
{
    return;
}

void HORNY_mode(CRGB leds[])
{
    for (int i = 0; i < NB_LED_CLIENT; i++)
        leds[i] = CRGB::HotPink;
    return;
}
