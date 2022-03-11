#include "server.hpp"

CRGB leds[NB_LED];
int mode = 1;
unsigned long last_check = 0;
unsigned long last_send = 0;

WiFiUDP UDP;

bool client_connected[NB_CLIENT];

void blink()
{
    leds[0] = CRGB::Purple;
    FastLED.show(); delay(500);
    leds[0] = CRGB::Black;
    FastLED.show(); delay(500);
}

void setup()
{
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, STATUS_LED>(leds, NB_LED);
    leds[0] = CRGB::Purple; FastLED.show();
    pinMode(STATUS_BUTTON, INPUT);
    create_wifi();
    Serial.println(WiFi.softAPIP());
    Serial.print("\r");
    UDP.begin(PORT);
    reset_client(client_connected);
    wait_connection(client_connected, UDP, leds);
    Serial.printf("Server started %d\n\r", PORT);
}

void loop()
{
    int old_mode = mode;
    if (millis() - last_check > check_delay)
        if (!check_connected(client_connected))
            wait_connection(client_connected, UDP, leds);
    last_check = millis();


    if ( millis() - last_send > check_send) {
        check_button(&mode);
        Serial.printf("Mode is %d\n\r", mode);
        if (old_mode != mode) {
            switch (mode) {
                case 1:
                    leds[0] = CRGB::WhiteSmoke; FastLED.show();
                    send_packet(client_connected, UDP, mode);
                    break;
                case 2:
                    leds[0] = CRGB::BlueViolet; FastLED.show();
                    send_packet(client_connected, UDP, mode);
                    break;
                case 3:
                    leds[0] = CRGB::Red; FastLED.show();
                    send_packet(client_connected, UDP, mode);
                    break;    
                case 4:
                    leds[0] = CRGB::OrangeRed; FastLED.show();
                    send_packet(client_connected, UDP, mode);
                    break;
                case 5:
                    leds[0] = CRGB::Yellow; FastLED.show();
                    send_packet(client_connected, UDP, mode);
                    break;
                default:
                    break;
            }
        }
    }
}


