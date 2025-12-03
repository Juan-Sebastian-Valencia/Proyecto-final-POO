#include <gtest/gtest.h>
#include "../modelo/Jugador.h"

TEST(JugadorTest, RecibirCartaAumentaMano) {
    Jugador jugador;
    Carta carta1(10, 'P');
    Carta carta2(1, 'C');

    jugador.recibirCarta(carta1);
    jugador.recibirCarta(carta2);

    auto mano = jugador.getMano();

    EXPECT_EQ(mano.size(), 2);
}

TEST(JugadorTest, CalcularPuntuacionConAs) {
    Jugador jugador;

    jugador.recibirCarta(Carta(1, 'P'));  
    jugador.recibirCarta(Carta(9, 'T')); 

    int puntuacion = jugador.calcularPuntuacion();

    EXPECT_EQ(puntuacion, 20);
}
