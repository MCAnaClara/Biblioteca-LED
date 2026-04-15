/*
encapsulamento é permitir apenas 1 pessoa saber e nao modificar as informaçoes, (privado)
*/
#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led.
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, liga por determinado tempo, piscar continuamente
 * e piscar por quantidade definida.
 * 
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
class Led
{
private:
bool estado; // atibuto
bool desligarPorTempo;

/**
 * @brief Processa a lógica de piscada do LED.
 */
void funcaoPiscar();

    uint32_t desligarMomento;
    uint8_t pino;
    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoDesligamento();

public:
   /**
    * @brief Constroi um objeto LED.
    * @param pin Numero do pino digital onde o LED está conectado.
    *  */ 
Led(uint8_t pin); 

    /**
    * @brief Liga o led continuamente.
    */
    void ligar();

    /**
     * @brief Liga o LED por tempo determinado.
     * @param tempoLigado_ms Tempo, e milissegundos, que o LED ficará ligado.
     */
    void ligar(unsigned long tempoLigado_ms);

    /**
     * @brief desliga o LED e cancela os modos automaticos.
     */
    void desligar();

    /**
     * @brief Inicia a piscada continua em 1 Hz.
     */
    void piscar();

    /**
     * @brief Pisca o LED de forma continua em uma quantidade definida de vezes por segundo.
     * @param frequencia Frequencia da piscada em Hz (quantas vezes pisca em 1 segundo).
     */
    void piscar(float frequencia);

    /**
     * @brief Pisca o LED uma quantidade definida de vezes.
     * @param frequencia Frequência da piscada em Hz.
     * @param repeticoes Quantidade de piscadas completas.
     */
    void piscar(float frequencia, uint16_t repeticoes);

    /**
     * @brief Armazena o estado atual do LED.
     */
    bool getEstado();

    /**
     * Armazena o pino digital conectado.
     */
    uint8_t getPino();

    /**
     * @brief Define manualmente o estado do LED.
     * @param estado Estado inicial desejado para o LED, sendo true para ligado e false para desligado.
     */
    void setEstado(bool estado);

    /**
     * @brief Inverte o estado atual do LED, se ligado, desliga.Se desligado, liga.
     */
    void alternar();

    /**
     * @brief Inicia funções que controlam o LED.
     */
    void update();
};
#endif