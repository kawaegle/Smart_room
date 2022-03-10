#include <Arduino.h>
#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define NB_LED_CLIENT 144
#define PIN_LED D5
#define ID 1 // ID of the client for the server

const int check_delay = 5000;
const int message_interval = 100;

typedef struct led_cmd_s {
    uint8_t mode;
    uint32 data;
} led_cmd_t;

typedef struct client_msg_s {
    uint8_t client;
    uint8_t check;
} client_msg_t;

void connect_wifi(CRGB leds[]);
void blink(CRGB leds[]);
unsigned long send_message(WiFiUDP UDP);
