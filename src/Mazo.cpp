#ifndef MAZO_CPP
#define MAZO_CPP

#include <vector>
#include <string>
#include <algorithm>
#include <random>

class Mazo {
private:
    std::vector<Carta> _cartas;

public:
    Mazo() {
        std::vector<std::string> colores = {"Rojo", "Azul", "Verde", "Amarillo"};
        for (const auto& color : colores) {
            for (int val = 1; val <= 8; ++val) {
                _cartas.push_back(Carta(color, val));
            }
        }
    }

    void mezclar() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(_cartas.begin(), _cartas.end(), g);
    }

    Carta repartir() {
        if (!_cartas.empty()) {
            Carta c = _cartas.back();
            _cartas.pop_back();
            return c;
        }
        return Carta("Vacia", 0);
    }
};

#endif