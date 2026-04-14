#include "LED.h"

/*primeiro a classe dps a funcao*/ Led::Led(uint8_t pin) :
 // parametro
    pino (pin),
    estado (LOW),
    desligarPorTempo(false),
    desligarMomento(0),
    tempoAnteriorPiscar(0),
    tempoEspera(0),
    estadoPiscar(false),
    repeticoes(0)

    {
        pinMode(pino, OUTPUT);
    }

void Led::ligar()
{
    estadoPiscar = false; //reseta valores
    desligarPorTempo = false;  //reseta valores
    estado = HIGH;
}

void Led::ligar(unsigned long tempoligado_ms)
{
    estado = HIGH;
    desligarPorTempo = true;
    desligarMomento = millis() + tempoligado_ms;
    estadoPiscar = false;
    
}

void Led::desligar()
{
    estadoPiscar = false;
    desligarPorTempo = false;  //reseta valores
    estado = LOW;
}

void Led ::alternar()
{
    estado = !estado;
}

void Led ::update()
{

   if (desligarPorTempo) funcaoDesligamento();
   if (estadoPiscar) funcaoPiscar();

    digitalWrite(pino, estado);
}

bool Led::getEstado()
{
    return estado;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
    desligarPorTempo = false;
    estadoPiscar = false;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::piscar(){
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    
    desligarPorTempo = false;
    
}

void Led::piscar(float frequencia, uint16_t repeticoes){
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    this->repeticoes = repeticoes * 2;
    desligarPorTempo = false;
}

void Led::piscar(float frequencia){
    estadoPiscar = true;
    tempoEspera = (1000.0f /( 2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    desligarPorTempo = false;
}
//funcao privada
void Led::funcaoPiscar(){
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();
         
        if(repeticoes > 0){
        repeticoes--;
        if (repeticoes == 0)
        {
            estadoPiscar = false;
            estado= LOW;
        }  
    }
    }
}

void Led::funcaoDesligamento(){
        if (millis() >= desligarMomento)
        {
            estado = LOW;
            desligarPorTempo = false;
        }
    }
