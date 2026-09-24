#ifndef JUGADOR_CPP
#define JUGADOR_CPP

#include <iostream>
#include <vector>
#include <string>
#include "Carta.cpp"

class Jugador {
private:
    std::string _nombre;
    std::vector<Carta> _mano;
    int _puntos;

public:
    Jugador(std::string nombre) : _nombre(nombre), _puntos(0) {}

    void recibirCarta(Carta c) {
        _mano.push_back(c);
    }

    void mostrarMano() const {
        for (size_t i = 0; i < _mano.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << _mano[i].getColor() << " " << _mano[i].getValor() << "\n";
        }
    }

    Carta jugarCartaPorIndice(int indice) {
        Carta c = _mano[indice];
        _mano.erase(_mano.begin() + indice);
        return c;
    }

    Carta jugarCartaAuto() {
        Carta c = _mano.back();
        _mano.pop_back();
        return c;
    }

    std::string getNombre() const { return _nombre; }
    int getPuntos() const { return _puntos; }
    int getCantidadCartas() const { return _mano.size(); }
    void sumarPunto() { _puntos++; }
};

#endif