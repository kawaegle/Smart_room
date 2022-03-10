#ifndef _CLIENT_H_
    #define _CLIENT_H_

#include <Arduino.h>
#include <FastLED.h>
#include <ESP8266WiFi.h>

#define NB_LED_CLIENT 144
#define PIN_LED D5

typedef struct rgb_s {
    int r;
    int g;
    int b;
} rgb_t;

void connect_wifi(CRGB leds[]);
void blink(CRGB leds[]);
#endif
