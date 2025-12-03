#include "VistaConsola.h"

int VistaConsola::mostrarMenuPrincipal() const {
    int opcion;
    std::cout << "=== Menu Principal ===" << std::endl;
    std::cout << "1. Iniciar Juego" << std::endl;
    std::cout << "2. Salir" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;
    return opcion;
}

int VistaConsola::mostrarMenuApuesta() const {
    int apuesta;
    std::cout << "\nIngrese su apuesta: ";
    std::cin >> apuesta;
    return apuesta;
}

int VistaConsola::mostrarMenuJuego() const {
    int opcion;
    std::cout << "\n=== Menu de Juego ===" << std::endl;
    std::cout << "1. Pedir Carta" << std::endl;
    std::cout << "2. Plantarse" << std::endl;
    std::cout << "3. Doblar Apuesta" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;
    return opcion;
}

double VistaConsola::hacerApuesta(double saldo) const {
    double apuesta;
    do {
        std::cout << "\nIngrese su apuesta (Saldo disponible: " << saldo << "): ";
        std::cin >> apuesta;
        if (apuesta > saldo) {
            std::cout << "Apuesta excede el saldo disponible. Intente de nuevo." << std::endl;
        }
        if (apuesta <= 0) {
            std::cout << "La apuesta debe ser mayor que cero. Intente de nuevo." << std::endl;
        }
    } while (apuesta > saldo || apuesta <= 0);

    return apuesta;
}



void VistaConsola::mostrarCarta(const Carta& carta) const {
    std::cout << "Carta: " << carta.getValor() << " " << carta.getPalo() << std::endl;
}

void VistaConsola::mostrarJugador(Jugador& jugador) const {
    std::cout << "\n=== Jugador ===" << std::endl;
    for (Carta carta : jugador.getMano()) {
        mostrarCarta(carta);
    }
    mostrarPuntaje(jugador);
}

void VistaConsola::mostrarCrupier(Crupier& crupier, bool mostrarSegundaCarta) const {
    std::cout << "\n=== Crupier ===" << std::endl;
    const std::vector<Carta> mano = crupier.getMano();
    for (int i = 0; i < mano.size(); ++i) {
        if (i == 1 && !mostrarSegundaCarta) {
            std::cout << "Carta: [Oculta]" << std::endl;
        } else {
            mostrarCarta(mano[i]);
        }
    }
    if (mostrarSegundaCarta) {
        mostrarPuntaje(crupier);
    }
}

void VistaConsola::mostrarPuntaje( Jugador& jugador) const {
    jugador.calcularPuntuacion();
    std::cout << "Puntaje total: " << jugador.getPuntuacion() << std::endl;
}

void VistaConsola::mostrarGanador() const {
    std::cout << "\n¡FELICIDADES! ganaste la ronda." << std::endl;
}

void VistaConsola::mostrarEmpate() const {
    std::cout << "\nEmpataste la ronda." << std::endl;
}

void VistaConsola::mostrarPerdedor() const {
    std::cout << "\nPerdiste la ronda, más suerte la próxima vez." << std::endl;
}

void VistaConsola::mostrarSinSaldo() const {
    std::cout << "\nNo tienes saldo suficiente para continuar jugando." << std::endl;
}

void VistaConsola::opcionNoValida() const {
    std::cout << "\n Opción no valida" << std::endl;
    std::cout << "Digite una opción valida" << std::endl;
    pausar();
    pausar();
}

void VistaConsola::saliendo() const {
    std::cout << "\n=== Gracias por jugar ===" << std::endl;
    std::cout << "Saliendo...";
}

void VistaConsola::limpiarConsola() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void VistaConsola::pausar() const {
    std::cout << "Presione una enter para continuar...";
    std::cin.get();
}