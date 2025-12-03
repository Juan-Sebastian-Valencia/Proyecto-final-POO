#include <gtest/gtest.h>
#include "../modelo/Baraja.h"
#include "../modelo/Carta.h"

TEST(BarajaTest, BarajarYCogerCarta) {
    Baraja baraja1;
    Baraja baraja2;

    auto antes = baraja1.obtenerCartas();
    
    baraja1.barajar();
    auto despues = baraja1.obtenerCartas();

    EXPECT_NE(antes, despues);

    Carta carta = baraja1.repartirCarta();

    EXPECT_GE(carta.getValor(), 1);
    EXPECT_LE(carta.getValor(), 13);

    EXPECT_EQ(baraja1.tamanio(), baraja2.tamanio() - 1);
}
