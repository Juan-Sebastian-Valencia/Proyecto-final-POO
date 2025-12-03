#include "Crupier.h"

Crupier::Crupier(Baraja* baraja) : Jugador(), baraja(baraja) {}

void Crupier::repartirCarta(Jugador& jugador){
    jugador.recibirCarta(baraja->sacarCarta());
}

void Crupier::repartirCartasInicioJuego(Jugador& jugador) {
    repartirCarta(jugador);
    repartirCarta(*this);
    repartirCarta(jugador);
    repartirCarta(*this);
}

void Crupier::recojerCartas(Jugador& jugador) {
    while(jugador.getMano().empty() == false) {
        Carta cartaRecogida = jugador.sacarCarta();
        baraja->recibirCartaBarajaSegundaria(cartaRecogida);
    }
}