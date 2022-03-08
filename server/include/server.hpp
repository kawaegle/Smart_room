#ifndef _SERVER_h_
#include "FastLED.h"
#include <ESP8266WiFi.h>
#include <Arduino.h>

#define NB_LED 1
#define STATUS_LED D4
#define STATUS_BUTTON D8
#define NB_CLIENT 1
#define MODE_MAX 5

void create_wifi(void);
void check_button(int *mode);

#endif // !_SERVER_h_
