#ifndef CARTA_CPP
#define CARTA_CPP

#include <string>

class Carta {
private:
    std::string _color;
    int _valor;

public:
    // Constructor: Asigna color y valor numérico al crear la carta
    Carta(std::string color, int valor) : _color(color), _valor(valor) {}

    // Métodos para consultar los datos de la carta
    std::string color() const { 
        return _color; 
    }

    int valor() const { 
        return _valor; 
    }
};

#endif