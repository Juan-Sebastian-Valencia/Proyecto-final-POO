#include "Jugador.h"

Jugador::Jugador() : saldo(2000.0), puntuacion(0) {}

double Jugador::getSaldo() const { return saldo;}
double Jugador::getApuesta() const { return apuesta;}
int Jugador::getPuntuacion() const { return puntuacion;}
std::vector<Carta> Jugador::getMano() const { return mano;}

void Jugador::setSaldo(const double saldo) { this->saldo = saldo;}

void Jugador::setApuesta(const double apuesta) { this->apuesta = apuesta;}

void Jugador::setPuntuacion(const int puntuacion) { this->puntuacion = puntuacion;}

void Jugador::doblarApuesta() {
    apuesta *= 2;
    saldo -= apuesta / 2;
}

int Jugador::calcularPuntuacion() {
    int suma = 0;
    int numAses = 0;

    for (const Carta& carta : mano) {
        int valor = carta.getValor();
        if (valor >= 10) {
            suma += 10;
        } else if (valor == 1) {
            suma += 11;
            numAses++;
        } else {
            suma += valor;
        }
    }

    while (suma > 21 && numAses > 0) {
        suma -= 10;
        numAses--;
    }
    setPuntuacion(suma);

    return suma;
}

void Jugador::recibirCarta(const Carta& carta) { mano.push_back(carta);}
Carta Jugador::sacarCarta() {
    Carta carta = mano.back();
    mano.pop_back();
    return carta;
}
