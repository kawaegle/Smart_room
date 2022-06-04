#include "client.hpp"

CRGB leds[NB_LED_CLIENT];

unsigned long last_received = 0;
unsigned long last_send = 0;

WiFiUDP UDP;

int mode = 1;
int old_mode = 0;

void setup(){
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, PIN_LED>(leds, NB_LED_CLIENT);
    FastLED.setBrightness(25);
    connect_wifi(leds);
    UDP.begin(PORT);
    last_send = send_message(UDP);
}

void loop()
{
    if (millis() - last_send > check_delay)
        last_send = send_message(UDP);
    if (millis() - last_received > message_delay)
        last_received = receive_message(UDP, &mode);
    if (old_mode != mode) {
        Serial.printf("Mode = %d\n\r", mode);
        init_led(mode);
    }
    led_mode(mode);
    FastLED.show();
    old_mode = mode;
}

void init_led(int mode)
{
    switch (mode) {
        case WHITE:
            Serial.print("White init\n\r");
            white_init(leds);
            break;
        case USER:
            Serial.print("USER DEFINED init\n\r");
            user_color_init(leds);
            break;
        case RAINBOW:
            Serial.print("rainbow move init\n\r");
            rainbow_init(leds);
            break;
        case RAINBOW_SOUND:
            Serial.print("rainbow Sound init\n\r");
            rainbow_init(leds);
            break;
        case HORNY:
            Serial.print("HORNY mode init\n\r");
            HORNY_init(leds);
            break;
        default:
            break;
    }
}

void led_mode(int mode)
{
    switch (mode) {
        case WHITE:
            Serial.print("White\n\r");
            white(leds);
            break;
        case USER:
            Serial.print("USER DEFINED\n\r");
            user_color(leds);
            break;
        case RAINBOW:
            Serial.print("rainbow move\n\r");
            rainbow_move(leds);
            break;
        case RAINBOW_SOUND:
            Serial.print("rainbow Sound\n\r");
            rainbow_sound(leds);
            break;
        case HORNY:
            Serial.print("HORNY mode\n\r");
            HORNY_mode(leds);
            break;
        default:
            break;
    }
}
