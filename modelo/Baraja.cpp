#include "Baraja.h"

Baraja::Baraja() {
    char palos[] = {'P', 'C', 'D', 'T'}; // Picas, Corazones, Diamantes, Tréboles
    for (char palo : palos) {
        for(int valor = 1; valor <=13; valor++) {
            Carta carta(valor, palo);
            barajaInicial.push_back(carta);
        }
    }
    barajaSegundaria.reserve(52);
}

Carta Baraja::sacarCarta() {
    if(barajaInicial.empty()) {
        barajar();
    }
    Carta carta = barajaInicial.back();
    barajaInicial.pop_back();
    return carta;
}

void Baraja::barajar() {
    for(Carta carta : barajaSegundaria) {
        barajaInicial.push_back(carta);
    }
    barajaSegundaria.clear();

    srand(time(0));  // Semilla para la aleatoriedad

    for(int i = barajaInicial.size() -1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(barajaInicial[i], barajaInicial[j]); // Intercambia la posición de las cartas
    }
}

void Baraja::recibirCartaBarajaSegundaria(const Carta& carta){
    barajaSegundaria.push_back(carta);
}