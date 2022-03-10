#include "FastLED.h"
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include <WiFiUdp.h>

#define NB_LED 1
#define STATUS_LED D5
#define STATUS_BUTTON D8
#define NB_CLIENT 1
#define MODE_MAX 5
#define PORT 4444

const int check_delay = 5000;

typedef struct led_cmd_s {
  uint8_t mode;
  uint32_t data;
} led_cmd_t;

typedef struct client_msg_s {
    int8_t client;
    int8_t check;
} client_msg_t;

void create_wifi(void);
void reset_client(bool *client);
void wait_connection(bool *client, WiFiUDP UDP, CRGB led[]);
bool check_connected(bool *client);
void check_button(int *mode);
void blink(void);
void read_packet(bool *client, WiFiUDP UDP);
