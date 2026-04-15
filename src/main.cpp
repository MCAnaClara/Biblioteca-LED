#include <Arduino.h>
#include <LED.h>

/*
Pisca o LED com uma freuqneica de 4 Hz (4 vezes por segundo) ate piscar 45 vezes.
*/
Led led1(35);

void setup() {
  led1.piscar(4, 45);
}

void loop() {
  led1.update();
}
