/*
Inicia a função piscar, mas por inicializar em seguida a função desligar, o LED fica desligado.
*/

#include <Arduino.h>
#include <LED.h>


Led led1(35);

void setup() {
  led1.piscar();
  led1.desligar();
}

void loop() {
  led1.update();
}