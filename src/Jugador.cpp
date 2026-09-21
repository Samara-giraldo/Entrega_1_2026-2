#ifndef JUGADOR_CPP
#define JUGADOR_CPP

#include <string>
#include <vector>

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

    Carta jugarCarta() {
        if (!_mano.empty()) {
            Carta c = _mano.back();
            _mano.pop_back();
            return c;
        }
        return Carta("Vacia", 0);
    }

    int cantidadCartas() const { return _mano.size(); }
};

#endif