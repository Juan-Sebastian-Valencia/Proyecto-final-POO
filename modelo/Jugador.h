#ifndef MODELO_JUGADOR_H
#define MODELO_JUGADOR_H

#include <vector>
#include "Carta.h"

class Jugador {
    private:
        double saldo;
        double apuesta;
        int puntuacion;
        std::vector<Carta> mano;
    public:
        Jugador();
        double getSaldo() const;
        double getApuesta() const;
        int getPuntuacion() const;
        std::vector<Carta> getMano() const;

        void setSaldo(const double saldo);
        void setApuesta(const double apuesta);
        void setPuntuacion(const int puntuacion);
        void doblarApuesta();
        void recibirCarta(const Carta& carta);
        int calcularPuntuacion();
        Carta sacarCarta();
};




#endif // MODELO_JUGADOR_H