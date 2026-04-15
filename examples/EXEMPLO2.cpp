/*
Liga o LED durante cinco segundos (tempo que o usuario determinar) e desliga.
*/

#include <Arduino.h>
#include <LED.h>


Led led1(35);

void setup() {
  led1.ligar(5000);

}

void loop() {
  led1.update();
}
