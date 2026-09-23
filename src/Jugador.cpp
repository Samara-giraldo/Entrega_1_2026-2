#ifndef JUGADOR_CPP
#define JUGADOR_CPP

#include <string>
#include <vector>
#include <iostream>

class Jugador {
private:
    std::string _nombre;
    int _puntos;
    std::vector<Carta> _mano;

public:
    Jugador(std::string nombre = "") : _nombre(nombre), _puntos(0) {}

    std::string getNombre() const { return _nombre; }
    int getPuntos() const { return _puntos; }

    void sumarPunto() { _puntos++; }
    void recibirCarta(const Carta& c) { _mano.push_back(c); }

    int getCantidadCartas() const { return _mano.size(); }

    // Muestra las cartas que tienes en la mano de forma numerada
    void mostrarMano() const {
        for (size_t i = 0; i < _mano.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << _mano[i].getColor() << " " << _mano[i].getValor() << "\n";
        }
    }

    // Elige y remueve una carta según el índice que escoja el usuario
    Carta jugarCartaPorIndice(int indice) {
        if (indice >= 0 && indice < _mano.size()) {
            Carta elegida = _mano[indice];
            _mano.erase(_mano.begin() + indice);
            return elegida;
        }
        return Carta("Vacia", 0);
    }

    // Juega la primera carta automáticamente (para los Bots)
    Carta jugarCartaAuto() {
        if (!_mano.empty()) {
            Carta c = _mano.front();
            _mano.erase(_mano.begin());
            return c;
        }
        return Carta("Vacia", 0);
    }
};

#endif
