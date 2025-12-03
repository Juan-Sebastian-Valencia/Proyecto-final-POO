#ifndef VISTA_VISTACONSOLA_H
#define VISTA_VISTACONSOLA_H

#include <string>
#include <iostream>
#include "../modelo/Jugador.h"
#include "../modelo/Crupier.h"
#include "../modelo/Carta.h"

class VistaConsola {
    public:
        int mostrarMenuPrincipal() const;
        int mostrarMenuApuesta() const;
        int mostrarMenuJuego() const;
        double hacerApuesta(double saldo) const;

        void mostrarCarta(const Carta& carta) const;
        void mostrarJugador(Jugador& jugador) const;  // polimorfismo estatico
        void mostrarJugador(Crupier& crupier, bool mostrarSegundaCarta) const;
        void mostrarPuntaje(Jugador& jugador) const;
        void mostrarGanador() const;
        void mostrarEmpate() const;
        void mostrarPerdedor() const;
        void mostrarSinSaldo() const;
        void saliendo() const;
        void opcionNoValida() const;
        void limpiarConsola() const;
        void pausar() const;
};

#endif // VISTA_VISTACONSOLA_H