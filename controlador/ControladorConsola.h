#ifndef CONTROLADOR_CONTROLADOR_H
#define CONTROLADOR_CONTROLADOR_H

#include "../vista/VistaConsola.h"
#include "../modelo/Jugador.h"
#include "../modelo/Crupier.h"
#include "../modelo/Baraja.h"

class ControladorConsola {
    private:
        VistaConsola& vista;
        Jugador& jugador;
        Crupier& crupier;
        Baraja& baraja;
    public:
        ControladorConsola(VistaConsola& vista, Jugador& jugador, Crupier& crupier, Baraja& baraja);
        void determinarGanador() const;
        void iniciarJuego();
};


#endif // CONTROLADOR_CONTROLADOR_H