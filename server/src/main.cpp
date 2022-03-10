#include "server.hpp"

CRGB leds[NB_LED];
int mode = 1;
unsigned long last_check = 0;

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
    delay(500);
    
    pinMode(STATUS_BUTTON, INPUT);
    create_wifi();
 
    leds[0] = CRGB::Red; FastLED.show();
    delay(500);
    Serial.println(WiFi.softAPIP());
    Serial.print("\r");
    UDP.begin(PORT);
    reset_client(client_connected);
    leds[0] = CRGB::Green; FastLED.show();
    delay(500);
    wait_connection(client_connected, UDP, leds);
    Serial.printf("Server started %d\n\r", PORT);
    leds[0] = CRGB::HotPink; FastLED.show();
    delay(500);
}

void loop()
{
/*    if (millis() - last_check > check_delay)
        if (!check_connected(client_connected))
            wait_connection(client_connected);
    last_check = millis();
*/
    check_button(&mode);
    switch (mode) {
        case 1:
            leds[0] = CRGB::WhiteSmoke; FastLED.show();
            break;
        case 2:
            leds[0] = CRGB::BlueViolet; FastLED.show();
            break;
        case 3:
            leds[0] = CRGB::Red; FastLED.show();
            break;    
        case 4:
            leds[0] = CRGB::OrangeRed; FastLED.show();
            break;
        case 5:
            leds[0] = CRGB::Yellow; FastLED.show();
            break;
        default:
            break;
    }
}


