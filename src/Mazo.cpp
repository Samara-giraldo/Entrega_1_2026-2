#ifndef MAZO_CPP
#define MAZO_CPP

#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include "Carta.cpp"

class Mazo {
private:
    std::vector<Carta> _cartas;

public:
    Mazo() {
        std::vector<std::string> colores = {"Rojo", "Azul", "Verde", "Amarillo"};
        for (const auto& color : colores) {
            for (int i = 1; i <= 8; ++i) { // Cartas del 1 al 8
                _cartas.push_back(Carta(color, i));
            }
        }
    }

    void mezclar() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(_cartas.begin(), _cartas.end(), std::default_random_engine(seed));
    }

    Carta repartir() {
        Carta c = _cartas.back();
        _cartas.pop_back();
        return c;
    }
};

#endif