#include "controlador/ControladorConsola.h"

int main() {
    VistaConsola vista;
    Baraja baraja;
    Jugador jugador;
    Crupier crupier(&baraja);

    ControladorConsola controlador(vista, jugador, crupier, baraja);
    controlador.iniciarJuego();

    return 0;
}