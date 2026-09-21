#ifndef JUGADOR_CPP
#define JUGADOR_CPP

#include <string>
#include <vector>
#include "Carta.cpp"

class Jugador {
private:
    std::string _nombre;
    int _puntos;
    std::vector<Carta> _mano; 
public:
   
    Jugador(std::string nombre) : _nombre(nombre), _puntos(0) {}

  
    void recibirCarta(const Carta& c) { 
        _mano.push_back(c); 
    }
    
    
    Carta lanzarCarta() {
        Carta c = _mano.back();
        _mano.pop_back();
        return c;
    }

   
    void agregarPuntos(int pts) { 
        _puntos += pts; 
    }

    
    int puntos() const { 
        return _puntos; 
    }

    std::string nombre() const { 
        return _nombre; 
    }
};

#endif