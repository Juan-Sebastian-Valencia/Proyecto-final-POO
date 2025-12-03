#include "ControladorConsola.h"

ControladorConsola::ControladorConsola(VistaConsola& vista, Jugador& jugador, Crupier& crupier, Baraja& baraja)
    : vista(vista), jugador(jugador), crupier(crupier), baraja(baraja) {}

void ControladorConsola::determinarGanador() const {
    int puntuacionJugador = jugador.calcularPuntuacion();
    int puntuacionCrupier = crupier.calcularPuntuacion();

    if (puntuacionJugador > 21 || puntuacionJugador < puntuacionCrupier) {
        vista.mostrarPerdedor();
    } else if (puntuacionCrupier > 21 || puntuacionJugador > puntuacionCrupier) {
        vista.mostrarGanador();
        jugador.setSaldo(jugador.getSaldo() + 2*jugador.getApuesta());
    } else {
        vista.mostrarEmpate();
        jugador.setSaldo(jugador.getSaldo() + jugador.getApuesta());
    }
}

void ControladorConsola::iniciarJuego() {
    bool jugando = true;

    while (jugando) {
        vista.limpiarConsola();
        int opcionMenuPrincipal = vista.mostrarMenuPrincipal();

        if (opcionMenuPrincipal == 1) {
            if (jugador.getSaldo() <= 0) {
                vista.pausar();
                vista.mostrarSinSaldo();
                vista.pausar();
                continue;
            }

            baraja.barajar();

            double apuesta = vista.hacerApuesta(jugador.getSaldo());
            jugador.setApuesta(apuesta);
            jugador.setSaldo(jugador.getSaldo() - apuesta);

            crupier.repartirCartasInicioJuego(jugador);

            bool turnoJugador = true;
            bool juegoTerminado = false;

            while (!juegoTerminado) {
                vista.limpiarConsola();
                vista.mostrarJugador(jugador);
                vista.mostrarJugador(crupier, false);

                if (turnoJugador) {
                    int opcionMenuJuego = vista.mostrarMenuJuego();

                    if (opcionMenuJuego == 1) {
                        crupier.repartirCarta(jugador);
                        if (jugador.calcularPuntuacion() > 21) {
                            juegoTerminado = true;
                        }
                    } else if (opcionMenuJuego == 2) {
                        jugador.doblarApuesta();
                        crupier.repartirCarta(jugador);
                        juegoTerminado = true;
                    } else {
                        turnoJugador = false;
                    }
                } else {
                    while (crupier.calcularPuntuacion() < 17) {
                        crupier.repartirCarta(crupier);
                        juegoTerminado = true;
                    }
                }
            }

            vista.limpiarConsola();
            vista.mostrarJugador(jugador);
            vista.mostrarJugador(crupier, true);

            vista.pausar();
            determinarGanador();
            vista.pausar();

            crupier.recojerCartas(jugador);
            crupier.recojerCartas(crupier);
        } else if (opcionMenuPrincipal == 2) {
            jugando = false;
            vista.saliendo();
        } else {
            vista.opcionNoValida();
        }
    }
}