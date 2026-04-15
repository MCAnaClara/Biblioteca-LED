/*
Deixa desligado durante três segundos e inverte o estado atual do LED (no caso, desligado) por tempo indeterminado
*/

#include <Arduino.h>
#include <LED.h>


Led led1(35);

void setup() {
  led1.desligar();
  delay(3000);
  led1.alternar();

}

void loop() {
  led1.update();
}