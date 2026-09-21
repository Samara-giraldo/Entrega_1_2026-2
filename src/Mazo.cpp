#ifndef MAZO_CPP
#define MAZO_CPP

#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "Carta.cpp"

class Mazo {
private:
    std::vector<Carta> _cartas; // Lista que guarda las cartas del mazo

public:
    // Constructor: Crea automáticamente las 32 cartas (4 colores x 8 valores)
    Mazo() {
        std::string colores[4] = {"Rojo", "Azul", "Verde", "Amarillo"};

        // Crea 8 cartas (valores del 1 al 8) para cada uno de los 4 colores
        for (std::string col : colores) {
            for (int v = 1; v <= 8; v++) {
                Carta cartaNueva(col, v);
                _cartas.push_back(cartaNueva);
            }
        }
    }

    // Mezcla las cartas en orden aleatorio
    void mezclar() {
        std::random_device rd;
        std::mt19937 generador(rd());
        std::shuffle(_cartas.begin(), _cartas.end(), generador);
    }

    // Entrega la carta de arriba del mazo y la remueve
    Carta tomarCarta() {
        Carta cartaRobada = _cartas.back(); // Toma la última carta de la lista
        _cartas.pop_back();                 // La borra del mazo
        return cartaRobada;                 // La devuelve
    }

    // Revisa si el mazo ya no tiene cartas
    bool vacio() const { 
        return _cartas.empty(); 
    }
};

#endif