#ifndef MODELO_CRUPIER_H
#define MODELO_CRUPIER_H

#include <vector>
#include "Baraja.h"
#include "Jugador.h"

class Crupier : public Jugador {
    private:
        Baraja* baraja;
    public:
        Crupier(Baraja* baraja);
        void repartirCarta(Jugador& jugador);
        void repartirCartasInicioJuego(Jugador& jugador);
        void recojerCartas(Jugador& jugador);
};

#endif // MODELO_CRUPIER_H