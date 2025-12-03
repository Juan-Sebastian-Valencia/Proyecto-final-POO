#include "Carta.h"

Carta::Carta(int valor, char palo) : valor(valor), palo(palo) {}

int Carta::getValor() const { return valor;}
char Carta::getPalo() const { return palo;}