#include <Arduino.h>
#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define NB_LED_CLIENT 29 
#define PIN_LED D5
#define PORT 4444
#define MODE_MAX 5
#define ID 1 // ID of the client for the server

typedef enum LED_MODE_e {
    WHITE = 1,
    USER,
    RAINBOW,
    RAINBOW_SOUND,
    HORNY
} LED_MODE;

const int check_delay = 5000;
const int message_delay = 100;
const int rainbow_delay = 250;

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
void led_mode(int mode);
unsigned long send_message(WiFiUDP UDP);
unsigned long receive_message(WiFiUDP UDP, int *mode);
void init_led(int mode);

void white(CRGB leds[]);
void user_color(CRGB leds[]);
void rainbow_move(CRGB leds[]);
void rainbow_sound(CRGB leds[]);
void HORNY_mode(CRGB leds[]);

void white_init(CRGB leds[]);
void user_color_init(CRGB leds[]);
void rainbow_init(CRGB leds[]);
void HORNY_init(CRGB leds[]);

