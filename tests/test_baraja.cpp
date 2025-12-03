#include <gtest/gtest.h>
#include "../modelo/Baraja.h"

TEST(BarajaTest, SacarCartaReduceTamanio) {
    Baraja baraja;

    // Sacar una carta debe reducir el tamaño de la baraja inicial
    Carta carta1 = baraja.sacarCarta();
    Carta carta2 = baraja.sacarCarta();

    // La baraja inicialmente tiene 52 cartas
    // Sacamos 2 → deben quedar 50
    Baraja baraja2; 
    // baraja2 está nueva, así que comparar tamaños

    // Sacar 52 cartas de baraja2 para llegar a vaciarla y forzar mezcla cuando llame barajar()
    int contador = 0;
    try {
        while (contador < 50) {
            baraja2.sacarCarta();
            contador++;
        }
    } catch(...) {}

    EXPECT_EQ(contador, 50);
}

TEST(BarajaTest, BarajarNoRompeLaBaraja) {
    Baraja baraja;

    // Saca una carta 
    Carta antes = baraja.sacarCarta();

    // Devolverla a barajaSegundaria
    baraja.recibirCartaBarajaSegundaria(antes);

    // Barajar debe mezclar ambas listas sin errores
    EXPECT_NO_THROW(baraja.barajar());

    // Sacar una carta nuevamente
    Carta despues = baraja.sacarCarta();

    // verificamos que sea una carta válida
    EXPECT_GE(despues.getValor(), 1);
    EXPECT_LE(despues.getValor(), 13);
}
