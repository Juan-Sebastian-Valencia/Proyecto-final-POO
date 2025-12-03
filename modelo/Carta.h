#ifndef MODELO_CARTA_H
#define MODELO_CARTA_H

class Carta {
    private:
        int valor;
        char palo;
    public:
        Carta(int valor, char palo);
        int getValor() const;
        char getPalo() const;
};

#endif // MODELO_CARTA_H