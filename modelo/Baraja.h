#ifndef MODELO_BARAJA_H
#define MODELO_BARAJA_H

#include "Carta.h"
#include <vector>
#include <ctime>
#include <stdlib.h>

class Baraja {
    private:
        std::vector<Carta> barajaInicial;
        std::vector<Carta> barajaSegundaria;
    public:
        Baraja();
        Carta sacarCarta();
        void barajar();
        void recibirCartaBarajaSegundaria(const Carta& carta);
};

#endif // MODELO_BARAJA_H