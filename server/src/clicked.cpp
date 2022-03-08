#include "server.hpp"
#include "client.hpp"

bool button_clicked = false;

static void clicked(int *mode) {
    if (*mode == MODE_MAX) 
        *mode = 1;
    else
        *mode += 1;
    Serial.printf("Mode = %d\n", *mode);
}

void check_button(int *mode)
{
    int but = digitalRead(STATUS_BUTTON);
    if (but == LOW) {
        button_clicked = true; 
    }
    else if (but == HIGH && button_clicked == true) {
        clicked(mode);
        button_clicked = false;
    }
}
