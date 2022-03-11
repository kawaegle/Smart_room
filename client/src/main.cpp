#include "client.hpp"

CRGB leds[NB_LED_CLIENT];

unsigned long last_received = 0;
unsigned long last_send = 0;

WiFiUDP UDP;

static int mode = 1;

void setup(){
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, PIN_LED>(leds, NB_LED_CLIENT);
    connect_wifi(leds);
    UDP.begin(PORT);
    last_send = send_message(UDP);
    Serial.print(WiFi.localIP());
}

void loop()
{
    int old_mode = mode;
    if (millis() - last_send > check_delay)
        last_send = send_message(UDP);
    if (millis() - last_received > message_interval)
        last_received = receive_message(UDP, &mode);
    if (old_mode != mode) {
        Serial.printf("Mode = %d\n\r", mode);
        led_mode(mode);
    }
}

void led_mode(int mode)
{
    switch (mode) {
        case 1:
            Serial.print("White\n\r");
            white(leds);
            break;
        case 2:
            Serial.print("USER DEFINED\n\r");
            user_color(leds);
            break;
        case 3:
            Serial.print("rainbow move\n\r");
            rainbow_move(leds);
            break;
        case 4:
            Serial.print("rainbow Sound\n\r");
            rainbow_sound(leds);
            break;
        case 5:
            Serial.print("HORNY mode\n\r");
            HORNY(leds);
            break;
        default:
            break;
    } 
}
