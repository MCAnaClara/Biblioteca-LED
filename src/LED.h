/*
encapsulamento é permitir apenas 1 pessoa saber e nao modificar as informaçoes, (privado)
*/
#ifndef LED_h
#define LED_h

#include <Arduino.h>

class Led
{
private:
bool estado; // atibuto
bool desligarPorTempo;
void funcaoPiscar();

    uint32_t desligarMomento;
    uint8_t pino;
    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;

    void funcaoDesligamento();

public:
    Led(uint8_t pin); // metodo construtor, tem q ter o msm nome da classe

    void ligar();
    void ligar(unsigned long tempoLigado_ms);

    void desligar();

    void piscar();
    void piscar(float frequencia);
    void piscar(float frequencia, uint16_t repeticoes);

    bool getEstado();
    uint8_t getPino();

    void setEstado(bool estado);

    void alternar();

    void update();
};

#endif