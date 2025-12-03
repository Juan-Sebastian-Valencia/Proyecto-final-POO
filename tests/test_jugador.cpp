#include <gtest/gtest.h>
#include "../modelo/Jugador.h"
#include "../modelo/Carta.h"

TEST(JugadorTest, CalcularPuntajeConAsYFiguras) {
    Jugador jugador;

    jugador.recibirCarta(Carta('P', 1));   
    jugador.recibirCarta(Carta('D', 13)); 
    jugador.recibirCarta(Carta('T', 5));

    int puntaje = jugador.calcularPuntaje();

    EXPECT_EQ(puntaje, 16);
}
