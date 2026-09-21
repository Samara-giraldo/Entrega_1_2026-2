#ifndef CARTA_CPP
#define CARTA_CPP

#include <string>

class Carta {
private:
    std::string _color;
    int _valor;

public:
    Carta(std::string color = "", int valor = 0) : _color(color), _valor(valor) {}

    std::string getColor() const { return _color; }
    int getValor() const { return _valor; }
};

#endif