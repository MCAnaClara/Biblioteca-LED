/*
Pisca o LED duas vezes por segundo por tempo indeterminado
 */

#include <Arduino.h>
#include <LED.h>

Led ledA(35);

void setup() {
    ledA.piscar(2);
}

void loop() {
    ledA.update();
}

